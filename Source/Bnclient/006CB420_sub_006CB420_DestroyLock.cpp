extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section); // 0x006CC1FC
extern unsigned char gCriticalSection_00881860[]; // 0x00881860

// 0x006CB420
void __cdecl sub_006CB420_DestroyLock()
{
    DeleteCriticalSection(gCriticalSection_00881860);
}
