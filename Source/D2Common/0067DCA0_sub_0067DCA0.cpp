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
    char unk0x00[0x2C];
    D2DrlgGridStrc tGrid;
    char unk0x40[0x1C];
    int nWidth;
    int nHeight;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoorInfo;
};

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int nOperation); // 0x0067C4F0
static __declspec(noinline) void sub_0067DCA0(D2DrlgLevelStrc* pLevel);

// 0x0067DCA0
static void sub_0067DCA0(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;

    const int nX = pInfo->nWidth - 2;
    const int nY = pInfo->nHeight - 3;
    D2DrlgGridStrc* const pGrid = &pInfo->tGrid;
    DRLGGRID_AlterGridFlag(pGrid, pInfo->nWidth - 2, pInfo->nHeight - 4, 0x400, 0);
    DRLGGRID_AlterGridFlag(pGrid, nX, nY, 0x400, 0);
}

// build: context EmitMarkLevel111Exit

// calling-convention shim (not game code)
void __stdcall EmitMarkLevel111Exit(D2DrlgLevelStrc* pLevel)
{
    sub_0067DCA0(pLevel);
}
