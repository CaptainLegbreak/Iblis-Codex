#include "D2Glide.h"
struct D2GlideTexInfoStrc;
struct D2GlideTexSlotStrc;
struct D2GlideTexCacheEntryStrc;
struct D2GlideTexCacheStrc;
struct D2GrTexInfoExStrc;
struct D2GlideTexDimsStrc;
struct D2BoundsStrc;
struct D2ClipStrc;

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

typedef void (__stdcall* gpfGlideTexDownloadMipMap_0087EAB8_t)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoExStrc* pInfo);

extern gpfGlideTexDownloadMipMap_0087EAB8_t gpfGlideTexDownloadMipMap_0087EAB8; // 0x0087EAB8

typedef void (__stdcall* gpfGlideTexSource_0087EB98_t)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoExStrc* pInfo);

extern gpfGlideTexSource_0087EB98_t gpfGlideTexSource_0087EB98; // 0x0087EB98

typedef void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4_t)(int nMode, int nCount, void* pVertices, int nStride);

extern gpfGlideDrawVertexArrayContiguous_0087EAC4_t gpfGlideDrawVertexArrayContiguous_0087EAC4; // 0x0087EAC4

typedef void (__stdcall* gpfGlideAlphaFunction_0087EAB4_t)(int nFunction);

extern gpfGlideAlphaFunction_0087EAB4_t gpfGlideAlphaFunction_0087EAB4; // 0x0087EAB4

typedef void (__stdcall* gpfGlideConstantColor_0087EFA0_t)(unsigned int dwColor);

extern gpfGlideConstantColor_0087EFA0_t gpfGlideConstantColor_0087EFA0; // 0x0087EFA0
extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gbGlideSpriteFlag_0087EFF0; // 0x0087EFF0
extern int gbGlideMultiTmu_0087EFF4; // 0x0087EFF4
extern D2GlideSpriteVertexStrc gaGlideSpriteVertices_0087EFF8[4]; // 0x0087EFF8
extern D2GlideTexCacheStrc gaGlideTexCaches_0087F048[4]; // 0x0087F048
extern unsigned char* gpGlideSpriteBufferA_0087F0C8; // 0x0087F0C8
extern unsigned char* gpGlideSpriteBufferB_0087F0CC; // 0x0087F0CC
extern int gnGlideSpriteScale_00880B64; // 0x00880B64
extern D2GlideTexDimsStrc gaGlideAspectTexDims_0072F278[7]; // 0x0072F278
void __stdcall sub_0050A9A0_GlideDrawSpriteQuad(int nX, int nY, unsigned int dwColor, int bTinted, D2GlideTexInfoStrc* pInfo, int nPaletteIndex);
void sub_0050ABF0_GlideSetBlendMode(int nMode);
static __declspec(noinline) int __stdcall sub_0050B390_ClipSprite(D2GlideTexInfoStrc* pInfo, int nY, const D2BoundsStrc* pBounds, int nX, D2ClipStrc* pClip);

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

// 0x0050A2D0
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
        pInfo->fT0 = 1.0f - (float)pInfo->nHeight / pInfo->f_18;
        pInfo->fT1 = 1.0f;
    }
    else
    {
        pInfo->fS0 = 0.0f;
        pInfo->fS1 = 1.0f;
        pInfo->fT0 = 0.0f;
        pInfo->fT1 = 1.0f;
    }
    pInfo->nTexSize = pInfo->f_18 * pInfo->f_14;
}

// 0x0050A450
static int __stdcall sub_0050A450_GlideTexInfoUpload(int nPalette, int nColor, int nType, D2GlideTexInfoStrc* pInfo)
{
    D2CelStrc* pCell = pInfo->pContext->f_3C;
    D2_ASSERT(pCell, 0x12D);

    D2GlideTexSlotStrc* pSlots = (D2GlideTexSlotStrc*)sub_00601B10_GetCelPixels(pCell);
    const int nRequested = nType;
    if (nType == 4)
        nType = 1;

    D2GrTexInfoExStrc tTexInfo;
    tTexInfo.nSmallLodLog2 = tTexInfo.nLargeLodLog2 = pInfo->nLod;
    tTexInfo.nAspectRatioLog2 = pInfo->f_34;
    tTexInfo.nFormat = 5;
    tTexInfo.pData = gpGlideSpriteBufferA_0087F0C8;

    D2GlideTexSlotStrc* pSlot = &pSlots[nType];
    if (!pSlot->nCache)
    {
        if (pInfo->nTexSize <= 0x1000)
            pSlot->nCache = 3;
        else if (pInfo->nTexSize <= 0x4000)
            pSlot->nCache = 2;
        else if (pInfo->nTexSize <= 0x10000)
            pSlot->nCache = 1;
        else
            return 0;
    }

    const int nCache = pSlot->nCache;
    D2GlideTexCacheStrc* pCache = &gaGlideTexCaches_0087F048[nCache];
    if (gbGlideSpriteFlag_0087EFF0)
        gbGlideMultiTmu_0087EFF4 = nCache == 1;

    int nAddress;
    if (pSlots[nType].nId && (pCache->pEntries[pSlots[nType].nId - 1].f_10 == nPalette || nRequested == 4))
    {
        sub_0050EBE0_TexCacheTouch(&gaGlideTexCaches_0087F048[nCache], pSlot->nId);
        nAddress = pCache->pEntries[pSlot->nId - 1].f_4;
    }
    else
    {
        if (!pSlot->nId)
            pSlot->nId = sub_0050ED10_ListRefill(pCache);

        pCache->pEntries[pSlot->nId - 1].pOwner = pSlots;
        pCache->pEntries[pSlot->nId - 1].nOwnerIndex = nType;
        pCache->pEntries[pSlot->nId - 1].f_10 = nPalette;
        nAddress = pCache->pEntries[pSlot->nId - 1].f_4;

        unsigned char* pBuffer = gpGlideSpriteBufferA_0087F0C8;
        D2_ASSERT(pBuffer, 0x184);
        D2_ASSERT(pInfo->nTexSize <= 0x10000, 0x185);
        memset(pBuffer, 0, pInfo->nTexSize);

        switch (nType)
        {
        case 1:
        case 4:
            CelDraw(pInfo->pContext, -pInfo->nOffsetX, pInfo->f_18 - pInfo->nOffsetY - 1, 0, 0, pBuffer, pInfo->f_18, pInfo->f_14, 0, 0, nPalette);
            break;

        case 2:
        {
            CelDraw(pInfo->pContext, -pInfo->nOffsetX, pInfo->f_18 - pInfo->nOffsetY - 1, 0, 0, pBuffer, pInfo->f_18, pInfo->f_14, 0, 0, nPalette);
            unsigned char* pPixel = gpGlideSpriteBufferA_0087F0C8;
            unsigned char* pRemap = gpGfxPaletteView_007C9150->f_118;
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
            CelDraw(pInfo->pContext, 1 - pInfo->nOffsetX, pInfo->f_18 - pInfo->nOffsetY - 2, 0, 0, pBuffer, pInfo->f_18, pInfo->f_14, 0, 0, 0);
            unsigned char* pOutline = gpGlideSpriteBufferB_0087F0CC;
            D2_ASSERT(pOutline, 0x1AD);
            D2_ASSERT(pInfo->nTexSize <= 0x10000, 0x1AE);
            memset(pOutline, 0, pInfo->nTexSize);

            unsigned char* pSrc = gpGlideSpriteBufferA_0087F0C8 + pInfo->f_14;
            unsigned char* pDst = pOutline + pInfo->f_14;
            const int nPitch = pInfo->f_14;
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
        if (!sub_0050A450_GlideTexInfoUpload(nPalette, 0, 2, &tInfo))
            return 1;
    }
    else if (!sub_0050A450_GlideTexInfoUpload(nPalette, 0, 1, &tInfo))
    {
        return 1;
    }

    sub_0050ABF0_GlideSetBlendMode(nMode);
    sub_0050A9A0_GlideDrawSpriteQuad(nX, nY, dwColor, 0, &tInfo, 0);
    return 1;
}

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
    if (sub_0050A450_GlideTexInfoUpload(0, 0, 1, &tInfo))
    {
        sub_0050ABF0_GlideSetBlendMode(nMode);
        sub_0050A9A0_GlideDrawSpriteQuad(nX, nY, dwColor, 0, &tInfo, nPaletteIndex);
    }
    return 1;
}

// 0x0050B390
static int __stdcall sub_0050B390_ClipSprite(D2GlideTexInfoStrc* pInfo, int nY, const D2BoundsStrc* pBounds, int nX, D2ClipStrc* pClip)
{
    nX += pInfo->nOffsetX;
    int nWidth = pInfo->nWidth;
    int nHeight = pInfo->nHeight;
    nY += pInfo->nOffsetY;

    pClip->nLeft = 0;
    pClip->nWidth = nWidth;
    pClip->nTop = 0;
    pClip->nHeight = nHeight;

    int nLeft = pBounds->nLeft > 0 ? pBounds->nLeft : 0;
    int nRight = pBounds->nRight < gnScreenWidth_007C9138 ? pBounds->nRight : gnScreenWidth_007C9138;
    if (nLeft > nRight || nX >= nRight || nX + nWidth < nLeft)
    {
        return 1;
    }

    int nTop = pBounds->nTop + 2 > 0 ? pBounds->nTop + 2 : 0;
    int nBottom = pBounds->nBottom < gnScreenHeight_007C913C ? pBounds->nBottom : gnScreenHeight_007C913C;
    if (nTop > nBottom || nY < nTop || nY - nHeight > nBottom)
    {
        return 1;
    }

    if (nX >= nLeft)
        pClip->nLeft = 0;
    else
        pClip->nLeft = nLeft - nX;

    if (nX + nWidth < nRight)
        pClip->nWidth = nWidth - pClip->nLeft;
    else
        pClip->nWidth = nRight - pClip->nLeft - nX;

    if (nY <= nBottom)
        pClip->nTop = 0;
    else
        pClip->nTop = nY - nBottom - 1;

    if (nY - nHeight >= nTop)
        pClip->nHeight = nHeight - pClip->nTop;
    else
        pClip->nHeight = nY - pClip->nTop - nTop + 1;

    if (pClip->nHeight <= 0)
    {
        sub_00408A60(gszEmpty_006CC837, sub_00408090(), 1060);
        exit(-1);
    }
    return 0;
}

int __fastcall Harness_ClipSprite(D2GlideTexInfoStrc* pInfo, int nX, int nY, const D2BoundsStrc* pBounds)
{
    D2ClipStrc tClip;
    if (sub_0050B390_ClipSprite(pInfo, nY, pBounds, nX, &tClip))
    {
        return 0;
    }
    return tClip.nLeft + tClip.nWidth + tClip.nTop + tClip.nHeight;
}
