#include "D2Common.h"

#define STATLIST_NEWLENGTH 0x00000002
#define STATLIST_UNK_0x100 0x00000100
#define STATLIST_SET 0x00002000
#define STATLIST_EXTENDED 0x80000000
#define ISC_FLAG_FMIN 10
#define STATEMASK_DISGUISE 16
#define UNITFLAGEX_ISSHAPESHIFTED 8
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define STAT_SHIFT 16
#define STAT_MAKE(nStatId, nLayer) (((nStatId) << STAT_SHIFT) + (nLayer))
#define ITEMSTATCOST_HASFLAG(pRecord, nFlag) ((pRecord)->nItemStatFlags[(nFlag) >> 3] & gdwBitMasks[(nFlag) & 7])
#define STATES_CHECKFLAG(pRecord, nFlag) ((pRecord)->nStateFlags[(nFlag) >> 3] & gdwBitMasks[(nFlag) & 7])
#define UNITS_IsType(pUnit, nType) ((pUnit) && (pUnit)->dwUnitType == (nType))
struct D2StatStrc;
struct D2ModStatsArrayStrc;
struct D2StatsArrayStrc;
struct D2ItemStatCostTxt;
struct D2StatesTxt;

struct D2ModStatsArrayStrc
{
    void* pStat;
    unsigned short nStatCount;
    unsigned short nCapacity;
};

struct D2StatsArrayStrc
{
    D2StatStrc* pStat;
    short nStatCount;
    short nCapacity;
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
    int dwSkillNo;
    int dwSLvl;
    union
    {
        struct
        {
            D2StatsArrayStrc Stats;
        };
        struct
        {
            D2StatStrc* pStat;
            short nStatCount;
        };
    };
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
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    char unk0x04[0x58];
    D2StatListStrc* pStatListEx;
    char unk0x60[0x68];
    unsigned int dwFlagEx;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

struct D2StatStrc
{
    union
    {
        struct
        {
            int nPackedValue;
        };
        struct
        {
            unsigned short nLayer;
            unsigned short nStat;
        };
    };
    int nValue;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x04];
    unsigned char nItemStatFlags[4];
    char unk0x08[0x10];
    unsigned char nValShift;
    char unk0x19[0x13];
    int dwMinAccr;
    char unk0x30[0x144 - 0x30];
};

struct D2StatesTxt
{
    char unk0x00[0x10];
    unsigned char nStateFlags[8];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xBCC - 0xC8];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0x04];
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8
D2StatesTxt* __fastcall DATATBLS_GetStatesTxtRecord(int nStateId); // 0x00452040
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
int __stdcall STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625420
int __stdcall sub_00625350(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625350
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
D2StatListStrc* __stdcall D2Common_GetStateFromStatListEx_6FDB8190(D2StatListStrc* pStatListEx, int nStateId); // 0x00625650
D2StatListStrc* __stdcall sub_006256E0_StatListFindByFlags(D2StatListStrc* pStatList, int nFlag); // 0x006256E0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __fastcall D2Common_STATLIST_FreeStatListImpl_6FDB7050(D2StatListStrc* pStatList); // 0x00626C00
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList); // 0x00627340
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030
int __stdcall STATES_CheckStateMaskStayDeathOnUnitByStateId(D2UnitStrc* pUnit, int nState); // 0x0063A4A0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
void __stdcall D2Common_ExpireStatList_6FDB6E30(D2StatListStrc* pStatList); // 0x006269F0
int __stdcall D2Common_11274(D2UnitStrc* pTarget, D2UnitStrc* pUnit); // 0x00627860
int __stdcall D2Common_11275(D2UnitStrc* pTarget, D2UnitStrc* pUnit); // 0x00627A40
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

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

static __forceinline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

static int sub_00624B90_FindStatIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    D2StatStrc* pStat = pStatsArray->pStat;
    int nMax = pStatsArray->nStatCount;
    int nMin = 0;
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
    return -1;
}

static D2StatStrc* sub_00624C60_FindStat(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    const int nIndex = sub_00624B90_FindStatIndex(pStatsArray, nLayer_StatId);
    if (nIndex < 0)
    {
        return 0;
    }
    return &pStatsArray->pStat[nIndex];
}

static int __stdcall sub_00624F60_GetTotalStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    D2StatStrc* pStat = sub_00624C60_FindStat((pStatList->dwFlags & STATLIST_EXTENDED) ? &pStatList->FullStats : &pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        return 0;
    }

    int nValue = pStat->nValue;
    if (pItemStatCostTxtRecord && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FMIN) && (pStatList->dwFlags & STATLIST_EXTENDED)
        && pStatList->pOwner && (UNITS_IsType(pStatList->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatList->pOwner, UNIT_MONSTER)))
    {
        if (nValue < pItemStatCostTxtRecord->dwMinAccr)
        {
            nValue = pItemStatCostTxtRecord->dwMinAccr << pItemStatCostTxtRecord->nValShift;
        }
    }
    return nValue;
}

// 0x00625420
int __stdcall STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    if (!pStatList)
    {
        return 0;
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return sub_00624F60_GetTotalStat(pStatList, STAT_MAKE(nStatId, nLayer), pItemStatCostTxtRecord);
}

// 0x00625480
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    if (!pStatList)
    {
        return 0;
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return sub_00624F60_GetTotalStat(pStatList, STAT_MAKE(nStatId, nLayer), pItemStatCostTxtRecord);
}

// 0x00625A70
void __stdcall sub_00625A70_ToggleState(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (pUnit)
    {
        D2StatListStrc* pStatListEx = pUnit->pStatListEx;
        if (pStatListEx && (pStatListEx->dwFlags & STATLIST_EXTENDED))
        {
            const unsigned int bWasSet = pStatListEx->StatFlags[nState >> 5] & gdwBitMasks[nState & 31];
            if (bSet)
                pStatListEx->StatFlags[nState >> 5] |= gdwBitMasks[nState & 31];
            else
                pStatListEx->StatFlags[nState >> 5] &= gdwInvBitMasks[nState & 31];

            if (!bWasSet)
            {
                if (!bSet)
                    return;
            }
            else
            {
                if (bSet)
                    return;
            }

            pStatListEx->StatFlags[(nState >> 5) + (sgptDataTables->nStatesTxtRecordCount + 31) / 32] |= gdwBitMasks[nState & 31];

            D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord(nState);
            if (pStatesTxtRecord)
            {
                if (bSet)
                {
                    if (STATES_CHECKFLAG(pStatesTxtRecord, STATEMASK_DISGUISE))
                        pUnit->dwFlagEx |= UNITFLAGEX_ISSHAPESHIFTED;
                }
                else if (STATES_CHECKFLAG(pStatesTxtRecord, STATEMASK_DISGUISE) && !STATES_CheckStateMaskOnUnit(pUnit, STATEMASK_DISGUISE))
                {
                    pUnit->dwFlagEx &= ~UNITFLAGEX_ISSHAPESHIFTED;
                }
            }
        }
    }
}

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
