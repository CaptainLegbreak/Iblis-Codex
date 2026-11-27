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
- lane8/d2common-api-decls-2 c858c4ef4 (on #445): Items.cpp includes D2CommonApi.h and drops 25 private prototypes it repeats with the same types. To get there, ITEMS_GetDimensions, ITEMS_SetOwnerId and STATLIST_ExpireUnitStatlist lose the `extern "C"` that Items.cpp's and Inventory.cpp's declarations gave them (it put Items.cpp's own definitions in C linkage); they now have the C++ linkage the header and every other caller use. Independent of d2common-api-decls (no file in common). Full build: Game.exe identical, tree ce26bb1fe97a01aaffb2ec4f7d9ddc585473b9fc, borrowed code / data 7,923 / 261.
- lane8/d2common-api-decls 8400caacc (on #444): 11 D2Common units (Collisn, AnimTbls, MonsterTbls, OutRoom, Outdoors, Env, ItemMods, Path, UnitRoom, Unknown_006634F0, Unknown_006647C0) include D2CommonApi.h and drop 20 private prototypes it already declares with the same types. Units, Skills, Items, Inventory and Drlg keep theirs (the header's other declarations clash with their private ones or change a function there); ProfCore and Unknown_0064FAD0 are left to lane 2's use-shared-headers, which makes the same change there. Full build: Game.exe identical, tree ac42a2db7cd88d20939ab2224073ac74dd7f6dd5, borrowed code / data 7,923 / 261.

## Questions

## Notes for other lanes
- **Lane 2, D2CommonApi.h declares SKILLS_GetFirstSkillFromSkillList twice** (`// 0x0063D630` and `// 0x00643910`: the image has two copies, one each in Inventory.cpp and Skills.cpp). With the header included, each of those units' own definition reads the other copy's marker and comes out NO_SYMBOL, so Inventory.cpp and Skills.cpp can't take the header yet. Could the header keep only one of them (or neither, since each unit defines its own)? Units.cpp also stops matching with the header (two call targets, 0x00620150 and 0x006219F0); I'll look at that one on my side.
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
