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

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x00477620
int __fastcall sub_00477620_RollUnitValue(D2UnitStrc* pUnit, unsigned short nOffset)
{
    if (!pUnit)
    {
        return 9;
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    SEED_InitLowSeed(pSeed, sub_00623C60(pUnit) + nOffset);
    return (unsigned int)SEED_RollRandomNumber(pSeed) % 30 + 9;
}
