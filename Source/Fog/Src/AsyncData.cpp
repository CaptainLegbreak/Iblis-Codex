#include "Fog.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct AsyncDataEventSlot;
struct D2OverlappedStrc;
struct AsyncData;
struct AsyncDataLoadFileCallback;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct AsyncData
{
    void* hFile;
    void* pMemPool;
    D2OverlappedStrc tOverlapped;
    AsyncDataLoadFileCallback pAsyncOpDesc;
    AsyncDataEventSlot* pEventSlot;
    void* pBuffer;
    unsigned int nFileSize;
    int nPriority;
    unsigned int nFlags;
    int nPreviousPriority;
    AsyncData* pNextPostponedPriorityChange;
};

int __stdcall sub_0041AA80(void* pHandle, int nValue); // 0x0041AA80

struct AsyncDataEventSlot
{
    void* hEvent;
    unsigned long bSlotAvailable;
    AsyncData* pAsyncOp;
};

extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName); // 0x006CC228
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __stdcall sub_004164A0_SetValue(int nValue); // 0x004164A0
void __stdcall sub_00416570_SetPowerOfTwoValue(int nValue); // 0x00416570
int __stdcall sub_0041A930_CancelRead(void* pBuffer); // 0x0041A930
void __fastcall sub_0040A4C0_AsyncDataFinish(AsyncData* pAsyncData); // 0x0040A4C0
int __fastcall FOG_AsyncDataTestLoaded(AsyncData* pAsyncData); // 0x0040A7F0
void __fastcall FOG_AsyncDataWaitAndGetBuffer(AsyncData* pAsyncData); // 0x0040A960
extern AsyncData* gpAsyncDataPostponed_0075AF90; // 0x0075AF90
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) int __stdcall ResetEvent(void* hEvent); // 0x006CC22C
void __fastcall sub_004068F0(void* hFile); // 0x004068F0

int gnAsyncDataPostponeCount_0075AF8C; // 0x0075AF8C

AsyncData* gpAsyncDataPostponed_0075AF90; // 0x0075AF90

// 0x0040A030
void __cdecl sub_0040A030_Nop()
{
}

// 0x0040A850
void __fastcall FOG_AsyncDataSetPriority(AsyncData* pAsyncData, int nPriority)
{
    D2_ASSERT(pAsyncData, 0x1DA);
    D2_ASSERT((pAsyncData->nFlags & 0xFFFFFFF0) == 0x41737960, 0x1DB);
    D2_ASSERT(nPriority <= 0, 0x1DC);
    if (gnAsyncDataPostponeCount_0075AF8C > 0)
    {
        if (pAsyncData->nFlags & 8)
        {
            if (nPriority > pAsyncData->nPriority)
            {
                pAsyncData->nPriority = nPriority;
            }
        }
        else
        {
            pAsyncData->nPreviousPriority = pAsyncData->nPriority;
            pAsyncData->nPriority = nPriority;
            pAsyncData->nFlags |= 8;
            pAsyncData->pNextPostponedPriorityChange = gpAsyncDataPostponed_0075AF90;
            gpAsyncDataPostponed_0075AF90 = pAsyncData;
        }
    }
    else if (nPriority != pAsyncData->nPriority)
    {
        pAsyncData->nPriority = nPriority;
        sub_0041AA80(pAsyncData->pBuffer, nPriority);
    }
}

// 0x0040A8E0
void __fastcall FOG_AsyncDataHandlePriorityChanges(int bPostpone)
{
    if (bPostpone)
    {
        ++gnAsyncDataPostponeCount_0075AF8C;
        return;
    }
    D2_ASSERT(gnAsyncDataPostponeCount_0075AF8C > 0, 0x211);
    if (--gnAsyncDataPostponeCount_0075AF8C == 0)
    {
        AsyncData* pNext;
        for (AsyncData* p = gpAsyncDataPostponed_0075AF90; p; p = pNext)
        {
            pNext = p->pNextPostponedPriorityChange;
            if (p->nPriority != p->nPreviousPriority)
            {
                sub_0041AA80(p->pBuffer, p->nPriority);
            }
            p->nFlags &= ~8;
            p->nPreviousPriority = 0;
            p->pNextPostponedPriorityChange = 0;
        }
        gpAsyncDataPostponed_0075AF90 = 0;
    }
}

void __fastcall sub_0040ABF0_HeapSiftDown(int* pHeap, int nCount, int nIndex)
{
    int nValue = pHeap[nIndex];
    int nHalf = nCount / 2;
    nCount -= 1;
    while (nIndex < nHalf)
    {
        int nChild = 2 * nIndex + 1;
        if (nChild < nCount && pHeap[nChild] < pHeap[nChild + 1])
            nChild += 1;
        if (nValue > pHeap[nChild])
            break;
        pHeap[nIndex] = pHeap[nChild];
        nIndex = nChild;
    }
    pHeap[nIndex] = nValue;
}

// 0x0040AC60
void __fastcall sub_0040AC60_HeapSort(int* pHeap, int nCount)
{
    for (int i = nCount / 2; i;)
    {
        --i;
        sub_0040ABF0_HeapSiftDown(pHeap, nCount, i);
    }
    while (--nCount)
    {
        const int nTop = pHeap[0];
        pHeap[0] = pHeap[nCount];
        pHeap[nCount] = nTop;
        sub_0040ABF0_HeapSiftDown(pHeap, nCount, 0);
    }
}

// 0x0040ADA0
void __cdecl sub_0040ADA0_Nop()
{
}

static int s_bAsyncDataEnabled_0075AF94; // 0x0075AF94

static unsigned int s_nAsyncEventSlots_0075AF98; // 0x0075AF98

static AsyncDataEventSlot* s_pAsyncEventSlots_0075AF9C; // 0x0075AF9C

// 0x0040A390
void __fastcall FOG_AsyncDataInitialize(int bEnable, int nUnused)
{
    D2_ASSERT(!s_bAsyncDataEnabled_0075AF94, 123);
    sub_004164A0_SetValue(0x40000);
    sub_00416570_SetPowerOfTwoValue(0x4000);
    if (bEnable)
    {
        s_pAsyncEventSlots_0075AF9C = (AsyncDataEventSlot*)FOG_Alloc(0x3000, ".\\Src\\AsyncData.cpp", 136, 0);
        D2_ASSERT(s_pAsyncEventSlots_0075AF9C, 137);
        for (int i = 0; i < 0x100; i++)
        {
            AsyncDataEventSlot* pSlot = &s_pAsyncEventSlots_0075AF9C[i];
            pSlot->hEvent = CreateEventA(0, 1, 0, 0);
            pSlot->bSlotAvailable = 1;
        }
        s_nAsyncEventSlots_0075AF98 = 0x100;
        s_bAsyncDataEnabled_0075AF94 = 1;
    }
}

// 0x0040A440
void __cdecl FOG_AsyncDataDestroy()
{
    if (s_pAsyncEventSlots_0075AF9C)
    {
        for (unsigned int i = 0; i < s_nAsyncEventSlots_0075AF98; i++)
        {
            AsyncDataEventSlot* pSlot = &s_pAsyncEventSlots_0075AF9C[i];
            if (pSlot && pSlot->hEvent)
            {
                CloseHandle(pSlot->hEvent);
                pSlot->hEvent = 0;
            }
        }
        FOG_Free(s_pAsyncEventSlots_0075AF9C, ".\\Src\\AsyncData.cpp", 174, 0);
        s_pAsyncEventSlots_0075AF9C = 0;
        s_nAsyncEventSlots_0075AF98 = 0;
    }
    s_bAsyncDataEnabled_0075AF94 = 0;
}

// 0x0040A550
AsyncDataEventSlot* __cdecl sub_0040A550_AsyncDataGetEventSlot()
{
    if (s_bAsyncDataEnabled_0075AF94)
    {
        for (unsigned int i = 0; i < s_nAsyncEventSlots_0075AF98; i++)
        {
            AsyncDataEventSlot* pSlot = &s_pAsyncEventSlots_0075AF9C[i];
            if (pSlot->bSlotAvailable)
            {
                pSlot->bSlotAvailable = 0;
                return pSlot;
            }
        }
        for (unsigned int i = 0; i < s_nAsyncEventSlots_0075AF98; i++)
        {
            AsyncDataEventSlot* pSlot = &s_pAsyncEventSlots_0075AF9C[i];
            if (!WaitForSingleObject(pSlot->hEvent, 0))
            {
                sub_0040A4C0_AsyncDataFinish(pSlot->pAsyncOp);
                pSlot->bSlotAvailable = 0;
                return pSlot;
            }
        }
        if (s_nAsyncEventSlots_0075AF98 < 0x400)
        {
            AsyncDataEventSlot* pSlot = &s_pAsyncEventSlots_0075AF9C[s_nAsyncEventSlots_0075AF98++];
            pSlot->hEvent = CreateEventA(0, 1, 0, 0);
            pSlot->bSlotAvailable = 0;
            return pSlot;
        }
    }
    return 0;
}

// 0x0040A9E0
void* __fastcall FOG_AsyncDataGetBuffer(AsyncData* pAsyncData)
{
    D2_ASSERT(pAsyncData, 607);
    D2_ASSERT((pAsyncData->nFlags & 0xFFFFFFF0) == 0x41737960, 608);
    if (!(pAsyncData->nFlags & 1))
    {
        FOG_AsyncDataWaitAndGetBuffer(pAsyncData);
    }
    D2_ASSERT(pAsyncData->nFlags & 1, 614);
    return pAsyncData->pBuffer;
}

// 0x0040AA40
unsigned int __fastcall FOG_AsyncDataGetBufferSize(AsyncData* pAsyncData)
{
    D2_ASSERT(pAsyncData, 625);
    D2_ASSERT((pAsyncData->nFlags & 0xFFFFFFF0) == 0x41737960, 626);
    return pAsyncData->nFileSize;
}

// 0x0040AB00
void __fastcall FOG_AsyncDataFree(AsyncData* ptAsyncData)
{
    D2_ASSERT(ptAsyncData, 656);
    D2_ASSERT((ptAsyncData->nFlags & 0xFFFFFFF0) == 0x41737960, 657);
    if (ptAsyncData->nFlags & 8)
    {
        for (AsyncData** ppLink = &gpAsyncDataPostponed_0075AF90; ppLink; ppLink = &(*ppLink)->pNextPostponedPriorityChange)
        {
            if (*ppLink == ptAsyncData)
            {
                *ppLink = ptAsyncData->pNextPostponedPriorityChange;
                break;
            }
        }
    }
    if (!FOG_AsyncDataTestLoaded(ptAsyncData))
    {
        sub_0041A930_CancelRead(ptAsyncData->pBuffer);
        WaitForSingleObject(ptAsyncData->pEventSlot->hEvent, (unsigned long)-1);
        sub_0040A4C0_AsyncDataFinish(ptAsyncData);
    }
    if (ptAsyncData->nFlags & 2)
    {
        D2_ASSERT(ptAsyncData->pBuffer, 707);
        FOG_FreeServerMemory(ptAsyncData->pMemPool, ptAsyncData->pBuffer, ".\\Src\\AsyncData.cpp", 710, 0);
        ptAsyncData->nFlags &= 0xF;
        ptAsyncData->pBuffer = 0;
    }
    FOG_FreeServerMemory(ptAsyncData->pMemPool, ptAsyncData, ".\\Src\\AsyncData.cpp", 717, 0);
}

// 0x0040A4C0
void __fastcall sub_0040A4C0_AsyncDataFinish(AsyncData* pAsyncData)
{
    if (pAsyncData->nFlags & 1)
    {
        return;
    }
    AsyncDataEventSlot* pSlot = pAsyncData->pEventSlot;
    if (pSlot)
    {
        ResetEvent(pSlot->hEvent);
        pSlot->bSlotAvailable = 1;
        pSlot->pAsyncOp = 0;
        pAsyncData->pEventSlot = 0;
    }
    if (pAsyncData->hFile)
    {
        sub_004068F0(pAsyncData->hFile);
        pAsyncData->hFile = 0;
    }
    pAsyncData->nFlags |= 1;
    if (pAsyncData->pAsyncOpDesc.pData)
    {
        FOG_FreeServerMemory(pAsyncData->pMemPool, pAsyncData->pBuffer, ".\\Src\\AsyncData.cpp", 215, 0);
        pAsyncData->pBuffer = pAsyncData->pAsyncOpDesc.pData;
        pAsyncData->nFileSize = pAsyncData->pAsyncOpDesc.nFileSize;
        memset(&pAsyncData->pAsyncOpDesc, 0, sizeof(pAsyncData->pAsyncOpDesc));
    }
}

// 0x0040A7F0
int __fastcall FOG_AsyncDataTestLoaded(AsyncData* ptAsyncData)
{
    if (!ptAsyncData)
    {
        return 0;
    }
    D2_ASSERT((ptAsyncData->nFlags & 0xFFFFFFF0) == 0x41737960, 452);
    if (!(ptAsyncData->nFlags & 1))
    {
        if (!WaitForSingleObject(ptAsyncData->pEventSlot->hEvent, 0))
        {
            sub_0040A4C0_AsyncDataFinish(ptAsyncData);
        }
    }
    return ptAsyncData->nFlags & 1;
}

// 0x0040A960
void __fastcall FOG_AsyncDataWaitAndGetBuffer(AsyncData* pAsyncData)
{
    D2_ASSERT(pAsyncData, 562);
    D2_ASSERT((pAsyncData->nFlags & 0xFFFFFFF0) == 0x41737960, 563);

    if (!FOG_AsyncDataTestLoaded(pAsyncData))
    {
        sub_0041AA80(pAsyncData->pBuffer, 1);
        D2_ASSERT(!WaitForSingleObject(pAsyncData->pEventSlot->hEvent, 0xFFFFFFFF), 584);
        sub_0040A4C0_AsyncDataFinish(pAsyncData);
    }
}
