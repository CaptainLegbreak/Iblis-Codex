struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
        unsigned __int64 lSeed;
    };
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
};

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
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
