extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SeedStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

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

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0

extern "C" const char gszTxtField_end_006D9060[];                                                           // 0x006D9060
extern const char gszAutomapLevelNames_006E7D50[36][16];                                                    // 0x006E7D50
extern const char gszAutomapTileNames_006E7F90[20][8];                                                      // 0x006E7F90
extern D2SeedStrc* gpAutomapSeed_00744504;                                                                  // 0x00744504
extern D2AutomapShortStrc* gpAutomap_0096CA28;                                                              // 0x0096CA28
int gnAutomapRecordCount_0096CA2C;                                                                          // 0x0096CA2C
D2AutomapRandStrc gAutomapRand_0096C8D0[36];                                                                // 0x0096C8D0

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

#include "gen/data/Source/D2Common/0061FCF0_DATATBLS_LoadAutomapTxt.inc"
