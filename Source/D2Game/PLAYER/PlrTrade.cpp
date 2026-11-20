#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define INVPAGE_CUBE 3
#define STRCOLOR_WHITE 0
#define EVENTTYPE_PLAYERISBUSY 8
#define EVENTTYPE_PLEASEWAIT 9
struct D2ObjectControlStrc;
struct D2PlayerTradeStrc;
struct D2ObjOperateFnStrc;
struct D2PlayerDataStrc;
struct D2SystemTimeStrc;
struct D2CubeItemStrc;
struct D2GSPacketSrv78;
struct Item;
struct ItemRecordTable;


void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

void __fastcall PLRTRADE_StopAllPlayerInteractions(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00568640

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

enum
{
    OBJECT_STASH = 0x10B,
    UPDATEUI_OPENSTASH = 0x10,
};

void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

struct D2PlayerTradeStrc
{
    int nSaveLength;
    unsigned char* pSaveData;
    void* pItemTrade;
    int nGoldInTrade;
    int nGoldInTradeOtherPlayer;
    int nNextUpdateTick;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    char unk0x10[0x40];
    int dwTradeState;
    unsigned int unk0x54;
    unsigned int dwAcceptTradeTick;
    D2PlayerTradeStrc* pTrade;
};

struct D2CubeMainTxt
{
    unsigned char nEnabled;
    unsigned char nLadder;
    unsigned char nMinDiff;
    unsigned char nClass;
    unsigned char nOp;
    char unk0x05[0x03];
    int nParam;
    int nValue;
    unsigned char nNumInputs;
    char unk0x11;
    unsigned short wVersion;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x18];
    unsigned char nValShift;
};


struct D2CubeItemStrc
{
    int nItemId;
    int nQuality;
    int nQuantity;
};

#pragma pack(push, 1)
struct D2GSPacketSrv78
{
    unsigned char nHeader;
    char szName[16];
    unsigned char nUnk0x11;
    int dwPlayerGUID;
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime); // 0x006CC1D4
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern int gbEnableAllCubeRecipes_0088CAC0; // 0x0088CAC0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall sub_00531BB0_WriteItemList(void* pArg1, void* pArg2, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7); // 0x00531BB0
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, int nFlag); // 0x00538670
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
void __fastcall sub_0053CAD0_SendPacket0x78(D2ClientStrc* pClient, D2GSPacketSrv78* pPacket); // 0x0053CAD0
void __fastcall D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(D2ClientStrc* pClient, int nGold, char bOwnGold); // 0x0053CBE0
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue); // 0x0053FF00
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0
void __fastcall ITEMS_HandleGoldTransaction(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue); // 0x0055B060
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine); // 0x0055F590
void __fastcall ITEMMODE_ResetBookScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055F9C0
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
int __fastcall ITEMMODE_DuplicateSocketFillers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pSocketable, int bRefresh); // 0x00563350
void __fastcall PLRTRADE_CreateCubeOutputs(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2CubeMainTxt* pCubeMainTxtRecord, D2CubeItemStrc* pCubeItem, int nArg5); // 0x00565AB0
int __fastcall PLRTRADE_CheckCubeInput(D2GameStrc* pGame, D2InventoryStrc* pInventory, D2CubeMainTxt* pCubeMainTxtRecord, int nInputIndex, D2CubeItemStrc* pCubeItem, int* pUsedItems); // 0x00565010
void __fastcall PLRTRADE_Free(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00566BF0
void __fastcall sub_6FC91050(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, D2PlayerDataStrc* pPlayerData1, D2PlayerDataStrc* pPlayerData2, int nTradeState); // 0x005679E0
int __fastcall sub_00597A20_IsBusy(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00597A20
int __fastcall ACT4Q2_HasDiabloBeenKilled(D2GameStrc* pGame); // 0x005B5810
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell); // 0x00628320
int __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem); // 0x006283A0
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
static void __stdcall PLRTRADE_HandleCubeInteraction(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005665F0

struct Seed { unsigned low,high; };

struct Game { char pad0[0x78]; unsigned short format; char pad7A[0x56]; Seed seed; };

struct Item { char pad0[0xF6]; unsigned short format; char padF8[5]; unsigned char level; char padFE[0x35]; unsigned char spawnable; char pad134[0x74]; };

struct ItemRecordTable { int count; Item* records; };

ItemRecordTable* __stdcall sub_00633590(); // 0x00633590
unsigned __fastcall sub_0045C3E0(Seed*,int); // 0x0045C3E0
int __stdcall sub_00629A90(int,int); // 0x00629A90

enum { EXPANSION_FORMAT = 100 };

int __fastcall ACT1Q4_CreateCowPortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00594140
int __fastcall ACT1Q4_CreateUberRunPortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00594270
int __fastcall ACT1Q4_CreateUberFinalePortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00594280

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
void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket); // 0x0053C850
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
void __fastcall PLRTRADE_SendEventPacketToPlayer(D2UnitStrc* pPlayer, unsigned char nType, char* szSource); // 0x00566D90
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0
void __fastcall sub_6FC4BA50(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0055FCC0
void __fastcall sub_6FC90BE0(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x00566C80
void __fastcall sub_6FC90C20(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00566CC0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70

// 0x00564CB0
void __fastcall sub_00564CB0_Nop(D2UnitStrc* pUnit)
{
}

// 0x00567330
void __fastcall sub_6FC92EF0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    SUNIT_ResetInteractInfo(pUnit);
    sub_6FC4B830(pGame, pUnit);
}

// 0x00568760
void __fastcall sub_00568760_ResetPlayerInteract(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    PLRTRADE_StopAllPlayerInteractions(pGame, pUnit);
}

// 0x00568D80
int __fastcall sub_00568D80_FindTerminator(const char* szText, int nSize)
{
    const char* pStart = szText;
    const char* pEnd = szText + nSize;
    while (szText < pEnd && *szText)
    {
        ++szText;
    }

    if (szText >= pEnd)
    {
        return -1;
    }

    return szText - pStart;
}

// 0x00564CD0
int __fastcall sub_00564CD0_OperateStash(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (pOp->nObjectIdx == OBJECT_STASH)
    {
        D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(pOp->pPlayer);
        if (pPlayerRoom && DUNGEON_IsRoomInTown(pPlayerRoom))
        {
            D2ActiveRoomStrc* pObjectRoom = UNITS_GetRoom(pOp->pObject);
            if (pObjectRoom && DUNGEON_IsRoomInTown(pObjectRoom))
            {
                SUNIT_SetInteractInfo(pOp->pPlayer, UNIT_OBJECT, !pOp->pObject ? -1 : pOp->pObject->dwUnitId);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pOp->pPlayer, ".\\PLAYER\\PlrTrade.cpp", 101), UPDATEUI_OPENSTASH);
                sub_6FC4B830(pOp->pGame, pOp->pPlayer);
            }
        }
    }

    return 0;
}

// 0x00564D50
static void __stdcall sub_00564D50_HandleStashButton(D2GameStrc* pGame, unsigned short nButton, D2UnitStrc* pPlayer, int nUnitGUID, int nGold)
{
    int nUnitType;
    int nGUID;
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, nUnitGUID);
    if (!pObject || pObject->dwClassId != 0x10B)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
    {
        return;
    }

    pRoom = UNITS_GetRoom(pObject);
    if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
    {
        return;
    }

    switch (nButton)
    {
    case 0x12:
    {
        if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nGUID) && nUnitType == 2)
        {
            SUNIT_ResetInteractInfo(pPlayer);
        }
        sub_6FC4B830(pGame, pPlayer);
        break;
    }
    case 0x13:
    {
        if (nGold > 0 && nGold <= STATLIST_UnitGetStatValue(pPlayer, 0xF, 0))
        {
            if (STATLIST_UnitGetStatValue(pPlayer, 0xE, 0) + nGold <= UNITS_GetInventoryGoldLimit(pPlayer))
            {
                ITEMS_HandleGoldTransaction(pGame, pPlayer, nGold);
                PLRTRADE_AddGold(pPlayer, 0xF, -nGold);
            }
            else
            {
                SUNIT_AttachSound(pPlayer, 0x13, pPlayer);
            }
        }
        break;
    }
    case 0x14:
    {
        if (nGold > 0 && nGold <= STATLIST_UnitGetStatValue(pPlayer, 0xE, 0))
        {
            const unsigned int nStashGoldLimit = UNITS_GetStashGoldLimit(pPlayer);
            const unsigned int nGoldBank = STATLIST_UnitGetStatValue(pPlayer, 0xF, 0);
            if (nGoldBank + nGold > nStashGoldLimit)
            {
                if (nGoldBank < nStashGoldLimit)
                {
                    PLRTRADE_AddGold(pPlayer, 0xF, nStashGoldLimit - nGoldBank);
                    PLRTRADE_AddGold(pPlayer, 0xE, nGoldBank - nStashGoldLimit);
                }
            }
            else
            {
                PLRTRADE_AddGold(pPlayer, 0xE, -nGold);
                PLRTRADE_AddGold(pPlayer, 0xF, nGold);
            }
        }
        break;
    }
    }
}

// 0x00564FD0
static __declspec(noinline) int sub_00564FD0_CountCubeItems(D2InventoryStrc* pInventory)
{
    int nCount = 0;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (ITEMS_GetInvPage(pCheckedItem) == 3)
        {
            ++nCount;
        }
    }
    return nCount;
}

// 0x005658C0
static __declspec(noinline) int __stdcall sub_005658C0_CheckCubeInputs(D2GameStrc* pGame, D2CubeItemStrc* pCubeItem, D2CubeMainTxt* pCubeMainTxtRecord, D2InventoryStrc* pInventory)
{
    if (!pInventory || !pCubeMainTxtRecord)
    {
        return 0;
    }

    int anUsedItems[48];
    memset(anUsedItems, 0, sizeof(anUsedItems));
    for (int nInput = 0; nInput < 7; ++nInput)
    {
        if (!PLRTRADE_CheckCubeInput(pGame, pInventory, pCubeMainTxtRecord, nInput, pCubeItem, anUsedItems))
        {
            return 0;
        }
    }
    return 1;
}

// build: context PLRTRADE_HandleCubeInteraction
static void __stdcall PLRTRADE_HandleCubeInteraction(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (!pPlayer)
    {
        return;
    }

    const int nRecordCount = DATATBLS_GetCubemainTxtRecordCount();
    const int nItemsInCube = sub_00564FD0_CountCubeItems(pPlayer->pInventory);
    if (nItemsInCube <= 0)
    {
        return;
    }

    D2SystemTimeStrc tSystemTime;
    GetLocalTime(&tSystemTime);
    const int nDayOfWeek = tSystemTime.wDayOfWeek + 1;
    for (int nId = 0; nId < nRecordCount; ++nId)
    {
        D2CubeMainTxt* pRecord = DATATBLS_GetCubemainTxtRecord(nId);
        if (!pRecord)
        {
            return;
        }

        if ((pRecord->nEnabled || gbEnableAllCubeRecipes_0088CAC0)
            && (pGame->bExpansion || pRecord->wVersion < 100)
            && (pGame->nGameType || pGame->dwGameType || !pRecord->nLadder)
            && pRecord->nMinDiff <= pGame->nDifficulty
            && (pRecord->nClass == 0xFF || pRecord->nClass == sub_00451F60_UnitClassId(pPlayer))
            && pRecord->nNumInputs == nItemsInCube)
        {
            switch (pRecord->nOp)
            {
            case 1:
                if (pRecord->nParam > tSystemTime.wDay)
                {
                    continue;
                }

                if (pRecord->nValue < tSystemTime.wDay)
                {
                    continue;
                }
                break;
            case 2:
                if (pRecord->nValue != nDayOfWeek)
                {
                    continue;
                }
                break;
            case 3:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (STATLIST_UnitGetStatValue(pPlayer, pRecord->nParam, 0) < nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            case 4:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (STATLIST_UnitGetStatValue(pPlayer, pRecord->nParam, 0) > nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            case 5:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (STATLIST_UnitGetStatValue(pPlayer, pRecord->nParam, 0) == nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            case 6:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (STATLIST_UnitGetStatValue(pPlayer, pRecord->nParam, 0) != nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            case 7:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (STATLIST_GetUnitBaseStat(pPlayer, pRecord->nParam, 0) < nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            case 8:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (STATLIST_GetUnitBaseStat(pPlayer, pRecord->nParam, 0) > nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            case 9:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (STATLIST_GetUnitBaseStat(pPlayer, pRecord->nParam, 0) == nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            case 10:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (STATLIST_GetUnitBaseStat(pPlayer, pRecord->nParam, 0) != nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            case 11:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (sub_00625560(pPlayer, pRecord->nParam, 0) < nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            case 12:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (sub_00625560(pPlayer, pRecord->nParam, 0) > nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            case 13:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (sub_00625560(pPlayer, pRecord->nParam, 0) == nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            case 14:
                if (pRecord->nParam >= 0 && pRecord->nParam <= sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pRecord->nParam);
                    if (!pItemStatCostTxtRecord)
                    {
                        continue;
                    }

                    const int nShiftedValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                    if (sub_00625560(pPlayer, pRecord->nParam, 0) != nShiftedValue)
                    {
                        continue;
                    }
                }
                break;
            default:
                break;
            }

            D2CubeItemStrc aCubeItems[3];
            memset(aCubeItems, 0, sizeof(aCubeItems));
            if (sub_005658C0_CheckCubeInputs(pGame, aCubeItems, pRecord, pPlayer->pInventory))
            {
                PLRTRADE_CreateCubeOutputs(pGame, pPlayer, pRecord, aCubeItems, 1);
                return;
            }
        }
    }
}

// 0x00566AE0
static __declspec(noinline) void sub_00566AE0_HandleCubeButton(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nButton)
{
    switch (nButton)
    {
    case 0x17:
    {
        int nUnitType;
        int nGUID;
        if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nGUID) && nUnitType == 4)
        {
            SUNIT_ResetInteractInfo(pPlayer);
        }
        sub_6FC4B830(pGame, pPlayer);
        break;
    }
    case 0x18:
        PLRTRADE_HandleCubeInteraction(pGame, pPlayer);
        break;
    }
}

// 0x00566B30
static __declspec(noinline) bool PLRTRADE_AllocPlayerTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData->pTrade)
    {
    D2PlayerTradeStrc* pTrade = (D2PlayerTradeStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PlayerTradeStrc), ".\\PLAYER\\PlrTrade.cpp", 0x806, 0);
    pTrade->pSaveData = (unsigned char*)FOG_AllocPool(pGame->pMemoryPool, 0x2000, ".\\PLAYER\\PlrTrade.cpp", 0x807, 0);
    pTrade->nSaveLength = sub_00531BB0_WriteItemList(pGame, pPlayer, pTrade->pSaveData, 0x2000, 0, 0, 0);
    D2_ASSERT(pTrade->nSaveLength > 0, 0x809);
    pTrade->pItemTrade = 0;
    pTrade->nGoldInTrade = 0;
    pTrade->nNextUpdateTick = 0;
    pTrade->nGoldInTradeOtherPlayer = STATLIST_UnitGetStatValue(pPlayer, 0xE, 0);
    pPlayerData->pTrade = pTrade;
    return true;
    }

    return false;
}

// 0x00567020
static void __stdcall sub_00567020_StartTrade(D2UnitStrc* pPlayer, D2UnitStrc* pInteractPlayer, D2PlayerDataStrc* pPlayerData, D2PlayerDataStrc* pInteractPlayerData)
{
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 2422), 6);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 2423), 6);

    pPlayerData->dwTradeState = 3;
    pInteractPlayerData->dwTradeState = 3;
}

// 0x00567070
static __declspec(noinline) void __stdcall sub_00567070_CopyEarData(int bHardcore, D2UnitStrc* pItem, D2UnitStrc* pDupeItem)
{
    if (ITEMS_GetItemType(pDupeItem) == 7)
    {
        ITEMS_SetEarName(pDupeItem, ITEMS_GetEarName(pItem));
        ITEMS_SetEarLevel(pDupeItem, ITEMS_GetEarLevel(pItem));
        ITEMS_SetItemFlag(pDupeItem, 0x8000, bHardcore);
    }
    else if (ITEMS_CheckItemFlag(pDupeItem, 0x1000000, 0x9AD, ".\\PLAYER\\PlrTrade.cpp"))
    {
        ITEMS_SetEarName(pDupeItem, ITEMS_GetEarName(pItem));
    }
}

static bool __stdcall PLRTRADE_TransferItems(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, D2GameStrc* pGame)
{
    const int bHardcore = CLIENTS_CheckFlag(SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x9BB), 4);
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pPlayer1->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (ITEMS_GetInvPage(pCheckedItem) == 2)
        {
            D2UnitStrc* pDupeItem = ITEMS_Duplicate(pGame, pCheckedItem, 0, 0);
            if (pDupeItem)
            {
                sub_00567070_CopyEarData(bHardcore, pCheckedItem, pDupeItem);
                UNITS_ChangeAnimMode(pDupeItem, 4);
                ITEMS_SetInvPage(pDupeItem, 0);
                if (!D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrTrade.cpp", 0x9CF, pGame, pPlayer2, pDupeItem->dwUnitId, 0, 0, 1, 1, 0))
                {
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x9D1), 0xA);
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 0x9D2), 9);
                    return false;
                }

                if (sub_0055F590_CheckItem(pCheckedItem, ".\\PLAYER\\PlrTrade.cpp", 0x9D5) && !ITEMMODE_DuplicateSocketFillers(pGame, pPlayer2, pCheckedItem, pDupeItem, 1))
                {
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x9D9), 0xA);
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 0x9DA), 9);
                    return false;
                }
            }
        }
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x9E4);
    pItem = INVENTORY_GetFirstItem(pPlayer1->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCurrentItem = pItem;
        pItem = INVENTORY_GetNextItem(pItem);
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pCurrentItem);
        const unsigned char nInvPage = ITEMS_GetInvPage(pCheckedItem);
        if (nInvPage != 1)
        {
            if (nInvPage != 2)
            {
                continue;
            }

            ITEMMODE_ResetBookScrollSkillQuantity(pPlayer1, pCheckedItem);
        }

        int nFlags = 0;
        ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
        ITEMS_SetItemCell(pCheckedItem, nInvPage);
        D2GAME_UpdateClientItem_6FC3E9D0(pClient, pPlayer1, pCheckedItem, nFlags);
        D2GAME_RemoveItem_6FC471F0(pGame, pPlayer1, pCheckedItem, 0);
    }
    return true;
}

// 0x005672D0
static __declspec(noinline) int __stdcall sub_005672D0_CanPickUpTradeItems(D2GameStrc* pGame, D2UnitStrc* pReceiver, D2UnitStrc* pOwner)
{
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pOwner->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (ITEMS_GetInvPage(pCheckedItem) == 2 && !ITEMMODE_CanPickUpItem(pGame, pReceiver, pCheckedItem))
        {
            return 0;
        }
    }
    return 1;
}

// 0x00567B00
static void __stdcall PLRTRADE_ResetTrade(D2PlayerDataStrc* pPlayerData1, D2PlayerDataStrc* pPlayerData2, D2UnitStrc* pPlayer2, D2UnitStrc* pPlayer1, D2GameStrc* pGame)
{
    sub_6FC4B830(pGame, pPlayer1);
    sub_6FC4B830(pGame, pPlayer2);
    UNITS_RefreshInventory(pPlayer1, 1);
    UNITS_RefreshInventory(pPlayer2, 1);
    if (pPlayer1)
    {
        pPlayer1->dwFlagEx |= 0x800000;
    }
    if (pPlayer2)
    {
        pPlayer2->dwFlagEx |= 0x800000;
    }
    pPlayerData1->pTrade->nGoldInTrade = 0;
    pPlayerData2->pTrade->nGoldInTrade = 0;
    sub_6FC90AE0(pGame, pPlayer1, 1);
    sub_6FC90AE0(pGame, pPlayer2, 1);
    D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x991), 0, 0);
    D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x992), 0, 1);
    D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(SUNIT_GetClientFromPlayer(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 0x993), 0, 0);
    D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(SUNIT_GetClientFromPlayer(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 0x994), 0, 1);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x995), 6);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 0x996), 6);
    pPlayerData1->dwTradeState = 5;
    pPlayerData2->dwTradeState = 5;
    sub_6FC4B830(pGame, pPlayer1);
    sub_6FC4B830(pGame, pPlayer2);
    EVENT_SetEvent(pGame, pPlayer1, 0xD, pGame->dwGameFrame + 1, 0, 0);
    EVENT_SetEvent(pGame, pPlayer2, 0xD, pGame->dwGameFrame + 1, 0, 0);
}

static void __stdcall sub_00567C70_AcceptTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pInteractPlayer, D2PlayerDataStrc* pPlayerData, D2PlayerDataStrc* pInteractPlayerData)
{
    {
        D2PlayerTradeStrc* pTrade = pPlayerData->pTrade;
        if (pTrade->nGoldInTrade)
        {
            if (STATLIST_UnitGetStatValue(pPlayer, 0xE, 0) < pTrade->nGoldInTrade)
            {
                PLRTRADE_ResetTrade(pPlayerData, pInteractPlayerData, pInteractPlayer, pPlayer, pGame);
                return;
            }

            if ((unsigned int)(STATLIST_UnitGetStatValue(pInteractPlayer, 0xE, 0) + pTrade->nGoldInTrade) > (unsigned int)UNITS_GetInventoryGoldLimit(pInteractPlayer))
            {
                PLRTRADE_ResetTrade(pPlayerData, pInteractPlayerData, pInteractPlayer, pPlayer, pGame);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA2D), 0xA);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA2E), 9);
                return;
            }
        }
    }

    {
        D2PlayerTradeStrc* pTrade = pInteractPlayerData->pTrade;
        if (pTrade->nGoldInTrade)
        {
            if (STATLIST_UnitGetStatValue(pInteractPlayer, 0xE, 0) < pTrade->nGoldInTrade)
            {
                PLRTRADE_ResetTrade(pPlayerData, pInteractPlayerData, pInteractPlayer, pPlayer, pGame);
                return;
            }

            if ((unsigned int)(STATLIST_UnitGetStatValue(pPlayer, 0xE, 0) + pTrade->nGoldInTrade) > (unsigned int)UNITS_GetInventoryGoldLimit(pPlayer))
            {
                PLRTRADE_ResetTrade(pPlayerData, pInteractPlayerData, pInteractPlayer, pPlayer, pGame);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA41), 9);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA42), 0xA);
                return;
            }
        }
    }

    int nTradeState = 0;
    if (!INVENTORY_CanItemsBeTraded(pGame->pMemoryPool, pPlayer, pInteractPlayer, &nTradeState))
    {
        pPlayerData->pTrade->nGoldInTrade = 0;
        pInteractPlayerData->pTrade->nGoldInTrade = 0;
        if (nTradeState)
        {
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA51), 9);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA52), 0xA);
            PLRTRADE_ResetTrade(pPlayerData, pInteractPlayerData, pInteractPlayer, pPlayer, pGame);
        }
        else
        {
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA56), 0xA);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA57), 9);
            PLRTRADE_ResetTrade(pPlayerData, pInteractPlayerData, pInteractPlayer, pPlayer, pGame);
        }
        return;
    }

    if (sub_005672D0_CanPickUpTradeItems(pGame, pInteractPlayer, pPlayer) && sub_005672D0_CanPickUpTradeItems(pGame, pPlayer, pInteractPlayer))
    {
        if (pPlayer)
        {
            pPlayer->dwFlagEx |= 0x800000;
        }
        if (pInteractPlayer)
        {
            pInteractPlayer->dwFlagEx |= 0x800000;
        }
        pPlayerData->dwTradeState = 9;
        pInteractPlayerData->dwTradeState = 9;
        EVENT_SetEvent(pGame, pPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
        EVENT_SetEvent(pGame, pInteractPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);

        if (!PLRTRADE_TransferItems(pPlayer, pInteractPlayer, pGame))
        {
            PLRTRADE_ResetTrade(pPlayerData, pInteractPlayerData, pInteractPlayer, pPlayer, pGame);
            return;
        }

        if (PLRTRADE_TransferItems(pInteractPlayer, pPlayer, pGame))
        {
            D2PlayerTradeStrc* pTrade = pPlayerData->pTrade;
            if (pTrade->nGoldInTrade)
            {
                const int nGold = pTrade->nGoldInTrade;
                if (STATLIST_UnitGetStatValue(pPlayer, 0xE, 0) >= nGold)
                {
                    PLRTRADE_AddGold(pPlayer, 0xE, -nGold);
                }
                ITEMS_HandleGoldTransaction(pGame, pInteractPlayer, pTrade->nGoldInTrade);
            }

            D2PlayerTradeStrc* pInteractTrade = pInteractPlayerData->pTrade;
            if (pInteractTrade->nGoldInTrade)
            {
                const int nGold = pInteractTrade->nGoldInTrade;
                if (STATLIST_UnitGetStatValue(pInteractPlayer, 0xE, 0) >= nGold)
                {
                    PLRTRADE_AddGold(pInteractPlayer, 0xE, -nGold);
                }
                ITEMS_HandleGoldTransaction(pGame, pPlayer, pInteractTrade->nGoldInTrade);
            }

            SUNIT_ResetInteractInfo(pPlayer);
            SUNIT_ResetInteractInfo(pInteractPlayer);
            PLRTRADE_Free(pGame, pPlayer);
            PLRTRADE_Free(pGame, pInteractPlayer);
            sub_6FC4B830(pGame, pPlayer);
            sub_6FC4B830(pGame, pInteractPlayer);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA9C), 0xD);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA9D), 0xD);
            return;
        }
    }

    PLRTRADE_ResetTrade(pPlayerData, pInteractPlayerData, pInteractPlayer, pPlayer, pGame);
}

int __fastcall PLRTRADE_HandleTradeButton(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nButton, unsigned int nGold)
{
    if (!pPlayer)
    {
        return 1;
    }

    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID))
    {
        if (nButton >= 0x12 && nButton <= 0x14)
        {
            if (nUnitType != 2)
            {
                return 1;
            }

            sub_00564D50_HandleStashButton(pGame, nButton, pPlayer, nUnitGUID, nGold);
            return 0;
        }

        if (nButton >= 0x17 && nButton <= 0x18)
        {
            if (nUnitType != 4)
            {
                return 3;
            }

            sub_00566AE0_HandleCubeButton(pGame, pPlayer, nButton);
            return 0;
        }

        if (nUnitType != 0)
        {
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB31), 0xD);
            return 3;
        }

        D2UnitStrc* pInteractPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
        if (pInteractPlayer)
        {
            D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
            D2PlayerDataStrc* pInteractPlayerData = UNITS_GetPlayerData(pInteractPlayer);
            switch (nButton)
            {
            case 2:
            {
                if (pPlayerData->dwTradeState != 2 && pPlayerData->dwTradeState != 1 || pInteractPlayerData->dwTradeState != 2 && pInteractPlayerData->dwTradeState != 1)
                {
                    if (sub_00597A20_IsBusy(pGame, pPlayer) || sub_00597A20_IsBusy(pGame, pInteractPlayer))
                    {
                        return 0;
                    }

                    sub_6FC91050(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 9);
                    const unsigned int nTickCount = GetTickCount();
                    pInteractPlayerData->dwAcceptTradeTick = nTickCount;
                    pPlayerData->dwAcceptTradeTick = nTickCount;
                }
                else
                {
                    sub_6FC91050(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 9);
                    const unsigned int nTickCount = GetTickCount();
                    pInteractPlayerData->dwAcceptTradeTick = nTickCount;
                    pPlayerData->dwAcceptTradeTick = nTickCount;
                }
                break;
            }
            case 3:
            {
                if (sub_00597A20_IsBusy(pGame, pPlayer) || sub_00597A20_IsBusy(pGame, pInteractPlayer))
                {
                    const int nTradeState = pPlayerData->dwTradeState;
                    if (nTradeState == 7)
                    {
                        pPlayerData->dwTradeState = 0xE;
                    }
                    else if (nTradeState == 8)
                    {
                        pPlayerData->dwTradeState = 0xF;
                    }
                    else
                    {
                        sub_6FC91050(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 0xC);
                    }
                    return 0;
                }

                if (ACT4Q2_HasDiabloBeenKilled(pGame))
                {
                    sub_6FC91050(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 9);
                    return 0;
                }

                if (pPlayerData->dwTradeState != 2 || pInteractPlayerData->dwTradeState != 1)
                {
                    sub_6FC91050(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 0xC);
                    return 0;
                }

                sub_00567020_StartTrade(pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData);
                if (!PLRTRADE_AllocPlayerTrade(pGame, pPlayer))
                {
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB65), 0xC);
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB66), 0xC);
                    return 0;
                }

                if (!PLRTRADE_AllocPlayerTrade(pGame, pInteractPlayer))
                {
                    PLRTRADE_Free(pGame, pPlayer);
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB6D), 0xC);
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB6E), 0xC);
                    return 0;
                }

                D2GSPacketSrv78 tPacket78;
                tPacket78.nHeader = 0x78;
                memcpy(tPacket78.szName, CLIENTS_GetName(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB76)), sizeof(tPacket78.szName));
                tPacket78.nUnk0x11 = 0;
                tPacket78.dwPlayerGUID = pInteractPlayer->dwUnitId;
                sub_0053CAD0_SendPacket0x78(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB79), &tPacket78);

                memcpy(tPacket78.szName, CLIENTS_GetName(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB7A)), sizeof(tPacket78.szName));
                tPacket78.nUnk0x11 = 0;
                tPacket78.dwPlayerGUID = pPlayer->dwUnitId;
                sub_0053CAD0_SendPacket0x78(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB7D), &tPacket78);
                break;
            }
            case 8:
            {
                if (nGold > (unsigned int)STATLIST_UnitGetStatValue(pPlayer, 0xE, 0))
                {
                    if (!sub_00597A20_IsBusy(pGame, pPlayer) && !sub_00597A20_IsBusy(pGame, pInteractPlayer))
                    {
                        sub_6FC91050(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 9);
                    }
                }
                else
                {
                    const unsigned int nInventoryGoldLimit = UNITS_GetInventoryGoldLimit(pInteractPlayer);
                    const unsigned int nCurrentGold = STATLIST_UnitGetStatValue(pInteractPlayer, 0xE, 0);
                    if (nCurrentGold + nGold > nInventoryGoldLimit)
                    {
                        nGold = nInventoryGoldLimit - nCurrentGold;
                    }

                    D2PlayerTradeStrc* pTrade = pPlayerData->pTrade;
                    if (pTrade)
                    {
                        pTrade->nGoldInTrade = nGold;
                        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBC3), nGold, 0);
                        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBC4), nGold, 1);
                    }
                }
                break;
            }
            case 4:
            {
                if (!sub_00597A20_IsBusy(pGame, pPlayer) && !sub_00597A20_IsBusy(pGame, pInteractPlayer))
                {
                    if (ACT4Q2_HasDiabloBeenKilled(pGame))
                    {
                        sub_6FC91050(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 9);
                        return 0;
                    }

                    if (pPlayerData->dwTradeState != 3)
                    {
                        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBD2), 6);
                        return 0;
                    }

                    if (INVENTORY_GetCursorItem(pPlayer->pInventory))
                    {
                        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBD7), 6);
                        return 0;
                    }

                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBDC), 5);
                    if (pPlayerData->dwTradeState != 3)
                    {
                        return 0;
                    }

                    pPlayerData->dwTradeState = 4;
                    if (pInteractPlayerData->dwTradeState != 4)
                    {
                        return 0;
                    }

                    sub_00567C70_AcceptTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData);
                    const unsigned int nTickCount = GetTickCount();
                    pInteractPlayerData->dwAcceptTradeTick = nTickCount;
                    pPlayerData->dwAcceptTradeTick = nTickCount;
                }
                else
                {
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBEE), 6);
                }
                break;
            }
            case 7:
            {
                if (pPlayerData->dwTradeState == 4)
                {
                    pPlayerData->dwTradeState = 3;
                }
                if (pInteractPlayerData->dwTradeState == 4)
                {
                    pInteractPlayerData->dwTradeState = 3;
                }
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBFD), 6);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBFE), 6);
                break;
            }
            default:
                break;
            }
        }
        else
        {
            if (!sub_00597A20_IsBusy(pGame, pPlayer))
            {
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xC06), 0xC);
            }
        }
        return 0;
    }

    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xC0C), 0xC);
    return 0;
}

// 0x00568D10
void __fastcall sub_00568D10_RefreshTradeSnapshot(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    PLRTRADE_AllocPlayerTrade(pGame, pPlayer);
    UNITS_RefreshInventory(pPlayer, 1);
    sub_6FC90AE0(pGame, pPlayer, 1);
    PLRTRADE_Free(pGame, pPlayer);
    sub_6FC4B830(pGame, pPlayer);
    EVENT_SetEvent(pGame, pPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
}

// 0x00564F30
static int __stdcall sub_00564F30_RemoveCubeInputs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    int nCount = 0;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (pCheckedItem && ITEMS_GetInvPage(pCheckedItem) == INVPAGE_CUBE)
        {
            int nFlags = 0;
            ITEMS_SetOrRemoveFlag(&nFlags, 32, 1);
            ITEMS_SetItemCell(pCheckedItem, INVPAGE_CUBE);
            D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pCheckedItem, nFlags);
            D2GAME_RemoveItem_6FC471F0(pGame, pUnit, pCheckedItem, 0);
            nCount += 1;
        }
    }

    return nCount;
}

void __fastcall sub_K11_Emit00564F30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_00564F30_RemoveCubeInputs(pGame, pUnit, SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrTrade.cpp", 1358));
}

// 0x00565930
short __fastcall sub_00565930(Game* game,int level,int type)
{
    short choices[256];
    ItemRecordTable* table=sub_00633590();
    int count=0;
    if(!table) { sub_00408A60(&gszEmptyAssertText,sub_00408090(),0x384); exit(-1); }
    int start=sub_0045C3E0(&game->seed,table->count);
    int stop=start-1;
    if(stop<0) stop=table->count-1;
    int index=start;
    while(index!=stop) {
        if(count>=256) break;
        if(sub_00629A90(index,type)) {
            Item* record=&table->records[index];
            if(record->spawnable && (record->format<EXPANSION_FORMAT || game->format>=EXPANSION_FORMAT) && record->level<=level) {
                choices[count++]=(short)index;
            }
        }
        ++index;
        if(index>=table->count) index=0;
    }
    if(!count) return 0;
    return choices[sub_0045C3E0(&game->seed,count)];
}

// 0x00565A80
int __fastcall PLRTRADE_CreateCowPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ACT1Q4_CreateCowPortal(pGame, pUnit);
}

// 0x00565A90
int __fastcall PLRTRADE_CreateUberRunPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ACT1Q4_CreateUberRunPortal(pGame, pUnit);
}

// 0x00565AA0
int __fastcall PLRTRADE_CreateUberFinalePortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ACT1Q4_CreateUberFinalePortal(pGame, pUnit);
}

// 0x00566D90
void __fastcall PLRTRADE_SendEventPacketToPlayer(D2UnitStrc* pPlayer, unsigned char nType, char* szSource)
{
    D2GSPacketSrv5A packet5A = {};
    packet5A.nHeader = 0x5A;
    packet5A.nType = nType;
    packet5A.nColor = STRCOLOR_WHITE;
    packet5A.dwParam = 0;

    if (szSource)
    {
        SStrCopy(packet5A.szText, szSource, 0x7FFFFFFF);
        packet5A.szText[15] = 0;
    }
    else
    {
        packet5A.szText[0] = 0;
    }

    D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 2254), &packet5A);
}

// 0x00566E60
void __fastcall PLRTRADE_TryToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    if (PLAYER_IsBusy(pPlayer1) || ACT4Q2_HasDiabloBeenKilled(pGame))
    {
        return;
    }

    const unsigned int nTickCount = GetTickCount();

    D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pPlayer2);
    D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer1);
    if (PLAYER_IsBusy(pPlayer2))
    {
        if (nTickCount - pPlayerData1->unk0x54 <= 1000)
        {
            return;
        }

        PLRTRADE_SendEventPacketToPlayer(pPlayer1, EVENTTYPE_PLAYERISBUSY, pPlayerData2->szName);
        pPlayerData1->unk0x54 = nTickCount;
        return;
    }

    if (nTickCount - pPlayerData2->dwAcceptTradeTick < 5000)
    {
        if (pPlayerData1->unk0x54 + 1000 < nTickCount)
        {
            pPlayerData1->unk0x54 = nTickCount;
            PLRTRADE_SendEventPacketToPlayer(pPlayer1, EVENTTYPE_PLEASEWAIT, pPlayerData2->szName);
        }
    }
    else
    {
        if (!pPlayerData1->dwTradeState && !pPlayerData2->dwTradeState)
        {
            if (nTickCount - pPlayerData1->dwAcceptTradeTick < 5000)
            {
                if (nTickCount > pPlayerData1->unk0x54 + 1000)
                {
                    PLRTRADE_SendEventPacketToPlayer(pPlayer1, EVENTTYPE_PLEASEWAIT, 0);
                    pPlayerData1->unk0x54 = nTickCount;
                }
                return;
            }

            if (DUNGEON_IsTownLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer1))) && DUNGEON_IsTownLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer2))))
            {
                SUNIT_SetInteractInfo(pPlayer1, 0, !pPlayer2 ? -1 : pPlayer2->dwUnitId);
                SUNIT_SetInteractInfo(pPlayer2, 0, !pPlayer1 ? -1 : pPlayer1->dwUnitId);

                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 2375), 0);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 2376), 1);

                pPlayerData1->dwTradeState = 1;
                pPlayerData2->dwTradeState = 2;
            }
            else
            {
                SUNIT_ResetInteractInfo(pPlayer1);
                SUNIT_ResetInteractInfo(pPlayer2);
            }
        }
    }
}

// 0x005678A0
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    int nUnitType;
    int nUnitGUID;

    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID) && nUnitType == UNIT_PLAYER && SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nUnitGUID))
    {
        return 1;
    }

    return 0;
}

// 0x005678F0
void __fastcall PLRTRADE_RestoreInventory(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused)
{
    if (!UNITS_GetPlayerData(pUnit)->pTrade)
    {
        return;
    }

    D2GAME_PACKETS_SendPacketSize06_6FC3C850(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrTrade.cpp", 0x84F), 0x92, 0, !pUnit ? -1 : pUnit->dwUnitId);
    SUNIT_IterateLivingPlayers(pGame, sub_6FC90BE0, pUnit);

    D2UnitStrc* pNext;
    for (D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory); pCurrent; pCurrent = pNext)
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        pNext = INVENTORY_GetNextItem(pCurrent);
        if (pItem && pItem->dwUnitType == 4)
        {
            if (pItem->dwAnimMode == 0)
            {
                ITEMMODE_ResetBookScrollSkillQuantity(pUnit, pItem);
            }

            INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem);
            ITEMS_SetItemCMDFlag(pItem, 1, 1);
        }
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pUnit->pInventory);
    if (pCursorItem && pCursorItem->dwUnitType == 4)
    {
        INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pCursorItem);
        ITEMS_SetItemCMDFlag(pCursorItem, 1, 1);
    }

    sub_6FC4BA50(pGame, pUnit);
    sub_6FC90C20(pGame, pUnit);
}

// 0x005689D0
void __fastcall sub_005689D0(D2GameStrc* game,D2UnitStrc* player,int unused1,int unused2)
{
    D2PlayerDataStrc* data=UNITS_GetPlayerData(player);
    if (data->dwTradeState<=4) return;
    if (data->dwTradeState==7) {
        data->dwTradeState=8;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    }
    if (data->dwTradeState==14) {
        data->dwTradeState=15;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    }
    D2PlayerTradeStrc* trade=data->pTrade;
    if (data->dwTradeState==8) {
        if (player) player->dwFlagEx &= ~0x00400000u;
        if (trade->nNextUpdateTick) {
            data->dwTradeState=11;
            EVENT_SetEvent(game,player,0xD,game->dwGameFrame+125,0,0);
        } else {
            data->dwTradeState=3;
        }
        return;
    }
    if (data->dwTradeState==15) {
        if (player) player->dwFlagEx &= ~0x00400000u;
        data->dwTradeState=16;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+5,0,0);
        return;
    }
    if (data->dwTradeState==16) {
        int type,id;
        if (SUNIT_GetInteractInfo(player,&type,&id) && type==0) {
            D2UnitStrc* other=SUNIT_GetServerUnit(game,0,id);
            if (other) {
                D2PlayerDataStrc* first=UNITS_GetPlayerData(player);
                D2PlayerDataStrc* second=UNITS_GetPlayerData(other);
                if ((first->dwTradeState==2 || first->dwTradeState==1)
                    && (second->dwTradeState==2 || second->dwTradeState==1)) {
                    sub_6FC91050(game,player,other,first,second,12);
                    const unsigned int tick=GetTickCount();
                    second->dwAcceptTradeTick=tick;
                    first->dwAcceptTradeTick=tick;
                    return;
                } else if (!sub_00597A20_IsBusy(game,player) && !sub_00597A20_IsBusy(game,other)) {
                    sub_6FC91050(game,player,other,first,second,12);
                    const unsigned int tick=GetTickCount();
                    second->dwAcceptTradeTick=tick;
                    first->dwAcceptTradeTick=tick;
                    return;
                }
            }
        }
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+5,0,0);
        return;
    }
    switch (data->dwTradeState) {
    case 11:
        if (trade->nNextUpdateTick < GetTickCount()) {
            data->dwTradeState=3;
            if (player) player->dwFlagEx &= ~0x00C00000u;
            trade->nNextUpdateTick=0;
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(player,".\\PLAYER\\PlrTrade.cpp",0xE95),15);
            return;
        }
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+25,0,0);
        return;
    case 9:
        data->dwTradeState=10;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    case 5:
        data->dwTradeState=6;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    case 6:
        data->dwTradeState=3;
        if (player) player->dwFlagEx &= ~0x00C00000u;
        return;
    case 12:
        data->dwTradeState=13;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+4,0,0);
        return;
    case 10:
    case 13:
        data->dwTradeState=0;
        if (player) player->dwFlagEx &= ~0x00C00000u;
        return;
    }
}
