struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2SMemBlockSigStrc
{
    unsigned short wHeapHigh;
    unsigned short wMagic;
};

struct D2SMemBlockStrc
{
    unsigned short wSize;
    unsigned char nPadding;
    unsigned char nFlags;
    union
    {
        D2SMemBlockSigStrc tSig;
        D2SMemBlockStrc* pNextFree;
    };
};

struct D2SMemLargeHeaderStrc
{
    unsigned int nSize;
    D2SMemBlockStrc* pBlock;
    D2SMemBlockStrc tBlock;
};

struct D2SMemHeapStrc
{
    D2SMemHeapStrc* pNext;
    unsigned int dwId;
    int nLockIndex;
    D2SMemBlockSigStrc tSig;
    int bReportLeak;
    int nBlocks;
    unsigned int nUsedBytes;
    D2SMemBlockStrc* pFirst;
    D2SMemBlockStrc* pEnd;
    unsigned int nFragments;
    unsigned int nPageSize;
    unsigned int nCommitted;
    unsigned int nReserved;
    unsigned int nLargeBytes;
    D2SMemBlockStrc* apFree[9];
    int nLine;
    char szFile[4];
};

enum D2SMemBlockFlags
{
    SMEM_BLOCK_SENTINEL = 0x01,
    SMEM_BLOCK_FREE = 0x02,
    SMEM_BLOCK_LARGE = 0x04,
    SMEM_BLOCK_INDIRECT = 0x08,
    SMEM_BLOCK_PREVFREE = 0x10,
    SMEM_BLOCK_NOREPORT = 0x40,
    SMEM_BLOCK_KEEP = 0x80,
};

struct D2SMemBlockInfoStrc
{
    unsigned int dwSize;
    void* pMemory;
    int bAllocated;
    int bValid;
    unsigned int nDataSize;
    unsigned int nHeaderSize;
    unsigned int unk_18;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
void __cdecl sub_00411CD0_InitHeaps(); // 0x00411CD0

extern "C" const char szSMemFindNextBlock_006CED04[]; // 0x006CED04
extern D2SMemHeapStrc* gapFreeBlocks_007768B8[0x100]; // 0x007768B8
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100]; // 0x00776CC0
extern int gnFlag1_007784C0; // 0x007784C0
extern int gbHeapInitialized_007788D0; // 0x007788D0

static void __stdcall sub_004117A0_SetAndShowError(const char* szFile, int nLine, unsigned int nError); // 0x004117A0
static int sub_00411910_CheckPtr(void* pMemory, int bReport, const char* szFile, int nLine); // 0x00411910
static void sub_00411B90_GetBlockSizes(D2SMemBlockStrc* pBlock, void* pMemory, unsigned int* pDataSize, unsigned int* pHeaderSize); // 0x00411B90

// 0x004117A0
static __declspec(noinline) void __stdcall sub_004117A0_SetAndShowError(const char* szFile, int nLine, unsigned int nError)
{
    sub_0041C340_SetLastError(nError);
    if (gnFlag1_007784C0)
    {
        SErrDisplayError(nError, szFile, nLine, 0, 1, 1);
    }
}

// 0x00411910
static __declspec(noinline) int sub_00411910_CheckPtr(void* pMemory, int bReport, const char* szFile, int nLine)
{
    if (!pMemory)
    {
        if (bReport)
            sub_004117A0_SetAndShowError(szFile, nLine, 0x85100081);
        return 0;
    }
    D2SMemBlockStrc* pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
    if (pBlock->tSig.wMagic != 0x6F6D)
    {
        if (bReport)
            sub_004117A0_SetAndShowError(szFile, nLine, 0x8510007C);
        return 0;
    }
    if (pBlock->nFlags & SMEM_BLOCK_FREE)
    {
        if (bReport)
            sub_004117A0_SetAndShowError(szFile, nLine, 0x8510007A);
        return 0;
    }
    if ((pBlock->nFlags & SMEM_BLOCK_SENTINEL) && *(unsigned short*)((char*)pBlock + pBlock->wSize - pBlock->nPadding - 2) != 0x12B1 && bReport)
        sub_004117A0_SetAndShowError(szFile, nLine, 0x8510007B);
    return 1;
}

// 0x00411B90
static __declspec(noinline) void sub_00411B90_GetBlockSizes(D2SMemBlockStrc* pBlock, void* pMemory, unsigned int* pDataSize, unsigned int* pHeaderSize)
{
    if (pBlock->nFlags & SMEM_BLOCK_LARGE)
    {
        *pDataSize = ((D2SMemLargeHeaderStrc*)pMemory)[-1].nSize;
        *pHeaderSize = pBlock->nPadding + 0x1C;
        return;
    }
    *pHeaderSize = pBlock->nPadding + sizeof(D2SMemBlockStrc);
    if (pBlock->nFlags & SMEM_BLOCK_SENTINEL)
        *pHeaderSize += 2;
    *pDataSize = pBlock->wSize - *pHeaderSize;
}

// build: context SMemGetBlockHeader
static __forceinline D2SMemBlockStrc* SMemGetBlockHeader(void* pMemory)
{
    if (!pMemory)
        return 0;
    D2SMemBlockStrc* pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
    if (pBlock->nFlags & SMEM_BLOCK_INDIRECT)
        pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    return pBlock;
}

// build: context SMemGetBlockData
static __forceinline void* SMemGetBlockData(D2SMemBlockStrc* pBlock)
{
    if (!pBlock)
        return 0;
    void* pData = &pBlock[1];
    if (pBlock->nFlags & SMEM_BLOCK_LARGE)
        pData = *(void**)pData;
    return pData;
}

// 0x004122F0
int __stdcall SMemFindNextBlock(unsigned int hHeap, void* pMemory, void** ppBlock, D2SMemBlockInfoStrc* pInfo)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
        {
            sub_004117A0_SetAndShowError(szSMemFindNextBlock_006CED04, -1, 0x8510007D);
            return 0;
        }
    }

    int nValid = -1;
    nValid &= hHeap ? -1 : 0;
    __assume(hHeap != 0);
    nValid &= ppBlock ? -1 : 0;
    __assume(ppBlock != 0);
    nValid &= pInfo ? -1 : 0;
    __assume(pInfo != 0);
    nValid &= (pInfo->dwSize == sizeof(D2SMemBlockInfoStrc)) ? -1 : 0;
    __assume(pInfo->dwSize == sizeof(D2SMemBlockInfoStrc));
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }

    SMemZero(&pInfo->pMemory, pInfo->dwSize - sizeof(pInfo->dwSize));
    const unsigned int nIndex = (unsigned char)hHeap;
    D2CriticalSectionStrc* pLock = &gaFreeBlockLocks_00776CC0[nIndex];
    EnterCriticalSection(pLock);

    D2SMemBlockStrc* pAfter = SMemGetBlockHeader(pMemory);
    D2SMemBlockStrc* pPrevious = 0;
    D2SMemBlockStrc* pBlock = 0;
    int bFound = 0;
    D2SMemHeapStrc* pHeap = (gapFreeBlocks_007768B8[nIndex]);
    while (pHeap)
    {
        if (!pHeap->pNext)
            break;
        pHeap = pHeap->pNext;
    }

    while (pHeap)
    {
        if (bFound)
            break;
        if (pHeap->dwId == hHeap)
        {
            for (pBlock = pHeap->pFirst; pBlock != pHeap->pEnd;
                 pBlock = (D2SMemBlockStrc*)((char*)pBlock + pBlock->wSize))
            {
                if (pPrevious == pAfter)
                {
                    bFound = 1;
                    break;
                }
                pPrevious = pBlock;
            }
        }
        if (pHeap == (gapFreeBlocks_007768B8[nIndex]))
            break;
        D2SMemHeapStrc* pNext = pHeap;
        pHeap = (gapFreeBlocks_007768B8[nIndex]);
        while (pHeap->pNext != pNext)
            pHeap = pHeap->pNext;
    }

    if (!bFound)
    {
        *ppBlock = 0;
        LeaveCriticalSection(pLock);
        return 0;
    }

    void* pResult = SMemGetBlockData(pBlock);
    *ppBlock = pResult;
    pInfo->pMemory = pResult;
    pInfo->bAllocated = !(pBlock->nFlags & SMEM_BLOCK_FREE);
    pInfo->bValid = sub_00411910_CheckPtr(pResult, 0, 0, 0);
    sub_00411B90_GetBlockSizes(pBlock, pResult, &pInfo->nDataSize, &pInfo->nHeaderSize);
    LeaveCriticalSection(pLock);
    return 1;
}

#include "gen/data/Source/Storm/004122F0_SMemFindNextBlock.inc"
