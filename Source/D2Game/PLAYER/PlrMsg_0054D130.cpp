#include "D2Game.h"

struct D2GameStrc
{
    char unk_00[0x70];
    int bExpansion;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk_04[0x0C];
    int dwAnimMode;
    char unk_14[0x4C];
    D2InventoryStrc* pInventory;
};

D2UnitStrc* __stdcall sub_0063BDE0(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
int __stdcall sub_0063BE30_Return(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30
void __fastcall sub_0055C730(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
int __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bRefresh); // 0x00621000
D2UnitStrc* __fastcall sub_0055A2A0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pOwner, int bDuplicateSocketFillers); // 0x0055A2A0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180
int __fastcall sub_6FC4B9D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055FB10
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __fastcall sub_0055DF00_RecalcItemStates(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4); // 0x0055DF00
void __fastcall sub_0055F500_RefreshItemStatLists(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0055F500
void __fastcall sub_0055F4F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x0055F4F0

static __declspec(noinline) int __stdcall sub_0054D130_TakeMercItemToCursor(D2GameStrc* pGame, D2UnitStrc* pMerc, D2UnitStrc* pPlayer, int nBodyLoc);

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
    sub_0055C730(pGame, pItem, pMerc, 0, 0);
    ITEMS_SetItemCMDFlag(pItem, 16, 1);
    INVENTORY_AddItemToTradeInventory(pMerc->pInventory, pItem);
    UNITS_RefreshInventory(pMerc, 1);

    D2UnitStrc* pCursorItem = sub_0055A2A0(pGame, pItem, pPlayer, 1);
    INVENTORY_SetCursorItem(pPlayerInventory, pCursorItem);
    sub_6FC4B9D0(pGame, pPlayer, pCursorItem);
    ITEMS_SetItemFlag(pItem, 0x20, 1);
    sub_0055DF00_RecalcItemStates(pGame, pMerc, 0, 0);
    sub_0055F500_RefreshItemStatLists(pGame, pMerc);
    sub_0055F4F0(pGame, pMerc, 0);
    return 0;
}

int __fastcall sub_Emit_0054D130(D2GameStrc* pGame, D2UnitStrc* pMerc, D2UnitStrc* pPlayer, int nBodyLoc)
{
    return sub_0054D130_TakeMercItemToCursor(pGame, pMerc, pPlayer, nBodyLoc);
}
