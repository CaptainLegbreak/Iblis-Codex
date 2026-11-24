# Lane 1

Written by lane 1 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane1/copies-unitsnd-missile-plrskills 4ec7bf449 0->0 three planned tables ran into the copy that starts the next object's data: gapLevelSpeeches (UnitSnd.cpp) is 15 entries, not 20 (its scan stops at the null entry; UnitSnd.cpp's declaration follows), and the copy at 0x72A300 (which ran on into gData_0072A314) is Missile.cpp's; gpfnCltHitFuncs (Missile.cpp) is 82 entries, not 98, and 0x72A650 (+4 B) is PlrSkills.cpp's; gaLightOffsetsA (Unknown_004DEDB0.cpp) is 10 records, not 11, and 0x72ADA8 (which ran on into gData_0072ADD8) is Unknown_004DF6C0.cpp's; VERIFIED d8c4cd17eb1850a2c561edfd07f94a372e1a0b21
  - based on main #340.

- lane1/object-data 3bb2b07e1 0->0 Object.cpp's data start (lane 4's note): the borrowed copy at 0x727708, the 22-int table at 0x727744 and the 80-byte block at 0x7277A0 (17 ints, then pointers to 0x727748 and to itself) are planned in Object.cpp around gnShrineHandlerCount; borrowed data 1,830 -> 1,599 B; VERIFIED 6e79b82c1ff197a567a61c19f141ccffdfe6cb36
  - based on main #339. This takes lane 1's borrowed-data rows 0x7277A0 (80 B); 0x7278BC (64 B) was useitem's copy, done in #333.

- lane1/skills-objects 32fd04d76 +2 placeholders (Unknown_004C9420.cpp, Unknown_004C9D50.cpp; Unknown_004C9320.cpp becomes Unknown_004E6E30.cpp) the four back-to-back copies 0x727DBC-0x727EAC are four data-less objects between Skills.cpp and UnitSnd.cpp: SkillsBar.cpp (on main), 0x4C9420-0x4C97C0 (new placeholder; SkillsPal's 0x4C9B40 calls the 43-byte 0x4C9460 out of line, so it is not SkillsPal code), SkillsPal.cpp, and 0x4C9D50-0x4CA280 (new placeholder; its .bss gdwNextTick 0x7C78B0 sits right before UnitSnd.cpp's gaLevelVisited 0x7C78B8). Each takes its copy; 0x4C9420's object takes the offset tables 0x4C9490 reads; Skills.cpp's 0x4C9060 (inside SkillsBar's run) joins SkillsBar.cpp; Skills.cpp keeps a context copy of 0x4C9D50, which 0x4C9060 inlines and nothing calls; VERIFIED b916f65a6436560a80b546124259bcd7fa2f1e3f
  - based on main #337. Left: Skills.cpp's 0x4C8670 (inside SkillsBar's run) needs gaLobBrackets' type in SkillsBar.cpp.

## In progress

- **Withdrawn: the UI/editbox.cpp split.** Lane 4's split is the one posted ready; mine (lane1/editbox-split) was never pushed and is dropped. For lane 4, in case it helps check theirs: the .rdata order is button vtables, the .\UI\editbox.cpp path string (used only by the edit-box functions 0x4BB170/0x4BB210/0x4BB620/0x4BBBB0), edit-box vtables and strings, spinner vtables and "%s\ui\menu\spinner"; in .data, the copy 0x72756C + gaButtonStrings go with the button classes, 0x727608 with the edit box, 0x727688 with the spinner.

- **0x4A4AD0 variant-search template:** lanes/vsearch/0x4A4AD0.cpp (unit Source/D2Client/Unknown_004A43E0.cpp on #331, function marked; with the first alternatives it builds 1,202/1,232 like now). Groups, following the coordinator's listing note (bPageDown gets ebx in the original): const/plain for bInList and bPageDown; bButton as `GetKeyConfigButtonAt != 3` or `IsOnKeyConfigButton`; the all-clear condition with !bPageDown moved first or the pressed test last; block 0 as `bInList || gaPressed[0]`, reversed, or with the hit test called again instead of bInList; the page-down block's condition order, `gaPressed[5] = bPageDown && gbRedraw`, and its inner test as gbRedraw / `bPageDown && gbRedraw` / `gaPressed[5]`; the button block's condition order.
- **PlrSkills.cpp-to-Wall2.cpp object map:** settled the Particle/GfxUtil question in favour of particle-strays (on main #332): with 0x4DA0B0/0x4DA0F0's bodies in GfxUtil.cpp, 0x4DA350 inlines them and stops matching, so they were not in 0x4DA350's unit. The line-only asserts there (425, 54, 129) don't rise with address, so I take them as coming from inlined header code. Still open: which four objects besides Particle, GfxUtil, CUnitEvent and PlayerList hold the other copies in gpfnClientStateRemFuncs (candidates: 0x4D9FC0, the 0x4DC3E0 relation-flag group, 0x4DC510 (line 22, after PlayerList's 39), 0x4DC580 (line 97), Unknown_004DC710/004DC7B0/004DCAA0, Item.cpp's 0x4DCD40). One group is certain: 0x4DCA30, 0x4DCAA0, 0x4DCD40 and 0x4DCE10 share the .bss block 0x7C89D0-0x7C8A04, which follows GfxUtil's gdwFadeTick (0x7C89CC) directly, so they are one object (timed hints / level sounds).
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
