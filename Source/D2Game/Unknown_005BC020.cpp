#include "D2Game.h"

struct D2GameStrc { char unk00[0x6D]; unsigned char nDifficulty; };
struct D2PlayerDataStrc { char unk00[0x10]; D2BitBufferStrc* pQuestData[3]; };
struct D2QuestDataStrc { char unk00[0xB]; unsigned char fLastState; unsigned char fState; };
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc*, int, int); // 0x0065C360
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*, int); // 0x00543640
// 0x005BC020
int __fastcall sub_005BC020_UpdatePlayerQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pFlags, 22, 0) == 1 || QUESTRECORD_GetQuestState(pFlags, 22, 11) == 1)
        return 0;
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pGame, 20);
    if (!pQuest)
        return 0;
    switch (pQuest->fState)
    {
    case 2:
        QUESTRECORD_SetQuestState(pFlags, 22, 2);
        return 0;
    case 3:
        QUESTRECORD_SetQuestState(pFlags, 22, 3);
        return 0;
    case 4:
        if (pQuest->fLastState == 2)
        {
            QUESTRECORD_SetQuestState(pFlags, 22, 4);
            return 0;
        }
        if (pQuest->fLastState == 3)
        {
            QUESTRECORD_SetQuestState(pFlags, 22, 5);
            return 0;
        }
        if (pQuest->fLastState == 4)
            QUESTRECORD_SetQuestState(pFlags, 22, 6);
        return 0;
    case 5:
        if (pQuest->fLastState == 2)
        {
            QUESTRECORD_SetQuestState(pFlags, 22, 7);
            return 0;
        }
        if (pQuest->fLastState == 3)
        {
            QUESTRECORD_SetQuestState(pFlags, 22, 8);
            return 0;
        }
        if (pQuest->fLastState == 4)
            QUESTRECORD_SetQuestState(pFlags, 22, 9);
        return 0;
    }
    return 0;
}
