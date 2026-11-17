extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

extern int gnStatus_00779994; // 0x00779994
void* __cdecl sub_00449AC0_GetHandle(); // 0x00449AC0
void __cdecl sub_00449C00_CloseHandle(); // 0x00449C00
int __cdecl sub_00432350_GetStatus(); // 0x00432350
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);

// 0x00432400
int __cdecl sub_00432400_PollStatus()
{
    if (gnStatus_00779994)
        return 1;
    if (!sub_00449AC0_GetHandle())
        return 2;
    switch (WaitForSingleObject(sub_00449AC0_GetHandle(), 0))
    {
    default:
        return 2;
    case 0x102:
        _ReadWriteBarrier();
        return 3;
    case 0:
        sub_00449C00_CloseHandle();
        return sub_00432350_GetStatus() ? 2 : 0;
    }
}
