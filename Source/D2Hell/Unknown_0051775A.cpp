struct D2CriticalSectionStrc;
struct TMESSAGESOURCE;

#include "D2SysTypes.h"

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

struct TMESSAGESOURCE
{
    int unk[4];

    void Clear(); // 0x005176F8
};

extern TMESSAGESOURCE gFaultHandlerList_0072FA14; // 0x0072FA14
extern D2CriticalSectionStrc gErrorHandlerLock_00881818; // 0x00881818
extern int gbFaultHandlerListInitialized_00881830; // 0x00881830
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
void sub_0051775A_FreeFaultHandlerList(); // 0x0051775A

// 0x0051775A
void sub_0051775A_FreeFaultHandlerList()
{
    EnterCriticalSection(&gErrorHandlerLock_00881818);
    gFaultHandlerList_0072FA14.Clear();
    LeaveCriticalSection(&gErrorHandlerLock_00881818);
    DeleteCriticalSection(&gErrorHandlerLock_00881818);
    gbFaultHandlerListInitialized_00881830 = 0;
}

int gbFaultHandlerListInitialized_00881830; // 0x00881830

// 0x00517788
void sub_00517788_InitFaultHandlerList()
{
    if (!gbFaultHandlerListInitialized_00881830) {
        InitializeCriticalSection(&gErrorHandlerLock_00881818);
        atexit(sub_0051775A_FreeFaultHandlerList);
        gbFaultHandlerListInitialized_00881830 = 1;
    }
}
