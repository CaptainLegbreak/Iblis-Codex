#include "D2Game.h"

#define UNIT_PLAYER 0
#define PLRMODE_DEATH 0
#define PLRMODE_DEAD 17
#define PATHTYPE_TOWARD 2
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2StaticPathStrc;
struct D2TargetNodeStrc;
struct D2AiBaalTargetArgsStrc;
struct D2SkillsTxt;
struct D2MonStatsTxt;
struct D2SeedStrc;
struct D2PlayerCountBonusStrc;
struct D2AiCmdStrc;

enum D2C_M244AiBaalConstants
{
    UNIT_MONSTER = 1,
    STAT_DAMAGERESIST = 0x24,
    STAT_MAGICRESIST = 0x25,
    STAT_FIRERESIST = 0x27,
    STAT_LIGHTRESIST = 0x29,
    STAT_COLDRESIST = 0x2B,
    STAT_MAXDAMAGE = 0x16,
    STAT_FIREMAXDAM = 0x31,
    STAT_LIGHTMAXDAM = 0x33,
    STAT_MAGICMAXDAM = 0x35,
    STAT_COLDMAXDAM = 0x37,
    STAT_POISONMAXDAM = 0x3A,
    STATE_COLD = 0x0B,
};

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned __int64 lSeed;
        };
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
    };
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    void* f_14;
    unsigned char nAct;
    unsigned char unk_19[0x7];
    D2SeedStrc pSeed;
    int unk0x28;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
        void* pPath;
    };
};

struct D2TargetNodeStrc
{
    D2UnitStrc* pUnit;
    int unk0x04;
    D2TargetNodeStrc* pNext;
    D2TargetNodeStrc* unk0x0C;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    unsigned char unk_6E[0x108A];
    D2TargetNodeStrc* pTargetNodes[10];
};

struct D2AiBaalTargetArgsStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2SkillsTxt
{
    char unk0x000[0x18E];
    unsigned char nAttackRank;
    char unk0x18F[0xAD];
};

struct D2MonStatsTxt
{
    char unk0x000[0x4E];
    unsigned char nThreat;
    char unk0x04F[0x159];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x114];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
int __fastcall AIUTIL_GetDistanceToCoordinates_HalfUnitSize(D2UnitStrc* pUnit, int nX, int nY);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __fastcall sub_005DD290_NoMissileBarrierCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DD290
__declspec(noinline) static int __stdcall sub_005FBB00_GetUberTargetScore(D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiBaalTargetArgsStrc* pArgs);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC530
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTarget); // 0x00648B90
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nType); // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int a3); // 0x00649970
__declspec(noinline) static D2UnitStrc* __stdcall sub_005FBDD0(D2GameStrc* pGame, int* pMax, int* pCount, D2AiBaalTargetArgsStrc* pArgs, int (__fastcall* pfCull)(D2UnitStrc*, D2UnitStrc*), D2UnitStrc* pUnit);

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

void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc* pGame, D2PlayerCountBonusStrc* pPlayerCountBonus, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMonster); // 0x00573930
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DC380
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
__declspec(noinline) static int sub_005FC070_CheckPrimeEvilSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
__declspec(noinline) static int AI_CheckSpecialSkillsOnPrimeEvil(D2UnitStrc* pUnit);
__declspec(noinline) static int __stdcall AIBAAL_RollRandomAiParamForNonCollidingUnit(D2GameStrc* pGame, D2AiControlStrc* pAiControl, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, int bInCloseRange, int nMax); // 0x005FC450
__declspec(noinline) static int __stdcall sub_005FC300_RollUberAiParam(D2GameStrc*, D2UnitStrc*, int, int, int, D2UnitStrc*);

struct D2AiCmdStrc { int pad[3]; int nX; int nY; };

int __stdcall PATH_GetX(void* pPath); // 0x006488C0
int __stdcall PATH_GetY(void* pPath); // 0x00648900
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nPattern, int nMask); // 0x0064D910
int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pUnit); // 0x005353F0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nType, int nId); // 0x00552F60
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRange); // 0x00622C40
__declspec(noinline) static int __stdcall AIBAAL_RollRandomAiParam(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, D2UnitStrc*, int, int, D2AiCmdStrc*);

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

// build: context sub_005FBB00_GetUberTargetScore
static int __stdcall sub_005FBB00_GetUberTargetScore(D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiBaalTargetArgsStrc* pArgs)
{
    const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);

    int nDistanceWeight = 0;
    if (pArgs && AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pUnit, pArgs->nX, pArgs->nY) > 75 && AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pTarget, pArgs->nX, pArgs->nY) < 75)
    {
        nDistanceWeight = 100;
    }

    const int nDamageResist = STATLIST_UnitGetStatValue(pTarget, STAT_DAMAGERESIST, 0);
    const int nFireResist = STATLIST_UnitGetStatValue(pTarget, STAT_FIRERESIST, 0);
    const int nLightningResist = STATLIST_UnitGetStatValue(pTarget, STAT_LIGHTRESIST, 0);
    const int nMagicResist = STATLIST_UnitGetStatValue(pTarget, STAT_MAGICRESIST, 0);
    const int nColdResist = STATLIST_UnitGetStatValue(pTarget, STAT_COLDRESIST, 0);
    const int nResistWeight = (nFireResist + nColdResist + nLightningResist + 4 * (nDamageResist + 2 * nMagicResist)) / 15;

    const int nMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_MAXDAMAGE, 0);
    const int nFireMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_FIREMAXDAM, 0);
    const int nLightningMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_LIGHTMAXDAM, 0);
    const int nMagicMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_MAGICMAXDAM, 0);
    const int nColdMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_COLDMAXDAM, 0);
    const int nPoisonMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_POISONMAXDAM, 0) >> 8;
    const int nDamageWeight = (nMaxDamage + nFireMaxDamage + nLightningMaxDamage + nMagicMaxDamage + nColdMaxDamage + nPoisonMaxDamage) / 2;

    const int nColdStateWeight = STATES_CheckState(pTarget, STATE_COLD) ? 100 : 0;
    const int nLifePercentageWeight = UNITS_GetCurrentLifePercentage(pTarget) < 20 ? 100 : 0;

    int nLeftSkillLevel;
    int nRightSkillLevel;
    int nLeftSkillAttackRank;
    int nRightSkillAttackRank;
    nLeftSkillLevel = 0;
    nRightSkillLevel = 0;
    nLeftSkillAttackRank = 0;
    nRightSkillAttackRank = 0;

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pTarget);
    if (pLeftSkill)
    {
        nLeftSkillLevel = SKILLS_GetSkillLevel(pTarget, pLeftSkill, 1);
        nLeftSkillAttackRank = SKILLS_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\Ai\\AiBaal.cpp", 0x75))->nAttackRank;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pTarget);
    if (pRightSkill)
    {
        nRightSkillLevel = SKILLS_GetSkillLevel(pTarget, pRightSkill, 1);
        nRightSkillAttackRank = SKILLS_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\Ai\\AiBaal.cpp", 0x7B))->nAttackRank;
    }

    const int nAttackRankWeight = (nLeftSkillLevel * nLeftSkillAttackRank + nRightSkillLevel * nRightSkillAttackRank) / 4;

    int nCollisionRangeWeight = 0;
    if (bInMeleeRange)
    {
        nCollisionRangeWeight = 100;
    }
    else if (sub_005DD290_NoMissileBarrierCollision(pUnit, pTarget))
    {
        nCollisionRangeWeight = 75;
    }

    if (pTarget && pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pTarget->dwClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        if (pMonStatsTxtRecord->nThreat <= 1)
        {
            return 0;
        }
    }

    int nTotalScore = (nResistWeight + 5 * (nCollisionRangeWeight + nDistanceWeight) + 2 * (nDamageWeight + nAttackRankWeight + 2 * nColdStateWeight) + 3 * nLifePercentageWeight) / 22;
    if (!nTotalScore)
    {
        nTotalScore = 1;
    }

    return nTotalScore;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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
            D2_ASSERT(pTargetNode->pUnit && pTargetNode->pUnit->dwUnitType == UNIT_PLAYER, 0xB3);
            D2UnitStrc* pTargetUnit = pTargetNode->pUnit;

            if (pfCull(pUnit, pTargetUnit))
            {
                int nCurrent;
                if (pTargetUnit && pTargetUnit->dwAnimMode != PLRMODE_DEAD && pTargetUnit->dwAnimMode != PLRMODE_DEATH)
                {
                    nCurrent = sub_005FBB00_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
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

                    pTargetUnit = pTargetNode->pUnit;
                    nCurrent = sub_005FBB00_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
                }
            }
        }

        pTargetNode = *++ppTargetNode;
    }

    while (pTargetNode)
    {
        D2UnitStrc* pTargetUnit = pTargetNode->pUnit;
        if (nAct == pTargetUnit->nAct)
        {
            const int nCurrent = sub_005FBB00_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
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
            D2UnitStrc* pTargetUnit = pTargetNode->pUnit;
            if (nAct == pTargetUnit->nAct)
            {
                const int nCurrent = sub_005FBB00_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
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

            if (!sub_00648780_pointCount(pPath))
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

D2UnitStrc* __stdcall sub_Emit_005FBDD0(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pMax, int* pCount, D2AiBaalTargetArgsStrc* pArgs, int (__fastcall* pfCull)(D2UnitStrc*, D2UnitStrc*))
{
    return sub_005FBDD0(pGame, pMax, pCount, pArgs, pfCull, pUnit);
}

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

int __stdcall sub_B01_Emit_005FC300(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange)
{
    return sub_005FC300_RollUberAiParam(pGame, pTarget, nCount, bInMediumRange, bInFarRange, pUnit);
}

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
        if (nRand < nThreshold)
        {
            return i;
        }
        ++pPick;
    }

    return nDefaultValue;
}

// 0x005FC450
static int __stdcall AIBAAL_RollRandomAiParamForNonCollidingUnit(D2GameStrc* pGame, D2AiControlStrc* pAiControl, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, int bInCloseRange, int nMax)
{
    int aiParams[16] = { 0, 100, 5, 5, 5, 0, 5, 0, 40, 40, 0, 70, 80, 60, 20, 0 };
    if (!pGame->nDifficulty)
    {
        aiParams[1] = 125;
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

    aiParams[1] += 100 - UNITS_GetCurrentLifePercentage(pUnit);
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

static __forceinline int AIBAAL_GetUnitX_Inline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) {
    case 2: case 4: case 5: return ((int*)pUnit->pPath)[3];
    default: return pUnit->pPath ? PATH_GetX(pUnit->pPath) : 0;
    }
}

static __forceinline int AIBAAL_GetUnitY_Inline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) {
    case 2: case 4: case 5: return ((int*)pUnit->pPath)[4];
    default: return pUnit->pPath ? PATH_GetY(pUnit->pPath) : 0;
    }
}

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
