#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2AiBaalTargetArgsStrc;
struct D2SkillsTxt;
struct D2MonStatsTxt;
struct D2MonsterDataStrc;
struct D2AiTableStrc;
struct D2SeedStrc;

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
    char unk0x08[12];
    D2MonsterDataStrc* pMonsterData;
    unsigned char nAct;
    unsigned char unk_19[0x7];
    D2SeedStrc pSeed;
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
int __fastcall AIUTIL_GetDistanceToCoordinates_HalfUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC480
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __fastcall sub_005DD290_NoMissileBarrierCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DD290

struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2AiTableStrc
{
    int unk0x00;
    void* unk0x04;
    void* pAiParamFn;
    void* unk0x0C;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC530

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

static __declspec(noinline) int __stdcall AI_GetRandomArrayIndex(int* pArray, int nArraySize, D2UnitStrc* pUnit);

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

// 0x005FBB00
static __declspec(noinline) int __stdcall sub_005FBB00_GetUberTargetScore(D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiBaalTargetArgsStrc* pArgs)
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

int __stdcall sub_M244_Emit_005FBB00(D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiBaalTargetArgsStrc* pArgs)
{
    return sub_005FBB00_GetUberTargetScore(pUnit, pTarget, pArgs) * 7 + 0x3D1;
}

// 0x005FC000
int __fastcall AIBAAL_CullPotentialTargets(D2UnitStrc* pBaal, D2UnitStrc* pTarget)
{
    D2_ASSERT(pBaal, 285);
    D2_ASSERT(pTarget, 286);

    if (pBaal->nAct != pTarget->nAct)
    {
        return 0;
    }

    return (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pTarget, CLIENTS_GetUnitX(pBaal), CLIENTS_GetUnitY(pBaal)) < 1020;
}

// 0x005FC070
static int sub_005FC070_CheckPrimeEvilSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\Ai\\AiBaal.cpp", 0x131);
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
    return SKILLS_GetSkillIdFromSkill(pSkill, ".\\Ai\\AiBaal.cpp", 0x131);
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

// build: context AIBAAL_RollLimited_Inline
static __forceinline int AIBAAL_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return AIBAAL_RollSeed_Inline(pSeed) % nMax;
    }

    return AIBAAL_RollSeed_Inline(pSeed) & (nMax - 1);
}

static __forceinline int AIBAAL_GetRandomArrayIndex_Inline(int* pArray, int nArraySize, D2UnitStrc* pUnit, int nDefaultValue)
{
    int nSum = 0;
    for (int i = 0; i < nArraySize; ++i)
    {
        nSum += pArray[i];
    }

    const int nRand = AIBAAL_RollLimited_Inline(&pUnit->pSeed, nSum);

    int nThreshold = 0;
    for (int i = 0; i < nArraySize; ++i)
    {
        nThreshold += pArray[i];
        if (nRand < nThreshold)
        {
            return i;
        }
    }

    return nDefaultValue;
}

static int __stdcall sub_005FC300_RollUberAiParam(D2GameStrc* pGame, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, D2UnitStrc* pUnit)
{
    int nBonus = 100;
    int aiParams[16] = { 0, 0, 20, 20, 20, 0, 20, 0, 80, 70, 0, 0, 0, 0, 0, 0 };
    if (!pGame->nDifficulty)
    {
        nBonus = 125;
    }

    if (nCount < 2)
    {
        aiParams[2] = 45;
        aiParams[10] = 25;
    }

    aiParams[1] = nBonus + (100 - UNITS_GetCurrentLifePercentage(pUnit));

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

// 0x005FC130
static int __stdcall AI_GetRandomArrayIndex(int* pArray, int nArraySize, D2UnitStrc* pUnit)
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

    return 1;
}

int __fastcall GetRandomArrayIndexContext(D2UnitStrc* pUnit, int nArraySize, int* pArray)
{
    return AI_GetRandomArrayIndex(pArray, nArraySize, pUnit);
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

// 0x005FC1C0
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

int __stdcall sub_M282_Emit_005FC1C0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int bFlag, int nExtra)
{
    return sub_005FC1C0_RollBaalMeleeAiParam(pGame, pTarget, bFlag, pUnit) + nExtra * 3;
}
