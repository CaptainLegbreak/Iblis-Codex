#include "D2CMP.h"
#include "D2CmpTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

struct T00604AE0
{
    unsigned int nKey;
    char szName[0x20];
    int nValue;
    T00604AE0* pPrev;
    T00604AE0* pNext;
};

struct D2CelDataHashStrc
{
    int nCheck[0x200];
    T00604AE0* pBuckets[0x200];
};

// 0x0060AEB0
void __fastcall CelDataHashFreeEntry(D2CelDataHashStrc* pHash, T00604AE0* pEntry, void* pMemPool)
{
    if (pHash->pBuckets[pEntry->nKey] == pEntry)
        pHash->pBuckets[pEntry->nKey] = pEntry->pNext;
    FOG_FreePool(pMemPool, pEntry, ".\\SRC\\CelDataHash.cpp", 0x3A, 0);
}

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);

// 0x0060AEE0
void __fastcall CelDataHashInit(D2CelDataHashStrc* pHash)
{
    memset(pHash, 0, sizeof(D2CelDataHashStrc));
}

// 0x0060AF90
T00604AE0* __fastcall CelDataHashFind(D2CelDataHashStrc* pHash, const char* szName)
{
    if (!*szName)
        return 0;

    unsigned int nHash = SStrHash(szName, 1, 0);
    unsigned int nKey = ((((((nHash >> 8) ^ nHash) >> 8) ^ nHash) >> 8) ^ nHash) & 0x1FF;
    for (T00604AE0* pEntry = pHash->pBuckets[nKey]; pEntry; pEntry = pEntry->pNext)
    {
        if (!strcmp(szName, pEntry->szName))
            return pEntry;
    }
    return 0;
}

// 0x0060AF00
void __fastcall CelDataHashFreeAll(void* pMemPool, D2CelDataHashStrc* pHash)
{
    for (unsigned int i = 0; i < 0x200; i++)
    {
        T00604AE0* pEntry = pHash->pBuckets[i];
        while (pEntry)
        {
            T00604AE0* pNext = pEntry->pNext;
            CelDataHashFreeEntry(pHash, pEntry, pMemPool);
            pEntry = pNext;
        }
        D2_ASSERT(!pHash->nCheck[i], 0x5B);
    }
}

// 0x0060B010
T00604AE0* __fastcall CelDataHashAdd(void* pMemPool, D2CelDataHashStrc* pHash, int nValue, const char* szName)
{
    T00604AE0* pEntry = (T00604AE0*)FOG_AllocPool(pMemPool, sizeof(T00604AE0), ".\\SRC\\CelDataHash.cpp", 0x88, 0);
    pEntry->nValue = nValue;
    unsigned int nHash = SStrHash(szName, 1, 0);
    unsigned int nKey = ((nHash ^ (nHash >> 8)) ^ ((nHash ^ (nHash >> 8)) >> 16)) & 0x1FF;
    pEntry->pPrev = 0;
    pEntry->pNext = pHash->pBuckets[nKey];
    if (pEntry->pNext)
        pEntry->pNext->pPrev = pEntry;
    pEntry->nKey = nKey;
    strcpy(pEntry->szName, szName);
    pHash->pBuckets[nKey] = pEntry;
    return pEntry;
}

// 0x0060B0B0
void __fastcall CelDataHashRemove(void* pMemPool, D2CelDataHashStrc* pHash, T00604AE0* pEntry)
{
    D2_ASSERT(pEntry, 0xB2);
    if (pEntry->pPrev)
        pEntry->pPrev->pNext = pEntry->pNext;
    if (pEntry->pNext)
        pEntry->pNext->pPrev = pEntry->pPrev;
    if (pHash->pBuckets[pEntry->nKey] == pEntry)
        pHash->pBuckets[pEntry->nKey] = pEntry->pNext;
    FOG_FreePool(pMemPool, pEntry, ".\\SRC\\CelDataHash.cpp", 0x3A, 0);
}
