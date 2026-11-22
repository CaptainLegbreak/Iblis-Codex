#include "D2Game.h"

struct List;struct Game { char pad0[0x1C]; void* pool; char pad20[0x88]; int frame; };
struct Unit { int type,classId; void* pool; int id; };
struct Skills { char pad0[0x60]; unsigned calc; char pad64[0x1C]; short state; char pad82[0x1BA]; };
struct Tables { char pad0[0xC4]; int stateCount; char padC8[0xAD0]; Skills* skills; void* linker; int skillCount; };
int __stdcall sub_006444A0(Skill*);  // 0x006444A0
int __stdcall sub_00646CA0(Unit*,unsigned,int,int);  // 0x00646CA0
List* __stdcall sub_006256B0(Unit*,int);  // 0x006256B0
List* __stdcall sub_006251F0(void*,unsigned,unsigned,int,int);  // 0x006251F0
void __stdcall STATLIST_SetState(List*,int);  // 0x006252D0
typedef void (__fastcall *RemoveCallback)(Unit*,int,List*);
void __stdcall STATLIST_SetStatRemoveCallback(List*,RemoveCallback);  // 0x00625CE0
void __fastcall sub_0056E900(Unit*,int,List*);  // 0x0056E900
void __stdcall sub_00627150(List*,int,int,int);  // 0x00627150
void __stdcall sub_00626E10(Unit*,List*,int);  // 0x00626E10
void __stdcall sub_00639DB0(Unit*,int,int);  // 0x00639DB0
void __stdcall STATLIST_SetListExpireFrame(List*,int);  // 0x006260B0
void __fastcall sub_005417D0(Game*,Unit*,int,int,int,int);  // 0x005417D0
void __stdcall sub_00639E30(Unit*,int,int);  // 0x00639E30
int __stdcall sub_00625D00(List*,int,unsigned short);  // 0x00625D00
void __fastcall sub_005C6CC0(Unit*,List*,Skills*,int,int);  // 0x005C6CC0
enum { CHARGE_STAT = 169 };
inline Skills* GetSkills(int skillId)
{
    if(skillId>=0 && skillId<tables->skillCount) return &tables->skills[skillId];
    return 0;
}
// 0x005D8C70
int __fastcall SKILLS_ApplyFrenzyStats(Game* game,Unit* unit,int skillId,int level)
{
    Skills* record=GetSkills(skillId);
    if(!record) return 0;
    Skill* skill=sub_00620250(unit);
    if(!skill) return 0;
    if(!sub_006444A0(skill)) return 0;
    if(record->state>=0 && record->state<tables->stateCount) {
        int expire=sub_00646CA0(unit,record->calc,skillId,level)+game->frame;
        List* list=sub_006256B0(unit,record->state);
        if(!list) {
            list=sub_006251F0(game->pool,2,expire,!unit ? 6 : unit->type,!unit ? -1 : unit->id);
            if(!list) return 0;
            STATLIST_SetState(list,record->state);
            STATLIST_SetStatRemoveCallback(list,sub_0056E900);
            sub_00627150(list,CHARGE_STAT,0,0);
            sub_00626E10(unit,list,1);
            sub_00639DB0(unit,record->state,1);
        }
        STATLIST_SetListExpireFrame(list,expire);
        sub_005417D0(game,unit,12,expire,0,0);
        sub_00639E30(unit,record->state,1);
        int value=sub_00625D00(list,CHARGE_STAT,0)+1;
        if(value>level) value=level;
        sub_00627150(list,CHARGE_STAT,value,0);
        sub_005C6CC0(unit,list,record,skillId,value);
    }
    return 1;
}
