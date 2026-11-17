struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[0x17E - 0x02];
    short nReqSkill[3];
    char unk0x184[0x23C - 0x184];
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[0x28 - 0x08];
    int nSkillLevel;
};

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[4];
    int nSkillsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* pUnit);                                              // 0x00620150
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0
int __stdcall SKILLS_GetRequiredLevelBasedOnCurrent(D2UnitStrc* pUnit, int nSkillId);                       // 0x00644750
int __fastcall sub_006447B0(D2UnitStrc* pUnit, int nSkillId);                          // 0x006447B0

#define STAT_LEVEL 12

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord_ForceInl(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x006446C0
static int sub_006446C0_UnitHasSkillsTxtRecord(D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord)
{
    D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit);
    D2_ASSERT(pSkill, 2736);

    while (pSkill)
    {
        if (pSkill->pSkillsTxt == pSkillsTxtRecord)
        {
            return 1;
        }

        pSkill = pSkill->pNextSkill;
    }

    return 0;
}

// 0x006447D0
int __stdcall SKILLS_CheckRequiredSkills(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (SKILLS_GetRequiredLevelBasedOnCurrent(pUnit, nSkillId) > nLevel)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nReqSkill[0] < 0)
    {
        if (SKILLS_GetRequiredLevelBasedOnCurrent(pUnit, nSkillId) > nLevel)
        {
            return 0;
        }
    }
    else
    {
        D2SkillsTxt* pReqSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_ForceInl(pSkillsTxtRecord->nReqSkill[0]);
        if (!pReqSkillsTxtRecord)
        {
            return 0;
        }

        if (!sub_006446C0_UnitHasSkillsTxtRecord(pUnit, pReqSkillsTxtRecord))
        {
            return 0;
        }

        if (!pUnit)
        {
            return 0;
        }

        D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, pSkillsTxtRecord->nReqSkill[0], -1);
        if (!pSkill || pSkill->nSkillLevel <= 0)
        {
            return 0;
        }
    }

    if (pSkillsTxtRecord->nReqSkill[1] >= 0)
    {
        D2SkillsTxt* pReqSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(pSkillsTxtRecord->nReqSkill[1]);
        if (!pReqSkillsTxtRecord)
        {
            return 0;
        }

        if (!sub_006446C0_UnitHasSkillsTxtRecord(pUnit, pReqSkillsTxtRecord))
        {
            return 0;
        }

        if (sub_006447B0(pUnit, pSkillsTxtRecord->nReqSkill[1]) <= 0)
        {
            return 0;
        }
    }

    if (pSkillsTxtRecord->nReqSkill[2] >= 0)
    {
        D2SkillsTxt* pReqSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(pSkillsTxtRecord->nReqSkill[2]);
        if (!pReqSkillsTxtRecord)
        {
            return 0;
        }

        if (!sub_006446C0_UnitHasSkillsTxtRecord(pUnit, pReqSkillsTxtRecord))
        {
            return 0;
        }

        if (sub_006447B0(pUnit, pSkillsTxtRecord->nReqSkill[2]) <= 0)
        {
            return 0;
        }
    }

    return 1;
}
