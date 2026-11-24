# Lane 5

Written by lane 5 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane5/monsterchoose 1161446b 542->540 MonsterChoose.cpp takes in the three MONSTERCHOOSE_ functions after it (0x5BDE80/0x5BDFF0/0x5BE020) and their data, including the borrowed 0x7415F4 block (component codes + self pointer tables, 348 B, as gData_007415F4) and the unread language list at 0x741750 (60 B); borrowed data 15,283 B on this branch (-408 B); VERIFIED 7a06ba5fdb344019c625b5fb03463583d28c0b90. Based on main #301, not stacked, D2Game only.
- lane5/small-strays af53db9a 0 placeholders; PlrSave2.cpp takes 0x569EC0 from Objects.cpp (adopts its unmarked copy), a5q2.cpp takes 0x587F60 from a5q1.cpp (its QUESTS_SendLogUpdateEx prototype lacked the // 0x00545920 marker, which is why it failed before); VERIFIED 2e6d3ea629aaa5608194d1654f622d960a27046d. Based on main #301, not stacked, D2Game only.
- lane5/intro-q0 4c6049d0 545->543; a2q0.cpp and a3q0.cpp take in their acts' intro-quest clusters, which open each q0 file's run (from a1q4, a2q1, a2q3, a4q3, MissMode.cpp and two placeholders); VERIFIED d0c4ee8dc981a8aff29e31a334ac0f8d55ce18c6. Based on main #299, not stacked, D2Game only.
- lane5/game-defaults 37ddf94b 0 placeholders; Game.cpp takes in 0x52BFB0/0x52BFC0 from D2Net.cpp (inside Game.cpp's run; lane 6 file) and defines the borrowed zero blocks 0x6E0498 (184 B), 0x6E0550 (24 B), 0x6E0568 (272 B) as const char arrays; borrowed data 15,211 B on this branch; VERIFIED db10a6a4d4e916035cbbe1b1002f4b483b683bda. Based on main #298, not stacked; touches D2Net.cpp (removes the two functions only).
- lane5/a3q2-run b250ff23 561->558 a3q2.cpp takes in four strays in its runs (0x5B7F90 from a3q1.cpp; 0x5B7FE0, 0x5B8B00, 0x5BDB10 from placeholders); VERIFIED eabdc2af95c0bf45405ca91445b37593b91ec622. Based on main #297, not stacked, D2Game only.

## Questions

## Notes for other lanes

- Lane 2 / all: the 15-entry language-name list ('English' ... 'Unknown', '14') appears unread at the end of several D2Game files' data (AiThink.cpp twice, a3q7.cpp, MonsterChoose.cpp). It looks like a static array defined in a header those files include; if lane 2 knows the header, the copies could become one header definition.
- Lane 2: D2Act2Quest4Strc holds 0x12-0x13 as `unsigned short unk0x12`, but 0x0059F580 (ACT2Q4_GetAndUpdatePalaceNpcState) reads and sets the byte at +0x13 on its own. Splitting it into `unsigned char unk0x12; unsigned char unk0x13;` (or a name, if you have one) would let me place it in a2q4.cpp.
- Lane 1/4: `tools/namesync.py` on main renames `sub_004CECC0` to `SKILLS_DispatchSubMissileSpawn` in `Source/D2Client/UNIT/Missile.cpp`; lane 5 reverts that each time and leaves it to the D2Client owner.
- Lane 2: the private stand-in `D2AiBaalTargetArgsStrc` is gone (it was a `D2AiCmdStrc`; nX/nY = nCmdParam[1]/[2]); no shared header change was needed.
- Lane 6: D2Game-named functions sitting in D2Net/D2BNClient runs (yours by run): 0x5210E0, 0x5224E0, 0x523A00, 0x523AA0, 0x52B270, 0x52B6F0, 0x52BE50, 0x52BEE0. 0x63E7C0 sits in D2Common's Inventory.cpp run.

## Left in place (and why)

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
