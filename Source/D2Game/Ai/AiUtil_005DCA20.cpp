#include "D2Structs.h"
#include "D2GameTypes.h"
#define UNIT_PAD 0xC0
struct D2GameStrc;
struct D2ActiveRoomStrc;



struct D2AiTargetSearchArgsStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int bCheckTargetCollision;
    int nMaxDistance;
    int unk0x10;
    D2UnitStrc* pAlternativeTarget;
    int nAlternativeDistance;
};

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                     // 0x00554200
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380
int __fastcall sub_005DC920_GetThreat(D2UnitStrc* pUnit);                                                   // 0x005DC920
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40
extern "C" unsigned int __fastcall sub_00541860(D2UnitStrc* pUnit);                                       // 0x00541860
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __stdcall D2Common_10095(D2ActiveRoomStrc* pRoom, int nX, int nY);                                      // 0x0061B130

static inline int UNITS_CanBeAttackedInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 2) & 1;
    return bResult;
}

// 0x005DCA20
static int __stdcall sub_005DCA20_IsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
 if (!pTarget) return 0;
 if (pTarget->dwUnitType < 0 || pTarget->dwUnitType > 1 || SUNIT_IsDead(pTarget) || !UNITS_CanBeAttackedInline(pTarget)) return 0;
 return SUNIT_AreUnitsHostile(pGame,pUnit,pTarget);
}
// @ref 0x005DCA70
D2UnitStrc* __fastcall AIUTIL_TargetCallback_SelectHostileTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2AiTargetSearchArgsStrc* pArg = (D2AiTargetSearchArgsStrc*)pCallbackArg;

    if (!pTarget)
    {
        return 0;
    }

    if (!sub_005DCA20_IsHostile(pGame, pUnit, pTarget))
    {
        if (pTarget->dwUnitType == UNIT_MONSTER && (!pUnit || pUnit->dwUnitType != UNIT_PLAYER) && !STATLIST_GetUnitAlignment(pUnit) && pArg->bCheckTargetCollision && !MONSTERS_IsDead(pTarget))
        {
            D2AiControlStrc* pAiControl = (D2AiControlStrc*)sub_00541860(pTarget);
            if ((pAiControl->nAiFlags & 8) && pArg->unk0x10 == D2Common_10095(UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget)))
            {
                pAiControl->nAiFlags |= 8;
                pArg->bCheckTargetCollision = 0;
            }
        }

        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > pArg->nMaxDistance)
    {
        return 0;
    }

    const int nThreat = sub_005DC920_GetThreat(pTarget);
    if (nThreat > 1)
    {
        if (nDistance >= pArg->nDistance)
        {
            return 0;
        }
    }
    else if (nDistance >= pArg->nAlternativeDistance)
    {
        return 0;
    }

    if (pArg->bCheckTargetCollision && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
    {
        return 0;
    }

    if (nThreat > 1)
    {
        pArg->pTarget = pTarget;
        pArg->nDistance = nDistance;
    }
    else
    {
        pArg->pAlternativeTarget = pTarget;
        pArg->nAlternativeDistance = nDistance;
    }

    return 0;
}
