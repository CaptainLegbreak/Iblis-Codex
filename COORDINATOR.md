# Coordinator board

Written by the coordinator only. Lanes: read this before starting work and after each push.

## Current state

- `main`: #306 (round j69). Game.exe identical; 14,918 / 14,918 placed; borrowed code 12,041 B in 9 functions; borrowed data 12,878 B (was 15,691 B at #297).
- Units 963, placeholder files 562.
- In progress: round j70 = `lane3/fog-strays`, `lane3/cpu-report`, `lane4/warden-class`, `lane5/prime-nova`. Next: j71 = `lane1/one-screenheight-r` alone. `lane2/party-row`: post it on your board file when it's verified.
- **Borrowed data by lane:** [borrowed-data.md](borrowed-data.md), regenerated at #305, lists every block of the 15,691 B still copied from Game.exe, with the file that owns it and how that was decided. Each lane has a section with its leads. Take them after your current branch.
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
| `lane1/hdr-drop-4df6c0` | same commit as `hdr-4df6c0-2` on an older base | nothing; superseded |
| `lane4/runs-sub`, `lane4/game-loader` | replaced by `runs-sub-2` and `game-borrowed` | nothing |
| `lane6/bss-a` | replaced by `bss-a-2` | nothing |
| `lane1/join-gethitsounds` | 0x4CA560 MISMATCH in UnitSnd.cpp on main | waits until UnitSnd.cpp's headers settle |

## Decisions in force

- **Evidence order for placements:** an assert path settles it; a `blizzard` name can outweigh adjacency; an `inferred` or `d2moo` name loses to the address run; if both are weak, leave it and list it.
- **Records:** the game configuration record is `D2ConfigStrc` (lane 2 renaming), one client global `gpClientConfig` in D2Client.h; the callback table at 0x225 is one record.
- **zlib:** units named after their zlib 1.2.8 files under `Source/Storm/zlib/` (lane 3).
- **Id headers:** only D2StatIds.h is `#define`s; the other six stay enums until a function needs otherwise.
- **D2ClientNotifyStrc stays a view** of D2ComInterfaceStrc for now. Don't force the merge: the inv_0048BC10/inv_0048DD90 operand order says those units' original headers differ from ours in a way we can't see yet. Lane 4 retries when those units change for other reasons.
- **Pathfinding cluster 0x00678B10-0x0067BE00 (lane 6):** the strays filed in Skills.cpp and Drlg.cpp move out either way. To choose between one placeholder and several, test the shared data block 0x006F1798-0x006F1D9C. Split it by which functions read each part. If it divides into consecutive pieces, each read by a consecutive group of functions, make one placeholder per group: one object's data is contiguous, so a clean partition marks file boundaries. If the readers cross the whole block, make one placeholder, `Unknown_006793E0.cpp`. Either way, names stay placeholders: there's no assert and the names are d2moo.
- **Language-name table (from lane 4):** the 15-entry table of language-name pointers is a header-level static array, so each object file that includes the header gets one copy. 308 copies are in .data. This is placement evidence: **a planned file holding N copies spans N original units**, and a copy marks where a unit's data starts. It sits next to the assert-path rule; it beats adjacency and names. Lane 2: find the header (Fog's ErrorManager.cpp reads its copy as `gaszLanguageNames`) and define the table there once, as `static`. Then each lane turns the copies in its own files into that include, unit by unit. Only units whose original had a copy may include it: a unit that gains a copy the image doesn't have breaks the build.
- **Redivivus:** not used. Nothing from it goes into the repo or to the lanes.

## Per lane

**Freeze lifted:** `config-record-3` is on main (#296). The record is `D2ConfigStrc`, the 0x7A0438 global is `gpClientConfig` in D2Client.h. Rebase before your next push.

### Lane 1
- `hdr-4df6c0-2` is in #302. `one-screenheight-r` is next, as j71, alone. Keeping the one private declaration in inv_004886C0.cpp is right; the declaration-count finding is now in Lane 2's notes too.
- The lane-7 notes (iblis-lane7 package) are with the user; they were sent earlier.
Work list, in order of value:
1. **Borrowed function 0x004A4AD0** (D2Client, 1,232 B, today `Source/StandIns/D2Client_004A4AD0.cpp`). Lane 7 never started, and it is in D2Client, so it is yours. It is one of the 9 functions still taken from the image: a match removes 1,232 B of borrowed code. The lane-7 notes from earlier attempts are in the iblis-lane7 package (ask the user if you don't have it). Report progress on your board file even if it doesn't land.
2. **D2Client.h tidy:** line 847 still declares `sub_004DF6C0(int nArg)`; 0x4DF6C0 is `GFXUTIL_ApplySoundEnviron` now and nothing uses that declaration. Drop it.
3. **gnScreenHeight (0x711470):** one name. D2Client.h has `gnScreenHeight_00711470`, while 59 units declare `gnScreenHeight` privately. Make D2Client.h's the one declaration (name `gnScreenHeight`) and drop the private ones. Mind your type-count finding (dropping declarations can shift registers): keep any unit's private declaration that must stay, and say which. One branch, pushed soon after it verifies; it touches other lanes' files, so I merge it alone.
4. **Placeholders lane 4 handed back:** Unknown_004C0440 (0x4C0550), Unknown_004C7C80, Unknown_004C97C0.
5. **GetHitSounds (0x4CA560):** retry now that #296 changed D2Client.h, using your struct-count finding.
6. **Borrowed data, UnitSnd.cpp:** 2,692 B in 69 blocks at 0x00727F84-0x007295E0. The gData_ pieces there are slices of one table of 48-byte records. See borrowed-data.md.

Note for item 3, from lane 2: in inv_0048BC10 and inv_0048DD90 (lane 4's), the gnScreenHeight/gnPanelOffsetY operand order flips when D2ClientUi.h changes. Lane 2 tried one name for 0x711470 in those two units, among other things, and it broke them. Keep their private declarations if they don't survive the unification, and say so.

### Lane 2
- Language-name table: yours to start (see Decisions). Lane 5 reports copies at the ends of AiThink.cpp (twice: so it spans two original units), a3q7.cpp and MonsterChoose.cpp.
- `sets-txt` is in #306.
- `com-interface` is in #301. The conflict with #299 (Unknown_0043A9D0.cpp folded into CharSel.cpp) was resolved by carrying the type rename into CharSel.cpp.
- D2ClientNotifyStrc: keep it as a view (see Decisions). Thanks for the 60 tries; that's enough evidence to stop.
- From lane 1: some functions change register choice with the **number** of struct definitions in the unit, not their names (0x4CA560 in UnitSnd.cpp matches with +2..+4 dummy structs, not +1 or +5..+8; the enum-size finding was probably the same effect; deleting three unused forward declarations in Item.cpp breaks 0x4C3760). Worth knowing before dropping private record copies or forward declarations in bulk.

### Lane 3
- zlib is in #297. `trees-data` and `crt-init` are in j65; `crt-locks` follows in j66.
- The critical-section and initializer notes for other lanes are passed on below.
- Borrowed data: 0x006D13D8, 768 B, is zlib's `_dist_code`/`_length_code` (read by deflate.c and trees.c). In zlib 1.2.8 they come from trees.h, included by trees.c. That one block is half your borrowed data.

### Lane 4
- `place-c` is in #299, `runs-sub-2` in #304; `game-borrowed` is in #305; `warden-class` is in j70. Reading the vtable through its object locator is the right way to settle a class.
- **UIWidget slots (your question): yes.** The vtable at 0x6DA6C0 is twelve `_purecall`s, so slots 1-11 are pure virtuals of the base, and ListBoxImplementation and ListBoxWrapper override them. Give each slot one name in all three classes, with its names.csv rows. Name a slot by what the two overrides have in common. Where one of the two current names is a `blizzard` name, keep that one. The char[260] and literal-string fixes in `game-borrowed`: good, push when verified.
- From lane 3: most of `Storm/Unknown_006C9A68.cpp`, `Unknown_006CACE0.cpp`, `Unknown_006CAA30.cpp` and `Unknown_006CAE80.cpp` are D2Client dynamic initializers (text buffers, layout rects, hashes of "Header"/"Game Time", captions). They belong with the globals they set, in your files and lane 1's. Wait for crt-locks (j66), then take the ones whose globals you own.
- Borrowed data: gszServerIP (WINMAIN.CPP) and gszMcpIP (Game_0044D080.cpp) are planned as char[16], and each is followed by 244 zero bytes copied from the image: 16 + 244 = 260. Check whether they are char[260]. More in borrowed-data.md.
- `chat-run-2` is in #294.
- SkillDesc.cpp and SkillDesc_004E1FF0.cpp call 0x4DF6C0 as `sub_004DF6C0`; it is `GFXUTIL_ApplySoundEnviron` now (in lane 1's sound unit). Rename the two calls.
- Leave `sub_00436E90_AlwaysOne` and `sub_00436EA0`: they moved to lane 6's `Unknown_004370B0.cpp` in #294.

### Lane 5
- `a3q5-orb` is in #298, `a3q7-dogs` in #299, `a3q2-run` in #300; `intro-q0` and `game-defaults` are in #302; `small-strays` is in #304; `monsterchoose` is in #305; `prime-nova` is in j70.
- **0x731EB8 gnUnitInitSeed (your question):** same answer as the Task.cpp locks. Take the initializer 0x6CAF60 out of Storm/Unknown_006CAE80.cpp into the file that owns the global.
- 0x745580 (0x11B plus a language list, between Inventory.cpp and ItemMode.cpp data): leaving it is right. Lane 6, it's at your edge.
- **Task.cpp locks (your question): yes, from your lane.** Delete the four functions from Storm/Unknown_006CAE80.cpp, Storm/Unknown_006CAF90.cpp, Storm/Unknown_006CB4A0.cpp and Bnclient/Unknown_006CB420.cpp, and move their units.json entries. A function goes to the file that owns it, whatever placeholder it sits in today. Lanes 3 and 6: leave those four alone.
- Language-name copies at the end of D2Game files: see the Decisions rule. Lane 2 has the header question.
- **0x007415F4 (your question):** you're right, nothing reads it. My first map counted references up to 8 bytes before a block, so a reference to the end of gpDiamondMonsterFormation was credited to it. That slack is gone. The block holds 4-char codes plus a pointer table into them (0x7416A0-0x741734), and nothing references that table either. Place it by its neighbours, or leave it if neither side's content fits.
- GAME_GetGamesCount twice (0x0052BFE0 in D2Net.cpp, 0x0052DB30 in Game.cpp): leaving it is right.
- From lane 3 (after crt-locks merges in j66): the initializer and destructor 0x6CAF70/0x6CB490 for lock 0x88CAA8 belong in D2Game Task.cpp. The array of 32 locks at 0x88C7A8 (0x6CAF90/0x6CB4A0, built with the CRT array constructor) sits in D2Game's bss; find which file uses it and take it if it's yours.
- `a5q2-run` and `a4q3-a3q6` are in #294; `a1q6-npc` (#292) and `a1q4-run` (#293) before that.
- 0x5B9A30 and 0x5947E0: listing them is right; no forcing constructs.

### Lane 6
- `cands-d` is in #299, `bss-a` in #302; `bss-a-2` and `path-a-2` are in j67. The path split by data reader is the right call.
- From lane 3: the dynamic initializers and atexit destructors of long-lived critical sections go into the file that owns the lock. `lane3/crt-locks` shows the pattern: a `CCritSect` type plus the `// build: symbol ??__E…`/`??__F…` lines. Yours: 0x6CAE80/0x6CB420 lock 0x881860 and 0x6CAED0/0x6CB470 lock 0x881F64 (BnDownload.cpp); 0x6CAEA0/0x6CB440 lock 0x881894 (CACHE.CPP); 0x6CB010/0x6CB4E0 lock 0x96D610 (Preset.cpp). Wait for crt-locks to merge (j66) and build on its type. CharSel.cpp taking sub_0043B830/0x43B840 from Game.cpp is fine: the run and the globals settle it.
- Pathfinding cluster: answered in Decisions. DUNGEON_ 0x00643260-0x00643560, the D2DDraw renderer, and Items.cpp 0x006313E0: leaving them is right.
- Borrowed data: you have the largest share, 7,361 B. 5,127 B of it is one block at 0x007420D1 between CelCmp.cpp and Unknown_006056D0.cpp: four small-int tables that no code addresses directly. See borrowed-data.md.
- `d2win-a` and `block-c` are in #294.

### Lane 7
- Not started. 296 B of borrowed data (0x006F13F0) goes when 0x00677880 is written.

## Merge log (newest first)

- #306 j69: D2SetsTxt.h, one sets.txt record (lane 2), alone.
- #305 j68: game-borrowed (lane 4), data-fixes (lane 3), monsterchoose (lane 5). Borrowed data −1,565 B.
- #304 j67: 22 D2Client run placements (lane 4), small strays (lane 5), bss-a-2 and the pathfinding groups (lane 6).
- #303 j66: critical sections become objects in their own files (lane 3); conflict with crt-init resolved by the coordinator.
- #302 j65: zlib tables and CRT initializers (lane 3), intro-q0 and game-defaults (lane 5), bss-a (lane 6), the 0x4DF6C0 declaration (lane 1). Borrowed data −1,248 B.
- #301 j64: D2ComInterfaceStrc, one record for the 0x225 table (lane 2), alone; CharSel.cpp conflict with #299 resolved by the coordinator.
- #300 j63: a3q2 takes in four strays (lane 5).
- #299 j62: a3q7 vile-dog pair (lane 5), ten D2Client placements (lane 4), fifteen placements incl. the CharSel.cpp seam and debug fonts (lane 6).
- #298 j61: a3q5 takes in the Compelling Orb functions (lane 5).
- #297 j60: zlib under Source/Storm/zlib/ (lane 3), a2q4 run (lane 5), chat.cpp placements (lane 4).
- #296 j59: D2ConfigStrc and gpClientConfig (lane 2), alone.
- #295 j58: SkillDesc calls GFXUTIL_ApplySoundEnviron by name (lane 4).
- #294 j56: sound unit takes NPC speech and sound environment (lane 1), chat.cpp run (lane 4), D2Win archive/palette and the launch pair (lane 6), a5q2/a4q3/a3q6 runs (lane 5).
- #293 j55: lane 3 dbghelp in five units (handler code stays built), lane 6 mainmenus-b, lane 5 a1q4-run.
- #292 j54: zlib per source file, 69 stray copies dropped, a1q6 NPC callback, NPC speech join. Borrowed data -40 B.
- #291 j53: Baal AI, MainMenus split, one launch record, Gfx records, sound-channel unit.
