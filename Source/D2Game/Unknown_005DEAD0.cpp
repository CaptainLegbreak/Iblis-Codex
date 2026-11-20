#include "D2Game.h"
#include "D2Structs.h"

#define UNIT_INVALID 6
#define UNIT_MONSTER 1
#define MONMODE_WALK 2
#define MONMODE_RUN 15
#define STATE_DECREPIFY 60
#define EVENTTYPE_AITHINK 2
struct D2ModeChangeStrc;
struct D2SeedStrc;
struct D2MonsterDataStrc;

enum D2C_Y10UseSkillConstants
{
    UNITFLAG_SKSRVDOFUNC = 0x40,
};



struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps); // 0x00649070
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(D2UnitStrc* pUnit); // 0x005A61F0
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance); // 0x005DE200
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

// 0x005DEAD0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY)
{
    if (nMode >= 16)
    {
        return 0;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    UNITS_SetUsedSkill(pUnit, SKILLS_GetSkillById(pUnit, nSkillId, -1));

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    PATH_SetStepNum(pUnit->pDynamicPath, 1);

    modeChange.pTargetUnit = pTarget;
    modeChange.nX = nX;
    modeChange.nY = nY;

    if (D2GAME_ModeChange_6FC65220(pGame, &modeChange, 0))
    {
        return 1;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    return 0;
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline int AI_RollPercentage(D2UnitStrc* pUnit)
{
    return (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100;
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x005DEB60
int __fastcall AITACTICS_MoveToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int nX, int nY, unsigned char bStep, unsigned char nFlags)
{
    int nNewMode = nMode;

    if (nMode == MONMODE_RUN && STATES_CheckState(pUnit, STATE_DECREPIFY))
    {
        D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(pUnit);
        nNewMode = MONMODE_WALK;
    }

    PATH_SetStepNum(pUnit->pDynamicPath, bStep);

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nNewMode, &modeChange);

    if (pTarget)
    {
        modeChange.pTargetUnit = pTarget;
    }
    else
    {
        modeChange.nX = nX;
        modeChange.nY = nY;
    }

    int nResult = D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    if (!nResult)
    {
        if (nFlags & 4)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
        }

        if (nFlags & 1)
        {
            D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
            if (pAiControl)
            {
                AIUTIL_ToggleAiControlFlag(pAiControl, 0x40, 1);
            }
        }

        if (nFlags & 2)
        {
            nResult = 1;
            if (AI_RollPercentage(pUnit) < 70)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
        }
    }

    return nResult;
}
