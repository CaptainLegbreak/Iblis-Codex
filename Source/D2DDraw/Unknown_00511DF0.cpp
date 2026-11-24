#include "D2DDraw.h"
#include "D2CelContext.h"

struct D2CelStrc;
struct D2DDrawClipRectStrc;
struct D2DDrawCelClipStrc;

extern int gnDDrawClipLeft; // 0x0088129C
int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0
int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0
int __stdcall CelGetOffsetX(D2CelStrc* pCel); // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* pCel); // 0x00601950
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

struct D2DDrawClipRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2DDrawCelClipStrc
{
    int nLeft;
    int nRight;
    int f_8;
    int nRows;
};

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);
void __stdcall CelDrawEx(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nClipTop, int nClipRows, int nArg13); // 0x00601650
int __fastcall DDCORE_GetDrawModePalette(int nIndex, int* pType); // 0x00511D70

extern D2PaletteTableStrc* gpGfxPaletteView; // 0x007C9150
extern int gnDDrawClipRight; // 0x008812A0
void __stdcall CmpDoLensEffect(unsigned char* pBuffer, int nPitch); // 0x00608C00

int gnDDrawClipRight; // 0x008812A0

// 0x00511DF0
void __fastcall sub_00511DF0_DDrawSetMode(int nResolutionMode)
{
    if (nResolutionMode == 0)
    {
        gnDDrawClipLeft = 0;
        gnDDrawClipRight = 640;
    }
    else
    {
        gnDDrawClipLeft = 0;
        gnDDrawClipRight = 800;
    }
}

// 0x00511E10
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


// 0x00511E80
static int __fastcall sub_00511E80_ClipCel(D2CelStrc* pCel, int nY, int nX, D2DDrawCelClipStrc* pOut, const D2DDrawClipRectStrc* pClip)
{
    int nWidth = CelGetWidth(pCel);
    int nHeight = CelGetHeight(pCel);

    const int nLeft = D2_MAX(pClip->nLeft, 0);
    const int nRight = D2_MIN(pClip->nRight, gnRenderWidth);
    if (nLeft <= nRight)
    {
        nX += CelGetOffsetX(pCel);
        if (nX < nRight && nWidth + nX >= nLeft)
        {
            const int nTop = D2_MAX(pClip->nTop, 0);
            const int nBottom = D2_MIN(pClip->nBottom, gnRenderHeight);
            if (nTop <= nBottom)
            {
                nY += CelGetOffsetY(pCel);
                if (nY >= nTop && nY - nHeight <= nBottom)
                {
                    pOut->nLeft = nLeft;
                    pOut->nRight = nRight;
                    if (nY <= nBottom)
                        pOut->f_8 = 0;
                    else
                        pOut->f_8 = nY - nBottom - 1;
                    if (nY - nHeight >= nTop)
                        pOut->nRows = nHeight - pOut->f_8;
                    else
                        pOut->nRows = nY - pOut->f_8 - nTop + 1;

                    D2_ASSERT(pOut->nRows > 0, 0xAB);
                    return 0;
                }
            }
        }
    }

    return 1;
}

// 0x00512250
void __fastcall sub_00512250_DrawCel(D2CelContextStrc* pContext, int nX, int nY, const D2DDrawClipRectStrc* pClip, int nDrawMode)
{
    D2DDrawCelClipStrc tOut;
    tOut.nLeft = 0;
    tOut.nRight = 0;
    tOut.f_8 = 0;
    tOut.nRows = 0;
    if (!sub_006001F0(pContext, 0, 1))
        return;
    if (sub_00511E80_ClipCel(pContext->pCel, nY, nX, &tOut, pClip))
        return;
    CelDrawEx((D2CmpCelContextStrc*)pContext, nX, nY, tOut.nLeft, tOut.nRight, gpScreenBuffer_007C9154,
        gnRenderHeight, gnRenderWidth, 0, DDCORE_GetDrawModePalette(nDrawMode, (int*)&pClip), tOut.f_8, tOut.nRows, 0); // 0x00511D70
}

// 0x00511FB0
int __fastcall sub_00511FB0_DrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, void* pPalette)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return 0;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return 0;

    const int nGamma = (unsigned char)dwGamma;
    unsigned char* pGammaTable = 0;
    const int nCaps = DDCORE_GetDrawModePalette(nDrawMode, (int*)&dwGamma);
    if (nGamma != 0xFF)
        pGammaTable = gpGfxPaletteView->pShadowLightGammaPalettes[nGamma >> 3];
    if (nDrawMode == 7)
        pGammaTable = gpGfxPaletteView->pRemap;

    CelDraw((D2CmpCelContextStrc*)pContext, nX, nY, gnDDrawClipLeft, gnDDrawClipRight,
        gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, (int)pGammaTable, nCaps, (int)pPalette);
    return 1;
}

// 0x005123B0
void __fastcall sub_005123B0_DDrawDebugFillBackBuffer(int nX, int nY)
{
    D2_ASSERT(nX > 0 && nX < gnRenderWidth - 0x50, 0x186);
    D2_ASSERT(nY > 0 && nY < gnRenderHeight - 0x50, 0x187);
    CmpDoLensEffect(gpScreenBuffer_007C9154 + gnRenderWidth * nY + nX, gnRenderWidth);
}
