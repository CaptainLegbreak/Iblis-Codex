struct Unit; struct Room; struct Flags;
struct Game { char pad[0x6D]; unsigned char difficulty; };
struct PlayerData { char pad[0x10]; Flags* quests[3]; };
struct Quest { char pad[0x0C]; unsigned char state; };
PlayerData* __stdcall sub_006221A0(Unit*);  // 0x006221A0
int __stdcall sub_0065C310(Flags*, int, int);  // 0x0065C310
void __stdcall sub_0065C360(Flags*, int, int);  // 0x0065C360
Room* __stdcall sub_00620BB0(Unit*);  // 0x00620BB0
int __stdcall sub_0061A1B0(Room*);  // 0x0061A1B0
unsigned char __stdcall sub_006427F0(int);  // 0x006427F0
Quest* __fastcall sub_00543640(Game*, int);  // 0x00543640
enum { QUEST_FLAGS_ID = 40, QUEST_DATA_ID = 36 };
// 0x0058D8B0
int __fastcall sub_0058D8B0(Game* game, Unit* unit, void* unused)
{
    Flags* flags = sub_006221A0(unit)->quests[game->difficulty];
    if (sub_0065C310(flags, QUEST_FLAGS_ID, 0) == 1 ||
        sub_0065C310(flags, QUEST_FLAGS_ID, 1) == 1) return 0;
    Room* room = sub_00620BB0(unit);
    if (!room) return 0;
    int level = sub_0061A1B0(room);
    if (!level || sub_006427F0(level) != 4) return 0;
    Quest* quest = sub_00543640(game, QUEST_DATA_ID);
    if (!quest) return 0;
    if (quest->state == 2) sub_0065C360(flags, QUEST_FLAGS_ID, 2);
    else if (quest->state == 3) sub_0065C360(flags, QUEST_FLAGS_ID, 3);
    return 0;
}
