#include "D2Game.h"
#include "D2Structs.h"

#include "D2LevelTxt.h"
struct D2MonStatsTxt;
struct D2LevelsTxt;
struct D2PantherAiCallbackArgStrc;
struct D2AiCallback11ArgStrc;


void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    unsigned int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2PantherAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
};

struct D2AiCallback11ArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    D2UnitStrc* unk0x08;
    int unk0x0C[7];
};

typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0
int __fastcall sub_005B1140_BossTauntOnSight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B1140
int __fastcall sub_005B11F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B11F0
int __fastcall sub_005DC640_HasFreeSpotNearTarget(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005DC640
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AITARGETCALLBACK pfnCallback, int nCallbackId); // 0x005DD0B0
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40

// 0x005B0CD0
void __fastcall AITHINK_Fn001_100_Idle_Buffy(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (UNITS_GetRoom(pUnit))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 200);
    }
}

// 0x005B0D00
D2UnitStrc* __fastcall AITHINK_TargetCallback_Panther(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2PantherAiCallbackArgStrc* pArg = (D2PantherAiCallbackArgStrc*)pCallbackArg;

    if (!pTarget || pTarget->dwUnitType != UNIT_MONSTER || pUnit == pTarget)
    {
        return 0;
    }

    if (sub_00463860(pUnit) != sub_00463860(pTarget) || MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance >= pArg->nDistance)
    {
        return 0;
    }

    pArg->pTarget = pTarget;
    pArg->nDistance = nDistance;
    return 0;
}

// 0x005B13E0
int __fastcall sub_005B13E0_AiMeleeWalkTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (!pAiTickParam->pTarget)
    {
        return 0;
    }

    if (sub_005B1140_BossTauntOnSight(pGame, pUnit, pAiTickParam))
    {
        return 1;
    }

    if (sub_005B11F0(pGame, pUnit, pAiTickParam))
    {
        return 1;
    }

    if (!sub_00457490_CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, 1))
    {
        return 0;
    }

    if (!sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 2))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nMonSpcWalk = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom))->nMonSpcWalk;
    if (nMonSpcWalk <= 0 || pAiTickParam->nTargetDistance <= nMonSpcWalk)
    {
        return 0;
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (sub_005DC640_HasFreeSpotNearTarget(pUnit, pTarget))
    {
        return 0;
    }

    D2AiCallback11ArgStrc arg;
    arg.pTarget = 0;
    arg.nDistance = 0x7FFFFFFF;
    arg.unk0x08 = pTarget;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 11);

    if (!arg.pTarget)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
        return 1;
    }

    pAiTickParam->pTarget = arg.pTarget;
    pAiTickParam->nTargetDistance = arg.nDistance;
    return 0;
}
