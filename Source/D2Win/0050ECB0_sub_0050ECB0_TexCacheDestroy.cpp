extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2GlideTexCacheEntryStrc;

struct D2GlideTexCacheStrc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideTexCacheEntryStrc* pHead;
    D2GlideTexCacheEntryStrc* pTail;
    D2GlideTexCacheEntryStrc* f_14;
    D2GlideTexCacheEntryStrc* f_18;
    D2GlideTexCacheEntryStrc* pEntries;
};

struct D2TileLibraryEntryStrc
{
    char unk0x00[0x42];
    short nCacheIndex;
};

struct D2GlideFloorCacheEntryStrc
{
    int unk0x00;
    int f_4;
    D2TileLibraryEntryStrc* pTile;
    D2GlideFloorCacheEntryStrc* pNext;
    D2GlideFloorCacheEntryStrc* pPrev;
};

struct D2GlideFloorCacheStrc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideFloorCacheEntryStrc* pHead;
    D2GlideFloorCacheEntryStrc* pTail;
    D2GlideFloorCacheEntryStrc* f_14;
    D2GlideFloorCacheEntryStrc* f_18;
    D2GlideFloorCacheEntryStrc* pEntries;
};

struct D2GrTexInfoStrc
{
    int nSmallLodLog2;
    int nLargeLodLog2;
    int nAspectRatioLog2;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall sub_00509460_GlideSelectTmuState(int nTmu);                                                 // 0x00509460
void __fastcall sub_0050EC40_TexCacheEvict(D2GlideTexCacheStrc* pCache);                                    // 0x0050EC40
void __fastcall sub_0050F670_FloorCacheTouch(D2GlideFloorCacheStrc* pCache, int nIndex);                    // 0x0050F670
void __fastcall sub_0050F6D0_FloorCacheEvict(D2GlideFloorCacheStrc* pCache);                                // 0x0050F6D0
short __fastcall sub_0050F820_FloorCacheAdd(D2GlideFloorCacheStrc* pCache);                                 // 0x0050F820
void __stdcall sub_0050F980_DecodeTileBlocks(D2TileLibraryEntryStrc* pTile, unsigned char* pDst);           // 0x0050F980
int __stdcall sub_005FDEA0(D2TileLibraryEntryStrc* pTile, int a2, int a3);                                  // 0x005FDEA0

extern D2GrTexInfoStrc gGlideFloorTexInfo_0072F6BC;                                                        // 0x0072F6BC
extern void (__stdcall* gpfGlideTexDownloadMipMap_0087EAB8)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EAB8
D2GlideFloorCacheStrc gGlideFloorCache_0087EB68;                                                            // 0x0087EB68
extern void (__stdcall* gpfGlideTexSource_0087EB98)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98
extern int gnGlideTileTmu_00880BF8;                                                                         // 0x00880BF8
extern unsigned char* gpGlideFloorDecodeBuffer_00880C00;                                                    // 0x00880C00

// 0x0050ECB0
void __fastcall sub_0050ECB0_TexCacheDestroy(D2GlideTexCacheStrc* pCache, int bFlush)
{
    if (bFlush)
    {
        while (pCache->nUsed)
            sub_0050EC40_TexCacheEvict(pCache);
    }
    if (pCache->pEntries)
    {
        FOG_Free(pCache->pEntries, ".\\Src\\glTextureCache.cpp", 0x7F, 0);
        pCache->pEntries = 0;
    }
    memset(pCache, 0, sizeof(*pCache));
}

// 0x0050F7C0
void __fastcall sub_0050F7C0_FloorCacheDestroy(D2GlideFloorCacheStrc* pCache, int bFlush)
{
    if (bFlush)
    {
        while (pCache->nUsed)
            sub_0050F6D0_FloorCacheEvict(pCache);
    }
    if (pCache->pEntries)
    {
        FOG_Free(pCache->pEntries, ".\\Src\\glFloorCache.cpp", 0x74, 0);
        pCache->pEntries = 0;
    }
    memset(pCache, 0, sizeof(*pCache));
}

// 0x0050FAD0
int __fastcall sub_0050FAD0_GlideBindFloorTexture(D2TileLibraryEntryStrc* pTile)
{
    int bResult = 0;
    if (sub_005FDEA0(pTile, 1, 0))
    {
        D2_ASSERT(pTile->nCacheIndex >= 0, 0xD8);
        int nTexAddress;
        if (pTile->nCacheIndex == 0)
        {
            sub_0050F980_DecodeTileBlocks(pTile, gpGlideFloorDecodeBuffer_00880C00);
            pTile->nCacheIndex = sub_0050F820_FloorCacheAdd(&gGlideFloorCache_0087EB68);
            const int nEntry = pTile->nCacheIndex - 1;
            D2_ASSERT(nEntry >= 0, 0xE5);
            D2_ASSERT(nEntry < gGlideFloorCache_0087EB68.nCount, 0xE6);
            gGlideFloorCache_0087EB68.pEntries[pTile->nCacheIndex - 1].pTile = pTile;
            nTexAddress = gGlideFloorCache_0087EB68.pEntries[pTile->nCacheIndex - 1].f_4;
            gpfGlideTexDownloadMipMap_0087EAB8(gnGlideTileTmu_00880BF8, nTexAddress, 3, &gGlideFloorTexInfo_0072F6BC);
        }
        else
        {
            sub_0050F670_FloorCacheTouch(&gGlideFloorCache_0087EB68, pTile->nCacheIndex);
            nTexAddress = gGlideFloorCache_0087EB68.pEntries[pTile->nCacheIndex - 1].f_4;
        }
        gpfGlideTexSource_0087EB98(gnGlideTileTmu_00880BF8, nTexAddress, 3, &gGlideFloorTexInfo_0072F6BC);
        sub_00509460_GlideSelectTmuState(gnGlideTileTmu_00880BF8);
        bResult = 1;
    }
    return bResult;
}

#include "gen/data/Source/D2Win/0050ECB0_sub_0050ECB0_TexCacheDestroy.inc"
