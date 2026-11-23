#include "Fog.h"
#include "D2GameTypes.h"
#include "D2FogTypes.h"
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, size_t nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C
extern "C" unsigned char _BitScanReverse(unsigned long* pIndex, unsigned long nMask);
extern "C" unsigned char _BitScanForward(unsigned long* pIndex, unsigned long nMask);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl realloc(void* pMemory, size_t nSize); // 0x00683BA5
extern "C" void* __cdecl malloc(unsigned int nSize); // 0x00683EFD
void* __fastcall ERRORMANAGER_PoolAllocLarge(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine); // 0x00409770
extern const unsigned int gadwLowBitMasks[]; // 0x006CD490
extern D2PoolDirectoryStrc gtPoolManager; // 0x0074F0E8
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall sub_00409220_FindZeroBit(unsigned int nWord); // 0x00409220

static inline int Log2Ceil(int nValue)
{
    if (nValue < 3)
    {
        return 1;
    }
    unsigned long nBits = nValue - 1;
    if (!_BitScanReverse(&nBits, nBits))
    {
        return 0;
    }
    nBits++;
    return nBits;
}

static __declspec(noinline) int sub_004091B0_GetPoolIndex(int nSize)
{
    if (nSize <= 0x10)
    {
        return 0;
    }
    return Log2Ceil(nSize) - 4;
}

// calling-convention shim (not game code)
__declspec(noinline) int __fastcall sub_00409220_FindZeroBit(unsigned int nWord)
{
    unsigned long nIndex;
    _BitScanForward(&nIndex, ~nWord);
    return nIndex;
}

// 0x00409240
static int sub_00409240_FindFreeSlot(int nCount, const unsigned int* pBits)
{
    int nWords = nCount >> 5;
    int nBase = 0;
    for (;;)
    {
        switch (nWords)
        {
        default:
            if (pBits[7] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[7]) + nBase + 0xE0;
        case 7:
            if (pBits[6] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[6]) + nBase + 0xC0;
        case 6:
            if (pBits[5] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[5]) + nBase + 0xA0;
        case 5:
            if (pBits[4] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[4]) + nBase + 0x80;
        case 4:
            if (pBits[3] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[3]) + nBase + 0x60;
        case 3:
            if (pBits[2] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[2]) + nBase + 0x40;
        case 2:
            if (pBits[1] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[1]) + nBase + 0x20;
        case 1:
            if (pBits[0] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[0]) + nBase;
        case 0:
            break;
        }
        if (nWords <= 8)
        {
            break;
        }
        nWords -= 8;
        pBits += 8;
        nBase += 0x100;
    }
    const int nRest = nCount & 0x1F;
    if (nRest && pBits[nWords] != gadwLowBitMasks[nRest])
    {
        return sub_00409220_FindZeroBit(pBits[nWords]) + nBase + nWords * 32;
    }
    return -1;
}

// 0x00409370
static void __stdcall sub_00409370_InsertBlockRecord(D2MemPoolBlockStrc* pBlock, D2PoolSystemStrc* pSystem)
{
    D2CriticalSectionStrc* pLock = &pSystem->tLock;
    EnterCriticalSection(pLock);
    if (pSystem->nPoolBlocks >= pSystem->nMaxPoolBlocks)
    {
        pSystem->nMaxPoolBlocks += 0x20;
        pSystem->pRecords = (D2PoolRecordStrc*)realloc(pSystem->pRecords, pSystem->nMaxPoolBlocks * sizeof(D2PoolRecordStrc));
        if (!pSystem->pRecords)
        {
// build: symbol ?MAINMENUS_LogPoolError@* 0x00409020
            MAINMENUS_LogPoolError("(1) Pool Blocks overflowed at %d", pSystem->nMaxPoolBlocks);
            D2_ASSERT(0, 0x261);
        }
    }
    pSystem->nCount += pBlock->pPool->nChunkSize + ((pBlock->pPool->nBlocksPerChunk + 0x1F) >> 5) * 4 + sizeof(D2MemPoolBlockStrc);
    D2PoolRecordStrc* pRecords = pSystem->pRecords;
    void* pMemory = pBlock->pMemory;
    int nLow = 0;
    int nHigh = pSystem->nPoolBlocks;
    while (nLow < nHigh)
    {
        const int nMid = nLow + ((nHigh - nLow) >> 1);
        if (pMemory > pRecords[nMid].pMemory)
        {
            nLow = nMid + 1;
        }
        else
        {
            nHigh = nMid;
        }
    }
    if (nLow < pSystem->nPoolBlocks)
    {
        memmove(&pRecords[nLow + 1], &pRecords[nLow], (pSystem->nPoolBlocks - nLow) * sizeof(D2PoolRecordStrc));
    }
    pRecords[nLow].pBlock = pBlock;
    pRecords[nLow].pMemory = pBlock->pMemory;
    pSystem->nPoolBlocks++;
    LeaveCriticalSection(pLock);
}

// 0x004095E0
static D2MemPoolBlockStrc* __stdcall sub_004095E0_NewBlock(D2MemPoolRecStrc* pPool, D2PoolSystemStrc* pSystem)
{
    if (pSystem->nPoolBlocks >= pSystem->nMaxPoolBlocks)
    {
        pSystem->nMaxPoolBlocks += 0x20;
        pSystem->pRecords = (D2PoolRecordStrc*)realloc(pSystem->pRecords, pSystem->nMaxPoolBlocks * sizeof(D2PoolRecordStrc));
        if (!pSystem->pRecords)
        {
            MAINMENUS_LogPoolError("(1) Pool Blocks overflowed at %d", pSystem->nMaxPoolBlocks);
            D2_ASSERT(0, 0x2FF);
        }
    }
    const int nBitsSize = ((pPool->nBlocksPerChunk + 0x1F) >> 5) * 4;
    D2MemPoolBlockStrc* pBlock = (D2MemPoolBlockStrc*)malloc(nBitsSize + sizeof(D2MemPoolBlockStrc));
    void* pMemory = VirtualAlloc(0, pPool->nChunkSize, 0x1000, 4);
    if (pBlock && pMemory)
    {
        memset(&pBlock->nUsed, 0, sizeof(pBlock->nUsed) + sizeof(pBlock->pPrev) + sizeof(pBlock->pNext));
        pBlock->pUsedBits = (unsigned int*)(pBlock + 1);
        memset(pBlock->pUsedBits, 0, nBitsSize);
        pBlock->pMemory = pMemory;
        pBlock->pPool = pPool;
        pPool->nBlocks++;
        sub_00409370_InsertBlockRecord(pBlock, pSystem);
        return pBlock;
    }
    MAINMENUS_LogPoolError("(2) nPoolBlocks = %d/%d  nBlockSize = %d  nUsageTableSize = %d", pSystem->nPoolBlocks, pSystem->nMaxPoolBlocks, pPool->nChunkSize, nBitsSize);
    D2_ASSERT(0, 0x320);
    return 0;
}

// 0x00409700
static int __stdcall sub_00409700_GetFreeSlot(D2MemPoolBlockStrc** ppBlock, D2MemPoolRecStrc* pPool, D2PoolSystemStrc* pSystem)
{
    D2MemPoolBlockStrc* pBlock = pPool->pFirstBlock;
    if (!pBlock)
    {
        pBlock = sub_004095E0_NewBlock(pPool, pSystem);
        if (pBlock)
        {
            pPool->pLastBlock = pBlock;
            pPool->pFirstBlock = pBlock;
        }
        *ppBlock = pBlock;
        return 0;
    }
    if (pBlock->nUsed < pPool->nBlocksPerChunk)
    {
        const int nSlot = sub_00409240_FindFreeSlot(pPool->nBlocksPerChunk, pBlock->pUsedBits);
        if (nSlot >= 0)
        {
            *ppBlock = pBlock;
            return nSlot;
        }
    }
    pBlock = sub_004095E0_NewBlock(pPool, pSystem);
    if (pBlock)
    {
        pBlock->pNext = pPool->pFirstBlock;
        pPool->pFirstBlock->pPrev = pBlock;
        pPool->pFirstBlock = pBlock;
    }
    *ppBlock = pBlock;
    return 0;
}

#include "gen/data/Source/Fog/Unknown_00409240.inc"

// 0x0040A080
void* __fastcall sub_0040A080_PoolAlloc(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!gtPoolManager.bInit)
    {
        sub_00409DD0_InitPoolSystem(0, "Global Pool System", 0x40000, 0x8000);
    }
    if (pSystem->bFreePoolAlloc)
    {
        return ERRORMANAGER_PoolAllocLarge(pSystem, nSize, szFile, nLine);
    }
    const int nIndex = sub_004091B0_GetPoolIndex(nSize);
    if (nIndex >= pSystem->nPools)
    {
        return ERRORMANAGER_PoolAllocLarge(pSystem, nSize, szFile, nLine);
    }
    D2MemPoolRecStrc* pPool = &pSystem->aPools[nIndex];
    EnterCriticalSection(&pPool->tLock);
    D2MemPoolBlockStrc* pBlock;
    const int nSlot = sub_00409700_GetFreeSlot(&pBlock, pPool, pSystem);
    D2_ASSERT(nSlot < pPool->nBlocksPerChunk, 0x4F3);
    if (!pBlock)
    {
        LeaveCriticalSection(&pPool->tLock);
        D2_ASSERT(0, 0x4F8);
    }
    pBlock->nUsed++;
    D2_ASSERT(!(pBlock->pUsedBits[nSlot >> 5] & gdwBitMasks[nSlot & 31]), 0x4FF);
    pBlock->pUsedBits[nSlot >> 5] |= gdwBitMasks[nSlot & 31];
    if (pBlock->nUsed >= pPool->nBlocksPerChunk && pBlock->pNext && pBlock->pNext->nUsed < pPool->nBlocksPerChunk)
    {
        if (!pBlock->pPrev)
        {
            pPool->pFirstBlock = pBlock->pNext;
        }
        else
        {
            pBlock->pPrev->pNext = pBlock->pNext;
        }
        if (pBlock->pNext)
        {
            pBlock->pNext->pPrev = pBlock->pPrev;
        }
        D2_ASSERT(pPool->pLastBlock, 0x50D);
        pPool->pLastBlock->pNext = pBlock;
        pBlock->pPrev = pPool->pLastBlock;
        pPool->pLastBlock = pBlock;
        pBlock->pNext = 0;
    }
    void* pResult = (char*)pBlock->pMemory + pPool->nBlockSize * nSlot;
    LeaveCriticalSection(&pPool->tLock);
    return pResult;
}
