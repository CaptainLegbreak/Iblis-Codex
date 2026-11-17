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
extern void* gpLvlwarpTxt;                                                                                  // 0x0096CA00
int gnLvlwarpTxtRecordCount;                                                                                // 0x0096CA04

// 0x0061F130
void __fastcall DATATBLS_LoadLvlWarpTxt(void* hArchive)
{
    int nRecordCount;
    D2BinFieldStrc pTbl[] =
    {
        { "Id", 2, 0, 0, 0 },
        { "SelectX", 2, 0, 4, 0 },
        { "SelectY", 2, 0, 8, 0 },
        { "SelectDX", 2, 0, 12, 0 },
        { "SelectDY", 2, 0, 16, 0 },
        { "ExitWalkX", 2, 0, 20, 0 },
        { "ExitWalkY", 2, 0, 24, 0 },
        { "OffsetX", 2, 0, 28, 0 },
        { "OffsetY", 2, 0, 32, 0 },
        { "LitVersion", 2, 0, 36, 0 },
        { "Tiles", 2, 0, 40, 0 },
        { "Direction", 1, 1, 44, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpLvlwarpTxt = DATATBLS_CompileTxt(hArchive, "lvlwarp", pTbl, &nRecordCount, 48);
    gnLvlwarpTxtRecordCount = nRecordCount;
}
