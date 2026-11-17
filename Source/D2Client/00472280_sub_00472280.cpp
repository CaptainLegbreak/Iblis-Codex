struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// build: context RNG_RollLimitedRef
__forceinline unsigned int RNG_RollLimitedRef(D2SeedStrc* pSeed, const int& nMax)
{
    if (nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return (unsigned int)SEED_RollRandomNumberInline(pSeed) % nMax;
    const unsigned int nRoll = (unsigned int)SEED_RollRandomNumberInline(pSeed);
    const int nMask = nMax;
    return nRoll & (nMask - 1);
}

// 0x00472280
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange)
{
    return nOffset + RNG_RollLimitedRef(pSeed, nRange);
}
