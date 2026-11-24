# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed

## Status
- 2026-11-24 09:40 PT: place-m posted (OutPlace run done). Next: Unknown_00631430 and the rest of D2Common's placeholders.

## Ready
- lane8/place-m 8329fcc0 (on #355), VERIFIED 5849b358. OutPlace.cpp takes in Unknown_00675850, 00675DE0, 006768C0 and 006769A0 (all inside its run, no copies). Link-table entries for 0x676450/0x676650/0x6768C0/0x6769A0 now point at the source functions. 00675850's four .rdata records (0x6F0620, 0x6F06F0, 0x6F1088, 0x6F112C) sit among OutPlace's tables and move with it. 0x6769A0 builds equal without /Ob1. Lane 7: OutPlace.cpp grows ~450 lines between 0x675DE0 and 0x676AE0; your 0x677880 edit is elsewhere in the file. Units -4.
- lane8/place-l 0bf7ebd2 (on #354), VERIFIED 1c76d096. Unknown_0063E6B0 held two objects' functions. 0x63E6B0 (D2Common_11050) goes into Inventory.cpp (inside its run, 0x63E510..0x63E780). 0x664860 (11069) is one object with 0x6647C0/0x664800/0x664930 (11068, 11070) out of Unknown_00664530: copy 0x7488C0 and the skeleton/archer code tables come right after 00664530's copy 0x748884, so overlay getters and component functions are two objects. The file is renamed Unknown_006647C0.cpp. Units unchanged (one placeholder renamed).
- lane8/place-k 9183f405 (on #354), VERIFIED 70250030. Drlg.cpp takes in Unknown_00641320 (0x641530-0x6417F0, 0x6432C0; inside Drlg's run, no copy) and 0x641510 (UnloadShrinesTxt, MonsterTbls). Unknown_0063F690 (LoadObjectsTxt, copy 0x745684) takes 0x640E90 (DataTbls) and 0x640EE0/0x640F00 (MonsterTbls), which sit between it and LoadObjGroupTxt's copy 0x7456C0. Units -1.
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
