extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_0077930C[]; // 0x0077930C
void __cdecl sub_006CB370_Cleanup(); // 0x006CB370
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CA920
void __cdecl sub_006CA920_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_0077930C);
    sub_00683824_RegisterExit(sub_006CB370_Cleanup);
}
