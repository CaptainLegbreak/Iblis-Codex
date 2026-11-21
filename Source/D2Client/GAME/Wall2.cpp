#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Win32Types.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2WallCellStrc;
struct D2WallCtxStrc;
struct D2StaticPathStrc;
struct Obj004DCF10;

struct D2WallRoomArgStrc
{
    D2WallCtxStrc* pCtx;
    tagRECT tRect;
    D2ActiveRoomStrc* pRoom;
    int nValue;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* hPath); // 0x006488C0
unsigned int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

struct Obj004DCF10 {
    unsigned char bUnknown00[0x38];
    unsigned int dwValue38;
    unsigned char bUnknown3C[0xEA9C - 0x3C];
    unsigned int dwValueEA9C;
    unsigned int dwUnknownEAA0;
    unsigned int dwUnknownEAA4;
    unsigned int dwValueEAA8;
    unsigned int dwUnknownEAAC;
    unsigned int dwValueEAB0;
};

static tagRECT s_tWallRect_007C8A14;

static unsigned int s_nPlayerX_007C8A08;

static int s_nCollision_007C8A0C;

static unsigned int s_nPlayerY_007C8A10;

struct D2ViewStrc
{
    char unk0x00[0x38];
    int nField0x38;
    char unk0x3C[0xEA60];
    int nField0xEA9C;
    char unk0xEAA0[8];
    void* pCells;
    char unk0xEAAC[4];
    int nField0xEAB0;
};

// 0x004DCE60
static void sub_004DCE60_ResizeWallCells(D2WallCtxStrc* pCtx)
{
    const int nWidth = (pCtx->nRight - pCtx->nLeft) / 160 + 11;
    const int nHeight = (pCtx->nBottom - pCtx->nTop) / 80 + 12;
    const int nSize = nHeight + nWidth - 1;
    const int nCount = nSize * nSize;
    if (!pCtx->pCells || nCount != pCtx->nCellCount)
    {
        if (pCtx->pCells)
            FOG_Free(pCtx->pCells, ".\\GAME\\Wall2.cpp", 0x3A, 0);
        pCtx->pCells = (D2WallCellStrc*)FOG_Alloc(nCount * sizeof(D2WallCellStrc), ".\\GAME\\Wall2.cpp", 0x3D, 0);
        pCtx->nCellCount = nCount;
    }
    pCtx->nSize = nSize;
    pCtx->nWidth = nWidth;
    pCtx->nHeight = nHeight;
}

static unsigned int GetUnitXPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 2 || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nXPos;
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static unsigned int GetUnitYPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 2 || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nYPos;
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

void __fastcall sub_004DDB70_PrepareWallCells(D2WallCtxStrc* pCtx, int nValue)
{
    sub_004DCE60_ResizeWallCells(pCtx);
    D2WallRoomArgStrc tArg;
    tArg.pCtx = pCtx;
    tArg.nValue = nValue;
    if (sub_004F51D0_IsPerspective())
        SetRect(&tArg.tRect, pCtx->nX - 0x30, pCtx->nY - 0x30, pCtx->nRight - pCtx->nLeft + pCtx->nX + 0x30, pCtx->nBottom - pCtx->nTop + pCtx->nY);
    else
        SetRect(&tArg.tRect, pCtx->nX, pCtx->nY, pCtx->nRight - pCtx->nLeft + pCtx->nX, pCtx->nBottom - pCtx->nTop + pCtx->nY);
    s_tWallRect_007C8A14 = tArg.tRect;
    pCtx->nUnk0xEA9C = 0;
    pCtx->nUnk0x38 = 0;
    D2_ASSERT(pCtx->pCells, 0x33C);
    memset(pCtx->pCells, 0, pCtx->nCellCount * sizeof(D2WallCellStrc));
    int nOriginX;
    int nOriginY;
    sub_00643340(pCtx->nX, pCtx->nY, &nOriginX, &nOriginY);
    nOriginX -= 3;
    nOriginY -= pCtx->nWidth;
    pCtx->f_EAA0 = nOriginX;
    pCtx->f_EAA4 = nOriginY;
    D2WallCellStrc* pCell = pCtx->pCells;
    for (unsigned int nRow = 0; nRow < pCtx->nSize; ++nRow)
    {
        for (unsigned int nColumn = 0; nColumn < pCtx->nSize; ++nColumn)
        {
            pCell->nX = nOriginX + nColumn;
            pCell->nY = nOriginY + nRow;
            ++pCell;
        }
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x351);
    tArg.pRoom = sub_004646A0_GetPlayerRoom();
    s_nPlayerX_007C8A08 = GetUnitXPosition_Inline(pPlayer) / 5;
    s_nPlayerY_007C8A10 = GetUnitYPosition_Inline(pPlayer) / 5;
    s_nCollision_007C8A0C = sub_0061B130_GetCollision(UNITS_GetRoom(pPlayer), GetUnitXPosition_Inline(pPlayer), GetUnitYPosition_Inline(pPlayer));
    sub_00619BD0(tArg.pRoom, sub_004DD7C0, &tArg);
}

// 0x004DCF10
extern "C" __declspec(dllexport) void __fastcall sub_004DCF10(Obj004DCF10* pObj) {
    pObj->dwValueEAB0 = 0;
    pObj->dwValueEA9C = 0;
    pObj->dwValue38 = 0;
    pObj->dwValueEAA8 = 0;
}

// 0x004DCF30
void __fastcall sub_004DCF30(D2ViewStrc* pView)
{
    if (pView->pCells)
    {
        FOG_Free(pView->pCells, ".\\GAME\\Wall2.cpp", 0x55, 0);
    }

    pView->pCells = 0;
    pView->nField0xEAB0 = 0;
    pView->nField0xEA9C = 0;
    pView->nField0x38 = 0;
}

