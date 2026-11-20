#include "D2Game.h"
#include "D2Structs.h"

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};


struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
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
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    D2TextHeaderStrc* pTextControl;
};

#define QUESTSTATEFLAG_A2Q5 13
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_UPDATEQUESTLOG 13

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

static inline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

// 0x0059BBC0
void __fastcall ACT2Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pQuestArg->pPlayer);
    D2BitBufferStrc* pQuestFlags = pPlayerData->pQuestData[pGame->nDifficulty];
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
    }
    else if (pQuestData->bNotIntro && pQuestData->fState)
    {
        const int nRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDGRANTED);
        const int nUpdateLog = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_UPDATEQUESTLOG);
        if (nRewardGranted == 1 && !nUpdateLog)
        {
            return;
        }

        if (pQuestData->fState >= 2 && !nUpdateLog)
        {
            return;
        }

        const int nIndex = gnAct2Quest5NpcIndices[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 4)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}
