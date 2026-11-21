#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2MonModes.h"

struct D2VileMotherAiCallbackArgStrc
{
    int nLastInClass;
    int nMaxDistance;
    int nCounter;
    int unk0x0C[7];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

enum D2C_M101VileMotherConstants
{
    UNIT_ALIGNMENT_EVIL = 0,
    MONSTER_VILECHILD1 = 301,
};

enum D2C_VileMotherAIParams
{
    VILEMOTHER_AI_PARAM_MAX_SPAWN = 0,
    VILEMOTHER_AI_PARAM_MAX_AT_ONCE = 1,
    VILEMOTHER_AI_PARAM_SPAWN_CHANCE_PCT = 2,
    VILEMOTHER_AI_PARAM_ATTACK_CHANCE_PCT = 3,
    VILEMOTHER_AI_PARAM_APPROACH_CHANCE_PCT = 4,
    VILEMOTHER_AI_PARAM_CIRCLE_CHANCE_PCT = 5,
    VILEMOTHER_AI_PARAM_STALL_DURATION = 6,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall SKILLS_GetMonsterClassFromChain(int nMonsterId, int nNoInChain);                             // 0x0054DA60
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
int __fastcall sub_005F9E30_VileMotherSpawnDirection(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonStatsTxt* pMonStatsTxt); // 0x005F9E30
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId);                // 0x006510C0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollSeedUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005FA010
void __fastcall AITHINK_Fn068_VileMother(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    const int nMonstersInChain = DATATBLS_GetMonsterChainInfo(nClassId, 0, 0);
    const int nLastInClass = SKILLS_GetMonsterClassFromChain(sgptDataTables->nMonStatsTxtRecordCount <= MONSTER_VILECHILD1 ? -1 : MONSTER_VILECHILD1, nMonstersInChain);

    if (pAiControl->dwAiParam[0] < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_MAX_SPAWN) && STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL
        && (int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_SPAWN_CHANCE_PCT))
    {
        D2VileMotherAiCallbackArgStrc arg;
        arg.nLastInClass = nLastInClass;
        arg.nMaxDistance = 25;
        arg.nCounter = 0;
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 12);

        if (arg.nCounter < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_MAX_AT_ONCE) && sub_005F9E30_VileMotherSpawnDirection(pGame, pUnit, pTarget, pMonStatsTxt))
        {
            ++pAiControl->dwAiParam[0];
            return;
        }
    }

    if (bCombat)
    {
        if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_STALL_DURATION));
        return;
    }

    if (pAiControl->dwAiParam[0] >= AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_MAX_SPAWN) || (int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_CIRCLE_CHANCE_PCT))
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}
