extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_0075E850[]; // 0x0075E850
void __cdecl sub_006CB080_Cleanup(); // 0x006CB080
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CA720
void __cdecl sub_006CA720_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_0075E850);
    sub_00683824_RegisterExit(sub_006CB080_Cleanup);
}
