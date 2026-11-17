#include "D2Win.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

struct D2PaletteStrc;
struct D2TileLibraryBlockStrc;

struct D2PaletteStrc
{
    union
    {
        unsigned char colors[256];
        unsigned char remap[256];
        unsigned char unk0x00[0x100];
    };
};

extern int gnScreenPitch_007D544C; // 0x007D544C
extern unsigned char gLightCube_007CA320[32][32][32]; // 0x007CA320
extern D2PaletteStrc gLightPalettes_007D2348[]; // 0x007D2348
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern int gnRowOffsets_007C9828[]; // 0x007C9828
extern unsigned char* gpScreenBuffer_007D5448; // 0x007D5448
extern unsigned char gLightRamps_007CA320[32][32][32]; // 0x007CA320
extern unsigned char** gppBlendTables_007D5578; // 0x007D5578

struct D2TileLibraryBlockStrc
{
    short nPosX;
    short nPosY;
    short unk0x04;
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned char nFormat;
    char unk0x09[0x07];
    unsigned char* pData;
};

void __fastcall sub_004F7580_DrawRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows); // 0x004F7580
extern int gnBlockClipBottom_007C97A0; // 0x007C97A0
extern int gnBlockClipLeft_007CA318; // 0x007CA318
extern int gnBlockClipTop_007D2334; // 0x007D2334
extern int gnBlockClipRight_007D233C; // 0x007D233C
void __fastcall sub_004F7850_DrawLitRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nArg); // 0x004F7850
extern int gnClipBottom_007C97A0; // 0x007C97A0
extern int gnClipLeft_007CA318; // 0x007CA318
extern int gnClipTop_007D2334; // 0x007D2334
extern int gnClipRight_007D233C; // 0x007D233C

unsigned char gLightCube_007CA320[32][32][32]; // 0x007CA320

D2PaletteStrc gLightPalettes_007D2348[49]; // 0x007D2348

// 0x004F71A0
void __fastcall sub_004F71A0_DrawLitRleRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nShift)
{
    unsigned char* pRow = pDst;
    unsigned char* pLight = gLightCube_007CA320[nLightX >> nShift][nLightY >> nShift];
    while (nRows) {
        int nSkip = *pSrc++;
        int nLength = *pSrc++;
        if (!nSkip && !nLength) {
            nLightX += nLightXStep;
            nLightY += nLightYStep;
            pDst += gnScreenPitch_007D544C;
            --nRows;
            pRow = pDst;
            pLight = gLightCube_007CA320[nLightX >> nShift][nLightY >> nShift];
        } else {
            pRow += nSkip;
            pLight += nSkip;
            switch (nLength) {
            case 32: pRow[31] = gLightPalettes_007D2348[pLight[31]].colors[pSrc[31]];
            case 31: pRow[30] = gLightPalettes_007D2348[pLight[30]].colors[pSrc[30]];
            case 30: pRow[29] = gLightPalettes_007D2348[pLight[29]].colors[pSrc[29]];
            case 29: pRow[28] = gLightPalettes_007D2348[pLight[28]].colors[pSrc[28]];
            case 28: pRow[27] = gLightPalettes_007D2348[pLight[27]].colors[pSrc[27]];
            case 27: pRow[26] = gLightPalettes_007D2348[pLight[26]].colors[pSrc[26]];
            case 26: pRow[25] = gLightPalettes_007D2348[pLight[25]].colors[pSrc[25]];
            case 25: pRow[24] = gLightPalettes_007D2348[pLight[24]].colors[pSrc[24]];
            case 24: pRow[23] = gLightPalettes_007D2348[pLight[23]].colors[pSrc[23]];
            case 23: pRow[22] = gLightPalettes_007D2348[pLight[22]].colors[pSrc[22]];
            case 22: pRow[21] = gLightPalettes_007D2348[pLight[21]].colors[pSrc[21]];
            case 21: pRow[20] = gLightPalettes_007D2348[pLight[20]].colors[pSrc[20]];
            case 20: pRow[19] = gLightPalettes_007D2348[pLight[19]].colors[pSrc[19]];
            case 19: pRow[18] = gLightPalettes_007D2348[pLight[18]].colors[pSrc[18]];
            case 18: pRow[17] = gLightPalettes_007D2348[pLight[17]].colors[pSrc[17]];
            case 17: pRow[16] = gLightPalettes_007D2348[pLight[16]].colors[pSrc[16]];
            case 16: pRow[15] = gLightPalettes_007D2348[pLight[15]].colors[pSrc[15]];
            case 15: pRow[14] = gLightPalettes_007D2348[pLight[14]].colors[pSrc[14]];
            case 14: pRow[13] = gLightPalettes_007D2348[pLight[13]].colors[pSrc[13]];
            case 13: pRow[12] = gLightPalettes_007D2348[pLight[12]].colors[pSrc[12]];
            case 12: pRow[11] = gLightPalettes_007D2348[pLight[11]].colors[pSrc[11]];
            case 11: pRow[10] = gLightPalettes_007D2348[pLight[10]].colors[pSrc[10]];
            case 10: pRow[9] = gLightPalettes_007D2348[pLight[9]].colors[pSrc[9]];
            case 9: pRow[8] = gLightPalettes_007D2348[pLight[8]].colors[pSrc[8]];
            case 8: pRow[7] = gLightPalettes_007D2348[pLight[7]].colors[pSrc[7]];
            case 7: pRow[6] = gLightPalettes_007D2348[pLight[6]].colors[pSrc[6]];
            case 6: pRow[5] = gLightPalettes_007D2348[pLight[5]].colors[pSrc[5]];
            case 5: pRow[4] = gLightPalettes_007D2348[pLight[4]].colors[pSrc[4]];
            case 4: pRow[3] = gLightPalettes_007D2348[pLight[3]].colors[pSrc[3]];
            case 3: pRow[2] = gLightPalettes_007D2348[pLight[2]].colors[pSrc[2]];
            case 2: pRow[1] = gLightPalettes_007D2348[pLight[1]].colors[pSrc[1]];
            case 1: pRow[0] = gLightPalettes_007D2348[pLight[0]].colors[pSrc[0]];
            }
            pRow += nLength;
            pSrc += nLength;
            pLight += nLength;
        }
    }
}

static int gnClipYMax_007C97A0; // 0x007C97A0

static int gnClipXMin_007CA318; // 0x007CA318

static int gnClipYMin_007D2334; // 0x007D2334

static int gnClipXMax_007D233C; // 0x007D233C

static int gnScreen_7C9780; // 0x007C9780

static int gnScreen_7C9784; // 0x007C9784

static int gnScreen_7C9788; // 0x007C9788

static int gnScreen_7C978C; // 0x007C978C

static int gnScreen_7C9790; // 0x007C9790

static int gnScreen_7C9794; // 0x007C9794

static int gnScreen_7C9798; // 0x007C9798

static int gnScreen_7C979C; // 0x007C979C

static int gnScreen_7C97A4; // 0x007C97A4

static int gnScreen_7CA31C; // 0x007CA31C

static int gnScreen_7D2320; // 0x007D2320

static int gnScreen_7D2324; // 0x007D2324

static int gnScreen_7D2328; // 0x007D2328

static int gnScreen_7D232C; // 0x007D232C

static int gnScreen_7D2330; // 0x007D2330

static int gnScreen_7D2338; // 0x007D2338

// 0x004F7DA0
void __fastcall sub_004F7DA0_SetPanelCoords(int nWidth, int nHeight)
{
    int nLeft = 0;
    int nRight = nWidth;
    const int nBottom = nHeight - 0x2F;
    if (gnResolutionMode_007C8CC4 == 1)
    {
        nRight -= nWidth / 2;
    }
    else if (gnResolutionMode_007C8CC4 == 2)
    {
        nLeft = nWidth / 2;
    }
    gnScreen_7D2338 = nBottom;
    gnScreen_7C97A4 = nLeft;
    gnScreen_7D2328 = nLeft;
    gnClipXMin_007CA318 = nLeft;
    gnScreen_7D2330 = -0x10;
    gnScreen_7C9788 = nLeft - 0x20;
    gnScreen_7C979C = nBottom - 0x10;
    gnScreen_7C9798 = nRight;
    gnScreen_7C9780 = 0;
    gnScreen_7D2320 = nRight - 0x20;
    gnScreen_7D232C = -0x20;
    gnScreen_7D2324 = nRight;
    gnScreen_7C978C = nBottom;
    gnScreen_7CA31C = 0;
    gnScreen_7C9794 = nLeft - 0x20;
    gnScreen_7C9790 = nBottom - 0x20;
    gnScreen_7C9784 = nRight - 0x20;
    gnClipYMin_007D2334 = 0;
    gnClipXMax_007D233C = nRight;
    gnClipYMax_007C97A0 = nBottom;
}

// 0x004F7580
void __fastcall sub_004F7580_DrawRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows)
{
    unsigned char* p = pDst;
    int i = 0;
    if (nRows > 0)
    {
    int nLeft = nY;
    do
    {
        int nSkip = *pSrc++;
        int nCount = *pSrc++;
        if (!nSkip && !nCount)
        {
            ++i;
            ++nLeft;
            pDst += gnScreenPitch_007D544C;
            p = pDst;
        }
        else
        {
            if (nLeft >= gnClipYMax_007C97A0)
            {
                return;
            }

            p += nSkip;
            if (nLeft >= gnClipYMin_007D2334)
            {
                unsigned char* pNextSrc = pSrc + nCount;
                unsigned char* pNext = p + nCount;
                const int nPos = p - pDst + nX;
                int nStart = gnClipXMin_007CA318 + (-nPos);
                nStart = nStart > 0 ? nStart : 0;
                int nEnd = gnClipXMax_007D233C + (-nPos);
                nEnd = nEnd > 0 ? nEnd : 0;
                nEnd = nEnd < nCount ? nEnd : nCount;
                const int nLength = nEnd - nStart;
                if (nLength > 0)
                {
                    p += nStart;
                    pSrc += nStart;
                    switch (nLength)
                    {
                    case 32: p[31] = pPalette[pSrc[31]];
                    case 31: p[30] = pPalette[pSrc[30]];
                    case 30: p[29] = pPalette[pSrc[29]];
                    case 29: p[28] = pPalette[pSrc[28]];
                    case 28: p[27] = pPalette[pSrc[27]];
                    case 27: p[26] = pPalette[pSrc[26]];
                    case 26: p[25] = pPalette[pSrc[25]];
                    case 25: p[24] = pPalette[pSrc[24]];
                    case 24: p[23] = pPalette[pSrc[23]];
                    case 23: p[22] = pPalette[pSrc[22]];
                    case 22: p[21] = pPalette[pSrc[21]];
                    case 21: p[20] = pPalette[pSrc[20]];
                    case 20: p[19] = pPalette[pSrc[19]];
                    case 19: p[18] = pPalette[pSrc[18]];
                    case 18: p[17] = pPalette[pSrc[17]];
                    case 17: p[16] = pPalette[pSrc[16]];
                    case 16: p[15] = pPalette[pSrc[15]];
                    case 15: p[14] = pPalette[pSrc[14]];
                    case 14: p[13] = pPalette[pSrc[13]];
                    case 13: p[12] = pPalette[pSrc[12]];
                    case 12: p[11] = pPalette[pSrc[11]];
                    case 11: p[10] = pPalette[pSrc[10]];
                    case 10: p[9] = pPalette[pSrc[9]];
                    case 9: p[8] = pPalette[pSrc[8]];
                    case 8: p[7] = pPalette[pSrc[7]];
                    case 7: p[6] = pPalette[pSrc[6]];
                    case 6: p[5] = pPalette[pSrc[5]];
                    case 5: p[4] = pPalette[pSrc[4]];
                    case 4: p[3] = pPalette[pSrc[3]];
                    case 3: p[2] = pPalette[pSrc[2]];
                    case 2: p[1] = pPalette[pSrc[1]];
                    case 1: p[0] = pPalette[pSrc[0]];
                    }
                }

                pSrc = pNextSrc;
                p = pNext;
            }
            else
            {
                p += nCount;
                pSrc += nCount;
            }
        }
    } while (i < nRows);
    }
}

static int gnInnerRight_007C9784; // 0x007C9784

static int gnClipBottom_007C978C; // 0x007C978C

static int gnInnerBottom_007C9790; // 0x007C9790

static int gnClipLeft_007C9794; // 0x007C9794

static int gnRowClipBottom_007C97A0; // 0x007C97A0

static int gnColClipLeft_007CA318; // 0x007CA318

static int gnInnerTop_007CA31C; // 0x007CA31C

static int gnClipRight_007D2324; // 0x007D2324

static int gnInnerLeft_007D2328; // 0x007D2328

static int gnClipTop_007D232C; // 0x007D232C

static int gnRowClipTop_007D2334; // 0x007D2334

static int gnColClipRight_007D233C; // 0x007D233C

// 0x004F7850
void __fastcall sub_004F7850_DrawLitRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nShift)
{
    unsigned char* pRow = pDst;
    unsigned char* pLight = gLightCube_007CA320[nLightX >> nShift][nLightY >> nShift];
    int nRow = 0;
    if (nRows > 0)
    {
        int nCurrentY = nY;
        do
        {
            int nSkip = *pSrc++;
            int nLength = *pSrc++;
            if (!nSkip && !nLength)
            {
                ++nRow; ++nCurrentY;
                pDst += gnScreenPitch_007D544C;
                pRow = pDst;
                nLightX += nLightXStep;
                nLightY += nLightYStep;
                pLight = gLightCube_007CA320[nLightX >> nShift][nLightY >> nShift];
            }
            else
            {
                if (nCurrentY >= gnRowClipBottom_007C97A0) return;
                pRow += nSkip;
                pLight += nSkip;
                if (nCurrentY >= gnRowClipTop_007D2334)
                {
                    unsigned char* pSrcEnd = pSrc + nLength;
                    unsigned char* pDstEnd = pRow + nLength;
                    const int nPosX = pRow - pDst + nX;
                    int nStart = gnColClipLeft_007CA318 + (-nPosX);
                    nStart = nStart > 0 ? nStart : 0;
                    int nEnd = gnColClipRight_007D233C + (-nPosX);
                    nEnd = nEnd > 0 ? nEnd : 0;
                    if (nEnd >= nLength) nEnd = nLength;
                    int nVisible = nEnd - nStart;
                    if (nVisible > 0)
                    {
                        pRow += nStart;
                        pSrc += nStart;
                        switch(nVisible)
                        {
                        case 32: pRow[31] = gLightPalettes_007D2348[pLight[31]].remap[pSrc[31]];
                        case 31: pRow[30] = gLightPalettes_007D2348[pLight[30]].remap[pSrc[30]];
                        case 30: pRow[29] = gLightPalettes_007D2348[pLight[29]].remap[pSrc[29]];
                        case 29: pRow[28] = gLightPalettes_007D2348[pLight[28]].remap[pSrc[28]];
                        case 28: pRow[27] = gLightPalettes_007D2348[pLight[27]].remap[pSrc[27]];
                        case 27: pRow[26] = gLightPalettes_007D2348[pLight[26]].remap[pSrc[26]];
                        case 26: pRow[25] = gLightPalettes_007D2348[pLight[25]].remap[pSrc[25]];
                        case 25: pRow[24] = gLightPalettes_007D2348[pLight[24]].remap[pSrc[24]];
                        case 24: pRow[23] = gLightPalettes_007D2348[pLight[23]].remap[pSrc[23]];
                        case 23: pRow[22] = gLightPalettes_007D2348[pLight[22]].remap[pSrc[22]];
                        case 22: pRow[21] = gLightPalettes_007D2348[pLight[21]].remap[pSrc[21]];
                        case 21: pRow[20] = gLightPalettes_007D2348[pLight[20]].remap[pSrc[20]];
                        case 20: pRow[19] = gLightPalettes_007D2348[pLight[19]].remap[pSrc[19]];
                        case 19: pRow[18] = gLightPalettes_007D2348[pLight[18]].remap[pSrc[18]];
                        case 18: pRow[17] = gLightPalettes_007D2348[pLight[17]].remap[pSrc[17]];
                        case 17: pRow[16] = gLightPalettes_007D2348[pLight[16]].remap[pSrc[16]];
                        case 16: pRow[15] = gLightPalettes_007D2348[pLight[15]].remap[pSrc[15]];
                        case 15: pRow[14] = gLightPalettes_007D2348[pLight[14]].remap[pSrc[14]];
                        case 14: pRow[13] = gLightPalettes_007D2348[pLight[13]].remap[pSrc[13]];
                        case 13: pRow[12] = gLightPalettes_007D2348[pLight[12]].remap[pSrc[12]];
                        case 12: pRow[11] = gLightPalettes_007D2348[pLight[11]].remap[pSrc[11]];
                        case 11: pRow[10] = gLightPalettes_007D2348[pLight[10]].remap[pSrc[10]];
                        case 10: pRow[9] = gLightPalettes_007D2348[pLight[9]].remap[pSrc[9]];
                        case 9: pRow[8] = gLightPalettes_007D2348[pLight[8]].remap[pSrc[8]];
                        case 8: pRow[7] = gLightPalettes_007D2348[pLight[7]].remap[pSrc[7]];
                        case 7: pRow[6] = gLightPalettes_007D2348[pLight[6]].remap[pSrc[6]];
                        case 6: pRow[5] = gLightPalettes_007D2348[pLight[5]].remap[pSrc[5]];
                        case 5: pRow[4] = gLightPalettes_007D2348[pLight[4]].remap[pSrc[4]];
                        case 4: pRow[3] = gLightPalettes_007D2348[pLight[3]].remap[pSrc[3]];
                        case 3: pRow[2] = gLightPalettes_007D2348[pLight[2]].remap[pSrc[2]];
                        case 2: pRow[1] = gLightPalettes_007D2348[pLight[1]].remap[pSrc[1]];
                        case 1: pRow[0] = gLightPalettes_007D2348[pLight[0]].remap[pSrc[0]];
                        }
                    }
                    pSrc = pSrcEnd;
                    pRow = pDstEnd;
                    pLight += nLength;
                }
                else
                {
                    pRow += nLength;
                    pLight += nLength;
                    pSrc += nLength;
                }
            }
        } while (nRow < nRows);
    }
}

// 0x004F7EA0
void __fastcall sub_004F7EA0_DrawVisTile(unsigned char* pSrc, int nX, int nY)
{
    if (nY < gnClipTop_007D232C || nY >= gnClipBottom_007C978C || nX < gnClipLeft_007C9794 || nX >= gnClipRight_007D2324)
        return;

    D2_ASSERT(gpScreenBuffer_007D5448, 0x2F4);
    unsigned char* pDst = gnRowOffsets_007C9828[nY] + gpScreenBuffer_007D5448 + nX;
    unsigned char* p = pDst;
    if (nY >= gnInnerTop_007CA31C && nY < gnInnerBottom_007C9790 && nX >= gnInnerLeft_007D2328 && nX < gnInnerRight_007C9784)
    {
        int nRows = 0x20;
        while (nRows)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                --nRows;
                pDst += gnScreenPitch_007D544C;
                p = pDst;
            }
            else
            {
                p += nSkip;
                memcpy(p, pSrc, nCount);
                p += nCount;
                pSrc += nCount;
            }
        }
    }
    else
    {
        int nRow = 0;
        int nRowY = nY;
        while (nRow < 0x20)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                ++nRow;
                ++nRowY;
                pDst += gnScreenPitch_007D544C;
                p = pDst;
            }
            else
            {
                if (nRowY >= gnRowClipBottom_007C97A0)
                    return;

                p += nSkip;
                if (nRowY >= gnRowClipTop_007D2334)
                {
                    const int nPosX = p - pDst + nX;
                    int nLeft = gnColClipLeft_007CA318 + (-nPosX);
                    nLeft = D2_MAX(nLeft, 0);
                    int nRight = gnColClipRight_007D233C + (-nPosX);
                    nRight = D2_MAX(nRight, 0);
                    if (nRight >= nCount)
                        nRight = nCount;
                    const int nLength = nRight - nLeft;
                    if (nLength > 0)
                        memcpy(p + nLeft, pSrc + nLeft, nLength);

                    pSrc += nCount;
                    p += nCount;
                }
                else
                {
                    p += nCount;
                    pSrc += nCount;
                }
            }
        }
    }
}

// 0x004F84F0
void __fastcall sub_004F84F0_TileDrawLitBlend(unsigned char* pSrc, int nX, int nY, int* pLight, unsigned char nAlpha)
{
    unsigned char* pBlend;
    if (nAlpha >= 0xC0)
        pBlend = gppBlendTables_007D5578[0];
    else if (nAlpha >= 0x80)
        pBlend = gppBlendTables_007D5578[1];
    else if (nAlpha >= 0x40)
        pBlend = gppBlendTables_007D5578[2];
    else
        return;

    int nLightX = pLight[0] << 5;
    const int nLightXStep = pLight[3] - pLight[0];
    int nLightY = pLight[1] << 5;
    const int nLightYStep = pLight[2] - pLight[1];

    if (nY < gnClipTop_007D232C || nY >= gnClipBottom_007C978C || nX < gnClipLeft_007C9794 || nX >= gnClipRight_007D2324)
        return;

    unsigned char* pBuffer = gpScreenBuffer_007D5448;
    D2_ASSERT(pBuffer, 0x48B);
    unsigned char* pDst = gnRowOffsets_007C9828[nY] + pBuffer + nX;
    unsigned char* p = pDst;
    unsigned char* pRamp = gLightRamps_007CA320[nLightX >> 8][nLightY >> 8];
    if (nY >= gnInnerTop_007CA31C && nY < gnInnerBottom_007C9790 && nX >= gnInnerLeft_007D2328 && nX < gnInnerRight_007C9784)
    {
        int nRows = 0x20;
        while (nRows)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                --nRows;
                pDst += gnScreenPitch_007D544C;
                p = pDst;
                nLightX += nLightXStep;
                nLightY += nLightYStep;
                pRamp = gLightRamps_007CA320[nLightX >> 8][nLightY >> 8];
            }
            else
            {
                p += nSkip;
                pRamp += nSkip;
                unsigned char* pEnd = pSrc + nCount;
                while (pSrc < pEnd)
                {
                    const unsigned char nLit = gLightPalettes_007D2348[*pRamp].unk0x00[*pSrc];
                    ++pSrc;
                    *p = pBlend[(nLit << 8) + *p];
                    ++pRamp;
                    ++p;
                }
            }
        }
    }
    else
    {
        int nRow = 0;
        int nRowY = nY;
        while (nRow < 0x20)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                ++nRow;
                ++nRowY;
                pDst += gnScreenPitch_007D544C;
                p = pDst;
                nLightX += nLightXStep;
                nLightY += nLightYStep;
                pRamp = gLightRamps_007CA320[nLightX >> 8][nLightY >> 8];
            }
            else
            {
                if (nRowY >= gnRowClipBottom_007C97A0)
                    return;

                p += nSkip;
                pRamp += nSkip;
                if (nRowY >= gnRowClipTop_007D2334)
                {
                    unsigned char* pNextSrc = pSrc + nCount;
                    unsigned char* pNextDst = p + nCount;
                    unsigned char* pNextRamp = pRamp + nCount;
                    const int nPosX = p - pDst + nX;
                    int nLeft = gnColClipLeft_007CA318 + (-nPosX);
                    nLeft = nLeft > 0 ? nLeft : 0;
                    int nRight = gnColClipRight_007D233C + (-nPosX);
                    nRight = nRight > 0 ? nRight : 0;
                    if (nRight >= nCount)
                        nRight = nCount;
                    const int nLength = nRight - nLeft;
                    if (nLength > 0)
                    {
                        pSrc += nLeft;
                        unsigned char* pEnd = pSrc + nLength;
                        p += nLeft;
                        while (pSrc < pEnd)
                        {
                            const unsigned char nLit = gLightPalettes_007D2348[*pRamp].unk0x00[*pSrc];
                            ++pSrc;
                            *p = pBlend[(nLit << 8) + *p];
                            ++pRamp;
                            ++p;
                        }
                    }

                    pSrc = pNextSrc;
                    p = pNextDst;
                    pRamp = pNextRamp;
                }
                else
                {
                    p += nCount;
                    pRamp += nCount;
                    pSrc += nCount;
                }
            }
        }
    }
}

// 0x004F88B0
void __fastcall sub_004F88B0_DrawBlockClipped(D2TileLibraryBlockStrc* pBlock, int nX, int nY, unsigned char* pDst, unsigned char nLight)
{
    unsigned char* pPalette = gLightPalettes_007D2348[nLight >> 3].unk0x00;
    if (pBlock->nFormat & 4)
    {
        sub_004F7580_DrawRleRowsClipped(nX, nY, pBlock->pData, pDst, pPalette, 0xF);
        return;
    }

    const int nStartRow = D2_MAX(gnBlockClipTop_007D2334 - nY, 0);
    const int nEndRow = D2_MIN(gnBlockClipBottom_007C97A0 - nY, 15);
    unsigned char* pRow = pDst + gnScreenPitch_007D544C * nStartRow;
    for (int i = nStartRow; i < nEndRow; ++i)
    {
        const int nNegX = -(nX + gnSubtileRowXOffset_0072DB48[i]);
        unsigned char* d = pRow + gnSubtileRowXOffset_0072DB48[i];
        unsigned char* s = pBlock->pData + gnSubtileRowSrcOffset_0072DBC0[i];
        const int nSkipValue = D2_MAX(gnBlockClipLeft_007CA318 + nNegX, 0);
        const int nClipRight = gnBlockClipRight_007D233C;
        const int nRight = nNegX + nClipRight;
        const int nWidth = gnSubtileRowWidth_0072DB84[i];
        int nSkip;
        nSkip = nSkipValue;
        int nCount = D2_MAX(nRight, 0);
        nCount = D2_MIN(nCount, nWidth) - nSkip;
        if (nCount > 0)
        {
            s += nSkip;
            d += nSkip;
            for (unsigned char* pEnd = s + nCount; s < pEnd; ++s, ++d)
            {
                *d = pPalette[*s];
            }
        }

        pRow += gnScreenPitch_007D544C;
    }
}

// build: context ClipRowSpan
static __forceinline int ClipRowSpan(int* pnSkip, int nWidth, int nRight, int nLeft)
{
    *pnSkip = nLeft;
    int nCount = D2_MAX(nRight, 0);
    return D2_MIN(nCount, nWidth) - *pnSkip;
}

// 0x004F89F0
void __fastcall sub_004F89F0_DrawLitBlockClipped(D2TileLibraryBlockStrc* pBlock, int nX, int nY, unsigned char* pDst, int* pLight)
{
    int nLightX = pLight[0] << 4;
    const int nLightXStep = pLight[3] - pLight[0];
    int nLightY = pLight[1] << 4;
    const int nLightYStep = pLight[2] - pLight[1];
    if (pBlock->nFormat & 4)
    {
        sub_004F7850_DrawLitRleRowsClipped(nX, nY, pBlock->pData, pDst, nLightX, nLightXStep, nLightY, nLightYStep, 15, 7);
        return;
    }

    const int nStartRow = D2_MAX(gnClipTop_007D2334 - nY, 0);
    const int nEndRow = D2_MIN(gnClipBottom_007C97A0 - nY, 15);
    unsigned char* pRow = pDst + gnScreenPitch_007D544C * nStartRow;
    for (int i = nStartRow; i < nEndRow; ++i)
    {
        const int nNegX = -(nX + gnSubtileRowXOffset_0072DB48[i]);
        unsigned char* pLevels = (unsigned char*)gLightCube_007CA320 + 32 * ((nLightY >> 7) + 32 * (nLightX >> 7)) + gnSubtileRowXOffset_0072DB48[i];
        unsigned char* d = pRow + gnSubtileRowXOffset_0072DB48[i];
        unsigned char* s = pBlock->pData + gnSubtileRowSrcOffset_0072DBC0[i];
        int nSkip;
        int nCount = ClipRowSpan(&nSkip, gnSubtileRowWidth_0072DB84[i], gnClipRight_007D233C + nNegX, D2_MAX(gnClipLeft_007CA318 + nNegX, 0));
        if (nCount > 0)
        {
            s += nSkip;
            d += nSkip;
            {
                unsigned char* pEnd = s + nCount;
                while (s < pEnd)
                {
                    *d = gLightPalettes_007D2348[*pLevels].unk0x00[*s];
                    ++s, ++d, ++pLevels;
                }
            }
        }

        pRow += gnScreenPitch_007D544C;
        nLightX += nLightXStep;
        nLightY += nLightYStep;
    }
}
