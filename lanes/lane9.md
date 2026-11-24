# Lane 9

Written by lane 9 only. Newest entries at the top of each section; delete what is done.

Lane 9 has started (2026-11-23). Owns the renderers and D2Hell: `Source/D2Gfx/**`, `Source/D2Direct3D/**`,
`Source/D2DDraw/**`, `Source/D2Gdi/**`, `Source/D2Glide/**`, `Source/D2Hell/**`, taking over from lane 6.

## Claimed
- From the #341 answers, in this order: D2Gdi (Unknown_006C8250.cpp joins gdiCore.cpp); D2Hell (a) all units /O1, the
  two list ctors keep /O2, and (b) the gpszModuleName join of Unknown_005173EF/00517423/00517874; then the renderer-run
  functions in other lanes' files (QServer.cpp's five d3d getters, D2Win Unknown_006B1BC0.cpp, D2Client
  Unknown_006B2F40.cpp).
- d3dCore.cpp's head: after atl-d3dcore, the strays between the ATL code and d3dCore's own code (see Questions).
- D2Hell object map (0x00516D8B-0x00517E39 and its data 0x0072F9B4-0x0072FA20).

## Status
- Setup done; baseline VERIFIED on #325.
- atl-d3dcore is in #332. Its 2 B note stands: 0x006FADC2 counts as copied, not padding, now that the ATL data shares d3dCore's object.

## Ready
Rebasing onto #345 (900824d3); full verifies running. SHAs and trees below are from #341 and will be replaced.

- lane9/join-d3dcore-2 c841855c placeholders 2->0 (D2Direct3D/Unknown_006B3570.cpp and Unknown_006B42F0.cpp into
  Src/d3dCore.cpp; 52 functions). Full verify on #341: VERIFIED tree a3a68a87. Both pieces' strings and 3570's 0x6FF488
  table lie inside d3dCore's .rdata. The unit becomes /EHsc /GS- (42F0's try/catch needs it; d3dCore's own code is
  equal there too). Piece-private types and three globals that the pieces declared with other types get distinct
  names (gpIDirectDraw4_00970E60 and the like); 0x6B42F0's DirectDrawCreate call casts to d3dCore's prototype.
- lane9/join-gdicore-8250 0b367bbf placeholders 1->1 (D2Gdi/Unknown_006C8250.cpp into Src/gdiCore.cpp, as you said;
  30 functions, flags unchanged). Full verify on #341: VERIFIED tree eaf15dac. 0x6C8750 now calls the real static
  0x6C8380 and draws through CelDrawEx like its neighbours; gdiCore's copies of 0x6C8250/0x6C8380 and the 0x6C8380
  emitter go. **One exception:** 0x6C8A50 (GetBlendedShadows) stays out, now Unknown_006C8A50.cpp. With its body in
  the same file, 0x6C87E0 (its caller) compiles differently from the image under every flag set I tried (the compiler
  uses what it knows of the callee), so the two were not one file.
- lane9/d2hell-o1 2d467bdb placeholders 3->1. Full verify on #341: VERIFIED tree 19624c6a. As you said: config.json gets
  module_flags D2Hell = base + /O1 and the per-unit variants go (34 units equal); Unknown_00517623.cpp and
  Unknown_005176D3.cpp keep the base /O2 set for their list ctors. Unknown_00517423.cpp and Unknown_00517874.cpp join
  Unknown_005173EF.cpp (gpszModuleName; three names for it become one; 10 functions equal).
In #344: place-ddcore-10160 (thanks). In #341: join-d3d-3570, join-d3dsprite-2 (thanks). In #340: join-d3d-7530, join-ddraw-11df0, join-glide-bd30, join-glide-d410 (thanks). Earlier: place-gdismack #338,
join-d3dsprite #336, atl-d3dcore #332 (its 2 B note stands).

## Questions
(none open; thanks for the #341 answers.)

## Notes for other lanes
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
