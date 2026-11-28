# Lane 13

Written by lane 13 only. Newest entries at the top of each section; delete what is done.

Lane 13 (started 2026-11-27, the user): every global the size and shape Blizzard's source had. (1) The short globals from tools/shortdata.py (lane10/short-data), unit/mode/animation/player-movement data first (the Shift-walk frame freeze). (2) The data clusters in LINK_DEBT.json: D2Win 0x00842710 and 0x0081EA68 first; 0x0096BC30-0x0096D66C last, with a reading posted here before any change. Branches are based on lane10/short-data until it is on main.

## Ready
- Fri Nov 27 22:10 PST 2026: **lane13/hireling-init** (cf84117fa, on main baf537f80 = #497). Item 9. VERIFIED tree f2bc765decab6de5a7af4663ac371fd64b11069a; Game.exe identical. Audit guard: no count rose. No pointer cast written.
  - One D2HirelingInitStrc, in a new Source/Include/D2HirelingInit.h. The four copies (D2Client.h, D2Common Unknown_006634F0.cpp, D2Game SUNITNPC.CPP and MonsterAI.cpp) each include it where the copy was. MonsterAI.cpp's copy had unk0x34[2] for field_34, nFlags and unk0x3A. Field names are D2MOO's.
  - **Counts, main #497 -> this:** linkdebt unchanged (19,253); shortdata unchanged (362).
- Fri Nov 27 22:10 PST 2026: **lane13/unit-packet-list** (37daae86f, on main baf537f80 = #497; independent of hireling-init, though both touch D2Client.h in different places). Item 9. VERIFIED tree 9daa9b89b3246419e9c7b6dd4a7370cde8125b1d; Game.exe identical. Audit guard: no count rose. No pointer cast written.
  - D2Client.h's D2PacketBufferStrc is renamed D2PacketListStrc. That is the type CUnit.cpp defines CUNIT_GetPacketList and CUNIT_SetPacketList with, and until now it was only forward-declared (D2Structs.h). D2Net's D2PacketBufferStrc (D2NetTypes.h) is a different type with the same name. SCmd.cpp, Player.cpp and automap.cpp use the new name.
  - The old name stays forward-declared in D2Client.h, with a comment, because removing it flips inv_0048BC10.cpp.
  - **Counts, main #497 -> this:** type_disagreement 4,279 -> 4,274; linkdebt 19,253 -> 19,248; D2Client 6,322 -> 6,317; no module rose. Shortdata unchanged (362).
## Claimed
- Fri Nov 27 23:00 PST 2026: **the declaration-count effect, solved as a rule (for every lane), and item 7's header step no longer needs the lock member.**
  - **The rule.** A function's code can depend on *how many names are declared before one global it references*, modulo 64. Shift that symbol's declaration by a multiple of 64 names and nothing changes; shift it by anything else and the function may flip. I measured this on UnitSnd.cpp, inv_0048BC10.cpp, inv_0048DD90.cpp, inv.cpp, CharSel.cpp, MonsterTbls.cpp and ItemTbls.cpp: all have period 64.
  - **What counts as a name** (measured with UNITSND_GetHitSounds, which flips at exactly 15):
    - a variable, used or not: 1
    - a typedef: 1 (a D2_CHECK_SIZE / D2_CHECK_OFFSET line: 2)
    - an enum: 1, plus 1 per enumerator
    - a prototype: 1 plus 1 per parameter, named or not, **and again in full for every redeclaration**
    - a struct, class or union definition: 7 plus 1 per data member; a declared method adds 1, an inline method 3
    - a forward declaration of a new struct: 1; of one already declared: 0
    - a #define, a rename, a type change, a comment: 0
  - **Which symbol.** Each sensitive function has one (sometimes more) global whose position matters, usually a string it passes: gszEmptyAssertText for UNITSND_GetHitSounds (0x004CA560), gwszRecipeScrollText for 0x0048BC10, the NPCMENU_ClearUnicode prototype for 0x0048DD90, gszLevelFormat for CharSel's 0x00439210, gszTxtField_mS1 for MonsterTbls' 0x006571A0, szFmtD_006D57BC for inv.cpp's 0x00488100. Names declared after that symbol never matter, including the function's own prototype and callees.
  - **What flips in the bytes.** Small orderings only: the order of two register reloads after a call (0x004CA560: `mov eax,[ebp-4]` / `mov edx,[ebp+0x10]` swapped), or which register is base and which index in a lea.
  - **How to use it.**
    - A header change that adds or removes a multiple of 64 names is safe for every includer. Count before pushing; add or drop a D2_CHECK line, or split one more placeholder, to land on the multiple.
    - When a unit has flipped: find the symbol (move two dummy one-int structs down the file until the flip stops; it stops at the symbol's declaration) and move that one declaration up or down past as many names as the header change added, modulo 64.
    - To make a function immune for good, declare its symbol above the includes. From there no header can move it. It still needs the right count ahead of it, so this only works where the unit's own declarations can supply that.
    - "Keep the retired declaration" worked because it keeps the count. So does any other declaration of the same size.
  - **Item 7: the struct is 0xC88 bytes, not 0x1A3C.** The highest offset any code reaches through `sgptDataTables->` is 0xC70 (nShiftedStuff), and D2MOO's field order ends with bCompileTxt at 0xC84. From 0x0096C8B8 on, the span holds other files' own globals in link order: DrlgActivate.cpp's four room counters, LvlTbls.cpp's tables, Logging.cpp's gLogLock / gpLogFile / gbLogEnabled, ItemTbls.cpp's tables, Arena.cpp's, Preset.cpp's list and its lock, FieldTbls.cpp's. Those were never struct fields; the header modelled them as fields, and files reach them as `sgtDataTables.<field>` at absolute addresses, which is what makes the cluster.
    - So gLevelFilesCriticalSection stays Preset.cpp's own CCritSect, as it is. No CCritSect member, no new include in D2DataTbls.h, and the two includer classes (101 with D2SysTypes.h, 77 without) don't arise.
    - Plan: the header's struct ends at 0xC88; the 28 tail members and their 5 offset checks go (38 names fewer). I split the placeholders inside the real struct into the fields the conversion needs anyway, sized so the header's total change is a multiple of 64 names. The files that use tail fields through sgtDataTables switch to the owning file's global. Then DataTbls.cpp defines `D2DataTablesStrc sgtDataTables; // 0x0096BC30` and the in-struct names convert file by file, each unit kept equal by the rule above.
  - My 21:20 question (may a branch leave 2 units unequal) is withdrawn: no, and it won't need to.
- Fri Nov 27 22:10 PST 2026: on Fable; read the coordinator's 22:00 entry. Item 7's header step is first. **What the declaration-count effect is, so far (UnitSnd.cpp 0x004CA560, UNITSND_GetHitSounds, on #497):**
  - **The bytes.** After the call to MONSTERREGION_CheckMonStats2Flag, two caller-saved register variables are reloaded: `mov eax, [ebp-4]` (nType) and `mov edx, [ebp+0x10]` (pSound2). The original has nType first. The flipped build has pSound2 first. Nothing else changes.
  - **It is not a count.** I added unused declarations after UnitSnd.cpp's includes. Forward declarations, externs, prototypes, typedefs and enums (6 of each) never flip it. Struct, class and union *definitions* do, and by size, not number: 2 to 6 one-int structs flip it, 8 don't, 12 do, 16 to 64 don't, 100 do; one struct flips it with 8 members but not with 2.
  - **It is one symbol's position.** I moved two dummy structs down the file line by line. Before line 43, `extern "C" const char gszEmptyAssertText;`, they flip the function. Anywhere after it (120 positions, down to the line above the function) they never do. So the function's code depends on where that global, which its D2_ASSERT references, sits in the compiler's memory. It does not depend on its own prototype, its callees or its locals.
  - **Reading.** Unused externs and prototypes never reach the back end; type definitions do, and they push every symbol declared after them. The back end keeps the globals a function references in an address-keyed table with the function's own variables, and the reload order comes out of that table. A unit therefore flips when a header adds type definitions ahead of a global its functions reference.
  - Next: the shift-size map for this function, then the same reading for inv_0048BC10, inv_0048DD90, inv.cpp and CharSel.cpp, and whether declaring the referenced global ahead of the headers' types pins it.
- Fri Nov 27 21:41 PST 2026: status.
  - **Item 7:** with the CCritSect member and the 15 checks moved to DataTbls.cpp (on #496), the flipping units are CharSel.cpp, inv.cpp, ItemTbls.cpp and MonsterTbls.cpp. I then searched each for one stale declaration whose removal brings it back:
    - inv.cpp: its unused local prototype of SKILLS_AssignSkill, which D2CommonApi2.h also declares.
    - MonsterTbls.cpp: a forward prototype of DATATBLS_MonStatsSkillModeLinker, defined before its first use.
    - ItemTbls.cpp and CharSel.cpp: no single removal works. ItemTbls.cpp is a loader that the conversion rewrites anyway, so its declarations change again there.
    - **CharSel.cpp is the open one.** It is lane 1's (cominterface-names, held) and lane 12's. Coordinator: may I make a compensating edit there? If not, item 7's header step waits for the Fable item.
  - **Item 9:** **lane13/hireling-init** (cf84117fa, VERIFIED f2bc765decab6de5a7af4663ac371fd64b11069a): one D2HirelingInitStrc in a new D2HirelingInit.h. There were 4 copies, in D2Client.h, D2Common Unknown_006634F0.cpp, D2Game SUNITNPC.CPP and MonsterAI.cpp; field names are D2MOO's. Counts against #497 are being taken now.
  - **lane13/unit-packet-list** is building: D2Client.h's D2PacketBufferStrc is renamed D2PacketListStrc, the type CUnit.cpp's CUNIT_GetPacketList is defined with (D2Net's D2PacketBufferStrc is another type). The old name stays forward-declared, because removing it flips inv_0048BC10.cpp.
- Fri Nov 27 21:21 PST 2026: #497 took npc-state-4, plan-includes-3, packet-2a and packet-2a-scmd; their Ready lines are cleared. Starting **item 9**, the unnamed fields of the D2Client headers. Lane 1 skips these: Source/D2Client/D2Client.h (48), D2ClientTextPanel.h, D2ClientTextBox.h, D2ClientNpcMenu.h, D2ClientTextState.h, D2ClientTypes.h, D2ClientGfx.h, D2ClientUiRecords.h, D2ClientMenus.h, D2ClientKeyConfig.h, D2ClientBallistic.h, D2ClientTileLight.h, D2ClientSound.h. Not claimed: D2ClientGame.h, D2ClientQuestText.h, D2ClientGfxState.h, which are lane 1's.
- Fri Nov 27 21:20 PST 2026: item 7 status. Moving the static checks is not converging: across 47 subsets of the 15 D2_CHECK_* lines (prefixes and random), only "move all 15" keeps inv_0048BC10/inv_0048DD90/UnitSnd/Items equal. That variant flips CharSel.cpp, inv.cpp, ItemTbls.cpp and MonsterTbls.cpp instead. ItemTbls and MonsterTbls are DATATBLS loaders that item 7 rewrites anyway, so they get rebuilt in the conversion. I'm now checking whether inv.cpp comes back equal with one of its own redundant redeclarations removed (time-boxed). If that fails too, my proposal: land the CCritSect member with the checks moved,, and list CharSel.cpp and inv.cpp for the Fable item. A header change can't be kept off a single unit, so those two would stay unequal until then. **Coordinator: is a branch acceptable that leaves 2 units NOT_ALL_EQUAL? I assume not, so I'll hold item 7's header step until you say, and work item 9 (D2Client header fields) meanwhile.**
- Fri Nov 27 20:51 PST 2026: check-in. Main is #496; npc-state-4, plan-includes-3, packet-2a and packet-2a-scmd are Ready. **Item 7 (D2DataTablesStrc), first findings on #496:**
  - The original's static initializer at 0x006CB010 is `push 0x0096D610; call [InitializeCriticalSection]; push 0x006CB4E0; call atexit`, and 0x006CB4E0 is `push 0x0096D610; call [DeleteCriticalSection]`. So the struct's lock at +0x19E0 is a member with a ctor and dtor: a CCritSect member of sgtDataTables produces exactly that.
  - Including CCritSect.h in D2DataTbls.h now flips 4 units (inv_0048BC10, inv_0048DD90, UnitSnd, Items), down from 6. Including only D2SysTypes.h, or declaring a ctor/dtor on the struct, flips 1 to 3. Splitting a byte array into named members flips none.
  - With the CCritSect member *and* D2DataTbls.h's 15 D2_CHECK_* typedefs moved to DataTbls.cpp (where the struct is defined), those 4 come back equal, but CharSel.cpp, inv.cpp, ItemTbls.cpp and MonsterTbls.cpp flip instead. I'm searching which checks can move so all 179 includers stay equal (on the 8 sensitive units first, then all 179).
- Fri Nov 27 20:23 PST 2026: read the restocked queue. Starting **item 7, D2DataTablesStrc**: on #496 I'm measuring first how many units the CCritSect member flips (it was 6 on #485). The definition will be named `sgtDataTables`, the name the 10 D2Common files already declare it under. Claimed: Source/Include/D2DataTbls.h, Source/D2Common/DATATBLS/*, Source/D2Common/DRLG/Preset.cpp, Source/Include/CCritSect.h, and the D2Common files that declare names in 0x0096BC30-0x0096D66C.
- Fri Nov 27 19:59 PST 2026: npc-state-4 and plan-includes-3 Ready. Building now: **lane13/packet-2a** (stacked on npc-state-4). D2ClientNpcMenu.h's D2GSPacketSrv2A was a second copy of D2Packets.h's D2PacketSrv2AStrc. That struct moves to its own D2PacketSrv2A.h, included by both, so gtNpcMenu.tPacket2A gets the server's field names (nResult, nUnitGUID, nTransactionType, nGold). Every D2Packets.h and D2ClientNpcMenu.h unit is equal. Claimed: D2Packets.h, D2PacketSrv2A.h, D2ClientNpcMenu.h, npcmenu.cpp.
- Fri Nov 27 19:20 PST 2026: check-in. #495 took text-panel, glide-grid and raw-offsets-4 (Ready lines cleared). The old plan-includes Ready line is cleared too. Both open branches are rebased onto #495 and doing full builds, one after the other: **lane13/npc-state-4** (b9daa65ec; supersedes npc-state-3) and **lane13/plan-includes-3** (fa067c1a4; supersedes plan-includes and plan-includes-2; it reapplies the include fix to main's data_plan.json, now 33 files). Ready lines follow once each is built and counted against #495.
  - **Coordinator: my queue is done** apart from blocked items: CharSel/ComCallback bitmasks (waiting for lane 12's answer), SGAMEDATA's RTTI name (D2Game.h has its own copies of Storm's templates, so stpl.h can't be included; it needs those merged), and short globals (classified, nothing to fix). What next? I could (a) take the D2DataTablesStrc struct once lane 1's item 0 sub-table records land, since lane 14 has moved to Iblis-Engine; (b) take a share of the 189 unnamed header fields, e.g. the D2Client headers (D2ClientNpcMenu.h, D2ClientTextState.h, D2ClientUi.h), so I don't overlap lane 1; or (c) merge D2Game.h's Storm template copies into stpl.h, which would also unblock the SGAMEDATA reference. Until you answer I'll start on (b) with my own two headers, which no one else touches.
- Fri Nov 27 18:33 PST 2026: check-in. #494 took npc-state-2 (Ready line cleared). **plan-includes** rebased onto #494 as **lane13/plan-includes-2** (cc014ba51): main's data_plan.json had changed around the same entries, so I reapplied the include fix to main's copy. It's now 33 files: D2WinTextBox.cpp and D2WinFont.cpp moved their data into source in interior-2 and have no include. Full build queued after npc-state-3. **lane13/npc-state-3** (on #494, building) finishes gtNpcMenu: Monster.cpp's setters and NPC_GET_INTERACT_UNIT (moved to D2ClientNpcMenu.h) use its members, the last 15 interior references into it. text-panel, glide-grid and raw-offsets-4 merge onto #494 with no conflict. Question for lane 12: may I take the 6 gdwBitMasks references in CharSel.cpp and ComCallback.cpp (`gdwBitMasks[k]` in place of gnFlagSet0_006CE278, gdwBitMask5/7, gdwTitleMaskA, gnFlagClear0/1)? If they're in your next branch, I'll leave them.
- Fri Nov 27 18:10 PST 2026: text-panel and glide-grid are Ready. Left in queue item 3: gtNpcMenu's 15 references (once npc-state-2 merges), CharSel/ComCallback's 6 bitmask references (lane 12's files), and Game.cpp's SGAMEDATA RTTI name (1 reference). Next: queue item 0's leftover from the board, the D2DataTablesStrc sub-table records, if lane 1 hasn't taken them; otherwise the remaining raw-offset lines.
- Fri Nov 27 17:50 PST 2026: check-in. Main is #493; npc-state-2 and plan-includes are Ready and unmerged. No ruling on the text-panel question, so I went ahead with option (a), its own 6-byte list type: **lane13/text-panel** is VERIFIED (tree c227f58609ef0307ee7f0e910a825d06a3683278); counts against a clean #493 are running and it goes Ready next. **lane13/glide-grid** (the 17 gData_ vertex pointers in the D2Glide strip/fan tables as &gaGlideTileGrid[k] / &gatGlideTileVertices[k]) is in its full build. The earlier failure there was a marker on the line naming the array. Claimed: Source/D2Glide/Unknown_0050BD30.cpp, Source/D2Win/Src/D2WinTextBox.cpp.
- Fri Nov 27 17:35 PST 2026: #493 took interior-2; its Ready line is cleared. plan-includes is Ready. Working the text panel block now (claimed at 17:25).
- Fri Nov 27 17:25 PST 2026: I had missed **queue item 6**. lane13/plan-includes (on #492) is doing its full build now: it points the 35 stale `include` entries at each file's own include (generated data unchanged), and adds two interior fixes, d3dSmack.cpp's gnRenderFlag = gdwBitMasks[10] and inv.cpp's eight gnRect* = gaBodyLocRects[1/3/4/5].rect. Next: the text panel block, without waiting for a ruling. It gets its own 6-byte list type in a new header, and D2ClientUi.h stays as it is. Claimed: text.cpp, text_0049D5A0.cpp, text_004A10E0.cpp, and the D2Client files naming 0x007BF1E0-0x007BF24F.
- Fri Nov 27 17:22 PST 2026: check-in. Main is still #492. interior-2 and npc-state-2 are Ready and unmerged. There is no answer yet on the D2TextListStrc text-panel question.
- Fri Nov 27 17:14 PST 2026: npc-state-2 Ready. The text-panel block is still waiting on the D2TextListStrc question above. Next: the rest of the interior list.
- Fri Nov 27 16:57 PST 2026: check-in. #492 took queue-1-2 and interior-1; I've cleared their Ready lines. interior-2 is still Ready and merges onto #492. npc-state conflicted with #492 in npcmenu.cpp, but only over my own interior-1 renames, so it's rebased as **lane13/npc-state-2**. Its 9 units are equal, and the full build is running now. Lane 14 note read: the data-tables span and the declaration-count units come back to lanes 1 and 13.
- Fri Nov 27 16:26 PST 2026: **lane13/npc-state** (on #491) is doing its full build. npcmenu.cpp's 0x007C0C68-0x007C0DF4 is now one pack(1) struct, gtNpcMenu: NPCMENU_InitNpcMenu memsets its first 0x160 bytes, and its fields sit at odd offsets. About 80 aliases become fields; every unit is equal.
  - gwszCost_007C0DF5 stays separate: its own dynamic initializer (0x006CAD10) zeroes it inline, and as a struct member the ctor goes out of line.
  - The other files that name these addresses through D2Client.h (npcmenu_004B5C60.cpp 20 uses, Monster.cpp 8, three more with 1-2) still use the old names; a follow-up gives them the struct through a header.
  - **The text panel block (0x007BF1E0) needs a ruling.** D2ClientUi.h's D2TextListStrc is 0x14, but the three lists sit 6 bytes apart. Making it the 6-byte {pFirst, wCount} flips inv_0048BC10.cpp's 0x0048BC10 (one lea's registers swap; the declaration-count effect). Should I (a) add the 6-byte list type in a new header for the panel struct and leave D2TextListStrc alone, (b) shrink D2TextListStrc and keep inv_0048BC10.cpp equal with an unused declaration, or (c) hand it to Fable?
- Fri Nov 27 16:18 PST 2026: interior-2 Ready. Next: the two packed state blocks (the text panel at 0x007BF1E0 and NPC trade at 0x007C0DE0) as one struct each. Claimed: Source/D2Client/UI/text.cpp, text_0049D5A0.cpp, text_004A10E0.cpp, npcmenu.cpp, and the other D2Client files that declare those addresses.
- Fri Nov 27 15:59 PST 2026: **Item 4 (shortdata), classified.** 362 candidates outside the D2DataTablesStrc span, sorted by what fills the room after each declaration. I read every room's bytes from Game.exe, and no linkdebt reference lands in any of them:
  - **zeros: 157.** Alignment padding, or zero data no code reads.
  - **strings: 137.** The literal pool after a declared global (compiler-emitted, with no source object).
  - **Language-name pointer copies: 38.** The per-unit copies of the 15 language strings (0x006CC81C...), which are lane 12's local-copy work.
  - **vtable/RTTI tails: 14.** The next class's complete-object-locator pointer.
  - **fp constants: 3.**
  - **Other: 13.**
    - 0x00749DA4: the next object is the CRT's __security_cookie.
    - 0x006F2854: CRT import names.
    - SMEM.CPP, glCore.cpp and Dungeon.cpp: a double or zeros, then strings.
    - gaPeriodLights: doubles.
    - Tilecmp.cpp and D2Hell: RTTI type descriptors.
    - gszBangLineFormat, cbNeverDelete: RTTI.
    - Fog ErrorManager.cpp: three unreferenced initialised words after gtLock_0074D848, gdwTotalPhys and gdwRegValue.

  So there is no array too short and no struct cut short left: every short global code reads past its end was fixed in the earlier branches. The only undeclared data are those three ErrorManager words, and nothing names them, so I'm leaving them.
- **Item 3, continuing:** lane13/interior-2 (on #491) has three more aliases resolved: gnMouseY, gtUnitSndObject = gaUnitSndObjects[106], and gbPanelFlag = gaEscMenuUIState[21].nSaved.
  - Still left: two packed pack(1) state blocks, the text panel at 0x007BF1E0 and NPC trade at 0x007C0DE0. Unaligned ints follow a byte in each, so they're one struct each, like gtQuestLog. I'll do them as their own branch next.
  - ChatDlg's +0x225 (queue item 2) is covered by lane 1's BnClient interface merge, so I'm dropping it from mine.
- **Item 5 (inlinedata D2Win):** no lane's Claimed line names D2Win's .cpp files (lane 1's wintypes is the header only). Starting after interior-2.
- Fri Nov 27 15:56 PST 2026: interior-1 Ready, alongside queue-1-2; both merge onto #491. Next: the rest of item 3. I'm leaving out the gtTextHistory struct (a branch of its own) and the Glide pointer tables (noted above).
- Fri Nov 27 15:43 PST 2026: **lane13/interior-1** (item 3, first part, on #489) is doing its full build. Its five commits:
  - **gdwBitMasks:** 18 units read it through about 40 scalar names; they now index it. CharSel.cpp and ComCallback.cpp are left for lane 12, and d3dSmack.cpp until queue-1-2 lands.
  - **gtPlayerInvRect/gtNpcInvRect:** the four-field aliases are gone.
  - **npcmenu.cpp:** two more gtPacket2A/gbNpcActionPending aliases are gone.
  - **gCmpBlockTableA:** the 0x1000-byte table at 0x0088CB20 is now defined.
  - **D2WinPalette.cpp:** light and gamma are rows 32-48 of gatShadowsLightGammaPalette.

  Left for later, with what I found:
  - **gtTextHistory:** D2TextListStrc is 0x14 in D2ClientUi.h, but the three lists sit 6 bytes apart and are followed by unaligned ints. That makes 0x007BF1E0-0x007BF24F one pack(1) text-panel struct, like gtQuestLog. Just shrinking the header struct flips inv_0048BC10.cpp (a lea swap), so it needs the whole-struct branch.
  - **gaGlideTileGrid/gatGlideTileVertices:** making the strip/fan pointer tables use `&gaGlideTileGrid[k]` makes two functions MASKED_EQUAL_BUT_TARGETS_DIFFER, so they stay gData_ labels.
  - **gaBodyLocRects:** inv.cpp, the declaration-count unit; it goes in its own branch.

  Claimed: the 18 gdwBitMasks units, inv_0048DD90.cpp, inv_00491D20.cpp, npcmenu.cpp, D2CMP SpriteCache.cpp, D2WinPalette.cpp.
- Fri Nov 27 15:33 PST 2026: queue-1-2 Ready. Starting **item 3**: 56 interior targets, 161 refs. The largest are gdwBitMasks (55 refs as separate ints in other files), gtTextHistory (33), gaGlideTileGrid (19), gtPacket2A's tail (14) and gaBodyLocRects (12). I'm skipping the entries in CharSel.cpp and ComCallback.cpp while lane 12 reconciles those files. Files claimed as I start each.
- Fri Nov 27 15:15 PST 2026: lane13/smack-slots is VERIFIED (tree de5174843e05e07e64ea7dc2a41899beef1ae768). I'm folding items 1 and 2 into one branch, **lane13/queue-1-2**, which is doing its full build now. Item 2:
  - **Roads:** D2DrlgRoadStrc is a view over pOutdoors->pVertices. Its tEnd, tEndInner, tStartInner and tStart/nStartType are exactly pVertices[n], [6 + n], [12 + n] and [18 + n].nDirection, so there's no road record to name. The read now indexes those vertices. D2DrlgRooms.h's D2DrlgRoadStrc is now unused, and I'm leaving it there: the header is shared.
  - **Save summary:** for version 0x5C-0x60 it reads D2SaveHeaderStrc. The "name" and "title" it packs are nComponent and nCompColor (the statstring). The pre-0x5C header has no struct, so its five byte reads stay.
  - **ChatDlg +0x225:** waiting for lane 12.
  - **Next: item 3 (interior references).**
- Fri Nov 27 14:58 PST 2026: read the lane 13 queue. **Item 1 (D3D smack slots)** is on lane13/smack-slots, on #489, and doing its full build. Every unit is equal, and the last cluster outside the data-tables span is gone. On your suggested names: 0x009897E4 holds device *surfaces* (CopySurface's destination, CreateDeviceTexture's first out-parameter), so I named it gapSmackDeviceSurfaces and gave gapSmackTextures to 0x009897EC, the drawn textures. The helpers are declared typed, so the branch adds no casts. Next: **item 2**. Claimed: Source/D2Direct3D/Src/d3dSmack.cpp, D2Direct3D.h; for item 2, Source/D2Common/Unknown_00681000.cpp and Source/D2Multi/Unknown_0043C8A0.cpp. I'm leaving ChatDlg.cpp's +0x225 until lane 12 finishes reconciling that file's declarations.
- Fri Nov 27 14:27 PST 2026: check-in. Nothing new for lane 13; main is #488. I'm idle until you send the next item or answer the D3D smack-slot question.
  - My remaining raw-offset lines all need a struct decision first:
    - ChatDlg's +0x225 is D2ComInterfaceStrc vs D2LaunchFuncsStrc, two structs for one table;
    - the roads in Unknown_00681000.cpp;
    - the save-header reads in Unknown_0043C8A0.cpp.
  - The rest (BnDownload, DataTbls and ItemTbls bin loaders, D2Comp COF reads) are buffer layouts, not fields.
- Fri Nov 27 13:56 PST 2026: check-in. split-objects-6 is in main (#488); cleared its Ready line. Data clusters on main are down to 2: the D2DataTablesStrc span (with lane 1 and Fable; field map at the end of this file) and the D3D smack slots 0x009897D4-F4, still waiting on the type question under Questions. Lane 13 has no other queued work. Send me the next item if there is one.
- Fri Nov 27 13:25 PST 2026: check-in. Nothing new for lane 13 on the board. split-objects-6 is still Ready; main is #487 and the branch merges onto it with no conflicts. Still waiting on the D3D smack-slot type question.
- Fri Nov 27 13:08 PST 2026: check-in. #487 landed without split-objects-6, and split-objects-6 still merges onto it with no conflicts. It stays Ready as posted; I'll rebuild on #487 if you want it rebased.
- Fri Nov 27 13:07 PST 2026: check-in. split-objects-6 Ready (on #486). Waiting on the D3D smack-slot type question; the data-tables span is with lane 1 and Fable. Next: the rest of the raw-offset lines in my files.
- Fri Nov 27 12:53 PST 2026: check-in. split-objects-4 (on #485) came back NOT VERIFIED: inv.cpp 0x00488B00 swaps the base and index of one lea, the declaration-count effect against #485's D2Client.h. Fixed by keeping two retired externs in inv.cpp (gaNpcTabStates and gabColors_007BCAD8), unused, as the board says to. #486 landed meanwhile, so **lane13/split-objects-6** (on #486) is doing its full build now, with all of it rebased. Ignore split-objects-4 and -5. Ready within 20 minutes.
- Fri Nov 27 12:13 PST 2026: check-in. The data-tables field map is at the end of this file, under **Data-tables field map** (see the note there on why it's not in its own file). Rebasing onto #485 as **lane13/split-objects-4**: it replaces split-objects-3 and adds the 3 raw-offset commits (GAME_HandleKeyDown's SMSGHANDLER_PARAMS, the CubeMain linkers, Window.cpp's gabLightCube). It is doing its full build now. MonsterMode.cpp was redone against lane 12's #485 declarations.
- Fri Nov 27 11:57 PST 2026: 0x009897EC posted under Questions (a type for the D3D smack slots). With split-objects-3, that and the parked data-tables span are the only clusters left. Next: going through the 363 shortdata candidates for any whose room code actually reads.
- Fri Nov 27 11:54 PST 2026: check-in. split-objects-3 Ready; it replaces split-objects-2 and short-arrays-3. Next: D2Direct3D 0x009897EC, then the remaining shortdata candidates.
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
- Fri Nov 27 11:57 PST 2026: **D2Direct3D 0x009897D4-0x009897F4 (the smack surface pairs): left as is; it needs a typing decision.** The span is four 2-entry pointer arrays, each also defined or declared as two scalars:
  - 0x009897D4 is gpArray_009897D4, gapObjectsD4_009897D4, gapSmackSurfaces/gpMemSurfaceB and gpBuffer_009897D4/D8.
  - 0x009897DC is gapObjectsDC, gapObjectsDC_009897DC and gpValue_009897DC/gpSmackSourceTexture.
  - 0x009897E4 is gpArray_009897E4, gapSmackTextures and gpTarget_009897E4/gpTarget.
  - 0x009897EC is gapObjectsEC, gapObjectsEC_009897EC and gpObject_009897EC/gpSmackTexture.

  D3DSMACK_CreateSmackSurfaces passes each slot to the D3DCORE allocators as `void**`. The upload calls each slot's `lpVtbl->Load` as a D2D3DTextureStrc*, and the release loop calls Release as a D2D3DObjStrc*. So any single element type needs a cast at one of those three uses, unless the allocators' declarations (defined in other D3D units) change. Only the 0x009897EC pair makes a cluster, because DrawSmackFrame reads gapObjectsEC[1], which d3dSmack.cpp defines as gpSmackTexture. Which type should the slots have? I'd say D2D3DTextureStrc*, with the two allocators declared to take D2D3DTextureStrc**.
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

## Data-tables field map (0x0096BC30-0x0096D66C), for lane 1 and the Fable chat

Generated Fri Nov 27 12:13 PST 2026 from main #485's sources. It's here, not in lanes/datatables-map.tsv, because my instructions from the user allow me to write only lanes/lane13.md.

Columns:
- address and offset into D2DataTablesStrc;
- span to the next declared address;
- the D2DataTbls.h field there, or `placeholder <name>+0x<off>` for the unsplit byte arrays (90 of the 234);
- every name, type and file declared at that address.

No values.

```tsv
address	offset	span	header_field	declared (name : type : file)
0x0096BC30	+0x0000	4	void* pPlayerClassTxt	gD2DataTables : D2DataTablesStrc : D2Common/DATATBLS/DataTbls.cpp; gpPlayerClassTxt : void* : D2Common/DATATBLS/DataTbls.cpp; sgtDataTables : D2DataTablesStrc : D2Common/DATATBLS/FieldTbls.cpp; sgtDataTables : D2DataTablesStrc : D2Common/DATATBLS/HoradricCube.cpp; sgtDataTables : D2DataTablesStrc : D2Common/DATATBLS/ItemTbls.cpp; sgtDataTables : D2DataTablesStrc : D2Common/DATATBLS/ItemTbls_00633730.cpp; sgtDataTables : D2DataTablesStrc : D2Common/DATATBLS/ItemTbls_00634DC0.cpp; sgtDataTables : D2DataTablesStrc : D2Common/DATATBLS/LvlTbls.cpp; sgtDataTables : D2DataTablesStrc : D2Common/DATATBLS/MissileTbls.cpp; sgtDataTables : D2DataTablesStrc : D2Common/DATATBLS/MissileTbls_00663270.cpp; sgtDataTables : D2DataTablesStrc : D2Common/DATATBLS/MonsterTbls.cpp; sgtDataTables : D2DataTablesStrc : D2Common/DATATBLS/OverlayTbls.cpp; sgtDataTables : D2DataTablesStrc : D2Common/Unknown_00664530.cpp; sgtDataTables : D2DataTablesStrc : D2Common/Unknown_0066A1A0.cpp
0x0096BC34	+0x0004	4	D2TxtLinkStrc* pPlayerClassLinker	gpPlayerClassLinker_0096BC34 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpPlayerClassLinker_0096BC34 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp; gpPlayerClassLinker_0096BC34 : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096BC38	+0x0008	4	void* pBodyLocsTxt	gpBodyLocsTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BC3C	+0x000C	4	D2TxtLinkStrc* pBodyLocsLinker	gpBodyLocsLinker_0096BC3C : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpBodyLocsLinker_0096BC3C : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp; gpBodyLocsLinker_0096BC3C : void* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096BC40	+0x0010	4	void* pStorePageTxt	gpStorePageTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BC44	+0x0014	4	D2TxtLinkStrc* pStorePageLinker	gpStorePageLinker_0096BC44 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpStorePageLinker_0096BC44 : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096BC48	+0x0018	4	void* pElemTypesTxt	gpElemTypesTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BC4C	+0x001C	4	D2TxtLinkStrc* pElemTypesLinker	gTxtLink_0096BC4C : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp; gpElemTypesLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpElemTypesLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096BC50	+0x0020	4	void* pHitClassTxt	gpHitClassTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BC54	+0x0024	4	D2TxtLinkStrc* pHitClassLinker	gpHitClassLinker_0096BC54 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpHitClassLinker_0096BC54 : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096BC58	+0x0028	4	void* pMonModeTxtStub	gpMonModeTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BC5C	+0x002C	4	D2TxtLinkStrc* pMonModeLinker	gpMonModeLinker : D2TxtLinkStrc* : D2Common/D2Common.h; gpMonModeLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096BC60	+0x0030	4	void* pPlrModeTxtStub	gpPlrModeTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BC64	+0x0034	4	D2TxtLinkStrc* pPlrModeLinker	gpPlrModeLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpPlrModeLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096BC68	+0x0038	4	void* pSkillCalcTxt	gpSkillCalcTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BC6C	+0x003C	4	D2TxtLinkStrc* pSkillCalcLinker	gpSkillCalcLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpSkillCalcLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MissileTbls.cpp; gpSkillCalcLinker : D2TxtLinkStrc* : D2Common/Logging/ProfCore.cpp
0x0096BC70	+0x0040	4	char* pSkillsCode	gpSkillsCode : char* : D2Common/DATATBLS/DataTbls.cpp; gpSkillsCode : void* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096BC74	+0x0044	4	unsigned int nSkillsCodeSize	gnSkillsCodeSize : int : D2Common/DATATBLS/DataTbls.cpp; gnSkillsCodeSize : int : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096BC78	+0x0048	4	int nSkillsCodeSizeEx	gnSkillsCodeSizeEx : int : D2Common/DATATBLS/DataTbls.cpp; gnSkillsCodeSizeEx : int : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096BC7C	+0x004C	4	char* pSkillDescCode	gpSkillDescCode : char* : D2Common/DATATBLS/DataTbls.cpp; gpSkillDescCode : void* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096BC80	+0x0050	4	unsigned int nSkillDescCodeSize	gnSkillDescCodeSize : int : D2Common/DATATBLS/DataTbls.cpp; gnSkillDescCodeSize : int : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096BC84	+0x0054	4	int nSkillDescCodeSizeEx	gnSkillDescCodeSizeEx : int : D2Common/DATATBLS/DataTbls.cpp; gnSkillDescCodeSizeEx : int : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096BC88	+0x0058	4	void* pMissileCalcTxt	gpMissileCalcTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BC8C	+0x005C	4	D2TxtLinkStrc* pMissileCalcLinker	gpMissileCalcLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpMissileCalcLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MissileTbls.cpp; gpMissileCalcLinker : D2TxtLinkStrc* : D2Common/Logging/ProfCore.cpp
0x0096BC90	+0x0060	4	void* pMissCode	gpMissCode : char* : D2Common/DATATBLS/MissileTbls.cpp
0x0096BC94	+0x0064	4	int nMissCodeSize	gnMissCodeSize : int : D2Common/DATATBLS/MissileTbls.cpp
0x0096BC98	+0x0068	4	int nMissCodeSizeEx	gnMissCodeSizeEx : int : D2Common/DATATBLS/MissileTbls.cpp
0x0096BC9C	+0x006C	4	void* pSkillCode	gpSkillCodeTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BCA0	+0x0070	4	D2TxtLinkStrc* unk0x70	gpSkillCodeLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpSkillCodeLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MissileTbls.cpp
0x0096BCA4	+0x0074	4	void* pEventsTxt	gpEventsTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BCA8	+0x0078	4	D2TxtLinkStrc* pEventsLinker	gpEventsLinker_0096BCA8 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpEventsLinker_0096BCA8 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp; gpEventsLinker_0096BCA8 : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096BCAC	+0x007C	4	void* pCompCodeTxt	gpCompCodeTxt : D2CompCodeTxt* : D2Common/Chat/Ignorelist.cpp; gpCompCodeTxt : D2CompCodeTxt* : D2Common/DATATBLS/DataTbls.cpp; gpCompCodeTxt_0096BCAC : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BCB0	+0x0080	4	D2TxtLinkStrc* pCompCodeLinker	gpCompCodeLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpCompCodeLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096BCB4	+0x0084	4	int nCompCodeTxtRecordCount	gnCompCodeTxtRecordCount : int : D2Common/Chat/Ignorelist.cpp; gnCompCodeTxtRecordCount : int : D2Common/DATATBLS/DataTbls.cpp
0x0096BCB8	+0x0088	4	void* pMonAiTxt	gpMonAiTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BCBC	+0x008C	8	D2TxtLinkStrc* pMonAiLinker	gpMonAiLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpMonAiLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096BCC4	+0x0094	4	D2TxtLinkStrc* pItemsLinker	gpItemsLinker : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp; gpItemsLinker : void* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096BCC8	+0x0098	4	char* pItemsCode	gpItemsCode : void* : D2Common/DATATBLS/ItemTbls.cpp
0x0096BCCC	+0x009C	4	unsigned int nItemsCodeSize	gnItemsCodeSize : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096BCD0	+0x00A0	4	int nItemsCodeSizeEx	gnItemsCodeSizeEx : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096BCD4	+0x00A4	4	D2PropertiesTxt* pPropertiesTxt	gpPropertiesTxt : void* : D2Common/DATATBLS/ItemTbls.cpp
0x0096BCD8	+0x00A8	4	D2TxtLinkStrc* pPropertiesLinker	gpPropertiesLinker : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp; gpPropertiesLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096BCDC	+0x00AC	4	int nPropertiesTxtRecordCount	gnPropertiesTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096BCE0	+0x00B0	4	D2TxtLinkStrc* pRunesLinker	gpRunesLinker : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096BCE4	+0x00B4	4	void* pHireDescTxt	gpHireDescTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096BCE8	+0x00B8	4	D2TxtLinkStrc* pHireDescLinker	gpHireDescLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpHireDescLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096BCEC	+0x00BC	4	D2StatesTxt* pStatesTxt	gpStatesTxt : D2StatesTxt* : D2Common/DATATBLS/DataTbls.cpp
0x0096BCF0	+0x00C0	4	D2TxtLinkStrc* pStatesLinker	gpStatesLinker_0096BCF0 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpStatesLinker_0096BCF0 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp; gpStatesLinker_0096BCF0 : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096BCF4	+0x00C4	4	int nStatesTxtRecordCount	gnStatesTxtRecordCount : int : D2Common/DATATBLS/DataTbls.cpp
0x0096BCF8	+0x00C8	4	unsigned int* pStateMasks	gpStateMasks : unsigned int* : D2Common/DATATBLS/DataTbls.cpp
0x0096BCFC	+0x00CC	160	unsigned int* fStateMasks[0]	gfStateMasks : unsigned int* [40] : D2Common/DATATBLS/DataTbls.cpp
0x0096BD9C	+0x016C	8	short* pProgressiveStates	gpProgressiveStates : short* : D2Common/DATATBLS/DataTbls.cpp
0x0096BDA4	+0x0174	8	short* pCurseStates	gpCurseStates : short* : D2Common/DATATBLS/DataTbls.cpp
0x0096BDAC	+0x017C	8	short* pTransformStates	gpTransformStates : short* : D2Common/DATATBLS/DataTbls.cpp
0x0096BDB4	+0x0184	16	short* pActionStates	gpActionStates : short* : D2Common/DATATBLS/DataTbls.cpp
0x0096BDC4	+0x0194	4	placeholder unk0x192+0x2	gpSoundsTxt : void* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096BDC8	+0x0198	4	D2TxtLinkStrc* pSoundsLinker	gpSoundsLinker : D2TxtLinkStrc* : D2Common/D2Common.h; gpSoundsLinker_0096BDC8 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpSoundsLinker_0096BDC8 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp; gpSoundsLinker_0096BDC8 : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096BDCC	+0x019C	4	placeholder nSoundsTxtCodes+0x0	gnSoundsTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096BDD0	+0x01A0	4	placeholder nSoundsTxtCodes+0x4	gHirelingTables : D2HirelingTableGlobals : D2Common/DATATBLS/MonsterTbls.cpp; gpHirelingTxt : D2HirelingTxt* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096BDD4	+0x01A4	2052	placeholder nSoundsTxtCodes+0x8	gnHirelingTxtRecordCount : int : D2Common/D2Common.h
0x0096C5D8	+0x09A8	4	placeholder nSoundsTxtCodes+0x80C	gpNpcTxt : D2NpcTxt* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C5DC	+0x09AC	4	placeholder nSoundsTxtCodes+0x810	gnNpcTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C5E0	+0x09B0	4	void* pColorsTxt	gpColorsTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096C5E4	+0x09B4	4	D2TxtLinkStrc* pColorsLinker	gpColorsLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpColorsLinker : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096C5E8	+0x09B8	4	D2TxtLinkStrc* pTreasureClassExLinker	gpTreasureClassExLinker : D2TxtLinkStrc* : D2Common/D2Common.h; gpTreasureClassExLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C5EC	+0x09BC	4	placeholder pTreasureClassEx+0x0	gpTreasureClassEx : D2TCExShortStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C5F0	+0x09C0	4	placeholder pTreasureClassEx+0x4	gnTreasureClassEx : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C5F4	+0x09C4	180	placeholder pTreasureClassEx+0x8	gpChestTreasureClasses : D2TCExShortStrc* [3][5][3] : D2Common/DATATBLS/MonsterTbls.cpp; gpChestTreasureClasses : D2TCExShortStrc* [45] : D2Common/SKILLS/Skills.cpp
0x0096C6A8	+0x0A78	4	D2MonStatsTxt* pMonStatsTxt	gpMonstatsTxt : D2MonStatsTxt* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C6AC	+0x0A7C	4	D2TxtLinkStrc* pMonStatsLinker	gpMonStatsLinker : D2TxtLinkStrc* : D2Common/D2Common.h; gpMonStatsLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C6B0	+0x0A80	4	int nMonStatsTxtRecordCount	gnMonstatsTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C6B4	+0x0A84	4	void* pMonSoundsTxt	gpMonsoundsTxt : D2MonSoundsTxt* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C6B8	+0x0A88	4	D2TxtLinkStrc* pMonSoundsLinker	gpMonSoundsLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C6BC	+0x0A8C	4	int nMonSoundsTxtRecordCount	gnMonsoundsTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C6C0	+0x0A90	4	D2MonStats2Txt* pMonStats2Txt	gpMonTable_96C6C0 : void* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C6C4	+0x0A94	8	D2TxtLinkStrc* pMonStats2Linker	gpMonStats2Linker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C6CC	+0x0A9C	4	void* pMonPlaceTxt	gpMonPlaceTxt : void* : D2Common/DATATBLS/DataTbls.cpp
0x0096C6D0	+0x0AA0	8	D2TxtLinkStrc* pMonPlaceLinker	gpMonPlaceLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpMonPlaceLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C6D8	+0x0AA8	4	placeholder pMonPresetTxt+0x0	gpMonPresetTxt : D2MonPresetTxt* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C6DC	+0x0AAC	20	placeholder pMonPresetTxt+0x4	gpMonPresetTxtActSections : D2MonPresetTxt* [5] : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C6F0	+0x0AC0	20	placeholder pMonPresetTxt+0x18	gnMonPresetTxtActRecordCounts : int [5] : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C704	+0x0AD4	4	D2SuperUniquesTxt* pSuperUniquesTxt	gpSuperUniquesTxt : D2SuperUniquesTxt* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C708	+0x0AD8	4	D2TxtLinkStrc* pSuperUniquesLinker	gpSuperUniquesLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C70C	+0x0ADC	140	int nSuperUniquesTxtRecordCount	gnSuperUniquesTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C798	+0x0B68	8	D2TxtLinkStrc* pMissilesLinker	gTxtLink_0096C798 : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp; gpMissilesLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpMissilesLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp; gpMissilesLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MissileTbls.cpp; gpMissilesLinker : D2TxtLinkStrc* : D2Common/Logging/ProfCore.cpp
0x0096C7A0	+0x0B70	4	D2MonLvlTxt* pMonLvlTxt	gpMonlvlTxt : void* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C7A4	+0x0B74	4	int nMonLvlTxtRecordCount	gnMonlvlTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C7A8	+0x0B78	4	placeholder pMonSeqTxt+0x0	gpMonseqTxt : D2AnimSeqTxt* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C7AC	+0x0B7C	4	placeholder pMonSeqTxt+0x4	gpMonSeqLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp; gpMonTableLinker_96C7AC : D2TxtLinkStrc* : D2Common/D2Common.h
0x0096C7B0	+0x0B80	4	placeholder pMonSeqTxt+0x8	gnMonseqTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C7B4	+0x0B84	4	placeholder pMonSeqTxt+0xC	gpMonSeqTable : D2AnimSeqRecordStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C7B8	+0x0B88	4	placeholder pMonSeqTxt+0x10	gnMonSeqTableRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C7BC	+0x0B8C	4	D2SkillDescTxt* pSkillDescTxt	gpSkillDescTxt : void* : D2Common/DATATBLS/DataTbls.cpp; gpSkillDescTxt : void* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C7C0	+0x0B90	4	D2TxtLinkStrc* pSkillDescLinker	gpSkillDescLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpSkillDescLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C7C4	+0x0B94	4	int nSkillDescTxtRecordCount	gnSkillDescTxtRecordCount : int : D2Common/DATATBLS/DataTbls.cpp; gnSkillDescTxtRecordCount : int : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C7C8	+0x0B98	4	D2SkillsTxt* pSkillsTxt	gpSkillsTxt : D2SkillsTxt* : D2Common/DATATBLS/DataTbls.cpp; gpSkillsTxt : D2SkillsTxt* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C7CC	+0x0B9C	4	D2TxtLinkStrc* pSkillsLinker	gTxtLink_0096C7CC : D2TxtLinkStrc* : D2Common/D2Common.h; gpSkillsLinker_0096C7CC : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpSkillsLinker_0096C7CC : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp; gpSkillsLinker_0096C7CC : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp; gpSkillsLinker_0096C7CC : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp; gpSkillsLinker_0096C7CC : D2TxtLinkStrc* : D2Common/Logging/ProfCore.cpp
0x0096C7D0	+0x0BA0	4	int nSkillsTxtRecordCount	gnSkillsTxtRecordCount : int : D2Common/DATATBLS/DataTbls.cpp; gnSkillsTxtRecordCount : int : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C7D4	+0x0BA4	4	int* nClassSkillCount	gpClassSkillCount : int* : D2Common/DATATBLS/DataTbls.cpp; gpClassSkillCount : int* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C7D8	+0x0BA8	4	int nHighestClassSkillCount	gnHighestClassSkillCount : int : D2Common/DATATBLS/DataTbls.cpp; gnHighestClassSkillCount : int : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C7DC	+0x0BAC	4	short* nClassSkillList	gpClassSkillList : short* : D2Common/DATATBLS/DataTbls.cpp; gpClassSkillList : short* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C7E0	+0x0BB0	4	int nPassiveSkills	gnPassiveSkills : int : D2Common/DATATBLS/DataTbls.cpp; gnPassiveSkills : int : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C7E4	+0x0BB4	4	unsigned short* pPassiveSkills	gpPassiveSkills : short* : D2Common/DATATBLS/DataTbls.cpp; gpPassiveSkills : short* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C7E8	+0x0BB8	12	D2TxtLinkStrc* pOverlayLinker	gpOverlayLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpOverlayLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C7F4	+0x0BC4	4	D2CharStatsTxt* pCharStatsTxt	gpCharstatsTxt : int : D2CMP/SRC/CelCmp.cpp; gpCharstatsTxt : void* : D2Common/D2Common.h
0x0096C7F8	+0x0BC8	4	int nCharStatsTxtRecordCount	gnCharstatsTxtRecordCount : int : D2Common/DATATBLS/DataTbls.cpp
0x0096C7FC	+0x0BCC	4	D2ItemStatCostTxt* pItemStatCostTxt	gpItemStatCostTxt : D2ItemStatCostTxt* : D2Common/DATATBLS/ItemTbls.cpp
0x0096C800	+0x0BD0	4	D2TxtLinkStrc* pItemStatCostLinker	gTxtLink_0096C800 : D2TxtLinkStrc* : D2Common/D2Common.h; gpItemStatCostLinker : D2TxtLinkStrc* : D2Common/D2Common.h; gpItemStatCostLinker_0096C800 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpItemStatCostLinker_0096C800 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp; gpItemStatCostLinker_0096C800 : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096C804	+0x0BD4	4	int nItemStatCostTxtRecordCount	gnItemStatCostTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096C808	+0x0BD8	4	short* pStatsWithDescFunc	gpStatsWithDescFunc : unsigned short* : D2Common/DATATBLS/ItemTbls.cpp
0x0096C80C	+0x0BDC	4	int nStatsWithDescFunc	gnStatsWithDescFunc : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096C810	+0x0BE0	4	D2MonEquipTxt* pMonEquipTxt	gpMonEquipTxt : D2MonEquipTxt* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C814	+0x0BE4	4	int nMonEquipTxtRecordCount	gnMonEquipTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C818	+0x0BE8	4	D2PetTypeTxt* pPetTypeTxt	gpPettypeTxt : void* : D2Common/D2Common.h; gpPettypeTxt_0096C818 : D2PetTypeTxt* : D2Common/DATATBLS/DataTbls.cpp; gpPettypeTxt_0096C818 : D2PetTypeTxt* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C81C	+0x0BEC	4	D2TxtLinkStrc* pPetTypeLinker	gTxtLink_0096C81C : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpPettypeLinker : D2TxtLinkStrc* : D2Common/D2Common.h; gpPettypeLinker : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C820	+0x0BF0	4	int nPetTypeTxtRecordCount	gnPettypeTxtRecordCount : int : D2Common/DATATBLS/DataTbls.cpp; gnPettypeTxtRecordCount : int : D2Common/DATATBLS/DataTbls_00613F80.cpp
0x0096C824	+0x0BF4	4	D2TxtLinkStrc* pItemTypesLinker	gpItemTypesLinker : D2TxtLinkStrc* : D2Common/D2Common.h; gpItemTypesLinker_0096C824 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls.cpp; gpItemTypesLinker_0096C824 : D2TxtLinkStrc* : D2Common/DATATBLS/DataTbls_00613F80.cpp; gpItemTypesLinker_0096C824 : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp; gpItemTypesLinker_0096C824 : D2TxtLinkStrc* : D2Common/Unknown_00668510.cpp
0x0096C828	+0x0BF8	4	D2ItemTypesTxt* pItemTypesTxt	gpItemTypesTxt_0096C828 : D2ItemTypesTxt* : D2Common/DATATBLS/DataTbls.cpp; gpItemTypesTxt_0096C828 : D2ItemTypesTxt* : D2Common/DATATBLS/ItemTbls.cpp; gp_0096C828 : void* : D2Common/DATATBLS/ItemTbls.cpp
0x0096C82C	+0x0BFC	4	int nItemTypesTxtRecordCount	gnItemTypesTxtRecordCount_0096C82C : int : D2Common/DATATBLS/DataTbls.cpp; gnItemTypesTxtRecordCount_0096C82C : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096C830	+0x0C00	4	int nItemTypesIndex	gnItemTypesIndex : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096C834	+0x0C04	4	unsigned int* pItemTypesEquivalenceLUTs	gpItemTypesEquivalenceLUTs : void* : D2Common/DATATBLS/ItemTbls.cpp; gpItemTypesEquivalenceLUTs_0096C834 : unsigned int* : D2Common/DATATBLS/ItemTbls.cpp
0x0096C838	+0x0C08	4	D2TxtLinkStrc* pSetsLinker	gpSetsLinker : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096C83C	+0x0C0C	4	D2SetsTxt* pSetsTxt	gpSetsTxt : void* : D2Common/DATATBLS/ItemTbls.cpp
0x0096C840	+0x0C10	4	int nSetsTxtRecordCount	gnSetsTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096C844	+0x0C14	4	D2TxtLinkStrc* pSetItemsLinker	gpSetItemsLinker : D2TxtLinkStrc* : D2Common/D2Common.h; gpSetItemsLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C848	+0x0C18	4	D2SetItemsTxt* pSetItemsTxt	gpSetItemsTxt : void* : D2Common/D2Common.h; gpSetItemsTxt : void* : D2Common/DATATBLS/MonsterTbls.cpp; gpSetItemsTxt_0096C848 : D2SetItemsTxt* : D2Common/Unknown_00668510.cpp
0x0096C84C	+0x0C1C	4	int nSetItemsTxtRecordCount	gnSetItemsTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096C850	+0x0C20	4	D2TxtLinkStrc* pUniqueItemsLinker	gpUniqueItemsLinker : D2TxtLinkStrc* : D2Common/D2Common.h; gpUniqueitemsLinker : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096C854	+0x0C24	4	D2UniqueItemsTxt* pUniqueItemsTxt	gpUniqueItemsTxt : void* : D2Common/D2Common.h; gpUniqueItemsTxt_0096C854 : D2UniqueItemsTxt* : D2Common/Unknown_00668510.cpp; gpUniqueitemsTxt : D2UniqueItemsTxt* : D2Common/DATATBLS/ItemTbls.cpp
0x0096C858	+0x0C28	4	int nUniqueItemsTxtRecordCount	gnUniqueitemsTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096C85C	+0x0C2C	4	D2TxtLinkStrc* pMonPropLinker	gpMonPropLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C860	+0x0C30	4	void* pMonPropTxt	gpMonpropTxt : void* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C864	+0x0C34	4	int nMonPropTxtRecordCount	gnMonpropTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C868	+0x0C38	4	D2TxtLinkStrc* pMonTypeLinker	gpMonTypeLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp; gpMonTypeLinker_0096C868 : D2TxtLinkStrc* : D2Common/DATATBLS/ItemTbls.cpp
0x0096C86C	+0x0C3C	4	D2MonTypeTxt* pMonTypeTxt	gpMonTypeTxt : D2MonTypeTxt* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C870	+0x0C40	4	int nMonTypeTxtRecordCount	gnMonTypeTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C874	+0x0C44	4	unsigned int* pMonTypeNest	gpMonTypeNest : unsigned int* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C878	+0x0C48	4	int nMonTypeIndex	gnMonTypeIndex : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C87C	+0x0C4C	4	D2TxtLinkStrc* pMonUModLinker	gpMonUModLinker : D2TxtLinkStrc* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C880	+0x0C50	4	D2MonUModTxt* pMonUModTxt	gpMonumodTxt : void* : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C884	+0x0C54	12	int nMonUModTxtRecordCount	gnMonumodTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C890	+0x0C60	4	void* pLevelDefBin	gpLevelDefBin : D2LevelDefBin* : D2Common/DATATBLS/LvlTbls.cpp
0x0096C894	+0x0C64	8	D2LvlPrestTxt* pLvlPrestTxt	gpLvlPrestTxt : D2LvlPrestTxt* : D2Common/DATATBLS/LvlTbls.cpp
0x0096C89C	+0x0C6C	4	int nStuff	gnItemStatCostStuff : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096C8A0	+0x0C70	4	int nShiftedStuff	gnItemStatCostStuffMask : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096C8A4	+0x0C74	4	void* pAnimData	gpAnimData : D2AnimDataTableStrc* : D2Common/DATATBLS/DataTbls.cpp; gpAnimData : int : D2CMP/SRC/CelCmp.cpp
0x0096C8A8	+0x0C78	4	placeholder pExperienceTxt+0x0	gpExperienceTxt : D2ExperienceDataTbl* : D2Common/Chat/Ignorelist.cpp; gpExperienceTxt : D2ExperienceDataTbl* : D2Common/DATATBLS/DataTbls.cpp
0x0096C8AC	+0x0C7C	4	placeholder pExperienceTxt+0x4	gpDifficultylevelsTxt : D2DifficultyLevelsTxt* : D2Common/DATATBLS/DataTbls.cpp
0x0096C8B0	+0x0C80	4	placeholder pExperienceTxt+0x8	gnDifficultylevelsTxtRecordCount : int : D2Common/DATATBLS/DataTbls.cpp
0x0096C8B4	+0x0C84	4	int bCompileTxt	gbCompileTxt : int : D2Common/Chat/Ignorelist.cpp; gbCompileTxt : int : D2Common/DATATBLS/DataTbls.cpp; gbCompileTxt : int : D2Common/DATATBLS/DataTbls_00613F80.cpp; gbCompileTxt : int : D2Common/DATATBLS/ItemTbls.cpp; gnSoundsGuard : int : D2Common/DATATBLS/MonsterTbls.cpp
0x0096C8B8	+0x0C88	4	placeholder unk0xC88+0x0	gStatsClientAllocatedRooms : int : D2Common/DUNGEON/Dungeon.cpp; gStatsClientAllocatedRooms : int : D2Common/ENVIRONMENT/Env.cpp; gStatsClientAllocatedRooms : static int : D2Common/DRLG/DrlgActivate.cpp; gnRoomStats_0096C8B8 : static int : D2Common/DRLG/DrlgActivate.cpp; gnStatsClientAllocatedRooms : static int : D2Common/DRLG/DrlgActivate.cpp
0x0096C8BC	+0x0C8C	4	placeholder unk0xC88+0x4	gStatsClientFreedRooms : int : D2Common/DUNGEON/Dungeon.cpp; gStatsClientFreedRooms : int : D2Common/ENVIRONMENT/Env.cpp; gStatsClientFreedRooms : static int : D2Common/DRLG/DrlgActivate.cpp; gnRoomStats_0096C8BC : static int : D2Common/DRLG/DrlgActivate.cpp; gnStatsClientFreedRooms : static int : D2Common/DRLG/DrlgActivate.cpp
0x0096C8C0	+0x0C90	4	placeholder unk0xC88+0x8	gStatsFreedRooms : int : D2Common/DUNGEON/Dungeon.cpp; gStatsFreedRooms : int : D2Common/ENVIRONMENT/Env.cpp; gStatsFreedRooms : static int : D2Common/DRLG/DrlgActivate.cpp; gnRoomStats_0096C8C0 : static int : D2Common/DRLG/DrlgActivate.cpp; gnStatsFreedRooms : static int : D2Common/DRLG/DrlgActivate.cpp
0x0096C8C4	+0x0C94	12	placeholder unk0xC88+0xC	gStatsAllocatedRooms : int : D2Common/DUNGEON/Dungeon.cpp; gStatsAllocatedRooms : int : D2Common/ENVIRONMENT/Env.cpp; gStatsAllocatedRooms : static int : D2Common/DRLG/DrlgActivate.cpp; gnRoomStats_0096C8C4 : static int : D2Common/DRLG/DrlgActivate.cpp; gnStatsAllocatedRooms : static int : D2Common/DRLG/DrlgActivate.cpp
0x0096C8D0	+0x0CA0	288	placeholder unk0xC88+0x18	gaAutomapIndex : D2AutomapIndexStrc [36] : D2Common/DATATBLS/LvlTbls.cpp
0x0096C9F0	+0x0DC0	4	D2LvlTypesTxt* pLvlTypesTxt	gpLvlTypesTxt : D2LvlTypesTxt* : D2Common/DATATBLS/LvlTbls.cpp; gpLvlTypesTxt_0096C9F0 : static D2LvlTypesTxt* : D2Common/DATATBLS/LvlTbls.cpp
0x0096C9F4	+0x0DC4	4	placeholder unk0xDC4+0x0	gpPortalLevels : int* : D2Common/DATATBLS/LvlTbls.cpp; gpPortalLevels_0096C9F4 : static int* : D2Common/DATATBLS/LvlTbls.cpp
0x0096C9F8	+0x0DC8	4	placeholder unk0xDC4+0x4	gnPortalLevels : int : D2Common/DATATBLS/LvlTbls.cpp; gnPortalLevels_0096C9F8 : static int : D2Common/DATATBLS/LvlTbls.cpp
0x0096C9FC	+0x0DCC	4	int nLvlTypesTxtRecordCount	gnLvlTypesTxtRecordCount : static int : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA00	+0x0DD0	4	placeholder unk0xDD0+0x0	gpLvlWarpTxt : D2LvlWarpTxt* : D2Common/DATATBLS/LvlTbls.cpp; gpLvlwarpTxt : void* : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA04	+0x0DD4	4	placeholder unk0xDD0+0x4	gnLvlwarpTxtRecordCount : int : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA08	+0x0DD8	4	placeholder unk0xDD0+0x8	gpLvlMazeTxt : D2LvlMazeTxt* : D2Common/DATATBLS/LvlTbls.cpp; gpLvlmazeTxt : void* : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA0C	+0x0DDC	4	placeholder unk0xDD0+0xC	gnLvlmazeTxtRecordCount : int : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA10	+0x0DE0	4	D2LvlSubTxt* pLvlSubTxt	gpLvlSubTxt : D2LvlSubTxt* : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA14	+0x0DE4	4	int nLvlSubTxtRecordCount	gnLvlSubTxtRecordCount : int : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA18	+0x0DE8	4	int* pLvlSubTypeStartIds	gpLvlSubTypeStartIds : int* : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA1C	+0x0DEC	4	placeholder unk0xDEC+0x0	gppTileLibraryHash : void* : D2Common/DATATBLS/LvlTbls.cpp; gppTileLibraryHash_0096CA1C : static D2TileLibraryHeaderStrc** : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA20	+0x0DF0	4	D2DrlgFileStrc** ppLvlPrestFiles	gppLvlPrestDrlgFiles : D2DrlgFileStrc** : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA24	+0x0DF4	4	D2DrlgFileStrc** ppLvlSubTypeFiles	gppLvlSubDrlgFiles : D2DrlgFileStrc** : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA28	+0x0DF8	4	placeholder unk0xDF8+0x0	gpAutomapRecords : D2AutomapRecordStrc* : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA2C	+0x0DFC	4	placeholder unk0xDF8+0x4	gnAutomapRecordCount : int : D2Common/DATATBLS/LvlTbls.cpp
0x0096CA30	+0x0E00	24	placeholder unk0xDF8+0x8	gLogLock : D2CriticalSectionStrc : D2Common/Logging/Logging.cpp
0x0096CA48	+0x0E18	4	placeholder unk0xDF8+0x20	gpLogFile : _iobuf* : D2Common/Logging/Logging.cpp
0x0096CA4C	+0x0E1C	4	placeholder unk0xDF8+0x24	gbLogEnabled : int : D2Common/Logging/Logging.cpp
0x0096CA50	+0x0E20	8	placeholder unk0xDF8+0x28	gnLogValue : int : D2Common/Logging/Logging.cpp
0x0096CA58	+0x0E28	4	placeholder unk0xDF8+0x30	gItemDataTables : D2ItemDataTbl : D2Common/DATATBLS/ItemTbls.cpp; gnItemsTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA5C	+0x0E2C	4	D2ItemsTxt* pItemsTxt	gpItemsTxt : D2ItemsTxt* : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA60	+0x0E30	4	placeholder unk0xE30+0x0	gpWeaponsTxt : D2ItemsTxt* : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA64	+0x0E34	4	placeholder unk0xE30+0x4	gnWeaponsTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA68	+0x0E38	4	placeholder unk0xE30+0x8	gpArmorTxt : D2ItemsTxt* : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA6C	+0x0E3C	4	placeholder unk0xE30+0xC	gnArmorTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA70	+0x0E40	4	placeholder unk0xE30+0x10	gpMiscTxt : D2ItemsTxt* : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA74	+0x0E44	4	placeholder unk0xE30+0x14	gnMiscTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA78	+0x0E48	4	placeholder unk0xE30+0x18	gpIndexOldToCurrent : unsigned short* : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA7C	+0x0E4C	20	D2MagicAffixDataTbl pMagicAffixDataTables	sgtMagicItemModsDataTblDesc : D2MagicAffixDataTbl : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA90	+0x0E60	4	placeholder unk0xE60+0x0	gGemDataTables : D2GemDataTbl : D2Common/DATATBLS/ItemTbls.cpp; gnGemsTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA94	+0x0E64	4	placeholder unk0xE60+0x4	gpGemsTxt : D2GemsTxt* : D2Common/DATATBLS/ItemTbls.cpp
0x0096CA98	+0x0E68	8	D2RuneDataTbl pRuneDataTables	sgtRuneWordsTblDesc : D2RuneDataTbl : D2Common/DATATBLS/DataTbls.cpp; sgtRuneWordsTblDesc : D2RuneDataTbl : D2Common/DATATBLS/ItemTbls.cpp; sgtRuneWordsTblDesc : D2RuneDataTbl : D2Common/ITEMS/Items.cpp
0x0096CAA0	+0x0E70	16	int nRareAffixTxtRecordCount	sgtRareItemModsDataTblDesc : D2RareAffixDataTbl : D2Common/DATATBLS/ItemTbls.cpp
0x0096CAB0	+0x0E80	408	D2GambleDataTbl pGambleDataTables	gGambleDataTables : D2GambleDataTbl : D2Common/DATATBLS/ItemTbls.cpp
0x0096CC48	+0x1018	4	placeholder unk0x1018+0x0	gItemRatioDataTables : D2ItemRatioDataTbl : D2Common/DATATBLS/ItemTbls.cpp; gnItemratioTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096CC4C	+0x101C	4	placeholder unk0x1018+0x4	gpItemratioTxt : void* : D2Common/DATATBLS/ItemTbls.cpp
0x0096CC50	+0x1020	4	placeholder unk0x1018+0x8	gQualityItemDataTables : D2QualityItemDataTbl : D2Common/DATATBLS/ItemTbls.cpp; gnQualityitemsTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096CC54	+0x1024	4	placeholder unk0x1018+0xC	gpQualityitemsTxt : D2QualityItemsTxt* : D2Common/DATATBLS/ItemTbls.cpp
0x0096CC58	+0x1028	4	placeholder unk0x1018+0x10	gLowQualityItemDataTables : D2LowQualityItemDataTbl : D2Common/DATATBLS/ItemTbls.cpp; gnLowqualityitemsTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096CC5C	+0x102C	4	placeholder unk0x1018+0x14	gpLowqualityitemsTxt : D2LowQualityItemsTxt* : D2Common/DATATBLS/ItemTbls.cpp
0x0096CC60	+0x1030	4	placeholder unk0x1018+0x18	gBookDataTables : D2BookDataTbl : D2Common/DATATBLS/ItemTbls.cpp; gnBooksTxtRecordCount : int : D2Common/DATATBLS/ItemTbls.cpp
0x0096CC64	+0x1034	4	placeholder unk0x1018+0x1C	gpBooksTxt : void* : D2Common/DATATBLS/ItemTbls.cpp
0x0096CC68	+0x1038	2040	placeholder unk0x1018+0x20	gTable_0096CC68 : CodeEntry [] : D2Common/INVENTORY/Inventory.cpp; gaTxtComponentItemTypeMap : static D2InventoryComponentItemTypeStrc [255] : D2Common/INVENTORY/Inventory.cpp
0x0096D460	+0x1830	4	placeholder unk0x1018+0x818	gnComponentArrayRecordCount : static int : D2Common/INVENTORY/Inventory.cpp
0x0096D464	+0x1834	4	placeholder unk0x1018+0x81C	gbComponentArrayInitialized : static int : D2Common/INVENTORY/Inventory.cpp
0x0096D468	+0x1838	4	placeholder unk0x1018+0x820	gpShrinesTxt : D2ShrinesTxt* : D2Common/DATATBLS/MonsterTbls.cpp; gpShrinesTxt : D2ShrinesTxt* : D2Common/DRLG/Drlg.cpp
0x0096D46C	+0x183C	4	placeholder unk0x1018+0x824	gnShrinesTxtRecordCount : int : D2CMP/SRC/CelCmp.cpp; gnShrinesTxtRecordCount : int : D2Common/D2Common.h
0x0096D470	+0x1840	4	placeholder unk0x1018+0x828	gpObjectsTxt : D2ObjectsTxt* : D2Common/DATATBLS/DataTbls.cpp; gpObjectsTxt : D2ObjectsTxt* : D2Common/DATATBLS/MonsterTbls.cpp; gpObjectsTxt : D2ObjectsTxt* : D2Common/Unknown_0063F690.cpp
0x0096D474	+0x1844	4	placeholder unk0x1018+0x82C	gnObjectsTxtRecordCount : int : D2Common/D2Common.h; gnObjectsTxtRecordCount : int : D2Common/Unknown_0063F690.cpp
0x0096D478	+0x1848	4	placeholder unk0x1018+0x830	gpObjgroupTxt : D2ObjGroupTxt* : D2Common/DRLG/Drlg.cpp; gpObjgroupTxt : void* : D2Common/DATATBLS/MonsterTbls.cpp; gpObjgroupTxt : void* : D2Common/Unknown_0063F690.cpp; gpObjgroupTxt : void* : D2Common/Unknown_00640F20.cpp
0x0096D47C	+0x184C	4	placeholder unk0x1018+0x834	gnObjgroupTxtRecordCount : int : D2Common/DATATBLS/MonsterTbls.cpp; gnObjgroupTxtRecordCount : int : D2Common/DRLG/Drlg.cpp; gnObjgroupTxtRecordCount : int : D2Common/Unknown_0063F690.cpp; gnObjgroupTxtRecordCount : int : D2Common/Unknown_00640F20.cpp
0x0096D480	+0x1850	8	placeholder unk0x1018+0x838	gMonItemPercentDataTables : D2MonItemPercentDataTbl : D2Common/DATATBLS/MonsterTbls.cpp
0x0096D488	+0x1858	16	placeholder unk0x1018+0x840	gUniqueNameTables : D2UniqueNameTablesStrc : D2Common/DATATBLS/MonsterTbls.cpp; gpUniqueNameTxtTables : D2UniqueNameTxt* [4] : D2Common/DATATBLS/MonsterTbls.cpp; gpUniqueNameTxtTables : D2UniqueNameTxt* [4] : D2Common/DUNGEON/Dungeon.cpp
0x0096D498	+0x1868	24	placeholder unk0x1018+0x850	gnUniqueNameTxtRecordCounts : int [4] : D2Common/DATATBLS/MonsterTbls.cpp; gnUniqueNameTxtRecordCounts : int [4] : D2Common/DUNGEON/Dungeon.cpp
0x0096D4B0	+0x1880	4	placeholder unk0x1018+0x868	gnTreasureClassItemTypes : int : D2Common/DATATBLS/MonsterTbls.cpp; gwTreasureClassItemTypes : unsigned short : D2Common/DATATBLS/MonsterTbls.cpp
0x0096D4B4	+0x1884	4	placeholder unk0x1018+0x86C	gwszDataTablesDefault : Unicode : D2Common/DATATBLS/MonsterTbls.cpp; gwszDataTablesDefault : Unicode : D2Common/DUNGEON/Dungeon.cpp
0x0096D4B8	+0x1888	4	placeholder unk0x1018+0x870	gMonModeDataTables : D2MonModeDataTbl : D2Common/DATATBLS/TokTbls.cpp; gnMonmodeTxtRecordCount : int : D2Common/DATATBLS/TokTbls.cpp
0x0096D4BC	+0x188C	4	placeholder unk0x1018+0x874	gpMonmodeTxt : void* : D2Common/DATATBLS/TokTbls.cpp
0x0096D4C0	+0x1890	4	placeholder unk0x1018+0x878	gpMonmodeTxtAlias1 : void* : D2Common/DATATBLS/TokTbls.cpp
0x0096D4C4	+0x1894	4	placeholder unk0x1018+0x87C	gpMonmodeTxtAlias2 : void* : D2Common/DATATBLS/TokTbls.cpp
0x0096D4C8	+0x1898	4	placeholder unk0x1018+0x880	gObjModeDataTables : D2ObjModeDataTbl : D2Common/DATATBLS/TokTbls.cpp; gnObjModeTypeTxtRecordCount : int : D2Common/DATATBLS/TokTbls.cpp
0x0096D4CC	+0x189C	4	placeholder unk0x1018+0x884	gpObjModeTypeTxt : D2ObjModeTypeTxt* : D2Common/DATATBLS/TokTbls.cpp
0x0096D4D0	+0x18A0	4	placeholder unk0x1018+0x888	gpObjType : D2ObjModeTypeTxt* : D2Common/DATATBLS/TokTbls.cpp
0x0096D4D4	+0x18A4	4	placeholder unk0x1018+0x88C	gpObjMode : D2ObjModeTypeTxt* : D2Common/DATATBLS/TokTbls.cpp
0x0096D4D8	+0x18A8	16	placeholder unk0x1018+0x890	gPlrModeDataTables : D2PlrModeDataTbl : D2Common/DATATBLS/TokTbls.cpp
0x0096D4E8	+0x18B8	4	placeholder unk0x1018+0x8A0	gpArmTypeTxt : D2TokRecord* : D2Common/DATATBLS/TokTbls.cpp
0x0096D4EC	+0x18BC	4	placeholder unk0x1018+0x8A4	gpCompositTxt : D2TokRecord* : D2Common/DATATBLS/TokTbls.cpp
0x0096D4F0	+0x18C0	4	placeholder unk0x1018+0x8A8	gnInventoryTxtRecordCount : int : D2Common/DATATBLS/InvTbls.cpp; gnTable96D4F4RecordCount : unsigned int : D2Common/DATATBLS/InvTbls.cpp
0x0096D4F4	+0x18C4	4	placeholder unk0x1018+0x8AC	gpInventoryTxt : void* : D2Common/DATATBLS/InvTbls.cpp; gpTable96D4F4 : D2Table96D4F4Record* : D2Common/DATATBLS/InvTbls.cpp
0x0096D4F8	+0x18C8	8	placeholder unk0x1018+0x8B0	sgptBeltInitStats : D2BeltsTxt* : D2Common/DATATBLS/BeltTbls.cpp
0x0096D500	+0x18D0	256	placeholder unk0x1018+0x8B8	gnCharTemplateStartIds : int [64] : D2Common/DATATBLS/Arena.cpp
0x0096D600	+0x19D0	4	placeholder unk0x1018+0x9B8	gpCharTemplateTxtTable : D2CharTemplateTxt* : D2Common/DATATBLS/Arena.cpp
0x0096D604	+0x19D4	4	placeholder unk0x1018+0x9BC	gnCharTemplateTxtTableRecordCount : int : D2Common/DATATBLS/Arena.cpp
0x0096D608	+0x19D8	4	placeholder unk0x1018+0x9C0	gpArenaTxtTable : D2ArenaTxt* : D2Common/DATATBLS/Arena.cpp
0x0096D60C	+0x19DC	4	placeholder unk0x1018+0x9C4	gpLevelFilesList : D2LevelFileListStrc* : D2Common/DRLG/Preset.cpp
0x0096D610	+0x19E0	68	placeholder unk0x1018+0x9C8	gLevelFilesCriticalSection : CCritSect : D2Common/DRLG/Preset.cpp; gLevelFilesCriticalSection : unsigned char [] : Storm/Storm.h
0x0096D654	+0x1A24	4	unsigned char* pFieldData	gpFieldData : unsigned char* : D2Common/DATATBLS/FieldTbls.cpp
0x0096D658	+0x1A28	20	D2CollisionFieldStrc pCollisionField	gtCollisionField : D2CollisionFieldStrc : D2Common/DATATBLS/FieldTbls.cpp
```
