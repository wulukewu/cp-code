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
    req = urllib.request.Request(url, headers={"User-Agent": UA, "Accept": "application/json"})
    for attempt in range(3):
        try:
            with urllib.request.urlopen(req, timeout=30) as response:
                return json.load(response)
        except (urllib.error.URLError, urllib.error.HTTPError, TimeoutError, json.JSONDecodeError) as exc:
            if attempt == 2:
                raise RuntimeError(f"failed to fetch {url}: {exc}") from exc
            time.sleep(2**attempt)
    raise AssertionError("unreachable")


def clean_atcoder_title(value: Any) -> str | None:
    if not isinstance(value, str):
        return None
    title = value.strip()
    return re.sub(r"^[A-Z]\s*[.\-]\s*", "", title).strip() or None


def fetch_codeforces(handle: str) -> list[dict[str, Any]]:
    records: list[dict[str, Any]] = []
    offset, page_size = 1, 1000
    while True:
        q = urllib.parse.urlencode({"handle": handle, "from": offset, "count": page_size})
        payload = get_json(f"{CF_API}?{q}")
        if payload.get("status") != "OK":
            raise RuntimeError(f"Codeforces API returned {payload!r}")
        page = payload.get("result") or []
        for raw in page:
            p = raw.get("problem") or {}
            contest_id = raw.get("contestId", p.get("contestId"))
            index = p.get("index")
            if contest_id is None or not index:
                continue
            sid = str(raw["id"])
            raw_verdict = raw.get("verdict")
            kind = "gym" if int(contest_id) >= 100000 else "contest"
            base = f"https://codeforces.com/{kind}/{contest_id}"
            records.append({
                "platform": "codeforces",
                "submission_id": sid,
                "contest_id": str(contest_id),
                "problem_id": f"{contest_id}{index}",
                "problem_index": str(index),
                "problem_name": str(p.get("name") or "").strip() or None,
                "epoch_second": int(raw["creationTimeSeconds"]),
                "verdict": CF_VERDICTS.get(raw_verdict, raw_verdict),
                "language": raw.get("programmingLanguage"),
                "time_ms": raw.get("timeConsumedMillis"),
                "memory_bytes": raw.get("memoryConsumedBytes"),
                "points": raw.get("points"),
                "rating": p.get("rating"),
                "tags": p.get("tags") or [],
                "submission_url": f"{base}/submission/{sid}",
                "problem_url": f"{base}/problem/{index}",
            })
        if len(page) < page_size:
            return records
        offset += page_size
        time.sleep(2.1)


def fetch_atcoder(handle: str) -> list[dict[str, Any]]:
    problem_names = {
        str(p["id"]): clean_atcoder_title(p.get("title"))
        for p in get_json(AT_PROBLEMS_API)
        if p.get("id")
    }
    records: list[dict[str, Any]] = []
    seen: set[str] = set()
    cursor = 0
    while True:
        q = urllib.parse.urlencode({"user": handle, "from_second": cursor})
        page = get_json(f"{AT_SUBMISSIONS_API}?{q}")
        if not isinstance(page, list):
            raise RuntimeError(f"AtCoder Problems API returned {page!r}")
        if not page:
            return records
        page.sort(key=lambda r: (int(r["epoch_second"]), int(r["id"])))
        for raw in page:
            sid = str(raw["id"])
            if sid in seen:
                continue
            seen.add(sid)
            contest_id = raw.get("contest_id")
            problem_id = raw.get("problem_id")
            records.append({
                "platform": "atcoder",
                "submission_id": sid,
                "contest_id": contest_id,
                "problem_id": problem_id,
                "problem_index": problem_id.rsplit("_", 1)[-1].upper() if problem_id and "_" in problem_id else None,
                "problem_name": problem_names.get(str(problem_id)),
                "epoch_second": int(raw["epoch_second"]),
                "verdict": raw.get("result"),
                "language": raw.get("language"),
                "time_ms": raw.get("execution_time"),
                "memory_bytes": None,
                "points": raw.get("point"),
                "rating": None,
                "tags": [],
                "submission_url": f"https://atcoder.jp/contests/{contest_id}/submissions/{sid}" if contest_id else None,
                "problem_url": f"https://atcoder.jp/contests/{contest_id}/tasks/{problem_id}" if contest_id and problem_id else None,
            })
        if len(page) < 500:
            return records
        next_cursor = max(int(r["epoch_second"]) for r in page) + 1
        if next_cursor <= cursor:
            raise RuntimeError("AtCoder pagination cursor did not advance")
        cursor = next_cursor
        time.sleep(1.1)


def normalized(value: str | None) -> str:
    return re.sub(r"[^a-z0-9]+", "", (value or "").casefold())


def latest_file_commit(path: Path) -> int | None:
    try:
        value = subprocess.check_output(
            ["git", "log", "-1", "--format=%ct", "--", str(path)],
            text=True,
            stderr=subprocess.DEVNULL,
        ).strip()
        return int(value) if value.isdigit() else None
    except (subprocess.CalledProcessError, FileNotFoundError):
        return None


def filename_index(path: Path) -> str | None:
    m = re.match(r"^([A-Za-z])(?:[_-]?(\d+))?(?:[_\-\s]|$)", path.stem)
    return f"{m.group(1).upper()}{m.group(2) or ''}" if m else None


def cf_contests(path: Path) -> list[str]:
    out: list[str] = []
    parts = path.parts
    for i, part in enumerate(parts):
        if part in {"contest", "gym"} and i + 1 < len(parts) and parts[i + 1].isdigit():
            out.append(parts[i + 1])
        m = re.fullmatch(r"round(\d{3,6})", part, re.IGNORECASE)
        if m:
            out.append(m.group(1))
    out.extend(part for part in parts if re.fullmatch(r"\d{3,6}", part))
    return list(dict.fromkeys(out))


def at_contest(path: Path) -> str | None:
    for part in path.parts:
        if re.fullmatch(r"[a-z][a-z0-9_-]*\d{2,4}", part, re.IGNORECASE):
            return part.lower()
    return None


def group_by_problem(records: list[dict[str, Any]]) -> dict[str, list[dict[str, Any]]]:
    groups: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for r in records:
        key = str(r.get("problem_index") or r.get("problem_id") or "")
        if key:
            groups[key].append(r)
    return groups


def match_codeforces(path: Path, history: dict[str, list[dict[str, Any]]]) -> tuple[list[dict[str, Any]] | None, str]:
    contest_ids = [c for c in cf_contests(path) if c in history]
    if not contest_ids:
        return None, "no contest id in path matched submission history"
    idx = filename_index(path)
    stem = normalized(path.stem)
    matches: dict[tuple[str, str], list[dict[str, Any]]] = {}
    for cid in contest_ids:
        groups = group_by_problem(history[cid])
        if idx and idx in groups:
            matches[(cid, idx)] = groups[idx]
            continue
        for key, records in groups.items():
            title = normalized(records[0].get("problem_name"))
            if title and (stem == title or stem.endswith(title) or title.endswith(stem)):
                matches[(cid, key)] = records
    if len(matches) == 1:
        return next(iter(matches.values())), "matched by contest path and filename"
    return (None, "multiple Codeforces problems matched") if matches else (None, "contest matched but filename did not identify a problem")


def match_atcoder(path: Path, history: dict[str, list[dict[str, Any]]]) -> tuple[list[dict[str, Any]] | None, str]:
    cid = at_contest(path)
    if not cid or cid not in history:
        return None, "no AtCoder contest id in path matched submission history"
    groups: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for r in history[cid]:
        if r.get("problem_id"):
            groups[str(r["problem_id"])].append(r)
    idx = filename_index(path)
    stem = normalized(path.stem)
    matches: dict[str, list[dict[str, Any]]] = {}
    for pid, records in groups.items():
        first = records[0]
        title = normalized(first.get("problem_name"))
        if idx and first.get("problem_index") == idx:
            matches[pid] = records
        elif title and (stem == title or stem.endswith(title) or title.endswith(stem)):
            matches[pid] = records
        elif normalized(pid) == stem:
            matches[pid] = records
    if len(matches) == 1:
        return next(iter(matches.values())), "matched by contest path and filename/title"
    return (None, "multiple AtCoder problems matched") if matches else (None, "contest matched but filename did not identify a problem")


def choose(records: list[dict[str, Any]], commit_epoch: int | None) -> dict[str, Any]:
    candidates = [r for r in records if r.get("verdict") == "AC"] or records
    if commit_epoch is None:
        return max(candidates, key=lambda r: int(r["epoch_second"]))
    before = [r for r in candidates if int(r["epoch_second"]) <= commit_epoch]
    if before:
        return max(before, key=lambda r: int(r["epoch_second"]))
    return min(candidates, key=lambda r: abs(int(r["epoch_second"]) - commit_epoch))


def local_time(epoch: int) -> str:
    return datetime.fromtimestamp(epoch, timezone.utc).astimezone(TAIPEI).strftime("%Y-%m-%d %H:%M:%S %z")


def memory_text(value: Any) -> str | None:
    if value is None:
        return None
    n = int(value)
    if n < 1024:
        return f"{n} B"
    if n < 1024**2:
        return f"{n / 1024:.1f} KiB"
    return f"{n / 1024**2:.1f} MiB"


def header(selected: dict[str, Any], records: list[dict[str, Any]], reason: str, commit_epoch: int | None) -> str:
    platform = "Codeforces" if selected["platform"] == "codeforces" else "AtCoder"
    accepted = sum(r.get("verdict") == "AC" for r in records)
    lines = [
        MARKER,
        " * Generated on the annotated branch. Do not edit manually.",
        f" * Platform:       {platform}",
        f" * Problem:        {selected.get('problem_id')} — {selected.get('problem_name') or 'Unknown title'}",
    ]
    if selected.get("problem_url"):
        lines.append(f" * Problem URL:    {selected['problem_url']}")
    lines += [
        " *",
        f" * Matched result: {selected.get('verdict') or 'Unknown'}",
        f" * Submission:     #{selected['submission_id']}",
    ]
    if selected.get("submission_url"):
        lines.append(f" * Submission URL: {selected['submission_url']}")
    lines += [
        f" * Submitted:      {local_time(int(selected['epoch_second']))}",
        f" * Language:       {selected.get('language') or 'Unknown'}",
    ]
    if selected.get("time_ms") is not None:
        lines.append(f" * Runtime:        {selected['time_ms']} ms")
    mem = memory_text(selected.get("memory_bytes"))
    if mem:
        lines.append(f" * Memory:         {mem}")
    if selected.get("points") is not None:
        lines.append(f" * Points:         {selected['points']}")
    if selected.get("rating") is not None:
        lines.append(f" * Rating:         {selected['rating']}")
    if selected.get("tags"):
        lines.append(f" * Tags:           {', '.join(selected['tags'])}")
    lines.append(f" * Submissions:    {len(records)} total / {accepted} accepted")
    if commit_epoch is not None:
        lines.append(f" * File commit:    {local_time(commit_epoch)}")
    lines += [
        f" * Match policy:   {reason}; accepted submission nearest before file commit when possible",
        " * Source equality with the online submission is not verified.",
        " */",
    ]
    return "\n".join(line.rstrip() for line in lines)


def without_header(text: str) -> str:
    if text.startswith(MARKER):
        end = text.find("*/")
        if end != -1:
            text = text[end + 2:].lstrip("\n")
    return text.rstrip("\n") + "\n"


def annotate(root: Path, submissions: dict[str, list[dict[str, Any]]]) -> dict[str, Any]:
    report: dict[str, Any] = {"annotated": [], "unmatched": [], "counts": {}}
    for platform in ("codeforces", "atcoder"):
        history: dict[str, list[dict[str, Any]]] = defaultdict(list)
        for r in submissions.get(platform, []):
            if r.get("contest_id"):
                history[str(r["contest_id"]).lower()].append(r)
        count = 0
        platform_root = root / platform
        if not platform_root.exists():
            continue
        for path in sorted(platform_root.rglob("*.cpp")):
            rel = path.relative_to(root)
            original = path.read_text(encoding="utf-8")
            if not original.strip():
                report["unmatched"].append({"path": str(rel), "reason": "empty source file"})
                continue
            matched, reason = match_codeforces(rel, history) if platform == "codeforces" else match_atcoder(rel, history)
            if not matched:
                report["unmatched"].append({"path": str(rel), "reason": reason})
                continue
            commit_epoch = latest_file_commit(rel)
            selected = choose(matched, commit_epoch)
            generated = f"{header(selected, matched, reason, commit_epoch)}\n\n{without_header(original)}"
            if generated != original:
                path.write_text(generated, encoding="utf-8")
            count += 1
            report["annotated"].append({
                "path": str(rel),
                "problem_id": selected.get("problem_id"),
                "submission_id": selected["submission_id"],
                "verdict": selected.get("verdict"),
            })
        report["counts"][platform] = {
            "submissions": len(submissions.get(platform, [])),
            "annotated_files": count,
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
    if handle := str(accounts.get("codeforces", "")).strip():
        submissions["codeforces"] = fetch_codeforces(handle)
        print(f"codeforces: fetched {len(submissions['codeforces'])} submissions")
    if handle := str(accounts.get("atcoder", "")).strip():
        submissions["atcoder"] = fetch_atcoder(handle)
        print(f"atcoder: fetched {len(submissions['atcoder'])} submissions")
    if not submissions:
        raise RuntimeError("no submission accounts configured")

    report = annotate(args.root, submissions)
    args.report.write_text(json.dumps(report, ensure_ascii=False, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    for platform, counts in report["counts"].items():
        print(f"{platform}: {counts['annotated_files']} files annotated from {counts['submissions']} submissions")
    print(f"unmatched files: {len(report['unmatched'])}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
