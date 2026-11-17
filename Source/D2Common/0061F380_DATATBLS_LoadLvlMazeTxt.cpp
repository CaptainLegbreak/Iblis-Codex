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
extern void* gpLvlmazeTxt;                                                                                  // 0x0096CA08
int gnLvlmazeTxtRecordCount;                                                                                // 0x0096CA0C

// 0x0061F380
void __fastcall DATATBLS_LoadLvlMazeTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Level", 2, 0, 0, 0 },
        { "Rooms", 2, 0, 4, 0 },
        { "Rooms(N)", 2, 0, 8, 0 },
        { "Rooms(H)", 2, 0, 12, 0 },
        { "SizeX", 2, 0, 16, 0 },
        { "SizeY", 2, 0, 20, 0 },
        { "Merge", 2, 0, 24, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpLvlmazeTxt = DATATBLS_CompileTxt(hArchive, "lvlmaze", pTbl, &gnLvlmazeTxtRecordCount, 28);
}
