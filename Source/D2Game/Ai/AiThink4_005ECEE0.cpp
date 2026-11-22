#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#include "D2GameTypes.h"
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE0F0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2UnitStrc* __fastcall sub_6FCCFD40(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat, int nRange); // 0x005DDE50
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0
int __fastcall sub_005DC640_HasFreeSpotNearTarget(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005DC640
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x006416D0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x005DED20
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200

#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))
#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
// 0x005ECEE0
void __fastcall AITHINK_Fn108_SpiritWolf(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2MonStatsTxt* pMonStats = pTick->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pTick->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (pAiControl->dwAiParam[2])
        {
            D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, pAiControl->dwAiParam[2]);
            if (pPlayer && pMonStats->nSkill[0] >= 0)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[0], pMonStats->nSkill[0], 0, CLIENTS_GetUnitX(pPlayer), CLIENTS_GetUnitY(pPlayer));
                EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + 6, 0, 0);
                AITACTICS_Idle(pGame, pUnit, 8);
                return;
            }
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    pAiControl->dwAiParam[2] = !pOwner ? -1 : pOwner->dwUnitId;
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (!sub_005E45D0_PetFollow(pGame, pUnit, 0, pOwner, 0, pTick, 0, 6))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 33);
        }
        return;
    }

    const int nRange = AI_PARAM(pGame, pMonStats, 3);
    int nDistance;
    int bCombat;
    D2UnitStrc* pTarget = sub_6FCCFD40(pGame, pUnit, pAiControl, &nDistance, &bCombat, nRange);
    int nOwnerDistance;
    int bOwnerCombat;
    D2UnitStrc* pOwnerTarget = sub_6FCF2110(pGame, pOwner, pAiControl, &nOwnerDistance, &bOwnerCombat);
    if (pTarget && !sub_005DC640_HasFreeSpotNearTarget(pUnit, pTarget))
    {
        pTarget = 0;
    }

    if (!pTarget && pOwnerTarget)
    {
        nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwnerTarget);
        if (nDistance < nRange && !sub_005DC640_HasFreeSpotNearTarget(pUnit, pOwnerTarget))
        {
            pTarget = pOwnerTarget;
        }
    }

    int nVelocity;
    if (pMonStats->nVelocity <= 0 || (nVelocity = pMonStats->nRun * 100 / pMonStats->nVelocity - 100) >= 100)
    {
        nVelocity = 100;
    }

    const int nOwnerDistance2 = sub_006416D0_UnitEdgeDistance(pOwner, pUnit);
    if (pMonStats->nSkill[0] >= 0 && nOwnerDistance2 > 50)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[0], pMonStats->nSkill[0], 0, CLIENTS_GetUnitX(pOwner), CLIENTS_GetUnitY(pOwner));
        EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + 4, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 10);
        return;
    }

    if (nOwnerDistance2 > AI_PARAM(pGame, pMonStats, 4))
    {
        if (sub_005E3EA0(pGame, pOwner, pUnit, 0, 1, 100, 0))
        {
            return;
        }
    }

    const int nOwnerMode = pOwner->dwAnimMode;
    if (nOwnerDistance2 > AI_PARAM(pGame, pMonStats, 2))
    {
        if (nOwnerMode == 2 || nOwnerMode == 6)
        {
            if (sub_005E3EA0(pGame, pOwner, pUnit, 0, 0, 0, 0))
            {
                return;
            }
        }

        if (nOwnerMode == 3)
        {
            if (sub_005E3EA0(pGame, pOwner, pUnit, 0, 1, 100, 0))
            {
                return;
            }
        }
    }

    if (sub_005E45D0_PetFollow(pGame, pUnit, pTarget, pOwner, bCombat, pTick, 1, 6))
    {
        return;
    }

    if (pTarget)
    {
        if (bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStats, 0));
            return;
        }

        if (sub_006416D0_UnitEdgeDistance(pOwner, pTarget) < nRange)
        {
            sub_005DE190_SetAiParam(pUnit, 0, nVelocity, 0);
            AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
            return;
        }

        if (nOwnerDistance2 > 10)
        {
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pOwner, 8, 6);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < AI_PARAM(pGame, pMonStats, 1))
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 10);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}
