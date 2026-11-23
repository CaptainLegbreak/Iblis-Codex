# Coordinator board

Written by the coordinator only. Lanes: read this before starting work and after each push.

## Current state

- `main`: #293 (round j55). Game.exe identical; 14,918 / 14,918 placed; borrowed code 12,041 B in 9 functions; borrowed data 15,689 B.
- Units 976, placeholder files 581.
- Rounds: the coordinator polls `lane*` branches, merges by cherry-pick (skipping commits already on main by subject), checks the data plan, units.json and data includes against main plus each lane's own moves, prechecks, runs one full verify, and ships.

## Ownership

| Lane | Owns |
|---|---|
| 1 | D2Client/UNIT, D2Client.h, D2Client placeholders at 0x4C0000-0x4DFFFF |
| 2 | Source/Include (shared headers, records, fields) |
| 3 | Storm, Fog, SRP |
| 4 | the rest of D2Client |
| 5 | D2Game |
| 6 | D2Common, D2CMP, D2Launch, D2Multi, D2Win, D2Net, D2BNClient/Bnclient, renderers, D2Hell, the other modules |
| 7 | the 9 borrowed functions (not started) |

A function belongs to the lane whose address range or file run it sits in, whatever file it is filed in today.

## Held back

| Branch / commit | Why | What it needs |
|---|---|---|
| `lane2/config-record` | conflicts in Game_0044D080.cpp; base ccb53902 predates #291-#293 | rebase on main, push as `config-record-2` |
| `lane1/join-gethitsounds` | 0x4CA560 MISMATCH in UnitSnd.cpp on main | waits until UnitSnd.cpp's headers settle |

## Decisions in force

- **Evidence order for placements:** an assert path settles it; a `blizzard` name can outweigh adjacency; an `inferred` or `d2moo` name loses to the address run; if both are weak, leave it and list it.
- **Records:** the game configuration record is `D2ConfigStrc` (lane 2 renaming), one client global `gpClientConfig` in D2Client.h; the callback table at 0x225 is one record.
- **zlib:** units named after their zlib 1.2.8 files under `Source/Storm/zlib/` (lane 3).
- **Id headers:** only D2StatIds.h is `#define`s; the other six stay enums until a function needs otherwise.
- **Redivivus:** not used. Nothing from it goes into the repo or to the lanes.

## Per lane

### Lane 1
- `place-launch-pair`, `join-soundenv`, `join-npcspeech-r2`: next round.

### Lane 2
- `config-record`: rebase onto main and push as `config-record-2`; it gets its own round.

### Lane 3
- zlib naming approved (see Decisions). Branch from main.

### Lane 4
- `chat-run`: next round.
- Leave `sub_00436E90_AlwaysOne` (Skills.cpp) and `sub_00436EA0` (Game.cpp): lane 6 takes them.

### Lane 5
- `a5q2-run`: next round.

### Lane 6
- `d2win-a`: next round. Take `sub_00436E90_AlwaysOne` and `sub_00436EA0` into `Unknown_004370B0.cpp`.

### Lane 7
- Not started.

## Merge log (newest first)

- #293 j55: lane 3 dbghelp in five units (handler code stays built), lane 6 mainmenus-b, lane 5 a1q4-run.
- #292 j54: zlib per source file, 69 stray copies dropped, a1q6 NPC callback, NPC speech join. Borrowed data -40 B.
- #291 j53: Baal AI, MainMenus split, one launch record, Gfx records, sound-channel unit.
