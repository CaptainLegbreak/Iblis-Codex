struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2UnitStrc;

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0xB8];
    D2UnitStrc* pRoomNext;
};

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

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define MONSTATSFLAGINDEX_NOAURA 27

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                              // 0x006492A0
int __fastcall sub_6FD0FA00(D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned int nAuraFilter);              // 0x0056B3E0
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY);              // 0x00463740

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int SKILLS_IsInRangeY(int nY, int nDistance, const D2DrlgCoordsStrc& drlgCoords)
{
    return nY + nDistance >= drlgCoords.nSubtileY || nY - nDistance <= drlgCoords.nSubtileY + drlgCoords.nSubtileHeight;
}

// 0x0056B770
static int sub_0056B770_IsRoomInRange(D2ActiveRoomStrc* pRoom, int nX, int nY, int nDistance)
{
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);
    if (nX + nDistance >= drlgCoords.nSubtileX)
    {
        return SKILLS_IsInRangeY(nY, nDistance, drlgCoords);
    }
    if (nX - nDistance <= drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
    {
        return SKILLS_IsInRangeY(nY, nDistance, drlgCoords);
    }
    return 0;
}

// 0x0056B7E0
void __fastcall sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int (__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine)
{
    if (!pGame || !pUnit || !pCallback || nAuraRange <= 0)
    {
        return;
    }

    D2ActiveRoomStrc* pCurrentRoom = UNITS_GetRoom(pUnit);
    if (!pCurrentRoom)
    {
        return;
    }

    if (!nX || !nY)
    {
        nX = CLIENTS_GetUnitX(pUnit);
        nY = CLIENTS_GetUnitY(pUnit);
    }

    if (!nAuraFilter)
    {
        nAuraFilter = 0x583;
    }

    D2AuraCallbackStrc auraCallback;
    auraCallback.pArgs = pCallbackArgs;
    auraCallback.pGame = pGame;
    auraCallback.pOwner = pUnit;
    auraCallback.nCounter = 0;
    const int nAuraRangeSq = nAuraRange * nAuraRange;

    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pCurrentRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        if (!(nAuraFilter & 0x2000) || !DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            if (sub_0056B770_IsRoomInRange(ppRoomList[i], nX, nY, nAuraRange))
            {
                D2UnitStrc* pTarget = ppRoomList[i]->pUnitFirst;
                while (pTarget)
                {
                    D2UnitStrc* pNextTarget = pTarget->pRoomNext;
                    if (pTarget != pUnit && nAuraRangeSq >= PATH_ComputeSquaredDistance(nX, nY, UNITS_GetUnitXPosition(pTarget), UNITS_GetUnitYPosition(pTarget)) && sub_6FD0FA00(pUnit, pTarget, nAuraFilter))
                    {
                        if (!bCheckMonAuraFlag || pTarget->dwUnitType != UNIT_MONSTER || !sub_00457490_CheckMonStatsFlag(pTarget->dwClassId, MONSTATSFLAGINDEX_NOAURA))
                        {
                            if (pCallback(&auraCallback, pTarget))
                            {
                                auraCallback.nCounter += 1;
                            }
                        }
                    }
                    pTarget = pNextTarget;
                }
            }
        }
    }
}

// 0x0056E780
int __fastcall sub_6FD10360(D2GameStrc* pGame, unsigned int nFlags, D2UnitStrc* pUnit, int nDistance, int (__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs)
{
    if (!pCallback)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    const int nDistanceSq = nDistance * nDistance;
    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (int i = 0; i < nNumRooms; ++i)
    {
        if (!(nFlags & 0x2000) || !DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            if (sub_0056B770_IsRoomInRange(ppRoomList[i], nX, nY, nDistance))
            {
                for (D2UnitStrc* j = ppRoomList[i]->pUnitFirst; j; j = j->pRoomNext)
                {
                    if (nDistanceSq >= PATH_ComputeSquaredDistance(nX, nY, UNITS_GetUnitXPosition(j), UNITS_GetUnitYPosition(j)) && sub_6FD0FA00(pUnit, j, nFlags))
                    {
                        pCallback(j, pArgs);
                    }
                }
            }
        }
    }

    return 1;
}
