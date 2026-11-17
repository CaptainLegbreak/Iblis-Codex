#include "D2Client.h"

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2ItemStatCostTxt
{
    unsigned short wStatId;
    unsigned short pad0x02;
    unsigned char nItemStatFlags[4];
    char unk0x08[0x13C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    int unk0xBD0;
    int nItemStatCostTxtRecordCount;
};

#define STAT_UNIT_MODE 172
#define ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE 9

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
void __fastcall sub_00463C00_OnModeChange(D2UnitStrc* pUnit, unsigned char nOldMode, int nNewMode);        // 0x00463C00
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, int nLayer);                    // 0x00625D00
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

inline D2ItemStatCostTxt* DATATBLS_GetItemStatCostTxtRecordInline(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }

    return 0;
}

// 0x004D9D70
D2StatListStrc* __fastcall sub_004D9D70_SetStateStat(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nState, int nStatId, int nValue, int nLayer)
{
    if (!pUnit)
    {
        return 0;
    }

    int nOldValue = 0;
    if (nStatId == STAT_UNIT_MODE)
    {
        nOldValue = 4;
    }

    if (!pStatList)
    {
        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(pStatList, (unsigned int)pStatList, (unsigned int)pStatList, (!pUnit ? 6 : pUnit->dwUnitType), (!pUnit ? -1 : pUnit->dwUnitId));
            STATLIST_SetState(pStatList, nState);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }
        else
        {
            nOldValue = STATLIST_GetStatValue(pStatList, nStatId, nLayer);
        }
    }

    STATLIST_SetStat(pStatList, nStatId, nValue, nLayer);

    if (nStatId == STAT_UNIT_MODE)
    {
        sub_00463C00_OnModeChange(pUnit, nOldValue, nValue);
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = DATATBLS_GetItemStatCostTxtRecordInline(nStatId);
    if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE & 7])
    {
        UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNIT\\PlrSkills.cpp", 1490);
    }

    return pStatList;
}
