#include "D2Common.h"

struct D2DrlgOutdoorInfoStrc;
struct D2CoordStrc;

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
    int unk0x00;
    D2DrlgGridStrc tGrid04;
    unsigned char unk_18[0x14];
    D2DrlgGridStrc tGrid;
    char unk0x40[0x1C];
    int nWidth;
    int nHeight;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoorInfo;
    char unk0x18[0x1B8];
    int nLevelId;
};

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int nOperation); // 0x0067C4F0
static __declspec(noinline) void sub_0067DCA0(D2DrlgLevelStrc* pLevel);

struct D2CoordStrc
{
    int nX;
    int nY;
};

int __fastcall sub_0067C570(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
void __fastcall sub_006743C0(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6); // 0x006743C0
extern const D2CoordStrc gAct5WallSteps_006F1FD8[12]; // 0x006F1FD8

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

// 0x0067DEF0
void __stdcall sub_0067DEF0(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    int nRight = pInfo->nWidth - 2;
    int nX = nRight;
    int nY = 0;
    int nBottom = pInfo->nHeight - 2;
    int bTundra = pLevel->nLevelId == 117;
    int nKindBase = bTundra ? 0x3BD : 0x371;
    int nPresetBase = bTundra ? 0x3C9 : 0x37D;

    while (nX != 0 || nY != nBottom)
    {
        const int nEntry = sub_0067C570(&pInfo->tGrid04, nX, nY);
        sub_006743C0(pLevel, nX, nY, nEntry - nKindBase + nPresetBase, -1, 0);
        nX += 2 * gAct5WallSteps_006F1FD8[nEntry - nKindBase].nX;
        nY += 2 * gAct5WallSteps_006F1FD8[nEntry - nKindBase].nY;
    }

    sub_006743C0(pLevel, nRight, 0, bTundra ? 0x3D6 : 0x38A, -1, 0);
    sub_006743C0(pLevel, 0, nBottom, bTundra ? 0x3D5 : 0x389, -1, 0);
}
