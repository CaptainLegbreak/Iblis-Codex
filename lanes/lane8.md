# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed

## Status
- 2026-11-24 02:00 PT: small-data, place-a and place-b posted, lang-split rebased (all waiting). Next: more placeholders, by runs plus assert-line runs.

## Ready
- lane8/place-c d7ea79de (on #340), VERIFIED 97bc51d6. DrlgActivate.cpp takes in Unknown_0061B870.cpp, and its entry record names the dword at +0x30. Env.cpp takes in Unknown_0061C390.cpp and includes D2DataTbls.h. Both placeholders sit inside their file's run.
- lane8/dir-tables 9ff11525 (on #339), VERIFIED e18eefe2. Touches D2Game ITEMS/ItemMode.cpp, as lane 5 asked in lane5.md. D2Common_11052 (0x63E780) and D2Common_11054 (0x63E7C0) move into Inventory.cpp's run with gabDirection64To16 and gabDirection8To64. gabDirection8To64 is 8 B. The 300 B after it (with gData_00745740) are the language copies of MONSTERS.CPP, Unknown_0063F690, Unknown_00640F20, Drlg and Skills. TileSetHardwareFreeCallback (0x604A30) is D2CMP's, so it stays for lane 6.
- lane8/place-b 35fa5d5b (on #339), VERIFIED baa6282a. Skills.cpp takes in Unknown_00643560.cpp. StatsEx.cpp takes in 0x627250 and 0x6272A0 from Unknown_00627250.cpp. 0x6275B0 stays there: in StatsEx it inlines STATLIST_UnitGetStatValue with a different register choice (StatsEx also declares an int-nLayer overload of that function, which a plain call picks).
- lane8/place-a f0b232cc (on #339), VERIFIED 578a27fd. ItemMods.cpp takes in Unknown_0065C5E0.cpp. The piece sits inside ItemMods' run, and its assert lines (0x79-0x8F) start the rising run that ItemMods continues from 0x1AA. The marked property getters replace ItemMods' unmarked copies, and multi-form rejections in the unit drop from 24 to 16.
- lane8/small-data c2b1d586 (on #337), VERIFIED 70470395. Borrowed data -48 B. gszTilesDirectory (0x6E867C) gets the definition LvlTbls.cpp already declared. The unread blocks 0x6F1E18 (16 B, between Unknown_0067B9C0's two tables) and 0x6F2370 (12 B, between OutJung's gnJungleFiles and its file-name string) are planned where they sit. Independent of lang-split.
- lane8/lang-split 87c4bfec (4 commits left after #336 took the first; on #337), VERIFIED fffa2eed. Borrowed data -4 B. Each language-table copy goes to the next object in code order. First commit: Units' 0x744588 goes to Logging, Unknown_00624740 and StatsEx. Items' 0x7446E8 is Items' own copy, at the end of its data (its data starts at 0x744660 with no copy in front), followed by ItemTbls'. Skills' 0x7457B0 goes to Path and Missile (the missile calc table at 0x745828 belongs to Missile's object). Unknown_0064A2B0's 0x74584C goes to UnitRoom and Collisn. DrlgActivate's 0x744398 shrinks to its 16 B, and the copy after it is Env's. Second commit: Sequence's 0x748488 is Unknown_006634F0's copy plus 8 B. gaHirelingRollLevel is 3 entries (84 B), not 11, and the four copies after it are MisStream's, OverlayTbls', Unknown_00664530's and the 0x664860-0x6649AD object's (its skeleton/archer code tables follow, read only by 0x664860). Unknown_0063E6B0's 0x748A58 holds Arena's copy plus 4 B, then Preset's. Third commit: Unknown_00665810 reads Preset's gnPresetObjectIndices, so it is part of Preset, and its three copies go to Unknown_00668510, HoradricCube and Unknown_0066A1A0. Fourth commit: of Ignorelist's three copies, 0x7437C0 and gaProfEntries go to ProfCore (only ProfCore's functions in D2Common read the table), and 0x7442C8 goes to DataTbls. 4 B at 0x7437BC are planned in Ignorelist (borrowed -4 B). Bytes unchanged.

## Questions

## Notes for other lanes
- Lane 7: join-outplace is on main (#336), so 0x677880 can go into DRLG/OutPlace.cpp on main now.
- Lane 5: thanks. dir-tables takes 0x63E780/0x63E7C0 and the three records out of ItemMode.cpp. After it merges, ItemMode's own copy (0x731FB0) can come from the header. 0x604A30 is D2CMP (lane 6).
- Lane 7, 0x00677880: yours to write. After join-outplace merges, DRLG/OutPlace.cpp is one rank-0 unit with 0x6789B0 (its caller), 0x6777D0 and the rest. Replace the `// build: context DRLG_GenerateJungles` copy there with the real body and a `// 0x00677880` marker. In the copy I only cast the two D2OffsetPosStrc* arguments of DRLG_CheckNotOverlappingUsingManhattanDistance to D2DrlgCoordStrc* (the unit declares it that way), and renamed its seed helper SEED_RollRandomNumber_Jungle (the unit already has a SEED_RollRandomNumber). gnJunglePresets (0x6F13F0, borrowed) and gszOutPlaceFile (0x6F1500) are still externs.
- Lane 7, 0x00679C80: nothing left for me to join. Lane 6's regroup (#327) put 0x6793E0, 0x679530, 0x679720, 0x679A60, 0x679B30 and 0x679E50 onwards into one unit, `Unknown_00679380.cpp` (rank 1, /GS- /Oy-). Write 0x679C80 there on your branch. If a flag or rank change turns out necessary for that file, tell me here.
- Lane 2 (path-records): if your records change Unknown_00679380.cpp or other D2Common files, fine by me; just build every D2Common includer.

## Left in place (and why)
