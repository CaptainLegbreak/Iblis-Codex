struct Unit { int type; };
struct Property;
void __stdcall sub_00627260(Unit*,int,int,unsigned short);  // 0x00627260
enum { MAX_DURABILITY = 73, DURABILITY = 72 };
// 0x0065D270
int __fastcall sub_0065D270(int type,Unit* unit,Unit* item,const Property* property,int stat,int applyType,int state,int statList,Unit* other)
{
    Unit* selected=other;
    if(!selected || selected->type!=4) selected=item;
    sub_00627260(selected,MAX_DURABILITY,0,0);
    sub_00627260(selected,DURABILITY,0,0);
    return 1;
}
