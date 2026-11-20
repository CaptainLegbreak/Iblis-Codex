#include "D2Glide.h"
#include "D2DrlgMaps.h"
struct D2GlideDebugCellStrc;
struct D2GfxLightStrc;
struct D2GlideVtxStrc;

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

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC
extern void (__stdcall* gpfGlideTexSource_0087EB98)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98
extern void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
extern T00508FE0 gaGlideDebugFontVertices_00880258[4]; // 0x00880258
extern int gaGlideDebugFontTexAddr_008800D8[96]; // 0x008800D8
extern D2GrTexInfoStrc gGlideDebugFontTexInfo_0072F2B4; // 0x0072F2B4
void __fastcall sub_005094B0_GlideSetState(int nState); // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode); // 0x00509500
void __fastcall sub_005095D0_GlideSetDepth(int nMode); // 0x005095D0
void __fastcall sub_00509460_GlideSelectTmuState(int nTmu); // 0x00509460
extern void (__stdcall* gpfGlideColorCombine_0087EB2C)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C
extern void (__stdcall* gpfGlideMask_0087EB8C)(int bEnable); // 0x0087EB8C
extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor); // 0x0087EFA0
extern D2GlideDebugCellStrc** gppGlideDebugBuffer_00880454; // 0x00880454

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern int gnScreenWidth_007C9138; // 0x007C9138
extern D2GlideSpriteVertexStrc gaGlideTileGrid_00880458[15]; // 0x00880458
extern D2GlideSpriteVertexStrc gaGlideTileQuad_00880600[4]; // 0x00880600
extern void (__stdcall* gpfGlideDrawVertexArray_0087EB18)(int nMode, int nCount, void** ppVertices); // 0x0087EB18
void __fastcall sub_0050DC30_GlideSetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor); // 0x0050DC30
int __cdecl sub_0050DD30_GlideIsPerspective(); // 0x0050DD30
void __fastcall sub_0050DD60_ProjectToScreen(int nX, int nY, int nZ, int* pScreenX, int* pScreenY); // 0x0050DD60

struct D2GlideVtxStrc { float x; float y; float z; float oow; float sow; float tow; unsigned int color; };

extern D2GlideVtxStrc gaGlideVertices_00880678[36]; // 0x00880678
extern D2GlideVtxStrc* gaGlideStrips_00880A68[60]; // 0x00880A68

int gaGlideDebugFontCharWidths_008802C8[96]; // 0x008802C8

int gnGlideDebugFontTmu_00880450; // 0x00880450

// 0x0050BBA0
static int __stdcall sub_0050BBA0_GlideDebugDrawChar(char ch, int nX, int nY)
{
    if (nX > 640)
        return 0;

    if (nX < 0)
        return gaGlideDebugFontCharWidths_008802C8[ch];

    if ((unsigned char)(ch - 0x20) <= 0x5F)
    {
        const int nRight = nX + 8;
        const int nBottom = nY + 16;
        gaGlideDebugFontVertices_00880258[0].x = (float)nX;
        gaGlideDebugFontVertices_00880258[0].y = (float)nY;
        gaGlideDebugFontVertices_00880258[1].x = (float)nX;
        gaGlideDebugFontVertices_00880258[1].y = (float)nBottom;
        gaGlideDebugFontVertices_00880258[2].x = (float)nRight;
        gaGlideDebugFontVertices_00880258[2].y = (float)nBottom;
        gaGlideDebugFontVertices_00880258[3].x = (float)nRight;
        gaGlideDebugFontVertices_00880258[3].y = (float)nY;

        ch -= 0x20;
        gpfGlideTexSource_0087EB98(gnGlideDebugFontTmu_00880450, gaGlideDebugFontTexAddr_008800D8[ch], 3, &gGlideDebugFontTexInfo_0072F2B4);
        gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, gaGlideDebugFontVertices_00880258, sizeof(T00508FE0));
        return gaGlideDebugFontCharWidths_008802C8[ch];
    }

    return gaGlideDebugFontCharWidths_008802C8[0];
}

// 0x0050BC90
void __fastcall sub_0050BC90_GlideDebugPrintf(int nX, int nY, const char* szFormat, char* args)
{
    char szText[0x200];
    const int nLength = wvsprintfA(szText, szFormat, args);
    const int nStartX = nX;

    sub_005094B0_GlideSetState(1);
    sub_00509500_GlideSetCombine(1);
    sub_005095D0_GlideSetDepth(1);
    sub_00509460_GlideSelectTmuState(gnGlideDebugFontTmu_00880450);

    for (int i = 0; i < nLength; ++i)
    {
        nX += sub_0050BBA0_GlideDebugDrawChar(szText[i], nX, nY);
        if (szText[i] == '\n')
        {
            nX = nStartX;
            nY += 12;
        }
    }
}

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

void sub_0050BD80_GlideDebugDrawLights()
{
    gpfGlideColorCombine_0087EB2C(1, 0, 1, 2, 0);
    gpfGlideMask_0087EB8C(0);
    for (int j = 0; j < 32; ++j)
    {
        for (int i = 0; i < 32; ++i)
            sub_0050BD30_GlideDrawPointCross(gaGlideLightPalette_0072F308[gaGlideDebugLight_0087F0D0[j * 32 + i]], (0x113 - j + i) * 2, (j + i + 50) * 2);
    }
    gpfGlideColorCombine_0087EB2C(3, 1, 0, 1, 0);
    gpfGlideMask_0087EB8C(1);
}

// 0x0050BE20
void __cdecl sub_0050BE20_GlideDebugRefresh()
{
    gpfGlideColorCombine_0087EB2C(1, 0, 1, 2, 0);
    gpfGlideMask_0087EB8C(0);
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
                const D2GlideDebugCellStrc* pCell = &gppGlideDebugBuffer_00880454[j][i];
                const unsigned int nAlpha = pCell->nAlpha;
                dwColor = ((pCell->nRed * nAlpha / 256 * 256 + pCell->nGreen * nAlpha / 256) * 256 + pCell->nBlue * nAlpha / 256) * 256;
                sub_0050BD30_GlideDrawPointCross(dwColor, nX, nY);
            }
        }
    }
    gpfGlideColorCombine_0087EB2C(3, 1, 0, 1, 0);
    gpfGlideMask_0087EB8C(1);
}

// 0x0050C690
static void __stdcall sub_0050C690_GlideGetDrawRect(int bPerspective, tagRECT* pRect, int nScreenPanels, int* pOffset)
{
    D2_ASSERT(pRect, 0x54);

    pRect->left = 0;
    pRect->right = gnScreenWidth_007C9138;
    pRect->top = 0;
    pRect->bottom = gnScreenHeight_007C913C - 0x2F;

    if (!bPerspective)
    {
        pRect->left = -0x20;
        pRect->bottom += 0x20;
        if (nScreenPanels == 1)
        {
            pRect->right += -(gnScreenWidth_007C9138 / 2);
        }
        else if (nScreenPanels == 2)
        {
            pRect->left = gnScreenWidth_007C9138 / 2 - 0x20;
        }
    }
    else
    {
        D2_ASSERT(pOffset, 0x68);

        const int nQuarter = gnScreenWidth_007C9138 / 4;
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

        sub_0050DD60_ProjectToScreen(nX0, nY0, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid_00880458[0].x = (float)nScreenX;
        gaGlideTileGrid_00880458[0].y = (float)nScreenY;
        sub_0050DD60_ProjectToScreen(nPosX + nWorldX + 0x20000, nPosY + nWorldY + 0x20000, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid_00880458[12].x = (float)nScreenX;
        gaGlideTileGrid_00880458[12].y = (float)nScreenY;
        sub_0050DD60_ProjectToScreen(nPosX + nWorldX + 0x30000, nPosY + nWorldY + 0x10000, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid_00880458[14].x = (float)nScreenX;
        gaGlideTileGrid_00880458[14].y = (float)nScreenY;
        sub_0050DD60_ProjectToScreen(nPosX + nWorldX + 0x10000, nPosY + nWorldY - 0x10000, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid_00880458[2].x = (float)nScreenX;
        gaGlideTileGrid_00880458[2].y = (float)nScreenY;

        if (GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[0], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[12], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[14], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[2], tRect))
        {
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);

            const float fOffset = (float)nOffset;
            int nRowX = nX0;
            int nRowY = nY0;
            for (int nGridRow = 0; nGridRow < 5; ++nGridRow)
            {
                for (int nGridCol = 0; nGridCol < 3; ++nGridCol)
                {
                    D2GlideSpriteVertexStrc* pVertex = &gaGlideTileGrid_00880458[nGridRow * 3 + nGridCol];
                    sub_0050DD60_ProjectToScreen(nRowX + nGridCol * 0x8000, nRowY - nGridCol * 0x8000, 0, &nScreenX, &nScreenY);
                    pVertex->y = (float)nScreenY;
                    pVertex->x = (float)nScreenX + fOffset;
                    sub_0050DBE0_GlideSetVertexShade(pVertex, eDrawMode);
                }

                nRowX += 0x8000;
                nRowY += 0x8000;
            }

            gpfGlideDrawVertexArray_0087EB18(4, 10, gapGlideTileStripA_0072F350);
            gpfGlideDrawVertexArray_0087EB18(4, 10, gapGlideTileStripB_0072F378);
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
            gaGlideTileQuad_00880600[0].x = fX0;
            gaGlideTileQuad_00880600[0].y = fY1;
            gaGlideTileQuad_00880600[1].x = fX0;
            gaGlideTileQuad_00880600[1].y = fY0;
            gaGlideTileQuad_00880600[2].x = fX1;
            gaGlideTileQuad_00880600[2].y = fY0;
            gaGlideTileQuad_00880600[3].x = fX1;
            gaGlideTileQuad_00880600[3].y = fY1;
            sub_0050DC30_GlideSetVertexColor(&gaGlideTileQuad_00880600[0], dwColor0);
            sub_0050DC30_GlideSetVertexColor(&gaGlideTileQuad_00880600[1], dwColor0);
            sub_0050DC30_GlideSetVertexColor(&gaGlideTileQuad_00880600[2], dwColor1);
            sub_0050DC30_GlideSetVertexColor(&gaGlideTileQuad_00880600[3], dwColor1);
            gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, gaGlideTileQuad_00880600, sizeof(D2GlideSpriteVertexStrc));
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

        const int* pCorner0 = gaGlideWallCorner_0072F3A0[nType][nCol];
        const int* pCorner1 = gaGlideWallCorner_0072F3A0[nType][nCol + 1];
        const int nX0 = pCorner0[0] + nPosX;
        const int nZ0 = pCorner0[2] - nHeight;
        const int nY0 = pCorner0[1] + nPosY;
        const int nX1 = pCorner1[0] + nPosX;
        const int nZ1 = pCorner1[2] - nHeight;
        const int nY1 = pCorner1[1] + nPosY;
        int nScreenX;
        int nScreenY;

        sub_0050DD60_ProjectToScreen(nX0, nY0, nZ0, &nScreenX, &nScreenY);
        gaGlideTileGrid_00880458[0].x = (float)nScreenX;
        gaGlideTileGrid_00880458[0].y = (float)nScreenY;
        sub_0050DD60_ProjectToScreen(nX0, nY0, nZ0 - 0x20, &nScreenX, &nScreenY);
        gaGlideTileGrid_00880458[12].x = (float)nScreenX;
        gaGlideTileGrid_00880458[12].y = (float)nScreenY;
        sub_0050DD60_ProjectToScreen(nX1, nY1, nZ1 - 0x20, &nScreenX, &nScreenY);
        gaGlideTileGrid_00880458[14].x = (float)nScreenX;
        gaGlideTileGrid_00880458[14].y = (float)nScreenY;
        sub_0050DD60_ProjectToScreen(nX1, nY1, nZ1, &nScreenX, &nScreenY);
        gaGlideTileGrid_00880458[2].x = (float)nScreenX;
        gaGlideTileGrid_00880458[2].y = (float)nScreenY;

        if (GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[0], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[12], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[14], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[2], tRect))
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
                    sub_0050DD60_ProjectToScreen(nX0, nY0, nZ0 - nDepth, &nScreenX, &nScreenY);
                    gaGlideTileGrid_00880458[nGridRow * 3].x = (float)nScreenX;
                    gaGlideTileGrid_00880458[nGridRow * 3].y = (float)nScreenY;
                    sub_0050DD60_ProjectToScreen(nX1, nY1, nZ1 - nDepth, &nScreenX, &nScreenY);
                    gaGlideTileGrid_00880458[nGridRow * 3 + 2].x = (float)nScreenX;
                    gaGlideTileGrid_00880458[nGridRow * 3 + 2].y = (float)nScreenY;
                }

                sub_0050DD60_ProjectToScreen(nMidX, nMidY, nMidZ - nDepth, &nScreenX, &nScreenY);
                gaGlideTileGrid_00880458[nGridRow * 3 + 1].x = (float)nScreenX;
                gaGlideTileGrid_00880458[nGridRow * 3 + 1].y = (float)nScreenY;
                for (int nGridCol = 0; nGridCol < 3; ++nGridCol)
                {
                    D2GlideSpriteVertexStrc* pVertex = &gaGlideTileGrid_00880458[nGridRow * 3 + nGridCol];
                    pVertex->x = pVertex->x + fOffset;
                    sub_0050DC30_GlideSetVertexColor(pVertex, aColors[nGridCol]);
                }
            }

            gpfGlideDrawVertexArray_0087EB18(4, 10, gapGlideTileStripA_0072F350);
            gpfGlideDrawVertexArray_0087EB18(4, 10, gapGlideTileStripB_0072F378);
            nResult = 1;
        }
    }

    return nResult;
}

// 0x0050D410
static int __stdcall sub_0050D410_GlideTileDrawAlpha(int nPosX, int nPosY, D2GfxLightStrc* pLight, unsigned char nAlpha, D2TileLibraryEntryStrc* pTile, int nScreenPanels)
{
    int nResult = 0;
    if (sub_005FDEA0(pTile, 1, 0))
    {
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

        sub_005095D0_GlideSetDepth(1);
        if (sub_0050DD30_GlideIsPerspective())
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

// 0x0050D490
int __fastcall sub_0050D490_GlideTileDrawTrans(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha)
{
    return sub_0050D410_GlideTileDrawAlpha(nPosX, nPosY, pLight, nAlpha, pTile, nScreenPanels);
}

// 0x0050D4C0
int __fastcall sub_0050D4C0_GlideTileDrawLit(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels)
{
    int nResult = 0;
    if (sub_005FDEA0(pTile, 1, 0))
    {
        sub_005094B0_GlideSetState(1);
        sub_00509500_GlideSetCombine(1);
        sub_005095D0_GlideSetDepth(1);
        if (sub_0050DD30_GlideIsPerspective())
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

static __forceinline float ScaleTexCoord(double dA, double dB, double dScale)
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
            gaGlideStrips_00880A68[12 * nRow + 2 * nCol] = &gaGlideVertices_00880678[6 * nRow + nCol];
            D2GlideVtxStrc** ppBottom = &gaGlideStrips_00880A68[12 * nRow + 2 * nCol + 1];
            *ppBottom = &gaGlideVertices_00880678[6 * nRow + nCol + 6];
        }
    }
}
