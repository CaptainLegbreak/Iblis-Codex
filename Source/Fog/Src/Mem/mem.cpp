#include "D2GameTypes.h"
#include "D2FogTypes.h"
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
#pragma intrinsic(memset)

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall RaiseException(unsigned long dwCode, unsigned long dwFlags, unsigned long nArgs, const unsigned long* pArgs); // 0x006CC224
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __cdecl MAINMENUS_LogPoolError(const char* szFormat, ...);                                          // 0x00409020
extern D2PoolDirectoryStrc gtPoolManager;                                                            // 0x0074F0E8

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220

// 0x00409000
int __fastcall ERRORMANAGER_GetBitWidth(unsigned int nValue)
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
    return nValue < 3 ? 1 : ERRORMANAGER_GetBitWidth(nValue - 1);
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
        memset(&gtPoolManager, 0, sizeof(gtPoolManager));
        InitializeCriticalSection(&gtPoolManager.tLock);
        gtPoolManager.bInit = 1;
    }
    EnterCriticalSection(&gtPoolManager.tLock);
    D2PoolSystemStrc* pSystem;
    if (gtPoolManager.nFreeCount)
    {
        --gtPoolManager.nFreeCount;
        pSystem = &gtPoolManager.aSystems[gtPoolManager.anFreeIndex[gtPoolManager.nFreeCount]];
    }
    else
    {
        if (gtPoolManager.nUsed >= 8)
        {
            LeaveCriticalSection(&gtPoolManager.tLock);
            MAINMENUS_LogPoolError("Insufficient pre-allocated pool systems");
            RaiseException(0xE0000001, 0, 0, 0);
            return 0;
        }
        pSystem = &gtPoolManager.aSystems[gtPoolManager.nUsed];
        ++gtPoolManager.nUsed;
    }
    LeaveCriticalSection(&gtPoolManager.tLock);

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

extern "C" void __cdecl free(void* pMemory); // 0x00683FC0

// 0x00409C80
void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem)
{
    if (!gtPoolManager.bInit)
    {
        return;
    }
    if (!pSystem)
    {
        pSystem = &gtPoolManager.aSystems[0];
    }
    if (!pSystem->nPools)
    {
        return;
    }
    for (int i = 0; i < pSystem->nPools; i++)
    {
        D2MemPoolRecStrc* pPool = &pSystem->aPools[i];
        D2MemPoolBlockStrc* pBlock = pPool->pFirstBlock;
        while (pBlock)
        {
            D2MemPoolBlockStrc* pNext = pBlock->pNext;
            VirtualFree(pBlock->pMemory, 0, 0x8000);
            free(pBlock);
            pBlock = pNext;
        }
        DeleteCriticalSection(&pPool->tLock);
    }
    free(pSystem->pRecords);
    for (int j = 0; j < 1023; j++)
    {
        int* pEntry = pSystem->apLargeBlocks[j];
        while (pEntry)
        {
            int* pNext = (int*)*pEntry;
            free(pEntry);
            pEntry = pNext;
        }
    }
    DeleteCriticalSection(&pSystem->tLock);
    memset(pSystem, 0, sizeof(D2PoolSystemStrc));
    EnterCriticalSection(&gtPoolManager.tLock);
    gtPoolManager.anFreeIndex[gtPoolManager.nFreeCount] = ((unsigned int)pSystem - (unsigned int)&gtPoolManager.aSystems[0]) / sizeof(D2PoolSystemStrc);
    gtPoolManager.nFreeCount++;
    LeaveCriticalSection(&gtPoolManager.tLock);
    if (pSystem == &gtPoolManager.aSystems[0])
    {
        gtPoolManager.bInit = 0;
        DeleteCriticalSection(&gtPoolManager.tLock);
    }
}
