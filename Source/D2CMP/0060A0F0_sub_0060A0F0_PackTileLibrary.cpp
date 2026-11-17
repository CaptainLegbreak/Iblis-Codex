extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

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
    int nVersion;
    unsigned int dwFlags;
    char szName[0x104];
    int nBlocks;
    D2CmpTileBlockStrc* pBlocks;
};

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
