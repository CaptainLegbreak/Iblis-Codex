#include "D2Common.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SeedStrc;
struct D2SkillsTxt;
struct D2AutomapShortStrc;
struct D2DrlgStrc;
struct D2LevelDefBin;
struct D2BinFieldStrc;
struct D2AutomapTxt;
struct D2AutomapRandStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2DataTablesStrc
{
    char unk0x000[0xC5C];
    int nLevelsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

struct D2LevelDefBin
{
    char unk0x00[0x8C];
    int dwPortal;
    int dwPosition;
    int dwSaveMonsters;
    int dwLOSDraw;
};

extern D2LevelDefBin* gpLevelDefBin_0096C890; // 0x0096C890

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
extern "C" const char gszTxtField_end_006D9060[]; // 0x006D9060
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* sz);
extern void* gpLvlwarpTxt; // 0x0096CA00
extern void* gpLvlmazeTxt; // 0x0096CA08

struct D2LvlTypesTxt
{
    char szFile[32][60];
    unsigned char nAct;
    unsigned char pad0x781[3];
    unsigned int dwExpansion;
};

extern "C" int __cdecl strcmp(const char* s1, const char* s2);
extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
extern const char gszAutomapLevelNames_006E7D50[36][16]; // 0x006E7D50
extern const char gszAutomapTileNames_006E7F90[20][8]; // 0x006E7F90

struct D2AutomapTxt
{
    char szLevelName[0x10];
    char szTileName[0x08];
    char nStyle;
    char nStartSequence;
    char nEndSequence;
    char pad0x1B;
    int nCel[4];
};

struct D2AutomapShortStrc
{
    int dwAutomapLevelType;
    int dwAutomapTileType;
    char nStyle;
    char nStartSequence;
    char nEndSequence;
    char pad0x0B;
    int nCel[4];
    int nCels;
};

struct D2AutomapRandStrc
{
    int nStart;
    int nEnd;
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0
extern D2SeedStrc* gpAutomapSeed_00744504; // 0x00744504
extern D2AutomapShortStrc* gpAutomap_0096CA28; // 0x0096CA28

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    int dwSkillMode;
    int dwFlags;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x24];
    D2DrlgRoomStrc* pDrlgRoomNext;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x8];
    int nRooms;
    char unk0x0C[0x4];
    D2DrlgRoomStrc* pFirstRoomEx;
    D2LvlMazeTxt* pMaze;
    char unk0x18[0x19C];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0xC];
    D2SeedStrc pSeed;
    void* pBuild;
    int nLevelId;
};
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040

static int* gpPortalLevels_0096C9F4; // 0x0096C9F4

static int gnPortalLevels_0096C9F8; // 0x0096C9F8

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

// 0x0061E4A0
static void sub_0061E4A0(char* szPath, const char* szDirectory)
{
    char szBuffer[60];
    const int nLength = strlen(szPath);
    if (nLength)
    {
        for (int i = 0; i < nLength; ++i)
        {
            if (szPath[i] == '/')
                szPath[i] = '\\';
        }
    }
    if (nLength > 1)
    {
        wsprintfA(szBuffer, gszPathFormat_006D4124, szDirectory, szPath);
        strcpy(szPath, szBuffer);
    }
}

void __fastcall sub_Z16_EmitFixPathSlashes(char* pRecords, int nCount)
{
    for (int i = 0; i < nCount; ++i)
    {
        sub_0061E4A0(pRecords, "DATA\\GLOBAL\\TILES");
        pRecords += 0x3C;
    }
}

int gnLvlwarpTxtRecordCount; // 0x0096CA04

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

int gnLvlmazeTxtRecordCount; // 0x0096CA0C

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

static D2LvlTypesTxt* gpLvlTypesTxt_0096C9F0; // 0x0096C9F0

static int gnLvlTypesTxtRecordCount_0096C9FC; // 0x0096C9FC

static D2TileLibraryHeaderStrc** gppTileLibraryHash_0096CA1C; // 0x0096CA1C

// 0x0061FAE0
void __fastcall DATATBLS_AllocGlobalTileLibraryHash()
{
    D2_ASSERT(gpLvlTypesTxt_0096C9F0, 1040);

    const int nSize = sizeof(D2TileLibraryHeaderStrc*[1024]) * gnLvlTypesTxtRecordCount_0096C9FC;
    gppTileLibraryHash_0096CA1C = (D2TileLibraryHeaderStrc**)FOG_AllocPool(0, nSize, ".\\DATATBLS\\LvlTbls.cpp", 1043, 0);
    memset(gppTileLibraryHash_0096CA1C, 0, nSize);

    D2TileLibraryHeaderStrc** ppTileLibraryHash = gppTileLibraryHash_0096CA1C;
    const int bExpansion = sub_00408F20_HasExpansionMpq();
    for (int i = 0; i < gnLvlTypesTxtRecordCount_0096C9FC; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            if (!strcmp(gpLvlTypesTxt_0096C9F0[i].szFile[j], "0"))
            {
                break;
            }

            if (bExpansion || !gpLvlTypesTxt_0096C9F0[i].dwExpansion)
            {
                DT1_ListAdd(ppTileLibraryHash, gpLvlTypesTxt_0096C9F0[i].szFile[j]);
            }
        }
        ppTileLibraryHash += 1024;
    }
}

void sub_W12_EmitLvlTypesTxtWrites(D2LvlTypesTxt* pLvlTypesTxt, int nRecordCount)
{
    gpLvlTypesTxt_0096C9F0 = pLvlTypesTxt;
    gnLvlTypesTxtRecordCount_0096C9FC = nRecordCount;
}

// 0x0061FC10
static int sub_0061FC10_GetAutomapLevelType(const char* szLevelName)
{
    if (szLevelName[0] != '0')
    {
        for (int nLevelType = 0; nLevelType < 36; ++nLevelType)
        {
            if (!strcmp(szLevelName, gszAutomapLevelNames_006E7D50[nLevelType]))
            {
                return nLevelType;
            }
        }

        D2_ASSERT(0, 0x4A5);
    }

    return 0;
}

// 0x0061FC80
static int sub_0061FC80_GetAutomapTileType(const char* szTileName)
{
    if (szTileName[0] != '0')
    {
        for (int nTileType = 0; nTileType < 20; ++nTileType)
        {
            if (!strcmp(szTileName, gszAutomapTileNames_006E7F90[nTileType]))
            {
                return nTileType;
            }
        }

        D2_ASSERT(0, 0x4D0);
    }

    return 0;
}

void __stdcall sub_M14_EmitAutomapLookups(const char* pAutomapRecord, int* pTypes)
{
    pTypes[0] = sub_0061FC10_GetAutomapLevelType(pAutomapRecord);
    pTypes[1] = sub_0061FC80_GetAutomapTileType(pAutomapRecord + 16);
}

#include "gen/data/Source/D2Common/DATATBLS/LvlTbls.inc"

int gnAutomapRecordCount_0096CA2C; // 0x0096CA2C

D2AutomapRandStrc gAutomapRand_0096C8D0[36]; // 0x0096C8D0

// 0x0061FCF0
void __fastcall DATATBLS_LoadAutomapTxt(void* hArchive)
{
    D2AutomapShortStrc* pAutomap = 0;
    D2AutomapTxt* pAutomapTxt;
    int nRecordCount;

    SEED_InitSeed(gpAutomapSeed_00744504);
    SEED_InitLowSeed(gpAutomapSeed_00744504, 0);

    D2BinFieldStrc pTbl[] =
    {
        { "LevelName", 1, 15, 0x00, 0 },
        { "TileName", 1, 7, 0x10, 0 },
        { "Style", 4, 0, 0x18, 0 },
        { "StartSequence", 4, 0, 0x19, 0 },
        { "EndSequence", 4, 0, 0x1A, 0 },
        { "Cel1", 2, 0, 0x1C, 0 },
        { "Cel2", 2, 0, 0x20, 0 },
        { "Cel3", 2, 0, 0x24, 0 },
        { "Cel4", 2, 0, 0x28, 0 },
        { gszTxtField_end_006D9060, 0, 0, 0, 0 },
    };

    pAutomapTxt = (D2AutomapTxt*)DATATBLS_CompileTxt(hArchive, "automap", pTbl, &nRecordCount, sizeof(D2AutomapTxt));
    pAutomap = (D2AutomapShortStrc*)sub_0040B430(0, sizeof(D2AutomapShortStrc) * nRecordCount, ".\\DATATBLS\\LvlTbls.cpp", 0x4F7, 0);
    memset(pAutomap, 0, sizeof(D2AutomapShortStrc) * nRecordCount);

    for (int i = 0; i < nRecordCount; ++i)
    {
        pAutomap[i].dwAutomapLevelType = sub_0061FC10_GetAutomapLevelType(pAutomapTxt[i].szLevelName);
        pAutomap[i].dwAutomapTileType = sub_0061FC80_GetAutomapTileType(pAutomapTxt[i].szTileName);
        pAutomap[i].nStyle = pAutomapTxt[i].nStyle;
        pAutomap[i].nStartSequence = pAutomapTxt[i].nStartSequence;
        pAutomap[i].nEndSequence = pAutomapTxt[i].nEndSequence;
        pAutomap[i].nCel[0] = pAutomapTxt[i].nCel[0];
        pAutomap[i].nCel[1] = pAutomapTxt[i].nCel[1];
        pAutomap[i].nCel[2] = pAutomapTxt[i].nCel[2];
        pAutomap[i].nCel[3] = pAutomapTxt[i].nCel[3];
        pAutomap[i].nCels = 0;

        for (int j = 0; j < 4; ++j)
        {
            if (pAutomap[i].nCel[j] == -1)
            {
                break;
            }
            ++pAutomap[i].nCels;
        }

        D2_ASSERT(pAutomap[i].nCels, 0x50D);
    }

    DATATBLS_UnloadBin(pAutomapTxt);

    gpAutomap_0096CA28 = pAutomap;
    gnAutomapRecordCount_0096CA2C = nRecordCount;

    for (int i = 0; i < 36; ++i)
    {
        gAutomapRand_0096C8D0[i].nStart = -1;
        gAutomapRand_0096C8D0[i].nEnd = -1;
    }

    int nCounter = 0;
    while (nCounter < nRecordCount)
    {
        const int nLevelType = pAutomap[nCounter].dwAutomapLevelType;
        gAutomapRand_0096C8D0[nLevelType].nStart = nCounter;
        while (nCounter + 1 < nRecordCount && nLevelType == pAutomap[nCounter + 1].dwAutomapLevelType)
        {
            ++nCounter;
        }
        ++nCounter;
        gAutomapRand_0096C8D0[nLevelType].nEnd = nCounter;
    }

    D2_ASSERT(nCounter <= nRecordCount, 0x528);
}

// 0x006200D0
void __fastcall DATATBLS_FreeAutomap()
{
    if (gpAutomap_0096CA28)
    {
        FOG_FreeServerMemory(0, gpAutomap_0096CA28, ".\\DATATBLS\\LvlTbls.cpp", 0x551, 0);
    }

    gpAutomap_0096CA28 = 0;
}

// 0x00644140
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    return pSkill->pSkillsTxt;
}

// 0x006446A0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill)
{
    if (pSkill)
    {
        return pSkill->dwFlags;
    }

    return 0;
}

// 0x00673FE0
void __fastcall DRLGMAZE_ResetMazeRecord(D2DrlgLevelStrc* pLevel, int bKeepMazeRecord)
{
    if (!bKeepMazeRecord)
    {
        pLevel->pMaze = 0;
    }
}

// 0x00673FF0
int __fastcall sub_00673FF0_GetVisFlagToLevel(D2DrlgLevelStrc* pLevel, D2DrlgLevelStrc* pOtherLevel)
{
    int* pLevelIds = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->nLevelId);
    int i = 0;
    for (; i < 8; ++i)
    {
        if (pLevelIds[i] == pOtherLevel->nLevelId)
        {
            break;
        }
    }

    if (i == 8)
    {
        return 0;
    }

    return 1 << (i + 4);
}

static __forceinline unsigned int MAZE_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int MAZE_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return MAZE_RollRandomNumberInline(pSeed) % nMax;
    }

    return MAZE_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x006711A0
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetRandomRoomExFromLevel(D2DrlgLevelStrc* pLevel)
{
    int i = MAZE_RollLimitedRandomNumberInline(&pLevel->pSeed, pLevel->nRooms);
    D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx;
    for (; i; --i)
    {
        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
    }

    return pDrlgRoom;
}
