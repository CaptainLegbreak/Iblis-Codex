#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"

#define UNIT_MONSTER 1



enum D2C_P11AiConstants
{
    AISPECIALSTATE_NONE = 0,
    EVENTTYPE_AITHINK = 2,
    MONMODE_ATTACK1 = 4,
    MONMODE_SKILL1 = 8,
    SKILL_IMPREGNATE = 300,
    STATE_POISON = 2,
    STAT_POISONRESIST = 45,
    MONSTER_VILEMOTHER1 = 0x12A,
    MONMODE_RUN = 15,
    MONSTATSFLAGINDEX_INTERACT = 9,
    STATE_TERROR = 0x38,
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




struct D2MinionSpawnerAiCallbackArgStrc
{
    int nMinions;
    int unk0x04[9];
};


typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

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

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                         // 0x005B0BD0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall sub_00573120_ClearMonsterPair(D2UnitStrc* pUnit);                                           // 0x00573120
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode);                              // 0x0046C140
int __fastcall sub_005DF140_Escape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DF140
int __fastcall sub_005DEFE0_Escape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance);         // 0x005DE200
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
D2UnitStrc* __fastcall AITHINK_TargetCallback_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E2B70
D2UnitStrc* __fastcall AITHINK_TargetCallback_PutridDefiler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005EFA50
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
int __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);       // 0x005DECA0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int a4, int bRun, int nVelocity, int a7); // 0x005E3EA0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __fastcall sub_005E45D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int a5, D2AiTickParamStrc* pAiTickParam, int a7, int a8); // 0x005E45D0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
int __fastcall sub_005FB650_GetTrapArrowVariant(D2GameStrc* pGame, D2UnitStrc* pUnit);                     // 0x005FB650

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY);                          // 0x00621DC0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex);                               // 0x0063E7A0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY);                  // 0x0063E7E0
int __fastcall sub_6FC68350(int nMonsterId, D2ActiveRoomStrc* pRoom, int nX, int nY, int a5);              // 0x005FD350

__forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

__forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

inline short AI_GetParamValue(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

inline void AITHINK_IdleInline(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    if (!nFrames)
    {
        nFrames = 1;
    }
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
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

// 0x005E17E0
void __fastcall sub_005E17E0_SiegeBeastSetTower(D2UnitStrc* pUnit, D2UnitStrc* pBeast)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitInline(pUnit);
    if (pBeast)
    {
        D2UnitStrc* pCurrent = SUNIT_GetServerUnit(SUNIT_GetGameFromUnit(pUnit), UNIT_MONSTER, pAiControl->dwAiParam[0]);
        if (!pCurrent || AITHINK_GetSquaredDistance(pUnit, pBeast) <= AITHINK_GetSquaredDistance(pUnit, pCurrent))
        {
            pAiControl->dwAiParam[0] = pBeast->dwUnitId;
        }
    }
    else
    {
        pAiControl->dwAiParam[0] = -1;
    }
}

// 0x005E2BD0
void __fastcall AITHINK_Fn121_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiControl->dwAiParam[1] >= pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        return;
    }

    if (pAiTickParam->nTargetDistance > pMonStatsTxt->wAiParam[3][pGame->nDifficulty])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    D2MinionSpawnerAiCallbackArgStrc arg;
    arg.nMinions = 0;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_MinionSpawner, 1);
    if (pMonStatsTxt->nSkill[0] >= 0 && arg.nMinions < pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
        ++pAiControl->dwAiParam[1];
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
}

// 0x005E8140
void __fastcall D2GAME_AI_SpecialState11_6FCE7E80(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (!STATES_CheckState(pUnit, STATE_TERROR))
    {
        AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, AISPECIALSTATE_NONE);
        AITHINK_IdleInline(pGame, pUnit, 1);
        return;
    }

    int nParam = pAiControl->dwAiParam[0];
    if (!nParam)
    {
        nParam = 30;
    }

    if (nDistance > nParam)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = pAiTickParam->pMonstatsTxt;
    int nVel = 0;
    if (pMonStatsTxtRecord->nVelocity > 0)
    {
        nVel = 100 * pMonStatsTxtRecord->nRun / pMonStatsTxtRecord->nVelocity;
    }

    if (nVel < 100)
    {
        nVel = 0;
    }
    else
    {
        nVel -= 100;
        if (nVel > 120)
        {
            nVel = 120;
        }
    }

    if (!pAiControl->dwAiParam[2])
    {
        pAiControl->dwAiParam[2] = 1;
        sub_00573120_ClearMonsterPair(pUnit);
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
        AITACTICS_SetVelocity(pUnit, 2, nVel, 0);
        if (sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, MONMODE_RUN))
        {
            sub_005DF140_Escape(pGame, pUnit, pTarget, 30, 0);
            return;
        }

        sub_005DEFE0_Escape(pGame, pUnit, pTarget, 30, 0);
        return;
    }

    if (bCombat && !sub_00457490_CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, MONSTATSFLAGINDEX_INTERACT) && sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, MONMODE_ATTACK1))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    AITACTICS_SetVelocity(pUnit, 2, nVel, 0);
    int bResult;
    if (sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, MONMODE_RUN))
    {
        bResult = sub_005DF140_Escape(pGame, pUnit, pTarget, 30, 1);
    }
    else
    {
        bResult = sub_005DEFE0_Escape(pGame, pUnit, pTarget, 30, 1);
    }

    if (!bResult)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
    }
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

    if (sub_006416D0_UnitEdgeDistance(pUnit, pOwner) >= AI_PARAM(pGame, pMonStatsTxt, 4) && D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, 6))
    {
        return;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (!sub_005E45D0(pGame, pUnit, 0, pOwner, 0, pAiTickParam, 0, 6))
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

    if (sub_005E45D0(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 6))
    {
        return;
    }

    if (pTarget)
    {
        if (STATES_CheckState(pTarget, STATE_POISON) || STATLIST_UnitGetStatValue(pTarget, STAT_POISONRESIST, 0) == 100)
        {
            sub_005DEFE0_Escape(pGame, pUnit, pTarget, AI_PARAM(pGame, pMonStatsTxt, 3), 0);
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

// 0x005EFA90
void __fastcall AITHINK_Fn137_PutridDefiler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nDistance = pAiTickParam->nTargetDistance;
    if (pTarget && pAiTickParam->bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    D2PutridDefilerAiCallbackArgStrc arg;
    arg.unk0x00 = 0;
    arg.nMaxDistance = 25;
    D2UnitStrc* pVictim = AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_PutridDefiler, 1);
    if (pVictim)
    {
        if (UNITS_IsInMeleeRange(pUnit, pVictim, 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_SKILL1, SKILL_IMPREGNATE, pVictim, 0, 0);
        }
        else
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pVictim);
        }
        return;
    }

    if (nDistance < AI_GetParamValue(pGame, pMonStatsTxt, 0))
    {
        sub_005DEFE0_Escape(pGame, pUnit, pTarget, AI_GetParamValue(pGame, pMonStatsTxt, 1), 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005FB6C0
void __fastcall AITHINK_Fn078_TrapRightArrow(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (nDistance < AI_PARAM(pGame, pMonStatsTxt, 0) || nDistance > AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
        return;
    }

    D2CoordStrc unitCoords;
    UNITS_GetCoords(pUnit, &unitCoords);
    D2CoordStrc targetCoords;
    UNITS_GetCoords(pTarget, &targetCoords);

    int nDiff = unitCoords.nX - targetCoords.nX;
    if (nDiff < 0)
    {
        nDiff = -nDiff;
    }

    if (nDiff > 2 || pGame->dwGameFrame <= pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 30);
        return;
    }

    pAiControl->dwAiParam[0] = AI_PARAM(pGame, pMonStatsTxt, 2) + pGame->dwGameFrame;
    switch (sub_005FB650_GetTrapArrowVariant(pGame, pUnit))
    {
    case 1:
        break;
    default:
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0)
    {
        pAiControl->dwAiParam[2] = AI_PARAM(pGame, pMonStatsTxt, 3) + pGame->dwGameFrame;
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 30);
}

// 0x005FB7E0
void __fastcall AITHINK_Fn079_TrapLeftArrow(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (nDistance < AI_PARAM(pGame, pMonStatsTxt, 0) || nDistance > AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
        return;
    }

    D2CoordStrc unitCoords;
    UNITS_GetCoords(pUnit, &unitCoords);
    D2CoordStrc targetCoords;
    UNITS_GetCoords(pTarget, &targetCoords);

    int nDiff = unitCoords.nY - targetCoords.nY;
    if (nDiff < 0)
    {
        nDiff = -nDiff;
    }

    if (nDiff > 2 || pGame->dwGameFrame <= pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 30);
        return;
    }

    pAiControl->dwAiParam[0] = AI_PARAM(pGame, pMonStatsTxt, 2) + pGame->dwGameFrame;
    switch (sub_005FB650_GetTrapArrowVariant(pGame, pUnit))
    {
    case 1:
        break;
    default:
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0)
    {
        pAiControl->dwAiParam[2] = AI_PARAM(pGame, pMonStatsTxt, 3) + pGame->dwGameFrame;
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 30);
}

// 0x005F9E30
int __fastcall sub_005F9E30_VileMotherSpawnDirection(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonStatsTxt* pMonStatsTxt)
{
    unsigned char nIndex = UNITS_GetDirectionToCoords(pUnit, CLIENTS_GetUnitXInline(pTarget), CLIENTS_GetUnitYInline(pTarget));
    nIndex = sub_0063E7A0_GetByteTableEntry(nIndex);
    const unsigned char nIndices[8] = { 6, 4, 2, 2, 2, 0, 6, 6 };

    for (int i = 0; i < 8; ++i)
    {
        nIndex = nIndex % 8;

        int nX;
        int nY;
        sub_0063E7E0_GetDirectionDelta(nIndices[nIndex], &nX, &nY);

        const int nFinalX = 3 * nX + CLIENTS_GetUnitXInline(pUnit);
        const int nFinalY = 3 * nY + CLIENTS_GetUnitYInline(pUnit);
        const int nMonsterId = sub_004E6C50_ValidateMonsterId(MONSTER_VILEMOTHER1);
        if (pMonStatsTxt->nSkill[0] >= 0 && sub_6FC68350(nMonsterId, UNITS_GetRoom(pUnit), nFinalX, nFinalY, 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, nFinalX, nFinalY);
            return 1;
        }

        ++nIndex;
    }

    return 0;
}
