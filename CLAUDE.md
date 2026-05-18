# Claude Code Project Memory

This repository is a personal CSP exam practice workspace. The user is a university student practicing algorithms in C.

## Communication

- Respond to the user in Simplified Chinese.
- Explain concepts step by step and keep explanations beginner-friendly.
- When reviewing code, focus on input/output, array bounds, data ranges, edge cases, and time/space complexity.

## Core Rule: Do Not Solve Practice Problems Directly

- The user is practicing. Do not write the full solution unless explicitly asked.
- If the user's code is wrong, do not edit it directly.
- Instead, point out the exact issue, explain why it is wrong, and tell the user how to fix it.
- Prefer hints, boundary cases, and reasoning prompts before giving a complete answer.
- Only edit problem solution code when the user clearly says something like "help me modify the code" or "directly edit the file".

## Project Structure

Main practice directory:

```text
csp-practice/
  README.md
  leetcode-practice-list.md
  templates/
    c_template.c
    notes_template.md
  problems/
    001-lc704-binary-search/
      main.c
      notes.md
      input.txt
```

For each new problem, use:

```text
csp-practice/problems/NNN-lcXXX-problem-name/
  main.c
  notes.md
  input.txt
```

## C Coding Preferences

- Use C by default, not C++ or Python.
- Keep sample code simple and readable.
- Avoid clever macros or advanced tricks unless the user asks.
- Mention `long long` when integer overflow may be possible.
- Choose array sizes based on problem constraints.
- Comments should be short and useful.

## Practice Workflow

When the user starts a new problem:

- Create the problem folder, `main.c`, `notes.md`, and `input.txt`.
- Provide only a function skeleton and hints.
- Do not fill in the algorithm.

When the user says they finished a problem:

- Read their code.
- Prefer the repository run script:

```powershell
.\scripts\run.ps1 012-lc70-climbing-stairs
```

- If the script is not suitable, compile with warnings manually, for example:

```powershell
gcc -Wall -Wextra -std=c11 .\csp-practice\problems\XXX\main.c -o .\csp-practice\problems\XXX\main.exe
```

- Run the sample and a few important edge cases.
- Report problems and how to fix them without editing code.

When the user says LeetCode accepted the solution:

- Update the relevant `notes.md` with:
  - problem statement summary
  - user's approach
  - key edge cases
  - mistakes encountered
  - complexity
  - local test record
  - review summary
- Update `csp-practice/README.md`.
- Update `csp-practice/leetcode-practice-list.md`.

## Git Workflow

- The user prefers batching saves to reduce tool usage.
- It is okay to check several problems first, then update notes and commit/push together.
- Build outputs such as `*.exe` are ignored and should not be committed.
- Before committing, check:

```powershell
git status --short --branch
git status --ignored --short
```

## Current Study Source of Truth

- Use `csp-practice/leetcode-practice-list.md` as the main problem checklist.
- Use each problem's `notes.md` as the review record.
- Use `git status --short --branch` to see whether work has already been committed or pushed.
