struct D2GameStrc;
struct D2ActiveRoomStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
};

struct D2UnkAiCallbackArgStrc2
{
    D2UnitStrc* pTarget;
    int nDistance;
    D2UnitStrc* pAlternativeTarget;
    int nAlternativeDistance;
};

struct D2AiCallback7ArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    D2UnitStrc* unk0x08;
};

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);
int __fastcall sub_005DC920_GetThreat(D2UnitStrc* pUnit);
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);

// 0x005DC970
static int __stdcall sub_6FCF1A50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pUnit || pUnit->dwUnitType < 0 || pUnit->dwUnitType > 1 || !pTarget || pTarget->dwUnitType < 0 || pTarget->dwUnitType > 1 || SUNIT_IsDead(pTarget) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)) || !sub_00451F30_TestUnitFlag(pTarget, 4))
    {
        return 0;
    }

    if (STATES_CheckState(pTarget, 0x92))
    {
        switch (pTarget->dwUnitType)
        {
        case 0:
            if ((int)SEED_RollLimitedRandomNumber(&pTarget->pSeed, 100) < 80 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            {
                return 0;
            }
            break;
        case 1:
            if (UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            {
                return 0;
            }
            break;
        }
    }

    return sub_00554200(pGame, pUnit, pTarget);
}

D2UnitStrc* __fastcall sub_6FCF1980(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2UnkAiCallbackArgStrc2* pArg = (D2UnkAiCallbackArgStrc2*)pCallbackArg;

    if (!sub_6FCF1A50(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > 48)
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

    if (!UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
    {
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
    }

    return 0;
}

D2UnitStrc* __fastcall sub_6FCF1B30(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2AiCallback7ArgStrc* pArg = (D2AiCallback7ArgStrc*)pCallbackArg;

    if (pTarget == pArg->unk0x08)
    {
        return 0;
    }

    if (!sub_6FCF1A50(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > 48)
    {
        return 0;
    }

    if (sub_005DC920_GetThreat(pTarget) > 1 && nDistance < pArg->nDistance && !UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
    {
        pArg->pTarget = pTarget;
        pArg->nDistance = nDistance;
    }

    return 0;
}
