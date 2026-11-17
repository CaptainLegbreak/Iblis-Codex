#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2LinkStrc;
struct D2TaskStrc;
struct D2LargeIntegerStrc;

struct D2LinkStrc
{
    D2LinkStrc* pPrev;
    D2LinkStrc* pNext;
};

struct D2TaskStrc
{
    int nTaskQ;
    int nType;
    D2LinkStrc pTaskBalanceLink;
    D2LinkStrc pTaskQueueLink;
};

struct D2CriticalSectionStrc
{
    char unk0x00[0x18];
};

struct D2LargeIntegerStrc
{
    __int64 QuadPart;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(D2LargeIntegerStrc* pFrequency); // 0x006CC254
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall TASK_GetClockTime(); // 0x00564340
D2LinkStrc* __fastcall TASK_LinkList_Remove(D2LinkStrc* pLink); // 0x005642E0
void __stdcall sub_00564460_TASK_BalanceQueues(D2TaskStrc* pTask); // 0x00564460
void __stdcall sub_005645E0_TASK_ProcessGame(int nTaskNumber, D2TaskStrc* ptTask); // 0x005645E0
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern D2TaskStrc* gtTaskSlots_0088C708[32]; // 0x0088C708
extern int gnNumberOfTasksCreated_0088C798; // 0x0088C798
extern int gnGamesCount_0088C79C; // 0x0088C79C
extern D2CriticalSectionStrc gtTaskQueuesCriticalSections_0088C7A8[32]; // 0x0088C7A8
extern D2CriticalSectionStrc gTaskSlotsCriticalSection_0088CAA8; // 0x0088CAA8

D2TaskStrc* gtTaskSlots_0088C708[32]; // 0x0088C708

D2LinkStrc gpTaskQueueLink_0088C788; // 0x0088C788

D2LargeIntegerStrc gPerformanceFrequency; // 0x0088C790

int gnNumberOfTasksCreated_0088C798; // 0x0088C798

int gbHasHighResolutionClock; // 0x0088C7A0

D2CriticalSectionStrc gtTaskQueuesCriticalSections_0088C7A8[32]; // 0x0088C7A8

D2CriticalSectionStrc gTaskSlotsCriticalSection_0088CAA8; // 0x0088CAA8

// 0x005641D0
int __fastcall sub_005641D0_TASK_LinkList_IsEmpty(D2LinkStrc* pList)
{
    return pList->pNext == pList;
}

// 0x005641F0
D2LinkStrc* __fastcall sub_005641F0_TASK_LinkList_GetFirst(D2LinkStrc* pList)
{
    D2LinkStrc* pNext = pList->pNext;
    return pNext != pList ? pNext : 0;
}

// 0x00564200
D2LinkStrc* __fastcall TASK_GetLastTaskFromListHead(D2LinkStrc* pList)
{
    if (pList->pNext == pList)
    {
        return 0;
    }

    return pList->pPrev;
}

// 0x00564210
void __fastcall TASK_LinkList_Insert(D2LinkStrc* pPrev, D2LinkStrc* pLink)
{
    D2_ASSERT(pPrev, 0x6C);
    D2_ASSERT(pLink, 0x6D);

    pLink->pPrev = pPrev;
    pLink->pNext = pPrev->pNext;
    pLink->pNext->pPrev = pLink;
    pPrev->pNext = pLink;
}

// 0x00564290
void __fastcall sub_00564290_TASK_LinkList_PushBack(D2LinkStrc* pList, D2LinkStrc* pLink)
{
    D2_ASSERT(pList, 0x7F);
    D2_ASSERT(pLink, 0x80);

    TASK_LinkList_Insert(pList->pPrev, pLink);
}

// 0x00564320
void __stdcall TASK_InitializeClock()
{
    gbHasHighResolutionClock = QueryPerformanceFrequency(&gPerformanceFrequency);
}

// 0x00564390
static __forceinline D2TaskStrc* sub_00564390_TASK_LockQueueSlot(int nTaskNumber)
{
    const int nIndex = nTaskNumber & 0x1F;
    EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[nIndex]);
    D2TaskStrc* pTask = gtTaskSlots_0088C708[nIndex];
    if (!pTask)
    {
        LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[nIndex]);
    }
    return pTask;
}

// 0x005643C0
static __forceinline void sub_005643C0_TASK_UnlockQueueSlot(D2TaskStrc* pTask)
{
    if (pTask)
    {
        D2_ASSERT((unsigned int)pTask->nTaskQ < 32, 0x97);
        LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[pTask->nTaskQ]);
    }
}

// 0x00564870
void __stdcall sub_00564870_TASK_InitializeClock()
{
    gbHasHighResolutionClock = QueryPerformanceFrequency(&gPerformanceFrequency);
}

// 0x00564940
void __stdcall sub_00564940_TASK_Return()
{
}

// 0x00564950
void __fastcall sub_00564950_TASK_ClearValue(void* pUnused, int* pValue)
{
    *pValue = 0;
}

// 0x00564960
int __cdecl sub_00564960()
{
    EnterCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);
    if (!gpTaskQueueLink_0088C788.pPrev)
    {
        gpTaskQueueLink_0088C788.pPrev = &gpTaskQueueLink_0088C788;
        gpTaskQueueLink_0088C788.pNext = &gpTaskQueueLink_0088C788;
    }

    const int nIndex = gnNumberOfTasksCreated_0088C798++ & 0x1F;
    EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[nIndex]);
    if (!gtTaskSlots_0088C708[nIndex])
    {
        D2TaskStrc* pTask = (D2TaskStrc*)sub_0040B430(0, sizeof(D2TaskStrc), ".\\GAME\\Task.cpp", 0x3FB, 0);
        pTask->nTaskQ = nIndex;
        pTask->nType = 0;
        D2LinkStrc* pBalanceLink = &pTask->pTaskBalanceLink;
        pBalanceLink->pPrev = pBalanceLink;
        pBalanceLink->pNext = pBalanceLink;
        gtTaskSlots_0088C708[nIndex] = pTask;
        sub_00564460_TASK_BalanceQueues(pTask);
    }
    LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[nIndex]);
    LeaveCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);
    return nIndex;
}

int __fastcall sub_00564B20(int nTaskNumber, int** ppTaskType)
{
    int nResult = 100;
    *ppTaskType = 0;

    D2TaskStrc* pTask = sub_00564390_TASK_LockQueueSlot(nTaskNumber);
    if (!pTask)
    {
        return nResult;
    }

    D2LinkStrc* pLink = pTask->pTaskBalanceLink.pNext;
    if (pLink != &pTask->pTaskBalanceLink && pLink)
    {
        int* pTaskType = &((D2TaskStrc*)((char*)pLink - 0x10))->nType;
        const int nTickCount = TASK_GetClockTime();
        nResult = *pTaskType - nTickCount;
        if (nResult <= 0)
        {
            TASK_LinkList_Remove(pLink);
            *ppTaskType = pTaskType;
        }
    }

    sub_005643C0_TASK_UnlockQueueSlot(pTask);
    return nResult;
}

int __fastcall sub_00564BE0(int nTaskNumber)
{
    int nResult = 100;

    D2TaskStrc* pTask = sub_00564390_TASK_LockQueueSlot(nTaskNumber);
    if (!pTask)
    {
        return nResult;
    }

    D2LinkStrc* pLink = pTask->pTaskBalanceLink.pNext;
    if (pLink != &pTask->pTaskBalanceLink && pLink)
    {
        const int nTickCount = TASK_GetClockTime();
        nResult = ((D2TaskStrc*)((char*)pLink - 0x10))->nType - nTickCount;
    }

    sub_005643C0_TASK_UnlockQueueSlot(pTask);
    return nResult;
}

// 0x00564C70
void __fastcall TASK_ProcessGame(int nTaskNumber, D2TaskStrc* ptTask)
{
    D2_ASSERT(ptTask->nType == 0, 0x463);

    sub_005645E0_TASK_ProcessGame(nTaskNumber, ptTask);
}

// 0x00564CC0
void __fastcall sub_00564CC0_TASK_SetType(D2TaskStrc* pTask, int nType)
{
    if (pTask)
    {
        pTask->nType = nType;
    }
}

// 0x00564250
void __fastcall TASK_LinkList_PushFront(D2LinkStrc* pList, D2LinkStrc* pLink)
{
    D2_ASSERT(pList, 0x77);
    D2_ASSERT(pLink, 0x78);

    pLink->pPrev = pList;
    pLink->pNext = pList->pNext;
    pLink->pNext->pPrev = pLink;
    pList->pNext = pLink;
}

// 0x005642E0
D2LinkStrc* __fastcall TASK_LinkList_Remove(D2LinkStrc* pLink)
{
    D2_ASSERT(pLink, 0x87);

    pLink->pPrev->pNext = pLink->pNext;
    pLink->pNext->pPrev = pLink->pPrev;
    return pLink;
}

// 0x00564890
void __stdcall TASK_FreeAllQueueSlots()
{
    EnterCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);

    for (unsigned int i = 0; i < 32; ++i)
    {
        EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[i]);

        if (D2TaskStrc* pTask = gtTaskSlots_0088C708[i])
        {
            TASK_LinkList_Remove(&pTask->pTaskQueueLink);
            FOG_FreeServerMemory(0, gtTaskSlots_0088C708[i], ".\\GAME\\Task.cpp", 0x330, 0);
            gtTaskSlots_0088C708[i] = 0;
        }

        LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[i]);
    }

    gnNumberOfTasksCreated_0088C798 = 0;
    gnGamesCount_0088C79C = 0;
    LeaveCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);
}
