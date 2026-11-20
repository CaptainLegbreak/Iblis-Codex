#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#ifdef MOVED_TEST
#define MON_FLAG 11
#define ATTACK_MODE 6
#define WALK_CHANCE 22
#define WALK_DISTANCE 5
#define IDLE_FRAMES 12
#else
#define MON_FLAG 9
#define ATTACK_MODE 4
#define WALK_CHANCE 20
#define WALK_DISTANCE 3
#define IDLE_FRAMES 10
#endif
struct D2GameStrc;
struct D2AiControlStrc;
struct D2MonStats2Txt;
struct D2MissilesTxt;





int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance);  // 0x005DE200
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode);
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268
static __forceinline D2MonStatsTxt* MonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline unsigned int CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MonStatsTxtRecord(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
    }
    return 0;
}

static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005E8020
void __fastcall sub_005E8020_Think(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2UnitStrc* pTarget = pTick->pTarget;
    if (pTick->bCombat && !CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, MON_FLAG)
        && sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, ATTACK_MODE))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, ATTACK_MODE, pTarget);
        return;
    }
    if (AI_RollPercentage(pUnit) < WALK_CHANCE)
        AITACTICS_WalkCloseToUnit(pGame, pUnit, WALK_DISTANCE);
    else
        AITACTICS_IdleInNeutralMode(pGame, pUnit, IDLE_FRAMES);
}
