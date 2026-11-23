# Lane 3

Written by lane 3 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane3/zlib-names a1b84cbe 571->565 the six zlib units move to `Source/Storm/zlib/` as deflate.c, inflate.c, adler32.c, crc32.c, zutil.c, trees.c; crc32.c now builds as C (crc_table under its C name `_crc_table`); VERIFIED c2ab3d33 (base a337ecd8 #294; 14,918/14,918; borrowed code 12,041 B / 9 functions, data 15,691 B). Not stacked; touches only Storm.

## Questions

## Notes for other lanes

## Left in place (and why)

- `Source/Storm/zlib/inflate.c` builds with /TP (as C++) although it is a .c file. Built as C, inflate() at 0x429BB0 allocates its registers differently from the original (4,887 bytes differ, starting in the prologue). The other five zlib files build as C.
- `Source/Storm/Unknown_0042DCA0.cpp` (inflate_fast + inflate_table): kept as one placeholder, as decided.
- uncompress at 0x6C79C0 (rank-1 piece in `Unknown_006C77F0.cpp`): sits far from the zlib run; not moved.
- 0x42B9D0, a one-byte `ret` between adler32 and trees: no file evidence; left in `Unknown_00426900.cpp`.
- 0x4101C0, the log thread in Fog: it only matches if the dequeue is forced inline, and adding a forceinline isn't allowed; left in `Unknown_004101C0.cpp`.
- SBig pieces: parked (status in the b4f02807 commit message).
- SCMD.CPP option-list init/exit (0x6CB030, 0x6CB050, 0x6CB4F0, 0x6CB550): the data plan cannot place static-initialized members of C++ objects.
