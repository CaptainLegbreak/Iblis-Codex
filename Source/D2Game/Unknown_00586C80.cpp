#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define MONSTER_LARZUK 511
#define QFLAG_CUSTOM1 5
struct D2PlayerDataStrc;
struct D2Act5Quest1Strc;




typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2Act5Quest1Strc
{
    void* pLarzukMapAI;
    void* pRoom;
    unsigned char bLarzukStartActivated;
    unsigned char unused0x09[7];
    int nLarzukGUID;
    unsigned char unused0x14;
    unsigned char bLarzukSpawned;
    unsigned char bLarzukEndActivated;
    unsigned char bLarzukMapAIChanged;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

// 0x00586C80
int __fastcall ACT5Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A5Q1_SHENK);
    }

    return 0;
}

// 0x00586D80
void __fastcall ACT5Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (short)pQuestArg->pTarget->dwClassId != MONSTER_LARZUK)
    {
        return;
    }

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bLarzukStartActivated == 1)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bLarzukStartActivated = 0;
    }

    if (pQuestDataEx->bLarzukEndActivated == 1)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bLarzukEndActivated = 0;
    }
}

// 0x00586DE0
int __fastcall ACT5Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_STARTED);
    }
    else if (pQuestData->fState == 3)
    {
        if (pQuestData->fLastState == 2)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_ENTERAREA);
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_LEAVETOWN);
        }
    }

    return 0;
}

// 0x00586CE0
bool __fastcall ACT5Q1_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING) || QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_PRIMARYGOALDONE))
    {
        if (QUESTRECORD_GetQuestState(pFlags, pQuest->eFilter, QFLAG_CUSTOM1))
        {
            *pStatus = 4;
            return true;
        }

        *pStatus = 3;
        return true;
    }

    if (!pQuest->bNotIntro)
    {
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED))
    {
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDNOW))
    {
        *pStatus = 12;
    }
    else if (pQuest->fState < 5)
    {
        *pStatus = pQuest->fLastState;
    }

    return true;
}
