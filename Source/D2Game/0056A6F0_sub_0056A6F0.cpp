struct Game; struct Unit;
struct T0056A6F0 { unsigned char value; };
void __fastcall sub_0056DEB0(Unit*,int,int,int);  // 0x0056DEB0
enum { REMOVE_SKILL = 1 };
// 0x0056A6F0
void __fastcall sub_0056A6F0(Game* unused,Unit* unit,int skill,T0056A6F0 level)
{
    if(level.value) sub_0056DEB0(unit,skill,level.value,REMOVE_SKILL);
}
