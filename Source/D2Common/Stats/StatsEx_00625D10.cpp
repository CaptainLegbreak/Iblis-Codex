#include "D2Common.h"

#define MOVED_PREFIX
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
struct D2StatStrc;
struct D2StatsArrayStrc;
struct D2ItemStatCostTxt;

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

struct D2StatListStrc
{
    char unk0x00[0x10];
    unsigned int dwFlags;
    char unk0x14[0x10];
    D2StatsArrayStrc Stats;
    char unk0x2C[0x18];
    D2UnitStrc* pOwner;
    D2StatsArrayStrc FullStats;
    char unk0x50[0x08];
    unsigned int* StatFlags;
};

struct D2UnitStrc
{
    MOVED_PREFIX
    unsigned int dwUnitType;
    char unk0x04[0x58];
    D2StatListStrc* pStatListEx;
    char unk0x60[0x68];
    unsigned int dwFlagEx;
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

struct D2DataTablesStrc
{
    MOVED_PREFIX
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xBCC - 0xC8];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0x04];
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268

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

static int __stdcall sub_00624F60_GetTotalStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord) // 0x00624F60
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

// 0x00625D10
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(7);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return sub_00624F60_GetTotalStat(pStatList, STAT_MAKE(7, 0), pItemStatCostTxtRecord);
}

// 0x00625D60
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(9);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return sub_00624F60_GetTotalStat(pStatList, STAT_MAKE(9, 0), pItemStatCostTxtRecord);
}

// 0x00625DB0
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(11);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return sub_00624F60_GetTotalStat(pStatList, STAT_MAKE(11, 0), pItemStatCostTxtRecord);
}

// 0x00626020
int __stdcall sub_00626020_ArmorValue(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(31);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return sub_00624F60_GetTotalStat(pStatList, STAT_MAKE(31, 0), pItemStatCostTxtRecord);
}
