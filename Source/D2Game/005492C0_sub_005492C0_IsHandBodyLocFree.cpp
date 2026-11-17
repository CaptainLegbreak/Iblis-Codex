struct D2InventoryStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

#define BODYLOC_RARM 4
#define BODYLOC_LARM 5

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

// 0x005492C0
static int __stdcall sub_005492C0_IsHandBodyLocFree(D2UnitStrc* pUnit, int nBodyLoc)
{
    if (nBodyLoc != BODYLOC_RARM && nBodyLoc != BODYLOC_LARM)
    {
        return 3;
    }
    return !INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc);
}

int __fastcall sub_K10_EmitIsHandBodyLocFree(D2UnitStrc* pUnit, int nBodyLoc)
{
    return sub_005492C0_IsHandBodyLocFree(pUnit, nBodyLoc);
}
