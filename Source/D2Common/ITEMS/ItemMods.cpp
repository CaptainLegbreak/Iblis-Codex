#include "D2Common.h"

#pragma intrinsic(_ReadWriteBarrier)

#define IM_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define MAXIMUM(a,b) (((a)>(b))?(a):(b))
#define MINIMUM(a,b) (((a)<(b))?(a):(b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SeedStrc;
struct Property;
struct D2PropertyStrc;
struct D2ItemsTxt;
struct D2RunesTxt;
struct D2DataTablesStrc;
struct D2UnitStrc;
struct Unit;
struct D2ItemStatCostTxt;
struct D2StatListStrc;

struct D2DataTablesStrc
{
    char unk0x00[0xAC];
    int nPropertiesTxtRecordCount;
    unsigned char unk_B0[0xAF0];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x28];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0x04];
    int nItemStatCostTxtRecordCount;
    char unk0xBD8[0x94];
    int nStuff;
    unsigned int dwStuffMask;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

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

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);
D2StatListStrc* __stdcall sub_00625790_UnitFindStatList(D2UnitStrc* pUnit, int nState, int nFlag);
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);
int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax);
int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState);
static __declspec(noinline) int sub_0065CCA0_IsPercentStat(int nStatId);

struct Unit { int type; };

void __stdcall sub_00627260(Unit*,int,int,unsigned short); // 0x00627260

enum { MAX_DURABILITY = 73, DURABILITY = 72 };

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
int __stdcall sub_006254E0_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);

struct Property { int id; int layer; int minimum; int maximum; };

void __stdcall sub_006286C0(Unit*,unsigned char*,unsigned char*,const char*,int); // 0x006286C0
unsigned char __stdcall sub_0062BC20(Unit*); // 0x0062BC20
int __fastcall sub_0065E9E0(Unit*,int,int); // 0x0065E9E0
void __stdcall sub_006280D0(Unit*,unsigned,int); // 0x006280D0

enum { SOCKET_FLAG = 0x800 };

struct D2RunesTxt
{
    char unk0x00[0xB0];
    D2PropertyStrc pProperties[7];
};

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062BED0
void __stdcall D2COMMON_11292_ItemAssignProperty(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a10); // 0x0065FD70
D2ItemsTxt* __fastcall sub_0065E9B0(D2UnitStrc* pUnit, D2UnitStrc* pItem);
static __declspec(noinline) int __stdcall sub_0065CF40_AddRolledStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int a7, int nState, int fStatList);
static __declspec(noinline) void __stdcall sub_0065CCC0_SetItemBaseStats(D2UnitStrc* pItem, int nStatId);
static __declspec(noinline) void sub_0065CE40_ShiftStatValue(int nStatId, int* pValue);
static __forceinline int ITEMMODS_RollPropertyValueA(D2UnitStrc* pItem, int nMin, int nMax);
static __forceinline int ITEMMODS_RollPropertyValueB(D2UnitStrc* pItem, int nMin, int nMax);
static int __stdcall sub_0065D1F0_AddValueStat0(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList);
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
int __fastcall ITEMMODS_PropertyFunc06(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11); // 0x0065EE80

struct D2ItemStatCostTxt
{
    char unk0x000[0x144];
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
int __stdcall SKILLS_GetRequiredLevel(int nSkillId); // 0x00644710
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
static __declspec(noinline) D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter);
static int __stdcall sub_0065D2E0_AddValueStat1(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList);
extern "C" void _ReadWriteBarrier(void);

// 0x0065C5D0
int __cdecl sub_0065C5D0()
{
    return sgptDataTables->nPropertiesTxtRecordCount;
}

// 0x0065C7A0
void __stdcall D2Common_10844_ITEMMODS_First(int nDataBits, int* pLayer, int* pValue)
{
    *pLayer = nDataBits & 511;
    *pValue = (nDataBits >> 9) & 31;
}

// 0x0065C7D0
void __stdcall D2Common_10846(int nDataBits, int* a2, int* a3, int* a4, int* a5)
{
    *a2 = nDataBits & 511;
    *a3 = (nDataBits >> 9) & 31;
    *a4 = (nDataBits >> 14) & 255;
    *a5 = (nDataBits >> 22) & 255;
}

// 0x0065CA30
int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax)
{
    int nTempItemModPeriodOfDay = nAmount & 3;
    int nTempItemModMin = ((nAmount >> 2) & 0x3FF) - 0x100;
    int nTempItemModMax = ((nAmount >> 12) & 0x3FF) - 0x100;

    if (pItemModPeriodOfDay)
    {
        *pItemModPeriodOfDay = nTempItemModPeriodOfDay;
    }

    if (pItemModMin)
    {
        *pItemModMin = nTempItemModMin;
    }

    if (pItemModMax)
    {
        *pItemModMax = nTempItemModMax;
    }

    int nTimeDiff = nBaseTime - (nTempItemModPeriodOfDay * 90);
    if (nTimeDiff < 0)
    {
        nTimeDiff = -nTimeDiff;
    }

    int nRoundedTimeDiff = ((nTimeDiff + 7) / 15) * 15;

    int nClampedTimeDiff = nRoundedTimeDiff > 0 ? nRoundedTimeDiff : 0;
    if (nClampedTimeDiff >= (360 - 1))
    {
        nClampedTimeDiff = (360 - 1);
    }

    if (nClampedTimeDiff > 180)
    {
        nClampedTimeDiff = 360 - nClampedTimeDiff;
    }

    return nTempItemModMax - (((nTempItemModMax - nTempItemModMin) * nClampedTimeDiff) / 180);
}

// 0x0065CB00
int __stdcall D2Common_10849(int a1, int a2)
{
    return a1 + (a2 << 9);
}

// 0x0065CB10
void __stdcall D2Common_10845(int nDataBits, int* a2, int* a3, int* a4)
{
    *a2 = nDataBits & 511;
    *a3 = (nDataBits >> 9) & 31;
    *a4 = (nDataBits >> 14) & 127;
}

// 0x0065CB40
int __stdcall D2Common_10850(int a1, int a2, int a3)
{
    return a1 + ((a2 + 32 * a3) << 9);
}

// 0x0065CB60
void __stdcall D2Common_10848(int nDataBits, int* pClass, int* pTab, int* pLevel)
{
    IM_ASSERT(pClass && pTab && pLevel, 426);

    int nClassTab = nDataBits & 31;
    *pClass = nClassTab / 3;
    *pTab = nClassTab % 3;
    *pLevel = (nDataBits >> 5) & 31;
}

// 0x0065CBD0
int __stdcall D2Common_10851(int a1, int a2, int a3)
{
    return a2 + 3 * a1 + 32 * a3;
}

// 0x0065CBF0
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

static __forceinline int IsStatInRange(int nStatId, int nMin, int nMax)
{
    if (nStatId < nMin)
        return 0;
    if (nStatId > nMax)
        return 0;
    return 1;
}

// 0x0065CCA0
static int sub_0065CCA0_IsPercentStat(int nStatId)
{
    if (IsStatInRange(nStatId, 16, 18))
        return 1;
    return 0;
}

// 0x0065CE40
static void sub_0065CE40_ShiftStatValue(int nStatId, int* pValue)
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

// 0x0065CF40
static __declspec(noinline) int __stdcall sub_0065CF40_AddRolledStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int a7, int nState, int fStatList)
{
    int nValue;
    if (a7)
    {
        nValue = ITEMMODS_RollPropertyValueA(pItem, pProperty->nMin, pProperty->nMax);
    }
    else
    {
        nValue = ITEMMODS_RollPropertyValueA(pItem, pProperty->nMin, pProperty->nMax);
        if (nType != 1)
        {
            goto skip_base;
        }
    }
    sub_0065CCC0_SetItemBaseStats(pItem, nStatId);
skip_base:

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

// 0x0065D110
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

int __fastcall IsPercentStatContext(const int* pStatId)
{
    return sub_0065CCA0_IsPercentStat(*pStatId);
}

// 0x0065D270
int __fastcall sub_0065D270(int type,Unit* unit,Unit* item,const Property* property,int stat,int applyType,int state,int statList,Unit* other)
{
    Unit* selected=other;
    if(!selected || selected->type!=4) selected=item;
    sub_00627260(selected,MAX_DURABILITY,0,0);
    sub_00627260(selected,DURABILITY,0,0);
    return 1;
}

// 0x0065D950
int __fastcall sub_0065D950_AddDamagePercent(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2_ASSERT(pProperty, 949);
        const int nValue = ITEMMODS_RollPropertyValueA(pItem, pProperty->nMin, pProperty->nMax);
        D2ItemsTxt* pItemsTxtRecord = sub_0065E9B0(pUnit, pItem);
        D2_ASSERT(pItemsTxtRecord, 960);
        unsigned char nMaxDam8 = pItemsTxtRecord->n2HandMaxDam;
        if (nMaxDam8 <= pItemsTxtRecord->nMaxDam)
        {
            nMaxDam8 = pItemsTxtRecord->nMaxDam;
        }
        const int nMaxDam = nMaxDam8;
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

// 0x0065DD80
int __fastcall sub_0065DD80_AddByTimeStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(pProperty->nMin <= pProperty->nMax, 0x444);
    int nPeriod = pProperty->nLayer;
    int nMin = pProperty->nMin + 256;
    int nMax = pProperty->nMax + 256;
    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(pStatList, 0x44A);
    D2_ASSERT(nPeriod >= 0 && nPeriod <= 3, 0x44C);
    D2_ASSERT(nMin >= 0 && nMin < (1 << 10), 0x44D);
    D2_ASSERT(nMax >= 0 && nMax < (1 << 10), 0x44E);
    STATLIST_SetStat(pStatList, nStatId, nPeriod + 4 * (nMin + (nMax << 10)), 0);
    return 1;
}

static int __stdcall sub_0065D1F0_AddValueStat0(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList)
{
    return sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, nStatId, nApplyType, 0, nState, fStatList);
}

static int __stdcall sub_0065D2E0_AddValueStat1(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList)
{
    return sub_0065D070_AddValueStat(nType, pUnit, pItem, nValue, nStatId, nApplyType, 1, nState, fStatList);
}

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

int __fastcall sub_0065D650_AddMinDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(pProperty, 891);
    const int nMin = ITEMMODS_RollPropertyValueB(pItem, pProperty->nMin, pProperty->nMax);
    D2ItemsTxt* pItemsTxtRecord = sub_0065E9B0(pUnit, pItem);
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

int __fastcall sub_0065D7D0_AddMaxDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(pProperty, 919);
    const int nMin = ITEMMODS_RollPropertyValueB(pItem, pProperty->nMin, pProperty->nMax);
    D2ItemsTxt* pItemsTxtRecord = sub_0065E9B0(pUnit, pItem);
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

// 0x0065DE40
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

// 0x0065E070
int __fastcall sub_6FD94AB0(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{

    const int nMinValue = (nStatId == (int)pProperty) ? pProperty->nMin : pProperty->nMin;
    int nMin = nMinValue;
    const int nMaxValue = pProperty->nMax;
    int nLayer = pProperty->nLayer;
    int nMax = nStatId ? nMaxValue : nMaxValue;
    _ReadWriteBarrier();
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

// 0x0065E170
int __fastcall sub_0065E170_AddSingleSkillStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nPropertyId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (!pProperty)
    {
        return 0;
    }

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

    const int nSkillId = pProperty->nLayer;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
    {
        return 0;
    }

    if (nApplyType)
    {
        nValue = -sub_006254E0_GetStatValue(pStatList, 107, nSkillId);
    }

    STATLIST_AddStat(pStatList, 107, nValue, nSkillId);
    return 1;
}

// 0x0065E230
int __fastcall sub_0065E230_AddElemSkillStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
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

    if (nApplyType)
    {
        nValue = -sub_006254E0_GetStatValue(pStatList, 126, 1);
    }

    STATLIST_AddStat(pStatList, 126, nValue, 1);
    return 1;
}

// 0x0065E440
int __fastcall sub_0065E440_StatFuncTrue(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    return 1;
}

// 0x0065E600
static __forceinline int sub_0065E600_GetSetItemsCount(unsigned int nMask)
{
    if (nMask >= 0x40)
        return 0;
    return gnSetItemsCount_006EDA40[nMask];
}

int __fastcall sub_M115_Emit_0065E600(unsigned int nMask)
{
    return sub_0065E600_GetSetItemsCount(nMask);
}

// 0x0065E610
void __stdcall sub_0065E610_Empty(int a1, int a2, int a3)
{
}

#include "gen/data/Source/D2Common/ITEMS/ItemMods.inc"

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

// 0x0065F390
int __fastcall ITEMMODS_PropertyFunc24(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (!nValue)
    {
        nValue = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    const int nPropertyLayer = pProperty->nLayer;
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nPropertyLayer, nValue, nState);
}

// 0x0065F590
int __fastcall sub_0065F590(int type,Unit* unit,Unit* item,const Property* property,int set,short stat,int layer,int value,int state,int statList,Unit* other)
{
    if(!property) return 0;
    if(!item || item->type!=4) return 0;
    int limit=6;
    unsigned char width=0,height=0;
    sub_006286C0(item,&width,&height,"d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h",0x6DC);
    int area=width*height;
    limit=MINIMUM(limit,area);
    if(limit<=0) return 0;
    limit=MINIMUM(limit,sub_0062BC20(item));
    int count=value;
    if(count<=0) {
        count=sub_0065E9E0(item,property->minimum,property->maximum);
        if(count<=0) count=property->layer;
    }
    count=MINIMUM(MAXIMUM(count,1),limit);
    if(count<=0) return 0;
    sub_006280D0(item,SOCKET_FLAG,1);
    sub_00627260(item,194,count,0);
    return count;
}

// 0x0065F6A0
int __fastcall sub_0065F6A0_PropertyFunc17_ChargedSkill(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (!pItem)
    {
        return 0;
    }
    if (pItem->dwUnitType != 4)
    {
        return 0;
    }

    const int nSkillId = pProperty->nLayer;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount || !sub_0045C4B0_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    int nSkillLevel = pProperty->nMax;
    if (nSkillLevel == 0)
    {
        nSkillLevel = (ITEMS_GetItemLevel(pItem) - (SKILLS_GetRequiredLevel(nSkillId))) / 4 + 1;
        nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, 1), sub_004AA8B0_GetSkillMaxLevel(nSkillId));
    }
    else if (nSkillLevel < 0)
    {
        const int nRequiredLevel = SKILLS_GetRequiredLevel(nSkillId);
        int nDivisor = 99 - nRequiredLevel;
        if (nDivisor < 1)
        {
            nDivisor = 1;
        }

        nDivisor = -(nDivisor / nSkillLevel);
        if (nDivisor < 1)
        {
            nDivisor = 1;
        }

        nSkillLevel = (ITEMS_GetItemLevel(pItem) - nRequiredLevel) / nDivisor;
        if (nSkillLevel <= 0)
        {
            nSkillLevel = 1;
        }
    }

    int nCharges = pProperty->nMin;
    if (nCharges == 0)
    {
        nCharges = 5;
    }
    else if (nCharges < 0)
    {
        nCharges = -nCharges;
        nCharges += nCharges * nSkillLevel / 8;
    }

    nCharges = D2_MIN(D2_MAX(nCharges, 1), 255);

    const int nCurrentCharges = SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nCharges - nCharges / 8) + nCharges / 8 + 1;
    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    STATLIST_SetStatIfListIsValid(pStatList, nStatId, (nCurrentCharges & 0xFF) + (nCharges << 8), (unsigned short)((nSkillId << sgptDataTables->nStuff) + (sgptDataTables->dwStuffMask & nSkillLevel)));
    return nCharges;
}

static inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }

    return 0;
}

// 0x0065F870
int __fastcall ITEMMODS_PropertyFunc18(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (!ITEMS_GetItemStatCostTxtRecord(nStatId))
    {
        return 0;
    }

    int nPropLayer = pProperty->nLayer;
    int nMin = pProperty->nMin + 256;
    int nMax = pProperty->nMax + 256;
    nPropLayer = D2_MIN(D2_MAX(nPropLayer, 0), 3);
    nMin = D2_MIN(D2_MAX(nMin, 0), 1023);
    nMax = D2_MIN(D2_MAX(nMax, 0), 1023);

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
    {
        return 0;
    }

    STATLIST_SetStatIfListIsValid(pStatList, nStatId, nPropLayer + 4 * (nMin + (nMax << 10)), 0);
    return nMax;
}

// 0x006600A0
int __stdcall ITEMMODS_UpdateRuneword(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nUnused)
{
    const D2RunesTxt* pRunesTxtRecord = ITEMS_GetRunesTxtRecordFromItem(pUnit);
    if (!pRunesTxtRecord)
    {
        return 0;
    }

    if (sub_00625790_UnitFindStatList(pUnit, 171, 0x40))
    {
        return 0;
    }

    ITEMS_SetItemFlag(pUnit, 0x4000000, 1);

    for (int i = 0; i < 7; ++i)
    {
        const D2PropertyStrc* pProperty = &pRunesTxtRecord->pProperties[i];
        if (pProperty->nProperty < 0)
        {
            break;
        }

        D2COMMON_11292_ItemAssignProperty(6, pUnit, pItem, 0, i, 0, pProperty, 171, 0x40, 0);
    }

    return 1;
}
