# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/runs-sub-2 ed9245b1 542->542 22 functions leave placeholders for the file whose run they sit in (no placeholder empties): automap.cpp 0x45B090/0x45B0A0; SCmd 0x45C370/0x45C390; inv 0x4AA8B0, 0x4967A0; View.cpp 0x46B630, 0x46B850, 0x4945F0; dLightMap.cpp 0x475D20/0x475DE0, 0x477690/0x4776A0/0x4776B0; RosterPets.cpp 0x478D10/0x478D90; Hireables.cpp 0x494FC0; panel.cpp 0x499500; spellsel 0x4A9E60, 0x4A9D70; npcmenu.cpp 0x4B6390; SkillsMon 0x4E1E30, 0x4F0830, 0x4F3FB0; SkillDesc 0x4E4200, 0x4EDA80 (+6), 0x4F4A30, 0x4F4EC0. Each piece builds equal in both files. VERIFIED e716d5f683df on #301. Not stacked; nothing outside lane 4. Replaces lane4/runs-sub (based on #299).
- lane4/game-borrowed (verify running; stacked on runs-sub-2) Game.cpp places Unknown_004520C0 and is built /GS- (its 0x104-byte path buffer has no cookie); Game.cpp takes 0x449890 and nine functions of Unknown_00451E70; gszServerIP/gszMcpIP become char[260] (-488 B borrowed); Unknown_0045BF00.cpp's sixteen report strings become literals (-487 B borrowed). Replaces lane4/game-loader.

## Questions

## Notes for other lanes

- All lanes, coordinator: one 15-entry table of language-name pointers ("English", "Spanish", ... "Unknown"; strings 0x6CC77C-0x6CC81C) appears 308 times in .data. Fog's ErrorManager.cpp reads its copy (0x706618) as `gaszLanguageNames`; the rest are unreferenced. A header-level static array gives one copy per object file that includes it, and MSVC 2005 keeps unreferenced static data, so this fits. 283 copies are already planned, mostly inside opaque gData_ blocks; 25 are borrowed (0x705000, 0x70F728, 0x70F764, 0x721CDC, 0x721D18, 0x721D58, 0x727608, 0x727688, 0x727708, 0x7278C0, 0x7314D0, 0x73D530, 0x741750, 0x743780, 0x7437C0, 0x745584, nine at 0x749BC4-0x749DA4). Two uses: lane 2 could define the table once in the shared header so each unit's copy comes from the include; and one object file has only one copy, so a planned file holding several copies spans several original units (FieldTbls.cpp 16, ItemMode.cpp 10, Unknown_004DF6C0.cpp 9, inv.cpp 8, PlrSkills.cpp 8, text.cpp 7, AiThink.cpp 2, ...). Runs of copies 0x3C apart are runs of units with no other initialized data.
- Lane 1: 0x721D18 (one of the three borrowed copies after WardenClient's data) is probably UnitMode.cpp's: by text order WardenClient, UnitMode, SoundHdr come next. I'm not placing it.
## Left in place (and why)
