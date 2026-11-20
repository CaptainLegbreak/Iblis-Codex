#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"





struct D2AiControlStrc
{
    char unk0x00[0x14];
    int dwAiParam[2];
};


struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

enum D2C_M150ZakarumZealotAi
{
    ACT_III = 2,
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    QUESTSTATEFLAG_A3Q5 = 0x15,
    COLLIDE_MISSILE = 0x40,
    ZAKARUMZEALOT_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    ZAKARUMZEALOT_AI_PARAM_ATTACK2_CHANCE_PCT = 1,
    ZAKARUMZEALOT_AI_PARAM_HURT_PCT = 2,
    ZAKARUMZEALOT_AI_PARAM_RUN_CHANCE_PCT = 3,
};

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType);               // 0x0058F090
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall sub_6FCD06D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DF140
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);   // 0x005DED20
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

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

// 0x005F6E60
void __fastcall AITHINK_Fn048_ZakarumZealot(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nVel = 0;
    if (pMonStatsTxt->nVelocity > 0)
    {
        const int nRatio = 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity;
        const int nDiff = nRatio - 100;
        nVel = nDiff > 0 ? nDiff : 0;
        if (nVel >= 120)
            nVel = 120;
    }
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    D2UnitStrc* pPlayer = pTarget;
    if (pTarget)
    {
        if (pTarget->dwUnitType == UNIT_MONSTER)
        {
            int nOwnerGUID;
            int nOwnerType;
            AIGENERAL_GetOwnerData(pTarget, &nOwnerGUID, &nOwnerType);
            if (nOwnerType == UNIT_PLAYER)
                pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOwnerGUID);
        }
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) == ACT_III)
        {
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, 0))
            {
                AITACTICS_SetVelocity(pUnit, 0, nVel, 0);
                if (!sub_6FCD06D0(pGame, pUnit, pTarget, 8, 1))
                    AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
                return;
            }
        }
    }
    if (sub_6FCF2E70(pUnit))
    {
        if (!pAiControl->dwAiParam[1] && nLifePercentage < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMZEALOT_AI_PARAM_HURT_PCT))
        {
            pAiControl->dwAiParam[0] = 0;
            AITACTICS_SetVelocity(pUnit, 0, nVel, 0);
            if (sub_6FCD06D0(pGame, pUnit, pTarget, 8, 1))
                return;
            pAiControl->dwAiParam[1] = 5;
        }
        if (COLLISION_CheckMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), COLLIDE_MISSILE))
        {
            if (bCombat)
            {
                sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
                return;
            }
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
            return;
        }
    }
    if (pAiControl->dwAiParam[1])
        --pAiControl->dwAiParam[1];
    if (bCombat)
    {
        if (pAiControl->dwAiParam[0])
        {
            if (!((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMZEALOT_AI_PARAM_ATTACK_CHANCE_PCT)))
            {
                pAiControl->dwAiParam[0] = 0;
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 80)
                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                else
                    sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
                return;
            }
        }
        pAiControl->dwAiParam[0] = 1;
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMZEALOT_AI_PARAM_ATTACK2_CHANCE_PCT))
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        else
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }
    pAiControl->dwAiParam[0] = 0;
    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMZEALOT_AI_PARAM_RUN_CHANCE_PCT))
    {
        AITACTICS_SetVelocity(pUnit, 0, nVel, 0);
        AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
        return;
    }
    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
}
