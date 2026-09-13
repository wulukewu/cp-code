#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import time
import urllib.error
import urllib.parse
import urllib.request
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

CF_API = "https://codeforces.com/api/user.status"
AT_API = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions"
UA = "wulukewu/cp-code submission-sync"
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
    request = urllib.request.Request(url, headers={"User-Agent": UA, "Accept": "application/json"})
    for attempt in range(3):
        try:
            with urllib.request.urlopen(request, timeout=30) as response:
                return json.load(response)
        except (urllib.error.URLError, urllib.error.HTTPError, TimeoutError, json.JSONDecodeError) as exc:
            if attempt == 2:
                raise RuntimeError(f"failed to fetch {url}: {exc}") from exc
            time.sleep(2**attempt)
    raise AssertionError("unreachable")


def iso_utc(epoch: int) -> str:
    return datetime.fromtimestamp(epoch, tz=timezone.utc).isoformat().replace("+00:00", "Z")


def read_jsonl(path: Path) -> list[dict[str, Any]]:
    if not path.exists():
        return []
    records = []
    for line_number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        if not line.strip():
            continue
        try:
            records.append(json.loads(line))
        except json.JSONDecodeError as exc:
            raise RuntimeError(f"{path}:{line_number}: invalid JSON: {exc}") from exc
    return records


def write_jsonl(path: Path, records: list[dict[str, Any]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    records.sort(key=lambda r: (int(r["epoch_second"]), str(r["submission_id"])))
    path.write_text(
        "".join(json.dumps(r, ensure_ascii=False, sort_keys=True) + "\n" for r in records),
        encoding="utf-8",
    )


def normalize_cf(raw: dict[str, Any], handle: str) -> dict[str, Any]:
    problem = raw.get("problem") or {}
    contest_id = raw.get("contestId", problem.get("contestId"))
    submission_id = int(raw["id"])
    index = problem.get("index")
    epoch = int(raw["creationTimeSeconds"])
    raw_verdict = raw.get("verdict")
    kind = "gym" if contest_id is not None and int(contest_id) >= 100000 else "contest"
    base = f"https://codeforces.com/{kind}/{contest_id}" if contest_id is not None else None
    return {
        "platform": "codeforces",
        "submission_id": str(submission_id),
        "user": handle,
        "contest_id": str(contest_id) if contest_id is not None else None,
        "problem_id": f"{contest_id}{index}" if contest_id is not None and index else None,
        "problem_index": index,
        "problem_name": problem.get("name"),
        "epoch_second": epoch,
        "submitted_at": iso_utc(epoch),
        "verdict": CF_VERDICTS.get(raw_verdict, raw_verdict),
        "raw_verdict": raw_verdict,
        "language": raw.get("programmingLanguage"),
        "time_ms": raw.get("timeConsumedMillis"),
        "memory_bytes": raw.get("memoryConsumedBytes"),
        "points": raw.get("points"),
        "participant_type": (raw.get("author") or {}).get("participantType"),
        "submission_url": f"{base}/submission/{submission_id}" if base else None,
        "problem_url": f"{base}/problem/{index}" if base and index else None,
    }


def normalize_at(raw: dict[str, Any], handle: str) -> dict[str, Any]:
    submission_id = int(raw["id"])
    contest_id = raw.get("contest_id")
    problem_id = raw.get("problem_id")
    epoch = int(raw["epoch_second"])
    return {
        "platform": "atcoder",
        "submission_id": str(submission_id),
        "user": handle,
        "contest_id": contest_id,
        "problem_id": problem_id,
        "problem_index": None,
        "problem_name": None,
        "epoch_second": epoch,
        "submitted_at": iso_utc(epoch),
        "verdict": raw.get("result"),
        "raw_verdict": raw.get("result"),
        "language": raw.get("language"),
        "time_ms": raw.get("execution_time"),
        "memory_bytes": None,
        "points": raw.get("point"),
        "participant_type": None,
        "submission_url": (
            f"https://atcoder.jp/contests/{contest_id}/submissions/{submission_id}" if contest_id else None
        ),
        "problem_url": (
            f"https://atcoder.jp/contests/{contest_id}/tasks/{problem_id}"
            if contest_id and problem_id
            else None
        ),
    }


def fetch_cf(handle: str, known: set[str], full_refresh: bool) -> list[dict[str, Any]]:
    offset, page_size = 1, 1000
    fresh = []
    while True:
        query = urllib.parse.urlencode({"handle": handle, "from": offset, "count": page_size})
        payload = get_json(f"{CF_API}?{query}")
        if payload.get("status") != "OK":
            raise RuntimeError(f"Codeforces API returned {payload!r}")
        page = payload.get("result") or []
        if not page:
            break

        saw_known = False
        for raw in page:
            submission_id = str(raw["id"])
            if not full_refresh and submission_id in known:
                saw_known = True
                continue
            fresh.append(normalize_cf(raw, handle))

        if (not full_refresh and saw_known) or len(page) < page_size:
            break
        offset += page_size
        time.sleep(2.1)
    return fresh


def fetch_at(handle: str, existing: list[dict[str, Any]], full_refresh: bool) -> list[dict[str, Any]]:
    cursor = 0 if full_refresh or not existing else max(
        0, max(int(r["epoch_second"]) for r in existing) - 1
    )
    known = {str(r["submission_id"]) for r in existing}
    fresh = []

    while True:
        query = urllib.parse.urlencode({"user": handle, "from_second": cursor})
        page = get_json(f"{AT_API}?{query}")
        if not isinstance(page, list):
            raise RuntimeError(f"AtCoder Problems API returned {page!r}")
        if not page:
            break

        page.sort(key=lambda r: (int(r["epoch_second"]), int(r["id"])))
        for raw in page:
            submission_id = str(raw["id"])
            if submission_id not in known:
                fresh.append(normalize_at(raw, handle))
                known.add(submission_id)

        if len(page) < 500:
            break
        next_cursor = max(int(r["epoch_second"]) for r in page) + 1
        if next_cursor <= cursor:
            raise RuntimeError("AtCoder pagination cursor did not advance")
        cursor = next_cursor
        time.sleep(1.1)
    return fresh


def build_summary(data: dict[str, list[dict[str, Any]]]) -> dict[str, Any]:
    result: dict[str, Any] = {"platforms": {}}
    all_records = []
    for platform, records in sorted(data.items()):
        all_records.extend(records)
        accepted = [r for r in records if r.get("verdict") == "AC"]
        solved = {r["problem_id"] for r in accepted if r.get("problem_id")}
        latest = max(records, key=lambda r: int(r["epoch_second"])) if records else None
        result["platforms"][platform] = {
            "submissions": len(records),
            "accepted_submissions": len(accepted),
            "solved_problems": len(solved),
            "acceptance_rate": round(len(accepted) / len(records), 4) if records else 0.0,
            "latest_submission_at": latest["submitted_at"] if latest else None,
        }
    accepted = [r for r in all_records if r.get("verdict") == "AC"]
    latest = max(all_records, key=lambda r: int(r["epoch_second"])) if all_records else None
    result.update(
        total_submissions=len(all_records),
        accepted_submissions=len(accepted),
        latest_submission_at=latest["submitted_at"] if latest else None,
    )
    return result


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--accounts", type=Path, default=Path("config/submission_accounts.json"))
    parser.add_argument("--output-dir", type=Path, default=Path("data/submissions"))
    parser.add_argument("--summary", type=Path, default=Path("data/submission-summary.json"))
    parser.add_argument("--full-refresh", action="store_true")
    args = parser.parse_args()

    accounts = json.loads(args.accounts.read_text(encoding="utf-8"))
    data: dict[str, list[dict[str, Any]]] = {}

    for platform in ("codeforces", "atcoder"):
        handle = str(accounts.get(platform, "")).strip()
        if not handle:
            continue
        path = args.output_dir / f"{platform}.jsonl"
        existing = read_jsonl(path)
        current = {} if args.full_refresh else {
            str(r["submission_id"]): r for r in existing
        }

        if platform == "codeforces":
            fresh = fetch_cf(handle, set(current), args.full_refresh)
        else:
            fresh = fetch_at(handle, [] if args.full_refresh else existing, args.full_refresh)

        for record in fresh:
            current[str(record["submission_id"])] = record
        merged = list(current.values())
        data[platform] = merged
        write_jsonl(path, merged)
        print(f"{platform}: {len(fresh)} new, {len(merged)} total")

    if not data:
        raise RuntimeError("no submission accounts configured")

    args.summary.parent.mkdir(parents=True, exist_ok=True)
    args.summary.write_text(
        json.dumps(build_summary(data), ensure_ascii=False, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
