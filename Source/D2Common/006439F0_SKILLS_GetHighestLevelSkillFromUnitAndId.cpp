struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[572 - 2];
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[40 - 4 - 4];
    int nSkillLevel;
    char unk0x2C[52 - 40 - 4];
    int nOwnerGUID;
    char unk0x38[60 - 52 - 4];
    int bExcludeFromHighestLevelLookup;
};

struct D2SkillListStrc
{
    char unk0x00[4];
    D2SkillStrc* pFirstSkill;
};

struct D2UnitStrc
{
    char unk0x00[168];
    D2SkillListStrc* pSkills;
};

struct D2SkillCalcStrc
{
    D2UnitStrc* pUnit;
    int nSkillId;
    int nSkillLevel;
};

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, int nParamId, int nSkillId, int nSkillLevel);  // 0x00646460

// @ref 0x00643810
// build: symbol ?SKILLS_GetHighestLevelSkillFromSkillId@@YAPAUD2SkillStrc@@PAUD2UnitStrc@@H@Z 0x00643810
static D2SkillStrc* SKILLS_GetHighestLevelSkillFromSkillId(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit->pSkills)
    {
        return 0;
    }

    D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill;
    D2SkillStrc* pHighestLevelSkill = 0;
    for (; pSkill; pSkill = pSkill->pNextSkill)
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && !pSkill->bExcludeFromHighestLevelLookup && (!pHighestLevelSkill
            || pSkill->nOwnerGUID == -1 || pHighestLevelSkill->nOwnerGUID != -1 && pSkill->nSkillLevel > pHighestLevelSkill->nSkillLevel))
        {
            pHighestLevelSkill = pSkill;
        }
    }

    return pHighestLevelSkill;
}

// 0x006439F0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId)
{
    return SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId);
}

// 0x00646C00
int __fastcall sub_6FDAF6C0(int nSkillId, int nParamId, int nUnused, void* pUserData)
{
    D2SkillCalcStrc* pSkillCalc = (D2SkillCalcStrc*)pUserData;
    if (!pSkillCalc)
    {
        return 0;
    }

    int nSkillLevel = 0;
    if (pSkillCalc->pUnit)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromSkillId(pSkillCalc->pUnit, nSkillId);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pSkillCalc->pUnit, pSkill, 1);
        }
    }

    return SKILLS_GetSpecialParamValue(pSkillCalc->pUnit, nParamId, nSkillId, nSkillLevel);
}
