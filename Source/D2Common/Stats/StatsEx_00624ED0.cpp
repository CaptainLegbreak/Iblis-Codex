#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
struct D2GameStrc;
struct D2DrlgActStrc;
struct D2SkillListStrc;
struct D2PlayerDataStrc;
struct D2StatStrc;
struct D2StatsArrayStrc;
struct D2ModStatsArrayStrc;
struct D2OpStatDataStrc;
struct D2ItemStatCostTxt;





typedef void (__fastcall* StatListUnitCallback)(D2UnitStrc* pUnit1, int nStatId, int nValue, D2UnitStrc* pUnit2);






extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall D2Common_STATLIST_FreeStatListImpl_6FDB7050(D2StatListStrc* pStatList); // 0x00626C00
void __stdcall D2Common_ExpireStatList_6FDB6E30(D2StatListStrc* pStatList); // 0x006269F0
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627030
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x006270B0

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

// 0x00624ED0
static int __stdcall sub_00624ED0_GetBaseStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    D2StatStrc* pStat = sub_00624C60_FindStat(&pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        return 0;
    }

    int nValue = pStat->nValue;
    if (pItemStatCostTxtRecord && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FMIN) && (pStatList->dwFlags & STATLIST_EXTENDED)
        && (UNITS_IsType(pStatListEx->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatListEx->pOwner, UNIT_MONSTER)))
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
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    D2StatStrc* pStat = sub_00624C60_FindStat((pStatList->dwFlags & STATLIST_EXTENDED) ? &pStatListEx->FullStats : &pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        return 0;
    }

    int nValue = pStat->nValue;
    if (pItemStatCostTxtRecord && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FMIN) && (pStatList->dwFlags & STATLIST_EXTENDED)
        && (UNITS_IsType(pStatListEx->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatListEx->pOwner, UNIT_MONSTER)))
    {
        if (nValue < pItemStatCostTxtRecord->dwMinAccr)
        {
            nValue = pItemStatCostTxtRecord->dwMinAccr << pItemStatCostTxtRecord->nValShift;
        }
    }
    return nValue;
}

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
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

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit)
{
    if (!STATLIST_GetUnitBaseStat(pUnit, STAT_MAXDURABILITY, 0))
    {
        return 0;
    }
    return STATLIST_GetTotalStatValue(pUnit->pStatListEx, STAT_MAXDURABILITY, 0);
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

inline int STATLIST_IsExtended(D2StatListStrc* pStatList)
{
    return pStatList->dwFlags & STATLIST_EXTENDED;
}

// 0x006260E0
D2SkillStrc* __stdcall sub_006260E0(D2StatListStrc* pStatList)
{
    return pStatList->pSkill;
}

// 0x00626CD0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList)
{
    if (pStatList && !STATLIST_IsExtended(pStatList))
    {
        D2Common_STATLIST_FreeStatListImpl_6FDB7050(pStatList);
    }
}

// 0x00626D10
void __stdcall STATLIST_FreeStatListEx(D2UnitStrc* pUnit)
{
    if (pUnit->pStatListEx)
    {
        if (STATLIST_IsExtended(pUnit->pStatListEx))
        {
            D2Common_STATLIST_FreeStatListImpl_6FDB7050(pUnit->pStatListEx);
        }

        pUnit->pStatListEx = 0;
    }
}

// 0x006272B0
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer)
{
    if (nValue)
    {
        STATLIST_AddStat(pUnit->pStatListEx, nStatId, nValue, nLayer);
    }
}

// 0x006277E0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList)
{
    D2Common_ExpireStatList_6FDB6E30(pStatList);
}

// 0x006277F0
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->pStatListEx)
    {
        D2Common_ExpireStatList_6FDB6E30(pUnit->pStatListEx);
    }
}

// 0x00626100
int __stdcall STATLIST_GetSkillLevel(D2StatListStrc* pStatList)
{
    return pStatList->dwSLvl;
}

// 0x00627150
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer)
{
    if (pStatList)
    {
        sub_006270B0(pStatList, nStatId, nValue, nLayer);
    }
}
