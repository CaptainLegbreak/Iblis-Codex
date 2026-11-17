struct D2GameStrc;
struct D2UnitStrc;
struct D2Act1Quest3ExStrc { unsigned char padding[0xA0]; unsigned char malusFound; };
struct D2QuestDataStrc { unsigned char padding[0x18]; D2Act1Quest3ExStrc* data; };
int __fastcall ITEMS_FindQuestItem(D2GameStrc* game, D2UnitStrc* unit, int code); // 0x00558110
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* game, int questId); // 0x00543640

// 0x00591CA0
void __fastcall ACT1Q3_UnitIterate_CheckForMalus(D2GameStrc* game, D2UnitStrc* unit, void* unused)
{
    if (ITEMS_FindQuestItem(game, unit, 0x206D6468))
    {
        D2QuestDataStrc* quest = QUESTS_GetQuestData(game, 3);
        if (quest)
            quest->data->malusFound = 1;
    }
}
