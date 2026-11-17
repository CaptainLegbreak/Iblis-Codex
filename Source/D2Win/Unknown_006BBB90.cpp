struct D2CacheListStrc;

struct D2TileLibraryBlockStrc
{
    int unk0x00;
    short nCacheSlot;
    short unk0x06;
    int unk0x08[3];
};

struct D2TileLibraryEntryStrc
{
    char unk0x00[0x42];
    short nCacheSlot;
    char unk0x44[0x0C];
    int nBlocks;
    D2TileLibraryBlockStrc* pBlocks;
};

extern D2CacheListStrc gBlockCache_0096FC80; // 0x0096FC80
extern D2CacheListStrc gTileCache_0096FC9C; // 0x0096FC9C

void __fastcall sub_006BB390_MoveNode(D2CacheListStrc* pCache, int nIndex); // 0x006BB390
void __fastcall sub_006BAD70_MoveNode(D2CacheListStrc* pCache, int nIndex); // 0x006BAD70

// 0x006BBB90
void __fastcall sub_006BBB90_InvalidateTileCaches(D2TileLibraryEntryStrc* pTile)
{
    if (pTile->nCacheSlot > 0)
    {
        sub_006BB390_MoveNode(&gTileCache_0096FC9C, (short)(pTile->nCacheSlot - 1));
    }

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        if (pTile->pBlocks[i].nCacheSlot > 0)
        {
            sub_006BAD70_MoveNode(&gBlockCache_0096FC80, (short)(pTile->pBlocks[i].nCacheSlot - 1));
        }
    }
}
