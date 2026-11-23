# Lane 3

Written by lane 3 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane3/crt-init bea40fd5 571->570 two more dynamic initializers go to their own files: STORM.CPP gets 0x6CA890, a static startup object whose inline constructor calls InitStorm (Unknown_006CA890 goes away); ErrorManager.cpp defines `gdwMainThreadId = GetCurrentThreadId()` at 0x992B1C with its initializer 0x6CA6F0. VERIFIED 689e9e33 on base 5a5617e0 (j61; 14,918/14,918; borrowed code 12,041 B / 9 functions, data 15,691 B), then rebased onto 71db0201 (j62) without conflicts (docs only) and prechecked. Not stacked.
- lane3/crt-locks 3ffb533d 571->571 the six long-lived critical sections become `CCritSect` objects (InitializeCriticalSection in the constructor, DeleteCriticalSection in the destructor) in their own files, with their dynamic initializer and atexit destructor: LogManager.cpp gtLogQueueLock/gtLogLock, SFILE.CPP gBasePathLock/gStormExplodeLock, SCOMP.CPP gtWorkBufferLock, SEVT.CPP gtSEvtLock; 12 functions leave Unknown_006C9A68/Unknown_006CAE80. VERIFIED 5fa1e275 on base 34ce356b (j60; same totals), then rebased onto 5a5617e0 (j61) without conflicts and prechecked. Not stacked; crt-init touches different lines of Unknown_006C9A68 and units.json.

## Questions

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

## In progress

- `_dist_code`/`_length_code` (0x6D13D8, 768 B) defined in trees.c from trees.h: the unit builds equal; full verify running.
