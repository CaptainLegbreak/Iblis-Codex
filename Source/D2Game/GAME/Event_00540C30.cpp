#include "D2Game.h"
#include "D2Structs.h"

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
struct D2GameStrc
{
    char padding0x00[0x1C];
    void* pMemoryPool;
    char padding0x20[0x88];
    int dwGameFrame;
    char padding0xAC[0x0C];
    D2EventTimerQueueStrc* pTimerQueue;
};
typedef char TimerSizeCheck[(sizeof(D2EventTimerStrc)==0x30)?1:-1];
typedef char SlabSizeCheck[(sizeof(D2EventTimerSlabListStrc)==0x7088)?1:-1];
typedef char QueueSizeCheck[(sizeof(D2EventTimerQueueStrc)==0xA20)?1:-1];
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern void __fastcall sub_005544B0_SetUninterruptable(D2UnitStrc*, int); // 0x005544B0

// @ref 0x00540BB0
// build: symbol ?sub_00540BB0_AllocateSlab@@YAPAUD2EventTimerSlabListStrc@@PAUD2GameStrc@@@Z 0x00540BB0
static __declspec(noinline) D2EventTimerSlabListStrc* sub_00540BB0_AllocateSlab(D2GameStrc* pGame)
{
    D2EventTimerSlabListStrc* pSlab = (D2EventTimerSlabListStrc*)sub_0040B430_Alloc(pGame->pMemoryPool, sizeof(D2EventTimerSlabListStrc), ".\\GAME\\Event.cpp", 169, 0);
    if (!pSlab)
        return 0;
    memset(pSlab, 0, sizeof(D2EventTimerSlabListStrc));
    D2EventTimerStrc* pTimer = pSlab->tEventTimersStorage;
    pSlab->pFreeEventTimerListHead = pTimer;
    int nRemaining = 599;
    do
    {
        --nRemaining;
        pTimer->pNextFreeEventTimer = pTimer + 1;
        ++pTimer;
    }
    while (nRemaining);
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

// @ref 0x00540DF0

// build: context sub_00540DF0_InitializeTimer
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

// @ref 0x005415E0

// build: context sub_005415E0_InsertInfinite
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
    pTimer->unk0x20 = 0;
    if (pTimer->pNextFreeEventTimer)
        pTimer->pNextFreeEventTimer->unk0x20 = pTimer;
    *ppFirst = pTimer;
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

// @ref 0x005416B0
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
    if (pUnit && pUnit->dwUnitType == 1 && nEventType == 2)
    {
        if (sub_00639DF0_CheckState(pUnit, 54))
            sub_005544B0_SetUninterruptable(pUnit, 0);
    }
    D2EventTimerStrc* pTimer = sub_00540DF0_InitializeTimer(pGame, pUnit);
    pTimer->dwEventCustomId = nCustomId;
    pTimer->nEventType = (unsigned char)nEventType;
    pTimer->nExpireFrame = nExpireFrame;
    pTimer->dwEventCustomParam = nCustomParam;
    pTimer->pCallback = pCallback;
    D2EventTimerStrc** ppTail = nExpireFrame == -1 ? 0 : &pGame->pTimerQueue->pTail[gaSlotRows_006E0B9C[pTimer->nUnitType]][nExpireFrame % 64];
    pTimer->pNextFreeEventTimer = 0;
    pTimer->unk0x20 = *ppTail;
    if (pTimer->unk0x20)
        pTimer->unk0x20->pNextFreeEventTimer = pTimer;
    *ppTail = pTimer;
    D2EventTimerStrc** ppHead;
    if (pTimer->nExpireFrame == -1)
        ppHead = &pGame->pTimerQueue->pInfinite[gaSlotRows_006E0B9C[pTimer->nUnitType]];
    else
        ppHead = &pGame->pTimerQueue->pHead[gaSlotRows_006E0B9C[pTimer->nUnitType]][pTimer->nExpireFrame % 64];
    if (!*ppHead)
        *ppHead = pTimer;
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
