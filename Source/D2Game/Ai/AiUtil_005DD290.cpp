#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"

enum
{
};

enum
{
    PLRMODE_DEATH = 0,
    PLRMODE_DEAD = 17,
};

enum
{
    MONMODE_DEATH = 0,
    MONMODE_DEAD = 12,
};








extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);      // 0x00622AA0
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);       // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00553010
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                     // 0x00554200
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                         // 0x005DE0F0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall COLLISION_ResetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);          // 0x0064CBE0
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

static __forceinline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
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

// 0x005DD290
int __fastcall sub_005DD290_NoMissileBarrierCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    return UNITS_TestCollisionWithUnit(pUnit, pTarget, 4) == 0;
}

// 0x005DD2B0
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit)
{
    const unsigned int nAiState = MONSTER_GetAiState(pUnit);
    return nAiState == 3 || nAiState == 19;
}

// 0x005DD2D0
int __fastcall AIUTIL_CheckIfMonsterUsesSkill(D2UnitStrc* pUnit, int nSkillId)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (nType == UNIT_MONSTER)
    {
        pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    for (int i = 0; i < 8; ++i)
    {
        if (pMonStatsTxtRecord->nSkill[i] == nSkillId)
        {
            return 1;
        }
    }

    return 0;
}

// 0x005DDFC0
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY)
{
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005DE830
D2UnitStrc* __fastcall AITACTICS_GetTargetMinion(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = SUNIT_GetLastAttacker(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    switch (pTarget->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pTarget->dwAnimMode == PLRMODE_DEATH || pTarget->dwAnimMode == PLRMODE_DEAD)
        {
            return 0;
        }
        return pTarget;

    case UNIT_MONSTER:
        if (pTarget->dwAnimMode == MONMODE_DEATH || pTarget->dwAnimMode == MONMODE_DEAD)
        {
            return 0;
        }
        return SUNIT_AreUnitsHostile(pGame, pUnit, pTarget) ? pTarget : 0;

    default:
        return 0;
    }
}

// 0x005E6800
bool __fastcall sub_005E6800_InitHomeCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pAiTickParam)
{
    D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
    if (pAiCmd && !pAiCmd->nCmdParam[1] && !pAiCmd->nCmdParam[2])
    {
        pAiCmd->nCmdParam[1] = CLIENTS_GetUnitX(pUnit);
        pAiCmd->nCmdParam[2] = CLIENTS_GetUnitY(pUnit);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return true;
    }

    return false;
}

// 0x005F2EB0
void __fastcall sub_005F2EB0_RemoveGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFF1;
    }

    COLLISION_ResetMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0x1000);
    COLLISION_ResetMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0x100);
    sub_00649190_SetPathMode(pUnit, 5);
    PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0);
    AITACTICS_Idle(pGame, pUnit, 12);
}

// 0x005F2FC0
int __fastcall AITHINK_TryRestoreGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0xE;
    }

    if (PATH_GetUnitCollisionPattern(pUnit) != 1)
    {
        if (!sub_6FCBDFE0(pGame, pUnit, UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 0))
        {
            return 0;
        }

        COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 1, 0x100);
        sub_00649190_SetPathMode(pUnit, 1);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0x3C01);
        AITACTICS_Idle(pGame, pUnit, 12);
        return 1;
    }

    return 0;
}
