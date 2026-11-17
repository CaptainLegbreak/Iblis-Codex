typedef struct _RTL_CRITICAL_SECTION
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
} CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct sub_006BC680_Shared
{
    int unk_00[3];
    CRITICAL_SECTION tLock;
    int bActive;
    int unk_28;
    int bSignalled;
};

struct sub_006BC680_Object
{
    char unk_000[0x110];
    sub_006BC680_Shared* pShared;
    char unk_114[0x10];
    int bPending;
};

static __declspec(noinline) void sub_006BC2C0(sub_006BC680_Object* pObject);

// 0x006BC2C0
static void sub_006BC2C0(sub_006BC680_Object* pObject)
{
    if (pObject && pObject->pShared && pObject->pShared->bActive)
    {
        pObject->bPending = 1;
        EnterCriticalSection(&pObject->pShared->tLock);
        pObject->pShared->bSignalled = 1;
        LeaveCriticalSection(&pObject->pShared->tLock);
    }
}

// 0x006BC680
void __stdcall sub_006BC680_Signal(sub_006BC680_Object* pObject)
{
    if (pObject)
        sub_006BC2C0(pObject);
}
