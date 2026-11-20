#include "D2Structs.h"
#include "D2GameStrc.h"
struct D2AiControlStrc { char pad00[0x14]; int dwAiParam[3]; };
struct D2MonStatsTxt { char pad00[0x56]; short wAiParam[8][3]; char pad86[0xEA]; short nSkill[8]; unsigned char nSkillMode[8]; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; int unk04; D2UnitStrc* pTarget; int unk0C[2]; int nTargetDistance; int bCombat; D2MonStatsTxt* pMonstatsTxt; };
struct D2RegurgitatorAiCallbackArgStrc { D2UnitStrc* pTarget; int nDistance; int unk0x08[8]; };
typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AIUTIL_TargetCallback pCallback, int nCallbackId); // 0x005DD0B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlag); // 0x005DEC80
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nStep); // 0x005DEF80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
D2UnitStrc* __fastcall AITHINK_TargetCallback_Regurgitator(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005FA690
#define AI_PARAM(i) (pMonStats->wAiParam[i][pGame->nDifficulty])
#define ROLL() ((int)SEED_RollLimitedRandomNumber(pSeed, 100))

// 0x005FA710
void __fastcall sub_005FA710_RegurgitatorThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStats = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2UnitStrc* pCorpse;
    D2AiControlStrc* pAi = pAiTickParam->pAiControl;
    if (pAi->dwAiParam[0] == 5)
    {
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 16, 1);
        pAi->dwAiParam[0] = 0;
        return;
    }
    if (pAi->dwAiParam[0] == 2)
    {
        pCorpse = SUNIT_GetServerUnit(pGame, 1, pAi->dwAiParam[1]);
        if (pCorpse && pCorpse->dwAnimMode == 12)
        {
            if (AITHINK_GetSquaredDistance(pUnit, pCorpse) > 4)
            {
                if (pAi->dwAiParam[2] < 6)
                {
                    AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pCorpse, 1);
                    ++pAi->dwAiParam[2];
                }
                else
                {
                    pAi->dwAiParam[0] = 0;
                    pAi->dwAiParam[1] = 0;
                    pAi->dwAiParam[2] = 0;
                    AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
                    return;
                }
            }
            pAi->dwAiParam[0] = 3;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
            return;
        }
        pAi->dwAiParam[0] = 0;
        pAi->dwAiParam[1] = 0;
        pAi->dwAiParam[2] = 0;
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
        return;
    }
    if (pAi->dwAiParam[0] == 3)
    {
        pCorpse = SUNIT_GetServerUnit(pGame, 1, pAi->dwAiParam[1]);
        if (pMonStats->nSkill[0] >= 0 && pCorpse && pCorpse->dwAnimMode == 12)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[0], pMonStats->nSkill[0], pCorpse, 0, 0);
            pAi->dwAiParam[0] = 4;
            return;
        }
        pAi->dwAiParam[0] = 0;
        pAi->dwAiParam[1] = 0;
        pAi->dwAiParam[2] = 0;
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
        return;
    }
    if (pAi->dwAiParam[0] == 4)
    {
        if (!bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
            pAi->dwAiParam[0] = 5;
            return;
        }
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 8, 1);
        return;
    }
    D2RegurgitatorAiCallbackArgStrc args;
    args.pTarget = 0;
    const int nDistance = AI_PARAM(5);
    args.nDistance = nDistance * nDistance;
    sub_6FCF1E80(pGame, pUnit, &args, AITHINK_TargetCallback_Regurgitator, 1);
    pCorpse = args.pTarget;
    if (pAi->dwAiParam[0] == 1)
    {
        if (pCorpse)
        {
            pAi->dwAiParam[1] = !pCorpse ? -1 : pCorpse->dwUnitId;
            if (AITHINK_GetSquaredDistance(pUnit, pCorpse) > 2)
            {
                AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pCorpse, 1);
                pAi->dwAiParam[0] = 2;
                pAi->dwAiParam[2] = 0;
                return;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
            pAi->dwAiParam[0] = 3;
            pAi->dwAiParam[2] = 0;
            return;
        }
        if (ROLL() < 20)
        {
            pAi->dwAiParam[0] = 0;
            pAi->dwAiParam[1] = 0;
            pAi->dwAiParam[2] = 0;
            return;
        }
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
        return;
    }
    if (pCorpse)
    {
        if (AITHINK_GetSquaredDistance(pUnit, pCorpse) < 9 && ROLL() < AI_PARAM(1))
        {
            AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pCorpse, 1);
            pAi->dwAiParam[0] = 2;
            pAi->dwAiParam[1] = !pCorpse ? -1 : pCorpse->dwUnitId;
            pAi->dwAiParam[2] = 0;
            return;
        }
        if (ROLL() < AI_PARAM(4))
        {
            AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pCorpse, 1);
            pAi->dwAiParam[0] = 2;
            pAi->dwAiParam[1] = !pCorpse ? -1 : pCorpse->dwUnitId;
            pAi->dwAiParam[2] = 0;
            return;
        }
    }
    int nRoll = ROLL();
    int nDifficulty = pGame->nDifficulty;
    if (bCombat)
    {
        if (nRoll < pMonStats->wAiParam[0][nDifficulty]) AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        else AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }
    if (nRoll < pMonStats->wAiParam[2][nDifficulty])
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        return;
    }
    if (pCorpse && ROLL() < AI_PARAM(3))
    {
        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pCorpse, 1);
        pAi->dwAiParam[0] = 2;
        pAi->dwAiParam[1] = !pCorpse ? -1 : pCorpse->dwUnitId;
        pAi->dwAiParam[2] = 0;
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
}
