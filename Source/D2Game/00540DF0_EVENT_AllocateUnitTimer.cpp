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
struct D2UnitStrc
{
    int dwUnitType;
    char padding0x04[0x08];
    int dwUnitId;
    char padding0x10[0xCC];
    D2EventTimerStrc* pTimer;
};
typedef char TimerSizeCheck[(sizeof(D2EventTimerStrc)==0x30)?1:-1];
typedef char SlabSizeCheck[(sizeof(D2EventTimerSlabListStrc)==0x7088)?1:-1];
typedef char QueueSizeCheck[(sizeof(D2EventTimerQueueStrc)==0xA20)?1:-1];

extern void* __fastcall sub_0040B430_Alloc(void*, unsigned int, const char*, int, int); // 0x0040B430
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern void __fastcall sub_00541400_FreeQueue(D2GameStrc*); // 0x00541400
extern int __stdcall sub_00639DF0_CheckState(D2UnitStrc*, int); // 0x00639DF0
extern void __fastcall sub_005544B0_SetUninterruptable(D2UnitStrc*, int); // 0x005544B0
extern const int gaSlotRows_006E0B9C[]; // 0x006E0B9C

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

D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit); // 0x00553980
void __fastcall SUNIT_SetTimerOnUnit(D2UnitStrc* pUnit, D2EventTimerStrc* pTimer); // 0x00553970

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
