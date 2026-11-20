#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"

#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_TILE 5
#define UNIT_TYPES_COUNT 6
#define UNIT_ITEM 4
#define MAX_QUEST_STATUS 42
#define QFLAG_UPDATEQUESTLOG 12
#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
#define STAT_GOLD 14
#define STAT_MANARECOVERY 26
#define STAT_MANARECOVERYBONUS 27
#define STATE_HEALTHPOT 100
#define STATE_MANAPOT 106
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define UNIT_PLAYER 0
#define UNITFLAGEX_TELEPORTED 0x10000

struct D2SkillsTxt;
struct D2GSPacketSrv26;
struct D2GSPacketClt15;
struct D2PlayerDataStrc;
struct D2StaticPathStrc;
struct D2UnkPlrMsgStrc;
struct D2CharStatsTxt;
struct D2ClientPlayerDataStrc;
struct D2MonsterDataStrc;
struct D2MonStatsTxt;
struct D2GSPacketClt3B;
struct D2GSPacketSrv26Args;
struct D2AiCmdStrc;
struct D2DynamicPathStrc;
struct D2CoordStrc;
struct D2UnitStrc;
struct D2GameStrc;
struct D2DataTablesStrc;
struct D2GSPacketSrv5A;
struct D2GSPacketClt20;




typedef void (__fastcall* PlrMsgFunc)(D2GameStrc*, D2UnitStrc*, D2ClientStrc*, int);

struct D2UnkPlrMsgStrc
{
    PlrMsgFunc field_0;
    int field_4;
    int field_8;
};

extern D2UnkPlrMsgStrc stru_6FD30708[20]; // 0x007319E8
void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife); // 0x0053B4B0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __fastcall sub_6FC3F060(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D4D0
void __fastcall sub_0053D530(D2ClientStrc* pClient, unsigned char a2, int a3, int nUnitType, int nUnitGUID, unsigned short a6, unsigned short a7, unsigned char a8, int a9);
int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005387F0

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    unsigned char unk_20[0x4D];
    unsigned char nDifficulty;
    unsigned char unk_6E[0x2];
    int bExpansion;
    char f_74[0x34];
    int dwGameFrame;
    int sub_005490E0_CheckCursorItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x005490E0
    int sub_00549150_CheckStoredItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x00549150
    int sub_005492F0_CheckBeltItem(D2UnitStrc* pUnit, int nItemGUID);
};

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10


void __fastcall D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(D2ClientStrc* pClient, char nHeader, unsigned char bTOU, int a4, char a5, short a6, short a7, char a8, short a9, short a10); // 0x0053B570
int __fastcall sub_6FC7C3A0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00535610
void __fastcall sub_00549A60_SendCantDoThat(D2UnitStrc* pUnit); // 0x00549A60
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall sub_6FC48940(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nBeltSlot, int bFindFreeSlot, int* a6); // 0x0055E9B0
int __fastcall sub_6FC446B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4, int a5, int bSetQuantityFlag, D2InventoryStrc* pInventoryArg, int a8); // 0x00560420
int __fastcall sub_6FC45550(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* a6); // 0x00563D20
void __fastcall D2GAME_NPC_IdentifyBoughtItem_6FCCA990(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID); // 0x00578640
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360



struct D2ClientPlayerDataStrc
{
    int dwInactivityTime;
    unsigned short nHitPoints;
    unsigned short nManaPoints;
    unsigned short nStaminaPoints;
    unsigned char nPotionLifePercent;
    unsigned char nPotionManaPercent;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned short nTargetOffsetX;
    unsigned short nTargetOffsetY;
    int dwBeltGold;
    int dwExperience;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __stdcall D2COMMON_10473(D2StatListStrc* pStatList); // 0x00626090
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void* __fastcall CLIENTS_GetClientPlayerData(D2ClientStrc* pClient); // 0x00539330
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall SCMD_SendVitalsAndPotionPrediction(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned char nPotionLifePercent, unsigned char nPotionManaPercent, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY); // 0x0053C230
void __fastcall SCMD_SendVitals(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY); // 0x0053C320
void __fastcall D2GAME_PACKETS_SendPacket0x96_WalkVerify_6FC3DA90(D2ClientStrc* pClient, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY); // 0x0053C3F0
void __fastcall D2GAME_PACKETS_SendPacket0x19_6FC3D3D0(D2ClientStrc* pClient, int nValue, int a3); // 0x0053E9B0
void __fastcall D2GAME_PACKETS_SendPacket0x1A_B_C_6FC3D410(D2ClientStrc* pClient, int nExperience, int a3); // 0x0053BDD0




extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" const char gszPlrMsgSourceFile[];
extern unsigned int gdwBitMasks[];
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit);
void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7);
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall QUESTS_UseClueItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID); // 0x00544840
D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer);
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);
void __fastcall SUNIT_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTile);
int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x00557FF0
unsigned int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);
void __fastcall D2GAME_PickupItemEx_6FC42B80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus);
int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nX, int nY, int* pItemStatus); // 0x0055E170
int __fastcall ITEMMODE_MergeItemStacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID1, int nItemGUID2, int* pItemStatus);
int __fastcall D2GAME_Return0_6FC48930(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus);
int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus);
int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0
int __fastcall ITEMMODE_UseItemOnItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetGUID, int nUseItemGUID, int* pItemStatus);
int __fastcall ITEMMODE_UseBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nX, int nY, int* pItemStatus, int bUseOnMerc);
int __fastcall ITEMMODE_PlaceItemInCube(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nCubeGUID, int* pItemStatus);
int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus);
void __fastcall PLRTRADE_TryToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678A0
void __fastcall MONSTERAI_ActivateNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract);
void __fastcall MONSTERAI_EndNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract);
void __fastcall MONSTERAI_StartNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonsterInteractStrc* pMonInteract, char nQuestFlags);
int __fastcall NPC_HandleDialogMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nType, int nNpcGUID, int nItemGUID);
void __fastcall sub_0057FB70_PickUpCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody);
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7);
void __fastcall StartModeID(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70
int __fastcall OBJMODE_OperateObjectInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectType, int nObjectGUID);
void __fastcall OBJMODE_UpdateDoorModeFromCollision(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID);
void __fastcall sub_00584F60(D2GameStrc* pGame, D2UnitStrc* pUnit, int nWaypointGUID, int nLevelId);
int __fastcall OBJMODE_MainObeliskHandler(D2GameStrc* pGame, int nPlayerGUID, int nObjectGUID, int nItemGUID, short nState);
void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue);
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall sub_00622B50_TestInteractCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMask);
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit);
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject);
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem);
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);
void __fastcall sub_00641F20_SetPlayerModeState(D2UnitStrc* pUnit, int nMode, int nArg1, int nArg2);
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);
int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill);
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue);
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo);
int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField);

#pragma pack(push, 1)
struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    unsigned int dwParam;
    unsigned char nParam;
    char szText[32];
};

#pragma pack(pop)

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
int __fastcall sub_6FC828D0(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame); // 0x00548B00
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EE70
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell); // 0x00628320
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210
int __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot); // 0x0063C4F0
int __stdcall INVENTORY_GetFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int* pFreeSlotId); // 0x0063C600
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
void __stdcall CHAT_SetLangIdInHoverMsg(D2HoverTextStrc* pHoverMsg, unsigned char nLangId); // 0x00661230

#pragma pack(push, 1)
struct D2GSPacketClt3B
{
    unsigned char nHeader;
    unsigned short nSkill;
};

#pragma pack(pop)

int __fastcall D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50(D2UnitStrc* pUnit, int nSkillId); // 0x0056C700
int __stdcall SKILLS_CheckRequiredSkills(D2UnitStrc* pUnit, int nSkillId); // 0x006447D0
int __stdcall SKILLS_CheckRequiredAttributes(D2UnitStrc* pUnit, int nSkillId); // 0x00644920
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x0053C4A0
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __fastcall sub_6FD136E0(D2UnitStrc* pUnit, int nSkillId); // 0x00570080
void __fastcall sub_0055F4F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x0055F4F0

struct D2GSPacketSrv26Args
{
    D2GSPacketSrv26* pPacket26;
    D2GSPacketClt15* pPacket15;
    int nUnitId;
};

D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient); // 0x005387C0

struct D2GSPacketSrv26 {
    unsigned char header, messageType, language, unitType;
    unsigned int unitId;
    unsigned char messageColor, nameColor;
    char name[16];
    char message[256];
};

void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket); // 0x0053C750
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pInteractUnitType, int* pInteractUnitGUID); // 0x00554100
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag); // 0x0055B300

typedef void (__fastcall *ClientCallback)(D2ClientStrc*, void*);

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __fastcall GAME_ForEachIngameClient(D2GameStrc*, ClientCallback, void*); // 0x0052DED0
void __fastcall j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc*, void*); // 0x0054A5C0
void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket); // 0x0053C850
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0
int __fastcall sub_00557FF0_InventoryContainsItem(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x00557FF0

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0
void __fastcall AIGENERAL_FreeAllAiCommands(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058EDE0
D2AiCmdStrc* __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40
void __stdcall STATES_ToggleState(D2UnitStrc* unit, int state, int enabled); // 0x00639DB0

typedef char H15_CheckInventoryOffset[(int)&((D2UnitStrc*)0)->pInventory == 0x60 ? 1 : -1];

typedef char H15_CheckGameFrameOffset[(int)&((D2GameStrc*)0)->dwGameFrame == 0xA8 ? 1 : -1];

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY); // 0x005BF240
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0
void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2); // 0x0062EA80
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70
void __fastcall sub_0055C460_UpdateItemStatlist(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAllowBrokenItemStats); // 0x0055C460
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0
int __fastcall sub_6FC4B9D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055FB10
static __declspec(noinline) int __stdcall sub_6FC83D00(D2UnitStrc* pUnit, D2UnitStrc* pTarget);
static __declspec(noinline) int __stdcall sub_6FC83C60(unsigned short nX, unsigned short nY, D2UnitStrc* pUnit, int nMaxDistance);
static __declspec(noinline) int __stdcall sub_00548F80_CheckTargetUnit(int nMaxDistance, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID);

#pragma pack(push, 1)
struct D2GSPacketClt20
{
    unsigned char nHeader;
    int nItemGUID;
    int nPosX;
    int nPosY;
};

#pragma pack(pop)

static __forceinline int sub_005494E0_CheckSkillLevel(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);
D2UnitStrc* __stdcall sub_0063BDE0(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall sub_0063BE30_Return(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30
void __fastcall sub_0055DF00_RecalcItemStates(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4); // 0x0055DF00
void __fastcall sub_0055F500_RefreshItemStatLists(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0055F500
static __declspec(noinline) int __stdcall sub_0054D130_TakeMercItemToCursor(D2GameStrc* pGame, D2UnitStrc* pMerc, D2UnitStrc* pPlayer, int nBodyLoc);

// 0x00547F70
void __fastcall sub_6FC81C00(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    const char nHitType = pUnit->dwLastHitClass;
    const unsigned char nLife = UNITS_GetCurrentLifePercentage(pUnit);
    int nY;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nY = pUnit->pStaticPath->tGameCoords.nY;
    else
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    int nX;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nX = pUnit->pStaticPath->tGameCoords.nX;
    else
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    const int nUnitId = (pUnit ? pUnit->dwUnitId : -1);
    D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient, 0x0D, 0, nUnitId, 19, nX, nY, nHitType, nLife);
}

// 0x00548090
void __fastcall sub_6FC81D20(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill && (SKILLS_GetFlags(pSkill) & 4 || pUnit != CLIENTS_GetPlayerFromClient(pClient, 0)))
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrMsg.cpp", 207);
        const char nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);

        if (pTarget && CLIENTS_IsInUnitsRoom(pTarget, pClient))
        {
            sub_0053D530(pClient, 0, nUnitGUID, !pTarget ? UNIT_TYPES_COUNT : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId, nSkillId, 0, nSkillLevel, 0);
        }
        else
        {
            sub_6FC3F060(pClient, 0, nUnitGUID, D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath), (unsigned short)nSkillId, 0, nSkillLevel, 0);
        }
    }
}

inline int PLRMSG_IsBodyLocValid(int nBodyLoc)
{
    return nBodyLoc > 0 && nBodyLoc < 11;
}

// 0x005482A0
void __fastcall sub_6FC81F60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    const char nHitClass = pUnit->dwLastHitClass;
    int nY;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nY = pUnit->pStaticPath->tGameCoords.nY;
    else
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    int nX;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nX = pUnit->pStaticPath->tGameCoords.nX;
    else
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    const int nUnitId = pUnit->dwUnitId;
    D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(pClient, 0x0F, 0, nUnitId, (unsigned char)stru_6FD30708[nAnimMode].field_4, D2COMMON_10175_PathGetFirstPointX(pPath), D2COMMON_10176_PathGetFirstPointY(pPath), nHitClass, nX, nY);
}

// 0x00548350
void __fastcall sub_6FC82010(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    const int nField = stru_6FD30708[nAnimMode].field_4;
    const char nHitClass = pUnit->dwLastHitClass;
    const char nLife = UNITS_GetCurrentLifePercentage(pUnit);
    int nY;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nY = pUnit->pStaticPath->tGameCoords.nY;
    else
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    int nX;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nX = pUnit->pStaticPath->tGameCoords.nX;
    else
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient, 0x0D, 0, !pUnit ? -1 : pUnit->dwUnitId, nField, nX, nY, nHitClass, nLife);
}

// 0x00548400
void __fastcall sub_6FC821C0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    if (pUnit != CLIENTS_GetPlayerFromClient(pClient, 0))
    {
        const unsigned char nLife = UNITS_GetCurrentLifePercentage(pUnit);
        const int nHitClass = stru_6FD30708[nAnimMode].field_4;
        int nY;
        if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
            nY = pUnit->pStaticPath->tGameCoords.nY;
        else
            nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        int nX;
        if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
            nX = pUnit->pStaticPath->tGameCoords.nX;
        else
            nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        const int nUnitId = (pUnit ? pUnit->dwUnitId : -1);
        D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient, 0x0D, 0, nUnitId, nHitClass, nX, nY, 0, nLife);
    }
}

// build: context sub_005485B0_GetPotionLifePercent
static unsigned char sub_005485B0_GetPotionLifePercent(D2UnitStrc* pUnit)
{
    D2StatListStrc* pHealthPotStatList;
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nShiftedMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    pHealthPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_HEALTHPOT);
    if (pHealthPotStatList && nShiftedMaxHp)
    {
        D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
        const int nFrameDiff = D2COMMON_10473(pHealthPotStatList) - pGame->dwGameFrame;
        const unsigned char nPotionLifePercent = 100 * ((nHitpoints + nFrameDiff * STATLIST_GetStatValue(pHealthPotStatList, STAT_HPREGEN, 0)) >> 8) / nShiftedMaxHp;
        return nPotionLifePercent > 100 ? 100 : nPotionLifePercent;
    }

    return 0;
}

static D2CharStatsTxt* sub_00548640_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x00548640
static unsigned char sub_00548640_GetPotionManaPercent(D2UnitStrc* pUnit)
{
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    D2StatListStrc* pManaPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_MANAPOT);
    if (!pManaPotStatList || !nMaxMana)
    {
        return 0;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = sub_00548640_GetCharStatsTxtRecord(pUnit ? pUnit->dwClassId : -1);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    int nManaRegen = 25 * pCharStatsTxtRecord->nManaRegen;
    if (!nManaRegen)
    {
        nManaRegen = 7500;
    }

    const int nQuotient = nMaxMana / nManaRegen;
    const int nManaMultiplier = nQuotient < 1 ? 1 : nQuotient;
    const int nRecoveryBonus = STATLIST_UnitGetStatValue(pUnit, STAT_MANARECOVERYBONUS, 0);
    const int nRecovery = STATLIST_UnitGetStatValue(pUnit, STAT_MANARECOVERY, 0);
    const int nFrameMultiplier = nManaMultiplier * (nRecoveryBonus + 100) / 100 + nRecovery;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    const unsigned char nPotionManaPercent = 100 * (nMana + nFrameMultiplier * (D2COMMON_10473(pManaPotStatList) - pGame->dwGameFrame)) / nMaxMana;
    return nPotionManaPercent > 100 ? 100 : nPotionManaPercent;
}

// 0x00548760
int __fastcall sub_6FC82360(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int bSkipHpCheck)
{
    if (!pPlayer || !pUnit)
    {
        return 0;
    }

    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrMsg.cpp", 0x1B0);
    if (!pClient)
    {
        return 0;
    }

    D2ClientPlayerDataStrc* pClientPlayerData = (D2ClientPlayerDataStrc*)CLIENTS_GetClientPlayerData(pClient);
    if (!pClientPlayerData)
    {
        return 0;
    }

    const int nShiftedHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
    const int nShiftedMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    if (nShiftedMaxHp <= 0)
    {
        return 0;
    }

    int nHpDiff = (unsigned short)pClientPlayerData->nHitPoints - nShiftedHitpoints;
    if (nHpDiff < 0)
    {
        nHpDiff = -nHpDiff;
    }

    if (!bSkipHpCheck && (100 * nHpDiff / nShiftedMaxHp < 10 || !nShiftedHitpoints && pClientPlayerData->nHitPoints))
    {
        return 0;
    }

    const int nUnitX = (unsigned short)CLIENTS_GetUnitX(pUnit);
    const int nUnitY = (unsigned short)CLIENTS_GetUnitY(pUnit);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    unsigned char nX = 0;
    unsigned char nY = 0;
    if (pPath)
    {
        nX = nUnitX - D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = nUnitY - D2COMMON_10176_PathGetFirstPointY(pPath);
    }

    const int nShiftedMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) >> 8;
    const int nStamina = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) >> 8;
    const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    const int nExperience = STATLIST_UnitGetStatValue(pUnit, STAT_EXPERIENCE, 0);
    const unsigned char nPotionLifePercent = sub_005485B0_GetPotionLifePercent(pUnit);
    const unsigned char nPotionManaPercent = sub_00548640_GetPotionManaPercent(pUnit);

    int bSent = 1;
    if (pClientPlayerData->nPotionLifePercent == nPotionLifePercent && pClientPlayerData->nPotionManaPercent == nPotionManaPercent)
    {
        if (pClientPlayerData->nHitPoints == (unsigned short)nShiftedHitpoints && pClientPlayerData->nManaPoints == (unsigned short)nShiftedMana)
        {
            if (pClientPlayerData->nStaminaPoints == (unsigned short)nStamina)
            {
                if (pClientPlayerData->dwInactivityTime <= 3)
                {
                    bSent = 0;
                }
                else
                {
                    int nXDiff = pClientPlayerData->nPosX - (unsigned short)nUnitX;
                    if (nXDiff < 0)
                    {
                        nXDiff = -nXDiff;
                    }

                    if (nXDiff < 2)
                    {
                        int nYDiff = pClientPlayerData->nPosY - (unsigned short)nUnitY;
                        if (nYDiff < 0)
                        {
                            nYDiff = -nYDiff;
                        }

                        if (nYDiff < 2)
                        {
                            bSent = 0;
                        }
                    }
                }
            }

            if (bSent)
            {
                D2GAME_PACKETS_SendPacket0x96_WalkVerify_6FC3DA90(pClient, nStamina, nUnitX, nUnitY, nX, nY);
            }
        }
        else
        {
            SCMD_SendVitals(pClient, nShiftedHitpoints, nShiftedMana, nStamina, nUnitX, nUnitY, nX, nY);
        }
    }
    else
    {
        SCMD_SendVitalsAndPotionPrediction(pClient, nShiftedHitpoints, nShiftedMana, nStamina, nPotionLifePercent, nPotionManaPercent, nUnitX, nUnitY, nX, nY);
    }

    if (bSent)
    {
        pClientPlayerData->nPosX = nUnitX;
        pClientPlayerData->nPosY = nUnitY;
        pClientPlayerData->nTargetOffsetX = nX;
        pClientPlayerData->nTargetOffsetY = nY;
        pClientPlayerData->dwInactivityTime = 0;
    }
    else
    {
        ++pClientPlayerData->dwInactivityTime;
    }

    if (nGold != pClientPlayerData->dwBeltGold)
    {
        D2GAME_PACKETS_SendPacket0x19_6FC3D3D0(pClient, nGold, pClientPlayerData->dwBeltGold);
        pClientPlayerData->dwBeltGold = nGold;
    }

    if (nExperience != pClientPlayerData->dwExperience)
    {
        D2GAME_PACKETS_SendPacket0x1A_B_C_6FC3D410(pClient, nExperience, pClientPlayerData->dwExperience);
        pClientPlayerData->dwExperience = nExperience;
    }

    pClientPlayerData->nHitPoints = nShiftedHitpoints;
    pClientPlayerData->nStaminaPoints = nStamina;
    pClientPlayerData->nManaPoints = nShiftedMana;
    pClientPlayerData->nPotionLifePercent = nPotionLifePercent;
    pClientPlayerData->nPotionManaPercent = nPotionManaPercent;
    return 1;
}

static __forceinline D2MonsterInteractStrc* PLRMSG_GetMonInteract(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonInteract;
    }

    return 0;
}

static __forceinline int PLRMSG_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int PLRMSG_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00548A50
static __declspec(noinline) void __stdcall sub_00548A50_ChangeModeAndSetInteract(int nInteractSkill, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID)
{
    StartModeID(pGame, pPlayer, 0, 3, nUnitType, nUnitGUID, 0);
    sub_00641F20_SetPlayerModeState(pPlayer, nInteractSkill, nUnitType, nUnitGUID);
}

int __fastcall sub_6FC828D0(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame)
{
    switch (nUnitType)
    {
    case 2:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 2, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        D2_ASSERT(DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId), 703);

        if (pUnit->dwAnimMode >= 8)
        {
            return 3;
        }

        if (D2Common_10399(pPlayer, pUnit) > 50)
        {
            return 1;
        }

        if (UNITS_IsObjectInInteractRange(pPlayer, pUnit) && !sub_00622B50_TestInteractCollision(pPlayer, pUnit, 0x804))
        {
            D2Common_10153(pPlayer->pDynamicPath);
            if (!OBJMODE_OperateObjectInRange(pGame, pPlayer, 2, nUnitGUID))
            {
                return 3;
            }
        }
        else
        {
            sub_00548A50_ChangeModeAndSetInteract(a4 ? -2 : -1, pGame, pPlayer, 2, nUnitGUID);
        }

        return 0;
    }
    case 5:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 5, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        const int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        if (nDistance > 4)
        {
            sub_00548A50_ChangeModeAndSetInteract(a4 ? -2 : -1, pGame, pPlayer, 5, nUnitGUID);
        }
        else
        {
            SUNIT_WarpPlayer(pGame, pPlayer, pUnit);
        }

        return 0;
    }
    case 4:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 4, nUnitGUID);
        const int nAnimMode = pUnit ? pUnit->dwAnimMode : 0;
        if (!pUnit || nAnimMode != 3)
        {
            return 1;
        }

        const int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        if (nDistance <= 4 && !sub_00622B50_TestInteractCollision(pPlayer, pUnit, 0x804))
        {
            int bFailed;
            if (a4)
            {
                D2GAME_PickupItemEx_6FC42B80(pGame, pPlayer, nUnitGUID, &bFailed);
            }
            else
            {
                D2GAME_PickupItem_6FC43340(pGame, pPlayer, nUnitGUID, &bFailed);
            }

            if (bFailed)
            {
                return 3;
            }
        }
        else
        {
            sub_00548A50_ChangeModeAndSetInteract(a4 ? -2 : -1, pGame, pPlayer, 4, nUnitGUID);
        }

        return 0;
    }
    case 1:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 1, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        const int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[1] && pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0])
        {
            D2Common_10153(pUnit->pDynamicPath);
            AIGENERAL_SetAiControlParam(pUnit, 1, 40);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 1, 0, 0);
        }

        if (nDistance > 6)
        {
            if (nDistance >= 9)
            {
                return 0;
            }

            sub_00548A50_ChangeModeAndSetInteract(a4 ? -2 : -1, pGame, pPlayer, 1, nUnitGUID);
            return 0;
        }
        else if (!PLAYER_IsBusy(pPlayer))
        {
            D2Common_10153(pPlayer->pDynamicPath);
            MONSTERAI_StartNpcInteraction(pGame, pPlayer, pUnit, sub_00535E80_GetMonInteract(pUnit), 0);
        }

        return 0;
    }
    case 0:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        const unsigned int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        if (nDistance > 8)
        {
            sub_00548A50_ChangeModeAndSetInteract(a4 ? -2 : -1, pGame, pPlayer, 0, nUnitGUID);
            return 0;
        }

        if (pUnit->dwAnimMode == 17 && !D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pPlayer, 1) && !D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
        {
            sub_0057FB70_PickUpCorpse(pGame, pPlayer, pUnit);
        }
        else
        {
            PLRTRADE_TryToTrade(pGame, pPlayer, pUnit);
        }

        return 0;
    }
    }

    return 1;
}

// 0x00549220
static __declspec(noinline) int __stdcall sub_00549220_CheckOwnedItem(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pGame, 1192);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem))
    {
        return 0;
    }

    return INVENTORY_GetCursorItem(pUnit->pInventory) != pItem;
}

static __declspec(noinline) int __stdcall sub_6FC86520(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pGame, 1283);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    int nResult = 0;
    switch (pItem->dwAnimMode)
    {
    case 3:
    {
        nResult = sub_6FC83D00(pPlayer, pItem);
        if (nResult)
        {
            return nResult;
        }

        const int nX = CLIENTS_GetUnitX(pItem);
        nResult = sub_6FC83C60(nX, CLIENTS_GetUnitY(pItem), pPlayer, 10);
        if (nResult)
        {
            return nResult;
        }
        break;
    }
    case 0:
    case 1:
    case 2:
    case 4:
        nResult = sub_00549220_CheckOwnedItem(nItemGUID, pGame, pPlayer);
        if (nResult)
        {
            return nResult;
        }
        break;
    default:
        return 1;
    }

    return 0;
}

static __declspec(noinline) int __stdcall sub_00549520_CheckOrificeObject(int nItemGUID, unsigned short nState, D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID)
{
    const int nResult = sub_00548F80_CheckTargetUnit(50, pGame, pUnit, 2, nObjectGUID);
    if (nResult)
    {
        return nResult;
    }

    switch (nState)
    {
    case 2:
        return 0;
    case 3:
        return pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    default:
        return 2;
    }
}

// build: context sub_00549570_CheckWaypointObject
static __declspec(noinline) int __stdcall sub_00549570_CheckWaypointObject(D2UnitStrc* pUnit, D2GameStrc* pGame, int nObjectGUID, unsigned short nLevelId)
{
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, nObjectGUID);
    if (!pObject)
    {
        return 1;
    }

    const unsigned char nUnitAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
    if (nUnitAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pObject))))
    {
        return 2;
    }

    const int nX = PLRMSG_GetUnitX(pObject);
    const int nY = PLRMSG_GetUnitY(pObject);
    int nMaxDistance = 10;
    if (pUnit && pUnit->dwClassId == 1)
    {
        nMaxDistance = 22;
    }

    const int nResult = sub_6FC83C60(nX, nY, pUnit, nMaxDistance);
    if (nResult)
    {
        return nResult;
    }

    if (!nLevelId)
    {
        return 0;
    }

    if (nLevelId >= sgptDataTables->nLevelsTxtRecordCount)
    {
        return 3;
    }

    D2_ASSERT(UNITS_GetPlayerData(pUnit), 1586);

    unsigned short nWaypointNo;
    if (!WAYPOINTS_GetWaypointNoFromLevelId(nLevelId, &nWaypointNo))
    {
        return 3;
    }

    return WAYPOINTS_IsActivated(sub_00547F50(pGame, pUnit), nWaypointNo) ? 0 : 2;
}

// 0x005496F0
static __declspec(noinline) int __stdcall sub_6FC82D10(D2GameStrc* pGame, int nPacketSize, unsigned short* pX, unsigned short* pY, D2UnitStrc* pUnit, void* pPacket)
{
    *pX = 0;
    *pY = 0;

    if (nPacketSize != 5)
    {
        return 3;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    if (!pPlayerData)
    {
        return 2;
    }

    const unsigned short nX = *(unsigned short*)((char*)pPacket + 1);
    const unsigned short nY = *(unsigned short*)((char*)pPacket + 3);

    const int nResult = sub_6FC83C60(nX, nY, pUnit, 50);
    if (nResult)
    {
        if (pGame->dwGameFrame - pPlayerData->dwGameFrame > 25)
        {
            D2ClientStrc* pClient = UnitGetClient(pUnit, gszPlrMsgSourceFile, 1639);
            if (pClient)
            {
                D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(pClient, 0x15, 0, !pUnit ? -1 : pUnit->dwUnitId, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 1);
            }
        }

        return nResult;
    }

    pPlayerData->dwGameFrame = pGame->dwGameFrame;
    *pX = nX;
    *pY = nY;
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x01_Walk_6FC82CB0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    sub_6FC817D0(pGame, pUnit, 0, 2, nX, nY, 0);
    return 0;
}

static __declspec(noinline) int __stdcall sub_00549830_ReadTargetUnitPacket(D2GameStrc* pGame, int nPacketSize, int* pUnitType, int* pUnitGUID, D2UnitStrc* pUnit, void* pPacket)
{
    *pUnitType = 0;
    *pUnitGUID = 0;

    if (nPacketSize != 9)
    {
        return 3;
    }

    const unsigned int nUnitType = *(unsigned int*)((char*)pPacket + 1);
    const int nUnitGUID = *(int*)((char*)pPacket + 5);
    if (nUnitType >= 6)
    {
        return 2;
    }

    const int nResult = sub_00548F80_CheckTargetUnit(50, pGame, pUnit, nUnitType, nUnitGUID);
    if (nResult)
    {
        return nResult;
    }

    *pUnitType = nUnitType;
    *pUnitGUID = nUnitGUID;
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x02_WalkToEntity_6FC82ED0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    StartModeID(pGame, pUnit, 0, 2, nUnitType, nUnitGUID, 0);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x03_Run_6FC83090(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    sub_6FC817D0(pGame, pUnit, 0, 3, nX, nY, 0);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x04_RunToEntity_6FC830F0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    StartModeID(pGame, pUnit, 0, 3, nUnitType, nUnitGUID, 0);
    return 0;
}

// 0x00549960
static __declspec(noinline) D2SkillStrc* __stdcall sub_6FC83450(D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    D2SkillStrc* pUsedSkill = pSkill;
    if (!SKILLS_GetSkillIdFromSkill(pSkill, gszPlrMsgSourceFile, 1804))
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (pRightWeapon && (!sub_0062A4E0_TestItem(pRightWeapon) || ITEMS_GetItemType(pRightWeapon) == 38))
        {
            pRightWeapon = 0;
        }

        D2UnitStrc* pLeftWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (pLeftWeapon && (!sub_0062A4E0_TestItem(pLeftWeapon) || ITEMS_GetItemType(pLeftWeapon) == 38))
        {
            pLeftWeapon = 0;
        }

        if (pRightWeapon && pLeftWeapon && ITEMSIsA(pRightWeapon, 45) && ITEMSIsA(pLeftWeapon, 45))
        {
            if (!SKILLS_GetParam4(pSkill))
            {
                pUsedSkill = SKILLS_GetSkillById(pUnit, 5, -1);
                D2_ASSERT(pUsedSkill, 1829);
                SKILLS_SetParam4(pSkill, 5);
            }
            else
            {
                SKILLS_SetParam4(pSkill, 0);
            }
        }
    }

    return pUsedSkill;
}

static __declspec(noinline) int __stdcall sub_6FC83340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY)
{
    if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 17)
    {
        return 2;
    }

    D2SkillStrc* pUsedSkill = pSkill;
    if (UNITS_CanDualWield(pUnit))
    {
        pUsedSkill = sub_6FC83450(pSkill, pUnit);
    }

    int nSkillUseState = SKILLS_GetUseState(pUnit, pUsedSkill);
    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pUsedSkill);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    if (nSkillUseState > 0 && (nSkillUseState <= 2 || nSkillUseState == 4) && pSkillsTxtRecord->nFlags[3] & gdwBitMasks[4])
    {
        pUsedSkill = SKILLS_GetSkillById(pUnit, 0, -1);
        nSkillUseState = SKILLS_GetUseState(pUnit, pUsedSkill);
    }

    const int nSkillMode = SKILLS_GetSkillModeFromUnit(pUnit, pUsedSkill);
    if (!nSkillMode)
    {
        return 2;
    }

    if (nSkillUseState != 0)
    {
        if (nSkillUseState == 1)
        {
            sub_00549A60_SendCantDoThat(pUnit);
        }

        return 2;
    }

    sub_6FC817D0(pGame, pUnit, pUsedSkill, nSkillMode, nX, nY, 0);
    return 0;
}

// build: context PLRMSG_UseSkillOnUnit
static __declspec(noinline) int __stdcall PLRMSG_UseSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nUnitType, int nUnitGUID, int bCheckRange)
{
    if (UNITS_CanDualWield(pUnit))
    {
        pSkill = sub_6FC83450(pSkill, pUnit);
    }

    int nUseState = SKILLS_GetUseState(pUnit, pSkill);
    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    if (nUseState > 0 && (nUseState <= 2 || nUseState == 4) && pSkillsTxtRecord->nFlags[3] & gdwBitMasks[4])
    {
        pSkill = SKILLS_GetSkillById(pUnit, 0, -1);
        nUseState = SKILLS_GetUseState(pUnit, pSkill);
    }

    if (nUseState)
    {
        return 2;
    }

    const int nSkillMode = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
    if (!nSkillMode)
    {
        return 2;
    }

    if (!(pSkillsTxtRecord->nFlags[3] & gdwBitMasks[3]) && (nUnitType < 0 || nUnitType > 1 && nUnitType != 3))
    {
        return 2;
    }

    D2UnitStrc* pOtherUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (pOtherUnit && STATES_CheckState(pOtherUnit, 0x8F))
    {
        D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pOtherUnit);
        if (pOwner)
        {
            nUnitType = pOwner->dwUnitType;
            nUnitGUID = pOwner->dwUnitId;
            pOtherUnit = pOwner;
        }
    }

    if (!bCheckRange || !pOtherUnit)
    {
        StartModeID(pGame, pUnit, pSkill, nSkillMode, nUnitType, nUnitGUID, 0);
        return 0;
    }

    const int nSkillRange = D2Common_11016(pUnit, pSkill);
    if (nSkillRange == 1)
    {
        if (UNITS_IsInMeleeRange(pUnit, pOtherUnit, UNITS_IsInMovingModeEx(pOtherUnit)))
        {
            StartModeID(pGame, pUnit, pSkill, nSkillMode, nUnitType, nUnitGUID, 0);
            return 0;
        }
    }
    else if (nSkillRange != 4)
    {
        StartModeID(pGame, pUnit, pSkill, nSkillMode, nUnitType, nUnitGUID, 0);
        return 0;
    }

    sub_00548A50_ChangeModeAndSetInteract(SKILLS_GetSkillIdFromSkill(pSkill, gszPlrMsgSourceFile, 2013), pGame, pUnit, nUnitType, nUnitGUID);
    return 0;
}

// 0x00549D00
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x05_ShiftLeftClickSkill_6FC832B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    sub_6FC83340(pGame, pUnit, UNITS_GetLeftSkill(pUnit), nX, nY);
    return 0;
}

// 0x00549D80
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x06_LeftSkillOnUnit_6FC83550(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetLeftSkill(pUnit), nUnitType, nUnitGUID, 1);
    return 0;
}

// 0x00549E00
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x07_ShiftLeftSkillOnUnit_6FC83890(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetLeftSkill(pUnit), nUnitType, nUnitGUID, 0);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x08_ShiftLeftSkillHold_6FC83A10(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x05_ShiftLeftClickSkill_6FC832B0(pGame, pUnit, pPacket, nSize);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x09_LeftSkillOnUnitHold_6FC83AC0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x06_LeftSkillOnUnit_6FC83550(pGame, pUnit, pPacket, nSize);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0A_ShiftLeftSkillOnUnitHold_6FC83D40(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x07_ShiftLeftSkillOnUnit_6FC83890(pGame, pUnit, pPacket, nSize);
    return 0;
}

// 0x00549FC0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0C_RightSkill_6FC83EF0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    sub_6FC83340(pGame, pUnit, UNITS_GetRightSkill(pUnit), nX, nY);
    return 0;
}

// 0x0054A040
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0D_RightSkillOnUnit_6FC83F80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetRightSkill(pUnit), nUnitType, nUnitGUID, 1);
    return 0;
}

// 0x0054A0C0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0E_ShiftRightSkillOnUnit_6FC84100(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, 0x148, STATLIST_GetUnitBaseStat(pUnit, 0x148, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetRightSkill(pUnit), nUnitType, nUnitGUID, 0);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0F_RightSkillHold_6FC84280(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = sub_6FC82D10(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x0C_RightSkill_6FC83EF0(pGame, pUnit, pPacket, nSize);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x10_RightSkillOnUnitHold_6FC84330(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x0D_RightSkillOnUnit_6FC83F80(pGame, pUnit, pPacket, nSize);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x11_ShiftRightSkillOnUnitHold_6FC844D0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = sub_00549830_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x0E_ShiftRightSkillOnUnit_6FC84100(pGame, pUnit, pPacket, nSize);
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1A_EquipItem_6FC85280(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const unsigned char nBodyLoc = *((unsigned char*)pPacket + 5);
    if (nSize != 9)
    {
        return 3;
    }

    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    int nItemStatus = 0;
    if (ITEMMODE_EquipCursorItem(pGame, pUnit, nItemGUID, nBodyLoc, 0, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    return 3;
}

// 0x0054B280
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x27_UseItemAction_6FC85B50(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nTargetItemGUID = *(int*)((char*)pPacket + 1);
    const int nUseItemGUID = *(int*)((char*)pPacket + 5);
    int nResult = sub_00549220_CheckOwnedItem(nTargetItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = sub_00549220_CheckOwnedItem(nUseItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_UseItemOnItem(pGame, pUnit, nTargetItemGUID, nUseItemGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B300
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x21_StackItems_6FC85C80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID1 = *(int*)((char*)pPacket + 1);
    const int nItemGUID2 = *(int*)((char*)pPacket + 5);
    int nResult = sub_00549220_CheckOwnedItem(nItemGUID1, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = sub_00549220_CheckOwnedItem(nItemGUID2, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    if (nItemGUID1 == nItemGUID2)
    {
        return 3;
    }

    int nItemStatus;
    if (ITEMMODE_MergeItemStacks(pGame, pUnit, nItemGUID1, nItemGUID2, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x22_UnstackItems_6FC85DA0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nResult = sub_00549220_CheckOwnedItem(nItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus;
    if (D2GAME_Return0_6FC48930(pGame, pUnit, nItemGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B560
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x26_UseBeltItem_6FC86150(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int bUseOnMerc = *(int*)((char*)pPacket + 5);
    const int nX = PLRMSG_GetUnitX(pUnit);
    const int nY = PLRMSG_GetUnitY(pUnit);
    int nResult = pGame->sub_005492F0_CheckBeltItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = sub_6FC83C60(nX, nY, pUnit, 50);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_UseBeltItem(pGame, pUnit, nItemGUID, nX, nY, &nItemStatus, bUseOnMerc) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B710
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x29_ScrollToBook_6FC86450(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nScrollGUID = *(int*)((char*)pPacket + 1);
    const int nBookGUID = *(int*)((char*)pPacket + 5);
    int nResult = sub_6FC86520(nScrollGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = pGame->sub_00549150_CheckStoredItem(pUnit, nBookGUID);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_AddScrollToBook(pGame, pUnit, nScrollGUID, nBookGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B790
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2A_ItemToCubeIndirect_6FC866E0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nCubeGUID = *(int*)((char*)pPacket + 5);
    int nResult = sub_6FC86520(nItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = pGame->sub_00549150_CheckStoredItem(pUnit, nCubeGUID);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_PlaceItemInCube(pGame, pUnit, nItemGUID, nCubeGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// build: context sub_00549410_GetInteractNpc
static int __stdcall sub_00549410_GetInteractNpc(int bCheckRange, D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc** ppNpc, int nNpcGUID)
{
    *ppNpc = SUNIT_GetServerUnit(pGame, 1, nNpcGUID);
    if (!*ppNpc)
    {
        return 1;
    }

    if (!PLRMSG_GetMonInteract(*ppNpc))
    {
        return 3;
    }

    const int nResult = sub_6FC83D00(pUnit, *ppNpc);
    if (nResult)
    {
        return nResult;
    }

    if (!bCheckRange)
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(*ppNpc);
    return sub_6FC83C60(nX, CLIENTS_GetUnitY(*ppNpc), pUnit, 10);
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2F_InitEntityChat_6FC868C0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    D2UnitStrc* pNpc;
    const int nResult = sub_00549410_GetInteractNpc(1, pGame, pUnit, &pNpc, *(int*)((char*)pPacket + 5));
    if (nResult)
    {
        return nResult;
    }

    MONSTERAI_ActivateNpcInteraction(pGame, pUnit, pNpc, PLRMSG_GetMonInteract(pNpc));
    return 0;
}

// 0x0054B9F0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x30_TerminateEntityChat_6FC869F0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    D2UnitStrc* pNpc;
    const int nResult = sub_00549410_GetInteractNpc(0, pGame, pUnit, &pNpc, *(int*)((char*)pPacket + 5));
    if (nResult)
    {
        return nResult;
    }

    MONSTERAI_EndNpcInteraction(pGame, pUnit, pNpc, PLRMSG_GetMonInteract(pNpc));
    return 0;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x38_EntityAction_6FC86CB0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const int nAction = *(int*)((char*)pPacket + 1);
    const int nNpcGUID = *(int*)((char*)pPacket + 5);
    const int nItemGUID = *(int*)((char*)pPacket + 9);
    const int nResult = sub_00548F80_CheckTargetUnit(50, pGame, pUnit, 1, nNpcGUID);
    if (nResult)
    {
        return nResult;
    }

    return NPC_HandleDialogMessage(pGame, pUnit, nAction, nNpcGUID, nItemGUID);
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3D_HighlightADoor_6FC870F0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nObjectGUID = *(int*)((char*)pPacket + 1);
    const int nResult = sub_00548F80_CheckTargetUnit(10, pGame, pUnit, 2, nObjectGUID);
    if (nResult)
    {
        return nResult;
    }

    OBJMODE_UpdateDoorModeFromCollision(pGame, pUnit, nObjectGUID);
    return 0;
}

// 0x0054C380
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x44_StaffInOrifice_6FC87780(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 17)
    {
        return 3;
    }

    const int nObjectGUID = *(int*)((char*)pPacket + 5);
    const int nItemGUID = *(int*)((char*)pPacket + 9);
    const unsigned short nState = *(unsigned short*)((char*)pPacket + 13);
    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 3;
    }

    const int nResult = sub_00549520_CheckOrificeObject(nItemGUID, nState, pGame, pUnit, nObjectGUID);
    if (!nResult)
    {
        OBJMODE_MainObeliskHandler(pGame, !pUnit ? -1 : pUnit->dwUnitId, nObjectGUID, nItemGUID, nState);
    }

    return nResult;
}

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x49_TakeOrCloseWp_6FC87E60(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nWaypointGUID = *(int*)((char*)pPacket + 1);
    const unsigned short nLevelId = *(unsigned short*)((char*)pPacket + 5);
    const unsigned int nTick = PLAYERLIST_GetHostileDelay(pUnit, 0) + 10000;
    if (nTick > GetTickCount())
    {
        SUNIT_AttachSound(pUnit, 19, pUnit);
        SUNIT_ResetInteractInfo(pUnit);
        return 1;
    }

    const int nResult = sub_00549570_CheckWaypointObject(pUnit, pGame, nWaypointGUID, nLevelId);
    if (nResult)
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
        D2UnitStrc* pWaypoint = SUNIT_GetServerUnit(pGame, 2, nWaypointGUID);
        if (pWaypoint && pWaypoint == pInteractUnit)
        {
            SUNIT_ResetInteractInfo(pUnit);
        }

        return nResult;
    }

    sub_00584F60(pGame, pUnit, nWaypointGUID, nLevelId);
    return 0;
}

// 0x00548A80
static __declspec(noinline) int __stdcall sub_6FC83D00(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) == DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pTarget))))
    {
        return 0;
    }

    return 2;
}

inline int sub_00548AC0_GetActMismatchStatus(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
    if (nAct == DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOther))))
    {
        return 0;
    }
    return 2;
}

// 0x00548AC0
int __fastcall sub_00548AC0_IsUnitInOtherAct(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    return sub_00548AC0_GetActMismatchStatus(pUnit, pOther) != 0;
}

// 0x00548EB0
static int __stdcall sub_00548EB0_CompareValues(int nValue, int nExpected)
{
    return nValue == nExpected ? 0 : 3;
}

int __fastcall sub_K10_EmitCompareValues(int a, int b)
{
    return sub_00548EB0_CompareValues(a, b) + sub_00548EB0_CompareValues(b, a + 1);
}

inline int UNITS_GetUnitTypeOrInvalid(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }

    return nType;
}

// 0x00548ED0
int __stdcall sub_00548ED0_SelectBelowSix(unsigned int nValue)
{
    return nValue < 6 ? 0 : 2;
}

// 0x00548EF0
static __declspec(noinline) int __stdcall sub_6FC83C60(unsigned short nX, unsigned short nY, D2UnitStrc* pUnit, int nMaxDistance)
{
    const int nUnitX = PLRMSG_GetUnitX(pUnit);
    const int nUnitY = PLRMSG_GetUnitY(pUnit);

    int nXDiff = nUnitX - nX;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }

    if (nXDiff <= nMaxDistance)
    {
        int nYDiff = nUnitY - nY;
        if (nYDiff < 0)
        {
            nYDiff = -nYDiff;
        }

        if (nYDiff <= nMaxDistance)
        {
            return 0;
        }
    }

    return 1;
}

// 0x00548F80
static __declspec(noinline) int __stdcall sub_00548F80_CheckTargetUnit(int nMaxDistance, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID)
{
    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (!pTarget)
    {
        return 1;
    }

    if (nUnitType == 4 && ITEMS_IsInPlayersInventory(pPlayer, pTarget, 0))
    {
        return 0;
    }

    const unsigned char nPlayerAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer)));
    if (nPlayerAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pTarget))))
    {
        return 2;
    }

    const int nX = PLRMSG_GetUnitX(pTarget);
    return sub_6FC83C60(nX, PLRMSG_GetUnitY(pTarget), pPlayer, nMaxDistance);
}

// 0x00549080
static __forceinline int sub_00549080_CheckLeftSkill(D2UnitStrc* pUnit)
{
    return UNITS_GetLeftSkill(pUnit) ? 0 : 3;
}

// 0x005490A0
static __forceinline int sub_005490A0_CheckRightSkill(D2UnitStrc* pUnit)
{
    return UNITS_GetRightSkill(pUnit) ? 0 : 3;
}

// 0x005490C0
static __forceinline int sub_005490C0_CheckName(const char* szName)
{
    if (!szName[0xFF])
    {
        return SStrChr(szName, -1) ? 2 : 0;
    }
    return 2;
}

// 0x00549290
static __forceinline int sub_00549290_CheckRange1To10(int nValue)
{
    return (unsigned int)(nValue - 1) > 9 ? 2 : 0;
}

// 0x005492A0
static __forceinline int sub_005492A0_CheckBodyLocFree(D2UnitStrc* pUnit, int nBodyLoc)
{
    return INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc) ? 0 : 1;
}

// build: context sub_M114_Emit_00549080
int __stdcall sub_M114_Emit_00549080(D2UnitStrc* pUnit, const char* szName, int a, int b)
{
    return sub_00549080_CheckLeftSkill(pUnit) + sub_005490A0_CheckRightSkill(pUnit) + sub_005490C0_CheckName(szName)
        + sub_00549290_CheckRange1To10(a) + sub_005492A0_CheckBodyLocFree(pUnit, b) + sub_005494E0_CheckSkillLevel(pUnit, a, b);
}

// 0x005492C0
static int __stdcall sub_005492C0_IsHandBodyLocFree(D2UnitStrc* pUnit, int nBodyLoc)
{
    if (nBodyLoc != BODYLOC_RARM && nBodyLoc != BODYLOC_LARM)
    {
        return 3;
    }
    return !INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc);
}

int __fastcall sub_K10_EmitIsHandBodyLocFree(D2UnitStrc* pUnit, int nBodyLoc)
{
    return sub_005492C0_IsHandBodyLocFree(pUnit, nBodyLoc);
}

// 0x00549490
static __declspec(noinline) int sub_00549490_CheckSkillAllocation(D2UnitStrc* pUnit, int nSkillId)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 2;
    }
    if (!D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50(pUnit, nSkillId))
    {
        return 3;
    }
    if (!SKILLS_CheckRequiredSkills(pUnit, nSkillId))
    {
        return 3;
    }
    return SKILLS_CheckRequiredAttributes(pUnit, nSkillId) ? 0 : 3;
}

// 0x005494E0
static __forceinline int sub_005494E0_CheckSkillLevel(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 3;
    }
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
    if (!pSkill)
    {
        return 3;
    }
    return SKILLS_GetSkillLevel(pUnit, pSkill, 1) ? 0 : 3;
}

// 0x0054A290
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x14_HandleOverheadChat_6FC84690(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize < 4 || nSize > 275)
    {
        return 3;
    }

    const int nStringLength = SStrLen((char*)pPacket + 3);
    if (nStringLength <= 0)
    {
        return 0;
    }

    char szText[256];
    SStrCopy(szText, (char*)pPacket + 3, sizeof(szText));
    if (nStringLength >= 256)
    {
        return 2;
    }

    char szName[16];
    SStrCopy(szName, (char*)pPacket + nStringLength + 4, sizeof(szName));

    if (SStrChr(szText, -1))
    {
        return 0;
    }

    if (pUnit && pUnit->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pUnit->pHoverText);
        pUnit->pHoverText = 0;
    }

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(pGame->pMemoryPool, szText, pGame->dwGameFrame);
    if (!pHoverText)
    {
        return 0;
    }

    CHAT_SetLangIdInHoverMsg(pHoverText, *((unsigned char*)pPacket + 2));

    if (pUnit)
    {
        pUnit->pHoverText = pHoverText;
    }

    UNITROOM_RefreshUnit(pUnit);

    if (pUnit)
    {
        pUnit->dwFlags |= 0x100;
    }

    EVENT_SetEvent(pGame, pUnit, 6, D2_MAX(pGame->dwGameFrame + 1, CHAT_GetTimeoutFromHoverMsg(pHoverText)), 0, 0);
    return 0;
}

// 0x0054A420
static int __stdcall sub_0054A420_CheckInteractUnit(D2GameStrc* pGame, D2UnitStrc* pExpected, D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID) && nUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nUnitGUID);
        if (pInteractUnit && pInteractUnit != pExpected)
        {
            return 1;
        }
    }

    return 0;
}

// 0x0054A470
void __fastcall D2GAME_PACKETS_HandlePlayerMessage_6FC847B0(D2ClientStrc* pClient, void* pArgs)
{
    D2GSPacketSrv26Args* pPacket26Args = (D2GSPacketSrv26Args*)pArgs;
    D2GameStrc* pGame = CLIENTS_GetGame(pClient);
    D2GSPacketSrv26* pPacket26 = pPacket26Args->pPacket26;

    if (pPacket26Args->nUnitId != -1)
    {
        D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPacket26Args->nUnitId);
        D2UnitStrc* pLocalPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
        if (pOtherPlayer && pLocalPlayer && pOtherPlayer != pLocalPlayer)
        {
            if (PLAYERLIST_CheckFlag(pLocalPlayer, pOtherPlayer, 4) || PLAYERLIST_CheckFlag(pOtherPlayer, pLocalPlayer, 2)
                || sub_0054A420_CheckInteractUnit(pGame, pLocalPlayer, pOtherPlayer) || sub_0054A420_CheckInteractUnit(pGame, pOtherPlayer, pLocalPlayer))
            {
                return;
            }
        }
    }

    D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(pClient, pPacket26);
}

// 0x0054A5C0
void __fastcall j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, void* pMsg)
{
    D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(pClient, (D2GSPacketSrv26*)pMsg);
}

// 0x0054A930
void __fastcall sub_0054A930_BroadcastMessage(D2GameStrc* game, const char* message, unsigned char color)
{
    D2GSPacketSrv26 packet;
    packet.header = 0x26;
    packet.messageType = 1;
    packet.unitType = 2;
    packet.unitId = 0;
    packet.messageColor = color;
    packet.name[0] = 0;
    packet.language = 0;
    memcpy(packet.message, message, sizeof(packet.message));
    GAME_ForEachIngameClient(game, j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0, &packet);
}

// 0x0054AA30
void __fastcall j_D2GAME_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, void* pPacket)
{
    D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(pClient, (D2GSPacketSrv5A*)pPacket);
}

// 0x0054AAD0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x16_PickItemOnGround_6FC84DB0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const unsigned int nUnitType = *(unsigned int*)((char*)pPacket + 1);
    const int nUnitGUID = *(int*)((char*)pPacket + 5);
    const int nArg = *(int*)((char*)pPacket + 9);
    if (nUnitType >= 6)
    {
        return 2;
    }

    if ((!pUnit ? -1 : pUnit->dwUnitId) != nUnitGUID || nUnitType != 0)
    {
        return sub_6FC828D0(pUnit, nUnitType, nUnitGUID, nArg, pGame);
    }

    return 3;
}

// 0x0054ACD0
int __fastcall sRemoveItemGrid(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    int a6;
    const int nResult = pGame->sub_00549150_CheckStoredItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        sub_00549A60_SendCantDoThat(pUnit);
        return 2;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        return 2;
    }

    if (ITEMS_GetInvPage(pItem) == 1)
    {
        return 3;
    }

    if (sub_6FC7C3A0(pGame, pUnit, pItem))
    {
        a6 = 0;
        if (!sub_6FC446B0(pGame, pUnit, nItemGUID, &a6, 1, 0, 0, 0) && a6)
        {
            return 3;
        }
    }

    return 0;
}

// 0x0054AE30
int __fastcall sInsertItemBodyRmvOpp(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const unsigned char nBodyLoc = *((unsigned char*)pPacket + 5);
    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    int a6 = 0;
    if (sub_6FC45550(pGame, pUnit, nItemGUID, nBodyLoc, 0, &a6) || !a6)
    {
        return 0;
    }

    return 3;
}

// 0x0054B1E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x20_UseGridItem_6FC85990(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    D2GSPacketClt20* pPacket20 = (D2GSPacketClt20*)pPacket;

    if (nSize != 13)
    {
        return 3;
    }

    const int nItemGUID = pPacket20->nItemGUID;
    const int nX = pPacket20->nPosX;
    const int nY = pPacket20->nPosY;
    int nResult = pGame->sub_00549150_CheckStoredItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = sub_6FC83C60(nX, nY, pUnit, 50);
    if (nResult)
    {
        return nResult;
    }

    int a5 = 0;
    if (ITEMMODE_UseStoredItemAtCoordinates(pGame, pUnit, nItemGUID, nX, nY, &a5) || !a5)
    {
        return 0;
    }

    SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    char szName[32];
    D2_MAYBE_UNUSED(szName);
    return 3;
}

// 0x0054B3E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x23_ItemToBelt_6FC85E70(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nBeltSlot = *(int*)((char*)pPacket + 5);
    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    int a6 = 0;
    if (sub_6FC48940(pGame, pUnit, nItemGUID, nBeltSlot, 0, &a6) || !a6)
    {
        return 0;
    }

    return 3;
}

// 0x0054B810
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2C_2D_52_6FC867B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054B820
int __fastcall sub_0054B820_Rcv0x2D(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054BC30
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x37_IdentifyFromGamble_6FC86C30(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    if (!SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID))
    {
        return 2;
    }

    const int nBoughtItemId = UNITS_GetPlayerData(pUnit)->dwBoughtItemId;
    if (nBoughtItemId != nItemGUID)
    {
        return 3;
    }

    D2GAME_NPC_IdentifyBoughtItem_6FCCA990(pGame, pUnit, nItemGUID);
    return 0;
}

// 0x0054BD00
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x39_PurchaseLife_6FC86E50(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054BD90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3B_AddSkillPoint_6FC86EF0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }
    const int nSkillId = ((D2GSPacketClt3B*)pPacket)->nSkill;
    const int nResult = sub_00549490_CheckSkillAllocation(pUnit, nSkillId);
    if (nResult)
    {
        if (nResult == 2)
        {
            D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x114F), pUnit, 0, 1, 0);
        }
        return nResult;
    }
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 0) >= sub_004AA8B0_GetSkillMaxLevel(nSkillId))
    {
        D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x1159), pUnit, 0, 1, 0);
        return 2;
    }
    if (!sub_6FD136E0(pUnit, nSkillId))
    {
        return 2;
    }
    sub_0055F4F0(pGame, pUnit, 1);
    sub_6FD14C30(pUnit);
    return 0;
}

// 0x0054BE70
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3C_SelectSkill_6FC87050(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nValue = *(int*)((char*)pPacket + 1);
    const int nOwnerGUID = *(int*)((char*)pPacket + 5);
    const int bLeftSkill = (unsigned int)nValue >> 31;
    const int nSkillId = nValue & 0x7FFFFFFF;
    if (nSkillId < 0)
    {
        return 3;
    }

    if (nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 3;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
    if (!pSkill)
    {
        return 3;
    }

    if (!SKILLS_GetSkillLevel(pUnit, pSkill, 1))
    {
        return 3;
    }

    D2GAME_AssignSkill_6FD13800(pUnit, bLeftSkill, nSkillId, nOwnerGUID);
    if (bLeftSkill)
    {
        UNITS_InitLeftSkill(pUnit);
    }
    else
    {
        UNITS_InitRightSkill(pUnit);
    }

    return 0;
}

// 0x0054BF60
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3E_ActivateInifussScroll_6FC87270(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (!sub_00557FF0_InventoryContainsItem(pUnit, pItem, 0))
    {
        const unsigned char nUnitAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
        if (nUnitAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pItem))))
        {
            return 2;
        }

        const int nX = PLRMSG_GetUnitX(pItem);
        const int nResult = sub_6FC83C60(nX, PLRMSG_GetUnitY(pItem), pUnit, 10);
        if (nResult)
        {
            return nResult;
        }
    }

    QUESTS_UseClueItem(pGame, pUnit, nItemGUID);
    return 0;
}

// 0x0054C420
int __fastcall sub_0054C420_Rcv0x45Stub(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

static __forceinline int sub_E03_PlrGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int sub_E03_PlrGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0054C430
static __declspec(noinline) int __stdcall sub_0054C430_CommandMerc(int nParam1, int nParam2, int nCommand, D2GameStrc* pGame, D2UnitStrc* pUnit, int nMercGUID)
{
    D2UnitStrc* pMerc = SUNIT_GetServerUnit(pGame, 1, nMercGUID);
    if (!pMerc)
    {
        return 1;
    }

    if (sub_6FC7E8B0(pGame, pUnit, 7, 0) != pMerc)
    {
        return 1;
    }

    AIGENERAL_FreeAllAiCommands(pGame, pMerc);

    D2AiCmdStrc aiCmd;
    aiCmd.nCmdParam[0] = nCommand;
    aiCmd.nCmdParam[1] = nParam1;
    aiCmd.nCmdParam[2] = nParam2;
    AIGENERAL_CopyAiCommand(pGame, pMerc, &aiCmd);

    SUNIT_AttachSound(pMerc, 0xF, pUnit);
    return 0;
}

// 0x0054C4B0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x46_MercInteract_6FC87B00(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const int nMercGUID = *(int*)(pPacket + 1);
    const unsigned int nUnitType = *(unsigned int*)(pPacket + 9);
    const int nItemGUID = *(int*)(pPacket + 5);
    if (nUnitType >= 6)
    {
        return 2;
    }

    const int nResult = sub_00548F80_CheckTargetUnit(50, pGame, pUnit, nUnitType, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    return sub_0054C430_CommandMerc(nItemGUID, nUnitType, 12, pGame, pUnit, nMercGUID);
}

// 0x0054C520
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x47_MoveMerc_6FC87CE0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const int nMercGUID = *(int*)(pPacket + 1);
    const unsigned short nX = *(unsigned short*)(pPacket + 5);
    const unsigned short nY = *(unsigned short*)(pPacket + 9);

    const int nResult = sub_6FC83C60(nX, nY, pUnit, 50);
    if (nResult)
    {
        return nResult;
    }

    sub_0054C430_CommandMerc(nX, nY, 13, pGame, pUnit, nMercGUID);
    return 0;
}

// 0x0054C6D0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4B_RequestEntityUpdate_6FC880F0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const unsigned int nUnitType = *(unsigned int*)((char*)pPacket + 1);
    const int nUnitGUID = *(int*)((char*)pPacket + 5);
    if (nUnitType >= UNIT_TYPES_COUNT)
    {
        return 2;
    }

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (nUnitType == UNIT_PLAYER && pTarget != pUnit)
    {
        return 3;
    }

    if (!pTarget)
    {
        return 1;
    }

    if (!UNITFINDS_AreUnitsInNeighboredRooms(pUnit, pTarget))
    {
        return 1;
    }

    UNITROOM_RefreshUnit(pTarget);
    pTarget->dwFlagEx |= UNITFLAGEX_TELEPORTED;
    return 0;
}

// 0x0054C930
int __fastcall sub_0054C930_Rcv0x52Stub(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054C9C0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x58_QuestCompleted_6FC883B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }

    const int nQuestId = *(unsigned short*)((char*)pPacket + 1);
    if (nQuestId < MAX_QUEST_STATUS)
    {
        D2BitBufferStrc* pQuestData = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestData, nQuestId, QFLAG_UPDATEQUESTLOG);
        return 0;
    }

    return 2;
}

// 0x0054CC30
void __fastcall sub_0054CC30_ClearState(D2UnitStrc* unit, int state, int unused)
{
    STATES_ToggleState(unit, state, 0);
}

static __forceinline int UNITS_GetAnimMode_H15(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwAnimMode : 0;
}

// 0x0054CED0
static int __stdcall sub_0054CED0_EquipMercItem(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2GameStrc* pGame, D2UnitStrc* pMerc)
{
    if (!pGame->bExpansion)
    {
        return 3;
    }

    D2InventoryStrc* pPlayerInventory = pPlayer->pInventory;
    if (!pPlayerInventory)
    {
        return 0;
    }

    if (!pMerc->pInventory)
    {
        INVENTORY_AllocInventory(0, pMerc);
    }

    D2InventoryStrc* pMercInventory = pMerc->pInventory;
    if (!pMercInventory)
    {
        return 0;
    }

    unsigned char nBodyLoc2;
    unsigned char nBodyLoc1;
    ITEMS_GetAllowedBodyLocations(pItem, &nBodyLoc1, &nBodyLoc2);

    D2UnitStrc* pItem1 = INVENTORY_GetItemFromBodyLoc(pMercInventory, nBodyLoc1);
    D2UnitStrc* pItem2 = INVENTORY_GetItemFromBodyLoc(pMercInventory, nBodyLoc2);

    D2UnitStrc* pExchangeItem;
    int nTargetBodyLoc;
    if (pMerc->dwClassId == 0x167 && ITEMSIsA(pItem, 2))
    {
        pExchangeItem = pItem2;
        nTargetBodyLoc = nBodyLoc2;
    }
    else
    {
        pExchangeItem = pItem1;
        nTargetBodyLoc = nBodyLoc1;
    }

    if (pExchangeItem)
    {
        if (pExchangeItem != INVENTORY_RemoveItemFromInventory(pMercInventory, pExchangeItem))
        {
            return 0;
        }

        sub_0063BE30(pMercInventory, nTargetBodyLoc);
        D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pExchangeItem, pMerc, 0, 0);
        D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pMerc, 0, 0);

        if (!ITEMS_CheckRequirements(pItem, pMerc, 0, 0, 0, 0))
        {
            sub_0063BDB0(pMercInventory, pExchangeItem, nTargetBodyLoc);
            INVENTORY_PlaceItemInSocket(pMercInventory, pExchangeItem, 3);
            ITEMS_SetBodyLocation(pExchangeItem, nTargetBodyLoc);
            UNITS_ChangeAnimMode(pExchangeItem, 1);
            ITEMS_SetInvPage(pExchangeItem, 0xFF);
            sub_0055C460_UpdateItemStatlist(pGame, pExchangeItem, pMerc, 0);
            sub_0055F4F0(pGame, pMerc, 0);
            return 0;
        }

        ITEMS_SetItemCMDFlag(pExchangeItem, 0x10, 1);
        INVENTORY_AddItemToTradeInventory(pMercInventory, pExchangeItem);
        ITEMS_SetItemFlag(pExchangeItem, 0x20, 1);
        UNITS_RefreshInventory(pMerc, 1);
    }

    D2UnitStrc* pDupeItem = ITEMS_Duplicate(pGame, pItem, pMerc, 1);
    UNITS_ChangeAnimMode(pDupeItem, 4);

    const int nItemGUID = pItem->dwUnitId;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pMerc, 9, nItemGUID);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, 9, nItemGUID);

    int nUnused;
    ITEMMODE_EquipCursorItem(pGame, pMerc, !pDupeItem ? -1 : pDupeItem->dwUnitId, nTargetBodyLoc, 1, &nUnused);

    D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pItem);
    INVENTORY_SetCursorItem(pPlayerInventory, 0);

    if (pExchangeItem)
    {
        D2UnitStrc* pCursorItem = ITEMS_Duplicate(pGame, pExchangeItem, pPlayer, 1);
        INVENTORY_SetCursorItem(pPlayerInventory, pCursorItem);
        sub_6FC4B9D0(pGame, pPlayer, pCursorItem);
    }

    D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pMerc, 0, 0);
    sub_0055F4F0(pGame, pMerc, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pMerc, 3, 0);
    EVENT_SetEvent(pGame, pMerc, 3, pGame->dwGameFrame + 1, 0, 0);
    return 1;
}

static __forceinline int sub_RemoveEquippedItem(D2UnitStrc* pMerc, D2UnitStrc* pItem)
{
    return pItem && (!pItem ? -1 : pItem->dwAnimMode) == 1 && pItem == INVENTORY_RemoveItemFromInventory(pMerc->pInventory, pItem);
}

// 0x0054D130
static int __stdcall sub_0054D130_TakeMercItemToCursor(D2GameStrc* pGame, D2UnitStrc* pMerc, D2UnitStrc* pPlayer, int nBodyLoc)
{
    D2InventoryStrc* pPlayerInventory = pPlayer->pInventory;
    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (!pMerc->pInventory || nBodyLoc < 1 || nBodyLoc > 10)
    {
        return 3;
    }

    D2UnitStrc* pItem = sub_0063BDE0(pMerc->pInventory, nBodyLoc);
    if (!sub_RemoveEquippedItem(pMerc, pItem))
    {
        return 2;
    }

    sub_0063BE30_Return(pMerc->pInventory, nBodyLoc);
    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pMerc, 0, 0);
    ITEMS_SetItemCMDFlag(pItem, 16, 1);
    INVENTORY_AddItemToTradeInventory(pMerc->pInventory, pItem);
    UNITS_RefreshInventory(pMerc, 1);

    D2UnitStrc* pCursorItem = ITEMS_Duplicate(pGame, pItem, pPlayer, 1);
    INVENTORY_SetCursorItem(pPlayerInventory, pCursorItem);
    sub_6FC4B9D0(pGame, pPlayer, pCursorItem);
    ITEMS_SetItemFlag(pItem, 0x20, 1);
    sub_0055DF00_RecalcItemStates(pGame, pMerc, 0, 0);
    sub_0055F500_RefreshItemStatLists(pGame, pMerc);
    sub_0055F4F0(pGame, pMerc, 0);
    return 0;
}

// build: context sub_0054D130_UnequipMercItem
static int __stdcall sub_0054D130_UnequipMercItem(D2UnitStrc* pPlayer, int nBodyLoc, D2GameStrc* pGame, D2UnitStrc* pMerc)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (!pMerc->pInventory)
    {
        return 3;
    }

    if (nBodyLoc <= 0 || nBodyLoc >= 11)
    {
        return 3;
    }

    D2UnitStrc* pEquippedItem = INVENTORY_GetItemFromBodyLoc(pMerc->pInventory, nBodyLoc);
    if (!pEquippedItem || UNITS_GetAnimMode_H15(pEquippedItem) != 1 || pEquippedItem != INVENTORY_RemoveItemFromInventory(pMerc->pInventory, pEquippedItem))
    {
        return 2;
    }

    {
        sub_0063BE30(pMerc->pInventory, nBodyLoc);
        D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pEquippedItem, pMerc, 0, 0);
        ITEMS_SetItemCMDFlag(pEquippedItem, 0x10, 1);
        INVENTORY_AddItemToTradeInventory(pMerc->pInventory, pEquippedItem);
        UNITS_RefreshInventory(pMerc, 1);
        D2UnitStrc* pCursorItem = ITEMS_Duplicate(pGame, pEquippedItem, pPlayer, 1);
        INVENTORY_SetCursorItem(pInventory, pCursorItem);
        sub_6FC4B9D0(pGame, pPlayer, pCursorItem);
        ITEMS_SetItemFlag(pEquippedItem, 0x20, 1);
        D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pMerc, 0, 0);
        D2GAME_UpdatePlayerVitals_6FC4B240(pGame, pMerc);
        sub_0055F4F0(pGame, pMerc, 0);
        return 0;
    }
}

// build: context sub_0054D230_TryEquipMercItem
static int __stdcall sub_0054D230_TryEquipMercItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x1728, ".\\PLAYER\\PlrMsg.cpp") || ITEMS_CheckItemFlag(pItem, 0x100, 0x172B, ".\\PLAYER\\PlrMsg.cpp"))
    {
        return 0;
    }

    if (ITEMSIsA(pItem, 0x4C) || ITEMSIsA(pItem, 0x51) || ITEMSIsA(pItem, 0x50))
    {
        SKILLITEM_pSpell_Handler(pGame, pMerc, pItem, pItem, 0, 0);
        D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pItem);
        INVENTORY_SetCursorItem(pInventory, 0);
        return 1;
    }

    int bCanBeEquipped = 0;
    if (ITEMSIsA(pItem, 3) || ITEMSIsA(pItem, 0x25))
    {
        bCanBeEquipped = 1;
    }

    switch (!pMerc ? -1 : pMerc->dwClassId)
    {
    case 0x10F:
        if (ITEMSIsA(pItem, 0x1B))
        {
            bCanBeEquipped = 1;
        }
        break;

    case 0x152:
        if (ITEMSIsA(pItem, 0x21) || ITEMSIsA(pItem, 0x22))
        {
            bCanBeEquipped = 1;
        }
        break;

    case 0x167:
        if (ITEMSIsA(pItem, 2) || ITEMSIsA(pItem, 0x1E) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bCanBeEquipped = 1;
        }
        break;

    case 0x230:
        if (ITEMSIsA(pItem, 0x1C) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bCanBeEquipped = 1;
        }
        if (ITEMSIsA(pItem, 0x47))
        {
            bCanBeEquipped = 1;
        }
        break;

    case 0x231:
        if (ITEMSIsA(pItem, 0x1E))
        {
            bCanBeEquipped = 1;
        }
        if (ITEMSIsA(pItem, 0x47))
        {
            bCanBeEquipped = 1;
        }
        break;
    }

    if (!bCanBeEquipped || !ITEMS_CheckRequirements(pItem, pMerc, 0, 0, 0, 0))
    {
        SUNIT_AttachSound(pMerc, 0x55, pPlayer);
        return 0;
    }

    if (sub_0054CED0_EquipMercItem(pPlayer, pItem, pGame, pMerc))
    {
        SUNIT_AttachSound(pMerc, 0x57, pPlayer);
        return 1;
    }

    SUNIT_AttachSound(pMerc, 0x56, pPlayer);
    return 0;
}

// 0x0054D430
int __fastcall sub_0054D430(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }

    if (!pGame->bExpansion)
    {
        return 3;
    }

    const unsigned short nBodyLoc = *(unsigned short*)((char*)pPacket + 1);

    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 3;
    }

    if (UNITS_GetUsedSkill(pUnit))
    {
        return 0;
    }

    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    D2UnitStrc* pMerc = sub_6FC7E8B0(pGame, pUnit, 7, 0);
    if (!pMerc)
    {
        return 0;
    }

    if (SUNIT_IsDead(pMerc))
    {
        return 0;
    }

    if (!UNITFINDS_AreUnitsInNeighboredRooms(pMerc, pUnit))
    {
        return 0;
    }

    if (!pUnit->pInventory)
    {
        return 3;
    }

    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pUnit->pInventory);
    if (!pItem)
    {
        if (nBodyLoc <= 0)
        {
            return 0;
        }
        return sub_0054D130_UnequipMercItem(pUnit, nBodyLoc, pGame, pMerc);
    }

    if (ITEMS_IsQuestItem(pItem))
    {
        return 0;
    }

    sub_0054D230_TryEquipMercItem(pGame, pUnit, pMerc, pItem);
    return 0;
}

// 0x0054D520
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x63_ShiftLeftClickItemToBelt_6FC88F80(D2GameStrc* ptGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);

    const int nResult = ptGame->sub_00549150_CheckStoredItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        sub_00549A60_SendCantDoThat(pUnit);
        return 2;
    }

    D2UnitStrc* hItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!hItem)
    {
        return 2;
    }

    if (!ITEMS_CheckIfBeltable(hItem))
    {
        return 2;
    }

    if (ITEMS_GetInvPage(hItem))
    {
        return 3;
    }

    unsigned char nPage;
    int nFreeSlotId = 0;
    if (INVENTORY_GetFreeBeltSlot(pUnit->pInventory, hItem, &nFreeSlotId) && nFreeSlotId >= 0 && sub_6FC7C3A0(ptGame, pUnit, hItem))
    {
        D2InventoryStrc* hInventory = pUnit->pInventory;
        D2_ASSERT(hInventory, 0x1821);

        if (ITEMS_GetInvPage(hItem) || hItem->dwAnimMode != 0)
        {
            return 2;
        }

        D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(hInventory, hItem);
        D2_ASSERT(hRemove, 0x182A);
        D2_ASSERT(hItem == hRemove, 0x182B);

        nPage = ITEMS_GetInvPage(hItem);
        const int nInventoryRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, ptGame->bExpansion);
        INVENTORY_Return(".\\PLAYER\\PlrMsg.cpp", 0x1830, hInventory, CLIENTS_GetUnitX(hItem), CLIENTS_GetUnitY(hItem), nInventoryRecordId, 0, nPage);
        ITEMS_SetItemCell(hItem, nPage);
        ITEMS_SetInvPage(hItem, 0xFF);

        D2GAME_UpdateClientItem_6FC3E9D0(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x1834), pUnit, hItem, 0);

        UNITS_ChangeAnimMode(hItem, 4);

        hItem->dwFlags &= ~2u;

        unsigned char nWidth;
        unsigned char nHeight;
        ITEMS_GetDimensions(hItem, &nWidth, &nHeight, ".\\PLAYER\\PlrMsg.cpp", 0x183B);

        if (INVENTORY_PlaceItemInBeltSlot(hInventory, hItem, nFreeSlotId))
        {
            ITEMS_SetInvPage(hItem, 0xFF);

            if (INVENTORY_PlaceItemInSocket(hInventory, hItem, 2))
            {
                UNITS_ChangeAnimMode(hItem, 2);
                D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x1842), pUnit, hItem, 0);
            }
        }

        UNITS_RefreshInventory(pUnit, 1);
    }

    return 0;
}

// 0x0054D8A0
void __fastcall D2GAME_PLRMSG_Last_6FC89450(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    const bool bDefenderIsPlayer = pDefender && pDefender->dwUnitType == 0;
    D2_ASSERT(bDefenderIsPlayer, 0x19B4);

    if (pAttacker && pAttacker->dwUnitType == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
        if (pOwner && pOwner->dwUnitType == 0)
        {
            pAttacker = pOwner;
        }
    }

    D2GSPacketSrv5A packet5A = {};
    packet5A.nHeader = 0x5A;
    packet5A.nType = 6;
    packet5A.nColor = 4;
    const int nClassId = !pAttacker ? -1 : pAttacker->dwClassId;
    packet5A.dwParam = nClassId;
    packet5A.nParam = UNITS_GetUnitTypeOrInvalid(pAttacker);
    packet5A.szText[16] = 0;

    const char* szDefenderName = CLIENTS_GetName(UnitGetClient(pDefender, ".\\PLAYER\\PlrMsg.cpp", 0x19C9));
    if (SStrLen(szDefenderName))
    {
        SStrCopy(packet5A.szText, szDefenderName, 16);
    }
    else
    {
        packet5A.szText[0] = 0;
    }

    switch (UNITS_GetUnitTypeOrInvalid(pAttacker))
    {
    case 0:
    {
        char szName[16];
        SStrCopy(szName, CLIENTS_GetName(UnitGetClient(pAttacker, ".\\PLAYER\\PlrMsg.cpp", 0x19DB)), 16);
        if (SStrLen(szName))
        {
            SStrCopy(&packet5A.szText[16], szName, 16);
        }
        break;
    }
    case 1:
        if (MONSTERUNIQUE_CheckMonTypeFlag(pAttacker, 2))
        {
            *(unsigned short*)&packet5A.szText[16] = MONSTERUNIQUE_GetBossHcIdx(pAttacker);
        }
        break;
    }

    sub_6FC84D40(pGame, &packet5A);
}

int __fastcall sub_Emit_0054D130(D2GameStrc* pGame, D2UnitStrc* pMerc, D2UnitStrc* pPlayer, int nBodyLoc)
{
    return sub_0054D130_TakeMercItemToCursor(pGame, pMerc, pPlayer, nBodyLoc);
}
