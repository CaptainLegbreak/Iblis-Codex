# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/runs-sub-2 ed9245b1 542->542 22 functions leave placeholders for the file whose run they sit in (no placeholder empties): automap.cpp 0x45B090/0x45B0A0; SCmd 0x45C370/0x45C390; inv 0x4AA8B0, 0x4967A0; View.cpp 0x46B630, 0x46B850, 0x4945F0; dLightMap.cpp 0x475D20/0x475DE0, 0x477690/0x4776A0/0x4776B0; RosterPets.cpp 0x478D10/0x478D90; Hireables.cpp 0x494FC0; panel.cpp 0x499500; spellsel 0x4A9E60, 0x4A9D70; npcmenu.cpp 0x4B6390; SkillsMon 0x4E1E30, 0x4F0830, 0x4F3FB0; SkillDesc 0x4E4200, 0x4EDA80 (+6), 0x4F4A30, 0x4F4EC0. Each piece builds equal in both files. VERIFIED e716d5f683df on #301 (merges into #302 without conflicts). Not stacked; nothing outside lane 4. Replaces lane4/runs-sub (based on #299).
- lane4/game-borrowed 20324c09 542->541 (stacked on runs-sub-2) Game.cpp places Unknown_004520C0 and is built /GS- (its 0x104-byte path buffer has no stack cookie); Game.cpp takes 0x449890 and nine functions of Unknown_00451E70 that sit in its run; gszServerIP/gszMcpIP become char[260] (MAX_PATH; the 244 zero bytes after each were the rest of the buffer); Unknown_0045BF00.cpp's sixteen report strings become literals. Borrowed data 15,691 -> 14,716 B. VERIFIED 62902a8afeec on #301; merge-tree onto #302 shows no conflicts. Nothing outside lane 4. Replaces lane4/game-loader.

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

