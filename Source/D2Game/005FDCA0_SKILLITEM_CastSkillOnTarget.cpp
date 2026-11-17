struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

enum D2C_Y11SkillItemConstants
{
    UNIT_INVALID = 6,
    STATE_UNINTERRUPTABLE = 0x36,
};

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
void __fastcall sub_6FCC60D0(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nUnitType, int nUnitGUID, int a6); // 0x005717C0
int __fastcall SKILLITEM_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int nX, int nY, int* pUnitType, int* pUnitGUID, int* pX, int* pY, int a7); // 0x005FDA80
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

// 0x005FDCA0
int __fastcall SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int a5)
{
    if (!pUnit || !pTargetUnit)
    {
        return 0;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return 0;
    }

    int nTargetUnitType = UNIT_INVALID;
    int nTargetUnitGUID = -1;
    int nTargetX;
    int nTargetY;
    if (!SKILLITEM_HandleItemEffectSkill(pGame, pUnit, nSkillId, nSkillLevel, pTargetUnit, 0, 0, &nTargetUnitType, &nTargetUnitGUID, &nTargetX, &nTargetY, a5))
    {
        return 0;
    }

    int nUnitType;
    int nUnitGUID;
    if (nTargetUnitType == UNIT_INVALID)
    {
        nUnitType = pTargetUnit->dwUnitType;
        nUnitGUID = pTargetUnit->dwUnitId;
    }
    else
    {
        nUnitType = nTargetUnitType;
        nUnitGUID = nTargetUnitGUID;
    }

    sub_6FCC60D0(pUnit, nSkillId, nSkillLevel, nUnitType, nUnitGUID, a5);
    return 1;
}
