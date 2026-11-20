#include "D2CMP.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SpriteCacheNodeStrc;
struct D2StormEntry38Strc;
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
struct D2StormLinkStrc;
struct D2StormListStrc;
struct D2Storm4167B0Strc;
struct D2Storm4168F0Strc;
struct D2Storm416A90Strc;
struct D2ChatStormLinkStrc;
struct D2ChatStormLinkAStrc;
struct D2ChatStormLinkBStrc;
struct D2ChatStormNodeStrc;
struct D2ChatStormBaseArrayAStrc;
struct D2ChatStormBaseArrayBStrc;
struct D2ChatStormListAStrc;
struct D2ChatStormListBStrc;
struct D2ChatStormHashTableStrc;
struct D2ChatStormCtorLinkStrc;
struct D2ChatStormListCStrc;
struct D2ChatStormListDStrc;
struct D2ChatStormListEStrc;
struct D2CommonStormSlotLinkStrc;
struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonMappingEntryNodeBaseStrc;
struct D2CommonMappingEntryNodeStrc;
struct D2CommonStringEntryNodeStrc;
struct D2CommonStormHashTableAStrc;
struct D2StormNodeStrc;
struct D2CelEntryStrc;
struct D2StormNodeListStrc;
struct D2StormSlotListStrc;
struct D2StormListEStrc;
struct D2GameHashTableStrc;
struct D2GameDataTableStrc;
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
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue); // 0x00517ABB
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
void __fastcall sub_0040AB00_FreeAsyncData(T00481720* pAsync); // 0x0040AB00

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
    int nFormat;
    int nTermination;
    int nDirections;
    int nCelsPerDirection;
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

typedef void (__stdcall* PixelDataFreeCallback)(void* pData);

extern unsigned short gwValue_0077905C;

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    ~D2StormLinkStrc()
    {
        Unlink();
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern "C" const char gszIgnoreListSourceFile_006E6290[];

extern "C" const char gszTypeNameCelEntry[]; // 0x00741F14

struct D2StormNodeStrc
{
    D2StormLinkStrc f_0;
};

// build: context ??_GD2CelEntryStrc@@QAEPAXI@Z
struct D2CelEntryStrc : D2StormNodeStrc
{
    int nArg8;
    unsigned int nHeight;
    unsigned int nWidth;
    unsigned int nSize;
    int nArg6;
    int nArg7;
    void* pData;
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormNodeStrc* Head()
    {
        return (int)m_terminator.m_next > 0 ? (D2StormNodeStrc*)m_terminator.m_next : 0;
    }
    void UnlinkAll();
    void sub_00602BF0_DeleteAll();
};

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void UnlinkAll();
};

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void UnlinkAll();
};

struct D2GameHashTableStrc
{
    char unk0x04[0x24];

    virtual ~D2GameHashTableStrc();                                                                         // 0x00603460
    D2StormEntry38Strc* sub_006030E0_InternalFind(unsigned int nHashVal, const int& tKey);                 // 0x006030E0
};

struct D2GameDataTableStrc : D2GameHashTableStrc
{
    char unk0x28[0x1C];
    int f_44;
    unsigned int m_sequence;
    int m_wrapped;

    unsigned int sub_00603280_GenerateHandle();
};

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

D2CmpCacheListEntryStrc* gpCmpCacheEntries; // 0x0089DB7C

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
void __cdecl D2CMPSpriteFreeAsyncLoads()
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
void __stdcall CelDrawShadow(D2CmpCelContextStrc* pContext, int nX, int nY, int nClipLeft, int nClipRight, unsigned char* pBuffer, int nHeightLimit, int nPitch, int nTable, int nColor)
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

#include "gen/data/Source/D2CMP/SRC/CelCmp_005FF2A0.inc"

PixelDataFreeCallback gpfnPixelDataFree; // 0x008E8CB8

// 0x006018C0
int __stdcall sub_006018C0(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 1403);

    return pCel->nWidth;
}

// 0x006019F0
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pFile)
{
    D2_ASSERT(pFile->nVersion == 6, 1489);

    return pFile->nCelsPerDirection;
}

// 0x00601A30
void __stdcall sub_00601A30_StorePixelFreeHandler(PixelDataFreeCallback pfnCallback)
{
    gpfnPixelDataFree = pfnCallback;
}

// 0x00601A40
PixelDataFreeCallback __stdcall sub_00601A40()
{
    return gpfnPixelDataFree;
}

// 0x00601B10
void* __stdcall sub_00601B10_GetCelPixels(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 1578);

    return pCel->pBlockPixelData;
}

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00601DD0
char* __fastcall sub_00416800_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

bool D2ChatStormLinkStrc::sub_0060E0C0_IsLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::sub_0060E0B0_GetKey()
{
    return f_14;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::sub_0060E230_Count()
{
    return f_4;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::sub_0060E250_Count()
{
    return f_4;
}

void D2ChatStormListAStrc::sub_0060E260_InitializeTerminator()
{
    InitializeTerminator();
}

void D2ChatStormListBStrc::sub_0060E270_InitializeTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::sub_0060E5D0_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::sub_0060E610_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x00601DE0
char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::sub_0060E6D0_Head()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::sub_0060EE30_Destroy()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::sub_0060ED60_Clear()
{
    sub_0060EB70_InternalClear(0);
}

// 0x006020B0
char* D2ChatStormListAStrc::sub_0060E440_Head()
{
    return m_terminator.MaskNext();
}

// 0x00602390
void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// build: symbol ?UnlinkAll@D2StormNodeListStrc@@QAEXXZ 0x006025E0
void D2StormNodeListStrc::UnlinkAll()
{
    D2StormNodeStrc* pNode;
    while ((pNode = Head()) != 0)
        pNode->f_0.Unlink();
}

// build: symbol ?UnlinkAll@D2StormSlotListStrc@@QAEXXZ 0x00602640
void D2StormSlotListStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}

// build: symbol ?UnlinkAll@D2StormListEStrc@@QAEXXZ 0x00602690
void D2StormListEStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}

// 0x00602BF0
void D2StormNodeListStrc::sub_00602BF0_DeleteAll()
{
    char* pNode;
    while ((pNode = m_terminator.Next()) != 0)
    {
        ((D2CelEntryStrc*)pNode)->~D2CelEntryStrc();
        SMemFree(pNode, gszTypeNameCelEntry, -2, 0);
    }
}

// 0x00603280
unsigned int D2GameDataTableStrc::sub_00603280_GenerateHandle()
{
    for (;;)
    {
        ++m_sequence;
        if (!m_sequence)
        {
            m_wrapped = 1;
            continue;
        }

        if (!m_wrapped || !sub_006030E0_InternalFind(m_sequence, f_44))
        {
            break;
        }
    }

    return m_sequence;
}

// 0x00602730
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}
