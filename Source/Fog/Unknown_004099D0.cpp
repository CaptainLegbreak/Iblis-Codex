#include "Fog.h"

typedef unsigned int size_t;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct T00408A30_2;

struct T00408A30
{
    void* pMemory;
    unsigned int* pUsedBits;
    int nUsed;
    T00408A30* pPrev;
    T00408A30* pNext;
    T00408A30_2* pPool;
};

struct T00408A30_2
{
    D2CriticalSectionStrc tLock;
    int f_18;
    int nElementsPerBlock;
    int nUnk0x20;
    int nBlocks;
    T00408A30* pFirstBlock;
    T00408A30* pLastBlock;
};

struct D2PoolRecordStrc
{
    T00408A30* pBlock;
    void* pMemory;
};

struct D2PoolSystemStrc
{
    int bFreePoolAlloc;
    D2CriticalSectionStrc tLock;
    int nPools;
    T00408A30_2 aPools[40];
    int nLargeOverflow;
    int nUnk0x7A4;
    D2PoolRecordStrc* pUnk0x7A8;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
struct T00408A30_1
{
    int bInit;
    D2CriticalSectionStrc tLock;
    D2PoolSystemStrc aSystems[8];
    int nUnk0xBE7C;
    unsigned int anFreeIndex[8];
    int nFreeCount;
};

extern T00408A30_1 gtPoolManager_0074F0E8;                                                                  // 0x0074F0E8
#define gtDefaultPoolSystem_0074F104 (gtPoolManager_0074F0E8.aSystems[0])
void* __fastcall sub_0040A080_PoolAlloc(void* pPool, int nSize, const char* szFile, int nLine);             // 0x0040A080

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x004099D0
static T00408A30* __stdcall sub_004099D0_FindBlock(void* pMemory, D2PoolSystemStrc* pSystem)
{
    D2PoolRecordStrc* pRecords = pSystem->pUnk0x7A8;
    EnterCriticalSection(&pSystem->tLock);
    int nLow = 0;
    int nHigh = pSystem->nLargeOverflow;
    while (nLow < nHigh)
    {
        const int nMid = nLow + ((nHigh - nLow) >> 1);
        if (pMemory >= pRecords[nMid].pMemory)
        {
            nLow = nMid + 1;
        }
        else
        {
            nHigh = nMid;
        }
    }
    const int nIndex = nLow - 1;
    T00408A30* pBlock = (nIndex >= 0 && nIndex < pSystem->nLargeOverflow) ? pRecords[nIndex].pBlock : 0;
    LeaveCriticalSection(&pSystem->tLock);
    return pBlock;
}

// 0x00409A60
static void sub_00409A60_MoveBlockToFront(T00408A30_2* pPool, T00408A30* pBlock)
{
    T00408A30* pPrev = pBlock->pPrev;
    if (pPrev && pPrev->nUsed >= pPool->nElementsPerBlock)
    {
        pPrev->pNext = pBlock->pNext;
        if (pBlock->pNext)
        {
            pBlock->pNext->pPrev = pBlock->pPrev;
        }
        else
        {
            pPool->pLastBlock = pBlock->pPrev;
        }
        pBlock->pNext = pPool->pFirstBlock;
        pPool->pFirstBlock->pPrev = pBlock;
        pPool->pFirstBlock = pBlock;
        pBlock->pPrev = 0;
    }
}

// 0x00409AB0
void __fastcall sub_00409AB0_PoolFree(D2PoolSystemStrc* pSystem, void** ppMemory, const char* szFile, int nLine)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!*ppMemory)
    {
        return;
    }
    T00408A30* pBlock = sub_004099D0_FindBlock(*ppMemory, pSystem);
    if (pBlock && *ppMemory >= pBlock->pMemory)
    {
        T00408A30_2* pPool = pBlock->pPool;
        const int nIndex = ((char*)*ppMemory - (char*)pBlock->pMemory) / pPool->f_18;
        if (nIndex >= pPool->nElementsPerBlock)
        {
            sub_00409810_FreeLarge(pSystem, *ppMemory, szFile, nLine);
            return;
        }
        EnterCriticalSection(&pPool->tLock);
        if (pBlock->pUsedBits[nIndex >> 5] & gdwBitMasks[nIndex & 31])
        {
            pBlock->pUsedBits[nIndex >> 5] &= gdwInvBitMasks[nIndex & 31];
            pBlock->nUsed--;
            sub_00409A60_MoveBlockToFront(pPool, pBlock);
        }
        LeaveCriticalSection(&pPool->tLock);
        return;
    }
    sub_00409810_FreeLarge(pSystem, *ppMemory, szFile, nLine);
}

void* __fastcall sub_0040A1F0_PoolRealloc(D2PoolSystemStrc* pPool, void* pMemory, int nSize, const char* szFile, int nLine)
{
    D2PoolSystemStrc* pSystem = pPool;
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!pMemory)
    {
        void* pNew = sub_0040A080_PoolAlloc(pPool, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x62D);
        return pNew;
    }
    T00408A30* pBlock = sub_004099D0_FindBlock(pMemory, pSystem);
    if (!pBlock)
    {
        void* pNew = sub_004098B0_ReallocLarge(pSystem, pMemory, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x635);
        return pNew;
    }
    if (pMemory < pBlock->pMemory)
    {
        void* pNew = sub_004098B0_ReallocLarge(pSystem, pMemory, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x63C);
        return pNew;
    }
    T00408A30_2* pBlockPool = pBlock->pPool;
    const int nIndex = ((char*)pMemory - (char*)pBlock->pMemory) / pBlockPool->f_18;
    if (nIndex >= pBlockPool->nElementsPerBlock)
    {
        void* pNew = sub_004098B0_ReallocLarge(pSystem, pMemory, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x648);
        return pNew;
    }
    EnterCriticalSection(&pBlockPool->tLock);
    if (pBlock->pUsedBits[nIndex >> 5] & gdwBitMasks[nIndex & 31])
    {
        const int nElementSize = pBlockPool->f_18;
        if (nSize <= nElementSize)
        {
            LeaveCriticalSection(&pBlockPool->tLock);
            return pMemory;
        }
        LeaveCriticalSection(&pBlockPool->tLock);
        void* pNew = sub_0040A080_PoolAlloc(pPool, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x68B);
        memcpy(pNew, pMemory, nElementSize);
        sub_00409AB0_PoolFree(pPool, &pMemory, szFile, nLine);
        return pNew;
    }
    LeaveCriticalSection(&pBlockPool->tLock);
    D2_ASSERT(0, 0x6A0);
    return 0;
}
