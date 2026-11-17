struct D2BitBufferStrc;
struct D2TextHeaderStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
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

extern "C" const unsigned int gnAct1Quest3NpcIndices[];                                                     // 0x00737630

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
int __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwCode);                       // 0x00558110
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x006253B0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

// 0x005916A0
void __fastcall ACT1Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    D2UnitStrc* pPlayer = pArg->pPlayer;
    D2GameStrc* pGame = pArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, 3, 0xD);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, 3, 0);
    const int nNpcId = !pArg->pTarget ? -1 : pArg->pTarget->dwClassId;
    if (bRewardGranted == 1 && !bPrimaryGoalDone)
    {
        return;
    }

    if (ITEMS_FindQuestItem(pArg->pGame, pArg->pPlayer, 0x206D6468))
    {
        if (STATLIST_GetUnitBaseStat(pArg->pPlayer, 0xC, 0) >= 8 && !QUESTRECORD_GetQuestState(pQuestFlags, 3, 0))
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, 3);
        }
    }
    else if (bRewardGranted != 1)
    {
        if (!pQuest->fState || pQuest->fState == 4)
        {
            return;
        }

        const unsigned int nIndex = gnAct1Quest3NpcIndices[pQuest->fState];
        if (nIndex != -1 && nIndex < 6)
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, nIndex);
        }
    }
}

#include "gen/data/Source/D2Game/005916A0_ACT1Q3_Callback00_NpcActivate.inc"
