#include "D2Structs.h"
#include "D2Path.h"
struct T00508FE0;
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
typedef void (__stdcall* GlideDrawVertexArrayFn)(int nMode, int nCount, void** ppVertices);
extern GlideDrawVertexArrayFn gpfGlideDrawVertexArray_0087EB18;                                             // 0x0087EB18

void __fastcall sub_005094B0_GlideSetState(int nState);                                                      // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode);                                                     // 0x00509500
void __fastcall sub_005095D0_GlideSetDepth(int nMode);                                                       // 0x005095D0
void __fastcall sub_0050DBE0_GlideSetVertexShade(D2GlideSpriteVertexStrc* pVertex, unsigned char nShade);   // 0x0050DBE0
void __fastcall sub_0050DC30_GlideSetVertexColor(T00508FE0* pVertex, unsigned int dwColor); // 0x0050DC30
int __cdecl sub_0050DD30_GlideIsPerspective();                                                               // 0x0050DD30
void __fastcall sub_0050DD60_ProjectToScreen(int nX, int nY, int nZ, int* pScreenX, int* pScreenY);          // 0x0050DD60
void __fastcall sub_0050FBD0_GlideBindTileTexture(D2GlideTileStrc* pTile);                                   // 0x0050FBD0
int __stdcall sub_005FDEA0(D2TileLibraryEntryStrc* pTile, int a2, int a3);                                   // 0x005FDEA0

static __declspec(noinline) void __stdcall sub_0050C690_GlideGetDrawRect(int bPerspective, tagRECT* pRect, int nScreenPanels, int* pOffset);
static void __stdcall sub_0050C690_GlideGetDrawRect(int bPerspective, tagRECT* pRect, int nScreenPanels, int* pOffset); // 0x0050C690

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

// 0x0050CA00
int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels)
{
    int nResult = 0;
    int nOffset = 0;

    int nOne = 1;
    tagRECT tRect;
    sub_0050C690_GlideGetDrawRect(1, &tRect, nScreenPanels, &nOffset);

    nPosX <<= 13;
    nPosY <<= 13;
    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        const int nCol = pTile->pBlocks[i].nPosX >> 5;
        const int nRow = (pTile->pBlocks[i].nPosY + 0x60) >> 5;
        const int nWorldX = ((nCol + nRow * 2) << 16) - 0x38000;
        const int nWorldY = (((nRow << nOne) - nCol) << 16) + 0x18000;
        const int nY0 = nPosY + nWorldY;
        const int nX0 = nPosX + nWorldX;
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

        if (GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[0], tRect))
        {
DrawVisibleTile:
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);

            const float fOffset = (float)nOffset;
            D2GlideSpriteVertexStrc* pVertex = gaGlideTileGrid_00880458;
            int nStartY = nY0;
            int nStartX = nX0;
            do
            {
                int nX = nStartX;

                int nY = *(volatile int*)&nStartY;
                for (int nGridCol = 0; nGridCol < 3; ++nGridCol)
                {
                    sub_0050DD60_ProjectToScreen(nX, nY, 0, &nScreenX, &nScreenY);
                    pVertex->y = (float)nScreenY;
                    pVertex->x = (float)nScreenX + fOffset;
                    sub_0050DBE0_GlideSetVertexShade(pVertex, eDrawMode);
                    nX += 0x8000;
                    ++pVertex;
                    nY -= 0x8000;
                }

                nStartX += 0x8000;
                nStartY += 0x8000;
            } while ((int)pVertex < (int)(gaGlideTileGrid_00880458 + 15));

            gpfGlideDrawVertexArray_0087EB18(4, 10, gapGlideTileStripA_0072F350);
            gpfGlideDrawVertexArray_0087EB18(4, 10, gapGlideTileStripB_0072F378);
            nResult = 1;
        }
        else if (GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[12], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[14], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid_00880458[2], tRect))
        {
            goto DrawVisibleTile;
        }
    }

    return nResult;
}
