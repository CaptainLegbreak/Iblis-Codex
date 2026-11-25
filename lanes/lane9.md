# Lane 9

Written by lane 9 only. Newest entries at the top of each section; delete what is done.

Lane 9 has started (2026-11-23). Owns the renderers and D2Hell: `Source/D2Gfx/**`, `Source/D2Direct3D/**`,
`Source/D2DDraw/**`, `Source/D2Gdi/**`, `Source/D2Glide/**`, `Source/D2Hell/**`, taking over from lane 6.

## Claimed
- The three unpadded placeholder runs as one file each (lane 10's object map): D2Hell 0x516D8B-0x5179A4 (25
  placeholders, plus the gFaultHandlerList init/fini 0x6CAE5F/0x6CB401; the two /O2 list-ctor units stay out), D2Gdi
  0x6C8A50-0x6C95D0, D2DDraw 0x511DF0-0x512D90. hell-run (#366), gdi-run and ddraw-run (#367) are in. Now: files-d2direct3d.tsv medium rows (d3d-7250, d3d-strays, d3d-2f60 are in, #369). Next: queues.md row..
- **Coordinator, a blocker on the D2Gdi and D2DDraw runs:** each run holds a static line helper (0x6C8DA0, 0x512A50)
  that two rectangle drawers of the same run call through a register convention only a static gets. With all three in
  one file, either the callers or the helper's own body come out differently: in 24 signature/order/body variants the
  best has every caller equal and the helper differing in one register choice (ebx vs edx for the second point's y).
  Separately compiled, the helper and the callers each match. Until that gives, I'll post the two runs without the
  helper's file (helper + its file-mates stay where they are) unless you'd rather wait.
  Update: the two rectangle drawers call 0x6C8DA0 with ecx/edx loaded fastcall-style (first point in ecx), and the
  helper built alone as a non-static __fastcall matches. With one shared non-static __fastcall definition, the callers
  get the right registers but the two `lea`s in the other order; with the static stdcall copy as the definition, the
  callers match and the helper differs (ebx vs edx), under /Ob2 and /Ob1 alike. Still parked.

## Status
- Setup done; baseline VERIFIED on #325.
- atl-d3dcore is in #332. Its 2 B note stands: 0x006FADC2 counts as copied, not padding, now that the ATL data shares d3dCore's object.

## Ready
- lane9/glide-noinline 23108e76, on main 2da823bd (#370), precheck 0 not all equal; full verify VERIFIED, borrowed data 844 B
  (main's). Follows your Gfx.cpp ruling: D2Glide/Unknown_0050BD30.cpp drops its per-file /Ob1, the blended-shadow getter
  0x50BF40 takes one __declspec(noinline) with a comment, the draw-rect helper 0x50C690 loses its inline. 24 equal.
  The same route doesn't join the other getters: D2Gdi 0x6C9290 still differs with a noinline 0x6C8A50 in its file
  (register choice, not inlining), and 0x6B7530 into 0x6B7250 with both getters noinline still leaves 0x6B83A0 and
  0x6B8950 different (float scheduling). So those stay separate objects.
- lane9/gdi-7cf0 957a2444, on main 6af4454b (#371), precheck 0 not all equal; full verify VERIFIED, borrowed data 844 B
  (main's). Placeholders -1: gdiCore.cpp takes Unknown_006C7CF0's seven functions (0x6C8000-0x6C80A0, interleaved with
  gdiCore's own 0x6C8020/0x6C8050/0x6C8060; they set gdiCore's palette view and render window and use its palette and
  palette handle). 53 equal. glide-noinline (above) is still clean on #371.
- lane9/d3d-strays-2 dda480d2, on main 70376fda (#371), precheck 0 not all equal; full verify VERIFIED, borrowed data 844 B
  (main's). Placeholders -1: Unknown_006B7250.cpp takes the line drawer 0x6B7B30 (between its 0x6B7980 and 0x6B7C90;
  only callers are that file's rect and diamond drawers, plus d3dCore's function table). 25 equal. The empty stub
  0x6B76C0 stays: it sits between 0x6B7530's and 0x6B7250's code and builds equal anywhere, so nothing places it.
- Superseded, please drop: lane9/join-ddraw-util, lane9/join-gdi-util.

## Questions
(none open; thanks for the #341 answers.)

## Notes for other lanes
- **Coordinator, on queues.md's lane 9 context copies:** the four DrawLine copies (D2Gdi Unknown_006C8F70/006C9030 of
  0x6C8DA0; D2DDraw Unknown_00512C20/00512CE0 of 0x512A50) don't look like join candidates. Joining 006C8F70 and
  006C9030 into Unknown_006C8DA0.cpp breaks the callers or 0x6C8DA0 itself under every signature I tried (static
  stdcall/fastcall/cdecl, the home file's fastcall, swapped argument order): the callers want a register convention
  that only the per-file static copy produces. That fits a header-defined static line helper compiled into each file
  and folded into one body by the linker's identical-code folding, so the copies may be the original's shape. I've
  dropped the claim. Likewise 0x5170E7 (Archive.cpp's shim): it takes its argument in eax but nothing calls it.
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
    Unknown_00513A20.cpp data; it belongs to that object. **Correction:** the copy 0x0072F9B4 (now planned in
    D2SoundUtil.cpp) stays there. D2SoundUtil.cpp (0x516950-) is the last D2Sound object, right before D2Hell's first
    code (0x516D8B), and has no other data, so this is its own copy; D2Hell is a Storm-style library that doesn't include
    D2's language header. (language-objects.md lists the copy as starting D2Hell/Unknown_00516DE1.cpp because the next
    planned data is D2Hell's; a data-less object's copy reads that way.) I've dropped that request.
  - After D2Hell's data, the copies 0x0072FA20 and 0x0072FA60 (each followed by 4 zero bytes, both inside
    gData_0072FA20 in D2Hell/Unknown_00517804.cpp's plan) precede gtBnClientInterface. They are two objects' copies,
    not D2Hell's: probably BNetGW.cpp's and the next D2BNClient object's. I'll take them out of D2Hell's plan when I do
    the D2Hell data; tell me which D2BNClient files they start and I'll put them there in the same branch, or leave it
    to you.
- Lane 6's note that D2Direct3D 0x006B1C70 sits in the QServer run: it doesn't. QServer's run is 0x006BE3C0 and up;
  0x006B1C70 is d3dCore code (it builds equal in d3dCore.cpp).
