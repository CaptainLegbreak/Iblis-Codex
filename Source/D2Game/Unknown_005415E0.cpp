#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2EventTimer.h"

struct D2EventTimerSlabListStrc;
struct D2EventTimerQueueStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2EventTimerSlabListStrc* __stdcall sub_00540BB0_AllocateSlab(D2GameStrc* pGame); // 0x00540BB0
D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit); // 0x00553980
__declspec(noinline) static D2EventTimerStrc* __stdcall sub_00540C30_AllocateTimer(D2GameStrc* pGame, D2EventTimerQueueStrc* pQueue);
__declspec(noinline) static D2EventTimerStrc* __stdcall EVENT_AllocateUnitTimer(D2GameStrc* pGame, D2UnitStrc* pUnit);

__declspec(noinline) static void __stdcall sub_005415E0_InsertInfinite(EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType);
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __fastcall sub_6FCBDE90(D2UnitStrc* pUnit, int bUninterruptable); // 0x005544B0
__declspec(noinline) static void __stdcall sub_005416B0_InsertDated(D2UnitStrc* pUnit, EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, int nEventType, int nExpireFrame);

// build: context sub_00540C30_AllocateTimer
static D2EventTimerStrc* __stdcall sub_00540C30_AllocateTimer(D2GameStrc* pGame, D2EventTimerQueueStrc* pQueue)
{
    D2EventTimerSlabListStrc* pSlab = pQueue->pSlabListHead;
    while (pSlab)
    {
        if (pSlab->pFreeEventTimerListHead)
        {
            break;
        }
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
static D2EventTimerStrc* __stdcall EVENT_AllocateUnitTimer(D2GameStrc* pGame, D2UnitStrc* pUnit)
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

// 0x005415E0
static void __stdcall sub_005415E0_InsertInfinite(EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType)
{
    if (nEventType >= 15)
    {
        return;
    }

    D2EventTimerStrc* pTimer = EVENT_AllocateUnitTimer(pGame, pUnit);
    pTimer->nFlags |= 4;
    pTimer->dwEventCustomId = nCustomId;
    pTimer->nEventType = (unsigned char)nEventType;
    pTimer->nExpireFrame = -1;
    pTimer->dwEventCustomParam = nCustomParam;
    pTimer->pCallback = pCallback;
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    D2EventTimerStrc** ppFirst = &pGame->pTimerQueue->pInfinite[gaSlotRows_006E0B9C[nUnitType]];
    pTimer->pNextFreeEventTimer = *ppFirst;
    pTimer->pPreviousQueuedTimer = 0;
    if (pTimer->pNextFreeEventTimer)
    {
        pTimer->pNextFreeEventTimer->pPreviousQueuedTimer = pTimer;
    }
    *ppFirst = pTimer;
}

// 0x00541650
void __fastcall sub_00541650_DirectInfinite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nCustomId, int nCustomParam)
{
    sub_005415E0_InsertInfinite(0, nCustomId, nCustomParam, pGame, pUnit, nEventType);
}

static __forceinline D2EventTimerStrc** EVENT_GetTimerListHead(D2GameStrc* pGame, int nUnitType, int nExpireFrame)
{
    const int nIndex = gaSlotRows_006E0B9C[nUnitType];
    D2EventTimerQueueStrc* pQueue = pGame->pTimerQueue;
    if (nExpireFrame == -1)
    {
        return &pQueue->pInfinite[nIndex];
    }

    return &pQueue->pHead[nIndex][nExpireFrame % 64];
}

static __forceinline D2EventTimerStrc** EVENT_GetTimerListTail(D2GameStrc* pGame, int nUnitType, int nExpireFrame)
{
    if (nExpireFrame == -1)
    {
        return 0;
    }

    return &pGame->pTimerQueue->pTail[gaSlotRows_006E0B9C[nUnitType]][nExpireFrame % 64];
}

// 0x005416B0
static void __stdcall sub_005416B0_InsertDated(D2UnitStrc* pUnit, EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, int nEventType, int nExpireFrame)
{
    if (nEventType >= 15)
    {
        return;
    }

    if (nExpireFrame == -1)
    {
        sub_005415E0_InsertInfinite(0, nCustomId, nCustomParam, pGame, pUnit, nEventType);
        return;
    }

    if (nExpireFrame <= pGame->dwGameFrame)
    {
        nExpireFrame = pGame->dwGameFrame + 1;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && nEventType == 2)
    {
        if (STATES_CheckState(pUnit, 54))
        {
            sub_6FCBDE90(pUnit, 0);
        }
    }

    D2EventTimerStrc* pTimer = EVENT_AllocateUnitTimer(pGame, pUnit);
    pTimer->dwEventCustomId = nCustomId;
    pTimer->nEventType = (unsigned char)nEventType;
    pTimer->nExpireFrame = nExpireFrame;
    pTimer->dwEventCustomParam = nCustomParam;
    pTimer->pCallback = pCallback;

    D2EventTimerStrc** ppTail = EVENT_GetTimerListTail(pGame, pTimer->nUnitType, nExpireFrame);
    pTimer->pNextFreeEventTimer = 0;
    pTimer->pPreviousQueuedTimer = *ppTail;
    if (pTimer->pPreviousQueuedTimer)
    {
        pTimer->pPreviousQueuedTimer->pNextFreeEventTimer = pTimer;
    }
    *ppTail = pTimer;

    D2EventTimerStrc** ppHead = EVENT_GetTimerListHead(pGame, pTimer->nUnitType, pTimer->nExpireFrame);

    if (!*ppHead)
    {
        *ppHead = pTimer;
    }
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
