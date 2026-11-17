struct D2UnitStrc;
struct D2GameStrc;
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
    char unk0x00[0xA8];
    int dwGameFrame;
    char unk0xAC[0x0C];
    D2EventTimerQueueStrc* pTimerQueue;
};

#define EVENTFLAG_0x1 1
#define EVENTFLAG_0x2 2
#define EVENTFLAG_0x8 8

extern const int gaSlotRows_006E0B9C[]; // 0x006E0B9C
D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit); // 0x00553980
void __fastcall SUNIT_SetTimerOnUnit(D2UnitStrc* pUnit, D2EventTimerStrc* pTimer); // 0x00553970

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
    D2EventTimerSlabListStrc* pEventTimerArray = pTimerQueue->pSlabListHead;
    pTimer->pNextFreeEventTimer = pEventTimerArray->pFreeEventTimerListHead;
    pTimer->unk0x20 = 0;
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

#include "gen/data/Source/D2Game/00540CD0_sub_6FC34890.inc"
