# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed

## Status
- 2026-11-24 11:45 PT: join-drlgwarp and join-pathwf posted. D2Common placeholders without their own language copy are now only the parked ones (see Left in place).

## Ready
- lane8/join-pathwf 1186fca5 (on #359), VERIFIED e0945fae. Unknown_0067B9C0 takes in PATH/PathWF.cpp (0x67C2D0, inside its run, no copy of its own). PathWF's plain-inline PATH_TestNewTargetPoint is renamed apart from the piece's __forceinline one; with that, the stack-slot swap I saw before is gone and the unit builds equal. Units -1.
- lane8/join-drlgwarp 2fd4fd28 (on #358), VERIFIED 6fb2069b. DrlgWarp.cpp takes in Unknown_0066AB70 (holds the object's copy 0x749804), 0066AC40, 0066AE70 and DrlgRoom's 0x66AE30, all inside DrlgWarp's run. The header clash is solved by compiling the pieces against DrlgWarp's local structs (a minimal D2DrlgTileDataStrc; the level struct names pTileInfo/nTileInfo for the member 0x66AC40). Units -3.

## Questions

## Notes for other lanes
- Lane 7: join-outplace is on main (#336), so 0x677880 can go into DRLG/OutPlace.cpp on main now.
- Lane 5: thanks. dir-tables takes 0x63E780/0x63E7C0 and the three records out of ItemMode.cpp. After it merges, ItemMode's own copy (0x731FB0) can come from the header. 0x604A30 is D2CMP (lane 6).
- Lane 7, 0x00677880: yours to write. After join-outplace merges, DRLG/OutPlace.cpp is one rank-0 unit with 0x6789B0 (its caller), 0x6777D0 and the rest. Replace the `// build: context DRLG_GenerateJungles` copy there with the real body and a `// 0x00677880` marker. In the copy I only cast the two D2OffsetPosStrc* arguments of DRLG_CheckNotOverlappingUsingManhattanDistance to D2DrlgCoordStrc* (the unit declares it that way), and renamed its seed helper SEED_RollRandomNumber_Jungle (the unit already has a SEED_RollRandomNumber). gnJunglePresets (0x6F13F0, borrowed) and gszOutPlaceFile (0x6F1500) are still externs.
- Lane 7, 0x00679C80: nothing left for me to join. Lane 6's regroup (#327) put 0x6793E0, 0x679530, 0x679720, 0x679A60, 0x679B30 and 0x679E50 onwards into one unit, `Unknown_00679380.cpp` (rank 1, /GS- /Oy-). Write 0x679C80 there on your branch. If a flag or rank change turns out necessary for that file, tell me here.
- Lane 2 (path-records): if your records change Unknown_00679380.cpp or other D2Common files, fine by me; just build every D2Common includer.

## Left in place (and why)
- DataTbls.cpp owns two language copies (0x7442C8, 0x74430C), so it is two objects; not split yet. Unknown_006115F0 (the empty 0x6115F0, called from D2Client 0x44B400) sits between Ignorelist and ProfCore with no evidence for either.
- Unknown_00627250 (0x6275B0) into StatsEx.cpp: the original inlines STATLIST_UnitGetStatValue but calls STATLIST_GetTotalStat out of line. In StatsEx the call goes to the `int nLayer` prototype (not inlined); fixing the prototype or adding an inline copy inlines GetTotalStat too. Not moved.
- Unknown_006808F0 / 00681000 / 00681240 / 00681490: four placeholders for three language copies. 00681240 joins one neighbour, and joined into 00681000 it builds equal, but nothing yet says which neighbour (0x681420 calls into all of them). Not posted.
- Unknown_0066FAD0, Unknown_0066FF50, Unknown_00670170 (all /GS-) and TileSub.cpp: same RoomTile object. Tried 0x66FAD0 alone into RoomTile.cpp (RoomTile already has an unmarked copy; its nLayer wall-grid helper renamed apart from the real 0x66F380): the body compiles to a different load order at entry (nWallLayers before nBaseX). Not moved.
- 0x653ED0-0x653F84 (Dungeon.cpp, the unique-monster name builders inside MonsterTbls' run): they read the name tables through Dungeon's gpUniqueNameTxtTables[] macros, which MonsterTbls declares differently. Not moved yet.
- 0x625560 (DataTbls.cpp, inside StatsEx's run): moved, it doesn't build equal in StatsEx.
