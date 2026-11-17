struct D2DataTablesStrc
{
    char unk0x000[0xC68];
    int nLvlPrestTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// 0x0061C530
int __cdecl sub_0061C530_GetLvlPrestTxtRecordCount()
{
    return sgptDataTables->nLvlPrestTxtRecordCount;
}
