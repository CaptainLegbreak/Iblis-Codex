typedef unsigned int size_t;

struct D2CmpPoolStrc;

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

extern D2CmpPoolStrc gCmpPool;                                                                              // 0x0088CAE0
extern int gbCmpCompressedDataMode;                                                                         // 0x00741EFC

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void __fastcall sub_006092D0_PoolFree(D2CmpPoolStrc* pPool, void* pMemory);                                 // 0x006092D0
void __fastcall sub_00609380(D2CmpPoolStrc* pPool, D2LRUNodeStrc* pNode);                                 // 0x00609380
D2LRUNodeStrc* __fastcall sub_00609420(D2CmpPoolStrc* pPool, unsigned int nSize, D2TileLibraryEntryStrc* pOwner); // 0x00609420
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
void __fastcall sub_00516F14_ArchiveSetFilePointer(void* hArchive, void* hFile, int nOffset, int a4, int a5); // 0x00516F14
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile);                                             // 0x00516E84
void __stdcall sub_0060A4C0_TileEntryLoaded(D2TileLibraryEntryStrc* pEntry);                               // 0x0060A4C0

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

    sub_00516F14_ArchiveSetFilePointer(0, hFile, pEntry->nFileOffset, 0, 0);
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

#include "gen/data/Source/D2Game/005FDEA0_sub_005FDEA0.inc"
