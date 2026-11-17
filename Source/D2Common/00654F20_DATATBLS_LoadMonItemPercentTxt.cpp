struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
void* gpMonitempercentTxt;                                                                                  // 0x0096D484
int gnMonitempercentTxtRecordCount;                                                                         // 0x0096D480

// 0x00654F20
void __fastcall DATATBLS_LoadMonItemPercentTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "HeartPercent", 4, 0, 0, 0 },
        { "BodyPartPercent", 4, 0, 1, 0 },
        { "TreasureClassPercent", 4, 0, 2, 0 },
        { "ComponentPercent", 4, 0, 3, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonitempercentTxt = DATATBLS_CompileTxt(hArchive, "monitempercent", pTbl, &gnMonitempercentTxtRecordCount, 4);
}
