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

struct D2UnitStrc
{
    unsigned int dwUnitType;
    char unk0x04[0x58];
    D2StatListStrc* pStatListEx;
};

int __stdcall STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);    // 0x00625420
int __stdcall sub_00625350(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625350
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
D2StatListStrc* __stdcall D2Common_GetStateFromStatListEx_6FDB8190(D2StatListStrc* pStatListEx, int nStateId); // 0x00625650
D2StatListStrc* __stdcall sub_006256E0_StatListFindByFlags(D2StatListStrc* pStatList, int nFlag);           // 0x006256E0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __fastcall D2Common_STATLIST_FreeStatListImpl_6FDB7050(D2StatListStrc* pStatList);                     // 0x00626C00
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList);                                          // 0x00627340
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer);  // 0x00627030
int __stdcall STATES_CheckStateMaskStayDeathOnUnitByStateId(D2UnitStrc* pUnit, int nState);                 // 0x0063A4A0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
void __stdcall D2Common_ExpireStatList_6FDB6E30(D2StatListStrc* pStatList);                                 // 0x006269F0
int __stdcall D2Common_11274(D2UnitStrc* pTarget, D2UnitStrc* pUnit);                                       // 0x00627860
int __stdcall D2Common_11275(D2UnitStrc* pTarget, D2UnitStrc* pUnit);                                       // 0x00627A40
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

// 0x006255A0
int __stdcall sub_006255A0_GetStatValueWithPercent(D2StatListStrc* pStatList, int nStatId, int nPercentStatId, int bAddBonus)
{
    if (!pStatList)
    {
        return 0;
    }
    const int nPercent = STATLIST_GetTotalStatValue(pStatList, nPercentStatId, 0);
    const int nBase = sub_00625350(pStatList, nStatId, 0);
    int nBonus = 0;
    if (bAddBonus)
    {
        nBonus = STATLIST_GetTotalStatValue(pStatList, nStatId, 0) - nBase;
    }
    return DATATBLS_ApplyRatio(nBase, nPercent, 100) + nBonus + nBase;
}

// 0x006256B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState)
{
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }
    if (!(pStatListEx->dwFlags & 0x80000000))
    {
        return 0;
    }
    return D2Common_GetStateFromStatListEx_6FDB8190(pStatListEx, nState);
}

// 0x00625790
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag)
{
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }
    if (!(pStatListEx->dwFlags & 0x80000000))
    {
        return 0;
    }
    if (nState)
    {
        return D2Common_GetStateFromStatListEx_6FDB8190(pStatListEx, nState);
    }
    return sub_006256E0_StatListFindByFlags(pStatListEx, nFlag);
}

// 0x00625C90
int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc* pStatList, D2StatStrc* pOutStatBuffer, int nBufferSize)
{
    if (!pStatList)
    {
        return 0;
    }
    int nStatCount = pStatList->nStatCount;
    if (nStatCount >= nBufferSize)
    {
        nStatCount = nBufferSize;
    }
    D2StatStrc* pStat = pStatList->pStat;
    D2StatStrc* pEnd = &pStat[nStatCount];
    for (; pStat < pEnd; ++pStat)
    {
        *pOutStatBuffer = *pStat;
        ++pOutStatBuffer;
    }
    return nStatCount;
}

// 0x006272E0
void __stdcall STATLIST_DeactivateTemporaryStates(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & 2))
    {
        return;
    }

    D2StatListStrc* pPrevious;
    for (D2StatListStrc* pCurrent = pStatListEx->pMyLastList; pCurrent; pCurrent = pPrevious)
    {
        pPrevious = pCurrent->pPrevLink;
        if (!(pCurrent->dwFlags & 4))
        {
            continue;
        }
        if (pCurrent->dwStateNo)
        {
            STATES_ToggleState(pUnit, pCurrent->dwStateNo, 0);
        }
        if (!(pCurrent->dwFlags & 0x80000000))
        {
            D2Common_STATLIST_FreeStatListImpl_6FDB7050(pCurrent);
        }
        pPrevious = pStatListEx->pMyLastList;
    }
    pStatListEx->dwFlags &= ~2;
}

// 0x00627410
void __stdcall STATLIST_RemoveAllStatsFromOverlay(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        D2StatListStrc* pStatListEx = pUnit->pStatListEx;
        if (pStatListEx)
        {
            pStatListEx->dwFlags &= ~0x100;
            if (pUnit->pStatListEx && (pUnit->pStatListEx->dwFlags & 0x80000000))
            {
                if (D2StatListStrc* pStatList = sub_006256E0_StatListFindByFlags(pUnit->pStatListEx, 0x80))
                {
                    STATLIST_RemoveAllStats(pStatList);
                }
            }
        }
    }
}

// 0x00627460
void __stdcall STATLIST_UpdateStatListsExpiration(D2UnitStrc* pUnit, int nFrame)
{
    if (!pUnit)
    {
        return;
    }
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & 0x80000000))
    {
        return;
    }

    D2StatListStrc* pCurrent = pStatListEx->pMyLastList;
    D2StatListStrc* pPrevious;
    if (nFrame)
    {
        for (; pCurrent; pCurrent = pPrevious)
        {
            pPrevious = pCurrent->pPrevLink;
            if ((pCurrent->dwFlags & 2) && pCurrent->dwExpireFrame <= nFrame)
            {
                if (!(pCurrent->dwFlags & 0x80000000))
                {
                    D2Common_STATLIST_FreeStatListImpl_6FDB7050(pCurrent);
                }
                pPrevious = pStatListEx->pMyLastList;
            }
        }
    }
    else
    {
        for (; pCurrent; pCurrent = pPrevious)
        {
            pPrevious = pCurrent->pPrevLink;
            if (pCurrent->dwFlags & 2)
            {
                --pCurrent->dwExpireFrame;
                if (pCurrent->dwExpireFrame <= nFrame)
                {
                    if (!(pCurrent->dwFlags & 0x80000000))
                    {
                        D2Common_STATLIST_FreeStatListImpl_6FDB7050(pCurrent);
                    }
                    pPrevious = pStatListEx->pMyLastList;
                }
            }
        }
    }
}

// 0x006274F0
void __stdcall STATLIST_MergeBaseStats(D2StatListStrc* pTargetStatList, D2StatListStrc* pSourceStatlist)
{
    if (pTargetStatList && pSourceStatlist)
    {
        D2StatStrc* pStat = pSourceStatlist->pStat;
        D2StatStrc* pEnd = &pStat[pSourceStatlist->nStatCount];
        for (; pStat < pEnd; ++pStat)
        {
            STATLIST_AddStat(pTargetStatList, pStat->nStat, pStat->nValue, pStat->nLayer);
        }
    }
}

// 0x00627540
void __stdcall D2Common_10469(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & 0x80000000))
    {
        return;
    }
    D2StatListStrc* pCurrent = pStatListEx->pMyLastList;
    if (!pCurrent)
    {
        return;
    }
    D2StatListStrc* pPrevious;
    do
    {
        pPrevious = pCurrent->pPrevLink;
        if (pCurrent->dwOwnerType != 4 && !(pCurrent->dwFlags & 0x181) && !STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, pCurrent->dwStateNo))
        {
            if (!(pCurrent->dwFlags & 0x80000000))
            {
                D2Common_STATLIST_FreeStatListImpl_6FDB7050(pCurrent);
            }
            pPrevious = pStatListEx->pMyLastList;
        }
        pCurrent = pPrevious;
    }
    while (pPrevious);
}

// 0x00627910
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType)
{
    if (!pTarget || !pUnit)
    {
        return;
    }
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return;
    }
    if (pUnit->dwUnitType == 4)
    {
        const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pUnit);
        if (nBodyLoc == 11 || nBodyLoc == 12)
        {
            D2Common_ExpireStatList_6FDB6E30(pStatListEx);
            return;
        }
    }
    if (pStatListEx->pUnit == pTarget)
    {
        if (bType)
        {
            if (pStatListEx->dwFlags & 0x40000000)
            {
                D2Common_11274(pTarget, pUnit);
            }
        }
        else if (!(pStatListEx->dwFlags & 0x40000000))
        {
            D2Common_11275(pTarget, pUnit);
        }
    }
    else
    {
        D2COMMON_10475_PostStatToStatList(pTarget, pStatListEx, bType);
        pStatListEx->pUnit = pTarget;
    }
}

// 0x006279A0
int __stdcall D2Common_10574(D2UnitStrc* pUnit, int nStateId, int bSet)
{
    if (!nStateId)
    {
        return 0;
    }
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (pStatListEx && (pStatListEx->dwFlags & 0x80000000))
    {
        if (D2StatListStrc* pStatList = D2Common_GetStateFromStatListEx_6FDB8190(pStatListEx, nStateId))
        {
            if (bSet)
            {
                if (!(pStatList->dwFlags & 0x2000))
                {
                    D2Common_ExpireStatList_6FDB6E30(pStatList);
                    pStatList->dwFlags |= 0x2000;
                    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                    return 1;
                }
            }
            else if (pStatList->dwFlags & 0x2000)
            {
                D2Common_ExpireStatList_6FDB6E30(pStatList);
                pStatList->dwFlags &= ~0x2000;
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                return 1;
            }
        }
    }
    return 0;
}
