typedef unsigned int size_t;

struct D2CmpPoolStrc
{
    unsigned char unk0x00[0x34];
};

struct D2CmpTileCacheStrc
{
    unsigned char unk0x00[0x2C];
    int bActive;
    unsigned char unk0x30[0x20];
};

struct D2TileLibraryEntryStrc
{
    unsigned char unk0x00[0x60];
};

struct D2TileLibraryHeaderStrc
{
    int dwVersion;
    int dwFlags;
    char szLibraryName[260];
    int nTiles;
    int dwTileStart_pFirst;
};

struct D2TSLinkStrc
{
    D2TSLinkStrc* pPrevLink;
    unsigned int nNext;
};

struct D2TSListStrc
{
    int nLinkOffset;
    D2TSLinkStrc tTerminator;

    void sub_00601E80_InitCopy(const D2TSListStrc& source);
};

extern D2CmpPoolStrc gCmpPool;                                                                              // 0x0088CAE0
int gbCmpPoolInitialized;                                                                                   // 0x0088CB14
int gnCmpPoolArg;                                                                                           // 0x0088CB18
extern D2CmpPoolStrc gCmpTilePool;                                                                          // 0x0088DB20
extern D2CmpTileCacheStrc gCmpTileCache;                                                                    // 0x0089DB60

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
void __fastcall sub_006093E0_PoolFreeAll(D2CmpPoolStrc* pPool);                                             // 0x006093E0
void __fastcall sub_00609020_PoolInit(D2CmpPoolStrc* pPool, void* pMemPool, int nArg, void (__fastcall* pfnFree)(void*), int nBlocks); // 0x00609020
void __fastcall sub_005FDE50(void* pEntry);                                            // 0x005FDE50
void __cdecl sub_006006B0_FreeTileRecords();                                                                // 0x006006B0
void __fastcall sub_005FFBE0_FreeTileCache(D2CmpTileCacheStrc* pCache);                                     // 0x005FFBE0
void __cdecl sub_0060CD50_ReleaseTileLock();                                                                // 0x0060CD50
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile);                                             // 0x00516E84
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85

// 0x005FDE10
void __stdcall sub_005FDE10_FreeCelPool(int bFree)
{
    if (gbCmpPoolInitialized)
    {
        if (bFree)
        {
            sub_006093E0_PoolFreeAll(&gCmpPool);
        }

        memset(&gCmpPool, 0, sizeof(gCmpPool));
        gnCmpPoolArg = 0;
    }

    sub_006006B0_FreeTileRecords();
}

// 0x005FDF80
int __fastcall sub_005FDF80_GetTileLibrarySize(const char* szFilePath)
{
    void* hFile;
    if (!ARCHIVE_OpenFile(0, szFilePath, &hFile, 0))
    {
        return 0;
    }

    D2TileLibraryHeaderStrc tHeader;
    ARCHIVE_ReadFileToBuffer(0, hFile, &tHeader, sizeof(tHeader));
    ARCHIVE_CloseFile(0, hFile);
    return tHeader.nTiles * sizeof(D2TileLibraryEntryStrc) + sizeof(tHeader);
}

// 0x005FE120
void __stdcall sub_005FE120_InitCelPool(void* pMemPool, int nArg)
{
    gnCmpPoolArg = nArg;
    memset(&gCmpPool, 0, sizeof(gCmpPool));
    sub_00609020_PoolInit(&gCmpPool, pMemPool, nArg, sub_005FDE50, 0x1000);
    gbCmpPoolInitialized = 1;
}

// 0x005FFE30
void __stdcall sub_005FFE30_FreeTileCache(int bFree)
{
    if (bFree && gCmpTileCache.bActive)
    {
        sub_005FFBE0_FreeTileCache(&gCmpTileCache);
    }

    memset(&gCmpTileCache, 0, sizeof(gCmpTileCache));

    if (bFree)
    {
        sub_006093E0_PoolFreeAll(&gCmpTilePool);
    }

    memset(&gCmpTilePool, 0, sizeof(gCmpTilePool));
    sub_0060CD50_ReleaseTileLock();
}

// 0x00601E80
void D2TSListStrc::sub_00601E80_InitCopy(const D2TSListStrc& source)
{
    nLinkOffset = source.nLinkOffset;
    tTerminator.pPrevLink = &tTerminator;
    tTerminator.nNext = ~(unsigned int)&tTerminator;
}
