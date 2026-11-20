#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"

#define UNIT_PLAYER 0
#define PLRMODE_DEATH 0
#define PLRMODE_DEAD 17
#define PATHTYPE_TOWARD 2
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define STATE_UNINTERRUPTABLE 54
#define MONMODE_ATTACK1 4
#define MONMODE_ATTACK2 5
#define AI_GetParamValue(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
struct D2AiBaalTargetArgsStrc;
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2TargetNodeStrc;
struct D2MonStatsTxt;
struct D2ModeChangeStrc;




struct D2TargetNodeStrc
{
    D2UnitStrc* hUnit;
    int unk0x04;
    D2TargetNodeStrc* pNext;
    D2TargetNodeStrc* unk0x0C;
};


struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
    char unk0x86[0x170 - 0x86];
    short nSkill[8];
    char nSkillMode[8];
    char unk0x188[0x20];
};



unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall ACT5Q5_IsNotActivatable(D2GameStrc* pGame); // 0x0058CF90
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __fastcall AIUTIL_CheckIfMonsterUsesSkill(D2UnitStrc* pUnit, int nSkillId); // 0x005DD2D0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE0F0
int __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DECA0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC530
int __fastcall AIBAAL_GetTargetScore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiBaalTargetArgsStrc* pArgs); // 0x005E8530
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTarget); // 0x00648B90
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nType); // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int a3); // 0x00649970
int __fastcall AITHINK_AreUnitsInSameLevel(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005EEB10
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x006416D0
int __stdcall sub_006417F0_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps); // 0x00649070

enum D2C_AncientBarb1AIParams
{
    ANCIENTBARB1_AI_PARAM_WHIRLWIND_DISTANCE = 0,
    ANCIENTBARB1_AI_PARAM_WHIRLWIND_CHANCE_PCT = 1,
    ANCIENTBARB1_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    ANCIENTBARB1_AI_PARAM_SKILL_REACH = 3,
};

int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DE000


void __fastcall AITHINK_AncientBarb1SkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EEB70
void __fastcall AITHINK_AncientBarb2SkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EEDA0
void __fastcall AITHINK_AncientBarb3SkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EF010
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall sub_0040C720_ReleaseReferences(int nArg); // 0x0040C720
void __fastcall sub_00469A60_ResetKeyConfig(int nArg); // 0x00469A60
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
extern "C" void __cdecl sub_00517ABB(void* pMemory); // 0x00517ABB
extern void* gpCelFile_007C02BC; // 0x007C02BC

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005E8F20
D2UnitStrc* __fastcall AIBAAL_GetTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pMax, int* pCount, D2AiBaalTargetArgsStrc* pArgs, int (__fastcall* pfCull)(D2UnitStrc*, D2UnitStrc*))
{
    D2_ASSERT(pfCull, 890);

    UNITS_GetRoom(pUnit);

    D2UnitStrc* pTarget = 0;
    int nCount = 0;
    int nMax = 0;
    D2TargetNodeStrc** ppTargetNode = pGame->pTargetNodes;
    D2TargetNodeStrc* pTargetNode = *ppTargetNode;
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    const unsigned char nAct = pUnit->nAct;

    for (int i = 0; i < 8; ++i)
    {
        if (pTargetNode)
        {
            D2_ASSERT(pTargetNode->hUnit && pTargetNode->hUnit->dwUnitType == UNIT_PLAYER, 917);
            D2UnitStrc* pTargetUnit = pTargetNode->hUnit;

            if (pfCull(pUnit, pTargetUnit))
            {
                int nCurrent;
                if (pTargetUnit && pTargetUnit->dwAnimMode != PLRMODE_DEAD && pTargetUnit->dwAnimMode != PLRMODE_DEATH)
                {
                    nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                }
                else
                {
                    nCurrent = 0;
                }

                while (1)
                {
                    if (nMax < nCurrent)
                    {
                        nMax = nCurrent;
                        pTarget = pTargetUnit;
                    }

                    pTargetNode = pTargetNode->pNext;
                    ++nCount;

                    if (!pTargetNode)
                    {
                        break;
                    }

                    pTargetUnit = pTargetNode->hUnit;
                    nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                }
            }
        }

        pTargetNode = *++ppTargetNode;
    }

    while (pTargetNode)
    {
        D2UnitStrc* pTargetUnit = pTargetNode->hUnit;
        if (nAct == pTargetUnit->nAct)
        {
            const int nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
            if (nMax < nCurrent)
            {
                nMax = nCurrent;
                pTarget = pTargetUnit;
            }
            ++nCount;
        }

        pTargetNode = pTargetNode->pNext;
    }

    pTargetNode = ppTargetNode[1];

    D2UnitStrc* pTemp = 0;
    int nTemp = 0;
    if (pTargetNode)
    {
        do
        {
            D2UnitStrc* pTargetUnit = pTargetNode->hUnit;
            if (nAct == pTargetUnit->nAct)
            {
                const int nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                if (nTemp < nCurrent)
                {
                    nTemp = nCurrent;
                    pTemp = pTargetUnit;
                }
            }

            pTargetNode = pTargetNode->pNext;
        }
        while (pTargetNode);

        if (pTemp && AIUTIL_GetDistanceToCoordinates_NoUnitSize(pTemp, nX, nY) < 5 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            sub_00648B90_SetPathTarget(pPath, pTarget);
            PATH_SetType(pPath, PATHTYPE_TOWARD);
            D2Common_10142(pPath, pUnit, 0);

            if (!sub_00648780_pointCount(pPath))
            {
                pTarget = pTemp;
                nMax = nTemp;
            }
        }
    }

    *pCount = nCount;
    *pMax = nMax;

    return pTarget;
}

// 0x005EEB70
void __fastcall AITHINK_AncientBarb1SkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (ACT5Q5_IsNotActivatable(pGame) || STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (!pTarget)
    {
        int nTemp1;
        int nTemp2;
        pTarget = AIBAAL_GetTarget(pGame, pUnit, &nTemp1, &nTemp2, 0, AITHINK_AreUnitsInSameLevel);
        if (!pTarget)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
            return;
        }
    }

    const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    const int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pTarget);

    const int bUseSkill = (pMonStatsTxt->nSkill[0] > 0 && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[0])
        && nDistance < AI_GetParamValue(pGame, pMonStatsTxt, ANCIENTBARB1_AI_PARAM_WHIRLWIND_DISTANCE)
        && AI_GetParamValue(pGame, pMonStatsTxt, ANCIENTBARB1_AI_PARAM_WHIRLWIND_CHANCE_PCT) > (int)SEED_RollLimitedRandomNumber(pSeed, 100));

    if (!bUseSkill)
    {
        if (bInMeleeRange)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParamValue(pGame, pMonStatsTxt, ANCIENTBARB1_AI_PARAM_ATTACK_CHANCE_PCT))
            {
                if (SEED_RollLimitedRandomNumber(pSeed, 2))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                }
                else
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                }
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
            }
        }
        else
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
            AITACTICS_Idle(pGame, pUnit, 10);
        }
        return;
    }

    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    int nXDiff = nTargetX - CLIENTS_GetUnitX(pUnit);
    int nYDiff = nTargetY - CLIENTS_GetUnitY(pUnit);

    const int nDist = sub_006417F0_GetDistanceToXY(pUnit, nTargetX, nTargetY);
    const int nScale = nDist ? nDist : 1;

    nXDiff = nXDiff * AI_GetParamValue(pGame, pMonStatsTxt, ANCIENTBARB1_AI_PARAM_SKILL_REACH) / nScale;
    nYDiff = nYDiff * AI_GetParamValue(pGame, pMonStatsTxt, ANCIENTBARB1_AI_PARAM_SKILL_REACH) / nScale;

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, pMonStatsTxt->nSkillMode[0], &modeChange);
    UNITS_SetUsedSkill(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[0]));
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    modeChange.nX = nXDiff + nTargetX;
    modeChange.nY = nYDiff + nTargetY;
    modeChange.nEventFlag = 100;
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 0);
}

// 0x005EF010
void __fastcall AITHINK_AncientBarb3SkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (ACT5Q5_IsNotActivatable(pGame))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    int nMax;
    int bInMeleeRange;
    D2UnitStrc* pTarget = AIBAAL_GetTarget(pGame, pUnit, &nMax, &bInMeleeRange, 0, AITHINK_AreUnitsInSameLevel);
    if (pTarget)
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
        const int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pTarget);

        if (pMonStatsTxt->nSkill[0] > 0 && nDistance < AI_PARAM(pGame, pMonStatsTxt, 0)
            && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 1)
            && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[0]))
        {
            AITACTICS_UseSequenceSkill(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        if (bInMeleeRange)
        {
            const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
            pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
            if ((int)((unsigned int)lSeed % 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
            {
                if (SEED_RollLimitedRandomNumber(pSeed, 2))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                }
                else
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                }
                return;
            }
        }
        else
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
            AITACTICS_Idle(pGame, pUnit, 10);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005EF1A0
void __fastcall AITHINK_Fn133_Ancient(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    switch (!pUnit ? -1 : pUnit->dwClassId)
    {
    case MONSTER_ANCIENTBARB1:
        AITHINK_AncientBarb1SkillHandler(pGame, pUnit, pAiTickParam);
        return;

    case MONSTER_ANCIENTBARB2:
        AITHINK_AncientBarb2SkillHandler(pGame, pUnit, pAiTickParam);
        return;

    case MONSTER_ANCIENTBARB3:
        AITHINK_AncientBarb3SkillHandler(pGame, pUnit, pAiTickParam);
        return;

    default:
        return;
    }
}

// 0x005EF910
void __fastcall AITHINK_Fn141_BaalMinion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (pTarget && pAiTickParam->bCombat)
    {
        if ((int)(SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            if (pMonStatsTxt->nSkill[0] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            }
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 2));
        }
    }
    else
    {
        if ((int)(SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
        }
    }

    AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
}

// 0x0040D530
int __cdecl sub_0040D530_Call0040C720()
{
    return sub_0040C720_ReleaseReferences(1);
}

// 0x004A5010
void __cdecl sub_004A5010_Call00469A60()
{
    sub_00469A60_ResetKeyConfig(0);
}

// 0x004A51E0
void __cdecl sub_004A51E0_FreeCelFile()
{
    if (gpCelFile_007C02BC)
    {
        sub_00478A00(gpCelFile_007C02BC);
        gpCelFile_007C02BC = 0;
    }
}

// 0x005EF1E0
int __fastcall sub_005EF1E0_BaalThroneGetAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag)
{
    return pAiTickParam->pAiControl->dwAiParam[1] & nFlag;
}

// build: context sub_00600C60_CallFree
void __fastcall sub_00600C60_CallFree(void* pMemory)
{
    sub_00517ABB(pMemory);
}
