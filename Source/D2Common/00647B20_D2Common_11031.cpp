struct D2SkillsTxt
{
    short nSkillId;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[0x20];
    int nSkillLevel;
    int nLevelBonus;
    char unk0x30[0x04];
    int nOwnerGUID;
};

struct D2SkillListStrc
{
    char unk0x00[4];
    D2SkillStrc* pFirstSkill;
};

struct D2UnitStrc
{
    char unk0x00[0xA8];
    D2SkillListStrc* pSkills;
};

D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00647110
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00646D60

// build: context SKILLS_GetSkillInl
static __forceinline D2SkillStrc* SKILLS_GetSkillInl(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    D2SkillStrc* pSkill;
    if (pUnit->pSkills)
    {
        for (pSkill = pUnit->pSkills->pFirstSkill; pSkill; pSkill = pSkill->pNextSkill)
        {
            if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
            {
                goto found;
            }
        }
    }

    pSkill = 0;
found:
    return pSkill;
}

// 0x00647B20
void __stdcall D2Common_11031(D2UnitStrc* pUnit, int nSkillId, int a3)
{
    D2SkillStrc* pSkill = SKILLS_GetSkillInl(pUnit, nSkillId, -1);

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
        pSkill->nLevelBonus += a3;
        if (pSkill->nLevelBonus < 0)
        {
            pSkill->nLevelBonus = 0;
        }
    }
}
