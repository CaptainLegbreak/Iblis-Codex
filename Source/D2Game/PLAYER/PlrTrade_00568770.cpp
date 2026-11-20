#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"




struct D2PlayerTradeStrc
{
    int nSaveLength;
    unsigned char* pSaveData;
    D2ItemTradeStrc* pItemTrade;
    char unk0x0C[0x08];
    unsigned int nNextUpdateTick;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x50];
    unsigned int dwTradeState;
    char unk0x54[0x08];
    D2PlayerTradeStrc* pTrade;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo);      // 0x0053CAB0
void __fastcall D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(D2ClientStrc* pClient, int nGold, char bOwnGold);    // 0x0053CBE0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID);                     // 0x00554100
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00557FD0
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine);                    // 0x0055F590
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
int __fastcall sub_6FC446B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4, int a5, int bSetQuantityFlag, D2InventoryStrc* pInventoryArg, int a8); // 0x00560420
int __fastcall ITEMMODE_DuplicateSocketFillers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pSocketable, int bRefresh); // 0x00563350
void __fastcall sub_6FC91050(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, D2PlayerDataStrc* pPlayerData1, D2PlayerDataStrc* pPlayerData2, int nTradeState); // 0x005679E0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900

static void __stdcall sub_00567020_StartTrade(D2UnitStrc*, D2UnitStrc*, D2PlayerDataStrc*, D2PlayerDataStrc*); // 0x00567020
static void __stdcall sub_00567350_AddItemTrade(D2GameStrc*, int, int, D2UnitStrc*); // 0x00567350
static char __stdcall sub_005673C0_FindItemTrade(int*, int, D2UnitStrc*); // 0x005673C0

static void __stdcall sub_00567020_StartTrade(D2UnitStrc* pPlayer, D2UnitStrc* pInteractPlayer, D2PlayerDataStrc* pPlayerData, D2PlayerDataStrc* pInteractPlayerData)
{
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 2422), 6);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 2423), 6);

    pPlayerData->dwTradeState = 3;
    pInteractPlayerData->dwTradeState = 3;
}

static void __stdcall sub_00567350_AddItemTrade(D2GameStrc* pGame, int nItemGUID1, int nItemGUID2, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        D2PlayerTradeStrc* pTrade = pPlayerData->pTrade;
        if (pTrade)
        {
            D2ItemTradeStrc* pItemTrade = (D2ItemTradeStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2ItemTradeStrc), ".\\PLAYER\\PlrTrade.cpp", 0xC5B, 0);
            pItemTrade->nItemGUID1 = nItemGUID1;
            pItemTrade->nItemGUID2 = nItemGUID2;
            pItemTrade->pNext = pTrade->pItemTrade;
            pTrade->pItemTrade = pItemTrade;
        }
    }
}

static void sub_005673A0_WalkItemTrade(D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData && pPlayerData->pTrade)
    {
        for (D2ItemTradeStrc* pItemTrade = pPlayerData->pTrade->pItemTrade; pItemTrade; pItemTrade = pItemTrade->pNext)
        {
        }
    }
}

static char __stdcall sub_005673C0_FindItemTrade(int* pItemGUID2, int nItemGUID1, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData && pPlayerData->pTrade)
    {
        for (D2ItemTradeStrc* pItemTrade = pPlayerData->pTrade->pItemTrade; pItemTrade; pItemTrade = pItemTrade->pNext)
        {
            if (pItemTrade->nItemGUID1 == nItemGUID1)
            {
                *pItemGUID2 = pItemTrade->nItemGUID2;
                return 1;
            }
        }
    }

    return 0;
}

void __fastcall PLRTRADE_RemoveItemFromTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    int nUnitGUID;
    int nUnitType;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) && nUnitType)
    {
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCDC), 0xC);
        return;
    }

    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
    if (!pOtherPlayer)
    {
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCE4), 0xC);
        return;
    }

    const int nItemGUID = !pItem ? -1 : pItem->dwUnitId;
    if (sub_005673C0_FindItemTrade(&nUnitGUID, nItemGUID, pPlayer))
    {
        int nUnused;
        if (sub_6FC446B0(pGame, pOtherPlayer, nUnitGUID, &nUnused, 1, 1, 0, 1))
        {
            sub_005673A0_WalkItemTrade(pPlayer);
        }
    }

    D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer);
    D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pOtherPlayer);
    D2PlayerTradeStrc* pTrade1 = pPlayerData1->pTrade;
    D2PlayerTradeStrc* pTrade2 = pPlayerData2->pTrade;
    const unsigned int nTickCount = GetTickCount() + 10000;
    pTrade1->nNextUpdateTick = nTickCount;
    pTrade2->nNextUpdateTick = nTickCount;

    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCF9), 0xE);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCFA), 0xE);

    if (pPlayerData1->dwTradeState == 4 || pPlayerData2->dwTradeState == 4)
    {
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCFF), 0, 0);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD00), 0, 1);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD01), 0, 0);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD02), 0, 1);
        sub_00567020_StartTrade(pPlayer, pOtherPlayer, pPlayerData1, pPlayerData2);
    }
}

__forceinline int PLRTRADE_GetUnitX(D2UnitStrc* pUnit)
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

__forceinline int PLRTRADE_GetUnitY(D2UnitStrc* pUnit)
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

// 0x00568770
void __fastcall PLRTRADE_AddItemToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) && nUnitType)
    {
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xC99), 0xC);
        return;
    }

    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
    if (!pOtherPlayer)
    {
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCA1), 0xC);
        return;
    }

    D2UnitStrc* pDupeItem = ITEMS_Duplicate(pGame, pItem, 0, 0);
    const int nX = PLRTRADE_GetUnitX(pItem);
    const int nY = PLRTRADE_GetUnitY(pItem);
    UNITS_ChangeAnimMode(pDupeItem, 4);
    ITEMS_SetInvPage(pDupeItem, 1);

    if (!D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrTrade.cpp", 0xCAD, pGame, pOtherPlayer, !pDupeItem ? -1 : pDupeItem->dwUnitId, nX, nY, 0, 1, 0))
    {
        ITEMS_RemoveFromAllPlayers(pGame, pDupeItem);
        D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer);
        D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pOtherPlayer);
        sub_6FC91050(pGame, pPlayer, pOtherPlayer, pPlayerData1, pPlayerData2, 9);
        return;
    }

    if (sub_0055F590_CheckItem(pItem, ".\\PLAYER\\PlrTrade.cpp", 0xCB9))
    {
        ITEMMODE_DuplicateSocketFillers(pGame, pOtherPlayer, pItem, pDupeItem, 1);
    }

    const int nDupeItemGUID = !pDupeItem ? -1 : pDupeItem->dwUnitId;
    const int nItemGUID = !pItem ? -1 : pItem->dwUnitId;
    sub_00567350_AddItemTrade(pGame, nItemGUID, nDupeItemGUID, pPlayer);

    D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer);
    D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pOtherPlayer);
    if (pPlayerData1->dwTradeState == 4 || pPlayerData2->dwTradeState == 4)
    {
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCC7), 0, 0);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCC8), 0, 1);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCC9), 0, 0);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCCA), 0, 1);
        sub_00567020_StartTrade(pPlayer, pOtherPlayer, pPlayerData1, pPlayerData2);
    }
}
