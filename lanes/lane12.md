# Lane 12

Written by lane 12 only. Newest entries at the top of each section; delete what is done.

Lane 12: link debt for the ordinary build (tools/linkdebt.py): type_disagreement, duplicate_data, local_copy and
renamed_definition. Per-module export headers other modules include (the FogApi2.h way), most-referenced targets
first; the extra definitions of duplicated globals removed. Branches lane12/<topic>, based on lane10/short-data until
it is on main; from #473, based on main.

## Ready

## Claimed
- Fri Nov 27 03:30 PST 2026: **lane12/module-api-headers-6** (lane 2's held branch, rebuilt on #473 f6f04a987):
  its two commits cherry-picked; Gfx_0046E300.cpp is gone on main (GFX_DrawUnitOverlays moved to Gfx.cpp, which
  now takes the D2UnitGfxDataStrc / D2GfxDataStrc names), and the Clients/Game/Level/SkillMonst.cpp hunks keep
  main's side (main had already dropped those copies). precheck: 455 units (every changed unit and every user of
  the 16 changed headers), 0 not all equal. Full verify running; linkdebt and auditguard before/after next.
  Files claimed: the 154 files of lane2/module-api-headers-6 (Source/Include/D2{Gfx,Win,CMP,Sound,Net,Hell,
  MCPClient}Api.h, D2CelContext.h, D2ClientTypes.h, D2Structs.h, D2D3DTypes.h, D2GlideTypes.h, D2Client.h,
  D2ClientFuncs.h, D2Gdi.h, D2Glide.h and the 130 units that drop their copies). After it: tools/genheaders.py on
  its own branch, then gfxdata-record-3, decls-d2game-8, decls-renderers-2.
  Note: build.py's include path for a unit is the repo root, the unit's module directory and Source/Include, so a
  Source/<Module>/<Module>Api.h is not visible to other modules' units; genheaders.py writes exports to
  Source/Include/<Module>Api.h (or the existing Source/Include header), as FogApi2.h is.
- Fri Nov 27 02:05 PST 2026: (superseded by the #473 base) baseline on lane10/short-data (90dddc727): 30,698 refs bound by address;
  type_disagreement 6,823 refs / 1,847 targets, duplicate_data 1,021 / 226, local_copy 623 / 160,
  renamed_definition 541 / 30. Working the top 100 type_disagreement targets (61% of its refs): each takes its
  definition's exact prototype in the defining module's export header (new exports go to <M>Api2.h or a new
  <M>Api.h, included only by the units that use them; a header line that already declares the address is
  corrected), private copies go, and every touched unit and every user of a changed header is rebuilt; a target
  whose header change flips a unit, or a unit a removal flips, is left out and listed here.

## Questions (owner's ruling: void definitions whose callers use a result)

## Notes for other lanes
