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

struct D2StormListStrc
{
    int m_linkoffset;
    void* m_prevlink;
    char* m_next;
    char* Head()
    {
        char* pHead = (int)m_next <= 0 ? 0 : m_next;
        return pHead;
    }
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);

extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
extern D2StormListStrc gRequestList_00708360;                                                               // 0x00708360
extern void* ghStormEvent_00779054;

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEENDVOID if (!nValid) { sub_0041C340_SetLastError(0x57); return; }

// 0x0041A8F0
static void sub_0041A8F0_SetWindowNodeValue(int nValue, void* hWnd)
{
    if (!hWnd)
        return;
    EnterCriticalSection(&gBasePathLock_00779068);
    for (D2StormWindowNodeStrc* p = (D2StormWindowNodeStrc*)gRequestList_00708360.Head(); (int)p > 0; p = p->pNext)
    {
        if (p->hWnd == hWnd)
            p->nValue = nValue;
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
}

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
