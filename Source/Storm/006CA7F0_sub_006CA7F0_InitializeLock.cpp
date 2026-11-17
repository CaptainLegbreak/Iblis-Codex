extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_00779068[]; // 0x00779068
void __cdecl sub_006CB0A0_Cleanup(); // 0x006CB0A0
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CA7F0
void __cdecl sub_006CA7F0_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00779068);
    sub_00683824_RegisterExit(sub_006CB0A0_Cleanup);
}
