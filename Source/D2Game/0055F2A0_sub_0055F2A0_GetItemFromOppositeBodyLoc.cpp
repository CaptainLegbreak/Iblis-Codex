struct D2UnitStrc;
struct D2InventoryStrc;

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0

int __fastcall sub_0055F240_GetOppositeBodyLoc(int nBodyLoc)
{
    switch (nBodyLoc)
    {
    case 4:
        return 5;
    case 5:
        return 4;
    case 6:
        return 7;
    case 7:
        return 6;
    case 11:
        return 12;
    case 12:
        return 11;
    }

    return 0;
}

// 0x0055F2A0
D2UnitStrc* __fastcall sub_0055F2A0_GetItemFromOppositeBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pDefault, int nBodyLoc)
{
    const int nOpposite = sub_0055F240_GetOppositeBodyLoc(nBodyLoc);
    if (!nOpposite)
    {
        return pDefault;
    }
    return INVENTORY_GetItemFromBodyLoc(pInventory, nOpposite);
}
