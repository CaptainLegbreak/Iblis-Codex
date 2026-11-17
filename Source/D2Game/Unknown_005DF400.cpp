#include "D2Game.h"

#define UNIT_INVALID 6
#define UNIT_MONSTER 1
#define MONMODE_WALK 2
#define MONMODE_RUN 15
#define STATE_DECREPIFY 60
#define EVENTTYPE_AITHINK 2
struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2MonsterDataStrc;
struct D2ModeChangeStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
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

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(D2UnitStrc* pUnit); // 0x005A61F0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance); // 0x005DE200
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps); // 0x00649070

// build: context CLIENTS_GetUnitXInline
static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

// build: context CLIENTS_GetUnitYInline
static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// build: context SEED_RollRandomNumber
inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 nValue = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nValue >> 32);
    pSeed->nLowSeed = (unsigned int)nValue;
    return (unsigned int)nValue;
}

// build: context AI_RollPercentage
inline int AI_RollPercentage(D2UnitStrc* pUnit)
{
    return SEED_RollRandomNumber(&pUnit->pSeed) % 100;
}

// build: context AIGENERAL_GetAiControlFromUnit
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

    if (nNewMode == MONMODE_RUN && STATES_CheckState(pUnit, STATE_DECREPIFY))
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

// 0x005DF400
int __fastcall AITACTICS_WanderToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance)
{
    int nTargetX = CLIENTS_GetUnitXInline(pUnit);
    int nTargetY = CLIENTS_GetUnitYInline(pUnit);

    int nOffsetX;
    int nOffsetY;

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (SEED_RollRandomNumber(pSeed) & 1)
    {
        nOffsetX = nMaxDistance;
        nOffsetY = ITEMS_RollLimitedRandomNumber(pSeed, nMaxDistance);
    }
    else
    {
        nOffsetX = ITEMS_RollLimitedRandomNumber(pSeed, nMaxDistance);
        nOffsetY = nMaxDistance;
    }

    if (SEED_RollRandomNumber(pSeed) & 1)
    {
        nOffsetX = -nOffsetX;
    }

    if (SEED_RollRandomNumber(pSeed) & 1)
    {
        nOffsetY = -nOffsetY;
    }

    nTargetX += nOffsetX;
    nTargetY += nOffsetY;

    return AITACTICS_MoveToTarget(pGame, pUnit, 0, MONMODE_WALK, nTargetX, nTargetY, 1, 0);
}

// 0x005DF530
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, unsigned char nMaxDistance)
{
    if (!pOwner)
    {
        return AITACTICS_WalkCloseToUnit(pGame, pUnit, 2);
    }

    int nOffsetX = 0;
    int nOffsetY = 0;

    int nTargetX = CLIENTS_GetUnitXInline(pOwner);
    int nTargetY = CLIENTS_GetUnitYInline(pOwner);

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (SEED_RollRandomNumber(pSeed) & 1)
    {
        nOffsetX = nMaxDistance;
        nOffsetY = ITEMS_RollLimitedRandomNumber(pSeed, nMaxDistance);
    }
    else
    {
        nOffsetX = ITEMS_RollLimitedRandomNumber(pSeed, nMaxDistance);
        nOffsetY = nMaxDistance;
    }

    if (SEED_RollRandomNumber(pSeed) & 1)
    {
        nOffsetX = -nOffsetX;
    }

    if (SEED_RollRandomNumber(pSeed) & 1)
    {
        nOffsetY = -nOffsetY;
    }

    nTargetX += nOffsetX;
    nTargetY += nOffsetY;

    return AITACTICS_MoveToTarget(pGame, pUnit, 0, MONMODE_WALK, nTargetX, nTargetY, 1, 0);
}
