#include "D2Common.h"

// build: context SEED_RollLimitedRandomNumber_Inline
#define LEVEL_ROCKYWASTE 41
#define LEVEL_DRYHILLS 42
#define LEVEL_FAROASIS 43
#define LEVEL_LOSTCITY 44
#define LEVEL_VALLEYOFSNAKES 45
#define LEVEL_CANYONOFTHEMAGI 46
#define LEVEL_PANDEMONIUMRUN2 134
#define LEVEL_ROGUEENCAMPMENT 1
#define LEVEL_BLOODMOOR 2
#define LEVEL_MOOMOOFARM 39
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DrlgStrc;
union D2SeedStrc;
struct D2DrlgOutdoorInfoStrc;
struct D2DrlgCoordsStrc;
struct D2LvlPrestTxt;
struct D2DrlgOutDesertInitStrc;

union D2SeedStrc
{
    struct
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
    };
    unsigned __int64 lSeed;
};

struct D2DrlgGridStrc
{
    char unk0x00[0x14];
};

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
    D2DrlgGridStrc pGrid[4];
    char unk0x54[0x08];
    int nGridWidth;
    int nGridHeight;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char unk0x018[0x04];
    D2DrlgCoordsStrc pLevelCoords;
    char unk0x020[0x194];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x0C];
    D2SeedStrc pSeed;
    char unk0x1CC[0x04];
    int nLevelId;
};

struct D2LvlPrestTxt
{
    char unk0x00[0x40];
    unsigned int dwFiles;
};

struct D2DrlgOutDesertInitStrc
{
    int nLvlPrestId;
    int nRand;
    int nX;
    int nY;
};

D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLvlPrestId); // 0x0061F0B0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nPickedFile, int a4, int a5); // 0x00674730
void __fastcall DRLGOUTDOORS_SpawnAct12Waypoint(D2DrlgLevelStrc* pLevel); // 0x00674B70
void __fastcall DRLGOUTDOORS_SpawnAct12Shrines(D2DrlgLevelStrc* pLevel, int nShrines); // 0x00674E40
void __fastcall DRLGOUTDOORS_AddAct124SecondaryBorder(D2DrlgLevelStrc* pLevel, int nLvlSubId, int nLevelPrestId); // 0x006752A0
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel); // 0x00675770
void __fastcall DRLGOUTPLACE_PlaceAct1245OutdoorBorders(D2DrlgLevelStrc* pLevel); // 0x00675850
void __fastcall DRLGOUTDESR_PlaceDesertTransitionToTown(D2DrlgLevelStrc* pLevel); // 0x0067F560
void __fastcall DRLGOUTDESR_AddExits(D2DrlgLevelStrc* pLevel); // 0x0067F670
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0
int __fastcall DRLGOUTDOORS_SpawnPresetFarAway(D2DrlgLevelStrc* pLevel, D2DrlgCoordsStrc* pCoords, int nLevelPrestId, int nPickedFile, int a5, int a6); // 0x006744F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
void __stdcall sub_0067FE90_PlaceColumns(D2DrlgLevelStrc* pLevel, int nColumn); // 0x0067FE90
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const D2DrlgOutDesertInitStrc gaDesertCliffs_006F2390[8][5]; // 0x006F2390
extern const D2DrlgOutDesertInitStrc gaCanyonTombEntries_006F2610[9]; // 0x006F2610
static __declspec(noinline) void __stdcall DRLGOUTDESR_PlacePresetVariants(const int* pLevelPrestIds, int nVariants, int bIterateFiles, D2DrlgLevelStrc* pLevel); // 0x0067F470
static __declspec(noinline) void DRLGOUTWILD_SpawnTownTransitionsAndCaves(D2DrlgLevelStrc* pLevel); // 0x006803D0
extern const D2DrlgOutDesertInitStrc gaTombEntries_006F2610[9]; // 0x006F2610

static __declspec(noinline) void DRLGOUTDESR_PlaceTombEntriesInCanyon(D2DrlgLevelStrc* pLevel);

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber_Inline(pSeed) % nMax;
    }

    return SEED_RollRandomNumber_Inline(pSeed) & (nMax - 1);
}

// build: context DRLGOUTDESR_PlacePresetVariants
static __declspec(noinline) void __stdcall DRLGOUTDESR_PlacePresetVariants(const int* pLevelPrestIds, int nVariants, int bIterateFiles, D2DrlgLevelStrc* pLevel)
{
    int nRand = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, nVariants);
    DATATBLS_GetLvlPrestTxtRecord(pLevelPrestIds[nRand]);

    for (int i = 0; i < nVariants; ++i)
    {
        if (bIterateFiles)
        {
            const int nFiles = DATATBLS_GetLvlPrestTxtRecord(pLevelPrestIds[nRand])->dwFiles;
            for (int nFile = 0; nFile < nFiles; ++nFile)
            {
                DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, pLevelPrestIds[nRand], nFile, 0, 15);
            }
        }
        else
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, pLevelPrestIds[nRand], -1, 0, 15);
        }

        nRand = (nRand + 1) % nVariants;
    }
}

// build: context DRLGOUTDESR_PlaceCliffs
static __declspec(noinline) void DRLGOUTDESR_PlaceCliffs(D2DrlgLevelStrc* pLevel)
{
    const unsigned int nRand = SEED_RollRandomNumber_Inline(&pLevel->pSeed) & 7;

    for (int i = 0; i < 5; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, gaDesertCliffs_006F2390[nRand][i].nX, gaDesertCliffs_006F2390[nRand][i].nY, gaDesertCliffs_006F2390[nRand][i].nLvlPrestId, gaDesertCliffs_006F2390[nRand][i].nRand, 0);
    }
}

// 0x0067F630
static __declspec(noinline) void DRLGOUTDESR_PlaceBorders(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 2, 0x16C);
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 1, 0x16C);
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 3, 0x16C);
}

// 0x0067F6F0
static __declspec(noinline) void sub_0067F6F0_PlaceRockyWasteVariants(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds[] = { 0x18B, 0x19B, 0x191, 0x192, 0x18F, 0x18E, 0x193 };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds, 7, 0, pLevel);
}

// 0x0067F740
static __declspec(noinline) void sub_0067F740_PlaceDryHillsVariants(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds1[] = { 0x18B, 0x19B, 0x190, 0x18E };
    const int nLevelPrestIds2[] = { 0x194, 0x195, 0x196, 0x197 };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds1, 4, 0, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 4, 1, pLevel);
}

// 0x0067F7A0
static void sub_0067F7A0_PlaceFarOasisVariants(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds[] = { 0x18C, 0x18D };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds, 2, 0, pLevel);
}

// 0x0067F7D0
static __declspec(noinline) void DRLGOUTDESR_PlaceFillsInFarOasis(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds1[4] = { 0x19B, 0x18F, 0x18E, 0x193 };
    const int nLevelPrestIds2[1] = { 0x18B };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds1, 4, 0, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 1, 1, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 1, 1, pLevel);
}

// 0x0067F830
static __declspec(noinline) void DRLGOUTDESR_PlaceRuinsInLostCity(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds[4] = { 0x19D, 0x198, 0x199, 0x19A };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds, 4, 0, pLevel);
}

// 0x0067F870
static __declspec(noinline) void DRLGOUTDESR_PlaceFillsInLostCity(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds1[5] = { 0x18B, 0x190, 0x18E, 0x194, 0x195 };
    const int nLevelPrestIds2[1] = { 0x19B };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds1, 5, 0, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 1, 1, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 1, 1, pLevel);
}

// 0x0067F920
static __declspec(noinline) void DRLGOUTDESR_PlaceFillsInCanyon(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds1[5] = { 0x191, 0x192, 0x196, 0x197, 0x193 };
    const int nLevelPrestIds2[2] = { 0x188, 0x189 };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds1, 5, 0, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 2, 1, pLevel);
}

// build: context DRLGOUTDESR_InitAct2OutdoorLevel
void __fastcall DRLGOUTDESR_InitAct2OutdoorLevel(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    DRLGOUTPLACE_PlaceAct1245OutdoorBorders(pLevel);

    switch (pLevel->nLevelId)
    {
    case LEVEL_ROCKYWASTE:
        DRLGOUTDESR_PlaceDesertTransitionToTown(pLevel);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDESR_AddExits(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        sub_0067F6F0_PlaceRockyWasteVariants(pLevel);
        break;

    case LEVEL_DRYHILLS:
        DRLGOUTDESR_PlaceCliffs(pLevel);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDESR_AddExits(pLevel);
        DRLGOUTDOORS_SpawnAct12Waypoint(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        sub_0067F740_PlaceDryHillsVariants(pLevel);
        break;

    case LEVEL_FAROASIS:
        DRLGOUTDESR_PlaceCliffs(pLevel);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDESR_AddExits(pLevel);
        sub_0067F7A0_PlaceFarOasisVariants(pLevel);
        DRLGOUTDOORS_SpawnAct12Waypoint(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        DRLGOUTDESR_PlaceFillsInFarOasis(pLevel);
        break;

    case LEVEL_LOSTCITY:
        DRLGOUTDESR_PlaceCliffs(pLevel);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDESR_AddExits(pLevel);
        DRLGOUTDESR_PlaceRuinsInLostCity(pLevel);
        DRLGOUTDOORS_SpawnAct12Waypoint(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        DRLGOUTDESR_PlaceFillsInLostCity(pLevel);
        break;

    case LEVEL_VALLEYOFSNAKES:
        DRLGOUTDESR_AddExits(pLevel);
        break;

    case LEVEL_CANYONOFTHEMAGI:
        DRLGOUTDESR_PlaceTombEntriesInCanyon(pLevel);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        DRLGOUTDESR_PlaceFillsInCanyon(pLevel);
        break;

    case LEVEL_PANDEMONIUMRUN2:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 4, 4, 0x18A, -1, 0);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDESR_PlaceFillsInCanyon(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        break;

    default:
        return;
    }
}

// 0x0067FC70
static __declspec(noinline) int DRLGOUTWILD_TestSpawnRiver(int nX, D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    for (int nY = 0; nY < pOutdoors->nGridHeight; ++nY)
    {
        if (DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY) & 2)
        {
            return 0;
        }

        if (DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX + 1, nY) & 2)
        {
            return 0;
        }
    }

    return 1;
}

// 0x006801A0
static __declspec(noinline) int __stdcall DRLGOUTWILD_SpawnCliffCaves(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    switch (DRLGGRID_GetGridEntry(&pOutdoors->pGrid[0], nX, nY))
    {
    case 16:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, 0x19, -1, 0);
        pOutdoors->dwFlags |= 0x40;
        return 1;

    case 17:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, 0x18, -1, 0);
        pOutdoors->dwFlags |= 0x40;
        return 1;

    default:
        return 0;
    }
}

void __stdcall sub_00680200_SpawnRiverAndCliffCaves(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->nLevelId == LEVEL_MOOMOOFARM)
    {
        return;
    }

    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    if (pOutdoors->dwFlags & 0xC)
    {
        const int nX = pOutdoors->nGridWidth - 2;
        if (DRLGOUTWILD_TestSpawnRiver(nX, pLevel))
        {
            sub_0067FE90_PlaceColumns(pLevel, nX);
        }
    }

    if ((pOutdoors->dwFlags & 0x20) && !(pOutdoors->dwFlags & 0x40))
    {
        int bAdded = 0;
        if (SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, 2))
        {
            for (int i = 0; i < pOutdoors->nGridHeight; ++i)
            {
                if (bAdded)
                {
                    break;
                }

                for (int j = 0; j < pOutdoors->nGridWidth; ++j)
                {
                    if (bAdded)
                    {
                        break;
                    }

                    bAdded = DRLGOUTWILD_SpawnCliffCaves(pLevel, i, j);
                }
            }
        }
        else
        {
            for (int i = 0; i < pOutdoors->nGridHeight; ++i)
            {
                if (bAdded)
                {
                    break;
                }

                for (int j = 0; j < pOutdoors->nGridWidth; ++j)
                {
                    if (bAdded)
                    {
                        break;
                    }

                    bAdded = DRLGOUTWILD_SpawnCliffCaves(pLevel, j, i);
                }
            }
        }

        D2_ASSERT(bAdded, 0x194);
    }

    if ((pOutdoors->dwFlags & 0x1C) && !(pOutdoors->dwFlags & 0x40))
    {
        const int nWidth = pOutdoors->nGridWidth - ((pOutdoors->dwFlags & 0x10) ? 4 : 5);
        const int nHeight = pOutdoors->nGridHeight - 4;
        const int nRand = SEED_RollRandomNumber_Inline(&pLevel->pSeed) & 3;
        const int nPosX = (nRand % 2) ? 3 : nWidth;
        const int nPosY = (nRand / 2) ? 3 : nHeight;
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nPosX, nPosY, (pLevel->nLevelId == LEVEL_BLOODMOOR) + 0x33, -1, 0);
        pOutdoors->dwFlags |= 0x40;
    }
}

// build: context DRLGOUTWILD_SpawnTownTransitionsAndCaves
static __declspec(noinline) void DRLGOUTWILD_SpawnTownTransitionsAndCaves(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->nLevelId == LEVEL_MOOMOOFARM)
    {
        return;
    }

    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    if (pOutdoors->dwFlags & 0x10)
    {
        const int nX = pOutdoors->nGridWidth / 2 - 1;
        if (DRLGOUTWILD_TestSpawnRiver(nX, pLevel))
        {
            sub_0067FE90_PlaceColumns(pLevel, nX);
        }
    }

    if (pOutdoors->dwFlags & 0x80)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 3, 1, 0);
    }

    if (pOutdoors->dwFlags & 0x100)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, pOutdoors->nGridWidth - 7, 0, 3, 2, 0);
    }

    if (pOutdoors->dwFlags & 0x200)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 1, 2, 1, 0);
    }

    if (pOutdoors->dwFlags & 0x400)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, pOutdoors->nGridHeight - 6, 2, 1, 0);
    }

    if (!(pOutdoors->dwFlags & 0x40))
    {
        int bAdded = 0;
        if (pLevel->nLevelId == LEVEL_BLOODMOOR)
        {
            D2DrlgCoordsStrc* pCoords = &DRLG_GetLevel(pLevel->pDrlg, LEVEL_ROGUEENCAMPMENT)->pLevelCoords;
            bAdded = DRLGOUTDOORS_SpawnPresetFarAway(pLevel, pCoords, 0x34, -1, 1, 15);
        }
        else
        {
            bAdded = DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x33, -1, 1, 15);
        }

        D2_ASSERT(bAdded, 0x1E5);
        pOutdoors->dwFlags |= 0x40;
    }
}

void __fastcall sub_A14_Emit_006803D0(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 2, 4);
    DRLGOUTWILD_SpawnTownTransitionsAndCaves(pLevel);
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 3, 4);
}

// 0x0067F8D0
static __declspec(noinline) void DRLGOUTDESR_PlaceTombEntriesInCanyon(D2DrlgLevelStrc* pLevel)
{
    for (int i = 0; i < 9; ++i)
    {
        const D2DrlgOutDesertInitStrc* pInit = &gaTombEntries_006F2610[i];
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, pInit->nX, pInit->nY, pInit->nLvlPrestId, pInit->nRand, 0);
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 4, 4, 0x18A, -1, 0);
}

void __fastcall sub_I19_Emit_0067F8D0(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDESR_InitAct2OutdoorLevel(pLevel);
    DRLGOUTDESR_PlaceTombEntriesInCanyon(pLevel);
    DRLGOUTDESR_InitAct2OutdoorLevel(pLevel);
}

#include "gen/data/Source/D2Common/DRLG/OutDesr.inc"
