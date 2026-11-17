struct D2UnitStrc;
struct D2SkillStrc
{
    char unk0x00[40];
    int nSkillLevel;
    int nLevelBonus;
    char unk0x30[52 - 40 - 8];
    int nOwnerGUID;
};

D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId);                                    // 0x00647110
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId);                                        // 0x00646D60

// 0x00647AA0
void __stdcall D2Common_11030(D2UnitStrc* pUnit, int nSkillId, int a3)
{
    D2SkillStrc* pSkill = 0;

    if (pUnit)
    {
        pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
        if (!pSkill)
        {
            if (a3 <= 0)
            {
                return;
            }

            pSkill = SKILLS_AddSkill(pUnit, nSkillId);
            if (!pSkill)
            {
                return;
            }

            D2SkillStrc* pAssigned = SKILLS_GetSkill(pUnit, nSkillId, -1);
            if (!pAssigned)
            {
                SKILLS_AddSkill(pUnit, nSkillId);
                pAssigned = SKILLS_GetSkill(pUnit, nSkillId, -1);
            }

            if (pAssigned)
            {
                pAssigned->nSkillLevel = 0;
                SKILLS_RefreshSkill(pUnit, nSkillId);
            }
        }

        if (pSkill->nOwnerGUID == -1)
        {
            pSkill->nLevelBonus = a3;
            SKILLS_RefreshSkill(pUnit, nSkillId);
        }
    }
}
