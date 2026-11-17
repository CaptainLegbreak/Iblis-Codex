struct D2MonStatsTxt
{
    char unk0x00[0x1C];
    short wMonType;
    char unk0x1E[0x18A];
};

struct D2MonUModTxt
{
    char unk0x00[0x1C];
    int dwConstants;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x1BC];
    int nMonTypeTxtRecordCount;
    unsigned int* pMonTypeNest;
    int nMonTypeIndex;
    char unk0xC4C[0x04];
    D2MonUModTxt* pMonUModTxt;
    int nMonUModTxtRecordCount;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

#define UNIT_MONSTER 1

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

static D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x005A0070
int __fastcall sub_005A0070_MONSTERUNIQUE_CheckMonType(D2UnitStrc* pUnit, int nMonType)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (pMonStatsTxtRecord && pMonStatsTxtRecord->wMonType >= 0 && pMonStatsTxtRecord->wMonType < sgptDataTables->nMonTypeTxtRecordCount
        && nMonType >= 0 && nMonType < sgptDataTables->nMonTypeTxtRecordCount)
    {
        return gdwBitMasks[pMonStatsTxtRecord->wMonType & 31] & sgptDataTables->pMonTypeNest[(pMonStatsTxtRecord->wMonType >> 5) + nMonType * sgptDataTables->nMonTypeIndex];
    }

    return 0;
}

// 0x005A00F0
int __fastcall sub_005A00F0_GetMonUModConstant(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nMonUModTxtRecordCount)
    {
        D2MonUModTxt* pMonUModTxtRecord = &sgptDataTables->pMonUModTxt[nIndex];
        if (pMonUModTxtRecord)
        {
            return pMonUModTxtRecord->dwConstants;
        }
    }

    return 0;
}
