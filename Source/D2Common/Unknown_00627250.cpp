#include "D2Common.h"
#include "D2Structs.h"
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
struct D2GameStrc;
struct D2DrlgActStrc;
struct D2StatStrc;
struct D2StatsArrayStrc;
struct D2ModStatsArrayStrc;
struct D2OpStatDataStrc;
struct D2ItemStatCostTxt;



typedef void (__fastcall* StatListValueChangeFunc)(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nLayer_StatId, int nPreviousValue, int nNewValue);


int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x006270B0
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030


typedef void (__fastcall* StatListUnitCallback)(D2UnitStrc* pUnit1, int nStatId, int nValue, D2UnitStrc* pUnit2);


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

struct D2DataTablesStrc
{
    char unk0x000[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0x04];
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0

// 0x00627250
int __stdcall sub_00627250_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer)
{
    return sub_006270B0(pStatList, nStatId, nValue, nLayer);
}

// 0x006272A0
void __stdcall sub_006272A0_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer)
{
    STATLIST_AddStat(pStatList, nStatId, nValue, nLayer);
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

// 0x006275B0
void __stdcall sub_006275B0(D2UnitStrc* pUnit)
{
    if (!pUnit || !pUnit->pStatListEx)
    {
        return;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0);
    int nMaxValue = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (nValue > nMaxValue)
    {
        const int nDiff = nMaxValue - nValue;
        if (nDiff)
        {
            STATLIST_AddStat(pStatList, STAT_STAMINA, nDiff, 0);
        }
    }

    pStatList = pUnit->pStatListEx;
    nValue = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    nMaxValue = STATLIST_GetMaxManaFromUnit(pUnit);
    if (nValue > nMaxValue)
    {
        const int nDiff = nMaxValue - nValue;
        if (nDiff)
        {
            STATLIST_AddStat(pStatList, STAT_MANA, nDiff, 0);
        }
    }

    pStatList = pUnit->pStatListEx;
    nValue = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    nMaxValue = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nValue > nMaxValue)
    {
        const int nDiff = nMaxValue - nValue;
        if (nDiff)
        {
            STATLIST_AddStat(pStatList, STAT_HITPOINTS, nDiff, 0);
        }
    }
}
