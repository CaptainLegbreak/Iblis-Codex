#include "D2CMP.h"

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

struct D2CmpTileStrc
{
    char unk0x00[0x10];
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
    char unk0x52[0x0A];
    D2CmpTileStrc* pNext;
};

struct D2CmpTileListStrc
{
    int unk0x00;
    int nId;
    int nCount;
    D2CmpTileStrc* pFirst;
};

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

struct D2CmpBitCursorStrc
{
    int unk0x00;
    int* pData;
    int unk0x08;
    int f_C;

    void sub_0060B1A0_AdvanceBits(int nBits);
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
extern int gnRemapStart_008E9D48[80]; // 0x008E9D48
extern int gnRemapEnd_008E9E88[80]; // 0x008E9E88
extern int gnRemapOffsets_008E9FC8[80 * 80]; // 0x008E9FC8

struct D2CelStrc { unsigned int unknown000,width; char unknown008[24]; };

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

// 0x00604AA0
void __stdcall sub_00604AA0_ClearMatchingSlot(int* pSlots, char* pEntry)
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
void __stdcall sub_006051F0_FreeIfSet(void* pMemory)
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
void __stdcall sub_006056C0_SetGlobal(int nValue)
{
    gnGlobal_008E9028 = nValue;
}

// 0x00605840
void __stdcall sub_00605840_SetGlobal(int nValue)
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

int gnRemapStart_008E9D48[80]; // 0x008E9D48

int gnRemapEnd_008E9E88[80]; // 0x008E9E88

int gnRemapOffsets_008E9FC8[80 * 80]; // 0x008E9FC8

// 0x00608C00
void __stdcall sub_00608C00_RemapRegion(unsigned char* pBuffer, int nPitch)
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

// 0x006096D0
D2CmpTileStrc* __stdcall TileListAddTile(D2CmpTileListStrc* ptList, short nValue16, short nValue14, int nValue24, int nValue28, int nValue2C, int nValue30, int nValue10, const D2CmpTileInfoStrc* pInfo)
{
    D2_ASSERT(ptList, 0xA2);
    D2CmpTileStrc* pTile = sub_00609550_AllocTile();
    D2_ASSERT(pTile, 0xA6);
    pTile->pNext = ptList->pFirst;
    ptList->nCount++;
    ptList->pFirst = pTile;
    pTile->f_16 = nValue16;
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
    int nPos = f_C + nBits;
    f_C = nPos & 0x1F;
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

// 0x0060D9C0
void __stdcall sub_0060D9C0_BuildDiamondBlock(D2CmpSubTileBlockStrc* pBlock, const unsigned char* pSrc)
{
    unsigned char* pDst = (unsigned char*)FOG_Alloc(0x100, szSubTileFile, 0x185, 0);
    D2_ASSERT(pDst, 0x186);
    unsigned char* pData = pDst;
    memset(pDst, 0, 0x100);
    int i = 0;
    int nOffset = 0xE;
    int nWidth = 4;
    for (; i < 15; i++)
    {
        memcpy(pDst, pSrc + nOffset, nWidth);
        pSrc += 0x20;
        pDst += nWidth;
        if (i < 7)
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
    pBlock->nValue08 = 1;
    pBlock->nSize = 0x100;
    pBlock->pData = pData;
}

// 0x0060DD20
int D2CmpStringStrc::sub_0060DD20_EqualsNoCase(const D2CmpStringStrc* pOther)
{
    return !SStrCmpI(szText, pOther->szText, 0x7FFFFFFF);
}

#include "gen/data/Source/D2CMP/SRC/FastCmp_00604AA0.inc"

int gdwGlobal_008F03C8; // 0x008F03C8

// 0x004067C0
int __cdecl sub_004067C0_SetBasePathToCurrent()
{
    return SFileSetBasePath(".\\");
}

// 0x00413740
void __cdecl sub_00413740_Nop()
{
}

// 0x00608520
int __cdecl D2CMPToggleCelDrawMode()
{
    return gdwGlobal_008F03C8 = (gdwGlobal_008F03C8 == 0);
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

static __forceinline const char* __fastcall SkipCelRows(const char* current,int rows)
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
