# Language-table copies: an object map

The 15-entry language-name table (D2LanguageNames.h; strings 0x6CC77C-0x6CC81C) is a header static, so each object file that includes the header has exactly one copy in .data, at the start of that object's initialised data (the header is included before the file's own definitions; lanes 4, 5 and 6 found the same) (see COORDINATOR.md, Decisions).
This map lists all 308 copies in Game.exe .data on main #359 (round j115): which planned definition holds each one, and the planned data just after it, which is the object the copy starts.

- **Copies built (planned record, or the header copy placed by its marker or by its object):** 307. **Borrowed (not defined yet):** 1.
- **Planned files holding more than one copy:** 14. Each one spans that many original objects and can be split at its copies.
- **Runs of back-to-back copies (0x3C apart):** 49 runs with 2 or more copies. A run of N copies is N objects in link order with no initialised data of their own besides the table.

## Planned files holding several copies

| File | Lane | Copies | Copy addresses |
|---|---|---:|---|
| D2Client/Unknown_004DF6C0.cpp | lane1 | 10 | 0x72ADA8, 0x72ADE8, 0x72CBE8, 0x72CC24, 0x72CC60, 0x72CC9C … |
| D2Client/UNIT/PlrSkills.cpp | lane1 | 9 | 0x72A650, 0x72A788, 0x72A7C4, 0x72A800, 0x72A83C, 0x72A878 … |
| D2Game/Ai/AiThink4.cpp | lane5 | 6 | 0x741D90, 0x741DCC, 0x741E08, 0x741E44, 0x741E80, 0x741EBC |
| D2Lang/Unknown_00526100.cpp | lane6 | 4 | 0x730978, 0x730A28, 0x730A64, 0x730AA0 |
| D2Client/UI/SkillDesc_004E1FF0.cpp | lane1 | 3 | 0x72D8D8, 0x72D914, 0x72D950 |
| D2Game/MONSTER/MonsterUnique.cpp | lane5 | 3 | 0x73C4C0, 0x73C4FC, 0x73C538 |
| D2Launch/Src/CharSel.cpp | lane6 | 2 | 0x70CBC4, 0x7111D8 |
| D2Multi/Src/ChatDlg.cpp | lane6 | 2 | 0x70CD18, 0x70EB94 |
| D2Multi/Src/ComCallback.cpp | lane6 | 2 | 0x70EBE0, 0x70F7A4 |
| D2Client/UI/inv.cpp | lane4 | 2 | 0x721DF8, 0x722298 |
| D2Hell/Unknown_00517804.cpp | lane9 | 2 | 0x72FA20, 0x72FA60 |
| D2Net/Unknown_0052B920.cpp | lane6 | 2 | 0x730F84, 0x730FC0 |
| D2Game/Ai/AiThink.cpp | lane5 | 2 | 0x73C9DC, 0x73D478 |
| D2Common/DATATBLS/DataTbls.cpp | lane8 | 2 | 0x7442C8, 0x74430C |

## Borrowed copies

Not defined by any file yet. It belongs to the object whose data follows it, normally the file of the next planned data (check that nothing else lies between).

| Copy | Lane | Data before (file) | Data after (file), gap |
|---|---|---|---|
| 0x745584 | lane8 | gaComponentItemTypeMap (D2Common/INVENTORY/Inventory.cpp) | gabDirection64To16 (D2Common/INVENTORY/Inventory.cpp), +0x0 |

## Runs of back-to-back copies

| First copy | Copies | Data after the run (file) | Planned as |
|---|---:|---|---|
| 0x70CB88 | 2 | D2Launch/Src/CharSel.cpp | D2Launch/Src/CharSel.cpp, D2Launch/Unknown_004370B0.cpp |
| 0x70CC50 | 2 | D2Client/UI/automap.cpp | D2Launch/Unknown_0043C4F0.cpp, D2Multi/Unknown_0043C8A0.cpp |
| 0x70F728 | 2 | D2Client/GAME/Record.cpp | D2Client/GAME/Record.cpp, D2Client/Unknown_00451290.cpp |
| 0x712A28 | 2 | D2Client/ENGINE/Gfx.cpp | ?, D2Client/Unknown_0046ACE0.cpp |
| 0x712C54 | 2 | D2Client/Unknown_00477620.cpp | ?, D2Client/GAME/PalShift.cpp |
| 0x712DD0 | 5 | D2Client/Unknown_0047A980.cpp | D2Client/CORE/ARCHIVE.CPP, D2Client/GAME/Msg.cpp, D2Client/GAME/Roster.cpp, D2Client/GAME/RosterPets.cpp, D2Client/Unknown_0047A980.cpp |
| 0x721CDC | 2 | D2Client/Unknown_00482C70.cpp | D2Client/Sound/SoundHdr.cpp, D2Client/UNIT/UnitMode.cpp |
| 0x722298 | 2 | D2Client/UI/Hireables.cpp | ?, D2Client/UI/inv.cpp |
| 0x7274B0 | 3 | D2Client/Sound/SoundInst.cpp | ?, D2Client/Unknown_004B8720.cpp, D2Client/Unknown_004B9200.cpp |
| 0x7279B0 | 2 | D2Client/UNIT/Item.cpp | D2Client/UI/showitems.cpp, D2Client/UNIT/Item.cpp |
| 0x727DBC | 4 | D2Client/UNIT/UnitSnd.cpp | D2Client/SKILLS/SkillsBar.cpp, D2Client/SKILLS/SkillsPal.cpp, D2Client/Unknown_004C9420.cpp, D2Client/Unknown_004C9D50.cpp |
| 0x72A788 | 8 | D2Client/GAME/Wall2.cpp | D2Client/UNIT/PlrSkills.cpp |
| 0x72A96C | 2 | D2Client/Unknown_004DEDB0.cpp | D2Client/GAME/Wall2.cpp, D2Client/Unknown_004DEDB0.cpp |
| 0x72CBE8 | 7 | D2Client/Unknown_004DF6C0.cpp | D2Client/Unknown_004DF6C0.cpp |
| 0x72D8D8 | 3 | D2Client/UI/SkillDesc.cpp | D2Client/UI/SkillDesc_004E1FF0.cpp |
| 0x72D994 | 3 | D2Gfx/SRC/Window.cpp | D2Client/SKILLS/SkillsAma.cpp, D2Client/SKILLS/SkillsNec.cpp, D2Gfx/SRC/Window.cpp |
| 0x72DDD8 | 2 | D2Win/Src/D2WinPalette.cpp | D2Win/Src/D2WinArchive.cpp, D2Win/Src/D2WinPalette.cpp |
| 0x72DE94 | 6 | D2Win/Src/D2WinFont.cpp | D2Win/D2WinAnimImage.cpp, D2Win/Src/D2WinButton.cpp, D2Win/Src/D2WinEditBox.cpp, D2Win/Src/D2WinImage.cpp, D2Win/Src/D2WinTimer.cpp, D2Win/Unknown_004FDA80.cpp |
| 0x72EFD4 | 7 | D2Glide/Src/glCore.cpp | D2Glide/Unknown_00508970.cpp, D2Win/Src/D2WinAccountList.cpp, D2Win/Src/D2WinList.cpp, D2Win/Src/D2WinPopup.cpp, D2Win/Src/D2WinProgressBar.cpp, D2Win/Src/D2WinScrollbar.cpp, D2Win/Src/D2WinSmack.cpp |
| 0x72F8FC | 3 | D2Sound/Src/D2SoundSmp.cpp | D2Sound/Src/D2SoundFast.cpp, D2Sound/Src/D2SoundSmp.cpp, D2Sound/Unknown_00514B60.cpp |
| 0x730A28 | 3 | Bnclient/Unknown_00527BE0.cpp | D2Lang/Unknown_00526100.cpp |
| 0x730F84 | 2 | D2Game/GAME/Game.cpp | D2Net/Unknown_0052B920.cpp |
| 0x7310D0 | 3 | D2Game/UNIT/sunitproxy.cpp | ?, D2Game/DEBUG/Debug.cpp, D2Game/PLAYER/Player.cpp |
| 0x7312E0 | 8 | D2Game/UNIT/SUnitInactive.cpp | ?, D2Game/GAME/Arena.cpp, D2Game/GAME/CCmd.cpp, D2Game/GAME/Clients.cpp, D2Game/GAME/Event.cpp, D2Game/GAME/Level.cpp, D2Game/GAME/SCmd.cpp, D2Game/UNIT/Party.cpp |
| 0x73192C | 2 | D2Game/PLAYER/PlrMsg.cpp | D2Game/MONSTER/MonsterRegion.cpp, D2Game/OBJECTS/objrgn.cpp |
| 0x731ED4 | 2 | D2Game/ITEMS/Items.cpp | ?, D2Game/UNIT/SUnit.cpp |
| 0x731F74 | 2 | D2Game/ITEMS/ItemMode.cpp | ?, D2Game/UNIT/PlayerList.cpp |
| 0x73200C | 4 | D2Game/SKILLS/Skills.cpp | D2Game/GAME/Task.cpp, D2Game/PLAYER/PlrSave2.cpp, D2Game/PLAYER/PlrTrade.cpp, D2Game/Unknown_0056B180.cpp |
| 0x732850 | 5 | D2Game/UNIT/SUnitDmg.cpp | D2Game/MONSTER/Monster.cpp, D2Game/MONSTER/MonsterAI.cpp, D2Game/PLAYER/PlayerPets.cpp, D2Game/UNIT/SUNITNPC.CPP, D2Game/UNIT/SUnitDmg.cpp |
| 0x73C4C0 | 3 | D2Game/MONSTER/MonsterMode.cpp | D2Game/MONSTER/MonsterUnique.cpp |
| 0x73D478 | 2 | D2Game/Unknown_005B24E0.cpp | ?, D2Game/Ai/AiThink.cpp |
| 0x741888 | 3 | D2Game/SKILLS/SkillNec.cpp | D2Game/SKILLS/SkillNec.cpp, D2Game/UNIT/SUnitEvent.cpp, D2Game/Unknown_005C0D00.cpp |
| 0x7419A4 | 6 | D2Game/SKILLS/SkillAss.cpp | ?, D2Game/SKILLS/SkilPal.cpp, D2Game/SKILLS/SkillDruid.cpp, D2Game/SKILLS/SkillMonst.cpp, D2Game/SKILLS/SkillSor.cpp, D2Game/Unknown_005D1080.cpp |
| 0x741C0C | 6 | D2Game/Ai/AiThink4.cpp | ?, D2Game/Ai/AiTatics.cpp, D2Game/Ai/AiUtil.cpp, D2Game/OBJECTS/OBJEVAL.CPP, D2Game/Quests/QuestsFX.cpp, D2Game/SKILLS/SkillAma.cpp |
| 0x741D90 | 6 | D2CMP/SRC/SpriteCache.cpp | D2Game/Ai/AiThink4.cpp |
| 0x74430C | 2 | D2Common/DRLG/DrlgActivate.cpp | D2Common/DATATBLS/DataTbls.cpp, D2Common/DRLG/DrlgActivate.cpp |
| 0x744588 | 3 | D2Common/Stats/StatsEx.cpp | D2Common/Logging/Logging.cpp, D2Common/Stats/StatsEx.cpp, D2Common/Unknown_00624740.cpp |
| 0x7446E8 | 3 | D2Common/INVENTORY/Inventory.cpp | D2Common/DATATBLS/ItemTbls.cpp, D2Common/INVENTORY/Inventory.cpp, D2Common/ITEMS/Items.cpp |
| 0x745648 | 5 | D2Common/SKILLS/Skills.cpp | D2Common/DRLG/Drlg.cpp, D2Common/Monsters/MONSTERS.CPP, D2Common/SKILLS/Skills.cpp, D2Common/Unknown_0063F690.cpp, D2Common/Unknown_00640F20.cpp |
| 0x7457B0 | 2 | D2Common/UNITS/Missile.cpp | D2Common/PATH/Path.cpp, D2Common/UNITS/Missile.cpp |
| 0x74584C | 3 | D2Common/COMPOSIT/Composit.cpp | D2Common/COLLISN/Collisn.cpp, D2Common/COMPOSIT/Composit.cpp, D2Common/UNITS/UnitRoom.cpp |
| 0x745920 | 4 | D2Common/DATATBLS/MonsterTbls.cpp | D2Common/DATATBLS/MonsterTbls.cpp, D2Common/Unknown_0064FAA0.cpp, D2Common/Unknown_0064FAD0.cpp, D2Common/Unknown_00650D70.cpp |
| 0x745A28 | 5 | D2Common/ITEMS/ItemMods.cpp | D2Common/DATATBLS/InvTbls.cpp, D2Common/DATATBLS/TokTbls.cpp, D2Common/ITEMS/ItemMods.cpp, D2Common/QuestRecord/QuestRecord.cpp, D2Common/UNITS/UnitFinds.cpp |
| 0x7465E8 | 3 | D2Common/DATATBLS/MissileTbls.cpp | D2Common/Chat/Chat.cpp, D2Common/DATATBLS/MissileTbls.cpp, D2Common/Text/Text.cpp |
| 0x74880C | 4 | D2Common/Unknown_006647C0.cpp | D2Common/DATATBLS/OverlayTbls.cpp, D2Common/UNITS/MisStream.cpp, D2Common/Unknown_00664530.cpp, D2Common/Unknown_006647C0.cpp |
| 0x749690 | 4 | D2Common/DATATBLS/FieldTbls.cpp | D2Common/DATATBLS/FieldTbls.cpp, D2Common/DATATBLS/HoradricCube.cpp, D2Common/Unknown_00668510.cpp, D2Common/Unknown_0066A1A0.cpp |
| 0x7497C8 | 14 | D2Common/Unknown_0067ADC0.cpp | D2Common/DATATBLS/AnimTbls.cpp, D2Common/DRLG/DrlgAnim.cpp, D2Common/DRLG/DrlgLogic.cpp, D2Common/DRLG/DrlgRoom.cpp, D2Common/DRLG/Maze.cpp, D2Common/DRLG/OutPlace.cpp, D2Common/DRLG/Outdoors.cpp, D2Common/DRLG/RoomTile.cpp, D2Common/PATH/PathUtil.cpp, D2Common/Unknown_0066AB70.cpp, D2Common/Unknown_00674040.cpp, D2Common/Unknown_00679380.cpp, D2Common/Unknown_0067A550.cpp, D2Common/Unknown_0067ADC0.cpp |
| 0x749B34 | 2 | D2Direct3D/Src/d3dCore.cpp | D2Common/DRLG/DrlgGrid.cpp, D2Common/Unknown_0067B9C0.cpp |
| 0x749BC4 | 9 | D2Direct3D/Src/d3dCore.cpp | D2Common/DRLG/DrlgVer.cpp, D2Common/DRLG/OutDesr.cpp, D2Common/DRLG/OutJung.cpp, D2Common/DRLG/OutRoom.cpp, D2Common/DRLG/OutSiege.cpp, D2Common/DRLG/OutWild.cpp, D2Common/Unknown_006808F0.cpp, D2Common/Unknown_00681000.cpp, D2Common/Unknown_00681490.cpp |

## Every copy, in address order

| Copy | Planned as | Starts the data of (next planned file) |
|---|---|---|
| 0x705000 | gaszLanguageNames (header, placed by its object) (?) | Storm/Unknown_00404F40.cpp |
| 0x706518 | gData_00706518 (D2Launch/Unknown_004059D0.cpp) | D2Launch/Unknown_004059D0.cpp |
| 0x706584 | gData_00706584 (D2Launch/Main.cpp) | D2Launch/Main.cpp |
| 0x706618 | gaszLanguageNames (Fog/Src/ErrorManager.cpp) | Fog/Src/ErrorManager.cpp |
| 0x708930 | gaszLanguageNames (header, placed by its object) (?) | D2Launch/Unknown_0042E590.cpp |
| 0x708970 | gData_00708970 (D2Launch/Src/MainMenus.cpp) | D2Launch/Src/MainMenus.cpp |
| 0x70CB88 | gData_0070CB88 (D2Launch/Unknown_004370B0.cpp) | D2Launch/Src/CharSel.cpp |
| 0x70CBC4 | gData_0070CBC4 (D2Launch/Src/CharSel.cpp) | D2Launch/Src/CharSel.cpp |
| 0x70CC10 | gData_0070CC10 (D2Launch/Unknown_0043B7A0.cpp) | D2Launch/Unknown_0043B7A0.cpp |
| 0x70CC50 | gData_0070CC50 (D2Launch/Unknown_0043C4F0.cpp) | D2Client/UI/automap.cpp |
| 0x70CC8C | gData_0070CC8C (D2Multi/Unknown_0043C8A0.cpp) | D2Client/UI/automap.cpp |
| 0x70CCD8 | gData_0070CCD8 (D2Multi/Unknown_0043CBE0.cpp) | D2Multi/Unknown_0043CBE0.cpp |
| 0x70CD18 | gData_0070CD18 (D2Multi/Src/ChatDlg.cpp) | D2Multi/Src/ChatDlg.cpp |
| 0x70EB94 | gData_0070EB94 (D2Multi/Src/ChatDlg.cpp) | D2Launch/Src/CharSel.cpp |
| 0x70EBE0 | gData_0070EBE0 (D2Multi/Src/ComCallback.cpp) | D2Multi/Src/ComCallback.cpp |
| 0x70EC80 | gData_0070EC80 (D2MCPClient/Src/McpConnect.cpp) | D2MCPClient/Unknown_0044A170.cpp |
| 0x70ECC0 | gData_0070ECC0 (D2MCPClient/Unknown_0044A170.cpp) | D2MCPClient/Unknown_0044A170.cpp |
| 0x70EDD0 | gaszLanguageNames (header, placed by its object) (?) | D2Client/Unknown_0044B400.cpp |
| 0x70EE10 | gData_0070EE10 (D2Client/CORE/WINMAIN.CPP) | D2Client/CORE/WINMAIN.CPP |
| 0x70EE90 | gData_0070EE90 (D2Client/Unknown_0044BA20.cpp) | D2Client/GAME/Game.cpp |
| 0x70EED0 | gData_0070EED0 (D2Client/GAME/Game.cpp) | D2Client/GAME/Game.cpp |
| 0x70F728 | gData_0070F728 (D2Client/Unknown_00451290.cpp) | D2Client/GAME/Record.cpp |
| 0x70F764 | gData_0070F764 (D2Client/GAME/Record.cpp) | D2Client/GAME/Record.cpp |
| 0x70F7A4 | gData_0070F7A4 (D2Multi/Src/ComCallback.cpp) | D2Client/GAME/Game_0044D080.cpp |
| 0x70F818 | gData_0070F818 (D2Client/UI/ui.cpp) | D2Client/UI/ui.cpp |
| 0x7111D8 | gData_007111D8 (D2Launch/Src/CharSel.cpp) | D2Client/UI/automap.cpp |
| 0x711218 | gData_00711218 (D2Client/UI/automap.cpp) | D2Client/UI/automap.cpp |
| 0x7113EC | gData_007113EC (D2Client/Unknown_0045AE90.cpp) | D2Client/Unknown_0045AE90.cpp |
| 0x711430 | gaszLanguageNames (header, placed by its object) (?) | D2Client/Unknown_0045B5F0.cpp |
| 0x711490 | gData_00711490 (D2Client/GAME/SCmd.cpp) | D2Client/GAME/SCmd.cpp |
| 0x711D04 | gData_00711D04 (D2Client/Unknown_00460420.cpp) | D2Client/Unknown_00460420.cpp |
| 0x711DA0 | gData_00711DA0 (D2Client/UNIT/Player.cpp) | D2Client/UNIT/Player.cpp |
| 0x711EF4 | gData_00711EF4 (D2Client/UNIT/CUnit.cpp) | D2Client/UNIT/CUnit.cpp |
| 0x711F54 | gData_00711F54 (D2Client/GAME/Select.cpp) | D2Client/GAME/Select.cpp |
| 0x711FB0 | gData_00711FB0 (D2Client/ENGINE/Cursor.cpp) | D2Client/ENGINE/Cursor.cpp |
| 0x7121E0 | gData_007121E0 (D2Client/UI/CmdTbl.cpp) | D2Client/UNIT/CUnit.cpp |
| 0x712990 | gaszLanguageNames (header, placed by its object) (?) | D2Client/Unknown_0046ACE0.cpp |
| 0x712A28 | gData_00712A28 (D2Client/Unknown_0046ACE0.cpp) | D2Client/ENGINE/Gfx.cpp |
| 0x712A64 | gaszLanguageNames (header, placed by its object) (?) | D2Client/ENGINE/Gfx.cpp |
| 0x712B10 | gData_00712B10 (D2Client/ENGINE/Gfx_0046DB90.cpp) | D2Client/Unknown_00472DA0.cpp |
| 0x712B50 | gaszLanguageNames (header, placed by its object) (?) | D2Client/DRAW/dLightMap.cpp |
| 0x712C10 | gData_00712C10 (D2Client/GAME/View.cpp) | D2Client/GAME/View.cpp |
| 0x712C54 | gData_00712C54 (D2Client/GAME/PalShift.cpp) | D2Client/Unknown_00477620.cpp |
| 0x712C90 | gaszLanguageNames (header, placed by its object) (?) | D2Client/Unknown_00477620.cpp |
| 0x712DD0 | gData_00712DD0 (D2Client/GAME/Msg.cpp) | D2Client/Unknown_0047A980.cpp |
| 0x712E0C | gData_00712E0C (D2Client/CORE/ARCHIVE.CPP) | D2Client/Unknown_0047A980.cpp |
| 0x712E48 | gData_00712E48 (D2Client/GAME/RosterPets.cpp) | D2Client/Unknown_0047A980.cpp |
| 0x712E84 | gData_00712E84 (D2Client/GAME/Roster.cpp) | D2Client/Unknown_0047A980.cpp |
| 0x712EC0 | gData_00712EC0 (D2Client/Unknown_0047A980.cpp) | D2Client/Unknown_0047A980.cpp |
| 0x712F08 | gData_00712F08 (D2Client/UI/chat.cpp) | D2Client/UI/chat.cpp |
| 0x713008 | gData_00713008 (D2Client/Unknown_0047CC90.cpp) | D2Client/Unknown_0047CC90.cpp |
| 0x721C58 | gData_00721C58 (D2Client/WARDEN/WardenClient.cpp) | D2Client/WARDEN/WardenClient.cpp |
| 0x721CDC | gData_00721CDC (D2Client/UNIT/UnitMode.cpp) | D2Client/Sound/SoundHdr.cpp |
| 0x721D18 | gData_00721D18 (D2Client/Sound/SoundHdr.cpp) | D2Client/Unknown_00482C70.cpp |
| 0x721D58 | gaszLanguageNames (header, placed by its object) (?) | D2Client/Unknown_00482C70.cpp |
| 0x721DF8 | gData_00721DF8 (D2Client/UI/inv.cpp) | D2Client/UI/inv.cpp |
| 0x722298 | gData_00722298 (D2Client/UI/inv.cpp) | D2Client/UI/Hireables.cpp |
| 0x7222D4 | gaszLanguageNames (header, placed by its object) (?) | D2Client/UI/Hireables.cpp |
| 0x722318 | gData_00722318 (D2Client/UI/panel.cpp) | D2Client/UI/panel.cpp |
| 0x722414 | gData_00722414 (D2Client/Unknown_0049B030.cpp) | D2Client/Unknown_0049B030.cpp |
| 0x722470 | gData_00722470 (D2Client/Unknown_0049BB40.cpp) | D2Client/Unknown_0049BB40.cpp |
| 0x7225C0 | gData_007225C0 (D2Client/UI/text.cpp) | D2Client/UI/text.cpp |
| 0x723768 | gData_00723768 (D2Client/UI/QuestLog.cpp) | D2Client/UI/text.cpp |
| 0x724228 | gaszLanguageNames (header, placed by its object) (?) | D2Client/Unknown_004A43E0.cpp |
| 0x724798 | gData_00724798 (D2Client/Unknown_004A6260.cpp) | D2Client/Unknown_004A6460.cpp |
| 0x7247D8 | gData_007247D8 (D2Client/Unknown_004A6460.cpp) | D2Client/Unknown_004A6460.cpp |
| 0x724A80 | gData_00724A80 (D2Client/UI/spellsel.cpp) | D2Client/UI/spellsel.cpp |
| 0x724BB0 | gData_00724BB0 (D2Client/Unknown_004AA9C0.cpp) | D2Client/Unknown_004AA9C0.cpp |
| 0x724D3C | gData_00724D3C (D2Client/UNIT/MonUnique.cpp) | D2Client/UNIT/MonUnique.cpp |
| 0x7251E0 | gData_007251E0 (D2Client/UNIT/Monster.cpp) | D2Client/UNIT/Monster.cpp |
| 0x7253A0 | gData_007253A0 (D2Client/UI/npcmenu.cpp) | D2Client/UI/npcmenu.cpp |
| 0x7273A8 | gData_007273A8 (D2Client/UI/dialog.cpp) | D2Client/UI/dialog.cpp |
| 0x7274B0 | gData_007274B0 (D2Client/Unknown_004B8720.cpp) | D2Client/Sound/SoundInst.cpp |
| 0x7274EC | gData_007274EC (D2Client/Unknown_004B9200.cpp) | D2Client/Sound/SoundInst.cpp |
| 0x727528 | gaszLanguageNames (header, placed by its object) (?) | D2Client/Sound/SoundInst.cpp |
| 0x72756C | gaszLanguageNames (header, placed by its object) (?) | D2Client/Unknown_004BABF0.cpp |
| 0x727608 | gData_00727608 (D2Client/UI/editbox.cpp) | D2Client/UNIT/Object.cpp |
| 0x727688 | gData_00727688 (D2Client/Unknown_004BBE10.cpp) | D2Client/UNIT/Object.cpp |
| 0x727708 | gData_00727708 (D2Client/UNIT/Object.cpp) | D2Client/UNIT/Object.cpp |
| 0x72783C | gData_0072783C (D2Client/Unknown_004BC1B0.cpp) | D2Client/UI/useitem.cpp |
| 0x7278C0 | gData_007278C0 (D2Client/UI/useitem.cpp) | D2Client/UI/useitem.cpp |
| 0x7279B0 | gData_007279B0 (D2Client/UI/showitems.cpp) | D2Client/UNIT/Item.cpp |
| 0x7279EC | gData_007279EC (D2Client/UNIT/Item.cpp) | D2Client/UNIT/Item.cpp |
| 0x727A50 | gData_00727A50 (D2Client/SKILLS/Skills.cpp) | D2Client/SKILLS/Skills.cpp |
| 0x727DBC | gData_00727DBC (D2Client/SKILLS/SkillsBar.cpp) | D2Client/UNIT/UnitSnd.cpp |
| 0x727DF8 | gData_00727DF8 (D2Client/Unknown_004C9420.cpp) | D2Client/UNIT/UnitSnd.cpp |
| 0x727E34 | gData_00727E34 (D2Client/SKILLS/SkillsPal.cpp) | D2Client/UNIT/UnitSnd.cpp |
| 0x727E70 | gData_00727E70 (D2Client/Unknown_004C9D50.cpp) | D2Client/UNIT/UnitSnd.cpp |
| 0x72A300 | gData_0072A300 (D2Client/UNIT/Missile.cpp) | D2Client/UNIT/Missile.cpp |
| 0x72A650 | gData_0072A650 (D2Client/UNIT/PlrSkills.cpp) | D2Client/UNIT/PlrSkills.cpp |
| 0x72A788 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A7C4 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A800 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A83C | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A878 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A8B4 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A8F0 | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A92C | gpfnClientStateRemFuncs (D2Client/UNIT/PlrSkills.cpp) | D2Client/GAME/Wall2.cpp |
| 0x72A96C | gData_0072A96C (D2Client/GAME/Wall2.cpp) | D2Client/Unknown_004DEDB0.cpp |
| 0x72A9A8 | gData_0072A9A8 (D2Client/Unknown_004DEDB0.cpp) | D2Client/Unknown_004DEDB0.cpp |
| 0x72ADA8 | gData_0072ADA8 (D2Client/Unknown_004DF6C0.cpp) | D2Client/Unknown_004DF6C0.cpp |
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
| 0x72D994 | gData_0072D994 (D2Client/SKILLS/SkillsNec.cpp) | D2Gfx/SRC/Window.cpp |
| 0x72D9D0 | gData_0072D9D0 (D2Client/SKILLS/SkillsAma.cpp) | D2Gfx/SRC/Window.cpp |
| 0x72DA0C | gData_0072DA0C (D2Gfx/SRC/Window.cpp) | D2Gfx/SRC/Window.cpp |
| 0x72DC00 | gData_0072DC00 (D2Win/Src/D2WinMain.cpp) | D2Win/Src/D2WinMain.cpp |
| 0x72DDD8 | gData_0072DDD8 (D2Win/Src/D2WinArchive.cpp) | D2Win/Src/D2WinPalette.cpp |
| 0x72DE14 | gData_0072DE14 (D2Win/Src/D2WinPalette.cpp) | D2Win/Src/D2WinPalette.cpp |
| 0x72DE54 | gData_0072DE54 (D2Win/Src/D2WinTextBox.cpp) | D2Win/Src/D2WinTextBox.cpp |
| 0x72DE94 | gData_0072DE94 (D2Win/Src/D2WinImage.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72DED0 | gData_0072DED0 (D2Win/Src/D2WinTimer.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72DF0C | gData_0072DF0C (D2Win/Unknown_004FDA80.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72DF48 | gData_0072DF48 (D2Win/Src/D2WinEditBox.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72DF84 | gData_0072DF84 (D2Win/D2WinAnimImage.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72DFC0 | gData_0072DFC0 (D2Win/Src/D2WinButton.cpp) | D2Win/Src/D2WinFont.cpp |
| 0x72E010 | gData_0072E010 (D2Win/Src/D2Comp.cpp) | D2Win/Src/D2Comp.cpp |
| 0x72EFD4 | gData_0072EFD4 (D2Win/Src/D2WinSmack.cpp) | D2Glide/Src/glCore.cpp |
| 0x72F010 | gData_0072F010 (D2Win/Src/D2WinList.cpp) | D2Glide/Src/glCore.cpp |
| 0x72F04C | gData_0072F04C (D2Win/Src/D2WinAccountList.cpp) | D2Glide/Src/glCore.cpp |
| 0x72F088 | gData_0072F088 (D2Win/Src/D2WinProgressBar.cpp) | D2Glide/Src/glCore.cpp |
| 0x72F0C4 | gData_0072F0C4 (D2Win/Src/D2WinScrollbar.cpp) | D2Glide/Src/glCore.cpp |
| 0x72F100 | gData_0072F100 (D2Win/Src/D2WinPopup.cpp) | D2Glide/Src/glCore.cpp |
| 0x72F13C | gData_0072F13C (D2Glide/Unknown_00508970.cpp) | D2Glide/Src/glCore.cpp |
| 0x72F7F4 | gData_0072F7F4 (D2Sound/Unknown_00513A20.cpp) | D2Sound/Unknown_00513A20.cpp |
| 0x72F838 | gData_0072F838 (D2Sound/Unknown_00513BC0.cpp) | D2Sound/Unknown_00513BC0.cpp |
| 0x72F8FC | gData_0072F8FC (D2Sound/Unknown_00514B60.cpp) | D2Sound/Src/D2SoundSmp.cpp |
| 0x72F938 | gData_0072F938 (D2Sound/Src/D2SoundFast.cpp) | D2Sound/Src/D2SoundSmp.cpp |
| 0x72F974 | gData_0072F974 (D2Sound/Src/D2SoundSmp.cpp) | D2Sound/Src/D2SoundSmp.cpp |
| 0x72F9B4 | gData_0072F9B4 (D2Sound/Src/D2SoundUtil.cpp) | D2Hell/Unknown_00516DE1.cpp |
| 0x72FA20 | gData_0072FA20 (D2Hell/Unknown_00517804.cpp) | D2BNClient/Unknown_00518C00.cpp |
| 0x72FA60 | gData_0072FA20 (D2Hell/Unknown_00517804.cpp) | D2BNClient/Unknown_00518C00.cpp |
| 0x730128 | gapfnPacketHandlers (D2BNClient/BnSend.cpp) | Bnclient/Unknown_00520DC0.cpp |
| 0x730198 | gData_00730198 (D2Lang/StrTable/strtable.cpp) | D2Lang/StrTable/strtable.cpp |
| 0x730538 | gData_00730538 (D2Lang/Unknown_00526610.cpp) | D2Lang/Unknown_00526610.cpp |
| 0x730978 | gData_00730978 (D2Lang/Unknown_00526100.cpp) | D2Lang/Unknown_00526100.cpp |
| 0x730A28 | gData_00730A28 (D2Lang/Unknown_00526100.cpp) | Bnclient/Unknown_00527BE0.cpp |
| 0x730A64 | gData_00730A64 (D2Lang/Unknown_00526100.cpp) | Bnclient/Unknown_00527BE0.cpp |
| 0x730AA0 | gData_00730AA0 (D2Lang/Unknown_00526100.cpp) | Bnclient/Unknown_00527BE0.cpp |
| 0x730F84 | gData_00730F84 (D2Net/Unknown_0052B920.cpp) | D2Game/GAME/Game.cpp |
| 0x730FC0 | gData_00730FC0 (D2Net/Unknown_0052B920.cpp) | D2Game/GAME/Game.cpp |
| 0x731090 | gaszLanguageNames (header, placed by its object) (?) | D2Game/PLAYER/PlrSave.cpp |
| 0x7310D0 | gaszLanguageNames (header) (D2Game/DEBUG/Debug.cpp) | D2Game/UNIT/sunitproxy.cpp |
| 0x73110C | gaszLanguageNames (header) (D2Game/PLAYER/Player.cpp) | D2Game/UNIT/sunitproxy.cpp |
| 0x731148 | gaszLanguageNames (header, placed by its object) (?) | D2Game/UNIT/sunitproxy.cpp |
| 0x7312E0 | gaszLanguageNames (header) (D2Game/GAME/Clients.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x73131C | gaszLanguageNames (header) (D2Game/GAME/Level.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x731358 | gaszLanguageNames (header) (D2Game/GAME/SCmd.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x731394 | gaszLanguageNames (header) (D2Game/GAME/CCmd.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x7313D0 | gaszLanguageNames (header) (D2Game/GAME/Arena.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x73140C | gaszLanguageNames (header) (D2Game/UNIT/Party.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x731448 | gaszLanguageNames (header) (D2Game/GAME/Event.cpp) | D2Game/UNIT/SUnitInactive.cpp |
| 0x731484 | gaszLanguageNames (header, placed by its object) (?) | D2Game/UNIT/SUnitInactive.cpp |
| 0x7314D0 | gaszLanguageNames (header, placed by its object) (?) | D2Game/Quests/QUESTS.CPP |
| 0x73192C | gaszLanguageNames (header) (D2Game/OBJECTS/objrgn.cpp) | D2Game/PLAYER/PlrMsg.cpp |
| 0x731968 | gaszLanguageNames (header) (D2Game/MONSTER/MonsterRegion.cpp) | D2Game/PLAYER/PlrMsg.cpp |
| 0x7319A8 | gaszLanguageNames (header, placed by its object) (?) | D2Game/PLAYER/PlrMsg.cpp |
| 0x731AF0 | gaszLanguageNames (header, placed by its object) (?) | D2Game/Unknown_0054DAC0.cpp |
| 0x731B40 | gaszLanguageNames (header, placed by its object) (?) | D2Game/OBJECTS/Objects.cpp |
| 0x731ED4 | gaszLanguageNames (header) (D2Game/UNIT/SUnit.cpp) | D2Game/ITEMS/Items.cpp |
| 0x731F10 | gaszLanguageNames (header, placed by its object) (?) | D2Game/ITEMS/Items.cpp |
| 0x731F74 | gaszLanguageNames (header) (D2Game/UNIT/PlayerList.cpp) | D2Game/ITEMS/ItemMode.cpp |
| 0x731FB0 | gaszLanguageNames (header, placed by its object) (?) | D2Game/ITEMS/ItemMode.cpp |
| 0x73200C | gaszLanguageNames (header) (D2Game/GAME/Task.cpp) | D2Game/SKILLS/Skills.cpp |
| 0x732048 | gaszLanguageNames (header) (D2Game/PLAYER/PlrTrade.cpp) | D2Game/SKILLS/Skills.cpp |
| 0x732084 | gaszLanguageNames (header) (D2Game/PLAYER/PlrSave2.cpp) | D2Game/SKILLS/Skills.cpp |
| 0x7320C0 | gaszLanguageNames (header) (D2Game/Unknown_0056B180.cpp) | D2Game/SKILLS/Skills.cpp |
| 0x732100 | gData_00732100 (D2Game/SKILLS/Skills.cpp) | D2Game/SKILLS/Skills.cpp |
| 0x732678 | gaszLanguageNames (header, placed by its object) (?) | D2Game/Unknown_00570420.cpp |
| 0x7326B8 | gaszLanguageNames (header) (D2Game/UNIT/SUnitMsg.cpp) | D2Game/PLAYER/PlrIntro.cpp |
| 0x7326F8 | gaszLanguageNames (header, placed by its object) (?) | D2Game/PLAYER/PlrIntro.cpp |
| 0x732850 | gaszLanguageNames (header) (D2Game/MONSTER/MonsterAI.cpp) | D2Game/UNIT/SUnitDmg.cpp |
| 0x73288C | gaszLanguageNames (header) (D2Game/MONSTER/Monster.cpp) | D2Game/UNIT/SUnitDmg.cpp |
| 0x7328C8 | gaszLanguageNames (header) (D2Game/PLAYER/PlayerPets.cpp) | D2Game/UNIT/SUnitDmg.cpp |
| 0x732904 | gaszLanguageNames (header) (D2Game/UNIT/SUNITNPC.CPP) | D2Game/UNIT/SUnitDmg.cpp |
| 0x732940 | gData_00732940 (D2Game/UNIT/SUnitDmg.cpp) | D2Game/UNIT/SUnitDmg.cpp |
| 0x732BD0 | gaszLanguageNames (header, placed by its object) (?) | D2Game/PLAYER/PlrModes.cpp |
| 0x732CB0 | gaszLanguageNames (header, placed by its object) (?) | D2Game/OBJECTS/ObjMode.cpp |
| 0x732FB0 | gaszLanguageNames (header, placed by its object) (?) | D2Game/Unknown_00586B50.cpp |
| 0x736160 | gaszLanguageNames (header) (D2Game/Ai/AiGeneral.cpp) | D2Game/Unknown_0058F870.cpp |
| 0x7361A0 | gaszLanguageNames (header, placed by its object) (?) | D2Game/Unknown_0058F870.cpp |
| 0x738C10 | gaszLanguageNames (header, placed by its object) (?) | D2Game/INVENTORY/InvMode.cpp |
| 0x738CC8 | gaszLanguageNames (header) (D2Game/MONSTER/MonsterMsg.cpp) | D2Game/Quests/a2q0.cpp |
| 0x738D08 | gaszLanguageNames (header, placed by its object) (?) | D2Game/Quests/a2q0.cpp |
| 0x73BEE0 | gaszLanguageNames (header) (D2Game/MISSILES/Missiles.cpp) | D2Game/MONSTER/MonsterUnique.cpp |
| 0x73BF20 | gaszLanguageNames (header, placed by its object) (?) | D2Game/MONSTER/MonsterUnique.cpp |
| 0x73C4C0 | gData_0073C4C0 (D2Game/MONSTER/MonsterUnique.cpp) | D2Game/MONSTER/MonsterMode.cpp |
| 0x73C4FC | gData_0073C4FC (D2Game/MONSTER/MonsterUnique.cpp) | D2Game/MONSTER/MonsterMode.cpp |
| 0x73C538 | gData_0073C538 (D2Game/MONSTER/MonsterUnique.cpp) | D2Game/MONSTER/MonsterMode.cpp |
| 0x73C578 | gData_0073C578 (D2Game/MONSTER/MonsterMode.cpp) | D2Game/MONSTER/MonsterMode.cpp |
| 0x73C6E0 | gaszLanguageNames (header, placed by its object) (?) | D2Game/MISSILES/MissMode.cpp |
| 0x73C9DC | gData_0073C9DC (D2Game/Ai/AiThink.cpp) | D2Game/Ai/AiThink.cpp |
| 0x73D478 | gaszLanguageNames_0073D478 (D2Game/Ai/AiThink.cpp) | D2Game/Unknown_005B24E0.cpp |
| 0x73D4B4 | gaszLanguageNames (header, placed by its object) (?) | D2Game/Unknown_005B24E0.cpp |
| 0x73D530 | gaszLanguageNames (header, placed by its object) (?) | D2Game/Quests/a4q1.cpp |
| 0x73E810 | gpAct4Q4NpcMessages (D2Game/Quests/a4q1.cpp) | D2Game/Quests/a4q1.cpp |
| 0x741578 | gaszLanguageNames_00741578 (D2Game/Quests/a3q7.cpp) | D2Game/MONSTER/MonsterChoose.cpp |
| 0x741750 | gaszLanguageNames (header, placed by its object) (?) | D2Game/SKILLS/SkillItem.cpp |
| 0x741888 | gaszLanguageNames (header) (D2Game/UNIT/SUnitEvent.cpp) | D2Game/SKILLS/SkillNec.cpp |
| 0x7418C4 | gaszLanguageNames (header) (D2Game/Unknown_005C0D00.cpp) | D2Game/SKILLS/SkillNec.cpp |
| 0x741900 | gData_00741900 (D2Game/SKILLS/SkillNec.cpp) | D2Game/SKILLS/SkillNec.cpp |
| 0x7419A4 | gaszLanguageNames (header) (D2Game/SKILLS/SkillDruid.cpp) | D2Game/SKILLS/SkillAss.cpp |
| 0x7419E0 | gaszLanguageNames (header) (D2Game/SKILLS/SkillSor.cpp) | D2Game/SKILLS/SkillAss.cpp |
| 0x741A1C | gaszLanguageNames (header) (D2Game/SKILLS/SkillMonst.cpp) | D2Game/SKILLS/SkillAss.cpp |
| 0x741A58 | gaszLanguageNames (header) (D2Game/SKILLS/SkilPal.cpp) | D2Game/SKILLS/SkillAss.cpp |
| 0x741A94 | gaszLanguageNames (header) (D2Game/Unknown_005D1080.cpp) | D2Game/SKILLS/SkillAss.cpp |
| 0x741AD0 | gaszLanguageNames (header, placed by its object) (?) | D2Game/SKILLS/SkillAss.cpp |
| 0x741B18 | gaszLanguageNames (header, placed by its object) (?) | D2Game/SKILLS/SkillBar.cpp |
| 0x741C0C | gaszLanguageNames (header) (D2Game/SKILLS/SkillAma.cpp) | D2Game/Ai/AiThink4.cpp |
| 0x741C48 | gaszLanguageNames (header) (D2Game/Ai/AiUtil.cpp) | D2Game/Ai/AiThink4.cpp |
| 0x741C84 | gaszLanguageNames (header) (D2Game/Ai/AiTatics.cpp) | D2Game/Ai/AiThink4.cpp |
| 0x741CC0 | gaszLanguageNames (header) (D2Game/OBJECTS/OBJEVAL.CPP) | D2Game/Ai/AiThink4.cpp |
| 0x741CFC | gaszLanguageNames (header) (D2Game/Quests/QuestsFX.cpp) | D2Game/Ai/AiThink4.cpp |
| 0x741D38 | gaszLanguageNames (header, placed by its object) (?) | D2Game/Ai/AiThink4.cpp |
| 0x741D90 | gData_00741D90 (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x741DCC | gData_00741DCC (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x741E08 | gData_00741E08 (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x741E44 | gData_00741E44 (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x741E80 | gData_00741E80 (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x741EBC | gData_00741EBC (D2Game/Ai/AiThink4.cpp) | D2CMP/SRC/SpriteCache.cpp |
| 0x7435C8 | gData_007435C8 (D2CMP/SRC/Tilecmp.cpp) | D2Common/Chat/Ignorelist.cpp |
| 0x743780 | gData_00743780 (D2Common/Chat/Ignorelist.cpp) | D2Common/Chat/Ignorelist.cpp |
| 0x7437C0 | gData_007437C0 (D2Common/Logging/ProfCore.cpp) | D2Common/Logging/ProfCore.cpp |
| 0x7442C8 | gData_007442C8 (D2Common/DATATBLS/DataTbls.cpp) | D2Client/UI/SkillDesc_004E1FF0.cpp |
| 0x74430C | gData_0074430C (D2Common/DATATBLS/DataTbls.cpp) | D2Common/DATATBLS/DataTbls.cpp |
| 0x744348 | gData_00744348 (D2Common/DRLG/DrlgActivate.cpp) | D2Common/DRLG/DrlgActivate.cpp |
| 0x7443A8 | gData_007443A8 (D2Common/ENVIRONMENT/Env.cpp) | D2Common/ENVIRONMENT/Env.cpp |
| 0x7444C8 | gData_007444C8 (D2Common/DATATBLS/LvlTbls.cpp) | D2Common/DATATBLS/LvlTbls.cpp |
| 0x744508 | gData_00744508 (D2Common/UNITS/Units.cpp) | D2Common/UNITS/Units.cpp |
| 0x744588 | gData_00744588 (D2Common/Logging/Logging.cpp) | D2Common/Stats/StatsEx.cpp |
| 0x7445C4 | gData_007445C4 (D2Common/Unknown_00624740.cpp) | D2Common/Stats/StatsEx.cpp |
| 0x744600 | gData_00744600 (D2Common/Stats/StatsEx.cpp) | D2Common/Stats/StatsEx.cpp |
| 0x7446E8 | gData_007446E8 (D2Common/ITEMS/Items.cpp) | D2Common/INVENTORY/Inventory.cpp |
| 0x744724 | gData_00744724 (D2Common/DATATBLS/ItemTbls.cpp) | D2Common/INVENTORY/Inventory.cpp |
| 0x744760 | gData_00744760 (D2Common/INVENTORY/Inventory.cpp) | D2Common/INVENTORY/Inventory.cpp |
| 0x745584 | **borrowed** | D2Common/INVENTORY/Inventory.cpp |
| 0x745648 | gData_00745648 (D2Common/Monsters/MONSTERS.CPP) | D2Common/SKILLS/Skills.cpp |
| 0x745684 | gData_00745684 (D2Common/Unknown_0063F690.cpp) | D2Common/SKILLS/Skills.cpp |
| 0x7456C0 | gData_007456C0 (D2Common/Unknown_00640F20.cpp) | D2Common/SKILLS/Skills.cpp |
| 0x7456FC | gData_007456FC (D2Common/DRLG/Drlg.cpp) | D2Common/SKILLS/Skills.cpp |
| 0x745738 | gData_00745738 (D2Common/SKILLS/Skills.cpp) | D2Common/SKILLS/Skills.cpp |
| 0x7457B0 | gData_007457B0 (D2Common/PATH/Path.cpp) | D2Common/UNITS/Missile.cpp |
| 0x7457EC | gData_007457EC (D2Common/UNITS/Missile.cpp) | D2Common/UNITS/Missile.cpp |
| 0x74584C | gData_0074584C (D2Common/UNITS/UnitRoom.cpp) | D2Common/COMPOSIT/Composit.cpp |
| 0x745888 | gData_00745888 (D2Common/COLLISN/Collisn.cpp) | D2Common/COMPOSIT/Composit.cpp |
| 0x7458C4 | gData_007458C4 (D2Common/COMPOSIT/Composit.cpp) | D2Common/COMPOSIT/Composit.cpp |
| 0x745920 | gData_00745920 (D2Common/Unknown_0064FAA0.cpp) | D2Common/DATATBLS/MonsterTbls.cpp |
| 0x74595C | gData_0074595C (D2Common/Unknown_0064FAD0.cpp) | D2Common/DATATBLS/MonsterTbls.cpp |
| 0x745998 | gData_00745998 (D2Common/Unknown_00650D70.cpp) | D2Common/DATATBLS/MonsterTbls.cpp |
| 0x7459D4 | gData_007459D4 (D2Common/DATATBLS/MonsterTbls.cpp) | D2Common/DATATBLS/MonsterTbls.cpp |
| 0x745A28 | gData_00745A28 (D2Common/UNITS/UnitFinds.cpp) | D2Common/ITEMS/ItemMods.cpp |
| 0x745A64 | gData_00745A64 (D2Common/DATATBLS/TokTbls.cpp) | D2Common/ITEMS/ItemMods.cpp |
| 0x745AA0 | gData_00745AA0 (D2Common/DATATBLS/InvTbls.cpp) | D2Common/ITEMS/ItemMods.cpp |
| 0x745ADC | gData_00745ADC (D2Common/QuestRecord/QuestRecord.cpp) | D2Common/ITEMS/ItemMods.cpp |
| 0x745B18 | gData_00745B18 (D2Common/ITEMS/ItemMods.cpp) | D2Common/ITEMS/ItemMods.cpp |
| 0x7463A8 | gData_007463A8 (D2Common/DATATBLS/BeltTbls.cpp) | D2Common/DATATBLS/BeltTbls.cpp |
| 0x7463E8 | gData_007463E8 (D2Common/Waypoint/Waypoint.cpp) | D2Common/Waypoint/Waypoint.cpp |
| 0x7465E8 | gData_007465E8 (D2Common/Chat/Chat.cpp) | D2Common/DATATBLS/MissileTbls.cpp |
| 0x746624 | gData_00746624 (D2Common/Text/Text.cpp) | D2Common/DATATBLS/MissileTbls.cpp |
| 0x746660 | gData_00746660 (D2Common/DATATBLS/MissileTbls.cpp) | D2Common/DATATBLS/MissileTbls.cpp |
| 0x7466A0 | gData_007466A0 (D2Common/DATATBLS/Sequence.cpp) | D2Common/DATATBLS/Sequence.cpp |
| 0x748488 | gData_00748488 (D2Common/Unknown_006634F0.cpp) | D2Common/Unknown_006634F0.cpp |
| 0x74880C | gData_0074880C (D2Common/UNITS/MisStream.cpp) | D2Common/Unknown_006647C0.cpp |
| 0x748848 | gData_00748848 (D2Common/DATATBLS/OverlayTbls.cpp) | D2Common/Unknown_006647C0.cpp |
| 0x748884 | gData_00748884 (D2Common/Unknown_00664530.cpp) | D2Common/Unknown_006647C0.cpp |
| 0x7488C0 | gData_007488C0 (D2Common/Unknown_006647C0.cpp) | D2Common/Unknown_006647C0.cpp |
| 0x748A58 | gData_00748A58 (D2Common/DATATBLS/Arena.cpp) | D2Common/DATATBLS/Arena.cpp |
| 0x748A98 | gData_00748A98 (D2Common/DRLG/Preset.cpp) | D2Common/DRLG/Preset.cpp |
| 0x749690 | gData_00749690 (D2Common/Unknown_00668510.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x7496CC | gData_007496CC (D2Common/DATATBLS/HoradricCube.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749708 | gData_00749708 (D2Common/Unknown_0066A1A0.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x749744 | gData_00749744 (D2Common/DATATBLS/FieldTbls.cpp) | D2Common/DATATBLS/FieldTbls.cpp |
| 0x7497C8 | gData_007497C8 (D2Common/DATATBLS/AnimTbls.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x749804 | gData_00749804 (D2Common/Unknown_0066AB70.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x749840 | gData_00749840 (D2Common/DRLG/DrlgRoom.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x74987C | gData_0074987C (D2Common/DRLG/DrlgLogic.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x7498B8 | gData_007498B8 (D2Common/DRLG/DrlgAnim.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x7498F4 | gData_007498F4 (D2Common/DRLG/RoomTile.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x749930 | gData_00749930 (D2Common/DRLG/Maze.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x74996C | gData_0074996C (D2Common/Unknown_00674040.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x7499A8 | gData_007499A8 (D2Common/DRLG/Outdoors.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x7499E4 | gData_007499E4 (D2Common/DRLG/OutPlace.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x749A20 | gData_00749A20 (D2Common/PATH/PathUtil.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x749A5C | gData_00749A5C (D2Common/Unknown_00679380.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x749A98 | gData_00749A98 (D2Common/Unknown_0067A550.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x749AD4 | gData_00749AD4 (D2Common/Unknown_0067ADC0.cpp) | D2Common/Unknown_0067ADC0.cpp |
| 0x749B34 | gData_00749B34 (D2Common/Unknown_0067B9C0.cpp) | D2Direct3D/Src/d3dCore.cpp |
| 0x749B70 | gData_00749B70 (D2Common/DRLG/DrlgGrid.cpp) | D2Direct3D/Src/d3dCore.cpp |
| 0x749BC4 | gData_00749BC4 (D2Common/DRLG/DrlgVer.cpp) | D2Direct3D/Src/d3dCore.cpp |
| 0x749C00 | gData_00749C00 (D2Common/DRLG/OutRoom.cpp) | D2Direct3D/Src/d3dCore.cpp |
| 0x749C3C | gData_00749C3C (D2Common/DRLG/OutSiege.cpp) | D2Direct3D/Src/d3dCore.cpp |
| 0x749C78 | gData_00749C78 (D2Common/DRLG/OutJung.cpp) | D2Direct3D/Src/d3dCore.cpp |
| 0x749CB4 | gData_00749CB4 (D2Common/DRLG/OutDesr.cpp) | D2Direct3D/Src/d3dCore.cpp |
| 0x749CF0 | gData_00749CF0 (D2Common/DRLG/OutWild.cpp) | D2Direct3D/Src/d3dCore.cpp |
| 0x749D2C | gData_00749D2C (D2Common/Unknown_006808F0.cpp) | D2Direct3D/Src/d3dCore.cpp |
| 0x749D68 | gData_00749D68 (D2Common/Unknown_00681000.cpp) | D2Direct3D/Src/d3dCore.cpp |
| 0x749DA4 | gData_00749DA4 (D2Common/Unknown_00681490.cpp) | D2Direct3D/Src/d3dCore.cpp |
