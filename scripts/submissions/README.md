# Annotated solution branch

This directory builds a machine-generated `annotated` branch for the competitive-programming archive.

`main` remains the source of truth. The workflow never commits generated metadata back to `main` and does not open pull requests. On every push to `main`, it starts from the latest `main`, annotates solutions it can match confidently, and force-updates the single `annotated` branch.

## Sources

- Codeforces: official `user.status` API
- AtCoder: AtCoder Problems `v3/user/submissions` API and public problem metadata
- CPE / UVa: public uHunt problem metadata, including problem titles and run-time limits
- UVa submissions: optional uHunt user-submission enrichment when a `uva` username is configured

The annotator uses public metadata only. It does not require login cookies, repository secrets, or third-party Python dependencies.

Accounts are configured in `config/submission_accounts.json`. Codeforces and AtCoder are currently configured. A UVa username can be added later as an optional `uva` key; without it, CPE files still receive problem metadata but do not claim a UVa verdict or submission.

## Matching

For Codeforces and AtCoder, the annotator combines repository structure, filename/problem title, and the file's latest Git commit time. It prefers an accepted submission that occurred before the file commit when possible.

For `cpe/`, a leading numeric filename such as `12063_Zeros_and_Ones.cpp` is treated as a UVa problem number only when that number exists in the uHunt problem catalog.

The source code itself is not downloaded from the judge and byte-for-byte equality with an online submission is not claimed. Files that cannot be matched confidently are left untouched.

## Generated header

Matched files receive a managed comment headed by Luke's fixed ASCII signature:

```text
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::
```

The metadata below the signature is intentionally compact: platform, problem identity/link, verdict/language/runtime/memory when available, submission ID/time, and optional rating/tags/limits.

The marker `cp-code:submission-metadata` is kept inside the generated comment so reruns can replace the managed block without stacking duplicate comments.

The source body is handled as bytes. Adding or replacing the managed header does not normalize the solution's line endings, leading whitespace, trailing whitespace, or EOF newlines.

## Branch lifecycle

```text
push main
   |
   v
checkout latest main
   |
   v
fetch public judge metadata
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
python -m unittest discover -s scripts/submissions -p 'test_*.py'
python scripts/submissions/annotate.py
```

The annotator edits matched files in the working tree and writes a report to `/tmp/submission-annotation-report.json` by default. Use `git diff` to inspect the generated annotations.
