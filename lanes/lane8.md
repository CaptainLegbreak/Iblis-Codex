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
- Thu Nov 26 14:10 PT: D2Common scaffolding: each of the 41 emit helpers removed alone and its unit rebuilt; only 0x0061B810's comes out (Ready, with the repeated declarations). Next: the eight `noinline`s with no evidence comment (Units, MonsterTbls, Items x2, RoomTile, Preset, Inventory x2).
- Thu Nov 26 13:58 PT: Missile_0064B860 joined into Missile.cpp (Ready). D2Common joins left: DataTbls_00613F80 (waiting on lane 7's 0x613F80). Then scaffolding in Source/D2Common.
- Thu Nov 26 13:32 PT: ItemTbls_00634DC0 parked with its reason too (Ready). MissileTbls note merged in #432, its Ready line gone. On Missile_0064B860 now.
- Thu Nov 26 13:25 PT: the ItemTbls_00633730 and Composit joins don't build equal; both pieces get reason comments (Ready). The ItemTbls_00634DC0 join flips the same way, its comment branch is in its full build. Next: Missile_0064B860, then DataTbls_00613F80 once lane 7 is done with it.
- Thu Nov 26 13:25 PT: the three identical-arm rows re-read on #430 and handed to lane 7 (Notes); back on the D2Common joins.
- Thu Nov 26 13:05 PT: baseline on #429 clean. MissileTbls join tried and parked (comment branch Ready). Next: the three identical-arm rows (Claimed), starting with 0x62FFF0 (4 bytes off in the helper form on 2026-11-25).
- Thu Nov 26 12:20 PT: setting up (repo, board, wine done; waiting for Game.exe, then setup and the baseline build).

## Ready
- lane8/d2common-dup-decls 84d59e36 (on #433): 24 declarations in 16 D2Common units that repeat token for token a prototype, extern or typedef from D2Common.h or an included Source/Include header go; DrlgActivate.cpp's emit helper for 0x0061B810 goes (the static builds equal without it; emit helpers 394 -> 393). ItemTbls.cpp's four repeats stay: removing them flips 0x00633F40 again. Full build: Game.exe identical, tree 79418873d3d9879748559e722aa9cbab778e38ac, borrowed code / data 8,373 / 261.
- lane8/join-missile-damage 7b34cd96 (on #432): Missile.cpp takes in MISSILE_CalculateDamageData (0x0064B860) from Missile_0064B860.cpp, which goes. The marked function replaces Missile.cpp's unmarked copy of it, and the four static damage helpers (0x0064A850, 0x0064A930, 0x0064AA60, 0x0064ABA0) take their arguments in the caller's order (damage record or unit first), which is what gives the caller its 0x30-byte frame (0x34 with the old order). Every Missile.cpp function equal; files in pieces 109 -> 108. Full build: Game.exe identical, tree 0ac6009fd4233a591b327cfdbf155996260b5cbb, borrowed code / data 8,373 / 261.
- lane8/itemtbls-sets-piece-note 35f8a485 (on #431): ItemTbls_00634DC0.cpp says why the sets loader stays its own file (moved into ItemTbls.cpp with the shared set records, it permutes the registers holding its repeated table constants and 0x00633F40 swaps its record-count loads). Comment only. Full build: Game.exe identical, tree 1b2f7bf03b6adee14a55323a38ea915cf2a3dcd4, borrowed code / data 8,373 / 261. (The audit guard against #432 flags the 1.10-name count only because #432 renamed names; against its base #431 no count rose.)
- lane8/composit-piece-note e565f0d4 (on #431): Composit_0064F060.cpp says why COMPOSIT_GetWeaponClassCode stays its own file (with its body in Composit.cpp, the compiler folds 0x0064F5B0's object-mode call `COMPOSIT_GetWeaponClassCode(unit, 2, ...)` to ' hth' and drops it, wherever the body sits; the joined 0x0064F060 itself builds equal). Comment only. Full build: Game.exe identical, tree 97f48ce36c36be3bd9490ae4ddf3201b7a19bf4d, borrowed code / data 8,373 / 261.
- lane8/itemtbls-piece-note 7018a03a (on #431): ItemTbls_00633730.cpp says why the affix loader stays its own file (moved into ItemTbls.cpp, it and 0x00633F40 swap their record-count loads; adding only its two field types to ItemTbls.cpp's enums already flips 0x00633F40, wherever the members go). Comment only. Full build: Game.exe identical, tree 26ae6e1250f6a03f7c16bde73b13ecb6af44a893, borrowed code / data 8,373 / 261.

## Questions

## Notes for other lanes
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
- **Lane 2, D2Common's four forcing rows** (0x621F90, 0x6419F0, 0x651040, 0x65EA50): your 12:10 PT status says you've just
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
