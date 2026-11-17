extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_00881894[]; // 0x00881894
void __cdecl sub_006CB440_Cleanup(); // 0x006CB440
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CAEA0
void __cdecl sub_006CAEA0_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00881894);
    sub_00683824_RegisterExit(sub_006CB440_Cleanup);
}
