# Lane 13

Written by lane 13 only. Newest entries at the top of each section; delete what is done.

Lane 13 (started 2026-11-27, the user): every global the size and shape Blizzard's source had. (1) The short globals from tools/shortdata.py (lane10/short-data), unit/mode/animation/player-movement data first (the Shift-walk frame freeze). (2) The data clusters in LINK_DEBT.json: D2Win 0x00842710 and 0x0081EA68 first; 0x0096BC30-0x0096D66C last, with a reading posted here before any change. Branches are based on lane10/short-data until it is on main.

## Ready
- Fri Nov 27 10:52 PST 2026: **lane13/split-objects-2** (4dedc24a6, on main a42b4ed66 = #483). It replaces short-arrays-3: those five commits are rebased in, with the QuestLog.cpp conflict against lane 11's #483 names redone. VERIFIED tree e045fc0f34924403faed79fefab1779512a9d1e6; Game.exe identical. Audit guard: no count rose.
  - **Eleven new commits.** Each table here was declared too short, or read through a second name at a field or element offset; each now has its real object:
    - `gaNpcTabs` (gaNpcTabStates and gnTabEnabled0-3 were its fields), with D2PanelTabStrc in a new Source/Include/D2PanelTab.h.
    - `gaNpcEntries` (gaNpcEntryFlags was its bSelected and bFlag).
    - `gaSkillTextPositions[12]` (4 B, a 68 B run, two ints and a 64 B run before).
    - `gaCharTexts[15]` (gaTextEntries was it seen from wStringId).
    - `gaLayouts[9]` (gaWaypointRowRects was +0x10), with D2WaypointLayoutStrc in a new Source/Include/D2WaypointLayout.h.
    - D2Game `gpMonsterEventFunctions[16]` (gpfnMonsterEventCallbacks was slot 2). It's now a const table under its own name: as an alias its references counted as placeholder.
    - D2Glide `gaGlideAspectTexDims` indexed at nAspect + 3 (gatGlideAspectScale was +3 entries).
    - D2Common `gRoomExUnsetStatus[4]` (split 4 + 16 before; its 4 bytes of padding stay a run).
    - `gnWallTileTypeRemap[6][7]`, defined at 0x006EF578 (it sat in a run that started 4 bytes early).
    - `gaDrlgRoomTilePresetUnits[34]` (12 B + a 940 B run before).
  - **Counts, main #483 -> this:**
    - data clusters: 38 -> 14; 15,090 -> 7,511 B.
    - data_cluster: 2,436 / 324 -> 1,671 / 265.
    - linkdebt total: 25,066 -> 24,239. D2Client 8,729 -> 8,118, D2Game 5,303 -> 5,292, D2Common 3,723 -> 3,710, D2Launch 1,221 -> 1,185, D2Glide 358 -> 215, D2Hell 74 -> 61; no module rose.
    - shortdata: 358 -> 360. Two new candidates:
      - gaStateStack[4], with 4 unreferenced bytes after it;
      - gaDrlgRoomTilePresetUnits[34], with 20 unreferenced bytes after it, before gaWarpTileOffsets (no 35th record fits there).
## Claimed
- Fri Nov 27 11:34 PST 2026: check-in. Read your 10:15 note. split-objects-2 (posted 10:52) has the short-arrays-3 commits rebased onto #483 with QuestLog.cpp redone, so short-arrays-3 can be dropped. Now **lane13/split-objects-3** (on #484, includes split-objects-2) is doing its full build. Its 12 new commits close 12 of the 13 clusters left outside D2DataTablesStrc. Ready in about 15 minutes.
- Fri Nov 27 11:08 PST 2026: check-in. split-objects-2 Ready. **Data-tables cluster parked: findings under Questions** (CCritSect.h in D2DataTbls.h alone flips 6 units; the sub-table types are private to cpps). Released the data-tables claim. Next: the 13 other clusters.
- Fri Nov 27 10:52 PST 2026: check-in. split-objects-2 Ready; it replaces short-arrays-3. 14 clusters left. Next: **the D2DataTablesStrc cluster** (the go-ahead under Current state). Claimed: Source/Include/D2DataTbls.h, Source/D2Common/DATATBLS/*.cpp, and every file that declares a global in 0x0096BC30-0x0096D66C (35 files: D2Common DATATBLS, DRLG, DUNGEON, ENVIRONMENT, INVENTORY, Logging, SKILLS, Chat/Ignorelist.cpp, two Unknown_ files; D2CMP CelCmp.cpp).
  - **One finding before I build it.** Three objects in the 0x1A3C span have their own TU's symbols in the original:
    - gLevelFilesCriticalSection (0x0096D610, +0x19E0) is a CCritSect with its own dynamic initializer and atexit destructor (0x006CB010, 0x006CB4E0), in the initializer table between D2CMP's gCelListTable and gOptionList.
    - gLogLock (+0xE00) is Logging.cpp's critical section.
    - Inventory.cpp's static component table (+0x1038) is a static.
  - Yet code reads sgptDataTables-> fields past all three (pCubeMainTxt +0x19F8, pFieldData +0x1A24, pCollisionField +0x1A28). So I'll first make the CCritSect a struct member, which moves its initializer to gDataTables'. If the initializer table then doesn't come back equal, I'll post that and stop there.
- Fri Nov 27 10:07 PST 2026: check-in. short-arrays-3 still Ready. Next branch, **lane13/split-objects** (stacked on it), is doing its full build now. It closes ten more clusters, each a table that the sources read through a second name at a field or element offset: NPC tabs, NPC entries, skill text positions, character panel text, waypoint rows, monster event table, Glide aspect dims, room-ex unset status, wall-tile remap, room-tile preset units. Claimed: Source/Include/D2PanelTab.h, Source/Include/D2WaypointLayout.h (new), plus those tables' files. Lane 13 still owes a later branch typing gapChatDlgControls so the smack slot needs no cast (coordinator's #480 note).
- Fri Nov 27 09:32 PST 2026: check-in. Cleared data-round-4 and short-arrays-2. Both are now in short-arrays-3, rebased onto #482. Next: the remaining small clusters, one at a time.
- Fri Nov 27 09:15 PST 2026: check-in. short-arrays-2 Ready, stacked on data-round-4. Still no answer on the D2Common data-tables reading. 24 clusters left with both. The rest are aliases of one object under different types (D3D vertices, gatGamePalette, gapAutomapCels, gtLoadingTimer, gtPacket2A) or need the packet's real layout. Taking them one at a time next.
- Fri Nov 27 08:58 PST 2026: check-in. data-round-4 Ready. The D2Common data-tables reading under Questions has no answer yet, so I'm leaving that cluster alone. Next: the small clusters left on #480 (33 with data-round-4).
- Fri Nov 27 08:22 PST 2026: check-in. #480 merged chat-controls, client-tables, glide-tile-vertices and bss-defs, so data-round-2 is superseded. I'm rebasing what's left onto #480 as lane13/data-round-4: the gtQuestLog commit (QuestLog.cpp redone on #480's file), a new commit merging four objects with their alias globals (gtPongData, gaUIVarStates, gaGlideTexCaches, the D2Hell fault-handler lock), and the gszA1Q2SourceFile fix (it closes gaAncientBarbItems; it was ancient-equipment's second commit, which missed #477). Building now.
- Fri Nov 27 08:01 PST 2026: check-in. data-round-2 Ready: it replaces questlog, client-tables, glide-tile-vertices, bss-defs and chat-controls, all rebased onto #479 as you asked. The D2Common data-tables reading is posted under Questions and waiting for an answer. Next: the remaining small clusters on #479 (37 left).
- Fri Nov 27 07:01 PST 2026: check-in. client-tables and glide-tile-vertices Ready. Next: D2Game 0x008842A8 (1 global, 1,048 B), D2Common 0x006EF188, D2Direct3D 0x00971450, then the small ones; the D2CMP/D2Common reading after those.
- Fri Nov 27 06:11 PST 2026: questlog Ready. The QuestLog file claims are done. Next: the remaining small D2Client/D2Glide/D2Game clusters (0x00880678 D2Glide, 0x008842A8 D2Game, 0x00726850 and 0x00723F30 D2Client), then the D2CMP/D2Common reading.
- Fri Nov 27 05:28 PST 2026: **claim for the QuestLog struct** (0x007BF298-0x007C0269, one pack(1) struct of 0xFD1 bytes: state, flags, cels, two 42-byte quest-state arrays and 6 entries of 0x26A, the first byte of each entry being a flag). About 40 alias globals at those addresses become `gtQuestLog.<field>`. Files: Source/D2Client/UI/QuestLog.cpp, UI/text.cpp, UI/text_0049D5A0.cpp, UI/text_004A10E0.cpp, Unknown_004A43E0.cpp, Unknown_004A6460.cpp, D2Client.h, D2ClientFuncs.h, Source/Include/D2ClientQuestLog.h, D2ClientQuestText.h. Lane 11: if names-d2client touches these, I'll rebase onto it, not the other way round.
- Fri Nov 27 05:20 PST 2026: check-in. Cleared control-templates and ancient-equipment (#477). Ready: cluster-rule-2, chat-controls (on control-templates, now in #477). Working on the QuestLog struct 0x007BF298 (files claimed below).
- Fri Nov 27 05:03 PST 2026: chat-controls Ready. Next: D2Client QuestLog 0x007BF298 (packed struct, about 4 KB). Claimed: Source/D2Client/UI/QuestLog.cpp, Source/Include/D2ClientQuestText.h, Source/Include/D2ClientQuestLog.h.
- Fri Nov 27 04:48 PST 2026: cluster-rule-2 Ready; ancient-equipment updated (second commit). Next: D2Client QuestLog 0x007BF298-0x007C0274 (one packed struct of about 4 KB, which the sources split into about 20 globals at odd addresses, several of them aliases of 0x007BF298). Claimed: Source/D2Client/UI/QuestLog.cpp.
- Fri Nov 27 04:05 PST 2026: ancient-equipment Ready. Next: D2Game 0x00882D38 (gnGamesGUIDs, 3 globals) and D2Client 0x007BF298 (16 globals). Files claimed as I start each.
- Fri Nov 27 03:49 PST 2026: control-templates Ready. Next cluster: D2Game 0x006E1BB0-0x006E2CF0 (4,416 B, 35 globals), then 0x00882D38 (gnGamesGUIDs) and D2Client 0x007BF298. Files claimed as I start each.
- Fri Nov 27 03:29 PST 2026: cluster-rule Ready. Next: the 78 remaining clusters (real split structs and short arrays, constant reads past the end), largest first, leaving 0x0096BC30 for last with a reading first. Files claimed as I start each one. Then the raw-offsets lines that fall in data work.
- Fri Nov 27 02:59 PST 2026: renderer-tables Ready. Next: **link.py's cluster rule** (your 01:43 yes, with its four conditions). Files claimed: tools/link.py (and tools/linkdebt.py only if its report needs the new reason). After that: the raw-offsets lines that fall in my data work, then the rest of the short globals.
- Fri Nov 27 02:40 PST 2026: checked the remaining indexed short globals in the unit/mode/animation/player-movement files. Every index is bounded within its declared size, and the room after each is a literal, float constants, a vtable's RTTI pointer, or bytes no code reads. Checked: Units.cpp's mode modulator and stat tables, PlrModes, SUnit/SUnitDmg, ObjMode, Path, Composit, D2Client Player/CUnit/PlrSkills/Select/Missile. I found no other short array there. The Shift-walk freeze isn't explained by a short global yet; the monster moving-anim table in short-tables-1 is the one real anim-path overread so far.
- Fri Nov 27 02:28 PST 2026: short-tables-1 Ready. Next: the other unit/mode tables with an index-bounded run after them (D2Game MONSTER 0x0073C0B8 gpfnSrvUModCallbacks + 0x0073C578, D2Common Path 0x006EB398 + 0x006EB3D8), then the rest of the 341.
- Fri Nov 27 01:43:35 PST 2026: baselines on lane10/short-data 90dddc727: shortdata 342 candidates; linkdebt data_cluster 7,072 refs to 666 targets, 126 clusters (534,127 B, 701 globals). Next: the short globals (first branch: D2Launch CharSel's 0x7799FC row table, declared as a scalar `gnListTop_007799FC` where the code indexes 8 ints).
- Fri Nov 27 01:14:52 PST 2026: starting. Running tools/shortdata.py and tools/linkdebt.py on lane10/short-data for the baseline counts. Claimed: the short globals in D2Common UNITS, D2Client UNIT/GAME, D2Game PLAYER/MONSTER, and the D2Win clusters 0x00842710 and 0x0081EA68.

## Questions
- Fri Nov 27 11:08 PST 2026: **D2DataTablesStrc gDataTables: parked, findings for Fable.** No source changed; claim released.
  - **Blocker 1, the CCritSect member.** gLevelFilesCriticalSection (+0x19E0) has a ctor/dtor, so as a struct member D2DataTbls.h has to see CCritSect.h. I tried only adding `#include "CCritSect.h"` to D2DataTbls.h and compiled its 179 direct includers: 6 units stop matching (inv.cpp, inv_0048BC10.cpp, inv_0048DD90.cpp, UnitSnd.cpp, SUnitMsg.cpp, LvlTbls.cpp) and Preset.cpp no longer compiles. That is the declaration-count effect.
    - link_exe anchors each .CRT$XC* piece at its original slot, so moving the initializer into gDataTables's TU is not itself a problem.
  - **Blocker 2, the sub-tables.** These are reached by address (`&gItemDataTables`, returned by the getters), so they must stay members of their own types, not be flattened:
    - D2ItemDataTbl (three definitions: D2ItemDataTbl.h, MonsterTbls.cpp, Inventory.cpp);
    - D2GemDataTbl, D2ItemRatioDataTbl, D2MonModeDataTbl, D2ObjModeDataTbl, D2PlrModeDataTbl;
    - D2QualityItemDataTbl and D2RareAffixDataTbl (in D2Game.h);
    - D2LowQualityItemDataTbl (D2Game Unknown_005C0D00.cpp);
    - D2BookDataTbl.h (doesn't compile on its own);
    - D2MonItemPercentDataTbl, D2UniqueNameTablesStrc, D2HirelingTableGlobals (MonsterTbls.cpp);
    - D2AutomapIndexStrc (LvlTbls.cpp), D2InventoryComponentItemTypeStrc (Inventory.cpp), and Logging's D2CriticalSectionStrc.

    Each has to move into a shared header that D2DataTbls.h includes, which is lane 1's queue item 2, and each move risks the same flips as blocker 1.
  - **Smaller points.**
    - DrlgActivate.cpp defines the four room-stat ints at 0x0096C8B8 under three names each, as statics. Env.cpp and Dungeon.cpp define them again.
    - 0x0096D4B0 is int in one file and unsigned short in another.
    - The header's placeholders cover 97 of the globals: nSoundsTxtCodes[0x814], pTreasureClassEx[0xBC], pMonPresetTxt[0x2C], pMonSeqTxt[0x14], pExperienceTxt[0xC], unk0xC88/DC4/DD0/DEC/DF8/E30/E60/1018. None of those placeholder names is used, so splitting them is free.
  - **Field map.** For each of the 234 addresses it gives the header field or placeholder offset and every name and type declared there. It is in my workspace; I'll post it to the board if Fable wants it.
  - I'm moving on to the clusters outside it (D3D vertices, D2CMP cache, gtPacket2A and the small ones).
- Fri Nov 27 07:22 PST 2026: **reading of the D2CMP/D2Common cluster 0x0096BC30-0x0096D66C** (6,716 B, 231 globals, 1,384 refs). I haven't changed anything there.
  - **What it is.** It is one object: D2Common's static `D2DataTablesStrc`.
    - D2DataTbls.h checks `D2DataTablesStrc` at 0x1A3C bytes, which is exactly 6,716.
    - `sgptDataTables` (0x00744304) is initialised in Game.exe to 0x0096BC30, a pointer to it.
    - D2MOO has the same thing: a static `D2DataTablesStrc` and `sgptDataTables = &it`.
  - **How the sources reach it.** Most code reaches it as `sgptDataTables->field` (149 files). But the DATATBLS loaders, and a few others, reach its fields as separate globals. There are 284 names at those addresses, in 36 files including D2Common.h and Storm.h: gpPlayerClassTxt, gpHirelingTxt, gaAutomapIndex, gn*TxtRecordCount, gpUniqueNameTxtTables and the rest.
  - **What makes the cluster.** All 308 triggers are fields of the struct read through the first of those globals plus an offset. 122 distinct offsets come from `gpPlayerClassTxt` alone (DataTbls.cpp 84, ItemTbls 51, MonsterTbls 46, FieldTbls 27, MissileTbls 22, ...).
  - **Proposal.**
    - DataTbls.cpp defines `D2DataTablesStrc gDataTables; // 0x0096BC30` (bss), and the plan's `sgptDataTables` record points at it by name.
    - Every one of the 284 names becomes `gDataTables.<field>`, with D2DataTablesStrc's field at that offset; where a name has no field yet, I name the field after the global.
    - Their declarations go away, except in shared headers (D2Common.h, Storm.h) where removing a declaration changes other units' code (the declaration-count effect I hit in D2Client.h). Those stay, unused, and I list them in the Ready entry.
    - Byte-identical as always, and a full rebuild since D2Common.h's users are everywhere.
  - **Question:** go ahead with that, or would you rather reads go through `sgptDataTables->field` (what the rest of the code does)? The pointer reads change the bytes in the loaders, so to stay byte-identical it has to be the struct's own name in those functions. Your board says Fable for this one; tell me if lane 13 should leave it.
- Fri Nov 27 01:43:35 PST 2026: **reading of the two D2Win clusters, and a question on link.py's cluster rule.** Neither is a split object.
  - 0x00842710 (gabItemPalettes[9][0x6900] + gabEmblemColor1[12]) clusters on one reference: 0x5053A0's `mov al, [ecx + 0x87D80F]`. That is D2Comp.cpp's `gabEmblemColor1[nColor1 - 1]` (line 1813), with the compiler folding the -1 into the displacement (gabEmblemColor1 - 1).
  - 0x0081EA68 (gatShadowsLightGammaPalette[49] + gabLuminancePalette[65536]) clusters on 0x4FB010's `cmp eax, 0x821B68`. That is the loop end pointer of `for (i = 0; i < 49; ++i) ... gatShadowsLightGammaPalette[i]` (D2WinPalette.cpp line 80), i.e. gatShadowsLightGammaPalette + 49.
  - Both sources are already right. link.py's cluster_data takes every reference whose addend lies outside [0, size) as reaching into the neighbour. That includes a one-past-the-end address used as a value (a loop bound) and an `a[i - k]` displacement.
  - I logged every cluster trigger (1,370 references) and decoded each instruction. In 40 of the 126 clusters every trigger is one of three things: a one-past-end address used as a value (`cmp reg, imm` / `push imm` / `mov reg, imm`), an indexed access at a negative constant offset (`[reg + a - k]`), or an indexed access at exactly the end. Those 40 include the next four biggest: D2Direct3D 0x00971740 (65,540 B), D2Gfx 0x007CA320 (32,772 B), D2Client 0x007C0ED0 (17,804 B) and 0x007ACA50 (16,388 B). The other 86 have a constant read past the end (854 refs `[a + n]` with n >= size, no index), which are the real split structs and short arrays.
  - **Question:** may lane 13 change link.py's cluster rule so that (a) a one-past-end address used as an immediate value and (b) `[reg + a - k]` no longer make a cluster? Telling an immediate from a memory operand needs the instruction decoded at the relocation. My proposal: decode with capstone where it is installed, and keep today's behaviour where it isn't, so counts never get worse. If you'd rather keep link.py lane 10's, I'll hand lane 10 the trigger list instead (/tmp/clusterprobe.json here; I can post the script). Parked; I'm on the short globals meanwhile.
- Fri Nov 27 01:14:52 PST 2026: the brief says to read COMMON.md (build setup, §1, and the brief/disassembly tools), but there's no COMMON.md on coord, main or lane10/short-data. I'm using the build setup I already have and my own disassembler for now. If it's somewhere else, please point me to it.
