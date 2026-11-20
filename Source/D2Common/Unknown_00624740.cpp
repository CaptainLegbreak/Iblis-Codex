#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2Win32Types.h"

struct D2StatStrc;
struct D2StatsArrayStrc;
struct D2ItemStatCostTxt;
struct D2StatesTxt;

typedef unsigned int size_t;

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40

extern D2DataTablesStrc* sgptDataTables;
extern unsigned int gdwBitMasks[];
extern unsigned int gdwInvBitMasks[];
D2StatesTxt* __fastcall DATATBLS_GetStatesTxtRecord(int nStateId);
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);

// 0x00624740
void __stdcall sub_00624740_FormatLocalTime(char* szBuffer, size_t nSize)
{
    D2SystemTimeStrc tTime;
    GetLocalTime(&tTime);
    SStrPrintf(szBuffer, nSize, "%02u:%02u:%02u.%03u\t", tTime.wHour, tTime.wMinute, tTime.wSecond, tTime.wMilliseconds);
}

static __forceinline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
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
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    D2StatStrc* pStat = sub_00624C60_FindStat((pStatList->dwFlags & STATLIST_EXTENDED) ? &pStatListEx->FullStats : &pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        return 0;
    }

    int nValue = pStat->nValue;
    if (pItemStatCostTxtRecord && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FMIN) && (pStatList->dwFlags & STATLIST_EXTENDED)
        && pStatListEx->pOwner && (UNITS_IsType(pStatListEx->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatListEx->pOwner, UNIT_MONSTER)))
    {
        if (nValue < pItemStatCostTxtRecord->dwMinAccr)
        {
            nValue = pItemStatCostTxtRecord->dwMinAccr << pItemStatCostTxtRecord->nValShift;
        }
    }
    return nValue;
}

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

void __stdcall sub_00625A70_ToggleState(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (pUnit)
    {
        D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
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
