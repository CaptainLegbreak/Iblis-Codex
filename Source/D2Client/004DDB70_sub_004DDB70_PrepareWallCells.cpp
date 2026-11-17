struct tagRECT
{
    int left;
    int top;
    int right;
    int bottom;
};

struct D2WallCellStrc
{
    char unk0x00[0x8];
    int nX;
    int nY;
    char unk0x10[0x14];
};

struct D2WallCtxStrc
{
    char unk0x00[0x4];
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
    char unk0x14[0x10];
    int nX;
    int nY;
    char unk0x2C[0xC];
    int nUnk0x38;
    char unk0x3C[0xEA60];
    int nUnk0xEA9C;
    int f_EAA0;
    int f_EAA4;
    D2WallCellStrc* pCells;
    int nCellCount;
    unsigned int nSize;
    int nWidth;
    int nHeight;
};

struct D2DynamicPathStrc;

struct D2WallPointStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0xC];
    unsigned int nXPos;
    unsigned int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2ActiveRoomStrc;

struct D2WallRoomArgStrc
{
    D2WallCtxStrc* pCtx;
    tagRECT tRect;
    D2ActiveRoomStrc* pRoom;
    int nValue;
};

static tagRECT s_tWallRect_007C8A14; // 0x007C8A14

static unsigned int s_nPlayerX_007C8A08; // 0x007C8A08

static int s_nCollision_007C8A0C; // 0x007C8A0C

static unsigned int s_nPlayerY_007C8A10; // 0x007C8A10

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __cdecl sub_004F51D0_IsPerspective();                                                                   // 0x004F51D0
void __stdcall sub_00643340(int nX, int nY, int* pX, int* pY);                                              // 0x00643340
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
unsigned int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                         // 0x006488C0
unsigned int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                         // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall sub_0061B130_GetCollision(D2ActiveRoomStrc* pRoom, int nX, int nY);                           // 0x0061B130
void __stdcall sub_00619BD0(D2ActiveRoomStrc* pRoom, void* pfCallback, D2WallRoomArgStrc* pArg);            // 0x00619BD0
void __stdcall sub_004DD7C0(D2ActiveRoomStrc* pRoom, D2WallRoomArgStrc* pArg);                              // 0x004DD7C0

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
    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(pPlayer, 0x351);
    tArg.pRoom = sub_004646A0_GetPlayerRoom();
    s_nPlayerX_007C8A08 = GetUnitXPosition_Inline(pPlayer) / 5;
    s_nPlayerY_007C8A10 = GetUnitYPosition_Inline(pPlayer) / 5;
    s_nCollision_007C8A0C = sub_0061B130_GetCollision(UNITS_GetRoom(pPlayer), GetUnitXPosition_Inline(pPlayer), GetUnitYPosition_Inline(pPlayer));
    sub_00619BD0(tArg.pRoom, sub_004DD7C0, &tArg);
}
