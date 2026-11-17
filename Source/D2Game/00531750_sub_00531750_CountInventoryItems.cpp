struct D2InventoryStrc;
struct D2UnitStrc;

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0

// 0x00531750
static __declspec(noinline) unsigned short sub_00531750_CountInventoryItems(D2InventoryStrc* pInventory)
{
    int nCount = 0;
    if (!pInventory)
        return 0;
    if (INVENTORY_GetCursorItem(pInventory))
        nCount = 1;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pIsItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (pIsItem)
            ++nCount;
    }
    return (unsigned short)nCount;
}

void __fastcall sub_M93_UseCount_00531750(int nCount);
void __stdcall sub_M93_Emit_00531750(int nUnused, D2InventoryStrc* pInventory)
{
    sub_M93_UseCount_00531750(sub_00531750_CountInventoryItems(pInventory));
}
