#include "D2Game.h"

struct D2StaticPathStrc;
struct SynCoord;
struct SynStatic;
struct SynUnit;

enum D2C_Y10AiUtilConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
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
    char unk0x04[0x28];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

struct SynCoord { int nX; int nY; };

struct SynStatic { char unk0[0x0C]; SynCoord tGameCoords; };

struct SynUnit { int dwUnitType; char unk4[0x28]; union { SynStatic* pStaticPath; D2DynamicPathStrc* pDynamicPath; }; };

int __stdcall sub_006488C0_PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall sub_00648900_PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall sub_00620510_UNITS_GetUnitSizeX(SynUnit* pUnit); // 0x00620510

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

// 0x005DC380
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource)
{
    int nXDiff = CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pSource);
    int nYDiff = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pSource);
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }
    if (nYDiff < 0)
    {
        nYDiff = -nYDiff;
    }

    const int nSize = UNITS_GetUnitSizeX(pTarget);
    nXDiff -= nSize;
    nYDiff -= nSize;
    if (nXDiff < 0)
    {
        nXDiff = 0;
    }
    if (nYDiff < 0)
    {
        nYDiff = 0;
    }

    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }

    return (nXDiff + 2 * nYDiff) / 2;
}

static __forceinline int synh_GetUnitX(SynUnit* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? sub_006488C0_PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int synh_GetUnitY(SynUnit* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? sub_00648900_PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// build: context DistanceWithSize
static __forceinline int DistanceWithSize(int nX, int nY, SynUnit* pUnit)
{
    int nXDiff = synh_GetUnitX(pUnit) - nX;
    int nYDiff = synh_GetUnitY(pUnit) - nY;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }
    if (nYDiff < 0)
    {
        nYDiff = -nYDiff;
    }

    const int nSize = ((unsigned int)sub_00620510_UNITS_GetUnitSizeX(pUnit) >> 1) + 1;
    nXDiff -= nSize;
    nYDiff -= nSize;
    if (nXDiff < 0)
    {
        nXDiff = 0;
    }
    if (nYDiff < 0)
    {
        nYDiff = 0;
    }

    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }

    return (nXDiff + 2 * nYDiff) / 2;
}

// 0x005DC480
int __fastcall sub_005DC480_Distance(SynUnit* pUnit, int nX, int nY)
{
    return DistanceWithSize(nX, nY, pUnit);
}
