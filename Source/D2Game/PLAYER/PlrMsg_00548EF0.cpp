#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define PLRMODE_WALK 2
#define PLRMODE_RUN 3
#define PLRMODE_DEAD 17
#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
#define STAT_GOLDLOST 0xAF
#define STATE_INFERNO 12
#define STATE_UNINTERRUPTABLE 0x36
#define BODYLOC_RARM 4
#define BODYLOC_LARM 5
#define BODYLOC_BELT 8
#define EVENTTYPE_AITHINK 2
#define EVENTTYPE_PLAYERLEFT 3
#define CLIENTSAVEFLAG_HARDCORE 4
#define UNITFLAG_TARGETABLE 2
#define UNITFLAGEX_TELEPORTED 0x10000
#define MONSTATSFLAGINDEX_NPC 8
#define MONSTATSFLAGINDEX_INTERACT 9
struct D2GSPacketSrv26;
struct D2StaticPathStrc;
struct D2MonsterDataStrc;
struct D2PlayerDataStrc;
struct D2MonStatsTxt;
struct D2SkillsTxt;
struct D2GSPacketClt15;
struct D2GSPacketSrv26Args;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2PlayerDataStrc
{
    char unk0x000[0x168];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C - 0x08];
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x2C - 0x18];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x60 - 0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
    char f_74[0x34];
    int dwGameFrame;
    int sub_005490E0_CheckCursorItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x005490E0
    int sub_00549150_CheckStoredItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x00549150
    int sub_005492F0_CheckBeltItem(D2UnitStrc* pUnit, int nItemGUID);                                      // 0x005492F0
    int sub_005491B0_CheckStoredOrEquippedItem(D2UnitStrc* pUnit, int nItemGUID);                          // 0x005491B0
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nFlags[4];
};

struct D2SkillsTxt
{
    char unk0x00[0x04];
    unsigned char nFlags[8];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBA0];
    int nSkillsTxtRecordCount;
    unsigned char unk_BA4[0xB8];
    int nLevelsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit); // 0x00535E80
void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7); // 0x0053BC10
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall QUESTS_UseClueItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID); // 0x00544840
D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00547F50
void __fastcall sub_00549A60_SendCantDoThat(D2UnitStrc* pUnit); // 0x00549A60
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00
void __fastcall SUNIT_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTile); // 0x005550B0
int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x00557FF0
unsigned int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B6C0
void __fastcall D2GAME_PickupItemEx_6FC42B80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x0055CF50
int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nX, int nY, int* pItemStatus); // 0x0055E170
int __fastcall ITEMMODE_MergeItemStacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID1, int nItemGUID2, int* pItemStatus); // 0x0055E7C0
int __fastcall D2GAME_Return0_6FC48930(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x0055E9A0
int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus); // 0x0055EF20
int __fastcall sub_6FC45060(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0
int __fastcall ITEMMODE_UseItemOnItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetGUID, int nUseItemGUID, int* pItemStatus); // 0x00561ED0
int __fastcall ITEMMODE_UseBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nX, int nY, int* pItemStatus, int bUseOnMerc); // 0x00562390
int __fastcall ITEMMODE_PlaceItemInCube(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nCubeGUID, int* pItemStatus); // 0x005628C0
int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x00563560
void __fastcall PLRTRADE_TryToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x00566E60
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678A0
void __fastcall MONSTERAI_ActivateNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract); // 0x00572E60
void __fastcall MONSTERAI_EndNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract); // 0x00572F20
void __fastcall MONSTERAI_StartNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonsterInteractStrc* pMonInteract, char nQuestFlags); // 0x00573020
int __fastcall NPC_HandleDialogMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nType, int nNpcGUID, int nItemGUID); // 0x00579D60
void __fastcall sub_0057FB70_PickUpCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody); // 0x0057FB70
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
void __fastcall D2GAME_PLAYERMODE_Change_6FC81A00(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70
int __fastcall OBJMODE_OperateObjectInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectType, int nObjectGUID); // 0x00584540
void __fastcall OBJMODE_UpdateDoorModeFromCollision(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID); // 0x005845D0
void __fastcall sub_00584F60(D2GameStrc* pGame, D2UnitStrc* pUnit, int nWaypointGUID, int nLevelId); // 0x00584F60
int __fastcall OBJMODE_MainObeliskHandler(D2GameStrc* pGame, int nPlayerGUID, int nObjectGUID, int nItemGUID, short nState); // 0x005852E0
void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue); // 0x0058EC00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall sub_00622B50_TestInteractCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMask); // 0x00622B50
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit); // 0x00622DC0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00623660
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem); // 0x0062A4E0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD50
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00641530
void __fastcall sub_00641F20_SetPlayerModeState(D2UnitStrc* pUnit, int nMode, int nArg1, int nArg2); // 0x00641F20
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00643860
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill); // 0x00644530
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00645460
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00647960
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath); // 0x00648730
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo); // 0x00660E00
int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField); // 0x00660E50
static __declspec(noinline) int __stdcall PLRMSG_UseSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nUnitType, int nUnitGUID, int bCheckRange); // 0x00549BA0

struct D2GSPacketClt15
{
    char unk0x00[0x103];
    char szName[16];
};

struct D2GSPacketSrv26Args
{
    D2GSPacketSrv26* pPacket26;
    D2GSPacketClt15* pPacket15;
    int nUnitId;
};

int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars); // 0x00413590
void __fastcall GAME_DisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType); // 0x0052CAF0
int __fastcall sub_6FC7C260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, unsigned int nValue); // 0x00535510
int __fastcall sub_6FC7C3A0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00535610
int __fastcall sub_6FC7C450(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nHotkeyId, short nSkillId, int nHand, int nFlags); // 0x005356B0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, int nFlag); // 0x00538670
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient); // 0x005387C0
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket); // 0x0053C750
int __fastcall ARENA_IsActive(D2GameStrc* pGame); // 0x0053FD10
int __fastcall ARENA_Return0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0053FDF0
void __fastcall sub_6FC82010(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode); // 0x00548350
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pInteractUnitType, int* pInteractUnitGUID); // 0x00554100
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag); // 0x0055B300
int __fastcall sub_6FC48D50(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCursorItemGUID, int nBeltItemGUID, int* a5); // 0x0055EB30
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
int __fastcall sub_6FC45B30(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nBodyLoc, int bSetQuantityFlag, int* a5); // 0x00560CD0
int __fastcall sub_00560F00(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* a6); // 0x00560F00
int __fastcall sub_6FC46840(D2GameStrc* pGame, D2UnitStrc* pUnit, int* a3); // 0x005616A0
int __fastcall sub_6FC48B40(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4); // 0x00562250
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9); // 0x00562660
int __fastcall sub_6FC93740(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00567840
void __fastcall sub_6FD11AE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0056C6A0
void __fastcall D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc* pUnit); // 0x0056DFA0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0
int __fastcall PLAYERSTATS_SpendStatPoint(D2UnitStrc* pUnit, int nStatId); // 0x00570D60
int __fastcall PARTYSCREEN_CommandHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCommand, int nArg, int nArg2); // 0x005A6000
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

inline int PLRMSG_IsBodyLocValid(int nBodyLoc)
{
    return nBodyLoc > 0 && nBodyLoc < 11;
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
        return pUnit->pStaticPath->nX;
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
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static __declspec(noinline) void __stdcall sub_00548A50_ChangeModeAndSetInteract(int nInteractSkill, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID)
{
    D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pPlayer, 0, 3, nUnitType, nUnitGUID, 0);
    sub_00641F20_SetPlayerModeState(pPlayer, nInteractSkill, nUnitType, nUnitGUID);
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
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nFlags[1] & gdwBitMasks[1] && pMonStatsTxtRecord->nFlags[1] & gdwBitMasks[0])
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

// build: context sub_00548F80_CheckTargetUnit
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

    return sub_6FC83C60(PLRMSG_GetUnitX(pTarget), PLRMSG_GetUnitY(pTarget), pPlayer, nMaxDistance);
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

// 0x00549350
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

// 0x00549520
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
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrMsg.cpp", 1639);
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

    D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, 0, 2, nUnitType, nUnitGUID, 0);
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

    D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, 0, 3, nUnitType, nUnitGUID, 0);
    return 0;
}

// 0x00549960
static __declspec(noinline) D2SkillStrc* __stdcall sub_6FC83450(D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    D2SkillStrc* pUsedSkill = pSkill;
    if (!SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrMsg.cpp", 1804))
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

        if (pRightWeapon && pLeftWeapon && ITEMS_CheckItemTypeId(pRightWeapon, 45) && ITEMS_CheckItemTypeId(pLeftWeapon, 45))
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

// 0x00549AD0
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
        D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, pSkill, nSkillMode, nUnitType, nUnitGUID, 0);
        return 0;
    }

    const int nSkillRange = D2Common_11016(pUnit, pSkill);
    if (nSkillRange == 1)
    {
        if (UNITS_IsInMeleeRange(pUnit, pOtherUnit, UNITS_IsInMovingModeEx(pOtherUnit)))
        {
            D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, pSkill, nSkillMode, nUnitType, nUnitGUID, 0);
            return 0;
        }
    }
    else if (nSkillRange != 4)
    {
        D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, pSkill, nSkillMode, nUnitType, nUnitGUID, 0);
        return 0;
    }

    sub_00548A50_ChangeModeAndSetInteract(SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrMsg.cpp", 2013), pGame, pUnit, nUnitType, nUnitGUID);
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

// build: context D2GAME_PACKETCALLBACK_Rcv0x1A_EquipItem_6FC85280
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
    if (sub_6FC45060(pGame, pUnit, nItemGUID, nBodyLoc, 0, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    return 3;
}

// build: context D2GAME_PACKETCALLBACK_Rcv0x20_UseGridItem_6FC85990
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x20_UseGridItem_6FC85990(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nX = *(int*)((char*)pPacket + 5);
    const int nY = *(int*)((char*)pPacket + 9);
    if (nSize != 13)
    {
        return 3;
    }

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

    int nItemStatus = 0;
    if (ITEMMODE_UseStoredItemAtCoordinates(pGame, pUnit, nItemGUID, nX, nY, &nItemStatus) || !nItemStatus)
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

// build: context D2GAME_PACKETCALLBACK_Rcv0x2F_InitEntityChat_6FC868C0
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

    OBJMODE_UpdateDoorModeFromCollision(pGame, pUnit, nObjectGUID);
    return 0;
}

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

    if (!ITEMS_IsInPlayersInventory(pUnit, pItem, 0))
    {
        const unsigned char nUnitAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
        if (nUnitAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pItem))))
        {
            return 2;
        }

        const int nResult = sub_6FC83C60(PLRMSG_GetUnitX(pItem), PLRMSG_GetUnitY(pItem), pUnit, 10);
        if (nResult)
        {
            return nResult;
        }
    }

    QUESTS_UseClueItem(pGame, pUnit, nItemGUID);
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

// build: context D2GAME_PACKETCALLBACK_Rcv0x49_TakeOrCloseWp_6FC87E60
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

int gbWhispReceiverNotListening_6FD4DC24; // 0x008846E0

int gbWhispReceiverInGame_6FD4DC20; // 0x008846E4

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

// 0x0054AB40
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x17_DropItemOnGround_6FC84E20(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
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
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x18_InsertItemInBuffer_6FC84ED0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 17)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nX = *(int*)((char*)pPacket + 5);
    const int nY = *(int*)((char*)pPacket + 9);
    const unsigned int nInvPage = *(unsigned int*)((char*)pPacket + 13);
    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
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
        if (!sub_6FC45B30(pGame, pUnit, nBodyLoc, 0, &a5) && a5)
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
    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
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
    if (sub_00560F00(pGame, pUnit, nItemGUID, nBodyLoc, 0, &a5) || !a5)
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
    const int nResult = pGame->sub_005492F0_CheckBeltItem(pUnit, nItemGUID);
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
    int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nCursorItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = pGame->sub_005492F0_CheckBeltItem(pUnit, nBeltItemGUID);
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

// 0x0054B650
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x28_SocketItem_6FC86310(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nCursorItemGUID = *(int*)((char*)pPacket + 1);
    const int nSocketableItemGUID = *(int*)((char*)pPacket + 5);
    int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nCursorItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = pGame->sub_005491B0_CheckStoredOrEquippedItem(pUnit, nSocketableItemGUID);
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

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrMsg.cpp", 4579);
    if (CLIENTS_CheckFlag(pClient, CLIENTSAVEFLAG_HARDCORE))
    {
        GAME_DisconnectClient(pGame, pClient, EVENTTYPE_PLAYERLEFT);
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
    if (pNpc && D2Common_10399(pUnit, pNpc) <= 50)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pNpc->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nFlags[MONSTATSFLAGINDEX_INTERACT >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_INTERACT & 7] && pMonStatsTxtRecord->nFlags[MONSTATSFLAGINDEX_NPC >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NPC & 7])
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
    if (sub_6FC46840(pGame, pUnit, &a3) || !a3)
    {
        return 0;
    }

    return 3;
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
