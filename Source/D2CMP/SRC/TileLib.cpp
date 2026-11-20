#include "D2CMP.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CmpTileStrc;
struct D2CmpTileProjectStrc;
struct D2CmpTileSubStrc;
struct D2CmpTileBlockStrc;
struct D2CmpTileLibraryStrc;
struct D2CmpGfxHashEntryStrc;
struct D2CmpGfxHashStrc;
struct T00604AE0;
struct D2CelDataHashStrc;
struct D2CmpFindTilesSubStrc;
struct D2CmpFindTilesNodeStrc;
struct D2CmpRGBStrc;
struct D2CmpRGBImageStrc;
struct D2CmpSubTileRecordStrc;
struct D2TileLibraryEntryStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
int __fastcall sub_0060D040_LookupTilesInProject(D2CmpTileProjectStrc* pProject, D2CmpTileStrc** ppTiles, int nMaxTiles, int nOrientation, int nMainIndex, int nSubIndex); // 0x0060D040
void* __stdcall sub_00606930_BuildTables(void* pSource); // 0x00606930

struct D2CmpTileSubStrc
{
    int unk0x00;
    int unk0x04;
    short unk0x08;
    unsigned short nSize;
    int unk0x0C;
    char* pData;
};

struct D2CmpTileBlockStrc
{
    char unk0x00[0x48];
    int f_48;
    int unk0x4C;
    int nSubs;
    D2CmpTileSubStrc* pSubs;
    char* pName;
    void* pExtra;
};

struct D2CmpTileLibraryStrc
{
    int dwVersion;
    unsigned int dwFlags;
    char szName[0x104];
    int nBlocks;
    D2CmpTileBlockStrc* pBlocks;
};

void __fastcall sub_005FE080_ReleaseBlockCaches(D2CmpTileLibraryStrc* pLibrary); // 0x005FE080

struct D2CmpGfxHashEntryStrc
{
    char unk0x00[0x28];
    D2CmpGfxHashEntryStrc* pPrev;
    D2CmpGfxHashEntryStrc* pNext;
};

struct D2CmpGfxHashStrc
{
    void sub_0060A9D0_Remove(void* pMemPool, D2CmpGfxHashEntryStrc* pEntry);                               // 0x0060A9D0
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

struct D2CmpFindTilesSubStrc
{
    int unk0x00;
    D2CmpFindTilesSubStrc* pNext;
};

struct D2CmpFindTilesNodeStrc
{
    int unk0x00[3];
    D2CmpFindTilesSubStrc* pSubs;
    D2CmpFindTilesNodeStrc* pNext;
};

struct D2CmpRGBImageStrc
{
    int unk0x00;
    unsigned int nWidth;
    unsigned int nHeight;
    char unk0x0C[0x14];
    D2CmpRGBStrc aPixels[1];
};

struct D2CmpSubTileRecordStrc
{
    int unk0x00;
    int unk0x04;
    short unk0x08;
    unsigned short nLength;
    int unk0x0C;
    void* ptData;
};

struct D2TileLibraryEntryStrc
{
    int nDirection;
    short nRoofHeight;
    unsigned short wFlags16;
    int nHeight;
    int nWidth;
    int unk0x10;
    int nOrientation;
    int f_18;
    int nSubIndex;
    int nRarity;
    char unk0x24[4];
    unsigned char aSubtileFlags[25];
    char unk0x41[0x17];
    int unk0x58;
};

// 0x00604AE0
int __stdcall TileLibraryGetTiles(D2CmpTileProjectStrc** ppProjects, int nOrientation, int nMainIndex, int nSubIndex, D2CmpTileStrc** ppTiles, int nMaxTiles)
{
    D2_ASSERT(ppProjects, 0x5D);
    int nFound = 0;
    int nLeft = nMaxTiles;
    for (int i = 0; i < 0x20; i++)
    {
        if (!ppProjects[i])
            break;
        int n = sub_0060D040_LookupTilesInProject(ppProjects[i], &ppTiles[nFound], nLeft, nOrientation, nMainIndex, nSubIndex);
        nLeft -= n;
        nFound += n;
        if (!nLeft)
            return nMaxTiles;
    }
    return nMaxTiles - nLeft;
}

// 0x006069F0
void* __stdcall CreateD2PaletteByteStream(void* pSource, int* pSize)
{
    *pSize = 0x6C327;
    return sub_00606930_BuildTables(pSource);
}

// 0x00609E90
void __stdcall TileProjectDestroy(D2CmpTileLibraryStrc* pLibrary, int bKeep)
{
    if (bKeep)
        return;
    D2_ASSERT(pLibrary, 0x25A);
    sub_005FE080_ReleaseBlockCaches(pLibrary);
    if (pLibrary->dwFlags & 4)
    {
        FOG_Free(pLibrary, ".\\SRC\\Tilecmp.cpp", 0x262, 0);
        return;
    }
    D2_ASSERT(!(pLibrary->dwFlags & 8), 0x267);
    for (int i = 0; i < pLibrary->nBlocks; i++)
    {
        D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
        for (int j = 0; j < pBlock->nSubs; j++)
        {
            D2CmpTileSubStrc* pSub = &pBlock->pSubs[j];
            if (pSub->pData)
                FOG_Free(pSub->pData, ".\\SRC\\Tilecmp.cpp", 0x274, 0);
            pSub->nSize = 0;
            pSub->pData = 0;
        }
        if (pBlock->pSubs)
            FOG_Free(pBlock->pSubs, ".\\SRC\\Tilecmp.cpp", 0x27B, 0);
        pBlock->pSubs = 0;
        pBlock->nSubs = 0;
    }
    FOG_Free(pLibrary->pBlocks, ".\\SRC\\Tilecmp.cpp", 0x281, 0);
    pLibrary->pBlocks = 0;
    pLibrary->nBlocks = 0;
    FOG_Free(pLibrary, ".\\SRC\\Tilecmp.cpp", 0x285, 0);
}

// 0x0060A290
void __stdcall TileProjectNormalize(D2CmpTileLibraryStrc* pLibrary, D2CmpTileLibraryStrc** ppLibrary, const char* szName)
{
    D2_ASSERT(pLibrary->dwVersion == 7, 0x348);
    if (pLibrary->dwFlags & 3)
    {
        pLibrary->pBlocks = (D2CmpTileBlockStrc*)((char*)pLibrary + (int)pLibrary->pBlocks);
        if (szName)
            strcpy(pLibrary->szName, szName);
        char* pData = (char*)pLibrary + sizeof(D2CmpTileLibraryStrc) + pLibrary->nBlocks * sizeof(D2CmpTileBlockStrc);
        for (int i = 0; i < pLibrary->nBlocks; i++)
        {
            D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
            pBlock->pName = pLibrary->szName;
            pBlock->pSubs = (D2CmpTileSubStrc*)((char*)pLibrary + pBlock->f_48);
            int nSize = pBlock->nSubs * sizeof(D2CmpTileSubStrc);
            for (int j = 0; j < pBlock->nSubs; j++)
            {
                D2CmpTileSubStrc* pSub = &pBlock->pSubs[j];
                pSub->pData += (int)pData;
                nSize += pSub->nSize;
            }
            pData += nSize;
        }
        pLibrary->dwFlags = (pLibrary->dwFlags & ~2) | 4;
        *ppLibrary = pLibrary;
    }
}

// 0x0060A390
void __stdcall sub_0060A390(D2CmpTileLibraryStrc* pLibrary, D2CmpTileLibraryStrc** ppLibrary, const char* szName)
{
    D2_ASSERT(pLibrary->dwVersion == 7, 0x37F);
    if (pLibrary->dwFlags & 2)
    {
        pLibrary->pBlocks = (D2CmpTileBlockStrc*)((char*)pLibrary + (int)pLibrary->pBlocks);
        strcpy(pLibrary->szName, szName);
        for (int i = 0; i < pLibrary->nBlocks; i++)
        {
            D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
            pBlock->pName = pLibrary->szName;
            D2_ASSERT(!pBlock->pSubs, 0x3A2);
            D2_ASSERT(!pBlock->pExtra, 0x3A3);
        }
        pLibrary->dwFlags = (pLibrary->dwFlags & ~2) | 4;
        *ppLibrary = pLibrary;
    }
}

// 0x0060A4C0
void __stdcall sub_0060A4C0_RelocateBlockSubs(D2CmpTileBlockStrc* pBlock)
{
    D2_ASSERT(pBlock, 0x3C9);
    char* pBase = (char*)pBlock->pSubs;
    for (int i = 0; i < pBlock->nSubs; i++)
    {
        D2CmpTileSubStrc* pSub = &pBlock->pSubs[i];
        pSub->pData += (int)pBase;
    }
}

// 0x0060AB10
void __fastcall sub_0060AB10_GfxHashRemove(void* pMemPool, D2CmpGfxHashStrc* pHash, D2CmpGfxHashEntryStrc* pEntry)
{
    D2_ASSERT(pEntry, 0x141);
    if (pEntry->pPrev)
        pEntry->pPrev->pNext = pEntry->pNext;
    if (pEntry->pNext)
        pEntry->pNext->pPrev = pEntry->pPrev;
    pHash->sub_0060A9D0_Remove(pMemPool, pEntry);
}

// 0x0060B010
T00604AE0* __fastcall sub_0060B010_CelDataHashAdd(void* pMemPool, D2CelDataHashStrc* pHash, int nValue, const char* szName)
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
void __fastcall sub_0060B0B0_CelDataHashRemove(void* pMemPool, D2CelDataHashStrc* pHash, T00604AE0* pEntry)
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

// 0x0060CE00
void __fastcall sub_0060CE00_FreeFindTilesTable(D2CmpFindTilesNodeStrc** ppBuckets)
{
    if (!ppBuckets)
        return;
    for (int i = 0; i < 0x80; i++)
    {
        D2CmpFindTilesNodeStrc* pNode = ppBuckets[i];
        while (pNode)
        {
            D2CmpFindTilesSubStrc* pSub = pNode->pSubs;
            D2CmpFindTilesNodeStrc* pNext = pNode->pNext;
            while (pSub)
            {
                D2CmpFindTilesSubStrc* pSubNext = pSub->pNext;
                FOG_Free(pSub, ".\\SRC\\FindTiles.cpp", 0x4C, 0);
                pSub = pSubNext;
            }
            pNode->pSubs = 0;
            FOG_Free(pNode, ".\\SRC\\FindTiles.cpp", 0x50, 0);
            pNode = pNext;
        }
        ppBuckets[i] = 0;
    }
    FOG_Free(ppBuckets, ".\\SRC\\FindTiles.cpp", 0x57, 0);
}

// 0x0060D110
void __fastcall sub_0060D110_ForEachOtherColor(D2CmpRGBImageStrc* pImage, D2CmpColorCallback pfnColor, unsigned int nKey)
{
    unsigned int nPacked = (((unsigned char)(nKey >> 16) << 8) + (unsigned char)(nKey >> 8) << 8) + (unsigned char)nKey;
    D2CmpRGBStrc* pPixel = pImage->aPixels;
    for (unsigned int i = 0; i < pImage->nWidth * pImage->nHeight; i++)
    {
        unsigned int nColor = ((pPixel->b2 << 8) + pPixel->b1 << 8) + pPixel->b0;
        pPixel++;
        if (nColor != nPacked)
            pfnColor(nColor);
    }
}

// 0x0060D510
D2CmpSubTileRecordStrc* __fastcall sub_0060D510_CreateSubTileRecord(const void* pSrc, int bRaw)
{
    void* pData;
    int nSize;
    if (bRaw)
    {
        pData = FOG_Alloc(0xC00, szSubTileFile, 0x66, 0);
        memcpy(pData, pSrc, 0xC00);
        nSize = 0xC00;
    }
    else
    {
        int nLength;
        pData = sub_0060D430_Compress(pSrc, &nLength);
        nSize = nLength;
    }
    D2CmpSubTileRecordStrc* pRecord = (D2CmpSubTileRecordStrc*)FOG_Alloc(sizeof(D2CmpSubTileRecordStrc), szSubTileFile, 0x6E, 0);
    memset(pRecord, 0, sizeof(D2CmpSubTileRecordStrc));
    D2_ASSERT(nSize > 0xFFFF, 0x70);
    pRecord->ptData = pData;
    pRecord->nLength = (unsigned short)nSize;
    return pRecord;
}

// 0x00604B60
int __stdcall TileGetType(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 121); return hTile->nOrientation; }

// 0x00604B90
int __stdcall TileGetStyle(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 122); return pTile->f_18; }

// 0x00604BC0
int __stdcall TileGetFlags(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 123); return hTile->wFlags16; }

// 0x00604BF0
int __stdcall TileGetWidth(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 124); return hTile->nWidth; }

// 0x00604C20
int __stdcall TileGetRarity(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 125); return hTile->nRarity; }

// 0x00604C50
int __stdcall TileGetSequence(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 126); return hTile->nSubIndex; }

// 0x00604C80
int __stdcall TileGetTileLight(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 127); return hTile->nDirection; }

// 0x00604CB0
int __stdcall TileGetTotalHeight(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 128); return hTile->nHeight; }

// 0x00604CE0
unsigned char* __stdcall sub_00604CE0(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 129); return pTile->aSubtileFlags; }

// 0x00604D10
int __stdcall TileGetHeightToBottom(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 130); return hTile->unk0x10; }

// 0x00604D40
short __stdcall TileGetRoofHeight(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 131); return hTile->nRoofHeight; }

// 0x00604D80
int __stdcall TileGetFilename(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 132); return hTile->unk0x58; }
