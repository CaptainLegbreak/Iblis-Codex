#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

struct D2AiControlStrc { char unk_00[0x14]; int dwAiParam[3]; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; int unk_04; D2UnitStrc* pTarget; int unk_0C[2]; int nDistance; int bCombat; D2MonStatsTxt* pMonstatsTxt; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x006416D0
int __fastcall sub_005541B0_IsDead(D2UnitStrc* pUnit); // 0x005541B0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkill); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkill, int nLevel); // 0x00646CA0
D2UnitStrc* __fastcall SKILLS_FindUseableCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nRange); // 0x005D2F80
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a3); // 0x00622C40
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStat, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall sub_00625D60(D2UnitStrc* pUnit); // 0x00625D60
void __fastcall sub_005DEAD0_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nSkill, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
void __fastcall sub_005DEFE0_Attack(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int a5); // 0x005DEFE0
void __fastcall sub_005DEC80_Walk(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSteps); // 0x005DEC80
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkill)
{
    if (nSkill >= 0 && nSkill < sgptDataTables->nSkillsTxtRecordCount) return &sgptDataTables->pSkillsTxt[nSkill];
    return 0;
}
#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))
#define AI_PARAM(n) pMonStats->wAiParam[n][pGame->nDifficulty]
// 0x005EC8C0
void __fastcall sub_005EC8C0_ThinkPet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2MonStatsTxt* pMonStats = pTick->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pTick->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner) return;
    D2UnitStrc* pTarget = 0;
    int bReachable = 0;
    int bUseSkill;
    int nDistance = 0;
    int nRange;
    D2UnitStrc* pCombatTarget = pTick->pTarget;
    int bCombat = pTick->bCombat;
    bUseSkill = 1;
    if (sub_006416D0_UnitEdgeDistance(pUnit, pOwner) >= AI_PARAM(4))
    {
        if (sub_005E3EA0(pGame, pOwner, pUnit, 3, 0, 0, 6)) return;
    }
    if (pCombatTarget && sub_005541B0_IsDead(pCombatTarget))
    {
        pCombatTarget = 0;
        bCombat = 0;
    }
    if (pMonStats->nSkill[0] > 0)
    {
        D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecord(pMonStats->nSkill[0]);
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStats->nSkill[0]);
        if (pSkills && pSkill)
        {
            nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwAuraRangeCalc, pMonStats->nSkill[0], SKILLS_GetSkillLevel(pUnit, pSkill, 1));
            nRange = D2_MIN(D2_MAX(nRange, 5), 50);
            pTarget = SKILLS_FindUseableCorpse(pGame, pUnit, pOwner, nRange);
            if (pTarget) nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pTarget);
        }
    }
    if (nDistance >= AI_PARAM(1))
        pTarget = 0;
    else if (pTarget)
        bReachable = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    if (sub_005E45D0_PetFollow(pGame, pUnit, pTarget, pOwner, bReachable, pTick, 0, 6)) return;
    int nClass;
    if (!pUnit) nClass = -1;
    else nClass = pUnit->dwClassId;
    int nCurrent;
    int nMaximum;
    switch (nClass)
    {
    case 426:
        nCurrent = STATLIST_UnitGetStatValue(pOwner, 6, 0);
        nMaximum = STATLIST_GetMaxLifeFromUnit(pOwner);
        if (nCurrent >= nMaximum) bUseSkill = 0;
        break;
    case 427:
        nCurrent = STATLIST_UnitGetStatValue(pOwner, 8, 0);
        nMaximum = sub_00625D60(pOwner);
        if (nCurrent >= nMaximum) bUseSkill = 0;
        break;
    }
    if (pTarget && bReachable && bUseSkill)
    {
        if (pAiControl->dwAiParam[1] + AI_PARAM(0) < pGame->dwGameFrame)
        {
            sub_005DEAD0_UseSkill(pGame, pUnit, 8, pMonStats->nSkill[0], pTarget, 0, 0);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame;
            return;
        }
    }
    if (bCombat && pCombatTarget)
    {
        if (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 25)
        {
            sub_005DEFE0_Attack(pGame, pUnit, pCombatTarget, (unsigned char)AI_PARAM(3), 0);
            return;
        }
    }
    if (pTarget) sub_005DEC80_Walk(pGame, pUnit, pTarget, 7);
    else AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(2));
}
