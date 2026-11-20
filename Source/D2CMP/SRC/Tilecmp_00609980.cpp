#include "D2CMP.h"
#include "D2CmpTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CmpColorStrc;
struct D2CmpTileNodeStrc;
struct D2CmpTileStrc;
struct D2CmpSubTilePosStrc;
struct D2Block0060A050Strc;
struct D2BlockSet0060A050Strc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

struct D2CmpTileNodeStrc
{
    unsigned short nX;
    unsigned short nY;
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short nFormat;
    unsigned short nLength;
    short unk0x0A;
    unsigned char* pData;
    D2CmpTileNodeStrc* pNext;
};

extern D2CmpSubTilePosStrc gSubTilePositions_00743500[25]; // 0x00743500
static __declspec(noinline) void __stdcall sub_00609980_ExtractSubTile(D2CmpTileNodeStrc* pSub, const unsigned char* pPixels, D2CmpColorStrc tColor, int nX, int nY);

struct D2Block0060A050Strc
{
    unsigned char unk_00[0x0A];
    unsigned short nSize;
    unsigned char unk_0C[0x04];
    unsigned int pData;
};

struct D2BlockSet0060A050Strc
{
    unsigned char unk_00[0x50];
    int nBlocks;
    D2Block0060A050Strc* pBlocks;
};

static __declspec(noinline) int sub_0060A050_Serialize(unsigned char* pOut, D2BlockSet0060A050Strc* pSet);

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

// 0x00609980
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
    int nRow = 0;
    const unsigned char* pSrc = pPixels + 3 * (nY * 160 + nX);
    unsigned char* pDst = pBuffer;
    int nStart = 0x2A;
    int nWidth = 0x0C;
    for (; nRow < 15; nRow++)
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

// 0x0060A050
static int sub_0060A050_Serialize(unsigned char* pOut, D2BlockSet0060A050Strc* pSet)
{
    unsigned char* pStart = pOut;
    int nTotal = pSet->nBlocks * sizeof(D2Block0060A050Strc);
    memcpy(pOut, pSet->pBlocks, nTotal);
    D2Block0060A050Strc* pOutBlocks = (D2Block0060A050Strc*)pOut;
    pOut += nTotal;
    for (int i = 0; i < pSet->nBlocks; ++i)
    {
        D2Block0060A050Strc* pBlock = &pSet->pBlocks[i];
        memcpy(pOut, (const void*)pBlock->pData, pBlock->nSize);
        pOutBlocks[i].pData = pOut - pStart;
        nTotal += pBlock->nSize;
        pOut += pBlock->nSize;
    }
    return nTotal;
}

// calling-convention shim (not game code)
int __stdcall shim_5(unsigned char* pOut, D2BlockSet0060A050Strc* pSet)
{
    return sub_0060A050_Serialize(pOut, pSet);
}
