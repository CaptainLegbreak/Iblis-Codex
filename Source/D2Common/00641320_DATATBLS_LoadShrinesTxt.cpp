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
extern void* gpShrinesTxt;                                                                                  // 0x0096D468
extern int gnShrinesTxtRecordCount;                                                                         // 0x0096D46C

// 0x00641320
void __fastcall DATATBLS_LoadShrinesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Code", 4, 0, 0, 0 },
        { "Arg0", 2, 0, 4, 0 },
        { "Arg1", 2, 0, 8, 0 },
        { "Duration in frames", 2, 0, 12, 0 },
        { "reset time in minutes", 4, 0, 16, 0 },
        { "rarity", 4, 0, 17, 0 },
        { "view name", 1, 31, 18, 0 },
        { "niftyphrase", 1, 127, 50, 0 },
        { "effectclass", 4, 0, 178, 0 },
        { "LevelMin", 2, 0, 180, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpShrinesTxt = DATATBLS_CompileTxt(hArchive, "shrines", pTbl, &gnShrinesTxtRecordCount, 184);
}
