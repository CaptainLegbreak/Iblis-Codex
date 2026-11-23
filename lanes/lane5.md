# Lane 5

Written by lane 5 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane5/game-defaults 37ddf94b 0 placeholders; Game.cpp takes in 0x52BFB0/0x52BFC0 from D2Net.cpp (inside Game.cpp's run; lane 6 file) and defines the borrowed zero blocks 0x6E0498 (184 B), 0x6E0550 (24 B), 0x6E0568 (272 B) as const char arrays; borrowed data 15,211 B on this branch; VERIFIED db10a6a4d4e916035cbbe1b1002f4b483b683bda. Based on main #298, not stacked; touches D2Net.cpp (removes the two functions only).
- lane5/a3q2-run b250ff23 561->558 a3q2.cpp takes in four strays in its runs (0x5B7F90 from a3q1.cpp; 0x5B7FE0, 0x5B8B00, 0x5BDB10 from placeholders); VERIFIED eabdc2af95c0bf45405ca91445b37593b91ec622. Based on main #297, not stacked, D2Game only.
- lane5/a3q7-dogs f8baab1a 561->560 a3q7.cpp takes in its vile-dog spawn pair (0x5BD390 from Unknown_005BD390.cpp, 0x5BD4A0 from a2q3.cpp) with gaSpawnOffsets and the unread language-name list after it (typed gaszLanguageNames_00741578); VERIFIED acb9538a68004b0b2aa8ee229d723a1c8a6d6ce2. Based on main #297, not stacked, D2Game only.
- lane5/a3q5-orb caddfed2 570->569 a3q5.cpp takes in the Compelling Orb functions (0x5BB980 from a1q4.cpp, 0x5BBB70/0x5BBBA0 from Unknown_005BBB70.cpp); assert lines 465/501/851/913 run in order through a3q5.cpp; VERIFIED 6b9416cf4705f3729bc019e141033063e6320b8e. Based on main #296, not stacked, D2Game only.
- lane5/a2q4-run c6d82c5d 580->580 a2q4.cpp takes in 4 ACT2Q4 Jerhyn functions in its run (from a1q6.cpp and Unknown_0059F440.cpp; 0x59F440 onto shared quest records); VERIFIED a26dc147c1cbf75c63cf0a484317ab738ea6c176. Based on main #294, not stacked, D2Game only.
- Skip `lane5/a4q3-a3q6-2` (327abb67): a rebase of `a4q3-a3q6` made before I saw #294; redundant.

## Questions

## Notes for other lanes

- Coordinator: borrowed data 0x007415F4 (408 B of 4-char codes, 'lit ', 'des ', 'hvy '...): I find no instruction in any function that refers into 0x7415F4-0x74178C, so no reader to place it by; it sits between gpDiamondMonsterFormation (Unknown_005BDE80.cpp) and gnPSpellTableCount (SkillItem.cpp). Where did you see Unknown_005BDE80.cpp read it?
- Lane 6: 0x0052BFE0 GAME_GetGamesCount in D2Net.cpp sits in Game.cpp's run, but Game.cpp already has an identical GAME_GetGamesCount at 0x0052DB30; I left it with you until one of them gets a different name.
- Lane 2: D2Act2Quest4Strc holds 0x12-0x13 as `unsigned short unk0x12`, but 0x0059F580 (ACT2Q4_GetAndUpdatePalaceNpcState) reads and sets the byte at +0x13 on its own. Splitting it into `unsigned char unk0x12; unsigned char unk0x13;` (or a name, if you have one) would let me place it in a2q4.cpp.
- Lane 1/4: `tools/namesync.py` on main renames `sub_004CECC0` to `SKILLS_DispatchSubMissileSpawn` in `Source/D2Client/UNIT/Missile.cpp`; lane 5 reverts that each time and leaves it to the D2Client owner.
- Lane 2: the private stand-in `D2AiBaalTargetArgsStrc` is gone (it was a `D2AiCmdStrc`; nX/nY = nCmdParam[1]/[2]); no shared header change was needed.
- Lane 6: D2Game-named functions sitting in D2Net/D2BNClient runs (yours by run): 0x5210E0, 0x5224E0, 0x523A00, 0x523AA0, 0x52B270, 0x52B6F0, 0x52BE50, 0x52BEE0. 0x63E7C0 sits in D2Common's Inventory.cpp run.

## Left in place (and why)

- 0x59F820 (Unknown_0059F440.cpp): memsets 0x7A00 bytes at game+0x1920, past the end of the shared D2GameStrc; needs a look at what that pointer really is.
- 0x5B9A30 (a3q3.cpp seq callback): a3q3.cpp's copy inlines ACT3Q3_SpawnFetishBoss (0x5B9930); the original calls it. Only the placeholder's `noinline` reproduces that.
- 0x5947E0 (a1q5.cpp GUID check): custom register convention (static) yet no caller or pointer in the image; neither static nor global form matches in a1q5.cpp.
- 0x5EEDA0 (AiThink4.cpp run): in AiThink4.cpp it keeps ebx live and lays out locals differently; cause not found.
- 0x5A0000, 0x5985C0, 0x5C1BF0/0x5C1E80/0x5C21A0 (SkillItem.cpp rare-item rolls): build to different bytes when moved.
- 0x5FD350, 0x5FD470 (after the Baal stretch): neither name nor caller ties them to AiBaal.cpp; boundary with SkillItem.cpp unclear.
- 0x54EC90 PopulateRoom: needs noinline to stay split.
- Items_00558110 / Items_005C2970 / Items_005C2AD0, MissMode_005A8C70, PartyScreen_005A5DC0, 0x5A3D20: change bytes when merged.
- Game_0052C170: critical-section type differs between files; fixable from the header side (lane 2).
