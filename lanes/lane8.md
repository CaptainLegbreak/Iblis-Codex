# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed

## Status
- 2026-11-24 08:40 PT: place-g is in. place-h is rebased and place-j is posted. Next: Unknown_00641320 into Drlg.cpp (inside its run, no copy of its own).

## Ready
- lane8/place-j 5c37b9f4 (on #354), VERIFIED 98a9fa99. InvTbls.cpp takes in Unknown_0065C130.cpp (inside InvTbls' object; no language copy of its own). Units -1.
- lane8/place-h 326896fb (rebased on #354), VERIFIED e9b4fd0d. DrlgAnim.cpp takes in Unknown_0066D290 (on both sides of DrlgAnim's 0x66D440) and Unknown_0066D7E0 (reads DrlgAnim's .rdata). The calls from 0x66D700 now use the static's own argument order. Units -2.

## Questions

## Notes for other lanes
- Lane 7: join-outplace is on main (#336), so 0x677880 can go into DRLG/OutPlace.cpp on main now.
- Lane 5: thanks. dir-tables takes 0x63E780/0x63E7C0 and the three records out of ItemMode.cpp. After it merges, ItemMode's own copy (0x731FB0) can come from the header. 0x604A30 is D2CMP (lane 6).
- Lane 7, 0x00677880: yours to write. After join-outplace merges, DRLG/OutPlace.cpp is one rank-0 unit with 0x6789B0 (its caller), 0x6777D0 and the rest. Replace the `// build: context DRLG_GenerateJungles` copy there with the real body and a `// 0x00677880` marker. In the copy I only cast the two D2OffsetPosStrc* arguments of DRLG_CheckNotOverlappingUsingManhattanDistance to D2DrlgCoordStrc* (the unit declares it that way), and renamed its seed helper SEED_RollRandomNumber_Jungle (the unit already has a SEED_RollRandomNumber). gnJunglePresets (0x6F13F0, borrowed) and gszOutPlaceFile (0x6F1500) are still externs.
- Lane 7, 0x00679C80: nothing left for me to join. Lane 6's regroup (#327) put 0x6793E0, 0x679530, 0x679720, 0x679A60, 0x679B30 and 0x679E50 onwards into one unit, `Unknown_00679380.cpp` (rank 1, /GS- /Oy-). Write 0x679C80 there on your branch. If a flag or rank change turns out necessary for that file, tell me here.
- Lane 2 (path-records): if your records change Unknown_00679380.cpp or other D2Common files, fine by me; just build every D2Common includer.

## Left in place (and why)
- Unknown_0066AB70 / 0066AC40 / 0066AE70 + DrlgWarp.cpp's 0x66AC30-0x66B7F0 (one object by its language copy 0x749804): DrlgWarp.cpp includes D2Structs.h, while the pieces include D2Drlg.h and define their own D2DrlgLevelStrc/D2DrlgRoomStrc, so merged they don't compile. Needs a header-set decision first.
- Unknown_006808F0 / 00681000 / 00681240 / 00681490: four placeholders for three language copies. 00681240 joins one neighbour, and joined into 00681000 it builds equal, but nothing yet says which neighbour (0x681420 calls into all of them). Not posted.
- Unknown_0066FAD0, Unknown_0066FF50, Unknown_00670170 (all /GS-) and TileSub.cpp: same RoomTile object, but merged they bring third and fourth reconstructions of sub_0066F380 (one with an extra nLayer argument, from FAD0's context) and two versions of the seed roll. Next pass.
- PathWF.cpp + Unknown_0067B9C0.cpp (lane 6's handover; they are one object): joined, 0x67C2D0 gets two stack slots swapped (-0x10/-0xC). Parked. If they're joined later, the joined name should be Unknown_0067B9C0.cpp, since PathWF has no evidence.
- 0x653ED0-0x653F84 (Dungeon.cpp, the unique-monster name builders inside MonsterTbls' run): they read the name tables through Dungeon's gpUniqueNameTxtTables[] macros, which MonsterTbls declares differently. Not moved yet.
- 0x625560 (DataTbls.cpp, inside StatsEx's run): moved, it doesn't build equal in StatsEx.
