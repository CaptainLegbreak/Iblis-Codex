struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2BnStateStrc
{
    int nState;
    void* pArg;
};

struct D2BnMessageStrc;

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);   // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218

extern char gszEmptyStateText_00881F80[];                                                                   // 0x00881F80
void* gpBnStateArg_00882000;                                                                                // 0x00882000
D2CriticalSectionStrc gMessageLock_00882004;                                                                // 0x00882004
int gnBnState_0088201C;                                                                                     // 0x0088201C
extern D2BnMessageStrc* gpMessageHead_00882020;                                                             // 0x00882020
extern D2BnMessageStrc* gpMessageTail_00882024;                                                             // 0x00882024

// 0x005201E0
void __cdecl sub_005201E0_InitMessageQueue()
{
    gpMessageHead_00882020 = 0;
    gpMessageTail_00882024 = 0;
    gnBnState_0088201C = 0;
    InitializeCriticalSection(&gMessageLock_00882004);
}

// 0x005204A0
int __fastcall sub_005204A0_SetError(int nError)
{
    EnterCriticalSection(&gMessageLock_00882004);
    if (!gnBnState_0088201C)
        gnBnState_0088201C = nError;
    LeaveCriticalSection(&gMessageLock_00882004);
    return 1;
}

// 0x00520520
int __fastcall sub_00520520_SetState(int nState)
{
    EnterCriticalSection(&gMessageLock_00882004);
    gnBnState_0088201C = nState;
    LeaveCriticalSection(&gMessageLock_00882004);
    return 1;
}

// 0x00520550
int __fastcall sub_00520550_SetStateArg(void* pArg)
{
    EnterCriticalSection(&gMessageLock_00882004);
    gpBnStateArg_00882000 = pArg;
    LeaveCriticalSection(&gMessageLock_00882004);
    return 1;
}

// 0x005205F0
int __fastcall sub_005205F0_GetState(D2BnStateStrc* pState)
{
    EnterCriticalSection(&gMessageLock_00882004);
    pState->nState = gnBnState_0088201C;
    pState->pArg = gpBnStateArg_00882000;
    if (gnBnState_0088201C == 0x1B)
        pState->pArg = gszEmptyStateText_00881F80;
    LeaveCriticalSection(&gMessageLock_00882004);
    return 1;
}
