#include "D2DDraw.h"
#include "D2CelContext.h"

struct D2CelStrc;
struct D2DDrawClipRectStrc;
struct D2DDrawCelClipStrc;

extern int gnDDrawOriginX_0088129C; // 0x0088129C
int __stdcall sub_006018C0(D2CelStrc* pCel); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel); // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* pCel); // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel); // 0x00601950
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

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
int __fastcall sub_00511D70_GetCapsValue(int nIndex, int* pType); // 0x00511D70

extern D2GfxPaletteViewStrc* gpDDrawCaps_007C9150; // 0x007C9150
extern int gnDDrawModeWidth_008812A0; // 0x008812A0
void __stdcall sub_00608C00_RemapRegion(unsigned char* pBuffer, int nPitch); // 0x00608C00

int gnDDrawModeWidth_008812A0; // 0x008812A0

// 0x00511DF0
void __fastcall sub_00511DF0_DDrawSetMode(int nResolutionMode)
{
    if (nResolutionMode == 0)
    {
        gnDDrawOriginX_0088129C = 0;
        gnDDrawModeWidth_008812A0 = 640;
    }
    else
    {
        gnDDrawOriginX_0088129C = 0;
        gnDDrawModeWidth_008812A0 = 800;
    }
}

// 0x00511E10
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

// build: context sub_K08_EmitCelClip
extern "C" int __stdcall sub_K08_EmitCelClip(D2CelStrc* pCel, int nX, int nY)
{
    return sub_00511E10_IsCelOffScreen(pCel, nX, nY, 0) + 9;
}

// 0x00511E80
static int __fastcall sub_00511E80_ClipCel(D2CelStrc* pCel, int nY, int nX, D2DDrawCelClipStrc* pOut, const D2DDrawClipRectStrc* pClip)
{
    int nWidth = sub_006018C0(pCel);
    int nHeight = sub_006018F0(pCel);

    const int nLeft = D2_MAX(pClip->nLeft, 0);
    const int nRight = D2_MIN(pClip->nRight, gnScreenWidth_007C9138);
    if (nLeft <= nRight)
    {
        nX += sub_00601920(pCel);
        if (nX < nRight && nWidth + nX >= nLeft)
        {
            const int nTop = D2_MAX(pClip->nTop, 0);
            const int nBottom = D2_MIN(pClip->nBottom, gnScreenHeight_007C913C);
            if (nTop <= nBottom)
            {
                nY += sub_00601950(pCel);
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

void __fastcall sub_M366_Emit_00512250(D2CelContextStrc* pContext, int nX, int nY, const D2DDrawClipRectStrc* pClip, int nDrawMode)
{
    D2DDrawCelClipStrc tOut;
    tOut.nLeft = 0;
    tOut.nRight = 0;
    tOut.f_8 = 0;
    tOut.nRows = 0;
    if (!sub_006001F0(pContext, 0, 9))
        return;
    if (sub_00511E80_ClipCel(pContext->pCel, nY, nX, &tOut, pClip))
        return;
    const int nCaps = sub_00511D70_GetCapsValue(nDrawMode, (int*)&pClip);
    CelDrawEx((D2CmpCelContextStrc*)pContext, nX, nY, tOut.nLeft, tOut.nRight, gpScreenBuffer_007C9154,
        gnScreenHeight_007C913C, gnScreenWidth_007C9138, 0, nCaps, tOut.f_8, tOut.nRows, 0);
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
    const int nCaps = sub_00511D70_GetCapsValue(nDrawMode, (int*)&dwGamma);
    if (nGamma != 0xFF)
        pGammaTable = gpDDrawCaps_007C9150->pGammaTables[nGamma >> 3];
    if (nDrawMode == 7)
        pGammaTable = gpDDrawCaps_007C9150->pRemap;

    CelDraw((D2CmpCelContextStrc*)pContext, nX, nY, gnDDrawOriginX_0088129C, gnDDrawModeWidth_008812A0,
        gpScreenBuffer_007C9154, gnScreenHeight_007C913C, gnScreenWidth_007C9138, (int)pGammaTable, nCaps, (int)pPalette);
    return 1;
}

// 0x005123B0
void __fastcall sub_005123B0_DDrawDebugFillBackBuffer(int nX, int nY)
{
    D2_ASSERT(nX > 0 && nX < gnScreenWidth_007C9138 - 0x50, 0x186);
    D2_ASSERT(nY > 0 && nY < gnScreenHeight_007C913C - 0x50, 0x187);
    sub_00608C00_RemapRegion(gpScreenBuffer_007C9154 + gnScreenWidth_007C9138 * nY + nX, gnScreenWidth_007C9138);
}
