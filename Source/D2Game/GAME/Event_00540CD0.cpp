#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2EventTimer.h"
struct D2EventTimerSlabListStrc;
struct D2EventTimerQueueStrc;

D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit); // 0x00553980

typedef char TimerSizeCheck[(sizeof(D2EventTimerStrc)==0x30)?1:-1];

typedef char SlabSizeCheck[(sizeof(D2EventTimerSlabListStrc)==0x7088)?1:-1];

typedef char QueueSizeCheck[(sizeof(D2EventTimerQueueStrc)==0xA20)?1:-1];
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern void __fastcall sub_6FCBDE90(D2UnitStrc*, int); // 0x005544B0

static __forceinline D2EventTimerStrc** sub_6FC353D0(D2GameStrc* pGame, int nUnitType, int nExpireFrame)
{
    const int nRow = gaSlotRows_006E0B9C[nUnitType];
    D2EventTimerQueueStrc* pTimerQueue = pGame->pTimerQueue;
    if (nExpireFrame == -1)
    {
        return &pTimerQueue->pInfinite[nRow];
    }
    return &pTimerQueue->pHead[nRow][nExpireFrame % 64];
}

static __declspec(noinline)
// 0x00540CD0
void sub_6FC34890(D2GameStrc* pGame, D2EventTimerStrc* pTimer)
{
    D2EventTimerQueueStrc* pTimerQueue = pGame->pTimerQueue;
    if (pTimer->nFlags & EVENTFLAG_0x1)
    {
        pTimer->nFlags |= EVENTFLAG_0x8;
        return;
    }
    if (pTimer == pTimerQueue->pCurrent)
    {
        pTimerQueue->pCurrent = pTimer->pNextFreeEventTimer;
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
    D2EventTimerSlabListStrc* pEventTimerArray = pTimerQueue->pSlabListHead;
    pTimer->pNextFreeEventTimer = pEventTimerArray->pFreeEventTimerListHead;
    pTimer->pPreviousQueuedTimer = 0;
    pEventTimerArray->pFreeEventTimerListHead = pTimer;
    pTimer->nFlags = EVENTFLAG_0x2;
}

void __fastcall EVENTS_DeleteByType(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId)
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

void __fastcall EVENTS_DeleteByCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, EventTimerCallback pCallback)
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

void __fastcall EVENTS_DeleteAll(D2GameStrc* pGame, D2UnitStrc* pUnit)
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

#include "gen/data/Source/D2Game/GAME/Event_00540CD0.inc"

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

// 0x00540DF0
static __declspec(noinline) D2EventTimerStrc* __stdcall EVENT_AllocateUnitTimer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2EventTimerQueueStrc* pQueue = pGame->pTimerQueue;
    D2EventTimerStrc* pTimer = sub_00540C30_AllocateTimer(pGame, pQueue);
    pTimer->pUnit = pUnit;
    pTimer->pNext = SUNIT_GetTimerFromUnit(pUnit);
    if (pTimer->pNext)
    {
        pTimer->pNext->pPrevious = pTimer;
    }
    pTimer->pPrevious = 0;
    SUNIT_SetTimerOnUnit(pUnit, pTimer);
    pTimer->nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    pTimer->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pTimer->nFlags &= ~2;
    return pTimer;
}

// build: context sub_00540DF0_Shim
// calling-convention shim (not game code)
D2EventTimerStrc* __fastcall sub_00540DF0_Shim(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return EVENT_AllocateUnitTimer(pGame, pUnit);
}
