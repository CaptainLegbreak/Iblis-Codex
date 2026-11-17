#include "D2CMP.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2CMP_BITCOUNT_BX(x) ((x) - (((x) >> 1) & 0x77777777) - (((x) >> 2) & 0x33333333) - (((x) >> 3) & 0x11111111))
#define D2CMP_BITCOUNT(x) (((D2CMP_BITCOUNT_BX(x) + (D2CMP_BITCOUNT_BX(x) >> 4)) & 0x0F0F0F0F) % 255)

struct D2UnitStrc;
struct D2SpriteCacheNodeStrc;
struct D2TileLibraryHeaderStrc;
struct D2CriticalSectionStrc;
struct D2SpriteCacheStrc;
struct D2CmpCacheKeyStrc;
struct D2CmpCacheListEntryStrc;
struct D2CelStrc;
struct D2CelFileStrc;
struct D2CmpCelContextStrc;
struct D2TileListHeaderStrc;
struct D2CmpTileStrc;
struct D2CmpTileBlockStrc;
struct D2CmpTileLibraryStrc;
struct D2CmpBlockTableAStrc;
struct D2CmpBlockTableBStrc;
struct D2CmpValueObjStrc;
struct D2SpriteCacheLockStrc;
struct D2SpriteFileStrc;
struct D2SpriteEntryStrc;
struct D2SpriteLoadRequestStrc;
struct T004013C0;
struct D2CelBlockStrc;

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue); // 0x00517ABB

struct D2CmpPoolStrc
{
    unsigned char unk0x00[0x34];
};

extern D2CmpPoolStrc gCmpPool; // 0x0088CAE0
extern void* gpfnTileFreeCallback_0088CB1C; // 0x0088CB1C

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

extern D2SpriteCacheStrc gCmpTileCache; // 0x0089DB60
int __fastcall sub_005FF4A0_SpriteCachePurge(D2SpriteCacheStrc* pCache, int nArg, int bForce); // 0x005FF4A0

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

extern D2CmpCacheListEntryStrc* gpCmpCacheEntries; // 0x0089DB7C
void __fastcall sub_0040AB00_FreeAsyncData(T00481720* pAsync); // 0x0040AB00

struct D2CelStrc
{
    int bFlip;
    int nWidth;
    int nHeight;
    int nXOffset;
    int nYOffset;
    unsigned int nDataSize;
    D2CelBlockStrc* pBlockPixelData;
    unsigned int nLength;
};

struct D2CelFileStrc
{
    int nVersion;
    unsigned int dwFlags;
    int nFormat;
    int nTermination;
    int nDirections;
    int nCelsPerDirection;
    D2CelStrc* pCels[1];
};

struct D2CmpCelContextStrc
{
    unsigned int nFrame;
    char unk0x04[0x30];
    D2CelFileStrc* pCelFile;
    char unk0x38[0x04];
    D2CelStrc* pCel;
    unsigned int nDirection;
};

void __fastcall sub_00608D60_DrawCelShadowLines(D2CelStrc* pCel, unsigned char* pDst, int nX, int nClipLeft, int nClipRight, int nPitch, int nSkip, int nLines, int nTable, int nColor); // 0x00608D60

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
void __fastcall sub_0060CFA0_AddTileToTable(D2TileLibraryHashStrc* pHash, D2CmpTileBlockStrc* pTile); // 0x0060CFA0

struct D2CmpBlockTableAStrc
{
    unsigned char data[0x1000];
    void sub_0060B130_Destroy();                                                                            // 0x0060B130
};

struct D2CmpBlockTableBStrc
{
    unsigned char data[0x10000];
    void sub_0060AB70_Destroy();                                                                            // 0x0060AB70
};

struct D2CmpValueObjStrc
{
    char unk0x00[0x2C];
    int nValue;
};

extern D2CmpBlockTableAStrc gCmpBlockTableA; // 0x0088CB20
extern D2CmpBlockTableBStrc gCmpBlockTableB; // 0x0088DB58

struct D2SpriteCacheNodeStrc
{
    void* pData;
    unsigned int nSize;
    unsigned int nKey;
    unsigned int dwFlags;
    unsigned int dwTick;
    D2SpriteCacheNodeStrc* pNext;
    D2SpriteCacheNodeStrc* pPrev;
};

struct D2SpriteCacheLockStrc
{
    char data[0x18];
};

typedef unsigned int size_t;

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2SpriteFileStrc
{
    unsigned char nFlags;
    char unk0x01[0x9F];
    char pData[4];
};

struct D2SpriteEntryStrc
{
    unsigned char nFlags;
    char unk0x01[0x93];
    D2SpriteCacheNodeStrc* pNode;
};

struct D2SpriteLoadRequestStrc
{
    int unk0x00;
    D2SpriteFileStrc* pFile;
    D2SpriteEntryStrc* f_8;
    int nArg0C;
    int nArg10;
    int nResult;
    int nSize;
};

int __fastcall sub_0060BFF0_LoadSpriteData(void* hArg, void* pMemPool, int nArg, D2SpriteFileStrc* pFile, D2SpriteEntryStrc* pEntry, int nArg0C, int nArg10, int* pSize, char* pData); // 0x0060BFF0
void __fastcall sub_005FF630_ResizeCacheEntry(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int nDelta, int nArg); // 0x005FF630

struct T004013C0
{
    char unk0x00[0x0C];
    unsigned int nTotalMemory;
};

extern D2CmpPoolStrc gCmpTilePool; // 0x0088DB20
extern int gnCmpTilePoolBlocks; // 0x00741EF8
void __cdecl sub_0060CD30_InitTileLock(); // 0x0060CD30
T004013C0* __cdecl sub_00407360_GetSystemInfo(); // 0x00407360
void __fastcall sub_0060AEE0_ClearBlockTableA(D2CmpBlockTableAStrc* pTable); // 0x0060AEE0
void __fastcall sub_0060AAF0_ClearBlockTableB(D2CmpBlockTableBStrc* pTable); // 0x0060AAF0
void __fastcall sub_005FE1D0_FreeTilePoolEntry(void* pEntry); // 0x005FE1D0
void __fastcall sub_005FFBE0_FreeTileCache(D2SpriteCacheStrc* pCache); // 0x005FFBE0
void __fastcall sub_005FEE90_SpriteCacheInit(D2SpriteCacheStrc* pCache, void* pMemPool, unsigned int nMaxSize, int nArg); // 0x005FEE90
void __fastcall sub_005FE170_SpriteCacheFreeCallback(void* pNode); // 0x005FE170
extern int gaDirectionIndex64A[8][64]; // 0x006E4DA0
extern int gaDirectionIndex64B[8][64]; // 0x006E55A0

struct D2CelBlockStrc
{
    char unk0x00[0x28];
    unsigned char* pPixels;
};

void __fastcall sub_0060D110_CelOp(D2CelStrc* pCel, int nArg, int nTermination); // 0x0060D110

typedef void(__fastcall* CELFILECELLOPFN)(D2CelStrc* pCel, int nArg);

extern CELFILECELLOPFN gpfnCelFileCellOp[]; // 0x006E3698

typedef void(__fastcall* CELDRAWFN)(D2CelStrc* pCel, unsigned char* pDst, int nX, int nArg4, int nArg5, int nPitch, int nSkipRows, int nRows, int nArg9, int nArg10, int nArg13);

extern CELDRAWFN gpfnCelDraw[]; // 0x006E3688

typedef void(__fastcall* PixelDataFreeCallback)(void* pData);

void __stdcall sub_00600790_LoadTileLibrary(D2TileLibraryHeaderStrc** ppLibrary, const char* szFilePath); // 0x00600790

int gdwGlobal_0089DB64; // 0x0089DB64

int gdwGlobal_0088DB28; // 0x0088DB28

int gdwGlobal_0088DB24; // 0x0088DB24

// 0x005B0CC0
void __stdcall sub_005B0CC0(int nUnused1)
{
}

// 0x005B72A0
void __stdcall sub_005B72A0(int nUnused1)
{
}

// 0x005B8740
void __stdcall sub_005B8740(int nUnused1)
{
}

// 0x005C2FE0
int __cdecl sub_005C2FE0()
{
    return 43;
}

// 0x005DD280
int __fastcall sub_005DD280(D2UnitStrc* pArg)
{
    return UNITS_GetCurrentLifePercentage(pArg);
}

// 0x005E5270
int __stdcall sub_005E5270(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x005EDC40
void __stdcall sub_005EDC40(int nUnused1)
{
}

// 0x005EE5C0
void __stdcall sub_005EE5C0(int nUnused1)
{
}

// 0x005EF310
void __stdcall sub_005EF310(int nUnused1)
{
}

// 0x005FE100
void __stdcall sub_005FE100(int nUnused1, int nUnused2)
{
}

// 0x005FEE40
int __cdecl sub_005FEE40()
{
    return gdwGlobal_0089DB64;
}

// 0x005FEE60
int __cdecl sub_005FEE60()
{
    return gdwGlobal_0088DB28;
}

// 0x005FEE70
int __cdecl sub_005FEE70()
{
    return gdwGlobal_0088DB24;
}

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

// 0x005FE0E0
void __cdecl sub_005FE0E0_Empty()
{
}

// 0x005FE0F0
void __cdecl sub_005FE0F0_Empty()
{
}

// 0x005FE110
void __cdecl sub_005FE110_Empty()
{
}

// 0x005FEE00
void __cdecl sub_005FEE00_DestroyBlockTableB()
{
    gCmpBlockTableB.sub_0060AB70_Destroy();
}

// 0x005FEE50
void __cdecl sub_005FEE50_DestroyBlockTableA()
{
    gCmpBlockTableA.sub_0060B130_Destroy();
}

// 0x005FEE80
int __fastcall sub_005FEE80_IsValueSet(D2CmpValueObjStrc* pObject)
{
    return pObject->nValue != 0;
}

// 0x005FF0D0
static __forceinline void sub_005FF0D0_SpriteCachePushFree(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    if (!pCache->f_28)
    {
        pCache->f_24 = pNode;
        pCache->f_28 = pNode;
    }
    else
    {
        pCache->f_28->pNext = pNode;
        pNode->pPrev = pCache->f_28;
        pCache->f_28 = pNode;
    }
}

// 0x005FF170
static __forceinline D2SpriteCacheNodeStrc* sub_005FF170_SpriteCachePopFree(D2SpriteCacheStrc* pCache)
{
    D2SpriteCacheNodeStrc* pNode = pCache->f_24;
    if (!pNode)
        return 0;
    if (pNode->dwFlags & 2)
        return 0;
    D2SpriteCacheNodeStrc* pNext = pNode->pNext;
    pCache->f_24 = pNext;
    if (pNext)
        pNext->pPrev = 0;
    else
        pCache->f_28 = 0;
    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x005FF390
void __cdecl sub_005FF390_Nop()
{
}

D2SpriteCacheNodeStrc* __fastcall sub_M110_Emit_005FF0D0(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    sub_005FF0D0_SpriteCachePushFree(pCache, pNode);
    return sub_005FF170_SpriteCachePopFree(pCache);
}

// 0x005FF6E0
int __stdcall sub_005FF6E0_SpriteLoadCallback(void* hArg, int nArg, D2SpriteLoadRequestStrc* pRequest)
{
    D2SpriteFileStrc* pFile = pRequest->pFile;
    D2SpriteEntryStrc* pEntry = pRequest->f_8;
    D2SpriteCacheNodeStrc* pNode = pEntry->pNode;
    pNode->dwFlags |= 2;
    pRequest->nResult = sub_0060BFF0_LoadSpriteData(hArg, gCmpTileCache.pMemPool, nArg, pFile, pEntry, pRequest->nArg0C, pRequest->nArg10, &pRequest->nSize, pFile->pData);
    pNode->dwFlags &= ~2;
    pEntry->nFlags &= ~4;
    sub_005FF630_ResizeCacheEntry(&gCmpTileCache, pNode, pRequest->nSize, 0);
    if (!pRequest->nResult)
    {
        pFile->nFlags |= 1;
    }
    return 1;
}

D2CmpBlockTableBStrc gCmpBlockTableB; // 0x0088DB58

int gbCmpSmallCelCache; // 0x0089DB58

// 0x005FFD40
void __stdcall D2CMP_InitSpriteCache(void* pMemPool, unsigned int nMaxSize, int nArg, unsigned int nCacheSize)
{
    sub_0060CD30_InitTileLock();
    if (!nCacheSize)
    {
        T004013C0* pInfo = sub_00407360_GetSystemInfo();
        D2_ASSERT(pInfo, 0x10B);
        nCacheSize = pInfo->nTotalMemory - 0xB00000;
    }
    gbCmpSmallCelCache = nCacheSize < 0x4000000;
    sub_0060AEE0_ClearBlockTableA(&gCmpBlockTableA);
    sub_006093E0_PoolFreeAll(&gCmpTilePool);
    memset(&gCmpTilePool, 0, sizeof(gCmpTilePool));
    sub_00609020_PoolInit(&gCmpTilePool, pMemPool, nArg, sub_005FE1D0_FreeTilePoolEntry, gnCmpTilePoolBlocks);
    memset(&gCmpBlockTableB, 0, sizeof(gCmpBlockTableB));
    sub_0060AAF0_ClearBlockTableB(&gCmpBlockTableB);
    if (gCmpTileCache.nArg)
    {
        sub_005FFBE0_FreeTileCache(&gCmpTileCache);
        memset(&gCmpTileCache, 0, sizeof(gCmpTileCache));
    }
    sub_005FEE90_SpriteCacheInit(&gCmpTileCache, pMemPool, nMaxSize, (int)sub_005FE170_SpriteCacheFreeCallback);
}

// 0x00600D60
int __stdcall sub_00600D60_GetDirectionIndex64A(unsigned int nIndex, unsigned int nDirections)
{
    D2_ASSERT(nIndex < 64, 0x1DD);
    D2_ASSERT(sub_00517ABB_BitScanForward1(nDirections) < 8u, 0x1DE);
    D2_ASSERT(D2CMP_BITCOUNT(nDirections) == 1, 0x1DF);
    return gaDirectionIndex64A[sub_00517ABB_BitScanForward1(nDirections)][nIndex];
}

// 0x00600E20
int __stdcall sub_00600E20_GetDirectionIndex64B(unsigned int nIndex, unsigned int nDirections)
{
    D2_ASSERT(nIndex < 64, 0x1EC);
    D2_ASSERT(sub_00517ABB_BitScanForward1(nDirections) < 8u, 0x1ED);
    D2_ASSERT(D2CMP_BITCOUNT(nDirections) == 1, 0x1EE);
    return gaDirectionIndex64B[sub_00517ABB_BitScanForward1(nDirections)][nIndex];
}

// 0x00601180
void __stdcall sub_00601180_ForEachCel(D2CelFileStrc* pCelFile, int nArg)
{
    D2_ASSERT(pCelFile->dwFlags & 4, 0x322);
    for (unsigned int nDirection = 0; nDirection < pCelFile->nDirections; nDirection++)
    {
        for (unsigned int nFrame = 0; nFrame < pCelFile->nCelsPerDirection; nFrame++)
        {
            sub_0060D110_CelOp(pCelFile->pCels[nDirection * pCelFile->nCelsPerDirection + nFrame], nArg, pCelFile->nTermination);
        }
    }
}

// 0x006011F0
int __stdcall sub_006011F0_CloneCelFile(D2CelFileStrc* pCelFile, D2CelFileStrc** ppNewCelFile, unsigned int* pnSize)
{
    const unsigned int nCels = pCelFile->nCelsPerDirection * pCelFile->nDirections;
    unsigned int nSize = nCels * sizeof(D2CelStrc*) + 0x18;
    for (unsigned int i = 0; i < nCels; i++)
    {
        nSize += pCelFile->pCels[i]->nLength + pCelFile->pCels[i]->nDataSize + 0x23;
    }
    D2CelFileStrc* pNewCelFile = (D2CelFileStrc*)FOG_Alloc(nSize, ".\\SRC\\CelCmp.cpp", 0x345, 0);
    *pNewCelFile = *pCelFile;
    pNewCelFile->dwFlags = pNewCelFile->dwFlags & ~2 | 1;
    char* pData = (char*)&pNewCelFile->pCels[nCels];
    D2CelBlockStrc* pBlockToFree = 0;
    for (unsigned int i = 0; i < nCels; i++)
    {
        D2CelStrc* pNewCel = (D2CelStrc*)pData;
        const unsigned int nCelSize = pCelFile->pCels[i]->nLength + 0x23;
        pNewCelFile->pCels[i] = (D2CelStrc*)(pData - (char*)pNewCelFile);
        memcpy(pData, pCelFile->pCels[i], nCelSize);
        pData += nCelSize;
        if (pCelFile->pCels[i]->pBlockPixelData && pCelFile->pCels[i]->pBlockPixelData->pPixels)
        {
            memcpy(pData, pCelFile->pCels[i]->pBlockPixelData->pPixels, pCelFile->pCels[i]->nDataSize);
            if (!i)
            {
                pBlockToFree = pCelFile->pCels[0]->pBlockPixelData;
            }
        }
        pNewCel->pBlockPixelData = (D2CelBlockStrc*)(pData - (char*)pNewCelFile);
        pData += pCelFile->pCels[i]->nDataSize;
    }
    if (pBlockToFree)
    {
        FOG_Free(pBlockToFree, ".\\SRC\\CelCmp.cpp", 0x375, 0);
    }
    *ppNewCelFile = pNewCelFile;
    *pnSize = nSize;
    return 1;
}

// 0x00601450
void __stdcall sub_00601450_CelFileCellOp(D2CelFileStrc* pCelFile, int nArg)
{
    D2_ASSERT(pCelFile, 0x431);
    for (unsigned int i = 0; i < pCelFile->nDirections * pCelFile->nCelsPerDirection; i++)
    {
        gpfnCelFileCellOp[pCelFile->nFormat](pCelFile->pCels[i], nArg);
    }
}

// 0x00601650
void __stdcall sub_00601650_DrawCelClipped(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nClipTop, int nClipRows, int nArg13)
{
    D2CelFileStrc* pCelFile = pContext->pCelFile;
    if (pCelFile)
    {
        D2_ASSERT(pCelFile->nVersion == 6, 0x4C6);
        D2_ASSERT(!(pCelFile->dwFlags & 4), 0x4C7);
    }
    D2_ASSERT(pBuffer, 0x4CA);
    D2CelStrc* pCel = pContext->pCel;
    D2_ASSERT(pCel, 0x4CD);
    nY += pCel->nYOffset;
    int nEnd = nY - nClipTop;
    nX += pCel->nXOffset;
    int nStart = nEnd - nClipRows;
    if (nEnd < 0 || nStart >= nHeight)
    {
        return;
    }
    if (nStart < 0)
    {
        nStart = 0;
    }
    if (nEnd >= nHeight)
    {
        nEnd = nHeight - 1;
    }
    const int nRows = nEnd - nStart;
    if (!nRows)
    {
        return;
    }
    CELDRAWFN pfnDraw = gpfnCelDraw[pCelFile->nFormat];
    D2_ASSERT(pfnDraw, 0x4E9);
    pfnDraw(pCel, &pBuffer[nEnd * nPitch + nX], nX, nArg4, nArg5, nPitch, nY - nEnd, nRows, nArg9, nArg10, nArg13);
}

static PixelDataFreeCallback gpfnPixelDataFree_008E8CB8; // 0x008E8CB8

void __stdcall sub_F43_EmitPixelDataFreeWriter(PixelDataFreeCallback pfnCallback)
{
    gpfnPixelDataFree_008E8CB8 = pfnCallback;
}

// 0x00601A50
int __stdcall D2CMP_CelFileFreeHardware(D2CelFileStrc* pCelFile)
{
    if (!pCelFile)
    {
        return 0;
    }
    D2_ASSERT(pCelFile->nVersion == 6, 0x5F1);
    D2CelBlockStrc* pBlocks = pCelFile->pCels[0]->pBlockPixelData;
    D2_ASSERT(pBlocks, 0x5F5);
    for (unsigned int i = 0; i < pCelFile->nCelsPerDirection * pCelFile->nDirections; i++)
    {
        if (pCelFile->pCels[i] && pCelFile->pCels[i]->pBlockPixelData)
        {
            if (gpfnPixelDataFree_008E8CB8)
            {
                gpfnPixelDataFree_008E8CB8(pCelFile->pCels[i]->pBlockPixelData);
            }
            pCelFile->pCels[i]->pBlockPixelData = 0;
        }
    }
    FOG_Free(pBlocks, ".\\SRC\\CelCmp.cpp", 0x61D, 0);
    return 1;
}

// 0x00604A40
void __stdcall DT1_ListAdd(D2TileLibraryHeaderStrc** ppList, const char* szFilePath)
{
    D2_ASSERT(ppList, 0x1C);
    D2_ASSERT(szFilePath, 0x1D);
    int i;
    for (i = 0; i < 32; ++i)
    {
        if (!ppList[i])
        {
            sub_00600790_LoadTileLibrary(&ppList[i], szFilePath);
            break;
        }
    }
    D2_ASSERT(i < 32, 0x2A);
}

#include "gen/data/Source/D2CMP/SRC/SpriteCache.inc"
