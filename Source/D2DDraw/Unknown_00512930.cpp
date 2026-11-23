#include "D2DDraw.h"

struct tagRECT;
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

static void __fastcall DDRAW_PutPixel(int nX, int nY, unsigned char nColor)
{
// build: symbol ?gnRenderWidth@* 0x007C9138
// build: symbol ?gnRenderHeight@* 0x007C913C
    if (nX >= 0 && nX < gnRenderWidth && nY >= 0 && nY < gnRenderHeight)
        gpScreenBuffer_007C9154[gnRenderWidth * nY + nX] = nColor;
}

// 0x00512930
void __fastcall sub_00512930_DDrawDrawLine(int nX1, int nY1, int nX2, int nY2, unsigned char nColor, int nUnused)
{
    int nX = nX1;
    int nY = nY1;
    int nDX = nX2 - nX1;
    int nDY = nY2 - nY1;
    int nStepX;
    int nStepY;

    if (nDX < 0)
    {
        nStepX = -1;
        nDX = -nDX;
    }
    else
    {
        nStepX = 1;
    }

    if (nDY < 0)
    {
        nStepY = -1;
        nDY = -nDY;
    }
    else
    {
        nStepY = 1;
    }

    DDRAW_PutPixel(nX1, nY1, nColor);

    int nError = 0;
    if (nDX < nDY)
    {
        for (int i = 0; i < nDY; ++i)
        {
            nY += nStepY;
            nError += nDX;
            if (nError > nDY)
            {
                nX += nStepX;
                nError -= nDY;
            }

            DDRAW_PutPixel(nX, nY, nColor);
        }
    }
    else
    {
        for (int i = 0; i < nDX; ++i)
        {
            nX += nStepX;
            nError += nDY;
            if (nError > nDX)
            {
                nY += nStepY;
                nError -= nDX;
            }

            DDRAW_PutPixel(nX, nY, nColor);
        }
    }
}

// 0x00512D90
void __fastcall sub_00512D90_DDrawUtilFilledRect(tagRECT* pRect, unsigned char nColor)
{
    D2_ASSERT(pRect->left <= pRect->right, 0x165);
    D2_ASSERT(pRect->top <= pRect->bottom, 0x166);
    if (pRect->right < 0 || pRect->left >= gnRenderWidth || pRect->bottom < 0 || pRect->top >= gnRenderHeight)
        return;
    if (pRect->left < 0)
        pRect->left = 0;
    if (pRect->right >= gnRenderWidth)
        pRect->right = gnRenderWidth - 1;
    if (pRect->top < 0)
        pRect->top = 0;
    if (pRect->bottom >= gnRenderHeight)
        pRect->bottom = gnRenderHeight - 1;
    const unsigned int nWidth = pRect->right - pRect->left;
    int nHeight = pRect->bottom - pRect->top;
    if (!nWidth || !nHeight)
        return;
    unsigned char* pDst = &gpScreenBuffer_007C9154[pRect->top * gnRenderWidth + pRect->left];
    while (nHeight--)
    {
        for (unsigned int x = 0; x < nWidth; ++x)
            pDst[x] = nColor;
        pDst += gnRenderWidth;
    }
}
