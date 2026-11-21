#include "D2GameTypes.h"
#include "D2StormTypes.h"

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

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, unsigned long nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode);   // 0x006CC2E0
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);          // 0x006CC468

int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed);             // 0x00413CE0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith);                    // 0x0041D2C0
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
void __cdecl SMemInitialize();                                                                      // 0x00411CD0
void __cdecl sub_00411A20_InitPageSize();                                                                   // 0x00411A20
void __fastcall sub_00411A80_ReleaseBlock(D2SMemHeapStrc** ppLink);                                         // 0x00411A80
void __cdecl sub_00412000_ReleaseFreeBlocks();                                                              // 0x00412000

extern "C" const char gszMemNeverReleased_006CECCC[];                                                       // 0x006CECCC
extern "C" const char szSMemFree_006CED2C[];                                                                // 0x006CED2C
extern "C" const char szSMemGetHeapByCaller_006CED38[];                                                     // 0x006CED38
extern "C" const char szSMemGetHeapByPtr_006CED50[];                                                        // 0x006CED50
extern "C" const char szSMemGetSize_006CED64[];                                                             // 0x006CED64
extern "C" const char szSMemHeapCreate_006CED74[];                                                          // 0x006CED74
extern "C" const char szSMemHeapFree_006CED9C[];                                                            // 0x006CED9C
extern "C" const char szSMemHeapSize_006CEDAC[];                                                            // 0x006CEDAC
extern "C" const char szSMemHeapAlloc_006CEDBC[];                                                           // 0x006CEDBC
extern "C" const char szSMemAlloc_006CEDCC[];                                                               // 0x006CEDCC
extern "C" const char szSMemHeapReAlloc_006CEE08[];                                                         // 0x006CEE08
extern "C" const char szSMemReAlloc_006CEE1C[];                                                             // 0x006CEE1C

extern int gbCallerFirst_00708340;                                                                          // 0x00708340
extern unsigned int gnHeapId_00708344;                                                                      // 0x00708344
extern unsigned int gdwCallerId_007768A8;                                                                   // 0x007768A8
extern unsigned int gdwCallerWord_007768AC;                                                                 // 0x007768AC
extern int gnCallerLine_007768B0;                                                                           // 0x007768B0
extern const char* gszCallerFile_007768B4;                                                                  // 0x007768B4
extern D2SMemHeapStrc* gapFreeBlocks_007768B8[0x100];                                                       // 0x007768B8
static unsigned int gnPageSize_00776CB8;                                                                    // 0x00776CB8

struct T004013C0
{
    unsigned long dwOemId;
    unsigned long dwPageSize;
    void* lpMinimumApplicationAddress;
    void* lpMaximumApplicationAddress;
    unsigned long dwActiveProcessorMask;
    unsigned long dwNumberOfProcessors;
    unsigned long dwProcessorType;
    unsigned long dwAllocationGranularity;
    unsigned short wProcessorLevel;
    unsigned short wProcessorRevision;
};

extern "C" __declspec(dllimport) void __stdcall GetSystemInfo(T004013C0* pInfo);                     // 0x006CC1F0

// 0x00411A20
void __cdecl sub_00411A20_InitPageSize()
{
    T004013C0 systemInfo;
    GetSystemInfo(&systemInfo);
    gnPageSize_00776CB8 = 1;
    while (gnPageSize_00776CB8 < systemInfo.dwPageSize)
        gnPageSize_00776CB8 *= 2;
}

extern int gnFlag2_00776CBC;                                                                                // 0x00776CBC
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100];                                              // 0x00776CC0
extern int gnFlag1_007784C0;                                                                                // 0x007784C0
extern int gnFlag0_007784C4;                                                                                // 0x007784C4
extern int gabFreeBlockDirty_007784C8[0x100];                                                               // 0x007784C8
extern D2SMemHeapStrc* gpFreeBlockSweep_007788C8;                                                           // 0x007788C8
extern int gnFlag3_007788CC;                                                                                // 0x007788CC
extern int gbHeapInitialized_007788D0;                                                                      // 0x007788D0
extern int gnFlag_00779098;                                                                                 // 0x00779098

static void __stdcall sub_004117A0_SetAndShowError(const char* szFile, int nLine, unsigned int nError);
static void sub_00411AA0_FreeBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock);

static __declspec(noreturn) void sub_00411620_FatalError(unsigned int nError, const char* szFile, int nLine);
// 0x00411620
static __declspec(noreturn) void sub_00411620_FatalError(unsigned int nError, const char* szFile, int nLine)
{
    SErrDisplayError(nError, szFile, nLine, 0, 0, 1);
    ExitProcess(1);
}

// 0x00411670
static unsigned int sub_00411670_GetCallerId(int nLine, const char* szFile)
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

static D2SMemHeapStrc* __stdcall sub_00411710_LockHeap(int* pLockIndex, D2SMemBlockStrc* pBlock);
// 0x00411710
static D2SMemHeapStrc* __stdcall sub_00411710_LockHeap(int* pLockIndex, D2SMemBlockStrc* pBlock)
{
    D2SMemHeapStrc* pHeap = (D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16);
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[pHeap->nLockIndex]);
    *pLockIndex = pHeap->nLockIndex;
    return pHeap;
}

static void __stdcall sub_004117A0_SetAndShowError(const char* szFile, int nLine, unsigned int nError);
// 0x004117A0
static void __stdcall sub_004117A0_SetAndShowError(const char* szFile, int nLine, unsigned int nError)
{
    sub_0041C340_SetLastError(nError);
    if (gnFlag1_007784C0)
    {
        SErrDisplayError(nError, szFile, nLine, 0, 1, 1);
    }
}

static void sub_004117D0_ReleaseHeapLock(int* pLockIndex);
// 0x004117D0
static void sub_004117D0_ReleaseHeapLock(int* pLockIndex)
{
    if (*pLockIndex != -1)
    {
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[*pLockIndex]);
        *pLockIndex = -1;
    }
}

D2SMemHeapStrc* __stdcall sub_004117F0_CreateHeap(const char* szFile, int nLine, unsigned int dwId, int nLockIndex, unsigned int nPageSize, unsigned int nCommit, unsigned int nReserve);

// build: context sub_004117F0_CreateHeap
static D2SMemHeapStrc* __stdcall sub_004117F0_CreateHeap(const char* szFile, int nLine, unsigned int dwId, int nLockIndex, unsigned int nPageSize, unsigned int nCommit, unsigned int nReserve)
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
    pHeap->nPageSize = nPageSize;
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
    tHeader.tSig.wMagic = 0x6F6D;
    pHeap->tSig = tHeader.tSig;
    gapFreeBlocks_007768B8[nLockIndex] = pHeap;
    return pHeap;
}

static int sub_00411910_CheckPtr(void* pMemory, int bReport, const char* szFile, int nLine);
// 0x00411910
static int sub_00411910_CheckPtr(void* pMemory, int bReport, const char* szFile, int nLine)
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

// build: context sub_A21_FreeListIndex
static unsigned int sub_A21_FreeListIndex(unsigned int nSize)
{
    unsigned int nIndex = nSize >> 5;
    if (nIndex >= 8)
        nIndex = 8;
    return nIndex;
}

// 0x004119B0
static void __stdcall sub_004119B0_CalcBlockSize(unsigned int* pTotal, unsigned int* pPadding, int* pbLarge, int* pbSentinel, unsigned int nSize)
{
    *pbLarge = gnFlag2_00776CBC || nSize > 0xFE87;
    *pbSentinel = gnFlag0_007784C4 && !*pbLarge;
    nSize = (*pbLarge ? 4 : nSize) + (*pbSentinel ? 2 : 0) + sizeof(D2SMemBlockStrc);
    *pTotal = nSize + ((0 - nSize) & 7);
    *pPadding = *pTotal - nSize;
}

__declspec(noinline) static void __stdcall sub_00411A50_InitBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock, unsigned int nSize, unsigned int nPadding, unsigned char nFlags);
// 0x00411A50
static void __stdcall sub_00411A50_InitBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock, unsigned int nSize, unsigned int nPadding, unsigned char nFlags)
{
    pBlock->wSize = (unsigned short)nSize;
    pBlock->nPadding = (unsigned char)nPadding;
    pBlock->nFlags = nFlags;
    pBlock->tSig = pHeap->tSig;
    if (nFlags & SMEM_BLOCK_SENTINEL)
        *(unsigned short*)((char*)pBlock + nSize - nPadding - 2) = 0x12B1;
}

// 0x00411AA0
static void sub_00411AA0_FreeBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock)
{
    unsigned int nSize;
    if (pBlock->nFlags & SMEM_BLOCK_LARGE)
    {
        D2SMemLargeHeaderStrc* pLarge = *(D2SMemLargeHeaderStrc**)&pBlock[1];
        if (pLarge)
        {
            nSize = pLarge[-1].nSize;
            pHeap->nLargeBytes -= nSize;
            VirtualFree((void*)((unsigned int)(pLarge - 1) & ~(gnPageSize_00776CB8 - 1)), 0, 0x8000);
        }
        else
            nSize = 0;
    }
    else
    {
        nSize = pBlock->wSize - pBlock->nPadding - sizeof(D2SMemBlockStrc);
        if (pBlock->nFlags & SMEM_BLOCK_SENTINEL)
            nSize -= 2;
    }
    pHeap->nUsedBytes -= nSize;
    pHeap->nBlocks -= 1;
    pBlock->nFlags = (pBlock->nFlags & SMEM_BLOCK_PREVFREE) | SMEM_BLOCK_FREE;
    D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pBlock + pBlock->wSize);
    pBlock->nPadding = 0;
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

static void sub_00411B90_GetBlockSizes(D2SMemBlockStrc* pBlock, void* pMemory, unsigned int* pDataSize, unsigned int* pHeaderSize);
// 0x00411B90
static void sub_00411B90_GetBlockSizes(D2SMemBlockStrc* pBlock, void* pMemory, unsigned int* pDataSize, unsigned int* pHeaderSize)
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

static int sub_00411BD0_CommitHeap(D2SMemHeapStrc* pHeap, unsigned int nNeeded);
// 0x00411BD0
static int sub_00411BD0_CommitHeap(D2SMemHeapStrc* pHeap, unsigned int nNeeded)
{
    unsigned int nCommit = nNeeded - pHeap->nCommitted;
    if (nCommit & (pHeap->nPageSize - 1))
        nCommit += pHeap->nPageSize - (nCommit & (pHeap->nPageSize - 1));
    if (pHeap->nCommitted + nCommit > pHeap->nReserved)
        nCommit = pHeap->nReserved - pHeap->nCommitted;
    if (!VirtualAlloc((char*)pHeap + pHeap->nCommitted, nCommit, 0x1000, 4))
        return 0;
    pHeap->nCommitted += nCommit;
    return 1;
}

static void __stdcall sub_00411C20_FreeBlockEx(void* pMemory, D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock);
// 0x00411C20
static void __stdcall sub_00411C20_FreeBlockEx(void* pMemory, D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock)
{
    if (gnFlag3_007788CC && !(pBlock->nFlags & SMEM_BLOCK_LARGE))
        SMemFill(pMemory, pBlock->wSize - (pBlock->nFlags & SMEM_BLOCK_SENTINEL) * 2 - pBlock->nPadding - sizeof(D2SMemBlockStrc), 0xDD);
    sub_00411AA0_FreeBlock(pHeap, pBlock);
}

static void __stdcall sub_00411C70_SplitBlock(unsigned int* pPadding, D2SMemHeapStrc* pHeap, unsigned int* pSize, D2SMemBlockStrc* pBlock);
// 0x00411C70
static void __stdcall sub_00411C70_SplitBlock(unsigned int* pPadding, D2SMemHeapStrc* pHeap, unsigned int* pSize, D2SMemBlockStrc* pBlock)
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
        pFree->nPadding = 0;
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

// 0x00411DC0
static void sub_00411DC0_RebuildFreeLists(D2SMemHeapStrc* pHeap)
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
                    pPrev->wSize = pBlock->wSize + pPrev->wSize;
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

D2SMemHeapStrc** __fastcall sub_00411F00_ProcessUsedBlock(D2SMemHeapStrc** ppLink); // 0x00411F00

int __stdcall sub_00412080_GrowBlock(D2SMemBlockStrc* pBlock, unsigned int nOldSize, unsigned int nNewSize, D2SMemHeapStrc* pHeap); // 0x00412080

void __stdcall sub_004121D0_ShrinkBlock(D2SMemBlockStrc* pBlock, unsigned int nOldSize, unsigned int nNewSize, D2SMemHeapStrc* pHeap); // 0x004121D0

// 0x00412650
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags)
{
    if (!gbHeapInitialized_007788D0)
    {
        SMemInitialize();
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

// 0x00412710
unsigned int __stdcall SMemGetHeapByCaller(const char* szFile, int nLine)
{
    if (!gbHeapInitialized_007788D0)
    {
        SMemInitialize();
        if (!gbHeapInitialized_007788D0)
        {
            sub_004117A0_SetAndShowError(szSMemGetHeapByCaller_006CED38, -1, 0x8510007D);
            return 0;
        }
    }
    return sub_00411670_GetCallerId(nLine, szFile);
}

// 0x00412760
unsigned int __stdcall SMemGetHeapByPtr(void* pMemory)
{
    if (!gbHeapInitialized_007788D0)
    {
        SMemInitialize();
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

// 0x004127E0
unsigned int __stdcall SMemGetSize(void* pMemory, const char* szFile, int nLine)
{
    if (!gbHeapInitialized_007788D0)
    {
        SMemInitialize();
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

// build: context sub_A21_HeapIdInUse
static inline int sub_A21_HeapIdInUse(unsigned int dwId)
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

// 0x00412870
unsigned int __stdcall SMemHeapCreate(unsigned int dwOptions, unsigned int nInitialSize, unsigned int nMaximumSize)
{
    if (!gbHeapInitialized_007788D0)
    {
        SMemInitialize();
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
    sub_004117F0_CreateHeap(0, 0, gnHeapId_00708344, nLockIndex, 0x1000, nInitialSize, 0x10000);
    LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    if (!gnHeapId_00708344)
        sub_004117A0_SetAndShowError(szSMemHeapCreate_006CED74, -1, 8);
    return gnHeapId_00708344;
}

// 0x00412A60
int __stdcall SMemHeapFree(unsigned int hHeap, unsigned int dwFlags, void* pMemory)
{
    if (!gbHeapInitialized_007788D0)
    {
        SMemInitialize();
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

// 0x00412B10
unsigned int __stdcall SMemHeapSize(unsigned int hHeap, unsigned int dwFlags, void* pMemory)
{
    if (!gbHeapInitialized_007788D0)
    {
        SMemInitialize();
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

// 0x00412BA0
static void* __stdcall sub_00412BA0_AllocBlock(unsigned int nSize, unsigned char nUserFlags, D2SMemHeapStrc* pHeap)
{
    int bSentinel;
    int bLarge;
    unsigned int nPadding;
    unsigned int nTotal;
    sub_004119B0_CalcBlockSize(&nTotal, &nPadding, &bLarge, &bSentinel, nSize);
    const unsigned int nShifted = nTotal >> 5;
    unsigned int nIndex = nShifted < 8 ? nShifted : 8;
    if (pHeap->nFragments >= 4 && !pHeap->apFree[nIndex])
        sub_00411DC0_RebuildFreeLists(pHeap);
    D2SMemBlockStrc** ppBest = 0;
    D2SMemBlockStrc** ppLink;
    D2SMemBlockStrc* pFree;
    unsigned int nBestDiff = 0x7FFFFFFF;
    if (!pHeap->apFree[nIndex])
    {
        unsigned int i = nIndex + 1;
        ppLink = &pHeap->apFree[nIndex];
        do
        {
            if (i >= 9)
                break;
            ++ppLink;
            ++i;
        } while (!*ppLink);
        pFree = *ppLink;
    }
    else
    {
        ppLink = &pHeap->apFree[nIndex];
        pFree = *ppLink;
    }
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
            ppLink = &(*ppLink)->pNextFree;
            pFree = *ppLink;
        } while (pFree);
    }
    int bPrevFree = 0;
    D2SMemBlockStrc* pResult;
    if (ppBest)
    {
        pResult = *ppBest;
        bPrevFree = ((pResult->nFlags) & SMEM_BLOCK_PREVFREE) != 0;
        *ppBest = pResult->pNextFree;
        D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pResult + pResult->wSize);
        if (pHeap->nFragments && (bPrevFree || (pNext != pHeap->pEnd && (pNext->nFlags & SMEM_BLOCK_FREE))))
            pHeap->nFragments -= 1;
        sub_00411C70_SplitBlock(&nPadding, pHeap, &nTotal, pResult);
    }
    else
    {
        D2SMemBlockStrc** ppEnd = &pHeap->pEnd;
        unsigned int nEnd = (char*)*ppEnd - (char*)pHeap + nTotal;
        unsigned int const tNReserved = pHeap->nReserved;
        if (nEnd > tNReserved)
        {
            unsigned int nReserve = tNReserved < 0x10000000 ? tNReserved * 2 : tNReserved;
            D2SMemHeapStrc* pNewHeap = sub_004117F0_CreateHeap(pHeap->szFile, pHeap->nLine, pHeap->dwId, pHeap->nLockIndex, nReserve >> 3, nReserve >> 3, nReserve);
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
            int bReserve;
            if (gnFlag2_00776CBC)
            {
                nOffset &= nPageSize - 1;
                bReserve = 1;
            }
            else
            {
                nOffset &= gnPageSize_00776CB8 - 4;
                bReserve = 0;
            }
            if (bReserve)
                pBase = (char*)VirtualAlloc(0, nOffset + nAlloc + 4, 0x2000, 1);
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
        D2SMemBlockStrc* pHdr = &pLarge->tBlock;
        pHdr->wSize = (unsigned short)((nSize + 0xFFFF) >> 16);
        pHdr->nPadding = 0;
        pHdr->nFlags = SMEM_BLOCK_LARGE | SMEM_BLOCK_INDIRECT;
        pHdr->tSig = pHeap->tSig;
        ++pLarge;
        *(D2SMemLargeHeaderStrc**)&pResult[1] = pLarge;
        pHeap->nLargeBytes += nSize;
        return pLarge;
    }
    return &pResult[1];
}

static void* __stdcall sub_00412E40_HeapAlloc(D2SMemHeapStrc* pHeap, unsigned int dwFlags, int* pLockIndex, unsigned int nSize);
// 0x00412E40
static void* __stdcall sub_00412E40_HeapAlloc(D2SMemHeapStrc* pHeap, unsigned int dwFlags, int* pLockIndex, unsigned int nSize)
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

static void* __stdcall sub_00412F30_ReAlloc(int* pLockIndex, D2SMemHeapStrc* pHeap, void* pMemory, D2SMemBlockStrc* pBlock, unsigned int dwFlags, unsigned int nNewSize);
// 0x00412F30
static void* __stdcall sub_00412F30_ReAlloc(int* pLockIndex, D2SMemHeapStrc* pHeap, void* pMemory, D2SMemBlockStrc* pBlock, unsigned int dwFlags, unsigned int nNewSize)
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

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags); // 0x00413020

// 0x00413250
void* __stdcall SMemHeapAlloc(unsigned int hHeap, unsigned int dwFlags, unsigned int nSize)
{
    if (!gbHeapInitialized_007788D0)
    {
        SMemInitialize();
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

// 0x00413310
void* __stdcall SMemHeapReAlloc(unsigned int hHeap, unsigned int dwFlags, void* pMemory, unsigned int nSize)
{
    if (!gbHeapInitialized_007788D0)
    {
        SMemInitialize();
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

// 0x004133D0
void* __stdcall SMemReAlloc(void* pMemory, unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags)
{
    if (!gbHeapInitialized_007788D0)
    {
        SMemInitialize();
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
