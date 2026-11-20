#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"
#include "D2DrlgMaps.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2TileStrc;
struct D2GridRectStrc;
struct D2GridOwnerStrc;
struct D2GridUnitStrc;
struct D2GridLightStrc;
struct D2GridCoordStrc;
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2DrlgCoordsStrc;
struct D2FloorViewArgStrc;
struct D2FloorTileViewStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

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

    void __thiscall sub_004DE410_ApplyUnitLight(D2GridUnitStrc* pUnit, int nArg, int nX, int nY, int nSubX, int nSubY);
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
static __declspec(noinline) void __stdcall sub_004DDEF0_BuildLargeGrid(int nX, int nY, int bFlat, D2GridCellStrc* pCells);

static __declspec(noinline) void __stdcall sub_004DDFD0_BuildSmallFlatGrid(D2GridCoordStrc tX, int nY, int bCorners, D2GridCellStrc* pCells, int nMode);
static __declspec(noinline) void __stdcall sub_004DE190_BuildSmallGrid(int nSubX, int nSubY, int nZ, int bCorners, D2GridCellStrc* pCells, int nMode);







struct D2FloorViewArgStrc
{
    char unk0x00[0x24];
    int nX;
    int nY;
};

struct D2FloorTileViewStrc
{
    int nMode;
    int bPerspective;
    int bTickFlag;
    int bMudFlag;
    int nPhase;
    unsigned int dwTickA;
    unsigned int dwTickB;
    D2SeedStrc* pSeed;
    int nBorder;
    D2FloorViewArgStrc* pArg;
    int bEdges;
    int nMinX;
    int nMaxX;
    int nMinY;
    int nMaxY;
    int nOffsetX;
    int nOffsetY;
    void __thiscall sub_004DE410_DrawFloorTile(D2TileStrc* pTile, int nArg, int nScreenX, int nScreenY, int nX, int nY);
    void __thiscall sub_004DE630_DrawTileAt(int nX, int nY);
    void __thiscall sub_004DE6C0_DrawTileTriple(int nX, int nY, int nStepX, int nStepY);
    void __thiscall sub_004DE730_UpdateView(void* pArgument);
};

int __cdecl sub_0044DB00(); // 0x0044DB00
int __cdecl sub_0045AE90(); // 0x0045AE90
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
int __cdecl sub_00473770_IsMudLevel(); // 0x00473770
float __cdecl sub_00473C80_GetPhaseLevel(); // 0x00473C80
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __stdcall D2GFX_CheckPerspective(); // 0x004F51D0
int __cdecl sub_004F5210(); // 0x004F5210
D2DrlgTileDataStrc* __stdcall DUNGEON_GetFloorTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pFloorCount); // 0x00619660
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

// build: context sub_B08_FillCellsInline
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

// 0x004DE190
static void __stdcall sub_004DE190_BuildSmallGrid(int nSubX, int nSubY, int nZ, int bCorners, D2GridCellStrc* pCells, int nMode)
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
        const int nY = nSubY + j;
        for (int i = 0; i < 6; ++i, ++pCells)
        {
            if (!bCorners || (i == 0 && j == 0) || (i == 5 && j == 0) || (i == 5 && j == 5) || (i == 0 && j == 5))
            {
                sub_004F6760((nSubX + i) << 16, nY << 16, nZ, &pCells->nX, &pCells->nY);
                pCells->nX += nShift;
                pCells->nB0 = 0xFF;
                pCells->nB1 = 0xFF;
                pCells->nB3 = 0xFF;
                pCells->nB2 = 0xFF;
            }
        }
    }
}

// 0x004DE410
void __thiscall D2GridLightStrc::sub_004DE410_ApplyUnitLight(D2GridUnitStrc* pUnit, int nArg, int nX, int nY, int nSubX, int nSubY)
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
                sub_004DE190_BuildSmallGrid(nSubX, nSubY, 0, bCorners, tSmall, nMode);
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
                D2GridCoordStrc tX;
                tX.n = nX;
                sub_004DDFD0_BuildSmallFlatGrid(tX, nY, bCorners, tSmall, nMode);
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

static __forceinline int CLIENTS_GetUnitX_FloorView(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitY_FloorView(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004DE730
void __thiscall D2FloorTileViewStrc::sub_004DE730_UpdateView(void* pArgument)
{
    D2ActiveRoomStrc** ppRooms;
    int nRooms;
    int nTiles;

    nMode = sub_004F5210();
    bPerspective = D2GFX_CheckPerspective();
    const unsigned int dwTick = sub_0044DB00();
    bTickFlag = 0;
    bMudFlag = 0;
    nPhase = (int)(sub_00473C80_GetPhaseLevel() * 1000.0);
    const int nBorderType = sub_0045AE90();
    nBorder = nBorderType;
    pArg = (D2FloorViewArgStrc*)pArgument;

    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    bEdges = pRoom && DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom))->nDrawEdges && !nBorderType && D2GFX_GetResolutionMode() == 2;

    nMinX = 0x7FFFFFFF;
    nMaxX = 0x80000000;
    nMinY = 0x7FFFFFFF;
    nMaxY = 0x80000000;
    nOffsetX = 0x50 - pArg->nX;
    nOffsetY = -0x50 - pArg->nY;

    if (dwTick > dwTickA + 3)
    {
        dwTickA = dwTick;
        if (nPhase)
            bTickFlag = 1;
    }

    if (sub_00473770_IsMudLevel() && dwTick > dwTickB + 0x19)
    {
        dwTickB = dwTick;
        bMudFlag = 1;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x11E);
    pSeed = &pPlayer->pSeed;

    pRoom = sub_004646A0_GetPlayerRoom();
    if (!pRoom)
        return;

    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
    D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxt, 0x130);
    const int bNoFilter = pLevelsTxt->dwFloorFilter == 0;

    const int& nViewX = nOffsetX;
    for (int i = 0; i < nRooms; ++i)
    {
        D2DrlgCoordsStrc tCoords;
        DUNGEON_GetRoomCoordinates(ppRooms[i], &tCoords);
        for (unsigned int nLayer = 1; nLayer < 3; ++nLayer)
        {
            const int bArg = !bNoFilter && nLayer == 1;
            D2DrlgTileDataStrc* pTile = DUNGEON_GetFloorTilesFromRoom(ppRooms[i], &nTiles);
            while (nTiles)
            {
                if (((pTile->dwFlags >> 0xE) & 7) == nLayer)
                {
                    sub_004DE410_DrawFloorTile((D2TileStrc*)pTile, bArg, nViewX + pTile->nWidth,
                        pTile->nHeight + nOffsetY, tCoords.nSubtileX + 5 * pTile->nPosX, tCoords.nSubtileY + 5 * pTile->nPosY);
                }
                --nTiles;
                ++pTile;
            }
        }
    }

    if (!bEdges)
        return;

    const int nRangeA = bPerspective ? 0x21 : 0x1E;
    const int nRangeB = bPerspective ? 0x17 : 0x19;
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    if (!pUnit)
        return;

    const int nX = CLIENTS_GetUnitX_FloorView(pUnit);
    const int nY = CLIENTS_GetUnitY_FloorView(pUnit);
    if (nX - nMinX < nRangeA)
        sub_004DE6C0_DrawTileTriple(nMinX - 5, nY, 0, -5);
    if (nMaxX - nX < nRangeB)
        sub_004DE6C0_DrawTileTriple(nMaxX + 5, nY, 0, 5);
    if (nY - nMinY < nRangeA)
        sub_004DE6C0_DrawTileTriple(nX, nMinY - 5, -5, 0);
    if (nMaxY - nY < nRangeB)
        sub_004DE6C0_DrawTileTriple(nX, nMaxY + 5, 5, 0);
}
