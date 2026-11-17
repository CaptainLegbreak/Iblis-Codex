struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    unsigned char nComponent[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
};

struct D2ComponentVariantStrc
{
    unsigned char nComponent[16];
};

struct D2MonRegDataStrc
{
    char unk0x00[3];
    unsigned char nComponentVariantsMax;
    D2ComponentVariantStrc nComponentVariants[1];
};

#define UNIT_MONSTER 1

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __stdcall D2COMMON_11068_GetCompInfo(D2UnitStrc* pUnit, int nComponent);                                // 0x006647C0

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// build: context MONSTER_GetComponents
static __forceinline unsigned char* MONSTER_GetComponents(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return 0;
    }

    return pMonsterData->nComponent;
}

// 0x005739D0
void __fastcall MONSTER_SetComponents(D2MonRegDataStrc* pMonRegData, D2UnitStrc* pUnit)
{
    if ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_MONSTER)
    {
        return;
    }

    if (pMonRegData && pMonRegData->nComponentVariantsMax > 0)
    {
        const D2ComponentVariantStrc* pVariant = &pMonRegData->nComponentVariants[ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pMonRegData->nComponentVariantsMax)];
        D2ComponentVariantStrc* pComponents = (D2ComponentVariantStrc*)MONSTER_GetComponents(pUnit);
        if (pComponents)
        {
            *pComponents = *pVariant;
        }
    }
    else
    {
        unsigned char* pComponents = MONSTER_GetComponents(pUnit);
        int i = 0;
        int nCount = 16;
        do
        {
            pComponents[i] = SEED_RollLimitedRandomNumber(&pUnit->pSeed, D2COMMON_11068_GetCompInfo(pUnit, i));
            ++i;
        }
        while (--nCount);
    }
}
