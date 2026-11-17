extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_0096D610[]; // 0x0096D610
void __cdecl sub_006CB4E0_Cleanup(); // 0x006CB4E0
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CB010
void __cdecl sub_006CB010_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_0096D610);
    sub_00683824_RegisterExit(sub_006CB4E0_Cleanup);
}
