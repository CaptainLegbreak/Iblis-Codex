#include "D2CMP.h"
#include "D2CmpTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CmpTileStrc;
struct D2CmpPoolEntryStrc;
struct D2LRUNodeStrc;
struct D2TileLibraryEntryStrc;
struct D2TileLibraryStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* D2FarProcFn)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn); // 0x006CC34C

struct D2CmpPoolEntryStrc
{
    int unk0x00;
    int unk0x04;
    D2CmpTileStrc* pTile;
};

typedef void (__fastcall* D2TileFreeCallbackFn)(D2CmpTileStrc* pTile);

struct D2LRUNodeStrc
{
    void* pData;
    unsigned int nSize;
};

struct D2TileLibraryEntryStrc
{
    char unk0x00[0x48];
    int nFileOffset;
    unsigned int nSize;
    int bCanLoad;
    void* pData;
    const char* szFilePath;
    D2LRUNodeStrc* pNode;
};

struct D2TileLibraryStrc
{
    char unk0x000[0x10C];
    int nTiles;
    D2TileLibraryEntryStrc* pTiles;
};

extern D2CmpPoolStrc gCmpPool; // 0x0088CAE0
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void __fastcall sub_00609380(D2CmpPoolStrc* pPool, D2LRUNodeStrc* pNode); // 0x00609380
D2LRUNodeStrc* __fastcall sub_00609420(D2CmpPoolStrc* pPool, unsigned int nSize, D2TileLibraryEntryStrc* pOwner); // 0x00609420
int __fastcall sub_00516F14_SetFilePointer(void* unused, void* file, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00516F14
void __stdcall sub_0060A4C0_TileEntryLoaded(D2TileLibraryEntryStrc* pEntry); // 0x0060A4C0

D2TileFreeCallbackFn gpfnTileFreeCallback_0088CB1C; // 0x0088CB1C

// 0x005FDE50
void __fastcall sub_005FDE50(void* pEntry)
{
    D2CmpTileStrc* pTile = ((D2CmpPoolEntryStrc*)pEntry)->pTile;
    if (gpfnTileFreeCallback_0088CB1C)
    {
        D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnTileFreeCallback_0088CB1C), 0xB4);
        gpfnTileFreeCallback_0088CB1C(pTile);
    }

    pTile->nCount = 0;
    pTile->pNext = 0;
}

// 0x005FDEA0
int __stdcall sub_005FDEA0(D2TileLibraryEntryStrc* pEntry, int a2, int a3)
{
    if (pEntry->pNode)
    {
        sub_00609380(&gCmpPool, pEntry->pNode);
        return 1;
    }

    if (!pEntry->bCanLoad)
    {
        return 0;
    }

    pEntry->pNode = sub_00609420(&gCmpPool, pEntry->nSize, pEntry);
    pEntry->pData = pEntry->pNode->pData;
    memset(pEntry->pData, 0, pEntry->nSize);

    void* hFile;
    if (!ARCHIVE_OpenFile(0, pEntry->szFilePath, &hFile, 0))
    {
        return 0;
    }

    sub_00516F14_SetFilePointer(0, hFile, pEntry->nFileOffset, 0, 0);
    ARCHIVE_ReadFileToBuffer(0, hFile, pEntry->pData, pEntry->nSize);
    ARCHIVE_CloseFile(0, hFile);
    sub_0060A4C0_TileEntryLoaded(pEntry);
    return 1;
}

// 0x005FE080
void __fastcall sub_005FE080_FreeTileLibraryBlocks(D2TileLibraryStrc* pLibrary)
{
    for (int i = 0; i < pLibrary->nTiles; ++i)
    {
        D2TileLibraryEntryStrc* pEntry = &pLibrary->pTiles[i];
        if (pEntry->pNode)
        {
            sub_006092D0_PoolFree(&gCmpPool, pEntry->pNode);
            pEntry->pData = 0;
            pEntry->pNode = 0;
        }
    }
}

// 0x005FE280
void __stdcall sub_005FE280_LoadCompressedDataFlag(int bAllowCompressed)
{
    SRegLoadValue("Diablo II", "CompressedData", 1, (unsigned long*)&gbCmpCompressedDataMode);
    if (!bAllowCompressed)
    {
        gbCmpCompressedDataMode = 0;
    }
}

#include "gen/data/Source/D2CMP/Unknown_005FDE50.inc"
