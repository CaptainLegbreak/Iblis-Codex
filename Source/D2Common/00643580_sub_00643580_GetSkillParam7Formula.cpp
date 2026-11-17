struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x15E];
    int f_160;
    int f_164;
    char unk0x168[0xD4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[4];
    int nSkillsTxtRecordCount;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[0x20];
    int nSkillLevel;
    int nLevelBonus;
    int nQuantity;
    int nOwnerGUID;
    int nCharges;
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
    D2SkillStrc* pLeftSkill;
    D2SkillStrc* pRightSkill;
    D2SkillStrc* pUsedSkill;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00643580
int __fastcall sub_00643580_GetSkillParam7Formula(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->f_160 + (nSkillLevel - 1) * pSkillsTxtRecord->f_164;
}

// 0x00643930
D2SkillStrc* __fastcall SKILLS_GetLeftSkillFromSkillList(D2SkillListStrc* pSkillList)
{
    D2_ASSERT(pSkillList, 0x3E9);
    return pSkillList->pLeftSkill;
}

// 0x00643960
D2SkillStrc* __fastcall SKILLS_GetRightSkillFromSkillList(D2SkillListStrc* pSkillList)
{
    D2_ASSERT(pSkillList, 0x40E);
    return pSkillList->pRightSkill;
}

// 0x00643990
void __fastcall SKILLS_SetUsedSkillInSkillList(D2SkillListStrc* pSkillList, D2SkillStrc* pUsedSkill)
{
    if (pSkillList)
    {
        pSkillList->pUsedSkill = pUsedSkill;
    }
}

// 0x006439A0
D2SkillStrc* __fastcall SKILLS_GetUsedSkillFromSkillList(D2SkillListStrc* pSkillList)
{
    if (!pSkillList)
    {
        return 0;
    }

    return pSkillList->pUsedSkill;
}

// 0x00643B00
int __stdcall SKILLS_GetSkillInfo(D2SkillStrc* pSkill, int* pOwnerGUID, int* pSkillId, int* pSkillLevel, int* pCharges)
{
    D2_ASSERT(pSkill, 0x641);

    if (pSkill->nOwnerGUID == -1)
    {
        return 0;
    }

    if (pOwnerGUID)
    {
        *pOwnerGUID = pSkill->nOwnerGUID;
    }
    if (pSkillId)
    {
        *pSkillId = pSkill->pSkillsTxt->nSkillId;
    }
    if (pSkillLevel)
    {
        *pSkillLevel = pSkill->nSkillLevel;
    }
    if (pCharges)
    {
        *pCharges = pSkill->nCharges;
    }

    return 1;
}
