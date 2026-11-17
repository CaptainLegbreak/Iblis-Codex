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
    int field_18;
    int nPosX;
    int nPosY;
    char pad_after_pos[416];
    D2SeedStrc tSeed;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
};

int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nOffset, int nFlags); // 0x00674230
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

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

// 0x006744F0
int __fastcall DRLGOUTDOORS_SpawnPresetFarAway(D2DrlgLevelStrc* pLevel, D2DrlgCoordsStrc* pCoords, int nLevelPrestId, int nPickedFile, int a5, int a6)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoor;
    const int nPosX = pLevel->nPosX;
    const int nPosY = pLevel->nPosY;
    const int nWidth = pOutdoor->nGridWidth - 2;
    const int nHeight = pOutdoor->nGridHeight - 2;
    const int nOffsetX = SEED_RollLimitedRandomNumber(&pLevel->tSeed, nWidth);
    const int nOffsetY = SEED_RollLimitedRandomNumber(&pLevel->tSeed, nHeight);
    int nBestDistance = 0;
    const int nCenterX = pCoords->nSubtileWidth / 2 + pCoords->nSubtileX;
    const int nCenterY = pCoords->nSubtileHeight / 2 + pCoords->nSubtileY;
    int nBestX = -1;
    int nBestY = -1;

    for (int j = 0; j <= nHeight; ++j)
    {
        for (int i = 0; i <= nWidth; ++i)
        {
            const int nY = (j + nOffsetY) % nHeight + 1;
            const int nX = (i + nOffsetX) % nWidth + 1;
            if (DRLGOUTDOORS_TestOutdoorLevelPreset(pLevel, nX, nY, nLevelPrestId, a5, a6))
            {
                const int nDeltaX = 8 * nX - nCenterX + nPosX + 4;
                const int nDiffX = D2_ABS(nDeltaX);
                const int nDeltaY = 8 * nY - nCenterY + nPosY + 4;
                const int nDiffY = D2_ABS(nDeltaY);
                const int nDistance = (nDiffX > nDiffY ? nDiffY + 2 * nDiffX : nDiffX + 2 * nDiffY) / 2;
                if (nBestDistance < nDistance)
                {
                    nBestDistance = nDistance;
                    nBestX = nX;
                    nBestY = nY;
                }
            }
        }
    }

    if (nBestX != -1 && nBestY != -1)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nBestX, nBestY, nLevelPrestId, nPickedFile, 0);
        return 1;
    }

    return 0;
}
