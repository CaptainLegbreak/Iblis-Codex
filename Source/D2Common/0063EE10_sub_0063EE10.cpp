struct Unit { int type, classId; };
struct Coord { int x,y; };
extern Coord table_006EA9D0[4];  // 0x006EA9D0
extern "C" const char* __cdecl sub_00408090();  // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int);  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl sub_00681E09(int);  // 0x00681E09
extern "C" const char text_006CC837[];  // 0x006CC837
int __stdcall sub_006510C0(int,int*,int*);  // 0x006510C0
#define CHECK(p,line) if (!(p)) { sub_00408A60(text_006CC837,sub_00408090(),line); sub_00681E09(-1); }
// 0x0063EE10
void __stdcall sub_0063EE10(Unit* unit,int* x,int* y)
{
    const int type=unit?unit->type:6;
    CHECK(type==1,0x2bc);
    int index;
    const int classId=unit?unit->classId:-1;
    sub_006510C0(classId,0,&index);
    CHECK(index<4,0x2c8);
    CHECK(index>=0,0x2c9);
    *x=table_006EA9D0[index].x;
    *y=table_006EA9D0[index].y;
}

#include "gen/data/Source/D2Common/0063EE10_sub_0063EE10.inc"
