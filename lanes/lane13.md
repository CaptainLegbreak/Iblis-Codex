# Lane 13

Written by lane 13 only. Newest entries at the top of each section; delete what is done.

Lane 13 (started 2026-11-27, the user): every global the size and shape Blizzard's source had. (1) The short globals from tools/shortdata.py (lane10/short-data), unit/mode/animation/player-movement data first (the Shift-walk frame freeze). (2) The data clusters in LINK_DEBT.json: D2Win 0x00842710 and 0x0081EA68 first; 0x0096BC30-0x0096D66C last, with a reading posted here before any change. Branches are based on lane10/short-data until it is on main.

## Ready
- Fri Nov 27 07:01 PST 2026: **lane13/client-tables** (25c167bce, on main ac1dc8375). VERIFIED tree 4ce3bc0a6dcb65b469b656c272c7817e76ec11f3; Game.exe identical. Audit guard: no count rose. Two D2Client commits:
  - **gaQuestTable[41]** (QuestLog, 0x00723F30, 16 B each).
    - The plan had no record for it. Its first 8 bytes were unowned and the rest was the 648 B blob `gaQuestLookup_00723F38`.
    - Two more views read it 8 bytes in: `gaQuestLookup` (D2UiEntry10Strc: nKey, nId) and the lookup view (D2QuestLookupEntryStrc: nKey, nValue). Those fields are the table's nCondition and nQuestId.
    - It is now declared once, and QuestLog/text read `gaQuestTable[i].nCondition / .nQuestId`.
  - **The NPC tables (npcmenu):**
    - `gaNpcEntries[46]` (0x00726850, D2NpcEntryStrc of 22 B, then 4 zero bytes). It was a 21 B record plus a 995 B run.
    - `gaNpcIndex[48]` (0x00726C48, D2NpcIndexStrc of 39 B: id, line count, 5 string ids, 5 handlers, enabled). It was 67 records. About 40 of its fields were separate globals (gnGlobal_*, gwGlobal_*, gpfn*MenuHandler, gw*MenuStringId), plus a second view 4 bytes in (gaNpcMenuEntries). They now read `gaNpcIndex[i].nCount / .awIds[k] / .apfHandlers[k]`.
    - `NPCMENU_NpcMenuAction28` (0x004B5140) is now set by its own name instead of through a `void sub_004B5140` declaration.
  - **What I left alone:** D2Client.h keeps its 16 externs of the old field names, unused, because removing them changes other units' code. The local D2NpcMenuEntryStrc is gone. D2UiEntry10Strc and D2QuestLookupEntryStrc stay in their headers, now unused.
  - **Counts on main, before -> after:**
    - data clusters: 77 -> 76; 36,258 -> 36,133 B; 466 -> 461 globals.
    - data_cluster: 5,956 / 475 -> 5,902 / 472.
    - interior: 115 -> 80.
    - linkdebt total: 29,819 -> 29,727. D2Client 10,591 -> 10,499; no module rose.
    - shortdata: 355 -> 355.
  - The NPC cluster (0x00726850-0x00726CC1) is gone. The quest table's cluster stays only for its loop bound (`cmp reg, gaQuestTable + 41*16 + 8`), which cluster-rule-2 handles.
- Fri Nov 27 07:01 PST 2026: **lane13/glide-tile-vertices** (07b7da21f, on main ac1dc8375). VERIFIED tree 92dc7923348f447a90bb85e3b73bd80320cda1b4; Game.exe identical. Audit guard: no count rose. This is the D2Glide cluster 0x00880678-0x00880B5C (1,252 B).
  - The Glide floor-tile mesh (`gatGlideTileVertices[36]`, 28 B each) and its strip pointers (`gapGlideTileStrips[5][12]`) had no definition. They were only externs, each under two names and two vertex types (a local D2GlideVtxStrc and D2GlideSpriteVertexStrc).
  - Both are now defined once in Unknown_0050BD30.cpp. sub_0050D540_GlideInitD fills the strips by row and column.
  - **Counts on main, before -> after:**
    - data clusters: 77 -> 76; 36,258 -> 35,006 B; 466 -> 463 globals.
    - data_cluster: 5,956 / 475 -> 5,930 / 470.
    - linkdebt total: 29,819 -> 29,793. D2Glide 486 -> 460; no module rose.
    - shortdata: 355 -> 355.
  - Independent of client-tables.
- Fri Nov 27 06:11 PST 2026: **lane13/questlog** (487005a03, on main ac1dc8375). VERIFIED tree 76b1134473a04facca3ca4e5fdfb158bf3d1b183; Game.exe identical. Audit guard: no count rose. This is the D2Client cluster 0x007BF298-0x007C0274 (4,060 B, 16 globals, 220 refs).
  - **What it is.** The quest log panel's state is one pack(1) struct, `D2QuestLogStateStrc`, 0xFDC bytes. It holds:
    - the panel state and quest count;
    - the button flags and pressed/selected slot;
    - the five page selections and the cels;
    - the server's 42-byte quest record (`tQuestRecord`), unioned with the step of each quest (`abQuestStepsA`), and the steps last shown (`abQuestStepsB`);
    - the six quests on the page (`aMsgs`, 0x26A each, whose first byte is a flag);
    - their anim/tick arrays, the page, the toggle tick, and the cof/packet flags.
  - **What was wrong.** The sources split it into about 40 globals at odd addresses, several of them aliases of each other:
    - gtQuestLog_007BF298, gB27_007BF298, gnState_007BF298, `int gtQuestLog`, and data_007BF298 (the one with the constructor);
    - gtQuestUiFlags_007BF2B3;
    - gaQuestEntries, which started one byte into each entry.
    Several were defined again in text.cpp, Unknown_004A43E0.cpp and Unknown_004A6460.cpp.
  - **The fix.** QuestLog.cpp now defines `gtQuestLog` once. Its constructor stays at 0x004A4260, and all uses read `gtQuestLog.<field>`. D2Record42Strc moves into D2ClientQuestText.h. D2QuestTextBufferStrc, D2QuestUiFlagsStrc and D2QuestPanelEntryStrc, the partial views, are gone.
  - **Field types follow the code.** nQuestAct is signed, because QuestLog compares it with jg/jle.
  - **D2Client.h keeps its 15 old externs of these names, unused.** Removing them changed the code of four units that don't use them (inv.cpp, inv_0048BC10, inv_0048DD90, UnitSnd): the declaration-count effect lane 11 reported. I edited only its D2_RESET_QUEST_SELECTION macro. D2ClientFuncs.h's 12 lines could go.
  - **Counts on main, before -> after:**
    - data clusters: 77 -> 76; 36,258 -> 32,198 B; 466 -> 450 globals.
    - data_cluster: 5,956 / 475 -> 5,736 / 455.
    - linkdebt total: 29,819 -> 29,520. D2Client 10,591 -> 10,292; every other module unchanged.
    - shortdata: 355 -> 355 (same list).
## Claimed
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
- Fri Nov 27 01:43:35 PST 2026: **reading of the two D2Win clusters, and a question on link.py's cluster rule.** Neither is a split object.
  - 0x00842710 (gabItemPalettes[9][0x6900] + gabEmblemColor1[12]) clusters on one reference: 0x5053A0's `mov al, [ecx + 0x87D80F]`. That is D2Comp.cpp's `gabEmblemColor1[nColor1 - 1]` (line 1813), with the compiler folding the -1 into the displacement (gabEmblemColor1 - 1).
  - 0x0081EA68 (gatShadowsLightGammaPalette[49] + gabLuminancePalette[65536]) clusters on 0x4FB010's `cmp eax, 0x821B68`. That is the loop end pointer of `for (i = 0; i < 49; ++i) ... gatShadowsLightGammaPalette[i]` (D2WinPalette.cpp line 80), i.e. gatShadowsLightGammaPalette + 49.
  - Both sources are already right. link.py's cluster_data takes every reference whose addend lies outside [0, size) as reaching into the neighbour. That includes a one-past-the-end address used as a value (a loop bound) and an `a[i - k]` displacement.
  - I logged every cluster trigger (1,370 references) and decoded each instruction. In 40 of the 126 clusters every trigger is one of three things: a one-past-end address used as a value (`cmp reg, imm` / `push imm` / `mov reg, imm`), an indexed access at a negative constant offset (`[reg + a - k]`), or an indexed access at exactly the end. Those 40 include the next four biggest: D2Direct3D 0x00971740 (65,540 B), D2Gfx 0x007CA320 (32,772 B), D2Client 0x007C0ED0 (17,804 B) and 0x007ACA50 (16,388 B). The other 86 have a constant read past the end (854 refs `[a + n]` with n >= size, no index), which are the real split structs and short arrays.
  - **Question:** may lane 13 change link.py's cluster rule so that (a) a one-past-end address used as an immediate value and (b) `[reg + a - k]` no longer make a cluster? Telling an immediate from a memory operand needs the instruction decoded at the relocation. My proposal: decode with capstone where it is installed, and keep today's behaviour where it isn't, so counts never get worse. If you'd rather keep link.py lane 10's, I'll hand lane 10 the trigger list instead (/tmp/clusterprobe.json here; I can post the script). Parked; I'm on the short globals meanwhile.
- Fri Nov 27 01:14:52 PST 2026: the brief says to read COMMON.md (build setup, §1, and the brief/disassembly tools), but there's no COMMON.md on coord, main or lane10/short-data. I'm using the build setup I already have and my own disassembler for now. If it's somewhere else, please point me to it.
