#include "D2Game.h"

struct Skills { char pad0[0x12E]; unsigned short resultFlags; unsigned hitFlags,hitClass; unsigned calc[4]; char pad148[0x5D]; unsigned char srcDamage; char pad1A6[0x36]; unsigned char element; char pad1DD[0x5F]; };
struct Tables { char pad0[0xB98]; Skills* skills; void* linker; int skillCount; };
struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

extern "C" void* __cdecl memset(void*,int,unsigned);
void __stdcall sub_00620C10(Unit*,Unit*);  // 0x00620C10
int __stdcall sub_006449F0(Unit*,int,int);  // 0x006449F0
int __stdcall sub_00646CA0(Unit*,unsigned,int,int);  // 0x00646CA0
void __fastcall sub_0056E0C0(Unit*,D2DamageStrc*,int,int);  // 0x0056E0C0
void __fastcall sub_0057DBF0(Game*,Unit*,Unit*,D2DamageStrc*,unsigned char);  // 0x0057DBF0
void __fastcall sub_0057D4F0(Game*,Unit*,Unit*,int);  // 0x0057D4F0
void __stdcall sub_00644560(Skill*,int);  // 0x00644560
inline Skills* GetSkills(int id) { if(id>=0 && id<tables->skillCount) return &tables->skills[id]; return 0; }
enum { DEFAULT_SRC = 0x80 };
// 0x005D8B10
int __fastcall sub_005D8B10(Game* game,Unit* unit,Unit* target,int id,int level)
{
    Skills* record=GetSkills(id);
    if(!record) return 0;
    if(!target) return 0;
    sub_00620C10(unit,target);
    D2DamageStrc damage;
    memset(&damage,0,sizeof(damage));
    damage.wResultFlags=sub_0057EC10(game,unit,target,sub_006449F0(unit,id,level),0);
    if(damage.wResultFlags&1) {
        damage.wResultFlags |= record->resultFlags;
        damage.dwHitFlags |= record->hitFlags;
        if(record->hitClass) damage.dwHitClass=record->hitClass;
        damage.dwEnDmgPct=sub_00646CA0(unit,record->calc[0],id,level);
        if(record->element>0) {
            damage.dwConvPct=sub_00646CA0(unit,record->calc[3],id,level);
            if(damage.dwConvPct>0) damage.nConvType=record->element;
        }
        sub_0056E0C0(unit,&damage,id,level);
    }
    unsigned char source=record->srcDamage;
    if(!source) source=DEFAULT_SRC;
    sub_0057DBF0(game,unit,target,&damage,source);
    sub_0057D4F0(game,unit,target,0);
    Skill* skill=sub_00620250(unit);
    if(skill) {
        if(damage.wResultFlags&1) sub_00644560(skill,1);
        else sub_00644560(skill,0);
    }
    return 1;
}
