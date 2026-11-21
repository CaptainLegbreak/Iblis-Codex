#include "D2Common.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2DataTbls.h"

struct D2StatStrc;
struct D2StatsArrayStrc;
struct D2StatListExStrc;
struct D2ItemStatCostTxt;





void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId); // 0x0045C4F0
void __fastcall sub_00626920_UpdateStatValue(D2StatListStrc* pStatList, int nLayer_StatId, int nValue, D2UnitStrc* pUnit); // 0x00626920



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_SetBaseStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer, D2UnitStrc* pUnit); // 0x00627170
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x006270B0

// 0x00624F40
static __declspec(noinline) D2StatsArrayStrc* sub_00624F40_GetStatsArray(D2StatListExStrc* pStatList)
{
    if (pStatList->dwFlags & 0x80000000)
        return &pStatList->FullStats;
    return &pStatList->Stats;
}

// 0x00627860
int __stdcall D2Common_11274(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    if (!pTarget || !pUnit)
        return 0;

    D2StatListExStrc* pStatList = pUnit->pStatListEx;
    if (!pStatList)
        return 0;

    if (pStatList->pUnit != pTarget)
    {
        STATLIST_MergeStatLists(pTarget, pUnit, 1);
        return 0;
    }

    D2StatListExStrc* pTargetStatListEx = pTarget->pStatListEx;
    if (!pTargetStatListEx || !(pTargetStatListEx->dwFlags & 0x80000000))
        return 0;

    const unsigned int dwFlags = pStatList->dwFlags;
    if (!(dwFlags & 0x40000000))
        return 0;
    pStatList->dwFlags = dwFlags & ~0x40000000;

    D2StatsArrayStrc* pStatsArray = sub_00624F40_GetStatsArray(pStatList);
    D2StatStrc* pEnd = &pStatsArray->pStat[pStatsArray->nStatCount];
    for (D2StatStrc* i = pStatsArray->pStat; i < pEnd; ++i)
    {
        const int nPacked = i->nPackedValue;
        D2ItemStatCostTxt* pRecord = sub_0045C4F0_GetItemStatCostTxtRecord((nPacked >> 16) & 0xFFFF);
        if (pRecord && (pRecord->nItemStatFlags[2 >> 3] & gdwBitMasks_006CE268[2 & 7]))
            sub_00626920_UpdateStatValue(pTargetStatListEx, nPacked, i->nValue, pUnit);
    }
    return 1;
}

// 0x00627A40
int __stdcall D2Common_11275(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    if (!pTarget || !pUnit)
        return 0;

    D2StatListExStrc* pStatList = pUnit->pStatListEx;
    if (!pStatList)
        return 0;

    if (pStatList->pUnit != pTarget)
    {
        STATLIST_MergeStatLists(pTarget, pUnit, 0);
        return 0;
    }

    D2StatListExStrc* pTargetStatListEx = pTarget->pStatListEx;
    if (!pTargetStatListEx || !(pTargetStatListEx->dwFlags & 0x80000000))
        return 0;

    const unsigned int dwFlags = pStatList->dwFlags;
    if (dwFlags & 0x40000000)
        return 0;
    pStatList->dwFlags = dwFlags | 0x40000000;

    D2StatsArrayStrc* pStatsArray = sub_00624F40_GetStatsArray(pStatList);
    D2StatStrc* pEnd = &pStatsArray->pStat[pStatsArray->nStatCount];
    for (D2StatStrc* i = pStatsArray->pStat; i < pEnd; ++i)
    {
        const int nPacked = i->nPackedValue;
        D2ItemStatCostTxt* pRecord = sub_0045C4F0_GetItemStatCostTxtRecord((nPacked >> 16) & 0xFFFF);
        if (pRecord && (pRecord->nItemStatFlags[2 >> 3] & gdwBitMasks_006CE268[2 & 7]))
            sub_00626920_UpdateStatValue(pTargetStatListEx, nPacked, -i->nValue, pUnit);
    }
    return 1;
}

// 0x00625270
int __stdcall STATLIST_GetBaseStatsCount(D2StatListStrc* pStatList)
{
    return !pStatList ? 0 : pStatList->Stats.nStatCount;
}

// 0x00625290
int __stdcall STATLIST_GetFullStatsCountFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!pUnit->pStatListEx)
    {
        return 0;
    }

    return pUnit->pStatListEx->FullStats.nStatCount;
}

// 0x00625620
int __stdcall sub_00625620(D2StatListStrc* pStatList, int nIndex)
{
    if (!pStatList)
    {
        return 0;
    }

    if (nIndex >= pStatList->Stats.nStatCount)
    {
        return 0;
    }

    return pStatList->Stats.pStat[nIndex].nValue;
}

// 0x00626070
int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId)
{
    return STATLIST_UnitGetStatValue(pUnit, nStatId, 0);
}

// 0x00627220
void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pUnit)
{
    if (pStatList)
    {
        STATLIST_SetBaseStat(pStatList, nStatId, nValue, nLayer, pUnit);
    }
}

// 0x00627810
int __stdcall D2Common_10531_SetStatInStatListLayer0(D2StatListStrc* pStatList, int nStatId, int nValue, int nUnused)
{
    return sub_006270B0(pStatList, nStatId, nValue, 0);
}

// 0x00627B30
int __cdecl sub_00627B30()
{
    return sgptDataTables->nItemTypesTxtRecordCount;
}

// 0x00627B40
int __cdecl sub_00627B40()
{
    return 0;
}

// 0x00627B50
int __fastcall sub_00627B50_Min(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x00627B60
int __fastcall sub_00627B60_Max(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}
