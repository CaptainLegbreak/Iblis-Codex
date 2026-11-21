#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0





struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    union
    {
        D2TextHeaderStrc* pTextControl;
        unsigned short nNPCNo;
    };
    unsigned short nMessageIndex;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);


struct D2Act2Quest7Strc
{
    unsigned char unk0x00;
};

struct D2Act2Quest8Strc
{
    unsigned char unk0x00;
    unsigned char unk0x01;
};

enum
{
    QUEST_A2Q1_RADAMENT = 8,
    QUESTSTATEFLAG_A2Q1 = 9,
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUEST_A2Q6_DURIEL = 13,
    QUESTSTATEFLAG_A2Q6 = 14,
    QUESTSTATEFLAG_A2Q7 = 30,
    QUESTSTATEFLAG_A2Q8 = 31,
    QFLAG_PRIMARYGOALDONE = 13,
};

extern "C" const char gszA2Q7SourceFile[];                                                                  // 0x006E20B4
extern "C" const char gszA2Q8SourceFile[];                                                                  // 0x006E20E8
extern char gpAct2Q7NpcMessages[];                                                                          // 0x0073B8C0
extern char gpAct2Q8NpcMessages[];                                                                          // 0x0073BD58
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544760
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __fastcall ACT2Q7_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x0059E140
void __fastcall sub_0059E2A0_ACT2Q7_Callback08_Empty(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E2A0
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0059E2B0
bool __fastcall ACT2Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059E2C0
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0059E4A0
bool __fastcall ACT2Q8_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059E4B0

void __fastcall ACT2Q7_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT2Q7_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E0E0
void __fastcall ACT2Q8_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT2Q8_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0059E140
void __fastcall ACT2Q7_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (!pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId) != MONSTER_ACT2GUARD4)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q7, 0))
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 0))
        {
            goto RollMessage;
        }
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, QFLAG_PRIMARYGOALDONE))
        {
            goto RollMessage;
        }
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 1))
        {
            goto RollMessage;
        }
        if (QUESTS_GetGlobalState(pQuestArg->pGame, QUESTSTATEFLAG_A2Q1, QFLAG_PRIMARYGOALDONE))
        {
RollMessage:
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD4, SEED_RollRandomNumber_Inline(&pQuestArg->pPlayer->pSeed) % 3 + 2);
            return;
        }

        D2QuestDataStrc* pQuestData8 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q1_RADAMENT);
        if (pQuestData8 && !pQuestData8->bNotIntro)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD4, SEED_RollLimitedRandomNumber(&pQuestArg->pPlayer->pSeed, 3) + 2);
            return;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q7, QFLAG_PRIMARYGOALDONE))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD4, SEED_RollLimitedRandomNumber(&pQuestArg->pPlayer->pSeed, 2));
            return;
        }
    }

    QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD4, SEED_RollRandomNumber_Inline(&pQuestArg->pPlayer->pSeed) % 3 + 2);
}

// 0x0059E0B0
void __fastcall ACT2Q7_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != MONSTER_ACT2GUARD4)
    {
        return;
    }

    D2Act2Quest7Strc* pQuestDataEx = (D2Act2Quest7Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->unk0x00 == 1)
    {
        pQuestDataEx->unk0x00 = 0;
        pQuestData->pCallback[2] = 0;
    }
}

// build: context ACT2Q7_Callback11_ScrollMessage
void __fastcall ACT2Q7_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nNPCNo != MONSTER_ACT2GUARD4)
    {
        return;
    }

    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pQuestArg->pGame->nDifficulty];
    if (nMessageIndex == 59 || nMessageIndex == 60)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q7, QFLAG_PRIMARYGOALDONE);
        pQuestData->pCallback[2] = ACT2Q7_Callback02_NpcDeactivate;
    }
    else
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q7, 0);
    }
}

// 0x0059E330
void __fastcall ACT2Q7_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[11] = ACT2Q7_Callback11_ScrollMessage;
    pQuestData->pCallback[0] = ACT2Q7_Callback00_NpcActivate;
    pQuestData->pCallback[8] = sub_0059E2A0_ACT2Q7_Callback08_Empty;
    pQuestData->pNPCMessages = gpAct2Q7NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    D2Act2Quest7Strc* pQuestDataEx = (D2Act2Quest7Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest7Strc), gszA2Q7SourceFile, 194, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestDataEx->unk0x00 = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A2Q7;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT2Q7_ActiveFilterCallback;
}

// 0x0059E3C0
void __fastcall ACT2Q8_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nNPCNo == MONSTER_ACT2GUARD5 && pQuestArg->nMessageIndex == 303)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q8, 0);
    }
}

// 0x0059E3F0
void __fastcall ACT2Q8_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (nNpcId != MONSTER_ACT2GUARD5)
    {
        return;
    }

    D2QuestDataStrc* pQuestData13 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q6_DURIEL);
    if (!pQuestData13 || !pQuestData13->bNotIntro || pQuestData13->fState >= 2)
    {
        return;
    }

    D2QuestDataStrc* pQuestData10 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q3_TAINTEDSUN);
    if (pQuestData10 && pQuestData10->bNotIntro && pQuestData10->fState < 4)
    {
        return;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, 1) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, 0))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD5, 0);
    }
}

// 0x0059E530
void __fastcall ACT2Q8_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[11] = ACT2Q8_Callback11_ScrollMessage;
    pQuestData->pCallback[0] = ACT2Q8_Callback00_NpcActivate;
    pQuestData->pNPCMessages = gpAct2Q8NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    D2Act2Quest8Strc* pQuestDataEx = (D2Act2Quest8Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest8Strc), gszA2Q8SourceFile, 150, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestDataEx->unk0x00 = 0;
    pQuestDataEx->unk0x01 = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A2Q8;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT2Q8_ActiveFilterCallback;
}
