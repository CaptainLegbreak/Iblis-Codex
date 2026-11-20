#include "D2Structs.h"
#include "D2Drlg.h"



extern "C" const char gszEmptyAssertText;      // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall DRLGOUTDOORS_GetPresetIndexFromGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674120
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6); // 0x006743C0

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return SEED_RollRandomNumber_Inline(pSeed) % nMax;
    return SEED_RollRandomNumber_Inline(pSeed) & (nMax - 1);
}

static __forceinline int sub_0067E210_PlaceShiftedPreset(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    const int nPreset = DRLGOUTDOORS_GetPresetIndexFromGridCell(pLevel, nX, nY);
    if (nPreset >= 0x393 && nPreset <= 0x39A)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPreset + 0x10, -1, 0);
        return 1;
    }
    return 0;
}

// 0x0067E240
static void sub_0067E240(D2DrlgLevelStrc* pLevel);

static __declspec(noinline) void sub_0067E240(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId != 111)
        return;

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    if (!pInfo)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 564);
        exit(-1);
    }

    int nPlaced;
    int i;
    for (i = 0, nPlaced = 0; i < 90 && nPlaced < 3; ++i)
    {
        const int nX = 2 * SEED_RollLimitedRandomNumber(&pLevel->pSeed, pInfo->nGridWidth / 2);
        const int nY = 2 * SEED_RollLimitedRandomNumber(&pLevel->pSeed, pInfo->nGridHeight / 2);
        if (sub_0067E210_PlaceShiftedPreset(pLevel, nX, nY))
            ++nPlaced;
    }

    const int nOffsetX = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, pInfo->nGridWidth / 2);
    const int nOffsetY = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, pInfo->nGridHeight / 2);
    for (int y = 0; y < pInfo->nGridHeight && nPlaced < 3; ++y)
    {
        for (int x = 0; x < pInfo->nGridWidth && nPlaced < 3; ++x)
        {
            const int nX = (x + 2 * nOffsetX) % pInfo->nGridWidth;
            const int nY = (y + 2 * nOffsetY) % pInfo->nGridHeight;
            if (sub_0067E210_PlaceShiftedPreset(pLevel, nX, nY))
                ++nPlaced;
        }
    }

    if (nPlaced < 3)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 601);
        exit(-1);
    }
}

void __fastcall sub_Emit_0067E240(D2DrlgLevelStrc* pLevel)
{
    sub_0067E240(pLevel);
    sub_0067E240(pLevel);
}
