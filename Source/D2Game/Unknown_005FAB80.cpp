#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"









enum D2C_M81AbyssKnightAi
{
    MONMODE_ATTACK1 = 4,
    ABYSSKNIGHT_AI_PARAM_BONE_ARMOR_HP_PCT = 0,
    ABYSSKNIGHT_AI_PARAM_BONE_ARMOR_CHANCE_PCT = 1,
    ABYSSKNIGHT_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    ABYSSKNIGHT_AI_PARAM_MELEE_STALL_DURATION = 3,
    ABYSSKNIGHT_AI_PARAM_NO_FIRE_DISTANCE = 4,
    ABYSSKNIGHT_AI_PARAM_FIRE_RECOVERY = 5,
    ABYSSKNIGHT_AI_PARAM_APPROACH_CHANCE_PCT = 6,
    ABYSSKNIGHT_AI_PARAM_ACTIVE_DISTANCE = 7,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

// 0x005FAB80
void __fastcall AITHINK_Fn073_AbyssKnight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nTargetDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nLifePct = UNITS_GetCurrentLifePercentage(pUnit);

    if (pMonStatsTxt->nSkill[1] >= 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(pMonStatsTxt->nSkill[1]);
        if (pSkillsTxtRecord && pSkillsTxtRecord->nAuraState >= 0 && !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState)
            && nLifePct < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_BONE_ARMOR_HP_PCT)
            && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_BONE_ARMOR_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], 0, 0, 0);
            return;
        }
    }

    if (bCombat)
    {
        if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_MELEE_STALL_DURATION));
        return;
    }

    if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_NO_FIRE_DISTANCE) && pAiControl->dwAiParam[0] <= 0)
    {
        pAiControl->dwAiParam[0] = AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_FIRE_RECOVERY);
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[0] && (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pMonsterData || pUnit->pMonsterData->nComponent[10] < 4u))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        pAiControl->dwAiParam[0] = AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_FIRE_RECOVERY);
        return;
    }

    if (pAiControl->dwAiParam[0] > 0)
    {
        --pAiControl->dwAiParam[0];
    }

    if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_SetVelocity(pUnit, 2, 0, ((unsigned int)SEED_RollRandomNumber(pSeed) & 1) + 6);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_ACTIVE_DISTANCE))
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}
