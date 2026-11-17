struct D2UnitStrc;
struct D2SkillStrc;

int __fastcall sub_004C54F0_CanThrow(D2UnitStrc* pUnit);                                                    // 0x004C54F0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560

// 0x004F4140
int __fastcall sub_004F4140_CanThrowCheck(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return sub_004C54F0_CanThrow(pUnit) != 0;
}

// 0x004F4150
int __fastcall sub_004F4150_ClearSkillParam(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, 0);
    return 1;
}
