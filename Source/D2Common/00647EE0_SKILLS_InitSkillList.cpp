struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[570];
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[52 - 4 - 4];
    int nOwnerGUID;
};

struct D2SkillListStrc
{
    char unk0x00[4];
    D2SkillStrc* pFirstSkill;
};

struct D2UnitStrc
{
    char unk0x00[4];
    int dwClassId;
    char unk0x08[168 - 4 - 4];
    D2SkillListStrc* pSkills;
};

struct D2CharStatsTxt
{
    char unk0x00[174];
    short nBaseSkill[10];
    char unk0xC2[196 - 174 - 2 * 10];
};

struct D2DataTablesStrc
{
    char unk0x00[2968];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[3012 - 2968 - 12];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId);                                    // 0x00647110
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50

inline D2SkillStrc* __fastcall SKILLS_GetSkillInl(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (pUnit->pSkills)
    {
        for (D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill; pSkill; pSkill = pSkill->pNextSkill)
        {
            if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
            {
                return pSkill;
            }
        }
    }

    return 0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00647EE0
void __stdcall SKILLS_InitSkillList(D2UnitStrc* pUnit)
{
    D2CharStatsTxt* pCharStatsTxtRecord = 0;
    int nClass = 0;

    if (SKILLS_GetSkillInl(pUnit, 0, -1) == 0)
    {
        nClass = pUnit->dwClassId;
        if (nClass < 0 || nClass >= sgptDataTables->nCharStatsTxtRecordCount)
        {
            return;
        }

        pCharStatsTxtRecord = &sgptDataTables->pCharStatsTxt[nClass];
        if (!pCharStatsTxtRecord)
        {
            return;
        }

        SKILLS_AddSkill(pUnit, 0);

        for (int i = 0; i < 10; ++i)
        {
            short nSkillId = pCharStatsTxtRecord->nBaseSkill[i];
            if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
            {
                SKILLS_AddSkill(pUnit, nSkillId);
            }
        }
    }

    if (UNITS_GetLeftSkill(pUnit) == 0)
    {
        SKILLS_SetLeftActiveSkill(pUnit, 0, -1);
    }

    if (UNITS_GetRightSkill(pUnit) == 0)
    {
        SKILLS_SetRightActiveSkill(pUnit, 0, -1);
    }
}
