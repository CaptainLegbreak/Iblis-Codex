struct D2UnitStrc;
struct D2SkillStrc;
struct D2SkillsTxt
{
    char unk_00[0x0C];
    unsigned char nCharClass;
    char unk_0D[0x22F];
};
struct D2DataTablesStrc
{
    char unk_00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* gpDataTables_00744304; // 0x00744304
int gbHasClassSkill_007C8CA0;        // 0x007C8CA0
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc*); // 0x00451F60
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc*, int, int); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0

static __forceinline D2SkillsTxt* GetSkillsRecord(D2DataTablesStrc* pTables, int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < pTables->nSkillsTxtRecordCount)
        return &pTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004ED480
int __stdcall sub_004ED480_HasClassSkill(D2UnitStrc* pUnit)
{
    int nSkillId = 0;
    if (gbHasClassSkill_007C8CA0)
        return 1;
    D2DataTablesStrc* pTables = gpDataTables_00744304;
    for (; nSkillId < pTables->nSkillsTxtRecordCount; ++nSkillId)
    {
        D2SkillsTxt* pRecord = GetSkillsRecord(pTables, nSkillId);
        if (pRecord && pRecord->nCharClass == (unsigned char)sub_00451F60_UnitClassId(pUnit))
        {
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 0))
            {
                gbHasClassSkill_007C8CA0 = 1;
                return 1;
            }
            pTables = gpDataTables_00744304;
        }
    }
    return 0;
}
