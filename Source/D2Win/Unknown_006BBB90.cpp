#include "D2DrlgMaps.h"
#include "D2GlideTypes.h"

struct D2CacheListStrc;

extern D2CacheListStrc gBlockCache_0096FC80; // 0x0096FC80
extern D2CacheListStrc gTileCache_0096FC9C; // 0x0096FC9C

void __fastcall sub_006BB390_MoveNode(D2CacheListStrc* pCache, int nIndex); // 0x006BB390
void __fastcall sub_006BAD70_MoveNode(D2CacheListStrc* pCache, int nIndex); // 0x006BAD70

// 0x006BBB90
void __fastcall sub_006BBB90_InvalidateTileCaches(D2TileLibraryEntryStrc* pTile)
{
    if (pTile->nCacheIndex > 0)
    {
        sub_006BB390_MoveNode(&gTileCache_0096FC9C, (short)(pTile->nCacheIndex - 1));
    }

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        if (pTile->pBlocks[i].nCacheIndex > 0)
        {
            sub_006BAD70_MoveNode(&gBlockCache_0096FC80, (short)(pTile->pBlocks[i].nCacheIndex - 1));
        }
    }
}
