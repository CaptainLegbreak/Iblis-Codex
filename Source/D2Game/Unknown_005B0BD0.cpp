#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2GameAux.h"

struct D2MonStatsTxt;

enum
{
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180

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

// 0x005B0BD0
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    const int nXDiff = CLIENTS_GetUnitX(pUnit1) - CLIENTS_GetUnitX(pUnit2);
    const int nYDiff = CLIENTS_GetUnitY(pUnit1) - CLIENTS_GetUnitY(pUnit2);

    return nXDiff * nXDiff + nYDiff * nYDiff;
}

// 0x005B0D60
int __fastcall AITHINK_GetSpecialStateFromAiControl(D2AiControlStrc* pAiControl)
{
    return pAiControl->nAiSpecialState;
}

// 0x005B0DA0
int __fastcall AITHINK_CanUnitSwitchAi(D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxtRecord, int nAiSpecialState, int bCheckIfSuperUnique)
{
    if (nAiSpecialState == 0)
    {
        return 1;
    }

    if (nAiSpecialState != 10 && nAiSpecialState != 11 && nAiSpecialState != 12)
    {
        return 1;
    }

    if (bCheckIfSuperUnique && MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 2))
    {
        return 0;
    }

    if (!pUnit)
    {
        return UNITS_CanSwitchAI(-1);
    }

    return UNITS_CanSwitchAI(pUnit->dwClassId);
}

// 0x005B1BC0
D2TargetNodeStrc* __fastcall sub_005B1BC0_FindTargetNode(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    if (!pGame || !pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return 0;
    }

    const int nNodeIndex = pUnit->dwNodeIndex;
    if (nNodeIndex == 11)
    {
        return 0;
    }

    for (D2TargetNodeStrc* pNode = pGame->pTargetNodes[nNodeIndex]; pNode; pNode = pNode->pNext)
    {
        if (pNode->hUnit == pUnit)
        {
            return pNode;
        }
    }

    return 0;
}
