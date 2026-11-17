struct Unit { int type; int classId; void* pool; int id; };
struct T005C40D0;
int __stdcall sub_00625480(Unit*,int,unsigned short);  // 0x00625480
T005C40D0* __stdcall sub_006251F0(void*,unsigned,unsigned,int,int);  // 0x006251F0
void __stdcall sub_00626E10(Unit*,T005C40D0*,int);  // 0x00626E10
void __stdcall sub_00627150(T005C40D0*,int,int,int);  // 0x00627150
// 0x005C40D0
void __fastcall sub_005C40D0(Unit* unit,Unit* pet)
{
    int resist=sub_00625480(unit,349,0);
    if (!resist) return;
    T005C40D0* list=sub_006251F0(!pet ? 0 : pet->pool,0,0,!pet ? 6 : pet->type,!pet ? -1 : pet->id);
    if (!list) return;
    sub_00626E10(pet,list,1);
    if(sub_00625480(pet,142,0)<=0) sub_00627150(list,39,resist,0);
    if(sub_00625480(pet,144,0)<=0) sub_00627150(list,41,resist,0);
    if(sub_00625480(pet,148,0)<=0) sub_00627150(list,43,resist,0);
    sub_00627150(list,45,resist,0);
}
