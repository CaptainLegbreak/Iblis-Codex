#include "D2Game.h"
#include "D2GameStrc.h"

struct D2QuestDataStrc
{
    unsigned char unk_00[0x0C];
    unsigned char nState0C;
};
struct D2PlayerDataStrc
{
    unsigned char unk_00[0x10];
    D2BitBufferStrc* pQuestData[3];
};
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestRecord, int nQuestId, int nState); // 0x0065C360

// 0x00592130
int __fastcall sub_00592130_SyncQuest4(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused)
{
    D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestRecord, 4, 0) == 1 || QUESTRECORD_GetQuestState(pQuestRecord, 4, 1) == 1)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (!pQuestData)
    {
        return 0;
    }
    if (pQuestData->nState0C == 2)
    {
        QUESTRECORD_SetQuestState(pQuestRecord, 4, 2);
        return 0;
    }
    if (pQuestData->nState0C >= 3 && pQuestData->nState0C <= 5)
    {
        QUESTRECORD_SetQuestState(pQuestRecord, 4, 3);
    }
    return 0;
}
