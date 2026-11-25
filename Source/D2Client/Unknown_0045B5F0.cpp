#include "D2LanguageNames.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2Win32Types.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2TileLibraryEntryStrc;
struct D2DrlgCoordStrc;
struct D2RoomCoordListStrc;
struct D2DrlgCoordsStrc;
struct D2StaticPathStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2DrlgTileDataStrc* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pWallCount); // 0x006196A0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
D2RoomCoordListStrc* __stdcall DUNGEON_GetRoomCoordList(D2ActiveRoomStrc* pRoom); // 0x0061AD50
void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY); // 0x00643310
int __stdcall TileGetFlags(D2TileLibraryEntryStrc* pTile); // 0x00604BC0
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380
void __fastcall CUNIT_DrawAutomapDiamond(int nX, int nY, unsigned char nColor); // 0x0045B1A0
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
extern int gnAutomapOriginY; // 0x007A5208
extern int gnAutomapOriginX; // 0x007A520C

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
int __cdecl sub_004F5140(); // 0x004F5140
void __stdcall AUTOMAP_DrawRoomCollision(D2ActiveRoomStrc* pRoom); // 0x0045B4F0
void __stdcall sub_0045B5F0(D2ActiveRoomStrc* pRoom); // 0x0045B5F0

// 0x0045B5F0
void __stdcall sub_0045B5F0(D2ActiveRoomStrc* pRoom)
{
    int nTiles;
    D2DrlgTileDataStrc* pTiles = DUNGEON_GetWallTilesFromRoom(pRoom, &nTiles);
    D2_ASSERT(pTiles || !nTiles, 725);

    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    for (unsigned int i = 0; i < (unsigned int)nTiles; ++i)
    {
        D2DrlgTileDataStrc* pTile = &pTiles[i];
        if (!pTile->pCoordList)
        {
            continue;
        }

        int nX = (pTile->nPosX + tCoords.nTileXPos) * 5 + 3;
        int nY = (pTile->nPosY + tCoords.nTileYPos) * 5 + 3;
        DUNGEON_GameSubtileToClientCoords(&nX, &nY);

        if (pTile->nTileType == 15 || (pTile->dwFlags & 0x1C000) != 0x4000)
        {
            continue;
        }

        if (TileGetFlags(pTile->pTile) & 4)
        {
            const int nDiamondX = nX + 0x20;
            tagRECT tRect;
            tRect.left = nDiamondX - gnAutomapOriginX - 0x10;
            tRect.right = nDiamondX - gnAutomapOriginX + 0x10;
            tRect.top = nY - gnAutomapOriginY;
            tRect.bottom = nY - gnAutomapOriginY + 0x10;
            D2GFX_UtilDiamond(&tRect, 0x78);
        }
        else if (pTile->dwFlags & 0x800)
        {
            CUNIT_DrawAutomapDiamond(nX + 0x10, nY + 8, 0x78);
        }
        else
        {
            CUNIT_DrawAutomapDiamond(nX, nY, 0xFF);
        }

        nX -= gnAutomapOriginX + 7;
        nY -= gnAutomapOriginY;
        D2GFX_OutputString(nX, nY, gszFormatInt_006D57BC, pTile->pCoordList->nIndex);
    }

    if (pRoom == CUNIT_GetPlayerRoom())
    {
        int aX[4];
        int aY[4];
        for (D2RoomCoordListStrc* pCoordList = DUNGEON_GetRoomCoordList(pRoom); pCoordList; pCoordList = pCoordList->pNext)
        {
            aX[0] = aX[1] = pCoordList->pBox[0].left;
            aX[2] = aX[3] = pCoordList->pBox[0].right;
            aY[0] = aY[2] = pCoordList->pBox[0].top;
            aY[1] = aY[3] = pCoordList->pBox[0].bottom;

            for (int j = 0; j < 4; ++j)
            {
                DUNGEON_GameTileToClientCoords(&aX[j], &aY[j]);
                aX[j] -= gnAutomapOriginX;
                aY[j] -= gnAutomapOriginY;
            }

            if (pRoom == CUNIT_GetPlayerRoom())
            {
                D2GFX_DrawLine(aX[0], aY[0], aX[0], aY[0] + 0x10, 0x78, 0xFF);
                D2GFX_DrawLine(aX[1], aY[1], aX[1] + 0x10, aY[1], 0x78, 0xFF);
                D2GFX_DrawLine(aX[2], aY[2], aX[2] - 0x10, aY[2], 0x78, 0xFF);
                D2GFX_DrawLine(aX[3], aY[3], aX[3], aY[3] - 0x10, 0x78, 0xFF);
            }

            D2GFX_DrawLine(aX[0], aY[0], aX[1], aY[1], 0x78, 0xFF);
            D2GFX_DrawLine(aX[0], aY[0], aX[2], aY[2], 0x78, 0xFF);
            D2GFX_DrawLine(aX[1], aY[1], aX[3], aY[3], 0x78, 0xFF);
            D2GFX_DrawLine(aX[2], aY[2], aX[3], aY[3], 0x78, 0xFF);
        }
    }
}

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0045B8B0
void __cdecl sub_0045B8B0_DrawLogicalRoom()
{
    if (sub_004F5140() == 3)
        return;

    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    int nX = UNITS_GetXPositionInline(pPlayer);
    int nY = UNITS_GetYPositionInline(pPlayer);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    D2GFX_OutputString(10, 0x37, "Logical Room->%d", sub_0061B130_GetCollision(pRoom, nX, nY));
    AUTOMAP_DrawRoomCollision(pRoom);
    sub_0045B5F0(pRoom);
}

// 0x0045BA90
extern "C" void* __fastcall sub_0045BA90(void* value) { return value; }

#include "gen/data/Source/D2Client/Unknown_0045B5F0.inc"
