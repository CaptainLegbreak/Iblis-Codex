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
    char unk0x00[0xD0];
    int dwMaxAc;
    char unk0xD4[0x2A];
    unsigned char nMinDam;
    unsigned char nMaxDam;
    unsigned char nMinMisDam;
    unsigned char nMaxMisDam;
    unsigned char n2HandMinDam;
    unsigned char n2HandMaxDam;
};

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);       // 0x00627260
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                // 0x00628590
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax);                      // 0x0065E9E0
int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState); // 0x0065EA50
int __fastcall ITEMMODS_PropertyFunc06(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11); // 0x0065EE80

// 0x0065F010
int __fastcall ITEMMODS_PropertyFunc07(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (!nValue)
    {
        nValue = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    const int nItemUnitType = pItem ? pItem->dwUnitType : 6;
    if (nItemUnitType != 4)
    {
        ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 18, 0, nValue, nState);
        ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 17, 0, nValue, nState);
        return 1;
    }

    int nClassId;
    if (pUnit && pUnit->dwUnitType == 4)
    {
        nClassId = pUnit->dwClassId;
    }
    else
    {
        nClassId = pItem->dwClassId;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    int nItemId;
    D2ItemsTxt* pBaseRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    if (pBaseRecord && ITEMS_CheckItemTypeId(pItem, 45))
    {
        if (pBaseRecord->nMinDam)
        {
            STATLIST_SetUnitStat(pItem, 21, pBaseRecord->nMinDam, 0);
        }

        if (pBaseRecord->n2HandMinDam)
        {
            STATLIST_SetUnitStat(pItem, 23, pBaseRecord->n2HandMinDam, 0);
        }

        if (ITEMS_CheckIfThrowable(pItem) && pBaseRecord->nMinMisDam)
        {
            STATLIST_SetUnitStat(pItem, 159, pBaseRecord->nMinMisDam, 0);
        }
    }

    pBaseRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    if (pBaseRecord && ITEMS_CheckItemTypeId(pItem, 45))
    {
        if (pBaseRecord->nMaxDam)
        {
            STATLIST_SetUnitStat(pItem, 22, pBaseRecord->nMaxDam, 0);
        }

        if (pBaseRecord->n2HandMaxDam)
        {
            STATLIST_SetUnitStat(pItem, 24, pBaseRecord->n2HandMaxDam, 0);
        }

        if (ITEMS_CheckIfThrowable(pItem) && pBaseRecord->nMaxMisDam)
        {
            STATLIST_SetUnitStat(pItem, 160, pBaseRecord->nMaxMisDam, 0);
        }
    }

    DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);

    unsigned char nMax = pItemsTxtRecord->n2HandMaxDam;
    if (nMax <= pItemsTxtRecord->nMaxDam)
    {
        nMax = pItemsTxtRecord->nMaxDam;
    }

    const int nMaxDamage = nMax;
    if (ITEMS_CheckItemTypeId(pItem, 45) && nMaxDamage + DATATBLS_ApplyRatio(nMaxDamage, nValue, 100) <= nMaxDamage)
    {
        return ITEMMODS_PropertyFunc06(nType, pUnit, pItem, pProperty, nSet, nStatId, 0, 1, nState, fStatList, a11);
    }

    ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 18, 0, nValue, nState);
    ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 17, 0, nValue, nState);
    return nValue;
}
