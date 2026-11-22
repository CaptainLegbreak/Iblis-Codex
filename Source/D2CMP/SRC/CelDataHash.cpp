#include "D2CMP.h"
#include "D2CmpTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
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
