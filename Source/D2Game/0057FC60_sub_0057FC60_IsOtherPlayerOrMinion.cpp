#define UNIT_PLAYER 0
#define UNIT_MONSTER 1

struct D2UnitStrc
{
    int dwUnitType;
};

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0

// 0x0057FC60
static __forceinline int sub_0057FC60_IsOtherPlayerOrMinion(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pUnit || !pTarget || pUnit->dwUnitType != UNIT_PLAYER || pUnit == pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType == UNIT_PLAYER)
    {
        return 1;
    }

    if (pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pTarget);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER && pOwner != pUnit)
        {
            return 1;
        }
    }

    return 0;
}

int __fastcall sub_M120_Emit_0057FC60(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    return sub_0057FC60_IsOtherPlayerOrMinion(pUnit, pTarget);
}
