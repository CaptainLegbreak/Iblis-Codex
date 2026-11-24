# Lane 9

Written by lane 9 only. Newest entries at the top of each section; delete what is done.

Lane 9 has started (2026-11-23). Owns the renderers and D2Hell: `Source/D2Gfx/**`, `Source/D2Direct3D/**`,
`Source/D2DDraw/**`, `Source/D2Gdi/**`, `Source/D2Glide/**`, `Source/D2Hell/**`, taking over from lane 6.

## Claimed
- d3dCore.cpp's head: after atl-d3dcore, the strays between the ATL code and d3dCore's own code (see Questions).
- D2Hell object map (0x00516D8B-0x00517E39 and its data 0x0072F9B4-0x0072FA20).

## Status
- Setup done; baseline VERIFIED on #325.
- atl-d3dcore is in #332. Its 2 B note stands: 0x006FADC2 counts as copied, not padding, now that the ATL data shares d3dCore's object.

## Ready
- lane9/join-d3d-7530 98bdfd62 placeholders 6->1 (D2Direct3D: Unknown_006B7630, _006B8950, _006B8DF0, _006B8E90,
  _006B87A0 join Unknown_006B7530.cpp; 13 functions). Base main ff0dd9c4 (#335). Precheck: 0 not all equal.
  Full verify: VERIFIED tree 99488276 on #333 (8f1bf35b); rebased onto #335 with namesync (4 renames in the joined file,
  unit rebuilt equal), re-verify of 98bdfd62 running.
  Evidence: the image's calls tie them by file statics. 0x6B7630 calls the static 0x6B7530; 0x6B8950 and 0x6B83A0 call
  the static 0x6B7FD0; 0x6B8DF0 and 0x6B8E90 call the statics 0x6B8950 and 0x6B87A0; 0x6B8E60 calls the static
  0x6B8DF0. With the bodies together the context copies, the glyph emitter and the ecx struct trick for 0x6B87A0 go
 . 0x6B7FD0's parameters are (nSide, pRect, pOffset, bFlag): its
  custom-convention callers evaluate pRect before nSide. gaGeometry (0x0074C100) moves to this unit's data.
  Two declaration-set sensitivities in 0x6B8950, both fixed naturally: its indexed draw goes through the file's own
  device record (as the piece had it), and the file's statics are prototyped once at the top.
- lane9/place-gdismack 224c0be7 placeholders 1->0 (D2Gdi/Unknown_006C9900.cpp into gdiSmack.cpp). Base main ff0dd9c4 (#335;
  verified on #333, rebase crosses only name sweeps). Precheck: 0 not all equal. Full verify: VERIFIED tree 145e8920.
  GdiPlaySmacker 0x6C9900 calls gdiSmack.cpp's file static RemapRows 0x6C9690 (the placeholder carried a context copy of
  it), so it is gdiSmack code; gdiSmack already defined it and builds equal with it, and now defines gbRemapValid.
- lane9/join-d3dsprite dbee0f1a 4->2 units (d3dSprite group: Unknown_006B5C80.cpp and d3dSprite_006B5CF0.cpp go;
  d3dSprite.cpp now owns 0x6B5C80 and 0x6B5CF0, which it already defined). Base main ff0dd9c4 (#335; verified on #333, the rebase crosses only name sweeps in other files).
  Precheck: no changed units (deletions only; d3dSprite.cpp and the remaining piece built: 0 not all equal).
  Full verify: VERIFIED tree 0eb9d35e. Every d3dSprite unit builds equal with and without /GS-, so flags don't keep
  the group apart; d3dSprite_006B5D40.cpp stays until its shims are reconciled with the main file's.
## Questions
- Coordinator, D2Hell grouping (I'll hold off joining until you say): every D2Hell unit builds equal under one flag
  set, plain `/O1` (config flags + /O1), including the pieces now carrying /O2, /Os, /O1 /Ob1 /Oy- or /GS- variants. The
  only exceptions are two copies of one list constructor, 0x00517628 and 0x005176E4 (TSList-style ctor: linkOffset 0,
  terminator links to itself), which match only under /O2; I tried six natural spellings, /O1 /Oi and /Os. The code run
  0x00516D8B-0x00517E39 has no inter-function padding (size-optimised objects). Evidence of file boundaries is thin:
  Archive.cpp has its allocation tags; nothing else has an assert or tag. D2Hell's .data is one block after one
  language copy (0x0072F9B4: gpReference read by 0x516DE1, the TMESSAGESOURCE type descriptor used by 0x517669's
  node allocator, gtMessages read by 0x517804). Proposal: (a) set all D2Hell units to `/O1` now (no joins, flags only;
  the two ctors keep /O2), which removes eight flag variants; (b) gather only what a shared global or const table ties
  together. OK to do (a)?
- Coordinator: may I take into my files the renderer-run functions that are filed in other lanes' files (as lane 5 did
  with the Task.cpp locks)? Each sits inside a renderer's address run:
  - Fog `QServer/QServer.cpp`: 0x006B1C00, 0x006B20A0 (QSERVER_GetFloorCacheSize), 0x006B20B0, 0x006B2F20, 0x006B76C0.
    QServer's own run is 0x006BE3C0 and up; these five are getters among d3dCore's functions and return d3d globals
    (0x00970E50, the floor-cache size). They go to d3dCore.cpp and its neighbours.
  - D2Win `Unknown_006B1BC0.cpp` (0x006B1BC0: frees the d3d floor, subtile and texture caches), between d3dCore's ATL
    code and its own: to d3dCore.cpp.
  - D2Client `Unknown_006B2F40.cpp` (0x006B2F40), inside the D2Direct3D run.
  - D2Win `Unknown_0050F910.cpp`: Glide 0x0050F910, 0x0050FBD0, 0x0050FDF0 and DDraw 0x00510130-0x005103B0 (stubs and
    DDrawLogError), 0x005137E0 (PlayBinkMovie), all between glBlocks.cpp and ddCore.cpp's code.
  - D2Win `Unknown_00508970.cpp`: 0x00508970 GlideLoadLibrary, 0x00508F60 GlideCheckBoards, at the head of the Glide run.
  - Storm `SCMD.CPP`: 12 three- and six-byte stubs 0x006C7CC0-0x006C8A40 inside gdiCore's run.
  - Bnclient `Unknown_00517520.cpp`, `Unknown_0051752A.cpp`, `Unknown_005175E3.cpp` (0x00517520-0x00517619), inside the
    unpadded D2Hell run (D2StormList/Record members D2Hell's own pieces use).

## Notes for other lanes
- Coordinator: the 264 B + 32 B still copied at 0x006CC618/0x006CC75C (borrowed-data.md lists them "between - and
  D2Hell/Unknown_00517423.cpp") are not D2Hell's: 0x006CC618 is a table of initializer pointers into 0x006CA700-
  0x006CB050, i.e. the CRT's .CRT$XCU list; they belong with the CRT/initializer work (lane 3 or you).
- Lane 6 (renderer files hold your functions; post here so you can take them, I won't move them):
  - Glide `glCore.cpp`: SCROLLBAR_Destroy 0x00507EE0 (D2Win run); BNCLIENT_GetInterfaceTable 0x00518C10,
    BNCLIENT_GetLogonType 0x0051A570, sub_0051CA10, BNCLIENT_IsSetEmailRequested 0x0051CA70 (D2BNClient run).
  - D2Gfx `Window.cpp`: CMNSUBTILE_SetPaletteTables 0x004F8E40, inside D2Win's Unknown_004F6F60.cpp run.
  - Language table: the copy 0x0072F7F4 is planned in ddCore.cpp (gData_0072F7F4) but starts D2Sound's
    Unknown_00513A20.cpp data; it belongs to that object. The reverse at the D2Hell edge: the copy 0x0072F9B4
    (gData_0072F9B4, planned in D2SoundSmp.cpp) starts D2Hell's data (gpReference 0x0072F9F0 onward); I'd like to take
    it for D2Hell/Unknown_00516DE1.cpp's object.
  - After D2Hell's data, the copies 0x0072FA20 and 0x0072FA60 (each followed by 4 zero bytes, both inside
    gData_0072FA20 in D2Hell/Unknown_00517804.cpp's plan) precede gtBnClientInterface. They are two objects' copies,
    not D2Hell's: probably BNetGW.cpp's and the next D2BNClient object's. I'll take them out of D2Hell's plan when I do
    the D2Hell data; tell me which D2BNClient files they start and I'll put them there in the same branch, or leave it
    to you.
- Lane 6's note that D2Direct3D 0x006B1C70 sits in the QServer run: it doesn't. QServer's run is 0x006BE3C0 and up;
  0x006B1C70 is d3dCore code (it builds equal in d3dCore.cpp).
