#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgTiles.h"
#include "D2TxtTables.h"





// 0x0066AB70
void __fastcall DRLGWARP_ToggleRoomTilesEnableFlag(D2DrlgRoomStrc* pDrlgRoom, int bEnabled)
{
    for (D2RoomTileStrc* i = pDrlgRoom->pRoomTiles; i; i = i->pNext)
    {
        i->bEnabled = bEnabled;
    }
}

// 0x0066AB90
void __fastcall DRLGWARP_UpdateWarpRoomSelect(D2DrlgRoomStrc* pDrlgRoom, int nLevelId)
{
    for (D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
    {
        if (pRoomTile->pLvlWarpTxtRecord->dwLevelId == nLevelId)
        {
            if (pRoomTile->pSelectedTiles)
            {
                for (D2DrlgTileDataStrc* i = pRoomTile->pSelectedTiles; i; i = i->pNext)
                {
                    i->dwFlags &= 0xFFFFFFF7;
                }

                for (D2DrlgTileDataStrc* i = pRoomTile->pUnselectedTiles; i; i = i->pNext)
                {
                    i->dwFlags |= 8;
                }
            }
            return;
        }
    }
}

// 0x0066ABE0
void __fastcall DRLGWARP_UpdateWarpRoomDeselect(D2DrlgRoomStrc* pDrlgRoom, int nLevelId)
{
    for (D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
    {
        if (pRoomTile->pLvlWarpTxtRecord->dwLevelId == nLevelId)
        {
            if (pRoomTile->pUnselectedTiles)
            {
                for (D2DrlgTileDataStrc* i = pRoomTile->pUnselectedTiles; i; i = i->pNext)
                {
                    i->dwFlags &= 0xFFFFFFF7;
                }

                for (D2DrlgTileDataStrc* i = pRoomTile->pSelectedTiles; i; i = i->pNext)
                {
                    i->dwFlags |= 8;
                }
            }
            return;
        }
    }
}

#include "gen/data/Source/D2Common/Unknown_0066AB70.inc"
