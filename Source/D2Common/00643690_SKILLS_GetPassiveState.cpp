struct D2SkillStrc;
struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[146];
    short nPassiveState;
    char unk0x96[422];
};
struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[32];
    int nSkillLevel;
    char unk0x2C[8];
    int nOwnerGUID;
};
struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
    D2SkillStrc* pLeftSkill;
    D2SkillStrc* pRightSkill;
    D2SkillStrc* pUsedSkill;
};
struct D2UnitStrc
{
    char unk0x00[8];
    void* pMemoryPool;
    char unk0x0C[156];
    D2SkillListStrc* pSkills;
};
struct D2DataTablesStrc
{
    char unk0x00[2968];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00643690
int __stdcall SKILLS_GetPassiveState(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nPassiveState <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->nPassiveState;
}
