#include "D2Game.h"
#include "D2Structs.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2SkillsTxt;


struct D2SkillsTxt
{
    char pad00[0x64];
    unsigned int dwAuraRangeCalc;
    char pad68[0x138 - 0x68];
    unsigned int dwCalc[4];
    char pad148[0x23C - 0x148];
};

struct D2DataTablesStrc
{
    char pad00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __fastcall SKILLS_CanUseWeaponAmmo(D2UnitStrc* pUnit); // 0x0056C4E0
void __fastcall PLRMODE_HandleDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580310
void __fastcall PLRMODE_BreakDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580380
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall sub_6FD10790(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter); // 0x0056BC80
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int nPrevious, int* pCount); // 0x0056BD10
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
int __fastcall SKILLS_ConsumeWeaponOrAmmoQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056C3F0

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

static __forceinline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

// 0x005DACD0
int __fastcall SKILLS_SrvSt08_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (!SKILLS_CanUseWeaponAmmo(pUnit))
    {
        PLRMODE_HandleDepletedWeapons(pGame, pUnit);
        PLRMODE_BreakDepletedWeapons(pGame, pUnit);
        return 0;
    }

    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);

    int nTargetCount = 0;
    if (!pTarget)
    {
        pTarget = sub_6FD107F0(pGame, pUnit, 0, 0, nAuraRange, 3, -1, &nTargetCount);
    }
    else
    {
        nTargetCount = sub_6FD10790(pGame, pUnit, 0, 0, nAuraRange, 3);
    }

    int nDesiredShots = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
    int nShotsRemaining = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nDesiredShots > nShotsRemaining)
    {
        nDesiredShots = nShotsRemaining;
    }

    nTargetCount = D2_MIN(D2_MAX(nTargetCount, nDesiredShots), nShotsRemaining);
    SKILLS_SetParam1(pSkill, nTargetCount);

    if (pTarget)
    {
        SKILLS_SetParam2(pSkill, sub_0044BE50(pTarget));
        SKILLS_SetParam3(pSkill, UNITS_GetUnitId(pTarget));
    }
    else
    {
        SKILLS_SetParam2(pSkill, 1);
        SKILLS_SetParam3(pSkill, -1);
    }

    SKILLS_ConsumeWeaponOrAmmoQuantity(pGame, pUnit);
    return 1;
}

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
