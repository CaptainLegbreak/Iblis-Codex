#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"





struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

void __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
void __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget); // 0x005DDF90
void __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DECA0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080

static __forceinline unsigned int SEED_RollPercentage(D2SeedStrc* pSeed, unsigned int& nLowSeed, unsigned int& nHighSeed)
{
    const uint64_t lSeed = pSeed->nHighSeed + 0x6AC690C5ui64 * pSeed->nLowSeed;
    nHighSeed = (unsigned int)(lSeed >> 32);
    nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = nHighSeed;
    pSeed->nLowSeed = nLowSeed;
    return nLowSeed % 100;
}

static __forceinline unsigned int SEED_RollPercentageAgain(D2SeedStrc* pSeed, unsigned int& nLowSeed, unsigned int& nHighSeed)
{
    const uint64_t lSeed = nHighSeed + 0x6AC690C5ui64 * nLowSeed;
    nHighSeed = (unsigned int)(lSeed >> 32);
    nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = nHighSeed;
    pSeed->nLowSeed = nLowSeed;
    return nLowSeed % 100;
}

static __forceinline short AI_GetParamValue(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxtRecord, int nParamId)
{
    return pMonStatsTxtRecord->wAiParam[nParamId][pGame->nDifficulty];
}

// 0x005E36F0
void __fastcall AITHINK_Fn125_BloodLord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxtRecord = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    unsigned int nLowSeed;
    unsigned int nHighSeed;
    if (bCombat)
    {
        if ((int)SEED_RollPercentage(pSeed, nLowSeed, nHighSeed) < AI_GetParamValue(pGame, pMonStatsTxtRecord, 0))
        {
            if ((int)SEED_RollPercentageAgain(pSeed, nLowSeed, nHighSeed) < AI_GetParamValue(pGame, pMonStatsTxtRecord, 2))
            {
                AITACTICS_UseSkill(pGame, pUnit, 5, pMonStatsTxtRecord->nSkill[0], pTarget, 0, 0);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParamValue(pGame, pMonStatsTxtRecord, 3));
        return;
    }
    else
    {
        if ((int)SEED_RollPercentage(pSeed, nLowSeed, nHighSeed) < AI_GetParamValue(pGame, pMonStatsTxtRecord, 1))
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParamValue(pGame, pMonStatsTxtRecord, 3));
    }
}
