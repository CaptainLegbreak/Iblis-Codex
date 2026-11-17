struct D2UnitStrc;
struct D2StatStrc;

struct D2ModStatsArrayStrc
{
    void* pStat;
    unsigned short nStatCount;
    unsigned short nCapacity;
};

struct D2StatListStrc
{
    void* pMemPool;
    D2UnitStrc* pUnit;
    unsigned int dwOwnerType;
    unsigned int dwOwnerId;
    unsigned int dwFlags;
    unsigned int dwStateNo;
    int dwExpireFrame;
    char unk0x1C[16];
    D2StatListStrc* pPrevLink;
    D2StatListStrc* pNextLink;
    D2StatListStrc* pParent;
    void* fpStatRemove;
    D2StatListStrc* pMyLastList;
    D2StatListStrc* pMyStats;
    D2UnitStrc* pOwner;
    char unk0x48[8];
    D2ModStatsArrayStrc ModStats;
    unsigned int* StatFlags;
};

struct D2UnitStrc
{
    char unk0x00[92];
    D2StatListStrc* pStatListEx;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

#define STATLIST_NEWLENGTH 0x00000002
#define STATLIST_UNK_0x100 0x00000100
#define STATLIST_SET 0x00002000
#define STATLIST_EXTENDED 0x80000000

// 0x006251F0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID)
{
    D2StatListStrc* pStatList = (D2StatListStrc*)sub_0040B430(pMemPool, 0x3C, ".\\Stats\\StatsEx.cpp", 1386, 0);
    memset(pStatList, 0x00, 0x3C);

    pStatList->dwOwnerType = nUnitType;
    pStatList->dwOwnerId = nUnitGUID;
    pStatList->pMemPool = pMemPool;
    pStatList->dwFlags = fFilter;
    pStatList->dwExpireFrame = dwTimeout;

    return pStatList;
}

// 0x00625310
void __stdcall STATLIST_SetExpireFrame(D2StatListStrc* pStatList, int nExpireFrame)
{
    if (pStatList)
    {
        if (nExpireFrame > 0)
        {
            pStatList->dwFlags |= STATLIST_NEWLENGTH;
        }

        pStatList->dwExpireFrame = nExpireFrame;
    }
}

// 0x006256E0
D2StatListStrc* __stdcall sub_006256E0_StatListFindByFlags(D2StatListStrc* pStatList, int nFlag)
{
    if (pStatList)
    {
        if (pStatList->dwFlags & STATLIST_EXTENDED)
        {
            pStatList = nFlag & STATLIST_SET ? pStatList->pMyStats : pStatList->pMyLastList;
        }
        nFlag &= ~STATLIST_SET;

        while (pStatList)
        {
            if (nFlag & pStatList->dwFlags)
            {
                return pStatList;
            }
            pStatList = pStatList->pPrevLink;
        }
    }

    return 0;
}

// 0x00625730
D2StatListStrc* __stdcall STATLIST_GetStatListFromFlag(D2StatListStrc* pStatList, int nFlag)
{
    if (pStatList)
    {
        for (pStatList = pStatList->pPrevLink; pStatList; pStatList = pStatList->pPrevLink)
        {
            if (nFlag & pStatList->dwFlags)
            {
                return pStatList;
            }
        }
    }

    return 0;
}

// 0x006257D0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag)
{
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (pStatListEx && pStatListEx->dwFlags & STATLIST_EXTENDED)
    {
        D2StatListStrc* pStatList = pStatListEx->pMyLastList;
        if (nFlag & STATLIST_SET)
        {
            pStatList = pStatListEx->pMyStats;
            nFlag &= ~STATLIST_SET;
        }

        while (pStatList)
        {
            if (pStatList->dwStateNo == nState && (!nFlag || nFlag & pStatList->dwFlags))
            {
                return pStatList;
            }
            pStatList = pStatList->pPrevLink;
        }
    }

    return 0;
}

// 0x00625960
void __stdcall STATLIST_FreeModStats(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatListEx = pUnit ? pUnit->pStatListEx : 0;
    if (pStatListEx && pStatListEx->dwFlags & STATLIST_EXTENDED)
    {
        if (pStatListEx->ModStats.pStat)
        {
            FOG_FreeServerMemory(pStatListEx->pMemPool, pStatListEx->ModStats.pStat, ".\\Stats\\StatsEx.cpp", 2590, 0);
            pStatListEx->ModStats.pStat = 0;
        }

        pStatListEx->ModStats.nCapacity = 0;
        pStatListEx->ModStats.nStatCount = 0;
    }
}

// 0x00625A00
void __stdcall D2Common_10534(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatListEx = pUnit ? pUnit->pStatListEx : 0;
    if (pStatListEx)
    {
        pStatListEx->dwFlags |= STATLIST_UNK_0x100;
    }
}

// 0x00625A20
int __stdcall D2COMMON_10530_D2CheckStatlistFlagDMGRed(D2UnitStrc* pUnit)
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

    return (pStatListEx->dwFlags & STATLIST_UNK_0x100) != 0;
}
