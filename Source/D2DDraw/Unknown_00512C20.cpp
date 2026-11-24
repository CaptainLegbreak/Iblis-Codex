#include "D2Win32Base.h"
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CoordPairStrc { int nX; int nY; };
static void __stdcall sub_00512A50_DrawLine(const D2CoordPairStrc* pFrom, const D2CoordPairStrc* pTo, unsigned char nColor);
static void __stdcall sub_00512A50_DrawLine(const D2CoordPairStrc* pFrom, const D2CoordPairStrc* pTo, unsigned char nColor); // 0x00512A50

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
