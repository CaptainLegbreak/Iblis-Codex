#include "D2Gdi.h"
#include "D2SysTypes.h"


extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern void* gpArg1_007C9148; // 0x007C9148
extern void* gpArg2_007C914C; // 0x007C914C
extern D2CriticalSectionStrc* gpLock_007C9134; // 0x007C9134
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection);

// 0x006C7A70
int __fastcall sub_006C7A70_Init(void* pArg1, void* pArg2)
{
    gpArg1_007C9148 = pArg1;
    gpArg2_007C914C = pArg2;
    gpLock_007C9134 = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\gdiCore.cpp", 0x4B, 0);
    InitializeCriticalSection(gpLock_007C9134);
    return 1;
}

// 0x006C7AB0
int __cdecl sub_006C7AB0_Free()
{
    if (gpLock_007C9134)
    {
        DeleteCriticalSection(gpLock_007C9134);
        FOG_Free(gpLock_007C9134, ".\\Src\\gdiCore.cpp", 0x59, 0);
        gpLock_007C9134 = 0;
    }
    return 1;
}
