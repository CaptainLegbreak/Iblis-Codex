#include "D2Game.h"

struct D2ClientStrc
{
    int dwClientId;
    char unk0x04[0x4A4];
    D2ClientStrc* pNext;
};

struct D2GameStrc
{
    char unk0x00[0x88];
    D2ClientStrc* pClientList;
    int nClients;
    char unk0x90[0x18];
    int dwGameFrame;
    char unk0xAC[0x1D14];
    int nTickCountSinceNoClients;
    unsigned int nSyncTimer;
};

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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
void __fastcall GAME_UpdateProgress(D2GameStrc* pGame);                                                     // 0x0052D870
int __cdecl sub_00410A80_GetTime();                                                                         // 0x00410A80
void __fastcall sub_0053B220_SendHeaderOnly0xB0(int nClientId);                                             // 0x0053B220
void __fastcall CLIENTS_RemoveClientFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave);          // 0x00539DA0
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90
void __fastcall GAME_CloseGame(int nGameGUID);                                                              // 0x0052E770
void __fastcall TASK_LinkList_PushFront(D2LinkStrc* pList, D2LinkStrc* pLink);                              // 0x00564250
void __fastcall TASK_LinkList_Remove(D2LinkStrc* pLink);                                                    // 0x005642E0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
extern D2TaskStrc* gtTaskSlots_0088C708[32];                                                          // 0x0088C708
extern D2LinkStrc gpTaskQueueLink_0088C788;                                                                 // 0x0088C788
extern int gnGamesCount_0088C79C;                                                                           // 0x0088C79C
extern D2CriticalSectionStrc gtTaskQueuesCriticalSections_0088C7A8[32];                               // 0x0088C7A8
extern D2CriticalSectionStrc gTaskSlotsCriticalSection_0088CAA8;                                            // 0x0088CAA8

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

static __forceinline void TASK_CloseGame(int nGameHashKey, int nTaskNumber, D2TaskStrc* ptTask)
{
    GAME_CloseGame(nGameHashKey);
    EnterCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);
    if (D2TaskStrc* pTaskSlot = gtTaskSlots_0088C708[nTaskNumber & 0x1F])
    {
        D2LinkStrc* ptTaskQTailLink = TASK_GetLastTaskFromListHead(&gpTaskQueueLink_0088C788);
        D2_ASSERT(ptTaskQTailLink, 0x2EC);
        const int nTaskSlotType = pTaskSlot->nType;
        D2TaskStrc* ptTaskQTail = TASK_GetTaskFromTaskQueueLink(ptTaskQTailLink);
        D2LinkStrc* pNewTaskLink;
        if (ptTaskQTail->nType == nTaskSlotType + 1)
        {
            EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[ptTaskQTail->nTaskQ]);
            D2LinkStrc* ptTaskBalanceLink = TASK_GetLastTaskFromListHead(&ptTaskQTail->pTaskBalanceLink);
            D2_ASSERT(ptTaskBalanceLink, 0x2F5);
            TASK_LinkList_Remove(ptTaskBalanceLink);
            LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[ptTaskQTail->nTaskQ]);
            EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[pTaskSlot->nTaskQ]);
            TASK_QueueIncrement(pTaskSlot, &TASK_GetTaskFromTaskQueueLink(ptTaskBalanceLink)->nType, 0);
            LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[pTaskSlot->nTaskQ]);
            --ptTaskQTail->nType;
            pNewTaskLink = ptTaskQTailLink;
        }
        else
        {
            pTaskSlot->nType = nTaskSlotType - 1;
            pNewTaskLink = &pTaskSlot->pTaskQueueLink;
        }
        TASK_LinkList_Remove(pNewTaskLink);
        TASK_LinkList_PushFront(&gpTaskQueueLink_0088C788, pNewTaskLink);
        FOG_Free(ptTask, ".\\GAME\\Task.cpp", 0x309, 0);
    }
    --gnGamesCount_0088C79C;
    LeaveCriticalSection(&gTaskSlotsCriticalSection_0088CAA8);
}

void __stdcall sub_005645E0_TASK_ProcessGame(int nTaskNumber, D2TaskStrc* ptTask)
{
    const int nGameHashKey = (int)ptTask->pTaskBalanceLink.pPrev;
    D2GameStrc* pGame = GAME_LockGame(nGameHashKey);
    if (!pGame)
    {
        return;
    }
    GAME_UpdateProgress(pGame);
    sub_6FC39270(pGame, 0);
    const int nTime = sub_00410A80_GetTime();
    const unsigned int nSyncTimer = pGame->nSyncTimer;
    if (nSyncTimer == 1 || nTime - nSyncTimer > 1800)
    {
        D2ClientStrc* pNext;
        for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pNext)
        {
            pNext = pClient->pNext;
            sub_0053B220_SendHeaderOnly0xB0(pClient->dwClientId);
            sub_0053B240_SendHeaderOnly0x06(pClient->dwClientId);
            CLIENTS_RemoveClientFromGame(pGame, pClient->dwClientId, 0);
        }
    }
    else
    {
        const unsigned long nTick = GetTickCount();
        if (pGame->nClients)
        {
            pGame->nTickCountSinceNoClients = 0;
        }
        else
        {
            if (!pGame->nTickCountSinceNoClients)
            {
                pGame->nTickCountSinceNoClients = nTick;
            }
            if (nTick - pGame->nTickCountSinceNoClients > 300000 || pGame->dwGameFrame > 1500 && pGame->dwGameFrame < 7500)
            {
                goto close_game;
            }
        }
        GAME_LeaveGamesCriticalSection(pGame);
        const int nTaskSlotIdx = nTaskNumber & 0x1F;
        EnterCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[nTaskSlotIdx]);
        if (D2TaskStrc* ptTaskQ = gtTaskSlots_0088C708[nTaskSlotIdx])
        {
            TASK_QueueIncrement(ptTaskQ, &ptTask->nTaskQ, 40);
            D2_ASSERT(ptTaskQ->nTaskQ < 32, 0x97);
            LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[ptTaskQ->nTaskQ]);
        }
        else
        {
            LeaveCriticalSection(&gtTaskQueuesCriticalSections_0088C7A8[nTaskSlotIdx]);
        }
        return;
    }
close_game:
    GAME_LeaveGamesCriticalSection(pGame);
    TASK_CloseGame(nGameHashKey, nTaskNumber, ptTask);
}
