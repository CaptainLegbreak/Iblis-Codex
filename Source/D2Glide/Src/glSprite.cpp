#include "D2Glide.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GlideRectViewStrc;
struct D2GlideTexInfoStrc;
struct D2GlideTexSlotStrc;
struct D2GlideTexCacheEntryStrc;
struct D2GlideTexCacheStrc;
struct D2GrTexInfoExStrc;
struct D2GlideTexDimsStrc;

struct D2GlideRectViewStrc
{
    int unk0x00;
    int nLeft;
    int nTop;
    int nOffsetX;
    int nOffsetY;
};

extern int gnScreenWidth_007C9138; // 0x007C9138

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38;
    D2CelStrc* f_3C;
    int unk0x40;
    int unk0x44;
};

struct D2GlideTexInfoStrc
{
    D2CelContextStrc* pContext;
    int nWidth;
    int nHeight;
    int nOffsetX;
    int nOffsetY;
    int f_14;
    int f_18;
    int nTexSize;
    float fS0;
    float fS1;
    float fT0;
    float fT1;
    int nLod;
    int f_34;
};

struct D2GlideTexSlotStrc
{
    int nCache;
    int nId;
};

struct D2GlideTexCacheEntryStrc
{
    int nId;
    int f_4;
    D2GlideTexSlotStrc* pOwner;
    int nOwnerIndex;
    int f_10;
    D2GlideTexCacheEntryStrc* pNext;
    D2GlideTexCacheEntryStrc* pPrev;
};

struct D2GlideTexCacheStrc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideTexCacheEntryStrc* pHead;
    D2GlideTexCacheEntryStrc* pTail;
    D2GlideTexCacheEntryStrc* f_14;
    D2GlideTexCacheEntryStrc* f_18;
    D2GlideTexCacheEntryStrc* pEntries;
};

struct D2GrTexInfoExStrc
{
    int nSmallLodLog2;
    int nLargeLodLog2;
    int nAspectRatioLog2;
    int nFormat;
    void* pData;
};

struct D2GlideSpriteVertexStrc
{
    float x;
    float y;
    unsigned int dwColor;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};

struct D2GlideTexDimsStrc
{
    int nWidth;
    int nHeight;
};

struct D2GfxPaletteViewStrc
{
    char unk0x00[0x114];
    unsigned char* pRgbTable;
    unsigned char* f_118;
};
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0
void* __stdcall sub_00601B10_GetCelPixels(D2CelStrc* pCel); // 0x00601B10
void __fastcall sub_00509460_GlideSelectTmuState(int nTmu); // 0x00509460
void __fastcall sub_005094B0_GlideSetState(int nState); // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode); // 0x00509500
void __fastcall sub_005095D0_GlideSetDepth(int nMode); // 0x005095D0
int __cdecl sub_0050BF40_GlideGetBlendedShadows(); // 0x0050BF40
void __fastcall sub_0050DC30_GlideSetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor); // 0x0050DC30
int __cdecl sub_0050DD30_GlideIsPerspective(); // 0x0050DD30
void __fastcall sub_0050DD60_ProjectToScreen(int nX, int nY, int nZ, int* pScreenX, int* pScreenY); // 0x0050DD60
void __fastcall sub_0050EBE0_TexCacheTouch(D2GlideTexCacheStrc* pCache, int nId); // 0x0050EBE0
int __fastcall sub_0050ED10_ListRefill(D2GlideTexCacheStrc* pList); // 0x0050ED10
extern void (__stdcall* gpfGlideTexDownloadMipMap_0087EAB8)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoExStrc* pInfo); // 0x0087EAB8
extern void (__stdcall* gpfGlideTexSource_0087EB98)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoExStrc* pInfo); // 0x0087EB98
extern void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
extern int gbGlideSpriteFlag_0087EFF0; // 0x0087EFF0
extern int gbGlideMultiTmu_0087EFF4; // 0x0087EFF4
extern D2GlideSpriteVertexStrc gaGlideSpriteVertices_0087EFF8[4]; // 0x0087EFF8
extern D2GlideTexCacheStrc gaGlideTexCaches_0087F048[4]; // 0x0087F048
extern unsigned char* gpGlideSpriteBufferA_0087F0C8; // 0x0087F0C8
extern unsigned char* gpGlideSpriteBufferB_0087F0CC; // 0x0087F0CC
extern int gnGlideSpriteScale_00880B64; // 0x00880B64
extern D2GlideTexDimsStrc gaGlideAspectTexDims_0072F278[7]; // 0x0072F278

void* gpGlideBuffer_0087F0C8; // 0x0087F0C8

void* gpGlideBuffer_0087F0CC; // 0x0087F0CC

// 0x0050A0C0
void __cdecl sub_0050A0C0_FreeSpriteBuffers()
{
    if (gpGlideBuffer_0087F0C8)
    {
        FOG_Free(gpGlideBuffer_0087F0C8, ".\\Src\\glSprite.cpp", 0x74, 0);
        gpGlideBuffer_0087F0C8 = 0;
    }
    if (gpGlideBuffer_0087F0CC)
    {
        FOG_Free(gpGlideBuffer_0087F0CC, ".\\Src\\glSprite.cpp", 0x7A, 0);
        gpGlideBuffer_0087F0CC = 0;
    }
}

// 0x0050A1E0
static __forceinline int sub_0050A1E0_RoundTexSize(int nSize)
{
    if (nSize > 128)
        return 256;
    if (nSize > 64)
        return 128;
    if (nSize > 32)
        return 64;
    if (nSize > 16)
        return 32;
    return nSize > 8 ? 16 : 8;
}

// 0x0050A220
static __forceinline int sub_0050A220_GetTexSizeLog2(int nSize)
{
    if (nSize == 256)
        return 8;
    if (nSize == 128)
        return 7;
    if (nSize == 64)
        return 6;
    if (nSize == 32)
        return 5;
    return nSize == 16 ? 4 : 3;
}

// 0x0050AC90
static __forceinline int sub_0050AC90_IsOutsideScreen(int nX, int nY, D2GlideRectViewStrc* pRect)
{
    nX += pRect->nOffsetX;
    if (nX > gnScreenWidth_007C9138 || pRect->nLeft + nX < 0 || (nY += pRect->nOffsetY) < 0 || nY - pRect->nTop >= gnScreenHeight_007C913C)
        return 1;
    return 0;
}

int __fastcall sub_M120_Emit_0050A1E0(D2GlideRectViewStrc* pRect, int nA, int nB)
{
    int n = sub_0050A1E0_RoundTexSize(nA);
    n += sub_0050A220_GetTexSizeLog2(nB);
    n += sub_0050AC90_IsOutsideScreen(nA, nB, pRect);
    return n;
}

void (__stdcall* gpfGlideAlphaFunction_0087EAB4)(int nFunction); // 0x0087EAB4

void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor); // 0x0087EFA0

// 0x0050A260
static int sub_0050A260_GlideTexInfoInit(D2CelContextStrc* pContext, D2GlideTexInfoStrc* pInfo)
{
    if (!sub_006001F0(pContext, 0, 1))
        return 0;

    D2_ASSERT(pContext->f_3C, 0xCE);

    pInfo->pContext = pContext;
    pInfo->nWidth = sub_006018C0(pContext->f_3C);
    pInfo->nOffsetX = sub_00601920(pContext->f_3C);
    pInfo->nHeight = sub_006018F0(pContext->f_3C);
    pInfo->nOffsetY = sub_00601950(pContext->f_3C);
    return 1;
}

static void sub_0050A2D0_GlideTexInfoSetupSize(D2GlideTexInfoStrc* pInfo)
{
    int nTexWidth;
    if (pInfo->nWidth > 0x80)
        nTexWidth = 0x100;
    else if (pInfo->nWidth > 0x40)
        nTexWidth = 0x80;
    else if (pInfo->nWidth > 0x20)
        nTexWidth = 0x40;
    else if (pInfo->nWidth > 0x10)
        nTexWidth = 0x20;
    else
        nTexWidth = pInfo->nWidth > 8 ? 0x10 : 8;
    pInfo->f_14 = nTexWidth;

    int nTexHeight;
    if (pInfo->nHeight > 0x80)
        nTexHeight = 0x100;
    else if (pInfo->nHeight > 0x40)
        nTexHeight = 0x80;
    else if (pInfo->nHeight > 0x20)
        nTexHeight = 0x40;
    else if (pInfo->nHeight > 0x10)
        nTexHeight = 0x20;
    else
        nTexHeight = pInfo->nHeight > 8 ? 0x10 : 8;
    pInfo->f_18 = nTexHeight;

    const int nMax = nTexWidth > nTexHeight ? nTexWidth : nTexHeight;
    int nLod;
    if (nMax == 0x100)
        nLod = 8;
    else if (nMax == 0x80)
        nLod = 7;
    else if (nMax == 0x40)
        nLod = 6;
    else if (nMax == 0x20)
        nLod = 5;
    else
        nLod = (nMax == 0x10) + 3;
    pInfo->nLod = nLod;

    if (nTexWidth == nTexHeight)
    {
        pInfo->f_34 = 0;
    }
    else if (nTexWidth < nTexHeight)
    {
        int i;
        for (i = 0; i < 3; ++i)
        {
            nTexWidth += nTexWidth;
            if (nTexWidth > nTexHeight)
                break;
        }
        pInfo->f_14 = nTexHeight >> i;
        pInfo->f_34 = gaGlideAspectLodTall_0072F258[i];
    }
    else
    {
        int i;
        for (i = 0; i < 3; ++i)
        {
            nTexHeight += nTexHeight;
            if (nTexHeight > nTexWidth)
                break;
        }
        pInfo->f_18 = nTexWidth >> i;
        pInfo->f_34 = gaGlideAspectLodWide_0072F268[i];
    }

    if (!sub_0050DD30_GlideIsPerspective())
    {
        pInfo->fS0 = 0.0f;
        pInfo->fS1 = (float)pInfo->nWidth / pInfo->f_14;
        pInfo->nTexSize = pInfo->f_18 * pInfo->f_14;
        pInfo->fT0 = 1.0f - (float)pInfo->nHeight / pInfo->f_18;
        pInfo->fT1 = 1.0f;
    }
    else
    {
        pInfo->nTexSize = pInfo->f_18 * pInfo->f_14;
        pInfo->fS0 = 0.0f;
        pInfo->fS1 = 1.0f;
        pInfo->fT0 = 0.0f;
        pInfo->fT1 = 1.0f;
    }
}

static int __stdcall sub_0050A450_GlideTexInfoUpload(int nPalette, int nColor, D2GlideTexInfoStrc* pInfo, int nType)
{
    D2CelStrc* pCell = pInfo->pContext->f_3C;
    D2_ASSERT(pCell, 0x12D);

    D2GlideTexSlotStrc* pSlots = (D2GlideTexSlotStrc*)sub_00601B10_GetCelPixels(pCell);
    const int nRequested = nType;
    if (nType == 4)
        nType = 1;

    D2GrTexInfoExStrc tTexInfo;
    tTexInfo.nSmallLodLog2 = pInfo->nLod;
    tTexInfo.nLargeLodLog2 = pInfo->nLod;
    tTexInfo.nAspectRatioLog2 = pInfo->f_34;
    tTexInfo.nFormat = 5;
    tTexInfo.pData = gpGlideSpriteBufferA_0087F0C8;

    if (!pSlots[nType].nCache)
    {
        if (pInfo->nTexSize <= 0x1000)
            pSlots[nType].nCache = 3;
        else if (pInfo->nTexSize <= 0x4000)
            pSlots[nType].nCache = 2;
        else if (pInfo->nTexSize <= 0x10000)
            pSlots[nType].nCache = 1;
        else
            return 0;
    }

    D2GlideTexCacheStrc* pCache = &gaGlideTexCaches_0087F048[pSlots[nType].nCache];
    if (gbGlideSpriteFlag_0087EFF0)
        gbGlideMultiTmu_0087EFF4 = pSlots[nType].nCache == 1;

    int* pId = &pSlots[nType].nId;
    int nAddress;
    if (*pId && (pCache->pEntries[*pId - 1].f_10 == nPalette || nRequested == 4))
    {
        sub_0050EBE0_TexCacheTouch(pCache, *pId);
        nAddress = pCache->pEntries[*pId - 1].f_4;
    }
    else
    {
        if (!*pId)
            *pId = sub_0050ED10_ListRefill(pCache);

        pCache->pEntries[*pId - 1].pOwner = pSlots;
        pCache->pEntries[*pId - 1].nOwnerIndex = nType;
        pCache->pEntries[*pId - 1].f_10 = nPalette;
        nAddress = pCache->pEntries[*pId - 1].f_4;

        unsigned char* pBuffer = gpGlideSpriteBufferA_0087F0C8;
        D2_ASSERT(pBuffer, 0x184);
        D2_ASSERT(pInfo->nTexSize <= 0x10000, 0x185);
        memset(pBuffer, 0, pInfo->nTexSize);

        switch (nType)
        {
        case 1:
        case 4:
            sub_006014C0(pInfo->pContext, -pInfo->nOffsetX, pInfo->f_18 - pInfo->nOffsetY - 1, 0, 0, pBuffer, pInfo->f_18, pInfo->f_14, 0, 0, nPalette);
            break;

        case 2:
        {
            sub_006014C0(pInfo->pContext, -pInfo->nOffsetX, pInfo->f_18 - pInfo->nOffsetY - 1, 0, 0, pBuffer, pInfo->f_18, pInfo->f_14, 0, 0, nPalette);
            unsigned char* pRemap = gpGfxPaletteView_007C9150->f_118;
            unsigned char* pPixel = gpGlideSpriteBufferA_0087F0C8;
            for (int i = 0; i < pInfo->nTexSize; ++i)
            {
                if (*pPixel)
                    *pPixel = pRemap[*pPixel];
                ++pPixel;
            }
            break;
        }

        case 3:
        {
            sub_006014C0(pInfo->pContext, 1 - pInfo->nOffsetX, pInfo->f_18 - pInfo->nOffsetY - 2, 0, 0, pBuffer, pInfo->f_18, pInfo->f_14, 0, 0, 0);
            unsigned char* pOutline = gpGlideSpriteBufferB_0087F0CC;
            D2_ASSERT(pOutline, 0x1AD);
            D2_ASSERT(pInfo->nTexSize <= 0x10000, 0x1AE);
            memset(pOutline, 0, pInfo->nTexSize);

            const int nPitch = pInfo->f_14;
            unsigned char* pSrc = gpGlideSpriteBufferA_0087F0C8 + nPitch;
            unsigned char* pDst = pOutline + nPitch;
            const int nCount = pInfo->nTexSize - 2 * nPitch;
            for (int i = 0; i < nCount; ++i)
            {
                if (*pSrc++)
                {
                    pDst[-pInfo->f_14] = (unsigned char)nColor;
                    pDst[-1] = (unsigned char)nColor;
                    pDst[1] = (unsigned char)nColor;
                    pDst[pInfo->f_14] = (unsigned char)nColor;
                }
                ++pDst;
            }
            tTexInfo.pData = pOutline;
            break;
        }
        }

        gpfGlideTexDownloadMipMap_0087EAB8(gbGlideMultiTmu_0087EFF4, nAddress, 3, &tTexInfo);
    }

    gpfGlideTexSource_0087EB98(gbGlideMultiTmu_0087EFF4, nAddress, 3, &tTexInfo);
    sub_00509460_GlideSelectTmuState(gbGlideMultiTmu_0087EFF4);
    return 1;
}

static void __stdcall sub_0050A7B0_GlideDrawIsoQuad(int nX, int nY, D2GlideTexInfoStrc* pInfo)
{
    const D2GlideTexDimsStrc tDims = gaGlideAspectTexDims_0072F278[pInfo->f_34 + 3];
    const float fTexWidth = (float)tDims.nWidth;
    const float fS0 = pInfo->fS0 * fTexWidth;
    const float fS1 = pInfo->fS1 * fTexWidth;
    const float fTexHeight = (float)tDims.nHeight;
    const float fT0 = pInfo->fT0 * fTexHeight;
    const float fT1 = pInfo->fT1 * fTexHeight;

    const int bPerspective = sub_0050DD30_GlideIsPerspective();
    int nWidth;
    int nHeight;
    if (!bPerspective)
    {
        nWidth = pInfo->nWidth;
        nHeight = pInfo->nHeight;
    }
    else
    {
        nWidth = pInfo->f_14;
        nHeight = pInfo->f_18;
    }

    pInfo->nOffsetY >>= 1;
    nHeight >>= 1;
    int nLeft = pInfo->nOffsetX + pInfo->nOffsetY;
    int nTop = pInfo->nOffsetY - nHeight;
    if (bPerspective && gnGlideSpriteScale_00880B64 != 0x100)
    {
        nLeft = nLeft * gnGlideSpriteScale_00880B64 / 0x100;
        nTop = nTop * gnGlideSpriteScale_00880B64 / 0x100;
        nWidth = nWidth * gnGlideSpriteScale_00880B64 / 0x100;
        nHeight = nHeight * gnGlideSpriteScale_00880B64 / 0x100;
    }

    const int nY0 = nY + nTop;
    const int nX0 = nX + nLeft;
    const int nY1 = nY0 + nHeight;

    gaGlideSpriteVertices_0087EFF8[0].x = (float)(nX0 - nHeight);
    gaGlideSpriteVertices_0087EFF8[0].y = (float)nY0;
    gaGlideSpriteVertices_0087EFF8[0].dwColor = 0;
    gaGlideSpriteVertices_0087EFF8[0].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[0].sow = fS0;
    gaGlideSpriteVertices_0087EFF8[0].tow = fT0;
    gaGlideSpriteVertices_0087EFF8[1].x = (float)nX0;
    gaGlideSpriteVertices_0087EFF8[1].y = (float)nY1;
    gaGlideSpriteVertices_0087EFF8[1].dwColor = 0;
    gaGlideSpriteVertices_0087EFF8[1].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[1].sow = fS0;
    gaGlideSpriteVertices_0087EFF8[1].tow = fT1;
    gaGlideSpriteVertices_0087EFF8[2].x = (float)(nX0 + nWidth);
    gaGlideSpriteVertices_0087EFF8[2].y = (float)nY1;
    gaGlideSpriteVertices_0087EFF8[2].dwColor = 0;
    gaGlideSpriteVertices_0087EFF8[2].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[2].sow = fS1;
    gaGlideSpriteVertices_0087EFF8[2].tow = fT1;
    gaGlideSpriteVertices_0087EFF8[3].x = (float)(nX0 - nHeight + nWidth);
    gaGlideSpriteVertices_0087EFF8[3].y = (float)nY0;
    gaGlideSpriteVertices_0087EFF8[3].dwColor = 0;
    gaGlideSpriteVertices_0087EFF8[3].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[3].sow = fS1;
    gaGlideSpriteVertices_0087EFF8[3].tow = fT0;
    gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, gaGlideSpriteVertices_0087EFF8, sizeof(D2GlideSpriteVertexStrc));
}

static void __stdcall sub_0050A9A0_GlideDrawSpriteQuad(int nX, int nY, unsigned int dwColor, int bTinted, D2GlideTexInfoStrc* pInfo, int nPaletteIndex)
{
    sub_005094B0_GlideSetState(1);
    sub_005095D0_GlideSetDepth(1);

    if (!nPaletteIndex && !bTinted)
    {
        sub_0050DC30_GlideSetVertexColor(gaGlideSpriteVertices_0087EFF8, dwColor);
    }
    else
    {
        const unsigned char* pPalette = gpGfxPaletteView_007C9150->pRgbTable;
        const unsigned char* pRgb = pPalette + nPaletteIndex * 3;
        gaGlideSpriteVertices_0087EFF8[0].dwColor = ((pRgb[0] | 0xFFFFFF00) << 8 | pRgb[1]) << 8 | pRgb[2];
    }
    gaGlideSpriteVertices_0087EFF8[3].dwColor = gaGlideSpriteVertices_0087EFF8[0].dwColor;
    gaGlideSpriteVertices_0087EFF8[2].dwColor = gaGlideSpriteVertices_0087EFF8[0].dwColor;
    gaGlideSpriteVertices_0087EFF8[1].dwColor = gaGlideSpriteVertices_0087EFF8[0].dwColor;

    const D2GlideTexDimsStrc tDims = gaGlideAspectTexDims_0072F278[pInfo->f_34 + 3];
    const float fTexWidth = (float)tDims.nWidth;
    const float fS0 = pInfo->fS0 * fTexWidth;
    const float fS1 = pInfo->fS1 * fTexWidth;
    const float fTexHeight = (float)tDims.nHeight;
    const float fT0 = pInfo->fT0 * fTexHeight;
    const float fT1 = pInfo->fT1 * fTexHeight;

    const int bPerspective = sub_0050DD30_GlideIsPerspective();
    int nWidth;
    int nHeight;
    if (!bPerspective)
    {
        nWidth = pInfo->nWidth;
        nHeight = pInfo->nHeight;
    }
    else
    {
        nWidth = pInfo->f_14;
        nHeight = pInfo->f_18;
    }

    int nLeft = pInfo->nOffsetX;
    int nTop = pInfo->nOffsetY - nHeight;
    if (bPerspective && gnGlideSpriteScale_00880B64 != 0x100)
    {
        nLeft = nLeft * gnGlideSpriteScale_00880B64 / 0x100;
        nTop = nTop * gnGlideSpriteScale_00880B64 / 0x100;
        nWidth = nWidth * gnGlideSpriteScale_00880B64 / 0x100;
        nHeight = nHeight * gnGlideSpriteScale_00880B64 / 0x100;
    }

    const int nX0 = nX + nLeft;
    const float fX0 = (float)nX0;
    const float fX1 = (float)(nX0 + nWidth);
    const int nY0 = nY + nTop;
    const float fY0 = (float)nY0;
    const float fY1 = (float)(nY0 + nHeight);

    gaGlideSpriteVertices_0087EFF8[0].x = fX0;
    gaGlideSpriteVertices_0087EFF8[0].y = fY0;
    gaGlideSpriteVertices_0087EFF8[0].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[0].sow = fS0;
    gaGlideSpriteVertices_0087EFF8[0].tow = fT0;
    gaGlideSpriteVertices_0087EFF8[1].x = fX0;
    gaGlideSpriteVertices_0087EFF8[1].y = fY1;
    gaGlideSpriteVertices_0087EFF8[1].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[1].sow = fS0;
    gaGlideSpriteVertices_0087EFF8[1].tow = fT1;
    gaGlideSpriteVertices_0087EFF8[2].x = fX1;
    gaGlideSpriteVertices_0087EFF8[2].y = fY1;
    gaGlideSpriteVertices_0087EFF8[2].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[2].sow = fS1;
    gaGlideSpriteVertices_0087EFF8[2].tow = fT1;
    gaGlideSpriteVertices_0087EFF8[3].x = fX1;
    gaGlideSpriteVertices_0087EFF8[3].y = fY0;
    gaGlideSpriteVertices_0087EFF8[3].oow = 1.0f;
    gaGlideSpriteVertices_0087EFF8[3].sow = fS1;
    gaGlideSpriteVertices_0087EFF8[3].tow = fT0;
    gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, gaGlideSpriteVertices_0087EFF8, sizeof(D2GlideSpriteVertexStrc));
    gpfGlideAlphaFunction_0087EAB4(2);
}

// 0x0050ABF0
static void sub_0050ABF0_GlideSetBlendMode(int nMode)
{
    switch (nMode)
    {
    case 5:
    case 7:
        sub_00509500_GlideSetCombine(1);
        break;

    case 3:
        sub_00509500_GlideSetCombine(2);
        gpfGlideConstantColor_0087EFA0(0xFF);
        gpfGlideAlphaFunction_0087EAB4(0);
        break;

    case 4:
        sub_00509500_GlideSetCombine(3);
        gpfGlideConstantColor_0087EFA0(0xFF);
        gpfGlideAlphaFunction_0087EAB4(0);
        break;

    default:
        sub_00509500_GlideSetCombine(4);
        gpfGlideAlphaFunction_0087EAB4(0);
        if (nMode == 0)
            gpfGlideConstantColor_0087EFA0(0x40);
        else if (nMode == 1)
            gpfGlideConstantColor_0087EFA0(0x80);
        else if (nMode == 2)
            gpfGlideConstantColor_0087EFA0(0xC0);
        break;
    }
}

int __fastcall sub_0050B0D0_GlideDrawSprite(D2CelContextStrc* pContext, int nX, int nY, unsigned int dwColor, int nMode, int nPalette)
{
    D2GlideTexInfoStrc tInfo;
    if (!sub_0050A260_GlideTexInfoInit(pContext, &tInfo))
        return 0;

    const int nLeft = nX + tInfo.nOffsetX;
    if (nLeft > gnScreenWidth_007C9138)
        return 0;
    if (nLeft + tInfo.nWidth < 0)
        return 0;
    const int nBottom = nY + tInfo.nOffsetY;
    if (nBottom < 0)
        return 0;
    if (nBottom - tInfo.nHeight >= gnScreenHeight_007C913C)
        return 0;

    sub_0050A2D0_GlideTexInfoSetupSize(&tInfo);
    if (nMode == 7)
    {
        if (!sub_0050A450_GlideTexInfoUpload(nPalette, 0, &tInfo, 2))
            return 1;
    }
    else if (!sub_0050A450_GlideTexInfoUpload(nPalette, 0, &tInfo, 1))
    {
        return 1;
    }

    sub_0050ABF0_GlideSetBlendMode(nMode);
    sub_0050A9A0_GlideDrawSpriteQuad(nX, nY, dwColor, 0, &tInfo, 0);
    return 1;
}

// build: context sub_0050B190_GlideDrawSpritePalette
int __fastcall sub_0050B190_GlideDrawSpritePalette(D2CelContextStrc* pContext, int nX, int nY, unsigned int dwColor, int nMode, int nPaletteIndex)
{
    D2GlideTexInfoStrc tInfo;
    if (!sub_0050A260_GlideTexInfoInit(pContext, &tInfo))
        return 0;

    const int nLeft = nX + tInfo.nOffsetX;
    if (nLeft > gnScreenWidth_007C9138)
        return 0;
    if (nLeft + tInfo.nWidth < 0)
        return 0;
    const int nBottom = nY + tInfo.nOffsetY;
    if (nBottom < 0)
        return 0;
    if (nBottom - tInfo.nHeight >= gnScreenHeight_007C913C)
        return 0;

    sub_0050A2D0_GlideTexInfoSetupSize(&tInfo);
    if (sub_0050A450_GlideTexInfoUpload(0, 0, &tInfo, 1))
    {
        sub_0050ABF0_GlideSetBlendMode(nMode);
        sub_0050A9A0_GlideDrawSpriteQuad(nX, nY, dwColor, 0, &tInfo, nPaletteIndex);
    }
    return 1;
}

void __fastcall sub_0050B230_GlideDrawSpriteRows(D2CelContextStrc* pContext, int nX, int nY, unsigned int nSkip, unsigned int nRows, int nMode)
{
    sub_0050ABF0_GlideSetBlendMode(nMode);

    D2GlideTexInfoStrc tInfo;
    if (!sub_0050A260_GlideTexInfoInit(pContext, &tInfo))
        return;

    sub_0050A2D0_GlideTexInfoSetupSize(&tInfo);
    if (!sub_0050A450_GlideTexInfoUpload(0, 0, &tInfo, 1))
        return;

    const float fScale = 1.0f / tInfo.f_18;
    if (!sub_0050DD30_GlideIsPerspective())
    {
        if (nSkip)
        {
            nY -= nSkip;
            tInfo.fT0 += (tInfo.nHeight - nSkip - nRows) * fScale;
            tInfo.fT1 -= nSkip * fScale;
        }
        else
        {
            tInfo.fT0 += (tInfo.nHeight - nRows) * fScale;
        }
        tInfo.nHeight = nRows;
    }
    else
    {
        if (nSkip)
        {
            nY -= nSkip;
            const unsigned int nRest = tInfo.f_18 - nSkip;
            tInfo.fT0 = (nRest - nRows) * fScale;
            tInfo.fT1 = nRest * fScale;
        }
        else
        {
            tInfo.fT0 = (tInfo.f_18 - nRows) * fScale;
        }
        tInfo.f_18 = nRows;
    }

    sub_0050A9A0_GlideDrawSpriteQuad(nX, nY, -1, 0, &tInfo, 0);
}

// build: context sub_0050B690_GlideDrawIsoSprite
void __fastcall sub_0050B690_GlideDrawIsoSprite(D2CelContextStrc* pContext, int nX, int nY)
{
    D2GlideTexInfoStrc tInfo;
    if (!sub_0050A260_GlideTexInfoInit(pContext, &tInfo))
        return;

    sub_0050A2D0_GlideTexInfoSetupSize(&tInfo);
    if (!sub_0050A450_GlideTexInfoUpload(0, 0, &tInfo, 4))
        return;

    sub_005094B0_GlideSetState(1);
    if (sub_0050BF40_GlideGetBlendedShadows())
    {
        sub_00509500_GlideSetCombine(4);
        gpfGlideConstantColor_0087EFA0(0xC0);
    }
    else
    {
        sub_00509500_GlideSetCombine(1);
    }
    sub_005095D0_GlideSetDepth(1);
    sub_0050A7B0_GlideDrawIsoQuad(nX, nY, &tInfo);
}

void __fastcall sub_0050B720_GlideDrawSpriteOutline(D2CelContextStrc* pContext, int nX, int nY, int nColor)
{
    sub_00509500_GlideSetCombine(4);
    gpfGlideAlphaFunction_0087EAB4(0);
    gpfGlideConstantColor_0087EFA0(0x40);

    D2GlideTexInfoStrc tInfo;
    if (!sub_0050A260_GlideTexInfoInit(pContext, &tInfo))
        return;

    tInfo.nWidth += 2;
    tInfo.nHeight += 2;
    sub_0050A2D0_GlideTexInfoSetupSize(&tInfo);
    if (!sub_0050A450_GlideTexInfoUpload(0, nColor, &tInfo, 3))
        return;

    sub_0050A9A0_GlideDrawSpriteQuad(nX - 1, nY + 1, -1, 1, &tInfo, 0);
}

// 0x004095D0
void __cdecl sub_004095D0_Nop()
{
}

// 0x00409C70
void __cdecl sub_00409C70_Nop()
{
}

// 0x0047B4D0
void __cdecl sub_0047B4D0_Nop()
{
}

// 0x004BF9C0
void __cdecl sub_004BF9C0_Nop()
{
}

// 0x0050B7A0
void __cdecl sub_0050B7A0_Nop()
{
}
