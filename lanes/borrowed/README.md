# The 8 borrowed functions: compiler readings (coordinator, 2026-11-25 on main #384)

Owners from 2026-11-25 10:30 PT: lane 2 has 0x62B5B0, 0x679C80, 0x677880; lane 3 has 0x6BD230; lane 5 has 0x5DD7F0, 0x55A6D0; 0x4A4AD0 (#400), 0x4F8B80 (#409) and 0x5DD7F0 (#410) are done.

Each folder holds: `candidate.cpp`, the best known draft, as built here; `score.json`, our length and the
original's, and the number of differing bytes after relocations are masked; `idiff.txt`, original and ours side by
side around each difference; and `prio.txt`, the register allocator's own reading of our compile (`tools/c2diag`,
see tools/c2diag/IBLIS.md). Each draft was put into its unit on main #384 and built there.

| Function | Size | Unit | Draft from | Ours / orig | Differing bytes | First difference |
|---|---:|---|---|---:|---:|---|
| 0x6BD230 | 246 B | Fog/Src/Excel/Excel.cpp | waiting for lane 7's current source | | | one unused 4-byte frame slot (board notes) |
| 0x679C80 | 450 B | D2Common/Unknown_00679380.cpp | lanes/vsearch/00679C80-near.cpp | 447 / 450 | 253 | +0x91: ours copies the point through eax before storing it; the original stores edi directly |
| 0x62B5B0 | 1,192 B | D2Common/ITEMS/Items.cpp | lane8/0062B5B0-wip | **1,192 / 1,192** | 355 | +0x30: the original zeroes **esi**, ours edi; the whole function's esi/edi choice follows from that variable |
| 0x4A4AD0 | 1,232 B | D2Client/Unknown_004A43E0.cpp | lane7/004A4AD0 | **from source, #400** | 0 | done: TEXT_ScrollKeyConfigList's prev/next written as plain `if`s gave nMax and gnKeyConfigFirstVisible the uses the original's allocation needs |
| 0x4F8B80 | 561 B | D2Gfx/SRC/Window.cpp | lane6/004F8B80 | **from source, #409** | 0 | done: CMNSUBTILE_DrawFloorTile, on the tile library's own records and a 12-byte light cell |
| 0x5DD7F0 | 1,084 B | D2Game/Ai/AiUtil.cpp | lane5/005DD7F0 | **from source, #410** | 0 | done: the 0x40 flag read into a local, the collision choice one if/else chain on it, the flag cleared after the chain; AIUTIL_CheckAiControlFlag's if and two returns |
| 0x55A6D0 | 2,253 B | D2Game/ITEMS/Items.cpp | lane7/0055A6D0-wip | 2,239 / 2,253 | 2,015 | +0x17: the original keeps the 0x1C parameter in esi and the fastcall edx argument in ebx; ours swaps them |
| 0x677880 | 4,232 B | D2Common/DRLG/OutPlace.cpp | waiting for lane 7's current source | | | the seed form fixed the first difference (lane 7, 21:40) |

The drafts are older than #384, so some were adapted to build here: old `sub_` names became today's names by
address, and helpers, structs and macros the draft's branch had were carried over. Those adaptations change no
logic, but the numbers are for these versions on #384, not the branches' own.

How to use a reading: tools/c2diag/IBLIS.md, "How to use it on a register difference".
