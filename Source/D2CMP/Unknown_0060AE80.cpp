#include "D2CMP.h"

struct D2CmpBitCursorStrc;
struct D2CmpByteMapStrc;
struct D2CmpByteRunStrc;
struct D2DccFrameStrc;
struct D2DccDirStrc;
struct D2DccIterStrc;
struct D2BitBufferInitStrc;
struct D2SpritePixelsStrc;
struct D2SpriteCelStrc;
struct D2CmpTileFileHeaderStrc;
struct D2CmpTileHeaderTargetStrc;

struct D2CmpBitCursorStrc
{
    int* pStart;
    int* pData;
    int unk0x08;
    int f_C;

    unsigned char* sub_0060B180_GetBytePtr();
    void sub_0060B1D0_AlignToByte();
    int sub_0060B1F0_GetBitPos();
};

struct D2CmpByteRunStrc
{
    unsigned char* pData;
    int nCount;
};

struct D2DccFrameStrc
{
    int nUnk0x00;
    int nWidth;
    int nHeight;
    int nXOffset;
    int nYOffset;
    int nUnk0x14[3];
    int nCellsX;
    int nCellsY;
    int bBottomUp;
};

struct D2DccDirStrc
{
    int nUnk0x00;
    D2DccFrameStrc* pFrames;
    int nMinX;
    int nMinY;
    int nBoxWidth;
    int f_14;
    int nUnk0x18;
    int nFrames;
    int nCells;
    int nCellsTotal;
    int nCellsPerRow;
};

struct D2DccIterStrc
{
    int nFrame;
    int nWidth;
    int nHeight;
    int nX0;
    int nY0;
    int nCellsX;
    int nCellsY;
    int nCellRow;
    int nCell;
    int nX;
    int nY;
    int f_2C;
    int nPixel;
    int nStepX;
    int nStepY;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2BitBufferInitStrc
{
    unsigned char* pBuffer;
    unsigned char* pCurrent;
    int nBits;
    int nPos;
};

struct D2SpritePixelsStrc { int unknown00,width,height; char unknown0C[0x14]; unsigned char* pixels; int pitch; int topDown; };

struct D2SpriteCelStrc { int unknown00[7]; unsigned int dataSize; };

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610
void* __cdecl sub_006829C0_Copy(void* dest,const void* source,unsigned int size); // 0x006829C0

#pragma pack(push, 1)
struct D2CmpTileFileHeaderStrc
{
    unsigned char nType;
    unsigned char nByte1;
    unsigned char nCount;
    int nDword3;
    int nDword7;
    int nUnk0x0B;
};

#pragma pack(pop)
struct D2CmpTileHeaderTargetStrc
{
    unsigned char bFlags;
    char pad0x01[3];
    int nByte1;
    int nDword7;
    int nZero0C;
    int f_10;
    int nCount;
    int nDword3;
    unsigned int adwData[33];
};

int __fastcall sub_004068E0(const char* szFileName, void** phFile); // 0x004068E0
int __fastcall sub_004068F0(void* pArg); // 0x004068F0
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900
int __fastcall sub_00406930(void* hFile, unsigned int* pnSizeHigh); // 0x00406930

static int sub_0060B2B0_DccNextCell(D2DccDirStrc* pDir, D2DccIterStrc* pIt);

// 0x0060AE80
static __declspec(noinline) unsigned int sub_0060AE80_GetCelDataHashKey(const char* szName)
{
    unsigned int nHash = SStrHash(szName, 1, 0);
    return ((nHash ^ (nHash >> 8)) ^ ((nHash ^ (nHash >> 8)) >> 16)) & 0x1FF;
}

unsigned int __fastcall sub_M383_Emit_0060AE80(int nAdd, const char* szName)
{
    return sub_0060AE80_GetCelDataHashKey(szName) + nAdd * 3;
}

// 0x0060B130
void __cdecl sub_0060B130_Nothing()
{
}

// 0x0060B180
unsigned char* D2CmpBitCursorStrc::sub_0060B180_GetBytePtr()
{
    return (unsigned char*)pData + (f_C + 7) / 8;
}

// 0x0060B1D0
void D2CmpBitCursorStrc::sub_0060B1D0_AlignToByte()
{
    const unsigned int nPos = (f_C + 7) & ~7u;
    f_C = nPos & 0x1F;
    pData += nPos / 32;
}

// 0x0060B1F0
int D2CmpBitCursorStrc::sub_0060B1F0_GetBitPos()
{
    return (pData - pStart) * 32 + f_C;
}

// 0x0060B480
static __forceinline int sub_0060B480_DccFirstCell(D2DccDirStrc* pDir, D2DccIterStrc* pIt)
{
    if (!pDir->nFrames)
    {
        return 0;
    }
    memset(pIt, 0, sizeof(*pIt));
    pIt->nFrame = -1;
    return sub_0060B2B0_DccNextCell(pDir, pIt);
}

static __forceinline void __stdcall sub_0060B5F0_BuildColorMaps(D2CmpByteMapStrc* pInverse, const unsigned char* pFlags, D2CmpByteMapStrc* pForward)
{
    int i;
    int n;
    for (i = 0, n = 0; i < 0x100; ++i)
    {
        if (pFlags[i])
        {
            pForward->ab[i] = (unsigned char)n;
            pInverse->ab[n] = (unsigned char)i;
            ++n;
        }
    }
    pForward->nCount = 0x100;
    pInverse->nCount = n;
}

// 0x0060B640
void __fastcall sub_0060B640_BuildColorMaps(D2CmpByteMapStrc* pInverse, const unsigned int* pBits, D2CmpByteMapStrc* pForward)
{
    unsigned char abFlags[0x100];
    for (int i = 0; i < 0x100; ++i)
    {
        abFlags[i] = (pBits[i >> 5] & gdwBitMasks_006CE268[i & 0x1F]) != 0;
    }
    sub_0060B5F0_BuildColorMaps(pInverse, abFlags, pForward);
}

// 0x0060B780
static __forceinline int sub_0060B780_GetRunBits(const unsigned char* pBytes)
{
    int nBits;
    for (nBits = 0; (1 << nBits) + 1 <= 4 && pBytes[1 << nBits] != pBytes[(1 << nBits) - 1]; ++nBits)
    {
    }
    return nBits;
}

// 0x0060BD90
static __forceinline void sub_0060BD90_RemapRun(D2CmpByteRunStrc* pRun, const unsigned char* pTable)
{
    for (int i = 0; i < pRun->nCount; ++i)
    {
        pRun->pData[i] = pTable[pRun->pData[i]];
    }
}

int sub_M123_Emit_0060B480(D2DccDirStrc* pDir)
{
    D2DccIterStrc tIt;
    int n = 0;
    if (sub_0060B480_DccFirstCell(pDir, &tIt))
    {
        do
        {
            ++n;
        } while (sub_0060B2B0_DccNextCell(pDir, &tIt));
    }
    return n;
}

int sub_M123_Emit_0060B780(const unsigned char* pBytes)
{
    return sub_0060B780_GetRunBits(pBytes + 0x10);
}

void sub_M123_Emit_0060BD90(D2CmpByteRunStrc* pRun, const unsigned char* pTable)
{
    sub_0060BD90_RemapRun(pRun, pTable);
}

// 0x0060B140
static void __stdcall sub_0060B140_BitBufferInit(int nSize, unsigned char* pBuffer, D2BitBufferInitStrc* pBitBuf)
{
    pBitBuf->pBuffer = pBuffer;
    pBitBuf->pCurrent = pBuffer;
    pBitBuf->nBits = nSize * 8;
    pBitBuf->nPos = 0;
}

void __stdcall sub_K13_Emit_0060B140(D2BitBufferInitStrc* pBitBuf, unsigned char* pBuffer, int nSize)
{
    sub_0060B140_BitBufferInit(nSize, pBuffer, pBitBuf);
}

// 0x0060B2B0
static int sub_0060B2B0_DccNextCell(D2DccDirStrc* pDir, D2DccIterStrc* pIt)
{
    pIt->nX += pIt->nStepX;
    if (pIt->nX < pIt->nWidth)
    {
        pIt->nPixel += pIt->nStepX;
        ++pIt->nCell;
        pIt->nStepX = pIt->nX + 5 < pIt->nWidth ? 4 : pIt->nWidth - pIt->nX;
        return 1;
    }

    pIt->nY += pIt->nStepY;
    if (pIt->nY < pIt->nHeight)
    {
        const int nRemX = -(pIt->nX0 % 4);
        pIt->nX = 0;
        pIt->nStepX = nRemX + 5 < pIt->nWidth ? nRemX + 4 : pIt->nWidth;
        pIt->f_2C += pIt->nCellsY * pIt->nStepY;
        pIt->nPixel = pIt->f_2C;
        pIt->nCellRow += pDir->nCellsPerRow;
        pIt->nCell = pIt->nCellRow;
        pIt->nStepY = pIt->nY + 5 < pIt->nHeight ? 4 : pIt->nHeight - pIt->nY;
        return 1;
    }

    ++pIt->nFrame;
    D2DccFrameStrc* pFrame = &pDir->pFrames[pIt->nFrame];
    for (; pIt->nFrame < pDir->nFrames; ++pIt->nFrame, ++pFrame)
    {
        if (pFrame->nWidth && pFrame->nHeight)
        {
            pIt->nWidth = pFrame->nWidth;
            pIt->nHeight = pFrame->nHeight;
            pIt->nX0 = pFrame->nXOffset - pDir->nMinX;
            pIt->nY0 = pFrame->nYOffset - pDir->nMinY - (pFrame->bBottomUp ? 0 : pFrame->nHeight);
            pIt->nCellsX = pFrame->nCellsX;
            pIt->nCellsY = pFrame->nCellsY;
            pIt->nCellRow = pIt->nY0 / 4 * pDir->nCellsPerRow + pIt->nX0 / 4;
            pIt->nCell = pIt->nCellRow;
            pIt->nX = 0;
            pIt->nY = 0;
            pIt->f_2C = 0;
            pIt->nPixel = 0;
            const int nRemX = -(pIt->nX0 % 4);
            const int nRemY = -(pIt->nY0 % 4);
            pIt->nStepX = nRemX + 5 < pIt->nWidth ? nRemX + 4 : pIt->nWidth;
            pIt->nStepY = nRemY + 5 < pIt->nHeight ? nRemY + 4 : pIt->nHeight;
            return 1;
        }
    }

    return 0;
}

// 0x0060B4B0
static void sub_0060B4B0_DccCountCells(D2DccDirStrc* pDir)
{
    const int nCellsX = (pDir->nBoxWidth + 3) / 4;
    const int nCellsY = (pDir->f_14 + 3) / 4;
    pDir->nCellsPerRow = nCellsX;
    pDir->nCellsTotal = nCellsY * nCellsX;
    pDir->nCells = 0;
    if (pDir->nFrames)
    {
        D2DccIterStrc iter;
        memset(&iter, 0, sizeof(iter));
        iter.nFrame = -1;
        if (sub_0060B2B0_DccNextCell(pDir, &iter))
        {
            do
            {
                ++pDir->nCells;
            }
            while (sub_0060B2B0_DccNextCell(pDir, &iter));
        }
    }
}

void sub_A22_Emit_0060B4B0(D2DccDirStrc* pDir)
{
    sub_0060B4B0_DccCountCells(pDir);
}

// 0x0060BDB0
int __fastcall sub_0060BDB0_EncodeSprite(D2SpritePixelsStrc* sprite,D2SpriteCelStrc* cel,unsigned char* output)
{
 unsigned char* dest=output;
 unsigned char* row=sprite->pixels;
 int y;
 int step=sprite->topDown?sprite->pitch:-sprite->pitch;
 if(!sprite->topDown) row+=(sprite->height-1)*sprite->pitch;
 for(y=0;y<sprite->height;) {
  int x=0;
  while(x<sprite->width) {
   int start=x;
   while(x<sprite->width && !row[x]) ++x;
   if(x>=sprite->width) break;
   if(x>start) do {
    int count=x-start;
    if(count>127) count=127;
    *dest++=(unsigned char)(count|0x80);
    start+=count;
   } while(start<x);
   start=x;
   while(x<sprite->width && row[x]) ++x;
   if(x>start) do {
    int count=x-start;
    if(count>127) count=127;
    *dest++=(unsigned char)count;
    sub_006829C0_Copy(dest,row+start,count);
    dest+=count;
    start+=count;
   } while(start<x);
  }
  *dest++=0x80;
  ++y;
  row+=step;
 }
 if(dest!=(unsigned char*)cel+32+cel->dataSize) {
  sub_00410610_WriteLogLine("Sprite Decompression Error");
  return 0;
 }
 return 1;
}

// 0x0060BF20
int __fastcall sub_0060BF20_LoadTileHeader(const char* szFile, D2CmpTileHeaderTargetStrc* pTarget)
{
    void* hFile;
    sub_004068E0(szFile, &hFile);
    if (!hFile)
    {
        return 0;
    }

    D2CmpTileFileHeaderStrc tHeader;
    int nRead;
    int bLoaded = 0;
    if (sub_00406900(hFile, &tHeader, sizeof(tHeader), &nRead, 0, 0, 0) && nRead == sizeof(tHeader) && tHeader.nType == 't')
    {
        pTarget->nByte1 = tHeader.nByte1;
        pTarget->nDword7 = tHeader.nDword7;
        pTarget->nZero0C = 0;
        pTarget->nCount = tHeader.nCount;
        pTarget->nDword3 = tHeader.nDword3;
        if (tHeader.nCount > 32)
        {
            tHeader.nCount = 32;
        }

        const int nSize = tHeader.nCount * sizeof(unsigned int);
        if (sub_00406900(hFile, pTarget->adwData, nSize, &nRead, 0, 0, 0) && nRead == nSize)
        {
            bLoaded = 1;
        }
    }

    if (!bLoaded)
    {
        sub_004068F0(hFile);
        return 0;
    }

    pTarget->adwData[tHeader.nCount] = sub_00406930(hFile, 0);
    sub_004068F0(hFile);
    pTarget->bFlags |= 2;
    return 1;
}
