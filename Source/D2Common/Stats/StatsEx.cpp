#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#define STATLIST_SET 0x2000

struct D2GameStrc;
struct D2DrlgActStrc;
struct D2StatStrc;
struct D2StatsArrayStrc;
struct D2ModStatsArrayStrc;
struct D2OpStatDataStrc;
struct D2ItemStatCostTxt;
struct D2CharStatsTxt;
struct Obj00625250;
struct Obj006252B0;
struct Obj006252D0;
struct Obj006252F0;
struct Obj00625330;
struct D2ItemCalcStrc;
struct Obj00625CE0;
struct Obj00626090;
struct Obj006260B0;
struct D2StatListStrc;
struct D2UnitStrc;
struct D2DataTablesStrc;





typedef void (__fastcall* StatListUnitCallback)(D2UnitStrc* pUnit1, int nStatId, int nValue, D2UnitStrc* pUnit2);








extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId); // 0x0045C4F0
extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax); // 0x0065CA30
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
static __forceinline int STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625420
int __fastcall sub_00626200_GetStatFromLayer(D2StatListStrc* pStatListEx, int nLayer_StatId);
int __fastcall sub_006266C0_UpdateStatOps(D2StatListStrc* pStatListEx, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit);

struct Obj00625250 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned int dwValue08; };

struct Obj006252B0 { unsigned char bUnknown00[0x0C]; unsigned int dwValue0C; };

struct Obj006252D0 { unsigned char bUnknown00[0x14]; unsigned int dwValue14; };

struct Obj006252F0 { unsigned char bUnknown00[0x14]; unsigned int dwValue14; };

struct Obj00625330 { unsigned char bUnknown00[0x18]; unsigned int dwValue18; };

int __stdcall sub_006255A0_GetStatValueWithPercent(D2StatListStrc* pStatList, int nStatId, int nPercentStatId, int bAddBonus); // 0x006255A0
D2StatListStrc* __stdcall sub_006256E0_StatListFindByFlags(D2StatListStrc* pStatList, int nFlag); // 0x006256E0

struct D2ItemCalcStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pItem;
};

extern void* gpItemsCalcFunctions[]; // 0x0074463C
extern int gnItemsCalcFunctions; // 0x0074465C
int __fastcall ITEMMODS_GetCalcParamValue_Return0(int nParam, void* pUserData); // 0x00627B40

struct Obj00625CE0 { unsigned char bUnknown00[0x38]; unsigned int dwValue38; };

int __stdcall sub_00625350(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625350

struct Obj00626090 { unsigned char bUnknown00[0x18]; unsigned int dwValue18; };

struct Obj006260B0 { unsigned char bUnknown00[0x10]; unsigned int dwFlags10; unsigned int dwUnknown14; int nValue18; };

void __fastcall D2Common_STATLIST_FreeStatListImpl_6FDB7050(D2StatListStrc* pStatList); // 0x00626C00
static int __stdcall sub_00626110_CopyStats(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize);
extern "C" const char gszStatListSourceFile[];
void __fastcall sub_00626920_UpdateStatValue(D2StatListStrc* pStatListEx, int nLayer_StatId, int nValue, D2UnitStrc* pUnit); // 0x00626920

static int __stdcall sub_00624ED0_GetBaseStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord);
static int __stdcall sub_00624F60_GetTotalStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord);

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
static void __stdcall sub_00624DD0_InsertStatModOrFail(D2StatListExStrc* pStatListEx, int nLayer_StatId)
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

// 0x00624FE0
static int __stdcall sub_00624FE0_GetStatWithChildLists(D2StatListExStrc* pStatListEx, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord)
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

static __forceinline void STATLIST_NotifyUnitOfStatValueChange(D2ItemStatCostTxt* pItemStatCostTxtRecord, D2StatListExStrc* pStatListEx, D2UnitStrc* pUnit, int nLayer_StatId, int nPreviousValue, int nNewValue)
{
    if (pStatListEx->pfOnValueChanged && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FCALLBACK))
    {
        pStatListEx->pfOnValueChanged(pStatListEx->pGame, pStatListEx->pOwner, pUnit, nLayer_StatId, nPreviousValue, nNewValue);
    }
}

// 0x006250B0
static int __stdcall sub_006250B0_AddFullStatValue(D2StatListExStrc* pStatListEx, int nLayer_StatId, int nValue, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit)
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
static void __stdcall sub_00625150_UpdateUnitStat(D2StatListExStrc* pStatListEx, int nLayer_StatId, int nNewValue, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit)
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

// 0x00625250
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00625250(Obj00625250* pObj) {
    if (!pObj) {
        return 6;
    }
    return pObj->dwValue08;
}

// 0x006252B0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006252B0(Obj006252B0* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue0C;
}

// 0x006252D0
extern "C" __declspec(dllexport) void __stdcall sub_006252D0(Obj006252D0* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwValue14 = dwValue;
    }
}

// 0x006252F0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006252F0(Obj006252F0* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue14;
}

// 0x00625330
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00625330(Obj00625330* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue18;
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

// 0x00625600
int __stdcall sub_00625600_UnitGetStatValueWithPercent(D2UnitStrc* pUnit, int nStatId, int nPercentStatId, int bAddBonus)
{
    return sub_006255A0_GetStatValueWithPercent(pUnit->pStatListEx, nStatId, nPercentStatId, bAddBonus);
}

// 0x00625650
D2StatListStrc* __stdcall D2Common_GetStateFromStatListEx_6FDB8190(D2StatListStrc* pStatList, int nStateId)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    if (!pStatListEx)
    {
        return 0;
    }

    if (!nStateId)
    {
        return 0;
    }

    D2StatListStrc* pState = (pStatListEx->dwFlags & 0x80000000) ? pStatListEx->pMyLastList : 0;
    while (pState && pState->dwStateNo != nStateId)
    {
        pState = pState->pPrevLink;
    }

    if (pState)
    {
        return pState;
    }

    pState = (pStatListEx->dwFlags & 0x80000000) ? pStatListEx->pMyStats : 0;
    while (pState)
    {
        if (pState->dwStateNo == nStateId)
        {
            return pState;
        }
        pState = pState->pPrevLink;
    }

    return 0;
}

// 0x00625760
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag)
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

    return sub_006256E0_StatListFindByFlags(pStatListEx, nFlag);
}

// 0x00625820
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic)
{
    if (!pUnit)
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    D2StatListExStrc* pParent = pStatListEx->pParent;
    if (!pParent)
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    if (!(pParent->dwFlags & STATLIST_EXTENDED))
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    if (pStatNotDynamic)
        *pStatNotDynamic = !(pStatListEx->dwFlags & STATLIST_DYNAMIC);

    return pParent->pOwner;
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

// 0x00625B70
int __stdcall sub_00625B70_CheckStatFlag(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit)
        return 0;

    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return pStatListEx->StatFlags[nState >> 5] & gdwBitMasks[nState & 31];
}

// 0x00625BB0
unsigned int* __stdcall D2COMMON_STATES_GetStatFlags_6FDB8A90(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;

    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return pStatListEx->StatFlags;
}

// 0x00625BE0
unsigned int* __stdcall D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;

    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return &pStatListEx->StatFlags[(sgptDataTables->nStatesTxtRecordCount + 31) / 32];
}

#include "gen/data/Source/D2Common/Stats/StatsEx.inc"

// 0x00625C30
int __stdcall STATLIST_GetFullStatsDataFromUnit(D2UnitStrc* pUnit, D2StatStrc* pOutStatBuffer, int nBufferSize)
{
    if (!pUnit)
    {
        return 0;
    }
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }
    if (!(pStatListEx->dwFlags & 0x80000000))
    {
        return 0;
    }
    int nStatCount = pStatListEx->FullStats.nStatCount;
    if (nStatCount >= nBufferSize)
    {
        nStatCount = nBufferSize;
    }
    D2StatStrc* pStat = pStatListEx->FullStats.pStat;
    D2StatStrc* pEnd = &pStat[nStatCount];
    for (; pStat < pEnd; ++pStat)
    {
        *pOutStatBuffer = *pStat;
        ++pOutStatBuffer;
    }
    return nStatCount;
}

// 0x00625CE0
extern "C" __declspec(dllexport) void __stdcall sub_00625CE0(Obj00625CE0* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwValue38 = dwValue;
    }
}

// 0x00625D00
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    return sub_00625350(pStatList, nStatId, nLayer);
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

// 0x00625E60
int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pUnit, int b2Handed)
{
    if (b2Handed)
    {
        if (!pUnit)
        {
            return 0;
        }

        D2StatListStrc* pStatList = pUnit->pStatListEx;
        D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
        if (pStatList)
        {
            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(24);
        }

        if (!pItemStatCostTxtRecord)
        {
            return 0;
        }

        return sub_00624F60_GetTotalStat(pStatList, STAT_MAKE(24, 0), pItemStatCostTxtRecord);
    }

    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(22);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return sub_00624F60_GetTotalStat(pStatList, STAT_MAKE(22, 0), pItemStatCostTxtRecord);
}

// 0x00625F80
int __stdcall STATLIST_GetMaxThrowDamageFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(160);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return sub_00624F60_GetTotalStat(pStatList, STAT_MAKE(160, 0), pItemStatCostTxtRecord);
}

// 0x00626090
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00626090(Obj00626090* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue18;
}

// 0x006260B0
extern "C" __declspec(dllexport) void __stdcall sub_006260B0(Obj006260B0* pObj, int nValue) {
    if (pObj) {
        if (nValue > 0) {
            pObj->dwFlags10 |= 2;
        }
        pObj->nValue18 = nValue;
    }
}

// 0x00626110
static int __stdcall sub_00626110_CopyStats(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    if (!pStatList)
    {
        return 0;
    }

    D2StatsArrayStrc* pStatsArray = (pStatList->dwFlags & STATLIST_EXTENDED) ? &pStatListEx->FullStats : &pStatList->Stats;
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
int __stdcall D2COMMON_11269_CopyStats(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    return sub_00626110_CopyStats(pStatListEx, nStatId, pBuffer, nBufferSize);
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
    return sub_00626110_CopyStats(pStatListEx, nStatId, pBuffer, nBufferSize);
}

// 0x00626200
int __fastcall sub_00626200_GetStatFromLayer(D2StatListStrc* pStatList, int nLayer_StatId)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
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

// 0x006266C0
int __fastcall sub_006266C0_UpdateStatOps(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    const int nNewValue = sub_00626200_GetStatFromLayer(pStatListEx, nLayer_StatId);
    if (!pItemStatCostTxtRecord->bIsBaseOfOtherStatOp)
    {
        sub_00625150_UpdateUnitStat(pStatListEx, nLayer_StatId, nNewValue, pItemStatCostTxtRecord, pUnit);
        return nNewValue;
    }

    if (!nNewValue)
    {
        sub_00625150_UpdateUnitStat(pStatListEx, nLayer_StatId, nNewValue, pItemStatCostTxtRecord, pUnit);
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
        const int nOpStatNewValue = sub_006266C0_UpdateStatOps(pStatListEx, nOpStatLayer_StatId, pOpItemStatCostTxtRecord, pUnit);
        sub_00625150_UpdateUnitStat(pStatListEx, nOpStatLayer_StatId, nOpStatNewValue, pOpItemStatCostTxtRecord, pUnit);
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
        sub_00625150_UpdateUnitStat(pStatListEx, nLayer_StatId, nNewValue, pItemStatCostTxtRecord, pUnit);

        for (int i = 0; i < AFFECTED_COUNT; ++i)
        {
            const unsigned short nStatId = pItemStatCostTxtRecord->wStatsAffected[i];
            if (nStatId == STAT_NONE)
            {
                break;
            }

            D2ItemStatCostTxt* pAffectedRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
            const int nAffectedLayer_StatId = nStatId << STAT_SHIFT;
            const int nAffectedNewValue = sub_006266C0_UpdateStatOps(pStatListEx, nAffectedLayer_StatId, pAffectedRecord, pUnit);
            sub_00625150_UpdateUnitStat(pStatListEx, nAffectedLayer_StatId, nAffectedNewValue, pAffectedRecord, pUnit);
        }
    }

    return nNewValue;
}

// 0x00626920
void __fastcall sub_00626920_UpdateStatValue(D2StatListStrc* pStatList, int nLayer_StatId, int nValue, D2UnitStrc* pUnit)
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
            sub_006266C0_UpdateStatOps(pParent, nLayer_StatId, pItemStatCostTxtRecord, pUnit);
        }
        else
        {
            sub_006250B0_AddFullStatValue(pParent, nLayer_StatId, nValue, pItemStatCostTxtRecord, pUnit);
        }

        D2StatListStrc* pCurrent = pParent;
        pParent = pParent->pParent;
        if ((pCurrent->dwFlags & STATLIST_SET) || (bDamageRelated && (pCurrent->dwFlags & STATLIST_DYNAMIC)))
        {
            break;
        }
    }
}

// 0x006269F0
void __stdcall D2Common_ExpireStatList_6FDB6E30(D2StatListStrc* pStatList)
{
    int anStats[16];

    if (!pStatList)
    {
        return;
    }

    D2StatListExStrc* pParent = pStatList->pParent;
    if (pParent)
    {
        if (pParent->dwFlags & 0x80000000)
        {
            if (pParent->pMyLastList == pStatList)
            {
                pParent->pMyLastList = pStatList->pPrevLink;
            }
            if (pParent->pMyStats == pStatList)
            {
                pParent->pMyStats = pStatList->pPrevLink;
            }
        }
        pStatList->pParent = 0;
    }

    if (pStatList->pNextLink)
    {
        pStatList->pNextLink->pPrevLink = pStatList->pPrevLink;
    }
    if (pStatList->pPrevLink)
    {
        pStatList->pPrevLink->pNextLink = pStatList->pNextLink;
    }

    pStatList->pPrevLink = 0;
    pStatList->pNextLink = 0;
    D2UnitStrc* pUnit = pStatList->pUnit;
    pStatList->pUnit = 0;

    if (pStatList->dwFlags & 0x2000)
    {
        return;
    }

    D2UnitStrc* pOwner = 0;
    if (pStatList->dwFlags & 0x80000000)
    {
        pOwner = ((D2StatListExStrc*)pStatList)->pOwner;
    }

    if ((pStatList->dwFlags & 0x80000000) && (pStatList->dwFlags & 0x20000000))
    {
        int nCount = 0;
        D2StatStrc* pStat = ((D2StatListExStrc*)pStatList)->FullStats.pStat;
        D2StatStrc* pStatEnd = &pStat[((D2StatListExStrc*)pStatList)->FullStats.nStatCount];
        for (; pStat < pStatEnd; ++pStat)
        {
            D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(STAT_GETID(pStat->nPackedValue));
            if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->bHasOpApplyingToItem)
            {
                anStats[nCount] = pStat->nPackedValue;
                ++nCount;
            }
        }

        for (int i = 0; i < nCount; ++i)
        {
            D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord((anStats[i] >> 16) & 0xFFFF);
            if (pItemStatCostTxtRecord)
            {
                sub_006266C0_UpdateStatOps(pStatList, anStats[i], pItemStatCostTxtRecord, 0);
            }
        }
    }

    if (pParent)
    {
        int bDamage = pStatList->dwFlags & 0x40000000;
        D2StatsArrayStrc* pStatsArray = (pStatList->dwFlags & 0x80000000) ? &((D2StatListExStrc*)pStatList)->FullStats : &pStatList->Stats;
        D2StatStrc* pStat = pStatsArray->pStat;
        D2StatStrc* pEnd = &pStat[pStatsArray->nStatCount];

        if (bDamage)
        {
            for (; pStat < pEnd; ++pStat)
            {
                D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(STAT_GETID(pStat->nPackedValue));
                if (pItemStatCostTxtRecord && !(pItemStatCostTxtRecord->nItemStatFlags[0] & gdwBitMasks[2]))
                {
                    sub_00626920_UpdateStatValue(pParent, pStat->nPackedValue, -pStat->nValue, pOwner);
                }
            }
        }
        else
        {
            for (; pStat < pEnd; ++pStat)
            {
                sub_00626920_UpdateStatValue(pParent, pStat->nPackedValue, -pStat->nValue, pOwner);
            }
        }
    }

    if (pUnit && pStatList->fpStatRemove)
    {
        pStatList->fpStatRemove(pUnit, pStatList->dwStateNo, pStatList);
    }
}

inline int STATLIST_IsExtended(D2StatListStrc* pStatList)
{
    return pStatList->dwFlags & STATLIST_EXTENDED;
}

// 0x00626CF0
void __fastcall sub_00626CF0_FreeExtendedStatList(D2StatListStrc* pStatList)
{
    if (pStatList && STATLIST_IsExtended(pStatList))
    {
        D2Common_STATLIST_FreeStatListImpl_6FDB7050(pStatList);
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
        pStat = sub_00624C80_InsertStatOrFail(pStatList->pMemPool, &pStatList->Stats, nLayer_StatId);
    }

    pStat->nValue += nValue;
    if (!pStat->nValue)
    {
        sub_00624D10_RemoveStat(pStatList->pMemPool, &pStatList->Stats, pStat);
    }

    sub_00626920_UpdateStatValue(pStatList, nLayer_StatId, nValue, 0);
    if ((pStatList->dwFlags & STATLIST_EXTENDED) && pStatList->dwOwnerType == UNIT_PLAYER)
    {
        sub_00624DD0_InsertStatModOrFail((D2StatListExStrc*)pStatList, nLayer_StatId);
    }
}

// 0x006270B0
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer)
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
        pStat = sub_00624C80_InsertStatOrFail(pStatList->pMemPool, &pStatList->Stats, nLayer_StatId);
    }

    const int nDiffValue = nValue - pStat->nValue;
    if (!nDiffValue)
    {
        return 0;
    }

    if (!nValue)
    {
        sub_00624D10_RemoveStat(pStatList->pMemPool, &pStatList->Stats, pStat);
    }
    else
    {
        pStat->nValue = nValue;
    }

    sub_00626920_UpdateStatValue(pStatList, nLayer_StatId, nDiffValue, 0);
    if ((pStatList->dwFlags & STATLIST_EXTENDED) && pStatList->dwOwnerType == UNIT_PLAYER)
    {
        sub_00624DD0_InsertStatModOrFail((D2StatListExStrc*)pStatList, nLayer_StatId);
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
        pStat = sub_00624C80_InsertStatOrFail(pStatList->pMemPool, &pStatList->Stats, nLayer_StatId);
    }

    const int nDiffValue = nValue - pStat->nValue;
    if (!nDiffValue)
    {
        return 0;
    }

    if (!nValue)
    {
        sub_00624D10_RemoveStat(pStatList->pMemPool, &pStatList->Stats, pStat);
    }
    else
    {
        pStat->nValue = nValue;
    }

    sub_00626920_UpdateStatValue(pStatList, nLayer_StatId, nDiffValue, pUnit);
    if ((pStatList->dwFlags & STATLIST_EXTENDED) && pStatList->dwOwnerType == UNIT_PLAYER)
    {
        sub_00624DD0_InsertStatModOrFail((D2StatListExStrc*)pStatList, nLayer_StatId);
    }
    return 1;
}

// 0x00627260
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer)
{
    if (sub_006270B0(pUnit->pStatListEx, nStatId, nValue, nLayer) && pUnit->dwUnitType == UNIT_PLAYER)
    {
        sub_00624DD0_InsertStatModOrFail(pUnit->pStatListEx, STAT_MAKE(nStatId, nLayer));
    }
}

// build: context STATLIST_RemoveAllStats
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList)
{
    if (!pStatList)
    {
        return;
    }

    while (pStatList->Stats.nStatCount > 0)
    {
        sub_006270B0(pStatList, pStatList->Stats.pStat->nStat, 0, pStatList->Stats.pStat->nLayer);
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
                const int nOpStatValue = sub_00626200_GetStatFromLayer(pUnit1->pStatListEx, nOpLayer_StatId);
                sub_00625150_UpdateUnitStat(pUnit1->pStatListEx, nOpLayer_StatId, nOpStatValue, pOpItemStatCostTxtRecord, pUnit1);
            }
            break;
        }
    }
}

// 0x00627830
int __stdcall sub_00627830_GetStatAccumulated(D2UnitStrc* pUnit, int nStatId)
{
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return sub_00626200_GetStatFromLayer(pStatListEx, nStatId << 16);
}

// 0x00627C20
int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc)
{
    if (!sgptDataTables->pItemsCode)
        return 0;

    if (nCalc >= sgptDataTables->nItemsCodeSize)
        return 0;

    D2ItemCalcStrc pItemCalc;
    pItemCalc.pUnit = pUnit;
    pItemCalc.pItem = pItem;
    return DATATBLS_CalcEvaluateExpression(&sgptDataTables->pItemsCode[nCalc], sgptDataTables->nItemsCodeSize - nCalc, ITEMMODS_GetCalcParamValue_Return0, gpItemsCalcFunctions, gnItemsCalcFunctions, &pItemCalc);
}
