#include "D2D3DTypes.h"

struct D2CelStrc;
struct D2CelContextStrc { unsigned char pad0[8]; int unitType; int classId; int mode; unsigned char pad1[0x18]; const char* name; unsigned char pad2[12]; D2CelStrc* cel; };

struct D2GlideContextStrc
{
    unsigned char unk_00[0x114];
    unsigned char* pPalette;
};

extern D2GlideContextStrc* gpGlideState_007C9150; // 0x007C9150
extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern D2VertexBufferStrc* gpVertexBuffer_00970F3C; // 0x00970F3C
extern int gnVertexIndex_00970F40; // 0x00970F40
extern int gnScale_00989748; // 0x00989748
extern const char gszEmpty_006CC837[]; // 0x006CC837
extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C

struct D2BoundsStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2ClipStrc
{
    int nLeft;
    int nWidth;
    int nTop;
    int nHeight;
};

int __stdcall sub_006001F0(D2CelContextStrc* context, int a2, int a3); // 0x006001F0
void __cdecl sub_00410610_WriteLogLine(const char* format, ...); // 0x00410610
int __stdcall sub_006018C0(D2CelStrc* cel); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* cel); // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* cel); // 0x00601920
int __stdcall sub_00601950(D2CelStrc* cel); // 0x00601950
int* __stdcall sub_00601B10_GetCelTextureSlots(D2CelStrc* cel); // 0x00601B10
void __fastcall sub_006BA760_Touch(int* pValue, int nValue); // 0x006BA760
void __fastcall sub_006B1F40_SetBlendMode(int mode); // 0x006B1F40
void __fastcall sub_006B1EA0_SetState(int nState); // 0x006B1EA0
void __fastcall sub_006B2030_SetFilterMode(int nMode); // 0x006B2030
void __fastcall sub_006B9780_SetColor(D2TLVertexStrc* pVertex, unsigned int nPacked, unsigned char nAlpha); // 0x006B9780
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

static __declspec(noinline) int sub_006B5C80_LoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info);
static __declspec(noinline) void sub_006B5CF0_SetTextureSize(D2SpriteInfoStrc* pInfo);
static __declspec(noinline) int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* pInfo, int nMode, int nArg3, int nArg4);
static __declspec(noinline) void __stdcall sub_006B63F0_DrawQuad(D2SpriteInfoStrc* pSprite, int nX, int nY, unsigned int nColor, int nPaletteIndex, unsigned char nAlpha, int bPalette);
static __declspec(noinline) unsigned char sub_006B6680_SetBlendAndAlpha(int mode);
static __declspec(noinline) int __stdcall sub_006B6D70_ClipSprite(D2SpriteInfoStrc* pInfo, int nX, int nY, const D2BoundsStrc* pBounds, D2ClipStrc* pClip);
static int __stdcall sub_006B6D70_ClipSprite(D2SpriteInfoStrc* pInfo, int nX, int nY, const D2BoundsStrc* pBounds, D2ClipStrc* pClip); // 0x006B6D70

int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* ptInfo, int nMode, int nArg3, unsigned char nColor); // 0x006B5D40

// 0x006B5C80
int sub_006B5C80_LoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info)
{
    if (!sub_006001F0(context, 0, 1))
        return 0;
    if (!context->cel)
    {
        sub_00410610_WriteLogLine("error loading sprite unit:%d  class:%d  mode:%d  %s", context->unitType, context->classId, context->mode, context->name);
        return 0;
    }
    info->pContext = context;
    info->nWidth = sub_006018C0(context->cel);
    info->nOffsetX = sub_00601920(context->cel);
    info->nHeight = sub_006018F0(context->cel);
    info->nOffsetY = sub_00601950(context->cel);
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
    int* pSlots = sub_00601B10_GetCelTextureSlots(pInfo->pContext->cel);
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
    sub_006B1EA0_SetState(1);
    sub_006B2030_SetFilterMode(1);

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
    if (bPerspective && gnScale_00989748 != 256)
    {
        tRect.nX = gnScale_00989748 * tRect.nX / 256;
        tRect.nY = gnScale_00989748 * tRect.nY / 256;
        tRect.nWidth = gnScale_00989748 * tRect.nWidth / 256;
        tRect.nHeight = gnScale_00989748 * tRect.nHeight / 256;
    }

    int nLeft = tRect.nX + nX;
    float fX0 = (float)nLeft;
    float fX1 = (float)(nLeft + tRect.nWidth);
    int nTop = tRect.nY + nY;
    float fY0 = (float)nTop;
    float fY1 = (float)(nTop + tRect.nHeight);

    D2TLVertexStrc* pVertices;
    if (gpVertexBuffer_00970F3C->lpVtbl->Lock(gpVertexBuffer_00970F3C, 0x21, (void**)&pVertices, 0))
    {
        return;
    }

    pVertices += gnVertexIndex_00970F40;
    if (!nPaletteIndex && !bPalette)
    {
        sub_006B9780_SetColor(pVertices, nColor, nAlpha);
    }
    else
    {
        pVertices->dwColor = (((unsigned int)nAlpha << 8 | gpGlideState_007C9150->pPalette[nPaletteIndex * 3]) << 8 | gpGlideState_007C9150->pPalette[nPaletteIndex * 3 + 1]) << 8 | gpGlideState_007C9150->pPalette[nPaletteIndex * 3 + 2];
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

    gpVertexBuffer_00970F3C->lpVtbl->Unlock(gpVertexBuffer_00970F3C);
    gpDevice_00970E78->lpVtbl->DrawPrimitiveVB(gpDevice_00970E78, 6, gpVertexBuffer_00970F3C, gnVertexIndex_00970F40, 4, 0x1C);
    gnVertexIndex_00970F40 += 4;
    if (gnVertexIndex_00970F40 > 43)
    {
        gnVertexIndex_00970F40 = 0;
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
        sub_006B1F40_SetBlendMode(1);
        break;
    case 3:
        sub_006B1F40_SetBlendMode(2);
        break;
    case 4:
        sub_006B1F40_SetBlendMode(3);
        break;
    default:
        sub_006B1F40_SetBlendMode(4);
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

// calling-convention shim (not game code)
int __stdcall sub_006B6D70_ClipSprite(D2SpriteInfoStrc* pInfo, int nX, int nY, const D2BoundsStrc* pBounds, D2ClipStrc* pClip)
{
    nX += pInfo->nOffsetX;
    pClip->nLeft = nX;
    pClip->nWidth = pInfo->nWidth;
    sub_006BA760_Touch(&nY, nX);
    sub_006BA760_Touch((int*)&pBounds, 0);
    return nY;
}

// 0x006B6EE0
void __fastcall sub_006B6EE0_DrawSpriteClipped(D2CelContextStrc* pContext, int nX, int nY, const D2BoundsStrc* pBounds, int nBlendMode)
{
    D2SpriteInfoStrc tInfo;
    D2ClipStrc tClip;

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

    if (sub_006B6D70_ClipSprite(&tInfo, nX, nY, pBounds, &tClip))
    {
        return;
    }

    float fScaleV = 1.0f / (float)tInfo.nTexHeight;
    float fScaleU = 1.0f / (float)tInfo.nTexWidth;
    if (tClip.nTop)
    {
        tInfo.fV0 = (float)(tInfo.nTexHeight - tClip.nHeight - tClip.nTop) * fScaleV;
        nY -= tClip.nTop;
        tInfo.fV1 = (float)(tInfo.nTexHeight - tClip.nTop) * fScaleV;
    }
    else
    {
        tInfo.fV0 = (float)(tInfo.nTexHeight - tClip.nHeight) * fScaleV;
    }
    tInfo.nTexHeight = tClip.nHeight;

    if (tClip.nLeft)
    {
        nX += tClip.nLeft;
        tInfo.fU0 = (float)tClip.nLeft * fScaleU;
        tInfo.fU1 = (float)(tClip.nLeft + tClip.nWidth) * fScaleU;
    }
    else
    {
        tInfo.fU1 = (float)tClip.nWidth * fScaleU;
    }
    tInfo.nTexWidth = tClip.nWidth;

    sub_006B63F0_DrawQuad(&tInfo, nX, nY, 0xFFFFFFFF, 0, nAlpha, 0);
}
