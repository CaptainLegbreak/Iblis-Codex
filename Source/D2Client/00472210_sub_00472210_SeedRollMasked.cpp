struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

inline unsigned __int64 SEED_RollRandomNumberInline_00472210(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00472210
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax)
{
    return SEED_RollRandomNumberInline_00472210(pSeed) & (nMax - 1);
}
