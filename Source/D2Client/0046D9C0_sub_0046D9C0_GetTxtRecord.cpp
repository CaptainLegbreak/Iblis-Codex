struct D2Txt84Strc
{
    char unk0x00[0x84];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBBC];
    D2Txt84Strc* pTxt84;
    int nTxt84Count;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// 0x0046D9C0
D2Txt84Strc* __fastcall sub_0046D9C0_GetTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nTxt84Count)
    {
        return &sgptDataTables->pTxt84[nIndex];
    }
    return 0;
}
