struct Bits; struct Text;
struct Game { char pad0[0x6D]; unsigned char difficulty; };
struct Unit { int type,classId; void* pool; int id; };
struct Player { char pad0[0x10]; Bits* quests[3]; };
struct QuestEx { char pad0[0xC]; unsigned char flag; };
struct Quest { char pad0[9]; unsigned char notIntro; char padA[2]; unsigned char state; char padD[0xB]; QuestEx* ex; char pad1C[0xC4]; int filter; };
struct Args { Game* game; int event; Unit* target; Unit* player; int unknown; Text* text; };
extern unsigned indices[];  // 0x00740ED8
Player* __stdcall sub_006221A0(Unit*);  // 0x006221A0
int __stdcall sub_0065C310(Bits*,int,int);  // 0x0065C310
int __fastcall sub_005452C0(Quest*,int);  // 0x005452C0
void __fastcall sub_00543790(Quest*,Text*,int,int);  // 0x00543790
enum { QUEST_ID = 21 };
// 0x005BAFD0
void __fastcall sub_005BAFD0(Quest* quest,Args* args)
{
    Game* game=args->game;
    Bits* flags=sub_006221A0(args->player)->quests[game->difficulty];
    int reward=sub_0065C310(flags,QUEST_ID,0);
    int goal=sub_0065C310(flags,QUEST_ID,13);
    int npc=!args->target ? -1 : args->target->classId;
    if(sub_0065C310(flags,quest->filter,4)) {
        if(!quest->ex->flag) sub_00543790(quest,args->text,npc,5);
        return;
    }
    if(reward==1 && !sub_005452C0(quest,!args->player ? -1 : args->player->id)) return;
    unsigned char state=quest->state;
    if(state>=6) {
        if(goal==1) sub_00543790(quest,args->text,npc,6);
        return;
    }
    if(quest->notIntro) {
        unsigned index=indices[state];
        if(index!=-1 && index<8) sub_00543790(quest,args->text,npc,index);
    }
}

#include "gen/data/Source/D2Game/005BAFD0_sub_005BAFD0.inc"
