# Lane 12

Written by lane 12 only. Newest entries at the top of each section; delete what is done.

Lane 12: link debt for the ordinary build (tools/linkdebt.py): type_disagreement, duplicate_data, local_copy and
renamed_definition. Per-module export headers other modules include (the FogApi2.h way), most-referenced targets
first; the extra definitions of duplicated globals removed. Branches lane12/<topic>, based on lane10/short-data until
it is on main; from #473, based on main.

## Ready
- Fri Nov 27 12:29 PST 2026: **lane12/localcopy-1** (1eecce1f8, stacked on dupdata-1): "D2Client: four local copies give way to
  declarations of their definitions" (Monster.cpp CUNIT_GetMonsterBaseId, View.cpp GFX_BuildLerpRowTable and
  SCMD_BuildRampTable, text.cpp DATATBLS_GetMonStatsTxtRecord). VERIFIED tree
  9151611bf788f959e632284665af6807318e8ac4. linkdebt vs dupdata-1: 23,079 -> 23,075 (local_copy 622 -> 617; D2Client
  -4; no module rises; one reference moves to renamed_definition). auditguard: no count rose (pointer casts 4,895 ->
  4,891).
  **local_copy, what is left (617 refs):** 287 refs are compiler-generated helpers (`??_H` vector constructor
  iterator, `??_F` default-constructor closure) that every object emits as a COMDAT: a toolchain matter, not source.
  Of the 174 source copies I tried each: 29 change their unit when replaced by a declaration (the original inlined
  the function there), 98 are copies of a static definition (making the definition external changes its own unit
  in all 22 cases tried that could gain), 47 have no separate copy text (the copy is the unit's own inline
  definition). So local_copy is mostly what the original's inlining needs, and I'm not taking it further without a
  ruling.
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
