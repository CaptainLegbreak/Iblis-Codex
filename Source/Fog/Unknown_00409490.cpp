#include "Fog.h"
#include "D2GameTypes.h"
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;
struct D2PoolBlockInfoStrc;
struct T00408A30;
struct T00408A30_2;
struct D2PoolRecordStrc;
struct T00408A30_1;


struct D2PoolBlockInfoStrc
{
    char unk0x00[0x1C];
    int nBits;
    int nSize;
};

struct T00408A30
{
    void* pMemory;
    int nUnk0x04;
    int bInUse;
    T00408A30* pPrev;
    T00408A30* pNext;
    D2PoolBlockInfoStrc* pInfo;
};

struct T00408A30_2
{
    D2CriticalSectionStrc tLock;
    char unk0x18[0x0C];
    int nBlocks;
    T00408A30* pFirstBlock;
    T00408A30* pLastBlock;
};

struct D2PoolRecordStrc
{
    int nUnk0x00;
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
    int* apLargeBlocks[1023];
    int nCount;
    char unk0x17AC[0x20];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" void* __cdecl realloc(void* pMemory, size_t nSize); // 0x00683BA5

struct T00408A30_1
{
    int bInit;
    D2CriticalSectionStrc tLock;
    D2PoolSystemStrc aSystems[8];
    int nUnk0xBE7C;
    unsigned int anFreeIndex[8];
    int nFreeCount;
};

extern T00408A30_1 gtPoolManager_0074F0E8; // 0x0074F0E8
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

// 0x00409490
static void __stdcall sub_00409490_RemoveBlockRecord(D2PoolSystemStrc* pSystem, T00408A30* pBlock)
{
    D2PoolRecordStrc* pRecords = pSystem->pUnk0x7A8;
    D2CriticalSectionStrc* pLock = &pSystem->tLock;
    EnterCriticalSection(pLock);
    int nLow = 0;
    int nHigh = pSystem->nLargeOverflow;
    void* pMemory = pBlock->pMemory;
    int nMid;
    while (nLow < nHigh)
    {
        nMid = nLow + ((nHigh - nLow) >> 1);
        if (pMemory > pRecords[nMid].pMemory)
        {
            nLow = nMid + 1;
        }
        else if (pMemory < pRecords[nMid].pMemory)
        {
            nHigh = nMid;
        }
        else
        {
            goto found;
        }
    }
    LeaveCriticalSection(pLock);
    D2_ASSERT(0, 0x2BF);
found:
    if (nMid < pSystem->nLargeOverflow - 1)
    {
        memmove(&pRecords[nMid], &pRecords[nMid + 1], (pSystem->nLargeOverflow - nMid - 1) * sizeof(D2PoolRecordStrc));
    }
    pSystem->nLargeOverflow--;
    D2PoolBlockInfoStrc* pPool = pBlock->pInfo;
    pSystem->nCount = pSystem->nCount - pPool->nSize - (((pPool->nBits + 0x1F) >> 5) * 4 + sizeof(T00408A30));
    if (pSystem->nLargeOverflow + 0x40 < pSystem->nUnk0x7A4)
    {
        pSystem->nUnk0x7A4 -= 0x20;
        pSystem->pUnk0x7A8 = (D2PoolRecordStrc*)realloc(pSystem->pUnk0x7A8, pSystem->nUnk0x7A4 * sizeof(D2PoolRecordStrc));
        if (!pSystem->pUnk0x7A8)
        {
            sub_00409020_LogPoolError("(1) Pool Blocks overflowed at %d", pSystem->nUnk0x7A4);
            D2_ASSERT(0, 0x2B4);
        }
    }
    LeaveCriticalSection(pLock);
}

// 0x00409B80
void __cdecl sub_00409B80_FreeUnusedPoolBlocks(D2PoolSystemStrc* pArg)
{
    D2PoolSystemStrc* pSystem = pArg;
    if (!pArg)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!pSystem->nPools)
    {
        return;
    }
    EnterCriticalSection(&pSystem->tLock);
    for (int i = 0; i < pSystem->nPools; i++)
    {
        T00408A30_2* pPool = &pSystem->aPools[i];
        EnterCriticalSection(&pPool->tLock);
        T00408A30* pBlock = pPool->pFirstBlock;
        while (pBlock)
        {
            T00408A30* pNext = pBlock->pNext;
            if (!pBlock->bInUse)
            {
                if (pBlock->pPrev)
                {
                    pBlock->pPrev->pNext = pNext;
                }
                if (pBlock->pNext)
                {
                    pBlock->pNext->pPrev = pBlock->pPrev;
                }
                if (pPool->pFirstBlock == pBlock)
                {
                    pPool->pFirstBlock = pBlock->pNext;
                }
                if (pPool->pLastBlock == pBlock)
                {
                    pPool->pLastBlock = pBlock->pPrev;
                }
                pPool->nBlocks--;
                sub_00409490_RemoveBlockRecord(pSystem, pBlock);
                VirtualFree(pBlock->pMemory, 0, 0x8000);
                free(pBlock);
            }
            pBlock = pNext;
        }
        LeaveCriticalSection(&pPool->tLock);
    }
    LeaveCriticalSection(&pSystem->tLock);
}
