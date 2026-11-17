struct D2UnitStrc;

struct D2TokRecord
{
    char unk0x00[0x20];
    unsigned int dwCode;
    char unk0x24[0x10];
};

struct D2MonStatsTxt
{
    char unk0x000[0x10];
    unsigned int dwCode;
    char unk0x014[0x1A8 - 0x14];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2TokRecord* __stdcall DATATBLS_GetPlrModeTypeTxtRecord(unsigned int nIndex, int bGetMode);                 // 0x0065B480
D2TokRecord* __stdcall DATATBLS_GetObjModeTypeTxtRecord(unsigned int nIndex, int bGetMode);                 // 0x0065B570

static __forceinline D2MonStatsTxt* GFXUTIL_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x004DAA00
int __fastcall sub_004DAA00_GetModeArg(D2UnitStrc* pUnit, int nType, int nClass)
{
    switch (nType)
    {
    case 2:
    {
        D2TokRecord* pRecord = DATATBLS_GetObjModeTypeTxtRecord(nClass, 0);
        if (!pRecord)
        {
            return 0;
        }
        return pRecord->dwCode;
    }
    case 1:
    {
        D2MonStatsTxt* pMonStatsTxtRecord = GFXUTIL_GetMonStatsTxtRecord(nClass);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }
        return pMonStatsTxtRecord->dwCode;
    }
    case 0:
    {
        D2TokRecord* pRecord = DATATBLS_GetPlrModeTypeTxtRecord(nClass, 0);
        if (!pRecord)
        {
            return 0;
        }
        return pRecord->dwCode;
    }
    default:
        return 0;
    }
}
