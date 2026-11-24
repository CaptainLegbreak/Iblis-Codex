# Lane 9

Written by lane 9 only. Newest entries at the top of each section; delete what is done.

Lane 9 has started (2026-11-23). Owns the renderers and D2Hell: `Source/D2Gfx/**`, `Source/D2Direct3D/**`,
`Source/D2DDraw/**`, `Source/D2Gdi/**`, `Source/D2Glide/**`, `Source/D2Hell/**`, taking over from lane 6.

## Claimed
- d3dCore.cpp's head: after atl-d3dcore, the strays between the ATL code and d3dCore's own code (see Questions).
- D2Hell object map (0x00516D8B-0x00517E39 and its data 0x0072F9B4-0x0072FA20).

## Status
- Setup done; baseline VERIFIED on #325.
- lane9/atl-d3dcore: ready (below). Next: D2Hell object map; renderer-run strays wait on the question below.

## Ready
- lane9/atl-d3dcore 7581b2b5 1->0 placeholders (D2Direct3D/Unknown_006B1A00.cpp joined into d3dCore.cpp). Base main c4ce2baa (#331).
  Precheck: 0 not all equal. Full verify on #331: VERIFIED tree 48d58fc0 (borrowed data 2,380 B on the branch; see the 2 B note below).
  The ATL object is the head of d3dCore.cpp, as lane 3 thought: d3dCore includes atlbase.h, so atldef.h's Thank_you,
  CAtlException, CRegKey come first in its object, then d3dCore's own code from 0x6B1B60 (the texture-format callback,
  which reads d3dCore's gtWantedFormat). The merged unit builds equal under d3dCore's /GS-, all 47 functions. Joined by
  hand (ATL preamble, then d3dCore's preamble, then bodies), because mergegroup's variable hoisting puts d3dCore's
  externs above the records they use. d3dCore's private 8-dword pixel-format record became the piece's named one.
  **Borrowed data +2 B:** the 2 zero bytes at 0x006FADC2, in front of AtlLimits at 0x6FADC4, count as alignment padding
  when the ATL data is its own object and as copied once it shares d3dCore's object (the next piece no longer gets
  4-byte start alignment in the padding rule). Every byte is still equal. If you want it gone first, say so and I'll
  look at how the merged object's .rdata pieces get their alignment.

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
