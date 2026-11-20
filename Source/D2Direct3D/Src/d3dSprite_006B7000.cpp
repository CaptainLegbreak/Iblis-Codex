#include "D2D3DTypes.h"

struct D2CelStrc;
struct D2CelContextStrc { unsigned char pad0[8]; int unitType; int classId; int mode; unsigned char pad1[0x18]; const char* name; unsigned char pad2[12]; D2CelStrc* cel; };

extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern D2VertexBufferStrc* gpVertexBuffer_00970F3C; // 0x00970F3C
extern int gnVertexIndex_00970F40; // 0x00970F40
extern int gnScale_00989748; // 0x00989748

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
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830
int __cdecl sub_006B77A0_GetBlendedShadows(); // 0x006B77A0

static __declspec(noinline) int sub_006B5C80_LoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info);
static __declspec(noinline) void sub_006B5CF0_SetTextureSize(D2SpriteInfoStrc* pInfo);
static __declspec(noinline) int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* pInfo, int nMode, int nArg3, int nArg4);
static __declspec(noinline) void __stdcall sub_006B61A0_DrawShadowQuad(int nOffsetX, int nOffsetY, unsigned char nAlpha, D2SpriteInfoStrc* pQuad);

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

// build: context sub_006B61A0_DrawShadowQuad
void __stdcall sub_006B61A0_DrawShadowQuad(int nOffsetX, int nOffsetY, unsigned char nAlpha, D2SpriteInfoStrc* pQuad)
{
    float fU0 = pQuad->fU0;
    float fU1 = pQuad->fU1;
    float fV0 = pQuad->fV0;
    float fV1 = pQuad->fV1;
    int bPerspective = sub_006B9830_GetPerspective();

    D2QuadRectStrc tRect;
    tRect.nHeight = pQuad->nTexHeight >> 1;
    pQuad->nOffsetY >>= 1;
    tRect.nWidth = pQuad->nTexWidth;
    tRect.nX = pQuad->nOffsetX + pQuad->nOffsetY;
    tRect.nY = pQuad->nOffsetY - tRect.nHeight;

    if (bPerspective && gnScale_00989748 != 256)
    {
        tRect.nX = gnScale_00989748 * tRect.nX / 256;
        tRect.nY = gnScale_00989748 * tRect.nY / 256;
        tRect.nWidth = gnScale_00989748 * tRect.nWidth / 256;
        tRect.nHeight = gnScale_00989748 * tRect.nHeight / 256;
    }

    int nX = tRect.nX + nOffsetX;
    int nY = tRect.nY + nOffsetY;
    int nWidth = tRect.nWidth;
    int nHeight = tRect.nHeight;
    float fTop = (float)nY;
    float fBottom = (float)(nY + nHeight);

    D2TLVertexStrc* pVertices;
    if (gpVertexBuffer_00970F3C->lpVtbl->Lock(gpVertexBuffer_00970F3C, 0x21, (void**)&pVertices, 0))
        return;

    pVertices += gnVertexIndex_00970F40;
    int nLeft = nX - nHeight;
    pVertices[0].fX = (float)nLeft;
    pVertices[0].fY = fTop;
    pVertices[0].fZ = 0.5f;
    pVertices[0].fRhw = 1.0f;
    pVertices[0].fU = fU0;
    pVertices[0].fV = fV0;
    pVertices[1].fX = (float)nX;
    pVertices[1].fY = fBottom;
    pVertices[1].fZ = 0.5f;
    pVertices[1].fRhw = 1.0f;
    pVertices[1].fU = fU0;
    pVertices[1].fV = fV1;
    pVertices[2].fX = (float)(nX + nWidth);
    pVertices[2].fY = fBottom;
    pVertices[2].fZ = 0.5f;
    pVertices[2].fRhw = 1.0f;
    pVertices[2].fU = fU1;
    pVertices[2].fV = fV1;
    pVertices[3].fX = (float)(nLeft + nWidth);
    pVertices[3].fY = fTop;
    pVertices[3].fZ = 0.5f;
    pVertices[3].fRhw = 1.0f;
    pVertices[3].fU = fU1;
    pVertices[3].fV = fV0;
    pVertices[0].dwColor = (unsigned int)nAlpha << 24;
    pVertices[1].dwColor = pVertices[0].dwColor;
    pVertices[2].dwColor = pVertices[1].dwColor;
    pVertices[3].dwColor = pVertices[2].dwColor;

    gpVertexBuffer_00970F3C->lpVtbl->Unlock(gpVertexBuffer_00970F3C);
    gpDevice_00970E78->lpVtbl->DrawPrimitiveVB(gpDevice_00970E78, 6, gpVertexBuffer_00970F3C, gnVertexIndex_00970F40, 4, 0x1C);

    gnVertexIndex_00970F40 += 4;
    if (gnVertexIndex_00970F40 > 0x2B)
        gnVertexIndex_00970F40 = 0;
}

// 0x006B7000
void __fastcall sub_006B7000_DrawSpriteShadow(D2CelContextStrc* pContext, int nX, int nY)
{
    D2SpriteInfoStrc tInfo;
    unsigned char nAlpha = 255;

    if (!sub_006B5C80_LoadSpriteInfo(pContext, &tInfo))
    {
        return;
    }

    sub_006B5CF0_SetTextureSize(&tInfo);
    if (!sub_006B5D40_UploadTexture(&tInfo, 4, 0, 0))
    {
        return;
    }

    sub_006B1EA0_SetState(1);
    if (sub_006B77A0_GetBlendedShadows())
    {
        sub_006B1F40_SetBlendMode(4);
        nAlpha = 192;
    }
    else
    {
        sub_006B1F40_SetBlendMode(1);
    }
    sub_006B2030_SetFilterMode(1);
    sub_006B61A0_DrawShadowQuad(nX, nY, nAlpha, &tInfo);
}
