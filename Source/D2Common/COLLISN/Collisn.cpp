#include "D2Common.h"
#define COLLISION_ABS(a) ((a) < 0 ? -(a) : (a))
struct D2CoordStrc;
struct D2FieldStrc;
struct D2DrlgCoordsStrc;
struct D2RoomCollisionGridStrc;
struct D2DrlgTileDataStrc;
struct D2BoundingBoxStrc;

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
    union
    {
        struct
        {
            D2DrlgCoordsStrc pRoomCoords;
        };
        struct
        {
            int nSubtileX;
            int nSubtileY;
            int nSubtileWidth;
            int nSubtileHeight;
        };
    };
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
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __fastcall DUNGEON_AreSubtileCoordinatesInsideRoom(D2DrlgCoordsStrc* pDrlgCoords, int nX, int nY); // 0x00619DF0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
D2DrlgTileDataStrc* __stdcall sub_00619660_GetFloorTiles(D2ActiveRoomStrc* pRoom, int* pCount); // 0x00619660
D2DrlgTileDataStrc* __stdcall sub_006196A0_GetWallTiles(D2ActiveRoomStrc* pRoom, int* pCount); // 0x006196A0
D2DrlgTileDataStrc* __stdcall DUNGEON_GetRoofTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pRoofCount); // 0x006196E0
static void __stdcall sub_6FD413E0(D2RoomCollisionGridStrc* pCollisionGrid, D2RoomCollisionGridStrc* pAdjacentCollisionGrid, D2DrlgTileDataStrc* pTiles, int nTiles, int bRemoveOldFlags); // 0x0064C790
void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064EBA0
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064EC10
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0
unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D870
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064EA00
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064EA90

struct D2CoordStrc
{
    int nX;
    int nY;
};

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesImpl(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms, int nMaxDistance, int nPosIncrementValue); // 0x0064DEA0

struct D2BoundingBoxStrc
{
    int nLeft;
    int nBottom;
    int nRight;
    int nTop;
};

static unsigned short __stdcall COLLISION_CheckCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CC30
static void __stdcall COLLISION_ResetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CCE0
static void __stdcall COLLISION_SetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CD70
static int __stdcall COLLISION_AdaptBoundingBoxToGrid(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, D2BoundingBoxStrc* pBoundingBoxes); // 0x0064CDF0
unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CEB0
static unsigned short __stdcall sub_0064D450(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064D450
static unsigned short __stdcall COLLISION_CheckCollisionMaskWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064D100
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2FieldStrc* __stdcall DATATBLS_AllocField(); // 0x0066A4B0
void __stdcall DATATBLS_FreeField(D2FieldStrc* pField); // 0x0066A500
void __stdcall DATATBLS_SetFieldCoordinates(D2FieldStrc* pField, int nX, int nY); // 0x0066A540
int __stdcall D2Common_11099(D2FieldStrc* pField, D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short fMask); // 0x0066A670

static void __stdcall sub_6FD411F0(D2RoomCollisionGridStrc* pCollisionGrid, int nX, int nY, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    if (pCollisionGrid && pCollisionGrid->pCollisionMask)
    {
        unsigned char* pFlags = sub_00604CE0(pTileLibraryEntry);
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

static void __stdcall sub_0064C580_ClearTileCollisionFlags(D2RoomCollisionGridStrc* pCollisionGrid, int nX, int nY, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    if (pCollisionGrid && pCollisionGrid->pCollisionMask)
    {
        unsigned char* pFlags = sub_00604CE0(pTileLibraryEntry);
        const int nWidth = pCollisionGrid->pRoomCoords.nSubtileWidth;
        const int nCappedY = nY > 0 ? nY : 0;
        const int nCappedX = nX > 0 ? nX : 0;
        unsigned char* pTmp = &pFlags[5 * (nY - nCappedY + 4) - nX];
        int nIndex = nWidth * nCappedY;
        for (int nYCounter = nCappedY; nYCounter < nY + 5; ++nYCounter)
        {
            unsigned short* pCollisionMask = &pCollisionGrid->pCollisionMask[nIndex];
            for (int nXCounter = nCappedX; nXCounter < nX + 5; ++nXCounter)
                pCollisionMask[nXCounter] &= ~pTmp[nXCounter];
            pTmp -= 5;
            nIndex += nWidth;
        }
    }
}

static void __stdcall sub_0064C640_SetTileCollisionFlags(D2RoomCollisionGridStrc* pCollisionGrid, int nX, int nY, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    if (pCollisionGrid && pCollisionGrid->pCollisionMask)
    {
        unsigned char* pFlags = sub_00604CE0(pTileLibraryEntry);
        const int nWidth = pCollisionGrid->pRoomCoords.nSubtileWidth;
        const int nCappedY = nY > 0 ? nY : 0;
        const int nCappedX = nX > 0 ? nX : 0;
        unsigned char* pTmp = &pFlags[5 * (nY - nCappedY + 4) - nX];
        int nIndex = nWidth * nCappedY;
        for (int nYCounter = nCappedY; nYCounter < nY + 5; ++nYCounter)
        {
            unsigned short* pCollisionMask = &pCollisionGrid->pCollisionMask[nIndex];
            for (int nXCounter = nCappedX; nXCounter < nX + 5; ++nXCounter)
                pCollisionMask[nXCounter] = pTmp[nXCounter];
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
        const int nCappedX = nX > 0 ? nX : 0;
        int nIndex = nWidth * nCappedY;
        for (int nYCounter = nCappedY; nYCounter < nY + 5; ++nYCounter)
        {
            unsigned short* pCollisionMask = &pCollisionGrid->pCollisionMask[nIndex];
            for (int nXCounter = nCappedX; nXCounter < nX + 5; ++nXCounter)
                pCollisionMask[nXCounter] |= nFlags;
            nIndex += nWidth;
        }
    }
}

// build: context sub_6FD413E0
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

// 0x0064C900
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
        D2DrlgTileDataStrc* pTileData = sub_00619660_GetFloorTiles(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
        pTileData = sub_006196A0_GetWallTiles(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
        pTileData = DUNGEON_GetRoofTilesFromRoom(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
    }
}

// 0x0064CB90
void __stdcall COLLISION_SetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
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

// 0x0064CBE0
void __stdcall COLLISION_ResetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid)
        {
            unsigned short* pCollisionMask = pCollisionGrid->pCollisionMask;
            if (pCollisionMask)
            {
                pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] &= ~nMask;
            }
        }
    }
}

// 0x0064E780
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithMaxDistance(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighborRooms, int nMaxDistance)
{
    return COLLISION_GetFreeCoordinatesImpl(pRoom, pSpawnPoint, 0, nUnitSize, nMask, nMask, bAllowNeighborRooms, nMaxDistance, 1);
}

// 0x0064E7B0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighborRooms)
{
    return COLLISION_GetFreeCoordinatesImpl(pRoom, pSpawnPoint, 0, nUnitSize, nMask, nMask, bAllowNeighborRooms, 50, 1);
}

// 0x0064E7E0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int nPosIncrementValue)
{
    return COLLISION_GetFreeCoordinatesImpl(pRoom, pSpawnPoint, 0, nUnitSize, nMask, nMask, 0, 50, nPosIncrementValue);
}

// 0x0064ED20
unsigned short __fastcall COLLISION_TryMoveUnitCollisionMask(D2ActiveRoomStrc* pRoom, int nX1, int nY1, int nX2, int nY2, int nUnitSize, unsigned short nCollisionMask, unsigned short nMoveConditionMask)
{
    COLLISION_ResetMaskWithSize(pRoom, nX1, nY1, nUnitSize, nCollisionMask);

    const unsigned short nCollidedWithMask = COLLISION_CheckMaskWithSize(pRoom, nX2, nY2, nUnitSize, nMoveConditionMask);

    if (nCollidedWithMask & 5)
    {
        COLLISION_SetMaskWithSize(pRoom, nX1, nY1, nUnitSize, nCollisionMask);
    }
    else
    {
        COLLISION_SetMaskWithSize(pRoom, nX2, nY2, nUnitSize, nCollisionMask);
    }

    return nCollidedWithMask;
}

// 0x0064EDA0
unsigned short __fastcall COLLISION_TryTeleportUnitCollisionMask(D2ActiveRoomStrc* pRoom, int nX1, int nY1, int nX2, int nY2, int nCollisionPattern, unsigned short nFootprintCollisionMask, unsigned short nMoveConditionMask)
{
    COLLISION_ResetMaskWithPattern(pRoom, nX1, nY1, nCollisionPattern, nFootprintCollisionMask);

    const unsigned short nCollidedWithMask = COLLISION_CheckMaskWithPattern(pRoom, nX2, nY2, nCollisionPattern, nMoveConditionMask);
    if (!nCollidedWithMask)
    {
        COLLISION_SetMaskWithPattern(pRoom, nX2, nY2, nCollisionPattern, nFootprintCollisionMask);
    }
    else
    {
        COLLISION_SetMaskWithPattern(pRoom, nX1, nY1, nCollisionPattern, nFootprintCollisionMask);
    }

    return nCollidedWithMask;
}

// 0x0064EE20
int __fastcall sub_0064EE20(D2ActiveRoomStrc* pRoom, int nX1, int nY1, int nX2, int nY2, int nCollisionPattern, unsigned short nFootprintCollisionMask, unsigned short nMoveConditionMask)
{
    COLLISION_ResetMaskWithPattern(pRoom, nX1, nY1, nCollisionPattern, nFootprintCollisionMask);

    const int nCollision = COLLISION_CheckAnyCollisionWithPattern(pRoom, nX2, nY2, nCollisionPattern, nMoveConditionMask);

    COLLISION_SetMaskWithPattern(pRoom, nX1, nY1, nCollisionPattern, nFootprintCollisionMask);

    return nCollision;
}

// 0x0064EE70
unsigned short __fastcall COLLISION_ForceTeleportUnitCollisionMaskAndGetCollision(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nUnitSize, unsigned short nFootprintCollisionMask, unsigned short nMoveConditionMask)
{
    if (pRoom1)
    {
        COLLISION_ResetMaskWithSize(pRoom1, nX1, nY1, nUnitSize, nFootprintCollisionMask);
    }

    const unsigned short nCollidedWithMask = COLLISION_CheckMaskWithSize(pRoom2, nX2, nY2, nUnitSize, nMoveConditionMask);

    COLLISION_SetMaskWithSize(pRoom2, nX2, nY2, nUnitSize, nFootprintCollisionMask);

    return nCollidedWithMask;
}

// 0x0064EED0
unsigned short __fastcall COLLISION_TeleportUnitCollisionMask(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nUnitSize, int nMask)
{
    if (pRoom1)
    {
        COLLISION_ResetMaskWithSize(pRoom1, nX1, nY1, nUnitSize, nMask);
    }

    COLLISION_SetMaskWithSize(pRoom2, nX2, nY2, nUnitSize, nMask);
    return 0;
}

// 0x0064EF10
int __fastcall COLLISION_TrySetUnitCollisionMask(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nCollisionPattern, unsigned short nFootprintCollisionMask, unsigned short nMoveConditionMask)
{
    if (pRoom1)
    {
        COLLISION_ResetMaskWithPattern(pRoom1, nX1, nY1, nCollisionPattern, nFootprintCollisionMask);
    }

    const int nCollision = COLLISION_CheckAnyCollisionWithPattern(pRoom2, nX2, nY2, nCollisionPattern, nMoveConditionMask);
    if (!nCollision)
    {
        COLLISION_SetMaskWithPattern(pRoom2, nX2, nY2, nCollisionPattern, nFootprintCollisionMask);
    }
    else if (pRoom1)
    {
        COLLISION_SetMaskWithPattern(pRoom1, nX1, nY1, nCollisionPattern, nFootprintCollisionMask);
    }

    return nCollision;

}

// 0x0064EFA0
void __fastcall COLLISION_SetUnitCollisionMask(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nCollisionPattern, unsigned short nCollisionMask)
{
    if (pRoom1)
    {
        COLLISION_ResetMaskWithPattern(pRoom1, nX1, nY1, nCollisionPattern, nCollisionMask);
        COLLISION_SetMaskWithPattern(pRoom2, nX2, nY2, nCollisionPattern, nCollisionMask);
    }
}

// build: context COLLISION_CheckCollisionMaskForBoundingBox
static unsigned short __stdcall COLLISION_CheckCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    unsigned short nResult = 0;
    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    const int nWidth = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nWidth];
    const int nLineSkip = nWidth + (nBeginX - nEndX) - 1;

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            nResult |= *pLine & nMask;
            ++pLine;
        }

        pLine += nLineSkip;
    }
    return nResult;
}

// build: context COLLISION_ResetCollisionMaskForBoundingBox
static void __stdcall COLLISION_ResetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    const int nWidth = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nWidth];
    const int nLineSkip = nWidth + (nBeginX - nEndX) - 1;
    const unsigned short nInvMask = ~nMask;

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            *pLine &= nInvMask;
            ++pLine;
        }

        pLine += nLineSkip;
    }
}

// build: context COLLISION_SetCollisionMaskForBoundingBox
static void __stdcall COLLISION_SetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    const int nWidth = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nWidth];
    const int nLineSkip = nWidth + (nBeginX - nEndX) - 1;

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            *pLine |= nMask;
            ++pLine;
        }

        pLine += nLineSkip;
    }
}

// build: context COLLISION_AdaptBoundingBoxToGrid
static int __stdcall COLLISION_AdaptBoundingBoxToGrid(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, D2BoundingBoxStrc* pBoundingBoxes)
{
    if (pBoundingBox->nBottom > pBoundingBox->nTop || pBoundingBox->nLeft > pBoundingBox->nRight)
    {
        return 0;
    }

    D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pCollisionGrid)
    {
        return 0;
    }

    int nBoundingBoxes = 1;
    pBoundingBoxes[0].nBottom = pBoundingBox->nBottom;
    pBoundingBoxes[0].nTop = pBoundingBox->nTop;
    pBoundingBoxes[0].nLeft = pBoundingBox->nLeft;
    pBoundingBoxes[0].nRight = pBoundingBox->nRight;

    const int nCollisionGridRight = pCollisionGrid->nSubtileX + pCollisionGrid->nSubtileWidth;
    if (pBoundingBox->nRight >= nCollisionGridRight)
    {
        pBoundingBoxes[0].nRight = nCollisionGridRight - 1;

        pBoundingBoxes[nBoundingBoxes].nLeft = pBoundingBoxes[0].nRight + 1;
        pBoundingBoxes[nBoundingBoxes].nRight = pBoundingBox->nRight;
        pBoundingBoxes[nBoundingBoxes].nBottom = pBoundingBoxes[0].nBottom;
        pBoundingBoxes[nBoundingBoxes].nTop = pBoundingBoxes[0].nTop;

        ++nBoundingBoxes;
    }

    const int nCollisionGridTop = pCollisionGrid->nSubtileY + pCollisionGrid->nSubtileHeight;
    if (pBoundingBox->nTop >= nCollisionGridTop)
    {
        pBoundingBoxes[0].nTop = nCollisionGridTop - 1;

        pBoundingBoxes[nBoundingBoxes].nLeft = pBoundingBoxes[0].nLeft;
        pBoundingBoxes[nBoundingBoxes].nRight = pBoundingBoxes[0].nRight;
        pBoundingBoxes[nBoundingBoxes].nBottom = pBoundingBoxes[0].nTop + 1;
        pBoundingBoxes[nBoundingBoxes].nTop = pBoundingBox->nTop;

        ++nBoundingBoxes;
    }

    return nBoundingBoxes;
}

// 0x0064CEB0
unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
    if (!pRoom)
    {
        return MASK_INVALID;
    }

    D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pCollisionGrid)
    {
        return MASK_INVALID;
    }

    D2BoundingBoxStrc pBoundingBoxes[3];
    const int nBoundingBoxes = COLLISION_AdaptBoundingBoxToGrid(pRoom, pBoundingBox, pBoundingBoxes);
    if (nBoundingBoxes <= 0)
    {
        return MASK_INVALID;
    }

    unsigned short nResult = COLLISION_CheckCollisionMaskForBoundingBox(pCollisionGrid, &pBoundingBoxes[0], nMask);
    for (int i = 1; i < nBoundingBoxes; ++i)
    {
        nResult |= COLLISION_CheckCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBoxes[i], nMask);
    }

    return nResult;
}

// 0x0064CF50
int __fastcall COLLISION_CheckAnyCollisionForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
    if (!pRoom)
    {
        return 1;
    }

    D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pCollisionGrid)
    {
        return 1;
    }

    D2BoundingBoxStrc pBoundingBoxes[3];
    const int nBoundingBoxes = COLLISION_AdaptBoundingBoxToGrid(pRoom, pBoundingBox, pBoundingBoxes);
    if (nBoundingBoxes <= 0 || COLLISION_CheckCollisionMaskForBoundingBox(pCollisionGrid, &pBoundingBoxes[0], nMask))
    {
        return 1;
    }

    for (int i = 1; i < nBoundingBoxes; ++i)
    {
        if (COLLISION_CheckAnyCollisionForBoundingBoxRecursively(pRoom, &pBoundingBoxes[i], nMask))
        {
            return 1;
        }
    }

    return 0;
}

// 0x0064CFF0
void __fastcall COLLISION_ResetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
    if (pRoom)
    {
        if (D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom))
        {
            D2BoundingBoxStrc pBoundingBoxes[3];
            int nBoundingBoxes = COLLISION_AdaptBoundingBoxToGrid(pRoom, pBoundingBox, pBoundingBoxes);
            if (nBoundingBoxes > 0)
            {
                COLLISION_ResetCollisionMaskForBoundingBox(pCollisionGrid, &pBoundingBoxes[0], nMask);

                for (int i = 1; i < nBoundingBoxes; ++i)
                {
                    COLLISION_ResetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBoxes[i], nMask);
                }
            }
        }
    }
}

// 0x0064D060
void __fastcall COLLISION_SetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
    if (pRoom)
    {
        if (D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom))
        {
            D2BoundingBoxStrc pBoundingBoxes[3];
            int nBoundingBoxes = COLLISION_AdaptBoundingBoxToGrid(pRoom, pBoundingBox, pBoundingBoxes);
            if (nBoundingBoxes > 0)
            {
                COLLISION_SetCollisionMaskForBoundingBox(pCollisionGrid, &pBoundingBoxes[0], nMask);

                for (int i = 1; i < nBoundingBoxes; ++i)
                {
                    COLLISION_SetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBoxes[i], nMask);
                }
            }
        }
    }
}

inline void COLLISION_CreateBoundingBoxInline(D2BoundingBoxStrc* pBoundingBox, int nCenterX, int nCenterY, unsigned int nSizeX, unsigned int nSizeY)
{
    pBoundingBox->nLeft = nCenterX - (nSizeX / 2);
    pBoundingBox->nRight = pBoundingBox->nLeft + nSizeX - 1;
    pBoundingBox->nBottom = nCenterY - (nSizeY / 2);
    pBoundingBox->nTop = pBoundingBox->nBottom + nSizeY - 1;
}

// 0x0064CA50
static unsigned short __stdcall COLLISION_CheckCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid && pCollisionGrid->pCollisionMask)
        {
            return pCollisionGrid->pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] & nMask;
        }
    }

    return MASK_INVALID;
}

// build: context sub_0064D450
static unsigned short __stdcall sub_0064D450(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid && pCollisionGrid->pCollisionMask)
        {
            return pCollisionGrid->pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] & nMask;
        }
    }

    return MASK_INVALID;
}

// build: context COLLISION_CheckCollisionMaskWithAdjacentCells
static unsigned short __stdcall COLLISION_CheckCollisionMaskWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pRoom)
    {
        return nMask;
    }

    D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pGrid)
    {
        return nMask;
    }

    unsigned short* pCollisionMask = pGrid->pCollisionMask;
    if (!pCollisionMask)
    {
        return nMask;
    }

    const int nWidth = pGrid->nSubtileWidth;
    int nCase = 0;
    if (pGrid->nSubtileX >= nX)
    {
        nCase += 1;
    }

    if (pGrid->nSubtileY >= nY)
    {
        nCase += 2;
    }

    if (pGrid->nSubtileX + nWidth <= nX + 1)
    {
        nCase += 4;
    }

    if (pGrid->nSubtileY + pGrid->nSubtileHeight <= nY + 1)
    {
        nCase += 8;
    }

    unsigned short* p = &pCollisionMask[nX + nWidth * (nY - pGrid->nSubtileY) - pGrid->nSubtileX];

    switch (nCase)
    {
    case 0:
        return (nMask & (*p | p[1] | *(p - 1) | p[nWidth] | p[-nWidth]));
    case 1:
        return COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask) | (nMask & (*p | p[1] | p[nWidth] | p[-nWidth]));
    case 2:
        return COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask) | (nMask & (*p | p[1] | *(p - 1) | p[nWidth]));
    case 3:
        return COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask) | (nMask & (*p | p[1] | p[nWidth]));
    case 4:
        return COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask) | (nMask & (*p | *(p - 1) | p[nWidth] | p[-nWidth]));
    case 6:
        return COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask) | (nMask & (*p | *(p - 1) | p[nWidth]));
    case 8:
        return COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask) | (nMask & (*p | p[1] | *(p - 1) | p[-nWidth]));
    case 9:
        return COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask) | (nMask & (*p | p[1] | p[-nWidth]));
    case 12:
        return COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask) | (nMask & (*p | *(p - 1) | p[-nWidth]));
    default:
        return nMask;
    }
}

// 0x0064D4A0
static unsigned short __stdcall sub_0064D4A0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;
    COLLISION_CreateBoundingBoxInline(&pBoundingBox, nX, nY, 3, 3);
    return COLLISION_CheckCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// 0x0064D800
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;

    if ((int)nSizeX <= 1 && (int)nSizeY <= 1)
    {
        return COLLISION_CheckCollisionMask(pRoom, nX, nY, nMask);
    }

    COLLISION_CreateBoundingBoxInline(&pBoundingBox, nX, nY, nSizeX, nSizeY);
    return COLLISION_CheckCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// 0x0064D870
unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask)
{
    switch (nCollisionPattern)
    {
    case 0:
        return sub_0064D450(pRoom, nX, nY, nMask);

    case 1:
    case 3:
        return COLLISION_CheckCollisionMaskWithAdjacentCells(pRoom, nX, nY, nMask);

    case 2:
    case 4:
        return sub_0064D4A0(pRoom, nX, nY, nMask);

    case 5:
        return COLLISION_CheckCollisionMaskWithAdjacentCells(pRoom, nX, nY, nMask);

    default:
        return MASK_ALL;
    }
}

// 0x0064D9B0
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask)
{
    switch (nUnitSize)
    {
    case 0:
        return sub_0064D450(pRoom, nX, nY, nMask);

    case 1:
        return sub_0064D450(pRoom, nX, nY, nMask);

    case 2:
        return COLLISION_CheckCollisionMaskWithAdjacentCells(pRoom, nX, nY, nMask);

    case 3:
        return sub_0064D4A0(pRoom, nX, nY, nMask);

    default:
        return MASK_ALL;
    }
}

// 0x0064DEA0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesImpl(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms, int nMaxDistance, int nPosIncrementValue)
{
    D2_ASSERT(pSpawnPoint, 0x726);

    const D2CoordStrc tSpawn = *pSpawnPoint;
    D2FieldStrc* pField = 0;

    if (pFieldCoord)
    {
        pField = DATATBLS_AllocField();
        D2_ASSERT(pField, 0x730);

        DATATBLS_SetFieldCoordinates(pField, pFieldCoord->nX, pFieldCoord->nY);
    }

    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, pSpawnPoint->nX, pSpawnPoint->nY);

    if (pRoom && !COLLISION_CheckMaskWithSize(pRoom, pSpawnPoint->nX, pSpawnPoint->nY, nUnitSize, nMask))
    {
        if (!pFieldCoord || !D2Common_11099(pField, pRoom, pSpawnPoint->nX, pSpawnPoint->nY, nFieldMask))
        {
            if (pField)
            {
                DATATBLS_FreeField(pField);
            }

            return pRoom;
        }
    }

    int nBestDistance = -1;
    for (int nRing = 1; nRing < nMaxDistance; nRing += nPosIncrementValue)
    {
        nBestDistance = -1;

        for (int nY = tSpawn.nY - nRing; nY <= tSpawn.nY + nRing; nY += nPosIncrementValue)
        {
            for (int nX = tSpawn.nX - nRing; nX <= tSpawn.nX + nRing; nX += 2 * nRing)
            {
                D2ActiveRoomStrc* pTemp = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
                if (pTemp)
                {
                    pRoom = pTemp;

                    if (!COLLISION_CheckMaskWithSize(pTemp, nX, nY, nUnitSize, nMask) && (!pFieldCoord || !D2Common_11099(pField, pTemp, nX, nY, nFieldMask)))
                    {
                        const int nAbsX = COLLISION_ABS(nX - tSpawn.nX);
                        int nDY = nY - tSpawn.nY;
                        if (nDY < 0)
                        {
                            nDY = -nDY;
                        }
                        const int nDistance = nAbsX + nDY;
                        if (nBestDistance == -1 || nDistance < nBestDistance)
                        {
                            pSpawnPoint->nX = nX;
                            pSpawnPoint->nY = nY;
                            nBestDistance = nDistance;
                        }
                    }
                }
            }
        }

        for (int nX = tSpawn.nX - nRing + 1; nX <= tSpawn.nX + nRing - 1; nX += nPosIncrementValue)
        {
            for (int nY = tSpawn.nY - nRing; nY <= tSpawn.nY + nRing; nY += 2 * nRing)
            {
                D2ActiveRoomStrc* pTemp = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
                if (pTemp)
                {
                    pRoom = pTemp;

                    if (!COLLISION_CheckMaskWithSize(pTemp, nX, nY, nUnitSize, nMask) && (!pFieldCoord || !D2Common_11099(pField, pTemp, nX, nY, nFieldMask)))
                    {
                        int nDX = nX - tSpawn.nX;
                        if (nDX < 0)
                        {
                            nDX = -nDX;
                        }
                        const int nDistance = nDX + COLLISION_ABS(nY - tSpawn.nY);
                        if (nBestDistance == -1 || nDistance < nBestDistance)
                        {
                            pSpawnPoint->nX = nX;
                            pSpawnPoint->nY = nY;
                            nBestDistance = nDistance;
                        }
                    }
                }
            }
        }

        if (nBestDistance != -1)
        {
            break;
        }
    }

    if (pField)
    {
        DATATBLS_FreeField(pField);
    }

    if (nBestDistance != -1)
    {
        return COLLISION_GetRoomBySubTileCoordinates(pRoom, pSpawnPoint->nX, pSpawnPoint->nY);
    }

    if (bAllowNeighborRooms)
    {
        return COLLISION_GetRoomBySubTileCoordinates(pRoom, pSpawnPoint->nX, pSpawnPoint->nY);
    }

    return 0;
}
