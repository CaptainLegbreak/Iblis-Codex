#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgTiles.h"



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


int __fastcall DRLGGRID_GetGridEntry(void* pDrlgGrid, int nX, int nY); // 0x0067C570

// 0x0066C9C0
void __stdcall DRLGLOGIC_SetCoordListForTiles(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgRoomTilesStrc* pTiles = &pDrlgRoom->ptDrlgTiles->pTiles;
    for (unsigned int i = 0; i < pTiles->nWalls; ++i)
    {
        D2DrlgTileDataStrc* pTile = &pTiles->pWallTiles[i];
        int nY = pTile->nPosY + pDrlgRoom->pDrlgCoord.nPosY;
        int nX = pTile->nPosX + pDrlgRoom->pDrlgCoord.nPosX;
        if (!pDrlgRoom->pLogicalRoomInfo)
            pTile->pCoordList = 0;
        else if (pDrlgRoom->pLogicalRoomInfo->dwFlags & 1)
            pTile->pCoordList = 0;
        else
        {
            nX -= pDrlgRoom->pDrlgCoord.nPosX;
            nY -= pDrlgRoom->pDrlgCoord.nPosY;
            pTile->pCoordList = (D2RoomCoordListStrc*)DRLGGRID_GetGridEntry(pDrlgRoom->pLogicalRoomInfo->pIndexY, nX, nY);
        }
    }
}
