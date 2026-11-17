struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2EventTimerStrc
{
    unsigned char nEventType;
    unsigned char padding0x01;
    unsigned short nFlags;
    int nExpireFrame;
    D2UnitStrc* pUnit;
    int nUnitGUID;
    int nUnitType;
    int dwEventCustomId;
    int dwEventCustomParam;
    D2EventTimerStrc* pNextQueuedTimer;
    D2EventTimerStrc* pPreviousQueuedTimer;
    D2EventTimerStrc* pNextUnitTimer;
    D2EventTimerStrc* pPreviousUnitTimer;
    void* pCallback;
};

struct D2EventTimerSlabListStrc
{
    D2EventTimerStrc tEventTimersStorage[600];
    D2EventTimerStrc* pFreeEventTimerListHead;
    D2EventTimerSlabListStrc* pNextSlab;
};

struct D2EventTimerQueueStrc
{
    char _pad_0x0[0xA04];
    D2EventTimerStrc* pInfinite[5];
    D2EventTimerStrc* pCurrent;
    D2EventTimerSlabListStrc* pSlabListHead;
};

struct D2GameStrc
{
    char _pad_0x0[0xB8];
    D2EventTimerQueueStrc* pTimerQueue;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2EventTimerSlabListStrc* __stdcall sub_00540BB0_AllocateSlab(D2GameStrc* pGame); // 0x00540BB0
void __fastcall SUNIT_SetTimerOnUnit(D2UnitStrc* pUnit, D2EventTimerStrc* pTimer); // 0x00553970
D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit); // 0x00553980

__declspec(noinline) static D2EventTimerStrc* __stdcall sub_00540C30_AllocateTimer(D2GameStrc* pGame, D2EventTimerQueueStrc* pQueue);

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
    pSlab->pFreeEventTimerListHead = pTimer->pNextQueuedTimer;
    memset(pTimer, 0, sizeof(D2EventTimerStrc));
    return pTimer;
}

__declspec(noinline) static D2EventTimerStrc* __stdcall EVENT_AllocateUnitTimer(D2GameStrc* pGame, D2UnitStrc* pUnit);

// 0x00540DF0
static D2EventTimerStrc* __stdcall EVENT_AllocateUnitTimer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2EventTimerQueueStrc* pQueue = pGame->pTimerQueue;
    D2EventTimerStrc* pTimer = sub_00540C30_AllocateTimer(pGame, pQueue);
    pTimer->pUnit = pUnit;
    pTimer->pNextUnitTimer = SUNIT_GetTimerFromUnit(pUnit);
    if (pTimer->pNextUnitTimer)
    {
        pTimer->pNextUnitTimer->pPreviousUnitTimer = pTimer;
    }
    pTimer->pPreviousUnitTimer = 0;
    SUNIT_SetTimerOnUnit(pUnit, pTimer);

    pTimer->nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    pTimer->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pTimer->nFlags &= ~2;
    return pTimer;
}

typedef void(__fastcall* EventTimerCallback)(D2GameStrc*, D2UnitStrc*, int, int, int);
extern const int gaSlotRows_006E0B9C[]; // 0x006E0B9C

__declspec(noinline) static void __stdcall sub_005415E0_InsertInfinite(EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType);

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
    pTimer->pCallback = (void*)pCallback;
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    D2EventTimerStrc** ppFirst = &pGame->pTimerQueue->pInfinite[gaSlotRows_006E0B9C[nUnitType]];
    pTimer->pNextQueuedTimer = *ppFirst;
    pTimer->pPreviousQueuedTimer = 0;
    if (pTimer->pNextQueuedTimer)
    {
        pTimer->pNextQueuedTimer->pPreviousQueuedTimer = pTimer;
    }
    *ppFirst = pTimer;
}

// 0x00541650
void __fastcall sub_00541650_DirectInfinite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nCustomId, int nCustomParam)
{
    sub_005415E0_InsertInfinite(0, nCustomId, nCustomParam, pGame, pUnit, nEventType);
}
