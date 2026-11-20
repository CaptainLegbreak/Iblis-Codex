#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define MONMODE_SKILL1 8
#define EVENTTYPE_AITHINK 0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SeedStrc;
struct D2MonStatsTxt;
struct D2StaticPathStrc;
struct D2TargetNodeStrc;




struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
    char unk0x86[0xEA];
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

enum D2C_AiThink005F0A20
{
    MONMODE_ATTACK1 = 4,
    AI_PARAM_ESCAPE_CHANCE_PCT = 0,
    AI_PARAM_IDLE_FRAMES = 1,
    AI_PARAM_ATTACK_CHANCE_PCT = 2,
};

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
};

enum D2C_M101SandLeaperConstants
{
    MONMODE_ATTACK2 = 5,
};

void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4); // 0x005DE190
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMaxDistance); // 0x005DF530
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
int __fastcall sub_005FD470(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005FD470

enum D2C_SandLeaperAIParams
{
    SANDLEAPER_AI_PARAM_LEAP_CHANCE_PCT = 0,
    SANDLEAPER_AI_PARAM_ATTACK_CHANCE_PCT = 1,
    SANDLEAPER_AI_PARAM_APPROACH_CHANCE_PCT = 2,
    SANDLEAPER_AI_PARAM_CIRCLE_CHANCE_PCT = 3,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance); // 0x005DE200


struct D2TargetNodeStrc
{
    D2UnitStrc* pUnit;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC530
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F0A20
void __fastcall sub_005F0A20_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_ESCAPE_CHANCE_PCT))
    {
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 12, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
}

static __forceinline unsigned int AI_RollSeedUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F20A0
void __fastcall AITHINK_Fn017_SandLeaper(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pMonStatsTxt->nSkill[0] >= 0 && nDistance < 5
        && (int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SANDLEAPER_AI_PARAM_LEAP_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, 0, 0))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    if (bCombat)
    {
        if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SANDLEAPER_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    else
    {
        if (nDistance > 10)
        {
            AITACTICS_SetVelocity(pUnit, 0, 75, 0);
            D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTarget, 5);
            return;
        }

        if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SANDLEAPER_AI_PARAM_APPROACH_CHANCE_PCT))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
            return;
        }

        if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SANDLEAPER_AI_PARAM_CIRCLE_CHANCE_PCT))
        {
            sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

// 0x005F6B70
void __fastcall sub_005F6B70(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nState = pAiTickParam->pAiControl->dwAiParam[0];

    if (nState == 2)
    {
        SUNITDMG_KillMonster(pGame, pUnit, pTarget, 1);
        return;
    }

    if (!nState)
    {
        if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, 1) || sub_6FCF2E70(pUnit))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
            pAiControl->dwAiParam[0] = 1;
            return;
        }
    }

    if (pAiControl->dwAiParam[0] == 1)
    {
        if (!bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
                return;
            }

            AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
            return;
        }

        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 1, 0, 0);
        pAiControl->dwAiParam[0] = 2;
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 2));
}

static __forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F8010
D2UnitStrc* __fastcall AITHINK_GetTargetForUberMinion(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = 0;
    D2TargetNodeStrc** ppNode = pGame->pTargetNodes;
    D2TargetNodeStrc* pNode = *ppNode;
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    for (int i = 0; i < 8; ++i)
    {
        if (pNode)
        {
            D2UnitStrc* pPlayer = pNode->pUnit;
            if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer)) == nLevelId
                && !SUNIT_IsDead(pPlayer)
                && (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pPlayer, nX, nY) < 1020)
            {
                D2_ASSERT(pPlayer && pPlayer->dwUnitType == 0, 5117);
                const int nClassChance[7] = { 35, 40, 30, 20, 0, 25, 10 };
                const int nClass = pPlayer->dwClassId;
                const unsigned int nRoll = ITEMS_RollRandomNumber(&pUnit->pSeed);
                if (nClassChance[nClass] + (int)(nRoll % 20) > -1)
                {
                    pTarget = pPlayer;
                }
            }
        }
        pNode = *++ppNode;
    }
    return pTarget;
}
