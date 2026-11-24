# Lane 3

Written by lane 3 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane3/sevt-deletenode 8b7d9fb4 519->518 D2StormBreakCmdListStrc::sub_00426F20_DeleteNode (0x426F20, inside SEVT.CPP's run between SEvtBreakHandlerChain and SEvtDispatch; SEvtDispatch calls it; frees with SEVT.CPP's BREAKCMD type name) moves from Unknown_00426F20.cpp to SEVT.CPP, which already declared it. The piece had nothing else of its own and is removed. VERIFIED 68f5bf63 on base 20f3e0fd (j82; 14,918/14,918; borrowed code 12,041 B / 9 functions, data 3,415 B). Not stacked.

- lane3/sfile-destroy 72495592 519->519 SFileDestroy (0x41A110, Storm name, inside SFILE.CPP's run) moves from SFILE_004177E0 to SFILE.CPP. The piece also defined five SFILE.CPP globals (gpCryptTable, gbThreadStop, ghStormEvent, gpStreamBuffer, gpStormExplodeWork; SFILE.CPP had them extern) plus duplicate copies of two SFILE.CPP statics; SFILE.CPP now defines the five and the piece drops all seven. Edits Storm/D2SFileTypes.h (D2StormFixedListStrc gets Head()). VERIFIED 557e0354 on base 39564cf8 (j81; 14,918/14,918; borrowed code 12,041 B / 9 functions, data 3,415 B). Not stacked.

- lane3/scomp-strays 06856e95 519->519 PkwareBufferRead and PkwareBufferWrite (0x41DEC0, 0x41DF00, Storm names) move from SSignature.cpp to SCOMP.CPP: they sit right before PkwareCompress at the start of SCOMP.CPP's run, and SCOMP.CPP's PkwareCompress/PkwareDecompress are their only users. VERIFIED 10ecfa6f on base 39564cf8 (j81; 14,918/14,918; borrowed code 12,041 B / 9 functions, data 3,415 B). Not stacked.

## Questions

- `Storm/Unknown_006C7000.cpp` (17 functions, 0x6C7030-0x6C79A0, right after SBMP.CPP) is Storm's Unicode module: SUniConvertUTF8to16(Len), SUniSGetUTF8, SUniSPutUTF8, SUniFindUTF8ChrStart, SUniFindAfterUTF8Chr and the code-page converters. names.csv has `blizzard` names for most of them. The image has no ".\SOURCE\SUNI.CPP" string (SUNI.CPP has no assert), so the file name would come from the SUni prefix alone, the same way SMEM/SREG/SSTR are named. May I rename it `Storm/SOURCE/SUNI.CPP`?

- `AUTOMAP_ReadTimeStampCounter` at 0x40E850 is filed in D2Client/UI/automap.cpp (lane 4), but it sits in Fog's ErrorManager.cpp run, between the CPUID helpers at 0x40E250 and 0x40E870, and its only callers are 0x40E8AD and 0x40E8FE in ERRORMANAGER_MeasureCpuMHz. May I move it into ErrorManager.cpp (and rename it ERRORMANAGER_ReadTimeStampCounter)?

## Notes for other lanes

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
