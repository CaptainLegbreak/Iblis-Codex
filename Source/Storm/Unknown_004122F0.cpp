#include "Storm.h"
#include "D2GameTypes.h"
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

struct D2CriticalSectionStrc;
struct D2SMemBlockSigStrc;
struct D2SMemBlockStrc;
struct D2SMemLargeHeaderStrc;
struct D2SMemHeapStrc;
struct D2SMemBlockInfoStrc;
struct D2SMemHeapInfoStrc;


struct D2SMemBlockSigStrc
{
    unsigned short wHeapHigh;
    union
    {
        unsigned short wMagic;
        unsigned short f_2;
    };
};

struct D2SMemBlockStrc
{
    unsigned short wSize;
    union
    {
        unsigned char nPadding;
        unsigned char f_2;
    };
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
    unsigned int f_28;
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

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
extern "C" const char szSMemFindNextHeap_006CED18[]; // 0x006CED18
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, unsigned long nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode); // 0x006CC2E0
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0
void __cdecl sub_00411A20_InitPageSize(); // 0x00411A20
void __fastcall sub_00411A80_ReleaseBlock(D2SMemHeapStrc** ppLink); // 0x00411A80
void __cdecl sub_00412000_ReleaseFreeBlocks(); // 0x00412000
extern "C" const char gszMemNeverReleased_006CECCC[]; // 0x006CECCC
extern "C" const char szSMemFree_006CED2C[]; // 0x006CED2C
extern "C" const char szSMemGetHeapByCaller_006CED38[]; // 0x006CED38
extern "C" const char szSMemGetHeapByPtr_006CED50[]; // 0x006CED50
extern "C" const char szSMemGetSize_006CED64[]; // 0x006CED64
extern "C" const char szSMemHeapCreate_006CED74[]; // 0x006CED74
extern "C" const char szSMemHeapFree_006CED9C[]; // 0x006CED9C
extern "C" const char szSMemHeapSize_006CEDAC[]; // 0x006CEDAC
extern "C" const char szSMemHeapAlloc_006CEDBC[]; // 0x006CEDBC
extern "C" const char szSMemAlloc_006CEDCC[]; // 0x006CEDCC
extern "C" const char szSMemHeapReAlloc_006CEE08[]; // 0x006CEE08
extern "C" const char szSMemReAlloc_006CEE1C[]; // 0x006CEE1C
extern int gbCallerFirst_00708340; // 0x00708340
extern unsigned int gnHeapId_00708344; // 0x00708344
extern unsigned int gdwCallerId_007768A8; // 0x007768A8
extern unsigned int gdwCallerWord_007768AC; // 0x007768AC
extern int gnCallerLine_007768B0; // 0x007768B0
extern const char* gszCallerFile_007768B4; // 0x007768B4
extern unsigned int gnPageSize_00776CB8; // 0x00776CB8
extern int gnFlag2_00776CBC; // 0x00776CBC
extern int gnFlag0_007784C4; // 0x007784C4
extern int gabFreeBlockDirty_007784C8[0x100]; // 0x007784C8
extern D2SMemHeapStrc* gpFreeBlockSweep_007788C8; // 0x007788C8
extern int gnFlag3_007788CC; // 0x007788CC
extern int gnFlag_00779098; // 0x00779098
static void sub_00411AA0_FreeBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock);

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

#include "gen/data/Source/Storm/Unknown_004122F0.inc"

// 0x004124B0
int __stdcall SMemFindNextHeap(unsigned int hPrev, unsigned int* phNext, D2SMemHeapInfoStrc* pInfo)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
        {
            sub_004117A0_SetAndShowError(szSMemFindNextHeap_006CED18, -1, 0x8510007D);
            return 0;
        }
    }
    VALIDATEBEGIN;
    VALIDATE(phNext);
    __assume(phNext != 0);
    VALIDATE(pInfo);
    __assume(pInfo != 0);
    VALIDATE(pInfo->dwSize == 0x128);
    __assume(pInfo->dwSize == 0x128);
    VALIDATEEND;

    SMemZero(&pInfo->hHeap, pInfo->dwSize - 4);

    unsigned int i = 0;
    if (hPrev)
        i = (unsigned char)hPrev;
    unsigned int dwLastId = 0;
    D2SMemHeapStrc* pHeap = 0;
    for (; i < 0x100; ++i)
    {
        EnterCriticalSection(&gaFreeBlockLocks_00776CC0[i]);
        for (pHeap = gapFreeBlocks_007768B8[i]; pHeap; pHeap = pHeap->pNext)
        {
            if (pHeap->bReportLeak)
            {
                if (dwLastId == hPrev && pHeap->dwId != hPrev)
                    break;
                dwLastId = pHeap->dwId;
            }
        }
        if (pHeap)
            break;
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[i]);
    }

    if (!pHeap)
    {
        *phNext = 0;
        return 0;
    }

    *phNext = pHeap->dwId;
    pInfo->hHeap = pHeap->dwId;
    pInfo->nLine = pHeap->nLine;
    pInfo->dwUnk11C = 0x7FFFFFFF;
    SStrCopy(pInfo->szName, pHeap->szFile, 0x104);
    for (; pHeap; pHeap = pHeap->pNext)
    {
        if (pHeap->dwId == *phNext)
        {
            pInfo->dwSizeA += pHeap->nCommitted + pHeap->nLargeBytes;
            pInfo->dwSizeB += pHeap->nReserved + pHeap->nLargeBytes;
            pInfo->nBlocks += pHeap->nBlocks;
            pInfo->dwSizeC += pHeap->nUsedBytes;
        }
    }
    LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[i]);
    return 1;
}

static __declspec(noinline) __declspec(noreturn) void sub_00411620_FatalError(unsigned int nError, const char* szFile, int nLine)
{
    SErrDisplayError(nError, szFile, nLine, 0, 0, 1);
    ExitProcess(1);
}

// 0x00411670
static __declspec(noinline) unsigned int sub_00411670_GetCallerId(const char* szFile, int nLine)
{
    unsigned int dwWord = szFile ? *(const unsigned int*)szFile : 0;
    int bHit = 0;
    if (gbCallerFirst_00708340 && szFile == gszCallerFile_007768B4 && nLine == gnCallerLine_007768B0)
    {
        if (dwWord == gdwCallerWord_007768AC)
            bHit = 1;
        else
            gbCallerFirst_00708340 = 0;
    }
    if (!bHit)
    {
        unsigned int dwId = szFile ? SStrHash(szFile, 1, nLine) : 0;
        dwId &= 0x7FFFFFFF;
        if (!dwId)
            dwId = 1;
        gdwCallerWord_007768AC = dwWord;
        gszCallerFile_007768B4 = szFile;
        gnCallerLine_007768B0 = nLine;
        gdwCallerId_007768A8 = dwId;
    }
    return gdwCallerId_007768A8;
}

static __declspec(noinline) D2SMemHeapStrc* __stdcall sub_00411710_LockHeap(int* pLockIndex, D2SMemBlockStrc* pBlock)
{
    D2SMemHeapStrc* pHeap = (D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16);
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[pHeap->nLockIndex]);
    *pLockIndex = pHeap->nLockIndex;
    return pHeap;
}

static __declspec(noinline) void sub_004117D0_ReleaseHeapLock(int* pLockIndex)
{
    if (*pLockIndex != -1)
    {
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[*pLockIndex]);
        *pLockIndex = -1;
    }
}

static __declspec(noinline) D2SMemHeapStrc* __stdcall sub_004117F0_CreateHeap(int nLine, unsigned int dwId, int nLockIndex, unsigned int nPageSize, unsigned int nCommit, unsigned int nReserve, const char* szFile)
{
    unsigned int nNameSize;
    unsigned int nHeaderSize;
    D2SMemBlockStrc tHeader;
    D2SMemHeapStrc* pHeap = (D2SMemHeapStrc*)VirtualAlloc(0, nReserve, 0x2000, 1);
    if (!pHeap)
        sub_00411620_FatalError(8, szFile, nLine);
    if (!VirtualAlloc(pHeap, nCommit, 0x1000, 4))
        sub_00411620_FatalError(8, szFile, nLine);
    nNameSize = (szFile ? SStrLen(szFile) : 0) + 1;
    nHeaderSize = nNameSize + 0x63;
    if (nHeaderSize & 3)
        nHeaderSize += 4 - (nHeaderSize & 3);
    pHeap->dwId = dwId;
    pHeap->pNext = gapFreeBlocks_007768B8[nLockIndex];

    pHeap->pFirst = (D2SMemBlockStrc*)((char*)pHeap + nHeaderSize);
    pHeap->pEnd = pHeap->pFirst;
    pHeap->f_28 = nPageSize;
    pHeap->nCommitted = nCommit;
    pHeap->nLockIndex = nLockIndex;
    pHeap->bReportLeak = 1;
    pHeap->nFragments = 0;
    pHeap->nReserved = nReserve;
    pHeap->nLine = nLine;
    pHeap->apFree[0] = 0;
    pHeap->apFree[1] = 0;
    pHeap->apFree[2] = 0;
    pHeap->apFree[3] = 0;
    pHeap->apFree[4] = 0;
    pHeap->apFree[5] = 0;
    pHeap->apFree[6] = 0;
    pHeap->apFree[7] = 0;
    pHeap->apFree[8] = 0;
    if (szFile)
        SMemCopy(pHeap->szFile, szFile, nNameSize);
    else
        pHeap->szFile[0] = 0;
    tHeader.tSig.wHeapHigh = (unsigned short)((unsigned int)pHeap >> 16);
    tHeader.tSig.f_2 = 0x6F6D;
    pHeap->tSig = tHeader.tSig;
    gapFreeBlocks_007768B8[nLockIndex] = pHeap;
    return pHeap;
}

static unsigned int sub_A21_FreeListIndex(unsigned int nSize)
{
    unsigned int nIndex = nSize >> 5;
    if (nIndex >= 8)
        nIndex = 8;
    return nIndex;
}

static __declspec(noinline) void __stdcall sub_004119B0_CalcBlockSize(unsigned int* pTotal, unsigned int* pPadding, int* pbLarge, int* pbSentinel, unsigned int nSize)
{
    *pbLarge = gnFlag2_00776CBC || nSize > 0xFE87;
    *pbSentinel = gnFlag0_007784C4 && !*pbLarge;
    if (*pbLarge)
        nSize = 4;
    nSize += (*pbSentinel ? 2 : 0) + sizeof(D2SMemBlockStrc);
    *pTotal = nSize + ((0 - nSize) & 7);
    *pPadding = *pTotal - nSize;
}

static __declspec(noinline) void __stdcall sub_00411A50_InitBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock, unsigned int nSize, unsigned int nPadding, unsigned char nFlags)
{
    pBlock->wSize = (unsigned short)nSize;
    pBlock->f_2 = (unsigned char)nPadding;
    pBlock->nFlags = nFlags;
    pBlock->tSig = pHeap->tSig;
    if (nFlags & SMEM_BLOCK_SENTINEL)
        *(unsigned short*)((char*)pBlock + nSize - nPadding - 2) = 0x12B1;
}

static __declspec(noinline) void sub_00411AA0_FreeBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock)
{
    unsigned int nSize;
    if (pBlock->nFlags & SMEM_BLOCK_LARGE)
    {
        D2SMemLargeHeaderStrc* pLarge = *(D2SMemLargeHeaderStrc**)&pBlock[1];
        if (pLarge)
        {
            nSize = pLarge[-1].nSize;
            pHeap->nLargeBytes -= nSize;
            VirtualFree((void*)(((unsigned int)pLarge - sizeof(D2SMemLargeHeaderStrc)) & ~(gnPageSize_00776CB8 - 1)), 0, 0x8000);
        }
        else
            nSize = 0;
    }
    else
    {
        nSize = pBlock->wSize - pBlock->f_2 - sizeof(D2SMemBlockStrc);
        if (pBlock->nFlags & SMEM_BLOCK_SENTINEL)
            nSize -= 2;
    }
    pHeap->nUsedBytes -= nSize;
    pHeap->nBlocks -= 1;
    pBlock->nFlags = (pBlock->nFlags & SMEM_BLOCK_PREVFREE) | SMEM_BLOCK_FREE;
    D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pBlock + pBlock->wSize);
    pBlock->f_2 = 0;
    if (pHeap->pEnd == pNext)
    {
        pBlock->pNextFree = 0;
        pHeap->pEnd = pBlock;
    }
    else
    {
        pNext->nFlags |= SMEM_BLOCK_PREVFREE;
        unsigned int nIndex = sub_A21_FreeListIndex(pBlock->wSize);
        pBlock->pNextFree = pHeap->apFree[nIndex];
        pHeap->apFree[nIndex] = pBlock;
        if ((pBlock->nFlags & SMEM_BLOCK_PREVFREE) || (pNext->nFlags & SMEM_BLOCK_FREE))
            pHeap->nFragments += 1;
    }
    if (!pHeap->nBlocks)
    {
        pHeap->pEnd = pHeap->pFirst;
        D2SMemBlockStrc** ppFree = pHeap->apFree;
        ppFree[0] = 0;
        ppFree[1] = 0;
        ppFree[2] = 0;
        ppFree[3] = 0;
        ppFree[4] = 0;
        ppFree[5] = 0;
        ppFree[6] = 0;
        ppFree[7] = 0;
        ppFree[8] = 0;
        pHeap->nFragments = 0;
        if (pHeap->dwId < 0x80000000)
        {
            gabFreeBlockDirty_007784C8[pHeap->nLockIndex] = 1;
            gpFreeBlockSweep_007788C8 = pHeap;
        }
    }
}

static __declspec(noinline) int sub_00411BD0_CommitHeap(D2SMemHeapStrc* pHeap, unsigned int nNeeded)
{
    unsigned int nCommit = nNeeded - pHeap->nCommitted;
    if (nCommit & (pHeap->f_28 - 1))
        nCommit += pHeap->f_28 - (nCommit & (pHeap->f_28 - 1));
    if (pHeap->nCommitted + nCommit > pHeap->nReserved)
        nCommit = pHeap->nReserved - pHeap->nCommitted;
    if (!VirtualAlloc((char*)pHeap + pHeap->nCommitted, nCommit, 0x1000, 4))
        return 0;
    pHeap->nCommitted += nCommit;
    return 1;
}

static __declspec(noinline) void __stdcall sub_00411C20_FreeBlockEx(void* pMemory, D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock)
{
    if (gnFlag3_007788CC && !(pBlock->nFlags & SMEM_BLOCK_LARGE))
        SMemFill(pMemory, pBlock->wSize - (pBlock->nFlags & SMEM_BLOCK_SENTINEL) * 2 - pBlock->f_2 - sizeof(D2SMemBlockStrc), 0xDD);
    sub_00411AA0_FreeBlock(pHeap, pBlock);
}

static __declspec(noinline) void __stdcall sub_00411C70_SplitBlock(unsigned int* pPadding, D2SMemHeapStrc* pHeap, unsigned int* pSize, D2SMemBlockStrc* pBlock)
{
    D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pBlock + pBlock->wSize);
    unsigned int nRemain = pBlock->wSize - *pSize;
    if (pNext == pHeap->pEnd)
    {
        pHeap->pEnd = (D2SMemBlockStrc*)((char*)pBlock + *pSize);
        return;
    }
    if (nRemain >= 0x10)
    {
        D2SMemBlockStrc* pFree = (D2SMemBlockStrc*)((char*)pBlock + *pSize);
        pFree->wSize = (unsigned short)nRemain;
        pFree->f_2 = 0;
        pFree->nFlags = SMEM_BLOCK_FREE;
        unsigned int nIndex = sub_A21_FreeListIndex(pFree->wSize);
        pFree->pNextFree = pHeap->apFree[nIndex];
        pHeap->apFree[nIndex] = pFree;
        return;
    }
    pNext->nFlags &= ~SMEM_BLOCK_PREVFREE;
    *pSize += nRemain;
    *pPadding += nRemain;
}

static __declspec(noinline) void sub_00411DC0_RebuildFreeLists(D2SMemHeapStrc* pHeap)
{
    D2SMemBlockStrc** apTail[9];
    apTail[0] = &pHeap->apFree[0];
    apTail[1] = &pHeap->apFree[1];
    apTail[2] = &pHeap->apFree[2];
    apTail[3] = &pHeap->apFree[3];
    apTail[4] = &pHeap->apFree[4];
    apTail[5] = &pHeap->apFree[5];
    apTail[6] = &pHeap->apFree[6];
    apTail[7] = &pHeap->apFree[7];
    apTail[8] = &pHeap->apFree[8];
    D2SMemBlockStrc* pPrev = 0;
    for (D2SMemBlockStrc* pBlock = pHeap->pFirst; pBlock != pHeap->pEnd; pBlock = (D2SMemBlockStrc*)((char*)pBlock + pBlock->wSize))
    {
        if (!(pBlock->nFlags & SMEM_BLOCK_FREE))
            continue;
        pBlock->pNextFree = 0;
        if (pPrev)
        {
            unsigned short wPrevSize = pPrev->wSize;
            unsigned int nPrevSize = wPrevSize;
            if (pBlock == (D2SMemBlockStrc*)((char*)pPrev + nPrevSize))
            {
                unsigned short wSize = pBlock->wSize;
                unsigned int nMerged = wSize + nPrevSize;
                if (nMerged <= 0xFFFF)
                {
                    pPrev->wSize = wSize + pPrev->wSize;
                    continue;
                }
            }
            unsigned int nIndex = sub_A21_FreeListIndex(nPrevSize);
            *apTail[nIndex] = pPrev;
            apTail[nIndex] = &pPrev->pNextFree;
        }
        pPrev = pBlock;
    }
    if (pPrev)
    {
        unsigned int nIndex = sub_A21_FreeListIndex(pPrev->wSize);
        *apTail[nIndex] = pPrev;
        apTail[nIndex] = &pPrev->pNextFree;
    }
    *apTail[0] = 0;
    *apTail[1] = 0;
    *apTail[2] = 0;
    *apTail[3] = 0;
    *apTail[4] = 0;
    *apTail[5] = 0;
    *apTail[6] = 0;
    *apTail[7] = 0;
    *apTail[8] = 0;
    pHeap->nFragments = 0;
}

D2SMemHeapStrc** __fastcall sub_00411F00_ProcessUsedBlock(D2SMemHeapStrc** ppLink)
{
    D2SMemHeapStrc* pHeap = *ppLink;
    int bKeep = 0;
    D2SMemBlockStrc* pBlock = pHeap->pFirst;
    while (pBlock < pHeap->pEnd)
    {
        D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pBlock + pBlock->wSize);
        if (pBlock->nFlags & (SMEM_BLOCK_KEEP | SMEM_BLOCK_FREE))
        {
            bKeep |= pBlock->nFlags & SMEM_BLOCK_KEEP;
            pBlock = pNext;
            continue;
        }
        if (!(pBlock->nFlags & SMEM_BLOCK_NOREPORT))
        {
            if (!gnFlag_00779098)
            {
                sub_004117A0_SetAndShowError(pHeap->szFile, pHeap->nLine, 0x8510007E);
            }
            else
            {
                char szBuffer[200];
                wsprintfA(szBuffer, gszMemNeverReleased_006CECCC, pHeap->szFile, pHeap->nLine);
                OutputDebugStringA(szBuffer);
            }
        }
        sub_00411AA0_FreeBlock(pHeap, pBlock);
        pBlock = pNext;
    }
    if (!bKeep)
    {
        sub_00411A80_ReleaseBlock(ppLink);
        return ppLink;
    }
    return &pHeap->pNext;
}

static __declspec(noinline) int __stdcall sub_00412080_GrowBlock(D2SMemBlockStrc* pBlock, unsigned int nOldSize, unsigned int nNewSize, D2SMemHeapStrc* pHeap)
{
    int bSentinel;
    int bLarge;
    unsigned int nTotal;
    unsigned int nPadding;
    sub_004119B0_CalcBlockSize(&nTotal, &nPadding, &bLarge, &bSentinel, nNewSize);
    if (nTotal > 0xFFFF || bLarge)
        return 0;
    if (nTotal <= pBlock->wSize)
    {
        unsigned int nExtra = pBlock->wSize - nTotal;
        nTotal += nExtra;
        nPadding += nExtra;
    }
    else
    {
        unsigned int nNeeded = nTotal - pBlock->wSize;
        D2SMemBlockStrc* pNewEnd = (D2SMemBlockStrc*)((char*)pBlock + nTotal);
        unsigned int nFound = 0;
        D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pBlock + pBlock->wSize);
        while (nFound < nNeeded)
        {
            if (pNext == pHeap->pEnd)
                break;
            if (!(pNext->nFlags & SMEM_BLOCK_FREE))
                return 0;
            nFound += pNext->wSize;
            pNext = (D2SMemBlockStrc*)((char*)pNext + pNext->wSize);
        }
        unsigned int nNewBlockSize = pBlock->wSize + (nFound > nNeeded ? nFound : nNeeded);
        if (nNewBlockSize > 0xFFFF)
            return 0;
        if (nFound < nNeeded)
        {
            unsigned int nEnd = (char*)pNewEnd - (char*)pHeap;
            if (nEnd > pHeap->nCommitted)
            {
                if (nEnd > pHeap->nReserved)
                    return 0;
                if (!sub_00411BD0_CommitHeap(pHeap, nEnd))
                    return 0;
            }
            pHeap->pEnd = pNewEnd;
        }
        pBlock->wSize = (unsigned short)nNewBlockSize;
        sub_00411C70_SplitBlock(&nPadding, pHeap, &nTotal, pBlock);
        pBlock->wSize = (unsigned short)nTotal;
        if (pNewEnd != pHeap->pEnd)
        {
            pNewEnd->nFlags &= ~SMEM_BLOCK_PREVFREE;
            if ((pNewEnd->nFlags & SMEM_BLOCK_FREE) && pHeap->nFragments)
                pHeap->nFragments -= 1;
        }
        sub_00411DC0_RebuildFreeLists(pHeap);
    }
    sub_00411A50_InitBlock(pHeap, pBlock, nTotal, nPadding, (pBlock->nFlags & ~SMEM_BLOCK_SENTINEL) | (bSentinel != 0));
    pHeap->nUsedBytes += nNewSize - nOldSize;
    return 1;
}

static __declspec(noinline) void __stdcall sub_004121D0_ShrinkBlock(D2SMemBlockStrc* pBlock, unsigned int nOldSize, unsigned int nNewSize, D2SMemHeapStrc* pHeap)
{
    int bLarge;
    int bSentinel;
    unsigned int nTotal;
    unsigned int nPadding;
    sub_004119B0_CalcBlockSize(&nTotal, &nPadding, &bLarge, &bSentinel, nNewSize);
    unsigned char nFlags = (pBlock->nFlags & ~SMEM_BLOCK_SENTINEL) | (bSentinel != 0);
    sub_00411C70_SplitBlock(&nPadding, pHeap, &nTotal, pBlock);
    sub_00411A50_InitBlock(pHeap, pBlock, nTotal, nPadding, nFlags);
    pHeap->nUsedBytes += nNewSize - nOldSize;
}

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
        {
            sub_004117A0_SetAndShowError(szSMemFree_006CED2C, -1, 0x8510007D);
            return 0;
        }
    }
    if (!sub_00411910_CheckPtr(pMemory, 1, szFile, nLine))
        return 0;
    D2SMemBlockStrc* pBlock;
    if (!pMemory)
        pBlock = 0;
    else
    {
        pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
        if (pBlock->nFlags & SMEM_BLOCK_INDIRECT)
            pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    }
    D2SMemHeapStrc* pHeap = (D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16);
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[pHeap->nLockIndex]);
    int nLockIndex = pHeap->nLockIndex;
    sub_00411C20_FreeBlockEx(pMemory, pHeap, pBlock);
    if (nLockIndex != -1)
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    return 1;
}

unsigned int __stdcall SMemGetHeapByCaller(const char* szFile, int nLine)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
        {
            sub_004117A0_SetAndShowError(szSMemGetHeapByCaller_006CED38, -1, 0x8510007D);
            return 0;
        }
    }
    return sub_00411670_GetCallerId(szFile, nLine);
}

unsigned int __stdcall SMemGetHeapByPtr(void* pMemory)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
        {
            sub_004117A0_SetAndShowError(szSMemGetHeapByPtr_006CED50, -1, 0x8510007D);
            return 0;
        }
    }
    if (!sub_00411910_CheckPtr(pMemory, 0, 0, 0))
        return 0;
    D2SMemBlockStrc* pBlock;
    if (!pMemory)
        pBlock = 0;
    else
    {
        pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
        if (pBlock->nFlags & SMEM_BLOCK_INDIRECT)
            pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    }
    return ((D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16))->dwId;
}

unsigned int __stdcall SMemGetSize(void* pMemory, const char* szFile, int nLine)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
        {
            sub_004117A0_SetAndShowError(szSMemGetSize_006CED64, -1, 0x8510007D);
            return -1;
        }
    }
    if (!sub_00411910_CheckPtr(pMemory, 1, szFile, nLine))
        return -1;
    D2SMemBlockStrc* pBlock;
    if (!pMemory)
        pBlock = 0;
    else
    {
        pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
        if (pBlock->nFlags & SMEM_BLOCK_INDIRECT)
            pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    }
    unsigned int nHeaderSize;
    unsigned int nDataSize;
    sub_00411B90_GetBlockSizes(pBlock, pMemory, &nDataSize, &nHeaderSize);
    return nDataSize;
}

static __forceinline int sub_A21_HeapIdInUse(unsigned int dwId)
{
    int nLockIndex = (unsigned char)dwId;
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    for (D2SMemHeapStrc* pHeap = gapFreeBlocks_007768B8[nLockIndex]; pHeap; pHeap = pHeap->pNext)
    {
        if (pHeap->dwId == dwId)
        {
            if (nLockIndex != -1)
                LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
            return 1;
        }
    }
    LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    return 0;
}

unsigned int __stdcall SMemHeapCreate(unsigned int dwOptions, unsigned int nInitialSize, unsigned int nMaximumSize)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
        {
            sub_004117A0_SetAndShowError(szSMemHeapCreate_006CED74, -1, 0x8510007D);
            return 0;
        }
    }
    if (dwOptions)
    {
        sub_004117A0_SetAndShowError(szSMemHeapCreate_006CED74, -1, 0x57);
        return 0;
    }
    if (nInitialSize & 0xFFF)
        nInitialSize += 0x1000 - (nInitialSize & 0xFFF);
    if (nInitialSize <= 0x1000)
        nInitialSize = 0x1000;
    do
    {
        if (!++gnHeapId_00708344)
            gnHeapId_00708344 = 0x80000000;
    } while (sub_A21_HeapIdInUse(gnHeapId_00708344));
    int nLockIndex = (unsigned char)gnHeapId_00708344;
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    sub_004117F0_CreateHeap(0, gnHeapId_00708344, nLockIndex, 0x1000, nInitialSize, 0x10000, 0);
    LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    if (!gnHeapId_00708344)
        sub_004117A0_SetAndShowError(szSMemHeapCreate_006CED74, -1, 8);
    return gnHeapId_00708344;
}

int __stdcall SMemHeapFree(unsigned int hHeap, unsigned int dwFlags, void* pMemory)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
        {
            sub_004117A0_SetAndShowError(szSMemHeapFree_006CED9C, -1, 0x8510007D);
            return 0;
        }
    }
    if (!sub_00411910_CheckPtr(pMemory, 1, 0, 0))
        return 0;
    D2SMemBlockStrc* pBlock;
    if (!pMemory)
        pBlock = 0;
    else
    {
        pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
        if (pBlock->nFlags & SMEM_BLOCK_INDIRECT)
            pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    }
    if (((D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16))->dwId != hHeap)
        return 0;
    int nLockIndex;
    D2SMemHeapStrc* pHeap = sub_00411710_LockHeap(&nLockIndex, pBlock);
    sub_00411C20_FreeBlockEx(pMemory, pHeap, pBlock);
    if (nLockIndex != -1)
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    return pHeap != 0;
}

unsigned int __stdcall SMemHeapSize(unsigned int hHeap, unsigned int dwFlags, void* pMemory)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
        {
            sub_004117A0_SetAndShowError(szSMemHeapSize_006CEDAC, -1, 0x8510007D);
            return -1;
        }
    }
    if (!sub_00411910_CheckPtr(pMemory, 1, 0, 0))
        return -1;
    D2SMemBlockStrc* pBlock;
    if (!pMemory)
        pBlock = 0;
    else
    {
        pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
        if (pBlock->nFlags & SMEM_BLOCK_INDIRECT)
            pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    }
    if (((D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16))->dwId != hHeap)
        return -1;
    unsigned int nHeaderSize;
    unsigned int nDataSize;
    sub_00411B90_GetBlockSizes(pBlock, pMemory, &nDataSize, &nHeaderSize);
    return nDataSize;
}

static __declspec(noinline) void* __stdcall sub_00412BA0_AllocBlock(unsigned int nSize, unsigned char nUserFlags, D2SMemHeapStrc* pHeap)
{
    int bSentinel;
    int bLarge;
    unsigned int nPadding;
    unsigned int nTotal;
    sub_004119B0_CalcBlockSize(&nTotal, &nPadding, &bLarge, &bSentinel, nSize);
    unsigned int nIndex = sub_A21_FreeListIndex(nTotal);
    if (pHeap->nFragments >= 4 && !pHeap->apFree[nIndex])
        sub_00411DC0_RebuildFreeLists(pHeap);
    D2SMemBlockStrc** ppBest = 0;
    D2SMemBlockStrc** ppLink = &pHeap->apFree[nIndex];
    unsigned int nBestDiff = 0x7FFFFFFF;
    unsigned int i = nIndex + 1;
    while (!*ppLink)
    {
        if (i >= 9)
            break;
        ++ppLink;
        ++i;
    }
    D2SMemBlockStrc* pFree = *ppLink;
    if (pFree)
    {
        unsigned int nThreshold = 0x10;
        do
        {
            unsigned int nDiff = pFree->wSize - nTotal;
            if (nDiff < nBestDiff)
            {
                nBestDiff = nDiff;
                ppBest = ppLink;
                if (nDiff < nThreshold)
                    break;
                nThreshold += 4;
            }
            ppLink = &pFree->pNextFree;
            pFree = *ppLink;
        } while (pFree);
    }
    int bPrevFree = 0;
    D2SMemBlockStrc* pResult;
    if (ppBest)
    {
        pResult = *ppBest;
        bPrevFree = (pResult->nFlags & SMEM_BLOCK_PREVFREE) != 0;
        *ppBest = pResult->pNextFree;
        D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pResult + pResult->wSize);
        if (pHeap->nFragments && (bPrevFree || (pNext != pHeap->pEnd && (pNext->nFlags & SMEM_BLOCK_FREE))))
            pHeap->nFragments -= 1;
        sub_00411C70_SplitBlock(&nPadding, pHeap, &nTotal, pResult);
    }
    else
    {
        D2SMemBlockStrc** ppEnd = &pHeap->pEnd;
        unsigned int nEnd = (char*)pHeap->pEnd - (char*)pHeap + nTotal;
        if (nEnd > pHeap->nReserved)
        {
            unsigned int nReserve = pHeap->nReserved < 0x10000000 ? pHeap->nReserved * 2 : pHeap->nReserved;
            D2SMemHeapStrc* pNewHeap = sub_004117F0_CreateHeap(pHeap->nLine, pHeap->dwId, pHeap->nLockIndex, nReserve >> 3, nReserve >> 3, nReserve, pHeap->szFile);
            if (!pNewHeap)
                return 0;
            pHeap->bReportLeak = 0;
            pHeap = pNewHeap;
            ppEnd = &pHeap->pEnd;
            nEnd = (char*)pHeap->pEnd - (char*)pHeap + nTotal;
        }
        if (nEnd > pHeap->nCommitted && !sub_00411BD0_CommitHeap(pHeap, nEnd))
            return 0;
        pResult = *ppEnd;
        *ppEnd = (D2SMemBlockStrc*)((char*)pResult + nTotal);
    }
    pHeap->nUsedBytes += nSize;
    pHeap->nBlocks += 1;
    unsigned char nFlags = (bPrevFree ? SMEM_BLOCK_PREVFREE : 0) | (bLarge ? SMEM_BLOCK_LARGE : 0) | (bSentinel != 0) | nUserFlags;
    sub_00411A50_InitBlock(pHeap, pResult, nTotal, nPadding, nFlags);
    if (bLarge)
    {
        unsigned int nPageSize = gnPageSize_00776CB8;
        *(D2SMemLargeHeaderStrc**)&pResult[1] = 0;
        if (!nPageSize)
        {
            sub_00411A20_InitPageSize();
            nPageSize = gnPageSize_00776CB8;
        }
        unsigned int nAlloc = nSize + sizeof(D2SMemLargeHeaderStrc);
        char* pBase = 0;
        unsigned int nOffset = 0;
        if (gnFlag0_007784C4 || gnFlag2_00776CBC)
        {
            nOffset = nPageSize - (nAlloc & (nPageSize - 1));
            if (gnFlag2_00776CBC)
            {
                nOffset &= nPageSize - 1;
                pBase = (char*)VirtualAlloc(0, nOffset + nAlloc + 4, 0x2000, 1);
            }
            else
                nOffset &= gnPageSize_00776CB8 - 4;
        }
        pBase = (char*)VirtualAlloc(pBase, nOffset + nAlloc, 0x1000, 4);
        if (!pBase)
        {
            sub_00411AA0_FreeBlock(pHeap, pResult);
            return 0;
        }
        pBase += nOffset;
        D2SMemLargeHeaderStrc* pLarge = (D2SMemLargeHeaderStrc*)pBase;
        pLarge->nSize = nSize;
        pLarge->pBlock = pResult;
        pLarge->tBlock.wSize = (unsigned short)((nSize + 0xFFFF) >> 16);
        pLarge->tBlock.f_2 = 0;
        pLarge->tBlock.nFlags = SMEM_BLOCK_LARGE | SMEM_BLOCK_INDIRECT;
        pLarge->tBlock.tSig = pHeap->tSig;
        *(D2SMemLargeHeaderStrc**)&pResult[1] = &pLarge[1];
        pHeap->nLargeBytes += nSize;
        return &pLarge[1];
    }
    return &pResult[1];
}

static __declspec(noinline) void* __stdcall sub_00412E40_HeapAlloc(D2SMemHeapStrc* pHeap, unsigned int dwFlags, int* pLockIndex, unsigned int nSize)
{
    if (nSize > 0x7FFFFFFF)
    {
        if (*pLockIndex != -1)
        {
            LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[*pLockIndex]);
            *pLockIndex = -1;
        }
        sub_00411620_FatalError(8, pHeap->szFile, pHeap->nLine);
    }
    void* pResult = 0;
    if (pHeap)
    {
        unsigned char nBlockFlags = 0;
        if (dwFlags & 0x4000000)
            nBlockFlags = SMEM_BLOCK_NOREPORT;
        if (dwFlags & 0x8000000)
            nBlockFlags |= SMEM_BLOCK_KEEP;
        pResult = sub_00412BA0_AllocBlock(nSize, nBlockFlags, pHeap);
    }
    if (!pResult)
    {
        if (*pLockIndex != -1)
        {
            LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[*pLockIndex]);
            *pLockIndex = -1;
        }
        if (pHeap->szFile[0])
            sub_00411620_FatalError(8, pHeap->szFile, pHeap->nLine);
        sub_00411620_FatalError(8, szSMemHeapAlloc_006CEDBC, -1);
    }
    if (dwFlags & 8)
    {
        SMemZero(pResult, nSize);
        return pResult;
    }
    if (gnFlag3_007788CC)
        SMemFill(pResult, nSize, 0xEE);
    return pResult;
}

static __declspec(noinline) void* __stdcall sub_00412F30_ReAlloc(int* pLockIndex, D2SMemHeapStrc* pHeap, void* pMemory, D2SMemBlockStrc* pBlock, unsigned int dwFlags, unsigned int nNewSize)
{
    unsigned int nHeaderSize;
    unsigned int nOldSize;
    sub_00411B90_GetBlockSizes(pBlock, pMemory, &nOldSize, &nHeaderSize);
    void* pResult = 0;
    if (!(pBlock->nFlags & SMEM_BLOCK_LARGE))
    {
        if (nNewSize < nOldSize)
        {
            sub_004121D0_ShrinkBlock(pBlock, nOldSize, nNewSize, pHeap);
            pResult = pMemory;
        }
        else if (nNewSize > nOldSize && sub_00412080_GrowBlock(pBlock, nOldSize, nNewSize, pHeap))
            pResult = pMemory;
    }
    if (!pResult)
    {
        if (dwFlags & 0x10)
            return 0;
        pResult = sub_00412E40_HeapAlloc(pHeap, 0, pLockIndex, nNewSize);
        if (pResult && nOldSize && nNewSize)
            SMemCopy(pResult, pMemory, nOldSize < nNewSize ? nOldSize : nNewSize);
        sub_00411C20_FreeBlockEx(pMemory, pHeap, pBlock);
        if (!pResult)
            return 0;
    }
    if (nNewSize > nOldSize)
    {
        if (dwFlags & 8)
        {
            SMemZero((char*)pResult + nOldSize, nNewSize - nOldSize);
            return pResult;
        }
        if (gnFlag3_007788CC)
            SMemFill((char*)pResult + nOldSize, nNewSize - nOldSize, 0xEE);
    }
    return pResult;
}

// 0x00413020
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
            sub_00411620_FatalError(0x8510007D, szSMemAlloc_006CEDCC, -1);
    }
    unsigned int dwId = sub_00411670_GetCallerId(szFile, nLine);
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[dwId & 0xFF]);
    int nLockIndex = dwId & 0xFF;
    D2SMemHeapStrc* pFound;
    for (pFound = gapFreeBlocks_007768B8[nLockIndex]; pFound; pFound = pFound->pNext)
    {
        if (pFound->dwId == dwId)
            break;
    }
    D2SMemHeapStrc* pHeap = pFound ? pFound : sub_004117F0_CreateHeap(nLine, dwId, nLockIndex, 0x1000, 0x1000, 0x10000, szFile);
    void* pResult = sub_00412E40_HeapAlloc(pHeap, dwFlags, &nLockIndex, nSize);
    if (nLockIndex != -1)
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    if (gpFreeBlockSweep_007788C8 && gpFreeBlockSweep_007788C8 != pHeap)
        sub_00412000_ReleaseFreeBlocks();
    return pResult;
}

// 0x00413250
void* __stdcall SMemHeapAlloc(unsigned int hHeap, unsigned int dwFlags, unsigned int nSize)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
            sub_00411620_FatalError(0x8510007D, szSMemHeapAlloc_006CEDBC, -1);
    }
    int nIndex = (unsigned char)hHeap;
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[nIndex]);
    int nLockIndex = nIndex;
    D2SMemHeapStrc* pHeap;
    for (pHeap = gapFreeBlocks_007768B8[nIndex]; pHeap; pHeap = pHeap->pNext)
    {
        if (pHeap->dwId == hHeap)
            break;
    }
    if (!pHeap)
    {
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nIndex]);
        sub_00411620_FatalError(6, szSMemHeapAlloc_006CEDBC, -1);
    }
    void* pResult = sub_00412E40_HeapAlloc(pHeap, dwFlags, &nLockIndex, nSize);
    if (nLockIndex != -1)
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    if (gpFreeBlockSweep_007788C8 && gpFreeBlockSweep_007788C8 != pHeap)
        sub_00412000_ReleaseFreeBlocks();
    return pResult;
}

void* __stdcall SMemHeapReAlloc(unsigned int hHeap, unsigned int dwFlags, void* pMemory, unsigned int nSize)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
            sub_00411620_FatalError(0x8510007D, szSMemHeapReAlloc_006CEE08, -1);
    }
    if (!pMemory || !sub_00411910_CheckPtr(pMemory, 1, 0, 0))
        return SMemHeapAlloc(hHeap, dwFlags, nSize);
    D2SMemBlockStrc* pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
    if (pBlock->nFlags & SMEM_BLOCK_INDIRECT)
        pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    if (((D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16))->dwId != hHeap)
        return 0;
    int nLockIndex;
    D2SMemHeapStrc* pHeap = sub_00411710_LockHeap(&nLockIndex, pBlock);
    void* pResult = sub_00412F30_ReAlloc(&nLockIndex, pHeap, pMemory, pBlock, dwFlags, nSize);
    sub_004117D0_ReleaseHeapLock(&nLockIndex);
    return pResult;
}

void* __stdcall SMemReAlloc(void* pMemory, unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
            sub_00411620_FatalError(0x8510007D, szSMemReAlloc_006CEE1C, -1);
    }
    if (!pMemory || !sub_00411910_CheckPtr(pMemory, 1, szFile, nLine))
        return SMemAlloc(nSize, szFile, nLine, dwFlags);
    D2SMemBlockStrc* pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
    if (pBlock->nFlags & SMEM_BLOCK_INDIRECT)
        pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    int nLockIndex;
    D2SMemHeapStrc* pHeap = sub_00411710_LockHeap(&nLockIndex, pBlock);
    void* pResult = sub_00412F30_ReAlloc(&nLockIndex, pHeap, pMemory, pBlock, dwFlags, nSize);
    if (nLockIndex != -1)
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    return pResult;
}

unsigned int gnStringCopyCheck; // 0x007788D8

// 0x004135D0
unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit)
{
 int valid=-1;
 valid&=dest?-1:0;
 valid&=source?-1:0;
 if(!valid) { sub_0041C340_SetLastError(87); return 0; }
 if(!limit) return 0;
 unsigned int end=(unsigned int)dest+limit-1;
 int offset=(unsigned int)dest-end;
 while((unsigned int)source&3) {
  if(!offset) break;
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 offset+=3;
 if(offset<0) {
  end-=3;
  unsigned int word=*(const unsigned int*)source;
  source+=4;
  unsigned int ones=0xFFFFFFFF;
  ones-=word;
  unsigned int check=(word+0x7EFEFEFF)^ones;
  ones|=word;
  check&=0x81010101;
  while(!check) {
   *(unsigned int*)(end+offset)=word;
   offset+=4;
   if(offset>=0) goto Tail;
   word=*(const unsigned int*)source;
   source+=4;
   ones-=word;
   check=(word+0x7EFEFEFF)^ones;
   ones|=word;
   check&=0x81010101;
  }
  for(;;) {
   if(!(unsigned char)word) {
    ((char*)end)[offset]=(char)word;
    goto Done;
   }
   if(!(unsigned char)(word>>8)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    offset+=1;
    goto Done;
   }
   if(!(word&0xFF0000)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    ((char*)end)[offset+2]=0;
    offset+=2;
    goto Done;
   }
   *(unsigned int*)(end+offset)=word;
   if(!(word&0xFF000000)) { offset+=3; goto Done; }
   offset+=4;
   gnStringCopyCheck=check;
   if(offset>=0) break;
   word=*(const unsigned int*)source;
   source+=4;
  }
Tail:
  end+=3;
 }
 offset-=3;
 while(offset) {
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 *(char*)end=0;
Done:
 return valid ? offset-(unsigned int)dest+end : 0;
}

// 0x00413800
unsigned int __stdcall sub_00413800(char* dest, const char* source, unsigned int limit)
{
 int valid=(__int64)dest?-1:0;
 valid&=source?-1:0;
 if(!valid) { sub_0041C340_SetLastError(87); return 0; }
 if(!limit) return 0;
 unsigned int dwOnes = 0xFFFFFFFF;
 const char* p = dest;
 unsigned int end=(unsigned int)dest+limit-1;
 if(limit!=0x7FFFFFFF) *(char*)end=0;
 while ((unsigned int)p & 3)
 {
  if (!*p) goto scanned;
  ++p;
 }
 for (;;)
 {
  const unsigned int w = *(const unsigned int*)p;
  dwOnes -= w;
  unsigned int dwTest = (w + 0x7EFEFEFF) ^ dwOnes;
  p += 4;
  dwOnes |= w;
  dwTest &= 0x81010101;
  if (dwTest)
  {
   if (!(char)w) { p -= 4; break; }
   if (!(char)(w >> 8)) { p -= 3; break; }
   if (!(w & 0xFF0000)) { p -= 2; break; }
   if (!(w & 0xFF000000)) { p -= 1; break; }
   gdwSStrScanWord_007788D8 = dwTest;
  }
 }
scanned:
 int offset=(unsigned int)p-end;
 while((unsigned int)source&3) {
  if(!offset) break;
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 offset+=3;
 if(offset<0) {
  end-=3;
  unsigned int word=*(const unsigned int*)source;
  source+=4;
  dwOnes-=word;
  unsigned int check=(word+0x7EFEFEFF)^dwOnes;
  dwOnes|=word;
  check&=0x81010101;
  while(!check) {
   *(unsigned int*)(end+offset)=word;
   offset+=4;
   if(offset>=0) goto Tail;
   word=*(const unsigned int*)source;
   source+=4;
   dwOnes-=word;
   check=(word+0x7EFEFEFF)^dwOnes;
   dwOnes|=word;
   check&=0x81010101;
  }
  for(;;) {
   if(!(unsigned char)word) {
    ((char*)end)[offset]=(char)word;
    goto Done;
   }
   if(!(unsigned char)(word>>8)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    offset+=1;
    goto Done;
   }
   if(!(word&0xFF0000)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    ((char*)end)[offset+2]=0;
    offset+=2;
    goto Done;
   }
   *(unsigned int*)(end+offset)=word;
   if(!(word&0xFF000000)) { offset+=3; goto Done; }
   offset+=4;
   gdwSStrScanWord_007788D8=check;
   if(offset>=0) break;
   word=*(const unsigned int*)source;
   source+=4;
  }
Tail:
  end+=3;
 }
 offset-=3;
 while(offset) {
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 *(char*)end=0;
Done:
 return valid ? offset-(unsigned int)dest+end : 0;
}
