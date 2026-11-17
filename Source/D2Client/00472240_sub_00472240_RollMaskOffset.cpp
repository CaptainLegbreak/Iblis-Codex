struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

extern "C" double __cdecl fabs(double x);

inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00472240
int __fastcall sub_00472240_RollMaskOffset(D2SeedStrc* pSeed, int nOffset, int nRange)
{
    return (SEED_RollRandomNumberInline(pSeed) & (nRange - 1)) + nOffset;
}

// 0x004722F0
float __stdcall sub_004722F0_AbsFloatStd(float fValue)
{
    return (float)fabs(fValue);
}

// 0x00472310
float __cdecl sub_00472310_AbsFloat(float fValue)
{
    return (float)fabs(fValue);
}
