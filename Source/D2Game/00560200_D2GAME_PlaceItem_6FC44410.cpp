struct D2InventoryStrc;
struct D2GameStrc { char unk_00[0x70]; int bExpansion; };
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; int dwAnimMode; char unk_14[0x4C]; D2InventoryStrc* pInventory; char unk_64[0x60]; unsigned int dwFlags; };
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc*, const char*, int); // 0x0055BF50
void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc*, D2UnitStrc*); // 0x0055C270
void __fastcall D2GAME_ITEMS_UpdateItemStatlist_6FC42310(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x0055C2C0
void __fastcall sub_0055DBC0(D2GameStrc*, D2UnitStrc*, int); // 0x0055DBC0
int __fastcall sub_0055F590_CheckItem(D2UnitStrc*, const char*, int); // 0x0055F590
void __fastcall PLRTRADE_AddItemToTrade(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x00568770
void __stdcall UNITS_RefreshInventory(D2UnitStrc*, int); // 0x00621000
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc*, unsigned char, int); // 0x00621050
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*, unsigned int, int, const char*); // 0x006280A0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc*, unsigned int, int); // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc*, int, int); // 0x00628170
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc*); // 0x00628250
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc*, D2UnitStrc*); // 0x0062FF70
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc*, D2UnitStrc*, int); // 0x0063B210
int __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc*, D2UnitStrc*, int, int, unsigned char, const char*, int); // 0x0063B950
int __stdcall INVENTORY_PlaceItemAtInventoryPage(D2InventoryStrc*, D2UnitStrc*, int, int, int, int, unsigned char); // 0x0063BCC0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc*, D2UnitStrc*); // 0x0063C180
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc*, D2UnitStrc*); // 0x0063CC70
extern const char szItemModeCpp[]; // 0x006E1164
// 0x00560200
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int bAutoPosition, int bNotify, D2InventoryStrc* pInventory)
{
    if (!pGame || !pPlayer) return 0;
    sub_0055BF50_ClearTargetingFlags(pPlayer, szItemModeCpp, 0x87B);
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nUnitId);
    if (!pItem) return 0;
    if (pItem->dwUnitType != 4) return 0;
    if (pItem->dwAnimMode != 4) return 0;
    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    if (!pInventory)
    {
        pInventory = pPlayer->pInventory;
        if (!pInventory) return 0;
    }
    int bTrade = 0;
    int bClearCursor = 1;
    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pPlayer, nPage, pGame->bExpansion);
    if (pPlayer->dwUnitType == 0)
    {
        switch (nPage)
        {
        case 1: bClearCursor = 0; break;
        case 2: bTrade = 1; break;
        }
    }
    if (bAutoPosition)
    {
        if (!INVENTORY_PlaceItemAtFreePosition(pInventory, pItem, nInventoryRecordId, 0, nPage, szFile, nLine)) goto failed;
    }
    else
    {
        if (nX < 0) nX = 0;
        if (nY < 0) nY = 0;
        if (!INVENTORY_PlaceItemAtInventoryPage(pInventory, pItem, nX, nY, nInventoryRecordId, 0, nPage)) goto failed;
    }
    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
    {
    failed:
        return 0;
    }
    if (ITEMS_GetInvPage(pItem) != 4) sub_0055C270_OnItemToBelt(pPlayer, pItem);
    pItem->dwFlags &= ~2u;
    if (ITEMS_IsCharmUsable(pItem, pPlayer)) D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pItem, pPlayer, 0);
    if (bClearCursor) INVENTORY_SetCursorItem(pInventory, 0);
    UNITS_ChangeAnimMode(pItem, 0);
    if (bNotify)
    {
        ITEMS_SetItemCMDFlag(pItem, 2, 1);
        if (sub_0055F590_CheckItem(pItem, szItemModeCpp, 0x8EA)) ITEMS_SetItemFlag(pItem, 1, 1);
        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x8EE, szItemModeCpp)) ITEMS_SetItemFlag(pItem, 0x4000, 0);
        UNITS_RefreshInventory(pPlayer, 1);
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    }
    if (bTrade == 1) PLRTRADE_AddItemToTrade(pGame, pPlayer, pItem);
    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        sub_0055DBC0(pGame, pPlayer, 0);
        UNITS_RefreshInventory(pPlayer, 1);
    }
    return 1;
}
