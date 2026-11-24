# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/context-sweep 7cb8458b no placeholder change: each of the 127 `// build: context` lines in lane 4's files (46 files; lane 1's two placeholders at 0x4DF1C0/0x4DF6C0 left alone) was tried alone and its unit still builds equal without it, so all go; the copies themselves stay. VERIFIED 5b86859e22ab on #332; rebased onto #339 cleanly (all 46 units build equal). Not stacked; nothing outside lane 4.

- lane4/record-object-2 017e3371 +0 placeholders (Unknown_00451290.cpp grows to the lng object): two objects sit between Game.cpp's template code and SCmd.cpp's, each with its own borrowed copy. (1) 0x451260-0x4513FF, the lng module (register the lng argument, free/load the lng module, load a string with its "Stupid Lng.cpp error." fallback; bss 0x7A0708-0x7A0710; copy 0x70F728): Unknown_00451290.cpp takes 0x451260 from Record.cpp, COMCALLBACK_LoadLngString from ComCallback.cpp and GAME_LoadLngModule from Game.cpp. The error string suggests the original was Lng.cpp; I kept a placeholder since no path names its directory. (2) 0x451400-0x4519CF, Record.cpp: its functions read its bss (0x7A0818-0x7A2788) and gpMsgRecordChunk, which follows its copy at 0x70F764. Record.cpp takes COMCALLBACK_RecordMessage (ComCallback.cpp), five record/playback queries from ui.cpp, three from Game.cpp and CUNIT_ReplayRecords (CUnit.cpp). VERIFIED 19e209068362 on #332; rebased onto #337 (precheck equal). lane4/record-object (071fa3fa) is the same commit on the old base; use -2. Touches ComCallback.cpp (D2Multi, lane 6's file; its two functions sit in lane 4's range) and CUnit.cpp (lane 1's).

- lane4/zero-gaps d062e7b0 no placeholder change: borrowed zero runs right after an opaque record join that record: gaEscMenuUIState (+4), the inventory record at 0x722110 (+4), gaPanelCels (+8), gaNpcEntries (+4), gaNpcMenuEntries (+2), the 0x726C56 record (+12) and fifteen of npcmenu.cpp's NPC menu pieces (+4/+8). A zero-only record of its own compiles into .bss (that is why they were borrowed), so each run joins the non-zero record in front. The zero dwords at 0x70F814, 0x71298C and 0x722314 are not data but padding to 8 bytes in front of ui.cpp's, the level events' and panel.cpp's copies (0x70F818, 0x712990, 0x722318), so their records go. Borrowed data 2,250 B on the verified tree. VERIFIED 9f97ef94248c on #332; rebased onto #335 cleanly (the owners build equal). Not stacked; nothing outside lane 4.

- lane4/winmain-object 70ecd823 no placeholder change: WINMAIN.CPP takes its object, 0x44B440-0x44B8AF. The `.\CORE\WINMAIN.CPP` users sit in it, its asserts run 170-654 (Game.cpp's start at 1502), and its data, from its copy 0x70EE10 (copies-start-b had sent it to Game_0044E5A0.cpp), holds the launch state, default caption, launch state handlers, gaszLaunchModeNames and gbExitApplication, read only by this run and WINMAIN.CPP's initializers. So WINMAIN.CPP takes the 14 functions inside the run filed in Game.cpp, Game_0044B7B0.cpp and Game_0044E5A0.cpp (state push/pop, game name/description/password, hardcore and death flags, exit flag, client info and notify, the launcher loop) and that data; the launch handler table names the Game files' handlers. Game.cpp's data starts with the copy at 0x70EED0 (cut from Game_0044E5A0.cpp's record). VERIFIED 4d7e4b50a72d on #326; rebased onto #333 (plan replayed; precheck equal). Not stacked; nothing outside lane 4.

- lane4/automap-view 427d6c5a no placeholder change (Unknown_0045AE90.cpp grows from 1 to 23 functions): automap.cpp's data and bss end before this run's. Its functions read gaAutomapPairs and the automap flags up to 0x45AC90, while 0x45AD60-0x45B4F0 read their own globals 0x711428/0x71142C after a copy of their own (0x7113EC) and the bss 0x7A5204-0x7A5214. So the run is one more object: the automap draw entry, panel slide and screen offsets, automap offsets and screen-to-map transform, origin update and the room/unit box draws. It gathers from automap.cpp (11), Player.cpp (7), ui.cpp (4), View.cpp (1) and CUnit.cpp (1), with its copy, data and bss. VERIFIED 8b7f75f47156 on #326 (stacked on automap-join, which is in #330); rebased onto #332 (precheck equal). Touches Player.cpp and CUnit.cpp (lane 1's files; the functions sit in lane 4's range).

## Claimed

- Verifying, to post when each passes: lane4/editbox-split (now with the header include for all three copies), lane4/lang-include (10 units take their copy from D2LanguageNames.h; in 11 more the header copy did not place, because their data has no other anchor or does not follow the copy without a gap, so they keep their records), lane4/session-object (Unknown_0044BA20.cpp, 0x44BA20-0x44BDCF between WINMAIN.CPP and Game.cpp).

## Questions

## Notes for other lanes

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

