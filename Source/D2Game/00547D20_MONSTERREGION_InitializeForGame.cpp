struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2MonsterRegionStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    char f_74[0x5C];
    D2SeedStrc pGameSeed;
    char unk0xD8[0x14];
    unsigned int dwMonSeed;
    D2MonsterRegionStrc* pMonReg[1024];
};

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
void __fastcall MONSTERREGION_InitializeAll(void* pMemoryPool, D2MonsterRegionStrc** ppMonsterRegion, D2SeedStrc* pSeed, int nSeed, unsigned char nDifficulty, int bExpansion); // 0x005479C0

inline unsigned __int64 ITEMS_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00547D20
void __fastcall MONSTERREGION_InitializeForGame(D2GameStrc* pGame)
{
    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);

    const int nSeed = (unsigned int)ITEMS_RollRandomNumberInline(&pGame->pGameSeed);
    SEED_InitLowSeed(&tSeed, nSeed);
    pGame->dwMonSeed = nSeed;
    MONSTERREGION_InitializeAll(pGame->pMemoryPool, pGame->pMonReg, &tSeed, nSeed, pGame->nDifficulty, pGame->bExpansion);
}
