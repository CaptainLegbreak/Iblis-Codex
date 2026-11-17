struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC0];
    unsigned int dwFlags;
};

struct D2AiCallback11ArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    D2UnitStrc* unk0x08;
};

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                     // 0x00554200
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380
int __fastcall sub_6FCF14D0(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                        // 0x005DC640
int __fastcall sub_005DC920_GetThreat(D2UnitStrc* pUnit);                                                   // 0x005DC920

static __forceinline int UNITS_CanBeAttackedInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 2) & 1;
    return bResult;
}

// 0x005DCCC0
D2UnitStrc* __fastcall sub_6FCF1BD0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2AiCallback11ArgStrc* pArg = (D2AiCallback11ArgStrc*)pCallbackArg;

    if (pTarget == pArg->unk0x08 || !pTarget || pTarget->dwUnitType < 0 || pTarget->dwUnitType > 1 || SUNIT_IsDead(pTarget) || !UNITS_CanBeAttackedInline(pTarget) || !sub_00554200(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > 48)
    {
        return 0;
    }

    if (sub_005DC920_GetThreat(pTarget) > 1 && nDistance < pArg->nDistance && sub_6FCF14D0(pUnit, pTarget))
    {
        pArg->pTarget = pTarget;
        pArg->nDistance = nDistance;
    }

    return 0;
}
