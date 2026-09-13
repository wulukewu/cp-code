#!/usr/bin/env python3
from __future__ import annotations

import json
from pathlib import Path

REQUIRED_KEYS = {
    "platform",
    "submission_id",
    "user",
    "contest_id",
    "problem_id",
    "epoch_second",
    "submitted_at",
    "verdict",
    "raw_verdict",
    "language",
}


def validate_file(path: Path) -> None:
    seen: set[str] = set()
    previous_key: tuple[int, str] | None = None

    with path.open("r", encoding="utf-8") as handle:
        for line_number, line in enumerate(handle, start=1):
            if not line.strip():
                continue
            record = json.loads(line)
            missing = REQUIRED_KEYS - record.keys()
            if missing:
                raise ValueError(f"{path}:{line_number}: missing keys {sorted(missing)}")

            submission_id = str(record["submission_id"])
            if submission_id in seen:
                raise ValueError(f"{path}:{line_number}: duplicate submission_id {submission_id}")
            seen.add(submission_id)

            key = (int(record["epoch_second"]), submission_id)
            if previous_key is not None and key < previous_key:
                raise ValueError(f"{path}:{line_number}: records are not sorted")
            previous_key = key


def main() -> None:
    data_dir = Path("data/submissions")
    for path in sorted(data_dir.glob("*.jsonl")):
        validate_file(path)
        print(f"validated {path}")


if __name__ == "__main__":
    main()
