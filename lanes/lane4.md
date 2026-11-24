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

- lane4/gamelist-strays-3 64f86422b -1 placeholder (Storm/Unknown_00426910.cpp): the eight D2Client game-list template members filed in Storm placeholders go to the D2Client placeholders around them, written with those files' types (Unknown_0044F9B0.cpp: the two NewNode members and four scalar deleting destructors with their existing emit helpers; Unknown_00450D90.cpp: the array Reserve/ReserveExact). **The hold is fixed:** the BREAKCMD type name at 0x7088D8, which the emptied Storm/Unknown_00426910.cpp no longer placed, moves to Storm/Unknown_00426900.cpp (right before its gtSEvtBreakCmdTerminator, read by the SEvt code), and the empty placeholder goes. Borrowed data 1,114 B on the verified tree (main's figure at #351). VERIFIED e946351a70ec on #351; rebased onto #353 (precheck equal). -1/-2 superseded. Not stacked; touches lane 3's Storm files.

- lane4/party-object-2 c23952400 -3 placeholders (Unknown_00499500.cpp, Unknown_0049AAF0.cpp, Unknown_0049B330.cpp): Party.cpp takes most of its object, 0x499DE0-0x49C46F. The party roster's bss 0x7BEFF4-0x7BF034 is read by those functions and no code outside; panel.cpp's run ends at 0x499DDF and the waypoint object starts at 0x49C470. Party.cpp takes panel.cpp's roster lookup, colours and party cel/panel functions (0x499DE0, 0x499E10, 0x499E30, 0x49C0A0, 0x49C0F0, 0x49C3D0), text.cpp's 0x49AAA0, text_0049A950.cpp's 0x49A950/0x49AA50, dLightMap.cpp's 0x49C160, and the three placeholders whole (Unknown_0049AAF0.cpp with its existing caller copy and emit helper). The panel label 0x49A460, filed in RosterPets.cpp as a fastcall with a dummy second parameter, is now Party.cpp's own static __stdcall view of it, already in the file; the dummy-parameter form goes. A second record for gbControlPanelMouseDown (0x722358) duplicated panel.cpp's and is dropped. Left out: Unknown_0049AF60.cpp (0x49AF60 and Unknown_0049B330's call to it disagree on the parameters in one unit), Unknown_0049B030.cpp and 0x49BB40/0x49BB60 (inlined there). Borrowed data 1,166 B on the verified tree. VERIFIED 39dc955e4c35 on #349; rebased onto #352 (ownership replayed; precheck equal). Not stacked.

- lane4/level-events 1f75d95e -2 placeholders (Unknown_0046AF70.cpp, Unknown_0046B850.cpp): Unknown_0046ACE0.cpp takes the level-event object, 0x46ACE0-0x46C56F. Its bss (0x7A742C-0x7A746C) and data (0x7129CC-0x712A27, after its copy at 0x712990) are read only by functions in 0x46AD10-0x46C060, among them the strays filed in RosterPets.cpp (0x46BD50) and SCmd.cpp (0x46BDD0). It takes those two, View.cpp's 0x46B850, and the two placeholders whole. gnPulseTick comes from RosterPets.cpp as the object's static; the object's first copy comes from D2LanguageNames.h at the top of the unit so it and the static come out in the image's order (with the copy in the generated include, 0x71298C became borrowed). The two placeholders' seed helper versions are unified to one, without __forceinline. Borrowed data 1,175 B on the verified tree. VERIFIED 2be8298a5c87 on #344; replayed on #352 (the same moves; main's renames touched View.cpp and the plan), precheck equal. Not stacked.

- lane4/session-object-5 9d86f9131 +1 placeholder (Unknown_0044BA20.cpp): the bss runs WINMAIN.CPP's to 0x7A044C, then 0x7A0458-0x7A0630, then Game.cpp's from 0x7A0658. The functions that use the middle block, 0x44BA20-0x44BDCF (resolution set-up, subsystem start/shutdown, the connect-failed flag, run client, session start/stop/wait and system packet pumping), are one object; Unknown_0044BA20.cpp takes five from WINMAIN.CPP and five from Game.cpp, with that bss. Its data is the copy at 0x70EE90 alone, which moves into it (the 4 zero bytes after it are padding before Game.cpp's 8-aligned copy at 0x70EED0, so they lose their record). WINMAIN.CPP's plan names WINMAIN_StartSession/StopSession as externs for its launch handler table. Borrowed data 1,175 B on the verified tree. VERIFIED e67b7d34c87e on #348 (as -4); rebased onto #352 (0x44BA20 takes main's current text; plan replayed; namesync; precheck equal). -3 and -4 are superseded. Not stacked.

- lane4/waypoint-tail d14e1544e no placeholder change, **stacked on lane4/waypoint-strays (d94367c6)**: Unknown_0049BB40.cpp takes 0x49CEC0 (from text_0049A950.cpp) and 0x49CF50 (from text.cpp). Both read only the waypoint object's bss (0x7BF07D-0x7BF085) and sit in its run before text.cpp's object starts. 0x49D010, which reads the waypoint list too, stays in text.cpp: it compiles unequal in the waypoint unit. Borrowed data 1,175 B on the verified tree. VERIFIED bf3d57a3319f on #345 (on the first waypoint-strays); replayed on the posted waypoint-strays, precheck equal. Touches text_0049A950.cpp and text.cpp, as text-strays does (different functions).

- lane4/text-strays b973e3162 no placeholder change: text.cpp's object runs from about 0x49D2xx (the functions up to 0x49D160 still read the waypoint object's bss) to about 0x4A15xx. Twelve text.cpp functions below 0x4A0000 filed in text_0049A950.cpp (settings load and text list free 0x49D440/0x49D4D0, the message eater 0x49DA10, 0x49E810, 0x49FE60) and text_0049DA50.cpp (0x49DA50, 0x49DBC0, 0x49E7E0, 0x49E8B0, 0x49F910, 0x49FF00, 0x49FF90) move to text.cpp, written with its types (the text list free uses text.cpp's pack(2) D2TextNodeStrc, the same layout the placeholder viewed as bytes; TEXT_EatMsg's handler-table entry names the definition instead of an extern). Left out: 0x49E340 (calls a list box member text.cpp's class view lacks), 0x49F8C0 (unequal), text_0049D5A0.cpp (inlined into its caller there). Borrowed data 1,175 B on the verified tree. VERIFIED 63522d18fa75 on #345; replayed on #349 (the same moves; main's renames touched both placeholders), precheck equal. Not stacked. The functions from 0x4A0000 up in these placeholders are lane 1's.

- lane4/run-strays 2dbcdf5ae no placeholder change: strays that sit inside another file's run and read only that file's bss go there. CmdTbl.cpp (bss 0x7A6F8C-0x7A6F96) takes the mouse wheel dispatch and the hotkey binding get/clear/has queries filed in CUnit.cpp (0x4693B0, 0x469AA0, 0x469D70, 0x469D90) and SCmd.cpp's sort compare and hotkey message handler (0x469450, 0x46A840); dLightMap.cpp takes SCmd.cpp's room light query and grid cell read (0x474550, 0x475AA0); View.cpp takes SCmd.cpp's timed effect start (0x476A80). Borrowed data 1,175 B on the verified tree. VERIFIED 520a2d19fedd on #345; rebased onto #349 (precheck equal). Not stacked; moves four functions out of lane 1's CUnit.cpp (they sit in lane 4's range).

- lane4/waypoint-strays d94367c6 no placeholder change: text.cpp's 0x49C580-0x49C756 (load and free the waypoint panel cels, send and close the panel) sit in the waypoint object's run and are the readers of its bss at 0x7BF071-0x7BF085. They move to Unknown_0049BB40.cpp, which is built /GS- now (the cel loader's path buffer has no cookie; the unit's other functions are the same either way). Borrowed data 1,175 B on the verified tree. VERIFIED e2ebcf550db5 on #345; replayed on #349 (the same five moves; main's renames touched the unit), precheck equal. Not stacked.

## Claimed

- **Verifying:** `lane4/data-strays` (six strays go to the files whose data they read: ui.cpp's 0x45F7A0 to SCmd.cpp, ui.cpp's 0x45A710 to automap.cpp, inv.cpp's 0x47EC40 to Unknown_0047CC90.cpp, Gfx.cpp's 0x475C40 and SCmd.cpp's 0x475D30 to dLightMap.cpp, dLightMap.cpp's 0x475DF0 to View.cpp).

## Questions

## Notes for other lanes

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

