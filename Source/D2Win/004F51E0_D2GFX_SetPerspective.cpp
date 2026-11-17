struct tagRECT;
struct tagPOINT;
struct D2PaletteTableStrc;

struct T004F51E0
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nFlags;
};

struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
    int bLowQuality;
    int nGamma;
    int bVSync;
    int bBlendedShadows;
};

struct D2GraphicsInterfaceStrc
{
    int (__fastcall* pfDetect)(void* hInstance);
    int (__fastcall* pfInit)(D2GfxSettingsStrc* pSettings, const void* pHelpers);
    int (__fastcall* pfClose)();
    int (__fastcall* pfCreateSurface)(void* hWnd, int nResolutionMode);
    int (__fastcall* pfCloseSurface)();
    void (__fastcall* pfPauseSurface)(void* hWnd, int nResolutionMode, int nWindowState);
    int (__fastcall* pfStartDraw)(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue);
    int (__fastcall* pfEndDraw)();
    int (__fastcall* pfBlit)();
    int (__fastcall* pfChangeRes)(void* hWnd, int nResolutionMode);
    int (__fastcall* pfGetBackBuffer)(unsigned char* pBuffer);
    int (__fastcall* pfActivateWindow)(int bActive, int bWindowed);
    int (__fastcall* pfSetOption)(int nOption, int nValue);
    int (__fastcall* pfPlayCutscene)();
    void (__fastcall* pfOpenSmackCutscene)(const char* szFile, int nResolutionMode, void* pfFrame);
    int (__fastcall* pfCheckCutScene)();
    void (__fastcall* pfDecodeSmacker)(const char* szSmacker, unsigned char* pBuffer, int nVersion);
    void (__fastcall* pfPlaySmacker)(void* pContext);
    void (__fastcall* pfCloseSmacker)(void* pContext);
    void* (__fastcall* pfGetCacheResults)();
    int (__fastcall* pfGetDimensions)(int* pWidth, int* pHeight);
    void (__fastcall* pfSetGlobalScale)(int nScaleFactor);
    int (__fastcall* pfSetGamma)(int nGamma);
    int (__fastcall* pfGammaCanBeControlled)();
    void (__fastcall* pfUpdatePerspective)(int nScaleX, int nScaleY);
    void (__fastcall* pfPerspectiveTransform)(int nPosX, int nPosY, int nBias, int* pXAdjust, int* pYAdjust);
    void (__fastcall* pfPerspectiveTransformScale)(int nPosX, int nPosY, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder);
    void (__fastcall* pfPerspectiveClearScale)();
    void (__fastcall* pfSetPalette)(T004F51E0* pPalette);
    void (__fastcall* pfSetPaletteTables)(D2PaletteTableStrc* pPaletteTables);
    void (__fastcall* pfSetAmbientColor)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);
    void* pfFloorTileDraw;
    void* pfCelFlatSpriteDraw;
    void* pfCelDraw;
    void* pfCelDrawColor;
    void* pfCelDrawEx;
    void* pfCelDrawShadow;
    void* pfCelDrawHilight;
    void* pfCelDrawClipped;
    void* pfTileDrawLit;
    void* pfTileDrawTrans;
    void* pfShadowTileDraw;
    void (__fastcall* pfUtilDiamond)(tagRECT* pRect, unsigned char nPaletteIndex);
    void (__fastcall* pfUtilRect)(tagRECT* pRect, unsigned char nPaletteIndex);
    void (__fastcall* pfUtilFilledRect)(tagRECT* pRect, unsigned char nPaletteIndex);
    void (__fastcall* pfUtilPoint)(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex);
    void* pfDrawBox;
    void* pfDrawBoxAlpha;
    void* pfDrawLine;
    void (__fastcall* pfClearScreen)(int bPartial);
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
void __cdecl sub_004F5510_HideCursor();                                                                     // 0x004F5510
void __cdecl sub_004F5540_ShowCursor();                                                                     // 0x004F5540
double __cdecl sub_004F6130_GetElapsedMs();                                                                 // 0x004F6130
void __fastcall sub_004F8E40_CopyPaletteTables(D2PaletteTableStrc* pPaletteTables);                        // 0x004F8E40

extern D2GfxSettingsStrc gGfxSettings;                                                                      // 0x0072DA48
extern int gnDisplayType;                                                                                   // 0x007C8CB0
extern int gbIsWindowed;                                                                                    // 0x007C8CB4
D2GraphicsInterfaceStrc* gpGraphicsInterface;                                                               // 0x007C8CC0
extern int gbPaused_6FA8D84C;                                                                               // 0x007C933C
double gdFrameRemainder_007C9360;                                                                           // 0x007C9360
T004F51E0 gpPalette_6FA8D278[256];                                                                 // 0x007C9378

// build: symbol ?$S1@?1??D2GFX_EndScene@@YGHXZ@4IA 0x007C9370
// build: symbol ?sdLastFrame@?1??D2GFX_EndScene@@YGHXZ@4NA 0x007C9368
// 0x004F51E0
void __stdcall D2GFX_SetPerspective(int bPerspective)
{
    gGfxSettings.bPerspectiveEnabled = bPerspective;
}

// 0x004F5200
void __stdcall D2GFX_SetBlendShadows(int bBlendedShadows)
{
    gGfxSettings.bBlendedShadows = bBlendedShadows;
}

// 0x004F5220
void __stdcall D2GFX_SetLowQuality(int bLowQuality)
{
    gGfxSettings.bLowQuality = bLowQuality;
}

// 0x004F5230
int __stdcall D2GFX_SetGamma(int nGamma)
{
    if (nGamma)
    {
        gGfxSettings.nGamma = nGamma;
    }

    return gpGraphicsInterface->pfSetGamma(gGfxSettings.nGamma);
}

// 0x004F5570
void __stdcall sub_004F5570_GetResolutionSize(int nResolution, int* pWidth, int* pHeight)
{
    switch (nResolution)
    {
    case 0:
        *pWidth = 640;
        *pHeight = 480;
        break;

    case 1:
    case 2:
        *pWidth = 800;
        *pHeight = 600;
        break;

    case 3:
        *pWidth = 1344;
        *pHeight = 700;
        break;

    default:
        *pWidth = 0;
        *pHeight = 0;
        D2_ASSERT(0, 109);
    }
}

// 0x004F5990
void __stdcall WINDOW_SetPaused(int bPaused)
{
    gbPaused_6FA8D84C = bPaused;
}

// 0x004F59B0
int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight)
{
    D2_ASSERT(gpGraphicsInterface, 423);

    return gpGraphicsInterface->pfGetDimensions(pWidth, pHeight);
}

// 0x004F59F0
void __stdcall WINDOW_ShowCursor(int bShow)
{
    if (!gbIsWindowed || gnDisplayType == 4 || gnDisplayType == 5 || gnDisplayType == 6)
    {
        return;
    }

    if (bShow)
    {
        sub_004F5510_HideCursor();
    }
    else
    {
        sub_004F5540_ShowCursor();
    }
}

// 0x004F5A50
int __stdcall WINDOW_Activate(int bActive)
{
    D2_ASSERT(gpGraphicsInterface, 471);

    gbIsWindowed = bActive == 0;
    return gpGraphicsInterface->pfActivateWindow(bActive, gbIsWindowed);
}

// 0x004F5D90
void __stdcall WINDOW_OpenSmackCutscene(const char* szFile, int nResolution, void* pfFrame)
{
    D2_ASSERT(gpGraphicsInterface, 732);

    return gpGraphicsInterface->pfOpenSmackCutscene(szFile, nResolution, pfFrame);
}

// 0x004F5E00
void __stdcall WINDOW_DecodeSmacker(const char* szSmacker, unsigned char* pBuffer, int nVersion)
{
    D2_ASSERT(gpGraphicsInterface, 770);

    return gpGraphicsInterface->pfDecodeSmacker(szSmacker, pBuffer, nVersion);
}

// 0x004F5E40
void __stdcall WINDOW_PlaySmacker(void* pContext)
{
    D2_ASSERT(gpGraphicsInterface, 782);

    return gpGraphicsInterface->pfPlaySmacker(pContext);
}

// 0x004F5E80
void __stdcall WINDOW_CloseSmacker(void* pContext)
{
    D2_ASSERT(gpGraphicsInterface, 794);

    return gpGraphicsInterface->pfCloseSmacker(pContext);
}

// 0x004F60F0
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    return gpGraphicsInterface->pfStartDraw(bClear, nRed, nGreen, nBlue);
}

// 0x004F6190
int __stdcall D2GFX_EndScene()
{
    static double sdLastFrame = sub_004F6130_GetElapsedMs();

    const double dNow = sub_004F6130_GetElapsedMs();
    const double dElapsed = dNow - sdLastFrame;
    if (dElapsed <= 5.0)
    {
        const double dWait = 5.0 - dElapsed + gdFrameRemainder_007C9360;
        const int nWait = (int)dWait;
        const double dWaitWhole = nWait;
        gdFrameRemainder_007C9360 = dWait - dWaitWhole;
        if (nWait > 0)
        {
            if (nWait <= 5)
            {
                Sleep(nWait);
                gdFrameRemainder_007C9360 = gdFrameRemainder_007C9360 - (sub_004F6130_GetElapsedMs() - dNow - dWaitWhole);
            }
            else
            {
                gdFrameRemainder_007C9360 = 0.0;
            }
        }
        else
        {
            gdFrameRemainder_007C9360 = 0.0;
        }
    }

    sdLastFrame = sub_004F6130_GetElapsedMs();
    gpGraphicsInterface->pfEndDraw();
    gpGraphicsInterface->pfBlit();
    return 1;
}

// 0x004F6280
void __stdcall D2GFX_UtilDiamond(tagRECT* pRect, unsigned char nPaletteIndex)
{
    return gpGraphicsInterface->pfUtilDiamond(pRect, nPaletteIndex);
}

// 0x004F62A0
void __stdcall D2GFX_UtilRect(tagRECT* pRect, unsigned char nPaletteIndex)
{
    return gpGraphicsInterface->pfUtilRect(pRect, nPaletteIndex);
}

// 0x004F62C0
void __stdcall D2GFX_UtilFilledRect(tagRECT* pRect, unsigned char nPaletteIndex)
{
    return gpGraphicsInterface->pfUtilFilledRect(pRect, nPaletteIndex);
}

// 0x004F62E0
void __stdcall D2GFX_UtilPoint(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex)
{
    return gpGraphicsInterface->pfUtilPoint(pPoint, nSize, nPaletteIndex);
}

// 0x004F63B0
void __stdcall D2GFX_ClearScreen(int bPartial)
{
    return gpGraphicsInterface->pfClearScreen(bPartial);
}

// 0x004F63D0
void __stdcall D2GFX_SetPalette(T004F51E0* pPalette)
{
    if (pPalette)
    {
        memcpy(gpPalette_6FA8D278, pPalette, sizeof(gpPalette_6FA8D278));
        gpGraphicsInterface->pfSetPalette(pPalette);
    }
    else
    {
        gpGraphicsInterface->pfSetPalette(gpPalette_6FA8D278);
    }
}

// 0x004F6410
void __stdcall D2GFX_SetPaletteTables(D2PaletteTableStrc* pPaletteTables)
{
    gpGraphicsInterface->pfSetPaletteTables(pPaletteTables);
    sub_004F8E40_CopyPaletteTables(pPaletteTables);
}
