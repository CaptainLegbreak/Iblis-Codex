#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"







unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544760
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

static inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00596A90
void __fastcall ACT1Q7_Callback00_NpcActivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg)
{
    if ((!pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId) != MONSTER_NAVI)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, 1);
    if (QUESTS_GetGlobalState(pQuestArg->pGame, 1, 13) || !pQuestData->bNotIntro)
    {
        QUESTS_InitScrollTextChain(pQuest, pQuestArg->pTextControl, MONSTER_NAVI, ITEMS_RollRandomNumber(&pQuestArg->pPlayer->pSeed) % 3 + 2);
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 1, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, 1, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 1, 1))
    {
        QUESTS_InitScrollTextChain(pQuest, pQuestArg->pTextControl, MONSTER_NAVI, ITEMS_RollRandomNumber(&pQuestArg->pPlayer->pSeed) % 3 + 2);
        return;
    }

    QUESTS_InitScrollTextChain(pQuest, pQuestArg->pTextControl, MONSTER_NAVI, SEED_RollLimitedRandomNumber(&pQuestArg->pPlayer->pSeed, 2));
}
