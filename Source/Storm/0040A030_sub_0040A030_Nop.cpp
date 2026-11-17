extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2OverlappedStrc
{
    unsigned long Internal;
    unsigned long InternalHigh;
    unsigned long Offset;
    unsigned long OffsetHigh;
    void* hEvent;
};

struct AsyncDataEventSlot;

struct AsyncData
{
    void* hFile;
    void* pMemPool;
    D2OverlappedStrc tOverlapped;
    unsigned long pAsyncOpDesc[7];
    AsyncDataEventSlot* pEventSlot;
    void* pBuffer;
    unsigned int nFileSize;
    int nPriority;
    unsigned int nFlags;
    int nPreviousPriority;
    AsyncData* pNextPostponedPriorityChange;
};

int __stdcall sub_0041AA80(void* pHandle, int nValue);                                                      // 0x0041AA80
int gnAsyncDataPostponeCount_0075AF8C;                                                                      // 0x0075AF8C
AsyncData* gpAsyncDataPostponed_0075AF90;                                                                   // 0x0075AF90

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
