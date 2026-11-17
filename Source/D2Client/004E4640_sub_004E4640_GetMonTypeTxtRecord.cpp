struct D2MonTypeTxt
{
    int unk0x00[3];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC34];
    int nMonTypeTxtRecordCount;
    int unk0xC38;
    D2MonTypeTxt* pMonTypeTxt;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// 0x004E4640
D2MonTypeTxt* __fastcall sub_004E4640_GetMonTypeTxtRecord(int nMonType)
{
    if (nMonType >= 0 && nMonType < sgptDataTables->nMonTypeTxtRecordCount)
        return &sgptDataTables->pMonTypeTxt[nMonType];
    return sgptDataTables->pMonTypeTxt;
}
