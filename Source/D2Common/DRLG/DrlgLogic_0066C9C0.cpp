#include "D2Common.h"

struct D2DrlgTileDataStrc
{
    int unk0x00[2];
    int nPosX;
    int nPosY;
    int nCoordList;
    int unk0x14[7];
};

struct D2DrlgRoomTilesStrc
{
    D2DrlgTileDataStrc* pWallTiles;
    unsigned int nWalls;
};

struct D2RoomTileGridStrc
{
    char unk0x00[0x14];
    D2DrlgRoomTilesStrc pTiles;
};

struct D2DrlgLogicalRoomInfoStrc
{
    unsigned int dwFlags;
    char unk0x04[0x18];
    char pIndexY[0x14];
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x34];
    int nTileXPos;
    int nTileYPos;
    char unk0x3C[0x18];
    D2RoomTileGridStrc* pTileGrid;
    char unk0x58[0x0C];
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo;
};

int __fastcall DRLGGRID_GetGridEntry(void* pDrlgGrid, int nX, int nY); // 0x0067C570

// 0x0066C9C0
void __stdcall DRLGLOGIC_SetCoordListForTiles(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgRoomTilesStrc* pTiles = &pDrlgRoom->pTileGrid->pTiles;
    for (unsigned int i = 0; i < pTiles->nWalls; ++i)
    {
        D2DrlgTileDataStrc* pTile = &pTiles->pWallTiles[i];
        int nY = pTile->nPosY + pDrlgRoom->nTileYPos;
        int nX = pTile->nPosX + pDrlgRoom->nTileXPos;
        if (!pDrlgRoom->pLogicalRoomInfo)
            pTile->nCoordList = 0;
        else if (pDrlgRoom->pLogicalRoomInfo->dwFlags & 1)
            pTile->nCoordList = 0;
        else
        {
            nX -= pDrlgRoom->nTileXPos;
            nY -= pDrlgRoom->nTileYPos;
            pTile->nCoordList = DRLGGRID_GetGridEntry(pDrlgRoom->pLogicalRoomInfo->pIndexY, nX, nY);
        }
    }
}
