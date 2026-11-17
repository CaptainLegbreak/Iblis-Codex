struct Game; struct Skill; struct Room;
struct Unit { char pad0[0xC4]; unsigned flags; };
struct Skills { char pad0[0xE6]; short overlay; char padE8[0x154]; };
struct Tables { char pad0[0xB98]; Skills* skills; void* linker; int skillCount; char padBA4[0x1C]; int overlayCount; };
extern Tables* tables;  // 0x00744304
Skill* __stdcall sub_00620250(Unit*);  // 0x00620250
int __stdcall sub_006444A0(Skill*);  // 0x006444A0
int __stdcall sub_006444D0(Skill*);  // 0x006444D0
int __stdcall sub_00644500(Skill*);  // 0x00644500
int __stdcall sub_00644530(Skill*);  // 0x00644530
Room* __stdcall sub_00620BB0(Unit*);  // 0x00620BB0
Room* __fastcall sub_00463740(Room*,int,int);  // 0x00463740
Unit* __fastcall sub_005B2F20(Game*,Room*,int,int,int,int,int,int);  // 0x005B2F20
void __stdcall sub_00621CE0(Unit*,Unit*);  // 0x00621CE0
void __stdcall sub_00621E40(Unit*,int,int);  // 0x00621E40
enum { MINION_FLAGS = 0x4020000 };
inline Skills* GetSkills(int skillId)
{
    if(skillId>=0 && skillId<tables->skillCount) return &tables->skills[skillId];
    return 0;
}
// 0x005D2490
int __fastcall sub_005D2490(Game* game,Unit* unit,int skillId,int level)
{
    Skills* record=GetSkills(skillId);
    if(!record) return 0;
    Skill* skill=sub_00620250(unit);
    if(!skill) return 0;
    int monsterId=sub_006444A0(skill);
    int x=sub_006444D0(skill);
    int y=sub_00644500(skill);
    int mode=sub_00644530(skill);
    Room* room=sub_00463740(sub_00620BB0(unit),x,y);
    if(!room) return 0;
    Unit* monster=sub_005B2F20(game,room,x,y,monsterId,mode,-1,0);
    if(!monster) {
        monster=sub_005B2F20(game,room,x,y,monsterId,mode,4,0);
        if(!monster) return 0;
    }
    monster->flags |= MINION_FLAGS;
    sub_00621CE0(monster,unit);
    if(record->overlay>=0 && record->overlay<tables->overlayCount) sub_00621E40(monster,record->overlay,0);
    return 1;
}
