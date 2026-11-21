#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2Primitives.h"
#include "D2DrlgPresets.h"

struct D2ActiveRoomStrc;

#define COLLISION_ABS(a) ((a) < 0 ? -(a) : (a))

struct D2CoordStrc;

struct D2FieldStrc;

struct D2DrlgCoordsStrc;

struct D2RoomCollisionGridStrc;

struct D2DrlgTileDataStrc;

struct D2BoundingBoxStrc;

enum
{
    COLLIDE_WALL = 0x0001,
    COLLIDE_MISSILE_BARRIER = 0x0004,
    COLLIDE_PRESET = 0x0010,
};

unsigned char* __stdcall sub_00604CE0(D2TileLibraryEntryStrc* pTile); // 0x00604CE0

D2RoomCollisionGridStrc* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A010

void __fastcall DUNGEON_SetCollisionGridInRoom(D2ActiveRoomStrc* pRoom, void* pCollisionGrid); // 0x0061A040

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

int __fastcall DUNGEON_AreSubtileCoordinatesInsideRoom(D2DrlgCoordsStrc* pDrlgCoords, int nX, int nY); // 0x00619DF0

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790

D2DrlgTileDataStrc* __stdcall DUNGEON_GetFloorTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pCount); // 0x00619660

D2DrlgTileDataStrc* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pCount); // 0x006196A0

D2DrlgTileDataStrc* __stdcall DUNGEON_GetRoofTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pRoofCount); // 0x006196E0

static void __stdcall sub_6FD413E0(D2RoomCollisionGridStrc* pCollisionGrid, D2RoomCollisionGridStrc* pAdjacentCollisionGrid, D2DrlgTileDataStrc* pTiles, int nTiles, int bRemoveOldFlags); // 0x0064C790

void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064EBA0

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064EC10

unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0

unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D870

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064EA00

void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064EA90

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesImpl(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms, int nMaxDistance, int nPosIncrementValue); // 0x0064DEA0

static unsigned short __stdcall COLLISION_CheckCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);

static void __stdcall COLLISION_ResetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);

static void __stdcall COLLISION_SetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, int nMask);

static int __stdcall COLLISION_AdaptBoundingBoxToGrid(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, D2BoundingBoxStrc* pBoundingBoxes);

unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);

static unsigned short __fastcall sub_0064D450(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

static unsigned short __stdcall COLLISION_CheckCollisionMaskWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2FieldStrc* __stdcall DATATBLS_AllocField(); // 0x0066A4B0

void __stdcall DATATBLS_FreeField(D2FieldStrc* pField); // 0x0066A500

void __stdcall DATATBLS_SetFieldCoordinates(D2FieldStrc* pField, int nX, int nY); // 0x0066A540

int __stdcall D2Common_11099(D2FieldStrc* pField, D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short fMask); // 0x0066A670

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

extern "C" const char gszCollisnSourceFile[];                                                               // 0x006EB730

static unsigned short __fastcall COLLISION_CheckCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

static void __fastcall COLLISION_ResetCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

static void __fastcall COLLISION_SetCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

int __fastcall COLLISION_CheckAnyCollisionForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);

void __fastcall COLLISION_ResetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);

void __fastcall COLLISION_SetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, int nMask);

static void __fastcall COLLISION_CreateBoundingBox(D2BoundingBoxStrc* pBoundingBox, int nCenterX, int nCenterY, unsigned int nSizeX, unsigned int nSizeY);

static unsigned short __fastcall sub_0064D4A0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

static int __stdcall COLLISION_CheckAnyCollisionWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

static int __fastcall sub_0064D7C0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

static void __fastcall sub_0064DA40(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

static void __fastcall sub_0064DB70(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

static void __fastcall sub_0064DBC0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

static void __fastcall sub_0064DC80(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

static void __fastcall sub_0064DDB0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

static void __fastcall sub_0064DDF0(D2ActiveRoomStrc* pRoom, int nX, int nY, int nMask);

#define MASK_INVALID 0x27

#define MASK_ALL 0xFFFF

#define MASK_NO_PATH 0x1000

#define MASK_PET 0x2000

#define BOX_LO 1

#define BOX_HI 1

void __fastcall COLLISION_FreeRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom);

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

void __stdcall COLLISION_SetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

void __stdcall COLLISION_ResetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask);

void __stdcall COLLISION_SetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, int nMask);

void __stdcall COLLISION_ResetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask);

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
        D2DrlgTileDataStrc* pTileData = DUNGEON_GetFloorTilesFromRoom(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
        pTileData = DUNGEON_GetWallTilesFromRoom(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
        pTileData = DUNGEON_GetRoofTilesFromRoom(ppRoomList[i], &nTiles);
        sub_6FD413E0(pCollisionGrid, pAdjacentCollisionGrid, pTileData, nTiles, 0);
    }
}

// 0x0064CA10
void __fastcall COLLISION_FreeRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom)
{
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid)
        {
            FOG_FreeServerMemory(pMemPool, pCollisionGrid, gszCollisnSourceFile, 449, 0);
            DUNGEON_SetCollisionGridInRoom(pRoom, 0);
        }
    }
}

// 0x0064CA50
static unsigned short __fastcall COLLISION_CheckCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
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

// 0x0064CAA0
static void __fastcall COLLISION_ResetCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
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
                pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] &= ~nMask;
            }
        }
    }
}

// 0x0064CAF0
static void __fastcall COLLISION_SetCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
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

// 0x0064CB30
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    return COLLISION_CheckCollisionMask(pRoom, nX, nY, nMask);
}

// 0x0064CB90
void __stdcall COLLISION_SetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
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

// 0x0064CBE0
void __stdcall COLLISION_ResetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
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
                pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] &= ~nMask;
            }
        }
    }
}

// 0x0064CC30
static unsigned short __stdcall COLLISION_CheckCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    unsigned short nResult = 0;
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    int nSkip = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nSkip];
    nSkip -= nEndX - nBeginX + 1;

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            nResult |= *pLine & nMask;
            ++pLine;
        }

        pLine += nSkip;
    }
    return nResult;
}

// 0x0064CCE0
static void __stdcall COLLISION_ResetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    int nSkip = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nSkip];
    nSkip -= nEndX - nBeginX + 1;
    const unsigned short nInvMask = ~nMask;

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            *pLine &= nInvMask;
            ++pLine;
        }

        pLine += nSkip;
    }
}

// 0x0064CD70
static void __stdcall COLLISION_SetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, int nMask)
{
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    int nSkip = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nSkip];
    nSkip -= nEndX - nBeginX + 1;

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            *pLine |= nMask;
            ++pLine;
        }

        pLine += nSkip;
    }
}

// 0x0064CDF0
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

    if (pBoundingBox->nRight >= pCollisionGrid->nSubtileX + pCollisionGrid->nSubtileWidth)
    {
        pBoundingBoxes[0].nRight = pCollisionGrid->nSubtileX + pCollisionGrid->nSubtileWidth - 1;

        pBoundingBoxes[nBoundingBoxes].nLeft = pBoundingBoxes[0].nRight + 1;
        pBoundingBoxes[nBoundingBoxes].nRight = pBoundingBox->nRight;
        pBoundingBoxes[nBoundingBoxes].nBottom = pBoundingBoxes[0].nBottom;
        pBoundingBoxes[nBoundingBoxes].nTop = pBoundingBoxes[0].nTop;

        ++nBoundingBoxes;
    }

    if (pBoundingBox->nTop >= pCollisionGrid->nSubtileY + pCollisionGrid->nSubtileHeight)
    {
        pBoundingBoxes[0].nTop = pCollisionGrid->nSubtileY + pCollisionGrid->nSubtileHeight - 1;

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
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
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
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
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
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
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
void __fastcall COLLISION_SetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, int nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
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

// 0x0064D0D0
static void __fastcall COLLISION_CreateBoundingBox(D2BoundingBoxStrc* pBoundingBox, int nCenterX, int nCenterY, unsigned int nSizeX, unsigned int nSizeY)
{
    pBoundingBox->nLeft = nCenterX - (nSizeX / 2);
    pBoundingBox->nRight = pBoundingBox->nLeft + nSizeX - 1;
    pBoundingBox->nBottom = nCenterY - (nSizeY / 2);
    pBoundingBox->nTop = pBoundingBox->nBottom + nSizeY - 1;
}

// 0x0064D100
static unsigned short __stdcall COLLISION_CheckCollisionMaskWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pGrid)
        {
            unsigned short* pCollisionMask = pGrid->pCollisionMask;
            if (pCollisionMask)
            {
                int nCase = 0;
                if (pGrid->nSubtileX >= nX)
                {
                    nCase = 1;
                }

                if (pGrid->nSubtileY >= nY)
                {
                    nCase += 2;
                }

                if (pGrid->nSubtileX + pGrid->nSubtileWidth <= nX + 1)
                {
                    nCase += 4;
                }

                if (pGrid->nSubtileY + pGrid->nSubtileHeight <= nY + 1)
                {
                    nCase += 8;
                }

                const int nWidth = pGrid->nSubtileWidth;
                unsigned short* p = &pCollisionMask[(nY - pGrid->nSubtileY) * nWidth - pGrid->nSubtileX + nX];

                int nResult;
                switch (nCase)
                {
                case 0:
                    nResult = (nMask & (*p | p[1] | *(p - 1) | p[-nWidth] | p[nWidth]));
                    break;
                case 1:
                    nResult = COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask) | (nMask & (*p | p[1] | p[-nWidth] | p[nWidth]));
                    break;
                case 2:
                    nResult = COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask) | (nMask & (*p | p[1] | *(p - 1) | p[nWidth]));
                    break;
                case 3:
                    nResult = COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask) | (nMask & (*p | p[1] | p[nWidth]));
                    break;
                case 4:
                    nResult = COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask) | (nMask & (*p | *(p - 1) | p[-nWidth] | p[nWidth]));
                    break;
                case 6:
                    nResult = COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask) | (nMask & (*p | *(p - 1) | p[nWidth]));
                    break;
                case 8:
                    nResult = COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask) | (nMask & (*p | p[1] | *(p - 1) | p[-nWidth]));
                    break;
                case 9:
                    nResult = COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask) | (nMask & (*p | p[1] | p[-nWidth]));
                    break;
                case 12:
                    nResult = COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask) | (nMask & (*p | *(p - 1) | p[-nWidth]));
                    break;
                default:
                    nResult = nMask;
                    break;
                }

                return nResult;
            }
        }
    }

    return nMask;
}

// 0x0064D450
static unsigned short __fastcall sub_0064D450(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    return COLLISION_CheckCollisionMask(pRoom, nX, nY, nMask);
}

#if 0

{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
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

#endif

// 0x0064D4A0
static unsigned short __fastcall sub_0064D4A0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;
    COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, 3, 3);
    return COLLISION_CheckCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// 0x0064D4E0
static int __stdcall COLLISION_CheckAnyCollisionWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
    {
        return 1;
    }

    D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pGrid || !pGrid->pCollisionMask)
    {
        return 1;
    }

    int nResult;
    int nCase = 0;
    if (pGrid->nSubtileX >= nX)
    {
        nCase = 1;
    }

    if (pGrid->nSubtileY >= nY)
    {
        nCase += 2;
    }

    if (pGrid->nSubtileX + pGrid->nSubtileWidth <= nX + 1)
    {
        nCase += 4;
    }

    if (pGrid->nSubtileY + pGrid->nSubtileHeight <= nY + 1)
    {
        nCase += 8;
    }

    const int nWidth = pGrid->nSubtileWidth;
    unsigned short* p = &pGrid->pCollisionMask[(nY - pGrid->nSubtileY) * nWidth - pGrid->nSubtileX + nX];

    switch (nCase)
    {
    case 0:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[1])
            || (nMask & p[-nWidth])
            || (nMask & p[nWidth]))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 1:
        if ((nMask & *p)
            || (nMask & p[1])
            || (nMask & p[-nWidth])
            || (nMask & p[nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 2:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[1])
            || (nMask & p[nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 3:
        if ((nMask & *p)
            || (nMask & p[1])
            || (nMask & p[nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask)
            || COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 4:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[-nWidth])
            || (nMask & p[nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 6:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask)
            || COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 8:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[1])
            || (nMask & p[-nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 9:
        if ((nMask & *p)
            || (nMask & p[1])
            || (nMask & p[-nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask)
            || COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 12:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[-nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask)
            || COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask))
        {
            goto Collide;
        }
        return 0;

    default:
    Collide:
        nResult = 1;
        break;
    }

    return nResult;
}

// 0x0064D7C0
static int __fastcall sub_0064D7C0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;
    COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, 3, 3);
    return COLLISION_CheckAnyCollisionForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

inline void COLLISION_CreateBoundingBoxInline(D2BoundingBoxStrc* pBoundingBox, int nCenterX, int nCenterY, unsigned int nSizeX, unsigned int nSizeY)
{
    pBoundingBox->nLeft = nCenterX - (nSizeX / 2);
    pBoundingBox->nRight = pBoundingBox->nLeft + nSizeX - 1;
    pBoundingBox->nBottom = nCenterY - (nSizeY / 2);
    pBoundingBox->nTop = pBoundingBox->nBottom + nSizeY - 1;
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

// 0x0064D910
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask)
{
    switch (nCollisionPattern)
    {
    case 0:
        return sub_0064D450(pRoom, nX, nY, nMask);

    case 1:
    case 3:
        return COLLISION_CheckAnyCollisionWithAdjacentCells(pRoom, nX, nY, nMask);

    case 2:
    case 4:
        return sub_0064D7C0(pRoom, nX, nY, nMask);

    case 5:
        return COLLISION_CheckAnyCollisionWithAdjacentCells(pRoom, nX, nY, nMask);

    default:
        return 1;
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

// 0x0064DA40
static void __fastcall sub_0064DA40(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    sub_0064DB70(pRoom, nX - 1, nY, nMask);
    sub_0064DB70(pRoom, nX, nY, nMask);
    sub_0064DB70(pRoom, nX + 1, nY, nMask);
    sub_0064DB70(pRoom, nX, nY - 1, nMask);
    sub_0064DB70(pRoom, nX, nY + 1, nMask);
}

// 0x0064DB70
static void __fastcall sub_0064DB70(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
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
                pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] &= ~nMask;
            }
        }
    }
}

// 0x0064DBC0
static void __fastcall sub_0064DBC0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;
    COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, 3, 3);
    COLLISION_ResetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// 0x0064DC00
void __stdcall COLLISION_ResetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;

    if ((int)nSizeX > 0 && (int)nSizeY > 0)
    {
        if (nSizeX != 1 || nSizeY != 1)
        {
            COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, nSizeX, nSizeY);
            COLLISION_ResetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
        }
        else
        {
            COLLISION_ResetCollisionMask(pRoom, nX, nY, nMask);
        }
    }
}

// 0x0064DC80
static void __fastcall sub_0064DC80(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    sub_0064DDB0(pRoom, nX - 1, nY, nMask);
    sub_0064DDB0(pRoom, nX, nY, nMask);
    sub_0064DDB0(pRoom, nX + 1, nY, nMask);
    sub_0064DDB0(pRoom, nX, nY - 1, nMask);
    sub_0064DDB0(pRoom, nX, nY + 1, nMask);
}

// 0x0064DDB0
static void __fastcall sub_0064DDB0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
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

// 0x0064DDF0
static void __fastcall sub_0064DDF0(D2ActiveRoomStrc* pRoom, int nX, int nY, int nMask)
{
    D2BoundingBoxStrc pBoundingBox;
    COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, 3, 3);
    COLLISION_SetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// @ref 0x0064EA00
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


// @ref 0x0064EBA0
void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask)
{
    if (pRoom)
    {
        switch (nUnitSize)
        {
        case 1:
            sub_0064DB70(pRoom, nX, nY, nMask);
            break;

        case 2:
            sub_0064DA40(pRoom, nX, nY, nMask);
            break;

        case 3:
            sub_0064DBC0(pRoom, nX, nY, nMask);
            break;
        }
    }
}


// 0x0064DE30
void __stdcall COLLISION_SetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, int nMask)
{
    D2BoundingBoxStrc pBoundingBox;

    if (nSizeX != 1 || nSizeY != 1)
    {
        COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, nSizeX, nSizeY);
        COLLISION_SetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
    }
    else
    {
        COLLISION_SetCollisionMask(pRoom, nX, nY, nMask);
    }
}

// 0x0064DEA0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesImpl(D2ActiveRoomStrc* pRoom, D2CoordStrc* ptSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms, int nMaxDistance, int nPosIncrementValue)
{
    D2_ASSERT(ptSpawnPoint, 0x726);

    const D2CoordStrc tSpawn = *ptSpawnPoint;
    D2FieldStrc* pField = 0;

    if (pFieldCoord)
    {
        pField = DATATBLS_AllocField();
        D2_ASSERT(pField, 0x730);

        DATATBLS_SetFieldCoordinates(pField, pFieldCoord->nX, pFieldCoord->nY);
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, ptSpawnPoint->nX, ptSpawnPoint->nY);

    if (pRoom && !COLLISION_CheckMaskWithSize(pRoom, ptSpawnPoint->nX, ptSpawnPoint->nY, nUnitSize, nMask))
    {
        if (!pFieldCoord || !D2Common_11099(pField, pRoom, ptSpawnPoint->nX, ptSpawnPoint->nY, nFieldMask))
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
                D2ActiveRoomStrc* pTemp = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
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
                            ptSpawnPoint->nX = nX;
                            ptSpawnPoint->nY = nY;
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
                D2ActiveRoomStrc* pTemp = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
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
                            ptSpawnPoint->nX = nX;
                            ptSpawnPoint->nY = nY;
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
        return sub_00463740_FindRoomAtPoint(pRoom, ptSpawnPoint->nX, ptSpawnPoint->nY);
    }

    if (bAllowNeighborRooms)
    {
        return sub_00463740_FindRoomAtPoint(pRoom, ptSpawnPoint->nX, ptSpawnPoint->nY);
    }

    return 0;
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
