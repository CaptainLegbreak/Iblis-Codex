#include "D2Common.h"

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2SetItemsTxt
{
    char unk0x00[0x2C];
    short nSetId;
};

struct D2DataTablesStrc
{
    char unk0x000[0xC10];
    int nSetsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gnItemSetStates_006EE424[6];                                                               // 0x006EE424

D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFlags, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);        // 0x00625D00
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                           // 0x00626CD0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList);                                         // 0x00627340
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                               // 0x006277E0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem);                                              // 0x0062A0F0
void __fastcall ITEMMODS_UpdateFullSetBoni(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState);               // 0x00660120

// 0x00663B40
int __fastcall sub_00663B40_SetBonusStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3)
{
    if (a3 > 1)
    {
        return 0;
    }

    if (!pUnit || !pItem || (!pItem ? 6 : pItem->dwUnitType) != 4 || ITEMS_GetItemQuality(pItem) != 5)
    {
        return 0;
    }

    if ((!pUnit ? 6 : pUnit->dwUnitType) == 4 && ITEMS_IsMagSetRarUniCrfOrTmp(pUnit))
    {
        return 0;
    }

    D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
    if (!pSetItemsTxtRecord)
    {
        return 0;
    }

    const int nValue = pSetItemsTxtRecord->nSetId;
    if (nValue < 0 || nValue >= sgptDataTables->nSetsTxtRecordCount)
    {
        return 0;
    }

    int nIndex = -1;
    D2StatListStrc* pStatList;
    int nState;
    int i = 0;
    for (;;)
    {
        if (!(i < 6))
            break;
        nState = gnItemSetStates_006EE424[i];
        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList)
        {
            if (nValue == STATLIST_GetStatValue(pStatList, 71, 0))
            {
                if (a3 == 0)
                {
                    STATLIST_RemoveAllStats(pStatList);
                }
                goto update;
            }
        }
        else if (nIndex < 0)
        {
            nIndex = i;
        }
        ++i;
    }

    if (a3 == 1)
    {
        return 0;
    }
    if (nIndex < 0)
    {
        return 0;
    }

    nState = gnItemSetStates_006EE424[nIndex];
    int const nItemId = pItem->dwUnitId;
    void* const pPool = pUnit->pMemoryPool;
    pStatList = STATLIST_AllocStatList(pPool, 0, 0, !pItem ? 6 : pItem->dwUnitType, nItemId);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    STATLIST_SetState(pStatList, nState);

update:
    switch (a3)
    {
    case 0:
        STATLIST_AddStat(pStatList, 71, nValue, 0);
        ITEMMODS_UpdateFullSetBoni(pUnit, pItem, nState);
        break;

    case 1:
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
        break;
    }

    return 1;
}
