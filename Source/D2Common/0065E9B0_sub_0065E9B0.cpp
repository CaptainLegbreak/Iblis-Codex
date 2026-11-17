struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2PropertyStrc
{
    int nProperty;
    int nLayer;
    int nMin;
    int nMax;
};

struct D2ItemsTxt
{
    char unk0x00[0xFE];
    unsigned char nMinDam;
    unsigned char nMaxDam;
    unsigned char nMinMisDam;
    unsigned char nMaxMisDam;
    unsigned char n2HandMinDam;
    unsigned char n2HandMaxDam;
};

int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax);                      // 0x0065E9E0
int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState); // 0x0065EA50

// 0x0065E9B0
D2ItemsTxt* __fastcall sub_0065E9B0(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pUnit && pUnit->dwUnitType == 4)
    {
        return DATATBLS_GetItemsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
    }
    return DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
}

// 0x0065ECF0
int __fastcall ITEMMODS_PropertyFunc05(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : 6;
    if (nUnitType != 4)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = sub_0065E9B0(pUnit, pItem);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    if (!nValue)
    {
        nValue = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    int nStatValue;
    if (!ITEMS_CheckItemTypeId(pItem, 45) || pItemsTxtRecord->nMinDam || !pItemsTxtRecord->n2HandMinDam)
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->nMinDam > 0)
        {
            if (pItemsTxtRecord->nMinDam + nValue <= 0)
            {
                nStatValue = 1 - pItemsTxtRecord->nMinDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 21, 0, nStatValue, nState);
        }
    }

    if (!ITEMS_CheckItemTypeId(pItem, 45) || pItemsTxtRecord->n2HandMinDam || !pItemsTxtRecord->nMinDam)
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->n2HandMinDam > 0)
        {
            if (pItemsTxtRecord->n2HandMinDam + nValue <= 0)
            {
                nStatValue = 1 - pItemsTxtRecord->n2HandMinDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 23, 0, nStatValue, nState);
        }
    }

    if (!ITEMS_CheckItemTypeId(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->nMinMisDam > 0)
        {
            if (pItemsTxtRecord->nMinMisDam + nValue <= 0)
            {
                nStatValue = 1 - pItemsTxtRecord->nMinMisDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 159, 0, nStatValue, nState);
        }
    }

    return nValue;
}

// 0x0065EE80
int __fastcall ITEMMODS_PropertyFunc06(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : 6;
    if (nUnitType != 4)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = sub_0065E9B0(pUnit, pItem);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    if (!nValue)
    {
        nValue = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    int nStatValue;
    if (!ITEMS_CheckItemTypeId(pItem, 45) || pItemsTxtRecord->nMaxDam || !pItemsTxtRecord->n2HandMaxDam)
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->nMaxDam > 0)
        {
            if (pItemsTxtRecord->nMaxDam + nValue <= 0)
            {
                nStatValue = -pItemsTxtRecord->nMaxDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 22, 0, nStatValue, nState);
        }
    }

    if (!ITEMS_CheckItemTypeId(pItem, 45) || pItemsTxtRecord->n2HandMaxDam || !pItemsTxtRecord->nMaxDam)
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->n2HandMaxDam > 0)
        {
            if (pItemsTxtRecord->n2HandMaxDam + nValue <= 0)
            {
                nStatValue = -pItemsTxtRecord->n2HandMaxDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 24, 0, nStatValue, nState);
        }
    }

    if (!ITEMS_CheckItemTypeId(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->nMaxMisDam > 0)
        {
            if (pItemsTxtRecord->nMaxMisDam + nValue <= 0)
            {
                nStatValue = -pItemsTxtRecord->nMaxMisDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 160, 0, nStatValue, nState);
        }
    }

    return nValue;
}
