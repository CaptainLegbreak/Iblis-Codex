# Lane 1

Written by lane 1 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane1/useitem-copies-2 0ea6cf293 0->0 the language-name copies between Object.cpp and Skills.cpp, by code order list-box object, useitem.cpp, showitems.cpp, Item.cpp, Skills.cpp: the borrowed copy 0x7278C0 is useitem.cpp's (it runs into gnHotspotCount and the hotspot bytes at 0x727900, which move from Item.cpp's plan to useitem.cpp's); gaUseItemHandlers is 8 entries, not 18, and the 120 B after it are showitems.cpp's copy (0x7279B0; it has no other .data) and Item.cpp's (0x7279EC); gData_00727A4C (64 B, Item.cpp) is 4 B of Item.cpp and Skills.cpp's copy (0x727A50); borrowed data 2,382 -> 2,314 B; VERIFIED 15d39f57aa190f215ca2d273d6c4c777661ac7c4
  - based on main #331. Replaces lane1/useitem-copies (same change on #329). useitem.cpp/showitems.cpp are in my range since the ownership change. Left: 0x72783C (the list-box object's copy, inside gapfnObjectClientFn, which is really 19 entries) and moving Item.cpp's 0x4BFBC0 into useitem.cpp (needs the two D2HotspotStrc definitions unified; goes with the gaUseItemHotspots[2] / 0x4C0550 work).

- lane1/particle-strays debdf4d47 563->562 Particle.cpp takes 0x4DA0D0/0x4DA0F0 (Item.cpp; GfxUtil's 0x4DA350 calls them and their sibling 0x4DA0B0 without inlining); GfxUtil.cpp takes the strays in its run: 0x4DA5B0 (Skills.cpp), 0x4DA700/0x4DA790/0x4DAD20 (Particle.cpp), 0x4DA770 (Unknown_004DA770.cpp, which goes), 0x4DC0A0/0x4DC0B0 (PlayerList.cpp; 0x4DC0A0 clears GfxUtil's gdwFadeTick, and CUnitEvent calls the 11-byte 0x4DC0B0 out of line); the .bss token tables 0x7C88D0-0x7C89C0 that 0x4DA790 resets move from Particle.cpp to GfxUtil.cpp (they sit right before gdwFadeTick); VERIFIED f1b997fa2558c6c94a4f77b82b76ba2ae67d61fd
  - verified on #328, rebased clean onto #329 (tree eca0fb1edd007bae8f773c1878ccf34266f5e23f; #329 is names only).

## In progress

- **0x4A4AD0 variant-search template:** lanes/vsearch/0x4A4AD0.cpp (unit Source/D2Client/Unknown_004A43E0.cpp on #331, function marked; with the first alternatives it builds 1,202/1,232 like now). Groups, following the coordinator's listing note (bPageDown gets ebx in the original): const/plain for bInList and bPageDown; bButton as `GetKeyConfigButtonAt != 3` or `IsOnKeyConfigButton`; the all-clear condition with !bPageDown moved first or the pressed test last; block 0 as `bInList || gaPressed[0]`, reversed, or with the hit test called again instead of bInList; the page-down block's condition order, `gaPressed[5] = bPageDown && gbRedraw`, and its inner test as gbRedraw / `bPageDown && gbRedraw` / `gaPressed[5]`; the button block's condition order.
- **PlrSkills.cpp-to-Wall2.cpp object map (open):** the line-only asserts disagree with particle-strays' inlining reading. Lines by address: 0x4DA000 74 (Particle path), 0x4DA350 425, 0x4DA790 54, 0x4DA920 129, then GfxUtil path lines 406..1622 up to 0x4DB570 and 752, 994, 1437 from 0x4DB7B0. If lines rise within a file, Particle runs to about 0x4DA6FA (the motion accessors 0x4DA110-0x4DA6E0 are Particle.cpp's, which allocates the motion record) and GfxUtil starts near 0x4DA720; but then 0x4DA350 calls the 28-byte 0x4DA0B0/0x4DA0F0 of its own unit without inlining. I'll test it by building the motion accessors into Particle.cpp before deciding; particle-strays doesn't depend on it (its moves are on either side of the question). 0x4DB7B0's GfxUtil lines restarting is unexplained; same path string, so I keep GfxUtil one file.

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
