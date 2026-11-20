#include "D2CmpCache.h"
#include "D2CmpTiles.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CmpGfxHashStrc;
struct D2CmpGfxHashEntryStrc;
struct D2CelDataHashStrc;
struct T00604AE0;

struct D2CmpPoolStrc
{
    void* pMemPool;
    unsigned int nTotal;
    unsigned int nHits;
    unsigned char unk0x0C[0x28];
};

struct D2CmpBlockTableAStrc
{
    unsigned char data[0x1000];
};

struct D2SpriteKeyStrc
{
    int nKeyA;
    int nKeyB;
    int nKeyC;
};

struct D2SpriteFreeNodeStrc
{
    char unk0x00[0x20];
    D2SpriteKeyStrc* pKey;
};

struct D2TilePoolEntryStrc
{
    char unk0x00[0x08];
    T00604AE0* pCelData;
};

struct D2CelDataViewStrc
{
    char unk0x00[0x24];
    int nRef;
};

extern D2CmpPoolStrc gCmpPool;                                                                              // 0x0088CAE0
extern "C" { int gnValue_0088CB0C; }                                                                        // 0x0088CB0C
extern "C" { int gnValue_0088CB10; }                                                                        // 0x0088CB10
static int gnCmpPoolArg_0088CB18;                                                                           // 0x0088CB18
void (__fastcall* gpfnCmpFreeCallback_0089DB5C)(int nKeyA, int nKeyC, int nKeyB);                           // 0x0089DB5C
extern D2SpriteCacheStrc gCmpTileCache;                                                                     // 0x0089DB60
extern D2CmpPoolStrc gCmpTilePool;                                                                          // 0x0088DB20
D2CmpBlockTableAStrc gCmpBlockTableA;                                                                       // 0x0088CB20
extern D2CmpBlockTableBStrc gCmpBlockTableB;                                                                // 0x0088DB58
void __fastcall sub_0060AB10_GfxHashRemove(void* pMemPool, D2CmpGfxHashStrc* pHash, D2CmpGfxHashEntryStrc* pEntry); // 0x0060AB10
void __fastcall sub_0060B0B0_CelDataHashRemove(void* pMemPool, D2CelDataHashStrc* pHash, T00604AE0* pEntry); // 0x0060B0B0

// 0x005FE010
void __stdcall D2CMPGetTileCacheHits(int* pnArg, int* pnCountB, int* pnCountA, int* pnHitPercent)
{
    *pnArg = gnCmpPoolArg_0088CB18;
    *pnCountA = gnValue_0088CB10;
    *pnCountB = gnValue_0088CB0C;
    if (gCmpPool.nTotal)
    {
        *pnHitPercent = gCmpPool.nHits * 100 / gCmpPool.nTotal;
    }
    else
    {
        *pnHitPercent = -1;
    }
}

// 0x005FE170
void __fastcall sub_005FE170_SpriteCacheFreeCallback(void* pNode)
{
    D2SpriteFreeNodeStrc* pFreeNode = (D2SpriteFreeNodeStrc*)pNode;
    if (gpfnCmpFreeCallback_0089DB5C)
    {
        D2SpriteKeyStrc* pKey = pFreeNode->pKey;
        D2_ASSERT(pKey, 0xB5);
        gpfnCmpFreeCallback_0089DB5C(pKey->nKeyA, pKey->nKeyC, pKey->nKeyB);
    }
    sub_0060AB10_GfxHashRemove(gCmpTileCache.pMemPool, (D2CmpGfxHashStrc*)&gCmpBlockTableB, (D2CmpGfxHashEntryStrc*)pNode);
}

// 0x005FE1D0
void __fastcall sub_005FE1D0_FreeTilePoolEntry(void* pEntry)
{
    D2CelDataViewStrc* pCelData = (D2CelDataViewStrc*)((D2TilePoolEntryStrc*)pEntry)->pCelData;
    pCelData->nRef = 0;
    sub_0060B0B0_CelDataHashRemove(gCmpTilePool.pMemPool, (D2CelDataHashStrc*)&gCmpBlockTableA, (T00604AE0*)pCelData);
}
