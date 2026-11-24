# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/options-split 62777d01 +1 placeholder (Unknown_0047CC90.cpp) 0x47CC90-0x47F8AF leaves chat.cpp: the option entries and menus, the escape menu and the mini panel slots (94 functions). The language-name table marks object files (see the note below; the rule held for all 21 files whose functions name their own path): chat.cpp's initialised data ends with the copy at 0x713008, and the option tables 0x713044-0x721C58 end with another copy before WardenClient.cpp's data; the bss splits the same way (chat to 0x7BC890, options 0x7BC898-0x7BC97C). I had joined them on assert line numbers alone (1256-1612 after chat.cpp's 235-669), which a second file also fits. No name for it, so a placeholder. VERIFIED bc82d08e98eb on #304. Not stacked; nothing outside lane 4. Borrowed data unchanged.

- lane4/warden-class 1b911034 541->541 the Warden service table at 0x6D8E68 is a vtable (a complete object locator precedes it; type descriptors `.?AUWardenClient@@` and `.?AULibrary@NWardenClient@@`), so `struct WardenClient : NWardenClient::Library` with seven overrides (0x480000-0x480150: __thiscall functions that ignore `this`); `gtWardenIface` (0x721C98) is a WardenClient object, statically initialised. The ctor 0x4801C0 comes from View.cpp (a one-member view) and 0x480000 from Gfx.cpp; the vtable, locator and type descriptor now come from the compiler. names.csv 0x4801C0 -> WardenClient (a constructor). Borrowed data 14,305 B. VERIFIED ada913279dd6 on #302; merge-tree onto #304 shows no conflicts. Not stacked; nothing outside lane 4.


## Questions


## Notes for other lanes

- All lanes, coordinator: one 15-entry table of language-name pointers ("English", "Spanish", ... "Unknown"; strings 0x6CC77C-0x6CC81C) appears 308 times in .data. Fog's ErrorManager.cpp reads its copy (0x706618) as `gaszLanguageNames`; the rest are unreferenced. A header-level static array gives one copy per object file that includes it, and MSVC 2005 keeps unreferenced static data, so this fits. 283 copies are already planned, mostly inside opaque gData_ blocks; 25 are borrowed (0x705000, 0x70F728, 0x70F764, 0x721CDC, 0x721D18, 0x721D58, 0x727608, 0x727688, 0x727708, 0x7278C0, 0x7314D0, 0x73D530, 0x741750, 0x743780, 0x7437C0, 0x745584, nine at 0x749BC4-0x749DA4). Two uses: lane 2 could define the table once in the shared header so each unit's copy comes from the include; and one object file has only one copy, so a planned file holding several copies spans several original units (FieldTbls.cpp 16, ItemMode.cpp 10, Unknown_004DF6C0.cpp 9, inv.cpp 8, PlrSkills.cpp 8, text.cpp 7, AiThink.cpp 2, ...). Runs of copies 0x3C apart are runs of units with no other initialized data.
- Lane 1: 0x721D18 (one of the three borrowed copies after WardenClient's data) is probably UnitMode.cpp's: by text order WardenClient, UnitMode, SoundHdr come next. I'm not placing it.
- Lane 1: D2Client.h line 847 still declares 0x4DF6C0 as `sub_004DF6C0(int nArg)`; nothing in lane 4 uses it.
- Lane 2: `D2ClientTypes.h`'s `D2GfxDataStrc` holds its 20 entries as byte pairs because moving `D2GfxEntryStrc` out of D2Client.h changes code in useitem.cpp and inv_0048DD90.cpp.

## Left in place (and why)

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

