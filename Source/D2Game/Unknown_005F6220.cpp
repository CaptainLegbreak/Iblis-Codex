#include "D2StateIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2ItemsWorld.h"
#include "D2GameStrc.h"
#include "D2MonModes.h"

struct D2MephistoAiCallbackArgStrc
{
    D2UnitStrc* unk0x00;
    int unk0x04;
    int unk0x08;
    D2UnitStrc* unk0x0C;
    int unk0x10;
    D2UnitStrc* unk0x14;
    int unk0x18;
    int nCounter;
    int unk0x20;
    int unk0x24;
};

enum D2C_J11AiConstants
{
    LEVEL_AI_TRAPARROW_RANDOM = 40,
    UNITFLAG_J11_SPAWNED = 0x4000000,
    STATE_J11_SPAWNED = 184,
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax);                                       // 0x004BC500
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall AITACTICS_WalkToTargetWithPathType13(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40
D2UnitStrc* __fastcall AITHINK_TargetCallback_Mephisto(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F7700
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    return (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100;
}

static short AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_ROLL_PERCENT(pUnit) ((int)((unsigned int)SEED_RollRandomNumber(&(pUnit)->pSeed) % 100))

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005F7F10
void __fastcall sub_005F7F10_SpawnRandomMinion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner)
{
    const int nX = UNITS_GetUnitXPosition(pUnit);
    const int nY = UNITS_GetUnitYPosition(pUnit);
    int nMonsterIds[8] = { 725, 725, 726, 726, 727, 728, 729, 730 };
    int nModes[8] = { 8, 8, 8, 8, 8, 8, 8, 8 };
    const int nIndex = (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) & 7;
    D2UnitStrc* pMonster;
    if (pOwner)
    {
        pMonster = MONSTERSPAWN_SpawnAtUnit(pGame, pOwner, nMonsterIds[nIndex], nModes[nIndex], 4, 0);
    }
    else
    {
        pMonster = MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, nMonsterIds[nIndex], nModes[nIndex], 4, 0);
    }
    if (pMonster)
    {
        pMonster->dwFlags |= UNITFLAG_J11_SPAWNED;
        STATES_ToggleState(pMonster, STATE_J11_SPAWNED, 1);
    }
}

// 0x005FB650
int __fastcall sub_005FB650_GetTrapArrowVariant(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, nLevelId);
    if (pMonsterRegion->nTrapVariant < 0)
    {
        if (nLevelId < LEVEL_AI_TRAPARROW_RANDOM)
        {
            pMonsterRegion->nTrapVariant = 0;
        }
        else
        {
            pMonsterRegion->nTrapVariant = OBJECTS_RollRandomNumber(&pUnit->pSeed, 0, 3);
        }
    }
    return pMonsterRegion->nTrapVariant;
}
