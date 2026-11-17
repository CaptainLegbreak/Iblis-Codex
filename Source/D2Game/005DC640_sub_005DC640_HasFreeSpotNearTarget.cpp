enum D2C_Y10AiUtilConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

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
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380
int __stdcall UNITS_TestCollisionByCoordinates(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask);      // 0x006229F0

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005DC640
int __fastcall sub_005DC640_HasFreeSpotNearTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pUnit || !pTarget)
    {
        return 0;
    }

    unsigned char aSteps[25] = { 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    int nStep;
    if (nDistance >= 25)
    {
        nStep = 3;
    }
    else
    {
        nStep = aSteps[nDistance];
    }

    const unsigned int nTargetX = CLIENTS_GetUnitX(pTarget);
    const unsigned int nTargetY = CLIENTS_GetUnitY(pTarget);
    int nX = CLIENTS_GetUnitX(pUnit) - nTargetX;
    int nY = CLIENTS_GetUnitY(pUnit) - nTargetY;

    if (nX < 0)
    {
        nX = -nStep;
    }
    else if (nX > 0)
    {
        nX = nStep;
    }

    if (nY < 0)
    {
        nY = -nStep;
    }
    else if (nY > 0)
    {
        nY = nStep;
    }

    if (!UNITS_TestCollisionByCoordinates(pUnit, nTargetX, nTargetY, 0x805))
    {
        return 1;
    }

    if (!UNITS_TestCollisionByCoordinates(pUnit, nTargetX - nY, nTargetY + nX, 0x805))
    {
        return 1;
    }

    return !UNITS_TestCollisionByCoordinates(pUnit, nTargetX + nY, nTargetY - nX, 0x805);
}
