extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2CmpTileInfoStrc
{
    char data[25];
};

struct D2CmpTileNodeStrc
{
    unsigned short nX;
    unsigned short nY;
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short nFormat;
    unsigned short nSize;
    short unk0x0A;
    unsigned char* pData;
    D2CmpTileNodeStrc* pNext;
};

struct D2CmpTileStrc
{
    int nMinX;
    int nMaxY;
    int nMaxX;
    int nMinY;
    int nValue10;
    short nValue14;
    short f_16;
    char unk0x18[0x0C];
    int nValue24;
    int nValue28;
    int nValue2C;
    int nValue30;
    int nOwnerId;
    D2CmpTileInfoStrc tInfo;
    unsigned char nType;
    char unk0x52[0x02];
    int nCount;
    D2CmpTileNodeStrc* pNodes;
    D2CmpTileStrc* pNext;
};

struct D2CmpTileListStrc
{
    int bFlag;
    int nId;
    int nCount;
    D2CmpTileStrc* pFirst;
};

struct D2CmpTileSubStrc
{
    unsigned short nX;
    unsigned short nY;
    short unk0x04;
    unsigned char nGridX;
    unsigned char nGridY;
    short nFormat;
    unsigned short nSize;
    int unk0x0C;
    unsigned char* pData;
};

struct D2CmpTileBlockStrc
{
    int nValue10;
    short nValue14;
    short f_6;
    int nHeight;
    int nWidth;
    int unk0x10;
    int nValue24;
    int nValue28;
    int nValue2C;
    int nValue30;
    int nOwnerId;
    D2CmpTileInfoStrc tInfo;
    char unk0x41[0x07];
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

// 0x00609C30
static void __stdcall sub_00609C30_ConvertTileToBlock(D2CmpTileStrc* pSrc, D2CmpTileBlockStrc* pDst)
{
    pDst->nValue10 = pSrc->nValue10;
    pDst->nValue14 = pSrc->nValue14;
    pDst->f_6 = pSrc->f_16;
    pDst->nWidth = pSrc->nMaxX - pSrc->nMinX;
    pDst->nHeight = pSrc->nMinY - pSrc->nMaxY;
    pDst->nValue24 = pSrc->nValue24;
    pDst->nValue28 = pSrc->nValue28;
    pDst->nValue2C = pSrc->nValue2C;
    pDst->nValue30 = pSrc->nValue30;
    pDst->nOwnerId = pSrc->nOwnerId;
    pDst->nSubs = pSrc->nCount;
    pDst->tInfo = pSrc->tInfo;
    const int nSize = pDst->nSubs * sizeof(D2CmpTileSubStrc);
    if (nSize)
    {
        pDst->pSubs = (D2CmpTileSubStrc*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 0x201, 0);
        D2_ASSERT(pDst->pSubs, 0x202);
        memset(pDst->pSubs, 0, nSize);
    }
    else
    {
        pDst->pSubs = 0;
    }
    int i = 0;
    for (D2CmpTileNodeStrc* pNode = pSrc->pNodes; pNode; pNode = pNode->pNext)
    {
        D2CmpTileSubStrc* pSub = &pDst->pSubs[i];
        pSub->nX = pNode->nX;
        pSub->nY = pNode->nY;
        pSub->nGridX = pNode->nGridX;
        pSub->nGridY = pNode->nGridY;
        pSub->nFormat = pNode->nFormat;
        pSub->nSize = pNode->nSize;
        pSub->pData = pNode->pData;
        pNode->pData = 0;
        i++;
    }
    D2_ASSERT(i == pDst->nSubs, 0x213);
}

// 0x00609D60
int __stdcall sub_00609D60_BuildTileLibrary(D2CmpTileListStrc* pList, D2CmpTileLibraryStrc** ppLibrary)
{
    D2_ASSERT(pList, 0x224);
    if (!pList->nCount)
    {
        *ppLibrary = 0;
        return 0x85200004;
    }
    D2CmpTileLibraryStrc* pLibrary = (D2CmpTileLibraryStrc*)FOG_Alloc(sizeof(D2CmpTileLibraryStrc), ".\\SRC\\Tilecmp.cpp", 0x22C, 0);
    D2_ASSERT(pLibrary, 0x22D);
    memset(pLibrary, 0, sizeof(D2CmpTileLibraryStrc));
    pLibrary->nVersion = 7;
    if (pList->bFlag)
    {
        pLibrary->dwFlags = 1;
    }
    const int nBlocks = pList->nCount;
    const int nSize = nBlocks * sizeof(D2CmpTileBlockStrc);
    pLibrary->nBlocks = nBlocks;
    pLibrary->pBlocks = (D2CmpTileBlockStrc*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 0x238, 0);
    D2_ASSERT(pLibrary->pBlocks, 0x239);
    memset(pLibrary->pBlocks, 0, nSize);
    int i = 0;
    for (D2CmpTileStrc* pTile = pList->pFirst; pTile; pTile = pTile->pNext)
    {
        sub_00609C30_ConvertTileToBlock(pTile, &pLibrary->pBlocks[i]);
        i++;
    }
    D2_ASSERT(i == pLibrary->nBlocks, 0x247);
    *ppLibrary = pLibrary;
    return 0;
}
