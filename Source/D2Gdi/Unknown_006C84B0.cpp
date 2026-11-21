#include "D2Gdi.h"
#include "D2GfxTypes.h"
#include "D2CelContext.h"

struct D2CelStrc;

int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* pCel);                                                               // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel);                                                               // 0x00601950
int __fastcall sub_006C8250_GetSetting(unsigned int nSelector, int* pValue); // 0x006C8250
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern D2PaletteTableStrc* gpDDrawCaps_007C9150;                                                               // 0x007C9150

static int __stdcall sub_00511E10_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
{
    int nWidth = sub_006018C0(pCel);
    int nHeight = sub_006018F0(pCel);
    if (bCenter)
    {
        nX -= nHeight;
        nWidth += nHeight;
        nHeight >>= 1;
    }

    nX += sub_00601920(pCel);
    if (nX < gnScreenWidth_007C9138 && nWidth + nX >= 0)
    {
        nY += sub_00601950(pCel);
        if (nY >= 0 && nY - nHeight < gnScreenHeight_007C913C)
            return 0;
    }

    return 1;
}

// 0x006C84B0
int __fastcall sub_006C84B0_Draw(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, void* pPalette)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return 0;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return 0;

    const int nGamma = (unsigned char)dwGamma;
    unsigned char* pGammaTable = 0;
    const int nCaps = sub_006C8250_GetSetting(nDrawMode, (int*)&dwGamma);
    if (nGamma != 0xFF)
        pGammaTable = gpDDrawCaps_007C9150->pShadowLightGammaPalettes[nGamma >> 3];
    if (nDrawMode == 7)
        pGammaTable = gpDDrawCaps_007C9150->pRemap;

    CelDraw((D2CmpCelContextStrc*)pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C,
        gpScreenBuffer_007C9154, gnScreenHeight_007C913C, gnScreenWidth_007C9138, (int)pGammaTable, nCaps, (int)pPalette);
    return 1;
}
