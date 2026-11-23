#include "D2LevelIds.h"
#include "D2Path.h"
#include "D2LevelTxt.h"
#include "D2Drlg.h"
struct D2DrlgStrc;






struct D2DrlgOutDesertInitStrc
{
    int nLvlPrestId;
    int nRand;
    int nX;
    int nY;
};

D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLvlPrestId);                                     // 0x0061F0B0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730
void __fastcall DRLGOUTDOORS_SpawnAct12Waypoint(D2DrlgLevelStrc* pLevel);                                   // 0x00674B70
void __fastcall DRLGOUTDOORS_SpawnAct12Shrines(D2DrlgLevelStrc* pLevel, int nShrines);                      // 0x00674E40
void __fastcall DRLGOUTDOORS_AddAct124SecondaryBorder(D2DrlgLevelStrc* pLevel, int nLvlSubId, int nLevelPrestId); // 0x006752A0
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel);                                  // 0x00675770
void __fastcall DRLGOUTPLACE_PlaceAct1245OutdoorBorders(D2DrlgLevelStrc* pLevel);                           // 0x00675850
void __fastcall DRLGOUTDESR_PlaceDesertTransitionToTown(D2DrlgLevelStrc* pLevel);                           // 0x0067F560
void __fastcall DRLGOUTDESR_AddExits(D2DrlgLevelStrc* pLevel);                                              // 0x0067F670
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                                  // 0x00642BB0
int __fastcall DRLGOUTDOORS_SpawnPresetFarAway(D2DrlgLevelStrc* pLevel, D2DrlgCoordStrc* pCoords, int nLevelPrestId, int nPickedFile, int a5, int a6); // 0x006744F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                // 0x0067C570
void __stdcall sub_0067FE90_PlaceColumns(D2DrlgLevelStrc* pLevel, int nColumn);                             // 0x0067FE90

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern const D2DrlgOutDesertInitStrc gaDesertCliffs[8][5];                                         // 0x006F2390
extern const D2DrlgOutDesertInitStrc gaCanyonTombEntries[9];                                       // 0x006F2610

static inline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
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

// 0x0067F470
static void __stdcall DRLGOUTDESR_PlacePresetVariants(const int* pLevelPrestIds, int nVariants, int bIterateFiles, D2DrlgLevelStrc* pLevel)
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

static void DRLGOUTDESR_PlaceCliffs(D2DrlgLevelStrc* pLevel)
{
    const unsigned int nRand = SEED_RollRandomNumber_Inline(&pLevel->pSeed) & 7;

    for (int i = 0; i < 5; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, gaDesertCliffs[nRand][i].nX, gaDesertCliffs[nRand][i].nY, gaDesertCliffs[nRand][i].nLvlPrestId, gaDesertCliffs[nRand][i].nRand, 0);
    }
}

static void DRLGOUTDESR_PlaceTombEntriesInCanyon(D2DrlgLevelStrc* pLevel)
{
    for (int i = 0; i < 9; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, gaCanyonTombEntries[i].nX, gaCanyonTombEntries[i].nY, gaCanyonTombEntries[i].nLvlPrestId, gaCanyonTombEntries[i].nRand, 0);
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 4, 4, 0x18A, -1, 0);
}

void __fastcall DRLGOUTDESR_InitAct2OutdoorLevel(D2DrlgLevelStrc* pLevel); // 0x0067F980

// 0x0067FC70
static int DRLGOUTWILD_TestSpawnRiver(int nX, D2DrlgLevelStrc* pLevel)
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
static int __stdcall DRLGOUTWILD_SpawnCliffCaves(D2DrlgLevelStrc* pLevel, int nX, int nY)
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

static inline unsigned int SEED_RollRandomNumberHighFirst_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int DRLG_IsBloodmoor_Inline(D2DrlgLevelStrc* pLevel)
{
    if (!pLevel)
    {
        return 0;
    }
    return pLevel->eLevelId == LEVEL_BLOODMOOR;
}

static inline unsigned __int64 SEED_RollRandomNumber64_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

// 0x00680200
void __stdcall sub_00680200_SpawnRiverAndCliffCaves(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == LEVEL_MOOMOOFARM)
    {
        return;
    }

    int nX;
    int nY;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    if (pOutdoors->dwFlags & 0xC)
    {
        nX = pOutdoors->nGridWidth - 2;
        if (DRLGOUTWILD_TestSpawnRiver(nX, pLevel))
        {
            sub_0067FE90_PlaceColumns(pLevel, nX);
        }
    }

    if ((pOutdoors->dwFlags & 0x20) && !(pOutdoors->dwFlags & 0x40))
    {
        int bAdded = 0;
        if (SEED_RollRandomNumberHighFirst_Inline(&pLevel->pSeed) & 1)
        {
            for (nX = 0; nX < pOutdoors->nGridHeight; ++nX)
            {
                if (bAdded)
                {
                    break;
                }

                for (nY = 0; nY < pOutdoors->nGridWidth; ++nY)
                {
                    if (bAdded)
                    {
                        break;
                    }

                    bAdded = DRLGOUTWILD_SpawnCliffCaves(pLevel, nX, nY);
                }
            }
        }
        else
        {
            for (nY = 0; nY < pOutdoors->nGridHeight; ++nY)
            {
                if (bAdded)
                {
                    break;
                }

                for (nX = 0; nX < pOutdoors->nGridWidth; ++nX)
                {
                    if (bAdded)
                    {
                        break;
                    }

                    bAdded = DRLGOUTWILD_SpawnCliffCaves(pLevel, nX, nY);
                }
            }
        }

        D2_ASSERT(bAdded, 0x194);
    }

    if ((pOutdoors->dwFlags & 0x1C) && !(pOutdoors->dwFlags & 0x40))
    {
        int nCornerX = pOutdoors->nGridWidth - ((pOutdoors->dwFlags & 0x10) ? 4 : 5);
        int nCornerY = pOutdoors->nGridHeight - 4;
        const int nRand = (int)(SEED_RollRandomNumber64_Inline(&pLevel->pSeed) & 3);
        if (nRand % 2)
        {
            nCornerX = 3;
        }

        if (nRand / 2)
        {
            nCornerY = 3;
        }
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nCornerX, nCornerY, DRLG_IsBloodmoor_Inline(pLevel) + 0x33, -1, 0);
        pOutdoors->dwFlags |= 0x40;
    }
}

void DRLGOUTWILD_SpawnTownTransitionsAndCaves(D2DrlgLevelStrc* pLevel); // 0x006803D0
void __fastcall sub_A14_Emit_006803D0(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 2, 4);
    DRLGOUTWILD_SpawnTownTransitionsAndCaves(pLevel);
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 3, 4);
}
