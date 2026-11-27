# Lane 12

Written by lane 12 only. Newest entries at the top of each section; delete what is done.

Lane 12: link debt for the ordinary build (tools/linkdebt.py): type_disagreement, duplicate_data, local_copy and
renamed_definition. Per-module export headers other modules include (the FogApi2.h way), most-referenced targets
first; the extra definitions of duplicated globals removed. Branches lane12/<topic>, based on lane10/short-data until
it is on main; from #473, based on main.

## Ready
- Fri Nov 27 03:52 PST 2026: **lane12/genheaders** (6b036b9b0, on #474 0950bf8ba; second commit: it runs on the checkout it is started in): `tools/genheaders.py` (standard
  library only) and a README paragraph. `--module M` lists every function and global M defines that another
  module's unit declares (same identifier, line ending in the definition's address), with the definition's
  prototype (types, convention, C linkage) and the header it goes to: Source/Include/<M>Api.h or `--header`, or the
  Source/Include header that already declares it (corrected there). `--apply` writes the header, corrects other
  headers' lines for those addresses, replaces each unit's private copy with an include, and `--units-out` lists
  the units to rebuild; `--exclude` takes units, addresses or unit+address pairs whose bytes change. It lists what
  it leaves out and why (static/inline, members, function-pointer globals, types no shared header defines, const
  without extern, addresses defined in more than one file). Exports go to Source/Include because a unit's include
  path is the repo root, its module directory and Source/Include only. Dry run on #474: D2Common 905 symbols
  (1,260 copies), D2Client 191 (565), D2Win 119 (307), D2Gfx 100 (237), Fog 152 (202), Storm 117 (121), ~3,400
  copies in all. Source unchanged. VERIFIED tree 034fd1b237015a3252d712bd6a27a82c6a0a725a; linkdebt and
  auditguard unchanged (no source change).
- Fri Nov 27 03:52 PST 2026: **lane12/module-api-headers-6** (c195e2acb, on #474 0950bf8ba): lane 2's held branch,
  its two commits rebuilt on main ("One name for the cel context: D2GfxDataStrc"; "Export headers for D2Gfx, D2Win,
  D2CMP, D2Sound, D2Net, D2Hell and D2MCPClient"). Gfx_0046E300.cpp is gone on main, so its edits went to Gfx.cpp,
  where GFX_DrawUnitOverlays now lives (CUNIT_GetGfxData's result is D2UnitGfxDataStrc*, the overlay cel context
  D2GfxDataStrc); in Clients/Game/Level/SkillMonst.cpp main had already dropped the copies, so main's side stays.
  precheck 455 units (every changed unit and every user of the 16 changed headers) 0 not all equal. VERIFIED tree
  81f4f4ca6a78d0b891e5d23bd17730a31e2f6772. linkdebt 30,700 -> 30,549 (type_disagreement 6,823 -> 6,671; D2Client
  10,777 -> 10,641, D2Win 918 -> 904, D2Multi 1,664 -> 1,663; no module rises; one D2Client reference moves from
  type_disagreement to renamed_definition, 150 -> 151, its declaration now agreeing with a static definition).
  auditguard: no count rose; raw offset access 120 -> 120, byte pointer math 153 -> 153, pointer casts 4,922 ->
  4,915.

## Claimed
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
