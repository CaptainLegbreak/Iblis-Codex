# Coordinator board

Written by the coordinator only. Lanes: read this before starting work and after each push.

## Current state

- `main`: #297 (round j60). Game.exe identical; 14,918 / 14,918 placed; borrowed code 12,041 B in 9 functions; borrowed data 15,691 B.
- Units 963, placeholder files 562.
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
| `lane1/place-launch-pair` | same move as `lane6/block-c`, which merged in #294 | nothing; superseded |
| `lane4/chat-run` | stacked on the old gfx-more; WardenClient.cpp unequal | nothing; `chat-run-2` merged in #294 |
| `lane1/join-gethitsounds` | 0x4CA560 MISMATCH in UnitSnd.cpp on main | waits until UnitSnd.cpp's headers settle |

## Decisions in force

- **Evidence order for placements:** an assert path settles it; a `blizzard` name can outweigh adjacency; an `inferred` or `d2moo` name loses to the address run; if both are weak, leave it and list it.
- **Records:** the game configuration record is `D2ConfigStrc` (lane 2 renaming), one client global `gpClientConfig` in D2Client.h; the callback table at 0x225 is one record.
- **zlib:** units named after their zlib 1.2.8 files under `Source/Storm/zlib/` (lane 3).
- **Id headers:** only D2StatIds.h is `#define`s; the other six stay enums until a function needs otherwise.
- **Redivivus:** not used. Nothing from it goes into the repo or to the lanes.

## Per lane

**Freeze lifted:** `config-record-3` is on main (#296). The record is `D2ConfigStrc`, the 0x7A0438 global is `gpClientConfig` in D2Client.h. Rebase before your next push.

### Lane 1
Work list, in order of value:
1. **Borrowed function 0x004A4AD0** (D2Client, 1,232 B, today `Source/StandIns/D2Client_004A4AD0.cpp`). Lane 7 never started, and it is in D2Client, so it is yours. It is one of the 9 functions still taken from the image: a match removes 1,232 B of borrowed code. The lane-7 notes from earlier attempts are in the iblis-lane7 package (ask the user if you don't have it). Report progress on your board file even if it doesn't land.
2. **D2Client.h tidy:** line 847 still declares `sub_004DF6C0(int nArg)`; 0x4DF6C0 is `GFXUTIL_ApplySoundEnviron` now and nothing uses that declaration. Drop it.
3. **gnScreenHeight (0x711470):** one name. D2Client.h has `gnScreenHeight_00711470`, while 59 units declare `gnScreenHeight` privately. Make D2Client.h's the one declaration (name `gnScreenHeight`) and drop the private ones. Mind your type-count finding (dropping declarations can shift registers): keep any unit's private declaration that must stay, and say which. One branch, pushed soon after it verifies; it touches other lanes' files, so I merge it alone.
4. **Placeholders lane 4 handed back:** Unknown_004C0440 (0x4C0550), Unknown_004C7C80, Unknown_004C97C0.
5. **GetHitSounds (0x4CA560):** retry now that #296 changed D2Client.h, using your struct-count finding.

### Lane 2
- `config-record-3` is in #296. The 0x225 callback-table merge is approved as your next branch.
- From lane 1: some functions change register choice with the **number** of struct definitions in the unit, not their names (0x4CA560 in UnitSnd.cpp matches with +2..+4 dummy structs, not +1 or +5..+8; the enum-size finding was probably the same effect; deleting three unused forward declarations in Item.cpp breaks 0x4C3760). Worth knowing before dropping private record copies or forward declarations in bulk.

### Lane 3
- zlib naming approved (see Decisions). Branch from main.

### Lane 4
- `chat-run-2` is in #294.
- SkillDesc.cpp and SkillDesc_004E1FF0.cpp call 0x4DF6C0 as `sub_004DF6C0`; it is `GFXUTIL_ApplySoundEnviron` now (in lane 1's sound unit). Rename the two calls.
- Leave `sub_00436E90_AlwaysOne` and `sub_00436EA0`: they moved to lane 6's `Unknown_004370B0.cpp` in #294.

### Lane 5
- `a5q2-run` and `a4q3-a3q6` are in #294; `a1q6-npc` (#292) and `a1q4-run` (#293) before that.
- 0x5B9A30 and 0x5947E0: listing them is right; no forcing constructs.

### Lane 6
- `d2win-a` and `block-c` are in #294.

### Lane 7
- Not started.

## Merge log (newest first)

- #297 j60: zlib under Source/Storm/zlib/ (lane 3), a2q4 run (lane 5), chat.cpp placements (lane 4).
- #296 j59: D2ConfigStrc and gpClientConfig (lane 2), alone.
- #295 j58: SkillDesc calls GFXUTIL_ApplySoundEnviron by name (lane 4).
- #294 j56: sound unit takes NPC speech and sound environment (lane 1), chat.cpp run (lane 4), D2Win archive/palette and the launch pair (lane 6), a5q2/a4q3/a3q6 runs (lane 5).
- #293 j55: lane 3 dbghelp in five units (handler code stays built), lane 6 mainmenus-b, lane 5 a1q4-run.
- #292 j54: zlib per source file, 69 stray copies dropped, a1q6 NPC callback, NPC speech join. Borrowed data -40 B.
- #291 j53: Baal AI, MainMenus split, one launch record, Gfx records, sound-channel unit.
