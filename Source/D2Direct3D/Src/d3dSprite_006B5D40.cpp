#include "D2D3DTypes.h"
#include "D2GfxTypes.h"

struct D2CelStrc;

struct D2CelContextStrc { unsigned char pad0[8]; int unitType; int classId; int mode; unsigned char pad1[0x18]; const char* name; unsigned char pad2[12]; D2CelStrc* cel; };

extern D2GfxPaletteViewStrc* gpGlideState_007C9150; // 0x007C9150

struct D2DDSurfaceDesc2Strc
{
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwHeight;
    unsigned long dwWidth;
    long lPitch;
    unsigned long dwBackBufferCount;
    unsigned long dwMipMapCount;
    unsigned long dwAlphaBitDepth;
    unsigned long dwReserved;
    void* lpSurface;
    unsigned char unk0x28[0x54];
};

struct D2DDSurfaceStrc;
struct D2DDSurfaceVtbl
{
    void* pfn00[25];
    long (__stdcall* Lock)(D2DDSurfaceStrc* pThis, void* pRect, D2DDSurfaceDesc2Strc* pDesc, unsigned long dwFlags, void* hEvent);
    void* pfn68[6];
    long (__stdcall* Unlock)(D2DDSurfaceStrc* pThis, void* pRect);
};
struct D2DDSurfaceStrc
{
    D2DDSurfaceVtbl* lpVtbl;
};

struct D2TexturePoolEntryStrc
{
    int unk0x00;
    int* pSlots;
    int nMode;
    int nArg;
    void* pTarget;
    D2D3DTextureStrc* pTexture;
    int unk0x18;
    int unk0x1C;
};

struct D2TexturePoolStrc
{
    int nCount;
    int unk0x04[5];
    D2TexturePoolEntryStrc* pEntries;
};

typedef char check_desc_size[(sizeof(D2DDSurfaceDesc2Strc) == 0x7C) ? 1 : -1];
typedef char check_pool_size[(sizeof(D2TexturePoolStrc) == 0x1C) ? 1 : -1];
typedef char check_entry_size[(sizeof(D2TexturePoolEntryStrc) == 0x20) ? 1 : -1];

extern "C" const char gszEmptyAssertText;                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                // 0x00681EF0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall CelDraw(D2CelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11); // 0x006014C0
void __fastcall sub_006B1DC0_Blit8To16(const unsigned char* pSource, unsigned short* pDest, int nWidth, int nHeight, int nPitch, int nUnused); // 0x006B1DC0
void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere, int hResult); // 0x006B20E0
void __fastcall sub_006B38A0_Copy(void* pTarget, D2DDSurfaceStrc* pSurface, int nRows); // 0x006B38A0
void __fastcall sub_006B39B0_ShowD3DError(const char* szText, long nResult); // 0x006B39B0
void __fastcall sub_006BA760_TouchEntry(D2TexturePoolStrc* pPool, int nIndex); // 0x006BA760
int __fastcall sub_006BA920_AllocEntry(D2TexturePoolStrc* pPool); // 0x006BA920

extern unsigned int gnRenderFlags_0096F3A8; // 0x0096F3A8
extern const unsigned int gnRenderFlag_006CE290; // 0x006CE290
extern D2TexturePoolStrc gaTexturePools_00970EAC[]; // 0x00970EAC
extern D2D3DTextureStrc* gapTextures_00970F18[]; // 0x00970F18
extern D2DDSurfaceStrc* gapSurfaces_00970F24[]; // 0x00970F24
extern unsigned char* gpBuffer_00970F34; // 0x00970F34
extern unsigned char* gpBuffer_00970F38; // 0x00970F38
extern "C" const char gszSetTextureFailed_006FC26C[]; // 0x006FC26C
extern "C" const char gszUnlockFailed_006FC284[]; // 0x006FC284
extern "C" const char gszLockFailed_006FC2A4[]; // 0x006FC2A4
extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern D2VertexBufferStrc* gpVertexBuffer_00970F3C; // 0x00970F3C
extern int gnVertexIndex_00970F40; // 0x00970F40
extern int gnScale_00989748; // 0x00989748
extern const char gszSpriteError_006FC238[]; // 0x006FC238

int __stdcall sub_006001F0(D2CelContextStrc* context, int a2, int a3); // 0x006001F0
void __cdecl sub_00410610_WriteLogLine(const char* format, ...); // 0x00410610
int __stdcall sub_006018C0(D2CelStrc* cel); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* cel); // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* cel); // 0x00601920
int __stdcall sub_00601950(D2CelStrc* cel); // 0x00601950
int* __stdcall sub_00601B10_GetCelTextureSlots(D2CelStrc* cel); // 0x00601B10
void __fastcall sub_006B1F40_SetBlendMode(int mode); // 0x006B1F40
void __fastcall sub_006B1EA0_SetState(int nState); // 0x006B1EA0
void __fastcall sub_006B2030_SetFilterMode(int nMode); // 0x006B2030
void __fastcall sub_006B9780_SetColor(D2TLVertexStrc* pVertex, unsigned int nPacked, unsigned char nAlpha); // 0x006B9780
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830

static __declspec(noinline) int sub_006B5C80_LoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info);
static __declspec(noinline) void sub_006B5CF0_SetTextureSize(D2SpriteInfoStrc* pInfo);
static __declspec(noinline) int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* pInfo, int nMode, int nArg3, unsigned char nColor);
static __declspec(noinline) void __stdcall sub_006B63F0_DrawQuad(D2SpriteInfoStrc* pSprite, int nX, int nY, unsigned int nColor, int nPaletteIndex, unsigned char nAlpha, int bPalette);
static __declspec(noinline) unsigned char sub_006B6680_SetBlendAndAlpha(int mode);

static int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* pInfo, int nMode, int nArg3, unsigned char nColor); // 0x006B5D40

// 0x006B5C80
int sub_006B5C80_LoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info)
{
    if (!sub_006001F0(context, 0, 1))
        return 0;
    if (!context->cel)
    {
        sub_00410610_WriteLogLine(gszSpriteError_006FC238, context->unitType, context->classId, context->mode, context->name);
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

struct D2TexLocationStrc
{
    int nCache;
    int nIndex;
};

// 0x006B5D40
int __stdcall sub_006B5D40_UploadTexture(D2SpriteInfoStrc* ptInfo, int nMode, int nArg3, unsigned char nColor)
{
    D2_ASSERT(ptInfo->pContext->cel, 0x11E);
    int* pSlots = sub_00601B10_GetCelTextureSlots(ptInfo->pContext->cel);
    const int nOrigMode = nMode;
    if (nMode == 4)
    {
        nMode = 1;
    }

    D2TexLocationStrc* tLocation = &((D2TexLocationStrc*)pSlots)[nMode];
    if (!tLocation->nCache)
    {
        if (ptInfo->nWidth <= 32 && ptInfo->nHeight <= 32)
        {
            tLocation->nCache = 3;
        }
        else if (ptInfo->nWidth <= 128 && ptInfo->nHeight <= 128)
        {
            tLocation->nCache = 2;
        }
        else if (ptInfo->nWidth <= 256 && ptInfo->nHeight <= 256)
        {
            tLocation->nCache = 1;
        }
        else
        {
            return 0;
        }
    }

    D2TexturePoolStrc* pPool = &gaTexturePools_00970EAC[tLocation->nCache];
    long hResult;
    if (((D2TexLocationStrc*)pSlots)[nMode].nIndex && (pPool->pEntries[((D2TexLocationStrc*)pSlots)[nMode].nIndex - 1].nArg == nArg3 || nOrigMode == 4))
    {
        sub_006BA760_TouchEntry(pPool, tLocation->nIndex);
        D2TexturePoolEntryStrc* pHit = &pPool->pEntries[tLocation->nIndex - 1];
        hResult = gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, pHit->pTexture);
        if (hResult)
        {
            sub_006B39B0_ShowD3DError(gszSetTextureFailed_006FC26C, hResult);
        }
        return 1;
    }

    {
    D2DDSurfaceStrc* pSurface = gapSurfaces_00970F24[tLocation->nCache];
    D2D3DTextureStrc* pSource = gapTextures_00970F18[tLocation->nCache];
    if (!((D2TexLocationStrc*)pSlots)[nMode].nIndex)
    {
        tLocation->nIndex = sub_006BA920_AllocEntry(pPool);
    }
    D2_ASSERT(tLocation->nIndex - 1 >= 0, 0x164);
    D2_ASSERT(tLocation->nIndex - 1 < pPool->nCount, 0x165);

    unsigned char* pBuffer = gpBuffer_00970F34;
    unsigned char* pData = gpBuffer_00970F34;
    D2TexturePoolEntryStrc* pEntry = &pPool->pEntries[tLocation->nIndex - 1];
    pEntry->pSlots = pSlots;
    pEntry->nMode = nMode;
    pEntry->nArg = nArg3;
    D2_ASSERT(pEntry->pTarget, 0x16D);
    D2_ASSERT(pEntry->pTexture, 0x16E);
    D2_ASSERT(pBuffer, 0x171);
    D2_ASSERT(ptInfo->nTexSize <= 0x10000, 0x172);
    memset(pBuffer, 0, ptInfo->nTexSize);

    switch (nMode)
    {
    case 1:
    case 4:
        CelDraw(ptInfo->pContext, -ptInfo->nOffsetX, ptInfo->nTexHeight - ptInfo->nOffsetY - 1, 0, 0, pBuffer,
            ptInfo->nTexHeight, ptInfo->nTexWidth, 0, 0, nArg3);
        break;

    case 2:
    {
        CelDraw(ptInfo->pContext, -ptInfo->nOffsetX, ptInfo->nTexHeight - ptInfo->nOffsetY - 1, 0, 0, pBuffer,
            ptInfo->nTexHeight, ptInfo->nTexWidth, 0, 0, nArg3);
        unsigned char* pPixel = gpBuffer_00970F34;
        unsigned char* pRemap = gpGlideState_007C9150->pRemap;
        for (int i = 0; i < ptInfo->nTexSize; ++i)
        {
            if (*pPixel)
            {
                *pPixel = pRemap[*pPixel];
            }
            ++pPixel;
        }
        break;
    }

    case 3:
    {
        CelDraw(ptInfo->pContext, 1 - ptInfo->nOffsetX, ptInfo->nTexHeight - ptInfo->nOffsetY - 2, 0, 0, pBuffer,
            ptInfo->nTexHeight, ptInfo->nTexWidth, 0, 0, 0);
        unsigned char* pOutline = gpBuffer_00970F38;
        D2_ASSERT(pOutline, 0x19A);
        D2_ASSERT(ptInfo->nTexSize <= 0x10000, 0x19B);
        memset(pOutline, 0, ptInfo->nTexSize);
        unsigned char* pSrc = gpBuffer_00970F34 + ptInfo->nTexWidth;
        unsigned char* pDst = pOutline + ptInfo->nTexWidth;
        const int nPitch = ptInfo->nTexWidth;
        const int nCount = ptInfo->nTexSize - 2 * nPitch;
        for (int i = 0; i < nCount; ++i)
        {
            if (*pSrc++)
            {
                pDst[-ptInfo->nTexWidth] = nColor;
                pDst[-1] = nColor;
                pDst[1] = nColor;
                pDst[ptInfo->nTexWidth] = nColor;
            }
            ++pDst;
        }
        pData = pOutline;
        break;
    }
    }

    D2_ASSERT(pSurface, 0x1B4);
    D2_ASSERT(pSource, 0x1B5);

    D2DDSurfaceDesc2Strc tDesc = { sizeof(tDesc) };
    hResult = pSurface->lpVtbl->Lock(pSurface, 0, &tDesc, 0x21, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError(gszLockFailed_006FC2A4, hResult);
    }
    D2_ASSERT(tDesc.dwFlags & 8, 0x1C0);
    sub_006B1DC0_Blit8To16(pData, (unsigned short*)tDesc.lpSurface, ptInfo->nTexWidth, ptInfo->nTexHeight, tDesc.lPitch >> 1,
        ptInfo->nTexHeight);
    hResult = pSurface->lpVtbl->Unlock(pSurface, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError(gszUnlockFailed_006FC284, hResult);
    }

    if (gnRenderFlags_0096F3A8 & gnRenderFlag_006CE290)
    {
        sub_006B38A0_Copy(pEntry->pTarget, pSurface, ptInfo->nTexHeight);
    }
    else
    {
        pEntry->pTexture->lpVtbl->Load(pEntry->pTexture, pSource);
    }

    hResult = gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, pEntry->pTexture);
    }
    if (hResult)
    {
        sub_006B39B0_ShowD3DError(gszSetTextureFailed_006FC26C, hResult);
    }
    return 1;
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
        pVertices->dwColor = (((unsigned int)nAlpha << 8 | gpGlideState_007C9150->pRgbTable[nPaletteIndex * 3]) << 8 | gpGlideState_007C9150->pRgbTable[nPaletteIndex * 3 + 1]) << 8 | gpGlideState_007C9150->pRgbTable[nPaletteIndex * 3 + 2];
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

#include "gen/data/Source/D2Direct3D/Src/d3dSprite_006B5D40.inc"
