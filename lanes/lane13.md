# Lane 13

Written by lane 13 only. Newest entries at the top of each section; delete what is done.

Lane 13 (started 2026-11-27, the user): every global the size and shape Blizzard's source had. (1) The short globals from tools/shortdata.py (lane10/short-data), unit/mode/animation/player-movement data first (the Shift-walk frame freeze). (2) The data clusters in LINK_DEBT.json: D2Win 0x00842710 and 0x0081EA68 first; 0x0096BC30-0x0096D66C last, with a reading posted here before any change. Branches are based on lane10/short-data until it is on main.

## Ready
- Fri Nov 27 05:03 PST 2026: **lane13/chat-controls** (62140a717, on lane13/control-templates b881a8f2e, take after it). VERIFIED tree f81a597410f0b008874f7dd2d8520c414d685c3c; Game.exe identical. Audit guard: no count rose. This is the D2Multi cluster 0x0077B058-0x0077B09C (68 B, 16 globals, 123 refs).
  - `gapChatDlgControls` holds the 17 controls the chat screen creates from gatChatControlInits, one per entry. Sixteen of its elements were separate globals, spread over ChatDlg, ComCallback and Unknown_00444020: gpChatControl_*, gpCreateScreenButton, gpJoinScreenButton, gpControlC, gpQuitButton, the four scroll buttons, gpAdImage and gpSmack (typed D2WinSmackStrc* in ComCallback). ComCallback also defined the array itself as a single pointer.
  - It is now one `D2WinControlStrc*[17]` in ChatDlg.cpp, read by the same `D2ChatControlInit` index as its inits. The enum and the array's extern move to a new header, Source/Include/D2ChatControls.h, which only ChatDlg and ComCallback include. CharSel and Unknown_00444020 only lose dead externs.
  - **Counts, before (control-templates) -> after**, on that branch's link.py:
    - linkdebt: 30,442 refs -> 30,442 refs, 5,562 -> 5,546 targets; every module unchanged.
    - data_cluster: 6,744 / 601 -> 6,745 / 586.
    - data clusters: 126 -> 126 (516,943 B); 602 -> 587 globals. The cluster stays only because of the array's loop-end bound.
    - shortdata: 342 -> 342.
  - **With cluster-rule-2's link.py:** 49 clusters, 23,321 B, 367 globals; data_cluster 2,964 / 390; total 27,005. Both ChatDlg clusters are gone.
- Fri Nov 27 04:48 PST 2026: **lane13/cluster-rule-2** (0bdda1c5e, on lane13/cluster-rule 5434a8696; **supersedes cluster-rule**, take this one). VERIFIED tree f66d34ecd95d455e1568ff41657af8abc4c241a1; Game.exe identical. Audit guard: no count rose. Only tools/link.py changes.
  - **The extension.** A `cmp` with an immediate (3D, 81 /7) reads no memory at that address, so any such operand outside its array is now plain: a loop bound, including an unrolled loop's `a + size + 4`. D2Game's gnGamesGUIDs[1024] is walked four entries a step and compared with `gnGamesGUIDs + 1025`. That is your condition (a), the loop bound, read as "any compare" rather than "exactly one past the end". Other immediates (push, mov) still have to be exactly one past the end, and (2) is unchanged: a constant read past the end with no register still makes a cluster.
  - The read-back check now skips a global that lies in its section's uninitialised tail (nothing to compare). The newly freed globals exposed one: D2Win gData_0072E1BA.
  - **Read back:** 14,927 / 14,927 verified functions and 2,408 / 2,408 initialised globals equal; image valid, same imports.
  - **Counts on main, before -> cluster-rule -> cluster-rule-2:**
    - data clusters: 126 -> 78 -> 51; 534,127 -> 58,706 -> 41,485 B; 701 -> 600 -> 484 globals.
    - data_cluster: 7,072 / 666 -> 6,357 / 575 -> 3,436 / 473.
    - linkdebt total: 30,698 -> 30,093 -> 27,386. No module rose.
    - As in cluster-rule, globals freed from blocks bring their own debts back into view (placeholder 3,544, different_identifier 5,744, duplicate_data 1,075, interior 134).
- Fri Nov 27 04:48 PST 2026 (replaces the 04:05 entry): **lane13/ancient-equipment** (1c474e69d, on main f6f04a987). VERIFIED tree a6cb89c70192b0386356f4b39363ad52b1941c65; Game.exe identical. Audit guard: no count rose. This is the D2Game cluster 0x006E1BB0-0x006E2CF0 (4,416 B, 35 globals). Two commits:
  - `gszTargetsSourceFile` (Targets.cpp, 0x006E2C78) was declared 120 chars. That ran over the 96 B table at 0x006E2C90 that MONSTERSPAWN_EquipAncientBarbarians reads as `gtAncientEquipment[nClassId - 540]`, which no source defined. The string is now its 20 chars, and Unknown_005B24E0.cpp defines `gtAncientEquipment[12]` (D2MonsterEquipmentStrc).
  - `gszA1Q2SourceFile` (a1q2.cpp, 0x006E1B98) is a 49-char path but was declared 24. Its last 28 bytes were a separate record in Unknown_005B24E0.cpp, `gaAncientBarbItems` (0x006E1BB0), named after nothing real: 0x006E1BB0 is only where `gtAncientEquipment - 540*8` folds to. The string is whole now and that record is gone.
  - **Counts on main:** 126 clusters, 534,127 -> 534,151 B, 701 -> 702 globals. data_cluster 7,072 / 666 -> 7,080 / 667: the whole string now sits inside the cluster this access still makes on main. Linkdebt total 30,698 -> 30,698, every module unchanged. shortdata 342 -> 342.
  - **With cluster-rule-2's link.py:** this cluster goes away (51 clusters, 37,133 B, 451 globals; data_cluster 3,384 / 440; total 27,369), and link.py reads back all 14,927 functions and 2,441 initialised globals equal.

- Fri Nov 27 03:49 PST 2026: **lane13/control-templates** (b881a8f2e, on main f6f04a987). VERIFIED tree 17ec33e560032b01d4cb3754685ce3071a5774b9; Game.exe identical. Audit guard: no count rose. This is the largest cluster, 0x00708D10-0x0070D3C0 (18,096 B, 101 globals).
  - **D2Launch gatControlTemplates** (0x00708D10) is 333 templates of 48 B, indexed by template id up to 0x11F.
    - The plan had it as 42 MainMenus records: the first 26 entries, byte runs, the 16 `gLayout_*` ints MainMenus sets for its language layout, and `gpGlobal_0070B738`.
    - The `gLayout_*` ints are the nY fields of templates 0x1A-0x10C. `gpGlobal_0070B738` is template 0xE0's pointer at +0x28.
    - Now it is one `D2LaunchControlTemplateStrc[333]`. Those writes read as `gatControlTemplates[i].nY` / `[0xE0].unk0x28`, and the struct (D2Launch.h) gets its leading fields.
  - **D2Multi ChatDlg** reached its own controls as `gatControlTemplates[0x15C...0x178]`, through D2Launch's array and past its end. It now names its own globals.
    - `gatChatControlInits` (0x0070CE50), which the chat screen creates in a loop of 17, is one `D2WinControlInitStrc[17]`. It holds the 6 panels plus 7 controls that were separate globals and a 192 B byte run (the 4 scroll buttons). Those are now indexed by a `D2ChatControlInit` enum.
    - [0x170], [0x172] and [0x178] are gtControlInit_0070D210, gtChatEditInit and gtGemButtonInit.
  - **Counts on main, before -> after:**
    - data clusters: 126 -> 126, but 534,127 -> 516,943 B and 701 -> 602 globals. The 18 KB cluster is gone; what's left there is a 912 B cluster, gatChatControlInits + gatControlInits, made only by the loop's one-past-end bound (`cmp reg, 0x0070D180`), which lane13/cluster-rule removes.
    - data_cluster: 7,072 / 666 -> 6,744 / 601.
    - linkdebt total: 30,698 -> 30,442. D2Multi 1,664 -> 1,491, D2Launch 1,494 -> 1,416, D2Client 10,777 -> 10,772; no module rose.
    - shortdata: 342 -> 342.
  - Independent of cluster-rule; both are on main.
## Claimed
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
