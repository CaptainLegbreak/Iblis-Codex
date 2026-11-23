#include "D2DrlgMaps.h"
#include "D2Glide.h"
#include "D2GlideTypes.h"
#include "D2Win32Types.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define GLIDE_VERTEX_IN_RECT(v, r) ((v).x >= (r).left && (v).x < (r).right && (v).y >= (r).top && (v).y < (r).bottom)

extern int gnRenderWidth;                                                                          // 0x007C9138
extern int gnRenderHeight;                                                                         // 0x007C913C
extern int gaGlideWallCorner[10][6][3];                                                          // 0x0072F3A0
extern void* gapGlideTileStripA[10];                                                            // 0x0072F350
extern void* gapGlideTileStripB[10];                                                            // 0x0072F378
extern D2GlideSpriteVertexStrc gaGlideTileGrid[15];                                                 // 0x00880458
extern D2GlideSpriteVertexStrc gaGlideTileQuad[4];                                                  // 0x00880600
extern void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
extern void (__stdcall* gpfnGrDrawVertexArray)(int nMode, int nCount, void** ppVertices);       // 0x0087EB18
extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor);                              // 0x0087EFA0

void __fastcall GLIDE_SetColorCombineMode(int nState);                                                      // 0x005094B0
void __fastcall GLIDE_SetAlphaBlendMode(int nMode);                                                     // 0x00509500
void __fastcall GLIDE_SetTextureFilterMode(int nMode);                                                       // 0x005095D0
void __fastcall sub_0050DBE0_GlideSetVertexShade(D2GlideSpriteVertexStrc* pVertex, unsigned char nShade);   // 0x0050DBE0
void __fastcall GLIDE_SetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor);    // 0x0050DC30
int __cdecl GLIDE_IsPerspective();                                                               // 0x0050DD30
void __fastcall GLIDE_PerspectiveTransform(int nX, int nY, int nZ, int* pScreenX, int* pScreenY);          // 0x0050DD60
void __fastcall sub_0050FBD0_GlideBindTileTexture(D2GlideTileStrc* pTile);                                   // 0x0050FBD0
int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pTile, int a2, int a3);                                   // 0x005FDEA0

// build: context sub_0050C690_GlideGetDrawRect
static void __stdcall sub_0050C690_GlideGetDrawRect(int bPerspective, tagRECT* pRect, int* pOffset, int nScreenPanels)
{
    D2_ASSERT(pRect, 0x54);

    pRect->left = 0;
    pRect->right = gnRenderWidth;
    pRect->top = 0;
    pRect->bottom = gnRenderHeight - 0x2F;

    if (!bPerspective)
    {
        pRect->left = -0x20;
        pRect->bottom += 0x20;
        if (nScreenPanels == 1)
        {
            pRect->right += -(gnRenderWidth / 2);
        }
        else if (nScreenPanels == 2)
        {
            pRect->left = gnRenderWidth / 2 - 0x20;
        }
    }
    else
    {
        D2_ASSERT(pOffset, 0x68);

        const int nQuarter = gnRenderWidth / 4;
        if (nScreenPanels == 1)
        {
            *pOffset = -nQuarter;
            pRect->right -= nQuarter;
            pRect->left += nQuarter;
        }
        else if (nScreenPanels == 2)
        {
            *pOffset = nQuarter;
            pRect->right -= nQuarter;
            pRect->left += nQuarter;
        }
    }
}

int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels); // 0x0050CA00

// 0x0050CDD0
static int __stdcall sub_0050CDD0_GlideTileDrawFlat(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels)
{
    int nResult = 0;
    tagRECT tRect;
    sub_0050C690_GlideGetDrawRect(0, &tRect, 0, nScreenPanels);
    nPosY += 0x20;

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        const int nBlockX = pTile->pBlocks[i].nPosX;
        const int nX = nPosX + nBlockX;
        const int nY = pTile->pBlocks[i].nPosY + nPosY;
        if (nX >= tRect.left && nX < tRect.right && nY >= tRect.top && nY < tRect.bottom)
        {
            const int nCol = nBlockX >> 5;
            const unsigned int dwColor0 = pLight->aColor[nCol];
            const unsigned int dwColor1 = pLight->aColor[nCol + 1];
            const int nY1 = nY - 0x20;
            const int nX1 = nX + 0x20;
            nResult = 1;
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);

            gaGlideTileQuad[0].x = (float)nX;
            gaGlideTileQuad[0].y = (float)nY1;
            gaGlideTileQuad[1].x = (float)nX;
            gaGlideTileQuad[1].y = (float)nY;
            gaGlideTileQuad[2].x = (float)nX1;
            gaGlideTileQuad[2].y = (float)nY;
            gaGlideTileQuad[3].x = (float)nX1;
            gaGlideTileQuad[3].y = (float)nY1;
            GLIDE_SetVertexColor(&gaGlideTileQuad[0], dwColor0);
            GLIDE_SetVertexColor(&gaGlideTileQuad[1], dwColor0);
            GLIDE_SetVertexColor(&gaGlideTileQuad[2], dwColor1);
            GLIDE_SetVertexColor(&gaGlideTileQuad[3], dwColor1);
            gpfnGrDrawVertexArrayContiguous(5, 4, gaGlideTileQuad, sizeof(D2GlideSpriteVertexStrc));
        }
    }

    return nResult;
}

int __stdcall sub_0050CF70_GlideTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels); // 0x0050CF70

int __stdcall sub_0050D410_GlideTileDrawAlpha(int nPosX, int nPosY, D2GfxLightStrc* pLight, unsigned char nAlpha, D2TileLibraryEntryStrc* pTile, int nScreenPanels); // 0x0050D410

// 0x0050D4C0
int __fastcall sub_0050D4C0_GlideTileDrawLit(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels)
{
    int nResult = 0;
    if (D2CMPTileValidate(pTile, 1, 0))
    {
        GLIDE_SetColorCombineMode(1);
        GLIDE_SetAlphaBlendMode(1);
        GLIDE_SetTextureFilterMode(1);
        if (GLIDE_IsPerspective())
        {
            nResult = sub_0050CF70_GlideTileDrawPerspective(pTile, nPosX, nPosY, pLight, nScreenPanels);
        }
        else
        {
            nResult = sub_0050CDD0_GlideTileDrawFlat(pTile, nPosX, nPosY, pLight, nScreenPanels);
        }
    }

    return nResult;
}

#include "gen/data/Source/D2Glide/Unknown_0050D410.inc"
