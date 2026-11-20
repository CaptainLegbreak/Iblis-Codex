#include "D2GameTypes.h"
#include "D2FogTypes.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

extern D2PoolDirectoryStrc gtPoolManager_0074F0E8;                                                                  // 0x0074F0E8
#define gtDefaultPoolSystem_0074F104 (gtPoolManager_0074F0E8.aSystems[0])
extern float gfSinTable_00707800[];                                                                         // 0x00707800
extern int gbUsePools_00708000;                                                                             // 0x00708000
void* __fastcall sub_0040A080_PoolAlloc(void* pPool, int nSize, const char* szFile, int nLine);             // 0x0040A080
void __fastcall sub_00409AB0_PoolFree(void* pPool, void** ppMemory, const char* szFile, int nLine);         // 0x00409AB0
void* __fastcall sub_0040A1F0_PoolRealloc(void* pPool, void* pMemory, int nSize, const char* szFile, int nLine); // 0x0040A1F0
void __cdecl sub_00408900_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900

// 0x00409FF0
void __cdecl FOG_SetMemoryPoolSystemMode(D2PoolSystemStrc* pSystem, int bFreePoolAlloc)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (pSystem->nPools)
    {
        EnterCriticalSection(&pSystem->tLock);
        pSystem->bFreePoolAlloc = bFreePoolAlloc;
        LeaveCriticalSection(&pSystem->tLock);
    }
}

// 0x0040A040
int __cdecl sub_0040A040_GetPoolSystemCount(D2PoolSystemStrc* pSystem)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    EnterCriticalSection(&pSystem->tLock);
    int nCount = pSystem->nCount;
    LeaveCriticalSection(&pSystem->tLock);
    return nCount;
}

// 0x0040B330
float __stdcall sub_0040B330_Cos(int nAngle)
{
    return gfSinTable_00707800[(nAngle + 128) & 511];
}

// 0x0040B350
float __stdcall sub_0040B350_Sin(int nAngle)
{
    return gfSinTable_00707800[nAngle & 511];
}

// 0x0040B370
void __fastcall sub_0040B370_SetUsePools(int bUsePools)
{
    gbUsePools_00708000 = bUsePools;
}

// 0x0040B380
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0)
{
    void* pMemory = sub_0040A080_PoolAlloc(0, nSize, szFile, nLine);
    if (!pMemory)
    {
        sub_00408900_RaiseErrorReport(2, szFile, nLine, &gszEmptyAssertText);
    }
    return pMemory;
}

// 0x0040B3C0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0)
{
    sub_00409AB0_PoolFree(0, &pFree, szFile, nLine);
    return 1;
}

// 0x0040B3F0
void* __fastcall FOG_Realloc(void* pMemory, int nSize, const char* szFile, int nLine, int n0)
{
    void* pNew = sub_0040A1F0_PoolRealloc(0, pMemory, nSize, szFile, nLine);
    if (!pNew)
    {
        sub_00408900_RaiseErrorReport(2, szFile, nLine, &gszEmptyAssertText);
    }
    return pNew;
}

// 0x0040B430
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0)
{
    void* pMemory = sub_0040A080_PoolAlloc(gbUsePools_00708000 ? pMemPool : 0, nSize, szFile, nLine);
    if (!pMemory)
    {
        sub_00408900_RaiseErrorReport(2, szFile, nLine, &gszEmptyAssertText);
    }
    return pMemory;
}

// 0x0040B480
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0)
{
    sub_00409AB0_PoolFree(gbUsePools_00708000 ? pMemPool : 0, &pFree, szFile, nLine);
    return 1;
}

// 0x0040B4B0
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0)
{
    void* pNew = sub_0040A1F0_PoolRealloc(gbUsePools_00708000 ? pMemPool : 0, pMemory, nSize, szFile, nLine);
    if (!pNew)
    {
        sub_00408900_RaiseErrorReport(2, szFile, nLine, &gszEmptyAssertText);
    }
    return pNew;
}

#include "gen/data/Source/Fog/Unknown_00409FF0.inc"
