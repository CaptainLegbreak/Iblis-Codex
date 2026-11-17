struct D2GameStrc;
struct D2UnitStrc;
struct D2QuestDataStrc;
struct D2QuestArgStrc {
    D2GameStrc* game;
    int event;
    D2UnitStrc* target;
    D2UnitStrc* player;
    unsigned int unknown10;
    int npcId;
    unsigned short message;
};
void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc*, D2GameStrc*, int); // 0x00572360
// 0x0058F870
void __fastcall sub_0058F870_ScrollMessage(D2QuestDataStrc* quest, D2QuestArgStrc* arg)
{
    int npc = arg->npcId;
    unsigned short message = arg->message;
    switch (npc) {
    case 148:
        if (message == 11 || message == 12) PLRINTRO_SetQuestIntroFlag(arg->player, arg->game, npc);
        break;
    case 147:
        if (message == 45 || message == 46) PLRINTRO_SetQuestIntroFlag(arg->player, arg->game, npc);
        break;
    case 154:
        if (message == 36 || message == 37) PLRINTRO_SetQuestIntroFlag(arg->player, arg->game, npc);
        break;
    case 150:
        if (message == 24 || message == 25) PLRINTRO_SetQuestIntroFlag(arg->player, arg->game, npc);
        break;
    }
}
