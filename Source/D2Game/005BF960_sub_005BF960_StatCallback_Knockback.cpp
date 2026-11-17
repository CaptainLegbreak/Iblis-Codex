struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[6];
    D2SeedStrc pSeed;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
};

struct D2MonStats2Txt
{
    int dwId;
    unsigned char nFlags[4];
};

#define UNIT_MONSTER 1
#define MONSTATS2FLAGINDEX_SMALL 10
#define MONSTATS2FLAGINDEX_LARGE 11

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

static inline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x005BF960
int __stdcall sub_005BF960_StatCallback_Knockback(D2UnitStrc* pUnit, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned int nStatLayer, int nUnused)
{
    if (!pUnit || !pDefender || !pDamage)
    {
        return 0;
    }

    if (STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, nStatLayer >> 16, nStatLayer) <= 0)
    {
        return 0;
    }

    int nChance = 64;
    if (sub_0044BE50(pDefender) == UNIT_MONSTER)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(sub_00623C60(pDefender));
        if (pMonStats2TxtRecord)
        {
            if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_LARGE >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_LARGE & 7])
            {
                nChance = 32;
            }
            else if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_SMALL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_SMALL & 7])
            {
                nChance = 128;
            }
        }
    }

    if ((int)(SEED_RollRandomNumber(&pUnit->pSeed) & 127) >= nChance)
    {
        return 0;
    }

    pDamage->wResultFlags |= 8;
    return 1;
}
