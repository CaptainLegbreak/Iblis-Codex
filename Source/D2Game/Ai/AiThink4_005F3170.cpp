#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Path.h"
#include "D2Txt.h"

struct D2VultureAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int nLifePercentage;
    int unk0x0C[7];
};

typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax); // 0x00472210
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AITARGETCALLBACK pfnCallback, int nCallbackId); // 0x005DD0B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE0F0
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4); // 0x005DE190
int __fastcall AITACTICS_ChangeModeAndTargetCoordinatesOneStep(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nMode); // 0x005DE440
int __fastcall sub_005DE4E0_MoveAwayFromTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int a5, int a6); // 0x005DE4E0
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
void __fastcall sub_005F2EB0_RemoveGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005F2EB0
int __fastcall AITHINK_TryRestoreGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005F2FC0
D2UnitStrc* __fastcall AITHINK_TargetCallback_Vulture(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F30F0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

// build: context CLIENTS_GetUnitXInline_005F3170
static __forceinline int CLIENTS_GetUnitXInline_005F3170(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nXPos; default: return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0; }
}

// build: context CLIENTS_GetUnitYInline_005F3170
static __forceinline int CLIENTS_GetUnitYInline_005F3170(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nYPos; default: return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0; }
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 nValue = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nValue >> 32);
    pSeed->nLowSeed = (unsigned int)nValue;
    return nValue;
}

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

// 0x005F3170
void __fastcall sub_005F3170_GroundCollisionAi(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    int nState = pAiControl->dwAiParam[0];
    if (!pTarget) {
        if (nState < 1) { AITACTICS_Idle(pGame, pUnit, 12); return; }
        if (AITHINK_TryRestoreGroundCollision(pGame, pUnit)) {
            sub_005DE4E0_MoveAwayFromTarget(pGame, pUnit, pUnit, 9, 2, 3);
            AITACTICS_Idle(pGame, pUnit, 12);
            pAiControl->dwAiParam[0] = -1;
            return;
        }
    }
    int bFar = AITHINK_GetSquaredDistance(pUnit, pTarget) > 144;
    if (pTarget) {
        if (UNITS_GetRoom(pTarget) != UNITS_GetRoom(pUnit) && bFar) {
            if (nState >= 1) {
                if (AITHINK_TryRestoreGroundCollision(pGame, pUnit)) {
                    sub_005DE4E0_MoveAwayFromTarget(pGame, pUnit, pUnit, 9, 2, 3);
                    AITACTICS_Idle(pGame, pUnit, 12);
                    pAiControl->dwAiParam[0] = -1;
                    return;
                }
            }
            else { D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 9, 0); return; }
        }
    }
    if (!nState && !AIGENERAL_GetMinionOwner(pUnit) && pTarget && bFar && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 60) {
        sub_005F2EB0_RemoveGroundCollision(pGame, pUnit);
        pAiControl->dwAiParam[0] = sub_00472210_SeedRollMasked(pSeed, 8) + 24;
        sub_005DE4E0_MoveAwayFromTarget(pGame, pUnit, pTarget, 8, 8, 8);
        AITACTICS_Idle(pGame, pUnit, 12);
        return;
    }
    D2VultureAiCallbackArgStrc tArg;
    tArg.pTarget = 0;
    tArg.nDistance = 121;
    tArg.nLifePercentage = AI_PARAM(pGame, pMonStatsTxt, 2);
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &tArg, AITHINK_TargetCallback_Vulture, 1);
    if (nState > 1) {
        if (tArg.pTarget) goto SUCCESS;
        if (nDistance < 6 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 15) {
SUCCESS:
            pAiControl->dwAiParam[0] = 1;
            nState = 1;
            goto RESTORE_TARGET;
        }
        else {
            sub_005F2EB0_RemoveGroundCollision(pGame, pUnit);
            int nX = CLIENTS_GetUnitXInline_005F3170(pUnit);
            int nY = CLIENTS_GetUnitYInline_005F3170(pUnit);
            if (pAiControl->dwAiParam[1] && pAiControl->dwAiParam[2] && (unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pAiControl->dwAiParam[1], pAiControl->dwAiParam[2]) > 1) {
                D2CoordStrc tCoord;
                tCoord.nX = pAiControl->dwAiParam[1]; tCoord.nY = pAiControl->dwAiParam[2];
                if (pTarget && COLLISION_GetFreeCoordinates(UNITS_GetRoom(pTarget), &tCoord, UNITS_GetUnitSizeX(pUnit), 0xFFFF, 1)) {
                    pAiControl->dwAiParam[1] = tCoord.nX; pAiControl->dwAiParam[2] = tCoord.nY;
                }
                else if (COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &tCoord, UNITS_GetUnitSizeX(pUnit), 0xFFFF, 1)) {
                    pAiControl->dwAiParam[1] = tCoord.nX; pAiControl->dwAiParam[2] = tCoord.nY;
                }
                --pAiControl->dwAiParam[0];
                AITACTICS_SetVelocity(pUnit, 7, 0, 0);
                AITACTICS_ChangeModeAndTargetCoordinatesOneStep(pGame, pUnit, pAiControl->dwAiParam[1], pAiControl->dwAiParam[2], 8);
                AITACTICS_Idle(pGame, pUnit, 12);
                return;
            }
            int nRadius = nState + 8;
            int nTargetX = CLIENTS_GetUnitXInline_005F3170(pTarget);
            int nMoveX = nTargetX - nRadius + ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRadius);
            int nTargetY = CLIENTS_GetUnitYInline_005F3170(pTarget);
            int nMoveY = nTargetY - nRadius + ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRadius);
            int nThreshold = nRadius << 1;
            if (nThreshold < 12) nThreshold = 12;
            else if (nThreshold > 36) nThreshold = 36;
            while ((int)AIUTIL_GetDistanceToCoordinates(pUnit, nMoveX, nMoveY) < nThreshold) {
                if (nMoveX < nX) --nMoveX; else if (nMoveX > nX) ++nMoveX;
                if (nMoveY < nY) --nMoveY; else if (nMoveY > nY) ++nMoveY;
                if (nMoveX == nX && nMoveY == nY) { ++nMoveX; ++nMoveY; }
            }
            pAiControl->dwAiParam[1] = nMoveX; pAiControl->dwAiParam[2] = nMoveY;
            AITACTICS_SetVelocity(pUnit, 1, 0, 0);
            AITACTICS_ChangeModeAndTargetCoordinatesOneStep(pGame, pUnit, nMoveX, nMoveY, 8);
            AITACTICS_Idle(pGame, pUnit, 12);
            --pAiControl->dwAiParam[0];
            return;
        }
    }
    else if (nState >= 1) {
RESTORE_TARGET:
        if (AITHINK_TryRestoreGroundCollision(pGame, pUnit)) {
            sub_005DE4E0_MoveAwayFromTarget(pGame, pUnit, pTarget, 9, 2, 3);
            AITACTICS_Idle(pGame, pUnit, 12);
            pAiControl->dwAiParam[0] = -1;
            return;
        }
        pAiControl->dwAiParam[0] = 8;
        AITACTICS_Idle(pGame, pUnit, 12);
    }
    if (bCombat) {
        if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0)) AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        else AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
        return;
    }
    if (nState != -1) {
        const int nDifficulty = pGame->nDifficulty;
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) >= pMonStatsTxt->wAiParam[4][nDifficulty]) {
            AITACTICS_Idle(pGame, pUnit, pMonStatsTxt->wAiParam[1][nDifficulty]);
            return;
        }
    }
    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 3)) sub_005DF7D0(pGame, pUnit, pTarget, 6, 0);
    else D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 9, 0);
    pAiControl->dwAiParam[0] = 0;
    AITACTICS_Idle(pGame, pUnit, 12);
}
