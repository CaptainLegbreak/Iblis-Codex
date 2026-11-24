# Lane 1

Written by lane 1 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane1/unit-strays 4b46a471a 563->562 UNIT files take 16 strays that sit between two of their functions (inferred or placeholder names, so the run decides): CUnit.cpp 0x463D80 (ui.cpp), 0x463E10 (Unknown_00462CA0), 0x463EE0 (SCmd.cpp; line-only assert 1419 between 1406 and 1503); Player.cpp 0x460780 (View.cpp), 0x461AC0 (automap.cpp); UnitMode.cpp 0x480780 (inv.cpp), 0x480B40 (View.cpp), 0x480C10 (automap.cpp); MonUnique.cpp 0x4ACD50, 0x4ACDB0 (all of Unknown_004ACC70.cpp, which goes); Monster.cpp 0x4B1050 (inv.cpp), 0x4B1240 (npcmenu.cpp); Item.cpp 0x4C1A70, 0x4C1AD0 (Object.cpp; line-only assert 840 between 584 and 900); Missile.cpp 0x4CD0A0 (Skills.cpp), 0x4CDB40 (GfxUtil.cpp, one prototype now); VERIFIED e7f1a442d439308bc38fe6aa7ef1944a72608a4c
  - verified on #323; rebased clean onto #324 (tree 7bc119150441d1b8c4f99e5cda367c429a22f6eb). Touches lane 4's ui.cpp, View.cpp, automap.cpp, inv.cpp, npcmenu.cpp, SCmd.cpp, Skills.cpp, GfxUtil.cpp, Unknown_00462CA0.cpp (all lines out only).
  - Left out: 0x466820 (View.cpp, in CUnit.cpp's run). With it in CUnit.cpp it inlines 0x4667F0 completely and the out-of-line 0x4667F0 disappears; the image keeps 0x4667F0 (custom register convention, so static) with no caller at all. I don't know yet what keeps it. 0x4B1D70 (Unknown_004A9BD0, in "Monster.cpp"'s 0x4B15F0-0x4B1DC0 tail): it reads gnNpcEntryCount/gaNpcEntries, npcmenu data, and that tail of Monster.cpp has no asserts and npc-menu setters; I think 0x4B15F0-0x4B1DC0 is the start of npcmenu.cpp, not Monster.cpp. Left for the npcmenu object work.

- lane1/umod-names-copy 2dd685ab6 0->0 gwUniqueModNameIds (0x725188) becomes a typed unsigned short[44] in Unknown_004ADD90.cpp; the language-name copy at 0x7251E0 (with its 4 zero bytes) is planned in Monster.cpp as gData_007251E0, the start of Monster.cpp's data; VERIFIED c8c501af1c872cf44e94f4398518b317a2bbbddf
  - based on main #323. The include route (D2LanguageNames.h in Monster.cpp) does not land yet: the compiler puts gtDiabloAnimRecord right after the unit's first data item (main's build does the same), so the copy is not followed by gaMonAnimRecords. Left as planned data for now.

## In progress

- **Claimed: casetable-to-d2lang** (verifying): gaCaseTable (0x730778, 576 B in Monster.cpp's plan) is D2Lang's lower-case table after gawToUpperTable; 512 B go to Unknown_00526610.cpp, the copy at 0x730978 to Unknown_00526100.cpp (lane 6's files, plan entries only).
- **Done: UNIT run strays** (branch lane1/unit-strays). Single functions filed elsewhere that sit between two functions of one UNIT file, all with inferred or placeholder names, move into that file: 0x463D80/0x463E10/0x463EE0/0x466820 -> CUnit.cpp; 0x460780/0x461AC0 -> Player.cpp; 0x480780/0x480B40/0x480C10 -> UnitMode.cpp; 0x4ACD50/0x4ACDB0 -> MonUnique.cpp; 0x4B1050 (+0x4B1240, 0x4B1D70 if they build) -> Monster.cpp; 0x4C1A70/0x4C1AD0 -> Item.cpp; 0x4CD0A0/0x4CDB40 -> Missile.cpp. They come out of lane 4's ui.cpp, View.cpp, automap.cpp, inv.cpp, npcmenu.cpp, SCmd.cpp, Skills.cpp, GfxUtil.cpp and placeholders. Skipping Unknown_004D1300's four (not Missile.cpp code) and 0x4CA560.

- Borrowed 0x4A4AD0, in Unknown_004A43E0.cpp (keycfg-extras state, marked locally): still 1,202 of 1,232 B, the same register difference after the first helper call. Tried the board's lever as well: a local copy of nY before the first call, and calling TEXT_IsInKeyConfigList again in the list block instead of reusing bInList (the compiler merges it): no change. Kept as a stand-in.

## Questions


## Notes for other lanes

- Lane 4 (object map, 0x4AC730-0x4AE0A0): what I found while placing the Monster.cpp pieces. .rdata 0x6DA488 gaHoverModes (0x4AC870's) sits straight after spellsel.cpp's path string, then ".\UNIT\MonUnique.cpp", gaUModList, then Monster.cpp's gaMonCmdRecords (0x6DA4D8). .data: gpfnUModCallbacks (0x724D78, read by MonUnique's 0x4AD020) points at 0x4AC870, 0x4ACC70, 0x4ACD50, 0x4ACD70, 0x4ACDB0; gaUModCallbacks (0x724E28, read by 0x4ADD90) points at the state callbacks 0x4AD0C0-0x4ADD80 filed in npcmenu.cpp; gwUniqueModNameIds (0x725188, read by 0x4ADEA0) follows; Monster.cpp's .data starts at 0x725220. 0x4AD970 calls 0x4AC7E0 (not inlined), so the state callbacks are not in 0x4AC7E0's unit. I read MonUnique.cpp as 0x4AC870-0x4AD0B5; the callbacks 0x4AD0C0-0x4ADD80 and Unknown_004ADD90 may be one more object. I'll take Unknown_004ACC70's two functions (inside MonUnique.cpp's run) next; 0x4AC870 and the callbacks are yours.

- All lanes: the struct-count effect also covers plain declarations. In inv_004886C0.cpp, 0x488B00 changes with one fewer or one more `extern int` in scope (D2Client.h lines included). GetHitSounds (0x4CA560) now matches only with +4..+6 dummy structs, not +2..+4 as on #283. Header edits that add or remove declarations can flip such functions in units that never use them.

## Left in place (and why)

- Unknown_004C0440 (0x4C0550, handed back): in useitem.cpp it needs gnUseItemPanelMode (0x7C5470) static (the original loads pPacket->nValue before storing 0 to it, which needs the no-alias a static gives), and then 0x4BFDD0 swaps the stack slots of mouseX/mouseY; same instruction stream otherwise. Not a declaration-count effect (+1..+3 externs do not change it); moving/scoping the mouse and lineCount locals and dropping the `mode` local do not either. Also found: Item.cpp's 0x4BFBC0/0x4C01E0 (inside useitem.cpp's run) use gaUseItemHotspotRects, which is gaUseItemHotspots[2] (0x727900, two 40-byte D2HotspotStrc) seen 2 bytes in; 0x727900 (Item.cpp), 0x727902 and 0x72792A are that one array split in three. Worth doing together with this placement.

- UNIT borrowed-data rows other than UnitSnd: 0x7277A0 (80 B) is an int[17] {1..9..1} plus {0x727748, 0x7277A0, 0}; nothing in code or defined data points at it, and 0x727748 itself is undefined (lane 4's editbox gap). 0x6DA6C4 (44 B) is part of a vtable at 0x6DA6C0 written by Unknown_004BA760 / Unknown_004BC1B0 (lane 4's range): it needs those classes' virtual functions declared, not a data definition. 0x7278BC (64 B) is a table of 16 string pointers into 0x6CC77C-0x6CC81C with no code reference found. Left for now.

- Unknown_004CA560 (GetHitSounds): still MISMATCH in UnitSnd.cpp on #304; it moves with the declaration count (window now +4..+6), so not landed.
- Unknown_004C0440 (0x4C0550), Unknown_004C7C80, Unknown_004C97C0 (handed back by lane 4): not started. The evidence points at useitem.cpp and Skills.cpp, where lane 4 saw register changes.
- ITEM_QueryCacheAddress (0x4DF630, Item.cpp): waiting for better evidence.
- Unknown_004D1300: only builds equal without Missile.cpp's callee bodies in the same unit, so it is not Missile.cpp code.
- Unknown_004DEDB0 (tile lights), _004DF4B0 / _004DF1C0 leftovers: no file evidence yet.
