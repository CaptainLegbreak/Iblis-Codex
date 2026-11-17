struct D2GfxLightStrc
{
    unsigned int aColor[8];
};

struct D2GlideTileStrc
{
    short nPosX;
    short nPosY;
    char unk0x04[0x10];
};

struct D2TileLibraryEntryStrc
{
    int nLightDirection;
    char unk0x04[0x4C];
    int nBlocks;
    D2GlideTileStrc* pBlocks;
};

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D2GlideSpriteVertexStrc
{
    float x;
    float y;
    unsigned int dwColor;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define GLIDE_VERTEX_IN_RECT(v, r) ((v).x >= (r).left && (v).x < (r).right && (v).y >= (r).top && (v).y < (r).bottom)

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern int gaGlideWallCorner_0072F3A0[10][6][3];                                                          // 0x0072F3A0
extern void* gapGlideTileStripA_0072F350[10];                                                            // 0x0072F350
extern void* gapGlideTileStripB_0072F378[10];                                                            // 0x0072F378
extern D2GlideSpriteVertexStrc gaGlideTileGrid_00880458[15];                                                 // 0x00880458
extern D2GlideSpriteVertexStrc gaGlideTileQuad_00880600[4];                                                  // 0x00880600
extern void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
extern void (__stdcall* gpfGlideDrawVertexArray_0087EB18)(int nMode, int nCount, void** ppVertices);       // 0x0087EB18
extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor);                              // 0x0087EFA0

void __fastcall sub_005094B0_GlideSetState(int nState);                                                      // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode);                                                     // 0x00509500
void __fastcall sub_005095D0_GlideSetDepth(int nMode);                                                       // 0x005095D0
void __fastcall sub_0050DBE0_GlideSetVertexShade(D2GlideSpriteVertexStrc* pVertex, unsigned char nShade);   // 0x0050DBE0
void __fastcall sub_0050DC30_GlideSetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor);    // 0x0050DC30
int __cdecl sub_0050DD30_GlideIsPerspective();                                                               // 0x0050DD30
void __fastcall sub_0050DD60_ProjectToScreen(int nX, int nY, int nZ, int* pScreenX, int* pScreenY);          // 0x0050DD60
void __fastcall sub_0050FBD0_GlideBindTileTexture(D2GlideTileStrc* pTile);                                   // 0x0050FBD0
int __stdcall sub_005FDEA0(D2TileLibraryEntryStrc* pTile, int a2, int a3);                                   // 0x005FDEA0

static void __stdcall sub_0050C690_GlideGetDrawRect(int bPerspective, tagRECT* pRect, int* pOffset, int nScreenPanels)
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

int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels)
{
    int nResult = 0;
    int nOffset = 0;
    tagRECT tRect;
    sub_0050C690_GlideGetDrawRect(1, &tRect, &nOffset, nScreenPanels);

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
    sub_0050C690_GlideGetDrawRect(0, &tRect, 0, nScreenPanels);

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
    sub_0050C690_GlideGetDrawRect(1, &tRect, &nOffset, nScreenPanels);

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

#include "gen/data/Source/D2Glide/Unknown_0050D410.inc"
