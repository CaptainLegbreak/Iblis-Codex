#include "D2Glide.h"

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
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define GLIDE_VERTEX_IN_RECT(v, r) ((v).x >= (r).left && (v).x < (r).right && (v).y >= (r).top && (v).y < (r).bottom)

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern D2GlideSpriteVertexStrc gaGlideTileGrid_00880458[15];                                                 // 0x00880458
extern D2GlideSpriteVertexStrc gaGlideTileQuad_00880600[4];                                                  // 0x00880600
typedef void (__stdcall* DrawContiguous)(int,int,void*,int);
extern DrawContiguous gpfGlideDrawVertexArrayContiguous_0087EAC4; // 0x0087EAC4
typedef void (__stdcall* DrawArray)(int,int,void**);
extern DrawArray gpfGlideDrawVertexArray_0087EB18; // 0x0087EB18
typedef void (__stdcall* ConstantColor)(unsigned int);
extern ConstantColor gpfGlideConstantColor_0087EFA0; // 0x0087EFA0

void __fastcall sub_005094B0_GlideSetState(int nState);                                                      // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode);                                                     // 0x00509500
void __fastcall sub_005095D0_GlideSetDepth(int nMode);                                                       // 0x005095D0
void __fastcall sub_0050DC30_GlideSetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor);    // 0x0050DC30
int __cdecl sub_0050DD30_GlideIsPerspective();                                                               // 0x0050DD30
void __fastcall sub_0050DD60_ProjectToScreen(int nX, int nY, int nZ, int* pScreenX, int* pScreenY);          // 0x0050DD60

// 0x0050C690
static void __stdcall sub_0050C690_GlideGetDrawRect(int bPerspective, int nScreenPanels, tagRECT* pRect, int* pOffset)
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

        const int nX0 = gaGlideWallCorner_0072F3A0[nType][nCol][0] + nPosX;
        const int nY0 = gaGlideWallCorner_0072F3A0[nType][nCol][1] + nPosY;
        const int nZ0 = gaGlideWallCorner_0072F3A0[nType][nCol][2] - nHeight;
        const int nX1 = gaGlideWallCorner_0072F3A0[nType][nCol + 1][0] + nPosX;
        const int nY1 = gaGlideWallCorner_0072F3A0[nType][nCol + 1][1] + nPosY;
        const int nZ1 = gaGlideWallCorner_0072F3A0[nType][nCol + 1][2] - nHeight;
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
static int __stdcall sub_0050CF70_GlideTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels); // 0x0050CF70
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
int __fastcall sub_0050D4C0_GlideTileDrawLit(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels); // 0x0050D4C0
