struct Game;
struct Unit { int type; int classId; char pad08[0xbc]; unsigned flags; };
extern int __fastcall sub_0046C140_TestMode(int,int);
extern int __fastcall sub_005A0180_TestMonType(Unit*,int);
extern int __fastcall sub_005541B0_IsDead(Unit*);
extern int __fastcall sub_00554200_CheckTarget(Game*,Unit*,Unit*);
inline int TestFlag(Unit* unit,unsigned mask)
{
    if (unit) return (unit->flags&mask)!=0;
    return 0;
}
static __forceinline int GetType(Unit* unit)
{
    int type=6;
    if (unit) type=unit->type;
    return type;
}
// 0x005C3420
int __fastcall sub_005C3420_ValidTarget(Game* game,Unit* unit,Unit* target)
{
    if (!target) return 0;
    if (GetType(target)==1) {
        if (!sub_0046C140_TestMode(target->classId,2)) return 0;
        if (sub_005A0180_TestMonType(target,0x20)) return 0;
    }
    if (!TestFlag(target,4)) return 0;
    if (!TestFlag(target,8)) return 0;
    if (!TestFlag(target,2)) return 0;
    if (sub_005541B0_IsDead(target)) return 0;
    return sub_00554200_CheckTarget(game,unit,target)!=0;
}
