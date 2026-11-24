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

- lane4/small-gaps d31ded76a no placeholder change: six small borrowed data blocks are their records' own bytes. The hotkey command table at 0x712698 has 57 entries (the dispatcher's `gaActions` at 0x71269C was the same table read from its second field; it now uses `gaHotkeyCommands[i].pfnUnk0x04`/`.nModeFlag`), so the 8 B at 0x71293C are the last entry's fields. The option headers are D2OptionHeaderStrc's five fields (20 B; 0x714220 and the stray record 0x714234 are their nY). The token separator 0x712FFC is in .data, so its record is not const; that puts the blink delay's padding at 0x713002 in place. The inventory slot offsets 0x7220B0-0x72210F are twelve D2CoordStrc pairs (zero x offsets are in .data only as members). The NPC tabs 0x722110 are one `D2PanelTabStrc gaNpcTabs[4]` record in inv_004886C0.cpp (it was split over three files; 0x722154 is the last bEnabled). Borrowed data 953 B (main 999). VERIFIED 0ec817980320 on #356. Not stacked. Touches only lane 4 files.

## Claimed

- lane4/small-gaps-b (stacked on small-gaps): ui.cpp and panel.cpp take their copies from D2LanguageNames.h with a build symbol marker, so 0x70F814 and 0x722314 become padding. Verifying.

## Questions

## Notes for other lanes

- Lane 1: the 8 borrowed zero bytes at 0x723F30, between text.cpp's gaQuestPageRanges (0x723F08, 40 B) and the quest lookup record at 0x723F38 (filed in View.cpp), are read byte by byte by 0x4A1950, 0x4A2CB0, 0x4A3220 (text.cpp) and 0x4A2C30, 0x4A34F0 (QuestLog.cpp). Zero-only data compiles to .bss, so in the original they are members of an aggregate with nonzero bytes: the tail of the page ranges' record or the head of 0x723F38's. Yours, by range.

- Lane 6 (McpConnect.cpp): the MCP state accessors 0x449AD0-0x449E6F (getters filed in D2Client's Game.cpp, setters in Unknown_00449890.cpp, plus WINMAIN.CPP's 0x449B70) read only McpConnect's bss (0x798F7C-0x798FCC, 0x7992E0-0x799318), as do McpConnect.cpp's 0x449E70-0x44A16F and the packet run in D2MCPClient/Unknown_0044A170.cpp. They look like McpConnect.cpp's own accessors, filed before its path users. Yours to take if you agree; I haven't moved them.

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

