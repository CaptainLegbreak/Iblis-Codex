struct D2DynamicPathStrc;
struct SynCoord { int nX; int nY; };
struct SynStatic { char unk0[0x0C]; SynCoord tGameCoords; };
struct SynUnit { int dwUnitType; char unk4[0x28]; union { SynStatic* pStaticPath; D2DynamicPathStrc* pDynamicPath; }; };
int __stdcall sub_006488C0_PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall sub_00648900_PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall sub_00620510_UNITS_GetUnitSizeX(SynUnit* pUnit);                                                           // 0x00620510

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
