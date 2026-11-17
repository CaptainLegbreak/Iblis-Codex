struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
};

struct D2SkillsTxt
{
    char unk0x00[0x2E];
    short wSrvDoFunc;
    char unk0x30[0x23C - 0x30];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[4];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
void __fastcall sub_004C9060_DrawRotated(D2UnitStrc* pUnit, int nArg, int bForward);                        // 0x004C9060
void __fastcall sub_004C9990(D2UnitStrc* pUnit, int nArg, int bForward);                                    // 0x004C9990

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define PLRMODE_SEQUENCE 18
#define MONMODE_SEQUENCE 14

// 0x004D84C0
static __declspec(noinline) int sub_004D84C0_IsInSequenceMode(D2UnitStrc* pUnit)
{
    int nUnitType = UNIT_INVALID;
    if (pUnit)
        nUnitType = pUnit->dwUnitType;
    switch (nUnitType)
    {
    case UNIT_MONSTER:
        return (!pUnit ? 0 : pUnit->dwAnimMode) == MONMODE_SEQUENCE;
    case UNIT_PLAYER:
        return (!pUnit ? 0 : pUnit->dwAnimMode) == PLRMODE_SEQUENCE;
    }
    return 0;
}

void __fastcall sub_004D8520_SkillSeqDo1(D2UnitStrc* pUnit, int nArg)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;

    if (!sub_004D84C0_IsInSequenceMode(pUnit))
        return;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\PlrSkills.cpp", 38);
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxtRecord)
        return;

    switch (pSkillsTxtRecord->wSrvDoFunc)
    {
    case 0x4C:
        sub_004C9060_DrawRotated(pUnit, nArg, 1);
        break;
    case 0x43:
        if (SKILLS_GetFlags(pSkill) & 1)
            sub_004C9990(pUnit, nArg, 1);
        break;
    }
}

void __fastcall sub_004D85B0_SkillSeqDo1Thunk(D2UnitStrc* pUnit, int nArg)
{
    sub_004D8520_SkillSeqDo1(pUnit, nArg);
}

void __fastcall sub_004D85C0_SkillSeqDo0(D2UnitStrc* pUnit, int nArg)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;

    if (!sub_004D84C0_IsInSequenceMode(pUnit))
        return;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\PlrSkills.cpp", 79);
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxtRecord)
        return;

    switch (pSkillsTxtRecord->wSrvDoFunc)
    {
    case 0x4C:
        sub_004C9060_DrawRotated(pUnit, nArg, 0);
        break;
    case 0x43:
        if (SKILLS_GetFlags(pSkill) & 1)
            sub_004C9990(pUnit, nArg, 0);
        break;
    }
}
