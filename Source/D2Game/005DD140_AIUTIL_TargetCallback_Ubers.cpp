struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2UbersAiCallbackArgStrc
{
    int nUberMephisto;
    int nUberDiablo;
    int nUberBaal;
    int nDistance;
    int nOtherMonsters;
    int nDiabloSpawner;
    int nBaalMinions;
    int nDiabloMinions;
};

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DC380

// 0x005DD140
D2UnitStrc* __fastcall AIUTIL_TargetCallback_Ubers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2UbersAiCallbackArgStrc* pArg = (D2UbersAiCallbackArgStrc*)pCallbackArg;

    if (pTarget
        && (!pTarget ? 6 : pTarget->dwUnitType) == 1
        && !SUNIT_IsDead(pTarget))
    {
        const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
        if (nDistance > pArg->nDistance)
        {
            return 0;
        }

        const int nClassId = pTarget->dwClassId;
        if (nClassId == 704)
        {
            pArg->nUberMephisto++;
            return 0;
        }
        if (nClassId == 705)
        {
            pArg->nUberDiablo++;
            return 0;
        }
        if (nClassId == 709)
        {
            pArg->nUberBaal++;
            return 0;
        }
        if (nClassId == 711)
        {
            pArg->nDiabloSpawner++;
            return 0;
        }
        if (nClassId == 712)
        {
            pArg->nDiabloMinions++;
            return 0;
        }
        if (nClassId == 732 || nClassId == 731 || nClassId == 733)
        {
            pArg->nBaalMinions++;
            return 0;
        }
        pArg->nOtherMonsters++;
    }

    return 0;
}
