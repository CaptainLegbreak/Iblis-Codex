# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed
- Language-table splits in D2Common: FieldTbls.cpp's remaining eight copies.

## Status
- 2026-11-23 23:40 PT: three branches posted (join-outplace, lang-path, lang-outdoor), all rebased on #331. Next: FieldTbls.cpp's eight remaining copies (0x749804-0x7499A8, DrlgRoom to Outdoors; that code holds many strays), then 0x745584 and borrowed-data.md's D2Common rows.
- FieldTbls.cpp after lang-path: its own copy 0x749744 and offset tables, AnimTbls' 0x7497C8 (planned in AnimTbls), and eight copies 0x749804-0x7499A8 for the eight objects from after AnimTbls up to Outdoors.cpp. Candidates in code order: DrlgRoom, DrlgLogic, DrlgAnim (with Unknown_0066D290), RoomTile, the 0x66F350-0x670809 group with TileSub, Maze, Unknown_00674040/00674120, Outdoors. That is one too many, or one too few if Unknown_0066AB70 is its own object.

## Ready
- lane8/lang-outdoor 732ead42 (on #331), VERIFIED c6a860f5. Borrowed data -480 B. The eight borrowed language-table copies after DrlgVer.cpp's (0x749C00-0x749DA4, ending where the CRT's data starts at 0x749DE0, the default security cookie) are planned in the objects that follow DrlgVer in code. 0x749C00 OutRoom.cpp: its file-name string follows DrlgVer's in .rdata. 0x749C3C OutSiege.cpp: 0x67E660-0x67E90F read its table 0x6F22A4. 0x749C78 OutJung.cpp: its first assert line is 0x27. Then OutDesr.cpp, OutWild.cpp, Unknown_006808F0.cpp, Unknown_00681000.cpp, and Unknown_00681490.cpp last (0x681540-0x6817D0 share 0x6F2840). The 0x749D68 row is the least certain: four placeholders for three copies, so Unknown_00681240.cpp belongs with a neighbour, and I can't yet tell which.
- lane8/lang-path 77fe6ffe (stacked on join-outplace, take that first; on #331), VERIFIED 870975b0. Six of FieldTbls.cpp's language-table copies go to the path objects, counted back from DrlgGrid.cpp: 0x749B34 Unknown_0067B9C0, 0x749AD4 + gData_00749B10 Unknown_0067ADC0 (new data include), 0x749A98 Unknown_0067A550, 0x749A5C Unknown_00679380, 0x749A20 PathUtil, 0x7499E4 OutPlace. Same order as their .rdata. Bytes unchanged.
- lane8/join-outplace dbab31ec (on #331), VERIFIED 8df22aa5. DRLG/OutPlace.cpp takes in Unknown_00675600.cpp, Unknown_006775C0.cpp and Unknown_00678AD0.cpp (0x675670-0x678AD0), with their data. 0x678B10-0x678F70 and the tables 0x6F1518/0x6F1648 go to PATH/PathUtil.cpp, which becomes rank 0. Evidence: assert lines. 0x678F70 asserts 0x1DF/0x1E0 and PathUtil's 0x679190/0x679250 assert 0x1EA-0x202, while OutPlace's 0x677880 runs 0x63E-0x7D5. Three emit shims and gnDrlgLinkFlags' duplicate dropped. Units 3 fewer.

## Questions

## Notes for other lanes
- Lane 7, 0x00677880: yours to write. After join-outplace merges, DRLG/OutPlace.cpp is one rank-0 unit with 0x6789B0 (its caller), 0x6777D0 and the rest. Replace the `// build: context DRLG_GenerateJungles` copy there with the real body and a `// 0x00677880` marker. In the copy I only cast the two D2OffsetPosStrc* arguments of DRLG_CheckNotOverlappingUsingManhattanDistance to D2DrlgCoordStrc* (the unit declares it that way), and renamed its seed helper SEED_RollRandomNumber_Jungle (the unit already has a SEED_RollRandomNumber). gnJunglePresets (0x6F13F0, borrowed) and gszOutPlaceFile (0x6F1500) are still externs.
- Lane 7, 0x00679C80: nothing left for me to join. Lane 6's regroup (#327) put 0x6793E0, 0x679530, 0x679720, 0x679A60, 0x679B30 and 0x679E50 onwards into one unit, `Unknown_00679380.cpp` (rank 1, /GS- /Oy-). Write 0x679C80 there on your branch. If a flag or rank change turns out necessary for that file, tell me here.
- Lane 2 (path-records): if your records change Unknown_00679380.cpp or other D2Common files, fine by me; just build every D2Common includer.

## Left in place (and why)
