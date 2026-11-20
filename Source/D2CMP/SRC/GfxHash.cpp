#include "D2CMP.h"
#include "D2CmpTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2FindTileEntryStrc;
struct D2CmpBlockTableAStrc;
struct D2CmpBlockTableBStrc;
struct T00604AE0;
struct D2CelDataHashStrc;
struct D2CmpGfxKeyStrc;
struct D2CmpGfxHashEntryStrc;
struct D2CmpGfxHashStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend); // 0x006CC208
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend); // 0x006CC204
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection); // 0x006CC1FC

struct D2CmpBlockTableAStrc
{
    unsigned char data[0x1000];
};

struct D2CmpBlockTableBStrc
{
    unsigned char data[0x10000];
};

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

struct D2CmpGfxKeyStrc
{
    int unk0x00;
    unsigned int dwFlags;
    int nType;
    int nSubA;
    int unk0x10;
    int nSubB;
    int nKey1;
    int nKey2;
    int nKey3;
    int nKey4;
    int nKey5;
    const char* szName;
};


struct D2CmpGfxHashStrc
{
    char unk0x0000[0x8000];
    D2CmpGfxHashEntryStrc* pBuckets[0x2000];
};

unsigned int __fastcall sub_0060AB80_GetGfxKeyValue(D2CmpGfxKeyStrc* pKey, int* pAux, void* pCel); // 0x0060AB80

long gnTileLockRefCount_008F03E4; // 0x008F03E4

char gTileLock_008F03CC[0x18]; // 0x008F03CC

// 0x0060AAF0
void __fastcall sub_0060AAF0_ClearBlockTableB(D2CmpBlockTableBStrc* pTable)
{
    memset(pTable, 0, sizeof(D2CmpBlockTableBStrc));
}

// 0x0060AEE0
void __fastcall sub_0060AEE0_ClearBlockTableA(D2CmpBlockTableAStrc* pTable)
{
    memset(pTable, 0, sizeof(D2CmpBlockTableAStrc));
}

// 0x0060AF90
T00604AE0* __fastcall sub_0060AF90_CelDataHashFind(D2CelDataHashStrc* pHash, const char* szName)
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

// 0x0060CD30
void __cdecl sub_0060CD30_InitTileLock()
{
    if (InterlockedIncrement(&gnTileLockRefCount_008F03E4) == 1)
        InitializeCriticalSection(gTileLock_008F03CC);
}

// 0x0060CD50
void __cdecl sub_0060CD50_ReleaseTileLock()
{
    if (InterlockedDecrement(&gnTileLockRefCount_008F03E4) == 0)
        DeleteCriticalSection(gTileLock_008F03CC);
}

// 0x0060CDB0
D2FindTileEntryStrc** __cdecl sub_0060CDB0_AllocFindTilesTable()
{
    D2FindTileEntryStrc** ppBuckets = (D2FindTileEntryStrc**)FOG_Alloc(0x200, ".\\SRC\\FindTiles.cpp", 0x2A, 0);
    D2_ASSERT(ppBuckets, 0x2B);
    memset(ppBuckets, 0, 0x200);
    return ppBuckets;
}

// 0x0054FB30
void __stdcall sub_0054FB30_Nop()
{
}

// 0x0060AB70
void __stdcall sub_0060AB70_Nop()
{
}

// 0x0060AC50
void __stdcall sub_0060AC50_Nop()
{
}

// 0x0060AC60
static unsigned int sub_0060AC60_GfxHashIndex(D2CmpGfxKeyStrc* pKey, int* pAux, void* pCel, unsigned int* pValue)
{
    const unsigned int nValue = sub_0060AB80_GetGfxKeyValue(pKey, pAux, pCel);
    *pValue = nValue;
    unsigned int nHash;
    if ((pKey->nType == 6 && (pKey->dwFlags & 2)) || pKey->nType == 3 || pKey->nType == 4)
    {
        D2_ASSERT(pKey->szName, 0x2C);
        nHash = SStrHash(pKey->szName, 1, 0) + *pValue;
    }
    else
    {
        nHash = pKey->nKey5 + pKey->nKey4 + pKey->nKey3 + pKey->nKey2 + pKey->nKey1 + nValue;
    }
    const unsigned int nShift = nHash >> 8;
    return ((nShift ^ nHash) >> 16 ^ nShift ^ nHash) & 0x1FFF;
}

// 0x0060ACE0
D2CmpGfxHashEntryStrc* __fastcall sub_0060ACE0_GfxHashFind(D2CmpGfxHashStrc* pHash, D2CmpGfxKeyStrc* pKey, unsigned int* pValue, int* pAux, void* pCel)
{
    const unsigned int nIndex = sub_0060AC60_GfxHashIndex(pKey, pAux, pCel, pValue);
    const int nKey1 = pKey->nKey1;
    const int nKey2 = pKey->nKey2;
    const int nKey3 = pKey->nKey3;
    for (D2CmpGfxHashEntryStrc* pEntry = pHash->pBuckets[nIndex]; pEntry; pEntry = pEntry->pNext)
    {
        if (pKey->nType == 6 && (pKey->dwFlags & 2))
        {
            if (nKey1 == pEntry->nKey1 && nKey2 == pEntry->nKey2 && nKey3 == pEntry->nKey3 && pKey->nKey4 == pEntry->nKey4 && pKey->nKey5 == pEntry->nKey5
                && pKey->nSubB == pEntry->nSub && *pValue == pEntry->nValue)
            {
                return pEntry;
            }
        }
        else if (pKey->nType == 4 || pKey->nType == 3)
        {
            if (nKey1 == pEntry->nKey1 && nKey2 == pEntry->nKey2 && nKey3 == pEntry->nKey3 && pKey->nKey4 == pEntry->nKey4 && pKey->nKey5 == pEntry->nKey5
                && pKey->nSubA == pEntry->nSub && *pValue == pEntry->nValue)
            {
                return pEntry;
            }
        }
        else
        {
            if (nKey1 == pEntry->nKey1 && nKey2 == pEntry->nKey2 && nKey3 == pEntry->nKey3 && pKey->nKey4 == pEntry->nKey4 && pKey->nKey5 == pEntry->nKey5
                && *pValue == pEntry->nValue)
            {
                return pEntry;
            }
        }
    }
    return 0;
}

// 0x0060ADC0
D2CmpGfxHashEntryStrc* __fastcall sub_0060ADC0_GfxHashAdd(void* pMemPool, D2CmpGfxHashStrc* pHash, int nArg, D2CmpGfxKeyStrc* pKey, void* pCel)
{
    D2CmpGfxHashEntryStrc* pEntry = (D2CmpGfxHashEntryStrc*)FOG_AllocPool(pMemPool, sizeof(D2CmpGfxHashEntryStrc), ".\\SRC\\GfxHash.cpp", 0xEF, 0);
    pEntry->nArg = nArg;
    nArg = 0;
    const unsigned int nIndex = sub_0060AC60_GfxHashIndex(pKey, &nArg, pCel, &pEntry->nValue);
    pEntry->nKey1 = pKey->nKey1;
    pEntry->nKey2 = pKey->nKey2;
    pEntry->nKey3 = pKey->nKey3;
    pEntry->nKey4 = pKey->nKey4;
    pEntry->nKey5 = pKey->nKey5;
    if (pKey->nType == 6 && (pKey->dwFlags & 2))
    {
        pEntry->nSub = pKey->nSubB;
    }
    else if (pKey->nType == 4 || pKey->nType == 3)
    {
        pEntry->nSub = pKey->nSubA;
    }
    pEntry->pPrev = 0;
    pEntry->pNext = pHash->pBuckets[nIndex];
    if (pEntry->pNext)
    {
        pEntry->pNext->pPrev = pEntry;
    }
    pEntry->nIndex = nIndex;
    pHash->pBuckets[nIndex] = pEntry;
    return pEntry;
}
