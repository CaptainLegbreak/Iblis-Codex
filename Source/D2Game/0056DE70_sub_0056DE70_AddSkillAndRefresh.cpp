#define UNIT_PLAYER 0

struct D2GameStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
};

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
void __fastcall sub_6FC7DF40(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                       // 0x00575900
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
void __stdcall SKILLS_RefreshPassiveSkills(D2UnitStrc* pUnit);                                              // 0x00646F20
void __stdcall SKILLS_RemoveSkill(D2UnitStrc* pUnit, int nSkillId, const char* szFile, int nLine);          // 0x006470F0
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId);                                    // 0x00647110

// 0x0056DE70
D2SkillStrc* __fastcall sub_0056DE70_AddSkillAndRefresh(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_AddSkill(pUnit, nSkillId);
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        sub_6FC7DF40(SUNIT_GetGameFromUnit(pUnit), pUnit);
    return pSkill;
}

// 0x0056DF10
void __fastcall sub_0056DF10_RemoveSkillAndRefresh(D2UnitStrc* pUnit, int nSkillId)
{
    SKILLS_RemoveSkill(pUnit, nSkillId, ".\\SKILLS\\Skills.cpp", 4405);
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        sub_6FC7DF40(SUNIT_GetGameFromUnit(pUnit), pUnit);
}

// 0x0056DF50
int __fastcall sub_0056DF50_IsActiveSkill(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 4416) == nSkillId)
        return 1;
    pSkill = UNITS_GetLeftSkill(pUnit);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 4419) == nSkillId)
        return 1;
    return 0;
}
