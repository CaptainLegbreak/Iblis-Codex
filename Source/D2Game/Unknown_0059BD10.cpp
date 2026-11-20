#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"




D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

// 0x0059BD10
int __fastcall ACT2Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 0) == 1)
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 1) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 12);
    if (pQuestData && pQuestData->fState == 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 13, 2);
    }

    return 0;
}
