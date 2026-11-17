struct D2MonStatsTxt
{
    char unk0x00[0x18];
    short nMonStatsEx;
    char unk0x1A[0x18E];
};

struct D2MonStats2CompStrc
{
    unsigned char nComposit[12];
};

struct D2MonStats2Txt
{
    char unk0x00[0x15];
    unsigned char nComponentChoiceCounts[16];
    char unk0x25;
    D2MonStats2CompStrc unk0x26[16];
    char unk0xE6[0x4E];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xC];
    D2MonStats2Txt* pMonStats2Txt;
    void* pMonStats2Linker;
    int nMonStats2TxtRecordCount;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

extern D2DataTablesStrc* sgptDataTables;                                                                         // 0x00744304
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                                                       // 0x00451FE0
int __stdcall DATATBLS_GetCodeFromCompCodeTxt(int nIndex);                                                                       // 0x006117D0

// 0x006647C0
int __stdcall D2COMMON_11068_GetCompInfo(D2UnitStrc* pMonster, int nComponent)
{
    if (!pMonster || pMonster->dwUnitType != 1)
    {
        return 0;
    }

    if (nComponent >= sizeof(((D2MonStats2Txt*)0)->nComponentChoiceCounts))
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pMonster->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    return pMonStats2TxtRecord->nComponentChoiceCounts[nComponent];
}

static D2MonStats2Txt* MONSTERS_GetMonStats2TxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].nMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// 0x00664930
int __stdcall D2Common_11070(int nMonsterId, unsigned int nComponent, unsigned int nIndex)
{
    if (nComponent >= sizeof(((D2MonStats2Txt*)0)->nComponentChoiceCounts))
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERS_GetMonStats2TxtRecordInline(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (pMonStats2TxtRecord->nComponentChoiceCounts[nComponent] <= nIndex)
    {
        return 0;
    }

    return DATATBLS_GetCodeFromCompCodeTxt(pMonStats2TxtRecord->unk0x26[nComponent].nComposit[nIndex]);
}
