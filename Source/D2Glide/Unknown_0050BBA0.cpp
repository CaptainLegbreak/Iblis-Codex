#include "D2Glide.h"
#include "D2DrlgMaps.h"

struct D2GlideDebugCellStrc;
struct D2GfxLightStrc;
struct D2GlideVtxStrc;

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC
extern void (__stdcall* gpfnGrTexSource)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98
extern void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
extern D2GlideSpriteVertexStrc gaGlideDebugFontVertices[4]; // 0x00880258
extern int gaGlideDebugFontTexAddr[96]; // 0x008800D8
extern D2GrTexInfoStrc gtGlideDebugFontTexInfo; // 0x0072F2B4
void __fastcall GLIDE_SetColorCombineMode(int nState); // 0x005094B0
void __fastcall GLIDE_SetAlphaBlendMode(int nMode); // 0x00509500
void __fastcall GLIDE_SetTextureFilterMode(int nMode); // 0x005095D0
void __fastcall GLIDE_SetTextureCombineMode(int nTmu); // 0x00509460
extern void (__stdcall* gpfnGrColorCombine)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C
extern void (__stdcall* gpfnGrChromakeyMode)(int bEnable); // 0x0087EB8C
extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor); // 0x0087EFA0
extern D2GlideDebugCellStrc** gppGlideDebugBuffer; // 0x00880454

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern int gnRenderWidth; // 0x007C9138
extern D2GlideSpriteVertexStrc gaGlideTileGrid[15]; // 0x00880458
extern D2GlideSpriteVertexStrc gaGlideTileQuad[4]; // 0x00880600
extern void (__stdcall* gpfnGrDrawVertexArray)(int nMode, int nCount, void** ppVertices); // 0x0087EB18
void __fastcall GLIDE_SetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor); // 0x0050DC30
int __cdecl GLIDE_IsPerspective(); // 0x0050DD30
void __fastcall GLIDE_PerspectiveTransform(int nX, int nY, int nZ, int* pScreenX, int* pScreenY); // 0x0050DD60

struct D2GlideVtxStrc { float x; float y; float z; float oow; float sow; float tow; unsigned int color; };

extern D2GlideVtxStrc gaGlideVertices_00880678[36]; // 0x00880678
extern D2GlideVtxStrc* gapGlideTileStrips[60]; // 0x00880A68

int gaGlideDebugFontCharWidths[96]; // 0x008802C8

int gnGlideDebugFontTmu; // 0x00880450

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

void sub_0050BD80_GlideDebugDrawLights()
{
    gpfnGrColorCombine(1, 0, 1, 2, 0);
    gpfnGrChromakeyMode(0);
    for (int j = 0; j < 32; ++j)
    {
        for (int i = 0; i < 32; ++i)
// build: symbol ?gaGlideLightPalette@* 0x0072F308
// build: symbol ?gaGlideDebugLight@* 0x0087F0D0
            sub_0050BD30_GlideDrawPointCross(gaGlideLightPalette[gaGlideDebugLight[j * 32 + i]], (0x113 - j + i) * 2, (j + i + 50) * 2);
    }
    gpfnGrColorCombine(3, 1, 0, 1, 0);
    gpfnGrChromakeyMode(1);
}

// 0x0050BE20
void __cdecl sub_0050BE20_GlideDebugRefresh()
{
    gpfnGrColorCombine(1, 0, 1, 2, 0);
    gpfnGrChromakeyMode(0);
    for (int j = 0; j < 48; ++j)
    {
        for (int i = 0; i < 48; ++i)
        {
            int nX = i * 2 + 100;
            nX -= j << 1;
            const int nY = (j + i + 50) * 2;
            unsigned int dwColor;
            if (j == 24 && i == j)
            {
                dwColor = 0;
                sub_0050BD30_GlideDrawPointCross(dwColor, nX, nY);
            }
            else
            {
                const D2GlideDebugCellStrc* pCell = &gppGlideDebugBuffer[j][i];
                const unsigned int nAlpha = pCell->nAlpha;
                dwColor = ((pCell->nRed * nAlpha / 256 * 256 + pCell->nGreen * nAlpha / 256) * 256 + pCell->nBlue * nAlpha / 256) * 256;
                sub_0050BD30_GlideDrawPointCross(dwColor, nX, nY);
            }
        }
    }
    gpfnGrColorCombine(3, 1, 0, 1, 0);
    gpfnGrChromakeyMode(1);
}

// 0x0050C690
static void __stdcall sub_0050C690_GlideGetDrawRect(int bPerspective, tagRECT* pRect, int nScreenPanels, int* pOffset)
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

int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels)
{
    int nResult = 0;
    int nOffset = 0;
    tagRECT tRect;
    sub_0050C690_GlideGetDrawRect(1, &tRect, nScreenPanels, &nOffset);

    nPosY <<= 13;
    nPosX <<= 13;
    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        D2GlideTileStrc* pBlock = &pTile->pBlocks[i];
        const int nCol = pBlock->nPosX >> 5;
        const int nRow = (pBlock->nPosY + 0x60) >> 5;
        const int nWorldX = ((nCol + nRow * 2) << 16) - 0x38000;
        const int nWorldY = ((2 * nRow - nCol) << 16) + 0x18000;
        const int nX0 = nPosX + nWorldX;
        const int nY0 = nPosY + nWorldY;
        int nScreenX;
        int nScreenY;

        GLIDE_PerspectiveTransform(nX0, nY0, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid[0].x = (float)nScreenX;
        gaGlideTileGrid[0].y = (float)nScreenY;
        GLIDE_PerspectiveTransform(nPosX + nWorldX + 0x20000, nPosY + nWorldY + 0x20000, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid[12].x = (float)nScreenX;
        gaGlideTileGrid[12].y = (float)nScreenY;
        GLIDE_PerspectiveTransform(nPosX + nWorldX + 0x30000, nPosY + nWorldY + 0x10000, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid[14].x = (float)nScreenX;
        gaGlideTileGrid[14].y = (float)nScreenY;
        GLIDE_PerspectiveTransform(nPosX + nWorldX + 0x10000, nPosY + nWorldY - 0x10000, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid[2].x = (float)nScreenX;
        gaGlideTileGrid[2].y = (float)nScreenY;

        if (GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[0], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[12], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[14], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[2], tRect))
        {
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);

            const float fOffset = (float)nOffset;
            int nRowX = nX0;
            int nRowY = nY0;
            for (int nGridRow = 0; nGridRow < 5; ++nGridRow)
            {
                for (int nGridCol = 0; nGridCol < 3; ++nGridCol)
                {
                    D2GlideSpriteVertexStrc* pVertex = &gaGlideTileGrid[nGridRow * 3 + nGridCol];
                    GLIDE_PerspectiveTransform(nRowX + nGridCol * 0x8000, nRowY - nGridCol * 0x8000, 0, &nScreenX, &nScreenY);
                    pVertex->y = (float)nScreenY;
                    pVertex->x = (float)nScreenX + fOffset;
                    sub_0050DBE0_GlideSetVertexShade(pVertex, eDrawMode);
                }

                nRowX += 0x8000;
                nRowY += 0x8000;
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

static int __stdcall sub_0050CDD0_GlideTileDrawFlat(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels)
{
    int nResult = 0;
    tagRECT tRect;
    sub_0050C690_GlideGetDrawRect(0, &tRect, nScreenPanels, 0);

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

static int __stdcall sub_0050CF70_GlideTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels)
{
    int nResult = 0;
    int nOffset = 0;
    tagRECT tRect;
    sub_0050C690_GlideGetDrawRect(1, &tRect, nScreenPanels, &nOffset);

    const int nType = pTile->nLightDirection;
    nPosY <<= 13;
    nPosX <<= 13;
    D2_ASSERT(nType >= 0 && nType <= 9, 0x1B4);

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        D2GlideTileStrc* pBlock = &pTile->pBlocks[i];
        const int nCol = pBlock->nPosX >> 5;
        const int nHeight = pBlock->nPosY;
        D2_ASSERT(nCol >= 0 && nCol <= 4, 0x1BC);

// build: symbol ?gaGlideWallCorner@* 0x0072F3A0
        const int* pCorner0 = gaGlideWallCorner[nType][nCol];
        const int* pCorner1 = gaGlideWallCorner[nType][nCol + 1];
        const int nX0 = pCorner0[0] + nPosX;
        const int nZ0 = pCorner0[2] - nHeight;
        const int nY0 = pCorner0[1] + nPosY;
        const int nX1 = pCorner1[0] + nPosX;
        const int nZ1 = pCorner1[2] - nHeight;
        const int nY1 = pCorner1[1] + nPosY;
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
            const unsigned int dwColor0 = pLight->aColor[nCol];
            const unsigned int dwColor1 = pLight->aColor[nCol + 1];
            unsigned int aColors[3];
            aColors[0] = dwColor0;
            const int nMixA = (unsigned char)(((unsigned char)(dwColor0 >> 24) + (unsigned char)(dwColor1 >> 24)) >> 1);
            const int nMixR = (unsigned char)(((unsigned char)(dwColor0 >> 16) + (unsigned char)(dwColor1 >> 16)) >> 1);
            const int nMixG = (unsigned char)(((unsigned char)(dwColor0 >> 8) + (unsigned char)(dwColor1 >> 8)) >> 1);
            const int nMixB = (unsigned char)(((unsigned char)dwColor0 + (unsigned char)dwColor1) >> 1);
            aColors[1] = (((((nMixA << 8) + nMixR) << 8) + nMixG) << 8) + nMixB;
            aColors[2] = dwColor1;
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

            gpfnGrDrawVertexArray(4, 10, gapGlideTileStripA);
            gpfnGrDrawVertexArray(4, 10, gapGlideTileStripB);
            nResult = 1;
        }
    }

    return nResult;
}

int __stdcall sub_0050D410_GlideTileDrawAlpha(int nPosX, int nPosY, D2GfxLightStrc* pLight, unsigned char nAlpha, D2TileLibraryEntryStrc* pTile, int nScreenPanels); // 0x0050D410

static inline float ScaleTexCoord(double dA, double dB, double dScale)
{
    return (float)(int)((dA + dB) * dScale);
}

// 0x0050D540
void __cdecl sub_0050D540_GlideInitD()
{
    D2GlideVtxStrc* pVertex = &gaGlideVertices_00880678[0];
    for (int nRow = 0; nRow < 6; ++nRow)
    {
        for (int nCol = 0; nCol < 6; ++nCol, ++pVertex)
        {
            int nBiasS = 0;
            int nBiasT = 0;
            if (nCol == 0)
            {
                nBiasS = nBiasT = 1;
            }
            else if (nCol == 5)
            {
                nBiasS = nBiasT = -1;
            }

            if (nRow == 0)
            {
                nBiasS -= 1;
                nBiasT += 1;
            }
            else if (nRow == 5)
            {
                nBiasS += 1;
                nBiasT -= 1;
            }

            pVertex->oow = 1.0f;
            pVertex->sow = ScaleTexCoord((float)((nBiasS + 80) * 0.00390625), (nCol - nRow) * 0.0625, 256.0);
            double const tArg3 = (nCol + nRow) * 0.0625;
            pVertex->tow = ScaleTexCoord(tArg3, (float)(nBiasT * 0.0078125), 128.0);
        }
    }

    for (int nRow = 0; nRow < 5; ++nRow)
    {
        for (int nCol = 0; nCol < 6; ++nCol)
        {
            gapGlideTileStrips[12 * nRow + 2 * nCol] = &gaGlideVertices_00880678[6 * nRow + nCol];
            D2GlideVtxStrc** ppBottom = &gapGlideTileStrips[12 * nRow + 2 * nCol + 1];
            *ppBottom = &gaGlideVertices_00880678[6 * nRow + nCol + 6];
        }
    }
}
