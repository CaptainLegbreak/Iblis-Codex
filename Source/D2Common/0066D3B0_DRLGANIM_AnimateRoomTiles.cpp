struct D2DrlgTileDataStrc
{
    char unk0x00[0x14];
    unsigned int dwFlags;
};

struct D2DrlgAnimTileGridStrc
{
    D2DrlgTileDataStrc** ppMapTileData;
    int nFrames;
    int nCurrentFrame;
    int nAnimationSpeed;
    D2DrlgAnimTileGridStrc* pNext;
};

struct D2DrlgTileGridStrc
{
    void* pMapLinks;
    D2DrlgAnimTileGridStrc* pAnimTiles;
    int nWalls;
    int nFloors;
    int nShadows;
    D2DrlgTileDataStrc* pWallTiles;
    int nWallTiles;
    D2DrlgTileDataStrc* pFloorTiles;
    int nFloorTiles;
    D2DrlgTileDataStrc* pRoofTiles;
    int nRoofTiles;
};

struct D2DrlgGridStrc;

struct D2DrlgRoomStrc
{
    char unk0x00[0x8];
    D2DrlgRoomStrc** ppRoomsNear;
    char unk0x0C[0x1C];
    unsigned int dwFlags;
    int nRoomsNear;
    char unk0x30[0x24];
    D2DrlgTileGridStrc* pTileGrid;
};

void __fastcall DRLGANIM_AllocAnimationTileGrid(D2DrlgGridStrc* pGrid, D2DrlgRoomStrc* pRoom, int nAnimationSpeed, D2DrlgTileDataStrc* pTiles, int nTiles);   // 0x0066D440

// build: symbol ?DRLGANIM_AnimateRoomTiles@@YAXPAUD2DrlgRoomStrc@@@Z 0x0066D3B0
static void DRLGANIM_AnimateRoomTiles(D2DrlgRoomStrc* pRoom)
{
    if (pRoom->dwFlags & 0x8000000 && pRoom->pTileGrid)
    {
        for (D2DrlgAnimTileGridStrc* pAnim = pRoom->pTileGrid->pAnimTiles; pAnim; pAnim = pAnim->pNext)
        {
            if (pAnim->ppMapTileData[pAnim->nCurrentFrame >> 8])
            {
                pAnim->ppMapTileData[pAnim->nCurrentFrame >> 8]->dwFlags |= 8;
            }

            pAnim->nCurrentFrame = (pAnim->nCurrentFrame + pAnim->nAnimationSpeed) % (pAnim->nFrames << 8);

            if (pAnim->ppMapTileData[pAnim->nCurrentFrame >> 8])
            {
                pAnim->ppMapTileData[pAnim->nCurrentFrame >> 8]->dwFlags &= ~8;
            }
        }
    }
}

// 0x0066D410
void __fastcall DRLGANIM_AnimateTiles(D2DrlgRoomStrc* pRoom)
{
    for (int i = 0; i < pRoom->nRoomsNear; ++i)
    {
        DRLGANIM_AnimateRoomTiles(pRoom->ppRoomsNear[i]);
    }
}

// 0x0066D700
void __fastcall DRLGANIM_AllocAnimationTileGrids(D2DrlgRoomStrc* pRoom, int nAnimationSpeed, D2DrlgGridStrc* pWallGrid, int nWalls, D2DrlgGridStrc* pFloorGrid, int nFloors, D2DrlgGridStrc* pShadowGrid)
{
    D2DrlgTileGridStrc* pTileGrid = pRoom->pTileGrid;
    DRLGANIM_AllocAnimationTileGrid(pWallGrid, pRoom, nAnimationSpeed, pTileGrid->pWallTiles, pTileGrid->nWalls);
    DRLGANIM_AllocAnimationTileGrid(pFloorGrid, pRoom, nAnimationSpeed, pTileGrid->pFloorTiles, pTileGrid->nFloors);
    DRLGANIM_AllocAnimationTileGrid(pShadowGrid, pRoom, nAnimationSpeed, pTileGrid->pRoofTiles, pTileGrid->nShadows);
}

// 0x0066D750
void __fastcall DRLGANIM_UpdateFrameInAdjacentRooms(D2DrlgRoomStrc* pRoom1, D2DrlgRoomStrc* pRoom2)
{
    if (!pRoom2)
    {
        return;
    }

    int nCurrentFrame = 0;
    if (pRoom1)
    {
        for (int i = 0; i < pRoom1->nRoomsNear; ++i)
        {
            if (pRoom1->ppRoomsNear[i]->pTileGrid && pRoom1->ppRoomsNear[i]->pTileGrid->pAnimTiles)
            {
                nCurrentFrame = pRoom1->ppRoomsNear[i]->pTileGrid->pAnimTiles->nCurrentFrame;
                break;
            }
        }
    }

    for (int i = 0; i < pRoom2->nRoomsNear; ++i)
    {
        if (D2DrlgTileGridStrc* pTileGrid = pRoom2->ppRoomsNear[i]->pTileGrid)
        {
            for (D2DrlgAnimTileGridStrc* pAnim = pTileGrid->pAnimTiles; pAnim; pAnim = pAnim->pNext)
            {
                pAnim->nCurrentFrame = nCurrentFrame;
            }
        }
    }
}
