#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define QUEST_A1Q4_CAIN 4
#define QUESTSTATEFLAG_A1Q4 4
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_PRIMARYGOALDONE 13
#define MONSTER_AKARA 0x94
#define MONSTER_CAIN5 0x109
#define ITEM_RING 0x206E6972
#define DIFFMODE_NIGHTMARE 1
#define DIFFMODE_HELL 2
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_MAGIC 4
#define ITEMQUAL_RARE 6
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2Act1Quest4Strc;
union D2SeedStrc;


struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};


struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    char unk0x10[0x04];
    unsigned short nNPCNo;
    char pad0x16[0x02];
    unsigned short nMessageIndex;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef int (__stdcall* FARPROC)();

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned char nFlagsLowByte;
    char unk0x15[0x03];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    char unk0xA0[0xF0 - 0xA0];
    QUESTSEQFILTER pfSeqFilter;
};

struct D2Act1Quest4Strc
{
    unsigned short nStoneOrder[6];
    unsigned short nStoneCount;
    unsigned char unk_0E[0x2A];
    int nDecipheredScrollGUID;
    char unk0x3C[0x0F];
    unsigned char unk0x4B;
    char unk0x4C[0x02];
    unsigned char bDecipheredScrollAcquired;
    char unk0x4F[0x04];
    unsigned char bAkaraIntroActivated;
    char unk0x54[0x0F];
    unsigned char bQuestCompleteBefore;
    unsigned char bAkaraActivatedForScroll;
    char unk0x65[0x17];
    int nScrollsInGame;
    char unk0x80[0x34];
    D2QuestGUIDStrc pQuestGUID;
    D2QuestGUIDStrc tPlayerGUIDs;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544760
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780
void __fastcall QUESTS_SendLogUpdate(D2UnitStrc* pUnit, int nQuestId); // 0x005458E0
int __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable); // 0x005466B0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C3A0
int __fastcall ACT1Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005920D0


extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame); // 0x005438B0

// 0x00592250
void __fastcall ACT1Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const short nNpcId = pQuestArg->nNPCNo;
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    const short nMessageIndex = pQuestArg->nMessageIndex;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (nNpcId == MONSTER_AKARA)
    {
        if (nMessageIndex == 97)
        {
            pQuestDataEx->bAkaraIntroActivated = 1;
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 333);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            return;
        }

        if (nMessageIndex == 112)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_BOOK_BKS))
            {
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_BOOK_BKS);
                D2UnitStrc* pDecipheredScroll = (D2UnitStrc*)QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_SCROLL_BKD, 0, ITEMQUAL_NORMAL, 1);
                if (pDecipheredScroll)
                {
                    pQuestDataEx->bAkaraActivatedForScroll = 1;
                    pQuestDataEx->unk0x4B = 1;
                    pQuestDataEx->bDecipheredScrollAcquired = 1;
                    pQuestDataEx->nDecipheredScrollGUID = !pDecipheredScroll ? -1 : pDecipheredScroll->dwUnitId;
                    QUESTS_DebugOutput(pQuestData->pGame, "deciphered scroll", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 351);
                    QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 352);
                    pQuestData->nFlagsLowByte = 0;
                    QUESTS_UnitIterate(pQuestData, 3, pQuestArg->pPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 0);
                }
                else
                {
                    --pQuestDataEx->nScrollsInGame;
                }
            }
            return;
        }

        if (nMessageIndex != 118 || !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDPENDING))
        {
            return;
        }

        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED);
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDPENDING);

        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        QUESTS_UpdatePlayerFlags(pQuestData->pGame, pQuestArg->pPlayer);

        int nItemLevel = 7;
        int nItemQuality = ITEMQUAL_MAGIC;
        switch (pQuestArg->pGame->nDifficulty)
        {
        case DIFFMODE_NIGHTMARE:
            nItemQuality = ITEMQUAL_RARE;
            nItemLevel = 30;
            break;

        case DIFFMODE_HELL:
            nItemQuality = ITEMQUAL_RARE;
            nItemLevel = 60;
            break;
        }

        QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_RING, nItemLevel, nItemQuality, 1);
        QUESTS_SendLogUpdate(pQuestArg->pPlayer, QUEST_A1Q4_CAIN);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE))
        {
            if (pQuestData->fLastState != 13)
            {
                pQuestData->fLastState = 13;
            }

            if (pQuestData->fState != 6)
            {
                QUESTS_StateDebug(pQuestData, 6, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 399);
            }

            if (!QUESTS_GetGlobalState(pQuestArg->pGame, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE))
            {
                QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE);
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 404);
                pQuestData->pfSeqFilter(pQuestData);
            }
        }

        if (pQuestDataEx->bQuestCompleteBefore == 1)
        {
            QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE);
        }
        return;
    }
    else if (nNpcId == MONSTER_CAIN5)
    {
        if (nMessageIndex == 125)
        {
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
        else if (nMessageIndex == 126 || nMessageIndex == 123)
        {
            QUESTS_AddPlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
}

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
