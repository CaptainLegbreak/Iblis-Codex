#include "D2Game.h"
#include "D2GameStrc.h"
#define EVENTROW_PLAYER 0
#define EVENTROW_MONSTER 1
#define EVENTROW_MISSILE 2
#define EVENTROW_OBJECT 3
#define EVENTROW_ITEM 4
struct D2EventTimerSlabListStrc;
struct D2EventTimerQueueStrc;

typedef void(__fastcall* EventTimerCallback)(D2GameStrc*, D2UnitStrc*, int, int, int);

struct D2EventTimerStrc
{
    unsigned char nEventType;
    char padding0x01;
    unsigned short nFlags;
    int nExpireFrame;
    D2UnitStrc* pUnit;
    int nUnitGUID;
    int nUnitType;
    int dwEventCustomId;
    int dwEventCustomParam;
    D2EventTimerStrc* pNextFreeEventTimer;
    D2EventTimerStrc* unk0x20;
    D2EventTimerStrc* pNext;
    D2EventTimerStrc* pPrevious;
    EventTimerCallback pCallback;
};

struct D2EventTimerSlabListStrc
{
    D2EventTimerStrc tEventTimersStorage[600];
    D2EventTimerStrc* pFreeEventTimerListHead;
    D2EventTimerSlabListStrc* pNextSlab;
};

struct D2EventTimerQueueStrc
{
    int nArrayIndex;
    D2EventTimerStrc* pHead[5][64];
    D2EventTimerStrc* pTail[5][64];
    D2EventTimerStrc* pInfinite[5];
    D2EventTimerStrc* pCurrent;
    D2EventTimerSlabListStrc* pSlabListHead;
};


typedef char TimerSizeCheck[(sizeof(D2EventTimerStrc) == 0x30) ? 1 : -1];

typedef char SlabSizeCheck[(sizeof(D2EventTimerSlabListStrc) == 0x7088) ? 1 : -1];

typedef char QueueSizeCheck[(sizeof(D2EventTimerQueueStrc) == 0xA20) ? 1 : -1];

typedef void(__fastcall* EventDefault3)(D2GameStrc*, D2UnitStrc*, int);
D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit); // 0x00553980
void __fastcall D2GAME_EVENTS_Callback_6FC81BD0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nCustomId, int nCustomParam); // 0x00581220
void __fastcall MONSTERMODE_EventHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nCustomId, int nCustomParam); // 0x005A7F80
void __fastcall D2GAME_OBJMODE_InvokeEventFunction_6FC75250(D2GameStrc* pGame, D2UnitStrc* pObject, int nEvent); // 0x00586AD0
void __fastcall MISSMODE_SrvDoHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, int nEvent); // 0x005ADCC0
void __fastcall D2GAME_Items_EventsHandler_6FC4A460(D2GameStrc* pGame, D2UnitStrc* pItem, int nEvent); // 0x00562DA0
static void sub_6FC34890(D2GameStrc* pGame, D2EventTimerStrc* pTimer); // 0x00540CD0
void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0

// 0x00540B20
static __forceinline D2EventTimerQueueStrc* sub_00540B20_GetTimerQueue(D2GameStrc* pGame)
{
    return pGame->pTimerQueue;
}

// 0x00540C10
static __forceinline void sub_00540C10_PushFreeTimer(D2EventTimerStrc* pTimer, D2EventTimerStrc** ppHead)
{
    D2EventTimerStrc* pHead = *ppHead;
    pTimer->pNextFreeEventTimer = pHead;
    pTimer->unk0x20 = 0;
    if (pHead)
        pHead->unk0x20 = pTimer;
    *ppHead = pTimer;
}

// 0x00540CA0
static __forceinline void sub_00540CA0_ReleaseTimer(D2EventTimerQueueStrc* pQueue, D2EventTimerStrc* pTimer)
{
    D2EventTimerSlabListStrc* pSlab = pQueue->pSlabListHead;
    pTimer->pNextFreeEventTimer = pSlab->pFreeEventTimerListHead;
    pTimer->unk0x20 = 0;
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
    if (pTimer->unk0x20)
    {
        pTimer->unk0x20->pNextFreeEventTimer = pTimer->pNextFreeEventTimer;
    }
    else
    {
        D2EventTimerStrc** ppEventTimer = sub_6FC353D0(pGame, pTimer->nUnitType, pTimer->nExpireFrame);
        *ppEventTimer = pTimer->pNextFreeEventTimer;
    }
    if (pTimer->pNextFreeEventTimer)
    {
        pTimer->pNextFreeEventTimer->unk0x20 = pTimer->unk0x20;
    }
    else if (pTimer->nExpireFrame != -1)
    {
        D2EventTimerStrc** ppEventTimer = &pGame->pTimerQueue->pTail[gaSlotRows_006E0B9C[pTimer->nUnitType]][pTimer->nExpireFrame % 64];
        if (ppEventTimer && *ppEventTimer == pTimer)
        {
            *ppEventTimer = pTimer->unk0x20;
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
    pTimer->unk0x20 = 0;
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
    EVENT_ExecuteEventsImpl3(MISSMODE_SrvDoHandler, pGame, pTimerQueue, pEventTimer, a4);
}

// 0x00541320
static void __stdcall EVENT_ExecuteItemEvents(int a4, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer)
{
    EVENT_ExecuteEventsImpl3(D2GAME_Items_EventsHandler_6FC4A460, pGame, pTimerQueue, pEventTimer, a4);
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

// 0x00540F30
void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (SUNIT_GetTimerFromUnit(pUnit))
    {
        sub_6FC349F0(pGame, pUnit);
    }

    SUNIT_SetTimerOnUnit(pUnit, 0);
}
