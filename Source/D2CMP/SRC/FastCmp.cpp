#include "D2CMP.h"
#include "D2CmpTypes.h"
#include "D2CmpTiles.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2GfxCellStrc;

struct D2CmpTileInfoStrc;

struct D2CmpTileStrc;

struct D2CmpTileListStrc;

struct T00604AE0;

struct D2CelDataHashStrc;

struct D2CmpBitCursorStrc;

struct D2CmpSubTileBlockStrc;

struct D2CmpStringStrc;

struct D2CelStrc;

struct D2CellFileStrc;

struct D2CmpColorStrc;

struct D2CmpCellNodeStrc;

struct D2CmpCellListStrc;

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

int __stdcall sub_00600760_GetValue(void* pData); // 0x00600760

void __fastcall sub_005179A4_FreeVirtualMemory(void* pMemory); // 0x005179A4

void __stdcall sub_006059B0_BuildAdditiveTable(unsigned char* pData); // 0x006059B0

extern unsigned int gdwSwappedColor_008E9D38; // 0x008E9D38

extern int gnGlobal_008E9028; // 0x008E9028

extern int gnGlobal_008E9D3C; // 0x008E9D3C

extern unsigned char gaTable_008E9830[0x100]; // 0x008E9830

extern int gbTableSet_008E9D40; // 0x008E9D40

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590

D2CmpTileStrc* __cdecl sub_00609550_AllocTile(); // 0x00609550

struct T00604AE0
{
    unsigned int nKey;
    char unk0x04[0x28];
    T00604AE0* pNext;
};

struct D2CelDataHashStrc
{
    int nCheck[0x200];
    T00604AE0* pBuckets[0x200];
};

struct D2CmpSubTileBlockStrc
{
    char unk0x00[0x08];
    short nValue08;
    short nSize;
    int unk0x0C;
    unsigned char* pData;
};

struct D2CmpStringStrc
{
    const char* szText;

    int sub_0060DD20_EqualsNoCase(const D2CmpStringStrc* pOther);
};

int __stdcall SFileSetBasePath(const char* szPath); // 0x004164B0

extern "C" void __cdecl _chkstk(); // 0x006831B0

extern "C" void __cdecl _ftol2_sse(); // 0x00682FD0

int gnRemapStart_008E9D48[80]; // 0x008E9D48

int gnRemapEnd_008E9E88[80]; // 0x008E9E88

int gnRemapOffsets_008E9FC8[80 * 80]; // 0x008E9FC8

struct D2CelStrc { unsigned int flags,width,height; unsigned char unknown0C[0x14]; unsigned char pixels[1]; };

extern const char gszEmptyAssert[]; // 0x006CC837

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

int __fastcall sub_0060D280_ScanSameRun(const unsigned char* pData, const unsigned char* pEnd, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D280

int __fastcall sub_0060D3A0_ScanOtherRun(const unsigned char* pData, const unsigned char* pEnd, unsigned char nValue, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D3A0

typedef unsigned char (__stdcall* D2CmpMapColorFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

struct D2CmpCellNodeStrc
{
    D2CmpCellNodeStrc* pPrev;
    D2CmpCellNodeStrc* pNext;
    unsigned int dwFlags;
    unsigned int dwWidth;
    unsigned int dwHeight;
    unsigned int unk0x14;
    int nXOffset;
    int nYOffset;
    const unsigned char* pPixels;
};

struct D2CmpCellListStrc
{
    char unk0x00[0x18];
    unsigned int dwFlags;
    char unk0x1C[0x08];
    unsigned int nCells;
    unsigned int nDirections;
    char unk0x2C[0x08];
    D2CmpCellNodeStrc* pHead;
};

int __stdcall sub_00600C90_GetDirectionIndex64(int nDirection, unsigned int nDirections); // 0x00600C90

#define BLEND_PIXEL(i) pDst[i] = pBlend[(pDst[i] << 8) + pTrans[pSrc[i]]]

typedef unsigned char BYTE;

extern int gnGenericRle_008F03C8; // 0x008F03C8

const unsigned char* __fastcall sub_00606D10_SkipCelLines(const unsigned char*,int); // 0x00606D10

void __fastcall sub_00606D40_RleCopyRows(const unsigned char*,unsigned char*,int,int); // 0x00606D40

void __fastcall sub_00606DA0_RleCopyRowsClipped(const unsigned char*,unsigned char*,int,int,int,int,int); // 0x00606DA0

void __fastcall sub_00606E40_BlitBlendMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x00606E40

void __fastcall sub_00607060_BlitClippedBlendMapped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*,const unsigned char*); // 0x00607060

void __fastcall sub_006072F0_BlitDoubleMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x006072F0

void __fastcall sub_00607480_BlitDoubleMappedClipped(const unsigned char* source, unsigned char* destination, int rows, int pitch, int x, int left, int right, const unsigned char* outer, const unsigned char* inner); // 0x00607480

void __fastcall sub_00607680_BlitMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00607680

void __fastcall sub_006077C0_BlitMappedClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pTable); // 0x006077C0

void __fastcall sub_00607970_BlitBlendMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x00607970

void __fastcall sub_00607B90_DrawRleTransBlend(const BYTE* pSrc, BYTE* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const BYTE* pTrans, const BYTE* pBlend); // 0x00607B90

void __fastcall sub_00607E20_BlitMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00607E20

void __fastcall sub_00607F60_BlitMappedClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pTable); // 0x00607F60

void __fastcall sub_00608110_BlitBlend(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00608110

void __fastcall sub_006082E0_BlitBlendClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pBlend); // 0x006082E0

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

int gdwGlobal_008F03C8; // 0x008F03C8

static void __stdcall sub_00606A10_EncodeRleCell(const unsigned char* pSrc, unsigned int nWidth, unsigned int nHeight, unsigned int dwFlags, unsigned char** ppOut, unsigned int* pnSize);

// 0x00604AA0
void __stdcall TileLibraryReleaseProject(int* pSlots, char* pEntry)
{
    if (pEntry)
    {
        int nValue = sub_00600760_GetValue(pEntry + 8);
        if (nValue)
        {
            for (int i = 0; i < 0x20; i++)
            {
                if (pSlots[i] == nValue)
                {
                    pSlots[i] = 0;
                    return;
                }
            }
        }
    }
}

// 0x00604DD0
double __stdcall sub_00604DD0_MinDouble(double a, double b)
{
    return a < b ? a : b;
}

// 0x00604FE0
double __stdcall sub_00604FE0_HueToRgb(double n1, double n2, double hue)
{
    if (hue > 360.0)
        hue -= 360.0;
    if (hue < 0.0)
        hue += 360.0;
    if (hue < 60.0)
        return n1 + (n2 - n1) * hue / 60.0;
    if (hue < 180.0)
        return n2;
    if (hue < 240.0)
        return n1 + (n2 - n1) * (240.0 - hue) / 60.0;
    return n1;
}

// 0x006051F0
void __stdcall DestroyD2Palette(void* pMemory)
{
    if (pMemory)
        sub_005179A4_FreeVirtualMemory(pMemory);
}

// 0x00605320
void __stdcall PaletteSetTransparency(unsigned int nColor)
{
    unsigned char nLow = (unsigned char)nColor;
    unsigned char nMid = (unsigned char)(nColor >> 8);
    unsigned char nHigh = (unsigned char)(nColor >> 16);
    gdwSwappedColor_008E9D38 = (((nLow << 8) | nMid) << 8) | nHigh;
}

// 0x006056C0
void __stdcall PaletteTestBackground(int nValue)
{
    gnGlobal_008E9028 = nValue;
}

// 0x00605840
void __stdcall PaletteFixBlack(int nValue)
{
    gnGlobal_008E9D3C = nValue;
}

// 0x00605850
void __stdcall PaletteSetMask(const unsigned char* pTable)
{
    memcpy(gaTable_008E9830, pTable, 0x100);
    gbTableSet_008E9D40 = 1;
}

// 0x00605A90
void __stdcall UpdateD2TransparencyTable(unsigned char* pData, int nUnused)
{
    sub_006059B0_BuildAdditiveTable(pData);
}

// 0x00606A10
static void __stdcall sub_00606A10_EncodeRleCell(const unsigned char* pSrc, unsigned int nWidth, unsigned int nHeight, unsigned int dwFlags, unsigned char** ppOut, unsigned int* pnSize)
{
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc((2 * nWidth + 1) * nHeight, szFastCmpFile, 37, 0);
    int nStride;
    unsigned char* pOut = pBuffer;
    int nRestReachedEnd;
    int nRunReachedEnd;
    unsigned int nRow = 0;
    if (!(dwFlags & 1))
    {
        pSrc += (nHeight - 1) * nWidth;
        nStride = -(int)nWidth;
    }
    else
    {
        nStride = nWidth;
    }

    const unsigned char* pNextRow = pSrc + nStride;
    const unsigned char* pRowEnd = pSrc + nWidth;
    while (nRow < nHeight)
    {
        if (*pSrc == 0)
        {
            const int nRun = sub_0060D280_ScanSameRun(pSrc, pRowEnd, 0x7F, &nRunReachedEnd, &nRestReachedEnd);
            if (!nRestReachedEnd && !nRunReachedEnd)
            {
                *pOut++ = (unsigned char)(nRun | 0x80);
                pSrc += nRun;
            }
            else
            {
                pSrc = pNextRow;
                pNextRow += nStride;
                pRowEnd += nStride;
                *pOut++ = 0x80;
                ++nRow;
            }
        }
        else
        {
            const unsigned int nRun = sub_0060D3A0_ScanOtherRun(pSrc, pRowEnd, 0, 0x7F, &nRunReachedEnd, &nRestReachedEnd);
            *pOut++ = (unsigned char)nRun;
            for (unsigned int i = 0; i < nRun; ++i)
            {
                *pOut++ = *pSrc++;
            }

            if (nRunReachedEnd)
            {
                pSrc = pNextRow;
                pNextRow += nStride;
                pRowEnd += nStride;
                *pOut++ = 0x80;
                ++nRow;
            }
        }
    }

    *ppOut = pBuffer;
    *pnSize = pOut - pBuffer;
}

// 0x00606B00
void __fastcall sub_00606B00_RemapRleCell(D2GfxCellStrc* pCell, const unsigned char* pRemap)
{
    int nRows = pCell->dwHeight;
    unsigned char* pData = pCell->pPixels;
    for (;;)
    {
        const char nCode = *pData++;
        if (nCode < 0)
        {
            if (!(nCode & 0x7F))
            {
                if (!--nRows)
                {
                    return;
                }
            }
        }
        else
        {
            for (int i = 0; i < nCode; ++i)
            {
                *pData = pRemap[*pData];
                ++pData;
            }
        }
    }
}

#pragma function(memcpy)

// 0x00606B50
void __fastcall sub_00606B50_CompressCellFile(D2CellFileStrc* pSrcFile, D2CellFileStrc* pDstFile, D2CmpMapColorFn pfnMapColor, D2CmpColorStrc tTransparent)
{
    D2_ASSERT(pSrcFile->dwFlags & 4, 206);
    for (unsigned int i = 0; i < pSrcFile->nDirections * pSrcFile->nFrames; ++i)
    {
        const unsigned int nPixels = pSrcFile->pGfxCells[i]->dwHeight * pSrcFile->pGfxCells[i]->dwWidth;
        unsigned char* pIndexed = (unsigned char*)FOG_Alloc(nPixels, ".\\SRC\\FastCmp.cpp", 212, 0);
        const unsigned char* pRgb = pSrcFile->pGfxCells[i]->pPixels;
        unsigned char* pWrite = pIndexed;
        for (unsigned int j = 0; j < nPixels; ++j)
        {
            if (pRgb[0] == tTransparent.nRed && pRgb[1] == tTransparent.nGreen && pRgb[2] == tTransparent.nBlue)
            {
                *pWrite++ = 0;
            }
            else
            {
                const unsigned char nIndex = pfnMapColor(pRgb[0], pRgb[1], pRgb[2]);
                D2_ASSERT(nIndex, 224);
                *pWrite++ = nIndex;
            }

            pRgb += 3;
        }

        unsigned char* pRle;
        unsigned int nRleSize;
        sub_00606A10_EncodeRleCell(pIndexed, pSrcFile->pGfxCells[i]->dwWidth, pSrcFile->pGfxCells[i]->dwHeight, pSrcFile->pGfxCells[i]->dwFlags, &pRle, &nRleSize);
        FOG_Free(pIndexed, ".\\SRC\\FastCmp.cpp", 240, 0);

        D2GfxCellStrc* pNew = (D2GfxCellStrc*)FOG_Alloc(nRleSize + sizeof(D2GfxCellStrc) - 1, ".\\SRC\\FastCmp.cpp", 242, 0);
        pNew->dwFlags = pSrcFile->pGfxCells[i]->dwFlags;
        pNew->dwWidth = pSrcFile->pGfxCells[i]->dwWidth;
        pNew->dwHeight = pSrcFile->pGfxCells[i]->dwHeight;
        pNew->nXOffset = pSrcFile->pGfxCells[i]->nXOffset;
        pNew->nYOffset = pSrcFile->pGfxCells[i]->nYOffset;
        pNew->unk0x14 = 0;
        pNew->dwParent = 0;
        pNew->dwLength = nRleSize;
        memcpy(pNew->pPixels, pRle, nRleSize);
        FOG_Free(pRle, ".\\SRC\\FastCmp.cpp", 253, 0);
        pDstFile->pGfxCells[i] = pNew;
    }
}

#pragma intrinsic(memcpy)

// 0x00606D40
void __fastcall sub_00606D40_RleCopyRows(const char* pSrc, char* pDst, int nLines, int nPitch)
{
    char* pNextLine = pDst + nPitch;
    while (1)
    {
        char nRun = *pSrc++;
        if (nRun < 0)
        {
            nRun &= 0x7F;
            if (!nRun)
            {
                if (--nLines == 0)
                    return;
                pDst = pNextLine;
                pNextLine += nPitch;
            }
            else
            {
                pDst += nRun;
            }
        }
        else
        {
            memcpy(pDst, pSrc, nRun);
            pSrc += nRun;
            pDst += nRun;
        }
    }
}

// 0x00606DA0
void __fastcall sub_00606DA0_RleCopyRowsClipped(const char* pSrc, char* pDst, int nLines, int nPitch, int nX, int nClipLeft, int nClipRight)
{
    int nLineX = nX;
    char* pNextLine = pDst + nPitch;
    while (1)
    {
        char nRun = *pSrc++;
        if (nRun < 0)
        {
            nRun &= 0x7F;
            if (!nRun)
            {
                if (--nLines == 0)
                    return;
                pDst = pNextLine;
                nX = nLineX;
                pNextLine += nPitch;
            }
            else
            {
                nX += nRun;
                pDst += nRun;
            }
        }
        else
        {
            int nSkip = nClipLeft - nX;
            if (nSkip < 0)
                nSkip = 0;
            int nEnd = nClipRight - nX;
            if (nEnd > nRun)
                nEnd = nRun;
            int nCount = nEnd - nSkip;
            if (nCount > 0)
                memcpy(pDst + nSkip, pSrc + nSkip, nCount);
            pSrc += nRun;
            nX += nRun;
            pDst += nRun;
        }
    }
}

// 0x00606E40
void __fastcall sub_00606E40_BlitBlendMapped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pMap, const unsigned char* pBlend)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
        case 6: pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
        case 5: pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
        case 4: pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
        case 3: pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
        case 2: pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
        case 1: pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pBlend[(pDst[7] << 8) + pMap[pSrc[7]]];
                pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
                pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
                pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
                pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
                pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
                pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
                pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// calling-convention shim (not game code)
void __stdcall sub_00606A10_Shim(const unsigned char* pSrc, unsigned int nWidth, unsigned int nHeight, unsigned int dwFlags, unsigned char** ppOut, unsigned int* pnSize)
{
    sub_00606A10_EncodeRleCell(pSrc, nWidth, nHeight, dwFlags, ppOut, pnSize);
}

// 0x00607060
void __fastcall sub_00607060_BlitClippedBlendMapped(const unsigned char* source,unsigned char* destination,int rows,int pitch,int x,int left,int right,const unsigned char* map,const unsigned char* blend)
{
 int initialX=x;
 unsigned char* next=destination+pitch;
 for(;;){
  char code=*source++;
  if(code<0){
   code&=0x7f;
   if(!code){
    if(!--rows)return;
    x=initialX;destination=next;next+=pitch;
   }else{x+=code;destination+=code;}
   continue;
  }
  int skip=left-x;
  if(skip<0)skip=0;
  int end=right-x;
  if(end>code)end=code;
  int count=end-skip;
  if(count>0){
   const unsigned char* savedSource=source;
   unsigned char* savedDestination=destination;
   source+=skip;destination+=skip;
   count>>=3;
   int rest=(end-skip)&7;
   switch(rest){
    case 7: destination[6]=blend[(destination[6]<<8)+map[source[6]]];
    case 6: destination[5]=blend[(destination[5]<<8)+map[source[5]]];
    case 5: destination[4]=blend[(destination[4]<<8)+map[source[4]]];
    case 4: destination[3]=blend[(destination[3]<<8)+map[source[3]]];
    case 3: destination[2]=blend[(destination[2]<<8)+map[source[2]]];
    case 2: destination[1]=blend[(destination[1]<<8)+map[source[1]]];
    case 1: destination[0]=blend[(destination[0]<<8)+map[source[0]]];
    case 0:
     destination+=rest;source+=rest;
     while(count--){
      destination[7]=blend[(destination[7]<<8)+map[source[7]]];
      destination[6]=blend[(destination[6]<<8)+map[source[6]]];
      destination[5]=blend[(destination[5]<<8)+map[source[5]]];
      destination[4]=blend[(destination[4]<<8)+map[source[4]]];
      destination[3]=blend[(destination[3]<<8)+map[source[3]]];
      destination[2]=blend[(destination[2]<<8)+map[source[2]]];
      destination[1]=blend[(destination[1]<<8)+map[source[1]]];
      destination[0]=blend[(destination[0]<<8)+map[source[0]]];
      destination+=8;source+=8;
     }
   }
   x+=code;source=savedSource+code;destination=savedDestination+code;
  }else{
   x+=code;source+=code;destination+=code;
  }
 }
}

// 0x006072F0
void __fastcall sub_006072F0_BlitDoubleMapped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pOuter, const unsigned char* pInner)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pOuter[pInner[pSrc[6]]];
        case 6: pDst[5] = pOuter[pInner[pSrc[5]]];
        case 5: pDst[4] = pOuter[pInner[pSrc[4]]];
        case 4: pDst[3] = pOuter[pInner[pSrc[3]]];
        case 3: pDst[2] = pOuter[pInner[pSrc[2]]];
        case 2: pDst[1] = pOuter[pInner[pSrc[1]]];
        case 1: pDst[0] = pOuter[pInner[pSrc[0]]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pOuter[pInner[pSrc[7]]];
                pDst[6] = pOuter[pInner[pSrc[6]]];
                pDst[5] = pOuter[pInner[pSrc[5]]];
                pDst[4] = pOuter[pInner[pSrc[4]]];
                pDst[3] = pOuter[pInner[pSrc[3]]];
                pDst[2] = pOuter[pInner[pSrc[2]]];
                pDst[1] = pOuter[pInner[pSrc[1]]];
                pDst[0] = pOuter[pInner[pSrc[0]]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x00607480
void __fastcall sub_00607480_BlitDoubleMappedClipped(const unsigned char* source, unsigned char* destination, int rows, int pitch, int x, int left, int right, const unsigned char* outer, const unsigned char* inner)
{
 int initialX=x;
 unsigned char* next=destination+pitch;
 for(;;){
  char code=*source++;
  if(code<0){
   code&=0x7f;
   if(!code){
    if(!--rows)return;
    x=initialX;destination=next;next+=pitch;
   }else{x+=code;destination+=code;}
   continue;
  }
  int skip=left-x;
  if(skip<0)skip=0;
  int end=right-x;
  if(end>code)end=code;
  int count=end-skip;
  if(count>0){
   const unsigned char* savedSource=source;
   unsigned char* savedDestination=destination;
   source+=skip;destination+=skip;
   count>>=3;
   switch((end-skip)&7){
    case 7: destination[6]=outer[inner[source[6]]];
    case 6: destination[5]=outer[inner[source[5]]];
    case 5: destination[4]=outer[inner[source[4]]];
    case 4: destination[3]=outer[inner[source[3]]];
    case 3: destination[2]=outer[inner[source[2]]];
    case 2: destination[1]=outer[inner[source[1]]];
    case 1: destination[0]=outer[inner[source[0]]];
    case 0:
     destination+=(end-skip)&7;source+=(end-skip)&7;
     if(count){
      do{
       destination[7]=outer[inner[source[7]]];
       destination[6]=outer[inner[source[6]]];
       destination[5]=outer[inner[source[5]]];
       destination[4]=outer[inner[source[4]]];
       destination[3]=outer[inner[source[3]]];
       destination[2]=outer[inner[source[2]]];
       destination[1]=outer[inner[source[1]]];
       destination[0]=outer[inner[source[0]]];
       --count;
       destination+=8;source+=8;
      }while(count);
     }
   }
   x+=code;source=savedSource+code;destination=savedDestination+code;
  }else{
   x+=code;source+=code;destination+=code;
  }
 }
}

// 0x00607680
void __fastcall sub_00607680_BlitMapped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pTable)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pTable[pSrc[6]];
        case 6: pDst[5] = pTable[pSrc[5]];
        case 5: pDst[4] = pTable[pSrc[4]];
        case 4: pDst[3] = pTable[pSrc[3]];
        case 3: pDst[2] = pTable[pSrc[2]];
        case 2: pDst[1] = pTable[pSrc[1]];
        case 1: pDst[0] = pTable[pSrc[0]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pTable[pSrc[7]];
                pDst[6] = pTable[pSrc[6]];
                pDst[5] = pTable[pSrc[5]];
                pDst[4] = pTable[pSrc[4]];
                pDst[3] = pTable[pSrc[3]];
                pDst[2] = pTable[pSrc[2]];
                pDst[1] = pTable[pSrc[1]];
                pDst[0] = pTable[pSrc[0]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x006077C0
void __fastcall sub_006077C0_BlitMappedClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pTable)
{
    const int nStartX = nX;
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                nX = nStartX;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                nX += nCode;
                pDst += nCode;
            }
            continue;
        }
        int nSkip = nClipLeft - nX;
        if (nSkip < 0)
            nSkip = 0;
        int nCount = nClipRight - nX;
        if (nCount > nCode)
            nCount = nCode;
        nCount -= nSkip;
        if (nCount > 0)
        {
            int nBlocks = nCount >> 3;
            const unsigned char* pRunSource = pSrc;
            unsigned char* pRunDestination = pDst;
            pSrc += nSkip;
            pDst += nSkip;
            nCount &= 7;
            switch (nCount)
            {
            case 7: pDst[6] = pTable[pSrc[6]];
            case 6: pDst[5] = pTable[pSrc[5]];
            case 5: pDst[4] = pTable[pSrc[4]];
            case 4: pDst[3] = pTable[pSrc[3]];
            case 3: pDst[2] = pTable[pSrc[2]];
            case 2: pDst[1] = pTable[pSrc[1]];
            case 1: pDst[0] = pTable[pSrc[0]];
            case 0:
                pDst += nCount;
                pSrc += nCount;
                if (nBlocks)
                {
                    do
                    {
                        pDst[7] = pTable[pSrc[7]];
                        pDst[6] = pTable[pSrc[6]];
                        pDst[5] = pTable[pSrc[5]];
                        pDst[4] = pTable[pSrc[4]];
                        pDst[3] = pTable[pSrc[3]];
                        pDst[2] = pTable[pSrc[2]];
                        pDst[1] = pTable[pSrc[1]];
                        pDst[0] = pTable[pSrc[0]];
                        --nBlocks;
                        pDst += 8;
                        pSrc += 8;
                    } while (nBlocks);
                }
            }
            nX += nCode;
            pSrc = pRunSource + nCode;
            pDst = pRunDestination + nCode;
            continue;
        }
        nX += nCode;
        pSrc += nCode;
        pDst += nCode;
    }
}

// 0x00607970
void __fastcall sub_00607970_BlitBlendMapped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pMap, const unsigned char* pBlend)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
        case 6: pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
        case 5: pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
        case 4: pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
        case 3: pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
        case 2: pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
        case 1: pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pBlend[(pDst[7] << 8) + pMap[pSrc[7]]];
                pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
                pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
                pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
                pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
                pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
                pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
                pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x00607B90
void __fastcall sub_00607B90_DrawRleTransBlend(const BYTE* pSrc, BYTE* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const BYTE* pTrans, const BYTE* pBlend)
{
    int nStartX = nX;
    BYTE* pLine = pDst + nPitch;

    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (--nRows == 0)
                {
                    return;
                }
                nX = nStartX;
                pDst = pLine;
                pLine += nPitch;
            }
            else
            {
                nX += nCode;
                pDst += nCode;
            }
        }
        else
        {
            int nStart = nClipLeft - nX;
            if (nStart < 0)
            {
                nStart = 0;
            }
            int nEnd = nClipRight - nX;
            if (nEnd > nCode)
            {
                nEnd = nCode;
            }
            int nCount = nEnd - nStart;

            if (nCount > 0)
            {
                int nBlocks = nCount >> 3;
                const BYTE* pRunSrc = pSrc;
                BYTE* pRunDst = pDst;
                pSrc += nStart;
                pDst += nStart;
                int nRem = nCount & 7;
                switch (nRem)
                {
                case 7: BLEND_PIXEL(6);
                case 6: BLEND_PIXEL(5);
                case 5: BLEND_PIXEL(4);
                case 4: BLEND_PIXEL(3);
                case 3: BLEND_PIXEL(2);
                case 2: BLEND_PIXEL(1);
                case 1: BLEND_PIXEL(0);
                case 0:
                    pDst += nRem;
                    pSrc += nRem;
                    while (nBlocks)
                    {
                        BLEND_PIXEL(7);
                        BLEND_PIXEL(6);
                        BLEND_PIXEL(5);
                        BLEND_PIXEL(4);
                        BLEND_PIXEL(3);
                        BLEND_PIXEL(2);
                        BLEND_PIXEL(1);
                        BLEND_PIXEL(0);
                        --nBlocks;
                        pDst += 8;
                        pSrc += 8;
                    }
                }
                nX += nCode;
                pSrc = pRunSrc + nCode;
                pDst = pRunDst + nCode;
            }
            else
            {
                nX += nCode;
                pSrc += nCode;
                pDst += nCode;
            }

        }
    }
}

// 0x00607E20
void __fastcall sub_00607E20_BlitMapped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pTable)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pTable[pSrc[6]];
        case 6: pDst[5] = pTable[pSrc[5]];
        case 5: pDst[4] = pTable[pSrc[4]];
        case 4: pDst[3] = pTable[pSrc[3]];
        case 3: pDst[2] = pTable[pSrc[2]];
        case 2: pDst[1] = pTable[pSrc[1]];
        case 1: pDst[0] = pTable[pSrc[0]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pTable[pSrc[7]];
                pDst[6] = pTable[pSrc[6]];
                pDst[5] = pTable[pSrc[5]];
                pDst[4] = pTable[pSrc[4]];
                pDst[3] = pTable[pSrc[3]];
                pDst[2] = pTable[pSrc[2]];
                pDst[1] = pTable[pSrc[1]];
                pDst[0] = pTable[pSrc[0]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x00607F60
void __fastcall sub_00607F60_BlitMappedClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pTable)
{
    const int nStartX = nX;
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                nX = nStartX;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                nX += nCode;
                pDst += nCode;
            }
            continue;
        }
        int nSkip = nClipLeft - nX;
        if (nSkip < 0)
            nSkip = 0;
        int nCount = nClipRight - nX;
        if (nCount > nCode)
            nCount = nCode;
        nCount -= nSkip;
        if (nCount > 0)
        {
            int nBlocks = nCount >> 3;
            const unsigned char* pRunSource = pSrc;
            unsigned char* pRunDestination = pDst;
            pSrc += nSkip;
            pDst += nSkip;
            nCount &= 7;
            switch (nCount)
            {
            case 7: pDst[6] = pTable[pSrc[6]];
            case 6: pDst[5] = pTable[pSrc[5]];
            case 5: pDst[4] = pTable[pSrc[4]];
            case 4: pDst[3] = pTable[pSrc[3]];
            case 3: pDst[2] = pTable[pSrc[2]];
            case 2: pDst[1] = pTable[pSrc[1]];
            case 1: pDst[0] = pTable[pSrc[0]];
            case 0:
                pDst += nCount;
                pSrc += nCount;
                if (nBlocks)
                {
                    do
                    {
                        pDst[7] = pTable[pSrc[7]];
                        pDst[6] = pTable[pSrc[6]];
                        pDst[5] = pTable[pSrc[5]];
                        pDst[4] = pTable[pSrc[4]];
                        pDst[3] = pTable[pSrc[3]];
                        pDst[2] = pTable[pSrc[2]];
                        pDst[1] = pTable[pSrc[1]];
                        pDst[0] = pTable[pSrc[0]];
                        --nBlocks;
                        pDst += 8;
                        pSrc += 8;
                    } while (nBlocks);
                }
            }
            nX += nCode;
            pSrc = pRunSource + nCode;
            pDst = pRunDestination + nCode;
            continue;
        }
        nX += nCode;
        pSrc += nCode;
        pDst += nCode;
    }
}

// 0x00608110
void __fastcall sub_00608110_BlitBlend(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pBlend)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
        case 6: pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
        case 5: pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
        case 4: pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
        case 3: pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
        case 2: pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
        case 1: pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pBlend[(pDst[7] << 8) + pSrc[7]];
                pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
                pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
                pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
                pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
                pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
                pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
                pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x006082E0
void __fastcall sub_006082E0_BlitBlendClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pBlend)
{
    const int nStartX = nX;
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                nX = nStartX;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                nX += nCode;
                pDst += nCode;
            }
            continue;
        }
        int nSkip = nClipLeft - nX;
        if (nSkip < 0)
            nSkip = 0;
        int nCount = nClipRight - nX;
        if (nCount > nCode)
            nCount = nCode;
        nCount -= nSkip;
        if (nCount > 0)
        {
            int nBlocks = nCount >> 3;
            const unsigned char* pRunSource = pSrc;
            unsigned char* pRunDestination = pDst;
            pSrc += nSkip;
            pDst += nSkip;
            nCount &= 7;
            switch (nCount)
            {
            case 7: pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
            case 6: pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
            case 5: pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
            case 4: pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
            case 3: pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
            case 2: pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
            case 1: pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
            case 0:
                if (nBlocks)
                {
                    pDst += nCount;
                    pSrc += nCount;
                    do
                    {
                        pDst[7] = pBlend[(pDst[7] << 8) + pSrc[7]];
                        pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
                        pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
                        pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
                        pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
                        pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
                        pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
                        pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
                        --nBlocks;
                        pDst += 8;
                        pSrc += 8;
                    } while (nBlocks);
                }
            }
            nX += nCode;
            pSrc = pRunSource + nCode;
            pDst = pRunDestination + nCode;
            continue;
        }
        nX += nCode;
        pSrc += nCode;
        pDst += nCode;
    }
}

int __cdecl sub_004067C0_SetBasePathToCurrent()
{
    return SFileSetBasePath(".\\");
}

void __cdecl sub_00413740_Nop()
{
}

// 0x00608520
int __cdecl D2CMPToggleCelDrawMode()
{
    return gdwGlobal_008F03C8 = (gdwGlobal_008F03C8 == 0);
}

// 0x00608540
void __fastcall sub_00608540_DrawCel(D2CelStrc* pCel, unsigned char* pDest, int nX, int nLeft, int nRight, int nPitch, int nSkipRows, int nRows, const unsigned char* pMapA, const unsigned char* pBlend, const unsigned char* pMapB)
{
    const int nStartX = nX;
    const int nWidth = pCel->width;
    if ((unsigned int)nPitch < (unsigned int)nWidth)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1514);
        exit(-1);
    }
    if ((unsigned int)(nSkipRows + nRows) > pCel->height)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1515);
        exit(-1);
    }

    const unsigned char* pSrc = sub_00606D10_SkipCelLines(pCel->pixels, nSkipRows);
    const int nStride = (pCel->flags & 1) ? nPitch : -nPitch;

    if (gnGenericRle_008F03C8)
    {
        unsigned char* pNextRow = pDest + nStride;
        for (;;)
        {
            char nCode = *pSrc++;
            if (nCode < 0)
            {
                nCode &= 0x7F;
                if (!nCode)
                {
                    nX = nStartX;
                    pDest = pNextRow;
                    pNextRow += nStride;
                    if (!--nRows)
                        return;
                }
                else
                {
                    nX += nCode;
                    pDest += nCode;
                }
                continue;
            }

            const int nRun = nCode;
            const unsigned char* pSrcEnd = pSrc + nRun;
            unsigned char* pDestEnd = pDest + nRun;
            int nCount = nRun;
            if (nLeft || nRight)
            {
                const int nSkip = D2_MAX(nLeft - nX, 0);
                int nEnd = D2_MAX(nRight - nX, 0);
                nEnd = D2_MIN(nEnd, nRun);
                nCount = nEnd - nSkip;
                if (nCount <= 0)
                {
                    nCount = 0;
                }
                else
                {
                    pDest += nSkip;
                    pSrc += nSkip;
                }
            }

            const unsigned char* pSrcStop = pSrc + nCount;
            if (pMapA)
            {
                if (pBlend)
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pBlend[pMapA[*pSrc] + (*pDest << 8)];
                        ++pSrc;
                        ++pDest;
                    }
                }
                else if (pMapB)
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pMapA[pMapB[*pSrc]];
                        ++pSrc;
                        ++pDest;
                    }
                }
                else
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pMapA[*pSrc];
                        ++pSrc;
                        ++pDest;
                    }
                }
            }
            else if (pMapB)
            {
                if (pBlend)
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pBlend[pMapB[*pSrc] + (*pDest << 8)];
                        ++pSrc;
                        ++pDest;
                    }
                }
                else
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pMapB[*pSrc];
                        ++pSrc;
                        ++pDest;
                    }
                }
            }
            else if (pBlend)
            {
                while (pSrc < pSrcStop)
                {
                    *pDest = pBlend[*pSrc + (*pDest << 8)];
                    ++pSrc;
                    ++pDest;
                }
            }
            else
            {
                while (pSrc < pSrcStop)
                {
                    *pDest = *pSrc;
                    ++pSrc;
                    ++pDest;
                }
            }

            nX += nRun;
            pSrc = pSrcEnd;
            pDest = pDestEnd;
        }
    }

    const int bUnclipped = (!nLeft && !nRight) || (nX >= nLeft && nX + nWidth < nRight);
    if (pMapA)
    {
        if (pBlend)
        {
            if (bUnclipped)
                sub_00606E40_BlitBlendMapped(pSrc, pDest, nRows, nStride, pMapA, pBlend);
            else
                sub_00607060_BlitClippedBlendMapped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapA, pBlend);
        }
        else if (pMapB)
        {
            if (bUnclipped)
                sub_006072F0_BlitDoubleMapped(pSrc, pDest, nRows, nStride, pMapA, pMapB);
            else
                sub_00607480_BlitDoubleMappedClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapA, pMapB);
        }
        else
        {
            if (bUnclipped)
                sub_00607680_BlitMapped(pSrc, pDest, nRows, nStride, pMapA);
            else
                sub_006077C0_BlitMappedClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapA);
        }
    }
    else if (pMapB)
    {
        if (pBlend)
        {
            if (bUnclipped)
                sub_00607970_BlitBlendMapped(pSrc, pDest, nRows, nStride, pMapB, pBlend);
            else
                sub_00607B90_DrawRleTransBlend(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapB, pBlend);
        }
        else
        {
            if (bUnclipped)
                sub_00607E20_BlitMapped(pSrc, pDest, nRows, nStride, pMapB);
            else
                sub_00607F60_BlitMappedClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapB);
        }
    }
    else if (pBlend)
    {
        if (bUnclipped)
            sub_00608110_BlitBlend(pSrc, pDest, nRows, nStride, pBlend);
        else
            sub_006082E0_BlitBlendClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pBlend);
    }
    else
    {
        if (bUnclipped)
            sub_00606D40_RleCopyRows(pSrc, pDest, nRows, nStride);
        else
            sub_00606DA0_RleCopyRowsClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight);
    }
}

// 0x006089F0
void __fastcall sub_006089F0_BuildRemap(int nPitch)
{
    int aInside[80][80];

    for (int y = 0; y < 80; ++y)
    {
        for (int x = 0; x < 80; ++x)
        {
            int nDX = x - 40;
            int nNewX = nDX;
            int nDY = y - 40;
            int nDist = nDX * nDX + nDY * nDY;
            aInside[x][y] = nDist < 1600;
            if (aInside[x][y])
            {
                int nScaled = nDist * nDist / 1600;
                nDist = (int)(float)sqrt((double)nDist);
                nScaled = (int)(float)sqrt((double)nScaled);
                if (nScaled < nDist / 2)
                    nScaled = nDist / 2;

                if (nDist)
                {
                    nNewX = nDX * nScaled / nDist;
                    nDY = nScaled * nDY / nDist;
                }

                int nSrcX = nNewX + 40;
                nDY += 40;
                nSrcX = ((nSrcX <= 0) - 1) & nSrcX;
                const int nClampX = D2_MIN(nSrcX, 79);
                int nSrcY = ((nDY <= 0) - 1) & nDY;
                nSrcY = D2_MIN(nSrcY, 79);
                gnRemapOffsets_008E9FC8[y * 80 + x] = (nSrcY - y) * nPitch - x + nClampX;
            }
        }
    }

    for (int y = 0; y < 80; ++y)
    {
        gnRemapStart_008E9D48[y] = 0;
        gnRemapEnd_008E9E88[y] = 0;

        int x;
        for (x = 0; x < 80; ++x)
        {
            if (aInside[x][y])
                break;
        }

        if (x < 80)
        {
            gnRemapStart_008E9D48[y] = x;
            while (aInside[x][y])
                ++x;
            gnRemapEnd_008E9E88[y] = x;
        }
    }
}

// 0x00608C00
void __stdcall CmpDoLensEffect(unsigned char* pBuffer, int nPitch)
{
    unsigned char* pRow = pBuffer;
    int nBase = 0;
    for (int y = 0; y < 40; y++)
    {
        int nIndex = gnRemapStart_008E9D48[y] + nBase;
        unsigned char* p = pRow + gnRemapStart_008E9D48[y];
        unsigned char* pEnd = pRow + (gnRemapEnd_008E9E88[y] < 41 ? gnRemapEnd_008E9E88[y] : 41);
        for (; p < pEnd; p++, nIndex++)
            *p = p[gnRemapOffsets_008E9FC8[nIndex]];

        nIndex = gnRemapEnd_008E9E88[y] + nBase;
        p = pRow + gnRemapEnd_008E9E88[y];
        pEnd = pRow + (gnRemapStart_008E9D48[y] >= 40 ? gnRemapStart_008E9D48[y] : 40);
        for (; p > pEnd; p--, nIndex--)
            *p = p[gnRemapOffsets_008E9FC8[nIndex]];

        nBase += 80;
        pRow += nPitch;
    }

    pRow = pBuffer + 79 * nPitch;
    nBase = 79 * 80;
    for (int y = 79; y >= 40; y--)
    {
        int nIndex = gnRemapStart_008E9D48[y] + nBase;
        unsigned char* p = pRow + gnRemapStart_008E9D48[y];
        unsigned char* pEnd = pRow + (gnRemapEnd_008E9E88[y] < 41 ? gnRemapEnd_008E9E88[y] : 41);
        for (; p < pEnd; p++, nIndex++)
            *p = p[gnRemapOffsets_008E9FC8[nIndex]];

        nIndex = gnRemapEnd_008E9E88[y] + nBase;
        p = pRow + gnRemapEnd_008E9E88[y];
        pEnd = pRow + (gnRemapStart_008E9D48[y] >= 40 ? gnRemapStart_008E9D48[y] : 40);
        for (; p > pEnd; p--, nIndex--)
            *p = p[gnRemapOffsets_008E9FC8[nIndex]];

        nBase -= 80;
        pRow -= nPitch;
    }
}

static inline const char* __fastcall SkipCelRows(const char* current,int rows)
{
 if(!rows) return current;
 for(;;) {
  const char code=*current++;
  if(code<0) {
   if(!(code&127) && !--rows) break;
  } else current+=code;
 }
 return current;
}

// 0x00608D60
void __fastcall sub_00608D60_DrawCelShadowLines(const D2CelStrc* cel,unsigned char* dst,int x,int clipLeft,int clipRight,unsigned int pitch,int skip,int rows,const unsigned char* table,int color)
{
 int startX=x;
 if(pitch<cel->width) { sub_00408A60(gszEmptyAssert,sub_00408090(),1871);exit(-1); }
 const char* src=SkipCelRows((const char*)cel+32,skip*2);
 int step=-(int)pitch;
 unsigned char* nextRow=dst+step;
 for(;;) {
  char code=*src++;
  if(code<0) {
   code&=127;
   if(!code) {
    dst=nextRow-1;
    nextRow+=step-1;
    --startX;
    x=startX;
    if(!--rows) return;
    do {
     code=*src++;
     if(code>0) src+=code;
     else code&=127;
    } while(code);
   } else {
    x+=code;
    dst+=code;
   }
   continue;
  }
  int count=code;
  unsigned char* next=dst+count;
  int length=count;
  if(clipLeft || clipRight) {
   int left=clipLeft-x>0?clipLeft-x:0;
   int right=clipRight-x>0?clipRight-x:0;
   length=(right<count?right:count)-left;
   if(length<=0) goto advance;
   dst+=left;
  }
  if(length) {
   if(table) {
    unsigned char* end=dst+length;
    while(dst<end) {
     *dst=table[(*dst<<8)+(unsigned char)color];
     ++dst;
    }
   } else memset(dst,(unsigned char)color,length);
  }
 advance:
  x+=count;
  dst=next;
  src+=count;
 }
}

// 0x00608EE0
void __fastcall sub_00608EE0_CompressCellList(D2CmpCellListStrc* pList, D2CellFileStrc* pDstFile)
{
    D2_ASSERT(!(pList->dwFlags & 4), 0x72);
    const unsigned int nFrames = pList->nCells / pList->nDirections;
    unsigned int i = 0;
    for (D2CmpCellNodeStrc* pNode = (D2CmpCellNodeStrc*)((((int)pList->pHead <= 0) - 1) & (int)pList->pHead); (int)pNode > 0; pNode = pNode->pNext)
    {
        unsigned char* pRle;
        unsigned int nRleSize;
        sub_00606A10_EncodeRleCell(pNode->pPixels, pNode->dwWidth, pNode->dwHeight, pNode->dwFlags, &pRle, &nRleSize);

        D2GfxCellStrc* pNew = (D2GfxCellStrc*)FOG_Alloc(nRleSize + sizeof(D2GfxCellStrc) - 1, ".\\SRC\\FastCmp.cpp", 0x82, 0);
        pNew->dwFlags = pNode->dwFlags;
        pNew->dwWidth = pNode->dwWidth;
        pNew->dwHeight = pNode->dwHeight;
        pNew->nXOffset = pNode->nXOffset;
        pNew->nYOffset = pNode->nYOffset;
        pNew->unk0x14 = 0;
        pNew->dwParent = 0;
        pNew->dwLength = nRleSize;
        memcpy(pNew->pPixels, pRle, nRleSize);
        FOG_Free(pRle, ".\\SRC\\FastCmp.cpp", 0x8D, 0);

        const unsigned int nDirections = pList->nDirections;
        const int nDirection = nDirections > 1 ? ((i / nFrames) << 6) / nDirections : 1;
        pDstFile->pGfxCells[sub_00600C90_GetDirectionIndex64(nDirection, nDirections) * nFrames + i % nFrames] = pNew;
        ++i;
    }
}

// 0x006096D0
D2CmpTileStrc* __stdcall TileListAddTile(D2CmpTileListStrc* ptList, short nValue16, short nValue14, int nValue24, int nValue28, int nValue2C, int nValue30, int nValue10, const D2CmpTileInfoStrc* pInfo)
{
    D2_ASSERT(ptList, 0xA2);
    D2CmpTileStrc* pTile = sub_00609550_AllocTile();
    D2_ASSERT(pTile, 0xA6);
    pTile->pNext = ptList->pFirst;
    ptList->nCount++;
    ptList->pFirst = pTile;
    pTile->unk0x16 = nValue16;
    pTile->nValue14 = nValue14;
    pTile->nValue24 = nValue24;
    pTile->nValue28 = nValue28;
    pTile->nValue2C = nValue2C;
    pTile->nValue30 = nValue30;
    pTile->nValue10 = nValue10;
    pTile->nOwnerId = ptList->nId;
    pTile->nType = 2;
    pTile->tInfo = *pInfo;
    return pTile;
}

// 0x0060AEB0
void __fastcall sub_0060AEB0_FreeEntry(D2CelDataHashStrc* pHash, T00604AE0* pEntry, void* pMemPool)
{
    if (pHash->pBuckets[pEntry->nKey] == pEntry)
        pHash->pBuckets[pEntry->nKey] = pEntry->pNext;
    FOG_FreePool(pMemPool, pEntry, ".\\SRC\\CelDataHash.cpp", 0x3A, 0);
}

// 0x0060AF00
void __fastcall sub_0060AF00_FreeAll(void* pMemPool, D2CelDataHashStrc* pHash)
{
    for (unsigned int i = 0; i < 0x200; i++)
    {
        T00604AE0* pEntry = pHash->pBuckets[i];
        while (pEntry)
        {
            T00604AE0* pNext = pEntry->pNext;
            sub_0060AEB0_FreeEntry(pHash, pEntry, pMemPool);
            pEntry = pNext;
        }
        D2_ASSERT(!pHash->nCheck[i], 0x5B);
    }
}

// 0x0060B1A0
void D2CmpBitCursorStrc::sub_0060B1A0_AdvanceBits(int nBits)
{
    int nPos = nBitPos + nBits;
    nBitPos = nPos & 0x1F;
    pData += nPos / 32;
}

// 0x0060CD70
unsigned char __fastcall sub_0060CD70_WrapIndex(unsigned char a, unsigned char b, unsigned char c)
{
    unsigned char nResult = (unsigned char)(2 * a - c + b) % 128;
    D2_ASSERT(nResult < 128, 0x1E);
    return nResult;
}

// 0x0060D310
int __fastcall sub_0060D310_ScanRun(unsigned char nValue, const unsigned char* pData, const unsigned char* pEnd, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd)
{
    D2_ASSERT(pData < pEnd, 0x45);
    int nCount = 0;
    while (pData < pEnd && nValue == *pData && nCount < nMax)
    {
        ++pData;
        ++nCount;
    }
    if (pData == pEnd)
    {
        *pbRunReachedEnd = 1;
        *pbRestReachedEnd = 0;
        return nCount;
    }
    *pbRunReachedEnd = 0;
    while (pData < pEnd && nValue == *pData)
        ++pData;
    *pbRestReachedEnd = pData == pEnd;
    return nCount;
}


// 0x0060DD20
int D2CmpStringStrc::sub_0060DD20_EqualsNoCase(const D2CmpStringStrc* pOther)
{
    return !SStrCmpI(szText, pOther->szText, 0x7FFFFFFF);
}

#include "gen/data/Source/D2CMP/SRC/FastCmp.inc"
