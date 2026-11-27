# Raw offset queue

Lines on main #473 that reach a field through a byte offset (`*(T*)((char*)p + N)` or `(char*)p + N`) instead of a named, typed member. 168 lines in all. Each one is a struct field not yet named or typed, or a record not yet declared. Fix it by giving the struct the field (named from D2MOO or from what the code does) and reading it as a member; the bytes must stay identical. The audit guard counts `raw offset access`, `byte pointer math` and `pointer casts`, and none may rise.

## Lane 1 (8 lines)

- `Source/D2Client/GAME/Wall2.cpp` (3): lines 102, 622, 652
- `Source/D2Client/SKILLS/SkillsNec.cpp` (2): lines 20, 22
- `Source/D2Client/Unknown_004DF4B0.cpp` (1): lines 223
- `Source/D2Client/Unknown_004DF1C0.cpp` (1): lines 342
- `Source/D2Client/Unknown_004E4670.cpp` (1): lines 1150

## Lane 4 (4 lines)

- `Source/D2Client/GAME/Game.cpp` (3): lines 3304, 3306, 3307
- `Source/D2Client/ENGINE/GfxUtil.cpp` (1): lines 1108

## Lane 5 (111 lines)

- `Source/D2Game/PLAYER/PlrMsg.cpp` (92): lines 1796, 1797, 1847, 1848, 2361, 2368, 2394, 2502, 2639, 2640, 2657, 2658, 2659, 2681, 2705, 2706, 2707, 2708, 2792, 2837, 2838, 2870, 2871, 2900, 2927, 2928, 2972, 2973, 3113, 3114, 3144, 3145, 3180, 3204, 3205, 3229, 3263, 3264, 3294, 3295, 3327, 3328, 3369, 3370, 3400, 3401, 3476, 3495, 3513, 3541, 3542, 3543, 3544, 3556, 3569, 3581, 3599, 3611, 3635, 3636, 3637, 3661, 3721, 3722, 3767, 3786, 3919, 3920, 3926, 3942, 3948, 3972, 3973, 3974, 4156, 4174, 4175, 4210, 4229, 4230, 4231, 4243, 4244, 4261, 4262, 4344, 4363, 4364, 4365, 4366, 4824, 4889
- `Source/D2Game/UNIT/SUnitMsg.cpp` (11): lines 576, 577, 582, 602, 608, 633, 659, 660, 661, 662, 794
- `Source/D2Game/D2Game.h` (2): lines 567, 582
- `Source/D2Game/GAME/CCmd.cpp` (2): lines 106, 203
- `Source/D2Game/OBJECTS/Objects.cpp` (1): lines 1176
- `Source/D2Game/UNIT/SUnitDmg.cpp` (1): lines 2258
- `Source/D2Game/UNIT/SUnit.cpp` (1): lines 706
- `Source/D2Game/GAME/SCmd.cpp` (1): lines 376

## Lane 6 (23 lines)

- `Source/D2BNClient/BnDownload.cpp` (7): lines 1361, 2164, 2323, 2465, 2497, 2530, 2558
- `Source/D2Win/Src/D2Comp.cpp` (4): lines 550, 764, 774, 1300
- `Source/D2Multi/Unknown_0043C8A0.cpp` (4): lines 88, 89, 98, 99
- `Source/D2Launch/Src/CharSel.cpp` (1): lines 2718
- `Source/D2Net/Unknown_0052B920.cpp` (1): lines 232
- `Source/D2Multi/Src/ChatDlg.cpp` (1): lines 4291
- `Source/D2Sound/Src/D2SoundSmp.cpp` (1): lines 1128
- `Source/D2CMP/SRC/Codec.cpp` (1): lines 519
- `Source/D2CMP/SRC/FastCmp.cpp` (1): lines 2307
- `Source/D2CMP/SRC/SpriteCache.cpp` (1): lines 1867
- `Source/Bnclient/Unknown_00524140.cpp` (1): lines 25

## Lane 8 (19 lines)

- `Source/D2Common/DATATBLS/DataTbls.cpp` (8): lines 837, 844, 848, 863, 870, 874, 925, 1127
- `Source/D2Common/DATATBLS/ItemTbls.cpp` (4): lines 435, 442, 446, 2013
- `Source/D2Common/DATATBLS/MissileTbls.cpp` (3): lines 396, 403, 407
- `Source/D2Common/Unknown_00668510.cpp` (2): lines 663, 670
- `Source/D2Common/Unknown_00681000.cpp` (1): lines 183
- `Source/D2Common/INVENTORY/Inventory.cpp` (1): lines 3859

## Lane 9 (3 lines)

- `Source/D2Gfx/SRC/Window.cpp` (2): lines 1588, 2500
- `Source/D2Direct3D/Src/d3dSmack.cpp` (1): lines 286
