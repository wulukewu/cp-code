# Submission sync

This directory contains a dependency-free sync for public competitive-programming submission metadata.

## Sources

- Codeforces: official `user.status` API
- AtCoder: AtCoder Problems `v3/user/submissions` API

The sync stores metadata only. It does not scrape submitted source code, require login cookies, or use repository secrets.

Accounts are configured in `config/submission_accounts.json`.

## Output

Each platform is written to `data/submissions/<platform>.jsonl` using one normalized schema. `data/submission-summary.json` contains compact aggregate counts.

Records are deduplicated by submission ID and sorted deterministically, so a scheduled run with no new submissions produces no commit.

## Running locally

```bash
python scripts/submissions/sync.py
python scripts/submissions/validate.py
```

To rebuild the local dataset from remote history:

```bash
python scripts/submissions/sync.py --full-refresh
```

The GitHub Actions workflow runs once per day and can also be started manually. Pull requests that change the sync code perform a read-only sync and validation but never commit generated data.
