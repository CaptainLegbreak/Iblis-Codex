#include "D2Win.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

int gnScreenPitch; // 0x007D544C

unsigned char gabLightCube[32][32][32]; // 0x007CA320

D2PaletteStrc gatLightPalettes[49]; // 0x007D2348

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0


extern unsigned char* gpScreenBuffer; // 0x007D5448

unsigned char** gpPaletteTables; // 0x007D5578

void __fastcall sub_004F7580_DrawRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows); // 0x004F7580

static int gnInnerBlockTop; // 0x007C9780

int gnInnerRight; // 0x007C9784

int gnClipBottom; // 0x007C978C

int gnInnerBottom; // 0x007C9790

int gnClipLeft; // 0x007C9794

static int gnInnerBlockBottom; // 0x007C979C

static int gnRowClipBottom; // 0x007C97A0

static int gnInnerBlockLeft; // 0x007C97A4

static int gnColClipLeft; // 0x007CA318

int gnInnerTop; // 0x007CA31C

static int gnInnerBlockRight; // 0x007D2320

int gnClipRight; // 0x007D2324

int gnInnerLeft; // 0x007D2328

int gnClipTop; // 0x007D232C

static int gnRowClipTop; // 0x007D2334

static int gnColClipRight; // 0x007D233C

void __fastcall sub_004F7850_DrawLitRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nArg); // 0x004F7850


static int gnScreen_7C9788; // 0x007C9788

static int gnScreen_7C9798; // 0x007C9798

static int gnScreen_7D2330; // 0x007D2330

static int gnScreen_7D2338; // 0x007D2338

void __fastcall sub_004F7DA0_SetPanelCoords(int nWidth, int nHeight);

// 0x004F71A0
void __fastcall sub_004F71A0_DrawLitRleRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nShift)
{
    unsigned char* pRow = pDst;
    unsigned char* pLight = gabLightCube[nLightX >> nShift][nLightY >> nShift];
    while (nRows) {
        int nSkip = *pSrc++;
        int nLength = *pSrc++;
        if (!nSkip && !nLength) {
            nLightX += nLightXStep;
            nLightY += nLightYStep;
            pDst += gnScreenPitch;
            --nRows;
            pRow = pDst;
            pLight = gabLightCube[nLightX >> nShift][nLightY >> nShift];
        } else {
            pRow += nSkip;
            pLight += nSkip;
            switch (nLength) {
            case 32: pRow[31] = gatLightPalettes[pLight[31]].colors[pSrc[31]];
            case 31: pRow[30] = gatLightPalettes[pLight[30]].colors[pSrc[30]];
            case 30: pRow[29] = gatLightPalettes[pLight[29]].colors[pSrc[29]];
            case 29: pRow[28] = gatLightPalettes[pLight[28]].colors[pSrc[28]];
            case 28: pRow[27] = gatLightPalettes[pLight[27]].colors[pSrc[27]];
            case 27: pRow[26] = gatLightPalettes[pLight[26]].colors[pSrc[26]];
            case 26: pRow[25] = gatLightPalettes[pLight[25]].colors[pSrc[25]];
            case 25: pRow[24] = gatLightPalettes[pLight[24]].colors[pSrc[24]];
            case 24: pRow[23] = gatLightPalettes[pLight[23]].colors[pSrc[23]];
            case 23: pRow[22] = gatLightPalettes[pLight[22]].colors[pSrc[22]];
            case 22: pRow[21] = gatLightPalettes[pLight[21]].colors[pSrc[21]];
            case 21: pRow[20] = gatLightPalettes[pLight[20]].colors[pSrc[20]];
            case 20: pRow[19] = gatLightPalettes[pLight[19]].colors[pSrc[19]];
            case 19: pRow[18] = gatLightPalettes[pLight[18]].colors[pSrc[18]];
            case 18: pRow[17] = gatLightPalettes[pLight[17]].colors[pSrc[17]];
            case 17: pRow[16] = gatLightPalettes[pLight[16]].colors[pSrc[16]];
            case 16: pRow[15] = gatLightPalettes[pLight[15]].colors[pSrc[15]];
            case 15: pRow[14] = gatLightPalettes[pLight[14]].colors[pSrc[14]];
            case 14: pRow[13] = gatLightPalettes[pLight[13]].colors[pSrc[13]];
            case 13: pRow[12] = gatLightPalettes[pLight[12]].colors[pSrc[12]];
            case 12: pRow[11] = gatLightPalettes[pLight[11]].colors[pSrc[11]];
            case 11: pRow[10] = gatLightPalettes[pLight[10]].colors[pSrc[10]];
            case 10: pRow[9] = gatLightPalettes[pLight[9]].colors[pSrc[9]];
            case 9: pRow[8] = gatLightPalettes[pLight[8]].colors[pSrc[8]];
            case 8: pRow[7] = gatLightPalettes[pLight[7]].colors[pSrc[7]];
            case 7: pRow[6] = gatLightPalettes[pLight[6]].colors[pSrc[6]];
            case 6: pRow[5] = gatLightPalettes[pLight[5]].colors[pSrc[5]];
            case 5: pRow[4] = gatLightPalettes[pLight[4]].colors[pSrc[4]];
            case 4: pRow[3] = gatLightPalettes[pLight[3]].colors[pSrc[3]];
            case 3: pRow[2] = gatLightPalettes[pLight[2]].colors[pSrc[2]];
            case 2: pRow[1] = gatLightPalettes[pLight[1]].colors[pSrc[1]];
            case 1: pRow[0] = gatLightPalettes[pLight[0]].colors[pSrc[0]];
            }
            pRow += nLength;
            pSrc += nLength;
            pLight += nLength;
        }
    }
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
            pDst += gnScreenPitch;
            p = pDst;
        }
        else
        {
            if (nLeft >= gnRowClipBottom)
            {
                return;
            }

            p += nSkip;
            if (nLeft >= gnRowClipTop)
            {
                unsigned char* pNextSrc = pSrc + nCount;
                unsigned char* pNext = p + nCount;
                const int nPos = p - pDst + nX;
                int nStart = gnColClipLeft + (-nPos);
                nStart = nStart > 0 ? nStart : 0;
                int nEnd = gnColClipRight + (-nPos);
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

// 0x004F7850
void __fastcall sub_004F7850_DrawLitRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nShift)
{
    unsigned char* pRow = pDst;
    unsigned char* pLight = gabLightCube[nLightX >> nShift][nLightY >> nShift];
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
                pDst += gnScreenPitch;
                pRow = pDst;
                nLightX += nLightXStep;
                nLightY += nLightYStep;
                pLight = gabLightCube[nLightX >> nShift][nLightY >> nShift];
            }
            else
            {
                if (nCurrentY >= gnRowClipBottom) return;
                pRow += nSkip;
                pLight += nSkip;
                if (nCurrentY >= gnRowClipTop)
                {
                    unsigned char* pSrcEnd = pSrc + nLength;
                    unsigned char* pDstEnd = pRow + nLength;
                    const int nPosX = pRow - pDst + nX;
                    int nStart = gnColClipLeft + (-nPosX);
                    nStart = nStart > 0 ? nStart : 0;
                    int nEnd = gnColClipRight + (-nPosX);
                    nEnd = nEnd > 0 ? nEnd : 0;
                    if (nEnd >= nLength) nEnd = nLength;
                    int nVisible = nEnd - nStart;
                    if (nVisible > 0)
                    {
                        pRow += nStart;
                        pSrc += nStart;
                        switch(nVisible)
                        {
                        case 32: pRow[31] = gatLightPalettes[pLight[31]].remap[pSrc[31]];
                        case 31: pRow[30] = gatLightPalettes[pLight[30]].remap[pSrc[30]];
                        case 30: pRow[29] = gatLightPalettes[pLight[29]].remap[pSrc[29]];
                        case 29: pRow[28] = gatLightPalettes[pLight[28]].remap[pSrc[28]];
                        case 28: pRow[27] = gatLightPalettes[pLight[27]].remap[pSrc[27]];
                        case 27: pRow[26] = gatLightPalettes[pLight[26]].remap[pSrc[26]];
                        case 26: pRow[25] = gatLightPalettes[pLight[25]].remap[pSrc[25]];
                        case 25: pRow[24] = gatLightPalettes[pLight[24]].remap[pSrc[24]];
                        case 24: pRow[23] = gatLightPalettes[pLight[23]].remap[pSrc[23]];
                        case 23: pRow[22] = gatLightPalettes[pLight[22]].remap[pSrc[22]];
                        case 22: pRow[21] = gatLightPalettes[pLight[21]].remap[pSrc[21]];
                        case 21: pRow[20] = gatLightPalettes[pLight[20]].remap[pSrc[20]];
                        case 20: pRow[19] = gatLightPalettes[pLight[19]].remap[pSrc[19]];
                        case 19: pRow[18] = gatLightPalettes[pLight[18]].remap[pSrc[18]];
                        case 18: pRow[17] = gatLightPalettes[pLight[17]].remap[pSrc[17]];
                        case 17: pRow[16] = gatLightPalettes[pLight[16]].remap[pSrc[16]];
                        case 16: pRow[15] = gatLightPalettes[pLight[15]].remap[pSrc[15]];
                        case 15: pRow[14] = gatLightPalettes[pLight[14]].remap[pSrc[14]];
                        case 14: pRow[13] = gatLightPalettes[pLight[13]].remap[pSrc[13]];
                        case 13: pRow[12] = gatLightPalettes[pLight[12]].remap[pSrc[12]];
                        case 12: pRow[11] = gatLightPalettes[pLight[11]].remap[pSrc[11]];
                        case 11: pRow[10] = gatLightPalettes[pLight[10]].remap[pSrc[10]];
                        case 10: pRow[9] = gatLightPalettes[pLight[9]].remap[pSrc[9]];
                        case 9: pRow[8] = gatLightPalettes[pLight[8]].remap[pSrc[8]];
                        case 8: pRow[7] = gatLightPalettes[pLight[7]].remap[pSrc[7]];
                        case 7: pRow[6] = gatLightPalettes[pLight[6]].remap[pSrc[6]];
                        case 6: pRow[5] = gatLightPalettes[pLight[5]].remap[pSrc[5]];
                        case 5: pRow[4] = gatLightPalettes[pLight[4]].remap[pSrc[4]];
                        case 4: pRow[3] = gatLightPalettes[pLight[3]].remap[pSrc[3]];
                        case 3: pRow[2] = gatLightPalettes[pLight[2]].remap[pSrc[2]];
                        case 2: pRow[1] = gatLightPalettes[pLight[1]].remap[pSrc[1]];
                        case 1: pRow[0] = gatLightPalettes[pLight[0]].remap[pSrc[0]];
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
    gnInnerBlockLeft = nLeft;
    gnInnerLeft = nLeft;
    gnColClipLeft = nLeft;
    gnScreen_7D2330 = -0x10;
    gnScreen_7C9788 = nLeft - 0x20;
    gnInnerBlockBottom = nBottom - 0x10;
    gnScreen_7C9798 = nRight;
    gnInnerBlockTop = 0;
    gnInnerBlockRight = nRight - 0x20;
    gnClipTop = -0x20;
    gnClipRight = nRight;
    gnClipBottom = nBottom;
    gnInnerTop = 0;
    gnClipLeft = nLeft - 0x20;
    gnInnerBottom = nBottom - 0x20;
    gnInnerRight = nRight - 0x20;
    gnRowClipTop = 0;
    gnColClipRight = nRight;
    gnRowClipBottom = nBottom;
}

// 0x004F7EA0
void __fastcall sub_004F7EA0_DrawVisTile(unsigned char* pSrc, int nX, int nY)
{
    if (nY < gnClipTop || nY >= gnClipBottom || nX < gnClipLeft || nX >= gnClipRight)
        return;

    D2_ASSERT(gpScreenBuffer, 0x2F4);
// build: symbol ?ganRowOffsets@* 0x007C97A8
    unsigned char* pDst = ganRowOffsets[nY + 32] + gpScreenBuffer + nX;
    unsigned char* p = pDst;
    if (nY >= gnInnerTop && nY < gnInnerBottom && nX >= gnInnerLeft && nX < gnInnerRight)
    {
        int nRows = 0x20;
        while (nRows)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                --nRows;
                pDst += gnScreenPitch;
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
                pDst += gnScreenPitch;
                p = pDst;
            }
            else
            {
                if (nRowY >= gnRowClipBottom)
                    return;

                p += nSkip;
                if (nRowY >= gnRowClipTop)
                {
                    const int nPosX = p - pDst + nX;
                    int nLeft = gnColClipLeft + (-nPosX);
                    nLeft = D2_MAX(nLeft, 0);
                    int nRight = gnColClipRight + (-nPosX);
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

// 0x004F82D0
void __fastcall sub_004F82D0_DrawBlendVisTile(unsigned char* pSrc, int nX, int nY, unsigned char nAlpha)
{
    unsigned char* pDst;
    unsigned char* p;
    unsigned char* pBlend;
    if (nAlpha >= 0xC0)
        pBlend = gpPaletteTables[0];
    else if (nAlpha >= 0x80)
        pBlend = gpPaletteTables[1];
    else if (nAlpha >= 0x40)
        pBlend = gpPaletteTables[2];
    else
        return;

    if (nY < gnClipTop || nY >= gnClipBottom || nX < gnClipLeft || nX >= gnClipRight)
        return;

    D2_ASSERT(gpScreenBuffer, 0x3F8);
    pDst = ganRowOffsets[nY + 32] + gpScreenBuffer + nX;
    p = pDst;
    if (nY >= gnInnerTop && nY < gnInnerBottom && nX >= gnInnerLeft && nX < gnInnerRight)
    {
        int nRows = 0x20;
        while (nRows)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                --nRows;
                pDst += gnScreenPitch;
                p = pDst;
            }
            else
            {
                unsigned char* pEnd = pSrc + nCount;
                p += nSkip;
                while (pSrc < pEnd)
                {
                    *p = pBlend[(*p << 8) + *pSrc++];
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
                pDst += gnScreenPitch;
                p = pDst;
            }
            else
            {
                if (nRowY >= gnRowClipBottom)
                    return;

                p += nSkip;
                if (nRowY >= gnRowClipTop)
                {
                    unsigned char* pNextSrc = pSrc + nCount;
                    int nPosX = p - pDst + nX;
                    unsigned char* pNextDst = p + nCount;
                    // stands for the original's register use in this draw loop (blend table kept in a stack slot); without it, plain forms reassign registers from the top of the function
                    __assume(nPosX != 0x80000000);
                    nPosX = -nPosX;
                    int nLeft = gnColClipLeft + nPosX;
                    nLeft = nLeft > 0 ? nLeft : 0;
                    int nRight = gnColClipRight + nPosX;
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
                            *p = pBlend[(*p << 8) + *pSrc];
                            ++pSrc;
                            ++p;
                        }
                    }

                    pSrc = pNextSrc;
                    p = pNextDst;
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
        pBlend = gpPaletteTables[0];
    else if (nAlpha >= 0x80)
        pBlend = gpPaletteTables[1];
    else if (nAlpha >= 0x40)
        pBlend = gpPaletteTables[2];
    else
        return;

    int nLightX = pLight[0] << 5;
    const int nLightXStep = pLight[3] - pLight[0];
    int nLightY = pLight[1] << 5;
    const int nLightYStep = pLight[2] - pLight[1];

    if (nY < gnClipTop || nY >= gnClipBottom || nX < gnClipLeft || nX >= gnClipRight)
        return;

    unsigned char* pBuffer = gpScreenBuffer;
    D2_ASSERT(pBuffer, 0x48B);
    unsigned char* pDst = ganRowOffsets[nY + 32] + pBuffer + nX;
    unsigned char* p = pDst;
    unsigned char* pRamp = gabLightCube[nLightX >> 8][nLightY >> 8];
    if (nY >= gnInnerTop && nY < gnInnerBottom && nX >= gnInnerLeft && nX < gnInnerRight)
    {
        int nRows = 0x20;
        while (nRows)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                --nRows;
                pDst += gnScreenPitch;
                p = pDst;
                nLightX += nLightXStep;
                nLightY += nLightYStep;
                pRamp = gabLightCube[nLightX >> 8][nLightY >> 8];
            }
            else
            {
                p += nSkip;
                pRamp += nSkip;
                unsigned char* pEnd = pSrc + nCount;
                while (pSrc < pEnd)
                {
                    const unsigned char nLit = gatLightPalettes[*pRamp].unk0x00[*pSrc];
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
                pDst += gnScreenPitch;
                p = pDst;
                nLightX += nLightXStep;
                nLightY += nLightYStep;
                pRamp = gabLightCube[nLightX >> 8][nLightY >> 8];
            }
            else
            {
                if (nRowY >= gnRowClipBottom)
                    return;

                p += nSkip;
                pRamp += nSkip;
                if (nRowY >= gnRowClipTop)
                {
                    unsigned char* pNextSrc = pSrc + nCount;
                    unsigned char* pNextDst = p + nCount;
                    unsigned char* pNextRamp = pRamp + nCount;
                    const int nPosX = p - pDst + nX;
                    int nLeft = gnColClipLeft + (-nPosX);
                    nLeft = nLeft > 0 ? nLeft : 0;
                    int nRight = gnColClipRight + (-nPosX);
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
                            const unsigned char nLit = gatLightPalettes[*pRamp].unk0x00[*pSrc];
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
    unsigned char* pPalette = gatLightPalettes[nLight >> 3].unk0x00;
    if (pBlock->nFormat & 4)
    {
        sub_004F7580_DrawRleRowsClipped(nX, nY, pBlock->pData, pDst, pPalette, 0xF);
        return;
    }

    const int nStartRow = D2_MAX(gnRowClipTop - nY, 0);
    const int nEndRow = D2_MIN(gnRowClipBottom - nY, 15);
    unsigned char* pRow = pDst + gnScreenPitch * nStartRow;
    for (int i = nStartRow; i < nEndRow; ++i)
    {
// build: symbol ?ganSubtileRowXOffset@* 0x0072DB48
        const int nNegX = -(nX + ganSubtileRowXOffset[i]);
        unsigned char* d = pRow + ganSubtileRowXOffset[i];
// build: symbol ?ganSubtileRowSrcOffset@* 0x0072DBC0
        unsigned char* s = pBlock->pData + ganSubtileRowSrcOffset[i];
        const int nSkipValue = D2_MAX(gnColClipLeft + nNegX, 0);
        const int nClipRight = gnColClipRight;
        const int nRight = nNegX + nClipRight;
// build: symbol ?ganSubtileRowWidth@* 0x0072DB84
        const int nWidth = ganSubtileRowWidth[i];
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

        pRow += gnScreenPitch;
    }
}

// build: context ClipRowSpan
static inline int ClipRowSpan(int* pnSkip, int nWidth, int nRight, int nLeft)
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

    const int nStartRow = D2_MAX(gnRowClipTop - nY, 0);
    const int nEndRow = D2_MIN(gnRowClipBottom - nY, 15);
    unsigned char* pRow = pDst + gnScreenPitch * nStartRow;
    for (int i = nStartRow; i < nEndRow; ++i)
    {
        const int nNegX = -(nX + ganSubtileRowXOffset[i]);
        unsigned char* pLevels = (unsigned char*)gabLightCube + 32 * ((nLightY >> 7) + 32 * (nLightX >> 7)) + ganSubtileRowXOffset[i];
        unsigned char* d = pRow + ganSubtileRowXOffset[i];
        unsigned char* s = pBlock->pData + ganSubtileRowSrcOffset[i];
        int nSkip;
        int nCount = ClipRowSpan(&nSkip, ganSubtileRowWidth[i], gnColClipRight + nNegX, D2_MAX(gnColClipLeft + nNegX, 0));
        if (nCount > 0)
        {
            s += nSkip;
            d += nSkip;
            {
                unsigned char* pEnd = s + nCount;
                while (s < pEnd)
                {
                    *d = gatLightPalettes[*pLevels].unk0x00[*s];
                    ++s, ++d, ++pLevels;
                }
            }
        }

        pRow += gnScreenPitch;
        nLightX += nLightXStep;
        nLightY += nLightYStep;
    }
}
