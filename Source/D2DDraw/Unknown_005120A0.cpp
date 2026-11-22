#include "D2DDraw.h"
#include "D2CelContext.h"

struct D2CelStrc;

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);
int __stdcall CelGetWidth(D2CelStrc* pCel);                                                                 // 0x006018C0
int __stdcall CelGetHeight(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall CelGetOffsetX(D2CelStrc* pCel);                                                               // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* pCel);                                                               // 0x00601950
int __fastcall sub_00511D70_GetCapsValue(int nIndex, int* pType);                                           // 0x00511D70
extern D2PaletteTableStrc* gpDDrawCaps_007C9150;                                                               // 0x007C9150
int gnDDrawOriginX_0088129C;                                                                                // 0x0088129C
extern int gnDDrawModeWidth_008812A0;                                                                       // 0x008812A0

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
    if (nX < gnScreenWidth_007C9138 && nWidth + nX >= 0)
    {
        nY += CelGetOffsetY(pCel);
        if (nY >= 0 && nY - nHeight < gnScreenHeight_007C913C)
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
        const int nCaps = sub_00511D70_GetCapsValue(nDrawMode, &nType);
        const int nGamma = (unsigned char)dwGamma;
        if (nGamma != 0xFF)
            pGammaTable = gpDDrawCaps_007C9150->pShadowLightGammaPalettes[nGamma >> 3];
        if (nDrawMode == 7)
            pGammaTable = gpDDrawCaps_007C9150->pRemap;
        if (nPalette)
            pPaletteTable = gpDDrawCaps_007C9150->pStandardShiftPalettes[nPalette];

        CelDraw((D2CmpCelContextStrc*)pContext, nX, nY, gnDDrawOriginX_0088129C, gnDDrawModeWidth_008812A0,
            gpScreenBuffer_007C9154, gnScreenHeight_007C913C, gnScreenWidth_007C9138, (int)pGammaTable, nCaps, (int)pPaletteTable);
    }
    return 1;
}
