struct D2StatStrc
{
    int nLayer_StatId;
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
    char unk0x00[36];
    D2StatsArrayStrc Stats;
};
struct D2StatListExStrc
{
    char unk0x00[72];
    D2StatsArrayStrc FullStats;
};
struct D2UnitStrc
{
    char unk0x00[92];
    D2StatListExStrc* pStatListEx;
};
struct D2DataTablesStrc
{
    char unk0x00[3068];
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_SetBaseStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pUnit); // 0x00627170
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);           // 0x006270B0

// 0x00625270
int __stdcall STATLIST_GetBaseStatsCount(D2StatListStrc* pStatList)
{
    return !pStatList ? 0 : pStatList->Stats.nStatCount;
}

// 0x00625290
int __stdcall STATLIST_GetFullStatsCountFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!pUnit->pStatListEx)
    {
        return 0;
    }

    return pUnit->pStatListEx->FullStats.nStatCount;
}

// 0x00625620
int __stdcall sub_00625620(D2StatListStrc* pStatList, int nIndex)
{
    if (!pStatList)
    {
        return 0;
    }

    if (nIndex >= pStatList->Stats.nStatCount)
    {
        return 0;
    }

    return pStatList->Stats.pStat[nIndex].nValue;
}

// 0x00626070
int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId)
{
    return STATLIST_UnitGetStatValue(pUnit, nStatId, 0);
}

// 0x00627220
void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pUnit)
{
    if (pStatList)
    {
        STATLIST_SetBaseStat(pStatList, nStatId, nValue, nLayer, pUnit);
    }
}

// 0x00627810
int __stdcall D2Common_10531_SetStatInStatListLayer0(D2StatListStrc* pStatList, int nStatId, int nValue, int nUnused)
{
    return sub_006270B0(pStatList, nStatId, nValue, 0);
}

// 0x00627B30
int __cdecl sub_00627B30()
{
    return sgptDataTables->nItemStatCostTxtRecordCount;
}

// 0x00627B40
int __cdecl sub_00627B40()
{
    return 0;
}

// 0x00627B50
int __fastcall sub_00627B50_Min(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x00627B60
int __fastcall sub_00627B60_Max(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}
