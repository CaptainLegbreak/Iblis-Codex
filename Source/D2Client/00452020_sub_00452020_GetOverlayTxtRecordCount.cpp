struct Unicode
{
    unsigned short wChar;
};

struct D2DataTablesStrc
{
    char unk0x00[0xBC0];
    int nOverlayTxtRecordCount;
    char unk0xBC4[0xBD4 - 0xBC4];
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode gwszText_007A2A78[256];                                                                             // 0x007A2A78
int gnHoverTextState_007A2C78;                                                                              // 0x007A2C78

// 0x00452020
int __fastcall sub_00452020_GetOverlayTxtRecordCount()
{
    return sgptDataTables->nOverlayTxtRecordCount;
}

// 0x00452030
int __fastcall sub_00452030_GetItemStatCostTxtRecordCount()
{
    return sgptDataTables->nItemStatCostTxtRecordCount;
}

// 0x00452070
int* __fastcall sub_00452070_ClearBlock(int* pData)
{
    for (int i = 0; i < 0x80; ++i)
    {
        pData[i] = 0;
    }

    return pData;
}

// 0x00452160
void __cdecl sub_00452160_Nop()
{
}

// 0x00452550
void __fastcall sub_00452550_SetHoverText(const Unicode* pText, int nState)
{
    if (!pText)
    {
        gwszText_007A2A78[0].wChar = 0;
        return;
    }

    sub_005267E0(gwszText_007A2A78, pText);
    gnHoverTextState_007A2C78 = nState;
}
