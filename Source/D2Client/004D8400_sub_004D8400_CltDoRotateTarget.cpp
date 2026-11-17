struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int unk0x04[10];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                               // 0x004D30C0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                             // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648900
int __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int a3);                     // 0x00649970
extern "C" int __stdcall sub_0064A3B0(D2UnitStrc* pUnit);                                                   // 0x0064A3B0
extern "C" int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pUnit);                              // 0x0064A730
extern "C" int __stdcall sub_0064A780_targetValue(D2UnitStrc* pUnit);                                         // 0x0064A780
extern "C" void __stdcall sub_00648AD0(D2DynamicPathStrc* pPath, unsigned short wA, unsigned short wB);     // 0x00648AD0

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004D8400
void __fastcall sub_004D8400_CltDoRotateTarget(D2UnitStrc* pMissile)
{
    if (!(sub_0064A3B0(pMissile) % 2))
    {
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        int nX = UNITS_GetUnitXPosition(pMissile);
        int nY = UNITS_GetUnitYPosition(pMissile);
        int nDX = nX - sub_0064A730_GetMissileTargetStatus(pMissile);
        int nDY = nY - sub_0064A780_targetValue(pMissile);
        sub_00648AD0(pPath, nX + nDY, nY - nDX);
        D2Common_10142(pPath, pMissile, 0);
    }
    sub_004D30C0_CltDoCommon(pMissile);
}
