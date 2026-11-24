# Lane 1

Written by lane 1 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane1/keycfg-extras e6cde19d0 -0 the rest of the key-config object into #317's Unknown_004A43E0.cpp: 0x4A4780 and 0x4A5A40-0x4A5F70 (8, from text_0049A950.cpp), 0x4A6000 (from Unknown_004A6000.cpp), gnKeyConfigColumn / gbKeyConfigReady data and the one gnKeyConfigSelected definition; gnKeyConfigFirstVisible static with 0x4A4500 in plain form; list-entry ids read as ints; 0x7C02B4 one name; VERIFIED 496bd86f9d54fa8324bc98693e5f520fca522855
  - based on main #317 (main is #318 now). Replaces lane1/keycfg-object-r (withdrawn; lane 4's keyconfig-split did the split). Touches lane 4's text_0049A950.cpp and Unknown_004A6000.cpp.



- lane1/unitsnd-table 5af46c365 0->0 UnitSnd.cpp: the 116 pieces at 0x00727F48-0x007295C8 become one D2UnitSndObjectStrc gaUnitSndObjects[121] (5,808 B); gapUnitSndObjects points at its elements, gaUnitSndObject3D is gaUnitSndObjects[21]; borrowed data should drop by 2,692 B (verify shows 9,924 B); VERIFIED fdb0012051a0a221d5c2df4ff6de6801b4344474
  - based on main #307 (main is #309 now).


## In progress

- Borrowed 0x4A4AD0, in Unknown_004A43E0.cpp (keycfg-extras state, marked locally): still 1,202 of 1,232 B, the same register difference after the first helper call. Tried the board's lever as well: a local copy of nY before the first call, and calling TEXT_IsInKeyConfigList again in the list block instead of reusing bInList (the compiler merges it): no change. Kept as a stand-in.

## Questions


## Notes for other lanes

- All lanes: the struct-count effect also covers plain declarations. In inv_004886C0.cpp, 0x488B00 changes with one fewer or one more `extern int` in scope (D2Client.h lines included). GetHitSounds (0x4CA560) now matches only with +4..+6 dummy structs, not +2..+4 as on #283. Header edits that add or remove declarations can flip such functions in units that never use them.

## Left in place (and why)

- Unknown_004C0440 (0x4C0550, handed back): in useitem.cpp it needs gnUseItemPanelMode (0x7C5470) static (the original loads pPacket->nValue before storing 0 to it, which needs the no-alias a static gives), and then 0x4BFDD0 swaps the stack slots of mouseX/mouseY; same instruction stream otherwise. Not a declaration-count effect (+1..+3 externs do not change it); moving/scoping the mouse and lineCount locals and dropping the `mode` local do not either. Also found: Item.cpp's 0x4BFBC0/0x4C01E0 (inside useitem.cpp's run) use gaUseItemHotspotRects, which is gaUseItemHotspots[2] (0x727900, two 40-byte D2HotspotStrc) seen 2 bytes in; 0x727900 (Item.cpp), 0x727902 and 0x72792A are that one array split in three. Worth doing together with this placement.

- UNIT borrowed-data rows other than UnitSnd: 0x7277A0 (80 B) is an int[17] {1..9..1} plus {0x727748, 0x7277A0, 0}; nothing in code or defined data points at it, and 0x727748 itself is undefined (lane 4's editbox gap). 0x6DA6C4 (44 B) is part of a vtable at 0x6DA6C0 written by Unknown_004BA760 / Unknown_004BC1B0 (lane 4's range): it needs those classes' virtual functions declared, not a data definition. 0x7278BC (64 B) is a table of 16 string pointers into 0x6CC77C-0x6CC81C with no code reference found. Left for now.

- Unknown_004CA560 (GetHitSounds): still MISMATCH in UnitSnd.cpp on #304; it moves with the declaration count (window now +4..+6), so not landed.
- Unknown_004C0440 (0x4C0550), Unknown_004C7C80, Unknown_004C97C0 (handed back by lane 4): not started. The evidence points at useitem.cpp and Skills.cpp, where lane 4 saw register changes.
- ITEM_QueryCacheAddress (0x4DF630, Item.cpp): waiting for better evidence.
- Unknown_004D1300: only builds equal without Missile.cpp's callee bodies in the same unit, so it is not Missile.cpp code.
- Unknown_004DEDB0 (tile lights), _004DF4B0 / _004DF1C0 leftovers: no file evidence yet.
