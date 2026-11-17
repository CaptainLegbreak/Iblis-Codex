#include "D2Game.h"

struct Bits;struct Game { char pad0[0x6D]; unsigned char difficulty; };
struct Unit { int type,classId; void* pool; int id; };
struct Player { char pad0[0x10]; Bits* quests[3]; };
struct Extra { char pad0[0x90]; unsigned char started; };
struct OtherExtra { char pad0[0x44]; int blocker; unsigned char ready; };
struct Quest { int id; Game* game; char pad8[4]; unsigned char state; char padD[0xB]; void* extra; char pad1C[0xC4]; int filter; };
struct Args { Game* game; int event; Unit* target; Unit* player; int unknown; Text* text; };
Player* __stdcall sub_006221A0(Unit*);  // 0x006221A0
Quest* __fastcall sub_00543640(Game*,int);  // 0x00543640
int __stdcall sub_0065C310(Bits*,int,int);  // 0x0065C310
extern unsigned stateIndices[4];  // 0x00735EE4
enum { QUEST_ID = 40 };
// 0x0058D9F0
void __fastcall sub_0058D9F0(Quest* quest,Args* args)
{
    Game* game=quest->game;
    Bits* flags=sub_006221A0(args->player)->quests[game->difficulty];
    int npc=!args->target ? -1 : args->target->classId;
    Extra* extra=(Extra*)quest->extra;
    switch(npc) {
    case 537: case 538: case 539: {
        Quest* other=sub_00543640(quest->game,35);
        if(other && ((OtherExtra*)other->extra)->ready && !((OtherExtra*)other->extra)->blocker) {
            if((quest->state==1 && !extra->started) || (quest->state==2 && extra->started))
                sub_00543790(quest,args->text,npc,3);
        }
        return;
    }
    default: break;
    }
    if(sub_0065C310(flags,QUEST_ID,0)) {
        switch(npc) {
        case 511:
            if(!sub_0065C310(flags,QUEST_ID,4)) sub_00543790(quest,args->text,npc,2);
            else if(sub_0065C310(flags,QUEST_ID,13)) sub_00543790(quest,args->text,npc,3);
            break;
        case 520:
            if(!sub_0065C310(flags,quest->filter,10)) {
                if(!sub_0065C310(flags,QUEST_ID,5)) sub_00543790(quest,args->text,npc,4);
                else if(sub_0065C310(flags,QUEST_ID,13)) sub_00543790(quest,args->text,npc,5);
            }
            break;
        case 513:
            if(!sub_0065C310(flags,QUEST_ID,6)) sub_00543790(quest,args->text,npc,2);
            else if(sub_0065C310(flags,QUEST_ID,13)) sub_00543790(quest,args->text,npc,3);
            break;
        case 521:
            if(sub_0065C310(flags,QUEST_ID,13)) sub_00543790(quest,args->text,npc,2);
            break;
        case 515:
            if(!sub_0065C310(flags,QUEST_ID,8)) sub_00543790(quest,args->text,npc,2);
            else if(sub_0065C310(flags,QUEST_ID,13)) sub_00543790(quest,args->text,npc,3);
            break;
        case 512:
            if(!sub_0065C310(flags,QUEST_ID,9)) sub_00543790(quest,args->text,npc,2);
            else if(sub_0065C310(flags,QUEST_ID,13)) sub_00543790(quest,args->text,npc,3);
            break;
        }
        return;
    }
    if(quest->state<4) {
        unsigned index=stateIndices[quest->state];
        if(index!=-1 && index<9) sub_00543790(quest,args->text,npc,index);
    }
}

#include "gen/data/Source/D2Game/Unknown_0058D9F0.inc"
