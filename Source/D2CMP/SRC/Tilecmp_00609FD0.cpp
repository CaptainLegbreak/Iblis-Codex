extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
#pragma function(memcpy)

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
    int dwVersion;
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

static int sub_0060A050_PackBlockSubs(unsigned char* pDst, D2CmpTileBlockStrc* pBlock)
{
    unsigned char* pWrite = pDst;
    int nSize = pBlock->nSubs * sizeof(D2CmpTileSubStrc);
    memcpy(pWrite, pBlock->pSubs, nSize);
    D2CmpTileSubStrc* pDstSubs = (D2CmpTileSubStrc*)pWrite;
    pWrite += nSize;
    for (int i = 0; i < pBlock->nSubs; i++)
    {
        memcpy(pWrite, pBlock->pSubs[i].pData, pBlock->pSubs[i].nSize);
        pDstSubs[i].pData = (char*)(pWrite - pDst);
        nSize += pBlock->pSubs[i].nSize;
        pWrite += pBlock->pSubs[i].nSize;
    }
    return nSize;
}

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
    unsigned char* pWrite = pData;
    memcpy(pWrite, pLibrary, sizeof(D2CmpTileLibraryStrc));
    D2CmpTileLibraryStrc* pHeader = (D2CmpTileLibraryStrc*)pWrite;
    pWrite += sizeof(D2CmpTileLibraryStrc);
    const int nBlockBytes = pLibrary->nBlocks * sizeof(D2CmpTileBlockStrc);
    memcpy(pWrite, pLibrary->pBlocks, nBlockBytes);
    pHeader->pBlocks = (D2CmpTileBlockStrc*)(pWrite - pData);
    D2CmpTileBlockStrc* pDstBlocks = (D2CmpTileBlockStrc*)pWrite;
    pWrite += nBlockBytes;
    for (int i = 0; i < pLibrary->nBlocks; i++)
    {
        pDstBlocks[i].pSubs = 0;
        const int nBytes = sub_0060A050_PackBlockSubs(pWrite, &pLibrary->pBlocks[i]);
        pDstBlocks[i].nSubBytes = nBytes;
        pDstBlocks[i].f_48 = pWrite - pData;
        pWrite += nBytes;
    }
    pLibrary->dwFlags |= 2;
    pHeader->dwFlags |= 6;
}
