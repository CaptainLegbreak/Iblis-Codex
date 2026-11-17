struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2BnMessage00520440Strc
{
    unsigned char unk_000[0x128];
    D2BnMessage00520440Strc* pNext128;
};
extern D2CriticalSectionStrc gtMessQueueLock_00882004; // 0x00882004
extern D2BnMessage00520440Strc* gpMessQueueHead_00882020; // 0x00882020

// 0x00520440
int __cdecl sub_00520440_FreeAllMessages()
{
    EnterCriticalSection(&gtMessQueueLock_00882004);
    D2BnMessage00520440Strc* pMessage = gpMessQueueHead_00882020;
    while (gpMessQueueHead_00882020)
    {
        pMessage = pMessage->pNext128;
        FOG_Free(gpMessQueueHead_00882020, ".\\BnMessQueue.cpp", 0x9F, 0);
        gpMessQueueHead_00882020 = pMessage;
    }
    LeaveCriticalSection(&gtMessQueueLock_00882004);
    return 1;
}
