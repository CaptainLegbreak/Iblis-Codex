#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2ItemsWorld.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

struct D2MonStatsTxt;

struct D2MonsterDataStrc;

struct D2VileMotherAiCallbackArgStrc;

struct D2PartyCallbackArgStrc;

struct D2CurseStrc;

struct D2UnkAiTableStrc;

enum D2C_F41AiUtilConstants
{
    UNITFLAG_CANBEATTACKED = 4,
    MONTYPEFLAG_UNIQUE_SUPERUNIQUE = 10,
    STATE_UNINTERRUPTABLE = 54,
    STATE_TERROR = 56,
    SKILL_TERROR = 77,
    AISPECIALSTATE_TERROR = 11,
    EVENTTYPE_AITHINK = 2,
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2VileMotherAiCallbackArgStrc
{
    int nLastInClass;
    int nMaxDistance;
    int nCounter;
};

struct D2PartyCallbackArgStrc
{
    AIUTIL_TargetCallback pfCallback;
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    void* unk0x0C;
};

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

int __fastcall AITHINK_CanUnitSwitchAi(D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxtRecord, int nAiSpecialState, int bCheckIfSuperUnique); // 0x005B0DA0

D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

struct D2UnkAiTableStrc
{
    int nType;
    AIUTIL_TargetCallback pfCallback;
};

extern const D2UnkAiTableStrc gAiTargetSearchTable_006E3300[]; // 0x006E3300

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* a2, void* a3, void(__fastcall* pfnParty)(D2UnitStrc*, void*, void*)); // 0x0058F380

void __fastcall sub_6FCF20E0(D2UnitStrc* pUnit, void* pArg, void* ppUnit); // 0x005DD020

D2UnitStrc* __stdcall sub_005DCEE0_FindPlayerTargetInAdjacentRooms(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfCallback); // 0x005DCEE0

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

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

void __stdcall COLLISION_ResetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);          // 0x0064CBE0

void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180

void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0

int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

// 0x005DCE10
D2UnitStrc* __fastcall sub_6FCF1E30(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2VileMotherAiCallbackArgStrc* pArg = (D2VileMotherAiCallbackArgStrc*)pCallbackArg;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pTarget->dwClassId != pArg->nLastInClass)
    {
        return 0;
    }

    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    if (AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    pArg->nCounter += 1;
    return 0;
}

// 0x005DCE60
static D2UnitStrc* __stdcall AIUTIL_FindTargetInAdjacentRooms(D2GameStrc* pGame, void* pCallbackArg, AIUTIL_TargetCallback pfCallback, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pTarget = ppRoomList[i]->pUnitFirst; pTarget; pTarget = pTarget->ptRoomNext)
        {
            D2UnitStrc* pResult = pfCallback(pGame, pUnit, pTarget, pCallbackArg);
            if (pResult)
            {
                return pResult;
            }
        }
    }

    return 0;
}

// 0x005DCEE0
D2UnitStrc* __stdcall sub_005DCEE0_FindPlayerTargetInAdjacentRooms(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfCallback)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        const unsigned int nNumClients = ppRoomList[i]->nNumClients;
        D2ClientStrc** ppClients = ppRoomList[i]->ppClients;
        for (unsigned int j = 0; j < nNumClients; ++j)
        {
            D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(ppClients[j], 0);
            if (pPlayer)
            {
                D2UnitStrc* pTarget = pfCallback(pGame, pUnit, pPlayer, pCallbackArg);
                if (pTarget)
                {
                    return pTarget;
                }
            }
        }
    }

    return 0;
}

// 0x005DD020
void __fastcall sub_6FCF20E0(D2UnitStrc* pUnit, void* pArg, void* ppUnit)
{
    D2PartyCallbackArgStrc* pPartyCallbackArg = (D2PartyCallbackArgStrc*)pArg;
    D2UnitStrc** ppResult = (D2UnitStrc**)ppUnit;
    if (*ppResult)
    {
        return;
    }

    D2GameStrc* pGame = pPartyCallbackArg->pGame;
    D2UnitStrc* pOwner = pPartyCallbackArg->pUnit;
    AIUTIL_TargetCallback pfCallback = pPartyCallbackArg->pfCallback;
    void* pCallbackArg = pPartyCallbackArg->unk0x0C;
    D2UnitStrc* pResult = pfCallback(pGame, pOwner, pUnit, pCallbackArg);
    if (pResult)
    {
        *ppResult = pResult;
    }
}

static D2UnitStrc* __stdcall AIUTIL_FindTargetInAdjacentActiveRooms(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfCallback)
{
    if (!pUnit || pUnit->dwUnitType < 0 || pUnit->dwUnitType > 1)
    {
        return 0;
    }

    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    unsigned int nNumRooms;
    D2ActiveRoomStrc** ppRoomList;
    unsigned int i;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (i = 0; i < nNumRooms; ++i)
    {
        if (!DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            D2ActiveRoomStrc* pAdjacentRoom = ppRoomList[i];
            if (pAdjacentRoom->nNumClients)
            {
                for (D2UnitStrc* pTarget = pAdjacentRoom->pUnitFirst; pTarget; pTarget = pTarget->ptRoomNext)
                {
                    D2UnitStrc* pResult = pfCallback(pGame, pUnit, pTarget, pCallbackArg);
                    if (pResult)
                    {
                        return pResult;
                    }
                }
            }
        }
    }

    return 0;
}

// 0x005DD050
static D2UnitStrc* __stdcall sub_005DD050_FindTargetAmongMinions(D2GameStrc* pGame, void* pCallbackArg, AIUTIL_TargetCallback pfCallback, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return 0;
    }

    if (pOwner->dwUnitType != 1)
    {
        return 0;
    }

    D2UnitStrc* pTarget = 0;
    D2PartyCallbackArgStrc partyCallbackArg;
    partyCallbackArg.pfCallback = pfCallback;
    partyCallbackArg.pGame = pGame;
    partyCallbackArg.pUnit = pUnit;
    partyCallbackArg.unk0x0C = pCallbackArg;

    AIGENERAL_ExecuteCallbackOnMinions(pOwner, &partyCallbackArg, &pTarget, sub_6FCF20E0);
    return pTarget;
}

D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId)
{
    AIUTIL_TargetCallback pfCallback = gAiTargetSearchTable_006E3300[nCallbackId].pfCallback;
    if (!pfCallback)
    {
        pfCallback = a4;
        if (!a4)
        {
            return 0;
        }
    }

    const int nType = gAiTargetSearchTable_006E3300[nCallbackId].nType;
    switch (nType)
    {
    case 1:
        return sub_005DCEE0_FindPlayerTargetInAdjacentRooms(pGame, pUnit, a3, pfCallback);
    case 2:
        return AIUTIL_FindTargetInAdjacentActiveRooms(pGame, pUnit, a3, pfCallback);
    case 3:
        return sub_005DD050_FindTargetAmongMinions(pGame, a3, pfCallback, pUnit);
    default:
        return AIUTIL_FindTargetInAdjacentRooms(pGame, a3, pfCallback, pUnit);
    }
}

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

// 0x005DDD00
void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nParam1, int nDuration)
{
    if (SUNIT_IsDead(pTarget))
    {
        return;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    if (STATES_CheckState(pTarget, STATE_UNINTERRUPTABLE))
    {
        return;
    }

    if (!UNITS_CanSwitchAI(pTarget->dwClassId))
    {
        return;
    }

    if (!sub_00451F30_TestUnitFlag(pTarget, UNITFLAG_CANBEATTACKED) && !SUNIT_IsDead(pTarget))
    {
        return;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE_SUPERUNIQUE))
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
    if (!AITHINK_CanUnitSwitchAi(pTarget, pMonStatsTxtRecord, AISPECIALSTATE_TERROR, 1))
    {
        return;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pTarget;
    curse.nSkillLevel = 1;
    curse.nDuration = nDuration;
    curse.nStat = -1;
    curse.nSkill = SKILL_TERROR;
    curse.nState = STATE_TERROR;
    sub_0056E970(&curse);

    UNITS_SetTargetUnitForDynamicUnit(pTarget, pUnit);

    D2AiControlStrc* pAiControl = (pTarget->dwUnitType == UNIT_MONSTER && pTarget->pMonsterData) ? pTarget->pMonsterData->pAiControl : 0;
    AITHINK_ExecuteAiFn(pGame, pTarget, pAiControl, AISPECIALSTATE_TERROR);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pTarget, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pTarget, EVENTTYPE_AITHINK, pGame->dwGameFrame + 1, 0, 0);
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

#include "gen/data/Source/D2Game/Ai/AiUtil_005DCE10.inc"
