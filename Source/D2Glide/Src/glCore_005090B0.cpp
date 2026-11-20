#include "D2Glide.h"
#include "D2GfxTypes.h"

struct D2TileLibraryEntryStrc;

struct tagPOINT
{
    long x;
    long y;
};

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020
void __fastcall sub_005094B0_GlideSetState(int nState);                                                      // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode);                                                     // 0x00509500
void __fastcall sub_005095D0_GlideSetDepth(int nMode);                                                       // 0x005095D0
int __fastcall sub_00509E90_GlideOpenWindow(void* hWnd, int nResolution); // 0x00509E90
int __cdecl sub_0050BF40_GlideGetBlendedShadows();                                                                    // 0x0050BF40
void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50
void __fastcall sub_0050C270_GlideDrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha); // 0x0050C270
int __fastcall sub_0050C890_GlideTileDrawShaded(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, unsigned char nShade, int nScreenPanels); // 0x0050C890
int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels); // 0x0050CA00
int __cdecl sub_0050DD30_GlideIsPerspective();                                                               // 0x0050DD30
void __fastcall sub_0050FDF0_GlidePlaySmacker(const char* szFile, int nResolutionMode, void* pfFrame);      // 0x0050FDF0
void __fastcall sub_005103B0_DDrawLogError(const char* szWhere, int hResult); // 0x005103B0
void __fastcall sub_00512D90_DDrawUtilFilledRect(tagRECT* pRect, unsigned char nColor);                     // 0x00512D90
void __fastcall sub_005137E0_DDrawPlaySmacker(const char* szFile, int nResolutionMode, void* pfFrame);      // 0x005137E0
void __fastcall sub_006BE190_BuildGammaTable(int gamma,void* table,double scale,int entrySize,int entries,int mask); // 0x006BE190

extern const double gdGlideGammaScale_006CD038;                                                             // 0x006CD038
extern T004F51E0 gaDDrawPalette_007C8CC8[256];                                                     // 0x007C8CC8
int gnScreenWidth_007C9138;                                                                                 // 0x007C9138
int gbRenderPaused_007C9144;                                                                                // 0x007C9144
extern D2GfxSettingsStrc* gpGfxSettings_007C9148;                                                           // 0x007C9148
extern void (__stdcall* gpfGlideGammaCorrectionRGB_0087EABC)(float fRed, float fGreen, float fBlue);       // 0x0087EABC
extern void (__stdcall* gpfGlideLoadGammaTable_0087EAE0)(int nEntries, unsigned int* pRed, unsigned int* pGreen, unsigned int* pBlue); // 0x0087EAE0
extern int (__stdcall* gpfGlideGet_0087EB1C)(int nName, int nSize, int* pParams);                          // 0x0087EB1C
extern void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88
extern void (__stdcall* gpfGlideBufferSwap_0087EB90)(int nSwapInterval);                                   // 0x0087EB90
extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor);                              // 0x0087EFA0
int gbGlidePlayingVideo_0087EFD0;                                                                           // 0x0087EFD0
int gnGlideGammaTableSize_0087EFD4;                                                                         // 0x0087EFD4
int gbDDrawPlayingVideo_0088126C;                                                                           // 0x0088126C
D2DDrawSurfaceStrc* gpDDrawBackSurface_0088127C;                                                            // 0x0088127C

// 0x005090B0
void __fastcall sub_005090B0_GlideSetGamma(int nGamma)
{
    if (gnGlideGammaTableSize_0087EFD4 > 0)
    {
        int nEntries;
        int nBits;
        if (!gpfGlideGet_0087EB1C(5, 4, &nEntries))
        {
            return;
        }

        if (!gpfGlideGet_0087EB1C(0x2A, 4, &nBits))
        {
            return;
        }

        unsigned int* pTable = (unsigned int*)SMemAlloc(nEntries * 4, ".\\Src\\glCore.cpp", 0x42F, 0);
        sub_006BE190_BuildGammaTable(nGamma, pTable, gnGlideGammaTableSize_0087EFD4, 4, nEntries, (1 << nBits) - 1);
        gpfGlideLoadGammaTable_0087EAE0(nEntries, pTable, pTable, pTable);
        SMemFree(pTable, ".\\Src\\glCore.cpp", 0x43A, 0);
    }
    else
    {
        const float fGamma = nGamma / gdGlideGammaScale_006CD038;
        gpfGlideGammaCorrectionRGB_0087EABC(fGamma, fGamma, fGamma);
    }
}

// 0x00509210
int __fastcall sub_00509210_GlideGetBackBuffer(unsigned char* pBuffer)
{
    D2GrLfbInfoStrc tInfo;
    tInfo.size = sizeof(tInfo);
    if (!gpfGlideLfbLock_0087EADC(0, 1, 0xFF, 0, 0, &tInfo))
    {
        return 0;
    }

    unsigned char* pDstRow = pBuffer;
    unsigned short* pSrcRow = (unsigned short*)tInfo.lfbPtr;
    for (int y = 0; y < gnScreenHeight_007C913C; ++y)
    {
        unsigned short* pSrc = pSrcRow;
        unsigned char* pDst = pDstRow;
        for (int x = 0; x < gnScreenWidth_007C9138; ++x)
        {
            const unsigned short nPixel = *pSrc;
            const unsigned char nRed = nPixel >> 11;
            const unsigned char nGreen = nPixel >> 5;
            const unsigned char nBlue = (unsigned char)nPixel;
            *pDst = nRed << 3;
            ++pDst;
            *pDst = nGreen << 2;
            ++pDst;
            *pDst = nBlue << 3;
            ++pSrc;
            ++pDst;
        }

        pDstRow += 3 * gnScreenWidth_007C9138;
        pSrcRow = (unsigned short*)((unsigned char*)pSrcRow + tInfo.strideInBytes);
    }

    gpfGlideLfbUnlock_0087EAD8(0, 1);
    return 1;
}

// 0x00509B60
void __fastcall sub_00509B60_GlideOpenSmackCutscene(const char* szFile, int nResolutionMode, void* pfFrame)
{
    if (!gbRenderPaused_007C9144)
    {
        gpfGlideBufferClear_0087EB88(0, 0, 0);
        if (gpGfxSettings_007C9148->bVSync)
        {
            gpfGlideBufferSwap_0087EB90(1);
        }
        else
        {
            gpfGlideBufferSwap_0087EB90(0);
        }

        gbGlidePlayingVideo_0087EFD0 = 1;
        sub_0050FDF0_GlidePlaySmacker(szFile, nResolutionMode, pfFrame);
        gbGlidePlayingVideo_0087EFD0 = 0;
    }
}

// 0x00509EE0
void __fastcall sub_00509EE0_GlidePauseSurface(void* hWnd, int nResolutionMode, int nWindowState)
{
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x3A3);

    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    if (nWindowState)
    {
        sub_00509AA0_GlideSuspend();
        gbRenderPaused_007C9144 = 1;
    }
    else
    {
        sub_00509E90_GlideOpenWindow(hWnd, nResolutionMode);
        gbRenderPaused_007C9144 = 0;
    }
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
}

// 0x0050C3A0
void __fastcall sub_0050C3A0_GlideUtilDiamond(tagRECT* pRect, int nPaletteIndex)
{
    const int nX = pRect->left;
    const int nRight = pRect->right;
    D2_ASSERT(nX <= nRight, 0xB9);

    const int nY = pRect->top;
    const int nBottom = pRect->bottom;
    D2_ASSERT(nY <= nBottom, 0xBA);

    const unsigned int nWidth = nRight - nX;
    const unsigned int nHeight = nBottom - nY;
    if (!nWidth || !nHeight)
    {
        return;
    }

    const int nCenterX = nX + (nWidth >> 1);
    const int nCenterY = nY + (nHeight >> 1);
    const int nX2 = nX + nWidth;
    const int nY2 = nY + nHeight;
    if (nX2 < 0 || nX > gnScreenWidth_007C9138 || nY2 < 0 || nY > gnScreenHeight_007C913C)
    {
        return;
    }

    sub_0050C270_GlideDrawLine(nCenterX, nY, nX2, nCenterY, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nCenterY, nCenterX, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nCenterX, nY2, nX, nCenterY, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX, nCenterY, nCenterX, nY, nPaletteIndex, 0xFF);
}

// 0x0050C490
void __fastcall sub_0050C490_GlideUtilRect(tagRECT* pRect, int nPaletteIndex)
{
    D2_ASSERT(pRect->left <= pRect->right, 0xDF);
    D2_ASSERT(pRect->top <= pRect->bottom, 0xE0);

    const int nX1 = D2_MIN(D2_MAX(pRect->left, 0), gnScreenWidth_007C9138 - 1);
    const int nX2 = D2_MIN(D2_MAX(pRect->right, 0), gnScreenWidth_007C9138 - 1);
    if (nX1 == nX2)
    {
        return;
    }

    const int nY1 = D2_MIN(D2_MAX(pRect->top, 0), gnScreenHeight_007C913C - 1);
    const int nY2 = D2_MIN(D2_MAX(pRect->bottom, 0), gnScreenHeight_007C913C - 1);
    if (nY1 == nY2)
    {
        return;
    }

    D2_ASSERT(nY2 > nY1, 0xF0);

    sub_0050C270_GlideDrawLine(nX1, nY1, nX2, nY1, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nY1, nX2, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nY2, nX1, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX1, nY2, nX1, nY1, nPaletteIndex, 0xFF);
}

// 0x0050C630
void __fastcall sub_0050C630_GlideUtilPoint(tagPOINT* pPoint, unsigned char nSize, int nPaletteIndex)
{
    if (nSize)
    {
        --nSize;
        tagRECT tRect;
        SetRect(&tRect, pPoint->x - nSize, pPoint->y - nSize, pPoint->x + nSize + 1, pPoint->y + nSize + 1);
        sub_0050BF50_GlideDrawBox(tRect.left, tRect.top, tRect.right, tRect.bottom, nPaletteIndex, 5);
    }
}

// 0x0050CD40
int __fastcall sub_0050CD40_GlideShadowTileDraw(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels)
{
    int nResult = 0;
    if (sub_005FDEA0(pTile, 1, 0))
    {
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
        if (sub_0050DD30_GlideIsPerspective())
        {
            nResult = sub_0050CA00_GlideShadowTileDrawPerspective(pTile, nPosX, nPosY, eDrawMode, nScreenPanels);
        }
        else
        {
            nResult = sub_0050C890_GlideTileDrawShaded(pTile, nPosX, nPosY, eDrawMode, nScreenPanels);
        }
    }

    return nResult;
}

// 0x00511660
void __fastcall sub_00511660_DDrawOpenSmackCutscene(const char* szFile, int nResolutionMode, void* pfFrame)
{
    if (!gbRenderPaused_007C9144)
    {
        gbDDrawPlayingVideo_0088126C = 1;
        D2DDBltFxStrc tBltFx = { sizeof(tBltFx) };
        tBltFx.dwFillColor = 0;
        D2_ASSERT(gpDDrawSurface_00881278, 0x387);

        const long hResult = gpDDrawSurface_00881278->lpVtbl->Blt(gpDDrawSurface_00881278, 0, 0, 0, 0x400, &tBltFx);
        if (hResult)
        {
            sub_005103B0_DDrawLogError("Cutscene clearing blit failed!", hResult);
            return;
        }

        sub_005137E0_DDrawPlaySmacker(szFile, nResolutionMode, pfFrame);
        gbDDrawPlayingVideo_0088126C = 0;
    }
}

// 0x00511970
int __fastcall sub_00511970_DDrawGetBackBuffer(unsigned char* pBuffer)
{
    D2DDSurfaceDescStrc tDesc = { sizeof(tDesc) };
    if (!gpDDrawBackSurface_0088127C)
    {
        return 0;
    }

    long hResult = gpDDrawBackSurface_0088127C->lpVtbl->Lock(gpDDrawBackSurface_0088127C, 0, &tDesc, 0x11, 0);
    if (hResult)
    {
        sub_005103B0_DDrawLogError("Lock failed!", hResult);
        return 0;
    }

    unsigned char* pDstRow = pBuffer;
    unsigned char* pSrcRow = (unsigned char*)tDesc.lpSurface;
    for (int y = 0; y < gnScreenHeight_007C913C; ++y)
    {
        unsigned char* pSrc = pSrcRow;
        unsigned char* pDst = pDstRow;
        for (int x = 0; x < gnScreenWidth_007C9138; ++x)
        {
            const T004F51E0* pEntry = &gaDDrawPalette_007C8CC8[*pSrc];
            *pDst = pEntry->peRed;
            ++pDst;
            *pDst = pEntry->peGreen;
            ++pDst;
            *pDst = pEntry->peBlue;
            ++pSrc;
            ++pDst;
        }

        pDstRow += 3 * gnScreenWidth_007C9138;
        pSrcRow += tDesc.lPitch;
    }

    hResult = gpDDrawBackSurface_0088127C->lpVtbl->Unlock(gpDDrawBackSurface_0088127C, 0);
    if (hResult)
    {
        sub_005103B0_DDrawLogError("Unlock failed!", hResult);
        return 0;
    }

    return 1;
}

// 0x00512E80
void __fastcall sub_00512E80_DDrawUtilPoint(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex)
{
    if (nSize)
    {
        --nSize;
        tagRECT tRect;
        SetRect(&tRect, pPoint->x - nSize, pPoint->y - nSize, pPoint->x + nSize + 1, pPoint->y + nSize + 1);
        sub_00512D90_DDrawUtilFilledRect(&tRect, nPaletteIndex);
    }
}
