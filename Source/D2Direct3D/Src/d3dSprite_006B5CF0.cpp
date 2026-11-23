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

static int sub_006B5C80_LoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info);
static void sub_006B5CF0_SetTextureSize(D2SpriteInfoStrc* pInfo);
static int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* pInfo, int nMode, int nArg3, int nArg4);
static void __stdcall sub_006B63F0_DrawQuad(D2SpriteInfoStrc* pSprite, int nX, int nY, unsigned int nColor, int nPaletteIndex, unsigned char nAlpha, int bPalette);
static unsigned char sub_006B6680_SetBlendAndAlpha(int mode);

int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* ptInfo, int nMode, int nArg3, unsigned char nColor); // 0x006B5D40

// 0x006B5C80
int sub_006B5C80_LoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info)
{
    if (!sub_006001F0(context, 0, 1))
        return 0;
    if (!context->pCel)
    {
        sub_00410610_WriteLogLine("error loading sprite unit:%d  class:%d  mode:%d  %s", context->nType, context->nClass, context->nMode, context->szName);
        return 0;
    }
    info->pContext = context;
    info->nWidth = CelGetWidth(context->pCel);
    info->nOffsetX = CelGetOffsetX(context->pCel);
    info->nHeight = CelGetHeight(context->pCel);
    info->nOffsetY = CelGetOffsetY(context->pCel);
    return 1;
}

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

// 0x006B63F0
void __stdcall sub_006B63F0_DrawQuad(D2SpriteInfoStrc* pSprite, int nX, int nY, unsigned int nColor, int nPaletteIndex, unsigned char nAlpha, int bPalette)
{
    D3D_SetColorCombineMode(1);
    D3D_SetTextureFilterMode(1);

    D2QuadRectStrc tRect;
    tRect.nX = pSprite->nOffsetX;
    float fU0 = pSprite->fU0;
    float fU1 = pSprite->fU1;
    float fV0 = pSprite->fV0;
    float fV1 = pSprite->fV1;

    int bPerspective = sub_006B9830_GetPerspective();
    tRect.nWidth = pSprite->nTexWidth;
    tRect.nHeight = pSprite->nTexHeight;
    tRect.nY = pSprite->nOffsetY - tRect.nHeight;
    if (bPerspective && gnPerspectiveScale != 256)
    {
        tRect.nX = gnPerspectiveScale * tRect.nX / 256;
        tRect.nY = gnPerspectiveScale * tRect.nY / 256;
        tRect.nWidth = gnPerspectiveScale * tRect.nWidth / 256;
        tRect.nHeight = gnPerspectiveScale * tRect.nHeight / 256;
    }

    int nLeft = tRect.nX + nX;
    float fX0 = (float)nLeft;
    float fX1 = (float)(nLeft + tRect.nWidth);
    int nTop = tRect.nY + nY;
    float fY0 = (float)nTop;
    float fY1 = (float)(nTop + tRect.nHeight);

    D2TLVertexStrc* pVertices;
    if (gpVertexBuffer->lpVtbl->Lock(gpVertexBuffer, 0x21, (void**)&pVertices, 0))
    {
        return;
    }

    pVertices += gnVertexBufferPos;
    if (!nPaletteIndex && !bPalette)
    {
        sub_006B9780_SetColor(pVertices, nColor, nAlpha);
    }
    else
    {
        pVertices->dwColor = (((unsigned int)nAlpha << 8 | gpGlideState_007C9150->pStandardColorsPalette[nPaletteIndex * 3]) << 8 | gpGlideState_007C9150->pStandardColorsPalette[nPaletteIndex * 3 + 1]) << 8 | gpGlideState_007C9150->pStandardColorsPalette[nPaletteIndex * 3 + 2];
    }

    pVertices[1].dwColor = pVertices[0].dwColor;
    pVertices[2].dwColor = pVertices[1].dwColor;
    pVertices[3].dwColor = pVertices[2].dwColor;

    pVertices[0].fX = fX0;
    pVertices[0].fY = fY0;
    pVertices[0].fZ = 0.5f;
    pVertices[0].fRhw = 1.0f;
    pVertices[0].fU = fU0;
    pVertices[0].fV = fV0;

    pVertices[1].fX = fX0;
    pVertices[1].fY = fY1;
    pVertices[1].fZ = 0.5f;
    pVertices[1].fRhw = 1.0f;
    pVertices[1].fU = fU0;
    pVertices[1].fV = fV1;

    pVertices[2].fX = fX1;
    pVertices[2].fY = fY1;
    pVertices[2].fZ = 0.5f;
    pVertices[2].fRhw = 1.0f;
    pVertices[2].fU = fU1;
    pVertices[2].fV = fV1;

    pVertices[3].fX = fX1;
    pVertices[3].fY = fY0;
    pVertices[3].fZ = 0.5f;
    pVertices[3].fRhw = 1.0f;
    pVertices[3].fU = fU1;
    pVertices[3].fV = fV0;

    gpVertexBuffer->lpVtbl->Unlock(gpVertexBuffer);
    gpDevice_00970E78->lpVtbl->DrawPrimitiveVB(gpDevice_00970E78, 6, gpVertexBuffer, gnVertexBufferPos, 4, 0x1C);
    gnVertexBufferPos += 4;
    if (gnVertexBufferPos > 43)
    {
        gnVertexBufferPos = 0;
    }
}

// 0x006B6680
unsigned char sub_006B6680_SetBlendAndAlpha(int mode)
{
    unsigned char alpha = 255;
    switch (mode)
    {
    case 5:
    case 7:
        D3D_SetAlphaBlendMode(1);
        break;
    case 3:
        D3D_SetAlphaBlendMode(2);
        break;
    case 4:
        D3D_SetAlphaBlendMode(3);
        break;
    default:
        D3D_SetAlphaBlendMode(4);
        if (mode == 0)
            alpha = 64;
        else if (mode == 1)
            alpha = 128;
        else if (mode == 2)
            alpha = 192;
        break;
    }
    return alpha;
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
