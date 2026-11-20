#include "D2Game.h"
#include "D2Structs.h"

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define MONMODE_ATTACK1 4
struct D2SeedStrc;
struct D2MonStatsTxt;
struct D2StaticPathStrc;


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

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall sub_004EFCB0_GetSummonLevel(int nSkillId, int nSkillLevel); // 0x004EFCB0
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_WalkAroundTargetWithScaledDistance(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nScale); // 0x005DE6F0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int a4, int bRun, int nVelocity, int a7); // 0x005E3EA0
int __fastcall sub_005ECBC0_RavenWalkToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char a4, int a2); // 0x005ECBC0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
void __fastcall AITHINK_Fn108_SpiritWolf(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005ECEE0
void __fastcall AITHINK_Fn108_Fenris(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005ED2A0

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

enum D2C_M80TotemAi
{
    PLRMODE_WALK = 2,
    PLRMODE_RUN = 3,
    PLRMODE_TOWNWALK = 6,
    TOTEM_AI_PARAM_WALK_AWAY_CHANCE_PCT = 0,
    TOTEM_AI_PARAM_IGNORE_TARGET_CHANCE_PCT = 1,
    TOTEM_AI_PARAM_TELEPORT_TO_OWNER_DISTANCE = 2,
    TOTEM_AI_PARAM_FOLLOW_OWNER_DISTANCE = 3,
};

int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
D2UnitStrc* __fastcall sub_6FCCFD40(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat, int nMaxDistance); // 0x005DDE50
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall sub_005E45D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int a5, D2AiTickParamStrc* pAiTickParam, int a7, int a8); // 0x005E45D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

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

// 0x005ED710
void __fastcall AITHINK_Fn108_DruidWolf(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (pUnit && pUnit->dwClassId == 420)
    {
        AITHINK_Fn108_SpiritWolf(pGame, pUnit, pAiTickParam);
        return;
    }
    AITHINK_Fn108_Fenris(pGame, pUnit, pAiTickParam);
}

static __forceinline int CLIENTS_GetUnitXInline_Totem(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitYInline_Totem(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005ED9E0
void __fastcall AITHINK_Fn109_Totem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nDistance;
    int bCombat;
    D2UnitStrc* pTarget = sub_6FCCFD40(pGame, pUnit, pAiControl, &nDistance, &bCombat, 24);
    if (bCombat && pTarget && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_WALK_AWAY_CHANCE_PCT) && D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 6, 1))
    {
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_IGNORE_TARGET_CHANCE_PCT))
    {
        pTarget = 0;
        bCombat = 0;
    }

    const int nOwnerDistance = sub_006416D0_UnitEdgeDistance(pUnit, pOwner);
    if (nOwnerDistance > AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_TELEPORT_TO_OWNER_DISTANCE))
    {
        if (sub_6FCBDFE0(pGame, pUnit, UNITS_GetRoom(pOwner), CLIENTS_GetUnitXInline_Totem(pOwner), CLIENTS_GetUnitYInline_Totem(pOwner), 0, 0))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
            return;
        }
    }

    const int nOwnerAnimMode = pOwner->dwAnimMode;
    if (nOwnerDistance > AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_FOLLOW_OWNER_DISTANCE))
    {
        if (((nOwnerAnimMode == PLRMODE_WALK || nOwnerAnimMode == PLRMODE_TOWNWALK) && D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 0, 0))
            || (nOwnerAnimMode == PLRMODE_RUN && D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 60, 0)))
        {
            return;
        }
    }

    if (sub_005E45D0(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 6))
    {
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}
