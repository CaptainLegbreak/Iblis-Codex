# Lane 11

The naming part of the link debt (tools/linkdebt.py): declarations still carrying a placeholder name where the definition has a real one (different_identifier), and generated gData_<VA> definitions whose declarations have the real name (placeholder). One module, or a few small ones, per branch, largest first. Based on lane10/short-data until it is on main.

## Ready

- **lane11/names-d2game-3 3448e0f31, on main #481** (replaces names-d2game-2, which #479's headers conflicted with; redone on main with the same lists). Two commits:
  1. different_identifier: 280 placeholder spellings take their definition's name everywhere (4 with the unit's private placeholder declaration dropped); 61 stay.
  2. placeholder: 86 data plan entries generated as gData_<VA> now define their declared name; 14 stay.
  Link debt (measured on #478 with the same change): D2Game different_identifier 904 -> 723, placeholder 560 -> 427; no module rose. Audit guard against main: no count rose. Merges clean with #482 (git merge-tree). Full build on #481: VERIFIED tree e1de7970b4d48bad8477c0e04a807385aba78e9e, Game.exe identical, 14,927 / 14,927 placed, borrowed code 0, 0 not all equal.
- **lane11/names-d2client-4 e9652060a, on main #480** (replaces names-d2client-3, which #479's headers conflicted with; redone on main with the same lists, taking lane 12's types). Two commits:
  1. different_identifier: 133 placeholder spellings take their definition's name everywhere (8 with the unit's private placeholder declaration dropped); 186 stay, their units failing with the new name.
  2. placeholder: 85 data plan entries generated as gData_<VA> now define their declared name; 38 stay.
  Link debt: D2Client different_identifier 2,685 -> 2,417 and placeholder 1,043 -> 887 (main #478 against this branch's tree on #479; #479/#480 changed no D2Client name); no module rose. Audit guard against main: no count rose. #481 touched build/data_plan.json only, in other entries. Full build on #480: VERIFIED tree 6346b6f2fedb7ee57c522a3912a056b4b547aaaf, Game.exe identical, 14,927 / 14,927 placed, borrowed code 0, 0 not all equal.

## Claimed

- Fri Nov 27 12:07 PST 2026: **status for the coordinator.**
  - Merged: names-d2common (#482). names-d2client-4 (#483 or later, per the board).
  - **names-d2game-3: rebase onto #483 noted, doing it next** (same lists, redone on main; D2Game.h, MissMode.cpp, Missiles.cpp). From now on each rename branch leaves out files another lane has claimed (QuestLog.cpp and the rest in the Claimed lines) and picks them up once the claim clears.
  - In progress, not yet Ready: **lane11/names-small** (D2Win, D2Direct3D, Storm, D2BNClient, Fog, D2Glide, D2CMP, D2Sound and the rest): 45 placeholder spellings and 200 data plan names build equal unit by unit, but the full image differs (3 linker_output bytes, borrowed data 15,689 B) with Storm's data plan names; every other module's set gives an identical image. Bisecting the 31 Storm entries now; the branch posts without whichever entry does it.
  - Parked: D2Multi and D2Launch. Almost all their debt is in CharSel.cpp, MainMenus.cpp, ChatDlg.cpp and ComCallback.cpp (the declaration-count units); any of their 107 renames makes those build unequal, and leaving those files out breaks them (they use the renamed header spellings). They need the private declarations reconciled first.
  - What's left in the renamed modules is mostly type mismatches: the private placeholder declaration gives another return or parameter type than the real one (FOG_FreePool void vs int, BNMESSQUEUE_QueueMessage), so a rename alone collides. Those need callers reconciled one by one.
- Fri Nov 27 11:41 PST 2026: check-in. Small modules: 45 placeholder spellings and about 200 data plan names build; one Storm data plan entry makes the image differ (linker_output), finding which before posting.
- Fri Nov 27 09:44 PST 2026: check-in. D2Multi and D2Launch parked: nearly all their debt is in CharSel.cpp, MainMenus.cpp, ChatDlg.cpp and ComCallback.cpp, the declaration-count units, which build unequal (or fail to compile when left out) with any of the 107 renames. Working the small modules together now (155 spellings over D2Win, D2Direct3D, Storm, D2BNClient, Fog and the rest).
- Fri Nov 27 09:03 PST 2026: check-in. names-d2common merged (#482). names-d2game-3 posted. Next: D2Multi and D2Launch.
- Fri Nov 27 08:37 PST 2026: check-in. names-d2client-4 posted (the board's #479 rebase). names-d2game-2's rebase next, then D2Multi and D2Launch.
- Fri Nov 27 07:51 PST 2026: check-in. names-d2common posted on #479. Next: D2Multi and D2Launch (500+ different_identifier each), then the smaller modules.
- Fri Nov 27 07:11 PST 2026: check-in. names-d2game-2 posted on #478. Next: names-d2common on #478 (built once on #476; 18 spellings and 395 data plan names).
- Fri Nov 27 06:24 PST 2026: check-in. names-d2client-3 posted on #478 (the board's rebase request). Rebasing names-d2game onto #478 next, then posting names-d2common.
- Fri Nov 27 05:05 PST 2026: check-in. D2Common: of 59 placeholder spellings, the ones D2Common.h declares change how DATATBLS/ItemTbls.cpp compiles when renamed together (no single one does; the declaration-count effect), so this branch takes the 18 declared only in .cpp files; the D2Common.h group waits for lane 2/8's header work.
- Fri Nov 27 04:47 PST 2026: check-in. names-d2game posted. Next: D2Common, then a second pass for the older non-placeholder spellings (ordinal names like D2COMMON_10476, FOG_FreeServerMemory) whose definitions have other names.
- Fri Nov 27 03:32 PST 2026: check-in. D2Client's first branch is built and verified on main #474 (lane11/names-d2client-2); measuring main #474's own link debt for the before/after, then posting it Ready. Next: D2Game.
- Fri Nov 27 02:03 PST 2026: check-in. Link debt on lane10/short-data before any change: 30,698 refs (different_identifier 5,641, placeholder 3,406; D2Client 10,777). Working D2Client's different_identifier renames (319 placeholder spellings whose definition has a real name), building each round and dropping the ones whose units fail.
- Fri Nov 27 01:30 PST 2026: starting. D2Client first, then D2Game, then D2Common.

## Notes for other lanes
