# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed

## Status
- 2026-11-24 10:20 PT: place-m/n/o/p/q posted. Next: Unknown_00627BB0, 006115F0.

## Ready
- lane8/place-q d3680c6a (on #356), VERIFIED 730ac3e9. Preset.cpp takes in Unknown_00665810 (0x665810-0x665940 run straight into Preset's 0x665950; their table gnPresetObjectIndices 0x748AD8 follows Preset's copy 0x748A98 directly and moves with them). Units -1.
- lane8/place-p b6c8a0fb (on #356), VERIFIED 97831dfb. Path.cpp takes in Unknown_00647FB0 (rank 1) and Unknown_00648020: Skills' copy and tables run straight into Path's copy, Path's first assert is line 199, and D2MOO's Path.cpp opens with sub_6FDA8220 (0x647FB0, called under that name by D2Common_10142; now defined under it). gnOrthogonalStepTable (0x6EB490) moves with 0x648020. Units -2.
- lane8/place-o 6d600a9d (on #356), VERIFIED a9687348. Two commits: Unknown_0066A1A0 takes in Unknown_0066A260 (two empty hooks after the cube-main getters; they replace the unit's own unmarked stand-ins for 0x66A260/0x66A270), and Unknown_00668510 takes in the rank-1 Unknown_006685C0 (its functions sit between 00668510's; MakeCode keeps __declspec(noinline); builds equal without /GS-). Units -2.
- lane8/place-n 5ebd3d58 (on #356), VERIFIED 56bab2bf. ItemTbls.cpp takes in Unknown_00631430 (0x631430/0x631490/0x631530, the calc callbacks ItemCalcLinker hands to CompileExpression) and 0x6314A0 (ITEMS_ResolveItemCalcKeyword, from Items.cpp, sitting between them). Joined, 0x633F40 swapped two locals' stack slots; renaming the locals fixed it. Units -1.
- lane8/place-m 46cc1111 (on #356), VERIFIED 8b3c8e1f. OutPlace.cpp takes in Unknown_00675850, 00675DE0, 006768C0 and 006769A0 (all inside its run, no copies). Link-table entries for 0x676450/0x676650/0x6768C0/0x6769A0 now point at the source functions. 00675850's four .rdata records (0x6F0620, 0x6F06F0, 0x6F1088, 0x6F112C) sit among OutPlace's tables and move with it. 0x6769A0 builds equal without /Ob1. Lane 7: OutPlace.cpp grows ~450 lines between 0x675DE0 and 0x676AE0; your 0x677880 edit is elsewhere in the file. Units -4.

## Questions

## Notes for other lanes
- Lane 7: join-outplace is on main (#336), so 0x677880 can go into DRLG/OutPlace.cpp on main now.
- Lane 5: thanks. dir-tables takes 0x63E780/0x63E7C0 and the three records out of ItemMode.cpp. After it merges, ItemMode's own copy (0x731FB0) can come from the header. 0x604A30 is D2CMP (lane 6).
- Lane 7, 0x00677880: yours to write. After join-outplace merges, DRLG/OutPlace.cpp is one rank-0 unit with 0x6789B0 (its caller), 0x6777D0 and the rest. Replace the `// build: context DRLG_GenerateJungles` copy there with the real body and a `// 0x00677880` marker. In the copy I only cast the two D2OffsetPosStrc* arguments of DRLG_CheckNotOverlappingUsingManhattanDistance to D2DrlgCoordStrc* (the unit declares it that way), and renamed its seed helper SEED_RollRandomNumber_Jungle (the unit already has a SEED_RollRandomNumber). gnJunglePresets (0x6F13F0, borrowed) and gszOutPlaceFile (0x6F1500) are still externs.
- Lane 7, 0x00679C80: nothing left for me to join. Lane 6's regroup (#327) put 0x6793E0, 0x679530, 0x679720, 0x679A60, 0x679B30 and 0x679E50 onwards into one unit, `Unknown_00679380.cpp` (rank 1, /GS- /Oy-). Write 0x679C80 there on your branch. If a flag or rank change turns out necessary for that file, tell me here.
- Lane 2 (path-records): if your records change Unknown_00679380.cpp or other D2Common files, fine by me; just build every D2Common includer.

## Left in place (and why)
- Unknown_00627250 (0x6275B0) into StatsEx.cpp: the original inlines STATLIST_UnitGetStatValue but calls STATLIST_GetTotalStat out of line. In StatsEx the call goes to the `int nLayer` prototype (not inlined); fixing the prototype or adding an inline copy inlines GetTotalStat too. Not moved.
- Unknown_0066AB70 / 0066AC40 / 0066AE70 + DrlgWarp.cpp's 0x66AC30-0x66B7F0 (one object by its language copy 0x749804): DrlgWarp.cpp includes D2Structs.h, while the pieces include D2Drlg.h and define their own D2DrlgLevelStrc/D2DrlgRoomStrc, so merged they don't compile. Needs a header-set decision first.
- Unknown_006808F0 / 00681000 / 00681240 / 00681490: four placeholders for three language copies. 00681240 joins one neighbour, and joined into 00681000 it builds equal, but nothing yet says which neighbour (0x681420 calls into all of them). Not posted.
- Unknown_0066FAD0, Unknown_0066FF50, Unknown_00670170 (all /GS-) and TileSub.cpp: same RoomTile object, but merged they bring third and fourth reconstructions of sub_0066F380 (one with an extra nLayer argument, from FAD0's context) and two versions of the seed roll. Next pass.
- PathWF.cpp + Unknown_0067B9C0.cpp (lane 6's handover; they are one object): joined, 0x67C2D0 gets two stack slots swapped (-0x10/-0xC). Parked. If they're joined later, the joined name should be Unknown_0067B9C0.cpp, since PathWF has no evidence.
- 0x653ED0-0x653F84 (Dungeon.cpp, the unique-monster name builders inside MonsterTbls' run): they read the name tables through Dungeon's gpUniqueNameTxtTables[] macros, which MonsterTbls declares differently. Not moved yet.
- 0x625560 (DataTbls.cpp, inside StatsEx's run): moved, it doesn't build equal in StatsEx.
