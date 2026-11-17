struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char unk0x04[0x1A4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

#define UNIT_MONSTER 1

static D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline_J03(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int MONSTERS_GetBaseIdInline_J03(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline_J03(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nMonsterId;
}

// 0x004F4EC0
int __fastcall sub_004F4EC0_GetSkillOverlay(D2UnitStrc* pUnit, int nSkillId, int nDefault, int nUnused)
{
    int nResult = nDefault;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const int nBaseId = MONSTERS_GetBaseIdInline_J03(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == 0x10B && nSkillId == 0xA7)
        {
            sub_00470390(pUnit, 0x55, 2, 0, 0, 0, 0, 0);
            nResult = 0x54;
        }
    }

    return nResult;
}
