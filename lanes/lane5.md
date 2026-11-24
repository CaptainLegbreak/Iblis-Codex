# Lane 5

Written by lane 5 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane5/lang-owners 9da62e3c 0 placeholders; two language-name copies go to the files whose data they precede and come from D2LanguageNames.h, included at the top: 0x731090 (planned as Game.cpp's last, ends at PlrSave.cpp's gbWriteSaveFile 0x7310CC) -> PlrSave.cpp, 0x741750 (planned as MonsterChoose.cpp's last, ends at SkillItem.cpp's gnPSpellTableCount 0x74178C) -> SkillItem.cpp; borrowed data unchanged (3,415 B); VERIFIED 8254f0b387011cabbe8122ce473fd3008dd1d227. Based on main #316, not stacked, D2Game only. (coord-init and unit-init-seed-2 merged in j78; coord-init-2 on the remote is the same two commits and can be ignored.)

## Questions


## Notes for other lanes

- Coordinator / lane 2 (language copies, D2Game): the same rule gives these owners, each copy ending exactly at the owner's first data, but the header include does not place yet, so they stay planned: 0x741578 -> MonsterChoose.cpp and 0x7314D0 -> QUESTS.CPP fail because a big pack(1) bytes-form record later in the object (gData_007415F4, 348 B; gData_0073192C, 188 B) is aligned to 8 by the compiler and shifts 4 B once the copy is in front (the image has them 4-aligned, so their real types differ); 0x732FB0 -> a5q2.cpp fails because gdwAct5Q2RuneCodes is planned `const` (lands in .rdata) though the image has it in .data; 0x73D4B4 -> Unknown_005B24E0.cpp fails because the zero int 0x73D52C after gtBonePrisonSpawnInfo goes to .bss. Typing those records properly should let each include land.
- Coordinator: the zero ints 0x7314CC (after SUnitInactive.cpp's three params) and 0x73D52C (after gtBonePrisonSpawnInfo) are .data in the image but `int x = 0;` compiles to .bss, so they stay borrowed (8 B). They are probably the tail of the preceding record (a 4th param / a 64-byte spawn info) rather than lone ints; not changed without a reader to prove it.
- Lane 2: D2Act2Quest4Strc holds 0x12-0x13 as `unsigned short unk0x12`, but 0x0059F580 (ACT2Q4_GetAndUpdatePalaceNpcState) reads and sets the byte at +0x13 on its own. Splitting it into `unsigned char unk0x12; unsigned char unk0x13;` (or a name, if you have one) would let me place it in a2q4.cpp.
- Lane 1/4: `tools/namesync.py` on main renames `sub_004CECC0` to `SKILLS_DispatchSubMissileSpawn` in `Source/D2Client/UNIT/Missile.cpp`; lane 5 reverts that each time and leaves it to the D2Client owner.
- Lane 2: the private stand-in `D2AiBaalTargetArgsStrc` is gone (it was a `D2AiCmdStrc`; nX/nY = nCmdParam[1]/[2]); no shared header change was needed.
- Lane 6: D2Game-named functions sitting in D2Net/D2BNClient runs (yours by run): 0x5210E0, 0x5224E0, 0x523A00, 0x523AA0, 0x52B270, 0x52B6F0, 0x52BE50, 0x52BEE0. 0x63E7C0 sits in D2Common's Inventory.cpp run.

## Left in place (and why)

- Borrowed 0x745580 (64 B: 0x11B + another language list) between D2Common Inventory.cpp and ItemMode.cpp data: the leading int is not 0 like the others, and the previous neighbour is lane 6's; left for now.
- Act 1 and Act 5 intro clusters (Unknown_0058F870.cpp 0x58F870-0x58FB80 before a1q1.cpp; 0x586B50/0x586C40/0x586C50 before a5q1.cpp): the Act 2/3 intros open a2q0.cpp/a3q0.cpp, but there is no a1q0.cpp or a5q0.cpp and nothing names the file; left until evidence turns up.
- 0x5985C0 (Unknown_00598220.cpp): Act 2 intro's empty status filter, named ACT3Q7_StatusFilterCallback like a2q0.cpp's own stub; needs its own name before it can join a2q0.cpp.
- 0x59F820 (Unknown_0059F440.cpp): memsets 0x7A00 bytes at game+0x1920, past the end of the shared D2GameStrc; needs a look at what that pointer really is.
- 0x5B9A30 (a3q3.cpp seq callback): a3q3.cpp's copy inlines ACT3Q3_SpawnFetishBoss (0x5B9930); the original calls it. Only the placeholder's `noinline` reproduces that.
- 0x5947E0 (a1q5.cpp GUID check): custom register convention (static) yet no caller or pointer in the image; neither static nor global form matches in a1q5.cpp.
- 0x5EEDA0 (AiThink4.cpp run): in AiThink4.cpp it keeps ebx live and lays out locals differently; cause not found.
- 0x5A0000, 0x5985C0, 0x5C1BF0/0x5C1E80/0x5C21A0 (SkillItem.cpp rare-item rolls): build to different bytes when moved.
- 0x5FD350, 0x5FD470 (after the Baal stretch): neither name nor caller ties them to AiBaal.cpp; boundary with SkillItem.cpp unclear.
- 0x54EC90 PopulateRoom: needs noinline to stay split.
- Items_00558110 / Items_005C2970 / Items_005C2AD0, MissMode_005A8C70, PartyScreen_005A5DC0, 0x5A3D20: change bytes when merged.
- Game_0052C170: critical-section type differs between files; fixable from the header side (lane 2).
