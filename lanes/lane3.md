# Lane 3

Written by lane 3 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane3/atl-data 689377cc 519->514 Replaces lane3/atl (same first commit, rebased) and adds the ATL object's .rdata: the 728 B at 0x6FAD20-0x6FAFF7 (statreg.h strings and CRegParser statics, atlbase.h AtlLimits, atlcomcli.h CVarTypeInfo, atliface.h GUIDs) defined in D2Direct3D/Unknown_006B1A00.cpp through 98 plan records, the GUIDs and CRegParser members as ATL's selectany definitions. Borrowed data 3,415 -> 2,687 B on its own (2,631 B on this base). VERIFIED 7a5eb650 on base dab5042f (#324; 14,918/14,918; borrowed code 12,041 B / 9 functions). Not stacked.

- lane3/suni 30f43254 519->518 Storm/Unknown_006C7000.cpp (Storm's Unicode module, 17 functions) is renamed Storm/SOURCE/SUNI.CPP, as approved; its data include follows. VERIFIED 8c45fafc on base 53ae59fd (j84; 14,918/14,918; borrowed code 12,041 B / 9 functions, data 3,415 B). Not stacked.

- lane3/ssig-window 4f8a5cd2 519->519 sub_0041D410_GetWindow (returns the signature stream's window size; between SSignatureVerifyStream_Begin and 0x41D420, inside SSignature.cpp's run, reads SSignature.cpp's stream record) moves from SFILE.CPP, its one caller, to SSignature.cpp. VERIFIED 7c7e5f21 on base 20f3e0fd (j82; 14,918/14,918; borrowed code 12,041 B / 9 functions, data 3,415 B). Not stacked.

- lane3/system-strays c1bd9dce 519->519 sub_004107B0_AtomicStore64 (between system.cpp's 0x4107A0 and 0x4107D0; only callers SYSTEM_InitTimeBase and FOG_GetSyncTime) moves from Fog/Unknown_00410790 to system.cpp, written __declspec(naked) like its neighbour Read64Locked (with a plain __asm body visible, both callers change). VERIFIED 31c9d75f on base 20f3e0fd (j82; 14,918/14,918; borrowed code 12,041 B / 9 functions, data 3,415 B). Not stacked.

## Questions

## Notes for other lanes

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
