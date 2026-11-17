extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_00881F64[24]; // 0x00881F64
void __cdecl sub_006CB470_Cleanup(); // 0x006CB470
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CAED0
void __cdecl sub_006CAED0_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00881F64);
    sub_00683824_RegisterExit(sub_006CB470_Cleanup);
}
