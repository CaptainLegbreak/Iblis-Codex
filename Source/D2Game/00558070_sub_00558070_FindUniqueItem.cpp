struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall ITEMS_PlayerIterateCallback_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);   // 0x00557FA0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600

static inline int ITEMS_IsUniqueWithFileIndex(D2UnitStrc* pItem, int nFileIndex)
{
    return pItem && pItem->dwUnitType == 4 && ITEMS_GetItemQuality(pItem) == 7 && ITEMS_GetFileIndex(pItem) == nFileIndex;
}

// 0x00558070
D2UnitStrc* __fastcall sub_00558070_FindUniqueItem(D2UnitStrc* pUnit, int nFileIndex)
{
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (ITEMS_IsUniqueWithFileIndex(pCursorItem, nFileIndex))
    {
        return pCursorItem;
    }

    for (D2UnitStrc* pIt = INVENTORY_GetFirstItem(pInventory); pIt; pIt = INVENTORY_GetNextItem(pIt))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pIt);
        if (ITEMS_IsUniqueWithFileIndex(pItem, nFileIndex) && ITEMS_GetInvPage(pItem) != 1)
        {
            return pItem;
        }
    }

    return 0;
}

// 0x00558990
void __cdecl sub_00558990_Nop()
{
}

// 0x00558B40
void __fastcall sub_00558B40_RemoveItemFromGame(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
    if (pRoom)
    {
        DUNGEON_AllocDrlgDelete(pRoom, pItem->dwUnitType, pItem->dwUnitId);
        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
    }

    pItem->dwFlags &= ~2u;
    SUNIT_IterateLivingPlayers(pGame, ITEMS_PlayerIterateCallback_RemoveItem, pItem);
    SUNIT_RemoveUnit(pGame, pItem);
}
