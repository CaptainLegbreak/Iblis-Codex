struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2StormWindowNodeStrc
{
    void* pPrevLink;
    D2StormWindowNodeStrc* pNext;
    int unk0x08[5];
    int nValue;
    int unk0x20;
    void* hWnd;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);

extern D2CriticalSectionStrc gBasePathLock_00779068;
extern D2StormWindowNodeStrc* gpWindowNodeHead_00708368;
extern void* ghStormEvent_00779054;                                                                         // 0x00779054

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEENDVOID if (!nValid) { sub_0041C340_SetLastError(0x57); return; }

static void sub_0041A8F0_SetWindowNodeValue(int nValue, void* hWnd)
{
    if (!hWnd)
        return;
    EnterCriticalSection(&gBasePathLock_00779068);
    for (D2StormWindowNodeStrc* p = (D2StormWindowNodeStrc*)((((int)gpWindowNodeHead_00708368 <= 0) - 1) & (int)gpWindowNodeHead_00708368);
         (int)p > 0; p = p->pNext)
    {
        if (p->hWnd == hWnd)
            p->nValue = nValue;
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
}

// 0x0041AA80
void __stdcall sub_0041AA80_SetWindowFlag(void* hWnd, int nValue)
{
    VALIDATEBEGIN;
    VALIDATE(hWnd);
    VALIDATEENDVOID;
    if (nValid)
    {
        sub_0041A8F0_SetWindowNodeValue(nValue > 0, hWnd);
        if (nValue >= 1)
            SetEvent(ghStormEvent_00779054);
    }
}
