# Lane 12

Written by lane 12 only. Newest entries at the top of each section; delete what is done.

Lane 12: link debt for the ordinary build (tools/linkdebt.py): type_disagreement, duplicate_data, local_copy and
renamed_definition. Per-module export headers other modules include (the FogApi2.h way), most-referenced targets
first; the extra definitions of duplicated globals removed. Branches lane12/<topic>, based on lane10/short-data until
it is on main; from #473, based on main.

## Ready
- Fri Nov 27 7:51 PST 2026: **lane12/api-storm-2** (2ed43b7e1, on #479 7a4cfcc42): two commits, Fog then Storm, rebased onto #479
  without conflicts (api-fog-2 and api-storm before; -8 is merged, and api-fog's Fog commit is the one thing it
  lacks). VERIFIED tree 6fc474e78f0fb3dcfb378163161aca39846fcb29. linkdebt vs #479: being measured, posted next.
  - "Fog: declarations of its exports agree with their definitions" (genheaders --module Fog --header FogApi2.h):
    19 new exports in FogApi2.h; FogApi.h's and other modules' header lines for Fog addresses take the
    definitions' types (forward declarations added above them where needed); 24 private copies give way. Left out:
    pool/async/data-array/queue-socket calls whose callers pass void* or their own record types (FOG_AllocPool,
    FOG_FreePool, FOG_ReallocPool, FOG_CreateNewPoolSystem, FOG_AsyncDataLoadFileEx, FOG_CreateBinFile,
    FOG_ComputeChecksum, BITMANIP_Write, DATAARRAYS_Reset/FreeEntry, D2QSSOCKET_DestroyRecord/SendPacket: these
    need the callers' fields typed, a later branch), typedefs only a .cpp defines (FOG_10219, LOGMANAGER_WriteLogV,
    D2QSSOCKET_SetPacketHandler, FOG_10170, QSInit, gapLogFiles), the duplicated ghD2ServerServiceStatus,
    FOG_GetInstallPath and sub_0040EB10 (a header change flips inv_0048BC10.cpp / ItemTbls.cpp), and per unit the
    copies whose removal changes the unit or no longer compiles (sub_00408090 in 5 units, FOG_IsExpansion in 4, 28
    other pairs). Measured on #477: linkdebt -74 (type_disagreement), no module rising.
  - "Storm: declarations ...": as the api-storm entry below says. Measured on #477: linkdebt -229, no module rising.
  auditguard on the tip: no count rose (raw offset 120, byte pointer math 153, pointer casts unchanged).
- Fri Nov 27 7:20 PST 2026: (second commit of api-storm-2; first posted as lane12/api-storm, eda3a960c, on api-fog-2): "Storm: declarations of its exports agree with their
  definitions", by genheaders --module Storm --header StormApi2.h. 19 new exports in StormApi2.h; StormApi.h's,
  D2StormArrayA.h's and other modules' header lines for Storm addresses take the definitions' types; 68 private
  copies give way. Left out (26): SStrChr, SStrCmpI, SRegLoadData, SMemCmp, SBigFromBinary/New/Sub/ToBinaryBuffer/
  Del/PowMod/IsPrime, uncompress (callers' types, or a header declares them differently; SBigSub/PowMod/IsPrime
  are defined twice in Storm), the eight SMsg(Un)Register* (SMSGHANDLER is only in .cpp files), SStrVPrintf,
  SCmdRegisterArgument (typedefs), ReportHeapError, FreeBlock (static), two Storm globals; and per unit the copies
  whose removal changes the unit (BnDownload.cpp 6, ComCallback.cpp 5, Bnclient Unknown_0052A240.cpp, D2Game
  Game.cpp, D2Hell Archive.cpp 1 each). 325 units EQUAL. VERIFIED tree db9017e2d9eafd984aa0973ff3d2f1ccfbf2f82a.
  linkdebt vs api-fog-2: 29,594 -> 29,365 (type_disagreement 6,616 -> 6,387; D2BNClient -72, D2Client -60,
  D2Common -55, D2Lang -11, D2Win -6, SRP -5, D2Launch -5, others down; no module rises). auditguard: no count
  rose (raw offset 120, byte pointer math 153, pointer casts 4,915).
- Fri Nov 27 7:51 PST 2026: **lane12/genheaders-4** (827b3733e, on #479): genheaders-3 rebased; its first commit is already on main
  (#478's genheaders-2), the second stays: a declaration needing another shared header's typedef is left out unless
  --includes. Tools only. VERIFIED tree 2d9b882586123b5d2168158baa9def02ad5ea17b. Replaces genheaders-3.

## Claimed
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
