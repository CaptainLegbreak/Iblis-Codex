#include "D2Glide.h"
#include "D2DrlgMaps.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2GlideTexCacheEntryStrc* __fastcall sub_0050EAE0_TexCacheUnlink(D2GlideTexCacheStrc* pCache, int nIndex); // 0x0050EAE0

void __fastcall sub_00509460_GlideSelectTmuState(int nTmu); // 0x00509460
void __fastcall sub_0050EC40_TexCacheEvict(D2GlideTexCacheStrc* pCache); // 0x0050EC40
void __fastcall sub_0050F670_FloorCacheTouch(D2GlideFloorCacheStrc* pCache, int nIndex); // 0x0050F670
void __fastcall sub_0050F6D0_FloorCacheEvict(D2GlideFloorCacheStrc* pCache); // 0x0050F6D0
short __fastcall sub_0050F820_FloorCacheAdd(D2GlideFloorCacheStrc* pCache); // 0x0050F820
void __stdcall sub_0050F980_DecodeTileBlocks(D2TileLibraryEntryStrc* pTile, unsigned char* pDst); // 0x0050F980
extern D2GrTexInfoStrc gGlideFloorTexInfo_0072F6BC; // 0x0072F6BC
extern void (__stdcall* gpfGlideTexDownloadMipMap_0087EAB8)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EAB8
extern void (__stdcall* gpfGlideTexSource_0087EB98)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98
extern int gnGlideTileTmu_00880BF8; // 0x00880BF8
extern unsigned char* gpGlideFloorDecodeBuffer_00880C00; // 0x00880C00

int gdwGlobal_0087EFB8; // 0x0087EFB8

// 0x0050E890
int __fastcall sub_0050E890_TexCacheInit(D2GlideTexCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nBlockSize)
{
    const int nCount = (nEnd - nStart) / nBlockSize;
    pCache->nBlockSize = nBlockSize;
    pCache->nCount = nCount;
    pCache->pEntries = (D2GlideTexCacheEntryStrc*)FOG_Alloc(nCount * sizeof(D2GlideTexCacheEntryStrc), ".\\Src\\glTextureCache.cpp", 45, 0);
    memset(pCache->pEntries, 0, nCount * sizeof(D2GlideTexCacheEntryStrc));

    for (int i = 0; i <= pCache->nCount - 1; ++i)
    {
        D2GlideTexCacheEntryStrc* pEntry = &pCache->pEntries[i];
        pEntry->nId = i;
        if (i < pCache->nCount - 1)
        {
            pEntry->pNext = &pCache->pEntries[i + 1];
        }
        if (i > 0)
        {
            pEntry->pPrev = &pCache->pEntries[i - 1];
        }
        pEntry->nAddress = nStart + i * nBlockSize;
    }

    pCache->nUsed = 0;
    pCache->pHead = 0;
    pCache->pTail = 0;
    pCache->pFreeHead = pCache->pEntries;
    pCache->pFreeTail = &pCache->pEntries[pCache->nCount - 1];

    if (!gdwGlobal_0087EFB8)
    {
        for (int i = 1; i < pCache->nCount - 1; ++i)
        {
            const unsigned int nEntryAddress = pCache->pEntries[i].nAddress;
            if (nEntryAddress < 0x200000 && pCache->nBlockSize + nEntryAddress > 0x200000)
            {
                pCache->pEntries[i - 1].pNext = &pCache->pEntries[i + 1];
                pCache->pEntries[i + 1].pPrev = &pCache->pEntries[i - 1];
                pCache->pEntries[i].pPrev = 0;
                pCache->pEntries[i].pNext = 0;
                ++pCache->nUsed;
                break;
            }
        }

        if (pCache->pEntries[pCache->nCount - 1].nAddress < 0x200000 && pCache->nBlockSize + pCache->pEntries[pCache->nCount - 1].nAddress > 0x200000)
        {
            pCache->pEntries[pCache->nCount - 1].pPrev = 0;
            pCache->pEntries[pCache->nCount - 2].pNext = 0;
            pCache->pFreeTail = &pCache->pEntries[pCache->nCount - 2];
            --pCache->nCount;
        }
    }

    return pCache->nCount * nBlockSize + nStart;
}

// 0x0050EA40
static __declspec(noinline) void sub_0050EA40_TexCacheAppendUsed(D2GlideTexCacheEntryStrc* pEntry, D2GlideTexCacheStrc* pCache)
{
    if (!pCache->pHead)
    {
        pCache->pHead = pEntry;
        pCache->pTail = pEntry;
        return;
    }

    pCache->pTail->pNext = pEntry;
    pEntry->pPrev = pCache->pTail;
    pCache->pTail = pEntry;
}

// 0x0050EBE0
void __fastcall sub_0050EBE0_TexCacheTouch(D2GlideTexCacheStrc* pCache, int nId)
{
    if (pCache->nUsed > 1)
    {
        D2_ASSERT(nId, 0xDE);
        D2_ASSERT(nId <= pCache->nCount, 0xDF);
        D2_ASSERT(nId >= 1, 0xE0);
        sub_0050EA40_TexCacheAppendUsed(sub_0050EAE0_TexCacheUnlink(pCache, nId - 1), pCache);
    }
}

// 0x0050EA60
static void sub_0050EA60_TexCacheAppendFree(D2GlideTexCacheEntryStrc* pEntry, D2GlideTexCacheStrc* pCache)
{
    if (!pCache->pFreeHead)
    {
        pCache->pFreeHead = pEntry;
        pCache->pFreeTail = pEntry;
        return;
    }
    pCache->pFreeTail->pNext = pEntry;
    pEntry->pPrev = pCache->pFreeTail;
    pCache->pFreeTail = pEntry;
}

// 0x0050EA80
static D2GlideTexCacheEntryStrc* sub_0050EA80_TexCachePopUsed(D2GlideTexCacheStrc* pCache)
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

// 0x0050EAB0
static D2GlideTexCacheEntryStrc* sub_0050EAB0_TexCachePopFree(D2GlideTexCacheStrc* pCache)
{
    D2GlideTexCacheEntryStrc* pEntry = pCache->pFreeHead;
    if (!pEntry)
        return 0;
    pCache->pFreeHead = pEntry->pNext;
    if (pCache->pFreeHead)
        pCache->pFreeHead->pPrev = 0;
    else
        pCache->pFreeTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050EF60
static void sub_0050EF60_TileCacheAppendFree(D2GlideTileCacheEntryStrc* pEntry, D2GlideTileCacheStrc* pCache)
{
    if (!pCache->pFreeHead)
    {
        pCache->pFreeHead = pEntry;
        pCache->pFreeTail = pEntry;
        return;
    }
    pCache->pFreeTail->pNext = pEntry;
    pEntry->pPrev = pCache->pFreeTail;
    pCache->pFreeTail = pEntry;
}

// 0x0050EFB0
static D2GlideTileCacheEntryStrc* sub_0050EFB0_TileCachePopFree(D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pEntry = pCache->pFreeHead;
    if (!pEntry)
        return 0;
    pCache->pFreeHead = pEntry->pNext;
    if (pCache->pFreeHead)
        pCache->pFreeHead->pPrev = 0;
    else
        pCache->pFreeTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

void __fastcall sub_M116_Emit_0050EA60(D2GlideTexCacheStrc* pTex, D2GlideTileCacheStrc* pTile)
{
    sub_0050EA60_TexCacheAppendFree(sub_0050EA80_TexCachePopUsed(pTex), pTex);
    sub_0050EA60_TexCacheAppendFree(sub_0050EAB0_TexCachePopFree(pTex), pTex);
    sub_0050EF60_TileCacheAppendFree(sub_0050EFB0_TileCachePopFree(pTile), pTile);
}

// 0x0050EB60
static int sub_0050EB60_ListTakeFree(D2GlideTexCacheStrc* pList)
{
    if (pList->nUsed == pList->nCount)
    {
        return 0;
    }

    D2GlideTexCacheEntryStrc* pNode = pList->pFreeHead;
    if (pNode)
    {
        pList->pFreeHead = pNode->pNext;
        if (pList->pFreeHead)
        {
            pList->pFreeHead->pPrev = 0;
        }
        else
        {
            pList->pFreeTail = 0;
        }
        pNode->pNext = 0;
        pNode->pPrev = 0;
        if (!pList->pHead)
        {
            pList->nUsed += 1;
            pList->pHead = pNode;
            pList->pTail = pNode;
            return pNode->nId + 1;
        }
    }
    else
    {
        D2_ASSERT(pNode, 0xC1);
    }

    pList->pTail->pNext = pNode;
    pNode->pPrev = pList->pTail;
    pList->nUsed += 1;
    pList->pTail = pNode;
    return pNode->nId + 1;
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

void __fastcall sub_0050EC40_TexCacheEvict(D2GlideTexCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideTexCacheEntryStrc* pEntry = sub_N19_TexPopHead(pCache);
    if (pEntry)
    {
        if (pEntry->pOwner)
        {
            pEntry->pOwner[pEntry->nOwnerIndex].nCache = 0;
            pEntry->pOwner[pEntry->nOwnerIndex].nId = 0;
            pEntry->pOwner = 0;
        }
        if (!pCache->pFreeHead)
        {
            pCache->pFreeHead = pEntry;
            pCache->pFreeTail = pEntry;
        }
        else
        {
            pCache->pFreeTail->pNext = pEntry;
            pEntry->pPrev = pCache->pFreeTail;
            pCache->pFreeTail = pEntry;
        }
    }
    --pCache->nUsed;
}

// build: context sub_0050ED10_ListRefill
void __fastcall sub_0050ED10_ListRefill(D2GlideTexCacheStrc* pList)
{
    while (!sub_0050EB60_ListTakeFree(pList))
    {
        sub_0050EC40_TexCacheEvict(pList);
    }
}

D2GlideFloorCacheStrc gGlideFloorCache_0087EB68; // 0x0087EB68

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
            nTexAddress = gGlideFloorCache_0087EB68.pEntries[pTile->nCacheIndex - 1].nAddress;
            gpfGlideTexDownloadMipMap_0087EAB8(gnGlideTileTmu_00880BF8, nTexAddress, 3, &gGlideFloorTexInfo_0072F6BC);
        }
        else
        {
            sub_0050F670_FloorCacheTouch(&gGlideFloorCache_0087EB68, pTile->nCacheIndex);
            nTexAddress = gGlideFloorCache_0087EB68.pEntries[pTile->nCacheIndex - 1].nAddress;
        }
        gpfGlideTexSource_0087EB98(gnGlideTileTmu_00880BF8, nTexAddress, 3, &gGlideFloorTexInfo_0072F6BC);
        sub_00509460_GlideSelectTmuState(gnGlideTileTmu_00880BF8);
        bResult = 1;
    }
    return bResult;
}

#include "gen/data/Source/D2Glide/Src/glTextureCache.inc"
