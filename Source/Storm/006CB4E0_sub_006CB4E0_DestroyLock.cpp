extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section); // 0x006CC1FC
extern unsigned char gCriticalSection_0096D610[]; // 0x0096D610

// 0x006CB4E0
void __cdecl sub_006CB4E0_DestroyLock()
{
    DeleteCriticalSection(gCriticalSection_0096D610);
}
