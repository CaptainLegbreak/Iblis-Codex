#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2UnitData.h"

struct D2SeedStrc;
struct D2AiCmdStrc;
struct D2MonsterDataStrc;



struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4); // 0x005DE190
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_WalkToTargetCoordinatesNoSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEF30
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820

enum
{
};

enum
{
    MONMODE_DEAD = 12,
};

enum
{
    MONSTER_DREHYAICED = 0x20F,
};

enum
{
    STAT_HITPOINTS = 6,
};


int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260
int __fastcall ACT1Q4_UpdateCainPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005944B0
int __fastcall ACT5Q3_InitializeDrehyaPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058A940
void __fastcall sub_6FCB53D0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058A980

int gnNpcWalkSequenceCounter; // 0x0088CADC

static __forceinline int AITHINK_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// 0x005E6AE0
bool __fastcall sub_6FCE69A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 4, 0);
    if (pAiCmd && pAiCmd->nCmdParam[3] > 0)
    {
        if (pAiCmd->nCmdParam[1] && pAiCmd->nCmdParam[2] && (unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]) > 3)
        {
            if ((gnNpcWalkSequenceCounter % 4) == 0)
            {
                AITACTICS_SetVelocity(pUnit, 5, 0, 0);
                AITACTICS_WalkToTargetCoordinatesNoSteps(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]);
            }
            else
            {
                AITACTICS_SetVelocity(pUnit, 1, 0, 0);
                AITACTICS_WalkToTargetCoordinatesNoSteps(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]);
            }

            ++gnNpcWalkSequenceCounter;
            --pAiCmd->nCmdParam[3];
            return 1;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiCmd->nCmdParam[4]);
        --pAiCmd->nCmdParam[3];
        return 1;
    }

    pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 5, 0);
    if (pAiCmd)
    {
        if (pAiCmd->nCmdParam[1] > 0)
        {
            if ((pAiCmd->nCmdParam[1] % 2) != 0)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, pAiCmd->nCmdParam[2]);
                --pAiCmd->nCmdParam[1];
                return 1;
            }

            if (pAiCmd->nCmdParam[3] > 0)
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiCmd->nCmdParam[4]);
                --pAiCmd->nCmdParam[1];
                --pAiCmd->nCmdParam[3];
                return 1;
            }

            --pAiCmd->nCmdParam[1];
        }
        else
        {
            if (pAiCmd->nCmdParam[3] > 0)
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiCmd->nCmdParam[4]);
                --pAiCmd->nCmdParam[3];
                return 1;
            }
        }
    }

    pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 7, 0);
    if (!pAiCmd || !pAiCmd->nCmdParam[1])
    {
        return 0;
    }

    if (pAiCmd->nCmdParam[1] != 8 && pAiCmd->nCmdParam[1] != 9 && pAiCmd->nCmdParam[1] != 10 && pAiCmd->nCmdParam[1] != 11)
    {
        pAiCmd->nCmdParam[1] = 0;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
        return 1;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[2], pAiCmd->nCmdParam[3]);
    if (nDistance > 0)
    {
        if (pAiCmd->nCmdParam[4] > 0)
        {
            AITACTICS_SetVelocity(pUnit, 7, 0, 0);

            if (!AITACTICS_WalkToTargetCoordinatesNoSteps(pGame, pUnit, pAiCmd->nCmdParam[2], pAiCmd->nCmdParam[3]))
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
            }

            --pAiCmd->nCmdParam[4];
            return 1;
        }

        if (nDistance > 1)
        {
            pAiCmd->nCmdParam[1] = 0;
        }
    }

    {
        if (pUnit)
        {
            if (pUnit->dwClassId == 154)
            {
                D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x38);
            }
            if (AITHINK_GetClassIdInline(pUnit) == 155)
            {
                D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x34);
            }
            if (pUnit->dwClassId == 178)
            {
                D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 4);
            }
            if (pUnit->dwClassId == 405)
            {
                if (pAiCmd->nCmdParam[1] == 8)
                {
                    D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x34);
                }
                if (pAiCmd->nCmdParam[1] == 9)
                {
                    D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x30);
                }
            }
            if (pUnit->dwClassId == 511 && (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) > 4)
            {
                pAiCmd->nCmdParam[1] = 0;
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
                return 1;
            }
        }

        if (pAiCmd->nCmdParam[1])
        {
            int nAnimMode;
            if (!pUnit)
            {
                nAnimMode = 0;
            }
            else
            {
                nAnimMode = pUnit->dwAnimMode;
            }

            if (nAnimMode == pAiCmd->nCmdParam[1])
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, pAiCmd->nCmdParam[1], pUnit);
                pAiCmd->nCmdParam[1] = 0;
            }
            return 1;
        }

        if (pUnit && pUnit->dwClassId == 178 && (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 66)
        {
            pAiCmd->nCmdParam[1] = 8;
        }

        return 0;
    }

}

// 0x005E7350
int __fastcall sub_005E7350_StopUnlessInteracting(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2MonsterInteractStrc* pMonInteract = (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) ? pUnit->pMonsterData->pMonInteract : 0;
    if (!MONSTERAI_HasInteractUnit(pMonInteract))
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return 1;
    }

    return 0;
}

// 0x005E77A0
int __fastcall AITHINK_SpawnNpcPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pAiTickParam)
{
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 3, 0);

    if (!pCurrentAiCmd || pCurrentAiCmd->nCmdParam[1] || pCurrentAiCmd->nCmdParam[2])
    {
        return 0;
    }

    pCurrentAiCmd->nCmdParam[1] = CLIENTS_GetUnitX(pUnit) + 3;
    pCurrentAiCmd->nCmdParam[2] = CLIENTS_GetUnitY(pUnit) + 3;

    int (__fastcall* pfUpdatePortalCoordinates)(D2GameStrc*, D2UnitStrc*) = ACT1Q4_UpdateCainPortalCoordinates;
    void (__fastcall* pfSpawnPortal)(D2GameStrc*, D2UnitStrc*) = ACT1Q4_SpawnCainPortalInTown;
    if (pUnit && pUnit->dwClassId == MONSTER_DREHYAICED)
    {
        pfUpdatePortalCoordinates = ACT5Q3_InitializeDrehyaPortalCoordinates;
        pfSpawnPortal = sub_6FCB53D0;
    }

    if (!pfUpdatePortalCoordinates(pGame, pUnit))
    {
        pfSpawnPortal(pGame, pUnit);
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0, 0);
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEAD, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
    }

    pCurrentAiCmd->nCmdParam[3] = 1;
    pCurrentAiCmd->nCmdParam[4] = 0;
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
    return 1;
}
