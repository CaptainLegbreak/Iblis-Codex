# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Handover to lane 1 (D2Client 0x4A0000 and up)

Lane 4 starts nothing new in this range. In flight and staying with lane 4: `editbox-split` (posted ready) and `spellsel-data` (verifying). Everything else here is yours:

- **QuestLog.cpp** (0x4A18F0-0x4A40D0, 29 functions on main). Its object also takes the 0x4A1760-0x4A3410 strays still filed in `UI/text_0049A950.cpp`: 0x4A1760, 0x4A1770, 0x4A1870, 0x4A18C0, 0x4A18E0, 0x4A1910, 0x4A1930, 0x4A2610, 0x4A2630, 0x4A2690, 0x4A26F0, 0x4A27D0, 0x4A2840, 0x4A2A20, 0x4A3020, 0x4A3410 (they sit between QuestLog.cpp's own functions). 0x4A01A0 sits in text.cpp's run (text.cpp ends around 0x4A15xx).
- **QuestLog's layout initializer** 0x6CAC30 (filed in `Storm/Unknown_006CAA30.cpp`) writes 0x7241C8-0x724210. Parked: the struct modelling of that block is not consistent yet, so the initializer can't be rebuilt against it.
- **Key config:** 0x4A4110 (text_0049A950.cpp) is inside the key-config object's run, and text_0049A950.cpp still defines `gnKeyConfigSelected`, which the key-config unit also has as a static. Move both into `Unknown_004A43E0.cpp` together.
- **Unknown_004A6260.cpp** (0x4A6260) and the strays 0x4A6310, 0x4A6350 (text_0049A950.cpp) are one object after the key-config one (0x4A61A0-0x4A63B0).
- **spellsel / levelup:** `Unknown_004A7AE0.cpp` (0x4A7AE0, 0x4A8ED0, 0x4A9260, 0x4A9300, 0x4A9690, 0x4A9870) and 0x4A8A30, 0x4A8CF0 (`Unknown_004A76C0.cpp`) sit in spellsel.cpp's run; check the asserts and data readers before joining.
- **npcmenu area:** 0x4B17A0 and 0x4B1D70 (`Unknown_004A9BD0.cpp`) sit between npcmenu.cpp's and Monster.cpp's functions.
- **SkillDesc:** `UI/SkillDesc.cpp` holds 4 language-table copies (0x72D728, 0x72D994, 0x72D9D0, 0x72DA0C) and `UI/SkillDesc_004E1FF0.cpp` 3 (0x72D8D8, 0x72D914, 0x72D950), so they span 4 and 3 original objects. `Unknown_004DF6C0.cpp` holds 9.
- **Other copies in this range:** text.cpp's 0x724A80, 0x7274B0, 0x7274EC, 0x727528 (all past text.cpp's own data at 0x723768, so they start later objects); `Unknown_004A43E0.cpp` 0x724798, 0x7247D8; useitem.cpp 0x7279B0, 0x7279EC; Wall2.cpp 0x72A96C, 0x72A9A8. 0x7274B0/0x7274EC are ambiguous: I couldn't tie them to code.
- **Borrowed data in the range:** 0x724CD8 (8 zero bytes between Unknown_004A76C0.cpp and Unknown_00499500.cpp), npcmenu.cpp's zero blocks (112 B, 18 blocks; most should join the record in front, as in zero-gaps), 0x726C54, and the editbox/Object.cpp edge (0x727708 is Object.cpp's copy; editbox-split places the other two).

## Ready

- lane4/lang-include 6fc48b40 no placeholder change: ten lane 4 units take their language-table copy from D2LanguageNames.h instead of an opaque record: dLightMap.cpp, Gfx.cpp, Roster.cpp, SoundInst.cpp, Hireables.cpp, Unknown_0044B400.cpp, Unknown_0045B5F0.cpp, Unknown_00477620.cpp, Unknown_00482C70.cpp, Unknown_004A43E0.cpp (in flight before the ownership change; it is lane 1's now). PROVENANCE marks all ten copies `source`. The other eleven lane 4 units with a copy keep their records: their header copy did not place (see the note for lane 2). VERIFIED 9ce5e1676c4f on #332; rebased onto #340 (plan replayed; precheck equal). Not stacked.

- lane4/editbox-split d57e9fa4 +2 placeholders (Unknown_004BABF0.cpp, Unknown_004BBE10.cpp): editbox.cpp is three objects. The copies at 0x72756C, 0x727608 and 0x727688 each start an object's data and are followed by that object's RTTI type descriptors: UIWidget/ButtonImplementation/ButtonWrapper; EditBoxImplementation/EditBoxWrapper; SpinnerImplementation/SpinnerWrapper. The code agrees: button classes 0x4BABF0-0x4BB16F, edit box classes (the only `.\UI\editbox.cpp` users) 0x4BB170-0x4BBE0F, spinner classes 0x4BBE10-0x4BC4F9. The button run becomes Unknown_004BABF0.cpp (with gaButtonStrings; its copy from D2LanguageNames.h), the spinner run Unknown_004BBE10.cpp; each file keeps only its own classes' member definitions and vtable symbol lines. The edit box's and spinner's copies, borrowed until now, get records. Borrowed data 1,707 B on the verified tree (the 0x727608 and 0x727688 blocks are placed now). VERIFIED 25cda9c27395 on #339; rebased onto #340 (plan replayed; precheck equal). Not stacked; nothing outside lane 4.

- lane4/session-object-3 e1168b6a +1 placeholder (Unknown_0044BA20.cpp): the bss runs WINMAIN.CPP's to 0x7A044C, then 0x7A0458-0x7A0630, then Game.cpp's from 0x7A0658. The functions that use the middle block, 0x44BA20-0x44BDCF, are one object of their own: resolution set-up, subsystem start/shutdown, the connect-failed flag, run client, and session start/stop/wait and system packet pumping. Unknown_0044BA20.cpp takes five functions from WINMAIN.CPP and five from Game.cpp, with the bss they define. Its data is the copy at 0x70EE90 alone, which now moves into it (60 B; the 4 zero bytes after it are padding before Game.cpp's 8-aligned copy at 0x70EED0, so they lose their record). Since main moved the MCP packet records into D2McpPackets.h, the file no longer copies them. **Stacked on winmain-object-2** (both edit the same part of WINMAIN.CPP; take them together). VERIFIED 0b594facb878 on #332 before the stack; full verify of the stack on #340 running. lane4/session-object and -2 are superseded. Nothing outside lane 4.

- lane4/context-sweep 7cb8458b no placeholder change: each of the 127 `// build: context` lines in lane 4's files (46 files; lane 1's two placeholders at 0x4DF1C0/0x4DF6C0 left alone) was tried alone and its unit still builds equal without it, so all go; the copies themselves stay. VERIFIED 5b86859e22ab on #332; rebased onto #339 cleanly (all 46 units build equal). Not stacked; nothing outside lane 4.

- lane4/winmain-object-2 b2f157de no placeholder change: WINMAIN.CPP takes its object, 0x44B440-0x44B8AF. The `.\CORE\WINMAIN.CPP` users sit in it, its asserts run 170-654 (Game.cpp's start at 1502), and its data, from its copy 0x70EE10 (copies-start-b had sent it to Game_0044E5A0.cpp), holds the launch state, default caption, launch state handlers, gaszLaunchModeNames and gbExitApplication, read only by this run and WINMAIN.CPP's initializers. So WINMAIN.CPP takes the 14 functions inside the run filed in Game.cpp, Game_0044B7B0.cpp and Game_0044E5A0.cpp (state push/pop, game name/description/password, hardcore and death flags, exit flag, client info and notify, the launcher loop) and that data; the launch handler table names the Game files' handlers. Game.cpp's data starts with the copy at 0x70EED0 (cut from Game_0044E5A0.cpp's record). VERIFIED 4d7e4b50a72d on #326; rebased onto #340: the WINMAIN.CPP conflict with lane 2's D2LaunchRequest.h include keeps both includes, and the launcher function moves with main's current text (D2ConfigStrc, current names); precheck equal. lane4/winmain-object is the old base; use -2. Not stacked; nothing outside lane 4.

## Claimed

- **Cursor object join (claimed):** ENGINE/Cursor.cpp takes its object, 0x467DF0-0x46893F: one bss block (0x7A6AA8-0x7A6B0C) is read by every function in the run and by nothing else, and the run's data is 0x711FB0-0x7121DF (the copy at 0x711FB0, then gaCursorMsgHandlers, gaCursorAnim, gaPanelAnim and the anim counts). It gathers Unknown_00467DF0.cpp, Unknown_00467E40.cpp, Unknown_004681C0.cpp, Unknown_00468730.cpp, Unknown_00468750.cpp, ROSTERPETS_HandleButtonDown/Up (RosterPets.cpp) and three ui.cpp functions.
- **Copy shift at 0x711DA0-0x711FB0 (claimed, plan only):** each copy there starts the data of the object after the one whose file holds it: 0x711DA0 (inside gaOkCancelHandlers) starts Player.cpp's data, 0x711EF4 (Player.cpp's record) CUnit.cpp's, 0x711F54 (CUnit.cpp's) Select.cpp's, and 0x711FB0 (inside gaUnitHoverPriority) the cursor object's. The readers agree: Player reads 0x711DDC, CUnit 0x711F30-0x711F50, Select 0x711F90-0x711F98, Cursor 0x711FEC. Lane 1: this moves two records between your Player.cpp and CUnit.cpp, plan only.
- Verifying: lane4/spellsel-data (gaSkillIconCels to spellsel.cpp; in flight from before the ownership change), then the session-object-3 stack.

## Questions

## Notes for other lanes

- Lane 2, all lanes (D2LanguageNames.h): a header copy is placed only when its unit's .data section places as a whole, that is when the unit has other planned data right after the copy and nothing elsewhere in the same section. Of 21 lane 4 units, 11 got their copy borrowed instead: units whose .data is the copy alone (PalShift.cpp), units that also hold a record far away (View.cpp holds 0x723F38), or a zero record next to it. The full verify still passes, so check the borrowed figure (or PROVENANCE's `copied` runs at the copy) after converting.

- Lane 1: the borrowed copy at 0x727708 starts Object.cpp's data (the spinner object's data ends with its RTTI at 0x727708; then come the copy, the 22-int table at 0x727744 and gnShrineHandlerCount at 0x72779C). Object.cpp can take it from D2LanguageNames.h if nothing of Object.cpp's comes before it.

- Lane 1: 0x721CDC, the borrowed copy after WardenClient's data, starts UnitMode.cpp's data by the code order (WardenClient 0x47F8B0, UnitMode 0x480490, SoundHdr 0x481840). Yours to define.

- Lane 1: the copy at 0x724D3C starts the data of the object after the skill tree, which by the data that follows (gpfnUModCallbacks, 0x724D78) is MonUnique.cpp. 14 of its pointers sit inside gaSkillTabX (planned as int[12][3], 144 B; the table itself is 88 B) and the 15th is gData_00724D74, left in Unknown_00499500.cpp. I'm not moving them into your file.

- Coordinator, lane 3: WardenClient's RTTI (0x700140-0x70018C: object locator, class hierarchy, base class array and descriptor) has come from the compiler since warden-class (#307); PROVENANCE marks it `source`. 0x70018C-0x7001C0 is UIWidget's (type descriptor 0x7275B0), also `source` now. Nothing left to take there.
- Lane 1: D2Client.h line 847 still declares 0x4DF6C0 as `sub_004DF6C0(int nArg)`; nothing in lane 4 uses it.
- Lane 2: `D2ClientTypes.h`'s `D2GfxDataStrc` holds its 20 entries as byte pairs because moving `D2GfxEntryStrc` out of D2Client.h changes code in useitem.cpp and inv_0048DD90.cpp.

## Left in place (and why)

- WardenClient.cpp still holds six strays whose neighbours are two different files: 0x479230 (Unknown_00478D10/Roster.cpp), 0x4922A0 (inv_00491D20/inv_0048DD90), 0x4936E0 (Hireables.cpp/Unknown_00493760), 0x496B10-0x496BE0 (Hireables.cpp/panel.cpp), 0x4E6560 (Unknown_004E2320/Missile.cpp). 0x4A1320 (the text panel opener) belongs to the text unit by its data (gnTextTop 0x7225FC), but it brings the text panel globals WardenClient.cpp defines (gnHintId, gpTextBox and others under different types); that move needs those globals sorted first.

- Game.cpp subsets of Unknown_0044F9B0/Unknown_0044F9D0 (0x44F9D0-0x450F70): the placeholders define Storm list/hash-table template members that Game.cpp already declares differently; merging them needs one definition of those templates first.
- Unknown_00469420 (CmdTbl.cpp's run): CmdTbl.cpp's 0x469C20 calls it in the original, and in CmdTbl.cpp it would be inlined.
- Unknown_0045AE90 (ui.cpp's run): ui.cpp would inline it into a caller the original calls it from.
- Unknown_004A6260 (text run): its callers 0x4A6310/0x4A6350 are in text_0049A950.cpp, which defines `gnKeyConfigSelected`; text.cpp has its own static one. The two definitions need sorting out first.
- Unknown_00450520 (View.cpp's run): Storm hash table template destructors; not placing compiler-generated template code by run evidence.
- Unknown_0047C420 (0x47C420): in chat.cpp it compiles with different registers; cause not found yet.
- WardenClient.cpp 0x47F8B0-0x47F990 and Unknown_0047F950: no assert; they sit on the chat/Warden boundary just before 0x47FA20.
- Weather block 0x472210-0x473F50: no assert path or data reference names its file yet.
- Unknown_0046C7D0: Gfx.cpp would inline its functions into 0x46CE40 and 0x46D780.
- Hireables.cpp's four placeholders (0x493A00, 0x493B50, 0x493CE0, 0x493E10): they disagree on the pet-icon helpers' argument order; aligning the calls made seven functions differ.

