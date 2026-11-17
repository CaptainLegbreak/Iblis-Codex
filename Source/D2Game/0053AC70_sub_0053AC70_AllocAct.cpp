struct D2DrlgActStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x0E];
    unsigned int dwInitSeed;
    char unk0x80[0x3C];
    D2DrlgActStrc* pAct[5];
};

typedef void (__fastcall* AUTOMAPFN)(void*);
typedef void (__fastcall* TOWNAUTOMAPFN)(void*);

unsigned int __fastcall ARENA_IsInArenaMode(D2GameStrc* pGame);                                             // 0x0053FCE0
int __fastcall ARENA_GetAlternateStartTown(D2GameStrc* pGame);                                              // 0x0053F5D0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct);                                          // 0x0061AB70
D2DrlgActStrc* __stdcall DUNGEON_AllocAct(unsigned char nAct, unsigned int nInitSeed, int bClient, D2GameStrc* pGame, unsigned char nDifficulty, void* pMemPool, int nTownLevelId, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap); // 0x006194A0
void __fastcall sub_0059AC40(D2GameStrc* pGame, unsigned char nAct);                                        // 0x0059AC40

// 0x0053AC70
static void sub_0053AC70_AllocAct(D2GameStrc* pGame, unsigned char nAct)
{
    int nTownLevelId;
    if (ARENA_IsInArenaMode(pGame))
    {
        nTownLevelId = ARENA_GetAlternateStartTown(pGame);
    }
    else
    {
        nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nAct);
    }

    pGame->pAct[nAct] = DUNGEON_AllocAct(nAct, pGame->dwInitSeed, 0, pGame, pGame->nDifficulty, pGame->pMemoryPool, nTownLevelId, 0, 0);
    sub_0059AC40(pGame, nAct);
}

// 0x0053AFB0
void __fastcall sub_0053AFB0_EnsureAct(D2GameStrc* pGame, unsigned char nAct)
{
    if (!pGame->pAct[nAct])
    {
        sub_0053AC70_AllocAct(pGame, nAct);
    }
}
