struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x00[0xDC];
    unsigned char nBitField1;
};

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

// 0x005451B0
int __fastcall sub_005451B0_HasFlaggedItem(D2UnitStrc* pUnit)
{
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        if (DATATBLS_GetItemsTxtRecord(!pCheckedItem ? -1 : pCheckedItem->dwClassId)->nBitField1 & 2)
        {
            return 1;
        }
    }

    return 0;
}
