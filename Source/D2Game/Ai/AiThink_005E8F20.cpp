#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameAux.h"

struct D2AiBaalTargetArgsStrc;

#define UNIT_PLAYER 0
#define PLRMODE_DEATH 0
#define PLRMODE_DEAD 17
#define PATHTYPE_TOWARD 2

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY);               // 0x005DC530
int __fastcall AIBAAL_GetTargetScore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiBaalTargetArgsStrc* pArgs); // 0x005E8530
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);              // 0x00622C40
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTarget);        // 0x00648B90
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nType);                                    // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int a3);                   // 0x00649970

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005E8F20
D2UnitStrc* __fastcall AIBAAL_GetTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pMax, int* pCount, D2AiBaalTargetArgsStrc* pArgs, int (__fastcall* pfCull)(D2UnitStrc*, D2UnitStrc*))
{
    D2_ASSERT(pfCull, 890);

    UNITS_GetRoom(pUnit);

    D2UnitStrc* pTarget = 0;
    int nCount = 0;
    int nMax = 0;
    D2TargetNodeStrc** ppTargetNode = pGame->pTargetNodes;
    D2TargetNodeStrc* ptTargetNode = *ppTargetNode;
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    const unsigned char nAct = pUnit->nAct;

    for (int i = 0; i < 8; ++i)
    {
        if (ptTargetNode)
        {
            D2_ASSERT(ptTargetNode->hUnit && ptTargetNode->hUnit->dwUnitType == UNIT_PLAYER, 917);
            D2UnitStrc* pTargetUnit = ptTargetNode->hUnit;

            if (pfCull(pUnit, pTargetUnit))
            {
                int nCurrent;
                if (pTargetUnit && pTargetUnit->dwAnimMode != PLRMODE_DEAD && pTargetUnit->dwAnimMode != PLRMODE_DEATH)
                {
                    nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                }
                else
                {
                    nCurrent = 0;
                }

                while (1)
                {
                    if (nMax < nCurrent)
                    {
                        nMax = nCurrent;
                        pTarget = pTargetUnit;
                    }

                    ptTargetNode = ptTargetNode->pNext;
                    ++nCount;

                    if (!ptTargetNode)
                    {
                        break;
                    }

                    pTargetUnit = ptTargetNode->hUnit;
                    nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                }
            }
        }

        ptTargetNode = *++ppTargetNode;
    }

    while (ptTargetNode)
    {
        D2UnitStrc* pTargetUnit = ptTargetNode->hUnit;
        if (nAct == pTargetUnit->nAct)
        {
            const int nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
            if (nMax < nCurrent)
            {
                nMax = nCurrent;
                pTarget = pTargetUnit;
            }
            ++nCount;
        }

        ptTargetNode = ptTargetNode->pNext;
    }

    ptTargetNode = ppTargetNode[1];

    D2UnitStrc* pTemp = 0;
    int nTemp = 0;
    if (ptTargetNode)
    {
        do
        {
            D2UnitStrc* pTargetUnit = ptTargetNode->hUnit;
            if (nAct == pTargetUnit->nAct)
            {
                const int nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                if (nTemp < nCurrent)
                {
                    nTemp = nCurrent;
                    pTemp = pTargetUnit;
                }
            }

            ptTargetNode = ptTargetNode->pNext;
        }
        while (ptTargetNode);

        if (pTemp && AIUTIL_GetDistanceToCoordinates_NoUnitSize(pTemp, nX, nY) < 5 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            sub_00648B90_SetPathTarget(pPath, pTarget);
            PATH_SetType(pPath, PATHTYPE_TOWARD);
            D2Common_10142(pPath, pUnit, 0);

            if (!sub_00648780_pointCount(pPath))
            {
                pTarget = pTemp;
                nMax = nTemp;
            }
        }
    }

    *pCount = nCount;
    *pMax = nMax;

    return pTarget;
}
