struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x5C];
    D2InventoryStrc* pInventory;
};

D2UnitStrc* __stdcall INVENTORY_IsItemInInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);          // 0x0063E070
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020
unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370
int __fastcall sub_00663A20_SetItemBonusStates(D2UnitStrc* pItem, unsigned int nSetItemMask);              // 0x00663A20
int __fastcall sub_00663B40_SetBonusStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3);                // 0x00663B40

__forceinline unsigned int ITEMS_GetStoreSetItemsMaskInline(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2UnitStrc* pInventoryItem = INVENTORY_IsItemInInventory(pUnit->pInventory, pItem);
    if (!pInventoryItem)
    {
        return 0;
    }

    if (INVENTORY_GetItemNodePage(pInventoryItem) != 3)
    {
        return 0;
    }

    return ITEMS_GetSetItemsMask(pUnit, pItem, 1);
}

// 0x00663CC0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!pItem || pItem->dwUnitType != 4 || !pUnit->pInventory)
    {
        return 0;
    }

    const unsigned int nSetItemMask = ITEMS_GetStoreSetItemsMaskInline(pUnit, pItem);

    if (a4 || !a3)
    {
        sub_00663A20_SetItemBonusStates(pItem, nSetItemMask);
    }

    sub_00663B40_SetBonusStatList(pUnit, pItem, a3);

    return 1;
}
