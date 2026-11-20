#include "D2Common.h"
#include "D2Drlg.h"
struct D2TileLibraryEntryStrc;

struct D2DrlgCoordStrc;
struct D2DrlgRoomTilesStrc;
struct D2DrlgTileDataStrc;
struct D2DrlgAnimTileGridStrc;


struct D2DrlgRoomTilesStrc
{
    void* pWallTiles;
    int nWalls;
    void* pFloorTiles;
    int nFloors;
    void* pRoofTiles;
    int nRoofs;
};

struct D2DrlgTileGridStrc
{
    void* pMapLinks;
    D2DrlgAnimTileGridStrc* pAnimTiles;
    int nWalls;
    int nFloors;
    int nShadows;
    union
    {
        struct
        {
            D2DrlgRoomTilesStrc pTiles;
        };
        struct
        {
            D2DrlgTileDataStrc* pWallTiles;
            unsigned char unk_18[0x4];
            D2DrlgTileDataStrc* pFloorTiles;
            unsigned char unk_20[0x4];
            D2DrlgTileDataStrc* pRoofTiles;
        };
    };
};


int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
int __stdcall TileLibraryGetTiles(void** ppTiles, int nTileType, int nStyle, int nSequence, D2TileLibraryEntryStrc** ppTileEntries, int nMaxEntries); // 0x00604AE0
int __stdcall TileGetFlags(D2TileLibraryEntryStrc* hTile); // 0x00604BC0

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

void __fastcall DRLGANIM_AllocAnimationTileGrid(D2DrlgGridStrc* pGrid, D2DrlgRoomStrc* pRoom, int nAnimationSpeed, D2DrlgTileDataStrc* pTiles, int nTiles); // 0x0066D440

// 0x0066D290
void __fastcall DRLGANIM_TestLoadAnimatedRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pDrlgGrid, D2DrlgGridStrc* pTileTypeGrid, int nTileType, int nTileX, int nTileY)
{
    D2TileLibraryEntryStrc* ppTileEntries[40];

    const int nWidth = (nTileX == 0) + pDrlgRoom->pDrlgCoord.nWidth;
    const int nHeight = (nTileY == 0) + pDrlgRoom->pDrlgCoord.nHeight;
    D2DrlgRoomTilesStrc* pRoomTiles = &pDrlgRoom->ptDrlgTiles->pTiles;

    for (int nY = 0; nY < nHeight; ++nY)
    {
        for (int nX = 0; nX < nWidth; ++nX)
        {
            const unsigned int nTileInfo = DRLGGRID_GetGridEntry(pDrlgGrid, nX, nY);
            if (nTileInfo & 0x8000003)
            {
                const int nType = pTileTypeGrid ? DRLGGRID_GetGridEntry(pTileTypeGrid, nX, nY) : nTileType;

                unsigned char nStyle;
                unsigned char nSequence;
                if (nTileInfo)
                {
                    nStyle = (unsigned char)(nTileInfo >> 20) & 0x3F;
                    nSequence = (unsigned char)(nTileInfo >> 8);
                }
                else
                {
                    nStyle = 0;
                    nSequence = 0;
                }

                const int nTiles = TileLibraryGetTiles(&pDrlgRoom->pTiles, nType, nStyle, nSequence, ppTileEntries, 40);
                if (nTiles && TileGetFlags(ppTileEntries[0]) & 0x100)
                {
                    if (nTileInfo & 2)
                    {
                        pRoomTiles->nFloors += nTiles - 1;
                    }
                    else if (nTileInfo & 1)
                    {
                        pRoomTiles->nWalls += nTiles - 1;
                    }
                    else
                    {
                        pRoomTiles->nRoofs += nTiles - 1;
                    }

                    pDrlgRoom->dwFlags |= 0x8000000;
                }
            }
        }
    }
}

// build: symbol ?DRLGANIM_AnimateRoomTiles@@YAXPAUD2DrlgRoomStrc@@@Z 0x0066D3B0
static void DRLGANIM_AnimateRoomTiles(D2DrlgRoomStrc* pRoom)
{
    if (pRoom->dwFlags & 0x8000000 && pRoom->ptDrlgTiles)
    {
        for (D2DrlgAnimTileGridStrc* pAnim = pRoom->ptDrlgTiles->pAnimTiles; pAnim; pAnim = pAnim->pNext)
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
    D2DrlgTileGridStrc* pTileGrid = pRoom->ptDrlgTiles;
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
            if (pRoom1->ppRoomsNear[i]->ptDrlgTiles && pRoom1->ppRoomsNear[i]->ptDrlgTiles->pAnimTiles)
            {
                nCurrentFrame = pRoom1->ppRoomsNear[i]->ptDrlgTiles->pAnimTiles->nCurrentFrame;
                break;
            }
        }
    }

    for (int i = 0; i < pRoom2->nRoomsNear; ++i)
    {
        if (D2DrlgTileGridStrc* pTileGrid = pRoom2->ppRoomsNear[i]->ptDrlgTiles)
        {
            for (D2DrlgAnimTileGridStrc* pAnim = pTileGrid->pAnimTiles; pAnim; pAnim = pAnim->pNext)
            {
                pAnim->nCurrentFrame = nCurrentFrame;
            }
        }
    }
}
