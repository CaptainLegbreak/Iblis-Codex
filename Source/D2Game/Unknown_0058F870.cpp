#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

#define MONSTER_AKARA 148
#define MONSTER_DROGNAN 177
#define MONSTER_JERHYN 201
#define MONSTER_ACT2GUARD2 331
#define MONSTER_ACT2GUARD4 377
#define QUESTSTATEFLAG_A1Q1 1
#define QUESTSTATEFLAG_A2Q1 9
#define QUESTSTATEFLAG_A2Q4 12
#define QUESTSTATEFLAG_A2Q7 30
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_CUSTOM3 7
#define QFLAG_CUSTOM4 8
#define QFLAG_PRIMARYGOALDONE 13
#define OBJMODE_OPENED 2
#define QUESTSTATEFLAG_A1INTRO 42
#define QUEST_A1Q1_DENOFEVIL 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define MONSTER_WARRIV1 155
struct D2PlayerDataStrc;
struct D2Act2Quest4Strc;
struct D2Act1Quest1Strc;

struct D2QuestArgStrc
{
    union
    {
        D2GameStrc* game;
        D2GameStrc* pGame;
    };
    int event;
    D2UnitStrc* pTarget;
    union
    {
        D2UnitStrc* player;
        D2UnitStrc* pPlayer;
    };
    unsigned int unknown10;
    union
    {
        int npcId;
        D2TextHeaderStrc* pTextControl;
        unsigned short nNPCNo;
    };
    union
    {
        unsigned short message;
        unsigned short nMessageIndex;
    };
    unsigned char unk_1A[0x2];
};



void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc*, D2GameStrc*, int); // 0x00572360


typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);


struct D2Act2Quest4Strc
{
    char pad0x00[0x40];
    unsigned short nHaremBlockerObjectMode;
    char pad0x42[0x04];
    unsigned char bIsHaremBlockerNeutral;
};

int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern char gpAct1IntroNpcMessages[]; // 0x007361F8
extern char gpAct1Q0NpcMessages[]; // 0x00736460
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190
void __fastcall ACT1Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058F870
void __fastcall ACT1Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058F8F0
bool __fastcall ACT1Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0058F9B0
bool __fastcall ACT1Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058F9C0
void __fastcall ACT1Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058FA90
bool __fastcall ACT1Q0_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0058FB40
bool __fastcall ACT1Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058FB50
void __fastcall ACT1Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

struct D2Act1Quest1Strc
{
    char pad0x00[0x84];
    unsigned char bFinished;
    unsigned char bEnteredDen;
    unsigned char bAkaraActivated;
    unsigned char bTimerActive;
};

int __fastcall ACT1Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058FBE0
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300

// 0x0058F870
void __fastcall sub_0058F870_ScrollMessage(D2QuestDataStrc* quest, D2QuestArgStrc* arg)
{
    int npc = arg->npcId;
    unsigned short message = arg->message;
    switch (npc) {
    case 148:
        if (message == 11 || message == 12) PLRINTRO_SetQuestIntroFlag(arg->player, arg->game, npc);
        break;
    case 147:
        if (message == 45 || message == 46) PLRINTRO_SetQuestIntroFlag(arg->player, arg->game, npc);
        break;
    case 154:
        if (message == 36 || message == 37) PLRINTRO_SetQuestIntroFlag(arg->player, arg->game, npc);
        break;
    case 150:
        if (message == 24 || message == 25) PLRINTRO_SetQuestIntroFlag(arg->player, arg->game, npc);
        break;
    }
}

// 0x0058F9C0
bool __fastcall ACT1Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    D2GameStrc* pGame = pQuest->pGame;
    D2BitBufferStrc* pPlayerQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pPlayerQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED) != 1
        && nNpcId == MONSTER_AKARA
        && !PLRINTRO_GetQuestIntroFlag(pPlayer, pQuest->pGame, MONSTER_AKARA))
    {
        return true;
    }

    return false;
}

// 0x0059ACA0
bool __fastcall ACT2Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) == 1)
    {
        return false;
    }

    if (nNpcId == MONSTER_ACT2GUARD2)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING) == 1)
        {
            return false;
        }

        D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuest->pQuestDataEx;
        switch (pQuestDataEx->nHaremBlockerObjectMode)
        {
        case OBJMODE_OPENED:
            if (pQuestDataEx->bIsHaremBlockerNeutral && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM4))
            {
                return true;
            }
            break;

        case 0:
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM3))
            {
                return true;
            }
            break;
        }
    }
    else if (nNpcId == MONSTER_DROGNAN)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING)
            && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_JERHYN)
    {
        if (pQuest->fState == 2 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING)
            && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }

    return false;
}

// 0x0059E2C0
bool __fastcall ACT2Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_ACT2GUARD4)
    {
        D2GameStrc* pGame = pQuest->pGame;
        D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q7, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q7, QFLAG_PRIMARYGOALDONE))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q1, QFLAG_PRIMARYGOALDONE) == 1 && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q7, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }

    return false;
}

// 0x0058FA20
void __fastcall ACT1Intro_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT1Intro_Callback00_NpcActivate;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = ACT1Intro_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct1IntroNpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A1INTRO;
    pQuestData->pfStatusFilter = ACT1Intro_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT1Intro_ActiveFilterCallback;
}

// 0x0058FAD0
void __fastcall ACT1Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != MONSTER_WARRIV1)
    {
        return;
    }

    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q0, QFLAG_REWARDGRANTED))
    {
        return;
    }

    if (pQuestArg->pPlayer && pQuestArg->pPlayer->dwClassId == PCLASS_PALADIN)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_WARRIV1, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_WARRIV1, 0);
    }
}

// 0x0058FB80
void __fastcall ACT1Q0_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT1Q0_Callback00_NpcActivate;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A1Q0;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = ACT1Q0_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct1Q0NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pfStatusFilter = ACT1Q0_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT1Q0_ActiveFilterCallback;
}

// 0x0058FBE0
int __fastcall ACT1Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A1Q1_DENOFEVIL);
    }

    return 0;
}

// 0x0058FC90
int __fastcall ACT1Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q1_DENOFEVIL);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_STARTED);
    }
    else if (pQuestData->fState == 3)
    {
        if (pQuestData->fLastState == 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_LEAVETOWN);
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_ENTERAREA);
        }
    }

    return 0;
}

#include "gen/data/Source/D2Game/Unknown_0058F870.inc"

// 0x0058FA90
void __fastcall ACT1Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    if (pQuestArg->nNPCNo == MONSTER_WARRIV1 && (nMessageIndex == 0 || nMessageIndex == 1))
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q0, QFLAG_REWARDGRANTED);
    }
}

// 0x0058FB40
bool __fastcall ACT1Q0_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

// 0x0058FC40
void __fastcall ACT1Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (short)pQuestArg->pTarget->dwClassId != MONSTER_AKARA)
    {
        return;
    }

    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bAkaraActivated == 1)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bAkaraActivated = 0;
        pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = 0;
    }
}
