extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_00779080[]; // 0x00779080
void __cdecl sub_006CB0B0_Cleanup(); // 0x006CB0B0
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CA870
void __cdecl sub_006CA870_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00779080);
    sub_00683824_RegisterExit(sub_006CB0B0_Cleanup);
}
