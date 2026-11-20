#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#ifdef MOVED_TEST
#define SKILL_FLAG 0x20
#else
#define SKILL_FLAG 0x40
#endif
struct D2MissilesTxt;


extern D2DataTablesStrc* sgptDataTables;  // 0x00744304
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId);                               // 0x004F21B0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2UnitStrc* __fastcall sub_004C5420_RequestAtTarget(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4); // 0x004C5420
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}
// 0x004E3720
int __fastcall sub_004E3720(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
        return 0;
    if (pUnit)
        pUnit->dwFlags |= SKILL_FLAG;
    const int nTarget = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    D2UnitStrc* pMissile = sub_004C5420_RequestAtTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    if (!pMissile)
        return 0;
    MISSILE_SetTargetX(pMissile, nTarget);
    return 1;
}
