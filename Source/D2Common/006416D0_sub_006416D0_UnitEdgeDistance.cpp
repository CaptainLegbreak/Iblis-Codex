struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
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

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

inline int UNITS_InlineGetX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int UNITS_InlineGetY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x006416D0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    int nX = UNITS_InlineGetX(pOther) - UNITS_InlineGetX(pUnit);
    int nXDiff = nX >= 0 ? nX : -nX;
    int nY = UNITS_InlineGetY(pOther) - UNITS_InlineGetY(pUnit);
    int nYDiff = nY < 0 ? -nY : nY;

    int nSize1 = UNITS_GetUnitSizeX(pUnit);
    int nSize2 = UNITS_GetUnitSizeX(pOther);
    nXDiff = nXDiff - nSize1 / 2 - nSize2 / 2;
    nYDiff = nYDiff - nSize1 / 2 - nSize2 / 2;

    if (nXDiff < 0)
    {
        nXDiff = 0;
    }

    if (nYDiff < 0)
    {
        nYDiff = 0;
    }

    return (nXDiff > nYDiff ? nYDiff + 2 * nXDiff : nXDiff + 2 * nYDiff) / 2;
}
