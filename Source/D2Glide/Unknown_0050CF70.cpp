#include "D2Glide.h"
#include "D2DrlgMaps.h"

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern int gnRenderWidth;                                                                          // 0x007C9138
extern D2GlideSpriteVertexStrc gaGlideTileGrid[15];                                                 // 0x00880458
extern D2GlideSpriteVertexStrc gaGlideTileQuad[4];                                                  // 0x00880600
typedef void (__stdcall* DrawContiguous)(int,int,void*,int);
extern DrawContiguous gpfnGrDrawVertexArrayContiguous; // 0x0087EAC4
typedef void (__stdcall* DrawArray)(int,int,void**);
extern DrawArray gpfnGrDrawVertexArray; // 0x0087EB18
typedef void (__stdcall* ConstantColor)(unsigned int);
extern ConstantColor gpfnGrConstantColorValue; // 0x0087EFA0

void __fastcall GLIDE_SetColorCombineMode(int nState);                                                      // 0x005094B0
void __fastcall GLIDE_SetAlphaBlendMode(int nMode);                                                     // 0x00509500
void __fastcall GLIDE_SetTextureFilterMode(int nMode);                                                       // 0x005095D0
void __fastcall GLIDE_SetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor);    // 0x0050DC30
int __cdecl GLIDE_IsPerspective();                                                               // 0x0050DD30
void __fastcall GLIDE_PerspectiveTransform(int nX, int nY, int nZ, int* pScreenX, int* pScreenY);          // 0x0050DD60

// 0x0050C690
static void __stdcall sub_0050C690_GlideGetDrawRect(int bPerspective, int nScreenPanels, tagRECT* pRect, int* pOffset)
{
    D2_ASSERT(pRect, 0x54);

    pRect->left = 0;
    pRect->right = gnRenderWidth;
    pRect->top = 0;
// build: symbol ?gnRenderHeight@* 0x007C913C
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
        }
        else if (nScreenPanels == 2)
        {
            *pOffset = nQuarter;
        }
        else
        {
            return;
        }
        pRect->right -= nQuarter;
        pRect->left += nQuarter;
    }
}
static void __stdcall sub_0050C690_GlideGetDrawRect(int bPerspective, int nScreenPanels, tagRECT* pRect, int* pOffset); // 0x0050C690

// build: context sub_0050CDD0_GlideTileDrawFlat
static int __stdcall sub_0050CDD0_GlideTileDrawFlat(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels)
{
    int nResult = 0;
    tagRECT tRect;
    sub_0050C690_GlideGetDrawRect(0, nScreenPanels, &tRect, 0);

    nPosY += 0x20;
    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        D2GlideTileStrc* pBlock = &pTile->pBlocks[i];
        const int nX = nPosX + pBlock->nPosX;
        const int nY = pBlock->nPosY + nPosY;
        if (nX >= tRect.left && nX < tRect.right && nY >= tRect.top && nY < tRect.bottom)
        {
            const int nCol = pBlock->nPosX >> 5;
            const unsigned int dwColor0 = pLight->aColor[nCol];
            const unsigned int dwColor1 = pLight->aColor[nCol + 1];
            const int nY1 = nY - 0x20;
            const int nX1 = nX + 0x20;
            nResult = 1;
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);

            const float fX0 = (float)nX;
            const float fY1 = (float)nY1;
            const float fY0 = (float)nY;
            const float fX1 = (float)nX1;
            gaGlideTileQuad[0].x = fX0;
            gaGlideTileQuad[0].y = fY1;
            gaGlideTileQuad[1].x = fX0;
            gaGlideTileQuad[1].y = fY0;
            gaGlideTileQuad[2].x = fX1;
            gaGlideTileQuad[2].y = fY0;
            gaGlideTileQuad[3].x = fX1;
            gaGlideTileQuad[3].y = fY1;
            GLIDE_SetVertexColor(&gaGlideTileQuad[0], dwColor0);
            GLIDE_SetVertexColor(&gaGlideTileQuad[1], dwColor0);
            GLIDE_SetVertexColor(&gaGlideTileQuad[2], dwColor1);
            GLIDE_SetVertexColor(&gaGlideTileQuad[3], dwColor1);
            gpfnGrDrawVertexArrayContiguous(5, 4, gaGlideTileQuad, sizeof(D2GlideSpriteVertexStrc));
        }
    }

    return nResult;
}
static int __stdcall sub_0050CDD0_GlideTileDrawFlat(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels); // 0x0050CDD0
// 0x0050CF70
static int __stdcall sub_0050CF70_GlideTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels)
{
    int nResult = 0;
    int nOffset = 0;
    tagRECT tRect;
    sub_0050C690_GlideGetDrawRect(1, nScreenPanels, &tRect, &nOffset);

    nPosY <<= 13;
    nPosX <<= 13;
    const int nType = pTile->nLightDirection;
    D2_ASSERT(nType >= 0 && nType <= 9, 0x1B4);

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        const int nCol = pTile->pBlocks[i].nPosX >> 5;
        const int nHeight = pTile->pBlocks[i].nPosY;
        D2_ASSERT(nCol >= 0 && nCol <= 4, 0x1BC);

// build: symbol ?gaGlideWallCorner@* 0x0072F3A0
        const int nX0 = gaGlideWallCorner[nType][nCol][0] + nPosX;
        const int nY0 = gaGlideWallCorner[nType][nCol][1] + nPosY;
        const int nZ0 = gaGlideWallCorner[nType][nCol][2] - nHeight;
        const int nX1 = gaGlideWallCorner[nType][nCol + 1][0] + nPosX;
        const int nY1 = gaGlideWallCorner[nType][nCol + 1][1] + nPosY;
        const int nZ1 = gaGlideWallCorner[nType][nCol + 1][2] - nHeight;
        int nScreenX;
        int nScreenY;

        GLIDE_PerspectiveTransform(nX0, nY0, nZ0, &nScreenX, &nScreenY);
        gaGlideTileGrid[0].x = (float)nScreenX;
        gaGlideTileGrid[0].y = (float)nScreenY;
        GLIDE_PerspectiveTransform(nX0, nY0, nZ0 - 0x20, &nScreenX, &nScreenY);
        gaGlideTileGrid[12].x = (float)nScreenX;
        gaGlideTileGrid[12].y = (float)nScreenY;
        GLIDE_PerspectiveTransform(nX1, nY1, nZ1 - 0x20, &nScreenX, &nScreenY);
        gaGlideTileGrid[14].x = (float)nScreenX;
        gaGlideTileGrid[14].y = (float)nScreenY;
        GLIDE_PerspectiveTransform(nX1, nY1, nZ1, &nScreenX, &nScreenY);
        gaGlideTileGrid[2].x = (float)nScreenX;
        gaGlideTileGrid[2].y = (float)nScreenY;

        if (GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[0], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[12], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[14], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[2], tRect))
        {
            const int nMidX = (nX0 + nX1) >> 1;
            const int nMidY = (nY0 + nY1) >> 1;
            const int nMidZ = (nZ0 + nZ1) >> 1;
            unsigned int aColors[3];
            aColors[0] = pLight->aColor[nCol];
            aColors[2] = pLight->aColor[nCol + 1];
            const int nMixA = (unsigned char)(((unsigned char)(aColors[2] >> 24) + (unsigned char)(aColors[0] >> 24)) >> 1);
            const int nMixR = (unsigned char)(((unsigned char)(aColors[2] >> 16) + (unsigned char)(aColors[0] >> 16)) >> 1);
            const int nMixG = (unsigned char)(((unsigned char)(aColors[2] >> 8) + (unsigned char)(aColors[0] >> 8)) >> 1);
            const int nMixB = (unsigned char)(((unsigned char)aColors[2] + (unsigned char)aColors[0]) >> 1);
            aColors[1] = (((((nMixA << 8) + nMixR) << 8) + nMixG) << 8) + nMixB;
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);

            const float fOffset = (float)nOffset;
            for (int nGridRow = 0; nGridRow < 5; ++nGridRow)
            {
                const int nDepth = nGridRow << 3;
                if (nGridRow != 0 && nGridRow != 4)
                {
                    GLIDE_PerspectiveTransform(nX0, nY0, nZ0 - nDepth, &nScreenX, &nScreenY);
                    gaGlideTileGrid[nGridRow * 3].x = (float)nScreenX;
                    gaGlideTileGrid[nGridRow * 3].y = (float)nScreenY;
                    GLIDE_PerspectiveTransform(nX1, nY1, nZ1 - nDepth, &nScreenX, &nScreenY);
                    gaGlideTileGrid[nGridRow * 3 + 2].x = (float)nScreenX;
                    gaGlideTileGrid[nGridRow * 3 + 2].y = (float)nScreenY;
                }

                GLIDE_PerspectiveTransform(nMidX, nMidY, nMidZ - nDepth, &nScreenX, &nScreenY);
                gaGlideTileGrid[nGridRow * 3 + 1].x = (float)nScreenX;
                gaGlideTileGrid[nGridRow * 3 + 1].y = (float)nScreenY;
                for (int nGridCol = 0; nGridCol < 3; ++nGridCol)
                {
                    D2GlideSpriteVertexStrc* pVertex = &gaGlideTileGrid[nGridRow * 3 + nGridCol];
                    pVertex->x = pVertex->x + fOffset;
                    GLIDE_SetVertexColor(pVertex, aColors[nGridCol]);
                }
            }

// build: symbol ?gapGlideTileStripA@* 0x0072F350
            gpfnGrDrawVertexArray(4, 10, gapGlideTileStripA);
// build: symbol ?gapGlideTileStripB@* 0x0072F378
            gpfnGrDrawVertexArray(4, 10, gapGlideTileStripB);
            nResult = 1;
        }
    }

    return nResult;
}
static int __stdcall sub_0050CF70_GlideTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels); // 0x0050CF70
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
int __fastcall sub_0050D4C0_GlideTileDrawLit(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels); // 0x0050D4C0
