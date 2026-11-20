#include "D2GameTypes.h"
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


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
static D2LinkStrc gpTaskQueueLink_0088C788; // 0x0088C788
extern unsigned int gnNumberOfTasksCreated_0088C798; // 0x0088C798
unsigned int gnGamesCount_0088C79C;        // 0x0088C79C
extern D2CriticalSectionStrc gtTaskQueuesCriticalSections_0088C7A8[32]; // 0x0088C7A8

static __forceinline D2TaskQueueStrc* TASK_GetTaskQueueFromLink(D2LinkStrc* pLink)
{
    return (D2TaskQueueStrc*)((char*)pLink - 0x10);
}

static __forceinline D2GameTaskStrc* TASK_GetGameTaskFromLink(D2LinkStrc* pLink)
{
    return (D2GameTaskStrc*)((char*)pLink - 0x0C);
}

static __forceinline int TASK_GetScheduledTimeDelta(D2LinkStrc* pTaskLink, D2LinkStrc* pOtherTaskLink)
{
    return (int)((unsigned int)TASK_GetGameTaskFromLink(pTaskLink)->nScheduledTime
        - (unsigned int)TASK_GetGameTaskFromLink(pOtherTaskLink)->nScheduledTime);
}

// 0x00564460
void __stdcall sub_00564460_TASK_BalanceQueues(D2TaskQueueStrc* pNewQueue)
{
    const unsigned int nGamesPerQueue = gnGamesCount_0088C79C / gnNumberOfTasksCreated_0088C798;
    const unsigned int nExtraGames = gnGamesCount_0088C79C % gnNumberOfTasksCreated_0088C798;
    unsigned int nOtherQueueCount = gnNumberOfTasksCreated_0088C798 - 1;
    if (nOtherQueueCount >= 32)
    {
        nOtherQueueCount = 32;
    }
    int nQueuesWithExtraGame = (int)(nOtherQueueCount - nExtraGames);

    for (D2LinkStrc* pQueueLink = gpTaskQueueLink_0088C788.pNext; pQueueLink != &gpTaskQueueLink_0088C788; pQueueLink = pQueueLink->pNext)
    {
        D2TaskQueueStrc* pQueue = TASK_GetTaskQueueFromLink(pQueueLink);
        const bool bExtraGame = --nQueuesWithExtraGame >= 0;
        const unsigned int nQueueShare = nGamesPerQueue + (bExtraGame ? 1 : 0);
        int nWalkSteps = pQueue->nGameCount - (nQueueShare == 0 ? 1 : 0);

        EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[pQueue->nQueueIndex]);
        D2LinkStrc* pLastMoved = pQueue->tGameTasks.pPrev;
        D2LinkStrc* pGameTasks = &pQueue->tGameTasks;
        D2LinkStrc* pLastKept = pLastMoved;
        for (; nWalkSteps; pLastKept = pLastKept->pNext)
        {
            --nWalkSteps;
            if (pLastKept == pGameTasks)
            {
                break;
            }
        }
        D2LinkStrc* pMoved = pLastKept->pNext;
        pLastKept->pNext = pGameTasks;
        pGameTasks->pPrev = pLastKept;
        LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[pQueue->nQueueIndex]);
        if (pMoved == pGameTasks)
        {
            continue;
        }

        D2LinkStrc* pNewGameTasks = &pNewQueue->tGameTasks;
        pLastMoved->pNext = 0;
        D2LinkStrc* pInsertAfter = pNewGameTasks->pPrev;
        while (pInsertAfter != pNewGameTasks && TASK_GetScheduledTimeDelta(pMoved, pInsertAfter) < 0)
        {
            pInsertAfter = pInsertAfter->pPrev;
        }

        while (pInsertAfter->pNext != pNewGameTasks)
        {
            D2LinkStrc* pNextMoved = pMoved->pNext;
            pMoved->pPrev = pInsertAfter;
            pMoved->pNext = pInsertAfter->pNext;
            pMoved->pNext->pPrev = pMoved;
            pInsertAfter->pNext = pMoved;
            if (!pNextMoved)
            {
                goto next_queue;
            }
            pInsertAfter = pMoved;
            pMoved = pNextMoved;
            while (pInsertAfter->pNext != pNewGameTasks && TASK_GetScheduledTimeDelta(pMoved, pInsertAfter->pNext) > 0)
            {
                pInsertAfter = pInsertAfter->pNext;
            }
        }

        pMoved->pPrev = pInsertAfter;
        pLastMoved->pNext = pNewGameTasks;
        pInsertAfter->pNext = pMoved;
        pNewGameTasks->pPrev = pLastMoved;
next_queue:
        ;
    }

    D2LinkStrc* pLink = &pNewQueue->tQueueLink;
    if (!pLink)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x78);
        exit(-1);
    }
    pLink->pPrev = &gpTaskQueueLink_0088C788;
    pLink->pNext = gpTaskQueueLink_0088C788.pNext;
    gpTaskQueueLink_0088C788.pNext->pPrev = pLink;
    gpTaskQueueLink_0088C788.pNext = pLink;
}
