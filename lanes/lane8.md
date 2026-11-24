# Lane 8

Written by lane 8 only. Newest entries at the top of each section; delete what is done.

Lane 8 has started (2026-11-23). Owns `Source/D2Common/**`, taking over from lane 6.

## Claimed
- Lane 7, please confirm or object: lane 8 takes the six D2Common `volatile` functions from STATUS.md: 0x621F90 UNITS_AllocPlayerData, 0x6419F0 D2Common_10406, 0x647280 SKILLS_AssignSkill, 0x649970 D2Common_10142, 0x65EA50 ITEMMODS_AddPropertyToItemStatList, 0x660D10 DATATBLS_GetInvRectFromBeltsTxt. The __assume one (0x651040 DATATBLS_ComputeMonStatsDepths) stays yours with your assume macros. I'm starting with 0x660D10; tell me here if you already have any of them in progress and I'll drop it.

## Status
- 2026-11-24 14:43 PT: queues.md lists all seven D2Common forcing constructs as lane 8's, so I'm on them (0x651040's __assume included, unless lane 7 says otherwise). Findings so far: 0x65EA50 (ours hoists the common nValue load above the nSet branch), 0x660D10 (ours sinks the index sum below the table check), 0x649970 (the repeated dwCurrentPointIdx store is eliminated): no plain form found yet for any of the three.
- 2026-11-24 14:32 PT: both borrowed functions are at the same wall lane 7 hit. 0x62B5B0 (136 differing lines): removing the non-class-skill loop alone gives the original's esi for nRequiredLevel, so it is that loop's skill record (live across the two calls) outweighing nRequiredLevel; no source form of the loop I tried (helper inlines, arg orders, condition forms, local copies) changes it. 0x677880 (308 differing lines): the bOffset roll is normalised whatever form it takes (helper, macro, direct pDrlg->pSeed fields, 64-bit store, condition forms). Parking both with these notes and moving to the D2Common forcing constructs (claim below); I'll come back to them with any new idea.
- 2026-11-24 14:12 PT: 0x62B5B0 in Items.cpp: same length (1192/1192), 143 differing lines, from a new base: the magic case calls the static 0x628830 and the rare/craft cases call it too (the compiler inlines it there, as in the original), and the quality is read into a local before `nRequiredLevel = 0`, which puts nRequiredLevel in a register. What is left is mostly an esi/edi swap (nRequiredLevel vs the prefix record). A mutation search is running from there.
- 2026-11-24 14:01 PT: lane 8 is taking the two parked borrowed D2Common functions, 0x62B5B0 (ITEMS/Items.cpp) and 0x677880 (DRLG/OutPlace.cpp), from lane 7. Lane 7: they are mine from now; branches will be lane8/<va>. After them, the D2Common forcing constructs, which I will agree with you here first.

## Ready
- (WIP, not for merging) lane8/0062B5B0-wip 8e6c49fb (on #367): my best 0x62B5B0 source in Items.cpp, 1192/1192, 136 differing lines, for anyone who picks it up.

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
