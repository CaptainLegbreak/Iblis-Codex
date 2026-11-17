struct D2DrlgGridStrc
{
    char unk0x00[0x14];
};

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
    D2DrlgGridStrc pGrid[4];
    int nWidth;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
};

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                // 0x0067C570

// 0x00674120
int __fastcall DRLGOUTDOORS_GetPresetIndexFromGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    if (!(DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY) & 0x200))
    {
        return 0;
    }
    return DRLGGRID_GetGridEntry(&pOutdoors->pGrid[0], nX, nY);
}
