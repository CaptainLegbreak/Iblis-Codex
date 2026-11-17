struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

enum
{
    ITEMQUAL_INFERIOR = 1,
    ITEMQUAL_NORMAL = 2,
    ITEMQUAL_SUPERIOR = 3,
};

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00576900
int __fastcall sub_00576900_RollStoreItemQuality(D2SeedStrc* pSeed, unsigned int dwCode, int nItemLevel)
{
    int nQuality = ITEMQUAL_NORMAL;
    const unsigned int nRoll = (unsigned int)SEED_RollRandomNumber(pSeed) % 100;

    if (nItemLevel < 5)
    {
        if (nRoll > 90)
        {
            nQuality = ITEMQUAL_INFERIOR;
        }
    }
    else if (nItemLevel < 10)
    {
        if (nRoll > 85)
        {
            nQuality = ITEMQUAL_SUPERIOR;
        }
    }
    else if (nRoll >= 75)
    {
        nQuality = ITEMQUAL_SUPERIOR;
    }

    return nQuality;
}
