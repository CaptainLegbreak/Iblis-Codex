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
};

// 0x00625650
D2StatListStrc* __stdcall D2Common_GetStateFromStatListEx_6FDB8190(D2StatListStrc* pStatListEx, int nStateId)
{
    if (!pStatListEx)
    {
        return 0;
    }

    if (!nStateId)
    {
        return 0;
    }

    D2StatListStrc* pStatList = (pStatListEx->dwFlags & 0x80000000) ? pStatListEx->pMyLastList : 0;
    while (pStatList && pStatList->dwStateNo != nStateId)
    {
        pStatList = pStatList->pPrevLink;
    }

    if (pStatList)
    {
        return pStatList;
    }

    pStatList = (pStatListEx->dwFlags & 0x80000000) ? pStatListEx->pMyStats : 0;
    while (pStatList)
    {
        if (pStatList->dwStateNo == nStateId)
        {
            return pStatList;
        }
        pStatList = pStatList->pPrevLink;
    }

    return 0;
}
