#include "D2CMP.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define BLEND_PIXEL(i) pDst[i] = pBlend[(pDst[i] << 8) + pTrans[pSrc[i]]]
#define D2_MAX(a,b) ((a)>(b)?(a):(b))
#define D2_MIN(a,b) ((a)<(b)?(a):(b))

struct D2GfxCellStrc;
struct D2CellFileStrc;
struct D2CmpColorStrc;
struct D2CelStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __fastcall sub_0060D280_ScanSameRun(const unsigned char* pData, const unsigned char* pEnd, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D280
int __fastcall sub_0060D3A0_ScanOtherRun(const unsigned char* pData, const unsigned char* pEnd, unsigned char nValue, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D3A0

struct D2GfxCellStrc
{
    unsigned int dwFlags;
    unsigned int dwWidth;
    unsigned int dwHeight;
    int nXOffset;
    int nYOffset;
    unsigned int unk0x14;
    unsigned int dwParent;
    unsigned int dwLength;
    unsigned char pPixels[1];
};

struct D2CellFileStrc
{
    unsigned int dwVersion;
    unsigned int dwFlags;
    unsigned int eFormat;
    unsigned int dwTermination;
    unsigned int nDirections;
    unsigned int nFrames;
    D2GfxCellStrc* pGfxCells[1];
};

struct D2CmpColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nPad;
};

typedef unsigned char (__stdcall* D2CmpMapColorFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

typedef unsigned char BYTE;

struct D2CelStrc { unsigned int flags,width,height; unsigned char unknown0C[0x14]; unsigned char pixels[1]; };

extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern int gnGenericRle_008F03C8; // 0x008F03C8
const unsigned char* __fastcall sub_00606D10_SkipCelLines(const unsigned char*,int); // 0x00606D10
void __fastcall sub_00606D40_RleCopyRows(const unsigned char*,unsigned char*,int,int); // 0x00606D40
void __fastcall sub_00606DA0_RleCopyRowsClipped(const unsigned char*,unsigned char*,int,int,int,int,int); // 0x00606DA0
void __fastcall sub_00606E40_BlitBlendMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x00606E40
void __fastcall sub_00607060_BlitClippedBlendMapped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*,const unsigned char*); // 0x00607060
void __fastcall sub_006072F0_BlitDoubleMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x006072F0
void __fastcall sub_00607480_BlitClippedDoubleMapped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*,const unsigned char*); // 0x00607480
void __fastcall sub_00607680_BlitMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00607680
void __fastcall sub_006077C0_BlitClippedMapped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*); // 0x006077C0
void __fastcall sub_00607970_BlitBlendMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x00607970
void __fastcall sub_00607B90_BlitClippedBlendMapped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*,const unsigned char*); // 0x00607B90
void __fastcall sub_00607E20_BlitMapped(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00607E20
void __fastcall sub_00607F60_BlitClippedMapped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*); // 0x00607F60
void __fastcall sub_00608110_BlitBlend(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00608110
void __fastcall sub_006082E0_BlitClippedBlend(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*); // 0x006082E0

// 0x00606A10
static __declspec(noinline) void __stdcall sub_00606A10_EncodeRleCell(const unsigned char* pSrc, unsigned int nWidth, unsigned int nHeight, unsigned int dwFlags, unsigned char** ppOut, unsigned int* pnSize)
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
                sub_00607480_BlitClippedDoubleMapped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapA, pMapB);
        }
        else
        {
            if (bUnclipped)
                sub_00607680_BlitMapped(pSrc, pDest, nRows, nStride, pMapA);
            else
                sub_006077C0_BlitClippedMapped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapA);
        }
    }
    else if (pMapB)
    {
        if (pBlend)
        {
            if (bUnclipped)
                sub_00607970_BlitBlendMapped(pSrc, pDest, nRows, nStride, pMapB, pBlend);
            else
                sub_00607B90_BlitClippedBlendMapped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapB, pBlend);
        }
        else
        {
            if (bUnclipped)
                sub_00607E20_BlitMapped(pSrc, pDest, nRows, nStride, pMapB);
            else
                sub_00607F60_BlitClippedMapped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapB);
        }
    }
    else if (pBlend)
    {
        if (bUnclipped)
            sub_00608110_BlitBlend(pSrc, pDest, nRows, nStride, pBlend);
        else
            sub_006082E0_BlitClippedBlend(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pBlend);
    }
    else
    {
        if (bUnclipped)
            sub_00606D40_RleCopyRows(pSrc, pDest, nRows, nStride);
        else
            sub_00606DA0_RleCopyRowsClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight);
    }
}
