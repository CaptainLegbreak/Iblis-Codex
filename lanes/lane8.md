# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed
- Language-table splits in D2Common: FieldTbls.cpp's remaining copies and the 9 borrowed copies 0x749C00-0x749DA4 after DrlgVer.cpp.

## Status
- 2026-11-23 23:20 PT: join-outplace and lang-path posted. Next: FieldTbls.cpp's eight remaining copies (0x749804-0x7499A8, DrlgRoom to Outdoors; the code there holds many strays), then the nine borrowed copies after DrlgVer.cpp.
- FieldTbls.cpp data, as planned on #325: copy 0x749744 + gnFieldXOffsets/gnFieldYOffsets (FieldTbls' own), AnimTbls' copy 0x7497C8, then 13 back-to-back copies 0x749804-0x749AD4, 36 B gData_00749B10 (data of the object whose copy is 0x749AD4), one more copy 0x749B34, then DrlgGrid's 0x749B70 and DrlgVer's 0x749BC4. So 14 objects sit between AnimTbls.cpp and DrlgGrid.cpp in link order, only one of them with initialised data of its own. In code that is the 0x66AB70-0x67C2D0 stretch (DrlgRoom, DrlgLogic, DrlgAnim, RoomTile, TileSub, Maze, Outdoors, OutPlace, the path cluster, and placeholders). Next: count the real objects there by asserts and runs, then split FieldTbls.cpp's copies one per object.

## Ready
- lane8/lang-path 9cc3116e (stacked on join-outplace; take join-outplace first), VERIFIED 542efd02. Six of FieldTbls.cpp's language-table copies go to the path objects, counted back from DrlgGrid.cpp: 0x749B34 Unknown_0067B9C0, 0x749AD4 + gData_00749B10 Unknown_0067ADC0 (new data include), 0x749A98 Unknown_0067A550, 0x749A5C Unknown_00679380, 0x749A20 PathUtil, 0x7499E4 OutPlace. Same order as their .rdata. Bytes unchanged.
- lane8/join-outplace 80a84cbd (on #328), VERIFIED dbc9c9f9. DRLG/OutPlace.cpp takes in Unknown_00675600.cpp, Unknown_006775C0.cpp and Unknown_00678AD0.cpp (0x675670-0x678AD0), with their data. 0x678B10-0x678F70 and the tables 0x6F1518/0x6F1648 go to PATH/PathUtil.cpp, which becomes rank 0. Evidence: assert lines. 0x678F70 asserts 0x1DF/0x1E0 and PathUtil's 0x679190/0x679250 assert 0x1EA-0x202, while OutPlace's 0x677880 runs 0x63E-0x7D5. Three emit shims and gnDrlgLinkFlags' duplicate dropped. Units 3 fewer.

## Questions

## Notes for other lanes
- Lane 7, 0x00677880: yours to write. After join-outplace merges, DRLG/OutPlace.cpp is one rank-0 unit with 0x6789B0 (its caller), 0x6777D0 and the rest. Replace the `// build: context DRLG_GenerateJungles` copy there with the real body and a `// 0x00677880` marker. In the copy I only cast the two D2OffsetPosStrc* arguments of DRLG_CheckNotOverlappingUsingManhattanDistance to D2DrlgCoordStrc* (the unit declares it that way), and renamed its seed helper SEED_RollRandomNumber_Jungle (the unit already has a SEED_RollRandomNumber). gnJunglePresets (0x6F13F0, borrowed) and gszOutPlaceFile (0x6F1500) are still externs.
- Lane 7, 0x00679C80: nothing left for me to join. Lane 6's regroup (#327) put 0x6793E0, 0x679530, 0x679720, 0x679A60, 0x679B30 and 0x679E50 onwards into one unit, `Unknown_00679380.cpp` (rank 1, /GS- /Oy-). Write 0x679C80 there on your branch. If a flag or rank change turns out necessary for that file, tell me here.
- Lane 2 (path-records): if your records change Unknown_00679380.cpp or other D2Common files, fine by me; just build every D2Common includer.

## Left in place (and why)
