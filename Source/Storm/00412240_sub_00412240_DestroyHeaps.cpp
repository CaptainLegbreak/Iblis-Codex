struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[2];
    int bReportLeak;
    int bInUse;
};

struct D2StormHashBufferStrc;

struct D2StormMemSourceStrc
{
    int unk0x00[3];
    char* pBuffer;
    unsigned int nPos;
    unsigned int nSize;
};

struct D2StormMemSinkStrc
{
    char* pBuffer;
    unsigned int nPos;
    unsigned int nSize;
};

struct D2StormCompParamStrc
{
    char* pDst;
    unsigned int nDstPos;
    unsigned int nDstSize;
    char* pSrc;
    unsigned int nSrcPos;
    unsigned int nSrcSize;
};

struct D2StormZArenaStrc
{
    char* f_0;
    char* f_8;
    unsigned int nSize;
};

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormNodeListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return m_terminator.Next();
    }
    void sub_0041ED90_LinkNode(char* pNode, unsigned int nLinkType, char* pExisting);                       // 0x0041ED90
};

struct D2StormHuffItemStrc
{
    D2StormLinkStrc f_0;
    unsigned int nValue;
    unsigned int nWeight;
    D2StormHuffItemStrc* pParent;
    D2StormHuffItemStrc* pChild;
};

struct D2StormHuffTreeStrc
{
    int unk0x00[2];
    D2StormHuffItemStrc f_8[0x203];
    D2StormNodeListAStrc tFreeList;
    D2StormNodeListAStrc tItemList;
    unsigned int nItemsUsed;

    D2StormHuffItemStrc* sub_0041EED0_NewItem(unsigned int nLinkType);
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void __fastcall sub_00411A80_ReleaseBlock(D2FogBlockStrc** ppLink);                                         // 0x00411A80
D2FogBlockStrc** __fastcall sub_00411F00_ProcessUsedBlock(D2FogBlockStrc** ppLink);                         // 0x00411F00
void __stdcall sub_0041D1E0_ReportHandleLeak(const char* szName);                                           // 0x0041D1E0
void __fastcall sub_0041D3B0_NewHashBuffer(D2StormHashBufferStrc** ppBuffer, unsigned int nSignSize, int nModulusSize); // 0x0041D3B0
void __fastcall sub_0041D420_HashBuffered(D2StormHashBufferStrc* pBuffer, const char* pData, int nSize);    // 0x0041D420
int __fastcall sub_0041D6D0_VerifyHashBuffer(D2StormHashBufferStrc* pBuffer, const void* pExponent, const void* pModulus); // 0x0041D6D0
unsigned int __cdecl sub_0041DEC0_ReadMemory(char* pBuffer, unsigned int* pSize, D2StormMemSourceStrc* pSource); // 0x0041DEC0
void __cdecl sub_0041DF00_WriteMemory(char* pBuffer, unsigned int* pSize, D2StormMemSinkStrc* pSink);      // 0x0041DF00
extern "C" unsigned int __cdecl sub_006B01B0_Explode(unsigned int (__cdecl* pRead)(char*, unsigned int*, D2StormMemSourceStrc*), void (__cdecl* pWrite)(char*, unsigned int*, D2StormMemSinkStrc*), char* pWork, void* pParam); // 0x006B01B0
extern "C" unsigned int __cdecl sub_006B0870_Implode(unsigned int (__cdecl* pRead)(char*, unsigned int*, D2StormMemSourceStrc*), void (__cdecl* pWrite)(char*, unsigned int*, D2StormMemSinkStrc*), char* pWork, void* pParam, unsigned int* pType, unsigned int* pDictSize); // 0x006B0870

extern D2FogBlockStrc* gapFreeBlocks_007768B8[0x100];                                                       // 0x007768B8
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100];                                              // 0x00776CC0
extern int gabFreeBlockDirty_007784C8[0x100];                                                               // 0x007784C8
extern int gbHeapInitialized_007788D0;                                                                      // 0x007788D0

// 0x00412240
int __cdecl sub_00412240_DestroyHeaps()
{
    int i = 0;
    if (gbHeapInitialized_007788D0)
    {
        gbHeapInitialized_007788D0 = 0;
        D2CriticalSectionStrc* pLock = gaFreeBlockLocks_00776CC0;
        int n = 0x100;
        do
        {
            EnterCriticalSection(pLock);
            D2FogBlockStrc** ppLink = &gapFreeBlocks_007768B8[i];
            gabFreeBlockDirty_007784C8[i] = 0;
            while (*ppLink)
            {
                D2FogBlockStrc* pBlock = *ppLink;
                if (pBlock->bInUse)
                {
                    ppLink = sub_00411F00_ProcessUsedBlock(ppLink);
                }
                else
                {
                    if (pBlock->bReportLeak && pBlock->dwSize >= 0x80000000)
                        sub_0041D1E0_ReportHandleLeak("HSHEAP");
                    sub_00411A80_ReleaseBlock(ppLink);
                }
            }
            LeaveCriticalSection(pLock);
            DeleteCriticalSection(pLock);
            ++i;
            ++pLock;
        } while (--n);
    }
    return 1;
}

// build: context sub_0041D7D0_VerifySignature
int __fastcall sub_0041D7D0_VerifySignature(const char* pData, int nSize, const void* pExponent, unsigned int nSignSize, const void* pModulus, int nModulusSize)
{
    D2StormHashBufferStrc* pBuffer;
    sub_0041D3B0_NewHashBuffer(&pBuffer, nSignSize, nModulusSize);
    sub_0041D420_HashBuffered(pBuffer, pData, nSize);
    return sub_0041D6D0_VerifyHashBuffer(pBuffer, pExponent, pModulus);
}

// 0x0041DF40
void __fastcall sub_0041DF40_CompressImplode(char* pDst, unsigned int* pDstLen, char* pSrc, unsigned int nSrcLen, int* pType, int nLevel)
{
    char* pWork = (char*)SMemAlloc(0x8DD8, ".\\SOURCE\\SCOMP.CPP", 0x440, 0);
    D2StormCompParamStrc tParam;
    unsigned int nType;
    unsigned int nDictSize;
    tParam.pDst = pDst;
    tParam.nDstPos = 0;
    tParam.nDstSize = *pDstLen;
    tParam.pSrc = pSrc;
    tParam.nSrcPos = 0;
    tParam.nSrcSize = nSrcLen;
    nType = *pType == 2;
    if (nSrcLen >= 0xC00)
        nDictSize = 0x1000;
    else
        nDictSize = nSrcLen < 0x600 ? 0x400 : 0x800;
    sub_006B0870_Implode(sub_0041DEC0_ReadMemory, sub_0041DF00_WriteMemory, pWork, &tParam, &nType, &nDictSize);
    SMemFree(pWork, ".\\SOURCE\\SCOMP.CPP", 0x467, 0);
    *pDstLen = tParam.nDstPos;
    *pType = 0;
}

// 0x0041E000
void __fastcall sub_0041E000_DecompressExplode(char* pDst, unsigned int* pDstLen, char* pSrc, unsigned int nSrcLen, int nUnused)
{
    char* pWork = (char*)SMemAlloc(0x3134, ".\\SOURCE\\SCOMP.CPP", 0x47B, 0);
    D2StormCompParamStrc tParam;
    tParam.pDst = pDst;
    tParam.nDstPos = 0;
    tParam.nDstSize = *pDstLen;
    tParam.pSrc = pSrc;
    tParam.nSrcPos = 0;
    tParam.nSrcSize = nSrcLen;
    sub_006B01B0_Explode(sub_0041DEC0_ReadMemory, sub_0041DF00_WriteMemory, pWork, &tParam);
    SMemFree(pWork, ".\\SOURCE\\SCOMP.CPP", 0x48D, 0);
    *pDstLen = tParam.nDstPos;
}

// 0x0041E080
void* __fastcall sub_0041E080_ZAlloc(D2StormZArenaStrc* pArena, unsigned int nItems, unsigned int nSize)
{
    unsigned int nBytes = nItems * nSize;
    if (nBytes & 3)
        nBytes += 4 - (nBytes & 3);
    if (nBytes < (unsigned int)(pArena->f_8 + pArena->nSize - pArena->f_0))
    {
        char* pResult = pArena->f_0;
        pArena->f_0 += nBytes;
        return pResult;
    }
    return SMemAlloc(nBytes, ".\\SOURCE\\SCOMP.CPP", 0x4C4, 0);
}

// 0x0041EED0
D2StormHuffItemStrc* D2StormHuffTreeStrc::sub_0041EED0_NewItem(unsigned int nLinkType)
{
    D2StormHuffItemStrc* pItem = (D2StormHuffItemStrc*)tFreeList.Head();
    if (!pItem)
        pItem = &f_8[nItemsUsed++];
    tItemList.sub_0041ED90_LinkNode((char*)pItem, nLinkType, 0);
    pItem->pParent = 0;
    pItem->pChild = 0;
    return pItem;
}
