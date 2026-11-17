struct D2UnitStrc
{
    unsigned int dwUnitType;
    unsigned int dwClassId;
    char unk0x08[16 - 4 - 4];
    unsigned int dwAnimMode;
};

struct D2SkillStrc
{
    char unk0x00[40];
    int nSkillLevel;
};

struct D2SkillsTxt
{
    char unk0x00[4];
    unsigned char nFlags[8];
    char unk0x0C[572 - 4 - 8];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770
int __fastcall sub_004638A0(int nMonsterId, int nFlag);                                              // 0x004638A0
int __stdcall UNITS_IsSoftMonster(D2UnitStrc* pUnit);                                                       // 0x00621F60

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x006447B0
int __fastcall sub_006447B0(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
    if (!pSkill)
    {
        return 0;
    }

    return pSkill->nSkillLevel;
}

// 0x00645A70
int __stdcall D2Common_11028(int nLevel)
{
    return 20 * (5 * nLevel + 5) / (nLevel + 8);
}

// 0x00645FB0
int __stdcall SKILLS_IsEnhanceable(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 17);
}
