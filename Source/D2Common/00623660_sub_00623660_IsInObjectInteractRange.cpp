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
    int dwClassId;
    char unk0x08[0x24];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit);                                                        // 0x006205A0
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                       // 0x00641530

__forceinline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00623660
int __stdcall sub_00623660_IsInObjectInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject)
{
    int nX1 = 0;
    int nY1 = 0;
    int nX2 = 0;
    int nY2 = 0;
    int nX = 0;
    int nY = 0;
    int nSizeX2 = 0;
    int nSizeY2 = 0;

    const int nObjectType = pObject ? pObject->dwUnitType : 6;
    if (nObjectType != 2)
    {
        return 0;
    }

    if ((unsigned int)D2Common_10399(pUnit, pObject) <= 0)
    {
        return 1;
    }

    nX1 = UNITS_GetXPositionInline(pUnit);
    nY1 = UNITS_GetYPositionInline(pUnit);

    nX2 = UNITS_GetXPositionInline(pObject);
    nY2 = UNITS_GetYPositionInline(pObject);

    nSizeX2 = UNITS_GetUnitSizeX(pObject);
    nSizeY2 = UNITS_GetUnitSizeY(pObject);

    nX = nX2 - nSizeX2 / 2;
    nY = nY2 - nSizeY2 / 2;

    if (nSizeX2 >= 1 && nSizeY2 >= 1)
    {
        if (nX1 >= nX - 2 && nX1 <= nSizeX2 + nX + 2 && nY1 >= nY - 2 && nY1 <= nSizeY2 + nY + 2)
        {
            if ((unsigned int)UNITS_GetUnitSizeX(pUnit) > 2)
            {
                return 1;
            }

            if (nY1 < nY - 1)
            {
                return nX1 >= nX - 1 && nX1 <= nSizeX2 + nX + 1;
            }

            return nY1 <= nSizeY2 + nY + 1 || (nX1 >= nX - 1 && nX1 <= nSizeX2 + nX + 1);
        }

        return 0;
    }

    return nX1 >= nX - 1 && nX1 <= nX + 1 && nY1 >= nY - 1 && nY1 <= nY + 1;
}
