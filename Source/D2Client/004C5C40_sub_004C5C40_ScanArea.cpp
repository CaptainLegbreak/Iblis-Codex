struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

enum
{
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

struct D2StaticPathStrc
{
    void* pRoom;
    int nTargetX;
    int nTargetY;
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0xB8];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomViewStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileX;
    int nTileY;
    int nTileWidth;
    int nTileHeight;
};

struct D2AreaScanStrc
{
    D2UnitStrc* pUnit;
    int nCount;
    void* pArg;
};

typedef int (__fastcall* AREASCANFN)(D2AreaScanStrc* pScan, D2UnitStrc* pUnit);

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                             // 0x006492A0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);                                  // 0x00457490
int __fastcall sub_004C5960_CanScanUnit(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nFlags);               // 0x004C5960
static int sub_004C5BD0_IsPointNearRoom(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRadius);             // 0x004C5BD0

static __forceinline int U04_IsNearRoomY(const D2DrlgCoordsStrc* pCoords, int nY, int nRadius)
{
    return nY + nRadius >= pCoords->nSubtileY || nY - nRadius <= pCoords->nSubtileHeight + pCoords->nSubtileY;
}

static __declspec(noinline) int sub_004C5BD0_IsPointNearRoom(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRadius)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    if (nX + nRadius >= tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    if (nX - nRadius <= tCoords.nSubtileWidth + tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    return 0;
}

static __forceinline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004C5C40
void __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType)
{
    if (!pUnit || !pfCallback)
    {
        return;
    }

    if (!nRange)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    if (!nX || !nY)
    {
        nX = UNITS_GetXPosition(pUnit);
        nY = CLIENTS_GetUnitY(pUnit);
    }

    if (!nFlags)
    {
        nFlags = 0x583;
    }

    D2AreaScanStrc tScan;
    tScan.pArg = pArg;
    tScan.pUnit = pUnit;
    tScan.nCount = 0;
    const int nRangeSq = nRange * nRange;

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        if ((nFlags & 0x2000) && DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            continue;
        }

        if (!sub_004C5BD0_IsPointNearRoom(ppRoomList[i], nX, nY, nRange))
        {
            continue;
        }

        D2UnitStrc* pTarget = ((D2ActiveRoomViewStrc*)ppRoomList[i])->pUnitFirst;
        while (pTarget)
        {
            D2UnitStrc* pNext = pTarget->pRoomNext;
            if (pTarget != pUnit
                && nRangeSq >= PATH_ComputeSquaredDistance(nX, nY, UNITS_GetXPositionInline(pTarget), UNITS_GetYPositionInline(pTarget))
                && sub_004C5960_CanScanUnit(pUnit, pTarget, nFlags)
                && (!bCheckType || pTarget->dwUnitType != UNIT_MONSTER || !sub_00457490_CheckMonStatsFlag(pTarget->dwClassId, 0x1B))
                && pfCallback(&tScan, pTarget))
            {
                ++tScan.nCount;
            }
            pTarget = pNext;
        }
    }
}
