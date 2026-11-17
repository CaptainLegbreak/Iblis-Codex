struct D2ItemDropStrc;
struct D2LowQualityItemsTxt;

union D2SeedStrc
{
    struct
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
    };
    unsigned __int64 lSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
};

struct D2ItemsTxt
{
    char unk0x00[0x112];
    unsigned char nDurability;
};

struct D2LowQualityItemDataTbl
{
    int nLowQualityItemsTxtRecordCount;
    D2LowQualityItemsTxt* pLowQualityItemsTxt;
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
void __fastcall ITEMS_AssignStaffModsForFormat(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);               // 0x005C1260
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);                                                 // 0x00627D90
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex);                             // 0x00629DF0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2LowQualityItemDataTbl* __fastcall DATATBLS_GetLowQualityItemDataTables();                                 // 0x006375B0

static __declspec(noinline) int __stdcall sub_005C0D40_PercentWithMinimum(int nValue, int nPercent, int nMin)
{
    const int nResult = nValue * nPercent / 100;
    if (nResult < nMin)
    {
        return nMin;
    }
    return nResult;
}

// 0x005C2AF0
int __fastcall ITEMS_ApplyLegacyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    D2LowQualityItemDataTbl* pLowQualityItemDataTbl = DATATBLS_GetLowQualityItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pLowQualityItemDataTbl)
    {
        return 0;
    }

    if (!pItemsTxtRecord)
    {
        return 0;
    }

    ITEMS_SetFileIndex(pItem, SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), pLowQualityItemDataTbl->nLowQualityItemsTxtRecordCount));

    int nResult = 0;
    if (ITEMS_HasDurability(pItem))
    {
        if (D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
        {
            unsigned int nMaxDurability = pTxt->nDurability / 3;
            if (!nMaxDurability)
            {
                nMaxDurability = 1;
            }

            const unsigned int nHalf = nMaxDurability / 2;
            unsigned int nDurability = ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nHalf) + nHalf;
            if (!nDurability)
            {
                nDurability = 1;
            }

            STATLIST_SetUnitStat(pItem, 0x48, nDurability, 0);
            STATLIST_SetUnitStat(pItem, 0x49, nMaxDurability, 0);
        }
    }

    if (ITEMS_CheckItemTypeId(pItem, 0x2D))
    {
        int nMaxDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x16, 0) / 100;
        if (nMaxDamage < 2)
        {
            nMaxDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, 0x16, nMaxDamage, 0);

        int nMinDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x15, 0) / 100;
        if (nMinDamage < 1)
        {
            nMinDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x15, nMinDamage, 0);

        int nMaxSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x18, 0) / 100;
        if (nMaxSecondaryDamage < 2)
        {
            nMaxSecondaryDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, 0x18, nMaxSecondaryDamage, 0);

        int nMinSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x17, 0) / 100;
        if (nMinSecondaryDamage < 1)
        {
            nMinSecondaryDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x17, nMinSecondaryDamage, 0);

        if (ITEMS_CheckIfThrowable(pItem))
        {
            const int nMinThrowDamage = sub_005C0D40_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x9F, 0), 75, 2);
            STATLIST_SetUnitStat(pItem, 0x9F, nMinThrowDamage, 0);

            const int nMaxThrowDamage = sub_005C0D40_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0xA0, 0), 75, 1);
            STATLIST_SetUnitStat(pItem, 0xA0, nMaxThrowDamage, 0);
        }
        nResult = 1;
    }
    else if (ITEMS_CheckItemTypeId(pItem, 0x32))
    {
        int nArmorClass = 75 * STATLIST_GetUnitBaseStat(pItem, 0x1F, 0) / 100;
        if (nArmorClass <= 0)
        {
            nArmorClass = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x1F, nArmorClass, 0);
        nResult = 1;
    }

    return nResult;
}

// 0x005C2D40
int __fastcall ITEMS_ApplyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    D2LowQualityItemDataTbl* pLowQualityItemDataTbl = DATATBLS_GetLowQualityItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pLowQualityItemDataTbl)
    {
        return 0;
    }

    if (!pItemsTxtRecord)
    {
        return 0;
    }

    ITEMS_SetFileIndex(pItem, SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), pLowQualityItemDataTbl->nLowQualityItemsTxtRecordCount));

    int nResult = 0;
    if (ITEMS_HasDurability(pItem))
    {
        if (D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
        {
            int nMaxDurability = 33 * pTxt->nDurability / 100;
            if (nMaxDurability < 1)
            {
                nMaxDurability = 1;
            }

            const unsigned int nHalf = (unsigned int)nMaxDurability / 2;
            unsigned int nDurability = ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nHalf) + nHalf;
            if (!nDurability)
            {
                nDurability = 1;
            }

            STATLIST_SetUnitStat(pItem, 0x48, nDurability, 0);
            STATLIST_SetUnitStat(pItem, 0x49, nMaxDurability, 0);
        }
    }

    if (ITEMS_CheckItemTypeId(pItem, 0x2D))
    {
        int nMaxDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x16, 0) / 100;
        if (nMaxDamage < 2)
        {
            nMaxDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, 0x16, nMaxDamage, 0);

        int nMinDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x15, 0) / 100;
        if (nMinDamage < 1)
        {
            nMinDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x15, nMinDamage, 0);

        int nMaxSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x18, 0) / 100;
        if (nMaxSecondaryDamage < 2)
        {
            nMaxSecondaryDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, 0x18, nMaxSecondaryDamage, 0);

        int nMinSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, 0x17, 0) / 100;
        if (nMinSecondaryDamage < 1)
        {
            nMinSecondaryDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x17, nMinSecondaryDamage, 0);

        if (ITEMS_CheckIfThrowable(pItem))
        {
            const int nMinThrowDamage = sub_005C0D40_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x9F, 0), 75, 2);
            STATLIST_SetUnitStat(pItem, 0x9F, nMinThrowDamage, 0);

            const int nMaxThrowDamage = sub_005C0D40_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0xA0, 0), 75, 1);
            STATLIST_SetUnitStat(pItem, 0xA0, nMaxThrowDamage, 0);
        }
        nResult = 1;
    }
    else if (ITEMS_CheckItemTypeId(pItem, 0x32))
    {
        int nArmorClass = 75 * STATLIST_GetUnitBaseStat(pItem, 0x1F, 0) / 100;
        if (nArmorClass <= 0)
        {
            nArmorClass = 1;
        }
        STATLIST_SetUnitStat(pItem, 0x1F, nArmorClass, 0);
        nResult = 1;
    }

    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return nResult;
}
