#include "D2GameTypes.h"
#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2GameClient.h"


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

static unsigned int gnGamesCount_0088C79C;        // 0x0088C79C

extern D2CriticalSectionStrc gtTaskQueuesCriticalSections_0088C7A8[32]; // 0x0088C7A8

struct D2LinkStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860

void __fastcall GAME_UpdateProgress(D2GameStrc* pGame);                                                     // 0x0052D870

void __fastcall D2GAME_PACKETS_SendGameLeft(int nClientId);                                             // 0x0053B220

void __fastcall ClientRemoveFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave);          // 0x00539DA0

void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90

void __fastcall GAME_CloseGame(int nGameGUID);                                                              // 0x0052E770

void __fastcall TASK_LinkList_PushFront(D2LinkStrc* pList, D2LinkStrc* pLink);                              // 0x00564250

D2LinkStrc* __fastcall TASK_LinkList_Remove(D2LinkStrc* pLink); // 0x005642E0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

extern "C" const char gszTaskSourceFile[];                                                                  // 0x006E11B8

extern D2TaskStrc* gtTaskSlots_0088C708[32];                                                          // 0x0088C708

extern D2CriticalSectionStrc gTaskSlotsCriticalSection_0088CAA8;                                            // 0x0088CAA8

static void TASK_QueueIncrement(D2TaskStrc*, int*, int);


struct D2TaskGameStrc
{
    int nTime;
    int nArg;
    unsigned int hGame;
    D2LinkStrc tLink;
};

int __fastcall TASK_GetClockTime();                                                                         // 0x00564340

static inline D2TaskQueueStrc* TASK_GetTaskQueueFromLink(D2LinkStrc* pLink)
{
    return (D2TaskQueueStrc*)((char*)pLink - 0x10);
}

static inline D2GameTaskStrc* TASK_GetGameTaskFromLink(D2LinkStrc* pLink)
{
    return (D2GameTaskStrc*)((char*)pLink - 0x0C);
}

static inline int TASK_GetScheduledTimeDelta(D2LinkStrc* pTaskLink, D2LinkStrc* pOtherTaskLink)
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

static D2TaskStrc* TASK_GetTaskFromTaskQueueLink(D2LinkStrc* pLink)
{
    return (D2TaskStrc*)((char*)pLink - 0x10);
}

static D2TaskStrc* TASK_GetTaskFromTaskType(int* pTaskType)
{
    return (D2TaskStrc*)((char*)pTaskType - 4);
}

static D2LinkStrc* TASK_GetLastTaskFromListHead(D2LinkStrc* pListHead)
{
    return pListHead->pNext != pListHead ? pListHead->pPrev : 0;
}

static void TASK_LinkList_Insert(D2LinkStrc* pPrev, D2LinkStrc* pLink)
{
    D2_ASSERT(pPrev, 0x6C);
    D2_ASSERT(pLink, 0x6D);
    pLink->pPrev = pPrev;
    pLink->pNext = pPrev->pNext;
    pLink->pNext->pPrev = pLink;
    pPrev->pNext = pLink;
}

// 0x00564400
static void TASK_QueueIncrement(D2TaskStrc* ptTaskQueue, int* pTaskType, int nTaskTypeIncrement)
{
    D2LinkStrc* ptTaskBalanceLink = &ptTaskQueue->pTaskBalanceLink;
    *pTaskType += nTaskTypeIncrement;
    D2LinkStrc* ptPrev;
    for (ptPrev = ptTaskBalanceLink->pPrev; ptPrev != ptTaskBalanceLink; ptPrev = ptPrev->pPrev)
    {
        if (TASK_GetTaskFromTaskQueueLink(ptPrev)->nType - *pTaskType <= 0)
        {
            break;
        }
    }
    TASK_LinkList_Insert(ptPrev, &TASK_GetTaskFromTaskType(pTaskType)->pTaskQueueLink);
}

// build: context TASK_CloseGame
static __forceinline void TASK_CloseGame(int nGameHashKey, int nTaskNumber, D2TaskStrc* ptTask)
{
    GAME_CloseGame(nGameHashKey);
    EnterCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);
    if (D2TaskStrc* pTaskSlot = gtTaskSlots_0088C708[nTaskNumber & 0x1F])
    {
        D2LinkStrc* ptTaskQTailLink = TASK_GetLastTaskFromListHead(&gpTaskQueueLink_0088C788);
        D2_ASSERT(ptTaskQTailLink, 0x2EC);
        const int nTaskSlotType = pTaskSlot->nType;
        D2TaskStrc* ptTaskQTail = TASK_GetTaskFromTaskQueueLink(gpTaskQueueLink_0088C788.pPrev);
        D2LinkStrc* pNewTaskLink = 0;
        if (ptTaskQTail->nType == nTaskSlotType + 1)
        {
            EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[ptTaskQTail->dwTaskQ]);
            D2LinkStrc* ptTaskBalanceLink = TASK_GetLastTaskFromListHead(&ptTaskQTail->pTaskBalanceLink);
            D2_ASSERT(ptTaskBalanceLink, 0x2F5);
            TASK_LinkList_Remove(ptTaskBalanceLink);
            LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[ptTaskQTail->dwTaskQ]);
            EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[pTaskSlot->dwTaskQ]);
            TASK_QueueIncrement(pTaskSlot, &TASK_GetTaskFromTaskQueueLink(ptTaskBalanceLink)->nType, 0);
            LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[pTaskSlot->dwTaskQ]);
            --ptTaskQTail->nType;
            TASK_LinkList_Remove(ptTaskQTailLink);
            pNewTaskLink = ptTaskQTailLink;
        }
        else
        {
            pTaskSlot->nType = nTaskSlotType - 1;
            pNewTaskLink = &pTaskSlot->pTaskQueueLink;
            TASK_LinkList_Remove(pNewTaskLink);
        }
        TASK_LinkList_PushFront(&gpTaskQueueLink_0088C788, pNewTaskLink);
        FOG_Free(ptTask, gszTaskSourceFile, 0x309, 0);
    }
    --gnGamesCount_0088C79C;
    LeaveCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);
}

// build: context sub_005645E0_IsEmptyGameExpired
static __forceinline int sub_005645E0_IsEmptyGameExpired(D2GameStrc* pGame)
{
    int bExpired = 0;
    const unsigned long nTick = GetTickCount();
    if (!pGame->nClients)
    {
        if (!pGame->nTickCountSinceNoClients)
            pGame->nTickCountSinceNoClients = nTick;
        if (nTick - pGame->nTickCountSinceNoClients > 300000 || pGame->dwGameFrame > 1500 && pGame->dwGameFrame < 7500)
            bExpired = 1;
    }
    else
    {
        pGame->nTickCountSinceNoClients = 0;
    }

    return bExpired;
}

// 0x005645E0
void __stdcall sub_005645E0_TASK_ProcessGame(int nTaskNumber, D2TaskStrc* ptTask)
{
    const int nGameHashKey = (int)ptTask->pTaskBalanceLink.pPrev;
    if (D2GameStrc* pGame = GAME_LockGame(nGameHashKey))
    {
        GAME_UpdateProgress(pGame);
        sub_6FC39270(pGame, 0);
// build: symbol ?FOG_GetSyncTime@* 0x00410A80
        const unsigned int nSyncTime = FOG_GetSyncTime();
        const unsigned int nSyncTimer = pGame->nSyncTimer;
        if (nSyncTimer == 1)
            goto IoTimeout;
        if (nSyncTime - nSyncTimer > 1800)
        {
IoTimeout:
            D2ClientStrc* pNextClient;
            for (D2ClientStrc* pCurrentClient = pGame->pClientList; pCurrentClient; pCurrentClient = pNextClient)
            {
                pNextClient = pCurrentClient->pNext;
                D2GAME_PACKETS_SendGameLeft(pCurrentClient->dwClientId);
                sub_0053B240_SendHeaderOnly0x06(pCurrentClient->dwClientId);
                ClientRemoveFromGame(pGame, pCurrentClient->dwClientId, 0);
            }
        }
        else if (!sub_005645E0_IsEmptyGameExpired(pGame))
        {
            GAME_LeaveGamesCriticalSection(pGame);
            const int nTaskSlotIdx = nTaskNumber & 0x1F;
            EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[nTaskSlotIdx]);
            D2TaskStrc* ptTaskQ = gtTaskSlots_0088C708[nTaskSlotIdx];
            if (!ptTaskQ)
            {
                LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[nTaskSlotIdx]);
            }
            else
            {
                TASK_QueueIncrement(ptTaskQ, &ptTask->dwTaskQ, 40);
                D2_ASSERT((unsigned int)ptTaskQ->dwTaskQ < 32, 0x97);
                LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[ptTaskQ->dwTaskQ]);
            }
            return;
        }

        GAME_LeaveGamesCriticalSection(pGame);
        TASK_CloseGame(nGameHashKey, nTaskNumber, ptTask);
        return;
    }
}

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
static inline void TASK_LinkList_RemoveInline(D2LinkStrc* pLink)
{
    pLink->pPrev->pNext = pLink->pNext;
    pLink->pNext->pPrev = pLink->pPrev;
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
            D2TaskStrc* pTask = TASK_GetTaskFromTaskQueueLink(gpTaskQueueLink_0088C788.pNext);
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
