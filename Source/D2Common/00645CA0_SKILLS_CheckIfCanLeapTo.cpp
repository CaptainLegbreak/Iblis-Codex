struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
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
    char unk0x04[0x2C - 0x04];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
};
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY);                      // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                           // 0x0061AB00
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                             // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                               // 0x00620BB0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                          // 0x00622C40
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                                                // 0x006417F0
int __stdcall sub_00645910_TestLine(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int nMask);           // 0x00645910
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                       // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                       // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                                // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                                // 0x00648A10
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                                   // 0x00649180
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define COLLIDE_MASK_PLAYER_PATH 0x1C09
#define COLLIDE_MASK_LINE 0x804

static __forceinline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int UNITS_GetYPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static int __stdcall sub_00645C60_IsOutsideTown(int nX, int nY, D2UnitStrc* pUnit); // 0x00645C60

static int __stdcall sub_00645C60_IsOutsideTown(int nX, int nY, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    return !DUNGEON_IsRoomInTown(pRoom);
}

// 0x00645CA0
int __stdcall SKILLS_CheckIfCanLeapTo(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int* pX, int* pY)
{
    struct { int n; } tX2 = {}, tY2 = {};

    if (pUnit2 && UNITS_IsInMeleeRange(pUnit1, pUnit2, 0))
    {
        return 0;
    }

    const int nX1 = UNITS_GetXPositionForceInl(pUnit1);
    const int nY1 = UNITS_GetYPositionForceInl(pUnit1);

    if (pUnit2)
    {
        tX2.n = UNITS_GetXPositionForceInl(pUnit2);
        tY2.n = UNITS_GetYPositionForceInl(pUnit2);
    }
    else
    {
        tX2.n = D2COMMON_10175_PathGetFirstPointX(pUnit1->pDynamicPath);
        tY2.n = D2COMMON_10176_PathGetFirstPointY(pUnit1->pDynamicPath);
    }

    const int nDivisor = UNITS_GetDistanceToCoordinates(pUnit1, tX2.n, tY2.n);
    if (!nDivisor)
    {
        return 0;
    }

    int nX = tX2.n + 2 * (tX2.n - nX1) / nDivisor;
    int nY = tY2.n + 2 * (tY2.n - nY1) / nDivisor;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit1);
    D2_ASSERT(pRoom, 4286);

    const int nPattern = PATH_GetUnitCollisionPattern(pUnit1);
    if (COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, nPattern, COLLIDE_MASK_PLAYER_PATH))
    {
        D2CoordStrc tCoord;
        tCoord.nX = tX2.n;
        tCoord.nY = tY2.n;
        pRoom = COLLISION_GetFreeCoordinates(pRoom, &tCoord, UNITS_GetUnitSizeX(pUnit1), COLLIDE_MASK_PLAYER_PATH, 0);
        if (!pRoom)
        {
            return 0;
        }
        nX = tCoord.nX;
        nY = tCoord.nY;
    }

    if (!sub_00645910_TestLine(UNITS_GetXPositionForceInl(pUnit1), UNITS_GetYPositionForceInl(pUnit1), nX, nY, pRoom, COLLIDE_MASK_LINE))
    {
        return 0;
    }

    *pX = nX;
    *pY = nY;
    return sub_00645C60_IsOutsideTown(nX, nY, pUnit1) != 0;
}
