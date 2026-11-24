# Lane 3

Written by lane 3 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane3/cpu-report c96bd8c8 562->561 0x40E300 (processor name) and 0x40EA00 (processor lines of the crash log) join ErrorManager.cpp: they sit between its CPUID helpers (0x40E250, 0x40E870-0x40E9E0) and call only those; gtSystemInfo (0x74D8A0) and the vendor-name table come with them. ERRORMANAGER_MeasureCpuMHz and WriteProcessorReport are __stdcall (their callers pop the previous call's arguments before calling them). Unknown_0040EA00 goes away. VERIFIED 98b37a92 on base e5714a07 (j65; 14,918/14,918; borrowed code 12,041 B / 9 functions, data 14,443 B), then rebased onto a620102a (j67) without conflicts and prechecked. Not stacked.
- lane3/data-fixes 8fd0d4d8 562->562 QServer.cpp gaMaskTable is 33 entries (132 B), not 35: the 140-byte record overlapped SCMD.CPP's CMDDEF type descriptor at 0x74C474, so the table was taken from the image; now placed. deflate.c defines deflate_copyright (0x6D0238); Unknown_0042DCA0 (inftrees) defines inflate_copyright (0x6D3878); SSignature.cpp's gszSEvtCpp record (0x6D0224) shrinks 88 -> 20 B (its tail was deflate_copyright). Borrowed data -182 B: 15,691 -> 15,509 B on its verified base. VERIFIED c5b699f9 on base ecc95640 (j63; 14,918/14,918; borrowed code 12,041 B / 9 functions), then rebased onto e5714a07 (j65, which has trees-data) without conflicts and prechecked; with trees-data the total should be 14,741 B. Not stacked.

## Questions

- `AUTOMAP_ReadTimeStampCounter` at 0x40E850 is filed in D2Client/UI/automap.cpp (lane 4), but it sits in Fog's ErrorManager.cpp run, between the CPUID helpers at 0x40E250 and 0x40E870, and its only callers are 0x40E8AD and 0x40E8FE in ERRORMANAGER_MeasureCpuMHz. May I move it into ErrorManager.cpp (and rename it ERRORMANAGER_ReadTimeStampCounter)?

## Notes for other lanes

- **Lanes 5, 6 (and whoever owns D2BNClient):** the dynamic initializers and atexit destructors of long-lived critical sections can go into the file that owns the lock; `lane3/crt-locks` shows the pattern (a `CCritSect : D2CriticalSectionStrc` type plus `// build: symbol ??__E<name>@@YAXXZ` / `??__F<name>@@YAXXZ` lines on the definition). These are still in Storm placeholders but aren't Storm's:
  - 0x6CAE80 / 0x6CB420: lock 0x881860 (BnDownload.cpp uses it)
  - 0x6CAEA0 / 0x6CB440: lock 0x881894 (CACHE.CPP)
  - 0x6CAED0 / 0x6CB470: lock 0x881F64 (BnDownload.cpp)
  - 0x6CAF70 / 0x6CB490: lock 0x88CAA8 (D2Game Task.cpp)
  - 0x6CB010 / 0x6CB4E0: lock 0x96D610 (D2Common Preset.cpp)
  - 0x6CAF90 / 0x6CB4A0: an array of 32 locks at 0x88C7A8, built with the CRT array constructor
- **Lanes 1 and 4:** most of `Storm/Unknown_006C9A68.cpp`, `Unknown_006CACE0.cpp`, `Unknown_006CAA30.cpp` and `Unknown_006CAE80.cpp` are D2Client's dynamic initializers (text buffers, layout rects, hashes of "Header"/"Game Time", captions). They belong with the globals they set, in your files.

## Left in place (and why)

- The TSList globals' initializers and destructors (InitializeList 0x6CA7B0-0x6CA900, DestroyList 0x6CB0C0-0x6CB380, plus the SCMD.CPP ones): the compiler initializes part of each list statically (link offset 0 and a prevlink that points at itself, in .data) and only writes `m_next = ~&terminator` at run time. The data plan can't place a C++ object that has both static and dynamic parts, so they stay put.
- `Source/Storm/zlib/inflate.c` builds with /TP (as C++) although it is a .c file. Built as C, inflate() at 0x429BB0 allocates its registers differently from the original (4,887 bytes differ, starting in the prologue). The other five zlib files build as C.
- `Source/Storm/Unknown_0042DCA0.cpp` (inflate_fast + inflate_table): kept as one placeholder, as decided.
- uncompress at 0x6C79C0 (rank-1 piece in `Unknown_006C77F0.cpp`): sits far from the zlib run; not moved.
- 0x42B9D0, a one-byte `ret` between adler32 and trees: no file evidence; left in `Unknown_00426900.cpp`.
- 0x4101C0, the log thread in Fog: it only matches if the dequeue is forced inline, and adding a forceinline isn't allowed; left in `Unknown_004101C0.cpp`.
- SBig pieces: parked (status in the b4f02807 commit message).
- 0x6BE190 (gamma table, asserts at lines 14-16) sits inside Excel.cpp's run, but its asserts say it comes from a short file of its own; left as a placeholder.
