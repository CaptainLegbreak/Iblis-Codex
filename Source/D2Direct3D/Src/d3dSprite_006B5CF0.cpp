#include "D2D3DTypes.h"
#include "D2GfxTypes.h"
#include "D2CelContext.h"

struct D2CelStrc;

extern D2PaletteTableStrc* gpGlideState_007C9150; // 0x007C9150
extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern D2VertexBufferStrc* gpVertexBuffer; // 0x00970F3C
extern int gnVertexBufferPos; // 0x00970F40
extern int gnPerspectiveScale; // 0x00989748

int __stdcall sub_006001F0(D2CelContextStrc* context, int a2, int a3); // 0x006001F0
void __cdecl sub_00410610_WriteLogLine(const char* format, ...); // 0x00410610
int __stdcall CelGetWidth(D2CelStrc* cel); // 0x006018C0
int __stdcall CelGetHeight(D2CelStrc* cel); // 0x006018F0
int __stdcall CelGetOffsetX(D2CelStrc* cel); // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* cel); // 0x00601950
int* __stdcall sub_00601B10_GetCelTextureSlots(D2CelStrc* cel); // 0x00601B10
void __fastcall sub_006BA760_Touch(int* pValue, int nValue); // 0x006BA760
void __fastcall D3D_SetAlphaBlendMode(int mode); // 0x006B1F40
void __fastcall D3D_SetColorCombineMode(int nState); // 0x006B1EA0
void __fastcall D3D_SetTextureFilterMode(int nMode); // 0x006B2030
void __fastcall sub_006B9780_SetColor(D2TLVertexStrc* pVertex, unsigned int nPacked, unsigned char nAlpha); // 0x006B9780
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830

int sub_006B5C80_LoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info); // 0x006B5C80
static void sub_006B5CF0_SetTextureSize(D2SpriteInfoStrc* pInfo);
static int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* pInfo, int nMode, int nArg3, int nArg4);
void __stdcall sub_006B63F0_DrawQuad(D2SpriteInfoStrc* pSprite, int nX, int nY, unsigned int nColor, int nPaletteIndex, unsigned char nAlpha, int bPalette); // 0x006B63F0
unsigned char sub_006B6680_SetBlendAndAlpha(int mode); // 0x006B6680

int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* ptInfo, int nMode, int nArg3, unsigned char nColor); // 0x006B5D40

// 0x006B5CF0
void sub_006B5CF0_SetTextureSize(D2SpriteInfoStrc* pInfo)
{
    int nSize = 32;
    if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
    {
        nSize = 128;
        if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
        {
            nSize = 256;
            if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
            {
                goto done;
            }
        }
    }
    pInfo->nTexWidth = nSize;
    pInfo->nTexHeight = nSize;
done:
    pInfo->nTexSize = pInfo->nTexHeight * pInfo->nTexWidth;
    pInfo->fU0 = 0.0f;
    pInfo->fU1 = 1.0f;
    pInfo->fV0 = 0.0f;
    pInfo->fV1 = 1.0f;
}

// calling-convention shim (not game code)
int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* pInfo, int nMode, int nArg3, int nArg4)
{
    int* pSlots = sub_00601B10_GetCelTextureSlots(pInfo->pContext->pCel);
    if (nMode == 4)
    {
        nMode = 1;
    }
    int nSlot = pSlots[nMode * 2];
    int nWidth = pInfo->nWidth;
    sub_006BA760_Touch(&nArg3, 0);
    sub_006BA760_Touch(&nArg4, nSlot);
    return nWidth + nSlot;
}

// 0x006B6C90
void __fastcall sub_006B6C90_DrawSpriteRows(D2CelContextStrc* pContext, int nX, int nY, unsigned int nSkip, unsigned int nRows, int nBlendMode)
{
    D2SpriteInfoStrc tInfo;

    unsigned char nAlpha = sub_006B6680_SetBlendAndAlpha(nBlendMode);
    if (!sub_006B5C80_LoadSpriteInfo(pContext, &tInfo))
    {
        return;
    }

    sub_006B5CF0_SetTextureSize(&tInfo);
    if (!sub_006B5D40_UploadTexture(&tInfo, 1, 0, 0))
    {
        return;
    }

    float fScale = 1.0f / (float)tInfo.nTexHeight;
    int nTexHeight = tInfo.nTexHeight;
    if (nSkip)
    {
        nY -= nSkip;
        unsigned int nBottom = nTexHeight - nSkip;
        tInfo.fV0 = (float)(nBottom - nRows) * fScale;
        tInfo.fV1 = (float)nBottom * fScale;
    }
    else
    {
        tInfo.fV0 = (float)(nTexHeight - nRows) * fScale;
    }

    tInfo.nTexHeight = nRows;
    sub_006B63F0_DrawQuad(&tInfo, nX, nY, 0xFFFFFFFF, 0, nAlpha, 0);
}
