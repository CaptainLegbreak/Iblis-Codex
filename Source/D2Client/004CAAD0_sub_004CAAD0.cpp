extern "C" const char gszEmptyAssertText;  // 0x006CC837
extern "C" const char* __cdecl sub_00408090();  // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int);  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int);
struct D2UnitStrc {
    char prefix[0x74];
    int dwSfxMode;
};
// 0x004CAAD0
static __forceinline int sub_004CAAD0(D2UnitStrc* unit)
{
    if (!unit) {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xCA5);
        exit(-1);
    }
    return unit->dwSfxMode;
}

int __stdcall emit_getter_004CAAD0(D2UnitStrc* unit) { return sub_004CAAD0(unit); }
