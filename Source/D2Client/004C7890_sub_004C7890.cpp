struct D2UnitStrc;
struct D2SkillStrc;
struct D2StatListStrc;

struct D2SkillsTxt
{
    char unk_00[0x2E];
    short nClientFunction;
    char unk_30[0x20C];
};

struct D2DataTablesStrc
{
    char unk_000[0xB98];
    D2SkillsTxt* pSkills;
    int unk_B9C;
    int nSkillCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
void __fastcall sub_004CA000(D2UnitStrc* pUnit, int nSkillId);                                              // 0x004CA000
void __fastcall sub_004C8B80_ResetLeapCollision(D2UnitStrc* pUnit);                                         // 0x004C8B80
void __fastcall sub_004C9420(D2UnitStrc* pUnit, int nSkillId);                                              // 0x004C9420

static __forceinline D2SkillsTxt* GetSkillRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillCount)
        return &sgptDataTables->pSkills[nSkillId];
    return 0;
}

// 0x004C7890
void __fastcall sub_004C7890(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;
    if (STATES_CheckState(pUnit, 18))
        return;
    if (SKILLS_GetFlags(pSkill) & 2)
        return;
    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 2365);
    D2SkillsTxt* pSkillsTxt = GetSkillRecord(nSkillId);
    if (!pSkillsTxt)
        return;
    switch (pSkillsTxt->nClientFunction)
    {
    case 67:
        sub_004CA000(pUnit, nSkillId);
        break;
    case 77:
    case 78:
        sub_004C8B80_ResetLeapCollision(pUnit);
        break;
    case 76:
        sub_004C9420(pUnit, nSkillId);
        break;
    }
}
