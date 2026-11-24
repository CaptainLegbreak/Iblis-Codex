# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/automap-view 427d6c5a no placeholder change (Unknown_0045AE90.cpp grows from 1 to 23 functions): automap.cpp's data and bss end before this run's. Its functions read gaAutomapPairs and the automap flags up to 0x45AC90, while 0x45AD60-0x45B4F0 read their own globals 0x711428/0x71142C after a copy of their own (0x7113EC) and the bss 0x7A5204-0x7A5214. So the run is one more object: the automap draw entry, panel slide and screen offsets, automap offsets and screen-to-map transform, origin update and the room/unit box draws. It gathers from automap.cpp (11), Player.cpp (7), ui.cpp (4), View.cpp (1) and CUnit.cpp (1), with its copy, data and bss. VERIFIED 8b7f75f47156 on #326 (stacked on automap-join, which is in #330); rebased onto #332 (precheck equal). Touches Player.cpp and CUnit.cpp (lane 1's files; the functions sit in lane 4's range).

- lane4/text-data 909d80f4 no placeholder change: the copy at 0x722470 starts the waypoint panel's data (Unknown_0049BB40.cpp); gaWaypointActRanges (planned in WardenClient.cpp, read by the panel's 0x49C7F0) follows it and joins it. gnTextTop (0x7225FC), also planned in WardenClient.cpp, is the first global after text.cpp's copy and is read by the text functions, so it joins text.cpp. VERIFIED f92c4dc02676 on #327; rebased onto #332 (plan replayed; the four owners build equal). Not stacked; nothing outside lane 4.

## Claimed

- Verifying, to post when each passes: lane4/editbox-split and lane4/winmain-object (stacked on copies-start-b, now in #330), lane4/zero-gaps (opaque records take the zero runs after them; three 8-byte alignment dwords lose their records), lane4/record-object (Record.cpp and the lng object), lane4/lang-include (22 units take their copy from D2LanguageNames.h), lane4/context-sweep (127 context directives that no unit needs), lane4/session-object (Unknown_0044BA20.cpp, 0x44BA20-0x44BDCF between WINMAIN.CPP and Game.cpp).





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

