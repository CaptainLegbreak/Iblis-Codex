struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[22];
    D2InventoryStrc* pInventory;
    int unk0x64[25];
    unsigned int dwFlagEx;
};

struct D2ItemsTxt
{
    char unk0x00[0x12C];
    unsigned char nTransparent;
    unsigned char nTransTbl;
};

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);
int __fastcall sub_0046D9F0_GetConvertedUnitType(D2UnitStrc* pUnit);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
extern "C" unsigned int __stdcall sub_006280A0(D2UnitStrc* pUnit, unsigned int dwMask, unsigned int dwUnused3, unsigned int dwUnused4); // 0x006280A0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                               // 0x0063A7B0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2UnitStrc* __stdcall sub_0063C050_GetBodyLocItem(D2InventoryStrc* pInventory, int nBodyLoc);

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

// 0x004DB360
int __fastcall sub_004DB360_GetCompTransparency(D2UnitStrc* pUnit, int nComponent, int* pOut, int nItemId)
{
    const int nType = sub_0046D9F0_GetConvertedUnitType(pUnit);
    switch (nType)
    {
    case 1:
    {
        const int nStat = STATLIST_UnitGetStatValue(pUnit, 0xB5, 0);
        if (nStat <= 0)
            break;
        if (nStat > 0xF)
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            if (!pInventory)
                return 0;
            for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
            {
                D2UnitStrc* pChecked = INVENTORY_UnitIsItem(pItem);
                if (pChecked && sub_006280A0(pChecked, 0x400000, 0x5E6, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
                {
                    *pOut = 1;
                    return 1;
                }
            }
            return 0;
        }
        *pOut = 1;
        return 1;
    }
    case 0:
        if (STATLIST_UnitGetStatValue(pUnit, 0xB5, 0))
        {
            *pOut = 1;
            return 1;
        }
        break;
    }

    if (nItemId != -1)
    {
        D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(nItemId);
        if (pTxt && pTxt->nTransparent)
        {
            *pOut = pTxt->nTransTbl;
            return 1;
        }
    }

    if (nType)
        return 0;

    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (STATES_IsUnitShapeShiftedInline(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }

    if (!pInventory)
        return 0;

    switch (nComponent)
    {
    case 7:
    {
        D2UnitStrc* pItem = sub_0063C050_GetBodyLocItem(pInventory, 7);
        if (pItem && sub_006280A0(pItem, 0x400000, 0x627, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
        {
            *pOut = 2;
            return 1;
        }
        break;
    }
    case 6:
    {
        D2UnitStrc* pItem = sub_0063C050_GetBodyLocItem(pInventory, 6);
        if (pItem && sub_006280A0(pItem, 0x400000, 0x61C, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
        {
            *pOut = 1;
            return 1;
        }
        break;
    }
    case 5:
    {
        D2UnitStrc* pItem = sub_0063C050_GetBodyLocItem(pInventory, 5);
        if (pItem && sub_006280A0(pItem, 0x400000, 0x611, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
        {
            *pOut = 1;
            return 1;
        }
        break;
    }
    }

    return 0;
}
