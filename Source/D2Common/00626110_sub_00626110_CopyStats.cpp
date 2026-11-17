struct D2UnitStrc;
struct D2GameStrc;
struct D2DrlgActStrc;
struct D2StatListStrc;

struct D2StatStrc
{
    union
    {
        struct
        {
            unsigned short nLayer;
            unsigned short nStat;
        };
        int nPackedValue;
    };
    int nValue;
};

struct D2StatsArrayStrc
{
    D2StatStrc* pStat;
    short nStatCount;
    short nCapacity;
};

struct D2ModStatsArrayStrc
{
    int* pStat;
    short nStatCount;
    short nCapacity;
};

typedef void (__fastcall* StatListValueChangeFunc)(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nLayer_StatId, int nPreviousValue, int nNewValue);
typedef void (__fastcall* StatListUnitCallback)(D2UnitStrc* pUnit1, int nStatId, int nValue, D2UnitStrc* pUnit2);

struct D2StatListStrc
{
    void* pMemPool;
    D2UnitStrc* pUnit;
    int dwOwnerType;
    int dwOwnerId;
    unsigned int dwFlags;
    char unk0x14[0x10];
    D2StatsArrayStrc Stats;
    D2StatListStrc* pPrevLink;
    D2StatListStrc* pNextLink;
    D2StatListStrc* pParent;
    void* fpStatRemove;
    D2StatListStrc* pMyLastList;
    D2StatListStrc* pMyStats;
    D2UnitStrc* pOwner;
    D2StatsArrayStrc FullStats;
    D2ModStatsArrayStrc ModStats;
    unsigned int* StatFlags;
    StatListValueChangeFunc pfOnValueChanged;
    D2GameStrc* pGame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x14];
    D2DrlgActStrc* pDrlgAct;
    char unk0x20[0x3C];
    D2StatListStrc* pStatListEx;
};

#define STATLIST_EXTENDED 0x80000000
#define STAT_SHIFT 16
#define STAT_GETID(nLayer_StatId) (((nLayer_StatId) >> STAT_SHIFT) & 0xFFFF)

static int __stdcall sub_00624C10_FindFirstStatIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    D2StatStrc* pStat = pStatsArray->pStat;
    int nMin = 0;
    int nMax = pStatsArray->nStatCount;
    while (nMin < nMax)
    {
        const int nMid = nMin + (nMax - nMin) / 2;
        const int nPackedValue = pStat[nMid].nPackedValue;
        if (nLayer_StatId > nPackedValue)
        {
            nMin = nMid + 1;
        }
        else if (nLayer_StatId < nPackedValue)
        {
            nMax = nMid;
        }
        else
        {
            return nMid;
        }
    }
    if (nMin >= pStatsArray->nStatCount)
    {
        return -1;
    }
    return nMin;
}

// 0x00626110
static int __stdcall sub_00626110_CopyStats(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize)
{
    if (!pStatList)
    {
        return 0;
    }

    D2StatsArrayStrc* pStatsArray = (pStatList->dwFlags & STATLIST_EXTENDED) ? &pStatList->FullStats : &pStatList->Stats;
    int nIndex = sub_00624C10_FindFirstStatIndex(pStatsArray, nStatId << STAT_SHIFT);
    if (nIndex < 0)
    {
        return 0;
    }

    int nCopied = 0;
    D2StatStrc* pStat = &pStatsArray->pStat[nIndex];
    while (nIndex < pStatsArray->nStatCount)
    {
        const int nPackedValue = pStat->nPackedValue;
        if (STAT_GETID(nPackedValue) != nStatId)
        {
            return nCopied;
        }
        if (nCopied >= nBufferSize)
        {
            return nCopied;
        }
        pBuffer->nPackedValue = nPackedValue;
        pBuffer->nValue = pStat->nValue;
        ++nCopied;
        ++nIndex;
        ++pStat;
        ++pBuffer;
    }
    return nCopied;
}

int __stdcall D2COMMON_11269_CopyStats(D2StatListStrc* pStatListEx, int nStatId, D2StatStrc* pBuffer, int nBufferSize)
{
    return sub_00626110_CopyStats(pStatListEx, nStatId, pBuffer, nBufferSize);
}

int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize)
{
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }
    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return 0;
    }
    return sub_00626110_CopyStats(pStatListEx, nStatId, pBuffer, nBufferSize);
}
