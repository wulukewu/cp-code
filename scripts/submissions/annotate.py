#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import re
import subprocess
import time
import urllib.error
import urllib.parse
import urllib.request
from collections import defaultdict
from datetime import datetime, timezone
from pathlib import Path
from typing import Any
from zoneinfo import ZoneInfo

CF_API = "https://codeforces.com/api/user.status"
AT_SUBMISSIONS_API = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions"
AT_PROBLEMS_API = "https://kenkoooo.com/atcoder/resources/problems.json"
UA = "wulukewu/cp-code submission-annotator"
MARKER = "/* cp-code:submission-metadata"
TAIPEI = ZoneInfo("Asia/Taipei")

CF_VERDICTS = {
    "OK": "AC",
    "WRONG_ANSWER": "WA",
    "TIME_LIMIT_EXCEEDED": "TLE",
    "MEMORY_LIMIT_EXCEEDED": "MLE",
    "COMPILATION_ERROR": "CE",
    "RUNTIME_ERROR": "RE",
    "IDLENESS_LIMIT_EXCEEDED": "ILE",
}


def get_json(url: str) -> Any:
    request = urllib.request.Request(
        url,
        headers={"User-Agent": UA, "Accept": "application/json"},
    )
    for attempt in range(3):
        try:
            with urllib.request.urlopen(request, timeout=30) as response:
                return json.load(response)
        except (urllib.error.URLError, urllib.error.HTTPError, TimeoutError, json.JSONDecodeError) as exc:
            if attempt == 2:
                raise RuntimeError(f"failed to fetch {url}: {exc}") from exc
            time.sleep(2**attempt)
    raise AssertionError("unreachable")


def fetch_codeforces(handle: str) -> list[dict[str, Any]]:
    offset, page_size = 1, 1000
    records: list[dict[str, Any]] = []
    while True:
        query = urllib.parse.urlencode({"handle": handle, "from": offset, "count": page_size})
        payload = get_json(f"{CF_API}?{query}")
        if payload.get("status") != "OK":
            raise RuntimeError(f"Codeforces API returned {payload!r}")
        page = payload.get("result") or []
        for raw in page:
            problem = raw.get("problem") or {}
            contest_id = raw.get("contestId", problem.get("contestId"))
            index = problem.get("index")
            if contest_id is None or not index:
                continue
            submission_id = int(raw["id"])
            raw_verdict = raw.get("verdict")
            kind = "gym" if int(contest_id) >= 100000 else "contest"
            base = f"https://codeforces.com/{kind}/{contest_id}"
            records.append(
                {
                    "platform": "codeforces",
                    "submission_id": str(submission_id),
                    "contest_id": str(contest_id),
                    "problem_id": f"{contest_id}{index}",
                    "problem_index": str(index),
                    "problem_name": problem.get("name"),
                    "epoch_second": int(raw["creationTimeSeconds"]),
                    "verdict": CF_VERDICTS.get(raw_verdict, raw_verdict),
                    "raw_verdict": raw_verdict,
                    "language": raw.get("programmingLanguage"),
                    "time_ms": raw.get("timeConsumedMillis"),
                    "memory_bytes": raw.get("memoryConsumedBytes"),
                    "points": raw.get("points"),
                    "rating": problem.get("rating"),
                    "tags": problem.get("tags") or [],
                    "submission_url": f"{base}/submission/{submission_id}",
                    "problem_url": f"{base}/problem/{index}",
                }
            )
        if len(page) < page_size:
            break
        offset += page_size
        time.sleep(2.1)
    return records


def fetch_atcoder(handle: str) -> list[dict[str, Any]]:
    problems_payload = get_json(AT_PROBLEMS_API)
    problem_names = {
        str(problem.get("id")): problem.get("title")
        for problem in problems_payload
        if problem.get("id")
    }

    cursor = 0
    records: list[dict[str, Any]] = []
    seen: set[str] = set()
    while True:
        query = urllib.parse.urlencode({"user": handle, "from_second": cursor})
        page = get_json(f"{AT_SUBMISSIONS_API}?{query}")
        if not isinstance(page, list):
            raise RuntimeError(f"AtCoder Problems API returned {page!r}")
        if not page:
            break
        page.sort(key=lambda r: (int(r["epoch_second"]), int(r["id"])))
        for raw in page:
            submission_id = str(raw["id"])
            if submission_id in seen:
                continue
            seen.add(submission_id)
            contest_id = raw.get("contest_id")
            problem_id = raw.get("problem_id")
            records.append(
                {
                    "platform": "atcoder",
                    "submission_id": submission_id,
                    "contest_id": contest_id,
                    "problem_id": problem_id,
                    "problem_index": problem_id.rsplit("_", 1)[-1].upper() if problem_id and "_" in problem_id else None,
                    "problem_name": problem_names.get(str(problem_id)),
                    "epoch_second": int(raw["epoch_second"]),
                    "verdict": raw.get("result"),
                    "raw_verdict": raw.get("result"),
                    "language": raw.get("language"),
                    "time_ms": raw.get("execution_time"),
                    "memory_bytes": None,
                    "points": raw.get("point"),
                    "rating": None,
                    "tags": [],
                    "code_length": raw.get("length"),
                    "submission_url": (
                        f"https://atcoder.jp/contests/{contest_id}/submissions/{submission_id}"
                        if contest_id
                        else None
                    ),
                    "problem_url": (
                        f"https://atcoder.jp/contests/{contest_id}/tasks/{problem_id}"
                        if contest_id and problem_id
                        else None
                    ),
                }
            )
        if len(page) < 500:
            break
        next_cursor = max(int(r["epoch_second"]) for r in page) + 1
        if next_cursor <= cursor:
            raise RuntimeError("AtCoder pagination cursor did not advance")
        cursor = next_cursor
        time.sleep(1.1)
    return records


def normalize_text(value: str | None) -> str:
    if not value:
        return ""
    return re.sub(r"[^a-z0-9]+", "", value.casefold())


def file_commit_epoch(path: Path) -> int | None:
    try:
        output = subprocess.check_output(
            ["git", "log", "-1", "--format=%ct", "--", str(path)],
            text=True,
            stderr=subprocess.DEVNULL,
        ).strip()
    except (subprocess.CalledProcessError, FileNotFoundError):
        return None
    return int(output) if output.isdigit() else None


def codeforces_contest_candidates(path: Path) -> list[str]:
    parts = path.parts
    candidates: list[str] = []
    for i, part in enumerate(parts):
        if part in {"contest", "gym"} and i + 1 < len(parts) and parts[i + 1].isdigit():
            candidates.append(parts[i + 1])
        match = re.fullmatch(r"round(\d{3,6})", part, flags=re.IGNORECASE)
        if match:
            candidates.append(match.group(1))
    for part in parts:
        if re.fullmatch(r"\d{3,6}", part):
            candidates.append(part)
    return list(dict.fromkeys(candidates))


def filename_index_candidate(path: Path) -> str | None:
    stem = path.stem
    match = re.match(r"^([A-Za-z])(?:[_-]?(\d+))?(?:[_\-\s]|$)", stem)
    if not match:
        return None
    letter = match.group(1).upper()
    suffix = match.group(2) or ""
    return f"{letter}{suffix}"


def choose_submission(records: list[dict[str, Any]], commit_epoch: int | None) -> dict[str, Any]:
    accepted = [r for r in records if r.get("verdict") == "AC"]
    candidates = accepted or records
    if not candidates:
        raise ValueError("no candidate submissions")
    if commit_epoch is None:
        return max(candidates, key=lambda r: int(r["epoch_second"]))

    before = [r for r in candidates if int(r["epoch_second"]) <= commit_epoch]
    if before:
        return max(before, key=lambda r: int(r["epoch_second"]))
    return min(candidates, key=lambda r: abs(int(r["epoch_second"]) - commit_epoch))


def match_codeforces(
    path: Path,
    by_contest: dict[str, list[dict[str, Any]]],
) -> tuple[list[dict[str, Any]] | None, str]:
    contest_ids = [c for c in codeforces_contest_candidates(path) if c in by_contest]
    if not contest_ids:
        return None, "no contest id in path matched submission history"

    index_candidate = filename_index_candidate(path)
    stem_normalized = normalize_text(path.stem)

    matches: list[list[dict[str, Any]]] = []
    for contest_id in contest_ids:
        problem_groups: dict[str, list[dict[str, Any]]] = defaultdict(list)
        for record in by_contest[contest_id]:
            problem_groups[str(record["problem_index"])].append(record)

        if index_candidate and index_candidate in problem_groups:
            matches.append(problem_groups[index_candidate])
            continue

        for records in problem_groups.values():
            title = normalize_text(records[0].get("problem_name"))
            if title and (
                stem_normalized == title
                or stem_normalized.endswith(title)
                or title.endswith(stem_normalized)
            ):
                matches.append(records)

    unique = {
        (group[0]["contest_id"], group[0]["problem_index"]): group
        for group in matches
    }
    if len(unique) == 1:
        return next(iter(unique.values())), "matched by contest path and filename"
    if len(unique) > 1:
        return None, "multiple Codeforces problems matched"
    return None, "contest matched but filename did not identify a problem"


def atcoder_contest_candidate(path: Path) -> str | None:
    for part in path.parts:
        if re.fullmatch(r"[a-z][a-z0-9_-]*\d{2,4}", part, flags=re.IGNORECASE):
            return part.lower()
    return None


def match_atcoder(
    path: Path,
    by_contest: dict[str, list[dict[str, Any]]],
) -> tuple[list[dict[str, Any]] | None, str]:
    contest_id = atcoder_contest_candidate(path)
    if not contest_id or contest_id not in by_contest:
        return None, "no AtCoder contest id in path matched submission history"

    problem_groups: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in by_contest[contest_id]:
        if record.get("problem_id"):
            problem_groups[str(record["problem_id"])].append(record)

    index_candidate = filename_index_candidate(path)
    stem_normalized = normalize_text(path.stem)
    matches: list[list[dict[str, Any]]] = []

    for problem_id, records in problem_groups.items():
        first = records[0]
        if index_candidate and first.get("problem_index") == index_candidate:
            matches.append(records)
            continue
        title = normalize_text(first.get("problem_name"))
        if title and (
            stem_normalized == title
            or stem_normalized.endswith(title)
            or title.endswith(stem_normalized)
        ):
            matches.append(records)
            continue
        if normalize_text(problem_id) == stem_normalized:
            matches.append(records)

    unique = {group[0]["problem_id"]: group for group in matches}
    if len(unique) == 1:
        return next(iter(unique.values())), "matched by contest path and filename/title"
    if len(unique) > 1:
        return None, "multiple AtCoder problems matched"
    return None, "contest matched but filename did not identify a problem"


def strip_managed_header(text: str) -> str:
    if not text.startswith(MARKER):
        return text
    end = text.find("*/")
    if end == -1:
        return text
    return text[end + 2 :].lstrip("\n")


def format_local_time(epoch: int) -> str:
    return datetime.fromtimestamp(epoch, tz=timezone.utc).astimezone(TAIPEI).strftime("%Y-%m-%d %H:%M:%S %z")


def format_memory(value: Any) -> str | None:
    if value is None:
        return None
    try:
        raw = int(value)
    except (TypeError, ValueError):
        return str(value)
    if raw < 1024:
        return f"{raw} B"
    if raw < 1024 * 1024:
        return f"{raw / 1024:.1f} KiB"
    return f"{raw / (1024 * 1024):.1f} MiB"


def build_header(
    selected: dict[str, Any],
    records: list[dict[str, Any]],
    match_reason: str,
    commit_epoch: int | None,
) -> str:
    platform_name = "Codeforces" if selected["platform"] == "codeforces" else "AtCoder"
    accepted = sum(1 for r in records if r.get("verdict") == "AC")
    lines = [
        MARKER,
        " * Generated on the annotated branch. Do not edit manually.",
        f" * Platform:       {platform_name}",
        f" * Problem:        {selected.get('problem_id')} — {selected.get('problem_name') or 'Unknown title'}",
    ]
    if selected.get("problem_url"):
        lines.append(f" * Problem URL:    {selected['problem_url']}")
    lines.extend(
        [
            " *",
            f" * Matched result: {selected.get('verdict') or 'Unknown'}",
            f" * Submission:     #{selected['submission_id']}",
        ]
    )
    if selected.get("submission_url"):
        lines.append(f" * Submission URL: {selected['submission_url']}")
    lines.extend(
        [
            f" * Submitted:      {format_local_time(int(selected['epoch_second']))}",
            f" * Language:       {selected.get('language') or 'Unknown'}",
        ]
    )
    if selected.get("time_ms") is not None:
        lines.append(f" * Runtime:        {selected['time_ms']} ms")
    memory = format_memory(selected.get("memory_bytes"))
    if memory:
        lines.append(f" * Memory:         {memory}")
    if selected.get("points") is not None:
        lines.append(f" * Points:         {selected['points']}")
    if selected.get("rating") is not None:
        lines.append(f" * Rating:         {selected['rating']}")
    tags = selected.get("tags") or []
    if tags:
        lines.append(f" * Tags:           {', '.join(str(tag) for tag in tags)}")
    lines.append(f" * Submissions:    {len(records)} total / {accepted} accepted")
    if commit_epoch is not None:
        lines.append(f" * File commit:    {format_local_time(commit_epoch)}")
    lines.extend(
        [
            f" * Match policy:   {match_reason}; accepted submission nearest before file commit when possible",
            " * Source equality with the online submission is not verified.",
            " */",
        ]
    )
    return "\n".join(lines)


def annotate_tree(root: Path, submissions: dict[str, list[dict[str, Any]]]) -> dict[str, Any]:
    report: dict[str, Any] = {
        "annotated": [],
        "unmatched": [],
        "counts": {},
    }

    for platform in ("codeforces", "atcoder"):
        by_contest: dict[str, list[dict[str, Any]]] = defaultdict(list)
        for record in submissions.get(platform, []):
            if record.get("contest_id"):
                by_contest[str(record["contest_id"]).lower()].append(record)

        platform_root = root / platform
        if not platform_root.exists():
            continue

        annotated_count = 0
        for path in sorted(platform_root.rglob("*.cpp")):
            relative = path.relative_to(root)
            if platform == "codeforces":
                matched, reason = match_codeforces(relative, by_contest)
            else:
                matched, reason = match_atcoder(relative, by_contest)

            if not matched:
                report["unmatched"].append({"path": str(relative), "reason": reason})
                continue

            commit_epoch = file_commit_epoch(relative)
            selected = choose_submission(matched, commit_epoch)
            original = path.read_text(encoding="utf-8")
            body = strip_managed_header(original)
            header = build_header(selected, matched, reason, commit_epoch)
            updated = f"{header}\n\n{body}"
            if updated != original:
                path.write_text(updated, encoding="utf-8")

            annotated_count += 1
            report["annotated"].append(
                {
                    "path": str(relative),
                    "problem_id": selected.get("problem_id"),
                    "submission_id": selected.get("submission_id"),
                    "verdict": selected.get("verdict"),
                }
            )

        report["counts"][platform] = {
            "submissions": len(submissions.get(platform, [])),
            "annotated_files": annotated_count,
        }

    return report


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--accounts", type=Path, default=Path("config/submission_accounts.json"))
    parser.add_argument("--root", type=Path, default=Path("."))
    parser.add_argument("--report", type=Path, default=Path("/tmp/submission-annotation-report.json"))
    args = parser.parse_args()

    accounts = json.loads(args.accounts.read_text(encoding="utf-8"))
    submissions: dict[str, list[dict[str, Any]]] = {}

    cf_handle = str(accounts.get("codeforces", "")).strip()
    if cf_handle:
        submissions["codeforces"] = fetch_codeforces(cf_handle)
        print(f"codeforces: fetched {len(submissions['codeforces'])} submissions")

    at_handle = str(accounts.get("atcoder", "")).strip()
    if at_handle:
        submissions["atcoder"] = fetch_atcoder(at_handle)
        print(f"atcoder: fetched {len(submissions['atcoder'])} submissions")

    if not submissions:
        raise RuntimeError("no submission accounts configured")

    report = annotate_tree(args.root, submissions)
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(
        json.dumps(report, ensure_ascii=False, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
    )

    for platform, counts in report["counts"].items():
        print(
            f"{platform}: {counts['annotated_files']} files annotated "
            f"from {counts['submissions']} submissions"
        )
    print(f"unmatched files: {len(report['unmatched'])}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
