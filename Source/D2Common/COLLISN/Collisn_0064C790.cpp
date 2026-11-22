#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgPresets.h"
#include "D2Primitives.h"

enum
{
    COLLIDE_WALL = 0x0001,
    COLLIDE_MISSILE_BARRIER = 0x0004,
    COLLIDE_PRESET = 0x0010,
};

extern "C" const char gszCollisnSourceFile[];

unsigned char* __stdcall TileGetCollisionInfo(D2TileLibraryEntryStrc* pTile);

D2RoomCollisionGridStrc* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom);

void __fastcall DUNGEON_SetCollisionGridInRoom(D2ActiveRoomStrc* pRoom, D2RoomCollisionGridStrc* pGrid);

D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY);

int __fastcall DUNGEON_AreSubtileCoordinatesInsideRoom(D2DrlgCoordsStrc* pDrlgCoords, int nX, int nY);      // 0x00619DF0

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms);

D2DrlgTileDataStrc* __stdcall sub_00619660_GetFloorTiles(D2ActiveRoomStrc* pRoom, int* pCount);

D2DrlgTileDataStrc* __stdcall sub_006196A0_GetWallTiles(D2ActiveRoomStrc* pRoom, int* pCount);

D2DrlgTileDataStrc* __stdcall DUNGEON_GetRoofTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pRoofCount);

void __stdcall sub_0064C580_ClearTileCollisionFlags(D2RoomCollisionGridStrc* pCollisionGrid, int nX, int nY, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0064C580

#define MASK_NO_PATH 0x1000

#define MASK_PET 0x2000

struct D2CoordStrc;

struct D2RoomCollisionGridStrc;

struct D2BoundingBoxStrc;

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesImpl(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms, int nMaxDistance, int nPosIncrementValue); // 0x0064DEA0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

void __fastcall COLLISION_SetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064D060

static void __stdcall sub_0064DDB0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

// build: symbol ?sub_6FD411F0@@YGXPAUD2RoomCollisionGridStrc@@HHPAUD2TileLibraryEntryStrc@@@Z 0x0064C4C0
static void __stdcall sub_6FD411F0(D2RoomCollisionGridStrc* pCollisionGrid, int nX, int nY, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    if (pCollisionGrid && pCollisionGrid->pCollisionMask)
    {
        unsigned char* pFlags = TileGetCollisionInfo(pTileLibraryEntry);
        const int nWidth = pCollisionGrid->pRoomCoords.nSubtileWidth;
        const int nCappedX = nX > 0 ? nX : 0;
        const int nCappedY = nY > 0 ? nY : 0;
        unsigned char* pTmp = &pFlags[5 * (nY - nCappedY + 4) - nX];
        int nIndex = nWidth * nCappedY;
        for (int nYCounter = nCappedY; nYCounter < nY + 5; ++nYCounter)
        {
            unsigned short* pCollisionMask = &pCollisionGrid->pCollisionMask[nIndex];
            for (int nXCounter = nCappedX; nXCounter < nX + 5; ++nXCounter)
                pCollisionMask[nXCounter] |= pTmp[nXCounter];
            pTmp -= 5;
            nIndex += nWidth;
        }
    }
}

// build: context sub_0064C640_SetTileCollisionFlags
static void __stdcall sub_0064C640_SetTileCollisionFlags(D2RoomCollisionGridStrc* pCollisionGrid, int nX, int nY, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    if (pCollisionGrid && pCollisionGrid->pCollisionMask)
    {
        unsigned char* pFlags = TileGetCollisionInfo(pTileLibraryEntry);
        const int nWidth = pCollisionGrid->pRoomCoords.nSubtileWidth;
        const int nCappedY = nY > 0 ? nY : 0;
        const int nEndY = nY + 5;
        const int nCappedX = nX > 0 ? nX : 0;
        const int nEndX = nX + 5;
        unsigned char* pTmp = &pFlags[5 * (nY - nCappedY + 4) - nX + nCappedX];
        int nIndex = nWidth * nCappedY;
        for (int nYCounter = nCappedY; nYCounter < nEndY; ++nYCounter)
        {
            unsigned short* pCollisionMask = &pCollisionGrid->pCollisionMask[nIndex];
            for (int nXCounter = nCappedX; nXCounter < nEndX; ++nXCounter)
                pCollisionMask[nXCounter] = pTmp[nXCounter - nCappedX];
            pTmp -= 5;
            nIndex += nWidth;
        }
    }
}

static void __stdcall sub_0064C700_SetCollisionMaskRect(D2RoomCollisionGridStrc* pCollisionGrid, int nX, int nY, unsigned short nFlags)
{
    if (pCollisionGrid && pCollisionGrid->pCollisionMask)
    {
        const int nWidth = pCollisionGrid->pRoomCoords.nSubtileWidth;
        const int nCappedY = nY > 0 ? nY : 0;
        const int nEndY = nY + 5;
        const int nCappedX = nX > 0 ? nX : 0;
        const int nEndX = nX + 5;
        int nIndex = nWidth * nCappedY;
        for (int nYCounter = nCappedY; nYCounter < nEndY; ++nYCounter)
        {
            unsigned short* pCollisionMask = &pCollisionGrid->pCollisionMask[nIndex];
            for (int nXCounter = nCappedX; nXCounter < nEndX; ++nXCounter)
                pCollisionMask[nXCounter] |= nFlags;
            nIndex += nWidth;
        }
    }
}

// 0x0064C790
static void __stdcall sub_6FD413E0(D2RoomCollisionGridStrc* pCollisionGrid, D2RoomCollisionGridStrc* pAdjacentCollisionGrid, D2DrlgTileDataStrc* pTiles, int nTiles, int bRemoveOldFlags)
{
    for (int i = 0; i < nTiles; ++i)
    {
        int nX = pTiles[i].nPosX + pAdjacentCollisionGrid->pRoomCoords.nTileXPos;
        int nY = pTiles[i].nPosY + pAdjacentCollisionGrid->pRoomCoords.nTileYPos;
        DUNGEON_GameTileToSubtileCoords(&nX, &nY);
        if (DUNGEON_AreSubtileCoordinatesInsideRoom(&pCollisionGrid->pRoomCoords, nX, nY))
        {
            const int nRelX = nX - pCollisionGrid->pRoomCoords.nSubtileX;
            const int nRelY = nY - pCollisionGrid->pRoomCoords.nSubtileY;
            if (bRemoveOldFlags)
                sub_0064C640_SetTileCollisionFlags(pCollisionGrid, nRelX, nRelY, pTiles[i].pTile);
            else
                sub_6FD411F0(pCollisionGrid, nRelX, nRelY, pTiles[i].pTile);

            int nFlags = 0;
            if (pTiles[i].dwFlags & 2)
                nFlags = COLLIDE_PRESET;
            if (pTiles[i].dwFlags & 0x40)
                nFlags |= COLLIDE_WALL;
            if (pTiles[i].dwFlags & 0x80)
                nFlags |= COLLIDE_MISSILE_BARRIER;
            if (nFlags)
                sub_0064C700_SetCollisionMaskRect(pCollisionGrid, nRelX, nRelY, nFlags);
        }
    }
}

void __fastcall sub_0064C860(D2ActiveRoomStrc* pRoom, D2DrlgTileDataStrc* pTileData, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    if (!pRoom)
        return;
    D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pCollisionGrid)
        return;
    int nX = pTileData->nPosX + pCollisionGrid->pRoomCoords.nTileXPos;
    int nY = pTileData->nPosY + pCollisionGrid->pRoomCoords.nTileYPos;
    DUNGEON_GameTileToSubtileCoords(&nX, &nY);
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pRoom)
        return;
    pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pCollisionGrid)
        return;
    const int nRelX = nX - pCollisionGrid->pRoomCoords.nSubtileX;
    const int nRelY = nY - pCollisionGrid->pRoomCoords.nSubtileY;
    sub_0064C580_ClearTileCollisionFlags(pCollisionGrid, nRelX, nRelY, pTileData->pTile);
    if (pTileLibraryEntry)
        sub_6FD411F0(pCollisionGrid, nRelX, nRelY, pTileLibraryEntry);
}

void __fastcall COLLISION_AllocRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom)
{
    D2DrlgCoordsStrc pDrlgCoords;
    D2ActiveRoomStrc** ppRoomList;
    int nAdjacentRooms;
    int nTiles;

    if (!pRoom)
        return;
    DUNGEON_GetRoomCoordinates(pRoom, &pDrlgCoords);
    const int nCells = pDrlgCoords.nSubtileWidth * pDrlgCoords.nSubtileHeight;
    D2RoomCollisionGridStrc* pCollisionGrid = (D2RoomCollisionGridStrc*)FOG_AllocPool(pMemPool, sizeof(D2RoomCollisionGridStrc) + sizeof(unsigned short) * (nCells + 2 * pDrlgCoords.nSubtileHeight), gszCollisnSourceFile, 389, 0);
    pCollisionGrid->pRoomCoords = pDrlgCoords;
    DUNGEON_SetCollisionGridInRoom(pRoom, pCollisionGrid);
    pCollisionGrid->pCollisionMask = (unsigned short*)&pCollisionGrid[1];
    memset(pCollisionGrid->pCollisionMask, 0, sizeof(unsigned short) * nCells);
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nAdjacentRooms);
    for (int i = 0; i < nAdjacentRooms; ++i)
    {
        D2RoomCollisionGridStrc* pAdjacentCollisionGrid = DUNGEON_GetCollisionGridFromRoom(ppRoomList[i]);
        D2DrlgTileDataStrc* pTileData = sub_00619660_GetFloorTiles(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
        pTileData = sub_006196A0_GetWallTiles(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
        pTileData = DUNGEON_GetRoofTilesFromRoom(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
    }
}

// 0x0064E810
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms)
{
    return COLLISION_GetFreeCoordinatesImpl(pRoom, pSpawnPoint, pFieldCoord, nUnitSize, nMask, nFieldMask, bAllowNeighborRooms, 50, 1);
}

inline void COLLISION_CreateBoundingBoxInline(D2BoundingBoxStrc* pBoundingBox, int nCenterX, int nCenterY, unsigned int nSizeX, unsigned int nSizeY)
{
    pBoundingBox->nLeft = nCenterX - (nSizeX / 2);
    pBoundingBox->nRight = pBoundingBox->nLeft + nSizeX - 1;
    pBoundingBox->nBottom = nCenterY - (nSizeY / 2);
    pBoundingBox->nTop = pBoundingBox->nBottom + nSizeY - 1;
}

static void __stdcall sub_0064DC80(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    sub_0064DDB0(pRoom, nX - 1, nY, nMask);
    sub_0064DDB0(pRoom, nX, nY, nMask);
    sub_0064DDB0(pRoom, nX + 1, nY, nMask);
    sub_0064DDB0(pRoom, nX, nY - 1, nMask);
    sub_0064DDB0(pRoom, nX, nY + 1, nMask);
}

static void __stdcall sub_0064DDB0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid)
        {
            unsigned short* pCollisionMask = pCollisionGrid->pCollisionMask;
            if (pCollisionMask)
            {
                pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] |= nMask;
            }
        }
    }
}

static void __stdcall sub_0064DDF0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc tBoundingBox;
    COLLISION_CreateBoundingBoxInline(&tBoundingBox, nX, nY, 3, 3);
    COLLISION_SetCollisionMaskForBoundingBoxRecursively(pRoom, &tBoundingBox, nMask);
}

// 0x0064EA00
void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask)
{
    switch (nUnitSize)
    {
    case 1:
        sub_0064DDB0(pRoom, nX, nY, nMask);
        break;

    case 2:
        sub_0064DC80(pRoom, nX, nY, nMask);
        break;

    case 3:
        sub_0064DDF0(pRoom, nX, nY, nMask);
        break;
    }
}

// 0x0064EA90
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask)
{
    switch (nCollisionPattern)
    {
    case 0:
        return;

    case 1:
        sub_0064DC80(pRoom, nX, nY, nMask);
        if (nMask)
        {
            sub_0064DDB0(pRoom, nX, nY, MASK_NO_PATH);
        }
        break;

    case 2:
        sub_0064DDF0(pRoom, nX, nY, nMask);
        if (nMask)
        {
            sub_0064DC80(pRoom, nX, nY, MASK_NO_PATH);
        }
        break;

    case 3:
        sub_0064DC80(pRoom, nX, nY, nMask);
        if (nMask)
        {
            sub_0064DDB0(pRoom, nX, nY, MASK_PET);
        }
        break;

    case 4:
        sub_0064DDF0(pRoom, nX, nY, nMask);
        if (nMask)
        {
            sub_0064DC80(pRoom, nX, nY, MASK_PET);
        }
        break;

    case 5:
        sub_0064DC80(pRoom, nX, nY, nMask);
        break;
    }
}
