#include "D2Structs.h"

struct D2AiControlStrc
{
    char unk0x00[0x14];
    int dwAiParam[3];
};


struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2MonStatsTxt
{
    char unk0x00[0x32];
    short nVelocity;
    short nRun;
    char unk0x36[0x20];
    short wAiParam[8][3];
    char unk0x86[0xEA];
    short nSkill[8];
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    void* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                // 0x0045C390
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                      // 0x00552F60
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                               // 0x0058F0D0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);               // 0x005DC380
int __fastcall sub_6FCF14D0(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                               // 0x005DC640
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0
D2UnitStrc* __fastcall sub_6FCCFD40(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat, int nMaxDistance); // 0x005DDE50
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget); // 0x005DDF90
int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DE000
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                    // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                                 // 0x005DE0F0
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);                      // 0x005DE190
int __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);              // 0x005DECA0
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int a4, int bRun, int nVelocity, int a7); // 0x005E3EA0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

// 0x005ED730
void __fastcall AITHINK_Fn112_DruidBear(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (pAiControl->dwAiParam[2])
        {
            D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, pAiControl->dwAiParam[2]);
            if (pPlayer)
            {
                D2GAME_AI_PetMove_6FCE2BA0(pGame, pPlayer, pUnit, 3, 0, 0, 0);
                return;
            }
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    pAiControl->dwAiParam[2] = !pOwner ? -1 : pOwner->dwUnitId;

    int nOwnerAnimMode;
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    nOwnerAnimMode = pOwner->dwAnimMode;
    int nVel;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (nDistance > 50)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, 0);
        return;
    }

    nVel = pMonStatsTxt->nVelocity > 0 ? 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity - 100 : 100;
    if (nVel >= 100)
    {
        nVel = 100;
    }

    if (nDistance > 28)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 100, 0);
        return;
    }

    if (nDistance > 18)
    {
        if (nOwnerAnimMode == 2 || nOwnerAnimMode == 6)
        {
            if (D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 0, 0))
            {
                return;
            }
        }

        if (nOwnerAnimMode == 3 && D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 100, 0))
        {
            return;
        }
    }

    int nTemp1;
    int nTemp2;
    int nTargetDistance;
    int bCombat;
    D2UnitStrc* pPotentialTarget = sub_6FCF2110(pGame, pOwner, pAiControl, &nTemp1, &nTemp2);
    D2UnitStrc* pTarget = sub_6FCCFD40(pGame, pUnit, pAiControl, &nTargetDistance, &bCombat, 28);
    if (pTarget && !sub_6FCF14D0(pUnit, pTarget))
    {
        pTarget = 0;
    }

    if (!pTarget && pPotentialTarget)
    {
        nTargetDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pPotentialTarget);
        if (nTargetDistance < 28 && sub_6FCF14D0(pUnit, pPotentialTarget))
        {
            pTarget = pPotentialTarget;
        }
    }

    if (bCombat)
    {
        if (pTarget)
        {
            if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
            {
                AITACTICS_UseSequenceSkill(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 0));
            }
            return;
        }
    }
    else if (pTarget)
    {
        if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_SetVelocity(pUnit, 0, nVel, 40);
        }

        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
        return;
    }

    if (nDistance > 16)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 0, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
    }
}
