#include "D2CMP.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TileRecordStrc;
struct D2CmpTileNodeStrc;
struct D2CmpTileStrc;
struct D2CmpTileListStrc;
struct D2CmpTileSubStrc;
struct D2CmpTileBlockStrc;
struct D2CmpTileLibraryStrc;
struct D2TileLibraryEntryStrc;
struct D2TileLibraryHeaderStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
extern const unsigned char gaDirection8To4_006E5DA0[]; // 0x006E5DA0
extern const unsigned char gaDirection16To8_006E5DA8[]; // 0x006E5DA8
extern const unsigned char gaDirection8To4Alt_006E5DB8[]; // 0x006E5DB8
extern const unsigned char gaDirection16To8Alt_006E5DC0[]; // 0x006E5DC0

struct D2TileRecordStrc
{
    int nFirst;
    int nSecond;
    int unk0x08;
    int unk0x0C;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2CmpTileNodeStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    void* pData;
    D2CmpTileNodeStrc* pNext;
};

struct D2CmpTileStrc
{
    char unk0x00[0x58];
    D2CmpTileNodeStrc* pNodes;
    D2CmpTileStrc* pNext;
};

struct D2CmpTileListStrc
{
    int unk0x00;
    int nId;
    int nCount;
    D2CmpTileStrc* pFirst;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

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
    int nSubBytes;
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

struct D2TileLibraryEntryStrc
{
    char unk0x00[0x50];
    void* pUnk0x50;
    void* pUnk0x54;
    char unk0x58[0x08];
};

struct D2TileLibraryHeaderStrc
{
    int dwVersion;
    int dwFlags;
    char szLibraryName[260];
    int nTiles;
    D2TileLibraryEntryStrc* pFirst;
};

// 0x00600CB0
int __stdcall sub_00600CB0_ConvertDirection(unsigned int nDirection, unsigned int nDirections, int nNewDirections, int bAlt)
{
    D2_ASSERT(nDirection < nDirections, 0x1A0);

    if (nDirections == 8)
    {
        if (nNewDirections == 4)
        {
            if (bAlt)
            {
                return gaDirection8To4Alt_006E5DB8[nDirection];
            }
            return gaDirection8To4_006E5DA0[nDirection];
        }
    }
    else if (nDirections == 16)
    {
        if (nNewDirections == 8)
        {
            if (bAlt)
            {
                return gaDirection16To8Alt_006E5DC0[nDirection];
            }
            return gaDirection16To8_006E5DA8[nDirection];
        }
    }

    return 0;
}

// 0x00605D20
void __stdcall sub_00605D20_BuildTintTables(unsigned char* pData)
{
    for (int j = 0; j < 12; ++j)
    {
        for (int i = 0; i < 256; ++i)
        {
            const int nValue = pData[4 * i];
            pData[0x6B727 + 256 * j + i] = sub_00605210_FindNearestColor(pData, 256,
                (unsigned char)(pData[0x6B603 + 3 * j] * nValue / 255),
                (unsigned char)(pData[0x6B604 + 3 * j] * nValue / 255),
                (unsigned char)(pData[0x6B605 + 3 * j] * nValue / 255));
        }
    }
}

// 0x00609620
D2TileRecordStrc* __stdcall TileListCreate(int nFirst, int nSecond)
{
    D2TileRecordStrc* pRecord = (D2TileRecordStrc*)FOG_Alloc(sizeof(D2TileRecordStrc), ".\\SRC\\Tilecmp.cpp", 0x6D, 0);
    D2_ASSERT(pRecord, 0x6E);
    memset(pRecord, 0, sizeof(D2TileRecordStrc));
    pRecord->nFirst = nFirst;
    pRecord->nSecond = nSecond;
    return pRecord;
}

#include "gen/data/Source/D2CMP/SRC/Tilecmp_00600CB0.inc"

// 0x00609500
static __forceinline void sub_00609500_ReleaseTileNode(D2CmpTileNodeStrc* pNode)
{
    D2_ASSERT(pNode, 0x31);
    if (pNode->pData)
    {
        FOG_Free(pNode->pData, ".\\SRC\\Tilecmp.cpp", 0x35, 0);
    }
    FOG_Free(pNode, ".\\SRC\\Tilecmp.cpp", 0x38, 0);
}

void __stdcall sub_M128_Emit_00609500(D2CmpTileNodeStrc* pNode)
{
    sub_00609500_ReleaseTileNode(pNode);
}

// 0x006095A0
static void sub_006095A0_FreeTile(D2CmpTileStrc* pTile)
{
    D2_ASSERT(pTile, 0x54);
    D2CmpTileNodeStrc* pNode = pTile->pNodes;
    while (pNode)
    {
        D2CmpTileNodeStrc* pNext = pNode->pNext;
        if (pNode->pData)
        {
            FOG_Free(pNode->pData, ".\\SRC\\Tilecmp.cpp", 0x35, 0);
        }
        FOG_Free(pNode, ".\\SRC\\Tilecmp.cpp", 0x38, 0);
        pNode = pNext;
    }
    FOG_Free(pTile, ".\\SRC\\Tilecmp.cpp", 0x60, 0);
}

// 0x00609670
void __stdcall sub_00609670_FreeTileList(D2CmpTileListStrc* pList)
{
    D2_ASSERT(pList, 0x80);
    D2CmpTileStrc* pTile = pList->pFirst;
    while (pTile)
    {
        D2CmpTileStrc* pNext = pTile->pNext;
        sub_006095A0_FreeTile(pTile);
        pTile = pNext;
    }
    FOG_Free(pList, ".\\SRC\\Tilecmp.cpp", 0x8C, 0);
}

// 0x00609FD0
static int sub_00609FD0_GetPackedSize(D2CmpTileLibraryStrc* pLibrary)
{
    D2_ASSERT(pLibrary, 0x293);
    int nSize = pLibrary->nBlocks * sizeof(D2CmpTileBlockStrc) + sizeof(D2CmpTileLibraryStrc);
    for (int i = 0; i < pLibrary->nBlocks; i++)
    {
        D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
        nSize += pBlock->nSubs * sizeof(D2CmpTileSubStrc);
        for (int j = 0; j < pBlock->nSubs; j++)
        {
            nSize += pBlock->pSubs[j].nSize;
        }
    }
    return nSize;
}

// 0x0060A050
static unsigned int sub_0060A050(unsigned char * pDstBuf, D2CmpTileBlockStrc * pTileSetEntry) {
    unsigned char* pBase = pDstBuf;
    unsigned int nNodeSize;
    int* pFixupPtr;
    unsigned int nCumSize = pTileSetEntry->nSubs * 0x14;
    memcpy(pDstBuf, pTileSetEntry->pSubs, nCumSize);
    pFixupPtr = (int*)pDstBuf;
    pDstBuf += nCumSize;
    int iNode = 0;
    if (pTileSetEntry->nSubs > 0) {
      D2CmpTileSubStrc* pDVar1;
      int nSubOffset = 0;
      pFixupPtr += 4;
      do {
        pDVar1 = (D2CmpTileSubStrc*)((char*)pTileSetEntry->pSubs + nSubOffset);
        memcpy(pDstBuf, (void*)pDVar1->pData, (unsigned int)pDVar1->nSize);
        *pFixupPtr = pDstBuf - pBase;
        nNodeSize = (unsigned int)pDVar1->nSize;
        nCumSize += nNodeSize;
        pDstBuf += nNodeSize;
        nSubOffset += 0x14;
        iNode++;
        pFixupPtr += 5;
      } while (iNode < pTileSetEntry->nSubs);

      return nCumSize;
    }

    return nCumSize;
}

// 0x0060A0F0
void __stdcall sub_0060A0F0_PackTileLibrary(D2CmpTileLibraryStrc* pLibrary, unsigned char** ppData, int* pnSize)
{
    D2_ASSERT(pLibrary, 0x2D9);
    D2_ASSERT(ppData, 0x2DA);
    D2_ASSERT(pnSize, 0x2DB);
    D2_ASSERT(pLibrary->nBlocks, 0x2DC);
    const int nSize = sub_00609FD0_GetPackedSize(pLibrary);
    D2_ASSERT(nSize, 0x2E0);
    unsigned char* pData = (unsigned char*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 0x2E3, 0);
    D2_ASSERT(pData, 0x2E4);
    memset(pData, 0, nSize);
    *ppData = pData;
    *pnSize = nSize;
    unsigned char* pBase = pData;
    unsigned int nHeaderSize = sizeof(D2CmpTileLibraryStrc);
    memcpy(pData, pLibrary, nHeaderSize);
    D2CmpTileLibraryStrc* pHeader = (D2CmpTileLibraryStrc*)pData;
    pData += sizeof(D2CmpTileLibraryStrc);
    const int nBlockBytes = pLibrary->nBlocks * sizeof(D2CmpTileBlockStrc);
    memcpy(pData, pLibrary->pBlocks, nBlockBytes);
    pHeader->pBlocks = (D2CmpTileBlockStrc*)(pData - pBase);
    D2CmpTileBlockStrc* pDstBlocks = (D2CmpTileBlockStrc*)pData;
    pData += nBlockBytes;
    for (int i = 0; i < pLibrary->nBlocks; i++)
    {
        D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
        pDstBlocks[i].pSubs = 0;
        const int nBytes = sub_0060A050(pData, pBlock);
        pDstBlocks[i].f_48 = pData - pBase;
        pDstBlocks[i].nSubBytes = nBytes;
        pData += nBytes;
    }
    pLibrary->dwFlags |= 2;
    pHeader->dwFlags |= 6;
}

// 0x0060A910
void __stdcall sub_0060A910_CopyTileLibrary(D2TileLibraryHeaderStrc* pSource, D2TileLibraryHeaderStrc** ppCopy, int* pnSize)
{
    D2_ASSERT(pSource, 1171);

    int nSize = sizeof(D2TileLibraryHeaderStrc) + pSource->nTiles * sizeof(D2TileLibraryEntryStrc);
    D2TileLibraryHeaderStrc* pCopy = (D2TileLibraryHeaderStrc*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 1178, 0);
    D2_ASSERT(pCopy, 1179);

    memset(pCopy, 0, nSize);
    memcpy(pCopy, pSource, nSize);
    D2TileLibraryEntryStrc* pEntries = (D2TileLibraryEntryStrc*)(pCopy + 1);
    pCopy->pFirst = pEntries;
    for (int i = 0; i < pCopy->nTiles; ++i)
    {
        pEntries[i].pUnk0x54 = 0;
        pEntries[i].pUnk0x50 = 0;
    }
    pCopy->dwFlags &= 4;

    *ppCopy = pCopy;
    *pnSize = nSize;
}
