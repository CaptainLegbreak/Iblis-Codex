struct D2InventoryStrc;
struct D2UnitStrc;

#define BODYLOC_RARM 4
#define BODYLOC_LARM 5

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

// 0x0056C670
static D2UnitStrc* __stdcall sub_0056C670_GetOtherHandItem(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (nBodyLoc == BODYLOC_LARM)
    {
        return INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
    }
    return INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
}

D2UnitStrc* __fastcall sub_K11_Emit0056C670(D2InventoryStrc* pInventory, int nBodyLoc)
{
    return sub_0056C670_GetOtherHandItem(pInventory, nBodyLoc + 1);
}
