#include "D2Glide.h"
#include "D2DrlgMaps.h"

extern int gnRenderWidth; // 0x007C9138
extern D2GlideSpriteVertexStrc gaGlideTileQuad[4]; // 0x00880600

typedef void (__stdcall* GLIDEDRAWVERTEXARRAYCONTIGUOUS)(int nMode, int nCount, void* pVertices, int nStride);

extern GLIDEDRAWVERTEXARRAYCONTIGUOUS gpfnGrDrawVertexArrayContiguous; // 0x0087EAC4
void __fastcall GLVERTEX_SetVertexAmbientColor(D2GlideSpriteVertexStrc* pVertex, unsigned char nIntensity); // 0x0050DBE0

struct D2TileVertexStrc
{
    unsigned char aColor[4];
    int nX;
    int nY;
};

typedef void (__stdcall* GlideConstantColorFn)(unsigned int dwColor);

typedef void (__stdcall* GlideDrawVertexArrayFn)(int nMode, int nCount, void** ppVertices);

int __fastcall GLTEXTURECACHE_BindFloorTexture(void* pTile); // 0x0050FAD0
void __fastcall GLCORE_SetColorCombineMode(int nState); // 0x005094B0
void __fastcall GLCORE_SetAlphaBlendMode(int nMode); // 0x00509500
void __fastcall GLCORE_SetTextureFilterMode(int nMode); // 0x005095D0
extern GlideConstantColorFn gpfnGrConstantColorValue; // 0x0087EFA0
extern GlideDrawVertexArrayFn gpfnGrDrawVertexArray; // 0x0087EB18
extern unsigned char* gpBlendTable; // 0x00880B5C
extern D2GfxSettingsStrc* gpGfxSettings; // 0x007C9148
extern D2GlideSpriteVertexStrc gatGlideTileVertices[36]; // 0x00880678
extern void* gapGlideTileFan[4]; // 0x0072F670
extern void* gapGlideTileStrips_00880A68[5][12]; // 0x00880A68

// 0x0050C890
int __fastcall sub_0050C890_GlideTileDrawShaded(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, unsigned char nShade, int nScreenPanels)
{
    tagRECT tRect;
    tRect.left = 0;
    tRect.top = 0;
    tRect.right = gnRenderWidth;
// build: symbol ?gnRenderHeight@* 0x007C913C
    tRect.bottom = gnRenderHeight - 47;
    tRect.left -= 32;
    tRect.bottom += 32;

    int bDrawn = 0;
    if (nScreenPanels == 1)
    {
        tRect.right += -(gnRenderWidth / 2);
    }
    else if (nScreenPanels == 2)
    {
        tRect.left = gnRenderWidth / 2 - 32;
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
            gaGlideTileQuad[0].x = (float)nLeft;
            gaGlideTileQuad[0].y = (float)nTop;
            gaGlideTileQuad[1].x = (float)nLeft;
            gaGlideTileQuad[1].y = (float)nBottom;
            gaGlideTileQuad[2].x = (float)nRight;
            gaGlideTileQuad[2].y = (float)nBottom;
            gaGlideTileQuad[3].x = (float)nRight;
            gaGlideTileQuad[3].y = (float)nTop;
            GLVERTEX_SetVertexAmbientColor(gaGlideTileQuad, nShade);
            gaGlideTileQuad[1].dwColor = gaGlideTileQuad[0].dwColor;
            gaGlideTileQuad[2].dwColor = gaGlideTileQuad[0].dwColor;
            gaGlideTileQuad[3].dwColor = gaGlideTileQuad[0].dwColor;
            gpfnGrDrawVertexArrayContiguous(5, 4, gaGlideTileQuad, sizeof(D2GlideSpriteVertexStrc));
        }
    }

    return bDrawn;
}

static __forceinline void GLIDE_SetTileVertex(const D2TileVertexStrc* pSource, D2GlideSpriteVertexStrc* pVertex)
{
    const unsigned char* pRow = &gpBlendTable[pSource->aColor[0] << 8];
    pVertex->dwColor = (((-1 << 8 | pRow[pSource->aColor[1]]) << 8 | pRow[pSource->aColor[2]]) << 8) | pRow[pSource->aColor[3]];
    pVertex->x = (float)pSource->nX;
    pVertex->y = (float)pSource->nY;
}

// 0x0050D6A0
void __fastcall sub_0050D6A0_GlideDrawFloorTile(void* pTile, const D2TileVertexStrc* pVertices, int a3, int a4, int a5, int a6, unsigned char nAlpha, int a8, int bDepth)
{
    if (!GLTEXTURECACHE_BindFloorTexture(pTile))
        return;

    GLCORE_SetColorCombineMode(1);
    if (nAlpha == 0xFF)
    {
        GLCORE_SetAlphaBlendMode(1);
    }
    else
    {
        GLCORE_SetAlphaBlendMode(4);
        gpfnGrConstantColorValue(nAlpha);
    }
    if (bDepth)
        GLCORE_SetTextureFilterMode(2);
    else
        GLCORE_SetTextureFilterMode(1);

    if (gpGfxSettings->bLowQuality)
    {
        GLIDE_SetTileVertex(&pVertices[0], &gatGlideTileVertices[0]);
        GLIDE_SetTileVertex(&pVertices[5], &gatGlideTileVertices[5]);
        GLIDE_SetTileVertex(&pVertices[35], &gatGlideTileVertices[35]);
        GLIDE_SetTileVertex(&pVertices[30], &gatGlideTileVertices[30]);
        gpfnGrDrawVertexArray(5, 4, gapGlideTileFan);
        return;
    }

    const D2TileVertexStrc* pSrc = pVertices;
    D2GlideSpriteVertexStrc* pDst = gatGlideTileVertices;
    for (unsigned int i = 0; i < 36; i++, pSrc++, pDst++)
        GLIDE_SetTileVertex(pSrc, pDst);

    for (int i = 0; i < 5; i++)
        gpfnGrDrawVertexArray(4, 12, gapGlideTileStrips_00880A68[i]);
}

#include "gen/data/Source/D2Glide/Unknown_0050C890.inc"
