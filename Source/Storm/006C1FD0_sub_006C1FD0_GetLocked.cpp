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

struct sub_006C1FD0_Object
{
    int nValue;
    CRITICAL_SECTION tLock;
};

// 0x006C1FD0
int __fastcall sub_006C1FD0_GetLocked(sub_006C1FD0_Object* pObject)
{
    EnterCriticalSection(&pObject->tLock);
    int nValue = pObject->nValue;
    LeaveCriticalSection(&pObject->tLock);
    return nValue;
}
