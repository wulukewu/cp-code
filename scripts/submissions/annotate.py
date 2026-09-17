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
UHUNT_PROBLEMS_API = "https://uhunt.onlinejudge.org/api/p"
UHUNT_BASE = "https://uhunt.onlinejudge.org/api"
UA = "wulukewu/cp-code submission-annotator"
MARKER = "cp-code:submission-metadata"
TAIPEI = ZoneInfo("Asia/Taipei")
LUKE_BANNER = (
    "'##:::::::'##::::'##:'##:::'##:'########:",
    " ##::::::: ##:::: ##: ##::'##:: ##.....::",
    " ##::::::: ##:::: ##: ##:'##::: ##:::::::",
    " ##::::::: ##:::: ##: #####:::: ######:::",
    " ##::::::: ##:::: ##: ##. ##::: ##...::::",
    " ##::::::: ##:::: ##: ##:. ##:: ##:::::::",
    " ########:. #######:: ##::. ##: ########:",
    "........:::.......:::..::::..::........::",
)
CF_VERDICTS = {
    "OK": "AC",
    "WRONG_ANSWER": "WA",
    "TIME_LIMIT_EXCEEDED": "TLE",
    "MEMORY_LIMIT_EXCEEDED": "MLE",
    "COMPILATION_ERROR": "CE",
    "RUNTIME_ERROR": "RE",
    "IDLENESS_LIMIT_EXCEEDED": "ILE",
}
UHUNT_VERDICTS = {
    10: "SE",
    15: "CJ",
    20: "QUEUE",
    30: "CE",
    35: "RF",
    40: "RE",
    45: "OLE",
    50: "TLE",
    60: "MLE",
    70: "WA",
    80: "PE",
    90: "AC",
}
UHUNT_LANGUAGES = {
    1: "ANSI C",
    2: "Java",
    3: "C++",
    4: "Pascal",
    5: "C++11",
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
                "time_limit_ms": None,
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
                "time_limit_ms": None,
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


def uva_problem_url(problem_number: int) -> str:
    return f"https://onlinejudge.org/external/{problem_number // 100}/{problem_number}.pdf"


def fetch_uhunt_problems() -> dict[str, dict[str, Any]]:
    payload = get_json(UHUNT_PROBLEMS_API)
    if not isinstance(payload, list):
        raise RuntimeError(f"uHunt problem API returned {type(payload).__name__}")
    problems: dict[str, dict[str, Any]] = {}
    for raw in payload:
        if not isinstance(raw, list) or len(raw) < 21:
            continue
        pid, number, title = raw[0], raw[1], raw[2]
        if not isinstance(number, int):
            continue
        problems[str(number)] = {
            "platform": "uva",
            "problem_id": str(number),
            "problem_name": str(title).strip() or None,
            "problem_url": uva_problem_url(number),
            "uhunt_problem_id": int(pid),
            "time_limit_ms": raw[19] if isinstance(raw[19], (int, float)) else None,
        }
    return problems


def fetch_uhunt_submissions(handle: str, problems: dict[str, dict[str, Any]]) -> list[dict[str, Any]]:
    encoded = urllib.parse.quote(handle, safe="")
    uid = get_json(f"{UHUNT_BASE}/uname2uid/{encoded}")
    if not isinstance(uid, int) or uid <= 0:
        raise RuntimeError(f"uHunt did not resolve UVa username {handle!r}")
    payload = get_json(f"{UHUNT_BASE}/subs-user/{uid}")
    if not isinstance(payload, dict) or not isinstance(payload.get("subs"), list):
        raise RuntimeError("uHunt user submissions API returned an unexpected payload")
    by_pid = {int(p["uhunt_problem_id"]): p for p in problems.values()}
    records: list[dict[str, Any]] = []
    for raw in payload["subs"]:
        if not isinstance(raw, list) or len(raw) < 7:
            continue
        sid, pid, verdict_id, runtime, submitted, language_id, _rank = raw[:7]
        p = by_pid.get(int(pid))
        if not p:
            continue
        records.append({
            "platform": "uva",
            "submission_id": str(sid),
            "contest_id": None,
            "problem_id": p["problem_id"],
            "problem_index": None,
            "problem_name": p.get("problem_name"),
            "epoch_second": int(submitted),
            "verdict": UHUNT_VERDICTS.get(int(verdict_id), str(verdict_id)),
            "language": UHUNT_LANGUAGES.get(int(language_id), f"language {language_id}"),
            "time_ms": runtime,
            "memory_bytes": None,
            "points": None,
            "rating": None,
            "tags": [],
            "time_limit_ms": p.get("time_limit_ms"),
            "submission_url": None,
            "problem_url": p.get("problem_url"),
        })
    return records


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


def uva_number(path: Path) -> str | None:
    m = re.match(r"^(\d{3,5})(?:[_\-\s.]|$)", path.stem)
    return m.group(1) if m else None


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


def platform_name(platform: str) -> str:
    return {"codeforces": "CODEFORCES", "atcoder": "ATCODER", "uva": "UVa"}.get(platform, platform.upper())


def header(selected: dict[str, Any], records: list[dict[str, Any]] | None = None) -> str:
    records = records or []
    title = selected.get("problem_name") or "Unknown title"
    lines = ["/*", *LUKE_BANNER, ""]
    lines.append(f" {platform_name(str(selected['platform']))} // {selected.get('problem_id')} // {title}")
    if selected.get("problem_url"):
        lines.append(f" {selected['problem_url']}")
    lines.append("")

    if selected.get("submission_id") is not None:
        summary = [str(selected.get("verdict") or "UNKNOWN")]
        if selected.get("language"):
            summary.append(str(selected["language"]))
        if selected.get("time_ms") is not None:
            summary.append(f"{selected['time_ms']} ms")
        mem = memory_text(selected.get("memory_bytes"))
        if mem:
            summary.append(mem)
        if selected.get("points") is not None:
            summary.append(f"{selected['points']} pt")
        lines.append(" " + " // ".join(summary))

        detail = [f"#{selected['submission_id']}", local_time(int(selected["epoch_second"]))]
        if len(records) > 1:
            detail.append(f"{len(records)} attempts")
        lines.append(" " + " // ".join(detail))

        extras: list[str] = []
        if selected.get("rating") is not None:
            extras.append(f"rating {selected['rating']}")
        if selected.get("tags"):
            extras.append(", ".join(str(t) for t in selected["tags"]))
        if selected.get("time_limit_ms") is not None:
            extras.append(f"time limit {selected['time_limit_ms']} ms")
        if extras:
            lines.append(" " + " // ".join(extras))
        if selected.get("submission_url"):
            lines.append(f" {selected['submission_url']}")
    else:
        details = ["problem metadata: uHunt"]
        if selected.get("time_limit_ms") is not None:
            details.append(f"time limit {selected['time_limit_ms']} ms")
        lines.append(" " + " // ".join(details))

    lines += ["", f" {MARKER}", "*/"]
    return "\n".join(lines)


def without_header_bytes(data: bytes) -> bytes:
    if not data.startswith(b"/*"):
        return data
    end = data.find(b"*/")
    if end == -1 or MARKER.encode() not in data[: end + 2]:
        return data
    rest = data[end + 2 :]
    if rest.startswith(b"\r\n\r\n"):
        return rest[4:]
    if rest.startswith(b"\n\n"):
        return rest[2:]
    if rest.startswith(b"\r\n"):
        return rest[2:]
    if rest.startswith(b"\n"):
        return rest[1:]
    return rest


def write_annotated(path: Path, generated_header: str, original: bytes) -> None:
    body = without_header_bytes(original)
    generated = generated_header.encode("utf-8") + b"\n\n" + body
    if generated != original:
        path.write_bytes(generated)


def annotate_submission_platform(
    root: Path,
    platform: str,
    records: list[dict[str, Any]],
    report: dict[str, Any],
) -> None:
    history: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for r in records:
        if r.get("contest_id"):
            history[str(r["contest_id"]).lower()].append(r)
    count = 0
    platform_root = root / platform
    if not platform_root.exists():
        return
    for path in sorted(platform_root.rglob("*.cpp")):
        rel = path.relative_to(root)
        original = path.read_bytes()
        if not original.strip():
            report["unmatched"].append({"path": str(rel), "reason": "empty source file"})
            continue
        matched, reason = match_codeforces(rel, history) if platform == "codeforces" else match_atcoder(rel, history)
        if not matched:
            report["unmatched"].append({"path": str(rel), "reason": reason})
            continue
        commit_epoch = latest_file_commit(rel)
        selected = choose(matched, commit_epoch)
        write_annotated(path, header(selected, matched), original)
        count += 1
        report["annotated"].append({
            "path": str(rel),
            "problem_id": selected.get("problem_id"),
            "submission_id": selected["submission_id"],
            "verdict": selected.get("verdict"),
        })
    report["counts"][platform] = {
        "submissions": len(records),
        "annotated_files": count,
    }


def annotate_cpe(
    root: Path,
    problems: dict[str, dict[str, Any]],
    uva_submissions: list[dict[str, Any]],
    report: dict[str, Any],
) -> None:
    platform_root = root / "cpe"
    if not platform_root.exists() or not problems:
        return
    history = group_by_problem(uva_submissions)
    count = 0
    for path in sorted(platform_root.rglob("*.cpp")):
        rel = path.relative_to(root)
        original = path.read_bytes()
        if not original.strip():
            report["unmatched"].append({"path": str(rel), "reason": "empty source file"})
            continue
        number = uva_number(rel)
        if not number or number not in problems:
            report["unmatched"].append({"path": str(rel), "reason": "filename did not identify a UVa problem in uHunt"})
            continue
        problem = problems[number]
        records = history.get(number, [])
        if records:
            commit_epoch = latest_file_commit(rel)
            selected = choose(records, commit_epoch)
        else:
            selected = problem
        write_annotated(path, header(selected, records), original)
        count += 1
        report["annotated"].append({
            "path": str(rel),
            "problem_id": number,
            "submission_id": selected.get("submission_id"),
            "verdict": selected.get("verdict"),
        })
    report["counts"]["cpe"] = {
        "submissions": len(uva_submissions),
        "annotated_files": count,
    }


def annotate(
    root: Path,
    submissions: dict[str, list[dict[str, Any]]],
    uhunt_problems: dict[str, dict[str, Any]],
) -> dict[str, Any]:
    report: dict[str, Any] = {"annotated": [], "unmatched": [], "counts": {}}
    for platform in ("codeforces", "atcoder"):
        annotate_submission_platform(root, platform, submissions.get(platform, []), report)
    annotate_cpe(root, uhunt_problems, submissions.get("uva", []), report)
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

    uhunt_problems: dict[str, dict[str, Any]] = {}
    if (args.root / "cpe").exists():
        try:
            uhunt_problems = fetch_uhunt_problems()
            print(f"uhunt: fetched {len(uhunt_problems)} UVa problems")
            if handle := str(accounts.get("uva", "")).strip():
                submissions["uva"] = fetch_uhunt_submissions(handle, uhunt_problems)
                print(f"uva: fetched {len(submissions['uva'])} submissions")
        except RuntimeError as exc:
            print(f"warning: uHunt enrichment unavailable: {exc}")

    if not submissions and not uhunt_problems:
        raise RuntimeError("no submission accounts configured and no public problem metadata available")

    report = annotate(args.root, submissions, uhunt_problems)
    args.report.write_text(json.dumps(report, ensure_ascii=False, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    for platform, counts in report["counts"].items():
        print(f"{platform}: {counts['annotated_files']} files annotated from {counts['submissions']} submissions")
    print(f"unmatched files: {len(report['unmatched'])}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
