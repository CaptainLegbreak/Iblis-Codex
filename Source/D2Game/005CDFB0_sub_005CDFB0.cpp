struct Game; struct MissileRecord;
struct MonsterData { char pad0[0xE]; unsigned char variant; };
struct Unit { int type,classId; char pad8[0xC]; MonsterData* monster; char pad18[0xAC]; unsigned flags; };
struct Skills { char pad0[4]; unsigned char flags[4]; char pad8[0x40]; short missile; char pad4A[0x1F2]; };
struct Tables { char pad0[0xB6C]; int missileCount; char padB70[0x28]; Skills* skills; void* linker; int skillCount; };
extern Tables* tables;  // 0x00744304
extern unsigned bitMasks[];  // 0x006CE268
Unit* __stdcall sub_00553540(Game*,Unit*);  // 0x00553540
MissileRecord* __fastcall sub_0046ACE0(int);  // 0x0046ACE0
Unit* __fastcall sub_0056EE90(Game*,int,Unit*,int,int,int,int,int,int,int);  // 0x0056EE90
Unit* __fastcall sub_0056ECB0(Game*,int,Unit*,int,int,int,int,int,int,int);  // 0x0056ECB0
inline Skills* GetSkills(int id) { if(id>=0 && id<tables->skillCount) return &tables->skills[id]; return 0; }
__forceinline unsigned char GetVariant(Unit* unit)
{
    if(unit && unit->type==1 && unit->monster) return unit->monster->variant;
    return 0;
}
enum { UNIT_FLAG = 0x40 };
// 0x005CDFB0
int __fastcall sub_005CDFB0(Game* game,Unit* unit,int id,int level)
{
    Skills* record=GetSkills(id);
    if(!record) return 0;
    if(!sub_00553540(game,unit)) return 0;
    int missile=record->missile;
    if(missile<0 || missile>=tables->missileCount) return 0;
    missile+=GetVariant(unit);
    if(missile>=tables->missileCount) return 0;
    if(!sub_0046ACE0(missile)) return 0;
    if(unit) unit->flags|=UNIT_FLAG;
    if(record->flags[0]&bitMasks[1]) sub_0056EE90(game,missile,unit,id,level,0,0,0,0,0);
    else sub_0056ECB0(game,missile,unit,id,level,0,0,0,0,0);
    return 1;
}
