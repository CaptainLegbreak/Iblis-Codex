struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
D2UnitStrc* __fastcall sub_6FD15210(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x0056E390
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10

// 0x005FD9C0
int __fastcall sub_005FD9C0_SelectSkillTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int* pUnitType, int* pUnitGUID)
{
    D2UnitStrc* pCurrentTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    D2UnitStrc* pTarget = sub_6FD15210(pUnit, pCurrentTarget, nSkillId, nSkillLevel);
    if (!pTarget)
    {
        return 0;
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    if (pUnitType)
    {
        *pUnitType = pTarget->dwUnitType;
        *pUnitGUID = pTarget->dwUnitId;
    }
    return 1;
}
