extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section); // 0x006CC1FC
extern unsigned char gCriticalSection_00881894[]; // 0x00881894

// 0x006CB440
void __cdecl sub_006CB440_DestroyLock()
{
    DeleteCriticalSection(gCriticalSection_00881894);
}
