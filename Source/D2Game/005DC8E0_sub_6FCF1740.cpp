enum D2C_P11AiUtilConstants
{
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
    MONMODE_DEATH = 0,
};

struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
};

struct UnkAiStrc5
{
    unsigned int nMaxDistance;
};

int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380

// 0x005DC8E0
D2UnitStrc* __fastcall sub_6FCF1740(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    UnkAiStrc5* pArg = (UnkAiStrc5*)pCallbackArg;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pTarget->dwAnimMode != MONMODE_DEATH)
    {
        return 0;
    }

    return (unsigned int)AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit) < pArg->nMaxDistance ? pTarget : 0;
}
