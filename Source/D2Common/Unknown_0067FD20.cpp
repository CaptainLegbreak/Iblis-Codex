#include "D2Common.h"
#include "D2Structs.h"
#include "D2Drlg.h"

struct D2OutdoorColumnFilesStrc
{
    int nLeft;
    int nRight;
};
extern D2OutdoorColumnFilesStrc gColumnFiles_006F2680[]; // 0x006F2680

// build: context SEED_RollRandomNumber_Inline
static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// build: context SEED_RollLimitedRandomNumber_Inline
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

static void __stdcall sub_0067FD20_PlacePair(int nColumn, D2DrlgLevelStrc* pLevel);

// 0x0067FD20
static void __stdcall sub_0067FD20_PlacePair(int nColumn, D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoors;
    const int bBridge = pOutdoor->dwFlags & 4;
    const int nRowRange = pOutdoor->nGridHeight - 2;
    const int nRand = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, nRowRange);
    for (int i = 0; i < nRowRange; ++i)
    {
        const int nY = (nRand + i) % nRowRange + 1;
        if (bBridge)
        {
            if (!sub_00674200_IsValid(pLevel, nColumn - 1, nY))
                continue;
        }
        else
        {
            if (!sub_00674200_IsValid(pLevel, nColumn - 1, nY))
                continue;
            if (!sub_00674200_IsValid(pLevel, nColumn + 2, nY))
                continue;
        }
        if ((sub_0067C570_GetGrid(&pOutdoor->pGrid[2], nColumn, nY) & 0xF0000) == 0x30000
            && (sub_0067C570_GetGrid(&pOutdoor->pGrid[2], nColumn + 1, nY) & 0xF0000) == 0x30000)
        {
            sub_006743C0_PlacePreset(pLevel, nColumn, nY, 28, 1, 0);
            sub_006743C0_PlacePreset(pLevel, nColumn + 1, nY, 28, bBridge ? 3 : 2, 0);
            return;
        }
    }
}

// build: context sub_0067FE90_PlaceColumns
void __stdcall sub_0067FE90_PlaceColumns(D2DrlgLevelStrc* pLevel, int nColumn)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoors;
    for (int nRow = 0; nRow < pOutdoor->nGridHeight; ++nRow)
    {
        int nFlags = sub_0067C570_GetGrid(&pOutdoor->pGrid[2], nColumn, nRow);
        int nType = sub_0067C570_GetGrid(&pOutdoor->pGrid[0], nColumn, nRow);
        int nFile;
        if (nType)
        {
            if (nType == 7 && (nFlags & 0xF0000) == 0x30000)
                nFile = 3;
            else
                nFile = gColumnFiles_006F2680[nType].nLeft;
        }
        else
            nFile = (nFlags & 0x100) ? 0 : 3;
        sub_006743C0_PlacePreset(pLevel, nColumn, nRow, 26, nFile, 0);

        nFlags = sub_0067C570_GetGrid(&pOutdoor->pGrid[2], nColumn + 1, nRow);
        nType = sub_0067C570_GetGrid(&pOutdoor->pGrid[0], nColumn + 1, nRow);
        if (nType)
        {
            if (nType == 7 && (nFlags & 0xF0000) == 0x30000)
                nFile = 3;
            else
                nFile = gColumnFiles_006F2680[nType].nRight;
        }
        else
            nFile = (nFlags & 0x100) ? 0 : 3;
        sub_006743C0_PlacePreset(pLevel, nColumn + 1, nRow, 27, nFile, 0);
    }
    if (pOutdoor->dwFlags & 0x14)
        sub_0067FD20_PlacePair(nColumn, pLevel);
}
