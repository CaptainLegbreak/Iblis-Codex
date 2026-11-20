#include "D2Game.h"
#include "D2Structs.h"

struct D2AiTableStrc;
struct D2MonStatsTxt;
struct D2MonsterDataStrc;
struct D2AiStateStrc;


struct D2AiControlStrc
{
    int nAiSpecialState;
    unsigned char unk_04[0x8];
    int nOwnerGUID;
    int nOwnerType;
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    int unk_04;
    D2UnitStrc* pTarget;
    int unk_0C[2];
    int nTargetDistance;
    int bCombat;
};

int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int, int); // 0x0046C140
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
int __fastcall SUNIT_IsDead(D2UnitStrc*); // 0x005541B0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*, D2UnitStrc*); // 0x005DC380
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DEFE0
void __fastcall AITACTICS_SetVelocity(D2UnitStrc*, int, int, unsigned char); // 0x005DE190
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x005DF530

struct D2AiTableStrc { int a, b, c, d; };

struct D2MonStatsTxt { char pad[0x1E]; unsigned short wAI; };

struct D2MonsterDataStrc { D2MonStatsTxt* pMonStatsTxt; };
extern const D2AiTableStrc gpAiTable_6FD3F990[148]; // 0x0073CA18

struct D2AiStateStrc { int nTargetMode; };

D2AiStateStrc* __fastcall sub_005B15D0_GetAiState(D2UnitStrc*, int); // 0x005B15D0
D2UnitStrc* __fastcall sub_6FCCF9D0(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DE890
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DD7F0
D2UnitStrc* __fastcall sub_005DE9D0_FindTarget(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DE9D0

static __forceinline int CanWalk(D2UnitStrc* pMonster)
{
    return sub_0046C140_CheckMonStats2ModeFlag(!pMonster ? -1 : pMonster->dwClassId, 2);
}

// 0x005B0FF0
int __fastcall D2GAME_AICORE_MinionLeash_6FCF0D10(D2GameStrc* pGame, D2UnitStrc* pMonster, D2AiTickParamStrc* pAiTickParam)
{
    int nOwnerGUID = 0;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    nOwnerGUID = *(volatile int*)&pAiControl->nOwnerGUID;
    if (nOwnerGUID == -1)
        return 0;
    if (!CanWalk(pMonster))
    {
        pAiControl->nOwnerGUID = -1;
        return 0;
    }
    nOwnerGUID = pAiControl->nOwnerGUID;
    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, !pAiControl ? 6 : pAiControl->nOwnerType, nOwnerGUID);
    if (!pOwner)
    {
        (*(D2AiControlStrc* volatile*)&pAiControl)->nOwnerGUID = -1;
        return 0;
    }
    if (SUNIT_IsDead(pOwner))
    {
        (*(D2AiControlStrc* volatile*)&pAiControl)->nOwnerGUID = -1;
        return 0;
    }
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pMonster, pOwner);
    if (nDistance <= 1 && (*(D2AiControlStrc* volatile*)&pAiControl)->nOwnerType == 0)
    {
        if (D2GAME_AICORE_Escape_6FCD0560(pGame, pMonster, pOwner, 19, 1))
            return 1;
    }
    else
    {
        if (nDistance <= 20)
            return 0;
        AITACTICS_SetVelocity(pMonster, 7, 0, 40);
    }
    D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pMonster, pOwner, 19);
    return 1;
}

static __forceinline D2MonStatsTxt* GetRec(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData) {
        return pUnit->pMonsterData->pMonStatsTxt;
    }
    return 0;
}

static __forceinline const D2AiTableStrc* GetByIndex(D2MonStatsTxt* pRecord)
{
    short nIndex = pRecord->wAI;
    if (nIndex >= 0 && (unsigned short)nIndex < 148) {
        return &gpAiTable_6FD3F990[nIndex];
    }
    return &gpAiTable_6FD3F990[0];
}

// 0x005B15D0
const D2AiTableStrc* __fastcall sub_005B15D0_GetAiTable(D2UnitStrc* pUnit, int nMode)
{
    D2MonStatsTxt* pRecord = GetRec(pUnit);
    if (nMode) {
        if (nMode == 10 || nMode == 11 || nMode == 12) {
            if (!UNITS_CanSwitchAI(!pUnit ? -1 : pUnit->dwClassId)) {
                return GetByIndex(pRecord);
            }
        }
        return &gpAiTable_6FD3F990[148 + nMode];
    }
    return GetByIndex(pRecord);
}

#include "gen/data/Source/D2Game/Unknown_005B0FF0.inc"

// 0x005B1650
int __fastcall sub_005B1650_AiTickTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const D2AiControlStrc* v_pAiControl_22 = pAiTickParam->pAiControl;
    D2AiStateStrc* pState = sub_005B15D0_GetAiState(pUnit, v_pAiControl_22->nAiSpecialState);
    switch (pState->nTargetMode)
    {
    case 0:
        return 0;
    case 1:
        pAiTickParam->pTarget = sub_6FCCF9D0(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return pAiTickParam->pTarget == 0;
    case 2:
        pAiTickParam->pTarget = sub_6FCF2110(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return 0;
    case 4:
        pAiTickParam->pTarget = sub_005DE9D0_FindTarget(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return pAiTickParam->pTarget == 0;
    case 5:
        pAiTickParam->pTarget = sub_005DE9D0_FindTarget(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return 0;
    default:
        return 1;
    }
}
