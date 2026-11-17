struct D2BitBufferStrc;
struct D2QuestArgStrc;
struct D2QuestDataStrc;
struct D2TextHeaderStrc;
struct Obj005452C0;

struct D2GameStrc
{
    char pad0x00[0x1C];
    void* pMemoryPool;
    char pad0x20[0x4D];
    unsigned char nDifficulty;
    char pad0x6E[0x2];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x4];
    int dwUnitId;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
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
    char nInitNo;
    char pad0x0E[0x2];
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    void* pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    char pad0x10[0x4];
    D2TextHeaderStrc* pTextControl;
};

extern "C" const unsigned int gnA5Q2NpcActivateIndices[];                                                   // 0x00734270
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
extern "C" int __fastcall sub_005452C0(Obj005452C0* pObj, unsigned int dwValue);                         // 0x005452C0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

// 0x00587D30
void __fastcall ACT5Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int nRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0);
    const int nPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        return;
    }

    if (sub_005452C0((Obj005452C0*)pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }

    if (nRewardGranted == 1)
    {
        return;
    }

    const unsigned char nState = pQuestData->fState;
    if ((nState >= 4 && !nPrimaryGoalDone) || !pQuestData->bNotIntro)
    {
        return;
    }

    const unsigned int nIndex = gnA5Q2NpcActivateIndices[nState];
    if (gnA5Q2NpcActivateIndices[nState] == 2 && nNpcId == 0x203)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 4))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 0x203, 5);
            return;
        }
        goto send;
    }

    if (nIndex != -1 && nIndex < 12)
    {
send:
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

#include "gen/data/Source/D2Game/00587D30_ACT5Q2_Callback00_NpcActivate.inc"
