#include "D2Hell.h"

#include "D2SysTypes.h"

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824

struct D2StormListStrc
{
    int unk[3];

    char* sub_00517669_NewNode(unsigned int nFlags, unsigned int nExtraBytes, unsigned int nUnused); // 0x00517669
};

void sub_0051775A_FreeFaultHandlerList(); // 0x0051775A

extern D2StormListStrc gFaultHandlerList_0072FA14; // 0x0072FA14
extern D2CriticalSectionStrc gtErrorHandlerLock; // 0x00881818
extern int gbFaultHandlerListInitialized; // 0x00881830

// 0x00517788
__forceinline void sub_00517788_InitFaultHandlerList()
{
    if (!gbFaultHandlerListInitialized)
    {
        InitializeCriticalSection(&gtErrorHandlerLock);
        atexit(sub_0051775A_FreeFaultHandlerList);
        gbFaultHandlerListInitialized = 1;
    }
}

// 0x005177B2
void __fastcall sub_005177B2_SetLoadStringFn(void* pfnLoadString)
{
    sub_00517788_InitFaultHandlerList();
    EnterCriticalSection(&gtErrorHandlerLock);
    char* pNode = gFaultHandlerList_0072FA14.sub_00517669_NewNode(1, 0, 0);
    *(void**)(pNode + 8) = pfnLoadString;
    LeaveCriticalSection(&gtErrorHandlerLock);
}
