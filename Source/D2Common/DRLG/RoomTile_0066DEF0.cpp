#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgTiles.h"
struct D2CmpTileStrc;




void __fastcall DRLGROOMTILE_InitTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY, unsigned int nPackedTileInformation, D2CmpTileStrc* pTileLibraryEntry); // 0x0066DDE0

// 0x0066DEF0
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitFloorTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2CmpTileStrc* pTileLibraryEntry)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    D2DrlgTileDataStrc* pTileData = &pTileGrid->pFloorTiles[pTileGrid->nFloors];
    if (ppTileData)
    {
        pTileData->pNext = *ppTileData;
        *ppTileData = pTileData;
    }
    else
    {
        pTileData->pNext = 0;
    }

    ++pTileGrid->nFloors;

    DRLGROOMTILE_InitTileData(pDrlgRoom, pTileData, nX, nY, nPackedTileInformation, pTileLibraryEntry);
    return pTileData;
}
