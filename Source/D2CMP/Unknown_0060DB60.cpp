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

int __fastcall CmpScanRun(unsigned char, const unsigned char*, const unsigned char*, int, int*, int*); // 0x0060D310
int __fastcall sub_0060D3A0_ScanOtherRun(const unsigned char*, const unsigned char*, unsigned char, int, int*, int*); // 0x0060D3A0
unsigned char* __stdcall sub_0060D6F0_MapPixels(const unsigned char*, int, D2CmpColorStrc, D2CmpMapColorFn); // 0x0060D6F0
void __stdcall SubTilePackFloor(D2CmpSubTileRecordStrc*, const unsigned char*); // 0x0060D9C0

int SubTileHasTransparentPixel(const unsigned char* pData); // 0x0060D7E0

void __stdcall SubTileCompressFloor(D2CmpSubTileRecordStrc* pDst, const unsigned char* pSrc); // 0x0060D840

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

static void __stdcall SubTileConvertFloor24To8(D2CmpColorStrc tColor, D2CmpMapColorFn pfnMap, D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc);

// 0x0060DA80
static void __stdcall SubTileConvertFloor24To8(D2CmpColorStrc tColor, D2CmpMapColorFn pfnMap, D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc)
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

    if (SubTileHasTransparentPixel(pPixels))
    {
        SubTileCompressFloor(pDst, pPixels);
    }
    else
    {
        SubTilePackFloor(pDst, pPixels);
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
            SubTileConvertFloor24To8(tColor, pfnQuantize, pDst, pSrc);
            if (pDst->tHeader.nFlags & 4)
            {
                ptTile8->nFlags |= 0x10;
            }
        }
    }
}
