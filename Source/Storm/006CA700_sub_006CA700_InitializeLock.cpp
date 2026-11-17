extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_0075E838[]; // 0x0075E838
void __cdecl sub_006CB070_Cleanup(); // 0x006CB070
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CA700
void __cdecl sub_006CA700_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_0075E838);
    sub_00683824_RegisterExit(sub_006CB070_Cleanup);
}
