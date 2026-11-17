extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2CmpColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nPad;
};

typedef unsigned char (__stdcall* D2CmpMapColorFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

struct D2CmpSubTileHeaderStrc
{
    int unk0x00;
    int unk0x04;
    unsigned short nFlags;
    unsigned short nLength;
    int unk0x0C;
};

struct D2CmpSubTileRecordStrc
{
    D2CmpSubTileHeaderStrc tHeader;
    unsigned char* pData;
};

void __fastcall sub_0060D5B0_MapSubTileColors(D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc, D2CmpColorStrc tTransparent, D2CmpMapColorFn pfnMapColor); // 0x0060D5B0
void* __fastcall sub_0060D430_Compress(const void* pSrc, int* pLength);                                    // 0x0060D430
void __fastcall sub_0060DB20_RecodeSubTile(D2CmpSubTileRecordStrc* pRecord);                               // 0x0060DB20

struct D2CmpTileBlockStrc
{
    char unk0x00[0x24];
    D2CmpColorStrc tTransparent;
    char unk0x28[0x20];
    int f_48;
    int nSubBytes;
    int nSubs;
    D2CmpSubTileRecordStrc* pSubs;
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

static int IsSubTileDataEmpty(const D2CmpSubTileRecordStrc* pRecord, const unsigned char* pData)
{
    for (int i = 0; i < pRecord->tHeader.nLength; i++)
    {
        if (*pData)
        {
            return 0;
        }
        pData++;
    }
    return 1;
}

// 0x0060A650
static void __stdcall sub_0060A650_MapSubTileRecord(D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc, D2CmpMapColorFn pfnMapColor, D2CmpColorStrc tTransparent)
{
    if (!pSrc->pData)
    {
        pDst->tHeader.nFlags &= ~1;
        pDst->tHeader.nLength = 0;
        pDst->pData = 0;
        return;
    }
    sub_0060D5B0_MapSubTileColors(pDst, pSrc, tTransparent, pfnMapColor);
    unsigned char* pMapped = pDst->pData;
    if (IsSubTileDataEmpty(pDst, pMapped))
    {
        FOG_Free(pMapped, ".\\SRC\\Tilecmp.cpp", 0x429, 0);
        pDst->tHeader.nFlags &= ~1;
        pDst->tHeader.nLength = 0;
        pDst->pData = 0;
        return;
    }
    if (pDst->tHeader.nFlags & 0x1000)
    {
        int nLength;
        unsigned char* pData = (unsigned char*)sub_0060D430_Compress(pMapped, &nLength);
        D2_ASSERT(pData, 0x434);
        D2_ASSERT(nLength < 0x10000, 0x435);
        FOG_Free(pDst->pData, ".\\SRC\\Tilecmp.cpp", 0x436, 0);
        pDst->pData = pData;
        pDst->tHeader.nLength = nLength;
    }
    else
    {
        D2_ASSERT(pDst->tHeader.nFlags & 0x2000, 0x43B);
        sub_0060DB20_RecodeSubTile(pDst);
    }
}

// 0x0060A750
void __stdcall sub_0060A750_MapTileLibrary(D2CmpTileLibraryStrc* pSrc, D2CmpTileLibraryStrc** ppLibrary, D2CmpMapColorFn pfnMapColor)
{
    D2_ASSERT(pSrc, 0x44F);
    D2_ASSERT(pSrc->dwFlags & 1, 0x450);
    D2CmpTileLibraryStrc* pLibrary = (D2CmpTileLibraryStrc*)FOG_Alloc(sizeof(D2CmpTileLibraryStrc), ".\\SRC\\Tilecmp.cpp", 0x453, 0);
    D2_ASSERT(pLibrary, 0x454);
    memset(pLibrary, 0, sizeof(D2CmpTileLibraryStrc));
    *pLibrary = *pSrc;
    pLibrary->dwFlags &= ~1;
    pLibrary->pBlocks = 0;
    const int nSize = pLibrary->nBlocks * sizeof(D2CmpTileBlockStrc);
    pLibrary->pBlocks = (D2CmpTileBlockStrc*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 0x45E, 0);
    D2_ASSERT(pLibrary->pBlocks, 0x45F);
    memset(pLibrary->pBlocks, 0, nSize);
    for (int i = 0; i < pSrc->nBlocks; i++)
    {
        D2CmpTileBlockStrc* pDstBlock = &pLibrary->pBlocks[i];
        D2CmpTileBlockStrc* pSrcBlock = &pSrc->pBlocks[i];
        *pDstBlock = *pSrcBlock;
        pDstBlock->pSubs = 0;
        if (pDstBlock->nSubs)
        {
            const int nSubSize = pDstBlock->nSubs * sizeof(D2CmpSubTileRecordStrc);
            D2_ASSERT(nSubSize, 0x470);
            pDstBlock->pSubs = (D2CmpSubTileRecordStrc*)FOG_Alloc(nSubSize, ".\\SRC\\Tilecmp.cpp", 0x472, 0);
            D2_ASSERT(pDstBlock->pSubs, 0x473);
            memset(pDstBlock->pSubs, 0, nSubSize);
            for (int j = 0; j < pSrcBlock->nSubs; j++)
            {
                sub_0060A650_MapSubTileRecord(&pDstBlock->pSubs[j], &pSrcBlock->pSubs[j], pfnMapColor, pSrcBlock->tTransparent);
            }
        }
    }
    *ppLibrary = pLibrary;
}
