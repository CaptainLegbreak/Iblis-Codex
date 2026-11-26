#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2MonModes.h"
#include "D2CommonApi.h"

#define UNIT_MONSTER 1

enum D2C_P11AiConstants
{
    AISPECIALSTATE_NONE = 0,
    EVENTTYPE_AITHINK = 2,
    STAT_POISONRESIST = 45,
    MONSTATSFLAGINDEX_INTERACT = 9,
};


typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

#include "D2GameFuncs.h"
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall AITACTICS_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode);                              // 0x0046C140
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
D2UnitStrc* __fastcall AITHINK_TargetCallback_PutridDefiler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005EFA50
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480


int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY);                          // 0x00621DC0
unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex);                               // 0x0063E7A0
void __stdcall INVENTORY_GetDirectionDelta(unsigned char nDirection, unsigned int* pX, unsigned int* pY); // 0x0063E7E0
int __fastcall sub_6FC68350(int nMonsterId, D2ActiveRoomStrc* pRoom, int nX, int nY, int a5);              // 0x005FD350

inline int CLIENTS_GetUnitXInline_005E17E0(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline_005E17E0(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

inline short AI_GetParamValue_005E17E0(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

inline void AITHINK_IdleInline_005E17E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    if (!nFrames)
    {
        nFrames = 1;
    }
    D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrames + pGame->dwGameFrame, 0, 0);
}

static D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x005EC6C0
void __fastcall AITHINK_Fn110_Vines(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    int bCombat = 0;
    int nDistance = 0;
    if (!pOwner)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    if (DRLG_UnitEdgeDistance(pUnit, pOwner) >= AI_PARAM(pGame, pMonStatsTxt, 4) && D2GAME_AI_PetMove(pGame, pOwner, pUnit, 3, 0, 0, 6))
    {
        return;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (!AITHINK_TryPetFollowOwner(pGame, pUnit, 0, pOwner, 0, pAiTickParam, 0, 6))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 2));
        }
        return;
    }

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (nDistance >= AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        pTarget = 0;
    }

    if (AITHINK_TryPetFollowOwner(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 6))
    {
        return;
    }

    if (pTarget)
    {
        if (STATES_CheckState(pTarget, STATE_POISON) || STATLIST_UnitGetStatValue(pTarget, STAT_POISONRESIST, 0) == 100)
        {
            AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, AI_PARAM(pGame, pMonStatsTxt, 3), 0);
            return;
        }

        if (bCombat)
        {
            if (pMonStatsTxt->nSkill[0] >= 0 && AI_PARAM(pGame, pMonStatsTxt, 0) + pAiControl->dwAiParam[1] < pGame->dwGameFrame)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame;
                return;
            }
        }
        else
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 2));
}

