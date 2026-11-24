# Lane 3

Written by lane 3 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane3/scomp-flush-2 4367e2d1 453->453 (lane3/scomp-flush was pushed before its rebase; this one replaces it) SCOMP.CPP takes the nine small functions inside its run 0x41DEC0-0x41EED0 that were filed elsewhere: 0x41E8F0 and 0x41EE40 from SFILE.CPP; 0x41E900, 0x41E9E0, 0x41EB40, 0x41EB60 and the huff-node list's LinkNode 0x41ED90 from SSignature.cpp (LinkNode joins D2StormNodeListAStrc, whose NewItem 0x41EED0 calls it; SSignature's AddSymbol reaches it through its symbol line); 0x41E9C0 and 0x41EA20 (a forwarder to SCompDecompress) from Unknown_0041E9C0.cpp. The CBitOutput flush 0x41D9A0 moves from SFILE.CPP to Unknown_0041D880.cpp, whose bit-output run it sits in (lane 10's note). VERIFIED b1d04670 on base c2f64d25 (#340; 14,918/14,918; borrowed code 12,041 B / 9 functions, data 1,577 B), then rebased onto 0b750228 (#341; SFILE.CPP's conflict with sevt-join resolved) and prechecked. Not stacked. **Lane 10:** 0x41D9A0 is done with this.

## Claimed

(none)

## Questions

- **ErrorManager.cpp objects, for the coordinator (you asked which and whose):** (1) the mode object: ERRORMANAGER_RunModeInterface (0x4059D0) with its data, the language copy at 0x706518 and gaModeTable at 0x706554 (6 entries; the plan has 13). (2) the NT-service object: D2ServerServiceHandlerProc (0x406410) and ERRORMANAGER_StartServiceDispatcher (0x406650) from ErrorManager.cpp, sub_00406340_SelectModule (Storm/Unknown_00405710), sub_00406470_OpenServiceHandles (Storm/Unknown_00404F40) and D2ServerServiceMain (0x4065E0, D2Launch MainMenus.cpp), with the language copy at 0x706584 and 0x7065BC-0x706617 (gData_007065BC, gbD2ServerStopEvent, gszServiceName, gD2ServerServiceStatus). It sits next to WinMain (0x4066E0) and MAINMENUS_InitStorm (0x406870), both filed in MainMenus.cpp. Both are Game.exe's own main module (the launcher you said you would place), not Fog's error manager. (3) the error manager proper, from gaszLanguageNames (0x706618) on, stays ErrorManager.cpp.

## Notes for other lanes

- **Lane 9 (D2Gdi, D2Direct3D; this note was addressed to lane 6 before the ownership change):** Storm/SOURCE/SCMD.CPP still holds thirteen tiny functions that sit inside D2Gdi's run, 0x6C7A60-0x6C8A40, between gdiCore.cpp and the D2Gdi placeholders: 0x6C7A60 (returns 1), 0x6C7CC0/0x6C7CE0/0x6C8050/0x6C80F0/0x6C8100/0x6C8190 (return 0), 0x6C7CD0/0x6C8060 (stdcall one-argument no-ops), 0x6C88A0/0x6C8A40 (two-argument no-ops), 0x6C8020 and 0x6C8240 (return gdwGlobal_0098A164 and gdwGlobal_007C914C). They look like the GDI renderer's stub callbacks, so they're yours: take them into the D2Gdi files around them when you get there. I've left them. Likewise Fog/Src/QServer/QServer.cpp holds five such stubs inside D2Direct3D's run: 0x6B1C00 and 0x6B2F20 (return gdwGlobal_00970E50 / gdwGlobal_00970E8C), 0x6B20A0, 0x6B20B0 and 0x6B76C0 (a two-argument no-op). None is called by address from code.

- **Lane 7 (0x6BD230, Fog export 10215, handed over):** my attempt is in "Left in place" below. Built inside Excel.cpp, between FOG_GetStringFromLinkIndex (0x6BD180) and EXCEL_FindLinkNode (0x6BD330), on Excel.cpp's own D2TxtLinkStrc (count, capacity at +4, entries, pFirstNode at +0xC; entry = 4-byte code + index), with `FOG_ReallocServerMemory` (0x40B4B0) and the literal ".\\Src\\Excel\\Excel.cpp" (it lands on 0x6FC448), every byte matches except the original's `push ecx` after the frame setup: an unused 4-byte slot at [ebp-4], which also makes the epilogue `mov esp, ebp`. Variants that did not bring the slot back: the stand-in's goto loop, a flag loop, a break loop, an inline binary-search helper with an out-parameter (worse), three ways of writing the tail. Note the `mov edi, edi` before the outer loop: the loop head is aligned.

- **Lane 6 (D2Launch), with a data fix that touches lane 3's files:** 0x42E590 (`sub_0042E590_SetOwner`, which stores the owner and returns the interface table) and 0x42E5A0 (its no-op partner) are filed in Storm/Unknown_00426900.cpp, but they are the pfnCreate/pfnRelease pair that ErrorManager's gaModeTable lists for the front-end mode, and the table they return holds `sub_004359D0_RunFrontEnd`. Their data is the language-table copy at 0x708930 followed by that one-entry table at 0x70896C, and the next copy, 0x708970, starts MainMenus.cpp's data. So they look like D2Launch's own small entry object, the first D2Launch object in link order. Two plan records are off: trees.c holds the 0x708930 copy (gData_00708930), and Unknown_00426900's gaTable_0070896C is 64 B, swallowing the 0x708970 copy, where it should be 4 B. I can fix both records (my files) once you say where the object should live; I won't create it in D2Launch myself.
- **Lane 5:** Storm/Unknown_006CAE80.cpp's gData_00731ED4 is the language copy at 0x731ED4; the next data is your Items.cpp copy at 0x731F10, so 0x731ED4 starts an object with no initialised data of its own, the one just before Items.cpp in link order. I can't tell which D2Game file that is from the data alone; if you know, I'll move the record there (plan only), or move it yourself.

- **Lane 6:** lane3/atl creates D2Direct3D/Unknown_006B1A00.cpp, the ATL object in front of d3dCore.cpp (0x6B1A00-0x6B1BC0; the coordinator's ATL lead). It is probably the start of d3dCore.cpp itself (d3dCore including atlbase.h); joining it is yours to decide once d3dCore's headers allow it.

- **Lane 4:** `AUTOMAP_PowInt` (0x414220, D2Client/UI/automap.cpp) sits inside Storm's SSTR.CPP run, next to 0x414260, which is a StormPowInt<double> wrapper. It looks like one more StormPowInt instantiation rather than an automap function. I've left it alone.

- **Lane 4:** borrowed-data.md lists 0x700140-0x7001C0 (in my "between Fog/Unknown_00401010.cpp and Storm/Unknown_00404F40.cpp" block) as mine, but it is WardenClient's RTTI: the complete object locator, class hierarchy and base class descriptors of `.?AUWardenClient@@` (type descriptor 0x721CC0, which WardenClient.cpp already maps). It belongs with WardenClient.cpp's `??_R0` line.

- **Lanes 5, 6 (and whoever owns D2BNClient):** the dynamic initializers and atexit destructors of long-lived critical sections can go into the file that owns the lock; `lane3/crt-locks` shows the pattern (a `CCritSect : D2CriticalSectionStrc` type plus `// build: symbol ??__E<name>@@YAXXZ` / `??__F<name>@@YAXXZ` lines on the definition). These are still in Storm placeholders but aren't Storm's:
  - 0x6CAE80 / 0x6CB420: lock 0x881860 (BnDownload.cpp uses it)
  - 0x6CAEA0 / 0x6CB440: lock 0x881894 (CACHE.CPP)
  - 0x6CAED0 / 0x6CB470: lock 0x881F64 (BnDownload.cpp)
  - 0x6CAF70 / 0x6CB490: lock 0x88CAA8 (D2Game Task.cpp)
  - 0x6CB010 / 0x6CB4E0: lock 0x96D610 (D2Common Preset.cpp)
  - 0x6CAF90 / 0x6CB4A0: an array of 32 locks at 0x88C7A8, built with the CRT array constructor
- **Lanes 1 and 4:** most of `Storm/Unknown_006C9A68.cpp`, `Unknown_006CACE0.cpp`, `Unknown_006CAA30.cpp` and `Unknown_006CAE80.cpp` are D2Client's dynamic initializers (text buffers, layout rects, hashes of "Header"/"Game Time", captions). They belong with the globals they set, in your files.

## Left in place (and why)

- SEVT.CPP's break-command list as stpl.h's TSList<BREAKCMD> (tried after sevt-join-3): with BREAKCMD : TSLinkedNode<BREAKCMD> and the list's code mapped by `// build: symbol` lines like SMSG/SERR, every function matches (SEvtBreakHandlerChain becomes `NewNode(2, 0, 0)`) except SEvtDispatch (0x426F90). Two findings: the original calls the list's RawNext (0x426C80) out of line, so Storm's TSList::RawNext was not an in-class inline (moving it out of the class in stpl.h fixes that call and keeps SCMD/SERR/SMSG equal); and at the top of its first loop the original keeps the queue head's masked value (setle/sub/and, then test) where our build folds the test into a branch, whatever form of Head/Next or DeleteNode the loop uses. Parked, SEVT keeps its own list type.

- 0x6BD230 (borrowed, Fog export 10215, the link-table key insert): tried inside Excel.cpp, between FOG_GetStringFromLinkIndex and EXCEL_FindLinkNode, on Excel.cpp's own D2TxtLinkStrc. Every variant tried (the stand-in's loop, a flag loop, a break loop, an inline search helper with an out-parameter, three ways of writing the tail) builds without the original's `push ecx`, the unused 4-byte slot at [ebp-4]; the rest of the body matches. Parked; the next things to try are a register-parameter static that the export wraps, and Excel.cpp's /Ob setting.

- **Fog/Src/ErrorManager.cpp is three objects (parked).** Its .data holds language-table copies at 0x706518 (record moved there by lane3/lang-00404f40), 0x706584 and 0x706618, and each starts an object: (1) gaModeTable, read by ERRORMANAGER_RunModeInterface (0x4059D0); (2) 0x7065BC-0x706617, the NT-service data, read by D2ServerServiceHandlerProc, ERRORMANAGER_StartServiceDispatcher, D2ServerServiceMain (MainMenus.cpp), sub_00406470_OpenServiceHandles and sub_00406340_SelectModule (Storm launcher pieces), all at 0x406340-0x406650, next to WinMain; (3) the error manager proper, from gaszLanguageNames on. gaModeTable is also modelled too long: 13 entries run over the 0x706584 copy, so the real table has 6 entries (0x30 B). (1) and (2) are Game.exe's own main module, which the user is placing, so I am not splitting ErrorManager.cpp. The 0x40E850 finding (the CPU helpers are not in the same unit as MeasureCpuMHz's callee) points the same way.

- 0x40E850 (AUTOMAP_ReadTimeStampCounter, rdtsc): tried in ErrorManager.cpp as approved, and it doesn't fit there. ErrorManager.cpp builds /Ob2, so with the body in the unit the compiler inlines it into ERRORMANAGER_MeasureCpuMHz (0x40E870), wherever the definition sits; the original calls it. So in the original the reader wasn't visible to MeasureCpuMHz: either the CPU helpers 0x40E250-0x40EA00 are a separate object from the rest of ErrorManager.cpp, or the reader lived in another unit. It stays in automap.cpp (lane 4's) until that is settled; no forcing constructs.

- 0x6CD5FC "unknown" (Exceptions.cpp, 8 B): written as a literal, it isn't placed ("duplicate_definition": another object's identical `??_C@_07CIFAGBMG@unknown?$AA@` wins). It stays a name mapped to the address.
- 0x6CCBE8 "Unknown" (ErrorManager.cpp) is already a literal, but stays copied for the same reason.
- The SFILE.CPP pieces (SFILE_004177D0 ... SFILE_00418F20, 22 functions): a trial merge needs one list type per list. 0x418470, 0x418640, 0x4186B0, 0x418CA0 and 0x418D80 are all written as `D2ChatStormListCStrc::D2ChatStormListCStrc()`, which one unit can define only once. They are really TSList<T> constructors for different T, so the merge waits for those types.

- The TSList globals' initializers and destructors (InitializeList 0x6CA7B0-0x6CA900, DestroyList 0x6CB0C0-0x6CB380, plus the SCMD.CPP ones): the compiler initializes part of each list statically (link offset 0 and a prevlink that points at itself, in .data) and only writes `m_next = ~&terminator` at run time. The data plan can't place a C++ object that has both static and dynamic parts, so they stay put.
- `Source/Storm/zlib/inflate.c` builds with /TP (as C++) although it is a .c file. Built as C, inflate() at 0x429BB0 allocates its registers differently from the original (4,887 bytes differ, starting in the prologue). The other five zlib files build as C.
- `Source/Storm/Unknown_0042DCA0.cpp` (inflate_fast + inflate_table): kept as one placeholder, as decided.
- uncompress at 0x6C79C0 (rank-1 piece in `Unknown_006C77F0.cpp`): sits far from the zlib run; not moved.
- 0x42B9D0, a one-byte `ret` between adler32 and trees: no file evidence; left in `Unknown_00426900.cpp`.
- 0x4101C0, the log thread in Fog: it only matches if the dequeue is forced inline, and adding a forceinline isn't allowed; left in `Unknown_004101C0.cpp`.
- SBig pieces still outside SBig.cpp: Shl, SubUInt, Sub, ToStr, Div, Gcd, PowMod, IsPrime and InvMod compile in SBig.cpp only as context; their own bodies differ there (several rank-1 copies need /GS-), so their pieces stay. The array-method pieces (Unknown_00421110, 004211C0, 004212F0, 00421EA0) are next.
- 0x6BE190 (gamma table, asserts at lines 14-16) sits inside Excel.cpp's run, but its asserts say it comes from a short file of its own; left as a placeholder.
