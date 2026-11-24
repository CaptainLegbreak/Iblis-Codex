# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/chat-head 070da39c no placeholder change: chat.cpp's object starts at 0x47A980. Roster.cpp's 0x4799C0 calls CHAT_IsNumberDisplayEnabled (0x47A980) instead of inlining it, so that accessor is in another file, and chat.cpp's functions follow it. The client flag and colour temperature accessors 0x47A990-0x47AA20 (from dLightMap.cpp and Roster.cpp) join chat.cpp, with four strays inside chat.cpp's run (from inv.cpp and Gfx.cpp) and ROSTERPETS_HandleImeStartComposition (0x47ACA0). chat.cpp names its IME flag once (gbImeOpen) instead of three ways. chat.cpp's copy 0x712F08 joins it. VERIFIED 8e6e409a2e5d on #326; rebased onto #329 (plan replayed; precheck equal). Not stacked; nothing outside lane 4.

- lane4/automap-join 8e7089df -3 placeholders (Unknown_004574D0.cpp, Unknown_00457900.cpp, Unknown_004579E0.cpp empty): automap.cpp's object starts at AUTOMAP_FreeCaches (0x457420); the functions up to 0x457B00 read its data (gnAutomapScale, gaAutomapPairs, the center/party/party-name flags) or are its step, pivot and cell helpers. automap.cpp takes them from ui.cpp (8, among them sub_00457510, which ui.cpp's gaAutomapHandlers now names), Object.cpp (5), Player.cpp (1) and the three placeholders. Its data starts with its copy 0x711218 (cut from CharSel.cpp's record). OBJECT_SubtractAutomapOffset/OBJECT_ScaleAutomapPoint (0x457810/0x457830) stay in Object.cpp: nothing calls them, the original passes their arguments in registers, and only Object.cpp's emit helper reproduces that. VERIFIED 0bc0ecb0495d on #326; rebased onto #329 (precheck equal). Touches Object.cpp and Player.cpp (lane 1's files; the functions sit in lane 4's address range) and CharSel.cpp's plan record.

- lane4/copies-start-b 2adf5b60 no placeholder change: nine more copies go to the object whose data follows them: 0x70EDD0 to Unknown_0044B400.cpp (gtClientInterface), 0x70EE10 to Game_0044E5A0.cpp (winmain-object below moves it on to WINMAIN.CPP), 0x70F818 to ui.cpp, 0x7222D4 to Hireables.cpp, 0x722318 to panel.cpp, 0x722414 to Unknown_0049B030.cpp, 0x7273A8 to dialog.cpp, 0x727528 to SoundInst.cpp, 0x72756C to editbox.cpp. gpfnConnectPacketHandlers has 26 handlers, not 41. dialog.cpp's data runs from its copy to 0x7274B0 (handlers, the cel name string, gaszDialogCels with its one entry); dialog.cpp's unused emit pointer to DIALOG_LButtonDownMsg goes, since as the file's first initialised global it sat in front of the copy. Copies that start an object with no other data stay put: 0x722298, 0x7274B0, 0x7274EC. Touches Source/D2MCPClient's plan record (gpfnConnectPacketHandlers shrinks); no source there. VERIFIED ecb4f39d87d0 on #326; rebased onto #327 (plan replayed). Not stacked.

- lane4/scmd-data c2b6ce82 no placeholder change: gaPacketTable (0x7114D0) moves from automap.cpp to SCmd.cpp, whose handlers fill it and whose dispatch reads it. The table has 175 entries, not 180; the last 60 B are the copy that starts Unknown_00460420.cpp's data. It renders with SCmd.cpp's own D2PacketTableEntryStrc, so automap.cpp's plan entry loses its 130 handler externs. SCmd.cpp's data starts with its copy at 0x711490 (cut from gszTypeNameAllocRec). The object before it, Unknown_0045B5F0.cpp, owns 0x711430-0x711490: its copy, gnScreenWidth, gnScreenHeight, gnSavedScreenWidth (from text.cpp, inv_0048DD90.cpp, Game.cpp; every includer still builds equal), 8 borrowed bytes at 0x711478 and gszTypeNameAllocRec. Borrowed data -8 B. VERIFIED ee5007665cad on #326; rebased onto #327 (only the plan needed replaying). Not stacked; nothing outside lane 4.

## Claimed

- Verifying, to post when each passes: lane4/text-data, lane4/automap-view (stacked on automap-join), lane4/editbox-split and lane4/winmain-object (both stacked on copies-start-b), lane4/zero-gaps (opaque records take the zero runs after them; npcmenu.cpp's 112 B and more).

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

