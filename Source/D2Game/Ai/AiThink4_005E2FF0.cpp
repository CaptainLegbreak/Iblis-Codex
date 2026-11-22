#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitId); // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0
int __fastcall sub_005DD280(D2UnitStrc* pUnit); // 0x005DD280
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEF80
int __fastcall sub_005DEFE0_Escape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
void __fastcall AITACTICS_UseSkillInRange(D2UnitStrc* pUnit, int nRange, int nSkillId, int nMode); // 0x005DF850
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 nValue = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nValue >> 32);
    pSeed->nLowSeed = (unsigned int)nValue;
    return nValue;
}

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_ROLL_PERCENT(pSeed) ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100))

// 0x005E2FF0
void __fastcall sub_005E2FF0_MonsterThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2MonStatsTxt* pRecords[4] = { MONSTERMODE_GetMonStatsTxtRecord(492), MONSTERMODE_GetMonStatsTxtRecord(493), MONSTERMODE_GetMonStatsTxtRecord(494), MONSTERMODE_GetMonStatsTxtRecord(495) };
    if (pAiControl->dwAiParam[0] != -1 && !STATLIST_GetUnitAlignment(pUnit))
    {
        const int nOtherId = pAiControl->dwAiParam[0];
        D2UnitStrc* pOther = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nOtherId);
        if (!pOther || SUNIT_IsDead(pOther) || SUNIT_GetOwner(pGame, pOther) || STATLIST_GetUnitAlignment(pOther))
        {
            AIGENERAL_GetAiControlFromUnitInline(pUnit)->dwAiParam[0] = -1;
        }
        else
        {
            if (AITHINK_GetSquaredDistance(pUnit, pOther) > AI_PARAM(pGame, pRecords[1], 0) * AI_PARAM(pGame, pRecords[1], 0))
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pOther, 0);
                return;
            }

            if (pMonStatsTxt->nSkill[0] >= 0)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pOther, 0, 0);
                return;
            }
        }
    }

    if (bCombat)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && sub_005DD280(pUnit) < AI_PARAM(pGame, pRecords[0], 0))
        {
            AITACTICS_UseSkillInRange(pUnit, AI_PARAM(pGame, pRecords[0], 1), pMonStatsTxt->nSkill[0], (signed char)pMonStatsTxt->nSkillMode[0]);
            return;
        }

        if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pRecords[2], 1) && sub_005DEFE0_Escape(pGame, pUnit, pTarget, 5, 1))
        {
            return;
        }
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pRecords[0], 2))
    {
        AITACTICS_UseSkillInRange(pUnit, AI_PARAM(pGame, pRecords[0], 1), pMonStatsTxt->nSkill[0], (signed char)pMonStatsTxt->nSkillMode[0]);
        return;
    }

    if (nDistance < AI_PARAM(pGame, pRecords[2], 0) && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pRecords[2], 1))
    {
        sub_005DEFE0_Escape(pGame, pUnit, pTarget, 5, 0);
        return;
    }

    if (pMonStatsTxt->nSkill[3] >= 0)
    {
        D2UnitStrc* pSelected = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);
        if (pSelected)
        {
            if (nDistance < AI_PARAM(pGame, pRecords[2], 2))
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pRecords[2], 3))
                {
                    AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pSelected, 0, 0);
                    return;
                }
            }
            else if (nDistance < AI_PARAM(pGame, pRecords[3], 2))
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pRecords[3], 3))
                {
                    AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pSelected, 0, 0);
                    return;
                }
            }
        }
    }

    if (AI_ROLL_PERCENT(pSeed) < 33)
    {
        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 4);
        return;
    }

    if (AI_ROLL_PERCENT(pSeed) < 20)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}
