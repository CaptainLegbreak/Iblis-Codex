struct D2SkillsTxt
{
    char unk0x00[12];
    signed char nCharClass;
    char unk0x0D[392 - 12 - 1];
    unsigned char nManaShift;
    char unk0x189;
    short wMana;
    short wLevelMana;
    char unk0x18E[572 - 392 - 6];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define SKILLS_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// @ref 0x00645040
int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (pSkillsTxtRecord && pSkillsTxtRecord->nCharClass >= 0)
    {
        return pSkillsTxtRecord->nCharClass;
    }

    return 7;
}

// 0x00644B10
int __stdcall SKILLS_GetManaCosts(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return (pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
}

// 0x00645080
int __stdcall SKILLS_IsPlayerClassSkill(int nSkillId, int* pPlayerClass)
{
    SKILLS_ASSERT(pPlayerClass, 3449);

    *pPlayerClass = SKILLS_GetClassIdFromSkillId(nSkillId);
    return *pPlayerClass != 7;
}
