# Iblis-Codex coordination

This branch (`coord`) is the message board between the lanes and the coordinator. It never merges into `main`
and nothing in it is built. Check it before you start work and every time you push.

    git fetch origin coord
    git show origin/coord:COORDINATOR.md        # decisions, holds, merge log (coordinator writes)
    git show origin/coord:lanes/laneN.md        # your own file (you write)

## Files

| File | Written by | What goes in it |
|---|---|---|
| `COORDINATOR.md` | coordinator only | decisions and answers, branches held back and why, what each round merged, notes for a lane |
| `lanes/laneN.md` | lane N only | your ready lines, questions for the coordinator, notes for other lanes, things you left and why |

Each writer owns its file, so pushes never conflict. Read the others; write only your own.

## How a lane posts

1. Push your work branch as usual (`laneN/<topic>`), based on current `main`, rebased right before you push.
2. Edit `lanes/laneN.md` on the `coord` branch and push it:

        git fetch origin coord && git checkout -B coord origin/coord
        # edit lanes/laneN.md
        git commit -am "laneN: <one line>" && git push origin coord

   If the push is rejected because someone else pushed, `git pull --rebase origin coord` and push again:
   your file is yours, so the rebase never conflicts.
3. Newest entries go at the top of each section. Delete what is done or answered.

## Ready line format

    laneN/<branch> <sha> <placeholders before>-><after> <what it does, one line>; VERIFIED <tree>

Also say if the branch is stacked on another, and anything it touches outside your lane.

## Questions

Put them under `## Questions` in your file, one bullet each, with the evidence. The coordinator answers in
`COORDINATOR.md` under your lane's heading and removes the question when answered. Keep working on other
things meanwhile; don't wait.

## Rules that save everyone time

- Rebase on `origin/main` right before you push. Most merge fixes so far came from stale bases.
- A branch must pass your precheck and a full verify (VERIFIED tree, 14,918/14,918, borrowed code 12,041 B / 9 functions).
- Don't touch files another lane owns unless `COORDINATOR.md` says you may.
- When a placement moves data into a file for the first time, make sure the file includes its `gen/data/<path>.inc`.
- Don't force-push shared branches; push a new name (`-2`, `-r2`) instead and say it replaces the old one.
