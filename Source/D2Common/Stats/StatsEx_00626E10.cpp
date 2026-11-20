#include "D2Common.h"
#include "D2Structs.h"





struct D2ItemStatCostTxt
{
    char unk0x00[0x04];
    unsigned char nItemStatFlags[4];
    char unk0x08[0x4B];
    unsigned char bUpdateAnimRate;
    char unk0x54[0x144 - 0x54];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0x04];
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId);                           // 0x0045C4F0
int __fastcall sub_006266C0_UpdateStatOps(D2StatListExStrc* pStatListEx, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit); // 0x006266C0
void __fastcall sub_00626920_UpdateStatValue(D2StatListExStrc* pStatListEx, int nLayer_StatId, int nValue, D2UnitStrc* pUnit); // 0x00626920
void __stdcall D2Common_ExpireStatList_6FDB6E30(D2StatListExStrc* pStatList);                               // 0x006269F0
static D2StatsArrayStrc* sub_00624F40_GetStatsArray(D2StatListExStrc* pStatList);                           // 0x00624F40

static __forceinline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

static __forceinline int STATLIST_IsExtended(D2StatListExStrc* pStatList)
{
    return pStatList->dwFlags & 0x80000000;
}

static __declspec(noinline) D2StatsArrayStrc* sub_00624F40_GetStatsArray(D2StatListExStrc* pStatList)
{
    if (pStatList->dwFlags & 0x80000000)
        return &pStatList->FullStats;
    return &pStatList->Stats;
}

// 0x00626E10
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListExStrc* pStatList, int bResetFlag)
{
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & 0x80000000))
        return;

    D2Common_ExpireStatList_6FDB6E30(pStatList);

    for (D2StatListStrc* pParent = pStatListEx; pParent; pParent = pParent->pParent)
    {
        if (pStatList == pParent)
            return;
    }

    if (pStatList->dwFlags & 4)
        pStatListEx->dwFlags |= 2;

    if (pStatList->dwFlags & 0x2000)
    {
        pStatList->pPrevLink = pStatListEx->pMyStats;
        if (pStatListEx->pMyStats)
            pStatListEx->pMyStats->pNextLink = pStatList;
        pStatList->pNextLink = 0;
        pStatListEx->pMyStats = pStatList;
        pStatList->pParent = pStatListEx;
        pStatList->pUnit = pUnit;
        return;
    }

    D2StatListStrc* pLastList = pStatListEx->pMyLastList;
    pStatList->pPrevLink = pLastList;
    if (pLastList)
        pLastList->pNextLink = pStatList;
    pStatList->pParent = pStatListEx;
    pStatListEx->pMyLastList = pStatList;
    pStatList->pUnit = pUnit;

    D2UnitStrc* pOwner = 0;
    if (STATLIST_IsExtended(pStatList))
        pOwner = pStatList->pOwner;

    if (STATLIST_IsExtended(pStatList) && (pStatList->dwFlags & 0x20000000))
    {
        int aStats[16];
        D2StatsArrayStrc* pStatsArray = sub_00624F40_GetStatsArray(pStatList);
        D2StatStrc* pStat = pStatsArray->pStat;
        D2StatStrc* pEnd = &pStat[pStatsArray->nStatCount];
        int nCount = 0;
        for (; pStat < pEnd; ++pStat)
        {
            const int nPacked = pStat->nPackedValue;
            D2ItemStatCostTxt* pRecord = ITEMS_GetItemStatCostTxtRecord((nPacked >> 16) & 0xFFFF);
            if (pRecord && pRecord->bUpdateAnimRate)
                aStats[nCount++] = nPacked;
        }

        for (int i = 0; i < nCount; ++i)
        {
            const int nPacked = aStats[i];
            D2ItemStatCostTxt* pRecord = sub_0045C4F0_GetItemStatCostTxtRecord((nPacked >> 16) & 0xFFFF);
            if (pRecord)
                sub_006266C0_UpdateStatOps(pStatList, nPacked, pRecord, 0);
        }
    }

    const unsigned int dwListFlags = pStatList->dwFlags;
    D2StatsArrayStrc* pStatsArray = (dwListFlags & 0x80000000) ? &pStatList->FullStats : &pStatList->Stats;
    D2StatStrc* pStat = pStatsArray->pStat;
    D2StatStrc* pEnd = &pStat[pStatsArray->nStatCount];
    if (bResetFlag)
    {
        pStatList->dwFlags = dwListFlags & ~0x40000000;
        for (; pStat < pEnd; ++pStat)
            sub_00626920_UpdateStatValue(pStatListEx, pStat->nPackedValue, pStat->nValue, pOwner);
    }
    else
    {
        pStatList->dwFlags = dwListFlags | 0x40000000;
        for (; pStat < pEnd; ++pStat)
        {
            const int nPacked = pStat->nPackedValue;
            D2ItemStatCostTxt* pRecord = ITEMS_GetItemStatCostTxtRecord((nPacked >> 16) & 0xFFFF);
            if (pRecord && !(pRecord->nItemStatFlags[2 >> 3] & gdwBitMasks_006CE268[2 & 7]))
                sub_00626920_UpdateStatValue(pStatListEx, nPacked, pStat->nValue, pOwner);
        }
    }
}
