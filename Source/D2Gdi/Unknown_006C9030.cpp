#include "D2Win32Base.h"
struct D2CoordPairStrc { int x, y; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* pText, const char* pFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
static void __stdcall sub_006C8DA0_DrawLine(const D2CoordPairStrc* pFrom, const D2CoordPairStrc* pTo, unsigned char nColor);
static void __stdcall sub_006C8DA0_DrawLine(const D2CoordPairStrc* pFrom, const D2CoordPairStrc* pTo, unsigned char nColor); // 0x006C8DA0
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x006C9030
void __fastcall sub_006C9030_DrawRect(tagRECT* pRect, int nColor)
{
    const int nLeft = pRect->left;
    D2_ASSERT(nLeft <= pRect->right, 0x142);
    const int nTop = pRect->top;
    D2_ASSERT(nTop <= pRect->bottom, 0x143);
    const unsigned int nWidth = pRect->right - nLeft;
    const unsigned int nHeight = pRect->bottom - nTop;
    if (!nWidth || !nHeight)
        return;

    D2CoordPairStrc aCorners[4];
    aCorners[1].x = nLeft;
    aCorners[1].y = pRect->top;
    aCorners[3].x = pRect->right;
    aCorners[3].y = pRect->top;
    aCorners[2].x = pRect->right;
    aCorners[2].y = pRect->bottom;
    aCorners[0].x = nLeft;
    aCorners[0].y = pRect->bottom;
    sub_006C8DA0_DrawLine(&aCorners[1], &aCorners[3], nColor);
    sub_006C8DA0_DrawLine(&aCorners[3], &aCorners[2], nColor);
    sub_006C8DA0_DrawLine(&aCorners[2], &aCorners[0], nColor);
    sub_006C8DA0_DrawLine(&aCorners[0], &aCorners[1], nColor);
}

extern int gnSurfaceWidth_007C9138;                                                                         // 0x007C9138
extern int gnSurfaceHeight_007C913C;                                                                        // 0x007C913C
extern unsigned char* gpSurfaceBits_007C9154;                                                               // 0x007C9154

static void __stdcall sub_006C8DA0_DrawLine(const D2CoordPairStrc* pFrom, const D2CoordPairStrc* pTo, unsigned char nColor)
{
    const int nDeltaX = pTo->x - pFrom->x;
    const int nDeltaY = pTo->y - pFrom->y;
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
    int nX = pFrom->x;
    int nY = pFrom->y;
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
