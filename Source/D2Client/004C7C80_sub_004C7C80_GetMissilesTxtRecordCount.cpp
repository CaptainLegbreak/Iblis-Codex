struct D2DataTablesStrc
{
    char unk0x000[0xB6C];
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// 0x004C7C80
int __cdecl sub_004C7C80_GetMissilesTxtRecordCount()
{
    return sgptDataTables->nMissilesTxtRecordCount;
}
