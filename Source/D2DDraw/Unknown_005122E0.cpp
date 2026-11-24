#include "D2DDraw.h"
#include "D2CmpTypes.h"

struct D2CelStrc;
int __stdcall sub_006001F0(D2CmpCelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0
int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0
int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0
int __stdcall CelGetOffsetX(D2CelStrc* pCel); // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* pCel); // 0x00601950
int __cdecl DDCORE_GetBlendedShadows(); // 0x00512700
void __stdcall CelDrawShadow(D2CmpCelContextStrc* pContext, int nX, int nY, int nClipLeft, int nClipRight, unsigned char* pBuffer, int nHeightLimit, int nPitch, int nTable, int nColor); // 0x00601730
extern int* gpShadowTable_007C9150; // 0x007C9150
extern unsigned char* gpSurface_007C9154; // 0x007C9154
extern int gnClipLeft_0088129C; // 0x0088129C
extern int gnClipRight_008812A0; // 0x008812A0

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

// 0x005122E0
void __fastcall sub_005122E0_DrawShadow(D2CmpCelContextStrc* pContext, int nX, int nY)
{
    if (!sub_006001F0(pContext, 0, 1))
        return;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 1))
        return;

    int nTable = 0;
    if (DDCORE_GetBlendedShadows())
        nTable = *gpShadowTable_007C9150;
    CelDrawShadow(pContext, nX, nY, gnClipLeft_0088129C, gnClipRight_008812A0, gpSurface_007C9154, gnRenderHeight, gnRenderWidth, nTable, 0);
}
