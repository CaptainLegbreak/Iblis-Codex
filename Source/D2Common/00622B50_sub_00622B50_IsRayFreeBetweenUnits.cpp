#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5

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
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned int __fastcall UNITS_GetCollisionMask(D2UnitStrc* pUnit);                                          // 0x006209D0
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit);                                        // 0x00649400
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce);                         // 0x00649560
int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260

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

static __declspec(noinline) int __stdcall sub_00622920_RayTraceBetweenBoxes(int nX1, int nY1, int nSize1, int nX2, int nY2, int nSize2, D2ActiveRoomStrc* pRoom, int nCollisionMask);
static int __stdcall sub_00622920_RayTraceBetweenBoxes(int nX1, int nY1, int nSize1, int nX2, int nY2, int nSize2, D2ActiveRoomStrc* pRoom, int nCollisionMask)
{
    COLLISION_RayTrace((D2ActiveRoomStrc*)nSize2, (D2CoordStrc*)nX1, (D2CoordStrc*)nX2, 0);
    return COLLISION_RayTrace(pRoom, (D2CoordStrc*)nY1, (D2CoordStrc*)nSize1, nY2 + nCollisionMask);
}

// build: context sub_006229F0_IsRayFreeFromUnit
int __stdcall sub_006229F0_IsRayFreeFromUnit(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask)
{
    if (!pUnit)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nUnitX = UNITS_GetXPositionForceInl(pUnit);
    const int nUnitY = UNITS_GetYPositionForceInl(pUnit);
    return sub_00622920_RayTraceBetweenBoxes(nUnitX, nUnitY, UNITS_GetUnitSizeX(pUnit), nX, nY, 2, pRoom, nCollisionMask);
}

// 0x00622B50
int __stdcall sub_00622B50_IsRayFreeBetweenUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask)
{
    if (!pUnit1 || !pUnit2)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit1);
    if (!pRoom)
    {
        return 0;
    }

    const int nX1 = CLIENTS_GetUnitX(pUnit1);
    const int nY1 = CLIENTS_GetUnitY(pUnit1);
    const int nX2 = CLIENTS_GetUnitX(pUnit2);
    const int nY2 = CLIENTS_GetUnitY(pUnit2);
    int bRemoved1 = 0;
    int bRemoved2 = 0;
    if (UNITS_GetCollisionMask(pUnit1) & nCollisionMask)
    {
        bRemoved1 = PATH_RemoveCollisionFootprintForUnit(pUnit1, 0);
    }

    if (UNITS_GetCollisionMask(pUnit2) & nCollisionMask)
    {
        bRemoved2 = PATH_RemoveCollisionFootprintForUnit(pUnit2, 0);
    }

    const int nResult = sub_00622920_RayTraceBetweenBoxes(nX1, nY1, UNITS_GetUnitSizeX(pUnit1), nX2, nY2, UNITS_GetUnitSizeX(pUnit2), pRoom, nCollisionMask);
    if (bRemoved1)
    {
        PATH_AddCollisionFootprintForUnit(pUnit1);
    }

    if (bRemoved2)
    {
        PATH_AddCollisionFootprintForUnit(pUnit2);
    }

    return nResult;
}
