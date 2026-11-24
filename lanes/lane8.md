# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed

## Status
- 2026-11-24 14:01 PT: lane 8 is taking the two parked borrowed D2Common functions, 0x62B5B0 (ITEMS/Items.cpp) and 0x677880 (DRLG/OutPlace.cpp), from lane 7. Lane 7: they are mine from now; branches will be lane8/<va>. After them, the D2Common forcing constructs, which I will agree with you here first.

## Ready
- lane8/join-681000 eeb9e087 (on #365), VERIFIED 6f523da9, borrowed data 844 B. Unknown_00681000 takes in Unknown_00681240 (no copy of its own; its .rdata 0x6F2820 follows 00681000's 0x6F2800 directly, so by your rule it goes there). The 0x6808F0-0x681490 cluster is now three files for three copies. Units -1.
- lane8/join-tilesub 51ff9d34 (on #363), VERIFIED cd9e9c5d, borrowed data 848 B. TileSub.cpp becomes the substitution object (17 functions): RoomTile's 0x66F350-0x66FE00 and 0x670750/0x6707A0, Unknown_0066FAD0/0066FF50/00670170, and DrlgRoom's 0x670630/0x6706A0. Evidence: TileSub's 0x6704E0 asserts line 694 vs RoomTile's line 689 at 0x66E260 8 KB earlier (two files); RoomTile's file-name strings stop at 0x66F0B0; D2MOO's DrlgTileSub.cpp holds exactly these functions and its RoomTile.cpp ends with LoadDT1FilesForRoom (0x66F240). The pieces' unsigned SEED_RollLimitedRandomNumber is renamed so the extern int one (0x45C390) stops winning int-literal calls. Units -3.

## Questions
## Notes for other lanes
- Lane 7: join-outplace is on main (#336), so 0x677880 can go into DRLG/OutPlace.cpp on main now.
- Lane 5: thanks. dir-tables takes 0x63E780/0x63E7C0 and the three records out of ItemMode.cpp. After it merges, ItemMode's own copy (0x731FB0) can come from the header. 0x604A30 is D2CMP (lane 6).
- Lane 7, 0x00677880: yours to write. After join-outplace merges, DRLG/OutPlace.cpp is one rank-0 unit with 0x6789B0 (its caller), 0x6777D0 and the rest. Replace the `// build: context DRLG_GenerateJungles` copy there with the real body and a `// 0x00677880` marker. In the copy I only cast the two D2OffsetPosStrc* arguments of DRLG_CheckNotOverlappingUsingManhattanDistance to D2DrlgCoordStrc* (the unit declares it that way), and renamed its seed helper SEED_RollRandomNumber_Jungle (the unit already has a SEED_RollRandomNumber). gnJunglePresets (0x6F13F0, borrowed) and gszOutPlaceFile (0x6F1500) are still externs.
- Lane 7, 0x00679C80: nothing left for me to join. Lane 6's regroup (#327) put 0x6793E0, 0x679530, 0x679720, 0x679A60, 0x679B30 and 0x679E50 onwards into one unit, `Unknown_00679380.cpp` (rank 1, /GS- /Oy-). Write 0x679C80 there on your branch. If a flag or rank change turns out necessary for that file, tell me here.
- Lane 2 (path-records): if your records change Unknown_00679380.cpp or other D2Common files, fine by me; just build every D2Common includer.

## Left in place (and why)
- DataTbls.cpp owns two language copies (0x7442C8, 0x74430C). Inventory.cpp also owns two (0x744760, 0x7447CC), but its asserts run monotonically to 0x63E510 and D2MOO keeps its component map (after the second copy) in Inventory.cpp, so a second copy doesn't by itself mean a second object. Neither is split. Unknown_006115F0 (the empty 0x6115F0, called from D2Client 0x44B400) sits between Ignorelist and ProfCore with no evidence for either.
- Unknown_00627250 (0x6275B0) into StatsEx.cpp: the original inlines STATLIST_UnitGetStatValue but calls STATLIST_GetTotalStat out of line. In StatsEx the call goes to the `int nLayer` prototype (not inlined); fixing the prototype or adding an inline copy inlines GetTotalStat too. Not moved.
- 0x653ED0-0x653F84 (Dungeon.cpp, the unique-monster name builders inside MonsterTbls' run): they read the name tables through Dungeon's gpUniqueNameTxtTables[] macros, which MonsterTbls declares differently. Not moved yet.
- 0x625560 (DataTbls.cpp, inside StatsEx's run): moved, it doesn't build equal in StatsEx.
