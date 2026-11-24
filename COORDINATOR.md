# Coordinator board

Written by the coordinator only. Lanes: read this before starting work and after each push.

## Current state

- `main`: #322 (round j85). Game.exe identical; 14,918 / 14,918 placed; borrowed code 12,041 B in 9 functions; borrowed data 3,415 B (was 15,691 B at #297).
- Units 963, placeholder files 562.
- In progress: nothing; next round as branches are posted ready.
- **`lane2/game-records` is held: precheck NOT_ALL_EQUAL on #321** in two includers of D2GameTypes.h that the branch doesn't touch, `Source/D2Win/Src/D2Comp.cpp` and `Source/D2Game/Ai/AiThink4.cpp`. It looks like the declaration-count effect. Lane 2: rebuild every includer of D2GameTypes.h on current main. If those two can't be kept equal, put the two callback records in a small header that only their users include, as you did with D2ClientTimer.h.
- **`lane1/keycfg-object-r` needs a rebase onto #317.** Lane 4's `keyconfig-split` (#317) already made `Unknown_004A43E0.cpp` from the same text.cpp range, so the two branches collide. The two splits also disagree on the range: lane 4's runs to 0x4A63B0, yours to 0x4A61A0, and lane 4's object map ends this object at 0x4A61A0. Rebase onto main and keep what yours adds: the 8 functions from text_0049A950.cpp, the 1 from Unknown_004A6000.cpp, the data 0x724264-0x72480F, the bss, and gnKeyConfigFirstVisible static. Send 0x4A61A0-0x4A63B0 back to the next object's placeholder, unless something in it ties it to this object.
- **Priority for every lane after your current branch: the language-table splits.** Each one places a file boundary, and often defines borrowed data too. Your rows are in language-objects.md.
- **Shims and context copies:** after you join files, try deleting the `// build: context` blocks in the joined unit. Many exist only because a caller and callee were in different files.
- **New: [language-objects.md](language-objects.md)**, an object map from all 308 language-table copies in .data. A copy *starts* its object's data (the header comes before the file's own definitions), so it belongs to the file whose data follows it. The map lists:
  - **60 planned files holding more than one copy.** Each spans that many original objects; split them at their copies. By lane: 6: 25 files, 5: 16, 4: 14, 1: 3, 3: 2. FieldTbls.cpp alone holds 15.
  - **21 borrowed copies (1,254 B, over a third of what's left).** Each has its neighbours and the gap to the next data. Copies at a lane edge are marked.
  - **49 runs of back-to-back copies.** A run of N is N objects in link order with no other initialised data.
  - **Every copy**, with the planned file it starts.

  Take the rows for your lane. Before a split, check that the copy's object fits the code's address runs. A copy shows where an object's data starts, not which code goes with it.
- **Rounds now also check plan `files` entries** (`planfiles.py`): j74's first verify failed because a stale whole entry dropped one lane's externs. The precheck also builds every file whose data plan changed. If you edit a file's plan entry, keep your branch on a recent main.
- **`lane4/options-split` needs a rebase onto #308:** it conflicts in chat.cpp with #308's gnScreenHeight change. A 94-function move is yours to redo, not mine.
- **Borrowed data by lane:** [borrowed-data.md](borrowed-data.md), regenerated at #318 (3,415 B left), lists every block of the 15,691 B still copied from Game.exe, with the file that owns it and how that was decided. Each lane has a section with its leads. Take them after your current branch.
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
| `lane5/unit-init-seed` | replaced by `unit-init-seed-2` | nothing |
| `lane6/lang-a` | replaced by `lang-a-2` | nothing |
| `lane4/options-split` | replaced by `options-split-2` | nothing |
| `lane5/coord-init-2` | same two commits as `coord-init`, already in #314 | nothing |
| `lane6/sound-a`, `lane1/keycfg-object-r` | replaced by `sound-a-2`, `keycfg-extras` | nothing |
| `lane2/cmp-records` | replaced by `cmp-records-2` | nothing |
| `lane2/game-records` | precheck unequal on #321: D2Comp.cpp, AiThink4.cpp | lane 2 (see Current state) |
| `lane1/monster-4aff60` | replaced by `-2` | nothing |
| `lane1/join-gethitsounds` | 0x4CA560 MISMATCH in UnitSnd.cpp on main | waits until UnitSnd.cpp's headers settle |

## Decisions in force

- **Evidence order for placements:** an assert path settles it; a `blizzard` name can outweigh adjacency; an `inferred` or `d2moo` name loses to the address run; if both are weak, leave it and list it.
- **Records:** the game configuration record is `D2ConfigStrc` (lane 2 renaming), one client global `gpClientConfig` in D2Client.h; the callback table at 0x225 is one record.
- **zlib:** units named after their zlib 1.2.8 files under `Source/Storm/zlib/` (lane 3).
- **Id headers:** only D2StatIds.h is `#define`s; the other six stay enums until a function needs otherwise.
- **D2ClientNotifyStrc stays a view** of D2ComInterfaceStrc for now. Don't force the merge: the inv_0048BC10/inv_0048DD90 operand order says those units' original headers differ from ours in a way we can't see yet. Lane 4 retries when those units change for other reasons.
- **Pathfinding cluster 0x00678B10-0x0067BE00 (lane 6):** the strays filed in Skills.cpp and Drlg.cpp move out either way. To choose between one placeholder and several, test the shared data block 0x006F1798-0x006F1D9C. Split it by which functions read each part. If it divides into consecutive pieces, each read by a consecutive group of functions, make one placeholder per group: one object's data is contiguous, so a clean partition marks file boundaries. If the readers cross the whole block, make one placeholder, `Unknown_006793E0.cpp`. Either way, names stay placeholders: there's no assert and the names are d2moo.
- **Language-name table (from lane 4):** the 15-entry table of language-name pointers is a header-level static array, so each object file that includes the header gets one copy. 308 copies are in .data. This is placement evidence: **a planned file holding N copies spans N original units**, and a copy marks where a unit's data starts. It sits next to the assert-path rule; it beats adjacency and names. Lane 2: find the header (Fog's ErrorManager.cpp reads its copy as `gaszLanguageNames`) and define the table there once, as `static`. Then each lane turns the copies in its own files into that include, unit by unit. Only units whose original had a copy may include it: a unit that gains a copy the image doesn't have breaks the build.
- **Shared const tables (from lane 6):** a namespace-scope `const` table has internal linkage in C++, so two functions that read the same one were in one file, unless the table is declared extern. Ignore pooled strings, floating-point constants and selectany GUIDs. This ranks with the language-table rule.
- **Redivivus:** not used. Nothing from it goes into the repo or to the lanes.

## Per lane

**Borrowed functions, now with each owning lane** (lane 7 never started; the user approved spreading them). These 9 functions are the last 12,041 B of code taken from the image. Each lane takes its own after its current branch. The earlier notes are in the iblis-lane7 package (ask the user for it). They are summed up here; the key finding is that a static callee with a register calling convention fixes which file the caller must be built in.

| Function | Size | Lane | Where it must be built / state |
|---|---:|---|---|
| 0x4A4AD0 | 1,232 | 1 | Unknown_004A43E0.cpp; 1,202 B, register choice only |
| 0x62B5B0 | 1,192 | 6 | D2Common ITEMS/Items.cpp (0x628830 takes nRequiredLevel in eax). Same length reached: the original keeps nRequiredLevel in esi; ours spills it |
| 0x677880 | 4,232 | 6 | needs DRLG/OutPlace.cpp and Unknown_00675600.cpp joined first; its 296 B of borrowed data at 0x6F13F0 comes with it |
| 0x679C80 | 450 | 6 | needs Unknown_006793E0 (/GS-) and Unknown_00679A60 joined; check whether `path-a-2`/`pathmisc-a` already did that |
| 0x4F8B80 | 561 | 6 | D2Win, __fastcall, no file constraint; stand-in differs in register allocation |
| 0x55A6D0 | 2,253 | 5 | D2Game ITEMS/Items.cpp |
| 0x5DD7F0 | 1,084 | 5 | D2Game Ai/AiUtil.cpp |
| 0x5EDC50 | 791 | 5 | D2Game AI, no file constraint |
| 0x6BD230 | 246 | 3 | Fog export 10215. Every byte equal except one unused 4-byte frame slot; verified functions show such a slot only when they have register parameters |

A match goes into its file in address order: record it in units.json and as `verified` in functions.json, delete its stand-in in Source/StandIns/, and post it as usual. No forcing constructs.

**Freeze lifted:** `config-record-3` is on main (#296). The record is `D2ConfigStrc`, the 0x7A0438 global is `gpClientConfig` in D2Client.h. Rebase before your next push.

### Lane 1
- `hdr-4df6c0-2` is in #302, `one-screenheight-r` in #308. Keeping the one private declaration in inv_004886C0.cpp is right; the declaration-count finding is now in Lane 2's notes too.
- **0x4A4AD0:**
  - **Earlier notes.** I've re-sent the lane-7 package to the user. The earlier attempts' finding: 0x4A4AD0's callees take arguments in registers, so it must share their unit. Then that unit was text_0049D490.cpp; it is text.cpp now, so your choice of text.cpp is right. The earlier attempts built it standalone and never got close.
  - **On 0x4A4AD0 (1,202 of 1,232 B in the split unit):** the remaining difference is register choice right after the first helper call. Keep it as a stand-in. One untried lever is the order in which nY and bInList are first assigned and used before that call: the compiler gives ebx to whichever value it sees most uses of, weighted by loop depth.
  - **Update:** lane 4's `keyconfig-split` (#317) puts the key-config panel 0x4A43E0-0x4A63B0, with its data and globals, in `Unknown_004A43E0.cpp`, and your 0x4A4AD0 work is in it. It is on main: continue there.
  - **Correction, from lane 4's object map:** text.cpp ends around 0x4A15xx. It has path users, its data runs to 0x723768, and its asserts go up to line 5747. **0x4A4AD0 sits in an unnamed object at 0x4A41xx-0x4A61A0** (stat/skill buttons and panel keys; its data runs to 0x724798). We have that object filed inside text.cpp. Its callees are in the same object, so the unit constraint still holds, but the unit is the smaller object, not text.cpp. Build it as that object: with lane 4, split 0x4A41xx-0x4A61A0 out of text.cpp into a placeholder, then try 0x4A4AD0 there with `gnKeyConfigFirstVisible` static. In a smaller unit, 0x4A4500 may survive the static.
  - **Lead on the static.** text_0049A950.cpp still owns 0x4A4110 and 0x4A4780, inside text.cpp's 0x4A40D0-0x4A5270 run. It also defines `gnKeyConfigSelected`, which text.cpp has as its own static (lane 4's note). That's the key-config list's state split across two files. If 0x4A4110/0x4A4780 join text.cpp and the key-config globals are made text.cpp statics together, 0x4A4500 may match with `gnKeyConfigFirstVisible` static. Lane 4 owns text_0049A950.cpp: coordinate there, or do it on your branch and say so.
Work list, in order of value:
1. **Borrowed function 0x004A4AD0** (D2Client, 1,232 B, today `Source/StandIns/D2Client_004A4AD0.cpp`). Lane 7 never started, and it is in D2Client, so it is yours. It is one of the 9 functions still taken from the image: a match removes 1,232 B of borrowed code. The lane-7 notes from earlier attempts are in the iblis-lane7 package (ask the user if you don't have it). Report progress on your board file even if it doesn't land.
2. **D2Client.h tidy:** line 847 still declares `sub_004DF6C0(int nArg)`; 0x4DF6C0 is `GFXUTIL_ApplySoundEnviron` now and nothing uses that declaration. Drop it.
3. **gnScreenHeight (0x711470):** one name. D2Client.h has `gnScreenHeight_00711470`, while 59 units declare `gnScreenHeight` privately. Make D2Client.h's the one declaration (name `gnScreenHeight`) and drop the private ones. Mind your type-count finding (dropping declarations can shift registers): keep any unit's private declaration that must stay, and say which. One branch, pushed soon after it verifies; it touches other lanes' files, so I merge it alone.
4. **Placeholders lane 4 handed back:** Unknown_004C0440 (0x4C0550), Unknown_004C7C80, Unknown_004C97C0.
5. **GetHitSounds (0x4CA560):** retry now that #296 changed D2Client.h, using your struct-count finding.
6. **Borrowed data, UnitSnd.cpp:** 2,692 B in 69 blocks at 0x00727F84-0x007295E0. The gData_ pieces there are slices of one table of 48-byte records. See borrowed-data.md.

Note for item 3, from lane 2: in inv_0048BC10 and inv_0048DD90 (lane 4's), the gnScreenHeight/gnPanelOffsetY operand order flips when D2ClientUi.h changes. Lane 2 tried one name for 0x711470 in those two units, among other things, and it broke them. Keep their private declarations if they don't survive the unification, and say so.

### Lane 2
- `fog-records` is in #316. pMonPropTxt staying `void*`: agreed, because every typed form flips inv_0048DD90 and the table units.
- `party-row`, `msg-record`, `save-header` and `lang-names` are in #310; `quest-timer` and `shared-copies` are in j76. D2LanguageNames.h is on main: lanes can now include it where a unit's original had a copy.
- Language-name table: yours to start (see Decisions). Lane 5 reports copies at the ends of AiThink.cpp (twice: so it spans two original units), a3q7.cpp and MonsterChoose.cpp.
- `sets-txt` is in #306.
- `com-interface` is in #301. The conflict with #299 (Unknown_0043A9D0.cpp folded into CharSel.cpp) was resolved by carrying the type rename into CharSel.cpp.
- D2ClientNotifyStrc: keep it as a view (see Decisions). Thanks for the 60 tries; that's enough evidence to stop.
- From lane 1: some functions change register choice with the **number** of struct definitions in the unit, not their names (0x4CA560 in UnitSnd.cpp matches with +2..+4 dummy structs, not +1 or +5..+8; the enum-size finding was probably the same effect; deleting three unused forward declarations in Item.cpp breaks 0x4C3760). Worth knowing before dropping private record copies or forward declarations in bulk.

### Lane 3
- On main: zlib #297; trees-data, crt-init #302; crt-locks #303; data-fixes #305; fog-strays, cpu-report #307; storm-strays, sfile-dtors #309; text-data #311; sstr-strays, sevt-strays #313; sbig-names #315; sbig-exports #317; sbig-arrays #318; sbig-copy, crypt #319; scomp-strays, sfile-destroy, sevt-deletenode #321.
- **SUNI.CPP: yes.** **AUTOMAP_ReadTimeStampCounter to ErrorManager.cpp: yes.** **D2StormBigBuffer.h / D2StormArrayA.h edits: approved.** (Answers from earlier, kept here.)
- **0x6BD230 (borrowed, Fog export 10215) is yours.** See the borrowed-functions table above.
- **New lead, from the coordinator's 728 B (the largest borrowed-data block left): an ATL object.** 0x6B1A00 is `Define_the_symbol__ATL_MIXED::Thank_you::Thank_you()`, which ATL's atldef.h emits. That function and its neighbours 0x6B1A10-0x6B1B60 (Storm/Unknown_006B1A00.cpp, _006B1A10, _006B1A20, _006B1A30, _006B1A70, _006B1A90) are one object that included ATL.
  - Its .rdata is the borrowed block at 0x6FAD20-0x6FAFF8, right after libcmt's: the ATL registrar's header data (statreg.h). That is the key names "TypeLib", "SYSTEM", "SECURITY", "SAM", "Mime", "Hardware", "Interface", "FileType", "Component Categories", "CLSID" and "AppID"; the keywords "Delete", "NoRemove", "ForceRemove" and "Val"; the never-delete pointer table; and the registrar GUIDs.
  - Proposal: gather 0x6B1A00-0x6B1B60 into one placeholder and define that data in it, in the order the image has it. The toolchain has no atlmfc headers, so write the declarations yourself, modelled on ATL 8.0's statreg.h and atldef.h (`__declspec(selectany)` where ATL uses it).
  - This is yours by directory. It isn't Storm code, though: if the object's callers say which module it belongs to, file it there and tell that lane.

### Lane 4
- `borrowed-b` and `initializers` are in #311; `warden-strays-2` and `init-more` are in j76.
- `options-split-2` and `keyconfig-split` are in j80. Thanks for doing the key-config split.
- Fast-forwarding a new commit onto an already-posted branch (questlog) is fine, as long as the old commits stay and the ready line names the new head. The new-name rule is for rewritten history.
- **WINMAIN.CPP split (your question): yes, both.** The language-table copies are the evidence, and they're strong.
  - Move 0x44B400-0x44B430 (InitInterface, ShutdownInterface, RunLauncher) to `Source/D2Client/Unknown_0044B400.cpp`.
  - Move the MCP packet run 0x44A170-0x44B3xx, with `gpfnConnectPacketHandlers` and its data, to `Source/D2MCPClient/Unknown_0044A170.cpp`. It follows `.\Src\McpConnect.cpp` and a data-less object, so it belongs to the D2MCPClient module. You know the code, so you do the move, on one branch. After it merges, the file is lane 6's; lane 6, take note.
- **The text-area object map:** good work, and it's now the basis for lane 1's 0x4A4AD0 attempt. Please split the unnamed object 0x4A41xx-0x4A61A0 out of text.cpp into a placeholder (it's your file), and tell lane 1 when it's pushed.
- From lane 3: 0x700140-0x7001C0 (listed as lane 3's in borrowed-data.md) is WardenClient's RTTI (object locator, class hierarchy, base class descriptors). It belongs with WardenClient.cpp's `??_R0` line; take it.
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
- `data-b` is in #309: borrowed data fell to 6,376 B in that round.
- **Language-table runs as an object count:** yes, go ahead. A run of back-to-back copies with no other data counts objects in link order, so match the copies to code files in order. Two cautions. First, a file that includes the header twice through different paths still gets one copy, because it's one static per translation unit; Ignorelist.cpp's two copies therefore mean two units. Second, objects that define no initialized data of their own still get a copy. A gData_ block holding N copies is N files' data: split it before you place anything.
- D2MCPClient: lane 4 is moving the MCP packet run out of WINMAIN.CPP into `Source/D2MCPClient/Unknown_0044A170.cpp`. It becomes yours once merged.
- `seg-a` is in #316. The const-table rule is now in Decisions. Leaving 0x00648020 and 0x0043B080 is right.
- `cands-d` is in #299, `bss-a` in #302; `bss-a-2` and `path-a-2` are in j67. The path split by data reader is the right call.
- From lane 3: the dynamic initializers and atexit destructors of long-lived critical sections go into the file that owns the lock. `lane3/crt-locks` shows the pattern: a `CCritSect` type plus the `// build: symbol ??__E…`/`??__F…` lines. Yours: 0x6CAE80/0x6CB420 lock 0x881860 and 0x6CAED0/0x6CB470 lock 0x881F64 (BnDownload.cpp); 0x6CAEA0/0x6CB440 lock 0x881894 (CACHE.CPP); 0x6CB010/0x6CB4E0 lock 0x96D610 (Preset.cpp). Wait for crt-locks to merge (j66) and build on its type. CharSel.cpp taking sub_0043B830/0x43B840 from Game.cpp is fine: the run and the globals settle it.
- Pathfinding cluster: answered in Decisions. DUNGEON_ 0x00643260-0x00643560, the D2DDraw renderer, and Items.cpp 0x006313E0: leaving them is right.
- Borrowed data: you have the largest share, 7,361 B. 5,127 B of it is one block at 0x007420D1 between CelCmp.cpp and Unknown_006056D0.cpp: four small-int tables that no code addresses directly. See borrowed-data.md.
- `d2win-a` and `block-c` are in #294.

### Lane 7
- Not started. 296 B of borrowed data (0x006F13F0) goes when 0x00677880 is written.

## Merge log (newest first)

- #322 j85: levelevents (lane 4), monster-4aff60-2 (lane 1), system-strays (lane 3), lang-pad (lane 5).
- #321 j84: levelup-split, inv-split (lane 4), scomp-strays, sfile-destroy, sevt-deletenode (lane 3), lang-split-2 (lane 5), codec-a (lane 6), cmp-records-2 (lane 2).
- #320 j83 (coordinator): 69 shims and context copies removed (shims 115 → 86, context markers 583 → 502). Each was tested alone, then all together.
- #319 j82: sound-a-2, glcore-a, pathmisc-a (lane 6), fog-records-b (lane 2), lang-split (lane 5), sbig-copy, crypt (lane 3), winmain-split (lane 4), keycfg-extras (lane 1).
- #318 j81: sbig-arrays (lane 3), lang-owners (lane 5), game-timer and records-a (lane 2).
- #317 j80: options-split-2 and keyconfig-split (lane 4), sbig-exports (lane 3).
- #316 j79: questlog (lane 4), seg-a (lane 6), fog-records (lane 2).
- #315 j78: skills-placeholders (lane 1), sbig-names (lane 3), questlog (lane 4), lang-a-2 (lane 6).
- #314 j77: unit-init-seed-2 and coord-init (lane 5); Storm conflict resolved by the coordinator.
- #313 j76: warden-strays-2, init-more (lane 4), sstr-strays, sevt-strays (lane 3), quest-timer, shared-copies (lane 2).
- #312 j75: BnDownload/CACHE/Preset locks become objects (lane 6); conflict with #309 resolved by the coordinator.
- #311 j74: UnitSnd table (lane 1), borrowed-b and initializers (lane 4), text-data (lane 3). Borrowed data −2,883 B.
- #310 j73: D2ClientParty.h, D2MsgRecord.h, D2SaveHeader.h, D2LanguageNames.h (lane 2).
- #309 j72: data-b (lane 6), task-locks (lane 5), storm-strays and sfile-dtors (lane 3), uiwidget (lane 4). Borrowed data −6,240 B.
- #308 j71: one declaration of gnScreenHeight, in D2Client.h (lane 1), alone. automap.cpp conflict resolved by the coordinator.
- #307 j70: fog-strays and cpu-report (lane 3), warden-class (lane 4), prime-nova (lane 5).
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
