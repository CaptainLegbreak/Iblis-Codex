#include "D2Glide.h"

struct D2GlideDebugCellStrc;

extern void (__stdcall* gpfnGrColorCombine)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C

extern void (__stdcall* gpfnGrChromakeyMode)(int bEnable); // 0x0087EB8C

extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor); // 0x0087EFA0

extern D2GlideDebugCellStrc** gppGlideDebugBuffer; // 0x00880454

unsigned int __fastcall GLIDE_GetPaletteColor(int nPaletteIndex); // 0x005093F0

void __fastcall GLIDE_SetColorCombineMode(int nState); // 0x005094B0

void __fastcall GLIDE_SetAlphaBlendMode(int nMode); // 0x00509500

extern int gnRenderWidth; // 0x007C9138

extern void (__stdcall* gpfnGrDrawLine)(const D2GlideSpriteVertexStrc* pStart, const D2GlideSpriteVertexStrc* pEnd); // 0x0087E978

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50

extern void (__stdcall* gpfnGrBufferClear)(unsigned int color, unsigned int alpha, unsigned int depth); // 0x0087EB88

typedef char cc_M439_D2GlideSpriteVertexStrc_size[sizeof(D2GlideSpriteVertexStrc) == 0x1C ? 1 : -1];

// 0x0050BD30
static void sub_0050BD30_GlideDrawPointCross(unsigned int dwColor, int nX, int nY)
{
    gpfnGrConstantColorValue(dwColor);
    for (int i = 0; i < 8; ++i)
    {
        D2GlideSpriteVertexStrc tVertex;
// build: symbol ?gaGlideCrossOffsetX@* 0x0072F2C8
        tVertex.x = (float)(gaGlideCrossOffsetX[i] + nX);
// build: symbol ?gaGlideCrossOffsetY@* 0x0072F2E8
        tVertex.y = (float)(gaGlideCrossOffsetY[i] + nY);
// build: symbol ?gpfnGrDrawPoint@* 0x0087EAA0
        gpfnGrDrawPoint(&tVertex);
    }
}

void __cdecl sub_0050BE20_GlideDebugRefresh()
{
    gpfnGrColorCombine(1, 0, 1, 2, 0);
    gpfnGrChromakeyMode(0);
    for (int j = 0; j < 48; ++j)
    {
        for (int i = 0; i < 48; ++i)
        {
            const int nX = (i + 50) * 2 - j * 2;
            const int nY = (j + i + 50) * 2;
            unsigned int dwColor;
            if (j == 24 && i == j)
            {
                dwColor = 0;
            }
            else
            {
                const D2GlideDebugCellStrc* pCell = &gppGlideDebugBuffer[j][i];
                dwColor = ((pCell->nRed * (unsigned int)pCell->nAlpha / 256 * 256 + pCell->nGreen * (unsigned int)pCell->nAlpha / 256) * 256 + pCell->nBlue * (unsigned int)pCell->nAlpha / 256) * 256;
            }
            sub_0050BD30_GlideDrawPointCross(dwColor, nX, nY);
        }
    }
    gpfnGrColorCombine(3, 1, 0, 1, 0);
    gpfnGrChromakeyMode(1);
}

#include "gen/data/Source/D2Glide/Unknown_0050BD30.inc"

// 0x0050BD80
void sub_0050BD80_GlideDebugDrawLights()
{
    gpfnGrColorCombine(1, 0, 1, 2, 0);
    gpfnGrChromakeyMode(0);
    struct Row { int remaining; int yBase; int j; } row;
    row.j=0;
// build: symbol ?gaGlideDebugLight@* 0x0087F0D0
    unsigned int* light=gaGlideDebugLight;
    for (row.yBase=100;row.yBase<164;row.yBase+=2,++row.j)
    {
        struct Coordinates { int x; int y; } coordinates;
        coordinates.x=(0x113-row.j)*2;
        coordinates.y=row.yBase;
        row.remaining=32;
        do {
// build: symbol ?gaGlideLightPalette@* 0x0072F308
            sub_0050BD30_GlideDrawPointCross(gaGlideLightPalette[*light],coordinates.x,coordinates.y);
            ++light;
            coordinates.y+=2;
            coordinates.x+=2;
        } while (--row.remaining);
    }
    gpfnGrColorCombine(3, 1, 0, 1, 0);
    gpfnGrChromakeyMode(1);
}

// 0x0050C270
void __fastcall sub_0050C270_GlideDrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha)
{
    if (nXEnd < 0 && nXStart < 0)
    {
        return;
    }
    if (nXEnd > gnRenderWidth && nXStart > gnRenderWidth)
    {
        return;
    }
    if (nYEnd < 0 && nYStart < 0)
    {
        return;
    }
// build: symbol ?gnRenderHeight@* 0x007C913C
    if (nYEnd > gnRenderHeight && nYStart > gnRenderHeight)
    {
        return;
    }

    unsigned int dwColor = GLIDE_GetPaletteColor(nColor);
    GLIDE_SetColorCombineMode(2);
    if (nAlpha == 0xFF)
    {
        GLIDE_SetAlphaBlendMode(1);
    }
    else
    {
        GLIDE_SetAlphaBlendMode(4);
        dwColor = (dwColor & 0xFFFFFF00) | nAlpha;
    }
    gpfnGrChromakeyMode(0);
    gpfnGrConstantColorValue(dwColor);

    if (nXStart == nXEnd && nYStart == nYEnd)
    {
        D2GlideSpriteVertexStrc tVertex;
        tVertex.x = (float)nXStart;
        tVertex.y = (float)nYStart;
        tVertex.oow = 1.0f;
        tVertex.sow = 0.0f;
        tVertex.tow = 0.0f;
        gpfnGrDrawPoint(&tVertex);
    }
    else
    {
        D2GlideSpriteVertexStrc tStart;
        D2GlideSpriteVertexStrc tEnd;
        tStart.x = (float)nXStart;
        tStart.y = (float)nYStart;
        tStart.oow = 1.0f;
        tStart.sow = 0.0f;
        tStart.tow = 0.0f;
        tEnd.x = (float)nXEnd;
        tEnd.y = (float)nYEnd;
        tEnd.oow = 1.0f;
        tEnd.sow = 0.0f;
        tEnd.tow = 0.0f;
        gpfnGrDrawLine(&tStart, &tEnd);
    }
    gpfnGrChromakeyMode(1);
}

int gnRenderWidth;                                                                                 // 0x007C9138
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

// 0x0050C3A0
void __fastcall GLIDE_UtilDiamond(tagRECT* pRect, int nPaletteIndex)
{
    const int nX = pRect->left;
    const int nRight = pRect->right;
    D2_ASSERT(nX <= nRight, 0xB9);

    const int nY = pRect->top;
    const int nBottom = pRect->bottom;
    D2_ASSERT(nY <= nBottom, 0xBA);

    const unsigned int nWidth = nRight - nX;
    const unsigned int nHeight = nBottom - nY;
    if (!nWidth || !nHeight)
    {
        return;
    }

    const int nCenterX = nX + (nWidth >> 1);
    const int nCenterY = nY + (nHeight >> 1);
    const int nX2 = nX + nWidth;
    const int nY2 = nY + nHeight;
    if (nX2 < 0 || nX > gnRenderWidth || nY2 < 0 || nY > gnRenderHeight)
    {
        return;
    }

    sub_0050C270_GlideDrawLine(nCenterX, nY, nX2, nCenterY, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nCenterY, nCenterX, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nCenterX, nY2, nX, nCenterY, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX, nCenterY, nCenterX, nY, nPaletteIndex, 0xFF);
}

// 0x0050C490
void __fastcall GLIDE_UtilRect(tagRECT* pRect, int nPaletteIndex)
{
    D2_ASSERT(pRect->left <= pRect->right, 0xDF);
    D2_ASSERT(pRect->top <= pRect->bottom, 0xE0);

    const int nX1 = D2_MIN(D2_MAX(pRect->left, 0), gnRenderWidth - 1);
    const int nX2 = D2_MIN(D2_MAX(pRect->right, 0), gnRenderWidth - 1);
    if (nX1 == nX2)
    {
        return;
    }

    const int nY1 = D2_MIN(D2_MAX(pRect->top, 0), gnRenderHeight - 1);
    const int nY2 = D2_MIN(D2_MAX(pRect->bottom, 0), gnRenderHeight - 1);
    if (nY1 == nY2)
    {
        return;
    }

    D2_ASSERT(nY2 > nY1, 0xF0);

    sub_0050C270_GlideDrawLine(nX1, nY1, nX2, nY1, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nY1, nX2, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nY2, nX1, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX1, nY2, nX1, nY1, nPaletteIndex, 0xFF);
}

// 0x0050C5E0
void __fastcall sub_0050C5E0_GlideUtilFilledRect(tagRECT* pRect, int nPaletteIndex)
{
    D2_ASSERT(pRect->left <= pRect->right, 0x100);
    D2_ASSERT(pRect->top <= pRect->bottom, 0x101);
    sub_0050BF50_GlideDrawBox(pRect->left, pRect->top, pRect->right, pRect->bottom, nPaletteIndex, 5);
}

// 0x0050C630
void __fastcall GLIDE_UtilPoint(tagPOINT* pPoint, unsigned char nSize, int nPaletteIndex)
{
    if (nSize)
    {
        --nSize;
        tagRECT tRect;
        SetRect(&tRect, pPoint->x - nSize, pPoint->y - nSize, pPoint->x + nSize + 1, pPoint->y + nSize + 1);
        sub_0050BF50_GlideDrawBox(tRect.left, tRect.top, tRect.right, tRect.bottom, nPaletteIndex, 5);
    }
}

// 0x0050C680
void __cdecl sub_0050C680_ClearBuffer()
{
    gpfnGrBufferClear(0, 0, 0);
}

D2GlideSpriteVertexStrc gaGlideTileGrid[15]; // 0x00880458

D2GlideSpriteVertexStrc gaGlideTileQuad[4]; // 0x00880600

int gbGlideCornersScaled; // 0x00880670

// 0x0050C760
void __cdecl sub_0050C760_GlideInitVertices()
{
    gaGlideTileQuad[0].x = 0.0f;
    gaGlideTileQuad[0].y = 0.0f;
    gaGlideTileQuad[0].oow = 1.0f;
    gaGlideTileQuad[0].sow = 0.0f;
    gaGlideTileQuad[0].tow = 0.0f;

    gaGlideTileQuad[1].x = 0.0f;
    gaGlideTileQuad[1].y = 0.0f;
    gaGlideTileQuad[1].oow = 1.0f;
    gaGlideTileQuad[1].sow = 0.0f;
    gaGlideTileQuad[1].tow = 256.0f;

    gaGlideTileQuad[2].x = 0.0f;
    gaGlideTileQuad[2].y = 0.0f;
    gaGlideTileQuad[2].oow = 1.0f;
    gaGlideTileQuad[2].sow = 256.0f;
    gaGlideTileQuad[2].tow = 256.0f;

    gaGlideTileQuad[3].x = 0.0f;
    gaGlideTileQuad[3].y = 0.0f;
    gaGlideTileQuad[3].oow = 1.0f;
    gaGlideTileQuad[3].sow = 256.0f;
    gaGlideTileQuad[3].tow = 0.0f;

    for (int i = 0; i < 5; i++)
    {
        float fTow = (float)(i << 6);
        for (int j = 0; j < 3; j++)
        {
            gaGlideTileGrid[i * 3 + j].oow = 1.0f;
            gaGlideTileGrid[i * 3 + j].sow = (float)(j << 7);
            gaGlideTileGrid[i * 3 + j].tow = fTow;
        }
    }

    if (!gbGlideCornersScaled)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 6; j++)
            {
// build: symbol ?gaGlideWallCorner@* 0x0072F3A0
                int* pPoint = gaGlideWallCorner[i][j];
                pPoint[0] <<= 16;
                pPoint[1] <<= 16;
            }
        }
        gbGlideCornersScaled = 1;
    }
}
