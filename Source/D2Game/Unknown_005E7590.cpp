#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
struct D2GameStrc;
struct D2UnitStrc;

struct D2MonStatsTxt;
union D2SeedStrc;
struct D2AiCmdStrc;






unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0
int __fastcall ACT2Q4_IsHaremBlockerObjectOpened(D2GameStrc* pGame); // 0x0059AEC0
int __fastcall ACT2Q4_HasGuardMovedToEndPosition(D2GameStrc* pGame); // 0x0059B8B0
int __fastcall ACT2Q4_GetGuardCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord); // 0x0059B8F0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0
D2UnitStrc* __fastcall sub_6FCCFD70(D2GameStrc* pGame, D2UnitStrc* pUnit, int* bCloseToTarget); // 0x005DDF20
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DED90
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, unsigned char nMaxDistance); // 0x005DF530


bool __fastcall sub_005E6800_InitHomeCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pAiTickParam); // 0x005E6800
bool __fastcall sub_005E68F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E68F0


D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

enum
{
    MONMODE_ATTACK1 = 4,
};

// 0x005E7590
void __fastcall AITHINK_Fn081_JarJar(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (sub_005E6800_InitHomeCommand(pGame, pUnit, pAiTickParam))
    {
        return;
    }

    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!ACT2Q4_HasGuardMovedToEndPosition(pGame))
    {
        D2CoordStrc coords;
        coords.nX = pAiCmd->nCmdParam[1];
        coords.nY = pAiCmd->nCmdParam[2];

        int bFree = 1;
        if (ACT2Q4_GetGuardCoordinates(pGame, &coords))
        {
            bFree = 0;
        }

        if (pAiCmd->nCmdParam[4] < pGame->dwGameFrame && pGame->dwGameFrame - pAiCmd->nCmdParam[4] < 200)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            return;
        }

        if (AIUTIL_GetDistanceToCoordinates(pUnit, coords.nX, coords.nY) > 1)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coords.nX, coords.nY);
            pAiCmd->nCmdParam[4] = pGame->dwGameFrame;
            return;
        }

        if (bFree)
        {
            if (sub_005E68F0(pGame, pUnit, pAiTickParam))
            {
                pAiCmd->nCmdParam[4] = pGame->dwGameFrame;
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            }
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        }
        return;
    }

    if (pAiCmd)
    {
        int bCloseToTarget;
        D2UnitStrc* pOwner = sub_6FCCFD70(pGame, pUnit, &bCloseToTarget);
        const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
        if (ACT2Q4_IsHaremBlockerObjectOpened(pGame) && AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3) > 2)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3);
            return;
        }

        if (AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3) > 7)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3);
            return;
        }

        if (!sub_005E68F0(pGame, pUnit, pAiTickParam) && pOwner && pOwner != pUnit)
        {
            if (pOwner->dwUnitType == UNIT_PLAYER)
            {
                if (nDistance < 12)
                {
                    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 1000) < 100)
                    {
                        D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, 2);
                    }

                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 200);
                    return;
                }

                AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            }

            if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 1000) < 50)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
            }
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 120);
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline int AI_GetAnimMode(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

// 0x005E7C10
void __fastcall sub_005E7C10_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (AI_GetAnimMode(pUnit) != 1)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        int nDistance;
        int bCombat;
        D2UnitStrc* pTarget = sub_6FCF2110(pGame, pUnit, pAiTickParam->pAiControl, &nDistance, &bCombat);
        if (pTarget)
        {
            const int nRand = SEED_RollLimitedRandomNumber(pSeed, 100);
            if (bCombat)
            {
                if (nRand < 80)
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                    return;
                }

                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                return;
            }

            if (nRand < 30)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
    }

    if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < 20)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E7D30
int __fastcall sub_005E7D30_IsInTownOrRoomless(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 1;
    }

    return DUNGEON_IsRoomInTown(pRoom) != 0;
}

// 0x005E7D60
void __fastcall AITHINK_Fn062_TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (pTarget && nDistance < 25)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
    }
}

// 0x005E7DC0
void __fastcall sub_005E7DC0_SpecialState08TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (pTarget && nDistance < 25)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
    }
}

// 0x005E7F50
void __fastcall AITHINK_Fn001_100_Idle_Buffy(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (UNITS_GetRoom(pUnit))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 200);
    }
}
