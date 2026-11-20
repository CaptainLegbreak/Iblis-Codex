#include "D2Common.h"
#include "D2DrlgPresets.h"

#define MASK_NO_PATH 0x1000
#define MASK_PET 0x2000
struct D2CoordStrc;
struct D2RoomCollisionGridStrc;
struct D2BoundingBoxStrc;

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesImpl(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms, int nMaxDistance, int nPosIncrementValue); // 0x0064DEA0


struct D2BoundingBoxStrc
{
    int nLeft;
    int nBottom;
    int nRight;
    int nTop;
};

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2RoomCollisionGridStrc* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A010
void __fastcall COLLISION_SetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064D060
static void __stdcall sub_0064DDB0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

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

// 0x0064DC80
static void __stdcall sub_0064DC80(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    sub_0064DDB0(pRoom, nX - 1, nY, nMask);
    sub_0064DDB0(pRoom, nX, nY, nMask);
    sub_0064DDB0(pRoom, nX + 1, nY, nMask);
    sub_0064DDB0(pRoom, nX, nY - 1, nMask);
    sub_0064DDB0(pRoom, nX, nY + 1, nMask);
}

// 0x0064DDB0
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

// 0x0064DDF0
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
