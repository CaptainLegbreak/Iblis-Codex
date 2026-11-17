struct D2GameStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
};
typedef int (__fastcall* D2ModeCheckFn)(D2GameStrc*, D2UnitStrc*, int, int);
extern D2ModeCheckFn gpModeChecks_00732C10[]; // 0x00732C10
void __fastcall sub_6FC81250(D2GameStrc*, D2UnitStrc*, int, int); // 0x00581020

// 0x005811D0
void __fastcall sub_005811D0_CheckPlayerMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nMode = !pUnit ? 0 : pUnit->dwAnimMode;
    if (gpModeChecks_00732C10[!pUnit ? 0 : pUnit->dwAnimMode])
    {
        if (gpModeChecks_00732C10[nMode](pGame, pUnit, nSkillId, nSkillLevel) == 2)
        {
            sub_6FC81250(pGame, pUnit, nSkillId, nSkillLevel);
        }
    }
}
