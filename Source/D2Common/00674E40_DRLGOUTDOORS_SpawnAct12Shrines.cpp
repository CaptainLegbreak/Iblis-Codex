struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int unk0x10;
};

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
    D2DrlgGridStrc pGrid[4];
    char unk0x054[0x08];
    int nGridWidth;
    int nGridHeight;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgRoomStrc;

struct D2DrlgLevelStrc
{
    char unk0x00[0x10];
    D2DrlgRoomStrc* pFirstRoomEx;
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char unk0x18[0x1AC];
    D2SeedStrc pSeed;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

extern "C" const int gdwAct12ShrineFlags_006F061C[4];                                                       // 0x006F061C

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY);                            // 0x0067C570
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pDrlgGrid, int nX, int nY, int nFlag, int nOperation); // 0x0067C4F0

int __fastcall DRLGOUTDOORS_TestGridCellSpawnValid(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    return !(DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY) & 0x1B81);
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollRandomNumberHighFirst(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumberHighFirst(pSeed) % nMax;
    }

    return SEED_RollRandomNumberHighFirst(pSeed) & (nMax - 1);
}

// 0x00674E40
void __fastcall DRLGOUTDOORS_SpawnAct12Shrines(D2DrlgLevelStrc* pLevel, int nShrines)
{
    D2CoordStrc pCoord[256];

    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nIndex = SEED_RollRandomNumber(&pLevel->pSeed) & 3;
    const int nWidth = pOutdoors->nGridWidth - 2;
    const int nArea = nWidth * (pOutdoors->nGridHeight - 2);

    if (nArea)
    {
        for (int i = 0; i < nArea; ++i)
        {
            pCoord[i].nX = i % nWidth;
            pCoord[i].nY = i / nWidth;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const unsigned int nRand1 = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nArea);
            const unsigned int nRand2 = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nArea);

            const D2CoordStrc tCoord = pCoord[nRand1];
            pCoord[nRand1] = pCoord[nRand2];
            pCoord[nRand2] = tCoord;
        }

        for (int i = 0; i < nArea; ++i)
        {
            if (nShrines <= 0)
            {
                break;
            }

            const int nX = pCoord[i].nX + 1;
            const int nY = pCoord[i].nY + 1;

            if (DRLGOUTDOORS_TestGridCellSpawnValid(pLevel, nX, nY))
            {
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[1], nX, nY, gdwAct12ShrineFlags_006F061C[nIndex], 0);
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x1000, 0);
                nIndex = (nIndex + 1) % 4;
                --nShrines;
            }
        }
    }
}

#include "gen/data/Source/D2Common/00674E40_DRLGOUTDOORS_SpawnAct12Shrines.inc"
