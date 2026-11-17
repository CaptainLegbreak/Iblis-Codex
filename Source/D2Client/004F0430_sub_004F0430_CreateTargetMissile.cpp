struct D2UnitStrc;
struct D2SkillsTxt
{
    char unk_000[0xEC];
    short nClientMissile;
    char unk_0EE[0x23C - 0xEE];
};
struct D2DataTablesStrc
{
    char unk_000[0xB6C];
    int nMissilesTxtRecordCount;
    char unk_B70[0x28];
    D2SkillsTxt* pSkillsTxt;
    int unk_B9C;
    int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall sub_004C5470_CreateMissileToTarget(D2UnitStrc* pUnit, int nMissile, int nSkillId, int nSkillLevel); // 0x004C5470
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000
void __fastcall sub_004706E0_GetUnitCelOffsets(D2UnitStrc* pUnit, int nComponent, int* pOffsetX, int* pOffsetY); // 0x004706E0
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

static __forceinline D2SkillsTxt* GetSkill(int nSkill)
{
    if (nSkill < 0 || nSkill >= sgptDataTables->nSkillsTxtRecordCount)
        return 0;
    return &sgptDataTables->pSkillsTxt[nSkill];
}

// 0x004F0430
int __fastcall sub_004F0430_CreateTargetMissile(D2UnitStrc* pUnit, int nSkill, int nUnused)
{
    D2SkillsTxt* pSkill = GetSkill(nSkill);
    if (!pSkill)
        return 0;
    int nMissile = pSkill->nClientMissile;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
        return 1;
    {
        D2UnitStrc* pMissile = sub_004C5470_CreateMissileToTarget(pUnit, nMissile, nSkill, 1);
        if (!pMissile)
            return 0;
        D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
        if (pTarget)
        {
            sub_004DA000_ResetGfxMotion(pMissile);
            int nX, nY;
            sub_004706E0_GetUnitCelOffsets(pTarget, 14, &nX, &nY);
            sub_004DA1D0_SetMotionVectorA(pMissile, nX, 0, -nY);
        }
    }
    return 1;
}
