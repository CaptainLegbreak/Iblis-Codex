#include "D2CMP.h"
#include "D2CmpTypes.h"

extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
void* __fastcall FOG_Alloc(int, const char*, int, int); // 0x0040B380
int __fastcall FOG_Free(void*, const char*, int, int); // 0x0040B3C0
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int); // 0x006829C0
typedef unsigned char (__stdcall* D2CmpMapColorFn)(unsigned char, unsigned char, unsigned char);

int __fastcall sub_0060D310_ScanRun(unsigned char, const unsigned char*, const unsigned char*, int, int*, int*); // 0x0060D310
int __fastcall sub_0060D3A0_ScanOtherRun(const unsigned char*, const unsigned char*, unsigned char, int, int*, int*); // 0x0060D3A0
unsigned char* __stdcall sub_0060D6F0_MapPixels(const unsigned char*, int, D2CmpColorStrc, D2CmpMapColorFn); // 0x0060D6F0
void __stdcall sub_0060D9C0_BuildDiamondBlock(D2CmpSubTileRecordStrc*, const unsigned char*); // 0x0060D9C0

static int sub_0060D7E0_HasTransparentDiamondPixel(const unsigned char* pData);

// 0x0060D7E0
static int sub_0060D7E0_HasTransparentDiamondPixel(const unsigned char* pData)
{
    int y = 0;
    int nOffset = 14;
    int nWidth = 4;
    for (; y < 15; ++y)
    {
        for (int x = 0; x < nWidth; ++x)
        {
            if (pData[nOffset + x] == 0)
            {
                return 1;
            }
        }

        pData += 32;
        if (y < 7)
        {
            nOffset -= 2;
            nWidth += 4;
        }
        else
        {
            nOffset += 2;
            nWidth -= 4;
        }
    }

    return 0;
}

static void __stdcall sub_0060D840_PackTransparent(D2CmpSubTileRecordStrc* pDst, const unsigned char* pSrc);

// 0x0060D840
static void __stdcall sub_0060D840_PackTransparent(D2CmpSubTileRecordStrc* pDst, const unsigned char* pSrc)
{
    int nSize;
    unsigned char* ptDestBuffer;
    unsigned char* pOut;
    unsigned int nRow;
    const unsigned char* pNextRow;
    const unsigned char* pEnd;
    int nOpaque;
    int nTransparent;
    int i;
    int bRunEnd;
    int bRestEnd;
    int nLength;
    unsigned char* ptNewData;

    nSize = 0x5AF;
    ptDestBuffer = (unsigned char*)FOG_Alloc(nSize, szTileCodecFile, 0x128, 0);
    D2_ASSERT(ptDestBuffer, 0x129);
    memset(ptDestBuffer, 0, nSize);
    pOut = ptDestBuffer;
    nRow = 0;
    pNextRow = pSrc + 32;
    pEnd = pSrc + 32;
    while (nRow < 15)
    {
        nTransparent = sub_0060D310_ScanRun(0, pSrc, pEnd, 0x7F, &bRunEnd, &bRestEnd);
        pSrc += nTransparent;
        if (bRunEnd || bRestEnd)
        {
            *pOut++ = 0;
            *pOut++ = 0;
            pSrc = pNextRow;
            pNextRow += 32;
            pEnd += 32;
            ++nRow;
        }
        else if (nTransparent == 0x7F)
        {
            *pOut++ = (unsigned char)nTransparent;
        }
        else
        {
            nOpaque = sub_0060D3A0_ScanOtherRun(pSrc, pEnd, 0, 0x7F, &bRunEnd, &bRestEnd);
            *pOut++ = (unsigned char)nTransparent;
            *pOut++ = (unsigned char)nOpaque;
            for (i = 0; i < nOpaque; ++i)
            {
                *pOut++ = *pSrc++;
            }
            if (bRunEnd || bRestEnd)
            {
                *pOut++ = 0;
                *pOut++ = 0;
                pSrc = pNextRow;
                pNextRow += 32;
                pEnd += 32;
                ++nRow;
            }
        }
    }
    nLength = pOut - ptDestBuffer;
    ptNewData = 0;
    nSize = nLength;
    D2_ASSERT(nSize < 0x10000, 0x166);
    ptNewData = (unsigned char*)FOG_Alloc(nSize, szTileCodecFile, 0x169, 0);
    D2_ASSERT(ptNewData, 0x16A);
    memset(ptNewData, 0, nSize);
    memcpy(ptNewData, ptDestBuffer, nSize);
    pDst->ptData = ptNewData;
    pDst->tHeader.nLength = (unsigned short)nSize;
    pDst->tHeader.nFlags |= 5;
    FOG_Free(ptDestBuffer, szTileCodecFile, 0x176, 0);
}

// build: context SUBTILE_IsBlank
static inline int SUBTILE_IsBlank(const unsigned char* pPixels)
{
    for (int i = 0; i < 0x200; ++i)
    {
        if (*pPixels)
        {
            return 0;
        }

        ++pPixels;
    }

    return 1;
}

static void __stdcall sub_0060DA80_MapSubTile(D2CmpColorStrc tColor, D2CmpMapColorFn pfnMap, D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc);

// 0x0060DA80
static void __stdcall sub_0060DA80_MapSubTile(D2CmpColorStrc tColor, D2CmpMapColorFn pfnMap, D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc)
{
    unsigned char* pPixels = sub_0060D6F0_MapPixels(pSrc->ptData, pSrc->tHeader.nLength, tColor, pfnMap);

    if (SUBTILE_IsBlank(pPixels))
    {
        pDst->tHeader.nFlags = 0;
        pDst->tHeader.nLength = 0;
        pDst->ptData = 0;
        FOG_Free(pPixels, szTileCodecFile, 0x1B8, 0);
        return;
    }

    if (sub_0060D7E0_HasTransparentDiamondPixel(pPixels))
    {
        sub_0060D840_PackTransparent(pDst, pPixels);
    }
    else
    {
        sub_0060D9C0_BuildDiamondBlock(pDst, pPixels);
    }

    FOG_Free(pPixels, szTileCodecFile, 0x1C7, 0);
}

// 0x0060DB60
void __fastcall sub_0060DB60_MapBlock(D2CmpTileBlockStrc* ptTile24, D2CmpTileBlockStrc* ptTile8, D2CmpColorStrc tColor, D2CmpMapColorFn pfnQuantize)
{
    D2_ASSERT(ptTile24, 0x1EC);
    D2_ASSERT(ptTile8, 0x1ED);
    D2_ASSERT(pfnQuantize, 0x1EE);
    D2_ASSERT(ptTile24->nFlags & 8, 0x1EF);

    for (int i = 0; i < ptTile24->nSubs; ++i)
    {
        D2CmpSubTileRecordStrc* pDst = &ptTile8->pSubs[i];
        const D2CmpSubTileRecordStrc* pSrc = &ptTile24->pSubs[i];

        *pDst = *pSrc;
        pDst->ptData = 0;
        if (pSrc->ptData)
        {
            sub_0060DA80_MapSubTile(tColor, pfnQuantize, pDst, pSrc);
            if (pDst->tHeader.nFlags & 4)
            {
                ptTile8->nFlags |= 0x10;
            }
        }
    }
}
