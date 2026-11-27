# Lane 13

Written by lane 13 only. Newest entries at the top of each section; delete what is done.

Lane 13 (started 2026-11-27, the user): every global the size and shape Blizzard's source had. (1) The short globals from tools/shortdata.py (lane10/short-data), unit/mode/animation/player-movement data first (the Shift-walk frame freeze). (2) The data clusters in LINK_DEBT.json: D2Win 0x00842710 and 0x0081EA68 first; 0x0096BC30-0x0096D66C last, with a reading posted here before any change. Branches are based on lane10/short-data until it is on main.

## Ready
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
- Fri Nov 27 04:48 PST 2026: **lane13/cluster-rule-2** (0bdda1c5e, on lane13/cluster-rule 5434a8696; **supersedes cluster-rule**, take this one). VERIFIED tree f66d34ecd95d455e1568ff41657af8abc4c241a1; Game.exe identical. Audit guard: no count rose. Only tools/link.py changes.
  - **The extension.** A `cmp` with an immediate (3D, 81 /7) reads no memory at that address, so any such operand outside its array is now plain: a loop bound, including an unrolled loop's `a + size + 4`. D2Game's gnGamesGUIDs[1024] is walked four entries a step and compared with `gnGamesGUIDs + 1025`. That is your condition (a), the loop bound, read as "any compare" rather than "exactly one past the end". Other immediates (push, mov) still have to be exactly one past the end, and (2) is unchanged: a constant read past the end with no register still makes a cluster.
  - The read-back check now skips a global that lies in its section's uninitialised tail (nothing to compare). The newly freed globals exposed one: D2Win gData_0072E1BA.
  - **Read back:** 14,927 / 14,927 verified functions and 2,408 / 2,408 initialised globals equal; image valid, same imports.
  - **Counts on main, before -> cluster-rule -> cluster-rule-2:**
    - data clusters: 126 -> 78 -> 51; 534,127 -> 58,706 -> 41,485 B; 701 -> 600 -> 484 globals.
    - data_cluster: 7,072 / 666 -> 6,357 / 575 -> 3,436 / 473.
    - linkdebt total: 30,698 -> 30,093 -> 27,386. No module rose.
    - As in cluster-rule, globals freed from blocks bring their own debts back into view (placeholder 3,544, different_identifier 5,744, duplicate_data 1,075, interior 134).
## Claimed
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
