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

struct D2OpStatDataStrc
{
    unsigned short nOpBase;
    unsigned short nStat;
    unsigned char nOp;
    unsigned char nOpParam;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x04];
    unsigned char nItemStatFlags[4];
    char unk0x08[0x10];
    unsigned char nValShift;
    char unk0x19[0x13];
    int dwMinAccr;
    char unk0x30[0x20];
    unsigned char nKeepZero;
    unsigned char bIsBaseOfOtherStatOp;
    unsigned char bHasOpStatData;
    unsigned char bHasOpApplyingToItem;
    unsigned char nOp;
    char unk0x55[0x03];
    unsigned short wOpStat[3];
    unsigned short wStatsAffected[64];
    D2OpStatDataStrc pOpStatData[16];
    char unk0x13E[0x06];
};

struct D2CharStatsTxt
{
    char unk0x00[0x46];
    unsigned char nLifePerVitality;
    unsigned char nStaminaPerVitality;
    unsigned char nManaPerMagic;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0x04];
    int nItemStatCostTxtRecordCount;
};

#define STATLIST_EXTENDED 0x80000000
#define STATLIST_DYNAMIC 0x40000000
#define STATLIST_PERMANENT 0x20000000
#define STATLIST_SET 0x2000
#define ISC_FLAG_DAMAGERELATED 2
#define ISC_FLAG_FMIN 10
#define ISC_FLAG_FCALLBACK 11
#define ISC_FLAG_SAVED 12
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_ITEM 4
#define STATS_GROWTH 4
#define STATS_SHRINK 8
#define STAT_SHIFT 16
#define STAT_NONE 0xFFFF
#define STAT_MAXSTAMINA 11
#define STAT_MAXDURABILITY 73
#define OPSTAT_COUNT 3
#define OPDATA_COUNT 16
#define AFFECTED_COUNT 64
#define STAT_MAKE(nStatId, nLayer) (((nStatId) << STAT_SHIFT) + (nLayer))
#define STAT_GETID(nLayer_StatId) (((nLayer_StatId) >> STAT_SHIFT) & 0xFFFF)
#define ITEMSTATCOST_HASFLAG(pRecord, nFlag) ((pRecord)->nItemStatFlags[(nFlag) >> 3] & gdwBitMasks[(nFlag) & 7])
#define UNITS_IsType(pUnit, nType) ((pUnit) && (pUnit)->dwUnitType == (nType))

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId);                           // 0x0045C4F0
D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClassId);                               // 0x004833E0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);                       // 0x0061C100
int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax); // 0x0065CA30
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

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

// 0x00624BD0
static int sub_00624BD0_FindStatInsertIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
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
            return -1;
        }
    }
    return nMin;
}

// 0x00624C10
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

static D2StatStrc* sub_00624C60_FindStat(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    const int nIndex = sub_00624B90_FindStatIndex(pStatsArray, nLayer_StatId);
    if (nIndex < 0)
    {
        return 0;
    }
    return &pStatsArray->pStat[nIndex];
}

// 0x00624C80
static D2StatStrc* __stdcall sub_00624C80_InsertStatOrFail(void* pMemPool, D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    const int nIndex = sub_00624BD0_FindStatInsertIndex(pStatsArray, nLayer_StatId);
    if (nIndex < 0)
    {
        return 0;
    }

    if (pStatsArray->nStatCount >= pStatsArray->nCapacity)
    {
        pStatsArray->nCapacity += STATS_GROWTH;
        pStatsArray->pStat = (D2StatStrc*)FOG_ReallocPool(pMemPool, pStatsArray->pStat, pStatsArray->nCapacity * sizeof(D2StatStrc), ".\\Stats\\StatsEx.cpp", 0xE8, 0);
    }

    if (nIndex < pStatsArray->nStatCount)
    {
        memmove(&pStatsArray->pStat[nIndex + 1], &pStatsArray->pStat[nIndex], (pStatsArray->nStatCount - nIndex) * sizeof(D2StatStrc));
    }

    D2StatStrc* pStat = &pStatsArray->pStat[nIndex];
    pStat->nPackedValue = nLayer_StatId;
    pStat->nValue = 0;
    ++pStatsArray->nStatCount;
    return pStat;
}

// 0x00624D10
static void __stdcall sub_00624D10_RemoveStat(void* pMemPool, D2StatsArrayStrc* pStatsArray, D2StatStrc* pStat)
{
    const int nIndex = pStat - pStatsArray->pStat;
    if (nIndex < pStatsArray->nStatCount)
    {
        if (nIndex < pStatsArray->nStatCount - 1)
        {
            memmove(pStat, pStat + 1, (pStatsArray->nStatCount - (nIndex + 1)) * sizeof(D2StatStrc));
        }

        --pStatsArray->nStatCount;

        if (pStatsArray->nCapacity - pStatsArray->nStatCount > STATS_SHRINK)
        {
            pStatsArray->nCapacity -= STATS_GROWTH;
            pStatsArray->pStat = (D2StatStrc*)FOG_ReallocPool(pMemPool, pStatsArray->pStat, pStatsArray->nCapacity * sizeof(D2StatStrc), ".\\Stats\\StatsEx.cpp", 0x110, 0);
        }
    }
}

// 0x00624D90
static int sub_00624D90_FindModStatInsertIndex(D2ModStatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    int* pStat = pStatsArray->pStat;
    int nMax = pStatsArray->nStatCount;
    int nMin = 0;
    while (nMin < nMax)
    {
        const int nMid = nMin + (nMax - nMin) / 2;
        const int nPackedValue = pStat[nMid];
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
            return -1;
        }
    }
    return nMin;
}

// 0x00624DD0
static void __stdcall sub_00624DD0_InsertStatModOrFail(D2StatListStrc* pStatListEx, int nLayer_StatId)
{
    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return;
    }

    const int nStatId = STAT_GETID(nLayer_StatId);
    switch (nStatId)
    {
    case 6:
    case 8:
    case 10:
    case 13:
    case 14:
        return;
    default:
        break;
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
    if (!pItemStatCostTxtRecord || !ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_SAVED))
    {
        return;
    }

    const int nIndex = sub_00624D90_FindModStatInsertIndex(&pStatListEx->ModStats, nLayer_StatId);
    if (nIndex < 0)
    {
        return;
    }

    if (pStatListEx->ModStats.nStatCount >= pStatListEx->ModStats.nCapacity)
    {
        pStatListEx->ModStats.nCapacity += STATS_GROWTH;
        pStatListEx->ModStats.pStat = (int*)FOG_ReallocPool(pStatListEx->pMemPool, pStatListEx->ModStats.pStat, pStatListEx->ModStats.nCapacity * sizeof(int), ".\\Stats\\StatsEx.cpp", 0x162, 0);
    }

    if (nIndex < pStatListEx->ModStats.nStatCount)
    {
        memmove(&pStatListEx->ModStats.pStat[nIndex + 1], &pStatListEx->ModStats.pStat[nIndex], (pStatListEx->ModStats.nStatCount - nIndex) * sizeof(int));
    }

    pStatListEx->ModStats.pStat[nIndex] = nLayer_StatId;
    ++pStatListEx->ModStats.nStatCount;
}

// 0x00624ED0
static int __stdcall sub_00624ED0_GetBaseStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    D2StatStrc* pStat = sub_00624C60_FindStat(&pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        return 0;
    }

    int nValue = pStat->nValue;
    if (pItemStatCostTxtRecord && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FMIN) && (pStatList->dwFlags & STATLIST_EXTENDED)
        && (UNITS_IsType(pStatList->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatList->pOwner, UNIT_MONSTER)))
    {
        if (nValue < pItemStatCostTxtRecord->dwMinAccr)
        {
            nValue = pItemStatCostTxtRecord->dwMinAccr << pItemStatCostTxtRecord->nValShift;
        }
    }
    return nValue;
}

// 0x00624F60
static int __stdcall sub_00624F60_GetTotalStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    D2StatStrc* pStat = sub_00624C60_FindStat((pStatList->dwFlags & STATLIST_EXTENDED) ? &pStatList->FullStats : &pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        return 0;
    }

    int nValue = pStat->nValue;
    if (pItemStatCostTxtRecord && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FMIN) && (pStatList->dwFlags & STATLIST_EXTENDED)
        && (UNITS_IsType(pStatList->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatList->pOwner, UNIT_MONSTER)))
    {
        if (nValue < pItemStatCostTxtRecord->dwMinAccr)
        {
            nValue = pItemStatCostTxtRecord->dwMinAccr << pItemStatCostTxtRecord->nValShift;
        }
    }
    return nValue;
}

// 0x00624FE0
static int __stdcall sub_00624FE0_GetStatWithChildLists(D2StatListStrc* pStatListEx, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    int nValue = sub_00624ED0_GetBaseStat(pStatListEx, nLayer_StatId, 0);

    const unsigned int bDamageRelated = ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_DAMAGERELATED);
    if (pStatListEx->dwFlags & STATLIST_EXTENDED)
    {
        for (D2StatListStrc* i = pStatListEx->pMyLastList; i; i = i->pPrevLink)
        {
            if (!bDamageRelated || !(i->dwFlags & STATLIST_DYNAMIC))
            {
                nValue += sub_00624F60_GetTotalStat(i, nLayer_StatId, 0);
            }
        }
    }
    return nValue;
}

static __forceinline void STATLIST_NotifyUnitOfStatValueChange(D2ItemStatCostTxt* pItemStatCostTxtRecord, D2StatListStrc* pStatListEx, D2UnitStrc* pUnit, int nLayer_StatId, int nPreviousValue, int nNewValue)
{
    if (pStatListEx->pfOnValueChanged && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FCALLBACK))
    {
        pStatListEx->pfOnValueChanged(pStatListEx->pGame, pStatListEx->pOwner, pUnit, nLayer_StatId, nPreviousValue, nNewValue);
    }
}

// 0x006250B0
static int __stdcall sub_006250B0_AddFullStatValue(D2StatListStrc* pStatListEx, int nLayer_StatId, int nValue, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit)
{
    D2StatStrc* pStat = sub_00624C60_FindStat(&pStatListEx->FullStats, nLayer_StatId);
    if (!pStat)
    {
        pStat = sub_00624C80_InsertStatOrFail(pStatListEx->pMemPool, &pStatListEx->FullStats, nLayer_StatId);
    }

    const int nPreviousValue = pStat->nValue;
    const int nNewValue = nPreviousValue + nValue;
    pStat->nValue = nNewValue;
    if (nNewValue > 0 && pItemStatCostTxtRecord->bHasOpApplyingToItem)
    {
        pStatListEx->dwFlags |= STATLIST_PERMANENT;
    }

    if (pStat->nValue == 0 && !pItemStatCostTxtRecord->nKeepZero)
    {
        sub_00624D10_RemoveStat(pStatListEx->pMemPool, &pStatListEx->FullStats, pStat);
    }

    STATLIST_NotifyUnitOfStatValueChange(pItemStatCostTxtRecord, pStatListEx, pUnit, nLayer_StatId, nPreviousValue, nNewValue);
    return nNewValue;
}

// 0x00625150
static void __stdcall sub_00625150_UpdateUnitStat(D2StatListStrc* pStatListEx, int nLayer_StatId, int nNewValue, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit)
{
    D2StatStrc* pStat = sub_00624C60_FindStat(&pStatListEx->FullStats, nLayer_StatId);
    if (!pStat)
    {
        if (!nNewValue)
        {
            return;
        }
        pStat = sub_00624C80_InsertStatOrFail(pStatListEx->pMemPool, &pStatListEx->FullStats, nLayer_StatId);
    }

    const int nPreviousValue = pStat->nValue;
    if (nNewValue || pItemStatCostTxtRecord->nKeepZero)
    {
        pStat->nValue = nNewValue;
        if (pItemStatCostTxtRecord->bHasOpApplyingToItem)
        {
            pStatListEx->dwFlags |= STATLIST_PERMANENT;
        }
    }
    else
    {
        sub_00624D10_RemoveStat(pStatListEx->pMemPool, &pStatListEx->FullStats, pStat);
    }

    if (nPreviousValue != nNewValue)
    {
        STATLIST_NotifyUnitOfStatValueChange(pItemStatCostTxtRecord, pStatListEx, pUnit, nLayer_StatId, nPreviousValue, nNewValue);
    }
}

// 0x00625350
int __stdcall sub_00625350(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
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

    return sub_00624ED0_GetBaseStat(pStatList, STAT_MAKE(nStatId, nLayer), pItemStatCostTxtRecord);
}

// 0x006253B0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer)
{
    if (!pUnit)
    {
        return 0;
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    if (!pStatList)
    {
        return 0;
    }

    return sub_00624ED0_GetBaseStat(pStatList, STAT_MAKE(nStatId, nLayer), pItemStatCostTxtRecord);
}

// 0x00625870
void __stdcall D2Common_10512(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nStatId, StatListUnitCallback pfCallback)
{
    if (!pUnit1)
    {
        return;
    }

    D2StatListStrc* pStatListEx = pUnit1->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return;
    }

    const int nLayer_StatId = nStatId << STAT_SHIFT;
    if (sub_00624D90_FindModStatInsertIndex(&pStatListEx->ModStats, nLayer_StatId) != -1)
    {
        return;
    }

    D2StatStrc* pStat = sub_00624C60_FindStat(&pStatListEx->Stats, nLayer_StatId);
    if (pStat)
    {
        pfCallback(pUnit1, nStatId, pStat->nValue, pUnit2);
    }
}

// 0x006258D0
void __stdcall D2Common_10513(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, StatListUnitCallback pfCallback)
{
    if (!pUnit1 || (!pUnit2 && pfCallback))
    {
        return;
    }

    D2StatListStrc* pStatListEx = pUnit1->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return;
    }

    for (int i = 0; i < pStatListEx->ModStats.nStatCount; ++i)
    {
        const int nLayer_StatId = pStatListEx->ModStats.pStat[i];
        D2StatStrc* pStat = sub_00624C60_FindStat(&pStatListEx->Stats, nLayer_StatId);
        if (!pStat)
        {
            pfCallback(pUnit1, STAT_GETID(nLayer_StatId), 0, pUnit2);
        }
        else
        {
            pfCallback(pUnit1, pStat->nStat, pStat->nValue, pUnit2);
        }
    }
}

// build: context STATLIST_GetTotalStatValue
static __forceinline int STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
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

// 0x00625E00
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit)
{
    if (!STATLIST_GetUnitBaseStat(pUnit, STAT_MAXDURABILITY, 0))
    {
        return 0;
    }
    return STATLIST_GetTotalStatValue(pUnit->pStatListEx, STAT_MAXDURABILITY, 0);
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

// 0x006261B0
int __stdcall D2COMMON_11269_CopyStats(D2StatListStrc* pStatListEx, int nStatId, D2StatStrc* pBuffer, int nBufferSize)
{
    return sub_00626110_CopyStats(pStatListEx, nStatId, pBuffer, nBufferSize);
}

// 0x006261D0
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

// 0x00626200
int __fastcall sub_00626200_GetStatFromLayer(D2StatListStrc* pStatListEx, int nLayer_StatId)
{
    const int nStatId = STAT_GETID(nLayer_StatId);

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    int nPreviousOpStatValue = sub_00624FE0_GetStatWithChildLists(pStatListEx, nLayer_StatId, pItemStatCostTxtRecord);
    int nAccumulatedValue = nPreviousOpStatValue;

    if (!pItemStatCostTxtRecord->bHasOpStatData)
    {
        return nAccumulatedValue;
    }

    for (int i = 0; i < OPDATA_COUNT; ++i)
    {
        D2OpStatDataStrc* pOpStatData = &pItemStatCostTxtRecord->pOpStatData[i];
        int nBaseTime;
        int nBaseTime2;
        if (!pOpStatData->nOp)
        {
            break;
        }

        switch (pOpStatData->nOp)
        {
        case 1:
            if (pStatListEx->pOwner)
            {
                if (pStatListEx->pOwner->dwUnitType == UNIT_ITEM)
                {
                    nPreviousOpStatValue = STATLIST_GetUnitBaseStat(pStatListEx->pOwner, nStatId, 0);
                }

                if (nPreviousOpStatValue)
                {
                    const int nOpStatValue = sub_00626200_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT);
                    if (nOpStatValue)
                    {
                        nAccumulatedValue += DATATBLS_ApplyRatio(nPreviousOpStatValue, nOpStatValue, 100);
                    }
                }
            }
            break;

        case 2:
            if (pStatListEx->dwOwnerType == UNIT_PLAYER || pStatListEx->dwOwnerType == UNIT_MONSTER)
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE)
                {
                    D2ItemStatCostTxt* pOpBaseItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nOpBase);
                    if (pOpBaseItemStatCostTxtRecord)
                    {
                        const int nShiftedVal = sub_00624F60_GetTotalStat(pStatListEx, nOpBase << STAT_SHIFT, 0) >> pOpBaseItemStatCostTxtRecord->nValShift;
                        if (nShiftedVal > 0)
                        {
                            const int nOpLayer_StatId = pOpStatData->nStat << STAT_SHIFT;
                            const int nRecursiveValue = sub_00626200_GetStatFromLayer(pStatListEx, nOpLayer_StatId);
                            if (nRecursiveValue)
                            {
                                nAccumulatedValue += (nShiftedVal * nRecursiveValue) >> pOpStatData->nOpParam;
                            }
                        }
                    }
                }
            }
            break;

        case 3:
            if (pStatListEx->dwOwnerType == UNIT_PLAYER || pStatListEx->dwOwnerType == UNIT_MONSTER)
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE)
                {
                    D2ItemStatCostTxt* pOpBaseItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nOpBase);
                    if (pOpBaseItemStatCostTxtRecord)
                    {
                        const int nShiftedVal = sub_00624F60_GetTotalStat(pStatListEx, nOpBase << STAT_SHIFT, 0) >> pOpBaseItemStatCostTxtRecord->nValShift;
                        if (nShiftedVal > 0)
                        {
                            const int nOpLayer_StatId = pOpStatData->nStat << STAT_SHIFT;
                            const int nRecursiveValue = sub_00626200_GetStatFromLayer(pStatListEx, nOpLayer_StatId);
                            if (nRecursiveValue)
                            {
                                nAccumulatedValue += DATATBLS_ApplyRatio(nPreviousOpStatValue, (nShiftedVal * nRecursiveValue) >> pOpStatData->nOpParam, 100);
                            }
                        }
                    }
                }
            }
            break;

        case 4:
            if (pStatListEx->pUnit && (pStatListEx->pUnit->dwUnitType == UNIT_PLAYER || pStatListEx->pUnit->dwUnitType == UNIT_MONSTER))
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE)
                {
                    D2ItemStatCostTxt* pOpBaseItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nOpBase);
                    if (pOpBaseItemStatCostTxtRecord)
                    {
                        D2UnitStrc* const pUnit = pStatListEx->pUnit;
                        const int nShiftedVal = STATLIST_UnitGetStatValue(pUnit, nOpBase, 0) >> pOpBaseItemStatCostTxtRecord->nValShift;
                        if (nShiftedVal > 0)
                        {
                            const int nOpLayer_StatId = pOpStatData->nStat << STAT_SHIFT;
                            const int nRecursiveValue = sub_00626200_GetStatFromLayer(pStatListEx, nOpLayer_StatId);
                            if (nRecursiveValue)
                            {
                                nAccumulatedValue += (nShiftedVal * nRecursiveValue) >> pOpStatData->nOpParam;
                            }
                        }
                    }
                }
            }
            break;

        case 5:
            if (pStatListEx->pUnit && (pStatListEx->pUnit->dwUnitType == UNIT_PLAYER || pStatListEx->pUnit->dwUnitType == UNIT_MONSTER))
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE)
                {
                    D2ItemStatCostTxt* pOpBaseItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nOpBase);
                    if (pOpBaseItemStatCostTxtRecord)
                    {
                        D2UnitStrc* const pUnit = pStatListEx->pUnit;
                        const int nShiftedVal = STATLIST_UnitGetStatValue(pUnit, nOpBase, 0) >> pOpBaseItemStatCostTxtRecord->nValShift;
                        if (nShiftedVal > 0)
                        {
                            const int nOpLayer_StatId = pOpStatData->nStat << STAT_SHIFT;
                            const int nRecursiveValue = sub_00626200_GetStatFromLayer(pStatListEx, nOpLayer_StatId);
                            if (nRecursiveValue)
                            {
                                nAccumulatedValue += DATATBLS_ApplyRatio(nPreviousOpStatValue, (nShiftedVal * nRecursiveValue) >> pOpStatData->nOpParam, 100);
                            }
                        }
                    }
                }
            }
            break;

        case 6:
            if (pStatListEx->pOwner)
            {
                if (D2DrlgActStrc* pAct = pStatListEx->pOwner->pDrlgAct)
                {
                    if (const int nTmp = sub_00626200_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT))
                    {
                        nBaseTime = 0;
                        const int nPeriodOfDay = ENVIRONMENT_GetPeriodOfDayFromAct(pAct, &nBaseTime);
                        nAccumulatedValue += ITEMMODS_GetByTimeAdjustment(nTmp, nPeriodOfDay, nBaseTime, 0, 0, 0);
                    }
                }
            }
            break;

        case 7:
            if (pStatListEx->pOwner)
            {
                if (D2DrlgActStrc* pAct = pStatListEx->pOwner->pDrlgAct)
                {
                    if (const int nTmp = sub_00626200_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT))
                    {
                        nBaseTime2 = 0;
                        const int nPeriodOfDay = ENVIRONMENT_GetPeriodOfDayFromAct(pAct, &nBaseTime2);
                        nAccumulatedValue += DATATBLS_ApplyRatio(nAccumulatedValue, ITEMMODS_GetByTimeAdjustment(nTmp, nPeriodOfDay, nBaseTime2, 0, 0, 0), 100);
                    }
                }
            }
            break;

        case 8:
            if (pStatListEx->pOwner && pStatListEx->pOwner->dwUnitType == UNIT_PLAYER)
            {
                if (D2CharStatsTxt* pCharStatsTxtRecord = sub_004833E0_GetCharStatsTxtRecord(pStatListEx->pOwner->dwClassId))
                {
                    const int nIndex = sub_00624B90_FindStatIndex(&pStatListEx->Stats, pOpStatData->nStat << STAT_SHIFT);
                    D2StatStrc* pStat = nIndex < 0 ? 0 : &pStatListEx->Stats.pStat[nIndex];
                    const int nTemp = !pStat ? 0 : pStat->nValue;

                    const int nBaseValue = sub_00626200_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT) - nTemp;
                    if (nBaseValue)
                    {
                        nAccumulatedValue += nBaseValue * pCharStatsTxtRecord->nManaPerMagic << 6;
                    }
                }
            }
            break;

        case 9:
            if (pStatListEx->pOwner && pStatListEx->pOwner->dwUnitType == UNIT_PLAYER)
            {
                if (D2CharStatsTxt* pCharStatsTxtRecord = sub_004833E0_GetCharStatsTxtRecord(pStatListEx->pOwner->dwClassId))
                {
                    const int nIndex = sub_00624B90_FindStatIndex(&pStatListEx->Stats, pOpStatData->nStat << STAT_SHIFT);
                    D2StatStrc* pStat = nIndex < 0 ? 0 : &pStatListEx->Stats.pStat[nIndex];
                    const int nBaseStatValue = !pStat ? 0 : pStat->nValue;

                    const int nBonusValue = sub_00626200_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT) - nBaseStatValue;
                    if (nBonusValue)
                    {
                        if (nStatId == STAT_MAXSTAMINA)
                        {
                            nAccumulatedValue += nBonusValue * pCharStatsTxtRecord->nStaminaPerVitality << 6;
                        }
                        else
                        {
                            nAccumulatedValue += nBonusValue * pCharStatsTxtRecord->nLifePerVitality << 6;
                        }
                    }
                }
            }
            break;

        case 11:
            if (nPreviousOpStatValue)
            {
                if (UNITS_IsType(pStatListEx->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatListEx->pOwner, UNIT_MONSTER))
                {
                    const int nOpStatValue = sub_00626200_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT);
                    if (nOpStatValue)
                    {
                        nAccumulatedValue += DATATBLS_ApplyRatio(nPreviousOpStatValue, nOpStatValue, 100);
                    }
                }
            }
            break;

        case 13:
            if (pStatListEx->pOwner && pStatListEx->pOwner->dwUnitType == UNIT_ITEM)
            {
                nPreviousOpStatValue = STATLIST_GetUnitBaseStat(pStatListEx->pOwner, nStatId, 0);
                if (nPreviousOpStatValue)
                {
                    const int nOpStatValue = sub_00626200_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT);
                    if (nOpStatValue)
                    {
                        nAccumulatedValue += DATATBLS_ApplyRatio(nPreviousOpStatValue, nOpStatValue, 100);
                    }
                }
            }
            break;

        default:
            break;
        }
    }

    return nAccumulatedValue;
}
