#include "D2FogTypes.h"
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
#pragma intrinsic(memset)
extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();

int __fastcall QuickStackWalk(const char* szPrefix, void* hThread, D2ThreadContextStrc* pContext); // 0x0040C7A0

// 0x0040D7D0
void __fastcall sub_0040D7D0_WalkCurrentStack(const char* szPrefix)
{
    void* hThread;
    {
        D2ThreadContextStrc tContext;
        unsigned long dwEip;
        unsigned long dwEsp;
        unsigned long dwEbp;

        memset(&tContext, 0, sizeof(tContext));
        tContext.ContextFlags = 0x10007;
        __asm
        {
            call next
        next:
            pop dwEip
            push esp
            pop dwEsp
            push ebp
            pop dwEbp
        }
        tContext.Eip = dwEip;
        tContext.Esp = dwEsp;
        tContext.Ebp = dwEbp;
        hThread = GetCurrentThread();
        QuickStackWalk(szPrefix, hThread, &tContext);
    }
}
