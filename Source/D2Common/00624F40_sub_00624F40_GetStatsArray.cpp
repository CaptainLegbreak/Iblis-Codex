struct D2UnitStrc;

struct D2StatStrc
{
    int nPackedValue;
    int nValue;
};

struct D2StatsArrayStrc
{
    D2StatStrc* pStat;
    short nStatCount;
    short nCapacity;
};

struct D2StatListExStrc
{
    void* pMemPool;
    D2UnitStrc* pUnit;
    char unk0x08[0x08];
    unsigned int dwFlags;
    char unk0x14[0x10];
    D2StatsArrayStrc Stats;
    char unk0x2C[0x1C];
    D2StatsArrayStrc FullStats;
};

struct D2UnitStrc
{
    char unk0x00[0x5C];
    D2StatListExStrc* pStatListEx;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x04];
    unsigned char nItemStatFlags[4];
};

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId);                           // 0x0045C4F0
void __fastcall sub_00626920_UpdateStatValue(D2StatListExStrc* pStatListEx, int nLayer_StatId, int nValue, D2UnitStrc* pUnit); // 0x00626920

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
