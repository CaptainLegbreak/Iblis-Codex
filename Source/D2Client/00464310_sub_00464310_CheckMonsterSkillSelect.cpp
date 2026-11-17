struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
};

enum
{
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
};

struct D2SkillsTxt
{
    char unk0x00[0x15];
    unsigned char nSelectProc;
    char unk0x16[0x226];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

typedef int (__fastcall* SKILLSELECTPROC)(D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern SKILLSELECTPROC gpfSkillSelectProcs_00711F34[];                                                      // 0x00711F34
extern int gnSkillSelectProcs_00711F50;                                                                     // 0x00711F50
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __fastcall sub_M210_EmitTest(D2UnitStrc* pPlayer, D2UnitStrc* pUnit);
int __fastcall sub_M210_EmitUse(D2UnitStrc* pUnit);

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord_Inl(int nSkillId)
{
    return nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

// 0x004642B0
static int __stdcall sub_004642B0_CheckSkillSelectProc(D2UnitStrc* pPlayer, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_Inl(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nSelectProc > 0 && pSkillsTxtRecord->nSelectProc < gnSkillSelectProcs_00711F50)
    {
        if (gpfSkillSelectProcs_00711F34[pSkillsTxtRecord->nSelectProc](pPlayer, pTarget))
        {
            return 1;
        }
    }

    return 0;
}

// 0x00464310
static int __stdcall sub_00464310_CheckMonsterSkillSelect(D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    if (sub_004642B0_CheckSkillSelectProc(pPlayer, pUnit, SKILLS_GetSkillIdFromSkill(UNITS_GetLeftSkill(pPlayer), ".\\UNIT\\CUnit.cpp", 1674)))
        return 1;

    return sub_004642B0_CheckSkillSelectProc(pPlayer, pUnit, SKILLS_GetSkillIdFromSkill(UNITS_GetRightSkill(pPlayer), ".\\UNIT\\CUnit.cpp", 1678)) != 0;
}

int __fastcall sub_M210_Emit_00464310(D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    if (!sub_M210_EmitTest(pPlayer, pUnit))
        return 0;
    if (sub_00464310_CheckMonsterSkillSelect(pUnit, pPlayer))
        return sub_M210_EmitUse(pUnit);
    return sub_M210_EmitUse(pPlayer);
}
