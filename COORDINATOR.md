# Coordinator board

Written by the coordinator only. Lanes: read this before starting work and after each push.

## Current state

- `main`: #363 (round j118). Game.exe identical; 14,918 / 14,918 placed; borrowed code 12,041 B in 9 functions; borrowed data 848 B (was 15,691 B at #297). Placeholder files 390; shims 68; context copies 4. Names: blizzard 475, library 85, d2moo 5,234, inferred 5,574, placeholder 3,563.
- **New: [queues.md](queues.md), what's left per lane** (regenerated on #363): placeholder files, context copies, forcing constructs, shimmed functions, per-file options, with each lane's own list. When your current branch is done, take the next item from your row. The forcing constructs (42) are lane 7's job now: owners, leave them to lane 7 unless you settle it with lane 7 in its file. The context copies outside Storm/Fog/SRP are lane 2's trim first (see Answers), then the owners'. Also regenerated (regenerated on #363): [borrowed-data.md](borrowed-data.md) (906 B, by current owner) and [language-objects.md](language-objects.md) (14 files still hold more than one copy, each a split to make).
- In progress: nothing; next round as branches are posted ready.
- **Renames are landing on main.** After a rebase, run `python3 tools/namesync.py`: it renames the old spellings in your branch, so your branch stops conflicting with the renamed lines.
- **Rebase onto #363, run namesync, and repost:** `lane10/sweep-d2common-3`, `lane10/names-prefixfix-d2client-3` (regenerate both on #363; unchanged for 2-3 hours).
- **Context copies: 4 left** (from 345 this morning). Shims are next: 68, most of them a register-argument call between two units. After any join, try removing the shim for that pair.
- **Lane 5's six held copy branches are superseded by #354** (the static data marker and 28 objects' copies). Drop any whose copies #354 already covers. Repost the rest on #354 with markers, giving your verify's borrowed data figure (main: 848 B).
- **If wine aborts with `free(): invalid pointer`** (every unit COMPILE_ERROR with empty output, 0 s): `unset TMPDIR` before building. A TMPDIR=/tmp in the session environment breaks wine 9.0 here.
- **Priority for every lane after your current branch: your row in [queues.md](queues.md).** Language-table splits come first where you have them: 14 files still hold more than one copy ([language-objects.md](language-objects.md)). Each split places a file boundary.
- **Shims and context copies:** after you join files, try deleting the `// build: context` blocks in the joined unit. Many exist only because a caller and callee were in different files.
- **Rounds now also check plan `files` entries** (`planfiles.py`): j74's first verify failed because a stale whole entry dropped one lane's externs. The precheck also builds every file whose data plan changed. If you edit a file's plan entry, keep your branch on a recent main.
- Rounds: the coordinator polls `lane*` branches, merges by cherry-pick (skipping commits already on main by subject), checks the data plan, units.json and data includes against main plus each lane's own moves, prechecks, runs one full verify, and ships.

## How rounds work now (from 2026-11-24, approved by the user)

1. **Before each round the coordinator answers every open question on the board.** No lane waits a whole round for an answer.
2. **Lanes rebase their own stale branches.** When a branch conflicts with main, the coordinator posts "rebase X onto #NNN" and goes on; it no longer resolves conflicts by hand. After a rebase, run `python3 tools/namesync.py` so your branch uses main's current function names, rebuild, and repost the ready line with the new SHA.
3. **Lane 10 applies the names itself.** That covers its naming plans and the call-site rename sweep, module by module. It posts each result as a normal branch (`lane10/names-<scope>`, `lane10/sweep-<module>`) and the coordinator merges it like any other. The tools are in [tools-lane10/](tools-lane10/), described in Lane 10's section below.

## Working through the night

Every lane, every time it finishes or gets blocked:
1. **Never stop on a question.** Post it in your board file, park that item, and take the next one from your list. Answers come on this board.
2. **Keep a queue.** Your section below and borrowed-data.md / language-objects.md always have work for you. If your list runs dry, take the next language-table split, borrowed-data block or placeholder in your range, and say so on your board file.
3. **Schedule your own next check-in** (30 minutes) before your turn ends. Each check-in: fetch main and coord, read this file, finish or continue, push, post.
4. **Before posting a branch as ready, rebase onto the newest main.** Most hand-resolved conflicts tonight came from stale bases.
5. **Claim large jobs first** (file splits, multi-file joins): one line in your board file before you start, so two lanes don't do the same one.

## Ownership

**In effect (all four new lanes have started, 2026-11-23 ~22:00 PT): lanes 7, 8, 9 and 10.** Branches already in flight stay with whoever started them.
- **lane 7:** the borrowed functions, all but 0x4A4AD0 (lane 1 keeps it). Lanes 5 and 6: hand over your rows of the borrowed-functions table; branches in flight stay yours.
- **lane 8:** `Source/D2Common/**`, from lane 6. Lane 6 keeps D2CMP and the other modules. Lane 6: finish your D2Common branches in flight, then post a short handover list in your board file.
- **lane 9:** the renderers and D2Hell (`Source/D2Gfx`, `D2Direct3D`, `D2DDraw`, `D2Gdi`, `D2Glide`, `D2Hell`), from lane 6. Lane 6 keeps D2CMP, D2Launch, D2Multi, D2Win, D2Sound, D2Lang, D2Net, D2MCPClient and the Battle.net modules. The handover is the same as for lane 8.
- **lane 10:** names. It writes naming plans (`lanes/names/<scope>.tsv`) for the ~2,025 placeholder-named functions in known files, and edits no source. The coordinator applies one plan per round.

**Change from #323 (approved by the user): lane 1 takes D2Client from 0x4A0000 up, lane 4 keeps 0x440000-0x49FFFF.** Lane 4 had about twice anyone else's load. The boundary falls at an original file edge in lane 4's own object map: text.cpp ends before QuestLog.cpp, and QuestLog.cpp starts the new lane 1 range.
- **Branches in flight** stay with whoever started them. Finish and post them as usual.
- **Lane 4:** post a short handover list in your board file for 0x4A0000 and up: QuestLog's 22 unmatched functions, Unknown_004A6260 and the gnKeyConfigSelected duality, the levelup/spellsel follow-ups, SkillDesc, the language-table splits there, and whatever else you know. After that, start nothing new in that range.
- **Lane 1:** pick up from lane 4's list once it's posted. 0x4A4AD0, Unknown_004A43E0.cpp and the 0x4C0550/useitem.cpp work are yours already.
- A function belongs to the lane whose range it sits in, whatever file it is filed in today. That rule is unchanged.

| Lane | Owns |
|---|---|
| 1 | D2Client/UNIT, D2Client.h, and **all of D2Client from 0x4A0000 up** (text, QuestLog, key config, character screen, spellsel, npcmenu, SkillDesc, 0x4C0000-0x4DFFFF and above) |
| 2 | Source/Include (shared headers, records, fields) |
| 3 | Storm, Fog, SRP |
| 4 | D2Client **0x440000-0x49FFFF** (game, engine, view, inv, chat, options, Warden, Hireables, automap) and D2Client code below 0x440000 |
| 5 | D2Game |
| 6 | D2CMP, D2Launch, D2Multi, D2Win, D2Sound, D2Lang, D2Net, D2MCPClient, D2BNClient, Bnclient |
| 7 | 8 of the 9 borrowed functions (all but 0x4A4AD0, which is lane 1's) |
| 8 | D2Common |
| 9 | D2Gfx, D2Direct3D, D2DDraw, D2Gdi, D2Glide, D2Hell |
| 10 | naming plans for placeholder names in known files (`lanes/names/<scope>.tsv`); no source edits |

A function belongs to the lane whose address range or file run it sits in, whatever file it is filed in today.

## Standing work for every lane (from the outside review, 2026-11-23)

In your own files, whenever your current list allows:
- **Decompiler-style names:** `f_<hex>` fields (about 3,900 in 226 files), `unk0x` fields (about 2,100), `T<address>` struct names (456 uses), `struct Unit` with padding macros, and the `Unit*`/`U32` style in about 28 files. Replace them with the shared headers' records and real field names, wherever the bytes allow it. Shared-header changes go to lane 2.
- **Storm containers in one form:** Storm's own `TSHashTable<…>`, `TSList<…>` and `TSGrowableArray<…>` templates, as D2CMP has them. The plain `D2Storm…Strc` structs in D2Client and elsewhere move to the template form. Lane 3 owns the templates (`stpl.h`) and leads; each lane converts its own files.
- **Shims (85) and context copies (491):** retry deleting them after each join. The coordinator reports both counts each round.
- **Prototypes:** one prototype per function, the one in its defining file. The coordinator's rename sweep does this per module; don't add new private declarations with a different type.

## Answers (2026-11-24, before round j98)

- **Lane 3, the ErrorManager.cpp objects: split both out.**
  - The mode object (0x4059D0, its data, gaModeTable at **6** entries) and the NT-service object (0x406410, 0x406650, 0x406340, 0x406470, 0x4065E0, with their data 0x706584-0x706617) belong to Game.exe's own main module, not Fog.
  - Make them two placeholders, `Source/D2Launch/Unknown_004059D0.cpp` and `Source/D2Launch/Unknown_00406410.cpp`, on one branch. Bring the strays from Storm's placeholders and MainMenus.cpp with them.
  - After the merge they are lane 6's, as is the question of where WinMain (0x4066E0) and MAINMENUS_InitStorm (0x406870) belong.
  - ErrorManager.cpp keeps the rest, from gaszLanguageNames (0x706618) on.
- **Lane 5, the per-act quest data: one block per act is fine as a start, then split it by readers.** The copy at the head of a block starts the object of the first code file in that run (a4q1.cpp for 0x73D52C, the act 1 intro file for 0x7361A0). For the tables after it, use the evidence rules: a table read only by one quest file's functions goes to that file, provided its place in the data run follows that file's place in the code order (a4q1..a4q3, a3q0..a3q7). Tables read from several files, or from none, stay with the block. Make a data-only placeholder (`Unknown_<address>.cpp`) only where a table's order breaks the code order. Act 5 follows the same rule: its copy at 0x732FB0 goes to the file whose code starts at 0x586B50, so ACT5Intro_Callback00 leaves a1q4.cpp for its own file.
- **Lane 5, follow-up on the quest data: keep each act's block whole; don't split it.** Your alignment argument settles it. An object holding 8-aligned data starts 8-aligned, so a table at 4 mod 8 can't open a new object. Tables sitting out of their files' code order (a2q4's indices, gnArcaneThingObjectIds) can't open one either. That's evidence the act's tables are one object. Splitting only the clean cases would leave a mix the layout doesn't support. Act 5 as Unknown_00586B50.cpp (0x586B50, 0x586C40, 0x586C50, with the copy and the block) is right.
- **Lane 10, prefixfix for the renderers: give inferred names the file prefix** (GLCORE_, D3DSPRITE_, D2SOUNDSMP_…), the same rule as every other module. A module prefix in a file with its own stem says nothing more about the original than the file prefix does, and one rule is easier to check. Change `inferred` names only: blizzard, library and d2moo names keep their spelling. If a renderer file is a placeholder (`Unknown_<address>.cpp`), leave its names as they are, since there's no stem to take.
- **Lane 5, a data marker for static symbols: yes, write it, on its own branch (`lane5/static-data-marker`).** That's the real cause of the held copies. link_exe.py places an object's data sections only from anchors: relocations from placed code, or data-plan markers, which match external (cls 2) symbols only. A no-data object's static `gaszLanguageNames` has neither, so its section isn't placed and the bytes are borrowed. The rules:
  - Parse `// build: symbol <name> 0xVA` lines in the unit for data symbols of class 2 or 3, and add them as anchors the same way `data_markers` does. It's an address hint only: the bytes still have to match.
  - A marker that disagrees with a relocation-derived anchor for the same section is a problem: count it and fail.
  - First commit: the tool change alone. A full verify must show Game.exe identical and borrowed data unchanged (1,048 B). Then put the copies on top, each with its own marker. The borrowed data figure must fall by the copies' bytes, and copiedcmp shows no new runs.
- **Lane 3, the main-module run and Main.cpp:**
  - **0x405A50-0x405C30** (the two Nops, WriteSurveyLocale, GameStart): move them into the mode object's file, `Unknown_004059D0.cpp`. Code between two objects goes with the one before it unless something says otherwise. A data-less object in between is possible, but nothing shows one.
  - **Main.cpp:** SelectModule's allocations name `.\Main.cpp`, and that's a Blizzard file name, so the NT-service object is `Source/D2Launch/Main.cpp`. Rename `Unknown_00406410.cpp` and give the names.csv entries the MAIN_ prefix as blizzard-file evidence.
  - **The mode object:** name it only from its own evidence. If the asserts at lines 307-308 print a file string, use that. If that string is also `.\Main.cpp`, don't merge the two: each has its own language copy (0x706518, 0x706584), and a copy starts a separate object. Say so in your board file and we'll decide then.
  - After the merge both files belong to lane 6, as before.
- **Lane 2, new work (your clear-evidence list is done; thanks for the pMonPropTxt retest).** `exception-pointers` merged in #359. Next, in this order:
  1. **The context-copy trim, outside Storm/Fog/SRP.** Lane 3's `ctx-trim` (#346) took its range from 345 copies to 220. 219 are left, mostly elsewhere: D2Game 105 (36 files), D2Client 45 (11), D2Common 26 (19), D2BNClient 10, D2CMP 7, D2Lang 4, D2Multi 3, and 2 each in D2Win, D2Glide, D2Gdi and D2DDraw.
     - **Method:** for each `// build: context` block, delete it and build its unit. Keep the deletion only if the unit stays all equal. Restore the file before the next test.
     - **Branches:** one per module (`lane2/ctx-trim-d2game` …), each with a full verify. Deletions only, no other edits. Owners: name your branch in their board file, and they rebase around it.
  2. **Address-named records used by a single unit.** Name them where the unit's code gives clear evidence: field use, a .txt column, an assert string. These sit in other lanes' files, so post each batch in the owner's board file before you push.
- **Lane 2, where to post the single-unit name batches:** your own file's "Notes for other lanes" is right, since each lane writes only its own file. Owners: read lane 2's "Notes for other lanes" before you rebase. A name there that you disagree with goes in your own file, and lane 2 drops it from the next batch.
- **Lane 7:**
  - **0x677880's join is on main:** #332, where OutPlace.cpp took in Unknown_00675600.cpp. Try the function in OutPlace.cpp now.
  - **0x679C80:** do the Unknown_006793E0 + Unknown_00679A60 join yourself, on your `lane7/` branch, once lane 6's path stack is in (it is, #327). Tell lane 8 in your board file. A join that unblocks a borrowed function doesn't wait for the owner.
  - **0x4F8B80 in Window.cpp:** yes, as you said.
- **Lane 9:**
  - **D2Gdi: join Unknown_006C8250 into gdiCore.cpp.** The shared file static says it's one object.
  - **D2Hell (a): yes.** Set every D2Hell unit to `/O1`; the two list constructors keep `/O2`. That's a module default, as the outside review asked for.
  - **D2Hell (b): yes.** Join the three units that read gpszModuleName.
  - **DrawQuad (0x6B63F0) without a return on its normal path: keep it.** 0x6B7090 returns whatever DrawQuad leaves in eax, so the original's DrawQuad was declared to return a value and fell off the end on one path. A missing return (C4715) is ordinary source that compiles to the same bytes, not a forcing construct. Add a one-line comment at the closing brace saying the normal path has no return statement, as in the original.
  - **Renderer-run functions filed in other lanes' files: yes, take them** (QServer.cpp's five d3d getters, D2Win's Unknown_006B1BC0.cpp, D2Client's Unknown_006B2F40.cpp). A function belongs to the lane whose range it sits in. Tell lanes 3, 6 and 4 in your board file.

## Held back

| Branch / commit | Why | What it needs |
|---|---|---|
| `lane1/join-gethitsounds` | 0x4CA560 MISMATCH in UnitSnd.cpp on main | waits until UnitSnd.cpp's headers settle |
| lane 5's `aigeneral-copy`, `missiles-copy`, `monstermsg`, `game-copies`, `copies-runs-b`, `skill-ai-copies` | raised borrowed data (no anchor for a header copy) | superseded by #354's static data marker; drop or repost |

Older rows (all superseded by later versions that merged, #294-#336) are gone; the merge log has them.

## Decisions in force

- **Evidence order for placements:** an assert path settles it; a `blizzard` name can outweigh adjacency; an `inferred` or `d2moo` name loses to the address run; if both are weak, leave it and list it.
- **Records:** the game configuration record is `D2ConfigStrc` (lane 2 renaming), one client global `gpClientConfig` in D2Client.h; the callback table at 0x225 is one record.
- **zlib:** units named after their zlib 1.2.8 files under `Source/Storm/zlib/` (lane 3).
- **Id headers:** only D2StatIds.h is `#define`s; the other six stay enums until a function needs otherwise.
- **D2ClientNotifyStrc stays a view** of D2ComInterfaceStrc for now. Don't force the merge: the inv_0048BC10/inv_0048DD90 operand order says those units' original headers differ from ours in a way we can't see yet. Lane 4 retries when those units change for other reasons.
- **Pathfinding cluster 0x00678B10-0x0067BE00 (lane 6):** the strays filed in Skills.cpp and Drlg.cpp move out either way. To choose between one placeholder and several, test the shared data block 0x006F1798-0x006F1D9C. Split it by which functions read each part. If it divides into consecutive pieces, each read by a consecutive group of functions, make one placeholder per group: one object's data is contiguous, so a clean partition marks file boundaries. If the readers cross the whole block, make one placeholder, `Unknown_006793E0.cpp`. Either way, names stay placeholders: there's no assert and the names are d2moo.
- **Language-name table (from lane 4):** the 15-entry table of language-name pointers is a header-level static array, so each object file that includes the header gets one copy. 308 copies are in .data. This is placement evidence: **a planned file holding N copies spans N original units**, and a copy marks where a unit's data starts. It sits next to the assert-path rule; it beats adjacency and names. Lane 2: find the header (Fog's ErrorManager.cpp reads its copy as `gaszLanguageNames`) and define the table there once, as `static`. Then each lane turns the copies in its own files into that include, unit by unit. Only units whose original had a copy may include it: a unit that gains a copy the image doesn't have breaks the build.
- **Shared const tables (from lane 6):** a namespace-scope `const` table has internal linkage in C++, so two functions that read the same one were in one file, unless the table is declared extern. Ignore pooled strings, floating-point constants and selectany GUIDs. This ranks with the language-table rule.
- **Real Windows headers (tested 2026-11-24 by the coordinator; not adopted for now).** The VC 8.0 and Platform SDK headers come out of the cached VS2005 disc (1,174 files). Adding `#include <windows.h>` to a unit means dropping the hand-written declarations it clashes with, and renaming our struct `Rectangle`, which clashes with GDI's function.
  - **Robust units stay equal.** Item.cpp: all 82 functions.
  - **Every declaration-sensitive function flips.** inv_0048DD90 0x48DD90 and useitem 0x4BFDD0 differ in exactly the commutative operand order lane 2 saw (`lea edi,[ecx+edx-0x3f]` versus `[edx+ecx-0x3f]`, 4 bytes), whether windows.h comes first or after the project headers.
  - **Reading:** these functions depend on the compiler's symbol-table state (how many and which identifiers precede them), not on any particular declaration. The real headers alone don't fix that.
  - **DirectX:** the VS2005 disc has windows.h, winsock2.h, mmsystem.h, dbghelp.h, imagehlp.h, wininet.h and the C runtime headers, but no DirectX headers (ddraw.h, d3d.h, dsound.h). Real headers for the renderers and D2Sound would also need a DirectX SDK.
  - **Consequence:** the declaration and rename work goes ahead on our own headers. Adopting windows.h later means re-checking every sensitive function, which is a per-module project, not a global switch.
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

**Unattended variant search (new, run by the coordinator).** Running: 0x55A6D0 (lane 7's template, 12 groups; start 2,239 / 2,253 B). For a function that's close (calls and stack match, registers differ), give me a template and I run it overnight on spare CPU. The search tries every alternative of each marked group, keeps what helps, repeats, then restarts from random points. It scores each try by differing listing lines plus length difference, and rejects any variant that breaks another function in the unit. The best variant goes on this board.
- **Template:** the whole unit source on current main, with the function marked `// 0x<VA>`, and alternatives written `<<{as now<<ALT>>variant 1<<ALT>>variant 2}>>`. Good groups: declaration order and type (`const int`/`int`), the order of first use, one local versus two, `a < b + k` versus `a - b < k`, `if`/`else` versus `?:`, reading a global into a local or not, and condition order.
- **How to submit:** put it on coord at `lanes/vsearch/<va>.cpp` with one line in your board file (unit path, and what each group tries). Templates are not merged into main.
- **0x4A4AD0, first run done** (210 variants, 9 groups): the best variant (`gaPressed[0] || bInList`) is 1,210 / 1,232 B; nothing in that space matches.
  - **What the listing says (lane 1):** the original gives ebx to **bPageDown**, the sixth flag (result of 0x4A49A0, also spilled to [ebp-0x1c]). It keeps nY in ebx until that call, and spills bInList like the other four. Ours gives ebx to bInList.
  - So in the original source bPageDown is probably used more than bInList. Look for one more read of bPageDown (say in the page-down block's condition, or the final checks), and for bInList being read once only (the second block testing `gaPressed[0]` first, or calling the hit test again).
  - Send me a template around those uses and I'll run it.

A match goes into its file in address order: record it in units.json and as `verified` in functions.json, delete its stand-in in Source/StandIns/, and post it as usual. No forcing constructs.

**Freeze lifted:** `config-record-3` is on main (#296). The record is `D2ConfigStrc`, the 0x7A0438 global is `gpClientConfig` in D2Client.h. Rebase before your next push.

### Lane 1
- **Ownership grows (see Ownership):** D2Client from 0x4A0000 up is now yours. Take lane 4's handover list once it's posted.
- On main: `hdr-4df6c0-2` #302, `one-screenheight-r` #308, `unitsnd-table` #311, `skills-placeholders` #315, `keycfg-extras` #319, `monster-4aff60-2` #322. Keeping the one private declaration in inv_004886C0.cpp is right; the declaration-count finding is now in Lane 2's notes too.
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
- `party-row`, `msg-record`, `save-header` and `lang-names` are in #310; `quest-timer` and `shared-copies` in #313; `fog-records` #316; `game-timer`, `records-a` #318; `fog-records-b` #319; `cmp-records-2` #321. D2LanguageNames.h is on main: lanes can now include it where a unit's original had a copy.
- Language-name table: yours to start (see Decisions). Lane 5 reports copies at the ends of AiThink.cpp (twice: so it spans two original units), a3q7.cpp and MonsterChoose.cpp.
- `sets-txt` is in #306.
- `com-interface` is in #301. The conflict with #299 (Unknown_0043A9D0.cpp folded into CharSel.cpp) was resolved by carrying the type rename into CharSel.cpp.
- D2ClientNotifyStrc: keep it as a view (see Decisions). Thanks for the 60 tries; that's enough evidence to stop.
- From lane 1: some functions change register choice with the **number** of struct definitions in the unit, not their names (0x4CA560 in UnitSnd.cpp matches with +2..+4 dummy structs, not +1 or +5..+8; the enum-size finding was probably the same effect; deleting three unused forward declarations in Item.cpp breaks 0x4C3760). Worth knowing before dropping private record copies or forward declarations in bulk.

### Lane 3
- On main: zlib #297; trees-data, crt-init #302; crt-locks #303; data-fixes #305; fog-strays, cpu-report #307; storm-strays, sfile-dtors #309; text-data #311; sstr-strays, sevt-strays #313; sbig-names #315; sbig-exports #317; sbig-arrays #318; sbig-copy, crypt #319; scomp-strays, sfile-destroy, sevt-deletenode #321.
- **SUNI.CPP: yes.** **AUTOMAP_ReadTimeStampCounter to ErrorManager.cpp: yes.** **D2StormBigBuffer.h / D2StormArrayA.h edits: approved.** (Answers from earlier, kept here.)
- **0x6BD230 is now lane 7's** (lanes 7-10 are in effect). Pass your notes on the unused slot to lane 7.
- **Already on main (your list said still waiting):** `suni` and `ssig-window` #323, `system-strays` #322, `atl-data` #326, `lang-00404f40` and `sfile-unlinkall` #327. `sfile-openpath-2` goes in the next round.
- **`inline` for the UnlinkAll members: fine.** They are TSList<T> template members, which are implicitly inline; it isn't a forcing construct.
- **D2Launch's entry object (`sub_0042E590_SetOwner` and partner):** put it in a D2Launch placeholder, `Source/D2Launch/Unknown_0042E590.cpp`, by its run. The fixes are yours: its language-table copy at 0x708930 (now held by trees.c) moves with it, and `gaTable_0070896C` shrinks to its 4 B. It's one branch, and lane 6 has been told.
- **The copies that start CUnit.cpp (lane 1) and Items.cpp (lane 5):** yes, move their records, as plan-only changes. Tell those lanes in your board file.
- ErrorManager.cpp: leaving it parked is right. Say which objects you mean and whose module they are, and I'll settle it.
- **New lead, from the coordinator's 728 B (the largest borrowed-data block left): an ATL object.** 0x6B1A00 is `Define_the_symbol__ATL_MIXED::Thank_you::Thank_you()`, which ATL's atldef.h emits. That function and its neighbours 0x6B1A10-0x6B1B60 (Storm/Unknown_006B1A00.cpp, _006B1A10, _006B1A20, _006B1A30, _006B1A70, _006B1A90) are one object that included ATL.
  - Its .rdata is the borrowed block at 0x6FAD20-0x6FAFF8, right after libcmt's: the ATL registrar's header data (statreg.h). That is the key names "TypeLib", "SYSTEM", "SECURITY", "SAM", "Mime", "Hardware", "Interface", "FileType", "Component Categories", "CLSID" and "AppID"; the keywords "Delete", "NoRemove", "ForceRemove" and "Val"; the never-delete pointer table; and the registrar GUIDs.
  - Proposal: gather 0x6B1A00-0x6B1B60 into one placeholder and define that data in it, in the order the image has it. The toolchain has no atlmfc headers, so write the declarations yourself, modelled on ATL 8.0's statreg.h and atldef.h (`__declspec(selectany)` where ATL uses it).
  - This is yours by directory. It isn't Storm code, though: if the object's callers say which module it belongs to, file it there and tell that lane.

### Lane 4
- **Ownership narrows (see Ownership):** you keep D2Client 0x440000-0x49FFFF. Post the handover list for 0x4A0000 and up, then focus on your range: Warden strays, Hireables, the weather block, 0x47C420, and the inv/chat/options language-table splits.
- `borrowed-b` and `initializers` are in #311; `warden-strays-2` and `init-more` in #313; `questlog` #316; `winmain-split` #319; `levelup-split`, `inv-split` #321; `levelevents` #322.
- `options-split-2` and `keyconfig-split` are in #317. Thanks for doing the key-config split.
- Fast-forwarding a new commit onto an already-posted branch (questlog) is fine, as long as the old commits stay and the ready line names the new head. The new-name rule is for rewritten history.
- **WINMAIN.CPP split (your question): yes, both.** The language-table copies are the evidence, and they're strong.
  - Move 0x44B400-0x44B430 (InitInterface, ShutdownInterface, RunLauncher) to `Source/D2Client/Unknown_0044B400.cpp`.
  - Move the MCP packet run 0x44A170-0x44B3xx, with `gpfnConnectPacketHandlers` and its data, to `Source/D2MCPClient/Unknown_0044A170.cpp`. It follows `.\Src\McpConnect.cpp` and a data-less object, so it belongs to the D2MCPClient module. You know the code, so you do the move, on one branch. After it merges, the file is lane 6's; lane 6, take note.
- **The text-area object map:** good work, and it's now the basis for lane 1's 0x4A4AD0 attempt. Please split the unnamed object 0x4A41xx-0x4A61A0 out of text.cpp into a placeholder (it's your file), and tell lane 1 when it's pushed.
- From lane 3: 0x700140-0x7001C0 (listed as lane 3's in borrowed-data.md) is WardenClient's RTTI (object locator, class hierarchy, base class descriptors). It belongs with WardenClient.cpp's `??_R0` line; take it.
- `place-c` is in #299, `runs-sub-2` in #304; `game-borrowed` is in #305; `warden-class` is in #307. Reading the vtable through its object locator is the right way to settle a class.
- **UIWidget slots (your question): yes.** The vtable at 0x6DA6C0 is twelve `_purecall`s, so slots 1-11 are pure virtuals of the base, and ListBoxImplementation and ListBoxWrapper override them. Give each slot one name in all three classes, with its names.csv rows. Name a slot by what the two overrides have in common. Where one of the two current names is a `blizzard` name, keep that one. The char[260] and literal-string fixes in `game-borrowed`: good, push when verified.
- From lane 3: most of `Storm/Unknown_006C9A68.cpp`, `Unknown_006CACE0.cpp`, `Unknown_006CAA30.cpp` and `Unknown_006CAE80.cpp` are D2Client dynamic initializers (text buffers, layout rects, hashes of "Header"/"Game Time", captions). They belong with the globals they set, in your files and lane 1's. Wait for crt-locks (j66), then take the ones whose globals you own.
- Borrowed data: gszServerIP (WINMAIN.CPP) and gszMcpIP (Game_0044D080.cpp) are planned as char[16], and each is followed by 244 zero bytes copied from the image: 16 + 244 = 260. Check whether they are char[260]. More in borrowed-data.md.
- `chat-run-2` is in #294.
- SkillDesc.cpp and SkillDesc_004E1FF0.cpp call 0x4DF6C0 as `sub_004DF6C0`; it is `GFXUTIL_ApplySoundEnviron` now (in lane 1's sound unit). Rename the two calls.
- Leave `sub_00436E90_AlwaysOne` and `sub_00436EA0`: they moved to lane 6's `Unknown_004370B0.cpp` in #294.

### Lane 5
- `a3q5-orb` is in #298, `a3q7-dogs` in #299, `a3q2-run` in #300; `intro-q0` and `game-defaults` are in #302; `small-strays` is in #304; `monsterchoose` #305, `prime-nova` #307, `task-locks` #309, `unit-init-seed-2`/`coord-init` #314, `lang-owners` #318, `lang-split` #319, `lang-split-2` #321, `lang-pad` #322.
- **0x731EB8 gnUnitInitSeed (your question):** same answer as the Task.cpp locks. Take the initializer 0x6CAF60 out of Storm/Unknown_006CAE80.cpp into the file that owns the global.
- 0x745580 (0x11B plus a language list, between Inventory.cpp and ItemMode.cpp data): leaving it is right. Lane 6, it's at your edge.
- **Task.cpp locks (your question): yes, from your lane.** Delete the four functions from Storm/Unknown_006CAE80.cpp, Storm/Unknown_006CAF90.cpp, Storm/Unknown_006CB4A0.cpp and Bnclient/Unknown_006CB420.cpp, and move their units.json entries. A function goes to the file that owns it, whatever placeholder it sits in today. Lanes 3 and 6: leave those four alone.
- Language-name copies at the end of D2Game files: see the Decisions rule. Lane 2 has the header question.
- **0x007415F4 (your question):** you're right, nothing reads it. My first map counted references up to 8 bytes before a block, so a reference to the end of gpDiamondMonsterFormation was credited to it. That slack is gone. The block holds 4-char codes plus a pointer table into them (0x7416A0-0x741734), and nothing references that table either. Place it by its neighbours, or leave it if neither side's content fits.
- GAME_GetGamesCount twice (0x0052BFE0 in D2Net.cpp, 0x0052DB30 in Game.cpp): leaving it is right.
- From lane 3 (done in #309/#314): the initializer and destructor 0x6CAF70/0x6CB490 for lock 0x88CAA8 belong in D2Game Task.cpp. The array of 32 locks at 0x88C7A8 (0x6CAF90/0x6CB4A0, built with the CRT array constructor) sits in D2Game's bss; find which file uses it and take it if it's yours.
- `a5q2-run` and `a4q3-a3q6` are in #294; `a1q6-npc` (#292) and `a1q4-run` (#293) before that.
- 0x5B9A30 and 0x5947E0: listing them is right; no forcing constructs.

### Lane 6
- From lane 3: D2Launch's small entry object (0x42E590 and its no-op partner, filed in a Storm placeholder) goes to `Source/D2Launch/Unknown_0042E590.cpp`, with its language-table copy and a corrected record. Lane 3 does it on one branch, then it's yours.
- Lanes 8 and 9 have started: D2Common is lane 8's and the renderers plus D2Hell are lane 9's. Finish your branches in flight there, then post the handover lists.
- `data-b` is in #309: borrowed data fell to 6,376 B in that round.
- **Language-table runs as an object count:** yes, go ahead. A run of back-to-back copies with no other data counts objects in link order, so match the copies to code files in order. Two cautions. First, a file that includes the header twice through different paths still gets one copy, because it's one static per translation unit; Ignorelist.cpp's two copies therefore mean two units. Second, objects that define no initialized data of their own still get a copy. A gData_ block holding N copies is N files' data: split it before you place anything.
- D2MCPClient: lane 4 is moving the MCP packet run out of WINMAIN.CPP into `Source/D2MCPClient/Unknown_0044A170.cpp`. It becomes yours once merged.
- `seg-a` is in #316. The const-table rule is now in Decisions. Leaving 0x00648020 and 0x0043B080 is right.
- `cands-d` is in #299, `bss-a` in #302; `bss-a-2` and `path-a-2` #304; `lang-a-2` #315; `seg-a` #316; `sound-a-2`, `glcore-a`, `pathmisc-a` #319; `codec-a` #321. The path split by data reader is the right call.
- From lane 3: the dynamic initializers and atexit destructors of long-lived critical sections go into the file that owns the lock. `lane3/crt-locks` shows the pattern: a `CCritSect` type plus the `// build: symbol ??__E…`/`??__F…` lines. Yours: 0x6CAE80/0x6CB420 lock 0x881860 and 0x6CAED0/0x6CB470 lock 0x881F64 (BnDownload.cpp); 0x6CAEA0/0x6CB440 lock 0x881894 (CACHE.CPP); 0x6CB010/0x6CB4E0 lock 0x96D610 (Preset.cpp). Wait for crt-locks to merge (j66) and build on its type. CharSel.cpp taking sub_0043B830/0x43B840 from Game.cpp is fine: the run and the globals settle it.
- Pathfinding cluster: answered in Decisions. DUNGEON_ 0x00643260-0x00643560, the D2DDraw renderer, and Items.cpp 0x006313E0: leaving them is right.
- Borrowed data: you have the largest share, 7,361 B. 5,127 B of it is one block at 0x007420D1 between CelCmp.cpp and Unknown_006056D0.cpp: four small-int tables that no code addresses directly. See borrowed-data.md.
- `d2win-a` and `block-c` are in #294.

### Lane 7
- Not started. 296 B of borrowed data (0x006F13F0) goes when 0x00677880 is written.

### Lanes 7-10
- **Lane 7:** 0x55A6D0's search tried 170 variants and none beat the starting point (2,239 / 2,253 B). That template's alternatives don't reach the difference: send one built around what the listing shows. **0x677880's join is in #332** (OutPlace.cpp took in Unknown_00675600.cpp), so that function can now be tried in its file.
- **Lane 8, lane 9:** handover lists from lane 6 are coming. Start with the language-table rows for your modules.
- **Lane 10: you now apply names yourself** (see "How rounds work now"). That needs the build setup from COMMON.md §1: Wine, the compiler, `tools/setup.py --game`, and the user's Game.exe; ask the user for it. Copy `tools-lane10/` from the coord branch to `/home/claude/tools-lane10/`.
  - **A naming plan:** `prepnames.sh <plan.tsv> <plan.json>`, which drops alternative spellings that are other functions or file names. Then `python3 nameround.py <repo> <plan.json>`, which applies the plan, builds every touched unit and every includer, drops the addresses whose units fail, and repeats until everything builds equal. Then commit, run `precheck.sh`, and run the full verify `vbuild.sh`.
    - **Run the full verify every time.** The coordinator's rank-1 attempt passed every unit build but left 16 functions unplaced (NO_SYMBOL) in the full link, so it was dropped. A rename can change a symbol the linker matches by name, such as a `// build: symbol` line or an `extern "C"` name. rank1 is yours to retry: find the 16 with the full verify and exclude them.
    - **Post `lane10/names-<scope>`.**
  - **The call-site sweep:** `SWEEP_ROOT=<repo> python3 sweep.py <name> <Module,...>` renames old `sub_` spellings of already-named functions and drops the ones whose units fail. #334 did the small modules. D2Common, D2Game and D2Client are left: about 985 spellings of 846 functions. `DEDUPE=1` also cuts duplicate prototypes, but it made the first run worse; the prototype report (queue item 3) is the better route.
  - **Order:**
    1. The waiting plans, one branch each: rank1 (retry), d2cmp, d2common, d2game, the d2client ones, moved333, stragglers. Members goes last, alone.
    2. The sweep for D2Common, D2Game and D2Client.
    3. The queue below.
- **Lane 10: your queue, in order.** Work down it without waiting for answers. Plans already posted don't need re-checking at every check-in; I re-check them when I apply them. Take each item as soon as the one before it is posted.
  1. **Global variables with an address in their name: about 1,536** (`gnGlobal_007A285C`, `gData_00731018`, …). Brief: [names-globals-brief.md](names-globals-brief.md), with the same plan format plus a type-prefix column. One plan per module: `globals-<module>.tsv`. Start with D2Game, D2Common and D2Client (by area).
  2. **Inferred names whose prefix fits neither their file nor any sourced name in it: about 430**, many of them stale after a function moved (TEXT_ names in QuestLog.cpp, INV_TickSound in SoundHdr.cpp, GLIDE_FloorCacheRemove in glSmack.cpp). Re-plan them with the file's prefix: `prefixfix-<module>.tsv`, same format, with the old inferred name as old_name.
  3. **Prototype report for the call-site sweep** (no names, just data). 185 functions (list: [sweep-excluded.txt](sweep-excluded.txt)) didn't take their real name because some file declares them differently. For each, write the definition's prototype and every other declaration that differs, with file and line: `proto-report.tsv`, columns va, name, file, line, declaration, differs_in (return / params / calling convention / linkage / class member). I'll use it to fix the prototypes and rename in one step.
  4. **names.csv label audit:** rows marked `d2moo` whose name isn't in D2MOO (search /tmp/D2MOO), and rows marked `blizzard` with no export, symbol or diagnostic behind them. Write them to `labels-audit.tsv` (va, name, current source, proposed source, evidence).
  5. When those are done, take the **field names**: `f_<hex>` (about 3,900) and `unk0x` (about 2,100) members of the shared headers. Plan names from how the code uses each field: `fields-<header>.tsv` (header, struct, offset, old, new, confidence, reason). Lane 2 applies those.
- **Lane 10, answers:**
  - **rank1: yes.** A rank-1 unit is a piece of a named file (SoundInst_004B9B50.cpp is part of SoundInst.cpp), so its functions take that file's prefix. I'll apply rank1.tsv with the others.
  - **Class members: yes, plan them.** The tool renames the old token in place, so `BigBuffer::sub_004212D0_Get` becomes `BigBuffer::Get`. Put the bare member name in `new_name`, `Class::Member` in the reason, and post them as their own plan (`members-<scope>.tsv`). I'll apply member plans in separate rounds, because their symbol lines need the class. Template-list and per-type array members stay skipped, as you say.
  - **zlib and ATL names that are already in the source:** these are names.csv label fixes, and I'll do them. zlib's ~80 functions and the four ATL helpers get the library's own names as their source.
  - **Plans are applied one per round, separately from placement rounds:** storm (#329) is in. Next: fog, small, rank1, d2cmp, d2common, d2game, then the d2client ones and moved333. I'm also running a call-site sweep that renames old `sub_` spellings of already-named functions; it doesn't touch your plans' placeholders.
- **Lane 10:** storm-sfile and storm-rest are in naming round n1: 150 renames including other spellings, 4 of them names.csv only, since the source already used the name. Good plans; keep the format. Take the next scope.

## Merge log (newest first)

- #363 j118: strays-d, join-drlgwarp (lane 8), strays-6 (lane 5), export-vtables-2 (lane 4), npcmenu-strays-2 (lane 1), renderer-module-flags (lane 9), fog-shims (lane 3), ctx-trim-d2game-2, unit-names-a, unit-names-b (lane 2). Placeholders 397 -> 390, shims 73 -> 68, **context copies 114 -> 4**, borrowed data 880 -> 848 B.
- #362 j117: strays-c (lane 8), skill-runs, skill-runs-b (lane 5), copy-46c570 (lane 4), uiwidget-ctor (lane 1), gdi-stubs, hell-bnclient-pieces, join-glcore-8970 (lane 9), fog-unknown (lane 3), ctx-trim-d2client, ctx-trim-d2common, ctx-trim-rest (lane 2). Placeholders 400 -> 397, **context copies 219 -> 114**, borrowed data 898 -> 880 B.
- #361 j116: storm-bigbuffer-assign (lane 7), join-pathwf (lane 8), strays-3 (lane 5), mcp-startthread-2 (lane 6), roster-copy (lane 4), soundinst-strays-4 (lane 1), archive-list (lane 3). Placeholders 402 -> 400, borrowed data 906 -> 898 B. Held: join-drlgwarp (include audit).
- #360: names.csv labels for two Destroy members (inferred).
- #359 j115: place-r, place-s (lane 8), monskill-split-3 (lane 5), qserver-fields, smem-c (lane 3), exception-pointers (lane 2). Placeholders 403 -> 402, borrowed data 922 -> 906 B.
- #358 j114: 0062A370 (lane 7: ITEMS_GetSetItemsMask without volatile), place-n, place-o, place-p, place-q (lane 8), mcp-copies (lane 6), small-gaps, warden-4922a0 (lane 4), dialog-neighbours-2, dialog-tail (lane 1), main-cpp-3 (lane 3), text-box (lane 2), monskill-split-2 (lane 5). Placeholders 410 -> 403, forcing-construct functions 43 -> 42, borrowed data 975 -> 922 B.
- #357 j113: place-m (lane 8), itemmode-run-copies, skill-run-copies (lane 5), take-win-strays, renderer-tables (lane 9), sfile-lists (lane 3), small-records-j, small-records-k (lane 2), names-d2client-ui-2 (94), names-moved333-2 (50) (lane 10). Placeholders 414 -> 410, borrowed data 999 -> 975 B, placeholder names 3,208 -> 3,080.
- #356 j112: place-j, place-k, place-l (lane 8), run-joins (lane 5), data-strays, weather-object (lane 4), chatdlg-cancel (lane 6), storm-lists (lane 3), small-records-h, small-records-i (lane 2), names-members-slots (lane 10). Placeholders 419 -> 414, context copies 220 -> 219, borrowed data 1,041 -> 999 B.
- #355 j111: place-h (lane 8), winmain-main (lane 6), qserver-head-2 (lane 3), gamelist-strays-3 (lane 4), unicode-inits (lane 1), names-prefixfix-d2common/-d2net/-d2win/-fog (lane 10, 20 renames). Placeholders 422 -> 419, context copies 218 -> 220.
- #354 j110: static-data-marker (lane 5: link_exe.py .data anchors + 28 copies), place-g (lane 8), bnsend-empty (lane 6), session-object-5, level-events, party-object-2 (lane 4), names2 (lane 3), missile-data (lane 2), names-prefixfix-d2game/-d2gdi/-d2launch (lane 10, 60 renames). Placeholders 427 -> 422, borrowed data 1,048 -> 1,041 B.
- #353 j109: text-strays, waypoint-tail (lane 4), layout-init-2 (lane 1), celcmp-rtti (lane 6), excel-aliases, rtti-names, sbig-fields (lane 3), storm-bytearray (lane 2), names-prefixfix-d2ddraw/-d2direct3d/-d2multi/-d2sound (lane 10, 206 renames). Placeholders 428 -> 427, borrowed data 1,114 -> 1,048 B.
- #352 j108: join-roomtile (lane 8), itemaffix-split-2, copy-owners (lane 5), waypoint-strays, run-strays (lane 4), excel-links, em-split (lane 3), client-fields (lane 2), names-prefixfix-d2glide (118 renames), sweep-d2client (93 spellings) (lane 10). Placeholders 428 (3 joined, 3 split out); borrowed data 1,114 B.
- #351 j107: place-f (lane 8), charsel-fechar (lane 6), panel-strays-3, hireables-object-3 (lane 4), skillbar-join-2, monstermsg-2 (lane 5), unused-types (lane 3), more-fields (lane 2). Placeholders 434 -> 428, context copies 219 -> 218, borrowed data 1,123 -> 1,114 B.
- #350 j106: place-e (lane 8, already in), soundhdr-strays (lane 4), spellsel-strays-3, skilldesc-path (lane 1), strtable-mpqs (lane 6), drawquad-note, move-d3d-bink, take-renderer-strays (lane 9), qserver-names, log-nop (lane 3), sweep-d2game (lane 10, 80 spellings). Placeholders 436 -> 434, borrowed data 1,166 -> 1,123 B. Held: gamelist-strays-2 (+16 B borrowed at 0x7088D8).
- #349 j105: place-e (lane 8), rosterpets-object (lane 4), chatdlg-pieces-2 (lane 6), srp-ob1-2, logmanager-strays (lane 3), fog-fields, storm-bitoutput-2, small-records-g-6 (lane 2), names-members-sub (lane 10, 25 renames). Placeholders 440 -> 436, context copies 220 -> 219. Held: lane 5's game-copies, copies-runs-b, skill-ai-copies (+1,268 B borrowed data).
- #348 j104: place-d (lane 8), waypoint-object (lane 4), qsnt-client, qserver-views (lane 3), storm-arrays, storm-critsect (lane 2), names-stragglers (lane 10). Placeholders 442 -> 440. Held: lane 5's three language-copy branches (+192 B borrowed data). Rebase requested: seven branches.
- #347 j103: act5-intro (lane 5), lob-velocity, useitem-hotspots (lane 1), mainmenus-object-2 (lane 6), join-d3dcore-2, join-gdicore-8250, d2hell-o1 (lane 9), bitmanip-clean, standin-types (lane 3), strays-b (lane 8), storm-hash (lane 2), names-d2client-game, names-d2client-units (lane 10; 98 renames). Placeholders 447 -> 442, borrowed data 1,175 -> 1,166 B, placeholder names 3,382 -> 3,288. Held for rebase: storm-bitoutput (compile clash with standin-types), small-records-g-4, gamelist-strays, names-d2client-ui.
- #346 j102: act1-data, act2-data, act34-data (lane 5), necama-copies-2 (lane 1), cursor-object, copy-shift (lane 4), ctx-trim (lane 3), strays-a (lane 8), storm-array, split-text-3 (lane 2), names-d2common, names-d2game (lane 10; 77 renames). Placeholders 451 -> 447, shims 78 -> 73, context copies 345 -> 220, placeholder names 3,455 -> 3,382.
- #345 j101: act1-intro-data (lane 5), spellsel-data, roster-run (lane 4), charsel-tail-2 (lane 6), link-member-names (lane 3), header-fields, mcp-fields (lane 2), names-d2cmp (lane 10, 18 renames). Placeholders 448 -> 451 (three objects split out); placeholder names 3,470 -> 3,455.
- #344 j100: place-ddcore-10160 (lane 9), itemmode-copy (lane 5), wall2-copies (lane 1), sound-environ, small-records-f-3 (lane 2), names-rank1 (lane 10, 106 renames). Placeholders 449 -> 448; placeholder names 3,562 -> 3,470. Rebase requested: strays-a, split-text-2, small-records-g-3.
- #343 j99: fog-em-nops (lane 3), lang-copies (lane 6), join-missile-3, join-missile-4 (lane 8), keycfg-handover-2 (lane 1). Placeholders 450 -> 449.
- #342 j98: net-copies, launch-copies-2 (lane 6); plrmodes-copy, missmode-join-2 (lane 5); scomp-flush-2 (lane 3); place-c, join-missile, join-missile-2 (lane 8); lang-include, winmain-object-2 (lane 4). Placeholders 453 -> 450, context copies 346 -> 345. Rebase requested: lane 2's split-text, small-records-f-2, small-records-g-2.

- #341 j97: lane 4's context sweep (481 → 346 copies), borrowed data −402 B, ItemMods/Skills/SEVT/d3dSprite joins, editbox split, two records.
- #340 j96: ChatDlg.cpp object, renderer joins, SERR/LogManager, Record.cpp, five records.
- #339: 87 small-module function names.
- #338 j95: zero runs join their records (−130 B), language-table cuts, gdiSmack, D2ClientDialogWidget.h, D2ProfileCounter.h.
- #337: 67 Fog function names (naming round).
- #336 j94: SFILE.CPP whole, zlib/uncompr.c, D2Win and d3dSprite joins, automap view object, language-table placements, three small records.
- #335: names.csv source `library` for 80 zlib and 3 ATL functions.
- #334: call sites use the real names of 124 functions (Storm, Fog, D2Lang, D2CMP, D2Win, smaller modules).
- #333 j93: eight borrowed outdoor copies defined (−550 B), quest data order, D2Sound and SMSG objects, popup line and quest log records, more language-table copies.
- #332 j92: OutPlace.cpp join (lane 7's 0x677880 prerequisite), ATL object into d3dCore.cpp, automap and chat objects, D2Launch entry object, act 4 tables, language-table copies, D2Win32System.h, D2PathFind.h, D2GameCallbackArgs.h. Shims 84, context copies 488.
- #331: names.csv labels: 186 ordinals are placeholders; 12 names on our own class names are inferred; 16 Storm template names are blizzard. README explains all four sources.
- #330 j91: MonUnique.cpp object, D2Win joins, act 4 tables, language-table starts, SCmd packet table, Fog log strays.
- #329 n1: 137 Storm function names (storm-sfile, storm-rest plans).
- #328 j90: skill-do-table (lane 5), sfile-openpath-2 (lane 3). `lane2/path-records` was not applied (conflict with #327's path regroup).
- #327 j89: view-chat-run (lane 4), unitmode-copy, casetable-to-d2lang-2 (lane 1), lang-00404f40, sfile-unlinkall (lane 3), one-copy-2, data-nonconst-2 (lane 5), path-d-2 (lane 6), multi-records, d3d-records, bn-messages (lane 2). Borrowed data 2,507 → 2,382 B.
- #326 j88: atl-data (lane 3, −728 B), fog-records-c (lane 2), path-b (lane 6), copies-start (lane 4), unit-strays (lane 1). Borrowed data 3,359 → 2,507 B.
- #325 j87: atl (lane 3), skilltree (lane 4), tails-a-2 (lane 6), dup-statics (lane 5), umod-names-copy (lane 1), mcp-packets (lane 2).
- #324: README graphics refreshed from #323; rounds now refresh them right after the verify.
- #323 j86: suni, ssig-window (lane 3), data-c (lane 6), lang-tails (lane 5), spellsel-join (lane 4).
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
