struct T00508FE0
{
    float fX;
    float fY;
    unsigned int dwColor;
    char unk0x0C[0x10];
};

struct D2TileVertexStrc
{
    unsigned char aColor[4];
    int nX;
    int nY;
};

struct D2GfxSettingsStrc
{
    int unk0x00;
    int unk0x04;
    int bFanOnly;
};

typedef void (__stdcall* GlideConstantColorFn)(unsigned int dwColor);
typedef void (__stdcall* GlideDrawVertexArrayFn)(int nMode, int nCount, void** ppVertices);

int __fastcall sub_0050FAD0_GlideBindFloorTexture(void* pTile);                                             // 0x0050FAD0
void __fastcall sub_005094B0_GlideSetState(int nState);                                                     // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode);                                                    // 0x00509500
void __fastcall sub_005095D0_GlideSetDepth(int nMode);                                                      // 0x005095D0

extern GlideConstantColorFn gpfGlideConstantColor_0087EFA0;                                                 // 0x0087EFA0
extern GlideDrawVertexArrayFn gpfGlideDrawVertexArray_0087EB18;                                             // 0x0087EB18
extern unsigned char* gpBlendTable_00880B5C;                                                                // 0x00880B5C
extern D2GfxSettingsStrc* gpGfxSettings_007C9148;                                                           // 0x007C9148
extern T00508FE0 gaGlideTileVertices_00880678[36];                                                  // 0x00880678
extern void* gapGlideTileFan_0072F670[4];                                                                   // 0x0072F670
extern void* gapGlideTileStrips_00880A68[5][12];                                                            // 0x00880A68

static __forceinline void GLIDE_SetTileVertex(const D2TileVertexStrc* pSource, T00508FE0* pVertex)
{
    const unsigned char* pRow = &gpBlendTable_00880B5C[pSource->aColor[0] << 8];
    pVertex->dwColor = (((-1 << 8 | pRow[pSource->aColor[1]]) << 8 | pRow[pSource->aColor[2]]) << 8) | pRow[pSource->aColor[3]];
    pVertex->fX = (float)pSource->nX;
    pVertex->fY = (float)pSource->nY;
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

    if (gpGfxSettings_007C9148->bFanOnly)
    {
        GLIDE_SetTileVertex(&pVertices[0], &gaGlideTileVertices_00880678[0]);
        GLIDE_SetTileVertex(&pVertices[5], &gaGlideTileVertices_00880678[5]);
        GLIDE_SetTileVertex(&pVertices[35], &gaGlideTileVertices_00880678[35]);
        GLIDE_SetTileVertex(&pVertices[30], &gaGlideTileVertices_00880678[30]);
        gpfGlideDrawVertexArray_0087EB18(5, 4, gapGlideTileFan_0072F670);
        return;
    }

    const D2TileVertexStrc* pSrc = pVertices;
    T00508FE0* pDst = gaGlideTileVertices_00880678;
    for (unsigned int i = 0; i < 36; i++, pSrc++, pDst++)
        GLIDE_SetTileVertex(pSrc, pDst);

    for (int i = 0; i < 5; i++)
        gpfGlideDrawVertexArray_0087EB18(4, 12, gapGlideTileStrips_00880A68[i]);
}

#include "gen/data/Source/D2Win/0050D6A0_sub_0050D6A0_GlideDrawFloorTile.inc"
