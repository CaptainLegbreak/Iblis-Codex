#include "D2GameTypes.h"
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
#pragma intrinsic(memset)


struct D2MemPoolRecStrc
{
    D2CriticalSectionStrc tLock;
    int nBlockSize;
    int nBlocksPerChunk;
    int nChunkSize;
    int nBlocks;
    void* pFirstBlock;
    void* pLastBlock;
};

struct D2PoolSystemStrc
{
    int bFreePoolAlloc;
    D2CriticalSectionStrc tLock;
    int nPools;
    D2MemPoolRecStrc aPools[40];
    int nLargeOverflow;
    int nUnk0x7A4;
    void* pRecords;
    int* apLargeBlocks[1023];
    int nCount;
    char szName[0x20];
};

struct D2PoolDirectoryStrc
{
    int bInit;
    D2CriticalSectionStrc tLock;
    D2PoolSystemStrc aSystems[8];
    int nUsed;
    unsigned int anFreeIndex[8];
    int nFreeCount;
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall RaiseException(unsigned long dwCode, unsigned long dwFlags, unsigned long nArgs, const unsigned long* pArgs); // 0x006CC224
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __cdecl sub_00409020_LogPoolError(const char* szFormat, ...);                                          // 0x00409020
extern D2PoolDirectoryStrc gtPoolManager_0074F0E8;                                                            // 0x0074F0E8

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00409000
int __fastcall sub_00409000_GetBitWidth(unsigned int nValue)
{
    if (!nValue)
    {
        return 0;
    }
    __asm
    {
        bsr eax, nValue
        inc eax
        mov nValue, eax
    }
    return nValue;
}

// build: context Log2Ceil
static inline int Log2Ceil(int nValue)
{
    return nValue < 3 ? 1 : sub_00409000_GetBitWidth(nValue - 1);
}

// build: context GetPoolIndex
static inline int GetPoolIndex(int nSize)
{
    if (nSize <= 0x10)
    {
        return 0;
    }
    return Log2Ceil(nSize) - 4;
}

// 0x00409DD0
int __cdecl sub_00409DD0_InitPoolSystem(D2PoolSystemStrc** ppPoolSystem, const char* szName, int nSize, int nUnused)
{
    if (!ppPoolSystem)
    {
        memset(&gtPoolManager_0074F0E8, 0, sizeof(gtPoolManager_0074F0E8));
        InitializeCriticalSection(&gtPoolManager_0074F0E8.tLock);
        gtPoolManager_0074F0E8.bInit = 1;
    }
    EnterCriticalSection(&gtPoolManager_0074F0E8.tLock);
    D2PoolSystemStrc* pSystem;
    if (gtPoolManager_0074F0E8.nFreeCount)
    {
        --gtPoolManager_0074F0E8.nFreeCount;
        pSystem = &gtPoolManager_0074F0E8.aSystems[gtPoolManager_0074F0E8.anFreeIndex[gtPoolManager_0074F0E8.nFreeCount]];
    }
    else
    {
        if (gtPoolManager_0074F0E8.nUsed >= 8)
        {
            LeaveCriticalSection(&gtPoolManager_0074F0E8.tLock);
            sub_00409020_LogPoolError("Insufficient pre-allocated pool systems");
            RaiseException(0xE0000001, 0, 0, 0);
            return 0;
        }
        pSystem = &gtPoolManager_0074F0E8.aSystems[gtPoolManager_0074F0E8.nUsed];
        ++gtPoolManager_0074F0E8.nUsed;
    }
    LeaveCriticalSection(&gtPoolManager_0074F0E8.tLock);

    memset(pSystem, 0, sizeof(*pSystem));
    if (ppPoolSystem)
    {
        *ppPoolSystem = pSystem;
    }
    D2CriticalSectionStrc* pLock = &pSystem->tLock;
    InitializeCriticalSection(pLock);
    EnterCriticalSection(pLock);
    if (szName)
    {
        SStrCopy(pSystem->szName, szName, sizeof(pSystem->szName));
        pSystem->szName[sizeof(pSystem->szName) - 1] = 0;
    }

    int nValue = GetPoolIndex(nSize);
    const int nPools = nValue + 1;
    D2_ASSERT(nPools <= 40, 0x866);
    pSystem->nPools = nPools;
    pSystem->pRecords = 0;
    for (int i = 0; i < nPools; ++i)
    {
        InitializeCriticalSection(&pSystem->aPools[i].tLock);
        int nBlockSize;
        if (i == 0)
        {
            nBlockSize = 0x10;
        }
        else
        {
            nBlockSize = 1 << (i + 4);
        }
        pSystem->aPools[i].nBlockSize = nBlockSize;
        if (nBlockSize > 1000000 || (nBlockSize << 8) >= 0x40000)
        {
            nValue = 0x80000 / nBlockSize;
        }
        else
        {
            nValue = 0x100;
            if ((nBlockSize << 8) < 0x10000)
            {
                nValue = 0x10000 / nBlockSize;
            }
        }
        pSystem->aPools[i].nBlocksPerChunk = nValue;
        pSystem->aPools[i].nChunkSize = nBlockSize * nValue;
    }
    memset(pSystem->apLargeBlocks, 0, sizeof(pSystem->apLargeBlocks));
    LeaveCriticalSection(pLock);
    return 0;
}
