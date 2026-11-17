struct Unit; struct Client; struct Flags;
struct QuestInfo { char pad[0x20]; unsigned char effect; };
struct Game { char pad[0x6D]; unsigned char difficulty; char pad6e[0x1086]; QuestInfo* quests; };
struct PlayerData { char pad[0x10]; Flags* quests[3]; };
struct Packet { unsigned char header; unsigned char effect; };
extern const char quest_source_file[];  // 0x006E0BE4
PlayerData* __stdcall sub_006221A0(Unit*);  // 0x006221A0
Client* __fastcall sub_005531C0(Unit*, const char*, int);  // 0x005531C0
void __fastcall sub_0053D670(Client*, unsigned char, unsigned char, int, Flags*, unsigned char);  // 0x0053D670
void __fastcall sub_0053DFE0(Client*, Packet*);  // 0x0053DFE0
enum { EFFECT_PACKET = 0x89, FLAGS_PACKET = 0x28 };
// 0x005456F0
int __fastcall sub_005456F0(Game* game, Unit* unit, void* unused)
{
    Packet packet;
    packet.header = EFFECT_PACKET;
    packet.effect = game->quests->effect;
    Flags* flags = sub_006221A0(unit)->quests[game->difficulty];
    sub_0053D670(sub_005531C0(unit, quest_source_file, 3239), FLAGS_PACKET, 6, 0, flags, 0);
    sub_0053DFE0(sub_005531C0(unit, quest_source_file, 3342), &packet);
    return 0;
}
