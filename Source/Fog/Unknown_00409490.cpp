#include "Fog.h"
#include "D2GameTypes.h"
#include "D2FogTypes.h"
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" void* __cdecl realloc(void* pMemory, size_t nSize); // 0x00683BA5

extern D2PoolDirectoryStrc gtPoolManager_0074F0E8; // 0x0074F0E8
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

// 0x00409490
static void __stdcall sub_00409490_RemoveBlockRecord(D2PoolSystemStrc* pSystem, D2MemPoolBlockStrc* pBlock)
{
    D2PoolRecordStrc* pRecords = pSystem->pRecords;
    D2CriticalSectionStrc* pLock = &pSystem->tLock;
    EnterCriticalSection(pLock);
    int nLow = 0;
    int nHigh = pSystem->nPoolBlocks;
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
    if (nMid < pSystem->nPoolBlocks - 1)
    {
        memmove(&pRecords[nMid], &pRecords[nMid + 1], (pSystem->nPoolBlocks - nMid - 1) * sizeof(D2PoolRecordStrc));
    }
    pSystem->nPoolBlocks--;
    D2MemPoolRecStrc* pPool = pBlock->pPool;
    pSystem->nCount = pSystem->nCount - pPool->nChunkSize - (((pPool->nBlocksPerChunk + 0x1F) >> 5) * 4 + sizeof(D2MemPoolBlockStrc));
    if (pSystem->nPoolBlocks + 0x40 < pSystem->nMaxPoolBlocks)
    {
        pSystem->nMaxPoolBlocks -= 0x20;
        pSystem->pRecords = (D2PoolRecordStrc*)realloc(pSystem->pRecords, pSystem->nMaxPoolBlocks * sizeof(D2PoolRecordStrc));
        if (!pSystem->pRecords)
        {
            sub_00409020_LogPoolError("(1) Pool Blocks overflowed at %d", pSystem->nMaxPoolBlocks);
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
        D2MemPoolRecStrc* pPool = &pSystem->aPools[i];
        EnterCriticalSection(&pPool->tLock);
        D2MemPoolBlockStrc* pBlock = pPool->pFirstBlock;
        while (pBlock)
        {
            D2MemPoolBlockStrc* pNext = pBlock->pNext;
            if (!pBlock->nUsed)
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
