extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_0088CAA8[]; // 0x0088CAA8
void __cdecl sub_006CB490_Cleanup(); // 0x006CB490
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CAF70
void __cdecl sub_006CAF70_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_0088CAA8);
    sub_00683824_RegisterExit(sub_006CB490_Cleanup);
}
