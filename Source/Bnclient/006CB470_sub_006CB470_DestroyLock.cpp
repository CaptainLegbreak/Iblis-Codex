extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section); // 0x006CC1FC
extern unsigned char gCriticalSection_00881F64[24]; // 0x00881F64

// 0x006CB470
void __cdecl sub_006CB470_DestroyLock()
{
    DeleteCriticalSection(gCriticalSection_00881F64);
}
