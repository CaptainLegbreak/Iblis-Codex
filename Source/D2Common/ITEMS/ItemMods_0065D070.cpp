#include "D2Common.h"
#include "D2Structs.h"
#include "D2Txt.h"

struct D2SeedStrc;


struct D2PropertyStrc
{
    int nProperty;
    int nLayer;
    int nMin;
    int nMax;
};


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

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
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax);                      // 0x0065E9E0
int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState); // 0x0065EA50

// build: symbol ?ITEMMODS_GetOrCreateStatList@@YGPAUD2StatListStrc@@PAUD2UnitStrc@@0HH@Z 0x0065CBF0
static __declspec(noinline) D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter)
{
    D2StatListStrc* pStatList;

    if (pUnit)
    {
        pStatList = sub_00625790_UnitFindStatList(pUnit, nState, fFilter);
        if (!pStatList)
        {
            int nUnitGUID = pUnit->dwUnitId;
            void* pMemPool = pUnit->pMemoryPool;
            pStatList = STATLIST_AllocStatList(pMemPool, fFilter, 0, 4, nUnitGUID);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATLIST_SetState(pStatList, nState);
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
        }
    }

    D2_ASSERT(pStatList, 513);
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
            if (ITEMSIsA(pItem, 50) && pItemsTxtRecord->dwMaxAc)
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
            if (ITEMSIsA(pItem, 45))
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
            if (ITEMSIsA(pItem, 45))
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

static __forceinline int ITEMMODS_RollPropertyValueA(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMax == nMin)
    {
        return nMin;
    }
    if (nMax < nMin)
    {
        const int nTemp = nMax;
        nMax = nMin;
        nMin = nTemp;
    }
    int nPossibleRolls;
    if (ITEMS_GetItemFormat(pItem) < 1)
    {
        nPossibleRolls = nMax - nMin;
    }
    else
    {
        nPossibleRolls = nMax - nMin + 1;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
}

static __forceinline int ITEMMODS_RollPropertyValueB(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMin == nMax)
    {
        return nMin;
    }
    if (nMax < nMin)
    {
        const int nTemp = nMax;
        nMax = nMin;
        nMin = nTemp;
    }
    int nPossibleRolls;
    if (ITEMS_GetItemFormat(pItem) < 1)
    {
        nPossibleRolls = nMax - nMin;
    }
    else
    {
        nPossibleRolls = nMax - nMin + 1;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
}

static __forceinline D2ItemsTxt* __fastcall sub_0065E9B0(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pUnit && pUnit->dwUnitType == 4)
    {
        return DATATBLS_GetItemsTxtRecord(pUnit->dwClassId);
    }
    return DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
}

static __declspec(noinline) int __stdcall sub_0065CF40_AddRolledStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int a7, int nState, int fStatList)
{
    int nValue;
    if (a7)
    {
        nValue = ITEMMODS_RollPropertyValueA(pItem, pProperty->nMin, pProperty->nMax);
        sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
    }
    else
    {
        nValue = ITEMMODS_RollPropertyValueA(pItem, pProperty->nMin, pProperty->nMax);
        if (nType == 1)
        {
            sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
        }
    }

    if (!nValue)
    {
        return 0;
    }

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

// 0x0065D070
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
    D2StatListStrc* hStatsList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(hStatsList, 709);
    if (nApplyType)
    {
        nValue = -STATLIST_GetStatValue(hStatsList, nStatId, 0);
    }
    STATLIST_AddStat(hStatsList, nStatId, nValue, 0);
    return 1;
}

// 0x0065D110
int __fastcall sub_0065D110_AddLayerStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(ptProperty, 738);
    int nValue = ptProperty->nLayer;
    if (!nValue)
    {
        return 0;
    }
    if (nStatId >= 16 && nStatId <= 18 || nType == 1)
    {
        sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
    }
    sub_0065CE40_ShiftStatValue(nStatId, &nValue);
    D2StatListStrc* hStatsList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(hStatsList, 752);
    if (nApplyType)
    {
        nValue = -STATLIST_GetStatValue(hStatsList, nStatId, 0);
    }
    STATLIST_AddStat(hStatsList, nStatId, nValue, 0);
    return 1;
}

// 0x0065D1F0
static int __stdcall sub_0065D1F0_AddValueStat0(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList)
{
    return sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, nStatId, nApplyType, 0, nState, fStatList);
}

// 0x0065D2E0
static int __stdcall sub_0065D2E0_AddValueStat1(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList)
{
    return sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, nStatId, nApplyType, 1, nState, fStatList);
}

// 0x0065D310
int __fastcall sub_0065D310_AddAllResist(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2_ASSERT(ptProperty, 841);
        const int nValue = ITEMMODS_RollPropertyValueA(pItem, ptProperty->nMin, ptProperty->nMax);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 39, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 41, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 43, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 45, nApplyType, nState, fStatList);
    }
    else
    {
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, ptProperty, 39, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, ptProperty, 41, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, ptProperty, 43, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, ptProperty, 45, nApplyType, 0, nState, fStatList);
    }
    return nStatId;
}

// 0x0065D4B0
int __fastcall sub_0065D4B0_AddAllMaxResist(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2_ASSERT(ptProperty, 868);
        const int nValue = ITEMMODS_RollPropertyValueA(pItem, ptProperty->nMin, ptProperty->nMax);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 40, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 42, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 44, nApplyType, nState, fStatList);
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nValue, 46, nApplyType, nState, fStatList);
    }
    else
    {
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, ptProperty, 40, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, ptProperty, 42, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, ptProperty, 44, nApplyType, 0, nState, fStatList);
        sub_0065CF40_AddRolledStat(nType, pUnit, pItem, ptProperty, 46, nApplyType, 0, nState, fStatList);
    }
    return nStatId;
}

// build: context sub_0065D650_AddMinDamage
int __fastcall sub_0065D650_AddMinDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(pProperty, 891);
    const int nMin = ITEMMODS_RollPropertyValueB(pItem, pProperty->nMin, pProperty->nMax);
    D2ItemsTxt* pItemsTxtRecord = sub_0065E9B0(pUnit, pItem);
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->nMinDam || !pItemsTxtRecord->n2HandMinDam)
    {
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 21, nApplyType, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->n2HandMinDam || !pItemsTxtRecord->nMinDam)
    {
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 23, nApplyType, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
    {
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 159, nApplyType, nState, fStatList);
    }
    return 1;
}

// build: context sub_0065D7D0_AddMaxDamage
int __fastcall sub_0065D7D0_AddMaxDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(pProperty, 919);
    const int nMin = ITEMMODS_RollPropertyValueB(pItem, pProperty->nMin, pProperty->nMax);
    D2ItemsTxt* pItemsTxtRecord = sub_0065E9B0(pUnit, pItem);
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->nMaxDam || !pItemsTxtRecord->n2HandMaxDam)
    {
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 22, nApplyType, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->n2HandMaxDam || !pItemsTxtRecord->nMinDam)
    {
        sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 24, nApplyType, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
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
        const int nValue = ITEMMODS_RollPropertyValueA(pItem, pProperty->nMin, pProperty->nMax);
        D2ItemsTxt* pItemsTxtRecord = sub_0065E9B0(pUnit, pItem);
        D2_ASSERT(pItemsTxtRecord, 960);
        unsigned char nMaxDam = pItemsTxtRecord->n2HandMaxDam;
        if (nMaxDam <= pItemsTxtRecord->nMaxDam)
        {
            nMaxDam = pItemsTxtRecord->nMaxDam;
        }
        if (ITEMSIsA(pItem, 45) && nMaxDam + (nValue * nMaxDam) / 100 <= nMaxDam)
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

int __fastcall sub_0065DE40_AddStatPair(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;
    const int nStatId1 = nStatId + 1;
    sub_0065CE40_ShiftStatValue(nStatId, &nMin);
    sub_0065CE40_ShiftStatValue(nStatId1, &nMax);
    if (nStatId == 21)
    {
        int nClassId;
        if (pUnit && pUnit->dwUnitType == 4)
        {
            nClassId = pUnit->dwClassId;
        }
        else
        {
            nClassId = !pItem ? -1 : pItem->dwClassId;
        }
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
        if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->nMaxDam || !pItemsTxtRecord->n2HandMaxDam)
        {
            sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, 21, nApplyType, nState, fStatList);
            sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMax, 22, nApplyType, nState, fStatList);
        }
        if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->n2HandMaxDam || !pItemsTxtRecord->nMinDam)
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
            nMax = -STATLIST_GetStatValue(pStatList, nStatId1, 0);
        }
        STATLIST_AddStat(pStatList, nStatId, nMin, 0);
        STATLIST_AddStat(pStatList, nStatId1, nMax, 0);
        if (nStatId == 57)
        {
            STATLIST_AddStat(pStatList, 326, 1, 0);
        }
    }
    return 1;
}

int __fastcall sub_0065E070_AddStatTriple(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;
    int nLayer = pProperty->nLayer;
    const int nStatId1 = nStatId + 1;
    const int nStatId2 = nStatId + 2;
    sub_0065CE40_ShiftStatValue(nStatId, &nMin);
    sub_0065CE40_ShiftStatValue(nStatId1, &nMax);
    sub_0065CE40_ShiftStatValue(nStatId2, &nLayer);
    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(pStatList, 1197);
    if (nApplyType)
    {
        nMin = -STATLIST_GetStatValue(pStatList, nStatId, 0);
        nMax = -STATLIST_GetStatValue(pStatList, nStatId1, 0);
        nLayer = -STATLIST_GetStatValue(pStatList, nStatId2, 0);
    }
    STATLIST_AddStat(pStatList, nStatId, nMin, 0);
    STATLIST_AddStat(pStatList, nStatId1, nMax, 0);
    STATLIST_AddStat(pStatList, nStatId2, nLayer, 0);
    if (nStatId == 57)
    {
        STATLIST_AddStat(pStatList, 326, 1, 0);
    }
    return 1;
}

// 0x0065E450
int __fastcall sub_0065E450_AddRangeStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    const int nMin = ITEMMODS_RollPropertyValueB(pItem, pProperty->nMin, pProperty->nMax);
    return sub_0065D1F0_AddValueStat0(nType, pUnit, pItem, nMin, nStatId, nApplyType, nState, fStatList);
}

int __fastcall sub_0065D1C0_AddRolledStat0(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    return sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, nStatId, nApplyType, 0, nState, fStatList);
}

int __fastcall sub_0065D2B0_AddRolledStat1(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    return sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, nStatId, nApplyType, 1, nState, fStatList);
}

int __fastcall sub_0065DB90_AddAllSkills(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    sub_0065CF40_AddRolledStat(nType, pUnit, pItem, pProperty, 127, nApplyType, 0, nState, fStatList);
    return nStatId;
}

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
