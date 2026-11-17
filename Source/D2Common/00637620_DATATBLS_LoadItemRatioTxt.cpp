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
void* gpItemratioTxt;                                                                                       // 0x0096CC4C
int gnItemratioTxtRecordCount;                                                                              // 0x0096CC48

// 0x00637620
void __fastcall DATATBLS_LoadItemRatioTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Version", 3, 0, 64, 0 },
        { "Uber", 4, 0, 66, 0 },
        { "Class Specific", 4, 0, 67, 0 },
        { "Unique", 2, 0, 0, 0 },
        { "UniqueDivisor", 2, 0, 4, 0 },
        { "UniqueMin", 2, 0, 8, 0 },
        { "Rare", 2, 0, 12, 0 },
        { "RareDivisor", 2, 0, 16, 0 },
        { "RareMin", 2, 0, 20, 0 },
        { "Set", 2, 0, 24, 0 },
        { "SetDivisor", 2, 0, 28, 0 },
        { "SetMin", 2, 0, 32, 0 },
        { "Magic", 2, 0, 36, 0 },
        { "MagicDivisor", 2, 0, 40, 0 },
        { "MagicMin", 2, 0, 44, 0 },
        { "HiQuality", 2, 0, 48, 0 },
        { "HiQualityDivisor", 2, 0, 52, 0 },
        { "Normal", 2, 0, 56, 0 },
        { "NormalDivisor", 2, 0, 60, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpItemratioTxt = DATATBLS_CompileTxt(hArchive, "itemratio", pTbl, &gnItemratioTxtRecordCount, 68);
}
