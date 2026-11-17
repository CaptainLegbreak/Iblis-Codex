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

struct D2ItemStatCostTxt
{
    char _pad_0x0[0x4];
    unsigned char nItemStatFlags[4];
    char _pad_0x8[0x4B];
    unsigned char bHasOpApplyingToItem;
    char _pad_0x54[0xF0];
};

struct D2DataTablesStrc
{
    char _pad_0x0[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    void* pItemStatCostLinker;
    int nItemStatCostTxtRecordCount;
};

struct D2StatListStrc;
typedef void(__fastcall* StatListRemoveFunc)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2StatListStrc
{
    void* pMemPool;
    D2UnitStrc* pUnit;
    int dwOwnerType;
    int dwOwnerId;
    unsigned int dwFlags;
    int dwStateNo;
    int dwExpireFrame;
    int dwSkillNo;
    int dwSLvl;
    D2StatsArrayStrc Stats;
    D2StatListStrc* pPrevLink;
    D2StatListStrc* pNextLink;
    D2StatListStrc* pParent;
    StatListRemoveFunc fpStatRemove;
    D2StatListStrc* pMyLastList;
    D2StatListStrc* pMyStats;
    D2UnitStrc* pOwner;
    D2StatsArrayStrc FullStats;
};

int __fastcall sub_006266C0_UpdateStatOps(D2StatListStrc* pStatListEx, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit); // 0x006266C0
void __fastcall sub_00626920_UpdateStatValue(D2StatListStrc* pStatListEx, int nLayer_StatId, int nValue, D2UnitStrc* pUnit); // 0x00626920
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268

static __forceinline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x006269F0
void __stdcall D2Common_ExpireStatList_6FDB6E30(D2StatListStrc* pStatList)
{
    int anStats[16];

    if (!pStatList)
    {
        return;
    }

    D2StatListStrc* pParent = pStatList->pParent;
    if (pParent)
    {
        if (pParent->dwFlags & 0x80000000)
        {
            if (pParent->pMyLastList == pStatList)
            {
                pParent->pMyLastList = pStatList->pPrevLink;
            }
            if (pParent->pMyStats == pStatList)
            {
                pParent->pMyStats = pStatList->pPrevLink;
            }
        }
        pStatList->pParent = 0;
    }

    if (pStatList->pNextLink)
    {
        pStatList->pNextLink->pPrevLink = pStatList->pPrevLink;
    }
    if (pStatList->pPrevLink)
    {
        pStatList->pPrevLink->pNextLink = pStatList->pNextLink;
    }

    pStatList->pPrevLink = 0;
    pStatList->pNextLink = 0;
    D2UnitStrc* pUnit = pStatList->pUnit;
    pStatList->pUnit = 0;

    if (pStatList->dwFlags & 0x2000)
    {
        return;
    }

    D2UnitStrc* pOwner = 0;
    if (pStatList->dwFlags & 0x80000000)
    {
        pOwner = pStatList->pOwner;
    }

    if ((pStatList->dwFlags & 0x80000000) && (pStatList->dwFlags & 0x20000000))
    {
        int nCount = 0;
        D2StatStrc* pStat = pStatList->FullStats.pStat;
        D2StatStrc* pStatEnd = &pStat[pStatList->FullStats.nStatCount];
        for (; pStat < pStatEnd; ++pStat)
        {
            D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord((pStat->nPackedValue >> 16) & 0xFFFF);
            if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->bHasOpApplyingToItem)
            {
                anStats[nCount] = pStat->nPackedValue;
                ++nCount;
            }
        }

        for (int i = 0; i < nCount; ++i)
        {
            D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord((anStats[i] >> 16) & 0xFFFF);
            if (pItemStatCostTxtRecord)
            {
                sub_006266C0_UpdateStatOps(pStatList, anStats[i], pItemStatCostTxtRecord, 0);
            }
        }
    }

    if (pParent)
    {
        int bDamage = pStatList->dwFlags & 0x40000000;
        D2StatsArrayStrc* pStatsArray = (pStatList->dwFlags & 0x80000000) ? &pStatList->FullStats : &pStatList->Stats;
        D2StatStrc* pStat = pStatsArray->pStat;
        D2StatStrc* pEnd = &pStat[pStatsArray->nStatCount];

        if (bDamage)
        {
            for (; pStat < pEnd; ++pStat)
            {
                D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord((pStat->nPackedValue >> 16) & 0xFFFF);
                if (pItemStatCostTxtRecord && !(pItemStatCostTxtRecord->nItemStatFlags[0] & gdwBitMasks[2]))
                {
                    sub_00626920_UpdateStatValue(pParent, pStat->nPackedValue, -pStat->nValue, pOwner);
                }
            }
        }
        else
        {
            for (; pStat < pEnd; ++pStat)
            {
                sub_00626920_UpdateStatValue(pParent, pStat->nPackedValue, -pStat->nValue, pOwner);
            }
        }
    }

    if (pUnit && pStatList->fpStatRemove)
    {
        pStatList->fpStatRemove(pUnit, pStatList->dwStateNo, pStatList);
    }
}
