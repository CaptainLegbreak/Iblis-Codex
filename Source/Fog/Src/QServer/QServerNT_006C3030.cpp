#include "Fog.h"

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2QueueServerStrc
{
    char unk_000[0x854];
    D2CriticalSectionStrc tLock;
    char unk_86C[0xC18 - 0x86C];
    int bInitialized;
    char unk_C1C[0xC3C - 0xC1C];
    int nSlots[1];
};

struct D2QServerReqStrc
{
    D2QueueServerStrc* pServer;
    int nSlot;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
void __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall sub_00407F90_ThreadHookNop1(int n); // 0x00407F90
void __fastcall sub_006C2D70(D2QueueServerStrc* pServer, int nSlot, int nWait); // 0x006C2D70
extern const char gszQServerFile[]; // 0x006FC8A0

// 0x006C3030
int __stdcall sub_006C3030_ReleaseSlot(D2QServerReqStrc* pReq)
{
    D2QueueServerStrc* pServer = pReq->pServer;
    int nSlot = pReq->nSlot;
    FOG_Free(pReq, ".\\Src\\QServer\\QServerNT.cpp", 686, 0);
    if (!pServer->bInitialized)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 687);
        exit(-1);
    }
    while (!pServer->nSlots[nSlot])
    {
        sub_006C2D70(pServer, nSlot, 50);
    }
    EnterCriticalSection(&pServer->tLock);
    pServer->nSlots[nSlot] = 0;
    LeaveCriticalSection(&pServer->tLock);
    sub_00407F90_ThreadHookNop1(0);
    return 1;
}
