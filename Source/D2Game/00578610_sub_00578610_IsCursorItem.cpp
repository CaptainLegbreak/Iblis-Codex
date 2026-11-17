struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    unsigned int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                // 0x0063C1E0

// 0x00578610
static __declspec(noinline) int __stdcall sub_00578610_IsCursorItem(unsigned int nItemGUID, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
        if (pItem)
        {
            const unsigned int nId = (pItem ? pItem->dwUnitId : -1);
            if (nId == nItemGUID)
            {
                return 1;
            }
        }
    }

    return 0;
}

int __stdcall sub_M452_Emit_00578610(D2UnitStrc* pUnit, unsigned int nGUID)
{
    return sub_00578610_IsCursorItem(nGUID, pUnit) + 7;
}
