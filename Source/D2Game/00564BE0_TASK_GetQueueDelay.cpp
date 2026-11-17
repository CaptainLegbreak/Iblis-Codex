struct D2LinkStrc
{
    D2LinkStrc* pPrev;
    D2LinkStrc* pNext;
};

struct D2TaskQueueStrc
{
    int nQueueIndex;
    int nGameCount;
    D2LinkStrc tGameTasks;
    D2LinkStrc tQueueLink;
};

struct D2GameTaskStrc
{
    int nScheduledTime;
    int nType;
    unsigned int nGameHashKey;
    D2LinkStrc tTaskLink;
};

struct D2CriticalSectionStrc
{
    char unk0x00[0x18];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
struct D2LargeIntegerStrc
{
    __int64 QuadPart;
};
extern int gbHasHighResolutionClock; // 0x0088C7A0
extern D2LargeIntegerStrc gPerformanceFrequency; // 0x0088C790
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerStrc* pCount); // 0x006CC25C
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
__declspec(noinline) int __fastcall TASK_GetClockTime();

// 0x00564340
int __fastcall TASK_GetClockTime()
{
    if (gbHasHighResolutionClock)
    {
        D2LargeIntegerStrc nQPC;
        QueryPerformanceCounter(&nQPC);
        return 1000 * nQPC.QuadPart / gPerformanceFrequency.QuadPart;
    }

    return GetTickCount();
}
extern D2TaskQueueStrc* gpTaskQueues_0088C708[32]; // 0x0088C708
extern D2CriticalSectionStrc gtTaskQueuesCriticalSections_0088C7A8[32]; // 0x0088C7A8

static __forceinline D2GameTaskStrc* TASK_GetGameTaskFromLink(D2LinkStrc* pLink)
{
    return (D2GameTaskStrc*)((char*)pLink - 0x0C);
}

static __forceinline D2TaskQueueStrc* TASK_LockQueueSlot(int nTaskNumber)
{
    const int nIndex = nTaskNumber & 0x1F;
    EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[nIndex]);
    D2TaskQueueStrc* pQueue = gpTaskQueues_0088C708[nIndex];
    if (!pQueue)
    {
        LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[nIndex]);
    }
    return pQueue;
}

static __forceinline void TASK_UnlockQueueSlot(D2TaskQueueStrc* pQueue)
{
    if (pQueue)
    {
        D2_ASSERT((unsigned int)pQueue->nQueueIndex < 32, 0x97);
        LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[pQueue->nQueueIndex]);
    }
}

// 0x00564BE0
int __fastcall TASK_GetQueueDelay(int nTaskNumber)
{
    int nResult = 100;

    D2TaskQueueStrc* pQueue = TASK_LockQueueSlot(nTaskNumber);
    if (!pQueue)
    {
        return nResult;
    }

    D2LinkStrc* const pHead = &pQueue->tGameTasks;
    D2LinkStrc* pLink = pHead->pNext;
    if (pLink != pHead && pLink)
    {
        const int nTickCount = TASK_GetClockTime();
        nResult = TASK_GetGameTaskFromLink(pLink)->nScheduledTime - nTickCount;
    }

    TASK_UnlockQueueSlot(pQueue);
    return nResult;
}
