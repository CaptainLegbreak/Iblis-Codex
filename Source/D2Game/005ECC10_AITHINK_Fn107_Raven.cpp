struct D2SkillStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    unsigned int dwOwnerType;
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x000[0x32];
    short nVelocity;
    short nRun;
    char unk0x036[0x56 - 0x36];
    short wAiParam[8][3];
    char unk0x086[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
    char unk0x188[0x20];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
};

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

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define MONMODE_ATTACK1 4

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall sub_004EFCB0_GetSummonLevel(int nSkillId, int nSkillLevel);                                  // 0x004EFCB0
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkAroundTargetWithScaledDistance(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nScale); // 0x005DE6F0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int a4, int bRun, int nVelocity, int a7); // 0x005E3EA0
int __fastcall sub_005ECBC0_RavenWalkToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char a4, int a2); // 0x005ECBC0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0

// 0x005ECC10
void __fastcall AITHINK_Fn107_Raven(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (!pMonStatsTxt)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (pAiControl->dwAiParam[0] == -1)
    {
        pAiControl->dwAiParam[0] = 3;
        if (pMonStatsTxt->nSkill[0] >= 0)
        {
            const int nSkillLevel = SKILLS_GetSkillLevel(pOwner, SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pMonStatsTxt->nSkill[0]), 1);
            pAiControl->dwAiParam[0] = sub_004EFCB0_GetSummonLevel(pMonStatsTxt->nSkill[0], nSkillLevel);
        }
    }
    else if (pAiControl->dwAiParam[0] == 0)
    {
        SUNITDMG_KillMonster(pGame, pUnit, pUnit, 1);
        return;
    }

    const int nOwnerDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    if (nOwnerDistance > 50)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, 0);
        return;
    }

    int nVel;
    if (pMonStatsTxt->nVelocity <= 0)
    {
        nVel = 100;
    }
    else
    {
        nVel = 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity - 100;
        if (nVel >= 100)
        {
            nVel = 100;
        }
    }

    if (nOwnerDistance > 28)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, nVel, 0);
        return;
    }

    int nDist;
    int bFoundCombat;
    D2UnitStrc* pFound = sub_6FCF2110(pGame, pOwner, pAiTickParam->pAiControl, &nDist, &bFoundCombat);
    if (pFound)
    {
        nDist = sub_006416D0_UnitEdgeDistance(pUnit, pFound);
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int bCombat = pAiTickParam->bCombat;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int nAverageDistance = (AI_PARAM(pGame, pMonStatsTxt, 1) + AI_PARAM(pGame, pMonStatsTxt, 0)) / 2;

    if (pTarget && pAiControl->dwAiParam[1] < pGame->dwGameFrame)
    {
        const int nDifficulty = pGame->nDifficulty;
        if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < pMonStatsTxt->wAiParam[3][nDifficulty]
            && nTargetDistance < pMonStatsTxt->wAiParam[4][nDifficulty])
        {
            if (bCombat)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 10 * AI_PARAM(pGame, pMonStatsTxt, 2);
                --pAiControl->dwAiParam[0];
            }
            else
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            }
            return;
        }
    }

    int bFailed;
    if (nOwnerDistance > AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        bFailed = !AITACTICS_WalkAroundTargetWithScaledDistance(pGame, pUnit, pAiTickParam->pAiControl, pOwner, nAverageDistance);
    }
    else if (nOwnerDistance < AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        bFailed = !AITACTICS_WalkAroundTargetWithScaledDistance(pGame, pUnit, pAiTickParam->pAiControl, pOwner, nAverageDistance);
    }
    else if (pAiControl->dwAiParam[2] ? sub_005ECBC0_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 5) : sub_005ECBC0_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 6))
    {
        return;
    }
    else
    {
        pAiControl->dwAiParam[2] = pAiControl->dwAiParam[2] == 0;
        if (pAiControl->dwAiParam[2] ? sub_005ECBC0_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 5) : sub_005ECBC0_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 6))
        {
            return;
        }

        bFailed = !AITACTICS_WalkAroundTargetWithScaledDistance(pGame, pUnit, pAiTickParam->pAiControl, pOwner, nAverageDistance);
    }

    if (bFailed)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 1, 0, 0, 0);
    }
}
