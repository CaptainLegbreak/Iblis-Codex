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
All on main 386d6e91 (#337), rebased today with namesync; each branch's changed units rebuild equal on its #337 head.
A tree with all seven cherry-picked onto #337 (gdismack, d3d-7530, ddraw, glide-bd30, glide-d410, d3d-3570,
d3dsprite-2, in that order) applies without conflicts beyond units.json/data_plan.json/docs and builds equal; its full
verify is queued and I'll post the tree id.

- lane9/place-gdismack cc959493 placeholders 1->0 (D2Gdi/Unknown_006C9900.cpp into gdiSmack.cpp). Full verify:
  VERIFIED tree 145e8920 (on #333). GdiPlaySmacker 0x6C9900 calls gdiSmack.cpp's file static RemapRows 0x6C9690.
- lane9/join-d3d-7530 d75177c6 placeholders 6->1 (Unknown_006B7630, _006B8950, _006B8DF0, _006B8E90, _006B87A0 join
  Unknown_006B7530.cpp; 13 functions). Full verify: VERIFIED tree fadd5258 (on #335). Evidence: file statics 0x6B7530,
  0x6B7FD0, 0x6B8950, 0x6B87A0, 0x6B8DF0 called across those units. 0x6B7FD0 takes (nSide, pRect, pOffset, bFlag).
  Two declaration-set sensitivities in 0x6B8950, fixed naturally (its indexed draw through the file's own device
  record; the file's statics prototyped once at the top).
- lane9/join-ddraw-11df0 f17e4c44 placeholders 1->0 (D2DDraw/Unknown_00512250.cpp into Unknown_00511DF0.cpp). Full
  verify: VERIFIED tree 7887dac9 (on #335). 0x512250 (sub_00512250_DrawCel) is the only caller of the file static
  ClipCel 0x511E80; the file's emitter for it becomes the real function.
- lane9/join-glide-bd30 04390cae placeholders 4->1 (D2Glide Unknown_0050BBA0, _0050CA00, _0050CF70 join
  Unknown_0050BD30.cpp; 14 functions). Full verify: VERIFIED tree 8bd90044 (on #335). Evidence: file statics 0x50BD30
  and 0x50C690 called across them; GlideGetDrawRect 0x50C690 takes (bPerspective, nScreenPanels, pRect, pOffset).
- lane9/join-glide-d410 73c54178 STACKED on lane9/join-glide-bd30, placeholders 2->0 (Unknown_0050CDD0 and
  Unknown_0050D410 join the same unit; 18 functions). Full verify: VERIFIED tree 211ccdbe (on #335). 0x50D410/0x50D4C0
  call the file statics 0x50CDD0 and 0x50CF70.
- lane9/join-d3d-3570 86b9058f placeholders 1->0 (D2Direct3D/Unknown_006B4C90.cpp into Unknown_006B3570.cpp). Full
  verify of its #337 rebase before namesync (79b0123b, which differs by two renamed lines) is running. DetectDirect3D
  0x6B4C90 is a file static whose only caller is 0x6B4E80. The unit is /EHsc /GS-, as its try/catch blocks need;
  LOGMANAGER_WriteLogLine keeps its throw() declaration, which /EHsc reads.
- lane9/join-d3dsprite-2 0c0e5581 pieces 2->1 (d3dSprite_006B5D40.cpp joins d3dSprite.cpp; 19 functions). Full verify
  queued. The piece's functions call d3dSprite.cpp's statics 0x6B5C80, 0x6B5CF0, 0x6B6680, and d3dSprite.cpp's
  0x6B7090 calls the piece's statics 0x6B5D40 and 0x6B63F0. Shims, context copies, emitters and the two noinline
  prototypes go; the three names for the 0x00970F40 counter become one static. **Please look at one point:**
  DrawQuad 0x6B63F0 returns what its exits leave in eax (the failed Lock's result; on the normal path there is no
  return statement, a C4715 warning), and 0x6B7090 returns that value, as the image does. It adds no instructions.
  If you'd rather not have a missing return, I'll keep 0x6B7090 and 0x6B63F0 apart instead.
- join-d3dsprite (the first half) is in #336; atl-d3dcore is in #332 (its 2 B note stands: 0x006FADC2 now counts as
  copied, not padding).

## Questions
- Coordinator, D2Gdi direction (I'll hold off): the file static 0x6C8380 (in Unknown_006C8250.cpp, 12 functions) is
  called from 0x6C8750, which is filed in gdiCore.cpp. So 0x6C8750 and Unknown_006C8250 are one object. gdiCore.cpp's
  only file evidence is the allocation tags in 0x6C7A70/0x6C7AB0, 0x6C8750 came into gdiCore from a placeholder, and
  the two units interleave function by function over 0x6C7A70-0x6C8C43 (renderer code here doesn't follow file
  order, as in Glide). Either Unknown_006C8250 joins gdiCore.cpp, or 0x6C8750 (and its neighbours 0x6C81A0, 0x6C84B0,
  0x6C86A0) leave gdiCore for the placeholder. I lean to the first: one D2Gdi core object. Which do you want?
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
  Update: one such tie exists. The const pointer gpszModuleName (0x006CC848, planned in Unknown_00517423.cpp) is read
  by 0x5173EF/0x51740B (Unknown_005173EF), 0x517423 (Unknown_00517423) and 0x517874 (Unknown_00517874), so those three
  are one file by the const-table rule. With your OK I'd join them under /O1 (all three build equal there).
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
