# Lane 5

Written by lane 5 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane5/task-locks 1290899c 534->532 Task.cpp's two lock globals become objects (Fog's out-of-line CCritSect array + an inline-ctor lock), so it emits the four initializers/destructors 0x6CAF70/0x6CAF90/0x6CB490/0x6CB4A0 itself; they leave Storm/Unknown_006CAE80.cpp, Storm/Unknown_006CAF90.cpp, Storm/Unknown_006CB4A0.cpp (both removed) and Bnclient/Unknown_006CB420.cpp as approved; Task.cpp now compiles /EHsc (the eh vector iterators need it; all its functions still equal); VERIFIED f969f40c2a7d79882c6d47011fb5d8534d4a6865. Based on main #305, not stacked; touches lane 3/6 placeholders as above.
- lane5/prime-nova b8dd60e3 0 placeholders; defines borrowed data: 0x6E31E8 (SkillMonst.cpp: gnPrimePoisonNovaX/Y as whole const int[16] tables, replacing a split 4 B + 60 B), 0x7314CC and 0x73D52C (int + unread language list closing SUnitInactive.cpp's and Unknown_005B24E0.cpp's data); borrowed data 14,319 B on this branch (expected -132 B); VERIFIED 3bab3cd3ac7a70c4d0a49994046ce8bbacfe8cd7. Based on main #303, not stacked, D2Game only.

## Questions


## Notes for other lanes

- Lane 2 / all: the 15-entry language-name list ('English' ... 'Unknown', '14') appears unread at the end of several D2Game files' data (AiThink.cpp twice, a3q7.cpp, MonsterChoose.cpp). It looks like a static array defined in a header those files include; if lane 2 knows the header, the copies could become one header definition.
- Lane 2: D2Act2Quest4Strc holds 0x12-0x13 as `unsigned short unk0x12`, but 0x0059F580 (ACT2Q4_GetAndUpdatePalaceNpcState) reads and sets the byte at +0x13 on its own. Splitting it into `unsigned char unk0x12; unsigned char unk0x13;` (or a name, if you have one) would let me place it in a2q4.cpp.
- Lane 1/4: `tools/namesync.py` on main renames `sub_004CECC0` to `SKILLS_DispatchSubMissileSpawn` in `Source/D2Client/UNIT/Missile.cpp`; lane 5 reverts that each time and leaves it to the D2Client owner.
- Lane 2: the private stand-in `D2AiBaalTargetArgsStrc` is gone (it was a `D2AiCmdStrc`; nX/nY = nCmdParam[1]/[2]); no shared header change was needed.
- Lane 6: D2Game-named functions sitting in D2Net/D2BNClient runs (yours by run): 0x5210E0, 0x5224E0, 0x523A00, 0x523AA0, 0x52B270, 0x52B6F0, 0x52BE50, 0x52BEE0. 0x63E7C0 sits in D2Common's Inventory.cpp run.

## Left in place (and why)

- Borrowed 0x745580 (64 B: 0x11B + another language list) between D2Common Inventory.cpp and ItemMode.cpp data: the leading int is not 0 like the others, and the previous neighbour is lane 6's; left for now.
- Borrowed 0x731EB8 (4 B, gnUnitInitSeed set by the dynamic initializer 0x6CAF60 in Storm/Unknown_006CAE80.cpp, read by Objects.cpp): same cross-lane question as the Task.cpp locks.
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
