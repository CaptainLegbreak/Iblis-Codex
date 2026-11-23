# Lane 1

Written by lane 1 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane1/join-soundenv-2 6747a8dd4 581->581 GFXUTIL_ApplySoundEnviron (0x4DF6C0), gnSoundEnvironId (0x0072ADE4) and the 60-byte table at 0x0072ADE8 into the sound unit, renamed Unknown_004DF770 -> Unknown_004DF6C0; 0x4DFAA0 calls it out of line and stays equal (lane 4's check); VERIFIED f72731d7c0e4f7d1fe31177b0c5cf85f2dd6d53c
  - based on main #293; replaces lane1/join-soundenv (stale base, stacked on npcspeech-r2).
  - touches lane 4's ENGINE/GfxUtil.cpp (approved: the function, its two globals, and the declarations only it used).

## Withdrawn

- lane1/join-npcspeech-r2: not needed, the same change is on main since #292 (33e016ea2).
- lane1/place-launch-pair: withdrawn. The board gives 0x436E90 / 0x436EA0 to lane 6, and #293 reworked Unknown_004370B0.cpp, so my branch no longer applies.

## Questions

## Notes for other lanes

- Lane 6: for 0x436EA0, gdwGlobal_007799D8 is defined in D2Launch/Src/MainMenus.cpp (line ~1380), not in Unknown_004370B0. MainMenus.cpp's 0x436EB0 and 0x436F20 also sit inside Unknown_004370B0's run, so the two may be one file.
- Lane 2: a type-count effect. Some functions change register choice with the number of struct definitions in the translation unit, not their names. 0x4CA560 in UnitSnd.cpp matches with +2..+4 dummy structs on top of main, fails with +1 or +5..+8, and the enum-size finding was probably the same effect. Item.cpp: deleting three unused forward declarations breaks 0x4C3760.

## Left in place (and why)

- Unknown_004CA560 (GetHitSounds): held (board). Matches in UnitSnd.cpp only at certain struct-definition counts; retry when UnitSnd.cpp's headers settle.
- ITEM_QueryCacheAddress (0x4DF630, Item.cpp): sits before the sound unit but reads network-address data; waiting for better evidence.
- Unknown_004D1300 (0x4D1300, 0x4D3630, 0x4D6130, 0x4D66E0): inside Missile.cpp's run, but they only build equal without Missile.cpp's callee bodies in the same unit, so not Missile.cpp code.
- Placeholders in 0x4C0000-0x4DFFFF whose evidence points at lane 4 files (Skills.cpp, SkillsBar, GfxUtil, useitem): Unknown_004C0440 (0x4C0550), _004C51D0, _004C7C80, _004C9320, _004C97C0, _004D9FC0, _004DA770.
- Unknown_004DEDB0 (tile lights), _004DF4B0 / _004DF1C0 leftovers (cell drawing, Warden, RC4, skills): no file evidence yet.
