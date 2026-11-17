struct D2DrlgGridStrc
{
    char unk0x00[0x14];
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2DrlgPresetRoomStrc
{
    char unk0x00[0x10];
    D2DrlgGridStrc pWallGrid[4];
    char unk0x60[0x90];
    D2CoordStrc* pTombStoneTiles;
    int nTombStoneTiles;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x20];
    D2DrlgPresetRoomStrc* pMaze;
    char unk0x24[0x10];
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

extern "C" const char gszDrlgPresetSourceFile_006EE7C4[];                                                   // 0x006EE7C4
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY);                            // 0x0067C570
void __stdcall DUNGEON_GameTileToSubtileCoords(int* pX, int* pY);                                           // 0x00643560

// 0x00666990
static void sub_00666990(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    int nTombStoneTiles = 0;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    if (pMaze->pTombStoneTiles)
        return;

    pMaze->pTombStoneTiles = (D2CoordStrc*)FOG_AllocPool(pMemPool, 6 * sizeof(D2CoordStrc), gszDrlgPresetSourceFile_006EE7C4, 1964, 0);
    for (int i = 0; i < pDrlgRoom->nTileHeight; ++i)
    {
        for (int j = 0; j < pDrlgRoom->nTileWidth; ++j)
        {
            const unsigned int nPacked = DRLGGRID_GetGridEntry(pMaze->pWallGrid, j, i);
            const unsigned char nTileStyle = (nPacked >> 20) & 0x3F;
            const unsigned char nTileSequence = (unsigned char)(nPacked >> 8);
            if (nTileStyle == 10 && nTileSequence >= 23 && nTileSequence <= 27)
            {
                if (nTombStoneTiles < 6)
                {
                    int nY;
                    int nX;
                    nX = j + pDrlgRoom->nTileXPos;
                    nY = i + pDrlgRoom->nTileYPos;
                    DUNGEON_GameTileToSubtileCoords(&nX, &nY);
                    nX += 2;
                    nY += 2;
                    pMaze->pTombStoneTiles[nTombStoneTiles].nX = nX;
                    pMaze->pTombStoneTiles[nTombStoneTiles].nY = nY;
                    ++nTombStoneTiles;
                }
            }
        }
    }
    pMaze->nTombStoneTiles = nTombStoneTiles;
}

void __fastcall sub_Z16_EmitTombStoneTiles(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool)
{
    if (pDrlgRoom->nTileWidth == 9)
        sub_00666990(pMemPool, pDrlgRoom);
}
