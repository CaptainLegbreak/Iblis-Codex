#include "D2Common.h"
#include "D2Structs.h"

struct D2DynamicPathStrc
{
    char unk0x00[0x10];
    unsigned int tTargetCoord;
    char unk0x14[0x18 - 0x14];
    unsigned int tFinalTargetCoord;
    char unk0x1C[0x24 - 0x1C];
    int dwCurrentPointIdx;
    char unk0x28[0x34 - 0x28];
    unsigned int dwFlags;
    char unk0x38[0x3C - 0x38];
    int dwPathType;
};


int __stdcall PATH_GetDistance(D2DynamicPathStrc* pDynamicPath); // 0x00649120
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
void __stdcall PATH_AddToDistance(D2DynamicPathStrc* pDynamicPath, int nAddition); // 0x00649140
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

// 0x00650350
int __stdcall D2Common_10236(D2UnitStrc* pUnit, int a2)
{
    int nResult = 0;

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 0;
    }

    if (!(pDynamicPath->dwFlags & 0x10))
    {
        const int nType = pUnit ? pUnit->dwUnitType : 6;
        if (nType == 1 && !PATH_GetDistance(pUnit->pDynamicPath))
        {
            return 0;
        }

        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= 1;

        PATH_AddToDistance(pDynamicPath, -pDynamicPath->dwCurrentPointIdx);
    }

    switch (pDynamicPath->dwPathType)
    {
    case 2:
    case 13:
    case 15:
        break;

    default:
        return D2Common_10142(pDynamicPath, pUnit, 0);
    }

    if (a2)
    {
        pDynamicPath->dwPathType = 13;
    }
    else
    {
        pDynamicPath->dwPathType = 2;
        pDynamicPath->tTargetCoord = pDynamicPath->tFinalTargetCoord;
    }

    nResult = D2Common_10142(pDynamicPath, pUnit, 0);
    if (!nResult)
    {
        pDynamicPath->dwPathType = 15;
        nResult = D2Common_10142(pDynamicPath, pUnit, 0);
    }

    return nResult;
}

static __forceinline int UNITS_IsServerSide(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 21) & 1;
    }
    return bResult;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x006504F0
int __fastcall sub_006504F0_TestPathFlag10(D2UnitStrc* pUnit, D2DynamicPathStrc* pPath)
{
    switch (sub_0044BE50(pUnit))
    {
    case 0:
        if (!(pPath->dwFlags & 0x10))
        {
            return 0;
        }
        break;

    case 1:
        if (pPath->dwFlags & 0x10)
        {
            if (!UNITS_IsServerSide(pUnit))
            {
                return 0;
            }
        }
        break;
    }

    return 1;
}
