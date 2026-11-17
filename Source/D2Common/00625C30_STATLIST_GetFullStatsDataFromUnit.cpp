struct D2UnitStrc;

struct D2StatStrc
{
    unsigned short nLayer;
    unsigned short nStat;
    int nValue;
};

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
    D2StatStrc* pStat;
    short nStatCount;
    short nCapacity;
    D2StatListStrc* pPrevLink;
    D2StatListStrc* pNextLink;
    D2StatListStrc* pParent;
    void* fpStatRemove;
    D2StatListStrc* pMyLastList;
    D2StatListStrc* pMyStats;
    D2UnitStrc* pOwner;
    D2StatStrc* pFullStat;
    short nFullStatCount;
    short nFullStatCapacity;
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    char unk0x04[0x58];
    D2StatListStrc* pStatListEx;
};

// 0x00625C30
int __stdcall STATLIST_GetFullStatsDataFromUnit(D2UnitStrc* pUnit, D2StatStrc* pOutStatBuffer, int nBufferSize)
{
    if (!pUnit)
    {
        return 0;
    }
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }
    if (!(pStatListEx->dwFlags & 0x80000000))
    {
        return 0;
    }
    int nStatCount = pStatListEx->nFullStatCount;
    if (nStatCount >= nBufferSize)
    {
        nStatCount = nBufferSize;
    }
    D2StatStrc* pStat = pStatListEx->pFullStat;
    D2StatStrc* pEnd = &pStat[nStatCount];
    for (; pStat < pEnd; ++pStat)
    {
        *pOutStatBuffer = *pStat;
        ++pOutStatBuffer;
    }
    return nStatCount;
}
