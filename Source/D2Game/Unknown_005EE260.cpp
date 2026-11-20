#include "D2Structs.h"
#ifdef MOVED_TEST
#define ATTACK_MODE 6
#define IDLE_FRAMES 17
#else
#define ATTACK_MODE 4
#define IDLE_FRAMES 15
#endif


struct D2GameStrc
{
#ifdef MOVED_TEST
    int moved_prefix;
#endif
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
#ifdef MOVED_TEST
    int moved_prefix;
#endif
    char unk0x00[0x56];
    short wAiParam[8][3];
    char unk0x86[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
};

struct D2AiTickParamStrc
{
#ifdef MOVED_TEST
    int moved_prefix;
#endif
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static int AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

// 0x005EE260
void __fastcall sub_005EE260_Think(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2MonStatsTxt* pStats = pTick->pMonstatsTxt;
    D2UnitStrc* pTarget = pTick->pTarget;
    int nTargetDistance = pTick->nTargetDistance;
    if (pTick->bCombat)
    {
        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pStats, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, ATTACK_MODE, pTarget);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, IDLE_FRAMES);
        }
        return;
    }
    else
    {
        if (pStats->nSkill[0] >= 0 && nTargetDistance < AI_GetParam(pGame, pStats, 2)
            && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pStats, 3))
        {
            AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pTarget, 0, 0);
            return;
        }
        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pStats, 1))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, IDLE_FRAMES);
}
