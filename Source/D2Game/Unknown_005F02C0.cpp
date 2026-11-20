#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
struct D2UnitStrc;

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
union D2SeedStrc;
struct D2MonStatsTxt;
struct D2AiCmdStrc;
struct D2ZakarumPriestAiCallbackArgStrc;
struct D2StaticPathStrc;




struct D2ActiveRoomStrc
{
    char unk0x00[0x38];
    int nLastDeadGUIDs[4];
};





enum D2C_M230FallenAi
{
    EVENTTYPE_AITHINK = 2,
    MONMODE_DEATH = 0,
    MONMODE_NEUTRAL = 1,
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    MONMODE_SKILL2 = 9,
    MONMODE_DEAD = 12,
    FALLEN_AI_PARAM_COMMAND_ATTACK_CHANCE_PCT = 0,
    FALLEN_AI_PARAM_APPROACH_DISTANCE = 1,
    FALLEN_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT = 3,
};

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int a4); // 0x00540E60
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058ED10
extern "C" D2AiCmdStrc* __fastcall sub_0058EE80(D2UnitStrc* pUnit); // 0x0058EE80
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC530
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall sub_005DEFE0_Escape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0

struct D2ZakarumPriestAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nMaxLifePercentage;
    int nMaxDistance;
    int unk0x10[6];
};

enum D2C_M197ZakarumPriestAi
{
    ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT = 1,
    ZAKARUMPRIEST_AI_PARAM_LIGHTNING_CHANCE_PCT = 2,
    ZAKARUMPRIEST_AI_PARAM_CAST_CHANCE_PCT = 3,
    ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER = 4,
    ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE = 5,
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AIUTIL_TargetCallback pfnCallback, int nCallbackId); // 0x005DD0B0
int __fastcall sub_005DD290_NoMissileBarrierCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DD290
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);
D2UnitStrc* __fastcall AITHINK_TargetCallback_ZakarumPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F7240
int __fastcall sub_005FD470(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY);
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20


void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE0F0
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEF80
void __fastcall sub_005F2EB0_RemoveGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005F2EB0
int __fastcall AITHINK_TryRestoreGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005F2FC0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

enum D2C_SummonerAIParams
{
    SUMMONER_AI_PARAM_CAST_CHANCE_PCT = 0,
    SUMMONER_AI_PARAM_WEAKEN_CHANCE_PCT = 1,
    SUMMONER_AI_PARAM_PREF_ELEMENT_CHANCE_PCT = 2,
    SUMMONER_AI_PARAM_NOVA_TIMER = 3,
    SUMMONER_AI_PARAM_FIREWALL_TIMER = 4,
    SUMMONER_AI_PARAM_WALK_AWAY_CHANCE_PCT = 5,
    SUMMONER_AI_PARAM_NOVA_DISTANCE = 6,
    SUMMONER_AI_PARAM_MISSILE_DISTANCE = 7,
};

void __fastcall ACT2Q5_OnSummonerActivated(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059C330
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall sub_005DEFE0_AiEscape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

static __forceinline unsigned int AI_RollUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F02C0
void __fastcall AITHINK_Fn006_Fallen(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pUnit)
    {
        return;
    }

    const int nAnimMode = pUnit->dwAnimMode;
    if (nAnimMode == MONMODE_DEATH || nAnimMode == MONMODE_DEAD)
    {
        return;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

    for (; nNumRooms; ++ppRoomList, --nNumRooms)
    {
        const int* pDeadGUID = (*ppRoomList)->nLastDeadGUIDs;
        for (int i = 0; i < 4; ++i, ++pDeadGUID)
        {
            D2UnitStrc* pCorpse = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, *pDeadGUID);
            if (pCorpse && pCorpse->dwAnimMode == MONMODE_DEATH && (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCorpse, nX, nY) < 15)
            {
                pAiControl->dwAiParam[0] = 1;
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                sub_005DE190_SetAiParam(pUnit, 0, 50, 0);

                if (sub_005DEFE0_Escape(pGame, pUnit, pAiTickParam->pTarget, 12, 1))
                {
                    if ((int)(AI_RollUnit(pUnit) % 20) < 1)
                    {
                        SUNIT_AttachSound(pUnit, 17, 0);
                    }

                    return;
                }

                nNumRooms = 1;
                break;
            }
        }
    }

    if (nAnimMode != MONMODE_NEUTRAL)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2AiCmdStrc* pCurrentAiCmd = sub_0058EE80(pUnit);
    if (!pCurrentAiCmd)
    {
        if (!bCombat && sub_6FCF2E70(pUnit))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        if (nDistance < 15 && AIGENERAL_GetMinionOwner(pUnit) == pUnit && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_COMMAND_ATTACK_CHANCE_PCT))
        {
            D2AiCmdStrc aiCmd;
            aiCmd.nCmdParam[0] = 1;
            AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
            AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pTarget);
            return;
        }

        if (bCombat)
        {
            if (!pAiControl->dwAiParam[0])
            {
                if (!((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK_CHANCE_PCT)))
                {
                    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 30)
                    {
                        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pTarget);
                        return;
                    }

                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                    return;
                }
            }

            pAiControl->dwAiParam[0] = 0;
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        if (nDistance > AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_APPROACH_DISTANCE))
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 30)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }

        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (pCurrentAiCmd->nCmdParam[0] == 1)
    {
        if (bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK_CHANCE_PCT))
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                    return;
                }

                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }

        if (!AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0))
        {
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        }
    }
    else
    {
        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F72D0
void __fastcall AITHINK_Fn049_ZakarumPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    if (bCombat || sub_6FCF2E70(pUnit))
    {
        if (pMonStatsTxt->nSkill[2] >= 0 && nLifePercentage < 33 && pGame->dwGameFrame > pAiControl->dwAiParam[0])
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + 4 * AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);

            int nTargetX;
            int nShift = 0;
            int nX = CLIENTS_GetUnitX(pUnit);
            int nY = CLIENTS_GetUnitY(pUnit);
            nTargetX = CLIENTS_GetUnitX(pTarget);
            int nTargetY = CLIENTS_GetUnitY(pTarget);
            if (bCombat)
            {
                nShift = 2;
            }

            nTargetX = ((nTargetX - nX) << nShift) + nTargetX;
            nTargetY = ((nTargetY - nY) << nShift) + nTargetY;

            if (sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[2], 0, nTargetX, nTargetY))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], 0, nTargetX, nTargetY);
                return;
            }
        }

        if (bCombat && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }
    }

    D2ZakarumPriestAiCallbackArgStrc arg;
    arg.pTarget = 0;
    arg.nCounter = 0;
    arg.nMaxLifePercentage = 0x7FFFFFFF;
    arg.nMaxDistance = AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE) * AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE);
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_ZakarumPriest, 1);

    if (pMonStatsTxt->nSkill[0] >= 0 && arg.pTarget && (int)(AI_RollSeed(pSeed) % 100) < 25)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], arg.pTarget, 0, 0);
        return;
    }

    if (sub_005DD290_NoMissileBarrierCollision(pUnit, pTarget))
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_CAST_CHANCE_PCT))
        {
            if (pMonStatsTxt->nSkill[3] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);
                return;
            }

            if (pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[2] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_LIGHTNING_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
                pAiControl->dwAiParam[2] = pGame->dwGameFrame + 20;
                return;
            }
        }
    }
    else
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT) && pMonStatsTxt->nSkill[3] >= 0
            && pGame->dwGameFrame > pAiControl->dwAiParam[1] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);
            return;
        }
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < 30)
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
    }
}

static __forceinline int CLIENTS_GetUnitX_FrogDemon(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitY_FrogDemon(D2UnitStrc* pUnit)
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

// 0x005F8260
void __fastcall AITHINK_Fn052_FrogDemon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pAiControl->dwAiParam[2] == 0)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance > 12)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pAiTickParam->pTarget, 0, 0);
            AITACTICS_Idle(pGame, pUnit, 8);
            pAiControl->dwAiParam[2] = 1;
            sub_005F2EB0_RemoveGroundCollision(pGame, pUnit);
            return;
        }

        if (pMonStatsTxt->nSkill[1] >= 0 && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
            goto LABEL_EMERGE0;
        }

        if (!COLLISION_CheckMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX_FrogDemon(pUnit), CLIENTS_GetUnitY_FrogDemon(pUnit), 0xC01))
        {
            pAiControl->dwAiParam[2] = 2;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 12);
        return;
    }

    if (pAiControl->dwAiParam[2] == 1)
    {
        if (pMonStatsTxt->nSkill[1] >= 0 && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, 7) && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
LABEL_EMERGE:
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
            pAiControl->dwAiParam[2] = 2;
            return;
        }

        if (pMonStatsTxt->nSkill[1] >= 0 && nTargetDistance < 20 && pAiControl->dwAiParam[1] > 64 && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
            pAiControl->dwAiParam[2] = 2;
            return;
        }

        sub_005F2EB0_RemoveGroundCollision(pGame, pUnit);
        AITACTICS_Idle(pGame, pUnit, 24);
        ++pAiControl->dwAiParam[1];
        pAiControl->dwAiParam[2] = 1;
        return;

LABEL_EMERGE0:
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
        pAiControl->dwAiParam[2] = 2;
        return;
    }

    {
        if (!pTarget)
        {
            AITACTICS_Idle(pGame, pUnit, 32);
            return;
        }

        if (bCombat)
        {
            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 0))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 2))
            {
                sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
                return;
            }

            AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 6));
            return;
        }

        if (nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, 5))
        {
            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 4))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 3))
            {
                sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
                return;
            }

            AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 6));
            return;
        }

        if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 3))
        {
            sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
            return;
        }

        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 4);
        return;
    }
}

static __forceinline int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005F85C0
void __fastcall AITHINK_Fn053_Summoner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (!pAiControl->dwAiParam[0])
    {
        ACT2Q5_OnSummonerActivated(pGame, pUnit);
        pAiControl->dwAiParam[0] = 1;
    }

    if (nTargetDistance < 5 && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_WALK_AWAY_CHANCE_PCT))
    {
        sub_005DEFE0_AiEscape(pGame, pUnit, pTarget, 6, 0);
    }

    int bUseColdSkill = STATLIST_UnitGetStatValue(pTarget, 39, 0) >= STATLIST_UnitGetStatValue(pTarget, 43, 0);

    const int nX = CLIENTS_GetUnitXInline(pTarget);
    const int nY = CLIENTS_GetUnitYInline(pTarget);

    if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_CAST_CHANCE_PCT))
    {
        if (pMonStatsTxt->nSkill[4] >= 0 && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_WEAKEN_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pTarget, nX, nY);
            return;
        }

        int nDistance;
        D2UnitStrc* pMissileTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);

        if (AI_RollPercentage(pUnit) > AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_PREF_ELEMENT_CHANCE_PCT))
        {
            bUseColdSkill = (bUseColdSkill == 0);
        }

        if (bUseColdSkill)
        {
            if (pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_DISTANCE))
            {
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_TIMER);
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, nX, nY);
                return;
            }

            if (pMonStatsTxt->nSkill[0] >= 0 && pMissileTarget && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_MISSILE_DISTANCE))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pMissileTarget, nX, nY);
                return;
            }
        }

        if (pMonStatsTxt->nSkill[3] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[2])
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_FIREWALL_TIMER);
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, nX, nY);
            return;
        }

        if (pMonStatsTxt->nSkill[2] >= 0 && pMissileTarget && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_MISSILE_DISTANCE))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pMissileTarget, nX, nY);
            return;
        }

        if (!bUseColdSkill && pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_DISTANCE))
        {
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_TIMER);
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, nX, nY);
            return;
        }

        if (pMonStatsTxt->nSkill[4] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pTarget, nX, nY);
            return;
        }
    }

    AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
}
