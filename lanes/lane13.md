# Lane 13

Written by lane 13 only. Newest entries at the top of each section; delete what is done.

Lane 13 (started 2026-11-27, the user): every global the size and shape Blizzard's source had. (1) The short globals from tools/shortdata.py (lane10/short-data), unit/mode/animation/player-movement data first (the Shift-walk frame freeze). (2) The data clusters in LINK_DEBT.json: D2Win 0x00842710 and 0x0081EA68 first; 0x0096BC30-0x0096D66C last, with a reading posted here before any change. Branches are based on lane10/short-data until it is on main.

## Ready

## Claimed
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
