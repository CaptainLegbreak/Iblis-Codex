# Language-table copies: an object map

The 15-entry language-name table (D2LanguageNames.h; strings 0x6CC77C-0x6CC81C) is a header static, so each object file that includes the header has exactly one copy in .data, at the start of that object's initialised data (the header is included before the file's own definitions; lanes 4, 5 and 6 found the same) (see COORDINATOR.md, Decisions).
This map lists all 308 copies in Game.exe .data on main #318: which planned definition holds each one, and the planned data just after it, which is the object the copy starts.

- **Copies in the plan:** 287. **Borrowed (not defined yet):** 21.
- **Planned files holding more than one copy:** 60. Each one spans that many original objects and can be split at its copies.
- **Runs of back-to-back copies (0x3C apart):** 49 runs with 2 or more copies. A run of N copies is N objects in link order with no initialised data of their own besides the table.

## Planned files holding several copies

| File | Lane | Copies | Copy addresses |
|---|---|---:|---|
| D2Common/DATATBLS/FieldTbls.cpp | lane6 | 15 | 0x749744, 0x749804, 0x749840, 0x74987C, 0x7498B8, 0x7498F4 … |
| D2Game/ITEMS/ItemMode.cpp | lane5 | 10 | 0x73200C, 0x732048, 0x732084, 0x7320C0, 0x732100, 0x745648 … |
| D2Client/Unknown_004DF6C0.cpp | lane4 | 9 | 0x72ADE8, 0x72CBE8, 0x72CC24, 0x72CC60, 0x72CC9C, 0x72CCD8 … |
| D2Client/UI/inv.cpp | lane4 | 8 | 0x712DD0, 0x712E0C, 0x712E48, 0x712E84, 0x712EC0, 0x721DF8 … |
| D2Client/UNIT/PlrSkills.cpp | lane1 | 8 | 0x72A788, 0x72A7C4, 0x72A800, 0x72A83C, 0x72A878, 0x72A8B4 … |
| D2Win/Src/D2Comp.cpp | lane6 | 8 | 0x72E010, 0x72EFD4, 0x72F010, 0x72F04C, 0x72F088, 0x72F0C4 … |
| D2Game/UNIT/sunitproxy.cpp | lane5 | 8 | 0x7312E0, 0x73131C, 0x731358, 0x731394, 0x7313D0, 0x73140C … |
| D2Win/Src/D2WinTextBox.cpp | lane6 | 7 | 0x72DE54, 0x72DE94, 0x72DED0, 0x72DF0C, 0x72DF48, 0x72DF84 … |
| D2Game/SKILLS/SkillNec.cpp | lane5 | 6 | 0x7419A4, 0x7419E0, 0x741A1C, 0x741A58, 0x741A94, 0x741AD0 |
| D2Game/Unknown_005D8100.cpp | lane5 | 6 | 0x741C0C, 0x741C48, 0x741C84, 0x741CC0, 0x741CFC, 0x741D38 |
| D2Game/Ai/AiThink4.cpp | lane5 | 6 | 0x741D90, 0x741DCC, 0x741E08, 0x741E44, 0x741E80, 0x741EBC |
| D2Launch/Src/CharSel.cpp | lane6 | 5 | 0x70CC10, 0x70CC50, 0x70CC8C, 0x7111D8, 0x711218 |
| D2Client/UI/text.cpp | lane4 | 5 | 0x723768, 0x724A80, 0x7274B0, 0x7274EC, 0x727528 |
| D2Client/UNIT/Item.cpp | lane1 | 5 | 0x727A50, 0x727DBC, 0x727DF8, 0x727E34, 0x727E70 |
| D2Game/PLAYER/PlrIntro.cpp | lane5 | 5 | 0x732850, 0x73288C, 0x7328C8, 0x732904, 0x732940 |
| D2Common/DATATBLS/MonsterTbls.cpp | lane6 | 5 | 0x7459D4, 0x745A28, 0x745A64, 0x745AA0, 0x745ADC |
| D2Common/Waypoint/Waypoint.cpp | lane6 | 5 | 0x7463E8, 0x7465E8, 0x746624, 0x746660, 0x7466A0 |
| D2Multi/Src/ComCallback.cpp | lane6 | 4 | 0x70EBE0, 0x70EC80, 0x70ECC0, 0x70F7A4 |
| D2Client/UI/SkillDesc.cpp | lane4 | 4 | 0x72D728, 0x72D994, 0x72D9D0, 0x72DA0C |
| D2Sound/Src/D2SoundSmp.cpp | lane6 | 4 | 0x72F8FC, 0x72F938, 0x72F974, 0x72F9B4 |
| D2Game/MONSTER/MonsterUnique.cpp | lane5 | 4 | 0x73C4C0, 0x73C4FC, 0x73C538, 0x73C578 |
| D2Common/UNITS/Units.cpp | lane6 | 4 | 0x744508, 0x744588, 0x7445C4, 0x744600 |
| D2Common/COMPOSIT/Composit.cpp | lane6 | 4 | 0x7458C4, 0x745920, 0x74595C, 0x745998 |
| D2Common/Unknown_006634F0.cpp | lane6 | 4 | 0x74880C, 0x748848, 0x748884, 0x7488C0 |
| D2Client/UI/automap.cpp | lane4 | 3 | 0x7113EC, 0x711430, 0x711D04 |
| D2Client/UNIT/Monster.cpp | lane1 | 3 | 0x7251E0, 0x7253A0, 0x730978 |
| D2Client/UI/SkillDesc_004E1FF0.cpp | lane4 | 3 | 0x72D8D8, 0x72D914, 0x72D950 |
| D2Lang/Unknown_00526100.cpp | lane6 | 3 | 0x730A28, 0x730A64, 0x730AA0 |
| D2Game/Ai/AiTatics.cpp | lane5 | 3 | 0x7310D0, 0x73110C, 0x731148 |
| D2Game/Quests/QUESTS.CPP | lane5 | 3 | 0x73192C, 0x731968, 0x7319A8 |
| D2Game/SKILLS/SkillItem.cpp | lane5 | 3 | 0x741888, 0x7418C4, 0x741900 |
| D2Common/Chat/Ignorelist.cpp | lane6 | 3 | 0x743780, 0x7437C0, 0x7442C8 |
| D2Common/Unknown_00665810.cpp | lane6 | 3 | 0x749690, 0x7496CC, 0x749708 |
| Fog/Src/ErrorManager.cpp | lane3 | 2 | 0x706584, 0x706618 |
| D2Launch/Src/MainMenus_00431AF0.cpp | lane6 | 2 | 0x70CB88, 0x70CBC4 |
| D2Multi/Src/ChatDlg.cpp | lane6 | 2 | 0x70CCD8, 0x70CD18 |
| D2Client/CORE/WINMAIN.CPP | lane4 | 2 | 0x70EDD0, 0x70EE10 |
| D2Client/GAME/Game_0044E5A0.cpp | lane4 | 2 | 0x70EE90, 0x70EED0 |
| D2Client/Unknown_0046B630.cpp | lane4 | 2 | 0x712A28, 0x712A64 |
| D2Client/DRAW/dLightMap.cpp | lane4 | 2 | 0x712C10, 0x712F08 |
| D2Client/GAME/View.cpp | lane4 | 2 | 0x712C54, 0x712C90 |
| D2Client/Unknown_004A43E0.cpp | lane4 | 2 | 0x724798, 0x7247D8 |
| D2Client/UI/useitem.cpp | lane4 | 2 | 0x7279B0, 0x7279EC |
| D2Client/GAME/Wall2.cpp | lane4 | 2 | 0x72A96C, 0x72A9A8 |
| D2Win/Src/D2WinMain.cpp | lane6 | 2 | 0x72DC00, 0x72DDD8 |
| D2Hell/Unknown_00517804.cpp | lane6 | 2 | 0x72FA20, 0x72FA60 |
| D2Net/Unknown_0052B920.cpp | lane6 | 2 | 0x730F84, 0x730FC0 |
| Storm/Unknown_006CAE80.cpp | lane3 | 2 | 0x731ED4, 0x731F10 |
| D2Game/ITEMS/Items.cpp | lane5 | 2 | 0x731F74, 0x731FB0 |
| D2Game/Unknown_00570420.cpp | lane5 | 2 | 0x7326B8, 0x7326F8 |
| D2Game/Quests/a5q3.cpp | lane5 | 2 | 0x736160, 0x7361A0 |
| D2Game/INVENTORY/InvMode.cpp | lane5 | 2 | 0x738CC8, 0x738D08 |
| D2Game/Quests/a2q8.cpp | lane5 | 2 | 0x73BEE0, 0x73BF20 |
| D2Game/Ai/AiThink.cpp | lane5 | 2 | 0x73D478, 0x73D4B4 |
| D2Common/DRLG/DrlgActivate.cpp | lane6 | 2 | 0x744348, 0x7443A8 |
| D2Common/ITEMS/Items.cpp | lane6 | 2 | 0x7446E8, 0x744724 |
| D2Common/SKILLS/Skills.cpp | lane6 | 2 | 0x7457B0, 0x7457EC |
| D2Common/Unknown_0064A2B0.cpp | lane6 | 2 | 0x74584C, 0x745888 |
| D2Common/ITEMS/ItemMods.cpp | lane6 | 2 | 0x745B18, 0x7463A8 |
| D2Common/Unknown_0063E6B0.cpp | lane6 | 2 | 0x748A58, 0x748A98 |

## Borrowed copies

Not defined by any file yet. It belongs to the object whose data follows it, normally the file of the next planned data (check that nothing else lies between).

| Copy | Lane | Data before (file) | Data after (file), gap |
|---|---|---|---|
| 0x705000 | lane6 / lane3 (edge) | gData_006FFC46 (D2Multi/Unknown_00444020.cpp) | gaIniEntries_00705040 (Storm/Unknown_00404F40.cpp), +0x4 |
| 0x70F728 | lane4 / lane6 (edge) | gszTypeHashObjectChunk (D2Client/Unknown_0044F9B0.cpp) | gpMsgRecordChunk_0070F7A0 (D2Multi/Src/ComCallback.cpp), +0x3C |
| 0x70F764 | lane4 / lane6 (edge) | gszTypeHashObjectChunk (D2Client/Unknown_0044F9B0.cpp) | gpMsgRecordChunk_0070F7A0 (D2Multi/Src/ComCallback.cpp), +0x0 |
| 0x721CDC | lane4 | gnWardenIfaceValue (D2Client/WARDEN/WardenClient.cpp) | gnAuxLevelEntries (D2Client/UI/inv.cpp), +0x7C |
| 0x721D18 | lane4 | gnWardenIfaceValue (D2Client/WARDEN/WardenClient.cpp) | gnAuxLevelEntries (D2Client/UI/inv.cpp), +0x40 |
| 0x721D58 | lane4 | gnWardenIfaceValue (D2Client/WARDEN/WardenClient.cpp) | gnAuxLevelEntries (D2Client/UI/inv.cpp), +0x0 |
| 0x727608 | lane4 / lane1 (edge) | gaButtonStrings (D2Client/UI/editbox.cpp) | gnShrineHandlerCount (D2Client/UNIT/Object.cpp), +0x158 |
| 0x727688 | lane4 / lane1 (edge) | gaButtonStrings (D2Client/UI/editbox.cpp) | gnShrineHandlerCount (D2Client/UNIT/Object.cpp), +0xD8 |
| 0x727708 | lane4 / lane1 (edge) | gaButtonStrings (D2Client/UI/editbox.cpp) | gnShrineHandlerCount (D2Client/UNIT/Object.cpp), +0x58 |
| 0x7278C0 | lane1 | gapfnObjectClientFn (D2Client/UNIT/Object.cpp) | gnHotspotCount (D2Client/UNIT/Item.cpp), +0x0 |
| 0x731090 | lane5 | gpfnGetDescription (D2Game/GAME/Game.cpp) | gbWriteSaveFile (D2Game/PLAYER/PlrSave.cpp), +0x0 |
| 0x741750 | lane5 | gData_007415F4 (D2Game/MONSTER/MonsterChoose.cpp) | gnPSpellTableCount (D2Game/SKILLS/SkillItem.cpp), +0x0 |
| 0x745584 | lane6 / lane5 (edge) | gaComponentItemTypeMap (D2Common/INVENTORY/Inventory.cpp) | gabDirection64To16 (D2Game/ITEMS/ItemMode.cpp), +0x0 |
| 0x749C00 | lane6 / lane4 (edge) | gData_00749B10 (D2Common/DATATBLS/FieldTbls.cpp) | gData_0074BF28 (D2Client/Unknown_004F4EC0.cpp), +0x22EC |
| 0x749C3C | lane6 / lane4 (edge) | gData_00749B10 (D2Common/DATATBLS/FieldTbls.cpp) | gData_0074BF28 (D2Client/Unknown_004F4EC0.cpp), +0x22B0 |
| 0x749C78 | lane6 / lane4 (edge) | gData_00749B10 (D2Common/DATATBLS/FieldTbls.cpp) | gData_0074BF28 (D2Client/Unknown_004F4EC0.cpp), +0x2274 |
| 0x749CB4 | lane6 / lane4 (edge) | gData_00749B10 (D2Common/DATATBLS/FieldTbls.cpp) | gData_0074BF28 (D2Client/Unknown_004F4EC0.cpp), +0x2238 |
| 0x749CF0 | lane6 / lane4 (edge) | gData_00749B10 (D2Common/DATATBLS/FieldTbls.cpp) | gData_0074BF28 (D2Client/Unknown_004F4EC0.cpp), +0x21FC |
| 0x749D2C | lane6 / lane4 (edge) | gData_00749B10 (D2Common/DATATBLS/FieldTbls.cpp) | gData_0074BF28 (D2Client/Unknown_004F4EC0.cpp), +0x21C0 |
| 0x749D68 | lane6 / lane4 (edge) | gData_00749B10 (D2Common/DATATBLS/FieldTbls.cpp) | gData_0074BF28 (D2Client/Unknown_004F4EC0.cpp), +0x2184 |
| 0x749DA4 | lane6 / lane4 (edge) | gData_00749B10 (D2Common/DATATBLS/FieldTbls.cpp) | gData_0074BF28 (D2Client/Unknown_004F4EC0.cpp), +0x2148 |

## Runs of back-to-back copies

| First copy | Copies | Data after the run (file) | Planned as |
|---|---:|---|---|
| 0x70CB88 | 2 | D2Launch/Src/CharSel.cpp | D2Launch/Src/MainMenus_00431AF0.cpp |
| 0x70CC50 | 2 | D2Client/UI/automap.cpp | D2Launch/Src/CharSel.cpp |
| 0x70F728 | 2 | D2Multi/Src/ComCallback.cpp | borrowed |
| 0x712A28 | 2 | D2Client/ENGINE/Gfx.cpp | D2Client/Unknown_0046B630.cpp |
| 0x712C54 | 2 | D2Client/UI/inv.cpp | D2Client/GAME/View.cpp |
| 0x712DD0 | 5 | D2Client/GAME/Roster.cpp | D2Client/UI/inv.cpp |
| 0x721CDC | 2 | D2Client/UI/inv.cpp | borrowed |
| 0x722298 | 2 | D2Client/UI/Hireables.cpp | D2Client/UI/inv.cpp |
| 0x7274B0 | 3 | D2Client/Sound/SoundInst.cpp | D2Client/UI/text.cpp |
| 0x7279B0 | 2 | D2Client/UNIT/Item.cpp | D2Client/UI/useitem.cpp |
| 0x727DBC | 4 | D2Client/UNIT/UnitSnd.cpp | D2Client/UNIT/Item.cpp |
| 0x72A788 | 8 | D2Client/GAME/Wall2.cpp | D2Client/UNIT/PlrSkills.cpp |
| 0x72A96C | 2 | D2Client/Unknown_004DEDB0.cpp | D2Client/GAME/Wall2.cpp |
| 0x72CBE8 | 7 | D2Client/Unknown_004DF6C0.cpp | D2Client/Unknown_004DF6C0.cpp |
| 0x72D8D8 | 3 | D2Client/UI/SkillDesc.cpp | D2Client/UI/SkillDesc_004E1FF0.cpp |
| 0x72D994 | 3 | D2Win/Unknown_004F5190.cpp | D2Client/UI/SkillDesc.cpp |
| 0x72DDD8 | 2 | D2Win/Src/D2WinPalette.cpp | D2Win/Src/D2WinMain.cpp, D2Win/Src/D2WinPalette.cpp |
| 0x72DE94 | 6 | D2Win/Src/D2WinFont.cpp | D2Win/Src/D2WinTextBox.cpp |
| 0x72EFD4 | 7 | D2Client/Unknown_004F4EC0.cpp | D2Win/Src/D2Comp.cpp |
| 0x72F8FC | 3 | D2Sound/Src/D2SoundSmp.cpp | D2Sound/Src/D2SoundSmp.cpp |
| 0x730A28 | 3 | Bnclient/Unknown_00527BE0.cpp | D2Lang/Unknown_00526100.cpp |
| 0x730F84 | 2 | D2Game/GAME/Game.cpp | D2Net/Unknown_0052B920.cpp |
| 0x7310D0 | 3 | D2Game/UNIT/sunitproxy.cpp | D2Game/Ai/AiTatics.cpp |
| 0x7312E0 | 8 | D2Game/UNIT/SUnitInactive.cpp | D2Game/UNIT/sunitproxy.cpp |
| 0x73192C | 2 | D2Game/PLAYER/PlrMsg.cpp | D2Game/Quests/QUESTS.CPP |
| 0x731ED4 | 2 | D2Game/ITEMS/Items.cpp | Storm/Unknown_006CAE80.cpp |
| 0x731F74 | 2 | D2Game/ITEMS/ItemMode.cpp | D2Game/ITEMS/Items.cpp |
| 0x73200C | 4 | D2Game/SKILLS/Skills.cpp | D2Game/ITEMS/ItemMode.cpp |
| 0x732850 | 5 | D2Game/UNIT/SUnitDmg.cpp | D2Game/PLAYER/PlrIntro.cpp |
| 0x73C4C0 | 3 | D2Game/MONSTER/MonsterMode.cpp | D2Game/MONSTER/MonsterUnique.cpp |
| 0x73D478 | 2 | D2Game/Unknown_005B24E0.cpp | D2Game/Ai/AiThink.cpp |
| 0x741888 | 3 | D2Game/SKILLS/SkillNec.cpp | D2Game/SKILLS/SkillItem.cpp |
| 0x7419A4 | 6 | D2Game/SKILLS/SkillAss.cpp | D2Game/SKILLS/SkillNec.cpp |
| 0x741C0C | 6 | D2Game/Ai/AiThink4.cpp | D2Game/Unknown_005D8100.cpp |
| 0x741D90 | 6 | D2CMP/SRC/SpriteCache.cpp | D2Game/Ai/AiThink4.cpp |
| 0x74430C | 2 | D2Common/DRLG/DrlgActivate.cpp | D2Common/DATATBLS/DataTbls.cpp, D2Common/DRLG/DrlgActivate.cpp |
| 0x744588 | 3 | D2Common/Stats/StatsEx.cpp | D2Common/UNITS/Units.cpp |
| 0x7446E8 | 3 | D2Common/INVENTORY/Inventory.cpp | D2Common/INVENTORY/Inventory.cpp, D2Common/ITEMS/Items.cpp |
| 0x745648 | 5 | D2Game/ITEMS/ItemMode.cpp | D2Game/ITEMS/ItemMode.cpp |
| 0x7457B0 | 2 | D2Common/Unknown_0064A2B0.cpp | D2Common/SKILLS/Skills.cpp |
| 0x74584C | 3 | D2Common/COMPOSIT/Composit.cpp | D2Common/COMPOSIT/Composit.cpp, D2Common/Unknown_0064A2B0.cpp |
| 0x745920 | 4 | D2Common/DATATBLS/MonsterTbls.cpp | D2Common/COMPOSIT/Composit.cpp, D2Common/DATATBLS/MonsterTbls.cpp |
| 0x745A28 | 5 | D2Common/ITEMS/ItemMods.cpp | D2Common/DATATBLS/MonsterTbls.cpp, D2Common/ITEMS/ItemMods.cpp |
| 0x7465E8 | 3 | D2Common/DATATBLS/Sequence.cpp | D2Common/Waypoint/Waypoint.cpp |
| 0x74880C | 4 | D2Common/Unknown_006634F0.cpp | D2Common/Unknown_006634F0.cpp |
| 0x749690 | 4 | D2Common/DATATBLS/FieldTbls.cpp | D2Common/DATATBLS/FieldTbls.cpp, D2Common/Unknown_00665810.cpp |
| 0x7497C8 | 14 | D2Common/DATATBLS/FieldTbls.cpp | D2Common/DATATBLS/AnimTbls.cpp, D2Common/DATATBLS/FieldTbls.cpp |
| 0x749B34 | 2 | D2Client/Unknown_004F4EC0.cpp | D2Common/DATATBLS/FieldTbls.cpp, D2Common/DRLG/DrlgGrid.cpp |
| 0x749BC4 | 9 | D2Client/Unknown_004F4EC0.cpp | D2Common/DRLG/DrlgVer.cpp, borrowed |

## Every copy, in address order

| Copy | Planned as | Starts the data of (next planned file) |
|---|---|---|
| 0x705000 | **borrowed** | Storm/Unknown_00404F40.cpp |
| 0x706518 | gData_00706518 (Storm/Unknown_00404F40.cpp) | Fog/Src/ErrorManager.cpp |
| 0x706584 | gaModeTable (Fog/Src/ErrorManager.cpp) | Fog/Src/ErrorManager.cpp |
| 0x706618 | gaszLanguageNames (Fog/Src/ErrorManager.cpp) | Fog/Src/ErrorManager.cpp |
| 0x708930 | gData_00708930 (Storm/zlib/trees.c) | Storm/Unknown_00426900.cpp |
| 0x708970 | gaTable_0070896C (Storm/Unknown_00426900.cpp) | D2Launch/Src/MainMenus.cpp |
| 0x70CB88 | gData_0070CB84 (D2Launch/Src/MainMenus_00431AF0.cpp) | D2Launch/Src/CharSel.cpp |
| 0x70CBC4 | gData_0070CB84 (D2Launch/Src/MainMenus_00431AF0.cpp) | D2Launch/Src/CharSel.cpp |
| 0x70CC10 | gData_0070CC10 (D2Launch/Src/CharSel.cpp) | D2Launch/Src/CharSel.cpp |
| 0x70CC50 | gData_0070CC50 (D2Launch/Src/CharSel.cpp) | D2Client/UI/automap.cpp |
| 0x70CC8C | gData_0070CC50 (D2Launch/Src/CharSel.cpp) | D2Client/UI/automap.cpp |
| 0x70CCD8 | gData_0070CCD8 (D2Multi/Src/ChatDlg.cpp) | D2Multi/Src/ChatDlg.cpp |
| 0x70CD18 | gtInterface (D2Multi/Src/ChatDlg.cpp) | D2Multi/Src/ChatDlg.cpp |
| 0x70EB94 | gData_0070EB94 (D2Multi/Unknown_00441320.cpp) | D2Launch/Src/CharSel.cpp |
| 0x70EBE0 | gData_0070EBE0 (D2Multi/Src/ComCallback.cpp) | D2Multi/Src/ComCallback.cpp |
| 0x70EC80 | gapfnMsgHandlers (D2Multi/Src/ComCallback.cpp) | D2Client/GAME/Game.cpp |
| 0x70ECC0 | gapfnMsgHandlers (D2Multi/Src/ComCallback.cpp) | D2Client/GAME/Game.cpp |
| 0x70EDD0 | gpfnConnectPacketHandlers (D2Client/CORE/WINMAIN.CPP) | D2Client/CORE/WINMAIN.CPP |
| 0x70EE10 | gtClientInterface (D2Client/CORE/WINMAIN.CPP) | D2Client/GAME/Game_0044E5A0.cpp |
| 0x70EE90 | gData_0070EE90 (D2Client/GAME/Game_0044E5A0.cpp) | D2Client/GAME/Game.cpp |
| 0x70EED0 | gData_0070EE90 (D2Client/GAME/Game_0044E5A0.cpp) | D2Client/GAME/Game.cpp |
| 0x70F728 | **borrowed** | D2Multi/Src/ComCallback.cpp |
| 0x70F764 | **borrowed** | D2Multi/Src/ComCallback.cpp |
| 0x70F7A4 | gData_0070F7A4 (D2Multi/Src/ComCallback.cpp) | D2Client/GAME/Game_0044D080.cpp |
| 0x70F818 | gData_0070F814 (D2Client/Unknown_00451E70.cpp) | D2Client/UI/ui.cpp |
| 0x7111D8 | gData_007111D8 (D2Launch/Src/CharSel.cpp) | D2Client/UI/automap.cpp |
| 0x711218 | gData_007111D8 (D2Launch/Src/CharSel.cpp) | D2Client/UI/automap.cpp |
| 0x7113EC | gData_007113EC (D2Client/UI/automap.cpp) | D2Client/UI/automap.cpp |
| 0x711430 | gData_00711430 (D2Client/UI/automap.cpp) | D2Client/UI/text.cpp |
| 0x711490 | gszTypeNameAllocRec (D2Client/Unknown_0045B5F0.cpp) | D2Client/UI/automap.cpp |
| 0x711D04 | gaPacketTable (D2Client/UI/automap.cpp) | D2Client/Unknown_00460420.cpp |
| 0x711DA0 | gaOkCancelHandlers (D2Client/Unknown_00460420.cpp) | D2Client/UNIT/Player.cpp |
| 0x711EF4 | gData_00711EF4 (D2Client/UNIT/Player.cpp) | D2Client/UNIT/CUnit.cpp |
| 0x711F54 | gData_00711F54 (D2Client/UNIT/CUnit.cpp) | D2Client/GAME/Select.cpp |
| 0x711FB0 | gaUnitHoverPriority (D2Client/GAME/Select.cpp) | D2Client/GAME/Select.cpp |
| 0x7121E0 | gData_007121E0 (Storm/Unknown_006C9A68.cpp) | D2Client/UNIT/CUnit.cpp |
| 0x712990 | gData_0071298C (D2Client/UI/CmdTbl.cpp) | D2Client/GAME/RosterPets.cpp |
| 0x712A28 | gpfnLevelEvents (D2Client/Unknown_0046B630.cpp) | D2Client/ENGINE/Gfx.cpp |
| 0x712A64 | gpfnLevelEvents (D2Client/Unknown_0046B630.cpp) | D2Client/ENGINE/Gfx.cpp |
| 0x712B10 | gData_00712B10 (D2Client/ENGINE/Gfx_0046DB90.cpp) | D2Client/Unknown_00472DA0.cpp |
| 0x712B50 | gData_00712B50 (D2Client/Unknown_00472DA0.cpp) | D2Client/DRAW/dLightMap.cpp |
| 0x712C10 | gData_00712B90 (D2Client/DRAW/dLightMap.cpp) | D2Client/GAME/View.cpp |
| 0x712C54 | gData_00712C54 (D2Client/GAME/View.cpp) | D2Client/UI/inv.cpp |
| 0x712C90 | gData_00712C54 (D2Client/GAME/View.cpp) | D2Client/UI/inv.cpp |
| 0x712DD0 | gData_00712CD0 (D2Client/UI/inv.cpp) | D2Client/GAME/Roster.cpp |
| 0x712E0C | gData_00712CD0 (D2Client/UI/inv.cpp) | D2Client/GAME/Roster.cpp |
| 0x712E48 | gData_00712CD0 (D2Client/UI/inv.cpp) | D2Client/GAME/Roster.cpp |
| 0x712E84 | gData_00712CD0 (D2Client/UI/inv.cpp) | D2Client/GAME/Roster.cpp |
| 0x712EC0 | gData_00712CD0 (D2Client/UI/inv.cpp) | D2Client/GAME/Roster.cpp |
| 0x712F08 | gData_00712F08 (D2Client/DRAW/dLightMap.cpp) | D2Client/UI/chat.cpp |
| 0x713008 | gData_00713008 (D2Client/UI/chat.cpp) | D2Client/Unknown_0047CC90.cpp |
| 0x721C58 | gData_00721C58 (D2Client/Unknown_0047CC90.cpp) | D2Client/WARDEN/WardenClient.cpp |
| 0x721CDC | **borrowed** | D2Client/UI/inv.cpp |
| 0x721D18 | **borrowed** | D2Client/UI/inv.cpp |
| 0x721D58 | **borrowed** | D2Client/UI/inv.cpp |
| 0x721DF8 | gaAuxLevelEntries (D2Client/UI/inv.cpp) | D2Client/UI/inv.cpp |
| 0x722298 | gData_00722298 (D2Client/UI/inv.cpp) | D2Client/UI/Hireables.cpp |
| 0x7222D4 | gData_00722298 (D2Client/UI/inv.cpp) | D2Client/UI/Hireables.cpp |
| 0x722318 | gData_00722314 (D2Client/UI/Hireables.cpp) | D2Client/UI/panel.cpp |
| 0x722414 | gData_00722414 (D2Client/UI/panel.cpp) | D2Client/Unknown_0049B030.cpp |
| 0x722470 | gData_00722470 (D2Client/Unknown_0049B030.cpp) | D2Client/WARDEN/WardenClient.cpp |
| 0x7225C0 | gaWaypointRowRects (D2Client/Unknown_0049BB40.cpp) | D2Client/Unknown_0049BB40.cpp |
| 0x723768 | gaMonStringSounds (D2Client/UI/text.cpp) | D2Client/UI/text.cpp |
| 0x724228 | gData_00724224 (D2Client/UI/QuestLog.cpp) | D2Client/Unknown_004A43E0.cpp |
| 0x724798 | gaKeyCaptureWheelHandlers (D2Client/Unknown_004A43E0.cpp) | D2Client/UI/text.cpp |
| 0x7247D8 | gaKeyCaptureWheelHandlers (D2Client/Unknown_004A43E0.cpp) | D2Client/UI/text.cpp |
| 0x724A80 | gData_00724A80 (D2Client/UI/text.cpp) | D2Client/Unknown_004A76C0.cpp |
| 0x724BB0 | gData_00724BAE (D2Client/Unknown_004A76C0.cpp) | D2Client/Unknown_004AA9C0.cpp |
| 0x724D3C | gaSkillTabX (D2Client/Unknown_00499500.cpp) | D2Client/Unknown_00499500.cpp |
| 0x7251E0 | gwUniqueModNameIds (D2Client/UNIT/Monster.cpp) | D2Client/UNIT/Monster.cpp |
| 0x7253A0 | gData_00725340 (D2Client/UNIT/Monster.cpp) | D2Client/UI/npcmenu.cpp |
| 0x7273A8 | gaStringMap (D2Client/UI/npcmenu.cpp) | D2Client/UI/dialog.cpp |
| 0x7274B0 | gaszDialogCels (D2Client/UI/text.cpp) | D2Client/Sound/SoundInst.cpp |
| 0x7274EC | gaszDialogCels (D2Client/UI/text.cpp) | D2Client/Sound/SoundInst.cpp |
| 0x727528 | gaszDialogCels (D2Client/UI/text.cpp) | D2Client/Sound/SoundInst.cpp |
| 0x72756C | gData_0072756C (D2Client/Sound/SoundInst.cpp) | D2Client/UI/editbox.cpp |
| 0x727608 | **borrowed** | D2Client/UNIT/Object.cpp |
| 0x727688 | **borrowed** | D2Client/UNIT/Object.cpp |
| 0x727708 | **borrowed** | D2Client/UNIT/Object.cpp |
| 0x72783C | gapfnObjectClientFn (D2Client/UNIT/Object.cpp) | D2Client/UNIT/Item.cpp |
| 0x7278C0 | **borrowed** | D2Client/UNIT/Item.cpp |
| 0x7279B0 | gaUseItemHandlers (D2Client/UI/useitem.cpp) | D2Client/UNIT/Item.cpp |
| 0x7279EC | gaUseItemHandlers (D2Client/UI/useitem.cpp) | D2Client/UNIT/Item.cpp |
| 0x727A50 | gData_00727A4C (D2Client/UNIT/Item.cpp) | D2Client/SKILLS/Skills.cpp |
| 0x727DBC | gData_00727DBC (D2Client/UNIT/Item.cpp) | D2Client/UNIT/UnitSnd.cpp |
| 0x727DF8 | gData_00727DBC (D2Client/UNIT/Item.cpp) | D2Client/UNIT/UnitSnd.cpp |
| 0x727E34 | gData_00727DBC (D2Client/UNIT/Item.cpp) | D2Client/UNIT/UnitSnd.cpp |
| 0x727E70 | gData_00727DBC (D2Client/UNIT/Item.cpp) | D2Client/UNIT/UnitSnd.cpp |
| 0x72A300 | gapLevelSpeeches (D2Client/UNIT/UnitSnd.cpp) | D2Client/UNIT/Missile.cpp |
| 0x72A650 | gpfnCltHitFuncs (D2Client/UNIT/Missile.cpp) | D2Client/UNIT/PlrSkills.cpp |
| 0x72A788 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A7C4 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A800 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A83C | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A878 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A8B4 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A8F0 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A92C | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A96C | gData_0072A96C (D2Client/GAME/Wall2.cpp) | D2Client/Unknown_004DEDB0.cpp |
| 0x72A9A8 | gData_0072A96C (D2Client/GAME/Wall2.cpp) | D2Client/Unknown_004DEDB0.cpp |
| 0x72ADA8 | gaLightOffsetsA (D2Client/Unknown_004DEDB0.cpp) | D2Client/Unknown_004DEDB0.cpp |
| 0x72ADE8 | gData_0072ADE8 (D2Client/Unknown_004DF6C0.cpp) | D2Client/Unknown_004DF6C0.cpp |
| 0x72CBE8 | gaStringSounds (D2Client/Unknown_004DF6C0.cpp) | D2Client/Unknown_004DF6C0.cpp |
| 0x72CC24 | gaStringSounds (D2Client/Unknown_004DF6C0.cpp) | D2Client/Unknown_004DF6C0.cpp |
| 0x72CC60 | gaStringSounds (D2Client/Unknown_004DF6C0.cpp) | D2Client/Unknown_004DF6C0.cpp |
| 0x72CC9C | gaStringSounds (D2Client/Unknown_004DF6C0.cpp) | D2Client/Unknown_004DF6C0.cpp |
| 0x72CCD8 | gaStringSounds (D2Client/Unknown_004DF6C0.cpp) | D2Client/Unknown_004DF6C0.cpp |
| 0x72CD14 | gaStringSounds (D2Client/Unknown_004DF6C0.cpp) | D2Client/Unknown_004DF6C0.cpp |
| 0x72CD50 | gaStringSounds (D2Client/Unknown_004DF6C0.cpp) | D2Client/Unknown_004DF6C0.cpp |
| 0x72CD90 | gaStringSounds (D2Client/Unknown_004DF6C0.cpp) | D2Client/Unknown_004DF6C0.cpp |
| 0x72D728 | gData_0072D724 (D2Client/UI/SkillDesc.cpp) | D2Client/UI/SkillDesc.cpp |
| 0x72D8D8 | gData_0072D8D8 (D2Client/UI/SkillDesc_004E1FF0.cpp) | D2Client/UI/SkillDesc.cpp |
| 0x72D914 | gData_0072D8D8 (D2Client/UI/SkillDesc_004E1FF0.cpp) | D2Client/UI/SkillDesc.cpp |
| 0x72D950 | gData_0072D8D8 (D2Client/UI/SkillDesc_004E1FF0.cpp) | D2Client/UI/SkillDesc.cpp |
| 0x72D994 | gData_0072D994 (D2Client/UI/SkillDesc.cpp) | D2Win/Unknown_004F5190.cpp |
| 0x72D9D0 | gData_0072D994 (D2Client/UI/SkillDesc.cpp) | D2Win/Unknown_004F5190.cpp |
| 0x72DA0C | gData_0072D994 (D2Client/UI/SkillDesc.cpp) | D2Win/Unknown_004F5190.cpp |
| 0x72DC00 | gData_0072DC00 (D2Win/Src/D2WinMain.cpp) | D2Win/Src/D2WinMain.cpp |
| 0x72DDD8 | gData_0072DDD8 (D2Win/Src/D2WinMain.cpp) | D2Win/Src/D2WinPalette.cpp |
| 0x72DE14 | gData_0072DE14 (D2Win/Src/D2WinPalette.cpp) | D2Win/Src/D2WinPalette.cpp |
| 0x72DE54 | gData_0072DE54 (D2Win/Src/D2WinTextBox.cpp) | D2Win/Src/D2WinTextBox.cpp |
| 0x72DE94 | gData_0072DE94 (D2Win/Src/D2WinTextBox.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72DED0 | gData_0072DE94 (D2Win/Src/D2WinTextBox.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72DF0C | gData_0072DE94 (D2Win/Src/D2WinTextBox.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72DF48 | gData_0072DE94 (D2Win/Src/D2WinTextBox.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72DF84 | gData_0072DE94 (D2Win/Src/D2WinTextBox.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72DFC0 | gData_0072DE94 (D2Win/Src/D2WinTextBox.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72E010 | gData_0072E010 (D2Win/Src/D2Comp.cpp) | D2Win/Src/D2Comp.cpp |
| 0x72EFD4 | gData_0072EFD4 (D2Win/Src/D2Comp.cpp) | D2Client/Unknown_004F4EC0.cpp |
| 0x72F010 | gData_0072EFD4 (D2Win/Src/D2Comp.cpp) | D2Client/Unknown_004F4EC0.cpp |
| 0x72F04C | gData_0072EFD4 (D2Win/Src/D2Comp.cpp) | D2Client/Unknown_004F4EC0.cpp |
| 0x72F088 | gData_0072EFD4 (D2Win/Src/D2Comp.cpp) | D2Client/Unknown_004F4EC0.cpp |
| 0x72F0C4 | gData_0072EFD4 (D2Win/Src/D2Comp.cpp) | D2Client/Unknown_004F4EC0.cpp |
| 0x72F100 | gData_0072EFD4 (D2Win/Src/D2Comp.cpp) | D2Client/Unknown_004F4EC0.cpp |
| 0x72F13C | gData_0072EFD4 (D2Win/Src/D2Comp.cpp) | D2Client/Unknown_004F4EC0.cpp |
| 0x72F7F4 | gData_0072F7F4 (D2DDraw/Src/ddCore.cpp) | D2Sound/Unknown_00513A20.cpp |
| 0x72F838 | gData_0072F834 (D2Sound/Unknown_00513A20.cpp) | D2Sound/Src/D2SoundSmp.cpp |
| 0x72F8FC | gData_0072F8FC (D2Sound/Src/D2SoundSmp.cpp) | D2Sound/Src/D2SoundSmp.cpp |
| 0x72F938 | gData_0072F8FC (D2Sound/Src/D2SoundSmp.cpp) | D2Sound/Src/D2SoundSmp.cpp |
| 0x72F974 | gData_0072F8FC (D2Sound/Src/D2SoundSmp.cpp) | D2Sound/Src/D2SoundSmp.cpp |
| 0x72F9B4 | gData_0072F9B4 (D2Sound/Src/D2SoundSmp.cpp) | D2Hell/Unknown_00516DE1.cpp |
| 0x72FA20 | gData_0072FA20 (D2Hell/Unknown_00517804.cpp) | D2BNClient/Unknown_00518C00.cpp |
| 0x72FA60 | gData_0072FA20 (D2Hell/Unknown_00517804.cpp) | D2BNClient/Unknown_00518C00.cpp |
| 0x730128 | gapfnPacketHandlers (D2BNClient/BnSend.cpp) | Bnclient/Unknown_00520DC0.cpp |
| 0x730198 | gData_00730194 (D2BNClient/grid.cpp) | D2Lang/StrTable/strtable.cpp |
| 0x730538 | gData_00730524 (D2Lang/StrTable/strtable.cpp) | D2Lang/Unknown_00526610.cpp |
| 0x730978 | gaCaseTable (D2Client/UNIT/Monster.cpp) | D2Lang/Unknown_00526100.cpp |
| 0x730A28 | gData_00730A28 (D2Lang/Unknown_00526100.cpp) | Bnclient/Unknown_00527BE0.cpp |
| 0x730A64 | gData_00730A28 (D2Lang/Unknown_00526100.cpp) | Bnclient/Unknown_00527BE0.cpp |
| 0x730AA0 | gData_00730A28 (D2Lang/Unknown_00526100.cpp) | Bnclient/Unknown_00527BE0.cpp |
| 0x730F84 | ganClientPacketSizes (D2Net/Unknown_0052B920.cpp) | D2Game/GAME/Game.cpp |
| 0x730FC0 | ganClientPacketSizes (D2Net/Unknown_0052B920.cpp) | D2Game/GAME/Game.cpp |
| 0x731090 | **borrowed** | D2Game/PLAYER/PlrSave.cpp |
| 0x7310D0 | gData_007310D0 (D2Game/Ai/AiTatics.cpp) | D2Game/UNIT/sunitproxy.cpp |
| 0x73110C | gData_007310D0 (D2Game/Ai/AiTatics.cpp) | D2Game/UNIT/sunitproxy.cpp |
| 0x731148 | gData_007310D0 (D2Game/Ai/AiTatics.cpp) | D2Game/UNIT/sunitproxy.cpp |
| 0x7312E0 | gNpcConfig (D2Game/UNIT/sunitproxy.cpp) | D2Game/UNIT/sunitproxy.cpp |
| 0x73131C | gNpcConfig (D2Game/UNIT/sunitproxy.cpp) | D2Game/UNIT/sunitproxy.cpp |
| 0x731358 | gNpcConfig (D2Game/UNIT/sunitproxy.cpp) | D2Game/UNIT/sunitproxy.cpp |
| 0x731394 | gData_00731388 (D2Game/UNIT/sunitproxy.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x7313D0 | gData_00731388 (D2Game/UNIT/sunitproxy.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x73140C | gData_00731388 (D2Game/UNIT/sunitproxy.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x731448 | gData_00731388 (D2Game/UNIT/sunitproxy.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x731484 | gData_00731388 (D2Game/UNIT/sunitproxy.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x7314D0 | gaszLanguageNames_007314D0 (D2Game/UNIT/SUnitInactive.cpp) | D2Game/Quests/QUESTS.CPP |
| 0x73192C | gData_0073192C (D2Game/Quests/QUESTS.CPP) | D2Game/PLAYER/PlrMsg.cpp |
| 0x731968 | gData_0073192C (D2Game/Quests/QUESTS.CPP) | D2Game/PLAYER/PlrMsg.cpp |
| 0x7319A8 | gData_0073192C (D2Game/Quests/QUESTS.CPP) | D2Game/PLAYER/PlrMsg.cpp |
| 0x731AF0 | gnBaseStatIdsToSend (D2Game/PLAYER/PlrMsg.cpp) | D2Game/Unknown_0054DAC0.cpp |
| 0x731B40 | gaWanderingRanges (D2Game/Unknown_0054DAC0.cpp) | D2Game/OBJECTS/Objects.cpp |
| 0x731ED4 | gData_00731ED4 (Storm/Unknown_006CAE80.cpp) | D2Game/ITEMS/Items.cpp |
| 0x731F10 | gData_00731ED4 (Storm/Unknown_006CAE80.cpp) | D2Game/ITEMS/Items.cpp |
| 0x731F74 | gData_00731F74 (D2Game/ITEMS/Items.cpp) | D2Game/ITEMS/ItemMode.cpp |
| 0x731FB0 | gData_00731F74 (D2Game/ITEMS/Items.cpp) | D2Game/ITEMS/ItemMode.cpp |
| 0x73200C | gData_0073200C (D2Game/ITEMS/ItemMode.cpp) | D2Game/SKILLS/Skills.cpp |
| 0x732048 | gData_0073200C (D2Game/ITEMS/ItemMode.cpp) | D2Game/SKILLS/Skills.cpp |
| 0x732084 | gData_0073200C (D2Game/ITEMS/ItemMode.cpp) | D2Game/SKILLS/Skills.cpp |
| 0x7320C0 | gData_0073200C (D2Game/ITEMS/ItemMode.cpp) | D2Game/SKILLS/Skills.cpp |
| 0x732100 | gData_0073200C (D2Game/ITEMS/ItemMode.cpp) | D2Game/SKILLS/Skills.cpp |
| 0x732678 | gpfnSkillEventCallbacks (D2Game/SKILLS/Skills.cpp) | D2Game/Unknown_00570420.cpp |
| 0x7326B8 | gData_007326B8 (D2Game/Unknown_00570420.cpp) | D2Game/PLAYER/PlrIntro.cpp |
| 0x7326F8 | gData_007326B8 (D2Game/Unknown_00570420.cpp) | D2Game/PLAYER/PlrIntro.cpp |
| 0x732850 | gaPlrIntroNpcIndexMap (D2Game/PLAYER/PlrIntro.cpp) | D2Game/UNIT/SUnitDmg.cpp |
| 0x73288C | gaPlrIntroNpcIndexMap (D2Game/PLAYER/PlrIntro.cpp) | D2Game/UNIT/SUnitDmg.cpp |
| 0x7328C8 | gaPlrIntroNpcIndexMap (D2Game/PLAYER/PlrIntro.cpp) | D2Game/UNIT/SUnitDmg.cpp |
| 0x732904 | gaPlrIntroNpcIndexMap (D2Game/PLAYER/PlrIntro.cpp) | D2Game/UNIT/SUnitDmg.cpp |
| 0x732940 | gaPlrIntroNpcIndexMap (D2Game/PLAYER/PlrIntro.cpp) | D2Game/UNIT/SUnitDmg.cpp |
| 0x732BD0 | gData_00732BCC (D2Game/UNIT/SUnitDmg.cpp) | D2Game/PLAYER/PlrModes.cpp |
| 0x732CB0 | gpfnModeChecks (D2Game/PLAYER/PlrModes.cpp) | D2Game/OBJECTS/ObjMode.cpp |
| 0x732FB0 | gData_00732FB0 (D2Game/OBJECTS/ObjMode.cpp) | D2Game/Quests/a5q2.cpp |
| 0x736160 | gData_00736144 (D2Game/Quests/a5q3.cpp) | D2Game/Quests/a1q6.cpp |
| 0x7361A0 | gData_00736144 (D2Game/Quests/a5q3.cpp) | D2Game/Quests/a1q6.cpp |
| 0x738C10 | gaAct1Q7NpcMessages (D2Game/Unknown_00596C40.cpp) | D2Game/INVENTORY/InvMode.cpp |
| 0x738CC8 | gData_00738CC8 (D2Game/INVENTORY/InvMode.cpp) | D2Game/Quests/a2q4.cpp |
| 0x738D08 | gData_00738CC8 (D2Game/INVENTORY/InvMode.cpp) | D2Game/Quests/a2q4.cpp |
| 0x73BEE0 | gpAct2Q8NpcMessages (D2Game/Quests/a2q8.cpp) | D2Game/MONSTER/MonsterUnique.cpp |
| 0x73BF20 | gpAct2Q8NpcMessages (D2Game/Quests/a2q8.cpp) | D2Game/MONSTER/MonsterUnique.cpp |
| 0x73C4C0 | gpfnSrvUModCallbacks (D2Game/MONSTER/MonsterUnique.cpp) | D2Game/MONSTER/MonsterMode.cpp |
| 0x73C4FC | gpfnSrvUModCallbacks (D2Game/MONSTER/MonsterUnique.cpp) | D2Game/MONSTER/MonsterMode.cpp |
| 0x73C538 | gpfnSrvUModCallbacks (D2Game/MONSTER/MonsterUnique.cpp) | D2Game/MONSTER/MonsterMode.cpp |
| 0x73C578 | gpfnSrvUModCallbacks (D2Game/MONSTER/MonsterUnique.cpp) | D2Game/MONSTER/MonsterMode.cpp |
| 0x73C6E0 | gbModeReset (D2Game/MONSTER/MonsterMode.cpp) | D2Game/MISSILES/MissMode.cpp |
| 0x73C9DC | gpfnMissileSrvDmgFunctions (D2Game/MISSILES/MissMode_005ADF10.cpp) | D2Game/Ai/AiThink.cpp |
| 0x73D478 | gaszLanguageNames_0073D478 (D2Game/Ai/AiThink.cpp) | D2Game/Unknown_005B24E0.cpp |
| 0x73D4B4 | gaszLanguageNames_0073D4B4 (D2Game/Ai/AiThink.cpp) | D2Game/Unknown_005B24E0.cpp |
| 0x73D530 | gaszLanguageNames_0073D530 (D2Game/Unknown_005B24E0.cpp) | D2Game/Quests/a4q1.cpp |
| 0x73E810 | gpAct4Q4NpcMessages (D2Game/Quests/a4q3.cpp) | D2Game/Quests/a4q3.cpp |
| 0x741578 | gaszLanguageNames_00741578 (D2Game/Quests/a3q7.cpp) | D2Game/MONSTER/MonsterChoose.cpp |
| 0x741750 | **borrowed** | D2Game/SKILLS/SkillItem.cpp |
| 0x741888 | gaPSpellTable (D2Game/SKILLS/SkillItem.cpp) | D2Game/SKILLS/SkillNec.cpp |
| 0x7418C4 | gaPSpellTable (D2Game/SKILLS/SkillItem.cpp) | D2Game/SKILLS/SkillNec.cpp |
| 0x741900 | gaPSpellTable (D2Game/SKILLS/SkillItem.cpp) | D2Game/SKILLS/SkillNec.cpp |
| 0x7419A4 | gaNecroSkeletonComponents (D2Game/SKILLS/SkillNec.cpp) | D2Game/SKILLS/SkillAss.cpp |
| 0x7419E0 | gaNecroSkeletonComponents (D2Game/SKILLS/SkillNec.cpp) | D2Game/SKILLS/SkillAss.cpp |
| 0x741A1C | gaNecroSkeletonComponents (D2Game/SKILLS/SkillNec.cpp) | D2Game/SKILLS/SkillAss.cpp |
| 0x741A58 | gaNecroSkeletonComponents (D2Game/SKILLS/SkillNec.cpp) | D2Game/SKILLS/SkillAss.cpp |
| 0x741A94 | gaNecroSkeletonComponents (D2Game/SKILLS/SkillNec.cpp) | D2Game/SKILLS/SkillAss.cpp |
| 0x741AD0 | gaNecroSkeletonComponents (D2Game/SKILLS/SkillNec.cpp) | D2Game/SKILLS/SkillAss.cpp |
| 0x741B18 | gData_00741B14 (D2Game/SKILLS/SkillAss.cpp) | D2Game/Unknown_005D8100.cpp |
| 0x741C0C | gaPotionTable (D2Game/Unknown_005D8100.cpp) | D2Game/Ai/AiThink4.cpp |
| 0x741C48 | gaPotionTable (D2Game/Unknown_005D8100.cpp) | D2Game/Ai/AiThink4.cpp |
| 0x741C84 | gaPotionTable (D2Game/Unknown_005D8100.cpp) | D2Game/Ai/AiThink4.cpp |
| 0x741CC0 | gaPotionTable (D2Game/Unknown_005D8100.cpp) | D2Game/Ai/AiThink4.cpp |
| 0x741CFC | gaPotionTable (D2Game/Unknown_005D8100.cpp) | D2Game/Ai/AiThink4.cpp |
| 0x741D38 | gaPotionTable (D2Game/Unknown_005D8100.cpp) | D2Game/Ai/AiThink4.cpp |
| 0x741D90 | gData_00741D90 (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x741DCC | gData_00741D90 (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x741E08 | gData_00741D90 (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x741E44 | gData_00741D90 (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x741E80 | gData_00741D90 (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x741EBC | gData_00741D90 (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x7435C8 | gData_007435C8 (D2CMP/SRC/Tilecmp.cpp) | D2Common/Chat/Ignorelist.cpp |
| 0x743780 | gData_00743780 (D2Common/Chat/Ignorelist.cpp) | D2Common/Chat/Ignorelist.cpp |
| 0x7437C0 | gData_007437C0 (D2Common/Chat/Ignorelist.cpp) | D2Common/Chat/Ignorelist.cpp |
| 0x7442C8 | gData_007442C8 (D2Common/Chat/Ignorelist.cpp) | D2Client/UI/SkillDesc_004E1FF0.cpp |
| 0x74430C | gData_0074430C (D2Common/DATATBLS/DataTbls.cpp) | D2Common/Unknown_006115F0.cpp |
| 0x744348 | gData_00744348 (D2Common/DRLG/DrlgActivate.cpp) | D2Common/DRLG/DrlgActivate.cpp |
| 0x7443A8 | gData_00744398 (D2Common/DRLG/DrlgActivate.cpp) | D2Common/ENVIRONMENT/Env.cpp |
| 0x7444C8 | gData_007444C8 (D2Common/DATATBLS/LvlTbls.cpp) | D2Common/DATATBLS/LvlTbls.cpp |
| 0x744508 | gData_00744508 (D2Common/UNITS/Units.cpp) | D2Common/UNITS/Units.cpp |
| 0x744588 | gData_00744588 (D2Common/UNITS/Units.cpp) | D2Common/Stats/StatsEx.cpp |
| 0x7445C4 | gData_00744588 (D2Common/UNITS/Units.cpp) | D2Common/Stats/StatsEx.cpp |
| 0x744600 | gData_00744588 (D2Common/UNITS/Units.cpp) | D2Common/Stats/StatsEx.cpp |
| 0x7446E8 | gData_007446E8 (D2Common/ITEMS/Items.cpp) | D2Common/INVENTORY/Inventory.cpp |
| 0x744724 | gData_007446E8 (D2Common/ITEMS/Items.cpp) | D2Common/INVENTORY/Inventory.cpp |
| 0x744760 | gData_00744760 (D2Common/INVENTORY/Inventory.cpp) | D2Common/INVENTORY/Inventory.cpp |
| 0x745584 | **borrowed** | D2Game/ITEMS/ItemMode.cpp |
| 0x745648 | gabDirection8To64 (D2Game/ITEMS/ItemMode.cpp) | D2Game/ITEMS/ItemMode.cpp |
| 0x745684 | gabDirection8To64 (D2Game/ITEMS/ItemMode.cpp) | D2Game/ITEMS/ItemMode.cpp |
| 0x7456C0 | gabDirection8To64 (D2Game/ITEMS/ItemMode.cpp) | D2Game/ITEMS/ItemMode.cpp |
| 0x7456FC | gabDirection8To64 (D2Game/ITEMS/ItemMode.cpp) | D2Game/ITEMS/ItemMode.cpp |
| 0x745738 | gabDirection8To64 (D2Game/ITEMS/ItemMode.cpp) | D2Game/ITEMS/ItemMode.cpp |
| 0x7457B0 | gData_007457B0 (D2Common/SKILLS/Skills.cpp) | D2Common/Unknown_0064A2B0.cpp |
| 0x7457EC | gData_007457B0 (D2Common/SKILLS/Skills.cpp) | D2Common/Unknown_0064A2B0.cpp |
| 0x74584C | gData_0074584C (D2Common/Unknown_0064A2B0.cpp) | D2Common/COMPOSIT/Composit.cpp |
| 0x745888 | gData_0074584C (D2Common/Unknown_0064A2B0.cpp) | D2Common/COMPOSIT/Composit.cpp |
| 0x7458C4 | gData_007458C4 (D2Common/COMPOSIT/Composit.cpp) | D2Common/COMPOSIT/Composit.cpp |
| 0x745920 | gData_00745920 (D2Common/COMPOSIT/Composit.cpp) | D2Common/DATATBLS/MonsterTbls.cpp |
| 0x74595C | gData_00745920 (D2Common/COMPOSIT/Composit.cpp) | D2Common/DATATBLS/MonsterTbls.cpp |
| 0x745998 | gData_00745920 (D2Common/COMPOSIT/Composit.cpp) | D2Common/DATATBLS/MonsterTbls.cpp |
| 0x7459D4 | gData_007459D4 (D2Common/DATATBLS/MonsterTbls.cpp) | D2Common/DATATBLS/MonsterTbls.cpp |
| 0x745A28 | gData_00745A28 (D2Common/DATATBLS/MonsterTbls.cpp) | D2Common/ITEMS/ItemMods.cpp |
| 0x745A64 | gData_00745A28 (D2Common/DATATBLS/MonsterTbls.cpp) | D2Common/ITEMS/ItemMods.cpp |
| 0x745AA0 | gData_00745A28 (D2Common/DATATBLS/MonsterTbls.cpp) | D2Common/ITEMS/ItemMods.cpp |
| 0x745ADC | gData_00745A28 (D2Common/DATATBLS/MonsterTbls.cpp) | D2Common/ITEMS/ItemMods.cpp |
| 0x745B18 | gData_00745B18 (D2Common/ITEMS/ItemMods.cpp) | D2Common/ITEMS/ItemMods.cpp |
| 0x7463A8 | gData_007463A8 (D2Common/ITEMS/ItemMods.cpp) | D2Common/Waypoint/Waypoint.cpp |
| 0x7463E8 | gData_007463E8 (D2Common/Waypoint/Waypoint.cpp) | D2Common/Waypoint/Waypoint.cpp |
| 0x7465E8 | gaWaypointBits (D2Common/Waypoint/Waypoint.cpp) | D2Common/DATATBLS/Sequence.cpp |
| 0x746624 | gaWaypointBits (D2Common/Waypoint/Waypoint.cpp) | D2Common/DATATBLS/Sequence.cpp |
| 0x746660 | gaWaypointBits (D2Common/Waypoint/Waypoint.cpp) | D2Common/DATATBLS/Sequence.cpp |
| 0x7466A0 | gaWaypointBits (D2Common/Waypoint/Waypoint.cpp) | D2Common/DATATBLS/Sequence.cpp |
| 0x748488 | gData_00748488 (D2Common/DATATBLS/Sequence.cpp) | D2Common/Unknown_006634F0.cpp |
| 0x74880C | gaHirelingRollLevel (D2Common/Unknown_006634F0.cpp) | D2Common/Unknown_006634F0.cpp |
| 0x748848 | gaHirelingRollLevel (D2Common/Unknown_006634F0.cpp) | D2Common/Unknown_006634F0.cpp |
| 0x748884 | gaHirelingRollLevel (D2Common/Unknown_006634F0.cpp) | D2Common/Unknown_006634F0.cpp |
| 0x7488C0 | gaHirelingRollLevel (D2Common/Unknown_006634F0.cpp) | D2Common/Unknown_006634F0.cpp |
| 0x748A58 | gData_00748A58 (D2Common/Unknown_0063E6B0.cpp) | D2Common/DRLG/Preset.cpp |
| 0x748A98 | gData_00748A58 (D2Common/Unknown_0063E6B0.cpp) | D2Common/DRLG/Preset.cpp |
| 0x749690 | gData_00749690 (D2Common/Unknown_00665810.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x7496CC | gData_007496CC (D2Common/Unknown_00665810.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749708 | gData_00749708 (D2Common/Unknown_00665810.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749744 | gData_00749744 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x7497C8 | gData_007497C8 (D2Common/DATATBLS/AnimTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749804 | gData_00749804 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749840 | gData_00749840 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x74987C | gData_0074987C (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x7498B8 | gData_007498B8 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x7498F4 | gData_007498F4 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749930 | gData_00749930 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x74996C | gData_0074996C (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x7499A8 | gData_007499A8 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x7499E4 | gData_007499E4 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749A20 | gData_00749A20 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749A5C | gData_00749A5C (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749A98 | gData_00749A98 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749AD4 | gData_00749AD4 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749B34 | gData_00749B34 (D2Common/DATATBLS/FieldTbls.cpp) | D2Client/Unknown_004F4EC0.cpp |
| 0x749B70 | gData_00749B70 (D2Common/DRLG/DrlgGrid.cpp) | D2Client/Unknown_004F4EC0.cpp |
| 0x749BC4 | gData_00749BC4 (D2Common/DRLG/DrlgVer.cpp) | D2Client/Unknown_004F4EC0.cpp |
| 0x749C00 | **borrowed** | D2Client/Unknown_004F4EC0.cpp |
| 0x749C3C | **borrowed** | D2Client/Unknown_004F4EC0.cpp |
| 0x749C78 | **borrowed** | D2Client/Unknown_004F4EC0.cpp |
| 0x749CB4 | **borrowed** | D2Client/Unknown_004F4EC0.cpp |
| 0x749CF0 | **borrowed** | D2Client/Unknown_004F4EC0.cpp |
| 0x749D2C | **borrowed** | D2Client/Unknown_004F4EC0.cpp |
| 0x749D68 | **borrowed** | D2Client/Unknown_004F4EC0.cpp |
| 0x749DA4 | **borrowed** | D2Client/Unknown_004F4EC0.cpp |
