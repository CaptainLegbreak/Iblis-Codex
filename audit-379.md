# Source audit on #379: does the tree read like Blizzard's own source?

Done by the coordinator on 2026-11-24, on main #379, by scanning every file under Source/ (621 .cpp/.c, 183 .h) and reading samples of each finding. Every count is a scan of #379's tree. The question: if Blizzard North's 1.14d source tree were next to ours, what in ours could not be in theirs?

**Short answer:** the code is plausible at function level. It has 14,919 functions built from source, Hungarian names in D2MOO's style, files named after the game's own diagnostics, almost no decompiler pointer casts (5) and cleanup-style `goto`s. What gives it away is mostly around the code, not in it:
- names that carry addresses;
- callees declared privately in every file instead of in module headers;
- helper bodies that exist only to steer the compiler;
- a forcing-construct count that misses some cases.

## 1. Constructs the original did not have (they change what the source says)

| Finding | Count on #379 | Owner |
|---|---:|---|
| Functions STATUS.md lists as forcing constructs (`volatile`, `__assume`, `#pragma optimize`) | 33 | lane 7 (D2Common's: lane 8) |
| **Missed by STATUS.md:** `#pragma optimize("", off)` around 0x477170 (D2Client/GAME/PalShift.cpp). status.py only looks inside a function's body, and the pragma sits above the address marker | 1+ | lane 7; coordinator fixes status.py |
| **Missed by STATUS.md:** `if`/`else` statements whose two arms are identical, a steering trick. ItemMods.cpp 0x65F470 says so in a comment ("not original source: the identical arms only shape register use") | 21 sites | lane 7 checks each; owners help |
| `__declspec(noinline)` | 107 uses in 67 files | owners: each needs the #368 ruling's evidence (a register-convention static and its callers in one object), noted in a comment. Remove the rest |
| Emit helpers (`sub_*_Emit*`): bodies that exist only to make the compiler emit a static as the original did | about 470 identifiers in 159 files (D2Client 171 uses, D2Common 53, D2Game 53, Fog 28) | owners, after joins (lane 5's emit-helpers-2 showed the method) |
| Calling-convention shims | 45 | lane 2 trim, then owners' joins |
| Context copies (`// build: context`) | 3 (Fog) | lane 3 |
| `#define nullptr 0` (D2Game.h:763), used in Quests/a5q2.cpp. VC8 has no nullptr, and Blizzard's code used NULL or 0 | 1 define, 8 uses | lane 5 |
| C99 type names typedef'd in Fog.h (`int32_t`, `uint8_t`), used in Fog/Unknown_006C0B80.cpp | 2 typedefs, 12 uses | lane 3 |
| Decompiler labels (`LABEL_20`, `LABEL_22`, `LABEL_FAIL`) | 10 in 3 files (D2Common Unknown_00679380.cpp, Unknown_0067B9C0.cpp; D2Direct3D Unknown_006BBBF0.cpp) | lanes 8, 9: name the label after what it does |

The identical-arm sites found (each has the same statement or block in both arms of an `if`/`else`). A few may be the original's own redundancy (the keep-alive tick in Game.cpp and Game_0044D080.cpp, for example). Each needs a look:
  - `D2Direct3D/Src/d3dCore.cpp:1731`
  - `D2Common/DATATBLS/LvlTbls.cpp:899`
  - `D2Common/DATATBLS/DataTbls_00613F80.cpp:549`
  - `D2Common/ITEMS/Items.cpp:7454`
  - `D2Common/ITEMS/Items.cpp:7506`
  - `Storm/SOURCE/SBig_00424700.cpp:359`
  - `Storm/SOURCE/SBig_00424700.cpp:381`
  - `Storm/SOURCE/SBig_00424700.cpp:383`
  - `D2Win/Src/D2WinFont.cpp:900`
  - `D2Game/Unknown_005B24E0.cpp:1144`
  - `D2Game/Unknown_005B24E0.cpp:1148`
  - `D2Game/Unknown_005B24E0.cpp:1182`
  - `D2Game/PLAYER/PlrModes.cpp:1567`
  - `D2Game/PLAYER/PlrModes.cpp:1616`
  - `D2Game/OBJECTS/ObjMode.cpp:2726`
  - `D2Game/Ai/AiThink4.cpp:3137`
  - `D2Game/Ai/AiThink4.cpp:3172`
  - `D2Game/Ai/AiUtil.cpp:1614`
  - `D2Client/GAME/Game_0044D080.cpp:1240`
  - `D2Client/GAME/Game.cpp:2485`
  - `Fog/Src/Excel/Excel.cpp:405`

Not counted against us: inline assembly is the kind the original very likely had: `bsr` in both SCmd.cpp and Fog, `rdtsc` in automap.cpp, `cpuid` in ErrorManager.cpp, `lock cmpxchg8b` 64-bit atomics in Fog's system.cpp (VC8 has no intrinsic for them), and hand-written copy and compare loops in D2Hell. `__forceinline` (210 uses) is ordinary in 2000s game code where the original inlined.

## 2. Names (bytes don't depend on them; this is the cheapest gain)

| Finding | Count on #379 | Owner |
|---|---:|---|
| Placeholder function names `sub_<VA>` (names.csv `placeholder`) | 2,148 functions | lane 10 |
| Old `sub_` spellings still in the source for functions that already have names (call sites and private prototypes) | about 1,070 identifiers (3,219 distinct `sub_` names in Source/ against 2,148 placeholders) | lane 10's call-site sweep |
| **Names carrying a 1.10 DLL address** (`D2COMMON_STATES_GetStatFlags_6FDB8A90`, `D2GAME_PACKETS_SendPacket0xA3_6FC3D730`): community names with the old version's address glued on, which no Blizzard source has | 351 functions in names.csv; 429 identifiers in Source/ (D2Game 107 files) | lane 10: drop the `_6Fxxxxxx` suffix, keep the rest of the name |
| Globals with an address in the name (`gnGlobal_007A285C`, `gData_00731018`, `gwszX_00711234`) | 1,434 distinct | lane 10's globals plans |
| Decompiler parameter names `a1`…`a10`, `v12` | about 3,000 uses in 229 files (D2Game SCmd.cpp 284, Game.cpp 135, D2Common ItemMods.cpp 133, PlrMsg.cpp 101) | owners; lane 10 can plan them from D2MOO |
| `f_<hex>` fields | 1,182 uses in 141 files | lane 10 plans (`fields-<header>.tsv`), lane 2 applies |
| `unk0x` fields | 2,537 uses (Include 770: D2QuestData.h 150, D2Packets.h 85) | same |
| `T<address>` struct names | 27 uses in 5 files (Path.cpp 13, Drlg.cpp 6) | lanes 8, 5, 1 |
| Decompiler types (`U32`, `_DWORD`, `LOBYTE`, `__int32`) | 250 uses in 25 files (Path.cpp 29, ItemMode.cpp 28, Particle.cpp 22) | owners |

## 3. Structure (where the tree differs from a real tree's shape)

| Finding | Count on #379 | Owner |
|---|---:|---|
| Placeholder files `Unknown_<VA>.cpp` | 229 | all lanes (queues.md) |
| Original files still in pieces (`<File>_<VA>.cpp` beside `<File>.cpp`) | 86 pieces of 33 files | owners |
| **Private prototypes.** Blizzard declared a module's functions in its headers; our .cpp files declare their callees themselves with an address marker | 29,317 declarations in .cpp files, for 8,244 functions; **3,911 functions are declared in two or more files**, 0x408A60 in 325 of them | the largest structural gap; see the note below |
| Private struct/union definitions in .cpp files | 2,507 (D2Client 801, D2Game 432, D2Common 398, D2CMP 204) | lane 2 (records), owners |
| Per-file compiler options other than the module default | 638 (Storm and Fog 487) | lowest priority: many are probably the original's own |
| Link-time code generation units | 14 (lane 3) | lane 3 |
| Stand-ins for functions not yet built from source | 8 files in Source/StandIns/ | lane 7, lane 1 |

**On the private prototypes:** this is what most separates our tree from a real one. It is also the riskiest change, because some functions change register allocation with the number of declarations in their unit (0x4CA560 in UnitSnd.cpp, inv_0048BC10, inv_0048DD90, Item.cpp's 0x4C3760). The way to do it is per module, by the owner: move each module's functions' declarations into the module header (D2Client.h, D2Game.h, D2Common.h, Fog.h, ...), include it, delete the private copies, and build every unit. Where a unit flips, keep its private declarations and say so. Start with the most-declared callees (the Fog and D2Common exports declared in hundreds of files): each removes the most lines for one header change.

## 4. Tool metadata (kept by design, not counted against us)

- `// 0x<VA>` above 14,215 definitions and after 42,051 declarations, and 2,417 `// build:` lines. The build needs them, and they read as annotations, not code.
- 349 `#include "gen/data/..."` lines. They keep the game's data out of the repo, and are the one place where the tree must differ from the original.
- About 95 comments explain a non-original construct ("the original keeps ... in a register"). They are right to be there while the construct is, and go with it.

## 5. What to do, in order

1. **Make the count honest** (coordinator): status.py also counts a `#pragma optimize` that wraps a function, and identical-arm `if`/`else` statements, as forcing constructs. The forcing-construct figure will rise; that's the true figure.
2. **Names** (lane 10, no byte risk): the 351 `_6Fxxxxxx` suffixes, then placeholders, the stale `sub_` spellings, globals, `a1`/`v12` parameters, and fields.
3. **Small anachronisms** (lanes 3, 5, 8, 9): `nullptr`, Fog.h's C99 types, `LABEL_` labels, `T<address>` structs, decompiler types.
4. **Forcing constructs** (lane 7 with owners): the 33, plus the pragma and the 21 identical-arm sites, plus a review of the 107 `noinline`s.
5. **Structure** (owners, ongoing): placeholders and split files from queues.md; private prototypes into module headers, one module at a time; emit helpers removed as joins make them unneeded.
