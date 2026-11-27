# Lane 11

The naming part of the link debt (tools/linkdebt.py): declarations still carrying a placeholder name where the definition has a real one (different_identifier), and generated gData_<VA> definitions whose declarations have the real name (placeholder). One module, or a few small ones, per branch, largest first. Based on lane10/short-data until it is on main.

## Ready

- **lane11/names-d2game-2 7680fb135, on main #478** (replaces names-d2game, which conflicted with #477; redone on #478 with the same lists). Two commits:
  1. different_identifier: 280 placeholder spellings take their definition's name everywhere (4 with the unit's private placeholder declaration dropped); 61 stay, their units failing with the new name.
  2. placeholder: 86 data plan entries generated as gData_<VA> now define their declared name; 14 stay.
  Link debt, main #478 -> this branch: 27,112 -> 26,949. D2Game 5,384 -> 5,242 (different_identifier 904 -> 723, placeholder 560 -> 427; type_disagreement 2,704 -> 2,876 where the renamed declaration now matches the definition's name but not its type), D2Client 9,690 -> 9,670, D2Common 4,368 -> 4,367; no module rose. Audit guard against #478: no count rose. Full build: VERIFIED tree 86b85b611603812228b838e40a343c8e3a6fa7db, Game.exe identical, 14,927 / 14,927 placed, borrowed code 0, 0 not all equal.
- **lane11/names-d2client-3 d1c184ce6, on main #478** (replaces names-d2client-2, held for the j230 conflicts; rebuilt on main: the first commit rebased clean, the data plan commit was redone with the same rule on #477's data plan). Two commits:
  1. different_identifier: 135 placeholder spellings take their definition's name everywhere (52 with the unit's private placeholder declaration dropped); 184 stay, their units failing with the new name.
  2. placeholder: 85 data plan entries generated as gData_<VA> now define their declared name; 38 stay.
  Link debt, main #477 -> this branch (#478 changed tools only): 29,819 -> 29,460. D2Client 10,591 -> 10,241 (different_identifier 2,631 -> 2,361, placeholder 1,012 -> 878; type_disagreement 2,051 -> 2,100, unsourced_data 1,892 -> 1,896), D2Game, D2Common, D2Multi, D2Launch, D2Win down or level; no module rose. Audit guard against main: no count rose. Full build on #478: VERIFIED tree 88eecaacdb0c8a04c0231cb8b886a19df69f36cd, Game.exe identical, 14,927 / 14,927 placed, borrowed code 0, 0 not all equal.

## Claimed

- Fri Nov 27 07:11 PST 2026: check-in. names-d2game-2 posted on #478. Next: names-d2common on #478 (built once on #476; 18 spellings and 395 data plan names).
- Fri Nov 27 06:24 PST 2026: check-in. names-d2client-3 posted on #478 (the board's rebase request). Rebasing names-d2game onto #478 next, then posting names-d2common.
- Fri Nov 27 05:05 PST 2026: check-in. D2Common: of 59 placeholder spellings, the ones D2Common.h declares change how DATATBLS/ItemTbls.cpp compiles when renamed together (no single one does; the declaration-count effect), so this branch takes the 18 declared only in .cpp files; the D2Common.h group waits for lane 2/8's header work.
- Fri Nov 27 04:47 PST 2026: check-in. names-d2game posted. Next: D2Common, then a second pass for the older non-placeholder spellings (ordinal names like D2COMMON_10476, FOG_FreeServerMemory) whose definitions have other names.
- Fri Nov 27 03:32 PST 2026: check-in. D2Client's first branch is built and verified on main #474 (lane11/names-d2client-2); measuring main #474's own link debt for the before/after, then posting it Ready. Next: D2Game.
- Fri Nov 27 02:03 PST 2026: check-in. Link debt on lane10/short-data before any change: 30,698 refs (different_identifier 5,641, placeholder 3,406; D2Client 10,777). Working D2Client's different_identifier renames (319 placeholder spellings whose definition has a real name), building each round and dropping the ones whose units fail.
- Fri Nov 27 01:30 PST 2026: starting. D2Client first, then D2Game, then D2Common.

## Notes for other lanes
