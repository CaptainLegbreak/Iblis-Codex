struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[148 - 2];
    short nPassiveState;
    char unk0x96[572 - 148 - 2];
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

struct D2DataTablesStrc
{
    char unk0x00[2968];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[2992 - 2968 - 12];
    int nPassiveSkills;
    unsigned short* pPassiveSkills;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId);                                        // 0x00646D60

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline short DATATBLS_GetPassiveSkillId(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nPassiveSkills)
    {
        return sgptDataTables->pPassiveSkills[nIndex];
    }

    return -1;
}

// 0x00643810
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

// 0x00646F20
void __stdcall SKILLS_RefreshPassiveSkills(D2UnitStrc* pUnit)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    D2SkillStrc* pSkill = 0;
    int nSkillId = 0;
    short nPassiveState = 0;
    int nPassiveSkills = sgptDataTables->nPassiveSkills;

    for (int i = 0; i < nPassiveSkills; ++i)
    {
        nSkillId = DATATBLS_GetPassiveSkillId(i);

        pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
        {
            nPassiveState = pSkillsTxtRecord->nPassiveState;
            if (nPassiveState > 0)
            {
                pSkill = SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId);

                if (pSkill && STATES_CheckState(pUnit, nPassiveState))
                {
                    SKILLS_RefreshSkill(pUnit, nSkillId);
                }
            }
        }
    }
}
