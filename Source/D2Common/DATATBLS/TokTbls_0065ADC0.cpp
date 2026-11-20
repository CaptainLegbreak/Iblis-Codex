struct D2BinFieldStrc
{
    const char* szName;
    int eType;
    int nOffset;
    int nUnk0;
    int nUnk1;
};

struct D2PlrModeDataTbl
{
    int nCount;
    void* pData;
    void* pData2;
    void* pPlrModeData;
};

extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern const char gszEnd[]; // 0x006D9060
extern D2PlrModeDataTbl gPlrModeDataTables; // 0x0096D4D8

// 0x0065ADC0
void __fastcall DATATBLS_LoadPlrType_ModeTxt(void* hArchive)
{
    D2BinFieldStrc tbl[3] =
    {
        { "name", 1, 0x1F, 0, 0 },
        { "token", 9, 0, 0x20, 0 },
        { gszEnd, 0, 0, 0, 0 },
    };
    int anCount[2];
    void* apBin[2];

    apBin[1] = DATATBLS_CompileTxt(hArchive, "plrtype", tbl, &anCount[1], 0x34);
    apBin[0] = DATATBLS_CompileTxt(hArchive, "plrmode", tbl, &anCount[0], 0x34);

    int nTotal = anCount[1] + anCount[0];
    char* ptTokenStats = (char*)FOG_AllocPool(0, nTotal * 0x34, ".\\DATATBLS\\TokTbls.cpp", 0x37, 0);
    if (!ptTokenStats)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x38);
        exit(-1);
    }
    memcpy(ptTokenStats, apBin[1], anCount[1] * 0x34);
    char* pMode = ptTokenStats + anCount[1] * 0x34;
    memcpy(pMode, apBin[0], anCount[0] * 0x34);
    DATATBLS_UnloadBin(apBin[1]);
    DATATBLS_UnloadBin(apBin[0]);

    gPlrModeDataTables.pPlrModeData = pMode;
    gPlrModeDataTables.pData = ptTokenStats;
    gPlrModeDataTables.pData2 = ptTokenStats;
    gPlrModeDataTables.nCount = nTotal;
}
