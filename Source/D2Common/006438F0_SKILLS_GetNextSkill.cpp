struct D2SkillsTxt
{
    short nSkillId;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[0x2C];
    int nOwnerGUID;
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
};

struct D2UnitStrc
{
    char unk0x00[0xA8];
    D2SkillListStrc* pSkills;
};

// 0x006438F0
D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill)
{
    if (!pSkill)
        return 0;
    return pSkill->pNextSkill;
}

// 0x00643910
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList)
{
    if (!pSkillList)
        return 0;
    return pSkillList->pFirstSkill;
}

// 0x006439B0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (!pUnit->pSkills)
        return 0;
    D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill;
    if (!pSkill)
        return 0;
    while (pSkill)
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
            break;
        pSkill = pSkill->pNextSkill;
    }
    return pSkill;
}
