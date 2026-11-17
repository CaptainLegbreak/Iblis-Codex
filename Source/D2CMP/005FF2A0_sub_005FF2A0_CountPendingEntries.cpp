extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue);                                   // 0x00517ABB

struct D2CmpPoolStrc;

extern D2CmpPoolStrc gCmpPool;                                                                              // 0x0088CAE0
extern void* gpfnTileFreeCallback_0088CB1C;                                                                 // 0x0088CB1C

void __fastcall sub_006093E0_PoolFreeAll(D2CmpPoolStrc* pPool);                                             // 0x006093E0

struct D2SpriteCacheNodeStrc;

struct D2SpriteCacheStrc
{
    void* pMemPool;
    unsigned int nMaxSize;
    unsigned int nTotalSize;
    unsigned int nCount;
    D2SpriteCacheNodeStrc* pNodes;
    D2SpriteCacheNodeStrc* pHeadA;
    D2SpriteCacheNodeStrc* pTailA;
    D2SpriteCacheNodeStrc* pHeadB;
    D2SpriteCacheNodeStrc* pTailB;
    D2SpriteCacheNodeStrc* f_24;
    D2SpriteCacheNodeStrc* f_28;
    int nArg;
    D2CriticalSectionStrc tLock;
    unsigned int nHits;
    unsigned int f_4C;
};

extern D2SpriteCacheStrc gCmpTileCache;                                                                     // 0x0089DB60

int __fastcall sub_005FF4A0_SpriteCachePurge(D2SpriteCacheStrc* pCache, int nArg, int bForce);              // 0x005FF4A0

// 0x005FE000
void __fastcall sub_005FE000_StoreTileFreeCallback(void* pfnCallback)
{
    gpfnTileFreeCallback_0088CB1C = pfnCallback;
}

// 0x005FE070
void __cdecl sub_005FE070()
{
    sub_006093E0_PoolFreeAll(&gCmpPool);
}

// 0x005FEE10
unsigned int __cdecl sub_005FEE10_GetTileCacheTotalSize()
{
    EnterCriticalSection(&gCmpTileCache.tLock);
    const unsigned int nTotalSize = gCmpTileCache.nTotalSize;
    LeaveCriticalSection(&gCmpTileCache.tLock);
    return nTotalSize;
}

struct T00481720;

struct D2CmpCacheKeyStrc
{
    int nKeyA;
    int nKeyB;
    int nKeyC;
    char unk0x0C[0x14];
    unsigned char nFlags;
    char unk0x21[0x8F];
    T00481720* pAsyncData;
};

struct D2CmpCacheListEntryStrc
{
    D2CmpCacheKeyStrc* pKey;
    char unk0x04[0x10];
    D2CmpCacheListEntryStrc* pNext;
};

D2CmpCacheListEntryStrc* gpCmpCacheEntries;                                                                 // 0x0089DB7C

int __fastcall sub_0040A7F0_AsyncDataCheck(T00481720* pAsyncData);                                    // 0x0040A7F0
void __fastcall sub_0040AB00_FreeAsyncData(T00481720* pAsync);                                        // 0x0040AB00

// 0x005FF2A0
int __cdecl sub_005FF2A0_CountPendingEntries()
{
    int nCount = 0;
    for (D2CmpCacheListEntryStrc* pEntry = gpCmpCacheEntries; pEntry; pEntry = pEntry->pNext)
    {
        D2CmpCacheKeyStrc* pKey = pEntry->pKey;
        if (pKey && !(pKey->nFlags & 1))
        {
            D2_ASSERT(pKey->pAsyncData, 0xB5B);
            if (!sub_0040A7F0_AsyncDataCheck(pKey->pAsyncData))
            {
                nCount += 1;
            }
        }
    }

    return nCount;
}

// 0x005FF3A0
void __cdecl sub_005FF3A0()
{
    for (D2CmpCacheListEntryStrc* pEntry = gpCmpCacheEntries; pEntry; pEntry = pEntry->pNext)
    {
        D2CmpCacheKeyStrc* pKey = pEntry->pKey;
        if (pKey)
        {
            T00481720* pAsyncData = pKey->pAsyncData;
            if (pAsyncData && !sub_0040A7F0_AsyncDataCheck(pAsyncData))
            {
                sub_0040AB00_FreeAsyncData(pAsyncData);
                pKey->pAsyncData = 0;
            }
        }
    }
}

// 0x005FFBE0
void __fastcall sub_005FFBE0_FreeTileCache(D2SpriteCacheStrc* pCache)
{
    while (pCache->nCount)
    {
        if (!sub_005FF4A0_SpriteCachePurge(pCache, 0, 1))
        {
            break;
        }
    }

    if (pCache->pNodes)
    {
        sub_0040B480(pCache->pMemPool, pCache->pNodes, ".\\SRC\\SpriteCache.cpp", 0x921, 0);
        pCache->pNodes = 0;
    }

    DeleteCriticalSection(&pCache->tLock);
    pCache->nArg = 0;
}

extern int gaDirectionIndex64_006E45A0[][64];                                                               // 0x006E45A0

// 0x00600C90
int __stdcall sub_00600C90_GetDirectionIndex64(int nDirection, unsigned int nDirections)
{
    return gaDirectionIndex64_006E45A0[sub_00517ABB_BitScanForward1(nDirections)][nDirection];
}

// 0x00600D30
int __stdcall sub_00600D30_CanConvertDirections(int nDirections, int nNewDirections)
{
    if (nDirections == 4)
    {
        return 0;
    }

    if (nDirections == 8 && nNewDirections == 16)
    {
        return 1;
    }

    return 0;
}

struct D2CelStrc
{
    int bFlip;
    int nWidth;
    int nHeight;
    int nXOffset;
    int nYOffset;
    int unk0x14;
    void* pBlockPixelData;
};

struct D2CelFileStrc
{
    int nVersion;
    unsigned int dwFlags;
};

struct D2CmpCelContextStrc
{
    unsigned int nFrame;
    char unk0x04[0x30];
    D2CelFileStrc* pCelFile;
    char unk0x38[0x04];
    D2CelStrc* pCel;
};

void __fastcall sub_00608D60_DrawCelShadowLines(D2CelStrc* pCel, unsigned char* pDst, int nX, int nClipLeft, int nClipRight, int nPitch, int nSkip, int nLines, int nTable, int nColor); // 0x00608D60

// 0x00601730
void __stdcall sub_00601730_DrawCelShadow(D2CmpCelContextStrc* pContext, int nX, int nY, int nClipLeft, int nClipRight, unsigned char* pBuffer, int nHeightLimit, int nPitch, int nTable, int nColor)
{
    D2CelFileStrc* pCelFile = pContext->pCelFile;
    if (pCelFile)
    {
        D2_ASSERT(pCelFile->nVersion == 6, 0x50D);
        D2_ASSERT(!(pCelFile->dwFlags & 4), 0x50E);
    }

    D2_ASSERT(pBuffer, 0x511);
    D2CelStrc* pCel = pContext->pCel;
    D2_ASSERT(pCel, 0x514);

    nX += pCel->nXOffset + pCel->nYOffset / 2;
    nY += pCel->nYOffset / 2;
    int nLines = (unsigned int)pCel->nHeight / 2;
    int nSkip = 0;
    if (nY - pCel->nHeight / 2 < 0)
    {
        nLines = nY + 1;
    }

    if (nLines <= 0)
    {
        return;
    }

    if (nY >= nHeightLimit)
    {
        nSkip = nY - nHeightLimit + 1;
        nLines -= nSkip;
        if (nLines <= 0)
        {
            return;
        }
        nY = nHeightLimit - 1;
    }

    const int nStart = nX - nSkip;
    sub_00608D60_DrawCelShadowLines(pCel, pBuffer + nY * nPitch + nStart, nStart, nClipLeft, nClipRight, nPitch, nSkip, nLines, nTable, nColor);
}

// 0x006018F0
int __stdcall sub_006018F0(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x589);

    return pCel->nHeight;
}

// 0x00601920
int __stdcall sub_00601920(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x597);

    return pCel->nXOffset;
}

// 0x00601950
int __stdcall sub_00601950(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x5A5);

    return pCel->nYOffset;
}

// 0x00606D10
const char* __fastcall sub_00606D10_SkipCelLines(const char* pData, int nLines)
{
    if (!nLines)
    {
        return pData;
    }

    for (;;)
    {
        const char nRun = *pData++;
        if (nRun < 0)
        {
            if (!(nRun & 0x7F) && !--nLines)
            {
                break;
            }
        }
        else
        {
            pData += nRun;
        }
    }

    return pData;
}

struct D2TileListHeaderStrc
{
    int nUnk0x00;
    int nUnk0x04;
    int nUnk0x08;
    int f_C;
    int f_10;
};

struct D2CmpTileStrc
{
    char unk0x00[0x60];
};

// 0x006094B0
D2TileListHeaderStrc* __cdecl sub_006094B0_AllocTileListHeader()
{
    D2TileListHeaderStrc* pHeader = (D2TileListHeaderStrc*)FOG_Alloc(sizeof(D2TileListHeaderStrc), ".\\SRC\\Tilecmp.cpp", 0x23, 0);
    D2_ASSERT(pHeader, 0x24);
    memset(pHeader, 0, sizeof(D2TileListHeaderStrc));
    return pHeader;
}

// 0x00609550
D2CmpTileStrc* __cdecl sub_00609550_AllocTile()
{
    D2CmpTileStrc* pTile = (D2CmpTileStrc*)FOG_Alloc(sizeof(D2CmpTileStrc), ".\\SRC\\Tilecmp.cpp", 0x45, 0);
    D2_ASSERT(pTile, 0x46);
    memset(pTile, 0, sizeof(D2CmpTileStrc));
    return pTile;
}

struct D2TileLibraryHashStrc;

struct D2CmpTileBlockStrc
{
    char unk0x00[0x60];
};

struct D2CmpTileLibraryStrc
{
    int nVersion;
    unsigned int dwFlags;
    char szName[0x104];
    int nBlocks;
    D2CmpTileBlockStrc* pBlocks;
};

D2TileLibraryHashStrc* __cdecl sub_0060CDB0_AllocTileHash();                                                // 0x0060CDB0
void __fastcall sub_0060CFA0_AddTileToTable(D2TileLibraryHashStrc* pHash, D2CmpTileBlockStrc* pTile);       // 0x0060CFA0

// 0x0060A440
D2TileLibraryHashStrc* __fastcall sub_0060A440_CreateTileHashBlock(D2CmpTileLibraryStrc* pLibrary)
{
    D2TileLibraryHashStrc* pHash = sub_0060CDB0_AllocTileHash();
    D2_ASSERT(pHash, 0x3B9);
    D2_ASSERT(pLibrary, 0x3BA);

    for (int i = 0; i < pLibrary->nBlocks; ++i)
    {
        sub_0060CFA0_AddTileToTable(pHash, &pLibrary->pBlocks[i]);
    }

    return pHash;
}

#include "gen/data/Source/D2CMP/005FF2A0_sub_005FF2A0_CountPendingEntries.inc"
