struct D2CriticalSectionStrc { unsigned int opaque[6]; };
struct D2Direct3DDeviceStrc;
struct D2Direct3DDeviceVtblStrc {
    void* unknown0[9];
    long (__stdcall* BeginScene)(D2Direct3DDeviceStrc*);
};
struct D2Direct3DDeviceStrc { D2Direct3DDeviceVtblStrc* vtable; };
extern D2CriticalSectionStrc* gpCriticalSection_007C9134; // 0x007C9134
extern int gnPaused_007C9144; // 0x007C9144
extern int gnState_00970E54; // 0x00970E54
extern int gnState_00970E58; // 0x00970E58
extern int gnState_00970E5C; // 0x00970E5C
extern D2Direct3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
void __fastcall sub_006B7F70_ClearTarget(int); // 0x006B7F70
void __fastcall sub_006B9710_SetColorComponents(int, int, int); // 0x006B9710
void __fastcall sub_006B39B0_ShowD3DError(const char*, long); // 0x006B39B0
// 0x006B5720
int __fastcall sub_006B5720_BeginScene(int clear, int unused, int unusedA, int unusedB)
{
    if (gnPaused_007C9144) return 0;
    if (!gpCriticalSection_007C9134) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x842); exit(-1); }
    EnterCriticalSection(gpCriticalSection_007C9134);
    if (clear) sub_006B7F70_ClearTarget(0);
    gnState_00970E54 = 0;
    gnState_00970E58 = 0;
    gnState_00970E5C = 0;
    sub_006B9710_SetColorComponents(255, 255, 255);
    long result = gpDevice_00970E78->vtable->BeginScene(gpDevice_00970E78);
    if (result) sub_006B39B0_ShowD3DError("BeginScene failed!", result);
    return 1;
}
