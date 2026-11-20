#include "D2Game.h"
#include "D2GameStrc.h"

struct D2PlayerDataStrc { unsigned char reserved[0x10]; D2BitBufferStrc* questFlags[3]; };
struct D2QuestDataStrc { unsigned char reserved[0xC]; signed char state; };
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* unit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* flags, int quest, int state); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* flags, int quest, int state); // 0x0065C360
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* game, int quest); // 0x00543640
// 0x00591340
int __fastcall sub_00591340_UpdateQuestFlags(D2GameStrc* game, D2UnitStrc* unit, void* context)
{
    D2BitBufferStrc* flags = UNITS_GetPlayerData(unit)->questFlags[game->nDifficulty];
    if (QUESTRECORD_GetQuestState(flags, 3, 0) == 1 || QUESTRECORD_GetQuestState(flags, 3, 1) == 1)
        return 0;
    D2QuestDataStrc* quest = QUESTS_GetQuestData(game, 3);
    if (quest) {
        signed char state = quest->state;
        if (state == 2) {
            QUESTRECORD_SetQuestState(flags, 3, 2);
            return 0;
        }
        if (state == 3 || state == 4)
            QUESTRECORD_SetQuestState(flags, 3, 3);
    }
    return 0;
}
