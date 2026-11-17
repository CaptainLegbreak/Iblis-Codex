struct D2SkillsTxt
{
    unsigned char beforeDescriptionId[0x194];
    short descriptionId;
    unsigned char unusedTail[0x23C - 0x194 - sizeof(short)];
};
struct D2SkillDescTxt
{
    unsigned char beforeStrings[8];
    unsigned short strings[(0x120 - 8) / sizeof(unsigned short)];
};
struct D2DataTablesStrc
{
    unsigned char beforeDescriptionPointer[0xB8C];
    D2SkillDescTxt* pSkillDescTxt;
    unsigned char beforeDescriptionCount[4];
    int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt;
    unsigned char beforeSkillCount[4];
    int nSkillsTxtRecordCount;
};
typedef char B07RealSkillsSize[(sizeof(D2SkillsTxt) == 0x23C) ? 1 : -1];
typedef char B07RealDescriptionSize[(sizeof(D2SkillDescTxt) == 0x120) ? 1 : -1];
typedef char B07RealTablesSize[(sizeof(D2DataTablesStrc) == 0xBA4) ? 1 : -1];
extern D2DataTablesStrc* sgptDataTables; // 0x00744304

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline D2SkillDescTxt* SKILLTREE_GetSkillDescTxtRecord(int nSkillDesc)
{
    if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
    {
        return &sgptDataTables->pSkillDescTxt[nSkillDesc];
    }
    return 0;
}

// 0x004E6CE0
unsigned short __fastcall sub_004E6CE0_GetStringId(int skillId, int stringIndex)
{
    D2SkillsTxt* skill = SKILLS_GetSkillsTxtRecord(skillId);
    D2SkillDescTxt* description = 0;
    if (skill)
    {
        description = SKILLTREE_GetSkillDescTxtRecord(skill->descriptionId);
    }
    if (!description)
    {
        return static_cast<unsigned short>(0x1506);
    }
    return description->strings[stringIndex];
}
