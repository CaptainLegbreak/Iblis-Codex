struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x1A8 - 0x0C - 4];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0xA80 - 0xA78 - 4];
    int nMonStatsTxtRecordCount;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xC4 - 0x08];
    unsigned int dwFlagEx;
};

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern const unsigned int gdwBitMasks[];                                                                    // 0x006CE268

static __forceinline void MONSTERS_GetFlagEx31(D2UnitStrc* pUnit, int* pResult)
{
    *pResult = pUnit ? (pUnit->dwFlagEx >> 31) & 1 : 0;
}

// 0x0063E860
int __fastcall MONSTERS_CanBeInTown(D2UnitStrc* pMonster)
{
    const int nUnitType = pMonster ? pMonster->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return 0;
    }

    const int nMonsterId = pMonster->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nMonStatsFlags[8 >> 3] & gdwBitMasks[8 & 7])
    {
        return 1;
    }

    if (pMonStatsTxtRecord->nMonStatsFlags[10 >> 3] & gdwBitMasks[10 & 7])
    {
        return 1;
    }

    int bFlag;
    MONSTERS_GetFlagEx31(pMonster, &bFlag);
    return bFlag != 0;
}
