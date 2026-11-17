struct D2GameStrc;
struct D2SkillStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; };
struct D2SkillsTxt { char unk00[0x138]; unsigned int dwCalc[4]; char unk148[0xF4]; };
struct D2DataTablesStrc { char unk00[0xB98]; D2SkillsTxt* pSkillsTxt; void* pLinker; int nSkillsTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __fastcall sub_6FD15460(D2UnitStrc* pUnit); // 0x0056E510
int __fastcall sub_6FD10790(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter); // 0x0056BC80
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nId];
    return 0;
}
// 0x005DAE30
int __fastcall sub_005DAE30_InitializeMeleeTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return 0;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;
    int nRange = sub_6FD15460(pUnit);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    int nTargets = 0;
    if (!pTarget)
    {
        pTarget = sub_6FD107F0(pGame, pUnit, 0, 0, nRange, 0x20003, -1, &nTargets);
        if (!pTarget)
        {
            SKILLS_SetParam1(pSkill, 0);
            return 1;
        }
    }
    else
        nTargets = sub_6FD10790(pGame, pUnit, 0, 0, nRange, 0x20003);
    int nMaxTargets = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    if (nTargets >= nMaxTargets)
        nTargets = nMaxTargets;
    SKILLS_SetParam1(pSkill, nTargets);
    int nTargetType = pTarget ? pTarget->dwUnitType : 6;
    SKILLS_SetParam2(pSkill, nTargetType);
    nRange = pTarget ? pTarget->dwUnitId : -1;
    SKILLS_SetParam3(pSkill, nRange);
    return 1;
}
