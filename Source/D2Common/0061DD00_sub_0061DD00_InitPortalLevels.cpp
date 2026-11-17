extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2DataTablesStrc
{
    char unk0x000[0xC5C];
    int nLevelsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

struct D2LevelDefBin
{
    char unk0x00[0x8C];
    int dwPortal;
    int dwPosition;
    int dwSaveMonsters;
    int dwLOSDraw;
};

extern D2LevelDefBin* gpLevelDefBin_0096C890;                                                               // 0x0096C890
static int* gpPortalLevels_0096C9F4;                                                                        // 0x0096C9F4
static int gnPortalLevels_0096C9F8;                                                                         // 0x0096C9F8

// 0x0061DD00
static void sub_0061DD00_InitPortalLevels(D2LevelDefBin* pLevelDefBin)
{
    gnPortalLevels_0096C9F8 = 0;
    for (int i = 0; i < sgptDataTables->nLevelsTxtRecordCount; ++i)
    {
        if (pLevelDefBin[i].dwPortal)
        {
            ++gnPortalLevels_0096C9F8;
        }
    }
    if (gnPortalLevels_0096C9F8)
    {
        gpPortalLevels_0096C9F4 = (int*)FOG_AllocPool(0, sizeof(int) * gnPortalLevels_0096C9F8, ".\\DATATBLS\\LvlTbls.cpp", 0x16C, 0);
        memset(gpPortalLevels_0096C9F4, 0, sizeof(int) * gnPortalLevels_0096C9F8);
    }
    int nPortalIndex = 0;
    for (int i = 0; i < sgptDataTables->nLevelsTxtRecordCount; ++i)
    {
        if (pLevelDefBin[i].dwPortal)
        {
            D2_ASSERT(nPortalIndex < gnPortalLevels_0096C9F8, 0x177);
            gpPortalLevels_0096C9F4[nPortalIndex] = i;
            ++nPortalIndex;
        }
    }
}

void __stdcall sub_M13_Emit_0061DD00(D2LevelDefBin* pLevelDefBin)
{
    gpLevelDefBin_0096C890 = pLevelDefBin;
    sub_0061DD00_InitPortalLevels(pLevelDefBin);
}
