struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

struct D2QueueServerStrc;

struct D2QServerClientStrc
{
    unsigned char unk_00[0x7C];
    unsigned int nLocalIp;
};

D2QServerClientStrc* __fastcall sub_006BEC00_FindLocked(D2QueueServerStrc* pServer, unsigned int nToken, D2CriticalSectionStrc** ppLock); // 0x006BEC00

// 0x006BEC70
unsigned int __stdcall sub_006BEC70_GetClientLocalIpByToken(D2QueueServerStrc* pServer, unsigned int nToken)
{
    D2CriticalSectionStrc* pLock = 0;
    D2QServerClientStrc* pClient = sub_006BEC00_FindLocked(pServer, nToken, &pLock);
    unsigned int nIp = 0;
    if (pClient)
    {
        nIp = pClient->nLocalIp;
    }
    if (pLock)
    {
        LeaveCriticalSection(pLock);
    }
    return nIp;
}
