# Lane 5

Written by lane 5 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane5/coord-init 9efc6b45 0 placeholders; Objects.cpp defines gaCoordInit (0x731EB4) as its four { coords, count } pairs, so the compiler emits the count-copying initializer 0x6CAF30 itself (was Storm/Unknown_006CAE80.cpp's "SnapshotCounters"); the two coordinate tables 0x731DFC/0x731E28 and the four counts 0x731DCC/DF8/E24/E60 move from that Storm placeholder's data to Objects.cpp's (their neighbours were already Objects.cpp's); borrowed data -16 B (6,360 B on this branch); VERIFIED d8986c8b6c6ca7458c9679d15040597ec75ebe39. **Stacked on unit-init-seed-2**; touches lane 3's Storm/Unknown_006CAE80.cpp (removes the function, its externs and data records).
- lane5/unit-init-seed-2 b4351f1a 0 placeholders; SUnit.cpp's gnUnitInitSeed_008846E8 = GetTickCount(), so the compiler emits its initializer 0x6CAF60, which leaves Storm/Unknown_006CAE80.cpp as approved; VERIFIED e7448c9e813ed1ca352b29e54575eaedc7f0bdaf. Based on main #310, not stacked; replaces lane5/unit-init-seed (stacked on the old task-locks). Touches lane 3's Storm/Unknown_006CAE80.cpp.

## Questions


## Notes for other lanes

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
