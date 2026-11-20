#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define STAT_ITEM_INDESTRUCTIBLE 152
union D2SeedStrc;
struct D2SkillsTxt;
struct D2PropertyStrc;
struct D2ItemStatCostTxt;





extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall sub_00627150(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
int __stdcall SKILLS_GetRequiredLevel(int nSkillId); // 0x00644710


void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030

// build: context SKILLS_GetSkillsTxtRecord
static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (!(nSkillId >= 0))
        return 0;
    if (!(nSkillId < sgptDataTables->nSkillsTxtRecordCount))
        return 0;
    return &sgptDataTables->pSkillsTxt[nSkillId];
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

// 0x0065DBC0
int __fastcall sub_0065DBC0_PropertyFunc_SkillCharges(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nSkillId = pProperty->nLayer;
    if (SKILLS_GetSkillsTxtRecord(nSkillId))
    {

    int nSkillLevel = pProperty->nMax;
    if (!nSkillLevel)
    {
        nSkillLevel = (ITEMS_GetItemLevel(pItem) - SKILLS_GetRequiredLevel(nSkillId)) / 4 + 1;
        nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, 1), sub_004AA8B0_GetSkillMaxLevel(nSkillId));
    }
    else if (nSkillLevel < 0)
    {
        const int nRequiredLevel = SKILLS_GetRequiredLevel(nSkillId);
        int nRange = 99 - nRequiredLevel;
        if (nRange < 1)
        {
            nRange = 1;
        }

        int nDivisor = -(nRange / nSkillLevel);
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
    if (!nCharges)
    {
        nCharges = 5;
    }
    else if (nCharges < 0)
    {
        nCharges = -nCharges;
        nCharges += nCharges * nSkillLevel / 8;
    }

    nCharges = D2_MIN(D2_MAX(nCharges, 1), 255);

    const int nCurrent = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nCharges - (nCharges / 8)) + (nCharges / 8) + 1;
    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    sub_00627150(pStatList, nStatId, (nCurrent & 0xFF) + (nCharges << 8), (nSkillId << sgptDataTables->nStuff) + (nSkillLevel & sgptDataTables->nShiftedStuff));
    return 1;
    }

    return 0;
}

// build: context ITEMS_GetItemStatCostTxtRecord
static inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    D2ItemStatCostTxt* pRecord = 0;
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        pRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
    }

    return pRecord;
}

// 0x0065FAE0
int __fastcall ITEMMODS_PropertyFunc20(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if ((pItem ? pItem->dwUnitType : 6) != UNIT_ITEM)
        return 0;
    if (!pProperty)
        return 0;
    if (!ITEMS_GetItemStatCostTxtRecord(STAT_ITEM_INDESTRUCTIBLE))
        return 0;
    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
        return 0;
    STATLIST_AddStat(pStatList, STAT_ITEM_INDESTRUCTIBLE, 1, 0);
    return 1;
}
