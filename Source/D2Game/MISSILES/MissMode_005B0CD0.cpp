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
int __fastcall AITHINK_TryBossTauntOnSight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B1140
int __fastcall AITHINK_TryTeleportAway(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B11F0
int __fastcall AIUTIL_HasClearApproachToTarget(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005DC640
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AITARGETCALLBACK pfnCallback, int nCallbackId); // 0x005DD0B0
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40

// 0x005B13E0
int __fastcall AITHINK_HandleMonsterAiPreActions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (!pAiTickParam->pTarget)
    {
        return 0;
    }

    if (AITHINK_TryBossTauntOnSight(pGame, pUnit, pAiTickParam))
    {
        return 1;
    }

    if (AITHINK_TryTeleportAway(pGame, pUnit, pAiTickParam))
    {
        return 1;
    }

// build: symbol ?MONSTERUNIQUE_CheckMonStatsFlag@* 0x00457490
    if (!MONSTERUNIQUE_CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, 1))
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
    if (AIUTIL_HasClearApproachToTarget(pUnit, pTarget))
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
