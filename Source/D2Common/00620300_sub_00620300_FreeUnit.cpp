struct Unit { int type; int classId; void* pMemoryPool; int id; int mode; void* monsterData; };
extern void __stdcall sub_00626D10_FreeStatList(Unit*);
extern void __stdcall sub_00643A60_FreeSkillList(Unit*);
extern void __fastcall sub_0040B480_FreePool(void*,void*,const char*,int,int);
// 0x00620300
void __stdcall sub_00620300_FreeUnit(Unit* unit)
{
    if (unit) {
        sub_00626D10_FreeStatList(unit);
        sub_00643A60_FreeSkillList(unit);
        unsigned typeDelta=(unsigned)unit->type-1u;
        if (!typeDelta) {
            sub_0040B480_FreePool((unit == 0 ? 0 : unit->pMemoryPool),unit->monsterData,".\\UNITS\\Units.cpp",0x69a,(int)typeDelta);
        }
        unit->type=6;
        unit->id=-1;
        sub_0040B480_FreePool((unit == 0 ? 0 : unit->pMemoryPool),unit,".\\UNITS\\Units.cpp",0x6a4,0);
    }
}
