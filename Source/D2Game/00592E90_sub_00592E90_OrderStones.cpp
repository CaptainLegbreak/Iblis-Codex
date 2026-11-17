struct D2GameStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2QuestDataStrc
{
    int unk0x00;
    D2GameStrc* pGame;
    char unk0x08[0x10];
    void* pQuestDataEx;
};

struct D2Act1Quest4Strc
{
    unsigned short nStoneOrder[6];
    unsigned short nStoneCount;
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame); // 0x005438B0
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00592E90
void __fastcall sub_00592E90_OrderStones(D2QuestDataStrc* pQuestData)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    int nStones[5] = { 17, 18, 19, 20, 21 };
    char szMessage[80];

    for (int i = 0; i < 5; ++i)
    {
        pQuestDataEx->nStoneOrder[i] = 0;
    }
    pQuestDataEx->nStoneCount = 0;

    int nCounter = 0;
    int nMax = 5;
    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pQuestData->pGame);
    while (nCounter < 5)
    {
        const unsigned int nRand = SEED_RollRandomNumber(pSeed) % nMax;
        if (!pQuestDataEx->nStoneOrder[nRand])
        {
            sprintf(szMessage, "stone %d is class %d", nRand, nStones[nCounter]);
            QUESTS_DebugOutput(pQuestData->pGame, szMessage, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 1329);
            pQuestDataEx->nStoneOrder[nRand] = nStones[nCounter];
            ++nCounter;
        }
    }
}
