#include "D2Glide.h"
struct D2GlideDebugCellStrc;

struct T00508FE0
{
    float x;
    float y;
    float unk0x08;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};
extern void (__stdcall* gpfGlideColorCombine_0087EB2C)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C
extern void (__stdcall* gpfGlideMask_0087EB8C)(int bEnable); // 0x0087EB8C
extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor); // 0x0087EFA0
extern D2GlideDebugCellStrc** gppGlideDebugBuffer_00880454; // 0x00880454
unsigned int __fastcall sub_005093F0_GlidePaletteColor(int nPaletteIndex); // 0x005093F0
void __fastcall sub_005094B0_GlideSetState(int nState); // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode); // 0x00509500
extern int gnScreenWidth_007C9138; // 0x007C9138
extern void (__stdcall* gpfGlideDrawLine_0087E978)(const T00508FE0* pStart, const T00508FE0* pEnd); // 0x0087E978
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50
extern void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int color, unsigned int alpha, unsigned int depth); // 0x0087EB88

typedef char cc_M439_D2GlideSpriteVertexStrc_size[sizeof(D2GlideSpriteVertexStrc) == 0x1C ? 1 : -1];

// 0x0050BD30
static void sub_0050BD30_GlideDrawPointCross(unsigned int dwColor, int nX, int nY)
{
    gpfGlideConstantColor_0087EFA0(dwColor);
    for (int i = 0; i < 8; ++i)
    {
        T00508FE0 tVertex;
        tVertex.x = (float)(gaGlideCrossOffsetX_0072F2C8[i] + nX);
        tVertex.y = (float)(gaGlideCrossOffsetY_0072F2E8[i] + nY);
        gpfGlideDrawPoint_0087EAA0(&tVertex);
    }
}

void __cdecl sub_0050BE20_GlideDebugRefresh()
{
    gpfGlideColorCombine_0087EB2C(1, 0, 1, 2, 0);
    gpfGlideMask_0087EB8C(0);
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
                const D2GlideDebugCellStrc* pCell = &gppGlideDebugBuffer_00880454[j][i];
                dwColor = ((pCell->nRed * (unsigned int)pCell->nAlpha / 256 * 256 + pCell->nGreen * (unsigned int)pCell->nAlpha / 256) * 256 + pCell->nBlue * (unsigned int)pCell->nAlpha / 256) * 256;
            }
            sub_0050BD30_GlideDrawPointCross(dwColor, nX, nY);
        }
    }
    gpfGlideColorCombine_0087EB2C(3, 1, 0, 1, 0);
    gpfGlideMask_0087EB8C(1);
}

#include "gen/data/Source/D2Glide/Unknown_0050BD30.inc"

// 0x0050BD80
void sub_0050BD80_GlideDebugDrawLights()
{
    gpfGlideColorCombine_0087EB2C(1, 0, 1, 2, 0);
    gpfGlideMask_0087EB8C(0);
    struct Row { int remaining; int yBase; int j; } row;
    row.j=0;
    unsigned int* light=gaGlideDebugLight_0087F0D0;
    for (row.yBase=100;row.yBase<164;row.yBase+=2,++row.j)
    {
        struct Coordinates { int x; int y; } coordinates;
        coordinates.x=(0x113-row.j)*2;
        coordinates.y=row.yBase;
        row.remaining=32;
        do {
            sub_0050BD30_GlideDrawPointCross(gaGlideLightPalette_0072F308[*light],coordinates.x,coordinates.y);
            ++light;
            coordinates.y+=2;
            coordinates.x+=2;
        } while (--row.remaining);
    }
    gpfGlideColorCombine_0087EB2C(3, 1, 0, 1, 0);
    gpfGlideMask_0087EB8C(1);
}

// 0x0050C270
void __fastcall sub_0050C270_GlideDrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha)
{
    if (nXEnd < 0 && nXStart < 0)
    {
        return;
    }
    if (nXEnd > gnScreenWidth_007C9138 && nXStart > gnScreenWidth_007C9138)
    {
        return;
    }
    if (nYEnd < 0 && nYStart < 0)
    {
        return;
    }
    if (nYEnd > gnScreenHeight_007C913C && nYStart > gnScreenHeight_007C913C)
    {
        return;
    }

    unsigned int dwColor = sub_005093F0_GlidePaletteColor(nColor);
    sub_005094B0_GlideSetState(2);
    if (nAlpha == 0xFF)
    {
        sub_00509500_GlideSetCombine(1);
    }
    else
    {
        sub_00509500_GlideSetCombine(4);
        dwColor = (dwColor & 0xFFFFFF00) | nAlpha;
    }
    gpfGlideMask_0087EB8C(0);
    gpfGlideConstantColor_0087EFA0(dwColor);

    if (nXStart == nXEnd && nYStart == nYEnd)
    {
        T00508FE0 tVertex;
        tVertex.x = (float)nXStart;
        tVertex.y = (float)nYStart;
        tVertex.oow = 1.0f;
        tVertex.sow = 0.0f;
        tVertex.tow = 0.0f;
        gpfGlideDrawPoint_0087EAA0(&tVertex);
    }
    else
    {
        T00508FE0 tStart;
        T00508FE0 tEnd;
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
        gpfGlideDrawLine_0087E978(&tStart, &tEnd);
    }
    gpfGlideMask_0087EB8C(1);
}

// 0x0050C5E0
void __fastcall sub_0050C5E0_GlideUtilFilledRect(tagRECT* pRect, int nPaletteIndex)
{
    D2_ASSERT(pRect->left <= pRect->right, 0x100);
    D2_ASSERT(pRect->top <= pRect->bottom, 0x101);
    sub_0050BF50_GlideDrawBox(pRect->left, pRect->top, pRect->right, pRect->bottom, nPaletteIndex, 5);
}

// 0x0050C680
void __cdecl sub_0050C680_ClearBuffer()
{
    gpfGlideBufferClear_0087EB88(0, 0, 0);
}

D2GlideSpriteVertexStrc gaGlideTileGrid_00880458[15]; // 0x00880458

D2GlideSpriteVertexStrc gaGlideTileQuad_00880600[4]; // 0x00880600

int gbGlideCornersScaled_00880670; // 0x00880670

// 0x0050C760
void __cdecl sub_0050C760_GlideInitVertices()
{
    gaGlideTileQuad_00880600[0].x = 0.0f;
    gaGlideTileQuad_00880600[0].y = 0.0f;
    gaGlideTileQuad_00880600[0].oow = 1.0f;
    gaGlideTileQuad_00880600[0].sow = 0.0f;
    gaGlideTileQuad_00880600[0].tow = 0.0f;

    gaGlideTileQuad_00880600[1].x = 0.0f;
    gaGlideTileQuad_00880600[1].y = 0.0f;
    gaGlideTileQuad_00880600[1].oow = 1.0f;
    gaGlideTileQuad_00880600[1].sow = 0.0f;
    gaGlideTileQuad_00880600[1].tow = 256.0f;

    gaGlideTileQuad_00880600[2].x = 0.0f;
    gaGlideTileQuad_00880600[2].y = 0.0f;
    gaGlideTileQuad_00880600[2].oow = 1.0f;
    gaGlideTileQuad_00880600[2].sow = 256.0f;
    gaGlideTileQuad_00880600[2].tow = 256.0f;

    gaGlideTileQuad_00880600[3].x = 0.0f;
    gaGlideTileQuad_00880600[3].y = 0.0f;
    gaGlideTileQuad_00880600[3].oow = 1.0f;
    gaGlideTileQuad_00880600[3].sow = 256.0f;
    gaGlideTileQuad_00880600[3].tow = 0.0f;

    for (int i = 0; i < 5; i++)
    {
        float fTow = (float)(i << 6);
        for (int j = 0; j < 3; j++)
        {
            gaGlideTileGrid_00880458[i * 3 + j].oow = 1.0f;
            gaGlideTileGrid_00880458[i * 3 + j].sow = (float)(j << 7);
            gaGlideTileGrid_00880458[i * 3 + j].tow = fTow;
        }
    }

    if (!gbGlideCornersScaled_00880670)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                int* pPoint = gaGlideWallCorner_0072F3A0[i][j];
                pPoint[0] <<= 16;
                pPoint[1] <<= 16;
            }
        }
        gbGlideCornersScaled_00880670 = 1;
    }
}
