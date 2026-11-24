#include "D2DDraw.h"
#include "D2CelContext.h"

struct D2CelStrc;

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);
int __stdcall CelGetWidth(D2CelStrc* pCel);                                                                 // 0x006018C0
int __stdcall CelGetHeight(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall CelGetOffsetX(D2CelStrc* pCel);                                                               // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* pCel);                                                               // 0x00601950
int __fastcall DDCORE_GetDrawModePalette(int nIndex, int* pType);                                           // 0x00511D70
extern D2PaletteTableStrc* gpGfxPaletteView;                                                               // 0x007C9150
int gnDDrawClipLeft;                                                                                // 0x0088129C
extern int gnDDrawClipRight;                                                                       // 0x008812A0

static int __stdcall sub_00511E10_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
{
    int nWidth = CelGetWidth(pCel);
    int nHeight = CelGetHeight(pCel);
    if (bCenter)
    {
        nX -= nHeight;
        nWidth += nHeight;
        nHeight >>= 1;
    }

    nX += CelGetOffsetX(pCel);
// build: symbol ?gnRenderWidth@* 0x007C9138
    if (nX < gnRenderWidth && nWidth + nX >= 0)
    {
        nY += CelGetOffsetY(pCel);
// build: symbol ?gnRenderHeight@* 0x007C913C
        if (nY >= 0 && nY - nHeight < gnRenderHeight)
            return 0;
    }

    return 1;
}

// 0x005120A0
int __fastcall sub_005120A0_DrawImagePalette(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, int nPalette)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return 0;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return 0;

    {
        unsigned char* pGammaTable = 0;
        unsigned char* pPaletteTable = 0;
        int nType;
        const int nCaps = DDCORE_GetDrawModePalette(nDrawMode, &nType);
        const int nGamma = (unsigned char)dwGamma;
        if (nGamma != 0xFF)
            pGammaTable = gpGfxPaletteView->pShadowLightGammaPalettes[nGamma >> 3];
        if (nDrawMode == 7)
            pGammaTable = gpGfxPaletteView->pRemap;
        if (nPalette)
            pPaletteTable = gpGfxPaletteView->pStandardShiftPalettes[nPalette];

        CelDraw((D2CmpCelContextStrc*)pContext, nX, nY, gnDDrawClipLeft, gnDDrawClipRight,
            gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, (int)pGammaTable, nCaps, (int)pPaletteTable);
    }
    return 1;
}
