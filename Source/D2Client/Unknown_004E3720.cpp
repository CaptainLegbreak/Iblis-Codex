#include "D2Structs.h"
#include "D2DataTbls.h"
#ifdef MOVED_TEST
#define SKILL_FLAG 0x20
#else
#define SKILL_FLAG 0x40
#endif
struct D2MissilesTxt;

struct D2SkillsTxt
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    char unk0x000[0x0C];
    char nCharClass;
    char unk0x00D[0x09];
    unsigned char nSeqInput;
    char unk0x017[0x4D];
    int dwAuraRangeCalc;
    char unk0x068[0x82];
    short wCltMissileA;
    char unk0x0EC[0x22];
    short wPrgSound;
    short wCltOverlayA;
    char unk0x112[0x02];
    int dwCltCalc[3];
    char unk0x120[0x18];
    int dwCalc[4];
    char unk0x148[0xF4];
};

extern D2DataTablesStrc* sgptDataTables;  // 0x00744304
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId);                               // 0x004F21B0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2UnitStrc* __fastcall sub_004C5420_CreateFirstMissile(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4); // 0x004C5420
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
    D2UnitStrc* pMissile = sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
    if (!pMissile)
        return 0;
    MISSILE_SetTargetX(pMissile, nTarget);
    return 1;
}
