struct D2ColorRecordStrc
{
    char unk0x00[0x18];
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

// 0x0061BB60
static void __stdcall sub_0061BB60_SetColorForId(D2ColorRecordStrc* pRecord, int nId)
{
    if (nId == 0x78)
    {
        pRecord->nRed = 0xF5;
        pRecord->nGreen = 0xF0;
        pRecord->nBlue = 0xFF;
    }
}

// calling-convention shim (not game code)
void __stdcall sub_K14_EmitSetColorForId(D2ColorRecordStrc* pRecord, int nId)
{
    sub_0061BB60_SetColorForId(pRecord, nId);
}
