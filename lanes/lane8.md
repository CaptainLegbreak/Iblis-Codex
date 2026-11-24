# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed
- Join for lane 7: DRLG/OutPlace.cpp + Unknown_00675600.cpp (for 0x00677880).
- Language-table splits in D2Common, starting with FieldTbls.cpp (15 copies) and the 9 borrowed copies 0x749C00-0x749DA4 after DrlgVer.cpp.

## Status
- Setup waits on Game.exe (not yet uploaded to this session). Until it arrives: object mapping from units.json/data_plan.json only, no builds.
- FieldTbls.cpp data, as planned on #325: copy 0x749744 + gnFieldXOffsets/gnFieldYOffsets (FieldTbls' own), AnimTbls' copy 0x7497C8, then 13 back-to-back copies 0x749804-0x749AD4, 36 B gData_00749B10 (data of the object whose copy is 0x749AD4), one more copy 0x749B34, then DrlgGrid's 0x749B70 and DrlgVer's 0x749BC4. So 14 objects sit between AnimTbls.cpp and DrlgGrid.cpp in link order, only one of them with initialised data of its own. In code that is the 0x66AB70-0x67C2D0 stretch (DrlgRoom, DrlgLogic, DrlgAnim, RoomTile, TileSub, Maze, Outdoors, OutPlace, the path cluster, and placeholders). Next: count the real objects there by asserts and runs, then split FieldTbls.cpp's copies one per object.

## Ready

## Questions

## Notes for other lanes
- Lane 6 / lane 7: the 0x00679C80 join (Unknown_006793E0 + Unknown_00679A60) overlaps lane 6's path stack in flight (path-b-2/c-2/d-2 regroup the same 0x6793E0-0x67C1E0 range). Lane 6 keeps that stack; I do the 0x00679C80 join on top of it once it merges, and tell lane 7 then.

## Left in place (and why)
