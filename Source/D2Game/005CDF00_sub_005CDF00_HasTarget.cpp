struct D2GameStrc;
struct D2UnitStrc;

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

// 0x005CDF00
int __fastcall sub_005CDF00_HasTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return SUNIT_GetTargetUnit(pGame, pUnit) != 0;
}
