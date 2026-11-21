#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
struct D2UnitStrc;

struct D2AiParamStrc;
struct D2MonsterDataStrc { char pad00[0x2C]; D2AiParamStrc* pAiParam; };
struct D2AiControlStrc { char pad00[0x14]; int dwAiParam[3]; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; int unk04; D2UnitStrc* pTarget; int unk0C[2]; int nTargetDistance; int bCombat; D2MonStatsTxt* pMonstatsTxt; };
struct D2AiCmdStrc { D2AiCmdStrc* pNext; D2AiCmdStrc* pPrev; int nCmdParam[5]; };
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nCustomId); // 0x00540E60
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmd, int bSet); // 0x0058EEF0
void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pCmd); // 0x0058EF40
void __fastcall sub_005A6260_SetAiParamFields(D2AiParamStrc* pAiParam, int nFlags, int nVelocity, unsigned char nUnused); // 0x005A6260
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DED20
int __fastcall AITACTICS_RunToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEDE0
int __fastcall sub_6FCE5520(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick); // 0x005E5B70
int __stdcall D2Common_10095(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0061B130
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
static __forceinline int GetX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nXPos; default: return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0; }
}
static __forceinline int GetY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nYPos; default: return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0; }
}

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C3E0
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc*, int); // 0x00472210
int __fastcall AIUTIL_GetDistanceToCoordinates_HalfUnitSize(D2UnitStrc*, int, int); // 0x005DC480
int __fastcall sub_6FCF2E70(D2UnitStrc*); // 0x005DD2B0
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc*, D2UnitStrc*, int*, int*); // 0x005DDC30
int __fastcall AITACTICS_UseSkill(D2GameStrc*, D2UnitStrc*, unsigned char, int, D2UnitStrc*, int, int); // 0x005DEAD0
int __fastcall AITACTICS_RunCloseToTargetUnit(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DF680
int __fastcall sub_005DF7D0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int); // 0x005DF7D0
int __fastcall sub_005DF140_Escape(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DF140
static __forceinline unsigned int Roll(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return (unsigned int)seed;
}
// 0x005E6320
void __fastcall sub_005E6320_Think(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2UnitStrc* pTarget = pTick->pTarget;
    int nDistance = pTick->nTargetDistance;
    int bCombat = pTick->bCombat;
    D2MonStatsTxt* pMonStats = pTick->pMonstatsTxt;
    D2AiCmdStrc* pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pCmd) {
        D2AiCmdStrc cmd;
        cmd.nCmdParam[0] = 10;
        cmd.nCmdParam[1] = GetX(pUnit);
        cmd.nCmdParam[2] = GetY(pUnit);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &cmd);
        pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    }
    int nHomeDistance = 0;
    D2AiControlStrc* pAi = pTick->pAiControl;
    if (pCmd) {
        nHomeDistance = AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pTarget, pCmd->nCmdParam[1], pCmd->nCmdParam[2]);
        if (nDistance > 45) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 5); return; }
        if (nHomeDistance >= 50 || (unsigned int)AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2]) > 50) {
            pAi->dwAiParam[2] = 1;
            sub_005DE190_SetAiParam(pUnit, 7, 100, 0);
            if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) return;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        }
        if (pAi->dwAiParam[2] && (unsigned int)AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2]) > 5) {
            sub_005DE190_SetAiParam(pUnit, 7, 100, 0);
            if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) return;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        }
        pAi->dwAiParam[2] = 0;
    }
    if (nDistance > 20 && nHomeDistance < 50) {
        nDistance >>= 1;
        if (nDistance < 12) nDistance = 12;
        sub_005DE190_SetAiParam(pUnit, 7, 100, 0);
        if (AITACTICS_RunCloseToTargetUnit(pGame, pUnit, pTarget, nDistance)) return;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    }
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nMax = 2 * pGame->nDifficulty + 8;
    pAi->dwAiParam[0] += 3;
    if (pMonStats->nSkill[0] >= 0 && !bCombat && pAi->dwAiParam[1] < nMax
        && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < pAi->dwAiParam[0]) {
        nDistance = SEED_RollLimitedRandomNumber(pSeed, 15) + 5;
        int nX, nY;
        if (sub_00472210_SeedRollMasked(pSeed, 2)) { nX = nDistance; nY = ITEMS_RollLimitedRandomNumber(pSeed, nDistance); }
        else { nX = ITEMS_RollLimitedRandomNumber(pSeed, nDistance); nY = nDistance; }
        if (sub_00472210_SeedRollMasked(pSeed, 2)) nX = -nX;
        if (sub_00472210_SeedRollMasked(pSeed, 2)) nY = -nY;
        AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[0], pMonStats->nSkill[0], 0, CLIENTS_GetUnitX(pTarget) + nX, CLIENTS_GetUnitY(pTarget) + nY);
        ++pAi->dwAiParam[1];
        pAi->dwAiParam[0] = 0;
        return;
    }
    if (nDistance > 5) {
        if ((int)(Roll(pSeed) % 100) < 5 && nHomeDistance < 50) {
            sub_005DE190_SetAiParam(pUnit, 7, 100, 0);
            AITACTICS_RunCloseToTargetUnit(pGame, pUnit, pTarget, 12);
            return;
        }
        int nNewDistance, bNewCombat;
        D2UnitStrc* pNewTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nNewDistance, &bNewCombat);
        if (pNewTarget && !sub_6FCF2E70(pUnit) && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 80) {
            const int nChance = 10 * (pGame->nDifficulty + 4);
            if (pMonStats->nSkill[1] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < nChance) {
                AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[1], pMonStats->nSkill[1], pNewTarget, 0, 0);
                return;
            }
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pNewTarget);
            return;
        }
        sub_005DE190_SetAiParam(pUnit, 0, 50, 0);
        if (sub_005DF7D0(pGame, pUnit, pTarget, 4, 1)) return;
    }
    if ((int)(Roll(pSeed) % 100) < 30 && nDistance < 12) {
        sub_005DE190_SetAiParam(pUnit, 7, 100, 0);
        if (sub_005DF140_Escape(pGame, pUnit, pTarget, 12 - nDistance, 0)) return;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    }
    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
}
