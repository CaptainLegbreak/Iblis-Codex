#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Txt.h"



struct D2MonsterRegionStrc
{
    char unk0x000[0x2D4];
    int nTrapVariant;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
    char unk0xAC[0x44];
    D2MonsterRegionStrc* pMonReg[1];
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
};



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
    MONMODE_ATTACK1 = 4,
    MONMODE_SKILL1 = 8,
    LEVEL_AI_TRAPARROW_RANDOM = 40,
    UNITFLAG_J11_SPAWNED = 0x4000000,
    STATE_J11_SPAWNED = 184,
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax);                                       // 0x004BC500
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall sub_6FCD0410(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40
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

// 0x005F6220
void __fastcall AITHINK_Fn038_MaggotLarva(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiTickParam->bCombat)
    {
        if (pAiControl->dwAiParam[0] || AI_RollPercentage(pUnit) >= AI_GetParam(pGame, pMonStatsTxt, 0))
        {
            pAiControl->dwAiParam[0] = 0;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 1));
        }
        else
        {
            pAiControl->dwAiParam[0] = 1;
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        return;
    }

    pAiControl->dwAiParam[0] = 0;
    if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 2))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 1);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 3));
}

// 0x005F77C0
D2UnitStrc* __fastcall AITHINK_FindTargetForMephisto(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pFallbackTarget)
{
    D2MephistoAiCallbackArgStrc arg = {};
    arg.unk0x04 = 0x7FFFFFFF;
    arg.unk0x10 = 0x7FFFFFFF;
    arg.unk0x18 = 0x7FFFFFFF;

    sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_Mephisto, 1);

    if (arg.unk0x0C && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxtRecord, 1))
    {
        return arg.unk0x0C;
    }

    if (arg.unk0x14 && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxtRecord, 2))
    {
        return arg.unk0x0C;
    }

    return pFallbackTarget;
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
        pMonster = sub_6FC68D70(pGame, pOwner, nMonsterIds[nIndex], nModes[nIndex], 4, 0);
    }
    else
    {
        pMonster = sub_6FC68D70(pGame, pUnit, nMonsterIds[nIndex], nModes[nIndex], 4, 0);
    }
    if (pMonster)
    {
        pMonster->dwFlags |= UNITFLAG_J11_SPAWNED;
        STATES_ToggleState(pMonster, STATE_J11_SPAWNED, 1);
    }
}

// 0x005FAA90
void __fastcall AITHINK_Fn072_DoomKnight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiTickParam->bCombat)
    {
        if (AI_ROLL_PERCENT(pUnit) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
        return;
    }

    if (AI_ROLL_PERCENT(pUnit) < AI_PARAM(pGame, pMonStatsTxt, 2))
    {
        sub_6FCD0410(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
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

// 0x005FBA60
void __fastcall AITHINK_Fn087_TrapMelee(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 1));
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
}
