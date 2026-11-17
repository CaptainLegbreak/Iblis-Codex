struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// 0x004C51D0
int __cdecl sub_004C51D0_GetStatesTxtRecordCount()
{
    return sgptDataTables->nStatesTxtRecordCount;
}
