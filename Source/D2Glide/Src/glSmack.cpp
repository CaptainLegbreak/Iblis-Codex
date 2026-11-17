#include "D2Glide.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GlideSmackStrc;
struct D2GlideFloorCacheEntryStrc;
struct D2GlideFloorCacheStrc;
struct D2GrTexInfoStrc;
struct D2GlideTexOwnerStrc;
struct D2GlideTexCacheEntryStrc;
struct D2GlideTexCacheStrc;
struct D2GlideTileCacheEntryStrc;
struct D2GlideTileCacheStrc;
struct T004F51E0;
struct D2RgbColorStrc;

struct T00508FE0
{
    float x;
    float y;
    unsigned int dwColor;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};

struct D2GlideSmackStrc
{
    void* f_0;
    unsigned char nType;
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
    int nFormat;
    unsigned char* pData;
};
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) void __stdcall SmackClose(void* hSmack); // 0x006CC608
D2GlideFloorCacheEntryStrc* __fastcall sub_0050F570_FloorCacheUnlink(D2GlideFloorCacheStrc* pCache, int nIndex); // 0x0050F570
extern D2GrTexInfoStrc gGlideTileTexInfo_0072F6A8; // 0x0072F6A8
extern D2GrTexInfoStrc gGlideFloorTexInfo_0072F6BC; // 0x0072F6BC
extern unsigned char* gpGlideSmackBufferB_00880B70; // 0x00880B70
extern unsigned char* gpGlideSmackBufferC_00880B74; // 0x00880B74
extern T00508FE0 gaGlideSmackVertices_00880B78[4]; // 0x00880B78
extern unsigned char* gpGlideSmackBuffer_00880BF0; // 0x00880BF0
extern unsigned char* gpGlideTileDecodeBuffer_00880BFC; // 0x00880BFC
extern unsigned char* gpGlideFloorDecodeBuffer_00880C00; // 0x00880C00
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2GlideTexOwnerStrc
{
    int unk0x00;
    int unk0x04;
};

struct D2GlideTexCacheEntryStrc
{
    int unk0x00[2];
    D2GlideTexOwnerStrc* pOwner;
    int nOwnerIndex;
    int unk0x10;
    D2GlideTexCacheEntryStrc* pNext;
    D2GlideTexCacheEntryStrc* pPrev;
};

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

struct D2GlideTileStrc
{
    int unk0x00;
    short nCacheIndex;
    short unk0x06;
};

struct D2GlideTileCacheEntryStrc
{
    int unk0x00;
    int f_4;
    D2GlideTileStrc* pTile;
    D2GlideTileCacheEntryStrc* pNext;
    D2GlideTileCacheEntryStrc* pPrev;
};

struct D2GlideTileCacheStrc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideTileCacheEntryStrc* pHead;
    D2GlideTileCacheEntryStrc* pTail;
    D2GlideTileCacheEntryStrc* f_14;
    D2GlideTileCacheEntryStrc* f_18;
    D2GlideTileCacheEntryStrc* pEntries;
};

struct T004F51E0
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

struct D2RgbColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840
extern "C" __declspec(dllimport) void* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604
extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(void* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C
int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped); // 0x0041B680
void __fastcall sub_0050E070_GlideSetSmackPalette(D2RgbColorStrc* pColors); // 0x0050E070
void __cdecl sub_0050E330_GlideRefresh(); // 0x0050E330
int __stdcall sub_006C6A80_DecodeImage(int nMode, void* pData, int nSize, T004F51E0* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth); // 0x006C6A80
extern int gbRenderPaused_007C9144; // 0x007C9144

// 0x0050DF10
void __cdecl sub_0050DF10_GlideSmackInit()
{
    gaGlideSmackVertices_00880B78[0].dwColor = 0xFFFFFFFF;
    gaGlideSmackVertices_00880B78[1].dwColor = 0xFFFFFFFF;
    gaGlideSmackVertices_00880B78[2].dwColor = 0xFFFFFFFF;
    gaGlideSmackVertices_00880B78[3].dwColor = 0xFFFFFFFF;
    gpGlideSmackBufferB_00880B70 = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glSmack.cpp", 0x47, 0);
    gpGlideSmackBufferC_00880B74 = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glSmack.cpp", 0x48, 0);
    gpGlideSmackBuffer_00880BF0 = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glSmack.cpp", 0x49, 0);
}

// 0x0050E040
void __fastcall sub_0050E040_GlideCloseSmacker(D2GlideSmackStrc* pRecord)
{
    if (pRecord->nType == 's' && pRecord->f_0)
    {
        SmackClose(pRecord->f_0);
        pRecord->f_0 = 0;
    }
    pRecord->nType = 0;
}

// 0x0050F750
void __fastcall sub_0050F750_FloorCacheRemove(D2GlideFloorCacheStrc* pCache, int nIndex)
{
    if (!pCache->nUsed)
        return;
    D2GlideFloorCacheEntryStrc* pEntry = sub_0050F570_FloorCacheUnlink(pCache, nIndex);
    if (pEntry)
    {
        D2TileLibraryEntryStrc* pTile = pEntry->pTile;
        D2_ASSERT(pTile, 0xF1);
        pTile->nCacheIndex = 0;
        pEntry->pTile = 0;
        if (!pCache->f_14)
        {
            pCache->f_14 = pEntry;
            pCache->f_18 = pEntry;
        }
        else
        {
            pCache->f_18->pNext = pEntry;
            pEntry->pPrev = pCache->f_18;
            pCache->f_18 = pEntry;
        }
    }
    --pCache->nUsed;
}

// 0x0050F870
void __cdecl sub_0050F870_GlideBlocksInit()
{
    gpGlideTileDecodeBuffer_00880BFC = (unsigned char*)FOG_Alloc(0x400, ".\\Src\\glBlocks.cpp", 0x33, 0);
    gpGlideFloorDecodeBuffer_00880C00 = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glBlocks.cpp", 0x34, 0);
    gGlideTileTexInfo_0072F6A8.pData = gpGlideTileDecodeBuffer_00880BFC;
    gGlideFloorTexInfo_0072F6BC.pData = gpGlideFloorDecodeBuffer_00880C00;
}

static D2GlideTexCacheEntryStrc* sub_N19_TexPopHead(D2GlideTexCacheStrc* pCache)
{
    D2GlideTexCacheEntryStrc* pEntry = pCache->pHead;
    if (!pEntry)
        return 0;
    pCache->pHead = pEntry->pNext;
    if (pCache->pHead)
        pCache->pHead->pPrev = 0;
    else
        pCache->pTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

static D2GlideTileCacheEntryStrc* sub_N19_TilePopHead(D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pEntry = pCache->pHead;
    if (!pEntry)
        return 0;
    pCache->pHead = pEntry->pNext;
    if (pCache->pHead)
        pCache->pHead->pPrev = 0;
    else
        pCache->pTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

static void sub_N19_TileEvict(D2GlideTileCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideTileCacheEntryStrc* pEntry = sub_N19_TilePopHead(pCache);
    if (pEntry)
    {
        D2GlideTileStrc* pTile = pEntry->pTile;
        if (pTile)
        {
            pTile->nCacheIndex = 0;
            pEntry->pTile = 0;
        }
        if (!pCache->f_14)
        {
            pCache->f_14 = pEntry;
            pCache->f_18 = pEntry;
        }
        else
        {
            pCache->f_18->pNext = pEntry;
            pEntry->pPrev = pCache->f_18;
            pCache->f_18 = pEntry;
        }
    }
    --pCache->nUsed;
}

static D2GlideFloorCacheEntryStrc* sub_N19_FloorPopHead(D2GlideFloorCacheStrc* pCache)
{
    D2GlideFloorCacheEntryStrc* pEntry = pCache->pHead;
    if (!pEntry)
        return 0;
    pCache->pHead = pEntry->pNext;
    if (pCache->pHead)
        pCache->pHead->pPrev = 0;
    else
        pCache->pTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050E030
void __cdecl sub_0050E030_GlideNoOp()
{
}

// 0x0050EAE0
D2GlideTexCacheEntryStrc* __fastcall sub_0050EAE0_TexCacheUnlink(D2GlideTexCacheStrc* pCache, int nIndex)
{
    D2GlideTexCacheEntryStrc* pNode = pCache->pHead;
    if (!pNode)
        return 0;
    D2GlideTexCacheEntryStrc* pEntry = &pCache->pEntries[nIndex];
    if (pEntry == pNode)
    {
        pCache->pHead = pNode->pNext;
        if (pCache->pHead)
            pCache->pHead->pPrev = 0;
        else
            pCache->pTail = 0;
        pNode->pNext = 0;
        pNode->pPrev = 0;
        return pNode;
    }
    pNode = pCache->pTail;
    if (pEntry == pNode)
    {
        pNode = pNode->pPrev;
        pCache->pTail = pNode;
        pNode->pNext = 0;
    }
    else
    {
        pNode = pEntry->pPrev;
        pNode->pNext = pEntry->pNext;
        pNode = pEntry->pNext;
        pNode->pPrev = pEntry->pPrev;
    }
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050EC40
void __fastcall sub_0050EC40_TexCacheEvict(D2GlideTexCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideTexCacheEntryStrc* pEntry = sub_N19_TexPopHead(pCache);
    if (pEntry)
    {
        if (pEntry->pOwner)
        {
            pEntry->pOwner[pEntry->nOwnerIndex].unk0x00 = 0;
            pEntry->pOwner[pEntry->nOwnerIndex].unk0x04 = 0;
            pEntry->pOwner = 0;
        }
        if (!pCache->f_14)
        {
            pCache->f_14 = pEntry;
            pCache->f_18 = pEntry;
        }
        else
        {
            pCache->f_18->pNext = pEntry;
            pEntry->pPrev = pCache->f_18;
            pCache->f_18 = pEntry;
        }
    }
    --pCache->nUsed;
}

// 0x0050F210
void __fastcall sub_0050F210_TileCacheDestroy(D2GlideTileCacheStrc* pCache, int bFlush)
{
    if (bFlush)
    {
        while (pCache->nUsed)
            sub_N19_TileEvict(pCache);
    }
    if (pCache->pEntries)
    {
        FOG_Free(pCache->pEntries, ".\\Src\\glSubtileCache.cpp", 0x74, 0);
        pCache->pEntries = 0;
    }
    memset(pCache, 0, sizeof(*pCache));
}

// 0x0050F570
D2GlideFloorCacheEntryStrc* __fastcall sub_0050F570_FloorCacheUnlink(D2GlideFloorCacheStrc* pCache, int nIndex)
{
    D2GlideFloorCacheEntryStrc* pNode = pCache->pHead;
    if (!pNode)
        return 0;
    D2GlideFloorCacheEntryStrc* pEntry = &pCache->pEntries[nIndex];
    if (pEntry == pNode)
    {
        pCache->pHead = pNode->pNext;
        if (pCache->pHead)
            pCache->pHead->pPrev = 0;
        else
            pCache->pTail = 0;
        pNode->pNext = 0;
        pNode->pPrev = 0;
        return pNode;
    }
    pNode = pCache->pTail;
    if (pEntry == pNode)
    {
        pNode = pNode->pPrev;
        pCache->pTail = pNode;
        pNode->pNext = 0;
    }
    else
    {
        pNode = pEntry->pPrev;
        pNode->pNext = pEntry->pNext;
        pNode = pEntry->pNext;
        pNode->pPrev = pEntry->pPrev;
    }
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050F6D0
void __fastcall sub_0050F6D0_FloorCacheEvict(D2GlideFloorCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideFloorCacheEntryStrc* pEntry = sub_N19_FloorPopHead(pCache);
    if (pEntry)
    {
        D2TileLibraryEntryStrc* pTile = pEntry->pTile;
        D2_ASSERT(pTile, 0xD3);
        pTile->nCacheIndex = 0;
        pEntry->pTile = 0;
        if (!pCache->f_14)
        {
            pCache->f_14 = pEntry;
            pCache->f_18 = pEntry;
        }
        else
        {
            pCache->f_18->pNext = pEntry;
            pEntry->pPrev = pCache->f_18;
            pCache->f_18 = pEntry;
        }
    }
    --pCache->nUsed;
}

unsigned char* gpGlideSmackBuffer_00880BF0; // 0x00880BF0

// 0x0050E5D0
void __fastcall sub_0050E5D0_GlideDecodeSmacker(const char* szFile, D2GlideSmackStrc* pSmack, unsigned char nType)
{
    D2_ASSERT(gpGlideSmackBuffer_00880BF0, 142);
    memset(gpGlideSmackBuffer_00880BF0, 0, 0x8000);
    memset(gpGlideSmackBufferB_00880B70, 0, 0x8000);
    memset(gpGlideSmackBufferC_00880B74, 0, 0x8000);
    if (!gbRenderPaused_007C9144)
    {
        sub_0050E330_GlideRefresh();
    }

    pSmack->nType = nType;
    switch (nType)
    {
    case 's':
        if (pSmack->f_0)
        {
            return;
        }
        pSmack->f_0 = SmackOpen(szFile, 0xFE000, -1);
        if (!pSmack->f_0)
        {
            break;
        }
        SmackToBuffer(pSmack->f_0, 0, 0, 0x200, 0x40, gpGlideSmackBuffer_00880BF0, 0);
        return;

    case 'p':
    {
        void* pBuffer = 0;
        int nSize = 0;
        if (!SFileLoadFileEx(0, szFile, &pBuffer, &nSize, 0, 3, 0) || !pBuffer)
        {
            break;
        }

        T004F51E0 aPalette[256];
        int nWidth;
        int nHeight;
        int nDepth;
        const int bDecoded = sub_006C6A80_DecodeImage(2, pBuffer, nSize, aPalette, gpGlideSmackBuffer_00880BF0, 0x6DB0, &nWidth, &nHeight, &nDepth);
        SMemFree(pBuffer, ".\\Src\\glSmack.cpp", 219, 0);
        if (!bDecoded || nWidth != 468 || nHeight != 60 || nDepth != 8)
        {
            break;
        }

        D2RgbColorStrc aColors[256];
        for (int i = 0; i < 256; ++i)
        {
            aColors[i].nRed = aPalette[i].peRed;
            aColors[i].nGreen = aPalette[i].peGreen;
            aColors[i].nBlue = aPalette[i].peBlue;
        }

        for (int y = 59; y > 0; --y)
        {
            memmove(&gpGlideSmackBuffer_00880BF0[y * 0x200], &gpGlideSmackBuffer_00880BF0[y * nWidth], nWidth);
        }

        sub_0050E070_GlideSetSmackPalette(aColors);
        sub_0050E330_GlideRefresh();
        return;
    }

    default:
        return;
    }

    if (pSmack->nType == 's' && pSmack->f_0)
    {
        SmackClose(pSmack->f_0);
        pSmack->f_0 = 0;
    }
    pSmack->nType = 0;
}
