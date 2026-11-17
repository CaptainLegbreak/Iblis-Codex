struct D2GrTexInfoStrc
{
    int nSmallLodLog2;
    int nLargeLodLog2;
    int nAspectRatioLog2;
};

struct D2GlideTileStrc
{
    int unk0x00;
    short nCacheIndex;
    short unk0x06;
    int unk0x08[2];
    unsigned char* pData;
};

struct D2GlideTileCacheEntryStrc
{
    int unk0x00;
    int f_4;
    D2GlideTileStrc* pTile;
    int unk0x0C[2];
};

struct D2GlideTileCacheStrc
{
    int unk0x00;
    int nCount;
    int unk0x08[5];
    D2GlideTileCacheEntryStrc* pEntries;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __fastcall sub_00509460_GlideSelectTmuState(int nTmu);                                                  // 0x00509460
void __fastcall sub_0050F0F0_TileCacheTouch(D2GlideTileCacheStrc* pCache, int nIndex);                      // 0x0050F0F0
short __fastcall sub_0050F2B0_TileCacheAdd(D2GlideTileCacheStrc* pCache);                                   // 0x0050F2B0

extern D2GrTexInfoStrc gGlideTileTexInfo_0072F6A8;                                                          // 0x0072F6A8
extern void (__stdcall* gpfGlideTexDownloadMipMap_0087EAB8)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EAB8
D2GlideTileCacheStrc gGlideTileCache_0087EB48;                                                              // 0x0087EB48
extern void (__stdcall* gpfGlideTexSource_0087EB98)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98
int gnGlideTileTmu_00880BF8;                                                                                // 0x00880BF8
extern unsigned char* gpGlideTileDecodeBuffer_00880BFC;                                                     // 0x00880BFC

static void sub_0050F910_DecodeTileRuns(const unsigned char* pSrc, unsigned char* pDst)
{
    memset(pDst, 0, 0x400);

    int nRows = 0x20;
    unsigned char* p = pDst;
    unsigned char* pRow = pDst;
    do
    {
        const unsigned char nGap = *pSrc++;
        unsigned char nCount = *pSrc++;
        if (!nGap && !nCount)
        {
            --nRows;
            pRow += 0x20;
            p = pRow;
        }
        else
        {
            p += nGap;
            while (nCount--)
            {
                *p++ = *pSrc++;
            }
        }
    }
    while (nRows);
}

// 0x0050FBD0
void __fastcall sub_0050FBD0_GlideBindTileTexture(D2GlideTileStrc* pTile)
{
    D2_ASSERT(pTile->nCacheIndex >= 0, 0x105);

    int nTexAddress;
    if (pTile->nCacheIndex == 0)
    {
        sub_0050F910_DecodeTileRuns(pTile->pData, gpGlideTileDecodeBuffer_00880BFC);
        pTile->nCacheIndex = sub_0050F2B0_TileCacheAdd(&gGlideTileCache_0087EB48);
        const int nEntry = pTile->nCacheIndex - 1;
        D2_ASSERT(nEntry >= 0, 0x112);
        D2_ASSERT(nEntry < gGlideTileCache_0087EB48.nCount, 0x113);
        gGlideTileCache_0087EB48.pEntries[pTile->nCacheIndex - 1].pTile = pTile;
        nTexAddress = gGlideTileCache_0087EB48.pEntries[pTile->nCacheIndex - 1].f_4;
        gpfGlideTexDownloadMipMap_0087EAB8(gnGlideTileTmu_00880BF8, nTexAddress, 3, &gGlideTileTexInfo_0072F6A8);
    }
    else
    {
        sub_0050F0F0_TileCacheTouch(&gGlideTileCache_0087EB48, pTile->nCacheIndex);
        nTexAddress = gGlideTileCache_0087EB48.pEntries[pTile->nCacheIndex - 1].f_4;
    }

    gpfGlideTexSource_0087EB98(gnGlideTileTmu_00880BF8, nTexAddress, 3, &gGlideTileTexInfo_0072F6A8);
    sub_00509460_GlideSelectTmuState(gnGlideTileTmu_00880BF8);
}

#include "gen/data/Source/D2Win/0050FBD0_sub_0050FBD0_GlideBindTileTexture.inc"
