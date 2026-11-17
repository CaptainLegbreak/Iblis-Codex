#include "D2Win.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define gnRowOffsets_007C9828 (gnRowOffsets_007C97A8 + 32)
extern int gnScreen_7C9780; // 0x007C9780
extern int gnInnerRight_007C9784; // 0x007C9784
extern int gnScreen_7C9788; // 0x007C9788
extern int gnClipBottom_007C978C; // 0x007C978C
extern int gnInnerBottom_007C9790; // 0x007C9790
extern int gnClipLeft_007C9794; // 0x007C9794
extern int gnScreen_7C9798; // 0x007C9798
extern int gnScreen_7C979C; // 0x007C979C
extern int gnRowClipBottom_007C97A0; // 0x007C97A0
extern int gnScreen_7C97A4; // 0x007C97A4
extern int gnColClipLeft_007CA318; // 0x007CA318
extern int gnInnerTop_007CA31C; // 0x007CA31C
extern int gnScreen_7D2320; // 0x007D2320
extern int gnClipRight_007D2324; // 0x007D2324
extern int gnInnerLeft_007D2328; // 0x007D2328
extern int gnClipTop_007D232C; // 0x007D232C
extern int gnScreen_7D2330; // 0x007D2330
extern int gnRowClipTop_007D2334; // 0x007D2334
extern int gnScreen_7D2338; // 0x007D2338
extern int gnColClipRight_007D233C; // 0x007D233C
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern unsigned char* gpScreenBuffer_007D5448; // 0x007D5448

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
    gnInnerLeft_007D2328 = nLeft;
    gnColClipLeft_007CA318 = nLeft;
    gnScreen_7D2330 = -0x10;
    gnScreen_7C9788 = nLeft - 0x20;
    gnScreen_7C979C = nBottom - 0x10;
    gnScreen_7C9798 = nRight;
    gnScreen_7C9780 = 0;
    gnScreen_7D2320 = nRight - 0x20;
    gnClipTop_007D232C = -0x20;
    gnClipRight_007D2324 = nRight;
    gnClipBottom_007C978C = nBottom;
    gnInnerTop_007CA31C = 0;
    gnClipLeft_007C9794 = nLeft - 0x20;
    gnInnerBottom_007C9790 = nBottom - 0x20;
    gnInnerRight_007C9784 = nRight - 0x20;
    gnRowClipTop_007D2334 = 0;
    gnColClipRight_007D233C = nRight;
    gnRowClipBottom_007C97A0 = nBottom;
}

int gnClipBottom_007C978C; // 0x007C978C

int gnClipLeft_007C9794; // 0x007C9794

int gnInnerRight_007C9784; // 0x007C9784

int gnInnerBottom_007C9790; // 0x007C9790

int gnRowClipBottom_007C97A0; // 0x007C97A0

int gnColClipLeft_007CA318; // 0x007CA318

int gnInnerTop_007CA31C; // 0x007CA31C

int gnClipRight_007D2324; // 0x007D2324

int gnInnerLeft_007D2328; // 0x007D2328

int gnClipTop_007D232C; // 0x007D232C

int gnRowClipTop_007D2334; // 0x007D2334

int gnColClipRight_007D233C; // 0x007D233C

int gnScreenPitch_007D544C; // 0x007D544C

unsigned char** gppBlendTables_007D5578; // 0x007D5578

// 0x004F82D0
void __fastcall sub_004F82D0_DrawBlendVisTile(unsigned char* pSrc, int nX, int nY, unsigned char nAlpha)
{
    unsigned char* pDst;
    unsigned char* p;
    unsigned char* pBlend;
    if (nAlpha >= 0xC0)
        pBlend = gppBlendTables_007D5578[0];
    else if (nAlpha >= 0x80)
        pBlend = gppBlendTables_007D5578[1];
    else if (nAlpha >= 0x40)
        pBlend = gppBlendTables_007D5578[2];
    else
        return;

    if (nY < gnClipTop_007D232C || nY >= gnClipBottom_007C978C || nX < gnClipLeft_007C9794 || nX >= gnClipRight_007D2324)
        return;

    D2_ASSERT(gpScreenBuffer_007D5448, 0x3F8);
    pDst = gnRowOffsets_007C9828[nY] + gpScreenBuffer_007D5448 + nX;
    p = pDst;
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
                    unsigned char* pNextSrc = pSrc + nCount;
                    int nPosX = p - pDst + nX;
                    unsigned char* pNextDst = p + nCount;
                    __assume(nPosX != 0x80000000);
                    nPosX = -nPosX;
                    int nLeft = gnColClipLeft_007CA318 + nPosX;
                    nLeft = nLeft > 0 ? nLeft : 0;
                    int nRight = gnColClipRight_007D233C + nPosX;
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
