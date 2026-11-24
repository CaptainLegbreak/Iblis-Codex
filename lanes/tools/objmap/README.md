# Placeholder object map

`objmap.py OUT.md [OUT.json]` (run from anywhere; `IBLIS_ROOT` picks the checkout, default the main one) reads the
original Game.exe, build/units.json, build/data_plan.json and the address markers on global definitions in the
sources. For every placeholder file (`Unknown_<addr>.cpp`) it scores every other file of the same module:

| Evidence | Points |
|---|---:|
| a source path string its code passes matches the file's name | 10 per use |
| a call edge to or from a function that only this pair of files calls (a static or private helper) | 3 |
| data the other file defines (2 if only the pair uses it) | 1 |
| the placeholder's code sits between two runs of the other file | 8 |
| next to the other file's run | 2 |

A lead is **clear** when the best score is at least 4 and at least twice the runner-up. It takes about 3 seconds.

Checked on main #339 against five joins the lanes made since (ItemMods, Skills, StatsEx, system.cpp,
Unknown_006B3570): the best candidate was the right file in all five, and three of the five were clear leads.
A lead still has to build equal. `report-369.md` is the run on main #369,
and 31 whole named files with a placeholder sitting between two of their own runs.
