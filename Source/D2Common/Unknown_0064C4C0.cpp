#include "D2Common.h"

struct D2DrlgCoordsStrc;
struct D2RoomCollisionGridStrc;
struct D2DrlgTileDataStrc;

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2RoomCollisionGridStrc
{
    D2DrlgCoordsStrc pRoomCoords;
    unsigned short* pCollisionMask;
};

struct D2DrlgTileDataStrc
{
    int nWidth;
    int nHeight;
    int nPosX;
    int nPosY;
    int unk0x10;
    unsigned int dwFlags;
    D2TileLibraryEntryStrc* pTile;
    char unk0x1C[0x14];
};

enum
{
    COLLIDE_WALL = 0x0001,
    COLLIDE_MISSILE_BARRIER = 0x0004,
    COLLIDE_PRESET = 0x0010,
};

unsigned char* __stdcall sub_00604CE0(D2TileLibraryEntryStrc* pTile); // 0x00604CE0
D2RoomCollisionGridStrc* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A010
void __fastcall DUNGEON_SetCollisionGridInRoom(D2ActiveRoomStrc* pRoom, D2RoomCollisionGridStrc* pGrid); // 0x0061A040
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __fastcall DUNGEON_AreSubtileCoordinatesInsideRoom(D2DrlgCoordsStrc* pDrlgCoords, int nX, int nY); // 0x00619DF0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
D2DrlgTileDataStrc* __stdcall DUNGEON_GetFloorTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pCount); // 0x00619660
D2DrlgTileDataStrc* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pCount); // 0x006196A0
D2DrlgTileDataStrc* __stdcall DUNGEON_GetRoofTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pRoofCount); // 0x006196E0

static void __stdcall sub_0064C700_SetCollisionMaskRect(D2RoomCollisionGridStrc* pCollisionGrid, int nX, int nY, unsigned short nFlags);

// 0x0064C4C0
static void __stdcall sub_6FD411F0(D2RoomCollisionGridStrc* pCollisionGrid, int nX, int nY, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    if (pCollisionGrid && pCollisionGrid->pCollisionMask)
    {
        unsigned char* pFlags = sub_00604CE0(pTileLibraryEntry);
        const int nWidth = pCollisionGrid->pRoomCoords.nSubtileWidth;
        const int nCappedX = nX > 0 ? nX : 0;
        const int nEndX = nX + 5;
        const int nCappedY = nY > 0 ? nY : 0;
        const int nEndY = nY + 5;
        unsigned char* pTmp = &pFlags[5 * (nY - nCappedY + 4) - nX + nCappedX];
        int nIndex = nWidth * nCappedY;
        for (int nYCounter = nCappedY; nYCounter < nEndY; ++nYCounter)
        {
            unsigned short* pCollisionMask = &pCollisionGrid->pCollisionMask[nIndex];
            for (int nXCounter = nCappedX; nXCounter < nEndX; ++nXCounter)
                pCollisionMask[nXCounter] |= pTmp[nXCounter - nCappedX];
            pTmp -= 5;
            nIndex += nWidth;
        }
    }
}

// 0x0064C580
static void __stdcall sub_0064C580_ClearTileCollisionFlags(D2RoomCollisionGridStrc* pCollisionGrid, int nX, int nY, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    if (pCollisionGrid && pCollisionGrid->pCollisionMask)
    {
        unsigned char* pFlags = sub_00604CE0(pTileLibraryEntry);
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
                pCollisionMask[nXCounter] &= ~pTmp[nXCounter - nCappedX];
            pTmp -= 5;
            nIndex += nWidth;
        }
    }
}

// 0x0064C640
static void __stdcall sub_0064C640_SetTileCollisionFlags(D2RoomCollisionGridStrc* pCollisionGrid, int nX, int nY, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    if (pCollisionGrid && pCollisionGrid->pCollisionMask)
    {
        unsigned char* pFlags = sub_00604CE0(pTileLibraryEntry);
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
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
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
    D2RoomCollisionGridStrc* pCollisionGrid = (D2RoomCollisionGridStrc*)FOG_AllocPool(pMemPool, sizeof(D2RoomCollisionGridStrc) + sizeof(unsigned short) * (nCells + 2 * pDrlgCoords.nSubtileHeight), ".\\COLLISN\\Collisn.cpp", 389, 0);
    pCollisionGrid->pRoomCoords = pDrlgCoords;
    DUNGEON_SetCollisionGridInRoom(pRoom, pCollisionGrid);
    pCollisionGrid->pCollisionMask = (unsigned short*)&pCollisionGrid[1];
    memset(pCollisionGrid->pCollisionMask, 0, sizeof(unsigned short) * nCells);
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nAdjacentRooms);
    for (int i = 0; i < nAdjacentRooms; ++i)
    {
        D2RoomCollisionGridStrc* pAdjacentCollisionGrid = DUNGEON_GetCollisionGridFromRoom(ppRoomList[i]);
        D2DrlgTileDataStrc* pTileData = DUNGEON_GetFloorTilesFromRoom(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
        pTileData = DUNGEON_GetWallTilesFromRoom(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
        pTileData = DUNGEON_GetRoofTilesFromRoom(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
    }
}

// 0x0064C700
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

// 0x0064C8F0
extern "C" unsigned __cdecl sub_0064C8F0() { return 0; }
