#include "D2QServer.h"

struct sub_006BE510_Guard;

struct sub_006BE530_LockRef;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);

struct sub_006BE510_Guard
{
    D2CriticalSectionStrc* pCriticalSection;

    sub_006BE510_Guard* sub_006BE510_Enter(D2CriticalSectionStrc* pCs);
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);

struct sub_006BE530_LockRef
{
    D2CriticalSectionStrc* pCriticalSection;
};

void __fastcall sub_006C2110_StopServerThreads(D2QueueServerStrc* pServer); // 0x006C2110

void __fastcall sub_006C33D0_Stop(D2QueueServerStrc* pServer); // 0x006C33D0

// 0x006BE470
int __stdcall sub_006BE470_IsActive(D2QueueServerStrc* pServer)
{
    if (!pServer)
        return 0;
    return pServer->nState == 1 || pServer->nState == 2;
}

// 0x006BE510
sub_006BE510_Guard* sub_006BE510_Guard::sub_006BE510_Enter(D2CriticalSectionStrc* pCs)
{
    pCriticalSection = pCs;
    EnterCriticalSection(pCs);
    return this;
}

// 0x006BE530
void __fastcall sub_006BE530_Leave(sub_006BE530_LockRef* pLock)
{
    LeaveCriticalSection(pLock->pCriticalSection);
}

// 0x006BEA70
int __stdcall sub_006BEA70_CountBucket(D2QueueServerStrc* pServer, int nBucket)
{
    if (nBucket >= pServer->nQueueCount)
        return -1;

    int nCount = 0;
    EnterCriticalSection(&pServer->tLock);
    for (D2MessageStrc* pMessage = pServer->ppMsgHeads[nBucket]; pMessage; pMessage = pMessage->pNext)
        ++nCount;
    LeaveCriticalSection(&pServer->tLock);
    return nCount;
}

// 0x006BF170
void __fastcall sub_006BF170_Dispatch(D2QueueServerStrc* pServer)
{
    if (pServer->bAltSend)
        sub_006C2110_StopServerThreads(pServer);
    else
        sub_006C33D0_Stop(pServer);
}

// 0x006BF250
void __stdcall sub_006BF250_Nop(int a1, int a2, int a3)
{
}
