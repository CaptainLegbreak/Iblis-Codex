#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define MONMODE_ATTACK1 4
struct D2MonsterDataStrc;
struct D2SeedStrc;
struct D2MapAIPathPositionStrc;
struct D2AiCmdStrc;

enum
{
};

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
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

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0
int __fastcall MONSTERAI_IsInteractingWith(D2MonsterInteractStrc* pMonInteract, D2UnitStrc* pUnit); // 0x00572DE0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0
D2UnitStrc* __fastcall sub_6FCCFD70(D2GameStrc* pGame, D2UnitStrc* pUnit, int* bCloseToTarget); // 0x005DDF20
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4); // 0x005DE190
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DED90
bool __fastcall sub_005E6860_HomeCommandStep(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, unsigned int nMaxDistance); // 0x005E6860
void __stdcall sub_00648730(D2DynamicPathStrc* pDynamicPath); // 0x00648730

struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
};

typedef bool (__fastcall* MAPAIACTIONFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition);

extern MAPAIACTIONFN gpfMapAiActions_00741D74[7]; // 0x00741D74
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90

enum D2C_Y10AiThinkConstants
{
    MONSTER_JERHYN = 201,
    MONSTER_ALKOR = 254,
    MONSTER_ORMUS = 255,
    MONSTER_CAIN5 = 265,
    MONSTER_DREHYA = 512,
    MONMODE_SKILL1 = 8,
};


struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

bool __fastcall sub_005E6800_InitHomeCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E6800
bool __fastcall sub_005E68F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E68F0
bool __fastcall sub_6FCE69A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E6AE0
bool __fastcall AITHINK_ExecuteMapAiAction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E7080
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall ACT3Q3_GetAltarCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord); // 0x005B9CA0
void __fastcall ACT3Q3_SetAltarMode(D2GameStrc* pGame); // 0x005B9CD0
int __fastcall ACT2Q4_IsJerhynPalaceActivated(D2GameStrc* pGame); // 0x0059F570
void __fastcall ACT2Q4_GetAndUpdatePalaceNpcState(D2GameStrc* pGame, D2UnitStrc* pUnit, int* a3, int* pIdle); // 0x0059F580
int __fastcall ACT2Q4_IsGuardMoving(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059B6E0
int __fastcall ACT3Q4_GoldenBirdBroughtToAlkor(D2GameStrc* pGame); // 0x005BAD20
void __fastcall ACT3Q4_ResetAlkor(D2GameStrc* pGame); // 0x005BAD40
int __fastcall ACT1Q4_GetCainPortalInTownCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00594360
void __fastcall ACT1Q4_OnCainInTownActivated(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005945F0
void __fastcall ACT5Q4_AnyaOpenPortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058BC80
void __fastcall sub_0059C750_Fn(D2GameStrc* pGame); // 0x0059C750
int __fastcall sub_0059DF50_Check(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059DF50
int __fastcall sub_005B43F0_Check(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005B43F0
void __fastcall sub_005B4440_Fn(D2GameStrc* pGame); // 0x005B4440
int __fastcall sub_005E7350_Check(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005E7350

// 0x005E68F0
bool __fastcall sub_005E68F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCloseToTarget = 0;
    D2UnitStrc* pTarget = sub_6FCCFD70(pGame, pUnit, &bCloseToTarget);
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);

    const int nType = pUnit ? pUnit->dwUnitType : 6;
    D2MonsterInteractStrc* pMonInteract = nType == UNIT_MONSTER && pUnit->pMonsterData ? pUnit->pMonsterData->pMonInteract : 0;
    if (!pMonInteract)
    {
        return false;
    }

    int bInteracting = MONSTERAI_IsInteractingWith(pMonInteract, pTarget);
    if (pTarget && pTarget->dwUnitType == UNIT_PLAYER && PLAYER_IsBusy(pTarget) == 1)
    {
        bInteracting = 1;
    }

    const int bHasInteractUnit = MONSTERAI_HasInteractUnit(pMonInteract);
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (bHasInteractUnit || bInteracting || pAiControl->dwAiParam[0] > 0)
    {
        if (AIUTIL_GetDistanceToCoordinates(pUnit, pAiControl->dwAiParam[1], pAiControl->dwAiParam[2]) > 2 && pAiControl->dwAiParam[0] > 36)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiControl->dwAiParam[1], pAiControl->dwAiParam[2]);
        }
        else if (pAiControl->dwAiParam[0] > 0)
        {
            if (pUnit->pDynamicPath)
            {
                sub_00648730(pUnit->pDynamicPath);
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
        }

        if (pAiControl->dwAiParam[0] < 0)
        {
            pAiControl->dwAiParam[0] = 0;
        }
        else
        {
            --pAiControl->dwAiParam[0];
        }

        return true;
    }

    if (!pTarget || pTarget == pUnit)
    {
        return false;
    }

    if (nDistance >= 3 && nDistance <= 23)
    {
        if (sub_005E6860_HomeCommandStep(pGame, pUnit, pAiTickParam, 16))
        {
            return true;
        }

        AITACTICS_SetVelocity(pUnit, 1, 0, 0);
        if (nDistance >= 5)
        {
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 3, 2);
        }
        else
        {
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, nDistance - 2, 2);
        }

        return true;
    }

    sub_00648730(pUnit->pDynamicPath);
    if (!pAiControl->dwAiParam[1])
    {
        pAiControl->dwAiParam[1] = 60;
        if (pTarget->dwUnitType == UNIT_PLAYER)
        {
            SUNIT_AttachSound(pUnit, 18, pTarget);
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
    return true;
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

#include "gen/data/Source/D2Game/Unknown_005E68F0.inc"

// 0x005E7130
void __fastcall AITHINK_Fn032_Npc(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2CoordStrc coord;
    int a3;
    int a4;

    if (sub_005E6800_InitHomeCommand(pGame, pUnit, pAiTickParam))
    {
        return;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    switch (nClassId)
    {
    case MONSTER_ORMUS:
    {
        if (ACT3Q3_GetAltarCoordinates(pGame, &coord))
        {
            if (AIUTIL_GetDistanceToCoordinates(pUnit, coord.nX, coord.nY) > 3)
            {
                AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coord.nX, coord.nY);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_SKILL1, 0, 0);
                ACT3Q3_SetAltarMode(pGame);
            }
            return;
        }
        break;
    }
    case MONSTER_JERHYN:
    {
        if (!ACT2Q4_IsJerhynPalaceActivated(pGame))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
            return;
        }

        ACT2Q4_GetAndUpdatePalaceNpcState(pGame, pUnit, &a3, &a4);
        if (a4)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        }

        if (!a3)
        {
            return;
        }

        if (ACT2Q4_IsGuardMoving(pGame, pUnit))
        {
            D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
            if (pAiCmd)
            {
                pAiCmd->nCmdParam[1] = CLIENTS_GetUnitX(pUnit) + 9;
                pAiCmd->nCmdParam[2] = CLIENTS_GetUnitY(pUnit);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
                return;
            }
        }
        break;
    }
    case MONSTER_ALKOR:
    {
        if (ACT3Q4_GoldenBirdBroughtToAlkor(pGame))
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_SKILL1, 0, 0);
            ACT3Q4_ResetAlkor(pGame);
            return;
        }
        break;
    }
    case MONSTER_CAIN5:
    {
        if (ACT1Q4_GetCainPortalInTownCoordinates(pGame, pUnit, &coord))
        {
            if (AIUTIL_GetDistanceToCoordinates(pUnit, coord.nX, coord.nY) > 2)
            {
                AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coord.nX, coord.nY);
                return;
            }

            ACT1Q4_OnCainInTownActivated(pGame, pUnit);
        }
        break;
    }
    case MONSTER_DREHYA:
    {
        ACT5Q4_AnyaOpenPortal(pGame, pUnit);
        break;
    }
    default:
        break;
    }

    if (!sub_005E68F0(pGame, pUnit, pAiTickParam) && !sub_6FCE69A0(pGame, pUnit, pAiTickParam) && !AITHINK_ExecuteMapAiAction(pGame, pUnit, pAiTickParam))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
    }
}

// 0x005E73A0
void __fastcall sub_005E73A0_AiThinkTownNpc(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCloseToTarget = 0;
    D2UnitStrc* pTarget = sub_6FCCFD70(pGame, pUnit, &bCloseToTarget);
    if (pTarget && pTarget != pUnit)
    {
        const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
        D2MonsterInteractStrc* pMonInteract = pUnit ? (pUnit->dwUnitType == UNIT_MONSTER ? (pUnit->pMonsterData ? pUnit->pMonsterData->pMonInteract : 0) : 0) : 0;
        if (pTarget->dwUnitType == UNIT_PLAYER && PLAYER_IsBusy(pTarget) == 1)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }

        if (MONSTERAI_HasInteractUnit(pMonInteract))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }

        D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
        if (nDistance < 24)
        {
            if (!pAiControl->dwAiParam[1])
            {
                pAiControl->dwAiParam[1] = 60;
                if (pTarget->dwUnitType == UNIT_PLAYER)
                {
                    SUNIT_AttachSound(pUnit, 18, pTarget);
                }
            }
            else
            {
                --pAiControl->dwAiParam[1];
            }
        }
        else
        {
            if (pAiControl->dwAiParam[1] <= 0)
            {
                pAiControl->dwAiParam[1] = 60;
            }
            --pAiControl->dwAiParam[1];
        }
    }
    else if (pUnit)
    {
        if (pUnit->dwClassId == 0xFB)
        {
            if (sub_0059DF50_Check(pGame, pUnit) && sub_005E7350_Check(pGame, pUnit))
            {
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
                sub_0059C750_Fn(pGame);
                return;
            }
        }
        else if (pUnit->dwClassId == 0x196)
        {
            if (sub_005B43F0_Check(pGame, pUnit) && sub_005E7350_Check(pGame, pUnit))
            {
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
                sub_005B4440_Fn(pGame);
                return;
            }
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}
