# Lane 12

Written by lane 12 only. Newest entries at the top of each section; delete what is done.

Lane 12: link debt for the ordinary build (tools/linkdebt.py): type_disagreement, duplicate_data, local_copy and
renamed_definition. Per-module export headers other modules include (the FogApi2.h way), most-referenced targets
first; the extra definitions of duplicated globals removed. Branches lane12/<topic>, based on lane10/short-data until
it is on main; from #473, based on main.

## Ready
- Fri Nov 27 05:23 PST 2026: **lane12/genheaders-2** (0d0127af9, on #476 9a4b7d477): lane12/genheaders rebased,
  plus a third commit: a unit includes the export header after the last #include above its first removed copy (or
  at the copy), so the declaration precedes every use; a corrected line in another module's header gets forward
  declarations just above it; --plan writes the symbols taken as JSON. Take this one instead of lane12/genheaders.
  Tools only. VERIFIED tree c6b85a0470514a8279cac057555428eefb2f926e.
- Fri Nov 27 05:12 PST 2026: **lane12/api-fog** (89dcc5ad3, stacked on lane12/module-api-headers-7, on #476
  9a4b7d477): "Fog: declarations of its exports agree with their definitions", by tools/genheaders.py --module Fog
  --header FogApi2.h. 19 new exports in FogApi2.h; FogApi.h's and other modules' header lines for Fog addresses
  take the definitions' types (forward declarations added above them where a header had none); 24 private copies
  give way to the header. Left out: the pool/async/data-array/queue-socket calls whose callers pass void* or their
  own record types (FOG_AllocPool, FOG_FreePool, FOG_ReallocPool, FOG_CreateNewPoolSystem, FOG_AsyncDataLoadFileEx,
  FOG_CreateBinFile, FOG_ComputeChecksum, BITMANIP_Write, DATAARRAYS_Reset, DATAARRAYS_FreeEntry, D2QSSOCKET_
  DestroyRecord/SendPacket; these need the callers' fields typed: a later branch), typedefs only a .cpp defines
  (FOG_10219, LOGMANAGER_WriteLogV, D2QSSOCKET_SetPacketHandler, FOG_10170, QSInit, gapLogFiles), the duplicated
  ghD2ServerServiceStatus, FOG_GetInstallPath and sub_0040EB10 (a header change flips inv_0048BC10.cpp /
  ItemTbls.cpp), and per unit the copies whose removal changes the unit's bytes or no longer compiles (sub_00408090
  in 5 units, FOG_IsExpansion in 4, and 28 other unit/symbol pairs; list in the branch's exclusion file, available
  on request). Every unit genheaders lists (253) EQUAL. VERIFIED tree 6fbf5fd339c799e995b148da5aaaee61018a3958.
  linkdebt vs module-api-headers-7: 29,942 -> 29,868 (type_disagreement 6,689 -> 6,615; D2Common 4,797 -> 4,744,
  D2Game 6,540 -> 6,530, D2Client, D2Multi, D2Win, D2MCPClient down; no module rises). auditguard: no count rose;
  raw offset 120, byte pointer math 153, pointer casts 4,915, all unchanged.
- Fri Nov 27 05:12 PST 2026: **lane12/module-api-headers-7** (6a00e8706): module-api-headers-6 rebased onto #476
  9a4b7d477 without conflicts; take this one instead of -6. VERIFIED tree 6472a693a8fb28e701b75cc3995add9ee5379506;
  link debt on it 29,942. (-6's linkdebt and audit numbers below hold.)
- Fri Nov 27 03:52 PST 2026: **lane12/genheaders** (superseded by genheaders-2; 6b036b9b0, on #474 0950bf8ba; second commit: it runs on the checkout it is started in): `tools/genheaders.py` (standard
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
- Fri Nov 27 03:52 PST 2026: **lane12/module-api-headers-6** (c195e2acb, on #474 0950bf8ba; superseded by -7): lane 2's held branch,
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
