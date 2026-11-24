# Lane 1

Written by lane 1 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane1/skills-placeholders 6ce2d18e7 -2 placeholders: Unknown_004C7C80 (0x4C7C80 -> SKILLS/Skills.cpp, 0x4C8350 -> SKILLS/SkillsBar.cpp, which already held its body unmarked) and Unknown_004C97C0 (0x4C97C0 -> Skills.cpp, a gpfnClientSkillDoFuncs entry; Skills.cpp's inline SEED_RollLimitedRandomNumber becomes ...Inline so the real 0x45C390 can be called); VERIFIED d31153616352fef0488b6729a8fb07539a3ebee7
  - based on main #311. Touches lane 4's Skills.cpp and SkillsBar.cpp (both are handed-back placeholders from the work list).

- lane1/unitsnd-table 5af46c365 0->0 UnitSnd.cpp: the 116 pieces at 0x00727F48-0x007295C8 become one D2UnitSndObjectStrc gaUnitSndObjects[121] (5,808 B); gapUnitSndObjects points at its elements, gaUnitSndObject3D is gaUnitSndObjects[21]; borrowed data should drop by 2,692 B (verify shows 9,924 B); VERIFIED fdb0012051a0a221d5c2df4ff6de6801b4344474
  - based on main #307 (main is #309 now).


## In progress

- Borrowed 0x4A4AD0 (StandIns/D2Client_004A4AD0.cpp), in UI/text.cpp between 0x4A4AA0 and 0x4A4FA0 (local WIP, not pushed):
  - lane-7 notes received; they only fix the host (text.cpp, via the old text_0049D490.cpp) because the helpers use custom register conventions. That part holds.
  - with `gnKeyConfigFirstVisible` static (as in the stand-in) and 0x4A4500 written back in the stand-in's plain form, 0x4A4500 matches again and 0x4A4AD0 gets the original's block structure: 1,210 of 1,232 B, same calls, same join/reload blocks, constants and slots in step.
  - what is left is register choice: the original keeps nY in ebx for the first helper calls, the first visible line in ebx and the GetTickCount pointer in esi; ours keeps bInList in ebx, then the GetTickCount pointer in ebx and the first visible line in esi. Declaration order of the seven hit flags and the form of the first test do not change it.
  - tried since: making any subset of gaPressed, gnDragThumbY, gnDragMouseY, gdwKeyConfigRepeatTick, gnThumbRange, gnKeyConfigThumbScale, gbKeyConfigPressRepeat static (all 128 combinations): no change. Moving 0x4A4780 (TEXT_IsAbovePanelLine) into text.cpp: slightly worse (1,202 B). The gap is one register choice early on: the original keeps nY in ebx after the first helper call and spills bInList; we keep bInList in ebx and reload nY.
  - text.cpp's unmarked copy of the stand-in body (~line 6198) goes when this lands.

## Questions

- 0x4A4AD0 lead: text_0049A950.cpp and text.cpp are interleaved across 0x491940-0x4A8D50 (61 text_0049A950 functions sit inside text.cpp's address range, including the key-config handlers 0x4A5A40-0x4A5F70 that use gnKeyConfigSelected / gpListEntries / gnKeyConfigColumn). Making the key-config state text.cpp statics means joining at least those, likely the whole of text_0049A950 into text.cpp. That is lane 4's file and a large join. Should lane 4 do it, or may I do it on a lane1/ branch? Until then I keep 0x4A4AD0 local (1,210 of 1,232 B).

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
