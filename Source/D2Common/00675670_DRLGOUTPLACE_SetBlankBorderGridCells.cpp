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

struct D2DrlgLevelStrc
{
    char pad_00[20];
    D2DrlgOutdoorInfoStrc* pOutdoor;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation);            // 0x0067C4F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY);                                     // 0x0067C570

// 0x00675670
void __fastcall DRLGOUTPLACE_SetBlankBorderGridCells(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoor;
    const D2CoordStrc aOffsets[4][2] = {
        {{  0,  0 }, {  1,  1 }},
        {{  1,  0 }, { -1,  1 }},
        {{  0,  1 }, {  1, -1 }},
        {{  1,  1 }, { -1, -1 }}
    };

    for (int k = 0; k < 4; ++k)
    {
        int nX = aOffsets[k][0].nX;
        if (nX)
        {
            nX = pOutdoor->nGridWidth - 1;
        }

        int nY = aOffsets[k][0].nY;
        if (nY)
        {
            nY = pOutdoor->nGridHeight - 1;
        }

        int nDirX = aOffsets[k][1].nX;
        int nDirY = aOffsets[k][1].nY;

        int i = nX;
        int j = nY;
        while (!(DRLGGRID_GetGridEntry(&pOutdoor->tGridFlags, nX, j) & 1))
        {
            while (!(DRLGGRID_GetGridEntry(&pOutdoor->tGridFlags, i, j) & 1))
            {
                DRLGGRID_AlterGridFlag(&pOutdoor->tGridFlags, i, j, 0x100, 0);
                i += nDirX;
            }
            j += nDirY;
            i = nX;
        }
    }
}
