struct D2DrlgGridStrc { char unknown[0x14]; };
struct D2RoomCoordListStrc;
struct D2DrlgTileDataStrc { char unknown0[0x10]; D2RoomCoordListStrc* pCoordList; };
struct D2DrlgLogicalRoomInfoStrc { unsigned int dwFlags; char unknown4[0x18]; D2DrlgGridStrc pIndexY; };
struct D2DrlgRoomStrc {
    char unknown0[0x34]; int nPosX; int nPosY;
    char unknown3c[0x28]; D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo;
};
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570

// 0x0066C620
int __fastcall sub_0066C620(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY)
{
    int nCoordList = 0;
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo = pDrlgRoom->pLogicalRoomInfo;
    if (!pLogicalRoomInfo)
    {
        pTileData->pCoordList = 0;
    }
    else if (pLogicalRoomInfo->dwFlags & 1)
    {
        pTileData->pCoordList = 0;
    }
    else
    {
        nCoordList = DRLGGRID_GetGridEntry(&pLogicalRoomInfo->pIndexY, nX - pDrlgRoom->nPosX, nY - pDrlgRoom->nPosY);
        pTileData->pCoordList = (D2RoomCoordListStrc*)nCoordList;
    }
    return nCoordList;
}
