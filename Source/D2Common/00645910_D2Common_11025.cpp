struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2StaticPathStrc
{
    char unk0x00[12];
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[44 - 4];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

inline int UNITS_GetXPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetYPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00645910
int __stdcall D2Common_11025(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int a6)
{
    D2CoordStrc pCoords1;
    D2CoordStrc pCoords2;

    pCoords1.nX = nX1;
    pCoords1.nY = nY1;
    pCoords2.nX = nX2;
    pCoords2.nY = nY2;

    return COLLISION_RayTrace(pRoom, &pCoords1, &pCoords2, a6) == 0;
}

// 0x00645950
int __stdcall D2Common_11026(int nX, int nY, D2UnitStrc* pUnit, int nColMask)
{
    int nUnitY = UNITS_GetYPositionInl(pUnit);
    int nUnitX = UNITS_GetXPositionInl(pUnit);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2CoordStrc pCoords1;
    D2CoordStrc pCoords2;

    pCoords1.nX = nX;
    pCoords1.nY = nY;
    pCoords2.nX = nUnitX;
    pCoords2.nY = nUnitY;

    return COLLISION_RayTrace(pRoom, &pCoords1, &pCoords2, nColMask) == 0;
}
