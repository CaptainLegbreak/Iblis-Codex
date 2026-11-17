#include "D2Common.h"

struct D2SeedStrc;

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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C3E0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
D2StatListStrc* __stdcall sub_00625790_UnitFindStatList(D2UnitStrc* pUnit, int nState, int nFlag);          // 0x00625790
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer);  // 0x00627030
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);                                                 // 0x00627D90
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax);                      // 0x0065E9E0
int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState); // 0x0065EA50

static __declspec(noinline) D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter)
{
    D2StatListStrc* pStatList;

    if (pUnit)
    {
        pStatList = sub_00625790_UnitFindStatList(pUnit, nState, fFilter);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(pUnit->pMemoryPool, fFilter, 0, 4, pUnit->dwUnitId);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATLIST_SetState(pStatList, nState);
            D2_ASSERT(pStatList, 513);
        }
    }
    else
    {
        pStatList = sub_00625790_UnitFindStatList(pItem, nState, fFilter);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(!pItem ? 0 : pItem->pMemoryPool, fFilter, 0, 4, !pItem ? -1 : pItem->dwUnitId);
            D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
            STATLIST_SetState(pStatList, nState);
            D2_ASSERT(pStatList, 513);
        }
    }

    return pStatList;
}

// 0x0065CCC0
static __declspec(noinline) void __stdcall sub_0065CCC0_SetItemBaseStats(D2UnitStrc* pItem, int nStatId)
{
    int nItemId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    if (pItemsTxtRecord)
    {
        switch (nStatId)
        {
        case 16:
        case 31:
            if (ITEMS_CheckItemTypeId(pItem, 50) && pItemsTxtRecord->dwMaxAc)
            {
                int nValue = STATLIST_GetUnitBaseStat(pItem, 31, 0) + 1;
                if (nValue <= pItemsTxtRecord->dwMaxAc)
                {
                    nValue = pItemsTxtRecord->dwMaxAc + 1;
                }

                STATLIST_SetUnitStat(pItem, 31, nValue, 0);
            }
            break;

        case 17:
        case 22:
            if (ITEMS_CheckItemTypeId(pItem, 45))
            {
                if (pItemsTxtRecord->nMaxDam)
                {
                    STATLIST_SetUnitStat(pItem, 22, pItemsTxtRecord->nMaxDam, 0);
                }

                if (pItemsTxtRecord->n2HandMaxDam)
                {
                    STATLIST_SetUnitStat(pItem, 24, pItemsTxtRecord->n2HandMaxDam, 0);
                }

                if (ITEMS_CheckIfThrowable(pItem) && pItemsTxtRecord->nMaxMisDam)
                {
                    STATLIST_SetUnitStat(pItem, 160, pItemsTxtRecord->nMaxMisDam, 0);
                }
            }
            break;

        case 18:
        case 21:
            if (ITEMS_CheckItemTypeId(pItem, 45))
            {
                if (pItemsTxtRecord->nMinDam)
                {
                    STATLIST_SetUnitStat(pItem, 21, pItemsTxtRecord->nMinDam, 0);
                }

                if (pItemsTxtRecord->n2HandMinDam)
                {
                    STATLIST_SetUnitStat(pItem, 23, pItemsTxtRecord->n2HandMinDam, 0);
                }

                if (ITEMS_CheckIfThrowable(pItem) && pItemsTxtRecord->nMinMisDam)
                {
                    STATLIST_SetUnitStat(pItem, 159, pItemsTxtRecord->nMinMisDam, 0);
                }
            }
            break;

        default:
            return;
        }
    }
}

// 0x0065CE40
static __declspec(noinline) void sub_0065CE40_ShiftStatValue(int nStatId, int* pValue)
{
    switch (nStatId)
    {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 216:
    case 217:
        *pValue <<= 8;
        break;

    case 57:
    case 58:
        break;

    default:
        return;
    }
}

static __declspec(noinline) int __stdcall sub_0065CF40_AddRolledStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int a7, int nState, int fStatList)
{
    int nValue;
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;

    if (a7)
    {
        if (nMax != nMin)
        {
            if (nMax < nMin)
            {
                const int nTemp = nMax;
                nMax = nMin;
                nMin = nTemp;
            }

            int nPossibleRolls = nMax - nMin;
            if (ITEMS_GetItemFormat(pItem) >= 1)
            {
                ++nPossibleRolls;
            }

            nMin += ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
        }

        nValue = nMin;
        sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
    }
    else
    {
        if (nMax != nMin)
        {
            if (nMax < nMin)
            {
                const int nTemp = nMax;
                nMax = nMin;
                nMin = nTemp;
            }

            int nPossibleRolls = nMax - nMin;
            if (ITEMS_GetItemFormat(pItem) >= 1)
            {
                ++nPossibleRolls;
            }

            nMin += ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
        }

        nValue = nMin;
        if (nType == 1)
        {
            sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
        }
    }

    if (nValue)
    {
        sub_0065CE40_ShiftStatValue(nStatId, &nValue);

        D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
        D2_ASSERT(pStatList, 669);

        if (nApplyType)
        {
            nValue = -STATLIST_GetStatValue(pStatList, nStatId, 0);
        }

        STATLIST_AddStat(pStatList, nStatId, nValue, 0);
        if (nStatId == 58)
        {
            STATLIST_AddStat(pStatList, 326, 1, 0);
        }

        return 1;
    }

    return 0;
}

static __declspec(noinline) int __stdcall sub_0065D070_AddValueStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int a7, int nState, int fStatList)
{
    if (a7 || nType == 1)
    {
        sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
    }

    if (!nValue)
    {
        return 0;
    }

    sub_0065CE40_ShiftStatValue(nStatId, &nValue);

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(pStatList, 709);

    if (nApplyType)
    {
        STATLIST_AddStat(pStatList, nStatId, -STATLIST_GetStatValue(pStatList, nStatId, 0), 0);
    }
    else
    {
        STATLIST_AddStat(pStatList, nStatId, nValue, 0);
    }

    return 1;
}

int __fastcall sub_0065D110_AddLayerStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(pProperty, 738);

    int nValue = pProperty->nLayer;
    if (!nValue)
    {
        return 0;
    }

    if (nStatId >= 16 && nStatId <= 18 || nType == 1)
    {
        sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
    }

    sub_0065CE40_ShiftStatValue(nStatId, &nValue);

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(pStatList, 752);

    if (nApplyType)
    {
        nValue = -STATLIST_GetStatValue(pStatList, nStatId, 0);
    }

    STATLIST_AddStat(pStatList, nStatId, nValue, 0);
    return 1;
}

// 0x0065D1C0
int __fastcall sub_0065D1C0_AddRolledStat0(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    return sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, nStatId, nApplyType, 0, nState, fStatList);
}

static __forceinline int __stdcall sub_0065D1F0_AddValueStat0(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList)
{
    return sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, nStatId, nApplyType, 0, nState, fStatList);
}

// 0x0065D2B0
int __fastcall sub_0065D2B0_AddRolledStat1(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    return sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, nStatId, nApplyType, 1, nState, fStatList);
}

static __forceinline int __stdcall sub_0065D2E0_AddValueStat1(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList)
{
    return sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, nStatId, nApplyType, 1, nState, fStatList);
}

// build: context sub_0065D310_AddAllResist
int __fastcall sub_0065D310_AddAllResist(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2_ASSERT(pProperty, 841);

        int nValue;
        int nMin = pProperty->nMin;
        int nMax = pProperty->nMax;
        if (nMax == nMin)
        {
            nValue = nMin;
        }
        else
        {
            if (nMax < nMin)
            {
                const int nTemp = nMax;
                nMax = nMin;
                nMin = nTemp;
            }

            int nPossibleRolls = nMax - nMin;
            if (ITEMS_GetItemFormat(pItem) >= 1)
            {
                ++nPossibleRolls;
            }

            nValue = nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
        }

        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 39, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 41, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 43, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 45, nApplyType, nState, fStatList);
    }
    else
    {
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 39, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 41, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 43, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 45, nApplyType, 0, nState, fStatList);
    }

    return nStatId;
}

// build: context sub_0065D4B0_AddAllMaxResist
int __fastcall sub_0065D4B0_AddAllMaxResist(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2_ASSERT(pProperty, 868);

        int nValue;
        int nMin = pProperty->nMin;
        int nMax = pProperty->nMax;
        if (nMax == nMin)
        {
            nValue = nMin;
        }
        else
        {
            if (nMax < nMin)
            {
                const int nTemp = nMax;
                nMax = nMin;
                nMin = nTemp;
            }

            int nPossibleRolls = nMax - nMin;
            if (ITEMS_GetItemFormat(pItem) >= 1)
            {
                ++nPossibleRolls;
            }

            nValue = nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
        }

        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 40, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 42, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 44, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 46, nApplyType, nState, fStatList);
    }
    else
    {
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 40, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 42, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 44, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 46, nApplyType, 0, nState, fStatList);
    }

    return nStatId;
}

// build: context sub_0065D650_AddMinDamage
int __fastcall sub_0065D650_AddMinDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(pProperty, 891);

    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;
    if (nMin != nMax)
    {
        if (nMax < nMin)
        {
            const int nTemp = nMax;
            nMax = nMin;
            nMin = nTemp;
        }

        int nPossibleRolls = nMax - nMin;
        if (ITEMS_GetItemFormat(pItem) >= 1)
        {
            ++nPossibleRolls;
        }

        nMin += ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
    }

    D2ItemsTxt* pItemsTxtRecord;
    if (pUnit && pUnit->dwUnitType == 4)
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pUnit->dwClassId);
    }
    else
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem ? pItem->dwClassId : -1);
    }

    if (!ITEMS_CheckItemTypeId(pItem, 45) || pItemsTxtRecord->nMinDam || !pItemsTxtRecord->n2HandMinDam)
    {
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 21, nApplyType, nState, fStatList);
    }

    if (!ITEMS_CheckItemTypeId(pItem, 45) || pItemsTxtRecord->n2HandMinDam || !pItemsTxtRecord->nMinDam)
    {
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 23, nApplyType, nState, fStatList);
    }

    if (!ITEMS_CheckItemTypeId(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
    {
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 159, nApplyType, nState, fStatList);
    }

    return 1;
}

// build: context sub_0065D7D0_AddMaxDamage
int __fastcall sub_0065D7D0_AddMaxDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(pProperty, 919);

    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;
    if (nMin != nMax)
    {
        if (nMax < nMin)
        {
            const int nTemp = nMax;
            nMax = nMin;
            nMin = nTemp;
        }

        int nPossibleRolls = nMax - nMin;
        if (ITEMS_GetItemFormat(pItem) >= 1)
        {
            ++nPossibleRolls;
        }

        nMin += ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
    }

    D2ItemsTxt* pItemsTxtRecord;
    if (pUnit && pUnit->dwUnitType == 4)
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pUnit->dwClassId);
    }
    else
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem ? pItem->dwClassId : -1);
    }

    if (!ITEMS_CheckItemTypeId(pItem, 45) || pItemsTxtRecord->nMaxDam || !pItemsTxtRecord->n2HandMaxDam)
    {
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 22, nApplyType, nState, fStatList);
    }

    if (!ITEMS_CheckItemTypeId(pItem, 45) || pItemsTxtRecord->n2HandMaxDam || !pItemsTxtRecord->nMinDam)
    {
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 24, nApplyType, nState, fStatList);
    }

    if (!ITEMS_CheckItemTypeId(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
    {
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 160, nApplyType, nState, fStatList);
    }

    return 1;
}

int __fastcall sub_0065D950_AddDamagePercent(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2_ASSERT(pProperty, 949);

        int nValue;
        int nMin = pProperty->nMin;
        int nMax = pProperty->nMax;
        if (nMax == nMin)
        {
            nValue = nMin;
        }
        else
        {
            if (nMax < nMin)
            {
                const int nTemp = nMax;
                nMax = nMin;
                nMin = nTemp;
            }

            int nPossibleRolls = nMax - nMin;
            if (ITEMS_GetItemFormat(pItem) >= 1)
            {
                ++nPossibleRolls;
            }

            nValue = nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
        }

        D2ItemsTxt* pItemsTxtRecord;
        if (pUnit && pUnit->dwUnitType == 4)
        {
            pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pUnit->dwClassId);
        }
        else
        {
            pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem ? pItem->dwClassId : -1);
        }

        D2_ASSERT(pItemsTxtRecord, 960);

        unsigned char nMaxDam = pItemsTxtRecord->n2HandMaxDam;
        if (nMaxDam <= pItemsTxtRecord->nMaxDam)
        {
            nMaxDam = pItemsTxtRecord->nMaxDam;
        }

        if (ITEMS_CheckItemTypeId(pItem, 45) && nMaxDam + (nValue * nMaxDam) / 100 <= nMaxDam)
        {
            if (pItemsTxtRecord->nMinDam)
            {
                sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, 1, 22, nApplyType, nState, fStatList);
            }

            if (pItemsTxtRecord->n2HandMinDam)
            {
                sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, 1, 24, nApplyType, nState, fStatList);
            }

            if (ITEMS_CheckIfThrowable(pItem))
            {
                sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, 1, 160, nApplyType, nState, fStatList);
            }

            return nStatId;
        }

        sub_0065D2E0_AddValueStat1(nType, pUnit, pItem, nValue, 17, nApplyType, nState, fStatList);
        sub_0065D2E0_AddValueStat1(nType, pUnit, pItem, nValue, 18, nApplyType, nState, fStatList);
        return nStatId;
    }

    sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 17, nApplyType, 1, nState, fStatList);
    sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 18, nApplyType, 1, nState, fStatList);
    return nStatId;
}

// 0x0065DB90
int __fastcall sub_0065DB90_AddAllSkills(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 127, nApplyType, 0, nState, fStatList);
    return nStatId;
}

int __fastcall sub_0065DE40_AddStatPair(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;

    sub_0065CE40_ShiftStatValue(nStatId, &nMin);
    sub_0065CE40_ShiftStatValue(nStatId + 1, &nMax);

    if (nStatId == 21)
    {
        D2ItemsTxt* pItemsTxtRecord;
        if (pUnit && pUnit->dwUnitType == 4)
        {
            pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pUnit->dwClassId);
        }
        else
        {
            pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem ? pItem->dwClassId : -1);
        }

        if (!ITEMS_CheckItemTypeId(pItem, 45) || pItemsTxtRecord->nMaxDam || !pItemsTxtRecord->n2HandMaxDam)
        {
            sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 21, nApplyType, nState, fStatList);
            sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMax, 22, nApplyType, nState, fStatList);
        }

        if (!ITEMS_CheckItemTypeId(pItem, 45) || pItemsTxtRecord->n2HandMaxDam || !pItemsTxtRecord->nMinDam)
        {
            sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 23, nApplyType, nState, fStatList);
            sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMax, 24, nApplyType, nState, fStatList);
        }

        if (ITEMS_CheckIfThrowable(pItem))
        {
            sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 159, nApplyType, nState, fStatList);
            sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMax, 160, nApplyType, nState, fStatList);
        }
    }
    else
    {
        D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
        D2_ASSERT(pStatList, 1157);

        if (nApplyType)
        {
            nMin = -STATLIST_GetStatValue(pStatList, nStatId, 0);
            nMax = -STATLIST_GetStatValue(pStatList, nStatId + 1, 0);
        }

        STATLIST_AddStat(pStatList, nStatId, nMin, 0);
        STATLIST_AddStat(pStatList, nStatId + 1, nMax, 0);

        if (nStatId == 57)
        {
            STATLIST_AddStat(pStatList, 326, 1, 0);
        }
    }

    return 1;
}

// build: context sub_0065E070_AddStatTriple
int __fastcall sub_0065E070_AddStatTriple(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;
    int nLayer = pProperty->nLayer;

    sub_0065CE40_ShiftStatValue(nStatId, &nMin);
    sub_0065CE40_ShiftStatValue(nStatId + 1, &nMax);
    sub_0065CE40_ShiftStatValue(nStatId + 2, &nLayer);

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(pStatList, 1197);

    if (nApplyType)
    {
        nMin = -STATLIST_GetStatValue(pStatList, nStatId, 0);
        nMax = -STATLIST_GetStatValue(pStatList, nStatId + 1, 0);
        nLayer = -STATLIST_GetStatValue(pStatList, nStatId + 2, 0);
    }

    STATLIST_AddStat(pStatList, nStatId, nMin, 0);
    STATLIST_AddStat(pStatList, nStatId + 1, nMax, 0);
    STATLIST_AddStat(pStatList, nStatId + 2, nLayer, 0);

    if (nStatId == 57)
    {
        STATLIST_AddStat(pStatList, 326, 1, 0);
    }

    return 1;
}

// build: context sub_0065E450_AddRolledValueStat
int __fastcall sub_0065E450_AddRolledValueStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;
    if (nMin != nMax)
    {
        if (nMax < nMin)
        {
            const int nTemp = nMax;
            nMax = nMin;
            nMin = nTemp;
        }

        int nPossibleRolls = nMax - nMin;
        if (ITEMS_GetItemFormat(pItem) >= 1)
        {
            ++nPossibleRolls;
        }

        nMin += ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
    }

    return sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, nStatId, nApplyType, nState, fStatList);
}

// 0x0065EB30
int __fastcall ITEMMODS_PropertyFunc01(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == 4 && nType == 1)
    {
        sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
}

// 0x0065EBA0
int __fastcall ITEMMODS_PropertyFunc02(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == 4)
    {
        sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
}

// 0x0065EC10
int __fastcall ITEMMODS_PropertyFunc03(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == 4 && nType == 1)
    {
        sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
    }

    int nMin = nValue;
    if (!nValue)
    {
        nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
}

// 0x0065EC80
int __fastcall ITEMMODS_PropertyFunc04(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == 4)
    {
        sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
    }

    int nMin = nValue;
    if (!nValue)
    {
        nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
}

// 0x0065FC90
int __fastcall ITEMMODS_PropertyFunc13(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty || !pItem)
    {
        return 0;
    }

    if (pItem->dwUnitType == 4 && nType == 1)
    {
        sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    const int nResult = ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
    if (nResult)
    {
        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (nMaxDurability > 0)
        {
            STATLIST_SetUnitStat(pItem, 72, nMaxDurability, 0);
        }

        return nResult;
    }

    return 0;
}
