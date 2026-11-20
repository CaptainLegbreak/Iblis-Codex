#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#define STAT_POISONMAXDAM 58
#define STAT_POISON_COUNT 326
union D2SeedStrc;
struct D2PropertyStrc;
struct D2ItemsTxt;
struct D2ItemStatCostTxt;
struct D2MagicAffixTxt;
struct D2GradeModsStrc;
struct D2GemsTxt;
struct D2UniqueItemsTxt;
struct D2SetItemsTxt;
struct D2PropertyAssignStrc;




extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax); // 0x0065E9E0
int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState); // 0x0065EA50
int __stdcall sub_006254E0_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x006254E0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0
extern int gaItemFileIndices_0074638C[]; // 0x0074638C
extern int gnItemFileIndexCount_007463A4; // 0x007463A4



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

struct D2MagicAffixTxt
{
    char pad0x00[0x24];
    D2PropertyStrc pProperties[3];
};

struct D2GradeModsStrc
{
    char pad0x00[0xC];
    D2PropertyStrc pProperties[12];
};

struct D2GemsTxt
{
    char pad0x00[0x30];
    D2PropertyStrc pProperties[3][3];
};



struct D2SetsTxt
{
    char pad0x00[0x0C];
    int nSetItems;
    D2PropertyStrc pBoni2[8];
    D2PropertyStrc pFBoni[8];
};

typedef int (__fastcall* ITEMMODS_PROPERTYFN)(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatlist, D2UnitStrc* a9);

struct D2PropertyAssignStrc
{
    ITEMMODS_PROPERTYFN pfAssign;
    int nStatId;
};

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nUniqueItemId); // 0x00483470
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex); // 0x00483440
void __stdcall D2COMMON_11292_ItemAssignProperty(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a10); // 0x0065FD70
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* pItem); // 0x0065E4D0
extern D2PropertyAssignStrc gtPropertyAssignTable_00745B58[]; // 0x00745B58
extern "C" const char gszItemModsFile_006EDB78[]; // 0x006EDB78

static __declspec(noinline) D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter);

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
        return DATATBLS_GetItemsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
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

// build: context sub_0065D070_AddValueStat
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
        nValue = -STATLIST_GetStatValue(pStatList, nStatId, 0);
    }
    STATLIST_AddStat(pStatList, nStatId, nValue, 0);
    return 1;
}

// build: context sub_0065D110_AddLayerStat
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
int __fastcall sub_0065D310_AddAllResist(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2_ASSERT(pProperty, 841);
        const int nValue = ITEMMODS_RollPropertyValueA(pItem, pProperty->nMin, pProperty->nMax);
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

// 0x0065D4B0
int __fastcall sub_0065D4B0_AddAllMaxResist(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2_ASSERT(pProperty, 868);
        const int nValue = ITEMMODS_RollPropertyValueA(pItem, pProperty->nMin, pProperty->nMax);
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

// 0x0065D650
int __fastcall sub_0065D650_AddMinDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(ptProperty, 891);
    const int nValue = ITEMMODS_RollPropertyValueB(pItem, ptProperty->nMin, ptProperty->nMax);
    D2ItemsTxt* pItemsTxtRecord = sub_0065E9B0(pUnit, pItem);
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->nMinDam || !pItemsTxtRecord->n2HandMinDam)
    {
        sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, 21, nApplyType, 0, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->n2HandMinDam || !pItemsTxtRecord->nMinDam)
    {
        sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, 23, nApplyType, 0, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
    {
        sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, 159, nApplyType, 0, nState, fStatList);
    }
    return 1;
}

// 0x0065D7D0
int __fastcall sub_0065D7D0_AddMaxDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(ptProperty, 919);
    const int nValue = ITEMMODS_RollPropertyValueB(pItem, ptProperty->nMin, ptProperty->nMax);
    D2ItemsTxt* pItemsTxtRecord = sub_0065E9B0(pUnit, pItem);
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->nMaxDam || !pItemsTxtRecord->n2HandMaxDam)
    {
        sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, 22, nApplyType, 0, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->n2HandMaxDam || !pItemsTxtRecord->nMinDam)
    {
        sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, 24, nApplyType, 0, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
    {
        sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, 160, nApplyType, 0, nState, fStatList);
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

// 0x0065CBF0
static __declspec(noinline) D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter)
{
    D2StatListStrc* pStatList;

    if (pUnit)
    {
        pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pUnit, nState, fFilter);
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
        pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pItem, nState, fFilter);
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

// 0x0065E2D0
int __fastcall sub_0065E2D0_AddClassSkillStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nPropertyId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    int nValue;
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;

    if (nMin == nMax)
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

        int nPossibleRolls;
        if (ITEMS_GetItemFormat(pItem) < 1)
        {
            nPossibleRolls = nMax - nMin;
        }
        else
        {
            nPossibleRolls = nMax - nMin + 1;
        }

        nValue = nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
    }

    if (!nValue)
    {
        return 0;
    }

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
    {
        return 0;
    }

    int nClass = 0;
    switch (nPropertyId)
    {
    case 83:
        nClass = 0;
        break;
    case 84:
        nClass = 1;
        break;
    case 85:
        nClass = 2;
        break;
    case 86:
        nClass = 3;
        break;
    case 87:
        nClass = 4;
        break;
    case 179:
        nClass = 5;
        break;
    case 180:
        nClass = 6;
        break;
    }

    if (nApplyType)
    {
        nValue = -sub_006254E0_GetStatValue(pStatList, 83, nClass);
    }

    STATLIST_AddStat(pStatList, 83, nValue, nClass);
    return 1;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x0065E8E0
void __stdcall sub_0065E8E0_InitItemFileIndex(D2UnitStrc* pItem)
{
    const int nCount = gnItemFileIndexCount_007463A4;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);
    const int nIndex = SEED_RollLimitedRandomNumber(pSeed, nCount);
    ITEMS_SetFileIndex(pItem, gaItemFileIndices_0074638C[nIndex]);

    const int nFileIndex = gaItemFileIndices_0074638C[nIndex];
    int nValue;
    if (nFileIndex == 9)
    {
        nValue = ((SEED_RollRandomNumber(ITEMS_GetItemSeed(pItem)) & 3) + 1) << 8;
    }
    else if (nFileIndex == 7)
    {
        nValue = ((SEED_RollRandomNumber(ITEMS_GetItemSeed(pItem)) & 3) + 1) << 8;
    }
    else
    {
        nValue = 1;
    }
    STATLIST_SetUnitStat(pItem, 0x47, nValue, 0);
}

#include "gen/data/Source/D2Common/ITEMS/ItemMods_0065D650.inc"
struct D2UnitStrc;

static __forceinline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }

    return 0;
}

// 0x0065EA50
int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState)
{
    if (!pProperty)
    {
        return 0;
    }

    if (!nValue)
    {
        return 0;
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
    {
        return 0;
    }

    if (nSet)
    {
        const unsigned char nShift = pItemStatCostTxtRecord->nValShift;
        STATLIST_SetStatIfListIsValid(pStatList, nStatId, (*(int volatile*)&nValue) << nShift, nLayer);

        if (nStatId == STAT_POISONMAXDAM && !STATLIST_GetStatValue(pStatList, STAT_POISON_COUNT, 0))
        {
            STATLIST_SetStatIfListIsValid(pStatList, STAT_POISON_COUNT, 1, 0);
        }
    }
    else
    {
        STATLIST_AddStat(pStatList, nStatId, nValue << pItemStatCostTxtRecord->nValShift, nLayer);

        if (nStatId == STAT_POISONMAXDAM)
        {
            STATLIST_AddStat(pStatList, STAT_POISON_COUNT, 1, 0);
        }
    }

    return nValue;
}

static const D2PropertyStrc* sub_0065C660_GetAffixProperty(const D2MagicAffixTxt* pMods, int nMod)
{
    D2_ASSERT(pMods, 0x79);
    if ((unsigned int)nMod < 3)
    {
        return &pMods->pProperties[nMod];
    }

    D2_ASSERT(0, 0x7A);
    return 0;
}

static const D2PropertyStrc* sub_0065C6A0_GetGradeProperty(const D2GradeModsStrc* pMods, int nMod)
{
    if ((unsigned int)nMod < 12)
    {
        return &pMods->pProperties[nMod];
    }

    D2_ASSERT(0, 0x81);
    return 0;
}

static const D2PropertyStrc* sub_0065C6D0_GetGemProperty(const D2GemsTxt* pMods, int nPropSet, int nMod)
{
    const D2PropertyStrc* pProperties[3];
    pProperties[0] = pMods->pProperties[0];
    pProperties[1] = pMods->pProperties[1];
    pProperties[2] = pMods->pProperties[2];
    D2_ASSERT((unsigned int)nPropSet < 3, 0x8F);
    if ((unsigned int)nMod < 3)
    {
        return &pProperties[nPropSet][nMod];
    }

    D2_ASSERT(0, 0x90);
    return 0;
}

// 0x0065C730
static const D2PropertyStrc* sub_0065C730_GetModsProperty(int nType, const void* pMods, int nMod, int nPropSet)
{
    switch (nType)
    {
    case 0:
        return sub_0065C660_GetAffixProperty((const D2MagicAffixTxt*)pMods, nMod);
    case 1:
        return sub_0065C6A0_GetGradeProperty((const D2GradeModsStrc*)pMods, nMod);
    case 2:
        return sub_0065C6D0_GetGemProperty((const D2GemsTxt*)pMods, nPropSet, nMod);
    case 5:
        return sub_0065C6D0_GetGemProperty((const D2GemsTxt*)pMods, nPropSet, nMod);
    case 3:
    case 4:
        return 0;
    case 6:
    case 7:
        return (const D2PropertyStrc*)pMods;
    default:
        D2_ASSERT(0, 0xAF);
        return 0;
    }
}

// 0x0065FE10
static void __stdcall sub_0065FE10(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, int nApplyType, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a11)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2COMMON_11292_ItemAssignProperty(nType, pUnit, pItem, pMods, nIndex, nPropSet, pProperty, nState, fStatlist, a11);
    }
    else
    {
        D2_ASSERT(pProperty, 0x66D);

        const int nProperty = pProperty->nProperty;
        if (nProperty != -1 && nProperty >= 0 && nProperty < sgptDataTables->nPropertiesTxtRecordCount)
        {
            ITEMMODS_PROPERTYFN pfAssign = gtPropertyAssignTable_00745B58[nProperty].pfAssign;
            if (pfAssign)
            {
                pfAssign(nType, pUnit, pItem, pProperty, gtPropertyAssignTable_00745B58[nProperty].nStatId, nApplyType, nState, fStatlist, a11);
            }
        }
    }
}

// build: context SetItemFlag
static __forceinline int SetItemFlag(const D2SetItemsTxt* pRecord, int nIndex)
{
    if (!pRecord->nAddFunc)
        return 0x40;
    return gnSetItemStatlistFlags_006EDB5C[nIndex];
}

// build: context SetItemState
static __forceinline int SetItemState(const D2SetItemsTxt* pRecord, int nIndex)
{
    if (!pRecord->nAddFunc)
        return 0;
    return gnSetItemStates_006EDB40[nIndex];
}

// 0x0065FEC0
void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType)
{
    int nProperties = 0;
    switch (nType)
    {
    case 0:
    case 2:
    case 5:
        nProperties = 3;
        break;

    case 1:
        nProperties = 2;
        break;

    case 3:
        if (ITEMS_GetFileIndex(pItem) >= 0)
        {
            D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (pUniqueItemsTxtRecord)
            {
                for (int i = 0; i < 12; ++i)
                {
                    sub_0065FE10(3, 0, pItem, 0, 0, 0, nApplyType, &pUniqueItemsTxtRecord->pProperties[i], 0, 0x40, 0);
                }
                return;
            }
        }
        break;

    case 4:
    {
        D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
        if (!pSetItemsTxtRecord)
        {
            return;
        }

        if (!ITEMS_GetItemFormat(pItem))
        {
            for (int i = 0; i < 2; ++i)
            {
                sub_0065FE10(4, 0, pItem, 0, 0, 0, nApplyType, &pSetItemsTxtRecord->pProperties[i], 0, 0x40, 0);
            }
            return;
        }

        for (int i = 0; i < 9; ++i)
        {
            sub_0065FE10(4, 0, pItem, 0, 0, 0, nApplyType, &pSetItemsTxtRecord->pProperties[i], 0, 0x40, 0);
        }

        for (int i = 0; i < 10; ++i)
        {
            const int nIndex = i / 2 + 2;
            const int nFlag = SetItemFlag(pSetItemsTxtRecord, nIndex);
            const int nState = SetItemState(pSetItemsTxtRecord, nIndex);
            sub_0065FE10(4, 0, pItem, 0, 0, 0, nApplyType, &pSetItemsTxtRecord->pPartialBoni[i], nState, nFlag, 0);
        }
        return;
    }
    }

    for (int nMod = 0; nMod < nProperties; ++nMod)
    {
        const D2PropertyStrc* pProperty = sub_0065C730_GetModsProperty(nType, pMods, nMod, nPropSet);
        if (!pProperty || pProperty->nProperty < 0)
        {
            break;
        }

        sub_0065FE10(nType, 0, pItem, pMods, nMod, nPropSet, nApplyType, pProperty, 0, 0x40, a2);
    }
}

// 0x00660120
void __fastcall ITEMMODS_UpdateFullSetBoni(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState)
{
    if (!nState)
    {
        return;
    }

    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType == 4 && ITEMS_GetItemQuality(pItem) == 5)
    {
        D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
        if (pSetItemsTxtRecord)
        {
            D2SetsTxt* pSetsTxtRecord = sub_00483410_GetSetsTxtRecord(pSetItemsTxtRecord->nSetId);
            if (pSetsTxtRecord)
            {
                const unsigned int nMask = ITEMS_GetSetItemsMask(pUnit, pItem, 1);
                int nItems;
                if (nMask >= 0x40)
                {
                    nItems = 0;
                }
                else
                {
                    nItems = gnSetItemsCount_006EDA40[nMask];
                }

                const int nCount = nItems < pSetsTxtRecord->nSetItems - 1 ? nItems : pSetsTxtRecord->nSetItems - 1;
                for (int i = 0; i < 2 * (nCount - 1); ++i)
                {
                    const D2PropertyStrc* pProperty = &pSetsTxtRecord->pBoni2[i];
                    if (pProperty->nProperty >= 0)
                    {
                        sub_0065FE10(4, pUnit, pItem, 0, i, 0, 0, pProperty, nState, 0, 0);
                    }
                }

                if (nItems >= pSetsTxtRecord->nSetItems)
                {
                    for (int i = 0; i < 8; ++i)
                    {
                        const D2PropertyStrc* pProperty = &pSetsTxtRecord->pFBoni[i];
                        if (pProperty->nProperty < 0)
                        {
                            break;
                        }

                        sub_0065FE10(4, pUnit, pItem, 0, i, 0, 0, pProperty, nState, 0, 0);
                    }
                }
            }
        }
    }
}

// 0x00660240
void __stdcall ITEMMODS_AddCraftPropertyList(D2UnitStrc* pItem, D2PropertyStrc* pProperty, int nUnused)
{
    if (pItem)
    {
        sub_0065FE10(7, 0, pItem, pProperty, 0, 0, 0, pProperty, 0, 0x40, 0);
        if (ITEMS_CheckItemFlag(pItem, 0x400000, 0x858, gszItemModsFile_006EDB78))
        {
            ITEMMODS_ApplyEthereality(pItem);
        }
    }
}
