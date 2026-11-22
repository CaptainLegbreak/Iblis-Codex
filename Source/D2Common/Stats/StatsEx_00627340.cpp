#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2GameStrc;
struct D2DrlgActStrc;




typedef void (__fastcall* StatListValueChangeFunc)(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nLayer_StatId, int nPreviousValue, int nNewValue);
typedef void (__fastcall* StatListUnitCallback)(D2UnitStrc* pUnit1, int nStatId, int nValue, D2UnitStrc* pUnit2);






#define STATLIST_SET 0x2000

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern "C" const char gszStatListSourceFile[];                                                              // 0x006E90A4
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId);                           // 0x0045C4F0
extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);                       // 0x0061C100
int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax); // 0x0065CA30
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

static inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x00624B90
static int sub_00624B90_FindStatIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
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
    return -1;
}

// 0x00624BD0
static int STATLIST_FindStatInsertIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
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
static int __stdcall STATLIST_FindFirstStatIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
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

// 0x00624C60
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
static D2StatStrc* __stdcall STATLIST_InsertStatOrFail(void* pMemPool, D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    const int nIndex = STATLIST_FindStatInsertIndex(pStatsArray, nLayer_StatId);
    if (nIndex < 0)
    {
        return 0;
    }

    if (pStatsArray->nStatCount >= pStatsArray->nCapacity)
    {
        pStatsArray->nCapacity += STATS_GROWTH;
        pStatsArray->pStat = (D2StatStrc*)FOG_ReallocPool(pMemPool, pStatsArray->pStat, pStatsArray->nCapacity * sizeof(D2StatStrc), gszStatListSourceFile, 0xE8, 0);
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
static void __stdcall STATLIST_RemoveStat(void* pMemPool, D2StatsArrayStrc* pStatsArray, D2StatStrc* pStat)
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
            pStatsArray->pStat = (D2StatStrc*)FOG_ReallocPool(pMemPool, pStatsArray->pStat, pStatsArray->nCapacity * sizeof(D2StatStrc), gszStatListSourceFile, 0x110, 0);
        }
    }
}

// 0x00624D90
static int STATLIST_FindModStatInsertIndex(D2ModStatsArrayStrc* pStatsArray, int nLayer_StatId)
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
static void __stdcall STATLIST_InsertStatModOrFail(D2StatListExStrc* pStatListEx, int nLayer_StatId)
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

    const int nIndex = STATLIST_FindModStatInsertIndex(&pStatListEx->ModStats, nLayer_StatId);
    if (nIndex < 0)
    {
        return;
    }

    if (pStatListEx->ModStats.nStatCount >= pStatListEx->ModStats.nCapacity)
    {
        pStatListEx->ModStats.nCapacity += STATS_GROWTH;
        pStatListEx->ModStats.pStat = (int*)FOG_ReallocPool(pStatListEx->pMemPool, pStatListEx->ModStats.pStat, pStatListEx->ModStats.nCapacity * sizeof(int), gszStatListSourceFile, 0x162, 0);
    }

    if (nIndex < pStatListEx->ModStats.nStatCount)
    {
        memmove(&pStatListEx->ModStats.pStat[nIndex + 1], &pStatListEx->ModStats.pStat[nIndex], (pStatListEx->ModStats.nStatCount - nIndex) * sizeof(int));
    }

    pStatListEx->ModStats.pStat[nIndex] = nLayer_StatId;
    ++pStatListEx->ModStats.nStatCount;
}

int __stdcall STATLIST_GetBaseStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord); // 0x00624ED0

int __stdcall sub_00624F60_GetTotalStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord); // 0x00624F60

// 0x00624FE0
static int __stdcall STATLIST_GetStatWithChildLists(D2StatListExStrc* pStatListEx, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    int nValue = STATLIST_GetBaseStat(pStatListEx, nLayer_StatId, 0);

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

static inline void STATLIST_NotifyUnitOfStatValueChange(D2ItemStatCostTxt* pItemStatCostTxtRecord, D2StatListExStrc* pStatListEx, D2UnitStrc* pUnit, int nLayer_StatId, int nPreviousValue, int nNewValue)
{
    if (pStatListEx->pfOnValueChanged && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FCALLBACK))
    {
        pStatListEx->pfOnValueChanged(pStatListEx->pGame, pStatListEx->pOwner, pUnit, nLayer_StatId, nPreviousValue, nNewValue);
    }
}

// 0x006250B0
static int __stdcall STATLIST_AddFullStatValue(D2StatListExStrc* pStatListEx, int nLayer_StatId, int nValue, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit)
{
    D2StatStrc* pStat = sub_00624C60_FindStat(&pStatListEx->FullStats, nLayer_StatId);
    if (!pStat)
    {
        pStat = STATLIST_InsertStatOrFail(pStatListEx->pMemPool, &pStatListEx->FullStats, nLayer_StatId);
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
        STATLIST_RemoveStat(pStatListEx->pMemPool, &pStatListEx->FullStats, pStat);
    }

    STATLIST_NotifyUnitOfStatValueChange(pItemStatCostTxtRecord, pStatListEx, pUnit, nLayer_StatId, nPreviousValue, nNewValue);
    return nNewValue;
}

// 0x00625150
static void __stdcall STATLIST_UpdateUnitStat(D2StatListExStrc* pStatListEx, int nLayer_StatId, int nNewValue, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit)
{
    D2StatStrc* pStat = sub_00624C60_FindStat(&pStatListEx->FullStats, nLayer_StatId);
    if (!pStat)
    {
        if (!nNewValue)
        {
            return;
        }
        pStat = STATLIST_InsertStatOrFail(pStatListEx->pMemPool, &pStatListEx->FullStats, nLayer_StatId);
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
        STATLIST_RemoveStat(pStatListEx->pMemPool, &pStatListEx->FullStats, pStat);
    }

    if (nPreviousValue != nNewValue)
    {
        STATLIST_NotifyUnitOfStatValueChange(pItemStatCostTxtRecord, pStatListEx, pUnit, nLayer_StatId, nPreviousValue, nNewValue);
    }
}

// 0x00625350
int __stdcall STATLIST_GetBaseStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
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

    return STATLIST_GetBaseStat(pStatList, STAT_MAKE(nStatId, nLayer), pItemStatCostTxtRecord);
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

    return STATLIST_GetBaseStat(pStatList, STAT_MAKE(nStatId, nLayer), pItemStatCostTxtRecord);
}

// 0x00625870
void __stdcall D2Common_10512(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nStatId, StatListUnitCallback pfCallback)
{
    if (!pUnit1)
    {
        return;
    }

    D2StatListExStrc* pStatListEx = pUnit1->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return;
    }

    const int nLayer_StatId = nStatId << STAT_SHIFT;
    if (STATLIST_FindModStatInsertIndex(&pStatListEx->ModStats, nLayer_StatId) != -1)
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

    D2StatListExStrc* pStatListEx = pUnit1->pStatListEx;
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

static inline int STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
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

int __stdcall STATLIST_CopyStatsOfId(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize); // 0x00626110

// 0x006261B0
int __stdcall D2COMMON_11269_CopyStats(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    return STATLIST_CopyStatsOfId(pStatListEx, nStatId, pBuffer, nBufferSize);
}

// 0x006261D0
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize)
{
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }
    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return 0;
    }
    return STATLIST_CopyStatsOfId(pStatListEx, nStatId, pBuffer, nBufferSize);
}

int __fastcall STATLIST_GetStatFromLayer(D2StatListStrc* pStatListEx, int nLayer_StatId);
int __fastcall STATLIST_UpdateStatOps(D2StatListStrc* pStatListEx, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit);

int __fastcall STATLIST_GetStatFromLayer(D2StatListStrc* pStatList, int nLayer_StatId); // 0x00626200

// 0x006266C0
int __fastcall STATLIST_UpdateStatOps(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    const int nNewValue = STATLIST_GetStatFromLayer(pStatListEx, nLayer_StatId);
    if (!pItemStatCostTxtRecord->bIsBaseOfOtherStatOp)
    {
        STATLIST_UpdateUnitStat(pStatListEx, nLayer_StatId, nNewValue, pItemStatCostTxtRecord, pUnit);
        return nNewValue;
    }

    if (!nNewValue)
    {
        STATLIST_UpdateUnitStat(pStatListEx, nLayer_StatId, nNewValue, pItemStatCostTxtRecord, pUnit);
    }

    int bUpdate = 1;
    for (int nCounter = 0; nCounter < OPSTAT_COUNT; ++nCounter)
    {
        const unsigned short nOpStat = pItemStatCostTxtRecord->wOpStat[nCounter];
        if (nOpStat == STAT_NONE)
        {
            break;
        }

        D2OpStatDataStrc* pOpStatData = &pItemStatCostTxtRecord->pOpStatData[nCounter];
        D2ItemStatCostTxt* pOpItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nOpStat);
        const int nOpStatLayer_StatId = nOpStat << STAT_SHIFT;
        const int nOpStatNewValue = STATLIST_UpdateStatOps(pStatListEx, nOpStatLayer_StatId, pOpItemStatCostTxtRecord, pUnit);
        STATLIST_UpdateUnitStat(pStatListEx, nOpStatLayer_StatId, nOpStatNewValue, pOpItemStatCostTxtRecord, pUnit);
        if (!nOpStatNewValue)
        {
            continue;
        }

        switch (pItemStatCostTxtRecord->nOp)
        {
        case 2:
        case 3:
            if (pStatListEx->dwOwnerType == UNIT_PLAYER || pStatListEx->dwOwnerType == UNIT_MONSTER)
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE && sub_00624F60_GetTotalStat(pStatListEx, nOpBase << STAT_SHIFT, 0) > 0)
                {
                    bUpdate = 0;
                }
            }
            break;

        case 4:
        case 5:
            if (pStatListEx->pUnit && (pStatListEx->pUnit->dwUnitType == UNIT_PLAYER || pStatListEx->pUnit->dwUnitType == UNIT_MONSTER))
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE && STATLIST_UnitGetStatValue(pStatListEx->pUnit, nOpBase, 0) > 0)
                {
                    bUpdate = 0;
                }
            }
            break;

        case 6:
        case 7:
            if (pStatListEx->dwOwnerType == UNIT_PLAYER || pStatListEx->dwOwnerType == UNIT_MONSTER)
            {
                bUpdate = 0;
            }
            break;

        case 13:
            if (pStatListEx->dwOwnerType == UNIT_ITEM)
            {
                bUpdate = 0;
            }
            break;

        case 0:
        case 8:
        case 9:
        case 10:
        case 11:
            break;

        default:
            bUpdate = 0;
            break;
        }
    }

    if (bUpdate && nNewValue)
    {
        STATLIST_UpdateUnitStat(pStatListEx, nLayer_StatId, nNewValue, pItemStatCostTxtRecord, pUnit);

        for (int i = 0; i < AFFECTED_COUNT; ++i)
        {
            const unsigned short nStatId = pItemStatCostTxtRecord->wStatsAffected[i];
            if (nStatId == STAT_NONE)
            {
                break;
            }

            D2ItemStatCostTxt* pAffectedRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
            const int nAffectedLayer_StatId = nStatId << STAT_SHIFT;
            const int nAffectedNewValue = STATLIST_UpdateStatOps(pStatListEx, nAffectedLayer_StatId, pAffectedRecord, pUnit);
            STATLIST_UpdateUnitStat(pStatListEx, nAffectedLayer_StatId, nAffectedNewValue, pAffectedRecord, pUnit);
        }
    }

    return nNewValue;
}

// 0x00626920
void __fastcall STATLIST_UpdateStatValue(D2StatListStrc* pStatList, int nLayer_StatId, int nValue, D2UnitStrc* pUnit)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    if (!nValue)
    {
        return;
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(STAT_GETID(nLayer_StatId));
    if (!pItemStatCostTxtRecord || (pStatListEx->dwFlags & STATLIST_SET))
    {
        return;
    }

    const unsigned int bDamageRelated = ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_DAMAGERELATED);
    D2StatListExStrc* pParent = (pStatListEx->dwFlags & STATLIST_EXTENDED) ? pStatListEx : pStatListEx->pParent;
    while (pParent)
    {
        if (pItemStatCostTxtRecord->bIsBaseOfOtherStatOp || pItemStatCostTxtRecord->bHasOpStatData)
        {
            STATLIST_UpdateStatOps(pParent, nLayer_StatId, pItemStatCostTxtRecord, pUnit);
        }
        else
        {
            STATLIST_AddFullStatValue(pParent, nLayer_StatId, nValue, pItemStatCostTxtRecord, pUnit);
        }

        D2StatListStrc* pCurrent = pParent;
        pParent = pParent->pParent;
        if ((pCurrent->dwFlags & STATLIST_SET) || (bDamageRelated && (pCurrent->dwFlags & STATLIST_DYNAMIC)))
        {
            break;
        }
    }
}

// 0x00627030
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer)
{
    if (!pStatList || !nValue)
    {
        return;
    }

    const int nLayer_StatId = STAT_MAKE(nStatId, nLayer);
    D2StatStrc* pStat = sub_00624C60_FindStat(&pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        pStat = STATLIST_InsertStatOrFail(pStatList->pMemPool, &pStatList->Stats, nLayer_StatId);
    }

    pStat->nValue += nValue;
    if (!pStat->nValue)
    {
        STATLIST_RemoveStat(pStatList->pMemPool, &pStatList->Stats, pStat);
    }

    STATLIST_UpdateStatValue(pStatList, nLayer_StatId, nValue, 0);
    if ((pStatList->dwFlags & STATLIST_EXTENDED) && pStatList->dwOwnerType == UNIT_PLAYER)
    {
        STATLIST_InsertStatModOrFail((D2StatListExStrc*)pStatList, nLayer_StatId);
    }
}

// 0x006270B0
int __stdcall STATLIST_SetStatValue(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer)
{
    if (!pStatList)
    {
        return 0;
    }

    const int nLayer_StatId = STAT_MAKE(nStatId, nLayer);
    D2StatStrc* pStat = sub_00624C60_FindStat(&pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        if (!nValue)
        {
            return 0;
        }
        pStat = STATLIST_InsertStatOrFail(pStatList->pMemPool, &pStatList->Stats, nLayer_StatId);
    }

    const int nDiffValue = nValue - pStat->nValue;
    if (!nDiffValue)
    {
        return 0;
    }

    if (!nValue)
    {
        STATLIST_RemoveStat(pStatList->pMemPool, &pStatList->Stats, pStat);
    }
    else
    {
        pStat->nValue = nValue;
    }

    STATLIST_UpdateStatValue(pStatList, nLayer_StatId, nDiffValue, 0);
    if ((pStatList->dwFlags & STATLIST_EXTENDED) && pStatList->dwOwnerType == UNIT_PLAYER)
    {
        STATLIST_InsertStatModOrFail((D2StatListExStrc*)pStatList, nLayer_StatId);
    }
    return 1;
}

// 0x00627170
int __stdcall STATLIST_SetBaseStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer, D2UnitStrc* pUnit)
{
    if (!pStatList)
    {
        return 0;
    }

    const int nLayer_StatId = STAT_MAKE(nStatId, nLayer);
    D2StatStrc* pStat = sub_00624C60_FindStat(&pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        if (!nValue)
        {
            return 0;
        }
        pStat = STATLIST_InsertStatOrFail(pStatList->pMemPool, &pStatList->Stats, nLayer_StatId);
    }

    const int nDiffValue = nValue - pStat->nValue;
    if (!nDiffValue)
    {
        return 0;
    }

    if (!nValue)
    {
        STATLIST_RemoveStat(pStatList->pMemPool, &pStatList->Stats, pStat);
    }
    else
    {
        pStat->nValue = nValue;
    }

    STATLIST_UpdateStatValue(pStatList, nLayer_StatId, nDiffValue, pUnit);
    if ((pStatList->dwFlags & STATLIST_EXTENDED) && pStatList->dwOwnerType == UNIT_PLAYER)
    {
        STATLIST_InsertStatModOrFail((D2StatListExStrc*)pStatList, nLayer_StatId);
    }
    return 1;
}

// 0x00627260
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer)
{
    if (STATLIST_SetStatValue(pUnit->pStatListEx, nStatId, nValue, nLayer) && pUnit->dwUnitType == UNIT_PLAYER)
    {
        STATLIST_InsertStatModOrFail(pUnit->pStatListEx, STAT_MAKE(nStatId, nLayer));
    }
}

static inline const D2StatStrc* STATLIST_GetFirstStat_Inline(const D2StatsArrayStrc* pStats)
{
    return pStats->pStat;
}

// 0x00627340
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList)
{
    if (!pStatList)
    {
        return;
    }

    while (pStatList->Stats.nStatCount > 0)
    {
        STATLIST_SetStatValue(pStatList, (!pStatList ? 0 : pStatList->Stats.pStat)->nStat, 0, (!pStatList ? 0 : pStatList->Stats.pStat)->nLayer);
    }
}

// 0x006276C0
void __stdcall D2Common_10525(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    if (!pUnit1 || !pUnit2 || !(pUnit1->dwUnitType == UNIT_PLAYER || pUnit1->dwUnitType == UNIT_MONSTER))
    {
        return;
    }

    D2StatListExStrc* pStatListEx2 = pUnit2->pStatListEx;
    if (!pStatListEx2 || !(pStatListEx2->dwFlags & STATLIST_EXTENDED))
    {
        return;
    }

    for (D2StatStrc* j = pStatListEx2->FullStats.pStat, *pEnd = &pStatListEx2->FullStats.pStat[pStatListEx2->FullStats.nStatCount]; j < pEnd; ++j)
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(j->nStat);
        switch (pItemStatCostTxtRecord->nOp)
        {
        case 6:
        case 7:
            for (int i = 0; i < OPSTAT_COUNT; ++i)
            {
                const unsigned short nOpStat = pItemStatCostTxtRecord->wOpStat[i];
                if (nOpStat == STAT_NONE)
                {
                    break;
                }

                D2ItemStatCostTxt* pOpItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nOpStat);
                const int nOpLayer_StatId = nOpStat << STAT_SHIFT;
                const int nOpStatValue = STATLIST_GetStatFromLayer(pUnit1->pStatListEx, nOpLayer_StatId);
                STATLIST_UpdateUnitStat(pUnit1->pStatListEx, nOpLayer_StatId, nOpStatValue, pOpItemStatCostTxtRecord, pUnit1);
            }
            break;
        }
    }
}
