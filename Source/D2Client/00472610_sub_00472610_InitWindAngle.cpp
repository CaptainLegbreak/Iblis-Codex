struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    char unk0x00[0x20];
    D2SeedStrc tSeed;
};

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                           // 0x00463DD0
extern int gnWeatherAngle_007A89C4;                                                                         // 0x007A89C4
extern int gnTargetAngle_007A89F8;                                                                          // 0x007A89F8
extern int gnWindCountdown_007A89E4;                                                                        // 0x007A89E4
extern int gnGlobal_007A8968;                                                                               // 0x007A8968

static __forceinline unsigned int SEED_RollFromInline(const D2SeedStrc* pSrc, D2SeedStrc* pDst)
{
    const unsigned __int64 lSeed = pSrc->nHighSeed + 0x6AC690C5i64 * pSrc->nLowSeed;
    pDst->nLowSeed = (unsigned int)lSeed;
    pDst->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLowInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x00472610
void __cdecl sub_00472610_InitWindAngle()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        D2SeedStrc tSeed;
        gnWindCountdown_007A89E4 = SEED_RollFromInline(&pPlayer->tSeed, &tSeed) % 375 + 125;
        gnGlobal_007A8968 = SEED_RollLowInline(&tSeed) % 1500 + 500;
        const unsigned int nRoll = SEED_RollLowInline(&tSeed);
        pPlayer->tSeed.nHighSeed = tSeed.nHighSeed;
        pPlayer->tSeed.nLowSeed = tSeed.nLowSeed;
        const int nAngle = nRoll % 71 + 92;
        gnWeatherAngle_007A89C4 = nAngle;
        gnTargetAngle_007A89F8 = nAngle;
    }
    else
    {
        gnWindCountdown_007A89E4 = 0x138;
        gnGlobal_007A8968 = 0x4E2;
        gnWeatherAngle_007A89C4 = 0x7F;
        gnTargetAngle_007A89F8 = 0x7F;
    }
}
