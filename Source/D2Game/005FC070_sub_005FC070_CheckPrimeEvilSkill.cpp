struct D2SkillStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
};

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20

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
