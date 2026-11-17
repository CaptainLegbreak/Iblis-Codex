struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

extern D2SeedStrc* gpClientSeed_00712C4C;                                                                   // 0x00712C4C
extern int gnStarFieldHeight_007A521C;                                                                      // 0x007A521C
extern int gnStarFieldWidth_007A5220;                                                                       // 0x007A5220
extern unsigned char gaStarShades_007B8D24[8];                                                              // 0x007B8D24
extern int gaStarX_007B8D30[256];                                                                           // 0x007B8D30
extern int gaStarY_007B57E8[256];                                                                           // 0x007B57E8
extern unsigned char gaStarColor_007B5688[256];                                                             // 0x007B5688
extern int gaStarSpeed_007B9130[256];                                                                       // 0x007B9130
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C390

static __forceinline unsigned int STARS_Roll(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int STARS_RollLH(D2SeedStrc* pSeed, unsigned int nLow, unsigned int nHigh)
{
    const unsigned __int64 lSeed = nHigh + 0x6AC690C5i64 * nLow;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int STARS_RollUpTo(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    const unsigned int nLow = pSeed->nLowSeed;
    const unsigned int nHigh = pSeed->nHighSeed;
    if ((nMax - 1) & nMax)
    {
        return STARS_RollLH(pSeed, nLow, nHigh) % nMax;
    }

    return STARS_RollLH(pSeed, nLow, nHigh) & (nMax - 1);
}

// 0x00476190
void __stdcall sub_00476190_ResetStar(int nStar, int bRespawn)
{
    int* const pX = &gaStarX_007B8D30[nStar];
    D2SeedStrc* pSeed = gpClientSeed_00712C4C;
    const int nX = bRespawn ? (STARS_Roll(pSeed) & 7) + gnStarFieldWidth_007A5220 - 1 : SEED_RollLimitedRandomNumber(pSeed, gnStarFieldWidth_007A5220);
    const int nHeight = gnStarFieldHeight_007A521C;
    *pX = nX;
    gaStarY_007B57E8[nStar] = STARS_RollUpTo(pSeed, nHeight);
    gaStarSpeed_007B9130[nStar] = -(int)(STARS_Roll(pSeed) % 5) - 1;
    gaStarColor_007B5688[nStar] = gaStarShades_007B8D24[STARS_Roll(pSeed) & 7];
}
