#include "D2Gdi.h"
#include "D2CelContext.h"
#include "D2GfxTypes.h"

struct D2CelStrc;

int __stdcall sub_006018C0(D2CelStrc* pCel); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel); // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* pCel); // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel); // 0x00601950
void __stdcall CelDrawEx(D2CelContextStrc* pContext, int nX, int nY, int nOriginX, int nModeWidth, unsigned char* pBuffer, int nHeight, int nWidth, int nArg9, unsigned char* pCaps, int nSkipTop, int nDrawHeight, int nArg13); // 0x00601650
extern int gnScreenHeight_007C913C; // 0x007C913C

void __stdcall CelDrawShadow(D2CelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, unsigned char* pShadowTable, int nArg10); // 0x00601730
int __cdecl sub_006C8A50_GetBlendedShadows(); // 0x006C8A50
extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150

int __fastcall sub_006C8250_GetSetting(unsigned int nSelector, int* pValue)
{
    *pValue = gaSelectorValues_0074C5A0[nSelector];
    switch (nSelector)
    {
    case 0:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[2];
    case 1:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[1];
    case 2:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[0];
    case 3:
        return (int)gpGfxPaletteView_007C9150->pScreenPalette;
    case 4:
        return (int)gpGfxPaletteView_007C9150->pLuminancePalette;
    case 6:
        return (int)gpGfxPaletteView_007C9150->pDarkBlendPalette;
    }
    return 0;
}

static int __stdcall sub_006C86A0_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
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
        int nTop = sub_00601950(pCel) + nY;
        if (nTop >= 0 && nTop - nHeight < gnScreenHeight_007C913C)
            return 0;
    }

    return 1;
}

// 0x006C86A0
void __fastcall sub_006C86A0_DrawImageRows(D2CelContextStrc* pContext, int nX, int nY, int nSkipTop, int nDrawHeight, int nDrawMode)
{
    if (!sub_006001F0(pContext, 0, 1))
        return;

    if (sub_006C86A0_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return;

    CelDrawEx(pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C, gpScreenBuffer_007C9154,
        gnScreenHeight_007C913C, gnScreenWidth_007C9138, 0, (unsigned char*)sub_006C8250_GetSetting(nDrawMode, &nDrawHeight),
        nSkipTop, nDrawHeight, 0);
}

static int __stdcall sub_006C85A0_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
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

// 0x006C87E0
void __fastcall sub_006C87E0_DrawShadow(void* pData, int nX, int nY)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return;

    if (sub_006C85A0_IsCelOffScreen(pContext->pCel, nX, nY, 1))
        return;

    unsigned char* pShadowTable = 0;
    if (sub_006C8A50_GetBlendedShadows())
        pShadowTable = gpGfxPaletteView_007C9150->pTransPalettes[0];

    CelDrawShadow(pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C,
        gpScreenBuffer_007C9154, gnScreenHeight_007C913C, gnScreenWidth_007C9138, pShadowTable, 0);
}
