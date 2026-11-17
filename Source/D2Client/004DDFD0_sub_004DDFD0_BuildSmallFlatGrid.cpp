struct D2GridCellStrc
{
    unsigned char nB0;
    unsigned char nB1;
    unsigned char nB2;
    unsigned char nB3;
    int nX;
    int nY;
};

struct D2GridCoordStrc
{
    int n;
};

extern int gnGlobal_0071146C;                                                                               // 0x0071146C

static __declspec(noinline) void __stdcall sub_004DDFD0_BuildSmallFlatGrid(D2GridCoordStrc tX, int nY, int bCorners, D2GridCellStrc* pCells, int nMode);

// 0x004DDFD0
static void __stdcall sub_004DDFD0_BuildSmallFlatGrid(D2GridCoordStrc tX, int nY, int bCorners, D2GridCellStrc* pCells, int nMode)
{
    switch (nMode)
    {
    case 1:
        tX.n -= gnGlobal_0071146C / 4;
        break;
    case 2:
        tX.n += gnGlobal_0071146C / 4;
        break;
    }

    for (int j = 0; j < 6; ++j)
    {
        for (int i = 0; i < 6; ++i)
        {
            if (!bCorners || (i == 0 && j == 0) || (i == 5 && j == 0) || (i == 5 && j == 5) || (i == 0 && j == 5))
            {
                pCells->nB0 = 0xFF;
                pCells->nX = 16 * (i - j) + tX.n;
                pCells->nY = nY + 8 * (i + j);
                pCells->nB1 = 0xFF;
                pCells->nB3 = 0xFF;
                pCells->nB2 = 0xFF;
            }
            ++pCells;
        }
    }
}

// build: context sub_004DDFD0_Shim
// calling-convention shim (not game code)
void __fastcall sub_004DDFD0_Shim(D2GridCellStrc* pCells, int nMode, int nX, int nY, int bCorners)
{
    D2GridCoordStrc tX;
    tX.n = nX;
    sub_004DDFD0_BuildSmallFlatGrid(tX, nY, bCorners, pCells, nMode);
}
