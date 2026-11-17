struct D2SkillsTxt
{
    char unk0x000[0x12C];
    short wUnk0x12C;
    char unk0x12E[0x23C - 0x12E];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// 0x0045C4B0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004AA8B0
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        const int nValue = sgptDataTables->pSkillsTxt[nSkillId].wUnk0x12C;
        if (nValue > 0)
            return nValue;
    }
    return 20;
}
