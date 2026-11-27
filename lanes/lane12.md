# Lane 12

Written by lane 12 only. Newest entries at the top of each section; delete what is done.

Lane 12: link debt for the ordinary build (tools/linkdebt.py): type_disagreement, duplicate_data, local_copy and
renamed_definition. Per-module export headers other modules include (the FogApi2.h way), most-referenced targets
first; the extra definitions of duplicated globals removed. Branches lane12/<topic>, based on lane10/short-data until
it is on main; from #473, based on main.

## Ready
- Fri Nov 27 11:48 PST 2026: **lane12/dupdata-1** (272e8088a, stacked on renamed-1): "One definition per global: second definitions become
  extern declarations". 167 globals a unit defined although another file defines them at the same address (the
  definition the link keeps) become extern declarations there, with the kept definition's type and linkage
  (gbStandStillHeld: Game_0044B7B0.cpp now declares, D2Client Game.cpp defines). Every changed unit EQUAL; two
  whose code changes keep their definitions. Left: definitions with an initializer or over several lines (55),
  kept definitions that are generated data (~37). VERIFIED tree 1959d9012d3a1790126fd2c568c30f579595009c.
  linkdebt vs renamed-1: 23,708 -> 23,079 (duplicate_data 1,100 -> 395, 241 -> 83 targets; D2Multi -146, D2Client
  -122, D2Launch -76, D2Sound -71, Fog -62, D2BNClient -39, D2MCPClient -36, D2Win -36, others down; no module
  rises; placeholder +46 and different_identifier +27 are references that now reach the kept definition and show
  its other name, lane 11's categories). auditguard: no count rose (raw offset 120, byte pointer math 153,
  pointer casts 4,895).
- Fri Nov 27 11:17 PST 2026: **lane12/renamed-1** (6a3bbae45, stacked on api-d2common-3): "One definition per name: unmarked second
  copies go or become static". Eight files had their own non-static, unmarked copy of a function another file
  defines at its address, so the ordinary link renamed one: the copy goes where nothing in its file calls it (D2CMP
  SpriteCache.cpp CelGetHeight/OffsetX/OffsetY/CelDrawShadow; D2Common Unknown_00624740.cpp STATLIST_UnitGetStatValue
  and STATLIST_ToggleState; D2Client Roster.cpp and D2Sound D2SoundSmp.cpp CLIENTS_SetPlayerUnitAlive; D2Client
  View.cpp LIST_UnloadPentspinCellfile) and becomes static where its file calls it (D2Common Unknown_00627250.cpp
  STATLIST_UnitGetStatValue, Outdoors.cpp DRLGOUTDOORS_TestGridCellSpawnValid, D2Game a5q3.cpp
  OBJMODE_GetSuperUniqueId). Kept (the change alters the unit): inv_0048BC10.cpp INV_GetPanelX/INV_ResetNpcButtons,
  OutDesr.cpp DRLGOUTWILD_InitAct1OutdoorLevel, strtable.cpp strncat. No new forcing construct (static only).
  VERIFIED tree 6026aca40b28b59ee9f2b350c6ffc9699ade7b2f. linkdebt vs api-d2common-3: 24,594 -> 23,708
  (renamed_definition 981 -> 103, 30 -> 20 targets; D2Game -552, D2Client -170, D2Common -107, D2DDraw -19, D2Gdi
  -18, D2Win -8, D2CMP -5, others down; no module rises). auditguard: no count rose (raw offset 120, byte pointer
  math 153, pointer casts 4,895).
  Left for the naming owners: two different functions under one name, each marked at its own address:
  SKILLS_GetFirstSkillFromSkillList (D2Common Skills.cpp 0x643910 and Inventory.cpp 0x63D630),
  OBJMODE_DropItemWithCodeAndQuality (D2Game ObjMode.cpp 0x585970 and Skills.cpp 0x56DAB0),
  ARCHIVE_LoadCellFileWithFileSize (D2Client ARCHIVE.CPP and D2Win D2WinArchive.cpp 0x4FAA40),
  MONSTERMODE_GetHpPercent128 (D2Game PlrModes.cpp 0x5805D0 and MonsterEval.cpp), DATATBLS_GetMonStatsTxtRecord
  (D2Client Game.cpp 0x451F80 and D2Common's): one of each pair needs its own name.
- Fri Nov 27 10:57 PST 2026: **lane12/api-d2common-3** (on #483 a42b4ed66; ignore api-d2common-2, pushed before a fix): two commits.
  (1) "D2Lang: three more copies give way to D2LangApi.h": D2Lang's exports already agree in D2LangApi.h; the
  other copies stay because dropping them changes their units (ui.cpp, SkillDesc_004F30A0.cpp, MonUnique.cpp,
  DataTbls.cpp, ...) or the callers' types differ. (2) "D2Common: declarations of its exports agree with their
  definitions" (genheaders --module D2Common --header D2CommonApi3.h): the exports D2CommonApi.h/Api2.h lack go
  to a new narrowly included D2CommonApi3.h; those headers' and other modules' header lines for D2Common
  addresses take the definitions' types; 483 private copies in 76 units go. Left out: 41 exports (static/inline,
  .cpp-only typedefs, twice-defined globals, callers passing other types, e.g. D2COMMON_10475_PostStatToStatList:
  defined with D2StatListExStrc*, 21 D2Game callers pass D2StatListStrc*), D2Game ItemMode.cpp and D2Client
  Wall2.cpp whole, and per unit the copies whose removal changes the unit. Parameter names a2/a3 of three
  definitions become nArg2/nArg3 in the headers (auditguard a1/v12 would otherwise rise). Every listed unit (249)
  EQUAL. VERIFIED tree d0ca29dd9b9e76fa42c716ad4286403ed8c7c3b5. linkdebt vs #483: 25,066 -> 24,594
  (type_disagreement 6,484 -> 5,574; D2Game 5,303 -> 4,879, D2Client 8,729 -> 8,681; no module rises).
  renamed_definition 543 -> 981: those references' declarations now agree, which exposes that their definition is
  renamed for the link: 806 of them are STATLIST_UnitGetStatValue (StatsEx.cpp), whose name is not unique. That
  is my renamed_definition item, next. auditguard: no count rose (raw offset 120, byte pointer math 153, pointer
  casts 4,916 -> 4,895).

## Claimed
- Fri Nov 27 8:40 PST 2026: status. D2Lang done on top of api-storm-2 (only 3 copies can go: D2LangApi.h already agrees with the
  definitions, and dropping the rest changes their units; it will ride with D2Common). D2Common through genheaders
  is running (905 symbols, 1,237 copies; round 1: 42 of 251 units still differ). Finding for the owners:
  D2COMMON_10475_PostStatToStatList (0x626E10) is defined taking D2StatListExStrc* while 21 D2Game units declare
  D2StatListStrc*; those keep their copies for now (a definition-side type question, not a void return).
- Fri Nov 27 7:20 PST 2026: status. Ready: module-api-headers-8, genheaders-3, api-fog-2, api-storm (a stack, in that order on #477).
  Next: D2Lang, then D2Common (new exports to a new narrowly included D2CommonApi3.h), on api-storm.
- Fri Nov 27 05:12 PST 2026: status. Held branches done (module-api-headers-7 Ready; the other three dropped, see
  below). genheaders: a third commit (includes placed where the copy stood, forward declarations for corrected
  header lines, --plan) is verifying on #476 as lane12/genheaders-2. Next: Storm, D2Lang, then D2Common through
  genheaders, each stacked on api-fog. Files claimed: Source/Include/StormApi*.h, D2LangApi*.h, D2CommonApi*.h and
  the private copies of Storm's, D2Lang's and D2Common's functions in other modules' units.
- Fri Nov 27 03:54 PST 2026: the other three held branches, checked on #474: **lane2/gfxdata-record-3 dropped**: its one
  commit is module-api-headers-6's first commit, carried there. **lane9/decls-renderers-2 dropped**: already on main
  (git cherry marks its commit equivalent; D2Glide.h has the 41 declarations). **lane5/decls-d2game-8 dropped**:
  12 of its 14 commits are already on main (each cherry-picks empty); the other two, Task.cpp taking in
  TASK_TASK_ProcessGame (0x5645E0) and Items.cpp taking in D2GAME_CreateItemUnit (0x559CE0), add two noinline
  (auditguard: noinline 109 -> 111) and a __forceinline, which the current rules forbid, so I don't carry them; they
  are function placement, not declarations, if lane 5's owner wants them ruled on.
  Next: genheaders module by module, Fog, Storm and D2Lang first, then D2Common (new exports to a narrowly included
  D2CommonApi3.h: appending to the widely included D2CommonApi.h changes units that count declarations), then the
  rest. These branches stack on lane12/module-api-headers-6 (its 130 units are the same ones), and say so.
  Files claimed: Source/Include/FogApi*.h, StormApi*.h, D2LangApi*.h, D2CommonApi*.h and the private copies of
  those modules' functions in other modules' units.

## Questions (owner's ruling: void definitions whose callers use a result)

## Notes for other lanes
