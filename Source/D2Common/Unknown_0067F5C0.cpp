#include "D2Common.h"
#include "D2Structs.h"
#include "D2Drlg.h"

typedef char G04_CheckSeedOffset[(int)&((D2DrlgLevelStrc*)0)->pSeed == 0x1C4 ? 1 : -1];
typedef char G04_CheckLevelIdOffset[(int)&((D2DrlgLevelStrc*)0)->eLevelId == 0x1D0 ? 1 : -1];

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0

extern const int gaDesertCliffs_006F2390[8][5][4];                                                         // 0x006F2390

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x0067F5C0
static __declspec(noinline) void DRLGOUTDESR_PlaceCliffs(D2DrlgLevelStrc* pLevel)
{
    const unsigned int nRand = SEED_RollRandomNumber_Inline(&pLevel->pSeed) & 7;

    const int* pEntry = &gaDesertCliffs_006F2390[nRand][0][3];
    for (int i = 0; i < 5; ++i, pEntry += 4)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, pEntry[-1], pEntry[0], pEntry[-3], pEntry[-2], 0);
    }
}

void __fastcall sub_G04_Emit_0067F5C0(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDESR_InitAct2OutdoorLevel(pLevel);
    DRLGOUTDESR_PlaceCliffs(pLevel);
    DRLGOUTDESR_InitAct2OutdoorLevel(pLevel);
}

#include "gen/data/Source/D2Common/Unknown_0067F5C0.inc"
