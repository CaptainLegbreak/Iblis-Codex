# Lane 1

Written by lane 1 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane1/monunique-object 4631a3c4f 562->560 MonUnique.cpp becomes its object 0x4AC730-0x4AD0B5: the accessors and setters 0x4AC730-0x4AC840 (from Unknown_004A9BD0, Monster.cpp's GetMonUmods, GfxUtil.cpp's type-flag toggle, and Unknown_004AC780.cpp, which goes) and the hover-name builder 0x4AC870 (Unknown_004AC870.cpp, which goes; it inlines the accessors, its gaHoverModes rdata sits right before the MonUnique.cpp path string, and gpfnUModCallbacks points at it); MonUnique.cpp builds /GS- like 0x4AC870 did. Data: the copy at 0x724D3C that starts MonUnique's data is planned in it; gaSkillTabX shrinks to int[7][3] with the int after it as gData_00724D38 (lane 4's note); VERIFIED 03befb06891cdda8b53b14b7b4163f1c1d93aec5
  - verified on #326, rebased onto #327 without touching the same files (tree e278896e0ba3a2be0c7778c30a9510272cb2d38f, re-verifying). Touches lane 4's Unknown_004A9BD0.cpp, Unknown_00499500.cpp's plan, GfxUtil.cpp.

- lane1/skillsbar-copy 78fbb3e97 0->0 the four back-to-back copies at 0x727DBC (planned in Item.cpp) are four data-less objects between Skills.cpp and UnitSnd.cpp; the first, SkillsBar.cpp's, is planned there with its data include; the other three stay together as gData_00727DF8 until the objects between SkillsBar and UnitSnd are mapped; VERIFIED 8c2fc2722e72fa28833b8aac10b75a276e313953
  - verified on #326, rebased onto #327 (tree 28b0d0e556f8ad864d86e37bd92e5180d75ae656, re-verifying).

- lane1/casetable-to-d2lang-2 516210e1c 0->0 gaCaseTable (0x730778) leaves Monster.cpp's plan: it is D2Lang's lower-case table after gawToUpperTable, 512 B in Unknown_00526610.cpp; the language-name copy at 0x730978 (+4 zero bytes) that ended it is planned in Unknown_00526100.cpp before gaUtf8ConvertTable; VERIFIED 38c9ebe8d77a48e989a69ea60a2861c8ff7165eb
  - based on main #325. Replaces lane1/casetable-to-d2lang (that name holds the same commit on #323). Lane 6's files, plan entries only.

## In progress

- **Claimed next: the PlrSkills.cpp-to-Wall2.cpp object map** (code 0x4D9FC0-0x4DCE56, now mine). gpfnClientStateRemFuncs (600 B) is 120 B of table and 8 back-to-back copies: 8 data-less objects in link order (Particle, GfxUtil, CUnitEvent, PlayerList and placeholders are the candidates).

- Borrowed 0x4A4AD0, in Unknown_004A43E0.cpp (keycfg-extras state, marked locally): still 1,202 of 1,232 B, the same register difference after the first helper call. Tried the board's lever as well: a local copy of nY before the first call, and calling TEXT_IsInKeyConfigList again in the list block instead of reusing bInList (the compiler merges it): no change. Kept as a stand-in.

## Questions


## Notes for other lanes

- Lane 4 (or whoever maps it): the .rdata path strings after PlrSkills.cpp's are, in order, .\ENGINE\Particle.cpp (0x6DB95C), .\ENGINE\GfxUtil.cpp (0x6DB974), .\UNIT\CUnitEvent.cpp (0x6DB98C), .\UNIT\PlayerList.cpp (0x6DB9A4), .\GAME\Wall2.cpp (0x6DB9BC). That is link order for those objects, and with the 8 copies in gpfnClientStateRemFuncs (0x72A788-0x72A968) it says 8 data-less objects sit between PlrSkills.cpp and Wall2.cpp, four of them those four. I'm working this out now (my range since the ownership change).

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
