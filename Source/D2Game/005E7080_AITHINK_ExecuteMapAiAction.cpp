struct D2GameStrc;
struct D2MonsterInteractStrc;

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define MONMODE_ATTACK1 4

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
};

struct D2MapAIPathPositionStrc
{
    int nMapAIAction;
    int nX;
    int nY;
};

struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    unsigned int dwOwnerType;
    int dwAiParam[3];
    char unk0x20[0x18];
    D2MapAIStrc* pMapAi;
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
};

typedef bool (__fastcall* MAPAIACTIONFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition);

extern MAPAIACTIONFN gpfMapAiActions_00741D74[7];                                                         // 0x00741D74

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                  // 0x0045C3E0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract);                             // 0x00572DC0
D2UnitStrc* __fastcall sub_6FCF2CC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
D2UnitStrc* __fastcall sub_6FCCFD70(D2GameStrc* pGame, D2UnitStrc* pUnit, int* bCloseToTarget);             // 0x005DDF20
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080

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

inline D2MonsterInteractStrc* AITHINK_GetMonInteractInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonInteract;
    }

    return 0;
}

// 0x005E7080
bool __fastcall AITHINK_ExecuteMapAiAction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    bool bResult = false;
    D2MapAIStrc* pMapAi = pAiTickParam->pAiControl->pMapAi;
    if (pMapAi && AI_RollPercentage(pUnit) < 66)
    {
        if (!pMapAi->nPathNodes)
        {
            return false;
        }

        D2MapAIPathPositionStrc* pPosition = &pMapAi->pPosition[ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pMapAi->nPathNodes)];
        if (pPosition->nMapAIAction < 0 || pPosition->nMapAIAction >= 7)
        {
            return false;
        }

        MAPAIACTIONFN pfAction = gpfMapAiActions_00741D74[pPosition->nMapAIAction];
        if (pfAction)
        {
            bResult = pfAction(pGame, pUnit, pAiTickParam, pPosition);
        }
    }

    return bResult;
}

// 0x005E7E20
void __fastcall AITHINK_Fn058_Navi(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (MONSTERAI_HasInteractUnit(AITHINK_GetMonInteractInline(pUnit)))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    int bCloseToTarget;
    D2UnitStrc* pPlayer = sub_6FCCFD70(pGame, pUnit, &bCloseToTarget);
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && !PLAYER_IsBusy(pPlayer) && SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3) && bCloseToTarget)
    {
        D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
        if (!pAiControl->dwAiParam[1])
        {
            pAiControl->dwAiParam[1] = 60;

            if (pPlayer->dwUnitType == UNIT_PLAYER)
            {
                SUNIT_AttachSound(pUnit, 18, pPlayer);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
                return;
            }
        }
        else
        {
            if (pAiControl->dwAiParam[1] < 0)
            {
                pAiControl->dwAiParam[1] = 0;
            }

            if (pAiControl->dwAiParam[1] > 0)
            {
                --pAiControl->dwAiParam[1];
            }
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }

    int bInMeleeRange;
    int nDistance;
    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bInMeleeRange);
    if (pTarget && nDistance < 25)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
}

#include "gen/data/Source/D2Game/005E7080_AITHINK_ExecuteMapAiAction.inc"
