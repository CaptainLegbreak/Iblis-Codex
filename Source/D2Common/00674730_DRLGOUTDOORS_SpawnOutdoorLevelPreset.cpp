struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int field_10;
};

struct D2DrlgOutdoorInfoStrc
{
    int field_00;
    D2DrlgGridStrc tGrid04;
    char pad_after_grid[20];
    D2DrlgGridStrc tGridFlags;
    char pad_after_flags[28];
    int nGridWidth;
    int nGridHeight;
};

struct D2SeedStrc
{
    unsigned int dwLow;
    unsigned int dwHigh;
};

struct D2DrlgLevelStrc
{
    char pad_00[20];
    D2DrlgOutdoorInfoStrc* pOutdoor;
    char pad_after_outdoor[428];
    D2SeedStrc tSeed;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nOffset, char nFlags); // 0x00674230
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int bBorder); // 0x006743C0

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->dwHigh + (unsigned __int64)pSeed->dwLow * 0x6AC690C5;
    pSeed->dwHigh = (unsigned int)(lSeed >> 32);
    pSeed->dwLow = (unsigned int)lSeed;
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
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x00674730
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags)
{
    D2CoordStrc pCoord[256];

    const int nWidth = pLevel->pOutdoor->nGridWidth - 2;
    const int nArea = nWidth * (pLevel->pOutdoor->nGridHeight - 2);

    if (nArea)
    {
        for (int i = 0; i < nArea; ++i)
        {
            pCoord[i].nX = i % nWidth;
            pCoord[i].nY = i / nWidth;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const unsigned int nRand1 = SEED_RollLimitedRandomNumber(&pLevel->tSeed, nArea);
            const unsigned int nRand2 = SEED_RollLimitedRandomNumber(&pLevel->tSeed, nArea);

            const D2CoordStrc tCoord = pCoord[nRand1];
            pCoord[nRand1] = pCoord[nRand2];
            pCoord[nRand2] = tCoord;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const int nX = pCoord[i].nX + 1;
            const int nY = pCoord[i].nY + 1;

            if (DRLGOUTDOORS_TestOutdoorLevelPreset(pLevel, nX, nY, nLevelPrestId, nOffset, nFlags))
            {
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nLevelPrestId, nRand, 0);
                return 1;
            }
        }
    }

    return 0;
}
