extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_00881860[]; // 0x00881860
void __cdecl sub_006CB420_Cleanup(); // 0x006CB420
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CAE80
void __cdecl sub_006CAE80_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00881860);
    sub_00683824_RegisterExit(sub_006CB420_Cleanup);
}
