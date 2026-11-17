#include "D2Game.h"

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[8];
    int dwUnitId;
    char unk10[0x10];
    D2SeedStrc pSeed;
    char unk28[0x9C];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
    char unk0x86[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
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
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int a4, int bRun, int nVelocity, int a7); // 0x005E3EA0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask); // 0x00622AA0
int __fastcall sub_005E45D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int a5, D2AiTickParamStrc* pAiTickParam, int a7, int a8); // 0x005E45D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __fastcall sub_005DF400_FollowOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nDistance); // 0x005DF400
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}
static __forceinline int UNITS_TestIgnoreTargetFlag(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 30) & 1;
    return bResult;
}

// 0x005E4AC0
void __fastcall sub_005E4AC0_NecroPetFollowOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (pAiControl->dwAiParam[2])
        {
            D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, pAiControl->dwAiParam[2]);
            if (pPlayer)
            {
                D2GAME_AI_PetMove_6FCE2BA0(pGame, pPlayer, pUnit, 3, 0, 0, 0);
                return;
            }
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    pAiControl->dwAiParam[2] = !pOwner ? -1 : pOwner->dwUnitId;
    AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    int nOwnerDistance;
    int bOwnerCombat;
    D2UnitStrc* pOwnerTarget = sub_6FCF2110(pGame, pOwner, pAiControl, &nOwnerDistance, &bOwnerCombat);
    if (pOwnerTarget && UNITS_TestIgnoreTargetFlag(pOwnerTarget))
        pOwnerTarget = 0;
    int nDistance;
    int bCombat;
    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (!pTarget || nDistance > 15)
    {
        pTarget = 0;
        if (pOwnerTarget && !UNITS_TestCollisionWithUnit(pUnit, pOwnerTarget, 4))
        {
            nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwnerTarget);
            if (nDistance < 20) pTarget = pOwnerTarget;
        }
    }
    int nResult;
    if ((int)(AI_RollUnitSeed(pUnit) % 100) < 15)
        nResult = sub_005E45D0(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 1, 8);
    else
        nResult = sub_005E45D0(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 7);
    if (nResult)
        return;
    if (pTarget && DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        sub_005DF400_FollowOwner(pGame, pUnit, pOwner, 4);
        return;
    }
    if (!pTarget)
    {
        sub_005DF400_FollowOwner(pGame, pUnit, pOwner, 4);
        return;
    }
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 80)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }
        if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 75)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}
