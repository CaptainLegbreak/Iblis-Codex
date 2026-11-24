# Lane 4

Written by lane 4 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane4/skilltree d278e6f3 -4 placeholders (Unknown_004A9D70.cpp, Unknown_004ABC30.cpp, Unknown_004AC200.cpp, Unknown_004AC4D0.cpp empty): the skill tree object 0x4AA900-0x4AC730 gathers into Unknown_004AA9C0.cpp (16 functions from Unknown_004A76C0.cpp, Unknown_004A9BD0.cpp, Unknown_004A9D70.cpp, Unknown_00499500.cpp and the four placeholders). Its asserts start again at 136 in 0x4AA920; its data starts with its copy at 0x724BB0 (still inside gData_00724BAE in Unknown_004A76C0.cpp) and runs to the next object's copy at 0x724D3C; its bss 0x7C0838-0x7C0C58 is read only by these functions, and its records (gaPanelCels, gnTabSelection, gaSkillTabX, the button and panel flags) move in. 0x4AAAA0 had two bodies with different parameter orders; it is one definition now, inlined and then called by 0x4AACE0. The dead emit helper in Unknown_004A9BD0.cpp and the file's one context directive go. 0x4AC730/0x4AC760 (monster data accessors around Monster.cpp's 0x4AC740) stay: they sit with the next object. VERIFIED 8ec76a807f72 on #321. **Stacked on lane4/spellsel-join**; nothing outside lane 4.

- lane4/spellsel-join 9b657eed no placeholder change: spellsel.cpp (the user of `.\UI\spellsel.cpp`, object 0x4A7AE0-0x4AA900; asserts 236-1316; its data starts with the copy at 0x724A80, which is still planned in Unknown_004A6460.cpp, see the note below) takes 25 functions of its object: the skill select icon and hotkey functions from Unknown_004A76C0.cpp (10), Unknown_004A9BD0.cpp (6), inv.cpp (7, among them 0x4AA8B0-0x4AA8F0 just before the skill tree), Unknown_004A9D70.cpp (0x4AA1F0) and text_0049A950.cpp (0x4A8D50). 0x4A8A30, 0x4A8CF0, 0x4A8DF0 and Unknown_004A7AE0.cpp's 0x4A8ED0-0x4A9870 still differ there. VERIFIED a2211f1a40cd on #321. Not stacked; nothing outside lane 4.

- lane4/levelevents 40f5e749 -1 placeholder (Unknown_0046B630.cpp empties): the level event object 0x46AD10-0x46C140 (timed boxes, level event requests and timers, boss death spawns, throne and Den of Evil checks, countdown) gathers its strays into Unknown_0046ACE0.cpp: six View.cpp functions (including 0x46B630, which runs-sub-2 had put in View.cpp from surrounding View.cpp strays), SCMD_TriggerNearbyMonsterEffect, UI_SetTimerUnitId with gnTimerUnitId, Unknown_0046B630.cpp whole with gpfnLevelEvents, and CUNIT_DrawCountdown (0x46C060, whose 0x200-byte buffer has no cookie, so the unit is built /GS-). Its bss 0x7A742C-0x7A746C and data 0x7129CC-0x712A28 (ending with its own language-table copy) are what they read. 0x46B850, ROSTERPETS_GetPulseColor and SCMD_GetLevelLight belong here too but still differ. VERIFIED c924a9f22788 on #318. Not stacked; nothing outside lane 4.

## Questions

## Notes for other lanes

- Lane 1: the copy at 0x724D3C starts the data of the object after the skill tree, which by the data that follows (gpfnUModCallbacks, 0x724D78) is MonUnique.cpp. 14 of its pointers sit inside gaSkillTabX (planned as int[12][3], 144 B; the table itself is 88 B) and the 15th is gData_00724D74, left in Unknown_00499500.cpp. I'm not moving them into your file.

- Coordinator: I placed the copies of levelevents, inv-split, levelup-split, keyconfig-split and options-split-2 by the "copy ends the object's data" reading. With language-objects.md's rule (the copy starts it), each of those copies belongs to the next object's file: 0x712A28 (levelevents), 0x721DF8 (inv-split), 0x7247D8 and 0x724A80 (keyconfig, levelup), 0x713008 (options). The code splits stand; only the copy records move. I'll do that on one branch once spellsel-join and skilltree are in, together with spellsel.cpp's own data (gaSkillIconCels, 0x724AC0, now in Unknown_004A76C0.cpp).

- Coordinator, lane 3: WardenClient's RTTI (0x700140-0x70018C: object locator, class hierarchy, base class array and descriptor) has come from the compiler since warden-class (#307); PROVENANCE marks it `source`. 0x70018C-0x7001C0 is UIWidget's (type descriptor 0x7275B0), also `source` now. Nothing left to take there.
- Lane 1: 0x721D18 (one of the three borrowed copies after WardenClient's data) is probably UnitMode.cpp's: by text order WardenClient, UnitMode, SoundHdr come next. I'm not placing it.
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

