#include "Storm.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2RectStrc;
struct tagPOINT;
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* pText, const char* pFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern int gnScreenHeight_007C913C; // 0x007C913C

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct tagPOINT
{
    long x;
    long y;
};
void __fastcall sub_006C90E0_GdiUtilFilledRect(tagRECT* pRect, unsigned char nColor); // 0x006C90E0
extern int gnRows_007C913C; // 0x007C913C
void __stdcall sub_006C9220_Apply(int enabled); // 0x006C9220

int gnScreenHeight_007C913C; // 0x007C913C

static void __fastcall GDI_PutPixel(int nX, int nY, unsigned char nColor)
{
    if (nX >= 0 && nX < gnScreenWidth_007C9138 && nY >= 0 && nY < gnScreenHeight_007C913C)
        gpScreenBuffer_007C9154[gnScreenWidth_007C9138 * nY + nX] = nColor;
}

// 0x006C8C80
void __fastcall sub_006C8C80_GdiDrawLine(int nX1, int nY1, int nX2, int nY2, unsigned char nColor, int nUnused)
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

    GDI_PutPixel(nX1, nY1, nColor);

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

            GDI_PutPixel(nX, nY, nColor);
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

            GDI_PutPixel(nX, nY, nColor);
        }
    }
}

// 0x006C90E0
void __fastcall sub_006C90E0_FillRect(D2RectStrc* pRect, int nColor)
{
    D2_ASSERT(pRect->nLeft <= pRect->nRight, 0x15E);
    D2_ASSERT(pRect->nTop <= pRect->nBottom, 0x15F);

    if (pRect->nRight < 0)
    {
        return;
    }

    if (pRect->nLeft >= gnScreenWidth_007C9138)
    {
        return;
    }

    if (pRect->nBottom < 0)
    {
        return;
    }

    if (pRect->nTop >= gnScreenHeight_007C913C)
    {
        return;
    }

    if (pRect->nLeft < 0)
    {
        pRect->nLeft = 0;
    }

    if (pRect->nRight >= gnScreenWidth_007C9138)
    {
        pRect->nRight = gnScreenWidth_007C9138 - 1;
    }

    if (pRect->nTop < 0)
    {
        pRect->nTop = 0;
    }

    if (pRect->nBottom >= gnScreenHeight_007C913C)
    {
        pRect->nBottom = gnScreenHeight_007C913C - 1;
    }

    unsigned int nWidth = pRect->nRight - pRect->nLeft;
    int nHeight = pRect->nBottom - pRect->nTop;

    if (!nWidth)
    {
        return;
    }

    if (!nHeight)
    {
        return;
    }

    unsigned char* pDst = &gpScreenBuffer_007C9154[pRect->nTop * gnScreenWidth_007C9138 + pRect->nLeft];
    while (nHeight--)
    {
        if (nWidth > 0)
        {
            memset(pDst, nColor, nWidth);
        }

        pDst += gnScreenWidth_007C9138;
    }
}

// 0x006C91D0
void __fastcall sub_006C91D0_GdiUtilPoint(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex)
{
    if (nSize)
    {
        --nSize;
        tagRECT tRect;
        SetRect(&tRect, pPoint->x - nSize, pPoint->y - nSize, pPoint->x + nSize + 1, pPoint->y + nSize + 1);
        sub_006C90E0_GdiUtilFilledRect(&tRect, nPaletteIndex);
    }
}

// 0x006C9220
void __stdcall sub_006C9220_ClearBuffer(int bPartial)
{
    if (bPartial)
    {
        memset(gpBuffer_007C9154, 0, gnStride_007C9138 * (gnRows_007C913C - 47));
    }
    else
    {
        memset(gpBuffer_007C9154, 0, gnStride_007C9138 * gnRows_007C913C);
    }
}

// 0x006C9270
void __fastcall sub_006C9270_Apply(int enabled)
{
    sub_006C9220_Apply(enabled);
}

// 0x006C9280
void __fastcall sub_006C9280_Apply(int enabled, unsigned char unusedRegister, int unusedA, int unusedB)
{
    sub_006C9220_Apply(enabled);
}
