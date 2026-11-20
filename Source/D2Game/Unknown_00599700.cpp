#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"





struct D2Act2Quest2Strc
{
    int unused0x00[5];
    int nItemDropCount;
};

enum
{
    QUEST_A2Q2_HORADRICSTAFF = 9,
    QUESTSTATEFLAG_A2Q2 = 10,
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

// 0x00599700
int __fastcall ACT2Q2_UnitIterate_DetermineHoradricScrollDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 0) == 1)
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 3))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q2_HORADRICSTAFF);
    if (pQuestData)
    {
        ++((D2Act2Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }

    return 0;
}
