#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"

struct D2LvlWarpTxt
{
    int dwLevelId;
};


struct D2RoomTileStrc
{
    D2DrlgRoomStrc* pDrlgRoom;
    D2RoomTileStrc* pNext;
    int bEnabled;
    D2DrlgTileDataStrc* unk0x0C;
    D2LvlWarpTxt* pLvlWarpTxtRecord;
    D2DrlgTileDataStrc* unk0x14;
};


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
            if (pRoomTile->unk0x14)
            {
                for (D2DrlgTileDataStrc* i = pRoomTile->unk0x14; i; i = i->pNext)
                {
                    i->dwFlags &= 0xFFFFFFF7;
                }

                for (D2DrlgTileDataStrc* i = pRoomTile->unk0x0C; i; i = i->pNext)
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
            if (pRoomTile->unk0x0C)
            {
                for (D2DrlgTileDataStrc* i = pRoomTile->unk0x0C; i; i = i->pNext)
                {
                    i->dwFlags &= 0xFFFFFFF7;
                }

                for (D2DrlgTileDataStrc* i = pRoomTile->unk0x14; i; i = i->pNext)
                {
                    i->dwFlags |= 8;
                }
            }
            return;
        }
    }
}
