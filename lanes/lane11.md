# Lane 11

The naming part of the link debt (tools/linkdebt.py): declarations still carrying a placeholder name where the definition has a real one (different_identifier), and generated gData_<VA> definitions whose declarations have the real name (placeholder). One module, or a few small ones, per branch, largest first. Based on lane10/short-data until it is on main.

## Ready

- **lane11/names-d2game d5260ca9a, on main #476** (independent of names-d2client-2). Two commits:
  1. different_identifier: 280 placeholder spellings whose definition has a real name take that name, everywhere (11 with their private placeholder declaration dropped, the unit already seeing the real one). 61 stay, their units failing with the new name.
  2. placeholder: 86 data plan entries generated as gData_<VA> with an alias now define their declared name; 14 stay (their units fail with it).
  Link debt, main #474 -> this branch (measured before the rebase onto #476, which changed no D2Game file): 30,700 -> 30,549. D2Game 6,555 -> 6,425 (different_identifier 885 -> 704, placeholder 520 -> 420; type_disagreement 2,700 -> 2,851 where a renamed declaration now matches the definition's name but not its type), D2Client 10,777 -> 10,757, D2Common 4,801 -> 4,800; no module rose. Audit guard against #476: no count rose. Full build on #476: VERIFIED tree 78427f5774ee4826da27b53d7ab0515f80e5445b, Game.exe identical, 14,927 / 14,927 placed, borrowed code 0, 0 not all equal.
- **lane11/names-d2client-2 3390cee83, on main #474.** Two commits:
  1. different_identifier: 135 placeholder spellings (sub_<VA>, g..._<VA>, data_<VA>) whose definition has a real name take that name, everywhere; where the unit already sees the real declaration, its private copy of the placeholder one goes (52 of the 135). 184 more stay, because a unit fails with the new name (mostly two declarations of the name with different signatures in one unit; listed by the build, each needs its private declaration reconciled first).
  2. placeholder: 85 data plan entries generated as gData_<VA> with an alias to the declared name now define that name (head without the gData_ name, extern "C" only where the source declares it C, alternatename line gone). 38 stay, because their units fail with the real name (the source's declaration has another type modifier).
  Link debt, main #474 -> this branch: 30,700 -> 30,356 refs. D2Client 10,777 -> 10,442 (different_identifier 2,631 -> 2,361, placeholder 994 -> 875; type_disagreement 2,033 -> 2,082 and unsourced_data 1,894 -> 1,898, where a renamed declaration now matches the definition's name but not yet its type); D2Game 6,555 -> 6,547, D2Launch and D2Win down too; no module rose. Audit guard against #474: no count rose (pointer casts 4,922 -> 4,921). Full build: VERIFIED tree 53560f569d9962ebf79944ca02c9251a6e41a422, Game.exe identical, 14,927 / 14,927 placed, borrowed code 0, 0 not all equal.
## Claimed

- Fri Nov 27 04:47 PST 2026: check-in. names-d2game posted. Next: D2Common, then a second pass for the older non-placeholder spellings (ordinal names like D2COMMON_10476, FOG_FreeServerMemory) whose definitions have other names.
- Fri Nov 27 03:32 PST 2026: check-in. D2Client's first branch is built and verified on main #474 (lane11/names-d2client-2); measuring main #474's own link debt for the before/after, then posting it Ready. Next: D2Game.
- Fri Nov 27 02:03 PST 2026: check-in. Link debt on lane10/short-data before any change: 30,698 refs (different_identifier 5,641, placeholder 3,406; D2Client 10,777). Working D2Client's different_identifier renames (319 placeholder spellings whose definition has a real name), building each round and dropping the ones whose units fail.
- Fri Nov 27 01:30 PST 2026: starting. D2Client first, then D2Game, then D2Common.

## Notes for other lanes
