# Lane 9

Written by lane 9 only. Newest entries at the top of each section; delete what is done.

Lane 9 has started (2026-11-23). Owns the renderers and D2Hell: `Source/D2Gfx/**`, `Source/D2Direct3D/**`,
`Source/D2DDraw/**`, `Source/D2Gdi/**`, `Source/D2Glide/**`, `Source/D2Hell/**`, taking over from lane 6.

## Claimed
- **The .CRT$XCU initializer-table prototype** (coordinator's assignment), `lane9/crt-xcu-*`. What the compiler does,
  from main's objects: the 49 initializers already written as real dynamic initializers (`build: symbol ??__E...`
  lines, e.g. SUnit.cpp's gnUnitInitSeed, ErrorManager.cpp's gdwMainThreadId) each come out in a `.text$yc` section,
  plus a 4 B `.CRT$XCU` section with one DIR32 to it. The atexit destructors (D2Hell's 0x6CB401 and the like) are
  `.text$yd`. Nothing references the .CRT$XCU pieces, so link_exe.py's anchor-based data placement leaves them
  unplaced (removed) and the table is copied. First step: anchor each piece at the original slot holding its
  initializer's address.
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
- lane9/window-data 2bfe5553, on main 5cc54de8 (#375), precheck 0 not all equal; full verify VERIFIED, borrowed data 844 B
  (main's). Plan only: Window.cpp's .data run (0x72DA0C-0x72DBFB, then Unknown_004F6F60's 0x72DBFC and D2WinMain's
  copy 0x72DC00) held four items planned in D2Glide files, all read by Window.cpp itself: the flag 0x72DA7C (glCore.cpp)
  and the subtile row tables 0x72DB48/0x72DB84/0x72DBC0 (glDebugFont.cpp). Their definitions move to Window.cpp's plan.
  Storm/Unknown_006CACE0.cpp's two strings in the same run (0x72DAA0, 0x72DB3C) are read only by dynamic initializers,
  so they wait for lane 7's initializer prototype.
- lane9/crt-xcu-tool bcbddc9f, on main f0f40e42 (#377), precheck 0 not all equal; full verify VERIFIED, **borrowed data 844 -> 648 B** (Game.exe identical). Step 2 of the initializer-table plan, the tool alone: link_exe.py's
  place_data anchors each unit's .CRT$XCU piece (4 B, one DIR32 to the unit's .text$yc initializer) at the original
  table slot holding that initializer's placed address (only when the address occurs once in .rdata). The 49
  initializers already written as real dynamic initializers (`build: symbol ??__E...` lines) all get their slots,
  hence -196 B at once rather than -4. The copied 264 B run at 0x6CC618 shrinks to 68 B in seven runs: the 17 slots
  whose initializers are still plain functions. No other copied run changes. Eight pieces whose initializer isn't
  placed (a global's duplicate in a second unit: gwszPopUpText, gwszNameSeparator, gwszRealmNames, gwszFramedText,
  gtNewsItems) stay removed and are counted (crt_table_target_unplaced). Step 3 (one more initializer, D2Hell's
  0x6CAE5F) follows as lane9/crt-xcu-hell.
- lane9/crt-xcu-hell fd2fe416, stacked on crt-xcu-tool (main f0f40e42, #377), precheck 0 not all equal; full verify
  VERIFIED, **borrowed data 648 -> 644 B**, copied runs: only 0x6CC6C4 shrinks 32 -> 28 B. Step 3, one initializer:
  D2Hell's gFaultHandlerList (0x72FA14) is defined in the unit as a D2ListStrc with a constructor and destructor, in
  place of the stand-ins 0x6CAE5F/0x6CB401 and its plan entry. What the compiler does: the constructor's constant
  stores (link offset 0, terminator back-link to itself) are folded into the .data image; only the non-constant
  terminator mark (~&terminator) stays in ??__EgFaultHandlerList (.text$yc), which atexit-registers
  ??__FgFaultHandlerList (.text$yd); both place from `build: symbol` marker lines alone and build equal. The
  dynamically initialized global is emitted after the unit's statically initialized data, so its .data section's
  layout no longer matches the original; the section splits (the existing split pass does it) as long as the global
  gets no data marker of its own (a marker makes the strict check fail).
- lane9/crt-xcu-owners d84e6030, stacked on crt-xcu-hell (main f0f40e42, #377), precheck 0 not all equal; full verify
  VERIFIED, **borrowed data 644 -> 608 B** (Game.exe identical). Step 4: nine more initializers come from the units
  that own their globals, with their Storm stand-ins dropped: CharSel.cpp gwszRealmNames (0x6CA940), D2WinFont.cpp
  gwszFramedText (0x6CAE20) and the color/monster code strings (0x6CAE40, 0x6CAE50), BNNews.cpp gtNewsItems
  (0x6CAEC0/0x6CB450), BnSend.cpp gtBigPair (0x6CAEF0/0x6CB480), D2Game Game.cpp gnTargetMsPerFrame (0x6CAF10),
  Window.cpp's three window texts (0x6CADF0, 0x6CAE00, 0x6CAE10; their two default strings 0x72DAA0/0x72DB3C move into
  Window.cpp's plan, which also touches lane9/window-data's Window.cpp plan entry: merge one, I'll rebase the other).
  Storm/Unknown_006CAE80.cpp and Bnclient/Unknown_006CB420.cpp end up empty and are removed. The user tells me lanes
  1-6 are inactive and lane 9 may take their files, so I'm doing the rest of the 16 myself. **Update:** the user has
  since withdrawn that; lane 9 is back to its own modules. crt-xcu-rest below was already in flight and is the last
  branch touching other lanes' files.
- lane9/crt-xcu-rest 7cefb6d0, on main 1beee1c7 (#380), precheck 0 not all equal; full verify VERIFIED,
  **borrowed data 281 -> 269 B** (main 281 B; Game.exe identical). Three more initializers with their owners: the
  "Header"/"Game Time" hashes (0x6CA960/0x6CA980, bss 0x77AD64/0x77AD60) in D2Multi/Unknown_0043C8A0.cpp, whose bss and
  rdata they end; the ms-per-tick quotient (0x6CAAB0, bss 0x7A6B0C) in D2Client/ENGINE/Cursor.cpp, which also takes its
  divisor's plan entry 0x7121DC (the last of Cursor's data). Files touched: D2Multi/Unknown_0043C8A0.cpp (lane 6),
  D2Client/ENGINE/Cursor.cpp (lane 1), Storm/Unknown_006C9A68.cpp (lane 3/10). Pitfall: a data marker on the
  initializer's own line (`T g = f(...); // 0xVA`) is read as f's address; put the marker on a separate extern line.
- lane9/atl-clash e559f22a, on main 1beee1c7 (#380), precheck 0 not all equal; full verify VERIFIED, **borrowed data
  281 -> 277 B** (main 281 B; Game.exe identical). d3dCore.cpp: the 4 B at 0x74C0C8 (the "d3dCore/Unknown_006B7250"
  row) are ATL's Define_the_symbol__ATL_MIXED::clash, a selectany global whose inline constructor folds into the
  data image (vtable pointer 0x6FAFFC). Thank_you's constructor and virtual function become inline, as in the ATL
  header, placed from `build: symbol` lines; both still build equal.
- **Coordinator, borrowed-data rows on lane 9 that aren't lane 9's:**
  - 0x74C6E4 (12 B, "between D2Hell/Unknown_006C9A38.cpp and Fog/Unknown_00401010.cpp"): three unread pointers to
    Fog's strings gszInternalCheckHost 0x6FF994, "MiniDump Thread" 0x6FFA34 and "MiniDump" 0x6FFA28, right after Fog's
    Report@crashy type descriptor and right before Fog's ghProcess. Fog's (lane 3), not D2Hell's.
  - 0x6CC75C (32 B): 4 zero bytes and then the image's debug directory entry (stamp 0x574DDFBC, type 2 CodeView,
    size 0x40); linker output, a tools row.
- Audit (audit-379-lanes.md, lane 9's rows), taken in this order: parameter names, decompiler types, labels, then
  noinline, emit helpers, f_<hex>/unk0x fields, declarations into the module headers.
- lane9/audit-params-renderers 32d7fc53, on main 312ab020 (#383), precheck 0 not all equal, auditguard no count rose
  (a1/v12 2,826 -> 2,728, all 98 of lane 9's); full verify VERIFIED, borrowed data 265 B (= main). One branch for the
  six modules since no bytes change: Glide entry points take the SDK's names, the tile/sprite validators bAsync/nFlags,
  ddCore's perspective stubs and the Glide floor-tile drawer the names in D2Gfx.h's function table (the stubs' two
  out-pointers become int*, units.json names follow), FaultDoAssert szFile/nLine/szExpression from its format string.
- lane9/audit-types-d2direct3d 0e3efc56, on main 312ab020 (#383), precheck 0 not all equal, auditguard no count rose
  (decompiler types 143 -> 131); full verify VERIFIED, borrowed data 265 B (= main). Unknown_006B7530.cpp's U32/U8
  become unsigned int / unsigned char.
- lane9/audit-labels-renderers fe068fc9, on main ab43ba69 (#384), precheck 0 not all equal, auditguard no count rose
  (decompiler labels 38 -> 34); full verify VERIFIED, borrowed data 265 B (= main). The two Bink players' LABEL_FAIL
  (ddCore.cpp, D2Glide/Unknown_0050F910.cpp) becomes OpenFailed. (audit-params-renderers and audit-types-d2direct3d,
  above, still apply cleanly on #385.)
- lane9/audit-noinline-renderers 2fbf9e4c, on main 1b5f8920 (#385), precheck 0 not all equal, auditguard no count
  rose; full verify VERIFIED, borrowed data 261 B (= main). All eight noinline uses in lane 9's files are needed:
  each unit differs without its attribute (tested one at a time). The six cache append statics (d3dTextureCache,
  d3dSubtileCache, d3dFloorCache, glTextureCache, glSubtileCache, glFloorCache) take their arguments in eax/ecx with
  their callers in the same object, the #368 case; each gets a one-line comment. **Can't delete, and not the #368
  case:** D2GFX_SetPalette (Window.cpp, exported stdcall) and sub_0050BF40_GlideGetBlendedShadows
  (D2Glide/Unknown_0050BD30.cpp, cdecl, already commented).
- lane9/audit-emit-renderers b639ae1e, on main 1b5f8920 (#385), precheck 0 not all equal, auditguard no count rose
  (emit helpers 544 -> 541); full verify VERIFIED, borrowed data 261 B (= main). Removed (each unit stays equal):
  sub_J03_EmitScaleReaders (Window.cpp), sub_Emit_006B7FD0 (Unknown_006B7530.cpp), sub_leg345d_Emit_0050A9A0
  (glSprite.cpp). **Still needed** (the unit differs without it): gdiCore.cpp's sub_006C8310_EmitCelClip,
  glSprite.cpp's sub_M120_Emit_0050A1E0, d3dTextureCache/d3dSubtileCache's EmitCaller, and the D2Glide cache
  helpers in glTextureCache.cpp and glSubtileCache.cpp/glFloorCache.cpp.
- lane9/audit-fields-renderers d8d06bf2, on main 7a9094d8 (#386), precheck 0 not all equal, auditguard no count rose;
  full verify VERIFIED, borrowed data 261 B (= main). Window.cpp: the tile block takes D2GlideTileStrc's layout, the
  light palettes drop their unk0x00 alias for colors, D2DevModeStrc spells out DEVMODEA's fields (42 unk0x/f_ uses
  gone); d3dCore's surface lpVtbl, d3dTextureCache's tLink, DDraw clip result's nFirstRow. Left: fields with no
  evidence in the code (d3dSprite's pool entry words, d3dFloorCache's f_8, the Glide debug vertex's 0x18 float,
  which the vertex layout doesn't use, D2Hell's record word, D2Glide.h's debug cell bytes).
- lane9/audit-decls-d2glide ff86442f, on main 7a9094d8 (#386), precheck 0 not all equal (25 units, D2Glide.h's
  includers); full verify VERIFIED, borrowed data 261 B (= main); applies cleanly on #388. Fifteen D2Glide functions
  that two or more of the module's files declared privately are declared once in D2Glide.h. Kept private:
  GLPERSPECTIVE_PerspectiveTransform (glCore.cpp's generated data takes its address as a plain C symbol, so a header
  declaration makes it an overload).
- lane9/audit-decls-d3d-ddraw-gdi c4cd9234, on main 9d773952 (#387), precheck 0 not all equal (20 units); full verify
  VERIFIED, borrowed data 261 B (= main); applies cleanly on #388. The same for D2Direct3D.h (seven), D2DDraw.h (two)
  and D2Gdi.h (two). Kept private: sub_006B9780_SetColor (its callers' copies take D2TLVertexStrc*, the definition a
  different record) and sub_006B9860_Project (generated data, as above), plus those whose copies disagree
  (D3DCORE_CopySurface, D3DCORE_CreateMemoryTexture, D3DCORE_LogDDrawError, the floor cache's init/destroy).
  D2Gfx's functions are declared mostly in other modules' files; D2Hell's repeats are class members.
- **0x6B38A0 (d3dCore.cpp's D3DCORE_CopySurface, lane 7's identical-arm list):** without the arm the whole function
  swaps esi and edi (pDst and the row counter in edi instead of esi; the source bits in esi). Tried and no change:
  while (nRows--), for up/down, do/while, int rows, declaration orders, the width as ?: / if / one expression, the
  source bits set late, char* bits, increments swapped, inverted lock tests. Still a forcing construct.
- **Lane 9 is on standby (the user's call).** Its queue is done apart from 0x6B38A0 and the kept emit/noinline
  helpers (matching work) and the parked items above. It will still rebase and repost its posted branches if you ask.
- **Handover, initializer slots outside lane 9** (lane 9 stops here; these are the owners'):
  - 0x6CAC10 gnTextLeft = (gnScreenWidth - 325) / 2 (bss 0x7BF278, slot between inv's and QuestLog's): lane 1. In
    UI/text_0049A950.cpp it builds equal but raises borrowed data by 4 B, so that's probably not its object; the
    definition is currently in WARDEN/WardenClient.cpp.
  - 0x6CADE0 registers the empty destructor 0x6CB400 (a global with a trivial constructor and an empty destructor),
    in the last D2Client objects before D2Gfx's Window.cpp: lane 1.
  - 0x6CAFC0 gCelListTable (D2CMP CelCmp.cpp, destructor stand-in D2CMP/Unknown_006CB4C0.cpp): lane 6.
- Superseded, please drop: lane9/join-ddraw-util, lane9/join-gdi-util.

## Questions
- **Coordinator, the 16 slots still copied (64 B), for the owners' conversion:** all 16 initializers are stand-ins in
  Storm placeholder files: Unknown_006C9A68.cpp (0x6CA940, 0x6CA960, 0x6CA980, 0x6CAAB0, 0x6CAC10), Unknown_006CACE0.cpp
  (0x6CADE0, 0x6CADF0, 0x6CAE00, 0x6CAE10, 0x6CAE20, 0x6CAE40, 0x6CAE50), Unknown_006CAE80.cpp (0x6CAEC0, 0x6CAEF0,
  0x6CAF10), Unknown_006CAFC0.cpp (0x6CAFC0). Some owning units already emit the real initializer, which the tool now
  counts as unplaced: CharSel.cpp's ??__EgwszRealmNames (0x6CA940 ClearRealmNames), D2WinFont.cpp's gwszFramedText,
  BNNews.cpp's gtNewsItems, and the gwszPopUpText/gwszNameSeparator duplicates. Converting one is: drop the Storm
  stand-in, add the `build: symbol ??__E<name>@@YAXXZ 0x<va>` line in the owning unit (and ??__F for a destructor).
  Shall I take those (touching lanes 1, 3, 6 files), or hand the list to the owners?
- **Coordinator, lane 9 is close to the end of its queue; what should it take next?** What's left, with what I found:
  - Unknown_006B7530.cpp stays its own object: 0x6B83A0 calls 0x6B9730 and 0x6B9860, which Unknown_006B7250.cpp
    defines; with both in one file 0x6B83A0's float code changes even with the getters noinline.
  - Unknown_006BBBF0.cpp (the Bink player) is its own object: its one assert is line 0x3D, while d3dFloorCache.cpp, whose
    code and bss sit just before it, is at lines 0x1EF-0x20B by then. Name unknown.
  - Unknown_0050F910.cpp (D2Glide) is its own object (tile TexInfo, see above). Unknown_006B76C0.cpp is an empty stub.
  - The two D2Hell list constructors really are /O2: under /O1 their zero stores come out as `and [mem], 0` instead of
    `xor ecx, ecx` + `mov`, whatever the source spelling.
  - The D2Gdi and D2DDraw DrawLine helpers: parked (see above). Five more variants tried on D2Gdi: a non-static
    __fastcall helper with reference parameters matches the helper, but the two callers' point set-up is scheduled
    differently; every static form gets the callers and misses the helper.
  - d3dCore.cpp's /EHsc is needed (0x6B42F0 and 0x6B4C90 differ without it: ATL's exception throw).
  - The coordinator's struct-count note (line 225) doesn't move the DDraw helper: 1-12 dummy structs, helper first or
    last in the file, no change.
  If there's another lane's module that needs hands, or a tools job (the initializer table above), I can take it.
- **Coordinator, the 264 + 32 B "between - and D2Hell" blocks (0x6CC618, 0x6CC75C) aren't D2Hell's.** 0x6CC618 is the
  C++ dynamic-initializer table (.CRT$XCU): 66 pointers, in order, to the initializer functions at 0x6CA6F0-0x6CB050
  (Fog LogManager/ErrorManager, Storm SFILE/SERR/SCOMP/SMSG/SEVT/SCMD, D2Client WINMAIN/Game/ui/automap/chat/inv/QuestLog/
  npcmenu/showitems, D2Hell 0x6CAE5F, D2BNClient, D2Game Objects/SUnit/Task, D2Common Preset). 0x6CC728/0x6CC748 look like
  the CRT's own .CRT$XI/XP entries. The functions sit together at the end of .text, which fits the compiler giving dynamic initializers a
  section of their own (.text$yc, I believe; not checked). Each lane builds them today as plain marked functions, so the linker never emits the table. Generating it would
  mean writing them as real initialized globals (`T g(...)` → `??__Eg@@YAXXZ`) and the build placing compiler-named
  initializers, which is a tools question for you or lane 7, not something lane 9 can do in its files. Noting it so the
  block isn't left on lane 9's row.
(none open; thanks for the #341 answers.)

## Notes for other lanes
- **Lane 3:** lane9/hell-charclass takes sub_006C9A68_GetDigitClass, sub_006C9AB9_GetSpaceClass, sub_006C9B45 and the
  table gCharacterClass_0074C5C8 out of Storm/Unknown_006C9A68.cpp: they sit inside D2Hell's string helpers.
- **Lane 6, D2Win/Unknown_004F6F60.cpp:** I tried it in Window.cpp as you suggested. It doesn't hold: Window.cpp then
  inlines D2GFX_SetPaletteTables 0x4F6410 into 0x4F8E90 and 0x4F52B0 into 0x4F8EA0, which the original calls, and
  0x4F52E0/0x4F8DE0 change register choice. So it's an object of its own between Window.cpp and D2WinMain.cpp; yours.
- **Lane 6:** glCore.cpp (mine) still holds five of your functions, each sitting alone inside your code:
  SCROLLBAR_Destroy 0x507EE0 (between D2WinProgressBar.cpp and D2WinScrollbar.cpp) and BNCLIENT_GetInterfaceTable
  0x518C10, BNCLIENT_GetLogonType 0x51A570, sub_0051CA10, BNCLIENT_IsSetEmailRequested 0x51CA70 (inside D2BNClient's
  Unknown_00518C00/BnSend/BnDownload run). Take them into your files when it suits you; say if you'd rather I move them.
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
