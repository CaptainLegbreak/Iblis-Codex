# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/text-data 909d80f4 no placeholder change: the copy at 0x722470 starts the waypoint panel's data (Unknown_0049BB40.cpp); gaWaypointActRanges (planned in WardenClient.cpp, read by the panel's 0x49C7F0) follows it and joins it. gnTextTop (0x7225FC), also planned in WardenClient.cpp, is the first global after text.cpp's copy and is read by the text functions, so it joins text.cpp. VERIFIED f92c4dc02676 on #327; rebased onto #332 (plan replayed; the four owners build equal). Not stacked; nothing outside lane 4.

## Claimed

- Verifying, to post when each passes: lane4/automap-view (stacked on automap-join), lane4/editbox-split and lane4/winmain-object (both stacked on copies-start-b), lane4/zero-gaps (opaque records take the zero runs after them; npcmenu.cpp's 112 B and more).

- The object after automap.cpp, 0x45AD60-0x45B4F0 (lane4/automap-view, stacked on automap-join): its own copy 0x7113EC with 0x711428/0x71142C after it, its bss 0x7A5204-0x7A5214; the automap draw, offset and screen-to-map functions now in automap.cpp, Player.cpp, ui.cpp, View.cpp and CUnit.cpp gather into Unknown_0045AE90.cpp.

- editbox.cpp is three objects (lane4/editbox-split): the button classes 0x4BABF0-0x4BB16F (data: copy 0x72756C, gaButtonStrings, the UIWidget/Button type descriptors), editbox.cpp proper 0x4BB170-0x4BBE0F (the `.\UI\editbox.cpp` user; copy 0x727608 and the EditBox descriptors, now borrowed) and the spinner classes 0x4BBE10-0x4BC4F9 (copy 0x727688 and the Spinner descriptors, borrowed). The button and spinner runs become placeholders.

- WINMAIN.CPP's object, 0x44B440-0x44B8AF (lane4/winmain-object, stacked on copies-start-b): the `.\CORE\WINMAIN.CPP` users sit in it, and its launch data (copy 0x70EE10, gnClientLaunchState, gpszDefaultCaption, gaszLaunchModeNames, gbExitApplication) is read only by it and by WINMAIN's initializers. The Game.cpp, Game_0044B7B0.cpp and Game_0044E5A0.cpp functions inside it join WINMAIN.CPP; Game.cpp's data starts at the copy 0x70EED0. (copies-start-b sends 0x70EE10 to Game_0044E5A0.cpp; this corrects it.)

- Record.cpp's object, 0x451260-0x4519CF (lane4/record-object): the lng loader, record chunk, record file, playback and replay functions read Record.cpp's bss (0x7A070C-0x7A2788) and its gpMsgRecordChunk, whose borrowed copy 0x70F764 starts its data. The functions inside the run filed in ComCallback.cpp (2, D2Multi), Game.cpp (4), ui.cpp (5), CUnit.cpp (1) and Unknown_00451290.cpp join Record.cpp.

## Questions

## Notes for other lanes

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

