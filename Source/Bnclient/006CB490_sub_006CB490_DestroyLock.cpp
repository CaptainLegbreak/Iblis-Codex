extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section); // 0x006CC1FC
extern unsigned char gCriticalSection_0088CAA8[]; // 0x0088CAA8

// 0x006CB490
void __cdecl sub_006CB490_DestroyLock()
{
    DeleteCriticalSection(gCriticalSection_0088CAA8);
}
