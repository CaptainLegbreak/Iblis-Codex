#include "D2Game.h"

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2GameStrc
{
    char unk0x00[0x7C];
    unsigned int dwInitSeed;
    char unk0x80[0x04];
    int InitSeed;
    char unk0x88[0x48];
    D2SeedStrc pGameSeed;
};

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerPartsStrc* pCount);     // 0x006CC25C
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

#include "gen/data/Source/D2Game/Unknown_0052C280/gnInitSeed_00731004.inc"

inline unsigned __int64 sub_I08_RollGameSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0052C280
static void sub_0052C280_InitGameSeed(D2GameStrc* pGame)
{
    if (gnInitSeed_00731004 == -1)
    {
        pGame->InitSeed = 0;
        D2LargeIntegerPartsStrc tCount;
        QueryPerformanceCounter(&tCount);
        SEED_InitSeed(&pGame->pGameSeed);
        SEED_InitLowSeed(&pGame->pGameSeed, SEED_GetRandomValue(tCount.LowPart));
        pGame->dwInitSeed = SEED_GetRandomValue((int)sub_I08_RollGameSeed(&pGame->pGameSeed));
    }
    else
    {
        pGame->InitSeed = 1;
        pGame->dwInitSeed = gnInitSeed_00731004;
        SEED_InitSeed(&pGame->pGameSeed);
        SEED_InitLowSeed(&pGame->pGameSeed, gnInitSeed_00731004);
    }
}

void sub_I08_Emit_0052C280(D2GameStrc* pGame)
{
    sub_0052C280_InitGameSeed(pGame);
}
