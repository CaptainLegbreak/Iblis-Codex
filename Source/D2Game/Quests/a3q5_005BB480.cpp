#include "D2Game.h"

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2Act3Quest5Strc
{
    int nLastKilledMonsterGUID;
    unsigned char bOrmusActivated;
    unsigned char bMonstersSpawned;
    unsigned char pad0x06[2];
    int bQuest1RewardGranted;
    unsigned char bOrbSmashed;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char unk0x0D[0x0B];
    D2Act3Quest5Strc* pQuestDataEx;
};

#define QUESTSTATEFLAG_A3Q1 17
#define QUESTSTATEFLAG_A3Q2 18
#define QUESTSTATEFLAG_A3Q5 21
#define QFLAG_REWARDGRANTED 0
#define QFLAG_LEAVETOWN 2
#define QFLAG_ENTERAREA 3
#define QFLAG_CUSTOM1 4
#define QFLAG_PRIMARYGOALDONE 13

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720

// 0x005BB480
void __fastcall ACT3Q5_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest5Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_REWARDGRANTED))
    {
        pQuestDataEx->bOrbSmashed = 1;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_CUSTOM1) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A3Q5, QFLAG_PRIMARYGOALDONE);
        pQuestData->bNotIntro = 0;
        return;
    }

    pQuestDataEx->bQuest1RewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q1, QFLAG_REWARDGRANTED);
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_LEAVETOWN))
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_ENTERAREA))
        {
            if (pQuestDataEx->bQuest1RewardGranted)
            {
                pQuestData->fLastState = 2;
                pQuestData->fState = 2;
            }
            else
            {
                pQuestData->fLastState = 2;
                pQuestData->fState = 3;
            }
            return;
        }
    }
    else if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_ENTERAREA))
    {
        return;
    }

    if (pQuestDataEx->bQuest1RewardGranted)
    {
        pQuestData->fLastState = 3;
        pQuestData->fState = 4;
    }
    else
    {
        pQuestData->fLastState = 3;
        pQuestData->fState = 5;
    }
}
