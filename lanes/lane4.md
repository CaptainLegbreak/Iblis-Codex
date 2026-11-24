# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/init-more 18d4889c no placeholder change: two initializers that were written out as functions become constructed globals. text.cpp: data_007BF298 is defined as its D2QuestTextBufferStrc (0x6CACD0 was a placement new); showitems.cpp: gaItemLabels (0x7C54A8, D2ItemLabelStrc[32]) is defined there, and 0x6CADB0 (a vector-constructor loop over a byte-array view at 0x7C54BC, the records' text members) is its implicit constructor. VERIFIED 68d286e3fd75 on #309. Not stacked; nothing outside lane 4.

- lane4/warden-strays-2 dee51841 no placeholder change: seven functions leave the files they were filed in for the run they sit in. Into WardenClient.cpp from inv.cpp: D2RC4Strc::ApplyKeystream 0x47F8C0, INV_CallServiceWithTime 0x47FFB0 (the service call returns its result, so WardenClient.cpp's view returns int), INV_ProcessWardenRequest 0x4802E0. Out of WardenClient.cpp: 0x49C7F0 to Unknown_0049BB40.cpp, 0x4C5EB0 to Skills.cpp (after the scan callback it passes; uses Skills.cpp's scan record), 0x4DB670 to GfxUtil.cpp, 0x4F3CE0 to SkillsMon.cpp; each sits between functions of its new file. VERIFIED 2136b2b60264 on #309. Not stacked; nothing outside lane 4.

- lane4/initializers 86d6def0 no placeholder change; touches lane 3's Storm placeholders (Unknown_006C9A68/006CAA30/006CACE0.cpp lose 15 functions, as the coordinator's note asked). Fifteen D2Client dynamic initializers join the globals they set. The CRT initializer table (from 0x6CC618) lists them in object order, which settles each global's file: WINMAIN.CPP the two caption pointers (0x6CA9A0/0x6CA9B0; gpszDefaultCaption 0x70EE50 becomes Game_0044E5A0.cpp data); ui.cpp gwszPopUpText, gwszHoverLine, gwszHoverText, gwszHoverName (consecutive constructors, adjacent in bss; gwszHoverText was defined in Unknown_00451E70.cpp); automap.cpp gnAutomapWidth/gnAutomapHeight (were defined in Unknown_004A9D70.cpp and text.cpp, which come later in the table); CmdTbl.cpp the key text; chat.cpp the input line, history and the two IME buffers; inv.cpp the recipe scroll text; text.cpp gnKeyConfigThumbY. Unicode arrays already had constructors; symbol lines place them. gnTextLeft (0x6CAC10) stays: its definition is in WardenClient.cpp but the table puts it after inv.cpp. VERIFIED a18b6558fca9 on #308. Not stacked.

- lane4/borrowed-b 3fd5deb4 no placeholder change: Game_0044E5A0.cpp defines gaEndScreenHandlers (0x70F418, nine handler entries the file registers); gaCofModeCodes (Gfx_0046DB90.cpp) is one 8-byte {code, mode} entry ('gh', 13), planned before as its first 4 bytes; gnAutomapScale (automap.cpp, 0x711254 = 10) had two names in automap.cpp, now one; gnTabEnabled3 (inv_00491D20.cpp, 0x722154), read only there (the file gets its first .inc). Borrowed data 12,878 -> 12,758 B. VERIFIED cc2c3e22bf63 on #306. Not stacked; nothing outside lane 4.

- lane4/uiwidget 5e63ee69 no placeholder change: UIWidget declares slots 1-11 as pure virtuals (its vtable 0x6DA6C0 is twelve `_purecall`s) and ListBoxImplementation/ListBoxWrapper override them. Slot names: the ones editbox.cpp's UIWidget already uses for the same base (Slot01, MsgSlot02-MsgSlot10, Slot11), so all six widget classes share one set; none of the replaced names was `blizzard` (all placeholders). 17 methods and names.csv rows renamed; duplicate names get symbol lines. Also in Unknown_004BC1B0_004BE770.cpp's copy of the base. Borrowed data 12,834 B (the 44 B of the vtable go). VERIFIED b99076493478 on #306. Not stacked; nothing outside lane 4.

- lane4/options-split 62777d01 +1 placeholder (Unknown_0047CC90.cpp) 0x47CC90-0x47F8AF leaves chat.cpp: the option entries and menus, the escape menu and the mini panel slots (94 functions). The language-name table marks object files (see the note below; the rule held for all 21 files whose functions name their own path): chat.cpp's initialised data ends with the copy at 0x713008, and the option tables 0x713044-0x721C58 end with another copy before WardenClient.cpp's data; the bss splits the same way (chat to 0x7BC890, options 0x7BC898-0x7BC97C). I had joined them on assert line numbers alone (1256-1612 after chat.cpp's 235-669), which a second file also fits. No name for it, so a placeholder. VERIFIED bc82d08e98eb on #304. Not stacked; nothing outside lane 4. Borrowed data unchanged.



## Questions

- WINMAIN.CPP is three or four object files by its data (the language-table copies mark object ends, see the note below). Its MCP packet run 0x44A170-0x44B3xx (send helpers, incoming handlers, `gpfnConnectPacketHandlers` 0x70ED68) has data ending at the copy at 0x70EDD0; 0x44B400-0x44B430 (InitInterface, ShutdownInterface, RunLauncher) ends at 0x70EE10; WINMAIN.CPP proper (the `.\CORE\WINMAIN.CPP` path is at 0x44B557, command line handling, LauncherRun) ends at 0x70EE90; Game.cpp follows (to 0x70F728). The MCP run comes right after `.\Src\McpConnect.cpp` (0x449E84) and an object with no data of its own (copy at 0x70ECC0), so it is probably a D2MCPClient file, not D2Client. May I move 0x44A170-0x44B3xx and 0x44B400-0x44B430 out of WINMAIN.CPP into two placeholders (Unknown_0044A170.cpp, Unknown_0044B400.cpp)? If the MCP one is lane 6's by module, say so and I'll leave it to them.


## Notes for other lanes

- All lanes, coordinator: one 15-entry table of language-name pointers ("English", "Spanish", ... "Unknown"; strings 0x6CC77C-0x6CC81C) appears 308 times in .data. Fog's ErrorManager.cpp reads its copy (0x706618) as `gaszLanguageNames`; the rest are unreferenced. A header-level static array gives one copy per object file that includes it, and MSVC 2005 keeps unreferenced static data, so this fits. 283 copies are already planned, mostly inside opaque gData_ blocks; 25 are borrowed (0x705000, 0x70F728, 0x70F764, 0x721CDC, 0x721D18, 0x721D58, 0x727608, 0x727688, 0x727708, 0x7278C0, 0x7314D0, 0x73D530, 0x741750, 0x743780, 0x7437C0, 0x745584, nine at 0x749BC4-0x749DA4). Two uses: lane 2 could define the table once in the shared header so each unit's copy comes from the include; and one object file has only one copy, so a planned file holding several copies spans several original units (FieldTbls.cpp 16, ItemMode.cpp 10, Unknown_004DF6C0.cpp 9, inv.cpp 8, PlrSkills.cpp 8, text.cpp 7, AiThink.cpp 2, ...). Runs of copies 0x3C apart are runs of units with no other initialized data.
- Lane 1: 0x721D18 (one of the three borrowed copies after WardenClient's data) is probably UnitMode.cpp's: by text order WardenClient, UnitMode, SoundHdr come next. I'm not placing it.
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

