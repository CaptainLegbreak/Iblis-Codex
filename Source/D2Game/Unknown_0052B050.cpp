#include "D2Game.h"

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250
extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority);             // 0x006CC264
unsigned long __stdcall CLIENT_ReceiveThreadProc(void* pParameter);                                         // 0x0052AB00

extern int gClientSocket;                                                                                   // 0x00730AE0
extern unsigned long gdwThreadId;                                                                           // 0x00882B30
extern void* ghReceiveThread_00882CD8;                                                                      // 0x00882CD8
extern void* ghClientConnectToHostThreadHandle;                                                             // 0x00882CE0
extern D2CriticalSectionStrc gCriticalSection;                                                              // 0x00882CE8
extern int gbConnected_00882D04;                                                                            // 0x00882D04

// 0x0052B050
int __cdecl CLIENT_GetConnectionStatus()
{
    if (NET_IsLocalConnection())
    {
        return 2;
    }

    if (!WaitForSingleObject(ghClientConnectToHostThreadHandle, 100))
    {
        if (gClientSocket != -1)
        {
            if (!NET_IsLocalConnection())
            {
                EnterCriticalSection(&gCriticalSection);
                gbConnected_00882D04 = 1;
                LeaveCriticalSection(&gCriticalSection);
            }

            ghReceiveThread_00882CD8 = CreateThread(0, 0, CLIENT_ReceiveThreadProc, 0, 0, &gdwThreadId);
            SetThreadPriority(ghReceiveThread_00882CD8, 1);
            return 2;
        }
        return 0;
    }
    return 1;
}

// 0x0052BDA0
void __cdecl sub_0052BDA0_Empty()
{
}

// 0x0052BDB0
void __cdecl sub_0052BDB0_Empty()
{
}
