struct D2CriticalSectionStrc { unsigned int opaque[6]; };
extern D2CriticalSectionStrc* gpCriticalSection_007C9134; // 0x007C9134
extern int gnWindow_007C9140; // 0x007C9140
extern int gnPaused_007C9144; // 0x007C9144
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
void __cdecl sub_006B3320_ReleaseResources(); // 0x006B3320
void __fastcall sub_006B55E0_InitializeWindow(int, int); // 0x006B55E0
// 0x006B5630
void __fastcall sub_006B5630_SetPaused(int window, int mode, int paused)
{
    if (!gpCriticalSection_007C9134) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x7b0); exit(-1); }
    EnterCriticalSection(gpCriticalSection_007C9134);
    if (paused) {
        gnPaused_007C9144 = 1;
        sub_006B3320_ReleaseResources();
        gnWindow_007C9140 = 0;
    }
    else {
        gnPaused_007C9144 = 0;
        sub_006B55E0_InitializeWindow(window, mode);
    }
    LeaveCriticalSection(gpCriticalSection_007C9134);
}
