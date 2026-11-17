struct D2CelContextStrc;

struct D2GlideTexInfoStrc
{
    D2CelContextStrc* pContext;
    int nWidth;
    int nHeight;
    int nOffsetX;
    int nOffsetY;
    int f_14;
    int f_18;
    int nTexSize;
    float fS0;
    float fS1;
    float fT0;
    float fT1;
    int nLod;
    int f_34;
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

struct D2GlideTexDimsStrc
{
    int nWidth;
    int nHeight;
};

struct D2PaletteRgbStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

struct D2GfxPaletteViewStrc
{
    char unk0x00[0x114];
    D2PaletteRgbStrc* pRgbTable;
    unsigned char* f_118;
};

void __fastcall sub_005094B0_GlideSetState(int nState); // 0x005094B0
void __fastcall sub_005095D0_GlideSetDepth(int nMode); // 0x005095D0
void __fastcall sub_0050DC30_GlideSetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor); // 0x0050DC30
int __cdecl sub_0050DD30_GlideIsPerspective(); // 0x0050DD30
typedef void (__stdcall* PFNGLIDEDRAWVERTEXARRAY)(int nMode, int nCount, void* pVertices, int nStride);
typedef void (__stdcall* PFNGLIDEALPHAFUNCTION)(int nFunction);
extern PFNGLIDEDRAWVERTEXARRAY gpfGlideDrawVertexArrayContiguous_0087EAC4; // 0x0087EAC4
extern PFNGLIDEALPHAFUNCTION gpfGlideAlphaFunction_0087EAB4; // 0x0087EAB4
extern D2GfxPaletteViewStrc* gpGfxPaletteView_007C9150; // 0x007C9150
extern D2GlideSpriteVertexStrc gaGlideSpriteVertices_0087EFF8[4]; // 0x0087EFF8
extern int gnGlideSpriteScale_00880B64; // 0x00880B64
extern D2GlideTexDimsStrc gaGlideAspectTexDims_0072F278[7]; // 0x0072F278

static __declspec(noinline) void __stdcall sub_0050A9A0_GlideDrawSpriteQuad(int nX, int nY, unsigned int dwColor, int bTinted, D2GlideTexInfoStrc* pInfo, int nPaletteIndex);

// 0x0050A9A0
static void __stdcall sub_0050A9A0_GlideDrawSpriteQuad(int nX, int nY, unsigned int dwColor, int bTinted, D2GlideTexInfoStrc* pInfo, int nPaletteIndex)
{
    sub_005094B0_GlideSetState(1);
    sub_005095D0_GlideSetDepth(1);

    if (!nPaletteIndex && !bTinted)
    {
        sub_0050DC30_GlideSetVertexColor(gaGlideSpriteVertices_0087EFF8, dwColor);
    }
    else
    {
        gaGlideSpriteVertices_0087EFF8[0].dwColor = ((gpGfxPaletteView_007C9150->pRgbTable[nPaletteIndex].nRed | 0xFFFFFF00) << 8
            | gpGfxPaletteView_007C9150->pRgbTable[nPaletteIndex].nGreen) << 8 | gpGfxPaletteView_007C9150->pRgbTable[nPaletteIndex].nBlue;
    }
    gaGlideSpriteVertices_0087EFF8[3].dwColor = gaGlideSpriteVertices_0087EFF8[0].dwColor;
    gaGlideSpriteVertices_0087EFF8[2].dwColor = gaGlideSpriteVertices_0087EFF8[0].dwColor;
    gaGlideSpriteVertices_0087EFF8[1].dwColor = gaGlideSpriteVertices_0087EFF8[0].dwColor;

    const int nDimIndex = pInfo->f_34 + 3;
    int nTexW = gaGlideAspectTexDims_0072F278[nDimIndex].nWidth;
    int nTexH = gaGlideAspectTexDims_0072F278[nDimIndex].nHeight;
    const float fS0 = pInfo->fS0 * nTexW;
    const float fS1 = pInfo->fS1 * nTexW;
    const float fT0 = pInfo->fT0 * nTexH;
    const float fT1 = pInfo->fT1 * nTexH;

    const int bPerspective = sub_0050DD30_GlideIsPerspective();
    int nWidth;
    int nHeight;
    if (!bPerspective)
    {
        nWidth = pInfo->nWidth;
        nHeight = pInfo->nHeight;
    }
    else
    {
        nWidth = pInfo->f_14;
        nHeight = pInfo->f_18;
    }

    int nLeft = pInfo->nOffsetX;
    int nTop = pInfo->nOffsetY - nHeight;
    if (bPerspective && gnGlideSpriteScale_00880B64 != 0x100)
    {
        nLeft = nLeft * gnGlideSpriteScale_00880B64 / 0x100;
        nTop = nTop * gnGlideSpriteScale_00880B64 / 0x100;
        nWidth = nWidth * gnGlideSpriteScale_00880B64 / 0x100;
        nHeight = nHeight * gnGlideSpriteScale_00880B64 / 0x100;
    }

    const int nX0 = nX + nLeft;
    const float fX0 = (float)nX0;
    const float fX1 = (float)(nX0 + nWidth);
    const int nY0 = nY + nTop;
    const float fY0 = (float)nY0;
    const float fY1 = (float)(nY0 + nHeight);

    gaGlideSpriteVertices_0087EFF8[0].x = fX0;
    gaGlideSpriteVertices_0087EFF8[0].y = fY0;
    gaGlideSpriteVertices_0087EFF8[0].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[0].sow = fS0;
    gaGlideSpriteVertices_0087EFF8[0].tow = fT0;
    gaGlideSpriteVertices_0087EFF8[1].x = fX0;
    gaGlideSpriteVertices_0087EFF8[1].y = fY1;
    gaGlideSpriteVertices_0087EFF8[1].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[1].sow = fS0;
    gaGlideSpriteVertices_0087EFF8[1].tow = fT1;
    gaGlideSpriteVertices_0087EFF8[2].x = fX1;
    gaGlideSpriteVertices_0087EFF8[2].y = fY1;
    gaGlideSpriteVertices_0087EFF8[2].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[2].sow = fS1;
    gaGlideSpriteVertices_0087EFF8[2].tow = fT1;
    gaGlideSpriteVertices_0087EFF8[3].x = fX1;
    gaGlideSpriteVertices_0087EFF8[3].y = fY0;
    gaGlideSpriteVertices_0087EFF8[3].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[3].sow = fS1;
    gaGlideSpriteVertices_0087EFF8[3].tow = fT0;
    gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, gaGlideSpriteVertices_0087EFF8, sizeof(D2GlideSpriteVertexStrc));
    gpfGlideAlphaFunction_0087EAB4(2);
}

void __fastcall sub_leg345d_Emit_0050A9A0(D2GlideTexInfoStrc* pInfo, int nX, int nY, unsigned int dwColor, int nMode, int nPaletteIndex)
{
    D2GlideTexInfoStrc tInfo = *pInfo;
    if (nMode == 1)
        sub_0050A9A0_GlideDrawSpriteQuad(nX, nY, dwColor, 0, &tInfo, nPaletteIndex);
    else if (nMode == 2)
        sub_0050A9A0_GlideDrawSpriteQuad(nX - 1, nY + 1, -1, 1, &tInfo, 0);
    else
        sub_0050A9A0_GlideDrawSpriteQuad(nX, nY, dwColor, 0, &tInfo, 0);
}

#include "gen/data/Source/D2Win/0050A9A0_sub_0050A9A0_GlideDrawSpriteQuad.inc"
