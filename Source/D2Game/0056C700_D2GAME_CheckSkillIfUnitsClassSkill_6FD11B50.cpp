struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2SkillsTxt
{
    char unk_00[0x0C];
    signed char nCharClass;
    char unk_0D[0x23C - 0x0D];
};

struct D2DataTablesStrc
{
    char unk_000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unk_B9C;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static __forceinline int GetClassId(D2UnitStrc* pUnit)
{
    int nClassId = -1;
    if (pUnit)
    {
        nClassId = pUnit->dwClassId;
    }
    return nClassId;
}

// 0x0056C700
int __fastcall D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50(D2UnitStrc* pUnit, int nSkillId)
{
    if (pUnit && pUnit->dwUnitType == 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
            return pSkillsTxtRecord->nCharClass == GetClassId(pUnit);
    }
    return 0;
}
