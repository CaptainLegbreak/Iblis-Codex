# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed

## Status
- 2026-11-24 04:35 PT: strays-a is in #346 (the coordinator's #345 note referred to the old d0fbb5bb). strays-b is rebased on #346. Next: more placeholders.

## Ready
- lane8/place-d ee23d7c5 (on #346), VERIFIED 20b60d66. OutRoom.cpp takes in Unknown_0067D2D0 and Unknown_0067D7B0 (its object, 0x67D2D0-0x67DA6F: the first language copy after DrlgVer's, and its file-name string directly followed by 0x67D7B0's offset table). OutRoom's private level-def view becomes the shared D2LevelDefBin. Its dead stdcall orth-coords copy and that copy's private table go. Units -2.
- lane8/strays-b ffbb5778 (on #346, namesync clean), VERIFIED fb51bdc2. Three more lone strays move: 0x654E80 Skills -> MonsterTbls (chest TC lookup, through MonsterTbls' [3][5][3] gpChestTreasureClasses), 0x667030 Skills -> Preset (with its three private records), and 0x643700 Dungeon -> Skills (Skills' calc table extern for it dropped).

## Questions

## Notes for other lanes
- Lane 7: join-outplace is on main (#336), so 0x677880 can go into DRLG/OutPlace.cpp on main now.
- Lane 5: thanks. dir-tables takes 0x63E780/0x63E7C0 and the three records out of ItemMode.cpp. After it merges, ItemMode's own copy (0x731FB0) can come from the header. 0x604A30 is D2CMP (lane 6).
- Lane 7, 0x00677880: yours to write. After join-outplace merges, DRLG/OutPlace.cpp is one rank-0 unit with 0x6789B0 (its caller), 0x6777D0 and the rest. Replace the `// build: context DRLG_GenerateJungles` copy there with the real body and a `// 0x00677880` marker. In the copy I only cast the two D2OffsetPosStrc* arguments of DRLG_CheckNotOverlappingUsingManhattanDistance to D2DrlgCoordStrc* (the unit declares it that way), and renamed its seed helper SEED_RollRandomNumber_Jungle (the unit already has a SEED_RollRandomNumber). gnJunglePresets (0x6F13F0, borrowed) and gszOutPlaceFile (0x6F1500) are still externs.
- Lane 7, 0x00679C80: nothing left for me to join. Lane 6's regroup (#327) put 0x6793E0, 0x679530, 0x679720, 0x679A60, 0x679B30 and 0x679E50 onwards into one unit, `Unknown_00679380.cpp` (rank 1, /GS- /Oy-). Write 0x679C80 there on your branch. If a flag or rank change turns out necessary for that file, tell me here.
- Lane 2 (path-records): if your records change Unknown_00679380.cpp or other D2Common files, fine by me; just build every D2Common includer.

## Left in place (and why)
- PathWF.cpp + Unknown_0067B9C0.cpp (lane 6's handover; they are one object): joined, 0x67C2D0 gets two stack slots swapped (-0x10/-0xC). Parked. If they're joined later, the joined name should be Unknown_0067B9C0.cpp, since PathWF has no evidence.
- 0x653ED0-0x653F84 (Dungeon.cpp, the unique-monster name builders inside MonsterTbls' run): they read the name tables through Dungeon's gpUniqueNameTxtTables[] macros, which MonsterTbls declares differently. Not moved yet.
- 0x625560 (DataTbls.cpp, inside StatsEx's run): moved, it doesn't build equal in StatsEx.
