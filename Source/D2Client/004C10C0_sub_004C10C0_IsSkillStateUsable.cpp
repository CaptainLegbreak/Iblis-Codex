struct D2UnitStrc;
struct D2SkillStrc;

extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit, D2SkillStrc* skill);                   // 0x004D9FC0

// 0x004C10C0
int __fastcall sub_004C10C0_IsSkillStateUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    switch (sub_004D9FC0(pUnit, pSkill))
    {
    case 2:
    case 7:
        return 0;
    }
    return 1;
}
