struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

// 0x00650E30
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed)
{
    pSeed->nLowSeed = 1;
    pSeed->nHighSeed = 666;
}

// 0x00650E40
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed)
{
    pSeed->nLowSeed = nLowSeed;
    pSeed->nHighSeed = 666;
}
