struct Unit { int type; char pad4[0xC]; int mode; };
extern "C" const char emptyAssert;  // 0x006CC837
extern "C" const char* __cdecl sub_00408090();  // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int);  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl sub_00681E09(int);  // 0x00681E09
enum { REQUIRED_TYPE = 6 };
// 0x006019B0
int __stdcall sub_006019B0(Unit* unit)
{
    if(unit->type!=REQUIRED_TYPE) {
        sub_00408A60(&emptyAssert,sub_00408090(),0x5C2);
        sub_00681E09(-1);
    }
    return unit->mode;
}
