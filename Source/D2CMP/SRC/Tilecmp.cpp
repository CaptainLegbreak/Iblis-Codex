#include "D2CMP.h"
#include "D2CmpTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TileListHeaderStrc;
struct D2CmpColorStrc;
struct D2CmpTileNodeStrc;
struct D2CmpTileStrc;
struct D2CmpSubTilePosStrc;
struct D2CmpSubTileRecordStrc;
struct D2CmpTileInfoStrc;
struct D2CmpTileListStrc;
struct D2CmpTileBlockStrc;
struct D2CmpTileLibraryStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2TileListHeaderStrc* __cdecl sub_006094B0_AllocTileListHeader(); // 0x006094B0
void __fastcall sub_005179B3_ConvertCelPixels(void* pDst, void* pSrc, int nRows, unsigned int nSrcSize, unsigned int nWidth, int nRows2);

struct D2CmpTileNodeStrc
{
    unsigned short nX;
    unsigned short nY;
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short nFormat;
    union
    {
        unsigned short nLength;
        unsigned short nSize;
    };
    short unk0x0A;
    unsigned char* pData;
    D2CmpTileNodeStrc* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern D2CmpSubTilePosStrc gSubTilePositions_00743500[25]; // 0x00743500

struct D2CmpTileListStrc
{
    int bFlag;
    int nId;
    int nCount;
    D2CmpTileStrc* pFirst;
};

// 0x00609770
static __declspec(noinline) int __stdcall sub_00609770_IsUniformBlock(D2CmpTileStrc* pTile, const unsigned char* pPixels, int nPitch)
{
    const unsigned char nFlags = pTile->nType;
    if (nFlags & 2)
    {
        const int nSkip = nPitch - 0x60;
        const unsigned int nColor = (((pTile->tColor.nBlue << 8) + pTile->tColor.nGreen) << 8) + pTile->tColor.nRed;
        for (int y = 0; y < 0x20; y++)
        {
            for (int x = 0; x < 0x20; x++)
            {
                const unsigned int nPixel = *(const unsigned int*)pPixels & 0xFFFFFF;
                pPixels += 3;
                if (nPixel != nColor)
                    return 0;
            }
            pPixels += nSkip;
        }
    }
    if (nFlags & 1)
    {
        const int nSkip = nPitch - 0x20;
        for (int y = 0; y < 0x20; y++)
        {
            for (int x = 0; x < 0x20; x++)
            {
                if (*pPixels++)
                    return 0;
            }
            pPixels += nSkip;
        }
    }
    return 1;
}

// 0x00609810
void __stdcall sub_00609810_AddTileBlock(D2CmpTileStrc* pTile, unsigned char* pPixels, int nPitch, int nX, int nY)
{
    D2_ASSERT(pTile, 0x100);
    D2_ASSERT(pPixels, 0x101);
    if (sub_00609770_IsUniformBlock(pTile, pPixels, nPitch))
        return;
    D2CmpTileNodeStrc* pNode = (D2CmpTileNodeStrc*)sub_006094B0_AllocTileListHeader();
    D2_ASSERT(pNode, 0x109);
    pNode->pNext = pTile->pNodes;
    pTile->nCount++;
    pTile->pNodes = pNode;
    D2_ASSERT(nX < 0x10000 && nY < 0x10000, 0x112);
    pNode->nX = nX;
    pNode->nY = nY;
    unsigned char* ptData = (unsigned char*)FOG_Alloc(0xC00, ".\\SRC\\Tilecmp.cpp", 0x119, 0);
    D2_ASSERT(ptData, 0x11A);
    memset(ptData, 0, 0xC00);
    pNode->nLength = 0xC00;
    pNode->pData = ptData;
    pNode->nFormat = 0x1001;
    sub_005179B3_ConvertCelPixels(ptData, pPixels, 0x60, nPitch, 0x20, 0x60);
    if (nX < pTile->nMinX)
        pTile->nMinX = nX;
    if (nX + 0x20 > pTile->nMaxX)
        pTile->nMaxX = nX + 0x20;
    if (nY > pTile->nMaxY)
        pTile->nMaxY = nY;
    if (nY - 0x20 < pTile->nMinY)
        pTile->nMinY = nY - 0x20;
}

// 0x00609940
static __declspec(noinline) int __stdcall sub_00609940_HasOtherColor(D2CmpColorStrc tColor, const unsigned char* pData)
{
    for (int i = 0; i < 0x200; i++)
    {
        if (pData[0] != tColor.nRed || pData[1] != tColor.nGreen || pData[2] != tColor.nBlue)
        {
            return 1;
        }
        pData += 3;
    }
    return 0;
}

static void __stdcall sub_00609980_ExtractSubTile(D2CmpTileNodeStrc* pSub, const unsigned char* pPixels, D2CmpColorStrc tColor, int nX, int nY)
{
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(0x600, ".\\SRC\\Tilecmp.cpp", 0x154, 0);
    D2_ASSERT(pBuffer, 0x155);
    memset(pBuffer, 0, 0x600);
    unsigned char* pFill = pBuffer;
    for (int i = 0; i < 0x200; i++)
    {
        pFill[0] = tColor.nRed;
        pFill[1] = tColor.nGreen;
        pFill[2] = tColor.nBlue;
        pFill += 3;
    }
    const unsigned char* pSrc = pPixels + 3 * (nY * 160 + nX);
    unsigned char* pDst = pBuffer;
    int nStart = 0x2A;
    int nWidth = 0x0C;
    for (int nRow = 0; nRow < 15; nRow++)
    {
        memcpy(pDst + nStart, pSrc + nStart, nWidth);
        if (nRow < 7)
        {
            nStart -= 6;
            nWidth += 0x0C;
        }
        else
        {
            nStart += 6;
            nWidth -= 0x0C;
        }
        pDst += 0x60;
        pSrc += 0x1E0;
    }
    if (sub_00609940_HasOtherColor(tColor, pBuffer))
    {
        pSub->nFormat |= 0x2001;
        pSub->pData = pBuffer;
        pSub->nLength = 0x600;
    }
    else
    {
        FOG_Free(pBuffer, ".\\SRC\\Tilecmp.cpp", 0x186, 0);
    }
}

// 0x00609AA0
static void sub_00609AA0_SplitFloorTile(D2CmpTileStrc* pTile, const unsigned char* pPixels)
{
    for (int i = 0; i < 25; i++)
    {
        D2CmpTileNodeStrc tSub;
        memset(&tSub, 0, sizeof(tSub));
        sub_00609980_ExtractSubTile(&tSub, pPixels, pTile->tColor, gSubTilePositions_00743500[i].nX, gSubTilePositions_00743500[i].nY);
        tSub.nGridX = i % 5;
        tSub.nGridY = i / 5;
        if (tSub.nFormat & 1)
        {
            D2CmpTileNodeStrc* pNode = (D2CmpTileNodeStrc*)FOG_Alloc(sizeof(D2CmpTileNodeStrc), ".\\SRC\\Tilecmp.cpp", 0x1A7, 0);
            D2_ASSERT(pNode, 0x1A8);
            *pNode = tSub;
            pNode->pNext = pTile->pNodes;
            pTile->nCount++;
            pTile->pNodes = pNode;
            pNode->nX = gSubTilePositions_00743500[i].nX;
            pNode->nY = gSubTilePositions_00743500[i].nY;
        }
    }
}

// 0x00609B90
void __stdcall sub_00609B90_InitFloorTile(D2CmpTileStrc* pTile, const unsigned char* pPixels)
{
    D2_ASSERT(pTile, 0x1C3);
    D2_ASSERT(pPixels, 0x1C4);
    sub_00609AA0_SplitFloorTile(pTile, pPixels);
    pTile->nMaxY = 0;
    pTile->nMinY = -0x80;
    pTile->nMinX = 0;
    pTile->nMaxX = 0xA0;
}

#include "gen/data/Source/D2CMP/SRC/Tilecmp.inc"

// 0x00609BF0
static __declspec(noinline) void sub_00609BF0_CopyTileNode(D2CmpSubTileRecordStrc* pSub, D2CmpTileNodeStrc* pNode)
{
    pSub->nX = pNode->nX;
    pSub->nY = pNode->nY;
    pSub->nGridX = pNode->nGridX;
    pSub->nGridY = pNode->nGridY;
    pSub->nFlags = pNode->nFormat;
    pSub->nLength = pNode->nSize;
    pSub->ptData = pNode->pData;
    pNode->pData = 0;
}

void __fastcall sub_M289_Emit_00609BF0(D2CmpSubTileRecordStrc* pSub, D2CmpTileNodeStrc* pNode)
{
    sub_00609BF0_CopyTileNode(pSub, pNode);
}

// 0x00609C30
static void __stdcall sub_00609C30_ConvertTileToBlock(D2CmpTileStrc* pSrc, D2CmpTileBlockStrc* ptTile)
{
    ptTile->nValue10 = pSrc->nValue10;
    ptTile->nValue14 = pSrc->nValue14;
    ptTile->unk0x06 = pSrc->unk0x16;
    ptTile->nWidth = pSrc->nMaxX - pSrc->nMinX;
    ptTile->nHeight = pSrc->nMinY - pSrc->nMaxY;
    ptTile->nValue24 = pSrc->nValue24;
    ptTile->nValue28 = pSrc->nValue28;
    ptTile->nValue2C = pSrc->nValue2C;
    ptTile->nValue30 = pSrc->nValue30;
    ptTile->nOwnerId = pSrc->nOwnerId;
    ptTile->nSubs = pSrc->nCount;
    ptTile->tInfo = pSrc->tInfo;
    const int nSize = ptTile->nSubs * sizeof(D2CmpSubTileRecordStrc);
    if (nSize)
    {
        ptTile->pSubs = (D2CmpSubTileRecordStrc*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 0x201, 0);
        D2_ASSERT(ptTile->pSubs, 0x202);
        memset(ptTile->pSubs, 0, nSize);
    }
    else
    {
        ptTile->pSubs = 0;
    }
    int i = 0;
    for (D2CmpTileNodeStrc* pNode = pSrc->pNodes; pNode; pNode = pNode->pNext)
    {
        D2CmpSubTileRecordStrc* pSub = &ptTile->pSubs[i];
        pSub->nX = pNode->nX;
        pSub->nY = pNode->nY;
        pSub->nGridX = pNode->nGridX;
        pSub->nGridY = pNode->nGridY;
        pSub->nFlags = pNode->nFormat;
        pSub->nLength = pNode->nSize;
        pSub->ptData = pNode->pData;
        pNode->pData = 0;
        i++;
    }
    D2_ASSERT(i == ptTile->nSubs, 0x213);
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
    pLibrary->dwVersion = 7;
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

// 0x0060A520
static void sub_0060A520_ForEachDataColor(D2CmpColorCallback pfnColor, const unsigned char* pData, int nSize)
{
    for (int i = 0; i < nSize; i += 3)
    {
        pfnColor((((pData[2] << 8) + pData[1]) << 8) + pData[0]);
        pData += 3;
    }
}

// 0x0060A570
void __stdcall TileProjectIteratePixels(D2CmpTileLibraryStrc* pLibrary, D2CmpColorCallback pfnColor)
{
    D2_ASSERT(pLibrary, 0x3EA);
    D2_ASSERT(pLibrary->dwFlags & 1, 0x3EB);
    for (int i = 0; i < pLibrary->nBlocks; i++)
    {
        D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
        for (int j = 0; j < pBlock->nSubs; j++)
        {
            D2CmpSubTileRecordStrc* pSub = &pBlock->pSubs[j];
            sub_0060A520_ForEachDataColor(pfnColor, pSub->ptData, pSub->nLength);
        }
    }
}
