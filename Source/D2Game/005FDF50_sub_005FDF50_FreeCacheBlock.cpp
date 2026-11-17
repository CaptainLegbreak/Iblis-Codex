extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection);             // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);             // 0x006CC214

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

struct D2CmpPoolStrc;

extern D2CmpPoolStrc gCmpPool;                                                                              // 0x0088CAE0

void __fastcall sub_006092D0_PoolFree(D2CmpPoolStrc* pPool, void* pMemory);                                 // 0x006092D0

struct D2CmpCacheBlockOwnerStrc
{
    char unk0x00[0x54];
    int nBlockUsed;
    char unk0x58[4];
    void* pBlock;
};

// 0x005FDF50
void __stdcall sub_005FDF50_FreeCacheBlock(D2CmpCacheBlockOwnerStrc* pOwner)
{
    sub_006092D0_PoolFree(&gCmpPool, pOwner->pBlock);
    pOwner->nBlockUsed = 0;
    pOwner->pBlock = 0;
}

extern int gbCmpCompressedDataMode;                                                                         // 0x00741EFC
extern const char* gszCmpCompressedExtension;                                                               // 0x00741F00
extern const char* gszCmpDefaultExtension;                                                                  // 0x00741F04

// 0x005FE1F0
const char* __stdcall D2CMP_GetGfxFileExtension(int bAllowCompressed)
{
    if (bAllowCompressed && gbCmpCompressedDataMode)
    {
        return gszCmpCompressedExtension;
    }

    return gszCmpDefaultExtension;
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

extern D2CmpCacheListEntryStrc* gpCmpCacheEntries;                                                          // 0x0089DB7C

int __fastcall sub_0040A7F0_AsyncDataCheck(T00481720* pAsyncData);                                   // 0x0040A7F0

// 0x005FF300
int __stdcall sub_005FF300_IsEntryPending(int nKeyA, int nKeyB, int nKeyC)
{
    for (D2CmpCacheListEntryStrc* pEntry = gpCmpCacheEntries; pEntry; pEntry = pEntry->pNext)
    {
        D2CmpCacheKeyStrc* pKey = pEntry->pKey;
        if (pKey && !(pKey->nFlags & 1) && pKey->nKeyC == nKeyC && pKey->nKeyB == nKeyB && pKey->nKeyA == nKeyA)
        {
            D2_ASSERT(pKey->pAsyncData, 0xB7B);
            if (!sub_0040A7F0_AsyncDataCheck(pKey->pAsyncData))
            {
                return 1;
            }
        }
    }

    return 0;
}

struct D2CmpCacheNodeStrc
{
    char unk0x00[0x04];
    unsigned int nSize;
    char unk0x08[0x04];
    unsigned int dwFlags;
};

struct D2CmpCacheStrc
{
    char unk0x00[0x04];
    unsigned int nMaxSize;
    unsigned int nTotalSize;
    char unk0x0C[0x24];
    char tLock[0x18];
};

D2CmpCacheNodeStrc* __fastcall sub_005FF4A0_EvictCacheNode(D2CmpCacheStrc* pCache, D2CmpCacheNodeStrc* pNode, int nArg); // 0x005FF4A0

// 0x005FF630
void __fastcall sub_005FF630_ResizeCacheEntry(D2CmpCacheStrc* pCache, D2CmpCacheNodeStrc* pNode, int nDelta, int nArg)
{
    EnterCriticalSection(pCache->tLock);
    const unsigned int nNewSize = nDelta + pNode->nSize;
    pCache->nTotalSize -= pNode->nSize;
    pNode->dwFlags |= 2;
    pNode->nSize = nNewSize;
    pCache->nTotalSize += nNewSize;
    unsigned int nTotalSize = pCache->nTotalSize;
    LeaveCriticalSection(pCache->tLock);

    while (nTotalSize > pCache->nMaxSize)
    {
        D2CmpCacheNodeStrc* pEvicted = sub_005FF4A0_EvictCacheNode(pCache, 0, nArg);
        if (!pEvicted)
        {
            break;
        }

        D2_ASSERT(pEvicted != pNode, 0xA47);
        EnterCriticalSection(pCache->tLock);
        nTotalSize = pCache->nTotalSize;
        LeaveCriticalSection(pCache->tLock);
    }

    EnterCriticalSection(pCache->tLock);
    pNode->dwFlags &= ~2;
    LeaveCriticalSection(pCache->tLock);
}

struct D2TileLibraryEntryStrc
{
    char unk0x00[0x60];
};

struct D2TileLibraryHeaderStrc
{
    char unk0x000[0x10C];
    int nTiles;
    D2TileLibraryEntryStrc* pFirst;
};

struct D2TileRecordStrc
{
    char szLibraryName[260];
    D2TileLibraryHeaderStrc* pLibrary;
    void* pHashBlock;
    D2TileRecordStrc* pPrev;
};

extern D2TileRecordStrc* gpTileRecords;                                                                     // 0x008ADBB4

// 0x00600960
D2TileLibraryHeaderStrc* __stdcall sub_00600960_FindTileLibrary(D2TileLibraryEntryStrc* pTile)
{
    for (D2TileRecordStrc* pRecord = gpTileRecords; pRecord; pRecord = pRecord->pPrev)
    {
        D2TileLibraryHeaderStrc* pLibrary = pRecord->pLibrary;
        for (int i = 0; i < pLibrary->nTiles; ++i)
        {
            if (pTile == &pLibrary->pFirst[i])
            {
                return pLibrary;
            }
        }
    }

    return 0;
}

extern int gnCmpGfxMode;                                                                                    // 0x00741F08

// 0x00600C00
void __stdcall sub_00600C00_SetGfxMode(int nMode)
{
    if (nMode >= 1 && nMode <= 5)
    {
        gnCmpGfxMode = nMode;
    }
}

extern unsigned char gaItemShiftMaps[][105][256];                                                           // 0x008ADBB8

// 0x00600C20
unsigned char* __stdcall sub_00600C20(int nSet, int nIndex)
{
    if (nSet < 9 && nIndex < 21 && nSet != 0 && (nSet <= 2 || nSet > 4))
    {
        return gaItemShiftMaps[nSet][nIndex];
    }

    return 0;
}

extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue);                                   // 0x00517ABB
extern int gaDirectionIndex32[][32];                                                                        // 0x006E3A20

// 0x00600C70
int __stdcall sub_00600C70_GetDirectionIndex32(int nDirection, unsigned int nDirections)
{
    return gaDirectionIndex32[sub_00517ABB_BitScanForward1(nDirections)][nDirection];
}

struct D2CmpCellStrc;

struct D2CmpCelFileStrc
{
    int nVersion;
    unsigned int dwFlags;
    int nFormat;
    int unk0x0C;
    int nDirections;
    int nFrames;
    D2CmpCellStrc* pCells[1];
};

// 0x00600EE0
void __stdcall sub_00600EE0_CheckCelFile(D2CmpCelFileStrc* pCelFile, int nUnused)
{
    D2_ASSERT(pCelFile, 0x29C);
}

typedef void(__fastcall* CELFILECONVERTFN)(D2CmpCelFileStrc* pSource, D2CmpCelFileStrc* pTarget, int nArg1, int nArg2);
extern CELFILECONVERTFN gpfCelFileConvert[];                                                               // 0x006E3690

// 0x00600F10
int __stdcall sub_00600F10_CelFileConvert(D2CmpCelFileStrc* pSource, D2CmpCelFileStrc** ppTarget, int nArg1, int nArg2)
{
    D2_ASSERT(pSource->dwFlags & 4, 0x2AD);
    const int nCells = pSource->nDirections * pSource->nFrames;
    D2CmpCelFileStrc* pTarget = (D2CmpCelFileStrc*)FOG_Alloc(0x18 + nCells * sizeof(D2CmpCellStrc*), ".\\SRC\\CelCmp.cpp", 0x2B1, 0);
    pTarget->nVersion = 6;
    pTarget->dwFlags = pSource->dwFlags & ~7;
    pTarget->nDirections = pSource->nDirections;
    pTarget->nFrames = pSource->nFrames;
    pTarget->nFormat = 0;
    gpfCelFileConvert[pSource->nFormat](pSource, pTarget, nArg1, nArg2);
    *ppTarget = pTarget;
    return 1;
}

// 0x00601410
void __stdcall sub_00601410_CelFileFree(D2CmpCelFileStrc* pCelFile)
{
    D2_ASSERT(pCelFile, 0x40D);
    FOG_Free(pCelFile, ".\\SRC\\CelCmp.cpp", 0x40E, 0);
}

#include "gen/data/Source/D2Game/005FDF50_sub_005FDF50_FreeCacheBlock.inc"
