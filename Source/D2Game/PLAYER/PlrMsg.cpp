#include "D2ObjectIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Constants.h"
#include "D2GameStrc.h"
#include "D2PlayerModes.h"
#include "D2ItemModes.h"

struct D2ClientStrc;

struct D2InventoryStrc;

#define UNIT_OBJECT 2

#define UNIT_MISSILE 3

#define UNIT_TILE 5

#define UNIT_TYPES_COUNT 6

#define UNIT_ITEM 4

#define MAX_QUEST_STATUS 42

#define QFLAG_UPDATEQUESTLOG 12

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

// Item-location checks of the game object (defined with the quest code); called with the game in ECX.
struct D2GameItemChecks
{
    int sub_005490E0_CheckCursorItem(D2UnitStrc* pUnit, int nItemGUID); // 0x005490E0
    int sub_00549150_CheckStoredItem(D2UnitStrc* pUnit, int nItemGUID); // 0x00549150
    int sub_005491B0_CheckStoredOrEquippedItem(D2UnitStrc* pUnit, int nItemGUID); // 0x005491B0
    int sub_005492F0_CheckBeltItem(D2UnitStrc* pUnit, int nItemGUID); // 0x005492F0
};

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

int __fastcall ITEMMODE_ReplaceOppositeHandItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* a6); // 0x00563D20

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

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" const char gszPlrMsgSourceFile[]; // 0x006E1050

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit); // 0x00535E80

void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7); // 0x0053BC10

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __fastcall QUESTS_UseClueItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID); // 0x00544840

D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00547F50

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00

void __fastcall SUNIT_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTile);

int __fastcall sub_00557FF0_InventoryContainsItem(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2InventoryStrc* pOtherInventory); // 0x00557FF0

unsigned int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B6C0

void __fastcall D2GAME_PickupItemEx_6FC42B80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x0055CF50

int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nX, int nY, int* pItemStatus); // 0x0055E170

int __fastcall ITEMMODE_MergeItemStacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID1, int nItemGUID2, int* pItemStatus); // 0x0055E7C0

int __fastcall D2GAME_Return0_6FC48930(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x0055E9A0

int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus); // 0x0055EF20

int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0

int __fastcall ITEMMODE_UseItemOnItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetGUID, int nUseItemGUID, int* pItemStatus); // 0x00561ED0

int __fastcall ITEMMODE_UseBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nX, int nY, int* pItemStatus, int bUseOnMerc); // 0x00562390

int __fastcall ITEMMODE_PlaceItemInCube(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nCubeGUID, int* pItemStatus); // 0x005628C0

int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x00563560

void __fastcall PLRTRADE_TryToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x00566E60

int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678A0

void __fastcall MONSTERAI_ActivateNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract);

void __fastcall MONSTERAI_EndNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract);

void __fastcall MONSTERAI_StartNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonsterInteractStrc* pMonInteract, char nQuestFlags); // 0x00573020

int __fastcall NPC_HandleDialogMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nType, int nNpcGUID, int nItemGUID); // 0x00579D60

void __fastcall sub_0057FB70_PickUpCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody); // 0x0057FB70

void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0

void __fastcall StartModeID(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70

int __fastcall OBJMODE_OperateObjectInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectType, int nObjectGUID);

void __fastcall OBJMODE_UpdateDoorModeFromCollision(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID);

void __fastcall sub_00584F60(D2GameStrc* pGame, D2UnitStrc* pUnit, int nWaypointGUID, int nLevelId);

int __fastcall OBJMODE_MainObeliskHandler(D2GameStrc* pGame, int nPlayerGUID, int nObjectGUID, int nItemGUID, short nState); // 0x005852E0

void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue); // 0x0058EC00

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall sub_00622B50_TestInteractCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMask);

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40

int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit); // 0x00622DC0

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject);

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem);

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD50

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);

void __fastcall sub_00641F20_SetPlayerModeState(D2UnitStrc* pUnit, int nMode, int nArg1, int nArg2); // 0x00641F20

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00643860

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140

int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill); // 0x00644530

void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620

int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00645460

int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00647960

void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath); // 0x00648730

int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo); // 0x00660E00

int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField); // 0x00660E50

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

void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nSkillId, unsigned char nSkillLevel, unsigned char bRemove); // 0x0053C4A0

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

struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nMessageType;
    unsigned char nLang;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessageColor;
    unsigned char nNameColor;
    char szName[16];
    char szMessage[256];
};

void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket); // 0x0053C750

int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pInteractUnitType, int* pInteractUnitGUID); // 0x00554100

int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300

typedef void (__fastcall *ClientCallback)(D2ClientStrc*, void*);

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

void __fastcall GAME_ForEachIngameClient(D2GameStrc*, ClientCallback, void*); // 0x0052DED0

void __fastcall j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc*, void*); // 0x0054A5C0

void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket); // 0x0053C850

void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0

D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0

void __fastcall AIGENERAL_FreeAllAiCommands(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058EDE0

void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40

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

static int __stdcall sub_6FC83D00(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00548A80

static int __stdcall sub_6FC83C60(unsigned short nX, unsigned short nY, D2UnitStrc* pUnit, int nMaxDistance); // 0x00548EF0

static int __stdcall sub_00548F80_CheckTargetUnit(int nMaxDistance, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID);

#pragma pack(push, 1)
struct D2GSPacketClt20
{
    unsigned char nHeader;
    int nItemGUID;
    int nPosX;
    int nPosY;
};
#pragma pack(pop)

static inline int sub_005494E0_CheckSkillLevel(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);

D2UnitStrc* __stdcall sub_0063BDE0(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall sub_0063BE30_Return(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30

void __fastcall sub_0055DF00_RecalcItemStates(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4); // 0x0055DF00

void __fastcall sub_0055F500_RefreshItemStatLists(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0055F500

static int __stdcall sub_0054D130_TakeMercItemToCursor(D2GameStrc* pGame, D2UnitStrc* pMerc, D2UnitStrc* pPlayer, int nBodyLoc);


struct D2BuyItemPacketStrc;

int __stdcall sub_00626090(D2StatListStrc* pStatList); // 0x00626090

static unsigned char sub_005485B0_GetPoisonedLifePercent(D2UnitStrc* pUnit);

void __fastcall sub_005550B0_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTile); // 0x005550B0

int __stdcall sub_0055E9A0(int nUnused1, int nUnused2); // 0x0055E9A0

void __fastcall sub_6FC61AB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract); // 0x00572E60

void __fastcall sub_6FC61B70(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract); // 0x00572F20

int __fastcall sub_6FC78B20(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nObjectType, int nObjectGUID); // 0x00584540

void __fastcall sub_005845D0_UpdateDoorCollisionMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID); // 0x005845D0

void __fastcall OBJMODE_TravelViaWaypoint(D2GameStrc* pGame, D2UnitStrc* pUnit, int nWaypointGUID, int nLevelId); // 0x00584F60

int __stdcall sub_00622B50_IsRayFreeBetweenUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask); // 0x00622B50

int __stdcall sub_00623660_IsInObjectInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00623660

int __stdcall sub_00641530(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00641530

static void __stdcall sub_00548A50_ChangeModeAndSetInteract(int nInteractSkill, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID);


void __fastcall j_D2GAME_SendPacket0x5A_6FC3DEC0(D2ClientStrc*, void*); // 0x0054AA30

int __fastcall sub_00561220_SwapDualWieldedItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int* pFailure); // 0x00561220

#pragma pack(push, 1)
struct D2BuyItemPacketStrc
{
    unsigned char nHeader;
    int nNpcUnitId;
    int nItemId;
    unsigned int nTransactionType;
    int nCost;
};
#pragma pack(pop)

int __fastcall D2GAME_NPC_BuyItemHandler_6FCC92A0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId, int nItemId, int nItemMode, int nTransactionType, int nCost, int bMultibuy); // 0x00577F30

#define PLRMODE_WALK 2

#define PLRMODE_RUN 3

#define PLRMODE_DEAD 17

#define BODYLOC_BELT 8

#define EVENTTYPE_AITHINK 2

#define EVENTTYPE_PLAYERLEFT 3

#define CLIENTSAVEFLAG_HARDCORE 4

#define UNITFLAG_TARGETABLE 2

#define MONSTATSFLAGINDEX_NPC 8

#define MONSTATSFLAGINDEX_INTERACT 9

static int __stdcall PLRMSG_UseSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nUnitType, int nUnitGUID, int bCheckRange); // 0x00549BA0

int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590

void __fastcall SrvDisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType); // 0x0052CAF0

int __fastcall sub_6FC7C260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, int nValue); // 0x00535510

int __fastcall sub_6FC7C450(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nHotkeyId, short nSkillId, int nHand, int nFlags); // 0x005356B0

int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag); // 0x00538670

void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0

int __fastcall ARENA_IsActive(D2GameStrc* pGame); // 0x0053FD10

int __fastcall ARENA_Return0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0053FDF0

void __fastcall sub_6FC82010(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode); // 0x00548350

void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520

int __fastcall sub_6FC48D50(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCursorItemGUID, int nBeltItemGUID, int* a5); // 0x0055EB30

int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200

int __fastcall ITEMMODE_UnequipBodyItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, unsigned char nBodyLoc, int bSetQuantityFlag, int* pItemStatus); // 0x00560CD0

int __fastcall ITEMMODE_SwapCursorAndBodyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* a6); // 0x00560F00

int __fastcall sub_005616A0_SwapWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit, int* a3); // 0x005616A0

int __fastcall sub_6FC48B40(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4); // 0x00562250

int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9); // 0x00562660

int __fastcall sub_6FC93740(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00567840

void __fastcall sub_6FD11AE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0056C6A0

void __fastcall D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc* pUnit); // 0x0056DFA0

int __fastcall PLAYERSTATS_SpendStatPoint(D2UnitStrc* pUnit, int nStatId); // 0x00570D60

int __fastcall PARTYSCREEN_CommandHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCommand, int nArg, int nArg2); // 0x005A6000

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70

int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0

static int __stdcall sub_6FC83D00(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00548A80

int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x05_ShiftLeftClickSkill_6FC832B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549D00

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x06_LeftSkillOnUnit_6FC83550(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549D80

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x07_ShiftLeftSkillOnUnit_6FC83890(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549E00

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0C_RightSkill_6FC83EF0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549FC0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0D_RightSkillOnUnit_6FC83F80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054A040

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0E_ShiftRightSkillOnUnit_6FC84100(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054A0C0

struct D2GSPacketClt15 { unsigned char nHeader; unsigned char nType; unsigned char nColor; char szMessage[256]; char szName[16]; };

typedef void (__fastcall* D2ClientCallback)(D2ClientStrc*, void*);

extern "C" void* __cdecl memset(void*, int, unsigned int);

extern int gbWhispTextNotListening_6FD4DC24; // 0x008846E0

extern int gbWhispTextInGame_6FD4DC20; // 0x008846E4

void __fastcall D2GAME_PACKETS_HandlePlayerMessage_6FC847B0(D2ClientStrc*, void*); // 0x0054A470

void __fastcall D2GAME_PACKETS_HandleWhisper_6FC848A0(D2ClientStrc*, void*); // 0x0054A510

#define EVENTTYPE_CANTDOTHAT 14

#define STRCOLOR_RED 1

union D2SeedStrc;

struct D2GSPacketClt5F;

struct D2WarpDelayStrc;

typedef void(__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc* pClient, void* pContext);

void __fastcall QUESTS_NPCMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwNPCGUID, unsigned short nMessage); // 0x005443B0

void __fastcall QUESTS_StatusCallback(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00546040

int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130

void __fastcall D2GAME_NPC_HireMerc_6FCC9540(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId, int a4); // 0x00577FE0

int __fastcall D2GAME_NPC_Repair_6FCC95B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcGUID, int nItemGUID, unsigned short nUnused, int a6); // 0x00578050

int __fastcall D2GAME_STORES_SellItem_6FCC7680(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID, int nItemGUID, unsigned short nItemMode, int a6); // 0x00579510

#pragma pack(push, 1)
struct D2GSPacketClt5F
{
    unsigned char nHeader;
    unsigned short nX;
    unsigned short nY;
};
#pragma pack(pop)

struct D2WarpDelayStrc
{
    int nChance;
    int nDelay;
};


extern const D2WarpDelayStrc gWarpDelays_006E1064[3]; // 0x006E1064

void __fastcall CLIENTS_NotifyWarpAttempt(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00539360

int __fastcall CLIENTS_ShouldDelayWarpAttempt(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005393F0

void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0

int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

extern "C" void __stdcall sub_006252D0(D2StatListStrc* pStatList, unsigned int dwValue); // 0x006252D0

extern "C" void __stdcall sub_00625CE0(D2StatListStrc* pStatList, unsigned int dwValue); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

int __stdcall sub_006417F0_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0

extern "C" unsigned int __stdcall sub_00648A40(D2DynamicPathStrc* pPath); // 0x00648A40

extern "C" unsigned int __stdcall sub_00648A60(D2DynamicPathStrc* pPath); // 0x00648A60

extern "C" void __stdcall sub_00648AD0(D2DynamicPathStrc* pPath, unsigned short wX, unsigned short wY); // 0x00648AD0

extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

extern "C" unsigned int __stdcall sub_00648CD0(D2DynamicPathStrc* pPath); // 0x00648CD0

void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask); // 0x00648CE0

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0

int __stdcall PATH_GetType(D2DynamicPathStrc* pDynamicPath); // 0x00648E30

extern "C" void __stdcall sub_00648E70_SetDistance(D2DynamicPathStrc* pPath, unsigned char nDistance); // 0x00648E70

unsigned char __stdcall PATH_GetMaxDistance(D2DynamicPathStrc* pDynamicPath); // 0x00648EA0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

void __fastcall sub_0054CC30_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2PacketTableStrc;

static int __stdcall sub_00549570_CheckWaypointObject(D2GameStrc* pGame, unsigned short nLevelId, D2UnitStrc* pUnit, int nObjectGUID);

typedef int (__fastcall* PacketCallback)(D2GameStrc*,D2UnitStrc*,unsigned char*,int);

struct D2PacketTableStrc { PacketCallback pfCallback; int nSize; };

extern D2PacketTableStrc sgcptIncomingMessageChart[]; // 0x006E0D18

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*); // 0x006CC34C

int __fastcall sub_0057EEC0(D2GameStrc*,D2UnitStrc*,int,int,D2SkillStrc*); // 0x0057EEC0

#define D2_MAYBE_UNUSED(x) (void)(x)

int __fastcall sub_6FC46D40(D2GameStrc*, D2UnitStrc*, int, int, int, int, int*); // 0x00561B00

#pragma pack(push, 1)
struct D2GSPacketClt1F
{
    unsigned char nHeader;
    int nCursorItemGUID;
    int nInventoryItemGUID;
    int nPosX;
    int nPosY;
};
#pragma pack(pop)

static int __stdcall sub_00549570_CheckWaypointObject(D2GameStrc* pGame, unsigned short nLevelId, D2UnitStrc* pUnit, int nObjectGUID);

static int __stdcall sub_00549220_CheckOwnedItem(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pUnit);

static int __stdcall sub_6FC86520(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pPlayer);

static int __stdcall sub_00549520_CheckOrificeObject(int nItemGUID, unsigned short nState, D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID);

static int __stdcall sub_00549570_CheckWaypointObject(D2GameStrc* pGame, unsigned short nLevelId, D2UnitStrc* pUnit, int nObjectGUID);

static int __stdcall sub_6FC82D10(D2GameStrc* pGame, int nPacketSize, unsigned short* pX, unsigned short* pY, D2UnitStrc* pUnit, void* pPacket);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x01_Walk_6FC82CB0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

static int __stdcall sub_00549830_ReadTargetUnitPacket(D2GameStrc* pGame, int nPacketSize, int* pUnitType, int* pUnitGUID, D2UnitStrc* pUnit, void* pPacket);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x02_WalkToEntity_6FC82ED0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x03_Run_6FC83090(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x04_RunToEntity_6FC830F0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

static D2SkillStrc* __stdcall sub_6FC83450(D2SkillStrc* pSkill, D2UnitStrc* pUnit);

static int __stdcall sub_6FC83340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY);

static int __stdcall PLRMSG_UseSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nUnitType, int nUnitGUID, int bCheckRange); // 0x00549BA0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x05_ShiftLeftClickSkill_6FC832B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549D00

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x06_LeftSkillOnUnit_6FC83550(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549D80

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x07_ShiftLeftSkillOnUnit_6FC83890(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549E00

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x08_ShiftLeftSkillHold_6FC83A10(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x09_LeftSkillOnUnitHold_6FC83AC0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0A_ShiftLeftSkillOnUnitHold_6FC83D40(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0C_RightSkill_6FC83EF0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549FC0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0D_RightSkillOnUnit_6FC83F80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054A040

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0E_ShiftRightSkillOnUnit_6FC84100(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054A0C0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0F_RightSkillHold_6FC84280(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x10_RightSkillOnUnitHold_6FC84330(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x11_ShiftRightSkillOnUnitHold_6FC844D0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1A_EquipItem_6FC85280(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x27_UseItemAction_6FC85B50(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x21_StackItems_6FC85C80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x22_UnstackItems_6FC85DA0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x26_UseBeltItem_6FC86150(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x29_ScrollToBook_6FC86450(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2A_ItemToCubeIndirect_6FC866E0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

static int __stdcall sub_00549410_GetInteractNpc(int bCheckRange, D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc** ppNpc, int nNpcGUID);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2F_InitEntityChat_6FC868C0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x30_TerminateEntityChat_6FC869F0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x38_EntityAction_6FC86CB0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3D_HighlightADoor_6FC870F0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x44_StaffInOrifice_6FC87780(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x49_TakeOrCloseWp_6FC87E60(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

static void __stdcall sub_00548A50_ChangeModeAndSetInteract(int nInteractSkill, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID);

static int __stdcall sub_6FC83C60(unsigned short nX, unsigned short nY, D2UnitStrc* pUnit, int nMaxDistance); // 0x00548EF0

static int __stdcall sub_00548F80_CheckTargetUnit(int nMaxDistance, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID);

int gbWhispReceiverNotListening_6FD4DC24; // 0x008846E0

int gbWhispReceiverInGame_6FD4DC20; // 0x008846E4

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x49_TakeOrCloseWp_6FC87E60(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x20_UseGridItem_6FC85990(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3E_ActivateInifussScroll_6FC87270(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

static int __stdcall sub_0054CED0_EquipMercItem(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2GameStrc* pGame, D2UnitStrc* pMerc);

static int __stdcall sub_0054D230_TryEquipMercItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, D2UnitStrc* pItem);

int __fastcall sub_0054D430(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);

void __fastcall D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(D2ClientStrc* pClient, unsigned short nStatId, unsigned int nValue); // 0x0053BE40

void __fastcall sub_6FC3D830(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, unsigned short nStatId, int nValue); // 0x0053C1D0

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

// build: context PoisonStat_GetPerFrame
static inline int PoisonStat_GetPerFrame(D2StatListStrc* pStatList)
{
	if (pStatList)
	{
		return STATLIST_GetStatValue(pStatList, STAT_HPREGEN, 0);
	}
	return 0;
}

// 0x00548520
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer)
{
    D2ClientStrc* hClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrMsg.cpp", 339);
    D2_ASSERT(hClient, 340);

    if (pUnit == pPlayer)
    {
        D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(hClient, nStat, nNewValue);
    }
    else
    {
        sub_6FC3D830(hClient, 0x20, !pUnit ? -1 : pUnit->dwUnitId, nStat, nNewValue);
    }
}

// 0x005485B0
static unsigned char sub_005485B0_GetPoisonedLifePercent(D2UnitStrc* pUnit)
{
	const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
	const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
	D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_HEALTHPOT);
	if (!pStatList || !nMaxLife)
	{
		return 0;
	}

	D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
	const int nFrames = sub_00626090(pStatList) - pGame->dwGameFrame;
	const unsigned char nPercent = (unsigned char)((((PoisonStat_GetPerFrame(pStatList) * nFrames + nHitpoints) >> 8) * 100) / nMaxLife);
	const int nClamped = nPercent > 100 ? 100 : nPercent;
	return (unsigned char)nClamped;
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

static inline D2MonsterInteractStrc* PLRMSG_GetMonInteract(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonInteract;
    }

    return 0;
}

static __forceinline int PLRMSG_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int PLRMSG_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00548A50
static void __stdcall sub_00548A50_ChangeModeAndSetInteract(int nInteractSkill, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID)
{
    StartModeID(pGame, pPlayer, 0, 3, nUnitType, nUnitGUID, 0);
    sub_00641F20_SetPlayerModeState(pPlayer, nInteractSkill, nUnitType, nUnitGUID);
}

// 0x00548A80
static int __stdcall sub_6FC83D00(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
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

// build: context sub_005485B0_Shim
// calling-convention shim (not game code)
int __stdcall sub_005485B0_Shim(D2UnitStrc* pUnit)
{
	return sub_005485B0_GetPoisonedLifePercent(pUnit);
}

// 0x00548B00
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

        D2_ASSERT(DATATBLS_GetObjectsTxtRecord(!pUnit ? -1 : pUnit->dwClassId), 703);

        if (pUnit->dwAnimMode >= 8)
        {
            return 3;
        }

        if (sub_00641530(pPlayer, pUnit) > 50)
        {
            return 1;
        }

        if (sub_00623660_IsInObjectInteractRange(pPlayer, pUnit) && !sub_00622B50_IsRayFreeBetweenUnits(pPlayer, pUnit, 0x804))
        {
            D2Common_10153(pPlayer->pDynamicPath);
            if (!sub_6FC78B20(pGame, pPlayer, 2, nUnitGUID))
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

        const int nDistance = sub_00641530(pPlayer, pUnit);
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
            sub_005550B0_WarpPlayer(pGame, pPlayer, pUnit);
        }

        return 0;
    }
    case 4:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 4, nUnitGUID);
        const int nAnimMode = pUnit ? pUnit->dwAnimMode : 0;
        if (!pUnit)
        {
            return 1;
        }
        if (nAnimMode != 3)
        {
            return 1;
        }

        const int nDistance = sub_00641530(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        if (nDistance <= 4 && !sub_00622B50_IsRayFreeBetweenUnits(pPlayer, pUnit, 0x804))
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

        const int nDistance = sub_00641530(pPlayer, pUnit);
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

        const unsigned int nDistance = sub_00641530(pPlayer, pUnit);
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
static int __stdcall sub_6FC83C60(unsigned short nX, unsigned short nY, D2UnitStrc* pUnit, int nMaxDistance)
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
static int __stdcall sub_00548F80_CheckTargetUnit(int nMaxDistance, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID)
{
    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (!pTarget)
    {
        return 1;
    }

    if (nUnitType == 4 && sub_00557FF0_InventoryContainsItem(pPlayer, pTarget, 0))
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
static inline int sub_00549080_CheckLeftSkill(D2UnitStrc* pUnit)
{
    return UNITS_GetLeftSkill(pUnit) ? 0 : 3;
}

// 0x005490A0
static inline int sub_005490A0_CheckRightSkill(D2UnitStrc* pUnit)
{
    return UNITS_GetRightSkill(pUnit) ? 0 : 3;
}

// 0x005490C0
static inline int sub_005490C0_CheckName(const char* szName)
{
    if (!szName[0xFF])
    {
        return SStrChr(szName, -1) ? 2 : 0;
    }
    return 2;
}

// 0x00549220
static int __stdcall sub_00549220_CheckOwnedItem(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pUnit)
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

// 0x00549290
static inline int sub_00549290_CheckRange1To10(int nValue)
{
    return (unsigned int)(nValue - 1) > 9 ? 2 : 0;
}

// 0x005492A0
static inline int sub_005492A0_CheckBodyLocFree(D2UnitStrc* pUnit, int nBodyLoc)
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

// 0x00549350
static int __stdcall sub_6FC86520(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pPlayer)
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
    case IMODE_ONGROUND:
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
    case IMODE_STORED:
    case IMODE_EQUIP:
    case IMODE_INBELT:
    case IMODE_ONCURSOR:
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

// 0x00549410
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

    if (bCheckRange)
    {
        const int nX = CLIENTS_GetUnitX(*ppNpc);
        const int nRange = sub_6FC83C60(nX, CLIENTS_GetUnitY(*ppNpc), pUnit, 10);
        if (nRange)
        {
            return nRange;
        }
    }

    return 0;
}

int __fastcall sub_K10_EmitIsHandBodyLocFree(D2UnitStrc* pUnit, int nBodyLoc)
{
    return sub_005492C0_IsHandBodyLocFree(pUnit, nBodyLoc);
}

// 0x00549490
static int sub_00549490_CheckSkillAllocation(D2UnitStrc* pUnit, int nSkillId)
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
static inline int sub_005494E0_CheckSkillLevel(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
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

// 0x00549520
static int __stdcall sub_00549520_CheckOrificeObject(int nItemGUID, unsigned short nState, D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID)
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
        return ((D2GameItemChecks*)pGame)->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    default:
        return 2;
    }
}

static inline int PLRMSG_J07_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline int PLRMSG_J07_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00549570
static int __stdcall sub_00549570_CheckWaypointObject(D2GameStrc* pGame, unsigned short nLevelId, D2UnitStrc* pUnit, int nObjectGUID)
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

    struct
    {
        unsigned short nWaypointNo;
        int nX;
    } tLocal;
    switch (pObject->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        tLocal.nX = pObject->pStaticPath->nXPos;
        break;
    default:
        if (pObject->pDynamicPath)
            tLocal.nX = PATH_GetXPosition(pObject->pDynamicPath);
        else
            tLocal.nX = 0;
        break;
    }
    const int nY = PLRMSG_J07_GetUnitY(pObject);
    int nMaxDistance = 0xA;
    if (pUnit && pUnit->dwClassId == 1)
    {
        nMaxDistance = 0x16;
    }

    const int nResult = sub_6FC83C60(tLocal.nX, nY, pUnit, nMaxDistance);
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

    D2_ASSERT(UNITS_GetPlayerData(pUnit), 0x632);

    if (WAYPOINTS_GetWaypointNoFromLevelId(nLevelId, &tLocal.nWaypointNo))
    {
        return WAYPOINTS_IsActivated(sub_00547F50(pGame, pUnit), tLocal.nWaypointNo) ? 0 : 2;
    }

    return 3;
}

// 0x005496F0
static int __stdcall sub_6FC82D10(D2GameStrc* pGame, int nPacketSize, unsigned short* pX, unsigned short* pY, D2UnitStrc* pUnit, void* pPacket)
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
            D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 1639);
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

// 0x005497E0
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

// 0x00549830
static int __stdcall sub_00549830_ReadTargetUnitPacket(D2GameStrc* pGame, int nPacketSize, int* pUnitType, int* pUnitGUID, D2UnitStrc* pUnit, void* pPacket)
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

// 0x00549890
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

// 0x005498D0
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

// 0x00549920
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
static D2SkillStrc* __stdcall sub_6FC83450(D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    D2SkillStrc* pUsedSkill = pSkill;
    if (!SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrMsg.cpp", 1804))
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (pRightWeapon && (!ITEMS_CanBeEquipped(pRightWeapon) || ITEMS_GetItemType(pRightWeapon) == ITEMTYPE_MISSILE_POTION))
        {
            pRightWeapon = 0;
        }

        D2UnitStrc* pLeftWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (pLeftWeapon && (!ITEMS_CanBeEquipped(pLeftWeapon) || ITEMS_GetItemType(pLeftWeapon) == ITEMTYPE_MISSILE_POTION))
        {
            pLeftWeapon = 0;
        }

        if (pRightWeapon && pLeftWeapon && ITEMSIsA(pRightWeapon, 45) && ITEMSIsA(pLeftWeapon, 45))
        {
            if (!SKILLS_GetParam4(pSkill))
            {
                pUsedSkill = SKILLS_GetSkillById(pUnit, SKILL_LEFTHANDSWING, -1);
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

inline int PLRMSG_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int PLRMSG_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00549A60
void __fastcall sub_00549A60_SendCantDoThat(D2UnitStrc* pUnit)
{
    D2GSPacketSrv5A packet5A = {};
    packet5A.nHeader = 0x5A;
    packet5A.nColor = STRCOLOR_RED;
    *(int*)&packet5A.dwParam = 0;
    packet5A.nType = EVENTTYPE_CANTDOTHAT;
    D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 1852), &packet5A);
}

// 0x00549AD0
static int __stdcall sub_6FC83340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY)
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
        pUsedSkill = SKILLS_GetSkillById(pUnit, SKILL_ATTACK, -1);
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

// 0x00549BA0
static int __stdcall PLRMSG_UseSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nUnitType, int nUnitGUID, int bCheckRange)
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
        pSkill = SKILLS_GetSkillById(pUnit, SKILL_ATTACK, -1);
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
    if (pOtherUnit && STATES_CheckState(pOtherUnit, STATE_ATTACHED))
    {
        D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pOtherUnit);
        if (pOwner)
        {
            nUnitType = pOwner->dwUnitType;
            pOtherUnit = pOwner;
            nUnitGUID = pOwner->dwUnitId;
        }
    }

    if (bCheckRange && pOtherUnit)
    {
        switch (D2Common_11016(pUnit, pSkill))
        {
        case 1:
            if (UNITS_IsInMeleeRange(pUnit, pOtherUnit, UNITS_IsInMovingModeEx(pOtherUnit)))
            {
                break;
            }

        case 4:
            sub_00548A50_ChangeModeAndSetInteract(SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrMsg.cpp", 2013), pGame, pUnit, nUnitType, nUnitGUID);
            return 0;
        }
    }

    StartModeID(pGame, pUnit, pSkill, nSkillMode, nUnitType, nUnitGUID, 0);
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

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
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

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
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

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetLeftSkill(pUnit), nUnitType, nUnitGUID, 0);
    return 0;
}

// 0x00549E80
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

// 0x00549EE0
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

// 0x00549F40
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

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
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

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
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

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetRightSkill(pUnit), nUnitType, nUnitGUID, 0);
    return 0;
}

// 0x0054A140
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

// 0x0054A1A0
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

// 0x0054A200
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

// 0x0054A260
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x12_6FC84670(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    return 0;
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

// 0x0054A510
void __fastcall D2GAME_PACKETS_HandleWhisper_6FC848A0(D2ClientStrc* pClient, void* pArgs)
{
    D2GSPacketSrv26Args* pPacket26Args = (D2GSPacketSrv26Args*)pArgs;
    D2GameStrc* pGame = CLIENTS_GetGame(pClient);
    D2GSPacketSrv26* pPacket26 = pPacket26Args->pPacket26;
    const char* szClientName = CLIENTS_GetName(pClient);
    if (!SStrCmpI(szClientName, pPacket26Args->pPacket15->szName, 0x7FFFFFFF))
    {
        const int nUnitGUID = pPacket26Args->nUnitId;
        if (nUnitGUID != -1)
        {
            D2UnitStrc* pReceiver = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nUnitGUID);
            D2UnitStrc* pLocalPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
            if (pReceiver && pLocalPlayer)
            {
                if (PLAYERLIST_CheckFlag(pLocalPlayer, pReceiver, 4))
                {
                    gbWhispReceiverNotListening_6FD4DC24 = 1;
                    return;
                }

                if (PLAYERLIST_CheckFlag(pReceiver, pLocalPlayer, 2))
                {
                    gbWhispReceiverNotListening_6FD4DC24 = 1;
                    return;
                }
            }
        }

        gbWhispReceiverInGame_6FD4DC20 = 1;
        D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(pClient, pPacket26);
    }
}

// 0x0054A5C0
void __fastcall j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, void* pMsg)
{
    D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(pClient, (D2GSPacketSrv26*)pMsg);
}

// 0x0054A5D0
int __fastcall sub_0054A5D0_HandleChat(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pBuffer, int nSize)
{
    D2GSPacketClt15 packet15;
    memset(&packet15, 0, sizeof(packet15));
    packet15.nHeader = pBuffer[0];
    packet15.nType = pBuffer[1];
    packet15.nColor = pBuffer[2];
    const char* pText = (const char*)pBuffer + 3;
    SStrCopy(packet15.szMessage, pText, 256);
    const int nLength = SStrLen(pText);
    if (nLength >= 256 || nLength + 4 >= nSize) return 2;
    pText += nLength + 1;
    SStrCopy(packet15.szName, pText, 16);
    SStrLen(pText);
    D2GSPacketSrv26 packet26;
    const char* pName = CLIENTS_GetName(UnitGetClient(pUnit, gszPlrMsgSourceFile, 0x9E7));
    if (SStrLen(pName) > 0) SStrCopy(packet26.szName, pName, 0x7FFFFFFF);
    else packet26.szName[0] = 0;
    const int nReceiverLength = SStrLen(packet15.szName);
    const int bWhisper = nReceiverLength > 0 && nReceiverLength <= 15;
    packet26.nNameColor = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    packet15.szName[15] = 0;
    if (packet15.szMessage[255]) goto MalformedChat;
    if (SStrChr(packet15.szMessage, -1)) {
MalformedChat:
        return 0;
    }
    memcpy(packet26.szMessage, packet15.szMessage, 256);
    packet26.nLang = packet15.nColor;
    packet26.nMessageColor = 0;
    packet26.nHeader = 0x26;
    packet26.dwUnitGUID = 0;
    packet26.nUnitType = 2;
    D2ClientCallback pCallback;
    if (bWhisper) { packet26.nMessageType = 2; pCallback = D2GAME_PACKETS_HandleWhisper_6FC848A0; }
    else { packet26.nMessageType = 1; pCallback = D2GAME_PACKETS_HandlePlayerMessage_6FC847B0; }
    gbWhispTextInGame_6FD4DC20 = 0;
    gbWhispTextNotListening_6FD4DC24 = 0;
    D2GSPacketSrv26Args args;
    args.pPacket26 = &packet26;
    args.pPacket15 = &packet15;
    args.nUnitId = pUnit && pUnit->dwUnitType == UNIT_PLAYER ? pUnit->dwUnitId : -1;
    GAME_ForEachIngameClient(pGame, pCallback, &args);
    if (packet26.nMessageType == 2)
    {
        if (gbWhispTextNotListening_6FD4DC24)
        {
            D2GSPacketSrv5A packet5A = {};
            packet5A.nHeader = 0x5A;
            packet5A.nColor = 0;
            packet5A.dwParam = 0;
            SStrCopy(packet5A.szText, packet15.szName, 0x7FFFFFFF);
            packet5A.nType = 13;
            packet5A.szText[15] = 0;
            D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(UnitGetClient(pUnit, gszPlrMsgSourceFile, 0xA2C), &packet5A);
        }
        else if (!gbWhispTextInGame_6FD4DC20)
        {
            D2GSPacketSrv5A packet5A = {};
            packet5A.nHeader = 0x5A;
            packet5A.nColor = 0;
            packet5A.dwParam = 0;
            SStrCopy(packet5A.szText, packet15.szName, 0x7FFFFFFF);
            packet5A.nType = 4;
            packet5A.szText[15] = 0;
            D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(UnitGetClient(pUnit, gszPlrMsgSourceFile, 0xA38), &packet5A);
        }
        else
        {
        D2GSPacketSrv26 reply;
        reply.nHeader = 0x26;
        reply.nMessageType = 6;
        reply.dwUnitGUID = 0;
        reply.nUnitType = 2;
        reply.nMessageColor = 0;
        SStrCopy(reply.szName, packet15.szName, 0x7FFFFFFF);
        reply.szName[15] = 0;
        reply.nLang = 0;
        memcpy(reply.szMessage, packet15.szMessage, 256);
        D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(UnitGetClient(pUnit, gszPlrMsgSourceFile, 0xA46), &reply);
        }
    }
    return 0;
}

// 0x0054A930
void __fastcall sub_0054A930_BroadcastMessage(D2GameStrc* game, const char* message, unsigned char color)
{
    D2GSPacketSrv26 packet;
    packet.nHeader = 0x26;
    packet.nMessageType = 1;
    packet.nUnitType = 2;
    packet.dwUnitGUID = 0;
    packet.nMessageColor = color;
    packet.szName[0] = 0;
    packet.nLang = 0;
    memcpy(packet.szMessage, message, sizeof(packet.szMessage));
    GAME_ForEachIngameClient(game, j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0, &packet);
}

// 0x0054A9B0
void __fastcall sub_6FC84CD0(D2GameStrc* pGame, const char* szMessage, unsigned char nColor)
{
    D2GSPacketSrv26 packet26;
    packet26.nMessageColor = nColor;
    packet26.nHeader = 0x26;
    packet26.nMessageType = 4;
    packet26.dwUnitGUID = 0;
    packet26.nUnitType = UNIT_PLAYER;
    memcpy(packet26.szMessage, szMessage, sizeof(packet26.szMessage));
    packet26.nLang = 0;
    GAME_ForEachIngameClient(pGame, j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0, &packet26);
}

// 0x0054AA30
void __fastcall j_D2GAME_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, void* pPacket)
{
    D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(pClient, (D2GSPacketSrv5A*)pPacket);
}

// 0x0054AA40
void __fastcall sub_0054AA40_BroadcastNamedPacket(D2GameStrc* pGame, D2GSPacketSrv5A* pPacket)
{
    const char* szName = pPacket->szText;
    int i;
    for (i = 0; i < 16; ++i)
    {
        if (!szName[i])
        {
            break;
        }
    }
    if (i < 16)
        GAME_ForEachIngameClient(pGame, j_D2GAME_SendPacket0x5A_6FC3DEC0, pPacket);
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

// 0x0054AB40
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x17_DropItemOnGround_6FC84E20(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nResult = ((D2GameItemChecks*)pGame)->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 0))
    {
        return 3;
    }

    sub_6FC44030(pGame, pUnit, nItemGUID);
    return 0;
}

// 0x0054ABB0
int __fastcall sInsertItemGrid(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 17)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nX = *(int*)((char*)pPacket + 5);
    const int nY = *(int*)((char*)pPacket + 9);
    const unsigned int nInvPage = *(unsigned int*)((char*)pPacket + 13);
    const int nResult = ((D2GameItemChecks*)pGame)->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (!PLAYER_IsBusy(pUnit) && nInvPage)
        {
            return 2;
        }

        if (nInvPage == 4)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
            {
                return 3;
            }
        }
        else
        {
            if (nInvPage != 3 && nInvPage != 2 && nInvPage != 0)
            {
                return 2;
            }

            if (nInvPage == 2 && !D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
            {
                return 3;
            }
        }
    }
    else if (nInvPage >= 5)
    {
        return 2;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (pItem)
    {
        ITEMS_SetInvPage(pItem, nInvPage);
        return D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrMsg.cpp", 3062, pGame, pUnit, nItemGUID, nX, nY, 0, 1, 0) ? 0 : 3;
    }

    return 2;
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
    const int nResult = ((D2GameItemChecks*)pGame)->sub_00549150_CheckStoredItem(pUnit, nItemGUID);
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

// 0x0054AD90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1A_EquipItem_6FC85280(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const unsigned char nBodyLoc = *((unsigned char*)pPacket + 5);
    const int nResult = ((D2GameItemChecks*)pGame)->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    int a6 = 0;
    if (ITEMMODE_EquipCursorItem(pGame, pUnit, nItemGUID, nBodyLoc, 0, &a6) || !a6)
    {
        return 0;
    }

    SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    char szName[32];
    D2_MAYBE_UNUSED(szName);
    return 3;
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
    const int nResult = ((D2GameItemChecks*)pGame)->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    int a6 = 0;
    if (ITEMMODE_ReplaceOppositeHandItem(pGame, pUnit, nItemGUID, nBodyLoc, 0, &a6) || !a6)
    {
        return 0;
    }

    return 3;
}

// 0x0054AEC0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1C_RemoveBodyItem_6FC854B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }

    const int nBodyLoc = *(unsigned short*)((char*)pPacket + 1);
    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc);
    if (sub_6FC7C3A0(pGame, pUnit, pItem) && (nBodyLoc != BODYLOC_BELT || sub_6FC93740(pGame, pUnit)))
    {
        int a5 = 0;
        if (!ITEMMODE_UnequipBodyItem(pGame, pUnit, nBodyLoc, 0, &a5) && a5)
        {
            return 3;
        }
    }

    return 0;
}

// 0x0054AF50
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1D_SwapCursorItemWithBody_6FC85550(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const unsigned char nBodyLoc = *((unsigned char*)pPacket + 5);
    const int nResult = ((D2GameItemChecks*)pGame)->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    if (!INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc))
    {
        return 1;
    }

    if (nBodyLoc == BODYLOC_BELT && !sub_6FC93740(pGame, pUnit))
    {
        return 0;
    }

    if (!sub_6FC7C3A0(pGame, pUnit, INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc)))
    {
        return 0;
    }

    int a5 = 0;
    if (ITEMMODE_SwapCursorAndBodyItem(pGame, pUnit, nItemGUID, nBodyLoc, 0, &a5) || !a5)
    {
        return 0;
    }

    return 3;
}

// 0x0054B030
int __fastcall sub_0054B030_SwapDualWieldedItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const unsigned char nBodyLoc = *((unsigned char*)pPacket + 5);
    int nResult = ((D2GameItemChecks*)pGame)->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    const int nLoc = nBodyLoc;
    if (!PLRMSG_IsBodyLocValid(nLoc))
    {
        return 2;
    }

    if (nLoc != BODYLOC_RARM && nLoc != BODYLOC_LARM)
    {
        return 3;
    }

    nResult = (INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nLoc) ? -1 : 0) + 1;
    if (nResult)
    {
        return nResult;
    }

    if (!sub_6FC7C3A0(pGame, pUnit, INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nLoc)))
    {
        return 0;
    }

    int nFailure;
    if (sub_00561220_SwapDualWieldedItem(pGame, pUnit, nItemGUID, nBodyLoc, &nFailure) || !nFailure)
    {
        return 0;
    }

    return 3;
}

// 0x0054B0F0
int __fastcall sub_0054B0F0_SwapInventoryItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    D2GSPacketClt1F* pPacket1F = (D2GSPacketClt1F*)pPacket;
    if (nSize != 17)
    {
        return 3;
    }

    const int nCursorItemGUID = pPacket1F->nCursorItemGUID;
    const int nInventoryItemGUID = pPacket1F->nInventoryItemGUID;
    const int nX = pPacket1F->nPosX;
    const int nY = pPacket1F->nPosY;
    D2UnitStrc* pInventoryItem;
    int nResult = ((D2GameItemChecks*)pGame)->sub_005490E0_CheckCursorItem(pUnit, nCursorItemGUID);
    if (!nResult)
    {
        nResult = ((D2GameItemChecks*)pGame)->sub_00549150_CheckStoredItem(pUnit, nInventoryItemGUID);
        if (!nResult)
        {
            pInventoryItem = SUNIT_GetServerUnit(pGame, 4, nInventoryItemGUID);
        }
    }
    if (nResult)
    {
        return nResult;
    }

    if (!pInventoryItem)
    {
        return 2;
    }

    if (ITEMS_GetInvPage(pInventoryItem) == 1)
    {
        return 3;
    }
    if (ITEMS_GetInvPage(pInventoryItem) == 2)
    {
        return 3;
    }

    int bPlaced;
    if (sub_6FC7C3A0(pGame, pUnit, pInventoryItem) && !sub_6FC46D40(pGame, pUnit, nCursorItemGUID, nInventoryItemGUID, nX, nY, &bPlaced) && bPlaced)
    {

        SUNIT_GetServerUnit(pGame, 4, nCursorItemGUID);
        char szName[32];
        char szCursorItemName[32];
        D2_MAYBE_UNUSED(szName);
        D2_MAYBE_UNUSED(szCursorItemName);
        return 3;
    }

    return 0;
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
    int nResult = ((D2GameItemChecks*)pGame)->sub_00549150_CheckStoredItem(pUnit, nItemGUID);
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

// 0x0054B380
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

// 0x0054B3E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x23_ItemToBelt_6FC85E70(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nBeltSlot = *(int*)((char*)pPacket + 5);
    const int nResult = ((D2GameItemChecks*)pGame)->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
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

// 0x0054B450
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x24_ItemFromBelt_6FC85F50(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nResult = ((D2GameItemChecks*)pGame)->sub_005492F0_CheckBeltItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!sub_6FC7C3A0(pGame, pUnit, 0))
    {
        return 0;
    }

    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        return 2;
    }

    int a5 = 0;
    if (sub_6FC48B40(pGame, pUnit, nItemGUID, &a5) || !a5)
    {
        return 0;
    }

    return 3;
}

// 0x0054B4E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x25_SwitchBeltItem_6FC86040(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nCursorItemGUID = *(int*)((char*)pPacket + 1);
    const int nBeltItemGUID = *(int*)((char*)pPacket + 5);
    int nResult = ((D2GameItemChecks*)pGame)->sub_005490E0_CheckCursorItem(pUnit, nCursorItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = ((D2GameItemChecks*)pGame)->sub_005492F0_CheckBeltItem(pUnit, nBeltItemGUID);
    if (nResult)
    {
        return nResult;
    }

    int a5 = 0;
    if (sub_6FC48D50(pGame, pUnit, nCursorItemGUID, nBeltItemGUID, &a5) || !a5)
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
    int nResult = ((D2GameItemChecks*)pGame)->sub_005492F0_CheckBeltItem(pUnit, nItemGUID);
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

// 0x0054B650
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x28_SocketItem_6FC86310(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nCursorItemGUID = *(int*)((char*)pPacket + 1);
    const int nSocketableItemGUID = *(int*)((char*)pPacket + 5);
    int nResult = ((D2GameItemChecks*)pGame)->sub_005490E0_CheckCursorItem(pUnit, nCursorItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = ((D2GameItemChecks*)pGame)->sub_005491B0_CheckStoredOrEquippedItem(pUnit, nSocketableItemGUID);
    if (nResult)
    {
        return nResult;
    }

    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
        if (pInteractUnit && pInteractUnit->dwUnitType == UNIT_PLAYER)
        {
            return 0;
        }
    }

    int bPlaced = 0;
    if (D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pUnit, nCursorItemGUID, nSocketableItemGUID, &bPlaced, 1, 1, 1, 1) || !bPlaced)
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

    nResult = ((D2GameItemChecks*)pGame)->sub_00549150_CheckStoredItem(pUnit, nBookGUID);
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

    nResult = ((D2GameItemChecks*)pGame)->sub_00549150_CheckStoredItem(pUnit, nCubeGUID);
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

// 0x0054B830
void __fastcall D2GAME_PlayerChangeAct_6FC867C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwDestLvl, int nTileCalc)
{
    const unsigned char nDestAct = DRLG_GetActNoFromLevelId(dwDestLvl);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const unsigned char nSourceAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));

    if (!dwDestLvl)
    {
        const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nSourceAct);
        LEVEL_WarpUnit(pGame, pUnit, nTownLevelId, nTileCalc);
        return;
    }

    if (nDestAct == nSourceAct)
    {
        const int nX = PLRMSG_GetUnitXInline(pUnit) - 5;
        const int nY = PLRMSG_GetUnitYInline(pUnit);
        D2GAME_CreatePortalObject_6FD13DF0(pGame, pUnit, pRoom, nX, nY, dwDestLvl, 0, OBJECT_TOWN_PORTAL, 0);
    }
    else
    {
        LEVEL_WarpUnit(pGame, pUnit, dwDestLvl, nTileCalc);
    }
}

// 0x0054B930
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2F_InitEntityChat_6FC868C0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    D2UnitStrc* pNpc;
    const int nResult = sub_00549410_GetInteractNpc(1, pGame, pUnit, &pNpc, *(int*)((char*)pPacket + 5));
    if (!nResult)
    {
        sub_6FC61AB0(pGame, pUnit, pNpc, PLRMSG_GetMonInteract(pNpc));
        return 0;
    }

    return nResult;
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

    sub_6FC61B70(pGame, pUnit, pNpc, PLRMSG_GetMonInteract(pNpc));
    return 0;
}

// 0x0054BA90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x31_QuestMessage_6FC86AB0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    QUESTS_NPCMessage(pGame, pUnit, *(int*)((char*)pPacket + 1), *(unsigned short*)((char*)pPacket + 5));
    return 0;
}

// 0x0054BAC0
int __fastcall sub_0054BAC0_BuyItemFromNpcBuffer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2BuyItemPacketStrc* pPacket, int nSize)
{
    if (nSize != sizeof(D2BuyItemPacketStrc))
        return 3;

    unsigned int nTransactionType = pPacket->nTransactionType;
    const int nNpcUnitId = pPacket->nNpcUnitId;
    const int nItemId = pPacket->nItemId;
    const int nCost = pPacket->nCost;
    const int bMultibuy = nTransactionType & 0x80000000;
    nTransactionType &= 0x7FFFFFFF;
    return D2GAME_NPC_BuyItemHandler_6FCC92A0(pGame, pPlayer, nNpcUnitId, nItemId,
        nTransactionType >> 16, nTransactionType, nCost, bMultibuy);
}

// 0x0054BB20
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x33_SellItemToNpcBuffer_6FC86B30(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 17)
    {
        return 3;
    }

    const int nNpcGUID = *(int*)((char*)pPacket + 1);
    const int nItemGUID = *(int*)((char*)pPacket + 5);
    const unsigned short nItemMode = *(unsigned short*)((char*)pPacket + 9);
    const int nCost = *(int*)((char*)pPacket + 13);
    return D2GAME_STORES_SellItem_6FCC7680(pGame, pUnit, nNpcGUID, nItemGUID, nItemMode, nCost);
}

// 0x0054BB60
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x35_Repair_6FC86B70(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 17)
    {
        return 3;
    }

    D2GAME_NPC_Repair_6FCC95B0(pGame, pUnit, *(int*)((char*)pPacket + 1), *(int*)((char*)pPacket + 5), *(unsigned short*)((char*)pPacket + 9), *(int*)((char*)pPacket + 13));
    return 0;
}

// 0x0054BBD0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x36_HireMerc_6FC86BD0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    D2GAME_NPC_HireMerc_6FCC9540(pGame, pUnit, *(int*)((char*)pPacket + 1), *(unsigned short*)((char*)pPacket + 5));
    return 0;
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

// 0x0054BCA0
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

// 0x0054BD00
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x39_PurchaseLife_6FC86E50(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054BD10
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3A_AddStatPoint_6FC86E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }

    const unsigned short nValue = *(unsigned short*)((char*)pPacket + 1);
    int nCount = (nValue >> 8) + 1;
    const int nStatId = nValue & 0xFF;
    if (nStatId <= -1 || nStatId >= 16 || nCount < 1 || nCount > 100)
    {
        return 3;
    }

    while (nCount)
    {
        --nCount;
        if (!PLAYERSTATS_SpendStatPoint(pUnit, nStatId))
        {
            return 2;
        }
    }

    return 0;
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

// 0x0054BF10
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

    sub_005845D0_UpdateDoorCollisionMode(pGame, pUnit, nObjectGUID);
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

static inline int HasSoundFlag(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwFlags >> 10) & 1 : 0;
}

// 0x0054C070
int __fastcall sub_0054C070_HandleSoundPacket(D2GameStrc* pGame, D2UnitStrc* pUnit, const unsigned char* pPacket, int nSize)
{
    if (nSize != 3)
        return 3;
    unsigned int nSound = *(const unsigned short*)(pPacket + 1);
    if (nSound >= 25 && nSound <= 32)
    {
        if (!HasSoundFlag(pUnit))
            SUNIT_AttachSound(pUnit, nSound, 0);
        else
            return 1;
    }
    return 0;
}

// 0x0054C0C0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x40_RequestQuestData_6FC87460(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    QUESTS_StatusCallback(pGame, pUnit);
    return 0;
}

// 0x0054C0E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x41_Resurrect_6FC87480(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (!pUnit || pUnit->dwAnimMode != PLRMODE_DEAD)
    {
        return 0;
    }

    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 4579);
    if (CLIENTS_CheckFlag(pClient, CLIENTSAVEFLAG_HARDCORE))
    {
        SrvDisconnectClient(pGame, pClient, EVENTTYPE_PLAYERLEFT);
        return 0;
    }

    const int n0 = ARENA_Return0(pGame, pUnit);
    D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);

    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxLife, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nMaxMana, 0);
    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_HITPOINTS, nMaxLife, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_MANA, nMaxMana, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_STAMINA, nMaxStamina, pUnit);

    pUnit->dwFlags |= UNITFLAG_TARGETABLE;

    STATES_ToggleState(pUnit, STATE_UNINTERRUPTABLE, 1);
    STATES_ToggleState(pUnit, STATE_UNINTERRUPTABLE, 0);

    DRLG_GetActNoFromLevelId(0);
    const unsigned char nSourceAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
    const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nSourceAct);
    LEVEL_WarpUnit(pGame, pUnit, nTownLevelId, n0);

    sub_6FC817D0(pGame, pUnit, 0, 1, 0, 0, 1);

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        D2GAME_AssignSkill_6FD13800(pUnit, 1, SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\PLAYER\\PlrMsg.cpp", 4617), SKILLS_GetOwnerGUIDFromSkill(pLeftSkill));
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        D2GAME_AssignSkill_6FD13800(pUnit, 0, SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\PLAYER\\PlrMsg.cpp", 4622), SKILLS_GetOwnerGUIDFromSkill(pRightSkill));
    }

    return 0;
}

// 0x0054C2A0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x5D_SquelchHostile_6FC876B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 7)
    {
        return 3;
    }

    if (ARENA_IsActive(pGame))
    {
        return 3;
    }

    const unsigned char nCommand = *((unsigned char*)pPacket + 1);
    const int nArg = *(int*)((char*)pPacket + 3);
    if (nCommand > 10)
    {
        return 2;
    }

    return PARTYSCREEN_CommandHandler(pGame, pUnit, nCommand, nArg, *((unsigned char*)pPacket + 2));
}

// 0x0054C300
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x5E_InviteToParty_6FC87720(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 6)
    {
        return 3;
    }

    if (ARENA_IsActive(pGame))
    {
        return 3;
    }

    const unsigned char nCommand = *((unsigned char*)pPacket + 1);
    if (nCommand > 10)
    {
        return 2;
    }

    PARTYSCREEN_CommandHandler(pGame, pUnit, nCommand, *(int*)((char*)pPacket + 2), 0);
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

// 0x0054C420
int __fastcall sub_0054C420_Rcv0x45Stub(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

static inline int sub_E03_PlrGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline int sub_E03_PlrGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0054C430
static int __stdcall sub_0054C430_CommandMerc(int nParam1, int nParam2, int nCommand, D2GameStrc* pGame, D2UnitStrc* pUnit, int nMercGUID)
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

// 0x0054C5D0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x49_TakeOrCloseWp_6FC87E60(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nWaypointGUID = *(int*)(pPacket + 1);
    const int nLevelId = *(unsigned short*)(pPacket + 5);
    const unsigned int nTick = PLAYERLIST_GetHostileDelay(pUnit, 0) + 0x2710;
    if (nTick > GetTickCount())
    {
        SUNIT_AttachSound(pUnit, 0x13, pUnit);
        SUNIT_ResetInteractInfo(pUnit);
        return 1;
    }

    const int nResult = sub_00549570_CheckWaypointObject(pGame, nLevelId, pUnit, nWaypointGUID);
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

    OBJMODE_TravelViaWaypoint(pGame, pUnit, nWaypointGUID, nLevelId);
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

// 0x0054C760
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4C_Transmogrify_6FC88170(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem && nItemGUID != -1)
    {
        return 1;
    }

    sub_6FD11AE0(pGame, pUnit, pItem);
    return 0;
}

// 0x0054C7C0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4F_ClickButton_6FC881D0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 7)
    {
        return 3;
    }

    const unsigned short nButton = *(unsigned short*)((char*)pPacket + 1);
    const unsigned short nHigh = *(unsigned short*)((char*)pPacket + 3);
    const unsigned short nLow = *(unsigned short*)((char*)pPacket + 5);
    return sub_6FC91250(pGame, pUnit, nButton, (nHigh << 16) | nLow);
}

// 0x0054C800
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x50_DropGold_6FC88210(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nUnitGUID = *(int*)((char*)pPacket + 1);
    const int nGoldValue = *(int*)((char*)pPacket + 5);
    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 3;
    }

    return sub_6FC7C260(pGame, pUnit, nUnitGUID, nGoldValue) ? 0 : 3;
}

// 0x0054C870
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x51_BindHotkeyToSkill_6FC88290(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const unsigned int nValue = *(unsigned int*)((char*)pPacket + 1);
    const int nOwnerGUID = *(int*)((char*)pPacket + 5);
    const unsigned int nHotKeyId = nValue >> 16;
    if (nHotKeyId <= 15)
    {
        int nSkillId = nValue & 0x7FFF;
        if (nSkillId > sgptDataTables->nSkillsTxtRecordCount)
        {
            nSkillId = -1;
        }
        else if (nSkillId != -1)
        {
            if (nSkillId < 0)
            {
                return 3;
            }

            if (nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
            {
                return 3;
            }

            if (!SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID))
            {
                return 3;
            }
        }

        return sub_6FC7C450(pGame, pUnit, nHotKeyId, nSkillId, (nValue >> 15) & 1, nOwnerGUID) ? 0 : 3;
    }

    return 3;
}

// 0x0054C930
int __fastcall sub_0054C930_Rcv0x52Stub(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054C940
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x53_TurnStaminaOn_6FC88340(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode == PLRMODE_WALK)
    {
        if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0))
        {
            UNITS_ChangeAnimMode(pUnit, PLRMODE_RUN);
        }
    }

    return 0;
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

// 0x0054CA10
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x59_MakeEntityMove_6FC88400(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 17)
    {
        return 3;
    }

    const unsigned int nUnitType = *(unsigned int*)((char*)pPacket + 1);
    const int nUnitGUID = *(int*)((char*)pPacket + 5);
    const int v8 = *(int*)((char*)pPacket + 9);
    const int a3 = *(int*)((char*)pPacket + 13);
    if (nUnitType >= 6)
    {
        return 2;
    }

    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (pNpc && sub_00641530(pUnit, pNpc) <= 50)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pNpc->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_INTERACT >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_INTERACT & 7] && pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NPC >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NPC & 7])
        {
            if (pNpc->pDynamicPath)
            {
                D2Common_10153(pNpc->pDynamicPath);
            }

            D2GAME_EVENTS_Delete_6FC34840(pGame, pNpc, EVENTTYPE_AITHINK, 0);
            EVENT_SetEvent(pGame, pNpc, EVENTTYPE_AITHINK, pGame->dwGameFrame + 1, 0, 0);
            AIGENERAL_SetAiControlParam(pNpc, 1, 40);
            AIGENERAL_SetAiControlParam(pNpc, 2, v8);
            AIGENERAL_SetAiControlParam(pNpc, 3, a3);
            return 0;
        }
    }

    return 1;
}

// 0x0054CB10
static int __stdcall sub_0054CB10_TestPathToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!sub_00463740_FindRoomAtPoint(pRoom, nX, nY))
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_SYNC_WARPED))
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    const int nMask = sub_00648CD0(pPath);
    const int nPathType = PATH_GetType(pPath);
    const unsigned char nNewDistance = PATH_GetMaxDistance(pPath);
    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    const int nFirstX = D2COMMON_10175_PathGetFirstPointX(pPath);
    const int nFirstY = D2COMMON_10176_PathGetFirstPointY(pPath);

    PATH_SetMoveTestCollisionMask(pPath, 0x409);
    PATH_SetType(pPath, 15);
    sub_00648E70_SetDistance(pPath, 77);
    sub_00648AD0(pPath, nX, nY);

    int bResult = D2Common_10142(pPath, pUnit, 0);
    if (bResult)
    {
        if (nX == sub_00648A40(pPath) && nY == sub_00648A60(pPath))
        {
            bResult = 1;
        }
        else
        {
            bResult = 0;
        }
    }

    PATH_SetMoveTestCollisionMask(pPath, nMask);
    PATH_SetType(pPath, nPathType);
    sub_00648E70_SetDistance(pPath, nNewDistance);

    if (pTargetUnit)
    {
        sub_00648B90_SetPathTarget(pPath, pTargetUnit);
    }
    else
    {
        sub_00648AD0(pPath, nFirstX, nFirstY);
    }

    return bResult;
}

// 0x0054CC30
void __fastcall sub_0054CC30_ClearState(D2UnitStrc* unit, int state, int unused)
{
    STATES_ToggleState(unit, state, 0);
}

// 0x0054CC40
static int __stdcall sub_0054CC40_WarpToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    if (!sub_6FCBDFE0(pGame, pUnit, 0, nX, nY, 0, 1))
    {
        return 0;
    }

    CLIENTS_NotifyWarpAttempt(pGame, pUnit);

    int nDelay = 125;
    if (CLIENTS_ShouldDelayWarpAttempt(pGame, pUnit) && !pGame->nGameType)
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
        pSeed->lSeed = lSeed;
        int nRand = (unsigned int)lSeed % 100;
        for (int i = 0; i < 3; ++i)
        {
            if (nRand < gWarpDelays_006E1064[i].nChance)
            {
                nDelay = gWarpDelays_006E1064[i].nDelay;
                break;
            }

            nRand -= gWarpDelays_006E1064[i].nChance;
        }
    }

    const int nEndFrame = pGame->dwGameFrame + nDelay;
    STATES_ToggleState(pUnit, STATE_SYNC_WARPED, 1);

    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nEndFrame, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    sub_006252D0(pStatList, STATE_SYNC_WARPED);
    sub_00625CE0(pStatList, (unsigned int)sub_0054CC30_StatRemoveCallback_ToggleStateOff);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    sub_005417D0_DirectDated(pGame, pUnit, 12, nEndFrame, 0, 0);
    return 1;
}

// 0x0054CD50
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x5F_UpdatePlayerPos_6FC88530(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != sizeof(D2GSPacketClt5F))
    {
        return 3;
    }

    const int nX = ((D2GSPacketClt5F*)pPacket)->nX;
    const int nY = ((D2GSPacketClt5F*)pPacket)->nY;

    D2ClientStrc* hClient = UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 5654);
    D2_ASSERT(hClient, 5655);

    if (UNITS_GetUsedSkill(pUnit) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    const int nDistance = sub_006417F0_GetDistanceToXY(pUnit, nX, nY);
    if (nDistance < 5)
    {
        return 0;
    }

    if (!STATES_CheckState(pUnit, STATE_SYNC_WARPED) && nDistance >= 15 && nDistance <= 45)
    {
        if (!sub_0054CB10_TestPathToCoords(pGame, pUnit, nX, nY) || !sub_0054CC40_WarpToCoords(pGame, pUnit, nX, nY))
        {
            sub_6FC81CA0(pUnit, hClient, 0);
        }

        return 0;
    }

    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        sub_6FC817D0(pGame, pUnit, 0, ((!pUnit ? 0 : pUnit->dwAnimMode) == 3) + 2, nX, nY, 0);
    }

    return 0;
}

// 0x0054CE70
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x60_SwapWeapons_6FC888A0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (UNITS_GetUsedSkill(pUnit) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    int a3 = 0;
    if (sub_005616A0_SwapWeapons(pGame, pUnit, &a3) || !a3)
    {
        return 0;
    }

    return 3;
}

static inline int UNITS_GetAnimMode_H15(D2UnitStrc* pUnit)
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
    if (pMerc->dwClassId == MONSTER_ACT3HIRE && ITEMSIsA(pItem, 2))
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

static inline int sub_RemoveEquippedItem(D2UnitStrc* pMerc, D2UnitStrc* pItem)
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

// 0x0054D230
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

    switch (!pMerc ? -1 : (unsigned int)pMerc->dwClassId)
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
        if (!(ITEMSIsA(pItem, 2) || ITEMSIsA(pItem, 0x1E) && !ITEMS_CheckWeaponIfTwoHanded(pItem)))
        {
            break;
        }

        bCanBeEquipped = 1;
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
        return sub_0054D130_TakeMercItemToCursor(pGame, pMerc, pUnit, nBodyLoc);
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

    const int nResult = ((D2GameItemChecks*)ptGame)->sub_00549150_CheckStoredItem(pUnit, nItemGUID);
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

        if (ITEMS_GetInvPage(hItem) || hItem->dwAnimMode != IMODE_STORED)
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

// 0x0054D750
int __fastcall D2GAME_PACKET_Handler_6FC89320(D2GameStrc* pGame,D2UnitStrc* pUnit,unsigned char* pPacket,int nSize)
{
    unsigned char nHeader = *pPacket;
    if (!nHeader || nHeader >= 103) return 3;
    if (!sgcptIncomingMessageChart[nHeader].pfCallback) return 3;
    int bIgnore;
    switch (nHeader)
    {
    case 20: case 21: case 60: case 67: case 102:
        bIgnore = 0;
        break;
    case 32: case 38:
        bIgnore = !sub_0057EEC0(pGame,pUnit,1,0,0);
        break;
    case 65:
        bIgnore = 1;
        if (pUnit && pUnit->dwAnimMode == 17) bIgnore = 0;
        break;
    default:
        bIgnore = !sub_0057EEC0(pGame,pUnit,1,0,0);
        break;
    }
    if (!bIgnore)
    {
        if (pGame->nSyncTimer > 1) pGame->nSyncTimer = sub_00410A80_GetTimeSeconds();
        if (IsBadCodePtr((void*)sgcptIncomingMessageChart[nHeader].pfCallback))
        {
            sub_00408A60(&gszEmptyAssertText,sub_00408090(),6564);
            exit(-1);
        }
        return sgcptIncomingMessageChart[nHeader].pfCallback(pGame,pUnit,pPacket,nSize);
    }
    return 0;
}

// 0x0054D8A0
void __fastcall D2GAME_PLRMSG_Last_6FC89450(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    const bool bDefenderIsPlayer = pDefender && pDefender->dwUnitType == UNIT_PLAYER;
    D2_ASSERT(bDefenderIsPlayer, 0x19B4);

    if (pAttacker && pAttacker->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
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

// 0x0054DA10
void __fastcall sub_6FC820C0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    sub_6FC82010(pGame, pUnit, pClient, nAnimMode);

    if (pUnit == CLIENTS_GetPlayerFromClient(pClient, 0))
    {
        const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_GOLDLOST, 0);
        D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_GOLDLOST, nValue, pUnit);
    }
}

#include "gen/data/Source/D2Game/PLAYER/PlrMsg.inc"
