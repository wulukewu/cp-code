# Annotated solution branch

This directory builds a machine-generated `annotated` branch for the competitive-programming archive.

`main` remains the source of truth. The workflow never commits generated metadata back to `main` and does not open pull requests. On every push to `main`, it starts from the latest `main`, annotates solutions it can match confidently, and force-updates the single `annotated` branch.

## Sources

- Codeforces: official `user.status` API
- AtCoder: AtCoder Problems `v3/user/submissions` API and public problem metadata

The annotator uses public metadata only. It does not require login cookies, repository secrets, or third-party Python dependencies.

Accounts are configured in `config/submission_accounts.json`.

## Matching

The annotator combines repository structure, filename/problem title, and the file's latest Git commit time. It prefers an accepted submission that occurred before the file commit when possible.

The source code itself is not downloaded from the judge and byte-for-byte equality is not claimed. Every generated header states that limitation explicitly.

Files that cannot be matched confidently are left untouched.

## Generated header

Matched C++ files receive a managed comment at the top containing the platform, problem and submission links, matched verdict, submission time, language, runtime, available memory/points/rating/tags, submission counts, and the file commit time.

The marker `cp-code:submission-metadata` allows the branch to be rebuilt idempotently without stacking duplicate comments.

## Branch lifecycle

```text
push main
   |
   v
checkout latest main
   |
   v
fetch public submission metadata
   |
   v
annotate all confidently matched solutions
   |
   v
force-update annotated
```

Every published `annotated` commit is therefore based directly on the current `main` commit. Old generated branch history is intentionally disposable.

## Running locally

```bash
python scripts/submissions/annotate.py
```

This edits matched files in the working tree and writes a report to `/tmp/submission-annotation-report.json` by default. Use `git diff` to inspect the generated annotations.
