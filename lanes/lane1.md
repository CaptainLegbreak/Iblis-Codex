# Lane 1

Written by lane 1 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane1/one-screenheight-r 3514d976a 0->0 gnScreenHeight (0x711470): D2Client.h declares it as gnScreenHeight, the suffixed uses take that name, and 47 private declarations go from units that include D2Client.h; VERIFIED e772c83f971be867452c7ca456185e5956de0ae0
  - based on main #302 (main reached #304 while it verified). Touches lane 4's files (many D2Client units); merge alone, as asked.
  - kept: UI/inv_004886C0.cpp keeps one private declaration under the old name gnScreenHeight_00711470. 0x488B00 builds equal only with a second declaration of 0x711470 in scope; the count matters, not the name. Swapping the operands of `gnScreenHeight + gnPanelOffsetY - 0x6D` does not help, and moving a declaration ahead of D2Client.h does not either.
  - kept (they do not include D2Client.h): UI/inv_00491D20.cpp, UI/text_0049C9C0.cpp, Unknown_00494EB0.cpp, Unknown_004AA9C0.cpp, Unknown_004ABC30.cpp.
  - not touched: UI/inv.cpp `gScreenHeight` (in an unmarked copy of 0x494EB0), Storm/Unknown_006CAA30.cpp (lane 3, own `gnScreenHeight_00711470`).
- lane1/hdr-4df6c0-2 6ec053a92 0->0 D2Client.h: 0x4DF6C0 is declared as GFXUTIL_ApplySoundEnviron instead of the unused sub_004DF6C0; VERIFIED a57139fe6f3b53f305c2618a526ee1e86125452e
  - based on main #299. Replaces lane1/hdr-drop-4df6c0.
  - Dropping the line outright breaks 0x488B00 (UI/inv_004886C0.cpp) the same way as above, so the line is corrected in place. one-screenheight-r does not depend on it.

## In progress

- Borrowed 0x4A4AD0 (StandIns/D2Client_004A4AD0.cpp), in UI/text.cpp between 0x4A4AA0 and 0x4A4FA0 (local WIP, not pushed):
  - lane-7 notes received; they only fix the host (text.cpp, via the old text_0049D490.cpp) because the helpers use custom register conventions. That part holds.
  - with `gnKeyConfigFirstVisible` static (as in the stand-in) and 0x4A4500 written back in the stand-in's plain form, 0x4A4500 matches again and 0x4A4AD0 gets the original's block structure: 1,210 of 1,232 B, same calls, same join/reload blocks, constants and slots in step.
  - what is left is register choice: the original keeps nY in ebx for the first helper calls, the first visible line in ebx and the GetTickCount pointer in esi; ours keeps bInList in ebx, then the GetTickCount pointer in ebx and the first visible line in esi. Declaration order of the seven hit flags and the form of the first test do not change it.
  - text.cpp's unmarked copy of the stand-in body (~line 6198) goes when this lands.

## Questions

## Notes for other lanes

- All lanes: the struct-count effect also covers plain declarations. In inv_004886C0.cpp, 0x488B00 changes with one fewer or one more `extern int` in scope (D2Client.h lines included). GetHitSounds (0x4CA560) now matches only with +4..+6 dummy structs, not +2..+4 as on #283. Header edits that add or remove declarations can flip such functions in units that never use them.

## Left in place (and why)

- Unknown_004CA560 (GetHitSounds): still MISMATCH in UnitSnd.cpp on #304; it moves with the declaration count (window now +4..+6), so not landed.
- Unknown_004C0440 (0x4C0550), Unknown_004C7C80, Unknown_004C97C0 (handed back by lane 4): not started. The evidence points at useitem.cpp and Skills.cpp, where lane 4 saw register changes.
- ITEM_QueryCacheAddress (0x4DF630, Item.cpp): waiting for better evidence.
- Unknown_004D1300: only builds equal without Missile.cpp's callee bodies in the same unit, so it is not Missile.cpp code.
- Unknown_004DEDB0 (tile lights), _004DF4B0 / _004DF1C0 leftovers: no file evidence yet.
