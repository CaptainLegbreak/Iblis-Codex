#include "D2Game.h"
#include "D2Path.h"
#include "D2GameStrc.h"
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

// build: context AIBAAL_RollSeed_M282Inline
// build: context AIBAAL_RollLimited_M282Inline
// build: context AIBAAL_GetRandomArrayIndex_M282Inline
// build: context AIBAAL_GetSkillId_Inline
// build: context AIBAAL_RollSeed_Inline
// build: context AIBAAL_RollLimited_Inline
// build: context AIBAAL_GetRandomArrayIndex_Inline
// build: context AIBAAL_GetUnitX_Inline
// build: context AIBAAL_GetUnitY_Inline
// build: context sub_005FC630_Shim


struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    unsigned int dwOwnerType;
    int dwAiParam[3];
};

struct D2PlayerCountBonusStrc
{
    int nHP;
    int nExperience;
    int nMonsterSkillBonus;
    int nDifficulty;
    int nPlayerCount;
};

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc* pGame, D2PlayerCountBonusStrc* pPlayerCountBonus, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMonster); // 0x00573930
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pUnit, D2UnitStrc* pTarget);        // 0x005DC380
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

static __forceinline unsigned __int64 AIBAAL_RollSeed_M282Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static __forceinline unsigned int AIBAAL_RollLimited_M282Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return (unsigned int)AIBAAL_RollSeed_M282Inline(pSeed) % nMax;
    }

    return AIBAAL_RollSeed_M282Inline(pSeed) & (nMax - 1);
}

static __forceinline int AIBAAL_GetRandomArrayIndex_M282Inline(int* pArray, int nArraySize, D2UnitStrc* pUnit, int nDefaultValue)
{
    int nSum = 0;
    int* pSum = pArray;
    for (int i = 0; i < nArraySize; ++i)
    {
        nSum += *pSum;
        ++pSum;
    }

    const int nRand = AIBAAL_RollLimited_M282Inline(&pUnit->pSeed, nSum);

    int nThreshold = 0;
    int* pPick = pArray;
    for (int i = 0; i < nArraySize; ++i)
    {
        nThreshold += *pPick;
        const int bTest = nRand < nThreshold;
        if (!bTest)
        {
            ++pPick;
        }
        if (bTest)
        {
            return i;
        }
    }

    return nDefaultValue;
}
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0

__declspec(noinline) static int sub_005FC070_CheckPrimeEvilSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

// 0x005FC070
static int sub_005FC070_CheckPrimeEvilSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, szAiBaalCpp_006E3580, 0x131);
    if (nSkillId == 0x3B || nSkillId == 0x38)
    {
        return 1;
    }

    if (nSkillId == 0x33)
    {
        if (SKILLS_GetSkillLevel(pUnit, pSkill, 1) > 3)
        {
            return 1;
        }
    }
    else if (nSkillId == 0x1B)
    {
        if (SKILLS_GetSkillLevel(pUnit, pSkill, 1) > 7)
        {
            return 1;
        }
    }

    return 0;
}

static __forceinline int AIBAAL_GetSkillId_Inline(D2SkillStrc* pSkill)
{
    return SKILLS_GetSkillIdFromSkill(pSkill, szAiBaalCpp_006E3580, 0x131);
}

__declspec(noinline) static int AI_CheckSpecialSkillsOnPrimeEvil(D2UnitStrc* pUnit);

// 0x005FC0C0
static int AI_CheckSpecialSkillsOnPrimeEvil(D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
    if (pSkill)
    {
        const int nSkillId = AIBAAL_GetSkillId_Inline(pSkill);
        if (nSkillId == 0x3B || nSkillId == 0x38)
        {
            return 1;
        }

        if (nSkillId == 0x33)
        {
            if (SKILLS_GetSkillLevel(pUnit, pSkill, 1) > 3)
            {
                return 1;
            }
        }
        else if (nSkillId == 0x1B)
        {
            if (SKILLS_GetSkillLevel(pUnit, pSkill, 1) > 7)
            {
                return 1;
            }
        }
    }

    return sub_005FC070_CheckPrimeEvilSkill(pUnit, UNITS_GetLeftSkill(pUnit));
}

__declspec(noinline) static int __stdcall AIBAAL_RollRandomAiParamForNonCollidingUnit(D2GameStrc* pGame, D2AiControlStrc* pAiControl, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, int bInCloseRange, int nMax); // 0x005FC450

// build: context AIBAAL_RollRandomAiParamForNonCollidingUnit
static int __stdcall AIBAAL_RollRandomAiParamForNonCollidingUnit(D2GameStrc* pGame, D2AiControlStrc* pAiControl, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, int bInCloseRange, int nMax)
{
    int aiParams[16] = { 0, 0, 5, 5, 5, 0, 5, 0, 40, 40, 0, 70, 80, 60, 20, 0 };
    int nBonus = 100;
    if (!pGame->nDifficulty)
    {
        nBonus = 125;
        aiParams[13] = 40;
    }

    aiParams[15] = 10 * (2 - pAiControl->dwAiParam[1]);
    if (aiParams[15] < 0)
    {
        aiParams[15] = 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    if (nDistance > 35)
    {
        aiParams[6] = 15;
        aiParams[13] = 0;
    }

    nBonus += 100 - UNITS_GetCurrentLifePercentage(pUnit);
    aiParams[1] = nBonus;
    if (nDistance > 25)
    {
        aiParams[14] = 30;
        aiParams[11] = 0;
    }

    if (nCount < 2)
    {
        aiParams[11] -= 10;
    }

    if (nCount > 3)
    {
        aiParams[13] += 25;
    }

    if (nMax > 60)
    {
        aiParams[8] = 70;
    }

    D2PlayerCountBonusStrc playerCountBonus;
    MONSTER_GetPlayerCountBonus(pGame, &playerCountBonus, UNITS_GetRoom(pUnit), pUnit);

    if (nCount < 2 && playerCountBonus.nDifficulty < 2)
    {
        aiParams[8] = 0;
    }

    if (AI_CheckSpecialSkillsOnPrimeEvil(pTarget) && !bInMediumRange)
    {
        aiParams[6] += 30;
        aiParams[11] += 10;
        aiParams[14] += 15;
    }
    else if (bInMediumRange)
    {
        aiParams[6] += 25;
        aiParams[14] += 35;
        aiParams[2] = 0;
        aiParams[3] = 25;
    }

    if (bInFarRange)
    {
        aiParams[5] = 60;
    }

    if (bInCloseRange)
    {
        aiParams[7] = 0;
    }

    return AIBAAL_GetRandomArrayIndex_M282Inline(aiParams, 16, pUnit, 1);
}

static __forceinline unsigned int AIBAAL_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int AIBAAL_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    int nResult;
    if (nMax <= 0)
        nResult = 0;
    else if (((unsigned int)nMax - 1) & (unsigned int)nMax)
        nResult = AIBAAL_RollSeed_Inline(pSeed) % nMax;
    else
        nResult = AIBAAL_RollSeed_Inline(pSeed) & (nMax - 1);
    return nResult;
}

static __forceinline int AIBAAL_GetRandomArrayIndex_Inline(int* pArray, int nArraySize, D2UnitStrc* pUnit, int nDefaultValue)
{
    int nSum = 0;
    int* pWeight = pArray;
    for (int i = 0; i < nArraySize; ++i)
    {
        nSum += *pWeight;
        ++pWeight;
    }

    const int nRand = AIBAAL_RollLimited_Inline(&pUnit->pSeed, nSum);

    int nThreshold = 0;
    pWeight = pArray;
    for (int i = 0; i < nArraySize; ++i)
    {
        nThreshold += *pWeight;
        if (nRand < nThreshold)
        {
            return i;
        }
        ++pWeight;
    }

    return nDefaultValue;
}

__declspec(noinline) static int __stdcall sub_005FC300_RollUberAiParam(D2GameStrc*, D2UnitStrc*, int, int, int, D2UnitStrc*);
// 0x005FC300
static int __stdcall sub_005FC300_RollUberAiParam(D2GameStrc* pGame, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, D2UnitStrc* pUnit)
{
    int aiParams[16] = { 0, 100, 20, 20, 20, 0, 20, 0, 80, 70, 0, 0, 0, 0, 0, 0 };
    if (!pGame->nDifficulty)
    {
        aiParams[1] = 125;
    }

    if (nCount < 2)
    {
        aiParams[2] = 45;
        aiParams[10] = 25;
    }

    aiParams[1] += 100 - UNITS_GetCurrentLifePercentage(pUnit);

    if (AI_CheckSpecialSkillsOnPrimeEvil(pTarget) && !bInMediumRange)
    {
        aiParams[14] = 50;
        aiParams[13] = 50;
    }
    else if (bInMediumRange)
    {
        aiParams[2] = 0;
        aiParams[6] = 0;
        aiParams[3] = 35;
        aiParams[11] = 25;
        aiParams[13] = 25;
    }

    if (bInFarRange)
    {
        aiParams[5] = 60;
    }

    return AIBAAL_GetRandomArrayIndex_Inline(aiParams, 16, pUnit, 1);
}

// build: context sub_005FC1C0_RollBaalMeleeAiParam
static __declspec(noinline) int __stdcall sub_005FC1C0_RollBaalMeleeAiParam(D2GameStrc* pGame, D2UnitStrc* pTarget, int bNotCollidingWithWall, D2UnitStrc* pUnit)
{
    int aiParams[16] = { 0, 50, 0, 0, 0, 0, 0, 0, 20, 30, 150, 10, 10, 70, 40, 0 };

    if (!pGame->nDifficulty)
    {
        aiParams[1] = 75;
        aiParams[13] = 45;
    }

    if (UNITS_GetCurrentLifePercentage(pTarget) < 33)
    {
        aiParams[10] += 50;
    }

    aiParams[1] += 100 - UNITS_GetCurrentLifePercentage(pUnit);

    if (STATES_CheckState(pTarget, 11))
    {
        aiParams[8] = 0;
        aiParams[13] = 0;
        aiParams[11] = 0;
    }

    if (!bNotCollidingWithWall)
    {
        aiParams[11] = 0;
        aiParams[13] = 0;
        aiParams[12] = 0;
    }

    return AIBAAL_GetRandomArrayIndex_M282Inline(aiParams, 16, pUnit, 1);
}

struct D2AiCmdStrc { int pad[3]; int nX; int nY; };
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* hPath); // 0x006488C0
int __stdcall PATH_GetY(void* pPath); // 0x00648900
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pUnit); // 0x005353F0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nType, int nId); // 0x00552F60
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
int __fastcall AIUTIL_GetDistanceToCoordinates_HalfUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC480
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRange); // 0x00622C40

static __forceinline int AIBAAL_GetUnitX_Inline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) {
    case 2: case 4: case 5: return ((int*)pUnit->pDynamicPath)[3];
    default: return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}
static __forceinline int AIBAAL_GetUnitY_Inline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) {
    case 2: case 4: case 5: return ((int*)pUnit->pDynamicPath)[4];
    default: return pUnit->pDynamicPath ? PATH_GetY(pUnit->pDynamicPath) : 0;
    }
}
__declspec(noinline) static int __stdcall AIBAAL_RollRandomAiParam(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, D2UnitStrc*, int, int, D2AiCmdStrc*);
// 0x005FC630
static int __stdcall AIBAAL_RollRandomAiParam(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nMax, int nCount, D2AiCmdStrc* pAiCmd)
{
    if (pAiControl->dwAiParam[0]) return pAiControl->dwAiParam[0];
    if (!pTarget)
    {
        if (COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit), AIBAAL_GetUnitX_Inline(pUnit), AIBAAL_GetUnitY_Inline(pUnit), 2, 64))
            return 4;
        return 8 * ((int)(AIBAAL_RollSeed_Inline(&pUnit->pSeed) % 100) < 8) + 1;
    }
    if (!pGame) pGame = sub_00554010_GetGame(pUnit);
    int bInCloseRange = 0;
    if ((!pTarget ? 6 : pTarget->dwUnitType) == 0)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, PLAYER_GetUniqueIdFromPlayerData(pTarget));
        if (pObject && DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pObject)) == 132)
        {
            if (!pAiCmd || UNITS_GetDistanceToCoordinates(pObject, pAiCmd->nX, pAiCmd->nY) < 75)
                bInCloseRange = 1;
        }
    }
    int bInMediumRange = 0;
    int bInFarRange = 0;
    if (pAiCmd)
    {
        const int nDistance = AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pTarget, pAiCmd->nX, pAiCmd->nY);
        if (nDistance > 75) bInMediumRange = 1;
        if (nDistance > 100) bInFarRange = 1;
    }
    const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    const int bNotCollidingWithWall = sub_005DD290_HasClearPath(pUnit, pTarget);
    if (bInMeleeRange)
        return sub_005FC1C0_RollBaalMeleeAiParam(pGame, pTarget, bNotCollidingWithWall, pUnit);
    if (bNotCollidingWithWall)
        return AIBAAL_RollRandomAiParamForNonCollidingUnit(pGame, pAiControl, pUnit, pTarget, nCount, bInMediumRange, bInFarRange, bInCloseRange, nMax);
    return sub_005FC300_RollUberAiParam(pGame, pTarget, nCount, bInMediumRange, bInFarRange, pUnit);
}

// calling-convention shim (not game code)
int __stdcall sub_005FC630_Shim(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nMax, int nCount, D2AiCmdStrc* pAiCmd)
{
    return AIBAAL_RollRandomAiParam(pGame, pUnit, pAiControl, pTarget, nMax, nCount, pAiCmd);
}

// build: context sub_005FC450_Shim

// calling-convention shim (not game code)
int __stdcall sub_005FC450_Shim(D2GameStrc* pGame, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nCount, int bMedium, int bFar, int bClose, int nMax, D2UnitStrc* pUnit)
{
    return AIBAAL_RollRandomAiParamForNonCollidingUnit(pGame, pAiControl, pUnit, pTarget, nCount, bMedium, bFar, bClose, nMax);
}
