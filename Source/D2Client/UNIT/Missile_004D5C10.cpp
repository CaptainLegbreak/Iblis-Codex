#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
struct D2UnitStrc;






extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C390
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall MISSILE_GetRemainingFrames(D2UnitStrc* pMissile);                                             // 0x0064A3B0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nSeed);                                             // 0x00650E40
unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed);                                                 // 0x00650E50

// build: context SKILLS_GetMissilesTxtRecord
static __forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// build: context SKILLS_GetSkillsTxtRecord
static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004D5C10
void __fastcall sub_004D5C10_CltDo_Volcano(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nLevel = MISSILE_GetLevel(pMissile);
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);

    int nAuraRange = pMissilesTxtRecord->dwCltParam[1];
    if (nAuraRange <= 0)
    {
        const int nCalc = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        nAuraRange = (nCalc >= 1) ? nCalc : 1;
    }

    int nFrames = pMissilesTxtRecord->dwCltParam[0];
    if (nFrames <= 0)
    {
        nFrames = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nFrames < 1)
        {
            nFrames = 1;
        }
    }

    const int nRemainingFrames = MISSILE_GetRemainingFrames(pMissile);
    if (nRemainingFrames > pMissilesTxtRecord->dwCltParam[2] && nRemainingFrames < pMissilesTxtRecord->dwCltParam[3] && !(nRemainingFrames % nFrames))
    {
        D2SeedStrc* pSeed = &pMissile->pSeed;
        SEED_InitLowSeed(pSeed, MISSILE_GetTargetX(pMissile));
        int nX = SEED_RollLimitedRandomNumber(pSeed, 2 * nAuraRange + 1) - nAuraRange;
        nX += CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile) + SEED_RollLimitedRandomNumber(pSeed, 2 * nAuraRange + 1) - nAuraRange;
        MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(pSeed));
        sub_004CDC30(pMissile, pMissilesTxtRecord->wCltSubMissile[0], 0, 0, nX, nY, MISSILE_GetSkill(pMissile), nLevel, pMissilesTxtRecord->dwCltParam[4]);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
