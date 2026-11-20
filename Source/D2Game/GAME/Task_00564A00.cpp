#include "D2GameTypes.h"
struct D2LinkStrc
{
    D2LinkStrc* pPrev;
    D2LinkStrc* pNext;
};

struct D2TaskStrc
{
    int dwTaskQ;
    int nType;
    D2LinkStrc pTaskBalanceLink;
    D2LinkStrc pTaskQueueLink;
};

struct D2TaskGameStrc
{
    int nTime;
    int nArg;
    unsigned int hGame;
    D2LinkStrc tLink;
};


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
int __fastcall TASK_GetClockTime();                                                                         // 0x00564340
extern D2LinkStrc gpTaskQueueLink_0088C788;                                                                 // 0x0088C788
static int gnGamesCount_0088C79C;                                                                           // 0x0088C79C
extern D2CriticalSectionStrc gtTaskQueuesCriticalSections_0088C7A8[32];                                     // 0x0088C7A8
extern D2CriticalSectionStrc gTaskSlotsCriticalSection_0088CAA8;                                            // 0x0088CAA8

// build: context TASK_LinkList_InsertInline
static __forceinline void TASK_LinkList_InsertInline(D2LinkStrc* pPrev, D2LinkStrc* pLink)
{
    D2_ASSERT(pPrev, 0x6C);
    D2_ASSERT(pLink, 0x6D);
    pLink->pPrev = pPrev;
    pLink->pNext = pPrev->pNext;
    pLink->pNext->pPrev = pLink;
    pPrev->pNext = pLink;
}

// build: context TASK_LinkList_PushFrontInline
static __forceinline void TASK_LinkList_PushFrontInline(D2LinkStrc* pList, D2LinkStrc* pLink)
{
    D2_ASSERT(pList, 0x77);
    D2_ASSERT(pLink, 0x78);
    TASK_LinkList_InsertInline(pList, pLink);
}

// build: context TASK_LinkList_RemoveInline
static __forceinline void TASK_LinkList_RemoveInline(D2LinkStrc* pLink)
{
    pLink->pPrev->pNext = pLink->pNext;
    pLink->pNext->pPrev = pLink->pPrev;
}

// build: context TASK_GetTaskQueueFromLink
static D2TaskStrc* TASK_GetTaskQueueFromLink(D2LinkStrc* pTaskQueueLink)
{
    return (D2TaskStrc*)((char*)pTaskQueueLink - 0x10);
}

// 0x00564A00
int __fastcall sub_00564A00_QueueGame(D2TaskGameStrc* pTaskGame, int nArg, unsigned int hGame)
{
    int bResult = 0;
    pTaskGame->nTime = TASK_GetClockTime();
    pTaskGame->nArg = nArg;
    pTaskGame->hGame = hGame;

    EnterCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);
    if (!gpTaskQueueLink_0088C788.pPrev)
    {
        gpTaskQueueLink_0088C788.pPrev = &gpTaskQueueLink_0088C788;
        gpTaskQueueLink_0088C788.pNext = &gpTaskQueueLink_0088C788;
    }
    else
    {
        D2LinkStrc* pLink = gpTaskQueueLink_0088C788.pNext;
        if (pLink != &gpTaskQueueLink_0088C788 && pLink)
        {
            D2TaskStrc* pTask = TASK_GetTaskQueueFromLink(gpTaskQueueLink_0088C788.pNext);
            EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[pTask->dwTaskQ]);
            TASK_LinkList_PushFrontInline(&pTask->pTaskBalanceLink, &pTaskGame->tLink);
            LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[pTask->dwTaskQ]);
            ++pTask->nType;
            ++gnGamesCount_0088C79C;
            TASK_LinkList_RemoveInline(pLink);
            TASK_LinkList_InsertInline(gpTaskQueueLink_0088C788.pPrev, pLink);
            bResult = 1;
        }
    }

    LeaveCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);
    return bResult;
}
