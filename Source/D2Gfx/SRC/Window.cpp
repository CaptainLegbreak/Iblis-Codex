#include "D2Gfx.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GraphicsInterfaceStrc;
struct tagPOINT;
struct D2PaletteTableStrc;
struct D2GfxSettingsStrc;
struct T004F51E0;
struct D2PaletteStrc;

struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
    int bLowQuality;
    int nGamma;
    int bVSync;
    int bBlendedShadows;
};

extern D2GfxSettingsStrc gGfxSettings; // 0x0072DA48
extern int gbIsWindowed; // 0x007C8CB4

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

extern D2GraphicsInterfaceStrc* gpGraphicsInterface; // 0x007C8CC0

struct T004F51E0
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nFlags;
};
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
void __cdecl sub_004F5510_HideCursor(); // 0x004F5510
void __cdecl sub_004F5540_ShowCursor(); // 0x004F5540
double __cdecl sub_004F6130_GetElapsedMs(); // 0x004F6130

struct D2PaletteTableStrc
{
    D2PaletteStrc* pPalettes[72];
};

void __fastcall sub_004F8E40_CopyPaletteTables(D2PaletteTableStrc* pPaletteTables); // 0x004F8E40
extern int gbPaused_6FA8D84C; // 0x007C933C

enum DisplayType
{
    DISPLAYTYPE_NONE = 0,
    DISPLAYTYPE_GDI = 1,
    DISPLAYTYPE_SOFTWARE = 2,
    DISPLAYTYPE_DDRAW = 3,
    DISPLAYTYPE_GLIDE = 4,
    DISPLAYTYPE_OPENGL = 5,
    DISPLAYTYPE_DIRECT3D = 6,
    DISPLAYTYPE_RAVE = 7,
};

struct D2PaletteStrc
{
    unsigned char unk0x00[0x100];
};
void __cdecl sub_004F5FA0_UpdatePauseState(); // 0x004F5FA0
extern int gbCursorDisplayed; // 0x0072DB38
extern void* ghWnd; // 0x007C8CBC
extern int gbWindowState_6FA8D850; // 0x007C9340
extern unsigned char gLightCube_007CA320[32][32][32]; // 0x007CA320
extern D2PaletteStrc gLightPalettes_007D2348[49]; // 0x007D2348
extern int gnScreenPitch_007D544C; // 0x007D544C
extern D2PaletteTableStrc* gpPaletteTables_007D5578; // 0x007D5578

// 0x004F51D0
int __stdcall D2GFX_CheckPerspective()
{
    return gGfxSettings.bPerspectiveCapable != 0 ? gGfxSettings.bPerspectiveEnabled : 0;
}

// 0x004F54F0
int __stdcall D2GFX_ToggleLowQuality()
{
    gGfxSettings.bLowQuality = gGfxSettings.bLowQuality == 0;
    return gGfxSettings.bLowQuality;
}

// 0x004F5A30
int __stdcall WINDOW_IsFullScreen()
{
    if (gpGraphicsInterface)
    {
        return gbIsWindowed == 0;
    }

    return 0;
}

D2GraphicsInterfaceStrc* gpGraphicsInterface; // 0x007C8CC0

double gdFrameRemainder_007C9360; // 0x007C9360

T004F51E0 gpPalette_6FA8D278[256]; // 0x007C9378

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

int gnRowOffsets_007C97A8[732]; // 0x007C97A8

D2PaletteTableStrc gPaletteTables_007D5458; // 0x007D5458

// 0x004F5510
void __cdecl sub_004F5510_HideCursor()
{
    if (gbCursorDisplayed)
    {
        while (ShowCursor(0) >= 0);
        gbCursorDisplayed = 0;
    }
}

// 0x004F5540
void __cdecl sub_004F5540_ShowCursor()
{
    if (!gbCursorDisplayed)
    {
        while (ShowCursor(1) < 0);
        gbCursorDisplayed = 1;
    }
}

// 0x004F5900
int __stdcall WINDOW_Destroy()
{
    int bWindowDestroyed = 1;
    D2_ASSERT(gpGraphicsInterface, 0x12C);

    if (!gbCursorDisplayed)
    {
        while (ShowCursor(1) < 0);
        gbCursorDisplayed = 1;
    }

    if (!gpGraphicsInterface->pfCloseSurface())
    {
        bWindowDestroyed = 0;
    }

    if (ghWnd)
    {
        if (!DestroyWindow(ghWnd))
        {
            bWindowDestroyed = 0;
        }
        ghWnd = 0;
    }

    ChangeDisplaySettingsA(0, 0);
    return bWindowDestroyed;
}

// 0x004F5DD0
int __stdcall WINDOW_CheckCutScene()
{
    D2_ASSERT(gpGraphicsInterface, 0x2F6);

    return gpGraphicsInterface->pfCheckCutScene();
}

// 0x004F6070
int __stdcall WINDOW_GetState()
{
    sub_004F5FA0_UpdatePauseState();
    return gbWindowState_6FA8D850;
}

// 0x004F6270
int __stdcall D2GFX_HardwareAcceleratedRenderMode()
{
    return gnDisplayType >= DISPLAYTYPE_GLIDE;
}

// 0x004F6830
void __stdcall SCALE_SetDefaultFactorPerspectiveFactor()
{
    D2_ASSERT(gnDisplayType == DISPLAYTYPE_GLIDE || gnDisplayType == DISPLAYTYPE_OPENGL || gnDisplayType == DISPLAYTYPE_RAVE || gnDisplayType == DISPLAYTYPE_DIRECT3D, 0xA8);
    D2_ASSERT(gGfxSettings.bPerspectiveEnabled, 0xA9);

    return gpGraphicsInterface->pfPerspectiveClearScale();
}

// 0x004F7CC0
extern "C" void __cdecl sub_004F7CC0()
{
    for (int i = 0; i < 32; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            int nValue = i << 24;
            const int nStep = ((j - i) << 24) >> 5;
            for (int k = 0; k < 32; ++k)
            {
                nValue = nValue > 0 ? nValue : 0;
                if (nValue >= 0x1F000000)
                {
                    nValue = 0x1F000000;
                }
                gLightCube_007CA320[i][j][k] = nValue >> 24;
                nValue += nStep;
            }

            D2_ASSERT((nValue >> 24) == j, 0x285);
        }
    }
}

// 0x004F7E70
void __cdecl sub_004F7E70_InitRowOffsets()
{
    int nValue = -32 * gnScreenPitch_007D544C;
    for (int i = 0; i < 732; ++i)
    {
        gnRowOffsets_007C97A8[i] = nValue;
        nValue += gnScreenPitch_007D544C;
    }
}

// 0x004F8E40
void __fastcall sub_004F8E40_CopyPaletteTables(D2PaletteTableStrc* pPaletteTables)
{
    gPaletteTables_007D5458 = *pPaletteTables;
    gpPaletteTables_007D5578 = &gPaletteTables_007D5458;
    for (int i = 0; i < 49; ++i)
    {
        gLightPalettes_007D2348[i] = *gPaletteTables_007D5458.pPalettes[i + 3];
    }
}

#include "gen/data/Source/D2Gfx/SRC/Window.inc"
