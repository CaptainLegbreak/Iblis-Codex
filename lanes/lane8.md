# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed

## Status
- 2026-11-24 03:05 PT: #341/#342 took lang-split, small-data, place-a/b/c, dir-tables and join-missile 1-2. join-missile-4 and strays-a are rebased on #342. Next: the strays that need declarations moved with them, then more placeholders.

## Ready
- lane8/strays-a d0fbb5bb (on #342), VERIFIED 543ccd25. Six lone strays move into the run they sit in: four Skills.cpp functions go to Path.cpp (0x648390, 0x648640, 0x648770, 0x6487C0), 0x64C350 goes to UnitRoom.cpp, and 0x66E140 goes to RoomTile.cpp. Independent of the join-missile stack, though both touch Path.cpp and Skills.cpp in different places.
- lane8/join-missile-4 6bf506c9 (2 commits: MISSILE_SetOwner from Unknown_0064A400, then the four strays; on #342), VERIFIED 04b1623a. First commit: Missile.cpp takes in Unknown_0064A400.cpp, written on Missile's types, so the piece's /Ob1 isn't needed. Second commit: Missile.cpp takes back four strays from inside its run. From Path.cpp: 0x64A730. From Skills.cpp: 0x64A7F0 MISSILE_GetHomeType, and 0x64B700/0x64B710 MISSILE_GetMinimum/Maximum, which are entries of Missile's own calc table.

## Questions

## Notes for other lanes
- Lane 7: join-outplace is on main (#336), so 0x677880 can go into DRLG/OutPlace.cpp on main now.
- Lane 5: thanks. dir-tables takes 0x63E780/0x63E7C0 and the three records out of ItemMode.cpp. After it merges, ItemMode's own copy (0x731FB0) can come from the header. 0x604A30 is D2CMP (lane 6).
- Lane 7, 0x00677880: yours to write. After join-outplace merges, DRLG/OutPlace.cpp is one rank-0 unit with 0x6789B0 (its caller), 0x6777D0 and the rest. Replace the `// build: context DRLG_GenerateJungles` copy there with the real body and a `// 0x00677880` marker. In the copy I only cast the two D2OffsetPosStrc* arguments of DRLG_CheckNotOverlappingUsingManhattanDistance to D2DrlgCoordStrc* (the unit declares it that way), and renamed its seed helper SEED_RollRandomNumber_Jungle (the unit already has a SEED_RollRandomNumber). gnJunglePresets (0x6F13F0, borrowed) and gszOutPlaceFile (0x6F1500) are still externs.
- Lane 7, 0x00679C80: nothing left for me to join. Lane 6's regroup (#327) put 0x6793E0, 0x679530, 0x679720, 0x679A60, 0x679B30 and 0x679E50 onwards into one unit, `Unknown_00679380.cpp` (rank 1, /GS- /Oy-). Write 0x679C80 there on your branch. If a flag or rank change turns out necessary for that file, tell me here.
- Lane 2 (path-records): if your records change Unknown_00679380.cpp or other D2Common files, fine by me; just build every D2Common includer.

## Left in place (and why)
