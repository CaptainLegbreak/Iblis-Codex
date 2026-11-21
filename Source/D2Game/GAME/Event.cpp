#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2EventTimer.h"
#include "D2Structs.h"

#define EVENTROW_PLAYER 0

#define EVENTROW_MONSTER 1

#define EVENTROW_MISSILE 2

#define EVENTROW_OBJECT 3

#define EVENTROW_ITEM 4

struct D2EventTimerSlabListStrc;

struct D2EventTimerQueueStrc;

typedef char TimerSizeCheck[(sizeof(D2EventTimerStrc) == 0x30) ? 1 : -1];

typedef char SlabSizeCheck[(sizeof(D2EventTimerSlabListStrc) == 0x7088) ? 1 : -1];

typedef char QueueSizeCheck[(sizeof(D2EventTimerQueueStrc) == 0xA20) ? 1 : -1];

typedef void(__fastcall* EventDefault3)(D2GameStrc*, D2UnitStrc*, int);

D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit); // 0x00553980

void __fastcall D2GAME_EVENTS_Callback_6FC81BD0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nCustomId, int nCustomParam); // 0x00581220

void __fastcall MONSTERMODE_EventHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nCustomId, int nCustomParam); // 0x005A7F80

void __fastcall D2GAME_OBJMODE_InvokeEventFunction_6FC75250(D2GameStrc* pGame, D2UnitStrc* pObject, int nEvent); // 0x00586AD0

void __fastcall sub_005ADCC0(D2GameStrc* pGame, D2UnitStrc* pMissile, int nEvent); // 0x005ADCC0

void __fastcall D2GAME_Items_EventsHandler_6FC4A460(D2GameStrc* pGame, D2UnitStrc* pItem, int nEvent); // 0x00562DA0

static void sub_6FC34890(D2GameStrc* pGame, D2EventTimerStrc* pTimer); // 0x00540CD0

void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0

extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0

extern void __fastcall sub_6FCBDE90(D2UnitStrc*, int); // 0x005544B0

static D2EventTimerSlabListStrc* sub_00540BB0_AllocateSlab(D2GameStrc* pGame);

static D2EventTimerStrc* __stdcall sub_00540C30_AllocateTimer(D2GameStrc* pGame, D2EventTimerQueueStrc* pQueue);

void __fastcall sub_00541470_InitializeQueue(D2GameStrc* pGame);

void __fastcall sub_00541650_DirectInfinite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nCustomId, int nCustomParam);

void __fastcall sub_00541680_DirectInfiniteCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, EventTimerCallback pCallback, int nCustomId, int nCustomParam);

void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam);

void __fastcall sub_00541800_DirectDatedCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, EventTimerCallback pCallback, int nCustomId, int nCustomParam);

struct D2Unk00540B70Obj;

struct D2Unk00540B70Owner;

struct D2Unk00540B70Obj
{
    char unk0x000[0x504];
    int f_504[1];
};

struct D2Unk00540B70Owner
{
    char unk0x00[0xB8];
    D2Unk00540B70Obj* pObj;
};

void __fastcall FOG_FreePool(void*,void*,const char*,int,int); // 0x0040B480

// 0x00540B20
static __forceinline D2EventTimerQueueStrc* sub_00540B20_GetTimerQueue(D2GameStrc* pGame)
{
    return pGame->pTimerQueue;
}

// 0x00540B30
static D2EventTimerStrc** __fastcall sub_00540B30_GetTimerListHead(D2GameStrc* pGame, int nExpireFrame, int nUnitType)
{
    const int nRow = gaSlotRows_006E0B9C[nUnitType];
    D2EventTimerQueueStrc* pQueue = pGame->pTimerQueue;
    if (nExpireFrame == -1)
        return &pQueue->pInfinite[nRow];
    return &pQueue->pHead[nRow][nExpireFrame % 64];
}

D2EventTimerStrc** __fastcall sub_M400_Emit_00540B30(D2GameStrc* pGame, int nExpireFrame, int nUnitType)
{
    return sub_00540B30_GetTimerListHead(pGame, nExpireFrame + 7, nUnitType);
}

// 0x00540B70
static int* __stdcall sub_00540B70_GetSlot(D2Unk00540B70Owner* pOwner, int nType, int nIndex)
{
    if (nIndex == -1)
    {
        return 0;
    }
    return &pOwner->pObj->f_504[gaSlotRows_006E0B9C[nType] * 64 + nIndex % 64];
}

// 0x00540BB0
static __declspec(noinline) D2EventTimerSlabListStrc* sub_00540BB0_AllocateSlab(D2GameStrc* pGame)
{
    D2EventTimerSlabListStrc* pSlab = (D2EventTimerSlabListStrc*)sub_0040B430_Alloc(pGame->pMemoryPool, sizeof(D2EventTimerSlabListStrc), ".\\GAME\\Event.cpp", 169, 0);
    if (!pSlab)
        return 0;
    memset(pSlab, 0, sizeof(D2EventTimerSlabListStrc));
    D2EventTimerStrc* pTimer = pSlab->tEventTimersStorage;
    pSlab->pFreeEventTimerListHead = pTimer;
    for (int i = 0; i < 599; ++i)
    {
        pTimer->pNextFreeEventTimer = pTimer + 1;
        ++pTimer;
    }
    pTimer->pNextFreeEventTimer = 0;
    return pSlab;
}

static __declspec(noinline) D2EventTimerStrc* sub_00540DF0_InitializeTimer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2EventTimerStrc* pTimer = sub_00540C30_AllocateTimer(pGame, pGame->pTimerQueue);
    pTimer->pUnit = pUnit;
    pTimer->pNext = sub_00553980_GetTimer(pUnit);
    if (pTimer->pNext)
        pTimer->pNext->pPrevious = pTimer;
    pTimer->pPrevious = 0;
    sub_00553970_SetTimer(pUnit, pTimer);
    pTimer->nUnitType = pUnit ? pUnit->dwUnitType : 6;
    pTimer->nUnitGUID = pUnit ? pUnit->dwUnitId : -1;
    pTimer->nFlags &= ~2;
    return pTimer;
}

static __declspec(noinline) void __stdcall sub_005415E0_InsertInfinite(EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType)
{
    if (nEventType >= 15)
        return;
    D2EventTimerStrc* pTimer = sub_00540DF0_InitializeTimer(pGame, pUnit);
    pTimer->nFlags |= 4;
    pTimer->dwEventCustomId = nCustomId;
    pTimer->nEventType = (unsigned char)nEventType;
    pTimer->nExpireFrame = -1;
    pTimer->dwEventCustomParam = nCustomParam;
    pTimer->pCallback = pCallback;
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    D2EventTimerStrc** ppFirst = &pGame->pTimerQueue->pInfinite[gaSlotRows_006E0B9C[nUnitType]];
    pTimer->pNextFreeEventTimer = *ppFirst;
    pTimer->pPreviousQueuedTimer = 0;
    if (pTimer->pNextFreeEventTimer)
        pTimer->pNextFreeEventTimer->pPreviousQueuedTimer = pTimer;
    *ppFirst = pTimer;
}

static __declspec(noinline) void __stdcall sub_005416B0_InsertDated(D2UnitStrc* pUnit, EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, int nEventType, int nExpireFrame)
{
    if (nEventType >= 15)
        return;
    if (nExpireFrame == -1)
    {
        sub_005415E0_InsertInfinite(0, nCustomId, nCustomParam, pGame, pUnit, nEventType);
        return;
    }
    if (nExpireFrame <= pGame->dwGameFrame)
        nExpireFrame = pGame->dwGameFrame + 1;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && nEventType == 2)
    {
        if (sub_00639DF0_CheckState(pUnit, 54))
            sub_6FCBDE90(pUnit, 0);
    }
    D2EventTimerStrc* pTimer = sub_00540DF0_InitializeTimer(pGame, pUnit);
    pTimer->dwEventCustomId = nCustomId;
    pTimer->nEventType = (unsigned char)nEventType;
    pTimer->nExpireFrame = nExpireFrame;
    pTimer->dwEventCustomParam = nCustomParam;
    pTimer->pCallback = pCallback;
    D2EventTimerStrc** ppTail = nExpireFrame == -1 ? 0 : &pGame->pTimerQueue->pTail[gaSlotRows_006E0B9C[pTimer->nUnitType]][nExpireFrame % 64];
    pTimer->pNextFreeEventTimer = 0;
    pTimer->pPreviousQueuedTimer = *ppTail;
    if (pTimer->pPreviousQueuedTimer)
        pTimer->pPreviousQueuedTimer->pNextFreeEventTimer = pTimer;
    *ppTail = pTimer;
    D2EventTimerStrc** ppHead;
    if (pTimer->nExpireFrame == -1)
        ppHead = &pGame->pTimerQueue->pInfinite[gaSlotRows_006E0B9C[pTimer->nUnitType]];
    else
        ppHead = &pGame->pTimerQueue->pHead[gaSlotRows_006E0B9C[pTimer->nUnitType]][pTimer->nExpireFrame % 64];
    if (!*ppHead)
        *ppHead = pTimer;
}

// 0x00540C10
static __forceinline void sub_00540C10_PushFreeTimer(D2EventTimerStrc* pTimer, D2EventTimerStrc** ppHead)
{
    D2EventTimerStrc* pHead = *ppHead;
    pTimer->pNextFreeEventTimer = pHead;
    pTimer->pPreviousQueuedTimer = 0;
    if (pHead)
        pHead->pPreviousQueuedTimer = pTimer;
    *ppHead = pTimer;
}

// 0x00540C30
static __declspec(noinline) D2EventTimerStrc* __stdcall sub_00540C30_AllocateTimer(D2GameStrc* pGame, D2EventTimerQueueStrc* pQueue)
{
    D2EventTimerSlabListStrc* pSlab = pQueue->pSlabListHead;
    while (pSlab)
    {
        if (pSlab->pFreeEventTimerListHead)
            break;
        pSlab = pSlab->pNextSlab;
    }
    if (!pSlab)
    {
        pSlab = sub_00540BB0_AllocateSlab(pGame);
        pSlab->pNextSlab = pQueue->pSlabListHead->pNextSlab;
        pQueue->pSlabListHead->pNextSlab = pSlab;
    }
    D2EventTimerStrc* pTimer = pSlab->pFreeEventTimerListHead;
    pSlab->pFreeEventTimerListHead = pTimer->pNextFreeEventTimer;
    memset(pTimer, 0, sizeof(D2EventTimerStrc));
    return pTimer;
}

// 0x00540CA0
static __forceinline void sub_00540CA0_ReleaseTimer(D2EventTimerQueueStrc* pQueue, D2EventTimerStrc* pTimer)
{
    D2EventTimerSlabListStrc* pSlab = pQueue->pSlabListHead;
    pTimer->pNextFreeEventTimer = pSlab->pFreeEventTimerListHead;
    pTimer->pPreviousQueuedTimer = 0;
    pSlab->pFreeEventTimerListHead = pTimer;
    pTimer->nFlags = 2;
}

void __stdcall sub_M113_Emit_00540B20(D2GameStrc* pGame, D2EventTimerStrc* pTimer, D2EventTimerStrc** ppHead)
{
    sub_00540C10_PushFreeTimer(pTimer, ppHead);
    sub_00540CA0_ReleaseTimer(sub_00540B20_GetTimerQueue(pGame), pTimer);
}

static __forceinline D2EventTimerStrc** sub_6FC353D0(D2GameStrc* pGame, int nUnitType, int nExpireFrame)
{
    if (nExpireFrame == -1)
    {
        return &pGame->pTimerQueue->pInfinite[gaSlotRows_006E0B9C[nUnitType]];
    }
    return &pGame->pTimerQueue->pHead[gaSlotRows_006E0B9C[nUnitType]][nExpireFrame % 64];
}

// build: context sub_6FC34890
static void sub_6FC34890(D2GameStrc* pGame, D2EventTimerStrc* pTimer)
{
    if (pTimer->nFlags & EVENTFLAG_0x1)
    {
        pTimer->nFlags |= EVENTFLAG_0x8;
        return;
    }
    if (pTimer == pGame->pTimerQueue->pCurrent)
    {
        pGame->pTimerQueue->pCurrent = pTimer->pNextFreeEventTimer;
    }
    if (pTimer->pPreviousQueuedTimer)
    {
        pTimer->pPreviousQueuedTimer->pNextFreeEventTimer = pTimer->pNextFreeEventTimer;
    }
    else
    {
        D2EventTimerStrc** ppEventTimer = sub_6FC353D0(pGame, pTimer->nUnitType, pTimer->nExpireFrame);
        *ppEventTimer = pTimer->pNextFreeEventTimer;
    }
    if (pTimer->pNextFreeEventTimer)
    {
        pTimer->pNextFreeEventTimer->pPreviousQueuedTimer = pTimer->pPreviousQueuedTimer;
    }
    else if (pTimer->nExpireFrame != -1)
    {
        D2EventTimerStrc** ppEventTimer = &pGame->pTimerQueue->pTail[gaSlotRows_006E0B9C[pTimer->nUnitType]][pTimer->nExpireFrame % 64];
        if (ppEventTimer && *ppEventTimer == pTimer)
        {
            *ppEventTimer = pTimer->pPreviousQueuedTimer;
        }
    }
    if (pTimer->pUnit)
    {
        if (pTimer->pNext)
        {
            pTimer->pNext->pPrevious = pTimer->pPrevious;
        }
        if (pTimer->pPrevious)
        {
            pTimer->pPrevious->pNext = pTimer->pNext;
        }
        else
        {
            SUNIT_SetTimerOnUnit(pTimer->pUnit, pTimer->pNext);
        }
    }
    D2EventTimerSlabListStrc* pEventTimerArray = pGame->pTimerQueue->pSlabListHead;
    pTimer->pPreviousQueuedTimer = 0;
    pTimer->pNextFreeEventTimer = pEventTimerArray->pFreeEventTimerListHead;
    pEventTimerArray->pFreeEventTimerListHead = pTimer;
    pTimer->nFlags = EVENTFLAG_0x2;
}

// 0x00540E60
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId)
{
    D2EventTimerStrc* pEventTimer = SUNIT_GetTimerFromUnit(pUnit);
    while (pEventTimer)
    {
        D2EventTimerStrc* pNextTimer = pEventTimer->pNext;
        if (pEventTimer->nEventType == nEventType && (!nEventCustomId || pEventTimer->dwEventCustomId == nEventCustomId))
        {
            sub_6FC34890(pGame, pEventTimer);
        }
        pEventTimer = pNextTimer;
    }
}

// 0x00540EA0
void __fastcall sub_6FC349B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, EventTimerCallback pCallback)
{
    D2EventTimerStrc* pEventTimer = SUNIT_GetTimerFromUnit(pUnit);
    while (pEventTimer)
    {
        D2EventTimerStrc* pNext = pEventTimer->pNext;
        if (pEventTimer->nEventType == nEvent)
        {
            if (pCallback == pEventTimer->pCallback)
            {
                sub_6FC34890(pGame, pEventTimer);
            }
        }
        pEventTimer = pNext;
    }
}

// 0x00540EE0
void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2EventTimerStrc* pEventTimer = SUNIT_GetTimerFromUnit(pUnit);
    while (pEventTimer)
    {
        D2EventTimerStrc* pNext = pEventTimer->pNext;
        sub_6FC34890(pGame, pEventTimer);
        pEventTimer->pUnit = 0;
        pEventTimer = pNext;
    }
    SUNIT_SetTimerOnUnit(pUnit, 0);
}

// 0x00540F30
void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (SUNIT_GetTimerFromUnit(pUnit))
    {
        sub_6FC349F0(pGame, pUnit);
    }

    SUNIT_SetTimerOnUnit(pUnit, 0);
}

// build: context EVENT_ExecuteEventsImpl5
static __forceinline void EVENT_ExecuteEventsImpl5(EventTimerCallback pDefaultCallback, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer, int a4)
{
    pTimerQueue->pCurrent = 0;
    D2EventTimerStrc* pTimer = pEventTimer;
    if (a4)
    {
        while (pTimer)
        {
            pTimerQueue->pCurrent = pTimer->pNextFreeEventTimer;
            if (pTimer->nExpireFrame == pGame->dwGameFrame)
            {
                pTimer->nFlags |= EVENTFLAG_0x1;
                if (pTimer->pCallback)
                {
                    pTimer->pCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
                }
                else
                {
                    pDefaultCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
                }
                pTimer->nFlags &= ~EVENTFLAG_0x1;
                sub_6FC34890(pGame, pTimer);
            }
            pTimer = pTimerQueue->pCurrent;
        }
    }
    else
    {
        while (pTimer)
        {
            pTimerQueue->pCurrent = pTimer->pNextFreeEventTimer;
            pTimer->nFlags |= EVENTFLAG_0x1;
            if (pTimer->pCallback)
            {
                pTimer->pCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
            }
            else
            {
                pDefaultCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
            }
            pTimer->nFlags &= ~EVENTFLAG_0x1;
            if (pTimer->nFlags & EVENTFLAG_0x8)
            {
                sub_6FC34890(pGame, pTimer);
            }
            pTimer = pTimerQueue->pCurrent;
        }
    }
}

// build: context EVENT_ExecuteEventsImpl3
static __forceinline void EVENT_ExecuteEventsImpl3(EventDefault3 pDefaultCallback, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer, int a4)
{
    pTimerQueue->pCurrent = 0;
    D2EventTimerStrc* pTimer = pEventTimer;
    if (a4)
    {
        while (pTimer)
        {
            pTimerQueue->pCurrent = pTimer->pNextFreeEventTimer;
            if (pTimer->nExpireFrame == pGame->dwGameFrame)
            {
                pTimer->nFlags |= EVENTFLAG_0x1;
                if (pTimer->pCallback)
                {
                    pTimer->pCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
                }
                else
                {
                    pDefaultCallback(pGame, pTimer->pUnit, pTimer->nEventType);
                }
                pTimer->nFlags &= ~EVENTFLAG_0x1;
                sub_6FC34890(pGame, pTimer);
            }
            pTimer = pTimerQueue->pCurrent;
        }
    }
    else
    {
        while (pTimer)
        {
            pTimerQueue->pCurrent = pTimer->pNextFreeEventTimer;
            pTimer->nFlags |= EVENTFLAG_0x1;
            if (pTimer->pCallback)
            {
                pTimer->pCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
            }
            else
            {
                pDefaultCallback(pGame, pTimer->pUnit, pTimer->nEventType);
            }
            pTimer->nFlags &= ~EVENTFLAG_0x1;
            if (pTimer->nFlags & EVENTFLAG_0x8)
            {
                sub_6FC34890(pGame, pTimer);
            }
            pTimer = pTimerQueue->pCurrent;
        }
    }
}

// 0x00540F60
static void __stdcall EVENT_ExecutePlayerEvents(int a4, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer)
{
    EVENT_ExecuteEventsImpl5(D2GAME_EVENTS_Callback_6FC81BD0, pGame, pTimerQueue, pEventTimer, a4);
}

// 0x00541060
static void __stdcall EVENT_ExecuteMonsterEvents(int a4, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer)
{
    EVENT_ExecuteEventsImpl5(MONSTERMODE_EventHandler, pGame, pTimerQueue, pEventTimer, a4);
}

// 0x00541160
static void __stdcall EVENT_ExecuteObjectEvents(int a4, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer)
{
    EVENT_ExecuteEventsImpl3(D2GAME_OBJMODE_InvokeEventFunction_6FC75250, pGame, pTimerQueue, pEventTimer, a4);
}

// 0x00541240
static void __stdcall EVENT_ExecuteMissileEvents(int a4, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer)
{
    EVENT_ExecuteEventsImpl3(sub_005ADCC0, pGame, pTimerQueue, pEventTimer, a4);
}

// 0x00541320
static void __stdcall EVENT_ExecuteItemEvents(int a4, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer)
{
    EVENT_ExecuteEventsImpl3(D2GAME_Items_EventsHandler_6FC4A460, pGame, pTimerQueue, pEventTimer, a4);
}

// 0x00541400
void __fastcall EVENT_FreeEventQueue(D2GameStrc* pGame)
{
    D2EventTimerQueueStrc* pTimerQueue = pGame->pTimerQueue;
    if (!pTimerQueue)
    {
        return;
    }

    D2EventTimerSlabListStrc* pTimerArray = pTimerQueue->pSlabListHead;
    while (pTimerArray)
    {
        D2EventTimerSlabListStrc* pNext = pTimerArray->pNextSlab;
        FOG_FreePool(pGame->pMemoryPool, pTimerArray, ".\\GAME\\Event.cpp", 0x314, 0);
        pTimerArray = pNext;
    }

    FOG_FreePool(pGame->pMemoryPool, pTimerQueue, ".\\GAME\\Event.cpp", 0x317, 0);
    pGame->pTimerQueue = 0;
}

// 0x00541470
void __fastcall sub_00541470_InitializeQueue(D2GameStrc* pGame)
{
    if (pGame->pTimerQueue)
        sub_00541400_FreeQueue(pGame);
    D2EventTimerQueueStrc* pQueue = (D2EventTimerQueueStrc*)sub_0040B430_Alloc(pGame->pMemoryPool, sizeof(D2EventTimerQueueStrc), ".\\GAME\\Event.cpp", 807, 0);
    memset(pQueue, 0, sizeof(D2EventTimerQueueStrc));
    pQueue->pSlabListHead = sub_00540BB0_AllocateSlab(pGame);
    pGame->pTimerQueue = pQueue;
}

// 0x005414D0
void __fastcall EVENT_IterateEvents(D2GameStrc* pGame)
{
    D2EventTimerQueueStrc* pTimerQueue = pGame->pTimerQueue;
    pTimerQueue->nArrayIndex = pGame->dwGameFrame % 64;
    EVENT_ExecuteMissileEvents(0, pGame, pTimerQueue, pTimerQueue->pInfinite[EVENTROW_MISSILE]);
    EVENT_ExecuteMissileEvents(1, pGame, pTimerQueue, pTimerQueue->pHead[EVENTROW_MISSILE][pTimerQueue->nArrayIndex]);
    EVENT_ExecutePlayerEvents(0, pGame, pTimerQueue, pTimerQueue->pInfinite[EVENTROW_PLAYER]);
    EVENT_ExecutePlayerEvents(1, pGame, pTimerQueue, pTimerQueue->pHead[EVENTROW_PLAYER][pTimerQueue->nArrayIndex]);
    EVENT_ExecuteMonsterEvents(0, pGame, pTimerQueue, pTimerQueue->pInfinite[EVENTROW_MONSTER]);
    EVENT_ExecuteMonsterEvents(1, pGame, pTimerQueue, pTimerQueue->pHead[EVENTROW_MONSTER][pTimerQueue->nArrayIndex]);
    EVENT_ExecuteObjectEvents(0, pGame, pTimerQueue, pTimerQueue->pInfinite[EVENTROW_OBJECT]);
    EVENT_ExecuteObjectEvents(1, pGame, pTimerQueue, pTimerQueue->pHead[EVENTROW_OBJECT][pTimerQueue->nArrayIndex]);
    EVENT_ExecuteItemEvents(0, pGame, pTimerQueue, pTimerQueue->pInfinite[EVENTROW_ITEM]);
    EVENT_ExecuteItemEvents(1, pGame, pTimerQueue, pTimerQueue->pHead[EVENTROW_ITEM][pTimerQueue->nArrayIndex]);
}

// 0x00541650
void __fastcall sub_00541650_DirectInfinite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nCustomId, int nCustomParam)
{
    sub_005415E0_InsertInfinite(0, nCustomId, nCustomParam, pGame, pUnit, nEventType);
}

// 0x00541680
void __fastcall sub_00541680_DirectInfiniteCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, EventTimerCallback pCallback, int nCustomId, int nCustomParam)
{
    sub_005415E0_InsertInfinite(pCallback, nCustomId, nCustomParam, pGame, pUnit, nEventType);
}

// 0x005417D0
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam)
{
    sub_005416B0_InsertDated(pUnit, 0, nCustomId, nCustomParam, pGame, nEventType, nExpireFrame);
}

// 0x00541800
void __fastcall sub_00541800_DirectDatedCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, EventTimerCallback pCallback, int nCustomId, int nCustomParam)
{
    sub_005416B0_InsertDated(pUnit, pCallback, nCustomId, nCustomParam, pGame, nEventType, nExpireFrame);
}

int* __fastcall sub_K10_EmitGetSlot(D2Unk00540B70Owner* pOwner, int nType)
{
    return sub_00540B70_GetSlot(pOwner, nType, nType + 1);
}
