extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

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

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0

extern D2LevelDefBin* gpLevelDefBin_0096C890;                                                               // 0x0096C890
extern "C" const char gszTxtField_end_006D9060[];                                                           // 0x006D9060

static int* gpPortalLevels_0096C9F4;                                                                        // 0x0096C9F4
static int gnPortalLevels_0096C9F8;                                                                         // 0x0096C9F8

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

// 0x0061DE00
void __fastcall DATATBLS_LoadLevelDefsBin(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "QuestFlag", 2, 0, 0, 0 },
        { "QuestFlagEx", 2, 0, 4, 0 },
        { "Layer", 2, 0, 8, 0 },
        { "SizeX", 2, 0, 12, 0 },
        { "SizeY", 2, 0, 24, 0 },
        { "SizeX(N)", 2, 0, 16, 0 },
        { "SizeY(N)", 2, 0, 28, 0 },
        { "SizeX(H)", 2, 0, 20, 0 },
        { "SizeY(H)", 2, 0, 32, 0 },
        { "OffsetX", 2, 0, 36, 0 },
        { "OffsetY", 2, 0, 40, 0 },
        { "Depend", 2, 0, 44, 0 },
        { "DrlgType", 2, 0, 48, 0 },
        { "LevelType", 2, 0, 52, 0 },
        { "SubType", 2, 0, 56, 0 },
        { "SubTheme", 2, 0, 60, 0 },
        { "SubWaypoint", 2, 0, 64, 0 },
        { "SubShrine", 2, 0, 68, 0 },
        { "Vis0", 2, 0, 72, 0 },
        { "Vis1", 2, 0, 76, 0 },
        { "Vis2", 2, 0, 80, 0 },
        { "Vis3", 2, 0, 84, 0 },
        { "Vis4", 2, 0, 88, 0 },
        { "Vis5", 2, 0, 92, 0 },
        { "Vis6", 2, 0, 96, 0 },
        { "Vis7", 2, 0, 100, 0 },
        { "Warp0", 2, 0, 104, 0 },
        { "Warp1", 2, 0, 108, 0 },
        { "Warp2", 2, 0, 112, 0 },
        { "Warp3", 2, 0, 116, 0 },
        { "Warp4", 2, 0, 120, 0 },
        { "Warp5", 2, 0, 124, 0 },
        { "Warp6", 2, 0, 128, 0 },
        { "Warp7", 2, 0, 132, 0 },
        { "Intensity", 4, 0, 136, 0 },
        { "Red", 4, 0, 137, 0 },
        { "Green", 4, 0, 138, 0 },
        { "Blue", 4, 0, 139, 0 },
        { "Portal", 2, 0, 140, 0 },
        { "Position", 2, 0, 144, 0 },
        { "SaveMonsters", 2, 0, 148, 0 },
        { "LOSDraw", 2, 0, 152, 0 },
        { gszTxtField_end_006D9060, 0, 0, 0, 0 },
    };

    gpLevelDefBin_0096C890 = (D2LevelDefBin*)DATATBLS_CompileTxt(hArchive, "leveldefs", pTbl, 0, 0x9C);
    sub_0061DD00_InitPortalLevels(gpLevelDefBin_0096C890);
}
