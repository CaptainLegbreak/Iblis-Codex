extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
unsigned char gCriticalSection_00779214[24];        // 0x00779214
void __cdecl sub_006CB300_Cleanup(); // 0x006CB300
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CA8C0
void __cdecl sub_006CA8C0_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00779214);
    sub_00683824_RegisterExit(sub_006CB300_Cleanup);
}
