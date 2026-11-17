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
    unsigned int dwFlags;
    D2DrlgGridStrc pGrid[4];
};

struct D2DrlgLevelStrc
{
    char pad_00[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
};

struct D2LvlPrestTxt
{
    char pad_00[0x28];
    int dwSizeX;
    int dwSizeY;
};

D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLvlPrestId); // 0x0061F0B0
int __fastcall DRLGGRID_IsPointInsideGridArea(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C4A0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570

static __forceinline int DRLGOUTDOORS_GetPackedGrid2Info(D2DrlgOutdoorInfoStrc* pOutdoors, int nX, int nY)
{
    return DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY);
}

static __forceinline int DRLGOUTDOORS_TestGridCellSpawnValid(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    return !(DRLGOUTDOORS_GetPackedGrid2Info(pLevel->pOutdoors, nX, nY) & 0x1B81);
}

// 0x00674230
int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nOffset, int nFlags)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nSizeX;
    int nSizeY;
    if (!nLevelPrestId)
    {
        nSizeX = 1;
        nSizeY = 1;
    }
    else
    {
        D2LvlPrestTxt* pLvlPrestTxtRecord = DATATBLS_GetLvlPrestTxtRecord(nLevelPrestId);
        nSizeX = pLvlPrestTxtRecord->dwSizeX / 8;
        nSizeY = pLvlPrestTxtRecord->dwSizeY / 8;
    }

    if (nOffset)
    {
        if (nFlags & 1)
        {
            nY -= nOffset;
            nSizeY += nOffset;
        }
        if (nFlags & 2)
        {
            nSizeX += nOffset;
        }
        if (nFlags & 4)
        {
            nSizeY += nOffset;
        }
        if (nFlags & 8)
        {
            nX -= nOffset;
            nSizeX += nOffset;
        }
    }
    const int nYEnd = nY + nSizeY;
    for (int i = nY; i < nYEnd; ++i)
    {

        for (int j = nX; j < nX + nSizeX; ++j)
        {
            if (!DRLGGRID_IsPointInsideGridArea(&pOutdoors->pGrid[2], j, i) || !DRLGOUTDOORS_TestGridCellSpawnValid(pLevel, j, i))
            {
                return 0;
            }
        }
    }

    return 1;
}
