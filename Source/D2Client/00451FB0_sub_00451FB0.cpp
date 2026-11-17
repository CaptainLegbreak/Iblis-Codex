struct D2MonStatsTxt
{
    char unk0x00[0x1A8];
};

struct D2MonStats2Txt
{
    char unk0x00[0x134];
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

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// 0x00451FB0
D2MonStats2Txt* __fastcall sub_00451FB0(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nId];
    }
    return 0;
}
