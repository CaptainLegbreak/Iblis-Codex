#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Win32Types.h"

struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2WallCellStrc;
struct D2WallCtxStrc;
struct D2WallPointStrc;
struct D2StaticPathStrc;
struct D2ClearPairStrc;
struct D2GridRectStrc;
struct D2GridOwnerStrc;
struct D2GridUnitStrc;
struct D2GridLightStrc;

struct D2WallPointStrc
{
    int nX;
    int nY;
};

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

struct D2ClearPairStrc
{
    char pad0x00[0x14];
    int nFirst;
    int nSecond;

    D2ClearPairStrc();
};

struct D2GridCellStrc
{
    unsigned char nB0;
    unsigned char nB1;
    unsigned char nB2;
    unsigned char nB3;
    int nX;
    int nY;
};

struct D2GridLightStrc
{
    int bCorners;
    int bSmall;
    int bEffectA;
    int bEffectB;
    int nLimitA;
    char pad0x14[0x8];
    int f_1C;
    int nMode;
    D2GridOwnerStrc* pOwner;

    void __thiscall sub_B08_ApplyUnitLight(D2GridUnitStrc* pUnit, int nArg, int nX, int nY, int nSubX, int nSubY);
    void __thiscall sub_004DDE80_UpdateBounds(D2GridUnitStrc* pUnit, int nSubX, int nSubY);     // 0x004DDE80
};

extern void* gpGlobal_007A0634; // 0x007A0634
extern int gnGlobal_0071146C; // 0x0071146C
unsigned char __stdcall sub_0061C0E0(void* pAct); // 0x0061C0E0
void __stdcall sub_0061C0B0(void* pAct, unsigned char* pR, unsigned char* pG, unsigned char* pB); // 0x0061C0B0
void __fastcall sub_00475AA0_ReadGridCell(int nX, int nY, unsigned char* pB0, unsigned char* pB1, unsigned char* pB2, unsigned char* pB3); // 0x00475AA0
int __cdecl sub_00477730(); // 0x00477730
void __stdcall sub_004DE070(D2GridCellStrc* pCells, int nX, int nY, int nSubX, int nSubY, int nZ, int nMode, int bCorners); // 0x004DE070
void __stdcall sub_004DE260(D2GridCellStrc* pCells, int nSubX, int nSubY, int nZ, int nMode, int bCorners); // 0x004DE260
int __fastcall sub_00472280(int nSeed, int nZero, int nMax); // 0x00472280

static tagRECT s_tWallRect_007C8A14; // 0x007C8A14

static unsigned int s_nPlayerX_007C8A08; // 0x007C8A08

static int s_nCollision_007C8A0C; // 0x007C8A0C

static unsigned int s_nPlayerY_007C8A10; // 0x007C8A10

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
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nXPos;
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static unsigned int GetUnitYPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nYPos;
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004DDB70
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
    D2WallPointStrc tOrigin;
    sub_00643340(pCtx->nX, pCtx->nY, &tOrigin.nX, &tOrigin.nY);
    tOrigin.nX -= 3;
    tOrigin.nY -= pCtx->nWidth;
    pCtx->f_EAA0 = tOrigin.nX;
    pCtx->f_EAA4 = tOrigin.nY;
    D2WallCellStrc* pCell = pCtx->pCells;
    for (unsigned int nRow = 0; nRow < pCtx->nSize; ++nRow)
    {
        for (unsigned int nColumn = 0; nColumn < pCtx->nSize; ++nColumn)
        {
            pCell->nX = tOrigin.nX + nColumn;
            pCell->nY = tOrigin.nY + nRow;
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

// 0x004DDDD0
D2ClearPairStrc::D2ClearPairStrc()
{
    nFirst = 0;
    nSecond = 0;
}

// 0x004DDDE0
void __cdecl sub_004DDDE0_Nop()
{
}

// 0x004DDE40
static __forceinline int sub_004DDE40_IsPointInRect(D2GridRectStrc* pRect, int nX, int nY)
{
    D2_ASSERT(pRect, 0x76);
    if (nX < pRect->nLeft || nX >= pRect->nRight || nY < pRect->nTop || nY >= pRect->nBottom)
    {
        return 0;
    }
    return 1;
}

// 0x004DDEC0
static __forceinline void sub_004DDEC0_FillCells(D2GridCellStrc* pCells)
{
    for (int j = 0; j < 8; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            pCells->nB0 = 0xFF;
            pCells->nB1 = 0xFF;
            pCells->nB3 = 0xFF;
            pCells->nB2 = 0xFF;
            ++pCells;
        }
    }
}

int __fastcall sub_M131_Emit_004DDE40(D2GridRectStrc* pRect, int nX, int nY, D2GridCellStrc* pCells)
{
    if (!sub_004DDE40_IsPointInRect(pRect, nX, nY))
    {
        return 0;
    }
    sub_004DDEC0_FillCells(pCells);
    return 1;
}

static void sub_B08_FillCellsInline(D2GridCellStrc* pCells)
{
    for (int j = 0; j < 8; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            pCells->nB0 = 0xFF;
            pCells->nB1 = 0xFF;
            pCells->nB3 = 0xFF;
            pCells->nB2 = 0xFF;
            ++pCells;
        }
    }
}

// 0x004DDEF0
static void __stdcall sub_004DDEF0_BuildLargeGrid(int nX, int nY, int bFlat, D2GridCellStrc* pCells)
{
    if (bFlat)
    {
        const unsigned char nB0 = sub_0061C0E0(gpGlobal_007A0634);
        unsigned char nB1, nB2, nB3;
        sub_0061C0B0(gpGlobal_007A0634, &nB1, &nB2, &nB3);
        for (int j = 0; j < 8; ++j)
        {
            for (int i = 0; i < 8; ++i)
            {
                pCells->nB1 = nB1;
                pCells->nB0 = nB0;
                pCells->nB3 = nB3;
                pCells->nB2 = nB2;
                ++pCells;
            }
        }
        return;
    }

    for (int j = 0; j < 8; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            sub_00475AA0_ReadGridCell(8 * (nX + i - 1), 8 * (nY + j - 1), &pCells->nB0, &pCells->nB1, &pCells->nB2, &pCells->nB3);
            ++pCells;
        }
    }
}

static void __stdcall sub_B08_BuildSmallFlatGrid(int nX, int nY, int bCorners, D2GridCellStrc* pCells, int nMode)
{
    switch (nMode)
    {
    case 1:
        nX -= gnGlobal_0071146C / 4;
        break;
    case 2:
        nX += gnGlobal_0071146C / 4;
        break;
    }

    for (int j = 0; j < 6; ++j)
    {
        for (int i = 0; i < 6; ++i)
        {
            if (!bCorners || ((i == 0 || i == 5) && (j == 0 || j == 5)))
            {
                pCells->nB0 = 0xFF;
                pCells->nX = 16 * (i - j) + nX;
                pCells->nY = nY + 8 * (i + j);
                pCells->nB1 = 0xFF;
                pCells->nB3 = 0xFF;
                pCells->nB2 = 0xFF;
            }
            ++pCells;
        }
    }
}

// build: context sub_B08_BuildSmallGrid
static void __stdcall sub_B08_BuildSmallGrid(int nSubX, int nSubY, int nZ, int bCorners, D2GridCellStrc* pCells, int nMode)
{
    int nShift = 0;
    switch (nMode)
    {
    case 1:
        nShift = -(gnGlobal_0071146C / 4);
        break;
    case 2:
        nShift = gnGlobal_0071146C / 4;
        break;
    }

    for (int j = 0; j < 6; ++j)
    {
        for (int i = 0; i < 6; ++i)
        {
            if (!bCorners || ((i == 0 || i == 5) && (j == 0 || j == 5)))
            {
                sub_004F6760((nSubX + i) << 16, (nSubY + j) << 16, nZ, &pCells->nX, &pCells->nY);
                pCells->nX += nShift;
                pCells->nB0 = 0xFF;
                pCells->nB1 = 0xFF;
                pCells->nB3 = 0xFF;
                pCells->nB2 = 0xFF;
            }
            ++pCells;
        }
    }
}

void __thiscall D2GridLightStrc::sub_B08_ApplyUnitLight(D2GridUnitStrc* pUnit, int nArg, int nX, int nY, int nSubX, int nSubY)
{
    if (pUnit->dwFlags & 0x408)
    {
        return;
    }

    D2GridRectStrc* pRect = &pOwner->tRect;
    D2_ASSERT(pRect, 0x76);
    if (nX < pRect->nLeft || nX >= pRect->nRight || nY < pRect->nTop || nY >= pRect->nBottom)
    {
        return;
    }

    D2GridInfoStrc* pInfo = pUnit->pInfo;
    if (pInfo->nBusy)
    {
        return;
    }

    D2GridCellStrc tLarge[8 * 8];
    D2GridCellStrc tSmall[6 * 6];
    if (sub_00477730() < 4)
    {
        if (pInfo->wFlags & 0x100)
        {
            sub_B08_FillCellsInline(tLarge);
        }
        else
        {
            sub_004DDEF0_BuildLargeGrid(nSubX, nSubY, 0, tLarge);
        }
        sub_004F68E0(pUnit->pInfo, tLarge, nX, nY, nSubX, nSubY, 0xFF, nMode, nArg);
    }
    else
    {
        if (bSmall)
        {
            if (pInfo->wFlags & 0x100)
            {
                sub_B08_BuildSmallGrid(nSubX, nSubY, 0, bCorners, tSmall, nMode);
            }
            else
            {
                sub_004DE260(tSmall, nSubX, nSubY, 0, nMode, bCorners);
            }
        }
        else
        {
            if (pInfo->wFlags & 0x100)
            {
                sub_B08_BuildSmallFlatGrid(nX, nY, bCorners, tSmall, nMode);
            }
            else
            {
                sub_004DE070(tSmall, nX, nY, nSubX, nSubY, 0, nMode, bCorners);
            }
        }
        sub_004F68E0(pUnit->pInfo, tSmall, nX, nY, nSubX, nSubY, 0xFF, nMode, nArg);
    }

    if (pInfo->wFlags & 2)
    {
        const int nRoll = sub_00472280(f_1C, 0, 1000);
        const int nFixX = nSubX << 16;
        const int nFixY = nSubY << 16;
        if (bEffectA && nRoll < nLimitA)
        {
            sub_00472DA0(nX, nY, nFixX, nFixY);
        }
        if (bEffectB && nRoll < 100)
        {
            sub_00472EC0(nX, nY, nFixX, nFixY);
        }
    }

    sub_004DDE80_UpdateBounds(pUnit, nSubX, nSubY);
}
