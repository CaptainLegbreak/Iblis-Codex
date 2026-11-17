struct D2GameStrc;
struct D2UnitStrc;
struct D2EventTimerStrc;
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

typedef char TimerSizeCheck[(sizeof(D2EventTimerStrc) == 0x30) ? 1 : -1];
typedef char SlabSizeCheck[(sizeof(D2EventTimerSlabListStrc) == 0x7088) ? 1 : -1];
typedef char QueueSizeCheck[(sizeof(D2EventTimerQueueStrc) == 0xA20) ? 1 : -1];

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
