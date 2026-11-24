#include "D2Glide.h"

struct D2TileLibraryEntryStrc;

void __fastcall GLCORE_SetColorCombineMode(int nState);                                                      // 0x005094B0
void __fastcall GLCORE_SetAlphaBlendMode(int nMode);                                                     // 0x00509500
void __fastcall GLCORE_SetTextureFilterMode(int nMode);                                                       // 0x005095D0
int __cdecl sub_0050BF40_GlideGetBlendedShadows();                                                                    // 0x0050BF40
int __fastcall sub_0050C890_GlideTileDrawShaded(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, unsigned char nShade, int nScreenPanels); // 0x0050C890
int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels); // 0x0050CA00
int __cdecl GLVERTEX_IsPerspective();                                                               // 0x0050DD30
extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor);                              // 0x0087EFA0

// 0x0050CD40
int __fastcall sub_0050CD40_GlideShadowTileDraw(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels)
{
    int nResult = 0;
    if (D2CMPTileValidate(pTile, 1, 0))
    {
        GLCORE_SetColorCombineMode(1);
        if (sub_0050BF40_GlideGetBlendedShadows())
        {
            GLCORE_SetAlphaBlendMode(4);
            gpfnGrConstantColorValue(0xC0);
        }
        else
        {
            GLCORE_SetAlphaBlendMode(1);
        }

        GLCORE_SetTextureFilterMode(1);
        if (GLVERTEX_IsPerspective())
        {
            nResult = sub_0050CA00_GlideShadowTileDrawPerspective(pTile, nPosX, nPosY, eDrawMode, nScreenPanels);
        }
        else
        {
            nResult = sub_0050C890_GlideTileDrawShaded(pTile, nPosX, nPosY, eDrawMode, nScreenPanels);
        }
    }

    return nResult;
}

