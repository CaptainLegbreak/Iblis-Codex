#include "D2Structs.h"
#include "D2UnitData.h"
struct D2BitBufferStrc;
struct D2QuestInfoStrc;


struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0xB0];
    D2SeedStrc pGameSeed;
    char unk0xD8[0x101C];
    D2QuestInfoStrc* pQuestControl;
};


struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
    int bExecuting;
    int bPickedSet;
    D2BitBufferStrc* pQuestFlags;
    void* pTimer;
    unsigned int dwTick;
    D2SeedStrc pSeed;
    int unk0x20;
};

typedef char QUESTINIT_check_data[sizeof(D2QuestDataStrc) == 0xF8 ? 1 : -1];
typedef char QUESTINIT_check_info[sizeof(D2QuestInfoStrc) == 0x24 ? 1 : -1];
typedef char QUESTINIT_check_game[sizeof(D2GameStrc) == 0x10F8 ? 1 : -1];

typedef void (__fastcall* QUESTINIT)(D2QuestDataStrc* pQuestData);
typedef int (__stdcall* FARPROC)();

struct D2QuestInitTableStrc
{
    QUESTINIT pfInit;
    unsigned char bAct;
    unsigned char pad0x05[3];
    unsigned int nVersion;
    unsigned char bNoSetState;
    unsigned char pad0x0D[3];
    int nChainNo;
    int nQuestNo;
};

struct D2QuestIntroTableStrc
{
    QUESTINIT pfInit;
    unsigned char nAct;
    unsigned char pad0x05[3];
};

extern D2QuestInitTableStrc sgQuestInit[];                                                    // 0x00731510
extern int gnQuestInitTableCount_00731888;                                                                  // 0x00731888
extern D2QuestIntroTableStrc sgQuestIntro[];                                                  // 0x0073188C
extern int gnQuestIntroTableCount_007318AC;                                                                 // 0x007318AC

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
#pragma function(memset)

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool);                                         // 0x0065C430

#define QUESTS_SEED_STEP_HIGH_FIRST(pSeed, nOut) { const unsigned __int64 lSeed_ = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; (pSeed)->nHighSeed = (unsigned int)(lSeed_ >> 32); (pSeed)->nLowSeed = (unsigned int)lSeed_; nOut = (unsigned int)lSeed_; }

static __forceinline void QUESTS_InitQuestData(D2QuestDataStrc* pQuestData, D2GameStrc* pGame, int nChainNo, unsigned char nAct)
{
    memset(pQuestData, 0, sizeof(D2QuestDataStrc));
    pQuestData->nQuestNo = nChainNo;
    pQuestData->pGame = pGame;
    pQuestData->bActive = 0;
    pQuestData->fLastState = 0;
    pQuestData->bNotIntro = 1;
    pQuestData->nActNo = nAct;
    pQuestData->tPlayerGUIDs.nPlayerCount = 0;
}

// 0x00545D80
void __fastcall QUESTS_QuestInit(D2GameStrc* pGame)
{
    D2QuestDataStrc* pPrev = 0;
    D2QuestDataStrc* pCurrent = 0;
    int i;

    for (i = 0; i < gnQuestInitTableCount_00731888; ++i)
    {
        pCurrent = (D2QuestDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2QuestDataStrc), gszQuestsSourceFile, 0x195, 0);
        QUESTS_InitQuestData(pCurrent, pGame, sgQuestInit[i].nChainNo, sgQuestInit[i].bAct);
        pCurrent->pPrev = pPrev;
        pPrev = pCurrent;

        if (sgQuestInit[i].pfInit)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)sgQuestInit[i].pfInit), 0x19B);
            sgQuestInit[i].pfInit(pCurrent);
        }
    }

    for (i = 0; i < gnQuestIntroTableCount_007318AC; ++i)
    {
        pCurrent = (D2QuestDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2QuestDataStrc), gszQuestsSourceFile, 0x1A1, 0);
        memset(pCurrent, 0, sizeof(D2QuestDataStrc));

        pCurrent->nQuestNo = i + 37;
        pCurrent->pGame = pGame;
        pCurrent->bActive = 1;
        pCurrent->fLastState = 0;
        pCurrent->bNotIntro = 0;
        pCurrent->nActNo = sgQuestIntro[i].nAct;
        pCurrent->pPrev = pPrev;
        pPrev = pCurrent;

        if (sgQuestIntro[i].pfInit)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)sgQuestIntro[i].pfInit), 0x1AD);
            sgQuestIntro[i].pfInit(pCurrent);
        }
    }

    D2QuestInfoStrc* pQuestInfo = (D2QuestInfoStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2QuestInfoStrc), gszQuestsSourceFile, 0x1B2, 0);
    pQuestInfo->bPickedSet = 0;
    pQuestInfo->pLastQuest = pCurrent;
    pQuestInfo->pTimer = 0;
    pQuestInfo->dwTick = 0;

    SEED_InitSeed(&pQuestInfo->pSeed);
    unsigned int nLow;
    QUESTS_SEED_STEP_HIGH_FIRST(&pGame->pGameSeed, nLow);
    SEED_InitLowSeed(&pQuestInfo->pSeed, nLow);
    pQuestInfo->bExecuting = 0;

    pQuestInfo->pQuestFlags = QUESTRECORD_AllocRecord(pGame->pMemoryPool);

    pGame->pQuestControl = pQuestInfo;
}

#include "gen/data/Source/D2Game/Quests/QUESTS_00545D80.inc"
