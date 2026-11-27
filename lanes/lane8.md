# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 reopened (new chat, 2026-11-26 12:00 PT). Owns `Source/D2Common/**` again, from lane 2; lane 2 keeps
`Source/Include` and the cross-module declarations (D2CommonApi.h). Focus order: forcing constructs, files in pieces,
scaffolding, names.

## Claimed
- File joins in D2Common, one branch each (`lane8/join-<file>`): `DataTbls/ItemTbls` (ItemTbls_00633730, ItemTbls_00634DC0),
  `DataTbls/DataTbls` (DataTbls_00613F80), `DataTbls/MissileTbls` (MissileTbls_00663270), `Composit/Composit`
  (Composit_0064F060), `Units/Missile` (Missile_0064B860). Lane 2 hadn't claimed any of them.

## Status
- Thu Nov 26 18:20 PT: check-in on #456; nothing new merged since #454, four branches still Ready. Continuing with the second pass of unreferenced bodies (stacked on d2common-dead-bodies).
- Thu Nov 26 18:17 PT: four branches Ready (missile-dead-views, path-views-2, path-dead-copies stacked on it, d2common-dead-bodies). Next: Missile.cpp's private Unit / Damage / MissileRecord views once missile-dead-views is in, then the rest of the unreferenced bodies (Preset.cpp's remaining Storm-link stand-ins).
- Thu Nov 26 17:47 PT: four branches Ready (statsex-accessor-views, path-accessor-views, path-views-2 stacked on it, missile-dead-views). D2Common's per-address views are nearly gone; what's left is DUNGEON_SaveKilledUnitGUID's (needs the header byte, note to lane 2), Unknown_00650D70's two `Pair<VA>` helpers, and Path.cpp's context copies (DrlgView/RoomStatusNode for DRLGACTIVATE_GetARoomInClientSight, LinkView for Fog's FOG_GetLinkIndexByCode).
- Thu Nov 26 17:15 PT: check-in on #452; drlg-api-decls, items-accessor-views and api-decls-3 are in, Ready lines gone. Building the next accessor-view branch (StatsEx, Inventory, Dungeon, Skills, Units); Path.cpp's 22 after it.
- Thu Nov 26 16:40 PT: **withdrawn: `lane8/d2common-api-decls` and `lane8/d2common-api-decls-2`** (don't merge them). Lane 2's `use-shared-headers-2b` (committed 15:59, before my note) makes the same change in 9 of their 11 units and in Items.cpp, more thoroughly. Only MonsterTbls.cpp and Unknown_006634F0.cpp aren't in it; they come back as a small `d2common-api-decls-3` once its full build is done. `drlg-api-decls` has no file in common with lane 2's branch and stays Ready.
- Thu Nov 26 16:30 PT: check-in on #447. Three header branches Ready (api-decls, api-decls-2 for Items.cpp, drlg-api-decls); Inventory, Skills and Units wait on D2CommonApi.h's duplicate SKILLS_GetFirstSkillFromSkillList (note to lane 2). Next: more D2Common scaffolding.
- Thu Nov 26 15:58 PT: check-in on #444. api-decls Ready (13 units take D2CommonApi.h); names-3 Ready. Next: the remaining D2Common scaffolding (private copies that D2Common.h could hold, unit by unit with the full build deciding).
- Thu Nov 26 15:58 PT: names-3 Ready. D2Common's a1/v12 names left are in ItemTbls.cpp and MissileTbls.cpp (declaration-sensitive; I leave them) and a few parameters whose meaning the code doesn't show (D2Common_10434's and 10236's flags, Path's unk0x67 setter). Next: D2Common scaffolding again.
- Thu Nov 26 15:30 PT: 0x6419F0: the plain range tests compare nX / nY in memory (`cmp [ebp-4], edx`) where the original loads them first (`mov ecx, [ebp-4]; cmp ecx, edx`); copies, a coordinate struct, and inline range helpers (min/max or centre/radius) all keep the memory compare. Parked with 0x651040 and 0x65EA50 (readings above); back to names and scaffolding.
- Thu Nov 26 15:35 PT: param-names and forcing-621f90 merged (#440), Ready lines gone; names-2 Ready. On 0x6419F0 now.
- Thu Nov 26 15:05 PT: forcing rows, readings so far (no branch):
  - 0x651040: the bottom-copy form (copy `nId = nNext` before the depth test, `while ((short)nId >= 0)`) gets the original's registers (7 instructions unaligned) but folds the preheader's conversion into the parent load, so it is 110 / 113: only the original's `movzx eax, ax` after `movzx eax, word [parent]` is missing. Reading nId straight from wParent: 5 unaligned, still 110. Function-scope declarations, every type pair for nNext/nId, and lane 2's top-of-loop copy (both conversions but the copy stays in the loop head, other registers) don't give it. The __assume keeps it by giving the converted value a use of its own before the loop; I have not found a plain statement that does the same.
  - 0x65EA50: the nValue load is hoisted above the `nSet` branch in every form (if/else, early return either way, swapped arms, switch, shifted-value / layer / record / stat-list temporaries, alias locals). The original's arms load it into different registers (eax in the set arm, edx in the add arm).
  - Going back to names and scaffolding between tries on these and 0x6419F0.
- Thu Nov 26 14:50 PT: Missile join, dup-decls and noinline-evidence merged (#437, #438), Ready lines gone. forcing-621f90 Ready. 0x65EA50: the nValue hoist survives every arm shape and temporary tried (early returns, swapped arms, switch, shifted-value and layer temporaries, alias locals); parked. On 0x651040 now (lane 2's top-of-loop copy, 38 bytes).
- Thu Nov 26 14:45 PT: param-names Ready. Lane 2 handed over D2Common's four forcing rows (lane2.md 14:25 PT): taking 0x621F90, 0x6419F0, 0x651040 and 0x65EA50 now, closest first (0x621F90, 1 byte).
- Thu Nov 26 14:12 PT: three piece notes merged (#434), their Ready lines gone. noinline-evidence Ready. Next: D2Common a1/v12 names, starting with ItemMods.cpp's property-function parameters.
- Thu Nov 26 14:10 PT: D2Common scaffolding: each of the 41 emit helpers removed alone and its unit rebuilt; only 0x0061B810's comes out (Ready, with the repeated declarations). Next: the eight `noinline`s with no evidence comment (Units, MonsterTbls, Items x2, RoomTile, Preset, Inventory x2).
- Thu Nov 26 13:58 PT: Missile_0064B860 joined into Missile.cpp (Ready). D2Common joins left: DataTbls_00613F80 (waiting on lane 7's 0x613F80). Then scaffolding in Source/D2Common.
- Thu Nov 26 13:32 PT: ItemTbls_00634DC0 parked with its reason too (Ready). MissileTbls note merged in #432, its Ready line gone. On Missile_0064B860 now.
- Thu Nov 26 13:25 PT: the ItemTbls_00633730 and Composit joins don't build equal; both pieces get reason comments (Ready). The ItemTbls_00634DC0 join flips the same way, its comment branch is in its full build. Next: Missile_0064B860, then DataTbls_00613F80 once lane 7 is done with it.
- Thu Nov 26 13:25 PT: the three identical-arm rows re-read on #430 and handed to lane 7 (Notes); back on the D2Common joins.
- Thu Nov 26 13:05 PT: baseline on #429 clean. MissileTbls join tried and parked (comment branch Ready). Next: the three identical-arm rows (Claimed), starting with 0x62FFF0 (4 bytes off in the helper form on 2026-11-25).
- Thu Nov 26 12:20 PT: setting up (repo, board, wine done; waiting for Game.exe, then setup and the baseline build).

## Ready
- lane8/d2common-bare-subs a097bcaad (on #458): 19 D2Common functions named only `sub_<address>` take the names D2MOO gives the same 1.14d addresses in its `1.14d: 0x...` comments (ITEMS_AssignPrefix / AssignSuffix / AssignRareSuffix / CheckItemFlag, STATLIST_ClampStaminaManaHP, PATH_SetDirection, PATH_ComputeSquaredDistance, D2Common_10399, SEED_SetSeeds / GetSeeds, DATATBLS_UnloadInventoryTxt / GetInventoryRect / GetInventoryGridInfo / GetInventoryComponentGrid, DRLGOUTDOORS_InitAct4OutdoorLevel, DRLG_OUTDOORS_GenerateDirtPath, DATATBLS_Return2, D2COMMON_10018_Return0, D2COMMON_11062_Return). names.csv, build/units.json, functions.json and every caller follow, so this touches 15 units outside D2Common and D2CommonApi.h (lane 2) by the rename only; five callers whose own `extern "C"` copy then clashed with a shared declaration drop the copy, and a3q6.cpp's distance test keeps its unsigned compare with a cast. COLLISION_SetCollisionMask (0x0064DDB0) is left: names.csv has that name at 0x0064CAF0. Full build: Game.exe identical, tree c89f50e07ac0615545f210b3fa16772d85f0bb3e, borrowed code / data 5,424 / 261.
- lane8/d2common-dead-bodies-2 a9a60a96c (on lane8/d2common-dead-bodies 2e16847d8, merge that first): the second pass, 31 more uncalled bodies (274 lines): Unknown_0067B9C0.cpp's unused A* helpers, Items.cpp's unused type and record getters and empty stand-ins, Preset.cpp's never-called Storm list stand-ins, Inventory.cpp's unused SKILLS_GetSkillById copy. Full build: Game.exe identical, tree 1a8f2fd3b8fdcfd4c80e72f8b6cb5d7e8969a3cc, borrowed code / data 7,677 / 261.
- lane8/d2common-dead-bodies 2e16847d8 (on #455): 23 D2Common units drop unmarked function bodies that no code in the unit calls and no build entry names (563 lines): unused inline copies of getters (stat-cost, skills, missiles, states, mon-stats, animation-mode tests, positions), never-called stand-ins of other modules' empty or constant functions, and leftovers like DRLGPRESET_AddTombStoneTiles, ITEMS_SetItemFlags and Dungeon.cpp's sub_F45 visitors. Bodies the build matches by name (Unknown_00624740, OutDesr) or a data table references (ItemMods) stay. May touch neighbouring lines of missile-dead-views in Missile.cpp and Dungeon.cpp. Full build: Game.exe identical, tree 4e080a51cdaf840521cd54d9da8da8593204a8c8, borrowed code / data 7,677 / 261.

## Questions

## Notes for other lanes
- **Lane 2, D2ActiveRoomStrc's `nCurrentDeathIndex` (0x14) is a byte in the game:** DUNGEON_SaveKilledUnitGUID (0x0061AFA0) reads and writes it with `movzx ecx, byte [eax+0x14]` / `mov byte [eax+0x14], cl` (the ring index for `nLastDeadGUIDs[4]` at 0x38). With D2Drlg.h's `int` the function comes out with dword accesses, so it keeps a private view until the header says `unsigned char nCurrentDeathIndex; unsigned char unk0x15[3];` (or similar). Your call; tell me if you change it and I'll drop the view.
- **Lane 2, D2CommonApi.h declares SKILLS_GetFirstSkillFromSkillList twice** (`// 0x0063D630` and `// 0x00643910`: the image has two copies, one each in Inventory.cpp and Skills.cpp). With the header included, each of those units' own definition reads the other copy's marker and comes out NO_SYMBOL, so Inventory.cpp and Skills.cpp can't take the header yet. Could the header keep only one of them (or neither, since each unit defines its own)? Units.cpp is blocked by the same pair: its calls to the function (in 0x00620150 and 0x006219F0) get "mapped to different addresses by markers of the same precedence".
- **Lane 2, `use-shared-headers` touches six D2Common units** (Composit_0064F060, DrlgActivate, Preset, ProfCore, StatsEx, Unknown_0064FAD0). Fine to keep them in that branch: they're the same kind of change as my `d2common-api-decls`, and I've taken ProfCore and Unknown_0064FAD0 out of mine so the two don't conflict. From here on please leave Source/D2Common to me; tell me here if one of your header changes needs a D2Common unit edited and I'll do it.
- **Lane 7, three more D2Common forcing rows parked and handed over** (lane 2's and my readings are in my Status, 15:05 and 15:30 PT): 0x651040 (`__assume`, bottom-copy form one `movzx eax, ax` short), 0x6419F0 (volatile, the range tests' nX / nY register loads), 0x65EA50 (volatile, the nValue hoist). All three look like allocator or hoisting decisions your c2diag reads; take any you want, and say so here. I'm not on them now.
- **Everyone with a declaration-sensitive unit: what flips ItemTbls.cpp's 0x00633F40.** Its only difference when it flips is the operand order of `nRareSuffixCount + nRarePrefixCount` (two address-taken locals): which of the two is loaded into ecx. The order does not follow the locals' names (six renamings, same result either way) and does not follow anything declared after the function. It follows the number of symbols declared before it: adding N dummy enumerators near the top gives equal for N = 0, 4, 5, 6, 7, 13 and the flip for 1-3, 8-12, 14-20 (an extern counts the same as an enumerator). So any declaration added or removed above that function is a coin flip, and a join is only safe if what it adds sits after the functions that tie like this. With the sets loader's include placed just above it (after 0x00633F40), 0x00633F40 stays equal and only the loader itself differs (it caches three table constants in registers, and their order also moves with the count). Other units' commutative-operand flips may be the same thing.
- **Lane 7, three D2Common forcing rows handed over** (identical if/else arms; plain forms re-read today on #430, one
  unit build each; none uses a forcing construct, and each is a register or slot choice, your c2diag's ground):
  - **0x62FFF0 ITEMS_SerializeItemComplete (Items.cpp ~7449, the stat writer's `if (nStats > 1)` pair).** The arms
    as one plain `if (nStatId < 0) goto L_NO_RECORD;` give 4,800 / 4,800 with 4 unmasked bytes: nStats and nLayer
    swap their frame slots (-0x14 / -0x18). The original's `nStats > 1` test is not in its code, so the compiler
    deleted it after weighing; its extra nStats reference is what puts nStats nearer ebp. No change from nLayer read
    from the record's `nLayer` field, from nStatId from `nStat`, or from the two declarations swapped. Worse: no
    nLayer local (the frame changes), an explicit `if (nStats > 0) do {} while (++i < nStats)` (shape changes).
    D2MOO has `while (nStatCounter < nStats)` and no layer local.
  - **0x613F80 DATATBLS_LoadSkills_SkillDescTxt (DataTbls_00613F80.cpp ~542, the passive-skill count's
    `if (nSkillId > 0)` pair).** As `if (pSkillsTxtRecord->nPassiveState >= 0) ++gnPassiveSkills;` it differs in 6
    bytes, all one swap at the loop entry: the original zeroes the counter in edx and the record offset in esi, ours
    the other way round. Same pattern as 0x62FFF0 (the counter's deleted test lifts it).
  - **0x61F500 DATATBLS_LoadLvlSubTxt (LvlTbls.cpp ~879, the type-start loop's `dwType > lastType` pair).** D2MOO
    writes the loop with no inner test. Yesterday's reading still holds: every plain form swaps edi/edx in that loop
    and also flips 0x61FCF0 in the same unit, so LvlTbls.cpp is sensitive to its own text.
  - I'm not on any of them now, and DataTbls_00613F80.cpp stays untouched by me while you have it (I'll join it into
    DataTbls.cpp after). If you'd rather I keep one, say so here.
- **Coordinator, a forcing construct the counts miss:** MissileTbls.cpp (0x00661B20 DATATBLS_LoadMissilesTxt, the
  line with `_ReadWriteBarrier();` and its `#pragma intrinsic` at the top of the file) uses a compiler barrier. The
  audit counts (volatile, pragma optimize, bare `__assume`, identical arms) don't include barriers. Lane 8 takes it as
  a D2Common forcing row unless you say it isn't one; it is also why the MissileTbls join is hard (the loader is
  declaration-sensitive).
- **Lane 2, thanks for the four forcing rows' readings** (lane2.md 14:25 PT); lane 8 has them now. Old note: (0x621F90, 0x6419F0, 0x651040, 0x65EA50): your 12:10 PT status says you've just
  started on them. Branches in flight stay yours, so tell me here which you finish and which you hand back; until then I
  leave all four to you and work the D2Common file joins (Claimed). Anything you hand over, I take from your notes and
  pushed branches. Your three borrowed drafts (0x62B5B0 with lane 4 now, 0x677880, 0x679C80) stay paused and untouched.
- VC8 behaviours found while removing forcing constructs (each reproduced in a test build), in case they match one of yours:
  - **A store the original repeats** (e.g. `x = 0; ...; x = 0;` with nothing reading x between) survives when the second store is written in **both arms of the following if/else**: the compiler hoists the common store above the branch after dead-store elimination has run, so both stores stay (0x649970).
  - **A range check `v >= 0 && v < N` on one value** is merged into one unsigned compare (`cmp bl, N-1 / ja`). The original's two-test form (`test bl, bl / jl / cmp bl, N / jge`) comes out when the source reads the field twice (`(c = p->f) >= 0 && p->f < N`): the merge runs before the two loads are combined, and they still end up in one register (0x62B5B0's class check).
  - **Statement order of plain field stores** after a call is kept as written (0x649970's unk0x38 / tPrevTargetCoord stores needed the original's order, no volatile).
  - **Spilled locals with equal weight** get stack slots in declaration order, the latest declared nearest ebp.

## Left in place (and why)
- DataTbls.cpp owns two language copies (0x7442C8, 0x74430C). Inventory.cpp also owns two (0x744760, 0x7447CC), but its asserts run monotonically to 0x63E510 and D2MOO keeps its component map (after the second copy) in Inventory.cpp, so a second copy doesn't by itself mean a second object. Neither is split. Unknown_006115F0 (the empty 0x6115F0, called from D2Client 0x44B400) sits between Ignorelist and ProfCore with no evidence for either.
- Unknown_00627250 (0x6275B0) into StatsEx.cpp: the original inlines STATLIST_UnitGetStatValue but calls STATLIST_GetTotalStat out of line. In StatsEx the call goes to the `int nLayer` prototype (not inlined); fixing the prototype or adding an inline copy inlines GetTotalStat too. Not moved.
- 0x653ED0-0x653F84 (Dungeon.cpp, the unique-monster name builders inside MonsterTbls' run): they read the name tables through Dungeon's gpUniqueNameTxtTables[] macros, which MonsterTbls declares differently. Not moved yet.
- 0x625560 (DataTbls.cpp, inside StatsEx's run): moved, it doesn't build equal in StatsEx.
