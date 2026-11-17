struct D2SkillsTxt
{
    short nSkillId;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[0x2C];
    int nOwnerGUID;
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
};

struct D2UnitStrc
{
    char unk0x00[0xA8];
    D2SkillListStrc* pSkills;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBB0];
    int nPassiveSkills;
    unsigned short* pPassiveSkills;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// 0x006435C0
int __cdecl sub_006435C0_GetPassiveSkillCount()
{
    return sgptDataTables->nPassiveSkills;
}

// 0x006435D0
short __fastcall sub_006435D0_GetPassiveSkillId(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nPassiveSkills)
        return sgptDataTables->pPassiveSkills[nIndex];
    return -1;
}

// 0x00643610
void __stdcall sub_00643610_Nop(int nUnused)
{
}

// 0x006437E0
static __forceinline D2SkillStrc* sub_006437E0_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (!pUnit->pSkills)
        return 0;
    D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill;
    if (!pSkill)
        return 0;
    while (pSkill)
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
            break;
        pSkill = pSkill->pNextSkill;
    }
    return pSkill;
}

D2SkillStrc* __stdcall sub_M113_Emit_006437E0(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    return sub_006437E0_GetSkillById(pUnit, nSkillId, nOwnerGUID);
}
