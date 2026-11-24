# Lane 3

Written by lane 3 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane3/fog-log-strays-2 c00e5335 519->519 Two LogManager.cpp-run functions filed in Exceptions.cpp move to LogManager.cpp: 0x410540 (log system start-up, renamed LOGMANAGER_InitLogSystem from the inferred EXCEPTIONS_ name; counterpart of sub_0040FFD0_ShutdownLogSystem) and 0x40FD00 (the log list's UnlinkAll, inline like SFILE's). LogManager.cpp also takes the definitions of ganLogNewFile, gbLogInitialized, gaszLogFilePaths and gnLogThreadId (their .bss neighbours are LogManager's). VERIFIED 97903cb1 on base cbd4f9ec (j88), then rebased onto 4bf262f6 (j90) and prechecked ( 14,918/14,918; borrowed code 12,041 B / 9 functions, data 2,507 B). Not stacked.

## Claimed

- **SFILE.CPP list types onto stpl.h's TSList<T> (big job, started).** Goal: SFILE.CPP's lists (requests, files, archives, streams, events and the ignore-list chat lists) as TSList<T> for their own T, so the five TSList constructors at 0x418470/0x418640/0x4186B0/0x418CA0/0x418D80 and the other SFILE_0041xxxx pieces can join SFILE.CPP. Touches Storm/D2SFileTypes.h (mine) and the SFILE pieces only.

## Questions

## Notes for other lanes

- **Lane 6 (D2Launch), with a data fix that touches lane 3's files:** 0x42E590 (`sub_0042E590_SetOwner`, which stores the owner and returns the interface table) and 0x42E5A0 (its no-op partner) are filed in Storm/Unknown_00426900.cpp, but they are the pfnCreate/pfnRelease pair that ErrorManager's gaModeTable lists for the front-end mode, and the table they return holds `sub_004359D0_RunFrontEnd`. Their data is the language-table copy at 0x708930 followed by that one-entry table at 0x70896C, and the next copy, 0x708970, starts MainMenus.cpp's data. So they look like D2Launch's own small entry object, the first D2Launch object in link order. Two plan records are off: trees.c holds the 0x708930 copy (gData_00708930), and Unknown_00426900's gaTable_0070896C is 64 B, swallowing the 0x708970 copy, where it should be 4 B. I can fix both records (my files) once you say where the object should live; I won't create it in D2Launch myself.
- **Lanes 1 and 5:** Storm/Unknown_006C9A68.cpp's gData_007121E0 is the language-table copy that starts D2Client/UNIT/CUnit.cpp's data (lane 1), and Storm/Unknown_006CAE80.cpp's gData_00731ED4 holds the two copies 0x731ED4/0x731F10 that start D2Game/ITEMS/Items.cpp's data (lane 5). Those records can move to your files (as #326 did for others); tell me if you'd rather I move them.

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
