struct Bits; struct Text;
struct Game { char pad0[0x6D]; unsigned char difficulty; };
struct Unit { int type,classId; void* pool; int id; };
struct Player { char pad0[0x10]; Bits* quests[3]; };
struct QuestEx { unsigned char birdBrought; };
struct Quest { char pad0[0x18]; QuestEx* ex; };
struct Args { Game* game; int event; Unit* target; Unit* player; int unknown; Text* text; };
Player* __stdcall sub_006221A0(Unit*);  // 0x006221A0
int __stdcall sub_0065C310(Bits*,int,int);  // 0x0065C310
int __fastcall sub_005452C0(Quest*,int);  // 0x005452C0
void __fastcall sub_00543790(Quest*,Text*,int,int);  // 0x00543790
Unit* __fastcall sub_00558110(Game*,Unit*,unsigned);  // 0x00558110
inline Bits* GetFlags(Unit* player,Game* game) { return sub_006221A0(player)->quests[game->difficulty]; }
enum { QUEST_ID = 20 };
// 0x005B9ED0
void __fastcall sub_005B9ED0(Quest* quest,Args* args)
{
    Game* game=args->game;
    Bits* flags=GetFlags(args->player,game);
    int reward=sub_0065C310(flags,QUEST_ID,0);
    int npc=!args->target ? -1 : args->target->classId;
    if(reward==1) {
        if(sub_005452C0(quest,!args->player ? -1 : args->player->id)) sub_00543790(quest,args->text,npc,6);
        return;
    }
    if(npc==254 && quest->ex->birdBrought==1) return;
    if(sub_0065C310(flags,QUEST_ID,1)) { sub_00543790(quest,args->text,npc,5); return; }
    if(sub_00558110(args->game,args->player,0x20343367)) {
        if(npc==245) {
            if(!sub_0065C310(flags,QUEST_ID,4)) { sub_00543790(quest,args->text,npc,3); return; }
        } else if(npc==254) {
            if(!sub_0065C310(flags,QUEST_ID,1) && !sub_0065C310(flags,QUEST_ID,0)) sub_00543790(quest,args->text,npc,2);
            return;
        }
        sub_00543790(quest,args->text,npc,2);
        return;
    }
    if(sub_00558110(args->game,args->player,0x2034336A)) {
        if(!sub_0065C310(flags,QUEST_ID,2)) {
            if(npc==245 || npc==252) { sub_00543790(quest,args->text,npc,0); return; }
        } else if(npc==245 || npc==252) { sub_00543790(quest,args->text,npc,7); return; }
        sub_00543790(quest,args->text,npc,1);
    }
}
