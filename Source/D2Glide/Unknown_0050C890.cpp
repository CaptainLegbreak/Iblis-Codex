#include "D2Glide.h"
#include "D2DrlgMaps.h"

extern int gnScreenWidth_007C9138; // 0x007C9138
extern D2GlideSpriteVertexStrc gaGlideTileQuad_00880600[4]; // 0x00880600

typedef void (__stdcall* GLIDEDRAWVERTEXARRAYCONTIGUOUS)(int nMode, int nCount, void* pVertices, int nStride);

extern GLIDEDRAWVERTEXARRAYCONTIGUOUS gpfGlideDrawVertexArrayContiguous_0087EAC4; // 0x0087EAC4
void __fastcall sub_0050DBE0_GlideSetVertexAmbientColor(D2GlideSpriteVertexStrc* pVertex, unsigned char nIntensity); // 0x0050DBE0

struct D2TileVertexStrc
{
    unsigned char aColor[4];
    int nX;
    int nY;
};

typedef void (__stdcall* GlideConstantColorFn)(unsigned int dwColor);

typedef void (__stdcall* GlideDrawVertexArrayFn)(int nMode, int nCount, void** ppVertices);

int __fastcall sub_0050FAD0_GlideBindFloorTexture(void* pTile); // 0x0050FAD0
void __fastcall sub_005094B0_GlideSetState(int nState); // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode); // 0x00509500
void __fastcall sub_005095D0_GlideSetDepth(int nMode); // 0x005095D0
extern GlideConstantColorFn gpfGlideConstantColor_0087EFA0; // 0x0087EFA0
extern GlideDrawVertexArrayFn gpfGlideDrawVertexArray_0087EB18; // 0x0087EB18
extern unsigned char* gpBlendTable_00880B5C; // 0x00880B5C
extern D2GfxSettingsStrc* gpGfxSettings_007C9148; // 0x007C9148
extern D2GlideSpriteVertexStrc gaGlideTileVertices_00880678[36]; // 0x00880678
extern void* gapGlideTileFan_0072F670[4]; // 0x0072F670
extern void* gapGlideTileStrips_00880A68[5][12]; // 0x00880A68

// 0x0050C890
int __fastcall sub_0050C890_GlideTileDrawShaded(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, unsigned char nShade, int nScreenPanels)
{
    tagRECT tRect;
    tRect.left = 0;
    tRect.top = 0;
    tRect.right = gnScreenWidth_007C9138;
    tRect.bottom = gnScreenHeight_007C913C - 47;
    tRect.left -= 32;
    tRect.bottom += 32;

    int bDrawn = 0;
    if (nScreenPanels == 1)
    {
        tRect.right += -(gnScreenWidth_007C9138 / 2);
    }
    else if (nScreenPanels == 2)
    {
        tRect.left = gnScreenWidth_007C9138 / 2 - 32;
    }

    nPosY += 32;
    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        int nLeft = nPosX + pTile->pBlocks[i].nPosX;
        int nBottom = pTile->pBlocks[i].nPosY + nPosY;
        if (nLeft >= tRect.left && nLeft < tRect.right && nBottom >= tRect.top && nBottom < tRect.bottom)
        {
            int nTop = nBottom - 32;
            bDrawn = 1;
            int nRight = nLeft + 32;
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);
            gaGlideTileQuad_00880600[0].x = (float)nLeft;
            gaGlideTileQuad_00880600[0].y = (float)nTop;
            gaGlideTileQuad_00880600[1].x = (float)nLeft;
            gaGlideTileQuad_00880600[1].y = (float)nBottom;
            gaGlideTileQuad_00880600[2].x = (float)nRight;
            gaGlideTileQuad_00880600[2].y = (float)nBottom;
            gaGlideTileQuad_00880600[3].x = (float)nRight;
            gaGlideTileQuad_00880600[3].y = (float)nTop;
            sub_0050DBE0_GlideSetVertexAmbientColor(gaGlideTileQuad_00880600, nShade);
            gaGlideTileQuad_00880600[1].dwColor = gaGlideTileQuad_00880600[0].dwColor;
            gaGlideTileQuad_00880600[2].dwColor = gaGlideTileQuad_00880600[0].dwColor;
            gaGlideTileQuad_00880600[3].dwColor = gaGlideTileQuad_00880600[0].dwColor;
            gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, gaGlideTileQuad_00880600, sizeof(D2GlideSpriteVertexStrc));
        }
    }

    return bDrawn;
}

static __forceinline void GLIDE_SetTileVertex(const D2TileVertexStrc* pSource, D2GlideSpriteVertexStrc* pVertex)
{
    const unsigned char* pRow = &gpBlendTable_00880B5C[pSource->aColor[0] << 8];
    pVertex->dwColor = (((-1 << 8 | pRow[pSource->aColor[1]]) << 8 | pRow[pSource->aColor[2]]) << 8) | pRow[pSource->aColor[3]];
    pVertex->x = (float)pSource->nX;
    pVertex->y = (float)pSource->nY;
}

// 0x0050D6A0
void __fastcall sub_0050D6A0_GlideDrawFloorTile(void* pTile, const D2TileVertexStrc* pVertices, int a3, int a4, int a5, int a6, unsigned char nAlpha, int a8, int bDepth)
{
    if (!sub_0050FAD0_GlideBindFloorTexture(pTile))
        return;

    sub_005094B0_GlideSetState(1);
    if (nAlpha == 0xFF)
    {
        sub_00509500_GlideSetCombine(1);
    }
    else
    {
        sub_00509500_GlideSetCombine(4);
        gpfGlideConstantColor_0087EFA0(nAlpha);
    }
    if (bDepth)
        sub_005095D0_GlideSetDepth(2);
    else
        sub_005095D0_GlideSetDepth(1);

    if (gpGfxSettings_007C9148->bLowQuality)
    {
        GLIDE_SetTileVertex(&pVertices[0], &gaGlideTileVertices_00880678[0]);
        GLIDE_SetTileVertex(&pVertices[5], &gaGlideTileVertices_00880678[5]);
        GLIDE_SetTileVertex(&pVertices[35], &gaGlideTileVertices_00880678[35]);
        GLIDE_SetTileVertex(&pVertices[30], &gaGlideTileVertices_00880678[30]);
        gpfGlideDrawVertexArray_0087EB18(5, 4, gapGlideTileFan_0072F670);
        return;
    }

    const D2TileVertexStrc* pSrc = pVertices;
    D2GlideSpriteVertexStrc* pDst = gaGlideTileVertices_00880678;
    for (unsigned int i = 0; i < 36; i++, pSrc++, pDst++)
        GLIDE_SetTileVertex(pSrc, pDst);

    for (int i = 0; i < 5; i++)
        gpfGlideDrawVertexArray_0087EB18(4, 12, gapGlideTileStrips_00880A68[i]);
}

#include "gen/data/Source/D2Glide/Unknown_0050C890.inc"
