#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2GameTypes.h"
#include "D2GameStrc.h"
#include "D2GameAux.h"
#include "D2PlayerModes.h"


extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);              // 0x00622C40
int __fastcall AIUTIL_GetDistanceToCoordinates_HalfUnitSize(D2UnitStrc* pUnit, int nX, int nY);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                           // 0x00621F20
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __fastcall AIUTIL_HasClearMissilePath(D2UnitStrc* pUnit, D2UnitStrc* pTarget);             // 0x005DD290

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

int __stdcall AIBAAL_GetUberTargetScore(D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiBaalTargetArgsStrc* pArgs); // 0x005FBB00

#define PATHTYPE_TOWARD 2

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY);               // 0x005DC530
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTarget);        // 0x00648B90
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nType);                                    // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int a3);                   // 0x00649970

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static D2UnitStrc* __stdcall sub_005FBDD0(D2GameStrc* pGame, int* pMax, int* pCount, D2AiBaalTargetArgsStrc* pArgs, int (__fastcall* pfCull)(D2UnitStrc*, D2UnitStrc*), D2UnitStrc* pUnit);
// 0x005FBDD0
static D2UnitStrc* __stdcall sub_005FBDD0(D2GameStrc* pGame, int* pMax, int* pCount, D2AiBaalTargetArgsStrc* pArgs, int (__fastcall* pfCull)(D2UnitStrc*, D2UnitStrc*), D2UnitStrc* pUnit)
{
    D2_ASSERT(pfCull, 0x9E);

    D2UnitStrc* pTarget = 0;
    int nMax = 0;
    int nCount = 0;
    D2TargetNodeStrc** ppTargetNode = pGame->pTargetNodes;
    D2TargetNodeStrc* pTargetNode = *ppTargetNode;
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    const unsigned char nAct = pUnit->nAct;

    for (int i = 0; i < 8; ++i)
    {
        if (pTargetNode)
        {
            D2_ASSERT(pTargetNode->hUnit && pTargetNode->hUnit->dwUnitType == UNIT_PLAYER, 0xB3);
            D2UnitStrc* pTargetUnit = pTargetNode->hUnit;

            if (pfCull(pUnit, pTargetUnit))
            {
                int nCurrent;
                if (pTargetUnit && pTargetUnit->dwAnimMode != PLRMODE_DEAD && pTargetUnit->dwAnimMode != PLRMODE_DEATH)
                {
                    nCurrent = AIBAAL_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
                }
                else
                {
                    nCurrent = 0;
                }

                while (1)
                {
                    if (nMax < nCurrent)
                    {
                        nMax = nCurrent;
                        pTarget = pTargetUnit;
                    }

                    pTargetNode = pTargetNode->pNext;
                    ++nCount;

                    if (!pTargetNode)
                    {
                        break;
                    }

                    pTargetUnit = pTargetNode->hUnit;
                    nCurrent = AIBAAL_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
                }
            }
        }

        pTargetNode = *++ppTargetNode;
    }

    while (pTargetNode)
    {
        D2UnitStrc* pTargetUnit = pTargetNode->hUnit;
        if (nAct == pTargetUnit->nAct)
        {
            const int nCurrent = AIBAAL_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
            if (nMax < nCurrent)
            {
                nMax = nCurrent;
                pTarget = pTargetUnit;
            }
            ++nCount;
        }

        pTargetNode = pTargetNode->pNext;
    }

    pTargetNode = ppTargetNode[1];

    D2UnitStrc* pTemp = 0;
    int nTemp = 0;
    if (pTargetNode)
    {
        do
        {
            D2UnitStrc* pTargetUnit = pTargetNode->hUnit;
            if (nAct == pTargetUnit->nAct)
            {
                const int nCurrent = AIBAAL_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
                if (nTemp < nCurrent)
                {
                    nTemp = nCurrent;
                    pTemp = pTargetUnit;
                }
            }

            pTargetNode = pTargetNode->pNext;
        }
        while (pTargetNode);

        if (pTemp && AIUTIL_GetDistanceToCoordinates_NoUnitSize(pTemp, nX, nY) < 5 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            sub_00648B90_SetPathTarget(pPath, pTarget);
            PATH_SetType(pPath, PATHTYPE_TOWARD);
            D2Common_10142(pPath, pUnit, 0);

            if (!PATH_GetNumberOfPathPoints(pPath))
            {
                pTarget = pTemp;
                nMax = nTemp;
            }
        }
    }

    *pCount = nCount;
    *pMax = nMax;

    return pTarget;
}

struct D2PlayerCountBonusStrc
{
    int nHP;
    int nExperience;
    int nMonsterSkillBonus;
    int nDifficulty;
    int nPlayerCount;
};
void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc* pGame, D2PlayerCountBonusStrc* pPlayerCountBonus, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMonster); // 0x00573930
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pUnit, D2UnitStrc* pTarget);        // 0x005DC380
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

static inline unsigned __int64 AIBAAL_RollSeed_M282Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static inline unsigned int AIBAAL_RollLimited_M282Inline(D2SeedStrc* pSeed, int nMax)
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

static inline int AIBAAL_GetRandomArrayIndex_M282Inline(int* pArray, int nArraySize, D2UnitStrc* pUnit, int nDefaultValue)
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

int AIBAAL_IsDangerousSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x005FC070

static inline int AIBAAL_GetSkillId_Inline(D2SkillStrc* pSkill)
{
    return SKILLS_GetSkillIdFromSkill(pSkill, gszAiBaalSourceFile, 0x131);
}

int AI_CheckSpecialSkillsOnPrimeEvil(D2UnitStrc* pUnit); // 0x005FC0C0

static int __stdcall AIBAAL_RollRandomAiParamForNonCollidingUnit(D2GameStrc* pGame, D2AiControlStrc* pAiControl, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, int bInCloseRange, int nMax); // 0x005FC450

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

static inline unsigned int AIBAAL_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int AIBAAL_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
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

static inline int AIBAAL_GetRandomArrayIndex_Inline(int* pArray, int nArraySize, D2UnitStrc* pUnit, int nDefaultValue)
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

static int __stdcall AIBAAL_RollRangedAiParam(D2GameStrc*, D2UnitStrc*, int, int, int, D2UnitStrc*);
// 0x005FC300
static int __stdcall AIBAAL_RollRangedAiParam(D2GameStrc* pGame, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, D2UnitStrc* pUnit)
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

int __stdcall AIBAAL_RollMeleeAiParam(D2GameStrc* pGame, D2UnitStrc* pTarget, int bNotCollidingWithWall, D2UnitStrc* pUnit); // 0x005FC1C0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* hPath); // 0x006488C0
int __stdcall PATH_GetY(void* pPath); // 0x00648900
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pUnit); // 0x005353F0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nType, int nId); // 0x00552F60
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall sub_006417F0_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0

static inline int AIBAAL_GetUnitX_Inline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return ((int*)pUnit->pDynamicPath)[3];
    default: return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}
static inline int AIBAAL_GetUnitY_Inline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return ((int*)pUnit->pDynamicPath)[4];
    default: return pUnit->pDynamicPath ? PATH_GetY(pUnit->pDynamicPath) : 0;
    }
}
static int __stdcall AIBAAL_RollRandomAiParam(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, D2UnitStrc*, int, int, D2AiCmdStrc*);
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
        if (pObject && DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pObject)) == LEVEL_THEWORLDSTONECHAMBER)
        {
            if (!pAiCmd || sub_006417F0_GetDistanceToXY(pObject, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]) < 75)
                bInCloseRange = 1;
        }
    }
    int bInMediumRange = 0;
    int bInFarRange = 0;
    if (pAiCmd)
    {
        const int nDistance = AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pTarget, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]);
        if (nDistance > 75) bInMediumRange = 1;
        if (nDistance > 100) bInFarRange = 1;
    }
    const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    const int bNotCollidingWithWall = sub_005DD290_HasClearPath(pUnit, pTarget);
    if (bInMeleeRange)
        return AIBAAL_RollMeleeAiParam(pGame, pTarget, bNotCollidingWithWall, pUnit);
    if (bNotCollidingWithWall)
        return AIBAAL_RollRandomAiParamForNonCollidingUnit(pGame, pAiControl, pUnit, pTarget, nCount, bInMediumRange, bInFarRange, bInCloseRange, nMax);
    return AIBAAL_RollRangedAiParam(pGame, pTarget, nCount, bInMediumRange, bInFarRange, pUnit);
}

typedef int(__fastcall* CULLFN)(D2UnitStrc*, D2UnitStrc*);
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0
void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40
int __fastcall AIBAAL_CullPotentialTargets(D2UnitStrc* pBaal, D2UnitStrc* pTarget); // 0x005FC000
void __fastcall AIBAAL_MainSkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nParam, D2AiCmdStrc* pAiCmd); // 0x005FCB60
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE0F0

static inline int UNITS_GetXPos(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    if (pUnit->pDynamicPath)
    {
        return PATH_GetXPosition(pUnit->pDynamicPath);
    }

    return 0;
}

static inline int UNITS_GetYPos(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    if (pUnit->pDynamicPath)
    {
        return PATH_GetYPosition(pUnit->pDynamicPath);
    }

    return 0;
}

// 0x005FCFE0
void __fastcall AITHINK_Fn135_BaalCrab(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nMax = 0;
    int nCount = 0;

    D2UnitStrc* pTarget = sub_005FBDD0(pGame, &nMax, &nCount, 0, AIBAAL_CullPotentialTargets, pUnit);
    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pAiCmd)
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 10;
        aiCmd.nCmdParam[1] = UNITS_GetXPos(pUnit);
        aiCmd.nCmdParam[2] = UNITS_GetYPos(pUnit);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
        pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nParam = AIBAAL_RollRandomAiParam(pGame, pUnit, pAiControl, pTarget, nMax, nCount, pAiCmd);
    AIBAAL_MainSkillHandler(pGame, pUnit, pAiControl, pTarget, nParam, pAiCmd);
    AITACTICS_Idle(pGame, pUnit, 25);
}
