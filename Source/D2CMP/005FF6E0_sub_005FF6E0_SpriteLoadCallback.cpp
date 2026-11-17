typedef unsigned int size_t;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

struct D2SpriteCacheNodeStrc
{
    void* pData;
    unsigned int nSize;
    unsigned int nKey;
    unsigned int dwFlags;
    int unk0x10;
    D2SpriteCacheNodeStrc* pNext;
    D2SpriteCacheNodeStrc* pPrev;
};

struct D2SpriteCacheLockStrc
{
    char data[0x18];
};

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
    D2SpriteCacheLockStrc tLock;
    unsigned int nHits;
    unsigned int f_4C;
};

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

extern D2SpriteCacheStrc gCmpTileCache;                                                                     // 0x0089DB60

int __fastcall sub_0060BFF0_LoadSpriteData(void* hArg, void* pMemPool, int nArg, D2SpriteFileStrc* pFile, D2SpriteEntryStrc* pEntry, int nArg0C, int nArg10, int* pSize, char* pData); // 0x0060BFF0
void __fastcall sub_005FF630_ResizeCacheEntry(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int nDelta, int nArg); // 0x005FF630

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

struct D2CmpPoolStrc
{
    unsigned char unk0x00[0x34];
};

struct D2CmpBlockTableAStrc
{
    unsigned char data[0x1000];
};

struct D2CmpBlockTableBStrc
{
    unsigned char data[0x10000];
};

struct T004013C0
{
    char unk0x00[0x0C];
    unsigned int nTotalMemory;
};

extern D2CmpPoolStrc gCmpTilePool;                                                                          // 0x0088DB20
extern D2CmpBlockTableAStrc gCmpBlockTableA;                                                                // 0x0088CB20
D2CmpBlockTableBStrc gCmpBlockTableB;                                                                       // 0x0088DB58
int gbCmpSmallCelCache;                                                                                     // 0x0089DB58
extern int gnCmpTilePoolBlocks;                                                                             // 0x00741EF8

void __cdecl sub_0060CD30_InitTileLock();                                                                   // 0x0060CD30
T004013C0* __cdecl sub_00407360_GetSystemInfo();                                                     // 0x00407360
void __fastcall sub_0060AEE0_ClearBlockTableA(D2CmpBlockTableAStrc* pTable);                                // 0x0060AEE0
void __fastcall sub_0060AAF0_ClearBlockTableB(D2CmpBlockTableBStrc* pTable);                                // 0x0060AAF0
void __fastcall sub_006093E0_PoolFreeAll(D2CmpPoolStrc* pPool);                                             // 0x006093E0
void __fastcall sub_00609020_PoolInit(D2CmpPoolStrc* pPool, void* pMemPool, int nArg, void (__fastcall* pfnFree)(void*), int nBlocks); // 0x00609020
void __fastcall sub_005FE1D0_FreeTilePoolEntry(void* pEntry);                                               // 0x005FE1D0
void __fastcall sub_005FFBE0_FreeTileCache(D2SpriteCacheStrc* pCache);                                      // 0x005FFBE0
void __fastcall sub_005FEE90_SpriteCacheInit(D2SpriteCacheStrc* pCache, void* pMemPool, unsigned int nMaxSize, int nArg); // 0x005FEE90
void __fastcall sub_005FE170_SpriteCacheFreeCallback(void* pNode);                                          // 0x005FE170

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

extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue);                                   // 0x00517ABB
extern int gaDirectionIndex64A[8][64];                                                                      // 0x006E4DA0
extern int gaDirectionIndex64B[8][64];                                                                      // 0x006E55A0

#define D2CMP_BITCOUNT_BX(x) ((x) - (((x) >> 1) & 0x77777777) - (((x) >> 2) & 0x33333333) - (((x) >> 3) & 0x11111111))
#define D2CMP_BITCOUNT(x) (((D2CMP_BITCOUNT_BX(x) + (D2CMP_BITCOUNT_BX(x) >> 4)) & 0x0F0F0F0F) % 255)

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

struct D2CelBlockStrc
{
    char unk0x00[0x28];
    unsigned char* pPixels;
};

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

void __fastcall sub_0060D110_CelOp(D2CelStrc* pCel, int nArg, int nTermination);                            // 0x0060D110

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

typedef void(__fastcall* CELFILECELLOPFN)(D2CelStrc* pCel, int nArg);
extern CELFILECELLOPFN gpfnCelFileCellOp[];                                                                 // 0x006E3698

// 0x00601450
void __stdcall sub_00601450_CelFileCellOp(D2CelFileStrc* pCelFile, int nArg)
{
    D2_ASSERT(pCelFile, 0x431);
    for (unsigned int i = 0; i < pCelFile->nDirections * pCelFile->nCelsPerDirection; i++)
    {
        gpfnCelFileCellOp[pCelFile->nFormat](pCelFile->pCels[i], nArg);
    }
}

struct D2CmpCelContextStrc
{
    unsigned int nFrame;
    char unk0x04[0x30];
    D2CelFileStrc* pCelFile;
    char unk0x38[0x04];
    D2CelStrc* pCel;
    unsigned int nDirection;
};

typedef void(__fastcall* CELDRAWFN)(D2CelStrc* pCel, unsigned char* pDst, int nX, int nArg4, int nArg5, int nPitch, int nSkipRows, int nRows, int nArg9, int nArg10, int nArg13);
extern CELDRAWFN gpfnCelDraw[];                                                                             // 0x006E3688

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

typedef void(__fastcall* PixelDataFreeCallback)(void* pData);
static PixelDataFreeCallback gpfnPixelDataFree_008E8CB8;                                                    // 0x008E8CB8

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

struct D2TileLibraryHeaderStrc;

void __stdcall sub_00600790_LoadTileLibrary(D2TileLibraryHeaderStrc** ppLibrary, const char* szFilePath);   // 0x00600790

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

#include "gen/data/Source/D2CMP/005FF6E0_sub_005FF6E0_SpriteLoadCallback.inc"
