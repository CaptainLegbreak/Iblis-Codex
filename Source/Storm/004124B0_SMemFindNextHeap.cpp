struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2SMemHeapStrc
{
    D2SMemHeapStrc* pNext;
    unsigned int dwId;
    int nLockIndex;
    unsigned int dwSig;
    int bReportLeak;
    int nBlocks;
    unsigned int nUsedBytes;
    void* pFirst;
    void* pEnd;
    unsigned int nFragments;
    unsigned int nPageSize;
    unsigned int nCommitted;
    unsigned int nReserved;
    unsigned int nLargeBytes;
    void* apFree[9];
    int nLine;
    char szFile[4];
};

struct D2SMemHeapInfoStrc
{
    unsigned int dwSize;
    unsigned int hHeap;
    char szName[0x104];
    int nLine;
    unsigned int dwUnk110;
    unsigned int dwSizeA;
    unsigned int dwSizeB;
    unsigned int dwUnk11C;
    unsigned int nBlocks;
    unsigned int dwSizeC;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __cdecl sub_00411CD0_InitHeaps();                                                                      // 0x00411CD0
extern int gnFlag1_007784C0;                                                                                // 0x007784C0
extern int gbHeapInitialized_007788D0;                                                                      // 0x007788D0
extern D2SMemHeapStrc* gapFreeBlocks_007768B8[0x100];                                                       // 0x007768B8
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100];                                              // 0x00776CC0
extern "C" const char szSMemFindNextHeap_006CED18[];                                                        // 0x006CED18

static void __stdcall sub_004117A0_SetAndShowError(const char* szFile, int nLine, unsigned int nError);         // 0x004117A0

// 0x004117A0
static __declspec(noinline) void __stdcall sub_004117A0_SetAndShowError(const char* szFile, int nLine, unsigned int nError)
{
    sub_0041C340_SetLastError(nError);
    if (gnFlag1_007784C0)
    {
        SErrDisplayError(nError, szFile, nLine, 0, 1, 1);
    }
}

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

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

#include "gen/data/Source/Storm/004124B0_SMemFindNextHeap.inc"
