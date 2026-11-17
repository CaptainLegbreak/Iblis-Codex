struct D2DrlgActStrc;
struct D2GameStrc;
struct D2DrlgLevelStrc;

typedef void (__fastcall* AUTOMAPFN)(void*);
typedef void (__fastcall* TOWNAUTOMAPFN)(int, int, int, int);

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1AC];
    D2DrlgLevelStrc* pNextLevel;
    char unk0x1B0[0x20];
    int nLevelId;
};

struct D2DrlgStrc
{
    D2SeedStrc pSeed;
    char unk0x008[0x84];
    unsigned int dwFlags;
    char unk0x090[0x04];
    int nStaffTombLevel;
    char unk0x098[0x04];
    D2GameStrc* pGame;
    char unk0x0A0[0x3B0];
    unsigned char nDifficulty;
    char unk0x451[0x03];
    AUTOMAPFN pfAutomap;
    unsigned int dwGameLowSeed;
    char unk0x45C[0x08];
    void* hArchive;
    char unk0x468[0x04];
    D2DrlgActStrc* pAct;
    unsigned int dwStartSeed;
    int bJungleInterlink;
    void* pMempool;
    D2DrlgLevelStrc* pLevel;
    unsigned char nAct;
    char unk0x481[0x03];
    int nBossTombLevel;
    TOWNAUTOMAPFN pfTownAutomap;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void* __fastcall DUNGEON_GetMemPoolFromAct(D2DrlgActStrc* pAct);                                            // 0x00619550
void __fastcall DRLGACTIVATE_InitializeRoomExStatusLists(D2DrlgStrc* pDrlg);                                // 0x0061B7E0
void __fastcall sub_00641F60(D2DrlgStrc* pDrlg);                                                      // 0x00641F60
void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel);                                                     // 0x006424A0
D2DrlgLevelStrc* __fastcall DRLG_AllocLevel(D2DrlgStrc* pDrlg, int nLevelId);                               // 0x00642AE0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nSeed);                                             // 0x00650E40
void __fastcall DRLGOUTPLACE_CreateLevelConnections(D2DrlgStrc* pDrlg, unsigned char nAct);                 // 0x00678AD0

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline D2DrlgLevelStrc* DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgLevelStrc* pLevel = pDrlg->pLevel; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (pLevel->nLevelId == nLevelId)
        {
            return pLevel;
        }
    }

    return DRLG_AllocLevel(pDrlg, nLevelId);
}

// 0x00642DA0
D2DrlgStrc* __fastcall DRLG_AllocDrlg(D2DrlgActStrc* pAct, unsigned char nActNo, void* hArchive, unsigned int nInitSeed, int nTownLevelId, unsigned int nFlags, D2GameStrc* pGame, unsigned char nDifficulty, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap)
{
    void* pMemPool = DUNGEON_GetMemPoolFromAct(pAct);
    D2DrlgStrc* pDrlg = (D2DrlgStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgStrc), ".\\DRLG\\Drlg.cpp", 0x3A, 0);
    memset(pDrlg, 0, sizeof(D2DrlgStrc));

    pDrlg->pMempool = pMemPool;
    pDrlg->hArchive = hArchive;
    pDrlg->nAct = nActNo;
    pDrlg->pAct = pAct;

    SEED_InitLowSeed(&pDrlg->pSeed, nInitSeed);

    pDrlg->dwStartSeed = SEED_RollRandomNumber(&pDrlg->pSeed);
    pDrlg->dwGameLowSeed = nInitSeed;
    pDrlg->dwFlags = nFlags;
    pDrlg->pGame = pGame;
    pDrlg->nDifficulty = nDifficulty;
    pDrlg->pfAutomap = pfAutoMap;
    pDrlg->pfTownAutomap = pfTownAutoMap;

    if (nActNo == 1)
    {
        unsigned int nStaffLevelOffset;
        unsigned int nBossLevelOffset;
        unsigned __int64 lSeed;
        do
        {
            lSeed = (unsigned __int64)pDrlg->pSeed.nLowSeed * 0x6AC690C5 + pDrlg->pSeed.nHighSeed;
            pDrlg->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pDrlg->pSeed.nLowSeed = (unsigned int)lSeed;
            nStaffLevelOffset = (unsigned int)lSeed % 7;
            lSeed = (unsigned __int64)pDrlg->pSeed.nLowSeed * 0x6AC690C5 + pDrlg->pSeed.nHighSeed;
            pDrlg->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pDrlg->pSeed.nLowSeed = (unsigned int)lSeed;
            nBossLevelOffset = (unsigned int)lSeed % 7;
        }
        while (nStaffLevelOffset == nBossLevelOffset);

        pDrlg->nStaffTombLevel = nStaffLevelOffset + 0x42;
        pDrlg->nBossTombLevel = nBossLevelOffset + 0x42;
    }
    else if (nActNo == 2)
    {
        pDrlg->bJungleInterlink = SEED_RollRandomNumber(&pDrlg->pSeed) & 1;
    }

    sub_00641F60(pDrlg);
    DRLGACTIVATE_InitializeRoomExStatusLists(pDrlg);
    DRLGOUTPLACE_CreateLevelConnections(pDrlg, nActNo);

    if (nTownLevelId)
    {
        DRLG_InitLevel(DRLG_GetLevel(pDrlg, nTownLevelId));
    }

    return pDrlg;
}
