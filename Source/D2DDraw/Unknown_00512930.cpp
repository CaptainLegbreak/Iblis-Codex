#include "D2DDraw.h"

struct tagRECT;
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CoordPairStrc { int nX; int nY; };
static void __stdcall sub_00512A50_DrawLine(const D2CoordPairStrc* pFrom, const D2CoordPairStrc* pTo, unsigned char nColor);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* pText, const char* pFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

// 0x00512C20
void __fastcall sub_00512C20_DrawDiamond(tagRECT* pRect, int nValue)
{
    D2_ASSERT(pRect->left <= pRect->right, 0x12D);
    int nBottom = pRect->bottom;
    D2_ASSERT(pRect->top <= nBottom, 0x12E);

    unsigned int nWidth = pRect->right - pRect->left;
    unsigned int nHeight = nBottom - pRect->top;
    if (!nWidth || !nHeight)
        return;

    D2CoordPairStrc ptTop;
    D2CoordPairStrc ptLeft;
    D2CoordPairStrc ptBottom;
    ptTop.nX = pRect->left + (nWidth >> 1);
    D2CoordPairStrc ptRight;
    ptTop.nY = pRect->top;
    ptRight.nX = pRect->right;
    ptRight.nY = pRect->top + (nHeight >> 1);
    ptBottom.nX = pRect->left + (nWidth >> 1);
    ptBottom.nY = nBottom;
    ptLeft.nX = pRect->left;
    ptLeft.nY = pRect->top + (nHeight >> 1);

    sub_00512A50_DrawLine(&ptTop, &ptRight, nValue);
    sub_00512A50_DrawLine(&ptRight, &ptBottom, nValue);
    sub_00512A50_DrawLine(&ptBottom, &ptLeft, nValue);
    sub_00512A50_DrawLine(&ptLeft, &ptTop, nValue);
}

extern int gnSurfaceWidth_007C9138;                                                                         // 0x007C9138
extern int gnSurfaceHeight_007C913C;                                                                        // 0x007C913C
extern unsigned char* gpSurfaceBits_007C9154;                                                               // 0x007C9154

static void __stdcall sub_00512A50_DrawLine(const D2CoordPairStrc* pFrom, const D2CoordPairStrc* pTo, unsigned char nColor)
{
    const int nDeltaX = pTo->nX - pFrom->nX;
    const int nDeltaY = pTo->nY - pFrom->nY;
    if (!nDeltaX && !nDeltaY)
    {
        return;
    }

    const int nLength = nDeltaY * nDeltaY + nDeltaX * nDeltaX;
    int nSteps = 0;
    while (nSteps * nSteps < nLength)
    {
        ++nSteps;
    }

    const int nStepX = (nDeltaX << 16) / nSteps;
    const int nStepY = (nDeltaY << 16) / nSteps;
    int nX = pFrom->nX;
    int nY = pFrom->nY;
    int nFracX = 0;
    int nFracY = 0;
    int i = 0;
    for (;;)
    {
        if (nY >= 0 && nY < gnSurfaceHeight_007C913C && nX >= 0 && nX < gnSurfaceWidth_007C9138)
        {
            break;
        }

        nFracX += nStepX;
        if (nFracX >= 0x10000 || nFracX <= -0x10000)
        {
            const int nMove = nFracX / 0x10000;
            nX += nMove;
            nFracX += nMove * -0x10000;
        }

        nFracY += nStepY;
        if (nFracY >= 0x10000 || nFracY <= -0x10000)
        {
            const int nMove = nFracY / 0x10000;
            nY += nMove;
            nFracY += nMove * -0x10000;
        }

        if (i >= nSteps)
        {
            return;
        }
        ++i;
    }

    unsigned char* pDst = gpSurfaceBits_007C9154 + gnSurfaceWidth_007C9138 * nY + nX;
    *pDst = nColor;
    for (++i; i < nSteps; ++i)
    {
        nFracX += nStepX;
        if (nFracX >= 0x10000 || nFracX <= -0x10000)
        {
            const int nMove = nFracX / 0x10000;
            nX += nMove;
            pDst += nMove;
            nFracX += nMove * -0x10000;
        }

        if (nX < 0 || nX >= gnSurfaceWidth_007C9138)
        {
            return;
        }

        nFracY += nStepY;
        if (nFracY >= 0x10000 || nFracY <= -0x10000)
        {
            const int nMove = nFracY / 0x10000;
            nY += nMove;
            pDst += gnSurfaceWidth_007C9138 * nMove;
            nFracY += nMove * -0x10000;
        }

        if (nY < 0 || nY >= gnSurfaceHeight_007C913C)
        {
            return;
        }

        *pDst = nColor;
    }
}

// 0x00512CE0
void __fastcall sub_00512CE0_DrawRect(tagRECT* pRect, int nColor)
{
    const int nLeft = pRect->left;
    D2_ASSERT(nLeft <= pRect->right, 0x149);
    const int nTop = pRect->top;
    D2_ASSERT(nTop <= pRect->bottom, 0x14A);
    const unsigned int nWidth = pRect->right - nLeft;
    const unsigned int nHeight = pRect->bottom - nTop;
    if (!nWidth || !nHeight)
        return;

    D2CoordPairStrc aCorners[4];
    aCorners[1].nX = nLeft;
    aCorners[1].nY = pRect->top;
    aCorners[3].nX = pRect->right;
    aCorners[3].nY = pRect->top;
    aCorners[2].nX = pRect->right;
    aCorners[2].nY = pRect->bottom;
    aCorners[0].nX = nLeft;
    aCorners[0].nY = pRect->bottom;
    sub_00512A50_DrawLine(&aCorners[1], &aCorners[3], nColor);
    sub_00512A50_DrawLine(&aCorners[3], &aCorners[2], nColor);
    sub_00512A50_DrawLine(&aCorners[2], &aCorners[0], nColor);
    sub_00512A50_DrawLine(&aCorners[0], &aCorners[1], nColor);
}

extern int gnSurfaceWidth_007C9138;                                                                         // 0x007C9138
extern int gnSurfaceHeight_007C913C;                                                                        // 0x007C913C
extern unsigned char* gpSurfaceBits_007C9154;                                                               // 0x007C9154

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
