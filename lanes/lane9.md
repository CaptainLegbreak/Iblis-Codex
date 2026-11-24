# Lane 9

Written by lane 9 only. Newest entries at the top of each section; delete what is done.

Lane 9 has started (2026-11-23). Owns the renderers and D2Hell: `Source/D2Gfx/**`, `Source/D2Direct3D/**`,
`Source/D2DDraw/**`, `Source/D2Gdi/**`, `Source/D2Glide/**`, `Source/D2Hell/**`, taking over from lane 6.

## Claimed
- From queues.md: the DrawLine context copies. D2Gdi Unknown_006C8F70 + Unknown_006C9030 into Unknown_006C8DA0 (lane9/join-gdi-line); D2DDraw Unknown_00512C20 + Unknown_00512CE0 into Unknown_005125E0 (lane9/join-ddraw-line). Each pair calls its home file's static DrawLine.
- Renderer functions filed in D2Win: Unknown_0050F910.cpp (Glide 0x50F910, 0x50FBD0, 0x50FDF0; DDraw 0x510130-0x5103B0,
  0x5137E0) and Unknown_00508970.cpp (0x508970 GlideLoadLibrary, 0x508F60 GlideCheckBoards). Lane 6: please don't edit
  these meanwhile. Then Storm SCMD.CPP's stubs in gdiCore's run and the Bnclient units in the D2Hell run.
- D2Hell object map (0x00516D8B-0x00517E39 and its data 0x0072F9B4-0x0072FA20).

## Status
- Setup done; baseline VERIFIED on #325.
- atl-d3dcore is in #332. Its 2 B note stands: 0x006FADC2 counts as copied, not padding, now that the ATL data shares d3dCore's object.

## Ready
All on main bc489a89 (#359), namesync run, precheck 0 not all equal on each head; borrowed data in each full verify:
906 B, main's figure.

- lane9/join-glcore-8970 de4efb47 (placeholders -1): D2Glide/Unknown_00508970.cpp joins glCore.cpp. The language
  copy 0x72F13C (planned there) is the only copy in front of glCore's .data and is followed directly by the Glide
  function table 0x72F178 (glCore's since #357) and glCore's own data from 0x72F250. The table's first entry is
  GlideCheckBoards 0x508F60, whose only callee is GlideLoadLibrary 0x508970. 45 functions equal. Full verify: VERIFIED
  tree 411a179d, borrowed data 906 B.
- lane9/gdi-stubs a574fada, STACKED on join-glcore-8970: 13 small functions filed in Storm/SOURCE/SCMD.CPP sit inside
  gdiCore's code run (0x6C7A60-0x6C8A40). Eleven are entries of the GDI function table (gdiCore's since #357); 0x6C8020
  returns gdiCore's ghBufferBitmap and is called by gdiCore's 0x6C8970; 0x6C8240 returns 0x7C914C like its neighbours.
  All join gdiCore.cpp; gdiCore (43) and SCMD.CPP (53) stay equal. Full verify: VERIFIED tree 9bd3cc7e, borrowed data
  906 B. (Storm's lane: SCMD.CPP loses these 13; please don't edit them meanwhile.)
- lane9/hell-bnclient-pieces 1d957e5b: Bnclient/Unknown_00517520.cpp, Unknown_0051752A.cpp, Unknown_005175E3.cpp
  (0x517520-0x517619, storm-list members) sit inside D2Hell's unpadded code run; they move to Source/D2Hell and build
  equal under D2Hell's /O1 module default, so their own flag sets go. Full verify: VERIFIED tree 743065d5, borrowed
  data 906 B. (Lane 6: three Bnclient placeholders leave.)

In #357: take-win-strays, renderer-tables (thanks). In #350: drawquad-note, move-d3d-bink, take-renderer-strays (thanks). In #347: join-d3dcore-2, join-gdicore-8250, d2hell-o1. In #344: place-ddcore-10160. In #341: join-d3d-3570, join-d3dsprite-2. In #340: join-d3d-7530, join-ddraw-11df0, join-glide-bd30, join-glide-d410 (thanks). Earlier: place-gdismack #338,
join-d3dsprite #336, atl-d3dcore #332 (its 2 B note stands).

## Questions
(none open; thanks for the #341 answers.)

## Notes for other lanes
- **Lane 1:** D2Client/Unknown_004F4EC0.cpp (0x4F4FF0 SetVideoMode and five data blocks) is D2Gfx's: the selector and
  its table gapGraphicsInterfaces (0x72DA80) sit inside Window.cpp's code and data, and the other four blocks are the
  renderers' function tables, each right where its renderer's core .data starts. Lane 9 moves them on
  lane9/renderer-tables and the placeholder goes; please don't edit it meanwhile.
- Window.cpp's .data run 0x72DA0C-0x72DB44 holds three 4-byte strays filed elsewhere: 0x72DA7C (planned in glCore.cpp),
  0x72DAA0 and 0x72DB3C (Storm/Unknown_006CACE0.cpp). I'll look at the first; Storm's lane, the other two may be
  Window's.
- **Storm's lane (at the user's request):** `Storm/Unknown_006BBBF0.cpp` is the renderer's Bink video player (0x6BBCE0
  is called from d3dCore.cpp's 0x6B56C0), not Storm code. Lane 9 moves it to `Source/D2Direct3D/` on
  lane9/move-d3d-bink; please don't edit it meanwhile.
- **Lanes 3, 6 and 4 (coordinator's #341 answer):** lane 9 takes these renderer-run functions into its files; please
  don't edit them meanwhile. Lane 3: Fog `QServer/QServer.cpp` 0x006B1C00, 0x006B20A0, 0x006B20B0, 0x006B2F20,
  0x006B76C0. Lane 6: D2Win `Unknown_006B1BC0.cpp` (0x006B1BC0). Lane 4: D2Client `Unknown_006B2F40.cpp`
  (0x006B2F40). One branch, lane9/take-renderer-strays; I'll post it here.
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
