#include "D2Client.h"

struct D2CoordStrc { int nX; int nY; };
struct D2StaticPathStrc { void* pRoom; int dwClientCoordX; int dwClientCoordY; D2CoordStrc tGameCoords; };
struct D2UnitStrc { int dwUnitType; char pad04[0x28]; union { D2StaticPathStrc* pStaticPath; D2DynamicPathStrc* pDynamicPath; }; };
enum D2C_UnitTypes { UNIT_OBJECT = 2, UNIT_ITEM = 4, UNIT_TILE = 5 };

D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nArg, int nX, int nY, int nArg3, int nArg4); // 0x004CDB40

// 0x004C51E0
void __fastcall sub_004C51E0_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    const int nDirection = UNITS_GetDirection(pUnit) >> 3;
    int aOffsetX[8] = { 0, -1, -2, -1, 0, 1, 2, 1 };
    int aOffsetY[8] = { 2, 1, 0, -1, -2, -1, 0, 1 };

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }
    *pX = aOffsetX[nDirection] + nX;

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }
    *pY = aOffsetY[nDirection] + nY;
}

// 0x004C52E0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    int nY;
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget)
    {
        int nX;
        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nX = pTarget->pStaticPath->tGameCoords.nX;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nX = PATH_GetXPosition(pTarget->pDynamicPath);
            }
            else
            {
                nX = 0;
            }
            break;
        }
        *pX = nX;

        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nY = pTarget->pStaticPath->tGameCoords.nY;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nY = PATH_GetYPosition(pTarget->pDynamicPath);
            }
            else
            {
                nY = 0;
            }
            break;
        }
    }
    else
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    *pY = nY;

    if (!*pX || !nY)
    {
        sub_004C51E0_GetAdjacentPosition(pUnit, pX, pY);
    }
    return 1;
}

// 0x004C5470
int __fastcall sub_004C5470_RequestAtTarget(D2UnitStrc* pUnit, int nArg, int nArg3, int nArg4)
{
    int nTargetY;
    int nTargetX;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (!nTargetX || !nTargetY)
    {
        return 0;
    }

    if (PATH_ComputeSquaredDistance(CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nTargetX, nTargetY) > 10000)
    {
        return 0;
    }

    return sub_004CDB40_SubmitRequest(pUnit, nArg, nTargetX, nTargetY, nArg3, nArg4);
}
