#include "D2Gfx.h"

struct D2GraphicsInterfaceStrc;
struct D2GfxSettingsStrc;
struct D2PaletteStrc;
struct _AppBarData;
struct D2WindowPlacementStrc;
struct D2DevModeStrc;

extern D2GfxSettingsStrc gGfxSettings; // 0x0072DA48
extern int gbIsWindowed; // 0x007C8CB4

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
void __cdecl sub_004F5510_HideCursor(); // 0x004F5510
void __cdecl sub_004F5540_ShowCursor(); // 0x004F5540
double __cdecl sub_004F6130_GetElapsedMs(); // 0x004F6130

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
void __stdcall WINDOW_ShowAll(); // 0x004F5F60
void __stdcall sub_004F5570_GetResolutionSize(int nResolution, long* pWidth, long* pHeight); // 0x004F5570
extern int gnResolutionMode; // 0x007C8CB8

struct _AppBarData
{
    unsigned long cbSize;
    void* hWnd;
    unsigned int uCallbackMessage;
    unsigned int uEdge;
    tagRECT rc;
    long lParam;
};

extern "C" __declspec(dllimport) unsigned int __stdcall SHAppBarMessage(unsigned long dwMessage, _AppBarData* pData); // 0x006CC434
extern "C" __declspec(dllimport) int __stdcall GetWindowRect(void* hWnd, tagRECT* lpRect); // 0x006CC4BC
extern "C" __declspec(dllimport) int __stdcall SystemParametersInfoA(unsigned int uiAction, unsigned int uiParam, void* pvParam, unsigned int fWinIni); // 0x006CC504
extern "C" __declspec(dllimport) int __stdcall GetWindowPlacement(void* hWnd, tagWINDOWPLACEMENT* lpwndpl); // 0x006CC508
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610
int __stdcall WINDOW_Resize(int nResolution, int bForceResize); // 0x004F5AA0
void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0
extern tagRECT gWindowRect_007C9160; // 0x007C9160
extern D2WindowPlacementStrc gWindowPlacement[4]; // 0x007C9278
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd); // 0x006CC50C
void __cdecl WINDOW_UpdatePlacement(); // 0x004F5EC0

struct D2DevModeStrc
{
    char dmDeviceName[0x20];
    unsigned short dmSpecVersion;
    unsigned short dmDriverVersion;
    unsigned short dmSize;
    unsigned short dmDriverExtra;
    unsigned int dmFields;
    char unk0x2C[0x3C];
    unsigned int dmBitsPerPel;
    unsigned int dmPelsWidth;
    unsigned int dmPelsHeight;
    char f_74[0x28];
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GdiSetBatchLimit(unsigned long dwLimit); // 0x006CC0DC
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464
extern "C" __declspec(dllimport) void* __stdcall GetDesktopWindow(); // 0x006CC494
extern "C" __declspec(dllimport) int __stdcall GetSystemMetrics(int nIndex); // 0x006CC4B8
extern "C" __declspec(dllimport) void* __stdcall SetFocus(void* hWnd); // 0x006CC4E4
extern "C" __declspec(dllimport) int __stdcall UpdateWindow(void* hWnd); // 0x006CC4E8
extern "C" __declspec(dllimport) void* __stdcall CreateWindowExA(unsigned long dwExStyle, const char* szClass, const char* szWindow, unsigned long dwStyle, int nX, int nY, int nWidth, int nHeight, void* hParent, void* hMenu, void* hInstance, void* pParam); // 0x006CC4F0
extern "C" __declspec(dllimport) void* __stdcall FindWindowA(const char* szClass, const char* szWindow); // 0x006CC500
extern int gnCaptionHeight_007C9270; // 0x007C9270
extern int gbNoWindowCreated_007C9338; // 0x007C9338
void __cdecl sub_0051793E_FormatAndRaise(unsigned long dwError, ...); // 0x0051793E

#include "gen/data/Source/D2Gfx/SRC/Window.inc"

// 0x004F5020
int __stdcall sub_004F5020_ClearInterface()
{
    gpGraphicsInterface = 0;
    return 1;
}

// 0x004F5030
void __cdecl j_D2GFX_10040_ShowAllWindows()
{
    WINDOW_ShowAll();
}

// 0x004F5040
int __stdcall D2GFX_ReturnFalse(int nArg1, int nArg2, int nArg3)
{
    return 0;
}

// 0x004F51D0
int __stdcall D2GFX_CheckPerspective()
{
    return gGfxSettings.bPerspectiveCapable != 0 ? gGfxSettings.bPerspectiveEnabled : 0;
}

D2GraphicsInterfaceStrc* gpGraphicsInterface; // 0x007C8CC0

double gdFrameRemainder_007C9360; // 0x007C9360

tagPALETTEENTRY gpPalette_6FA8D278[256]; // 0x007C9378

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

// 0x004F52C0
void __cdecl sub_004F52C0_Empty()
{
}

// 0x004F52D0
void __cdecl sub_004F52D0_Empty()
{
}

// 0x004F54B0
int __stdcall D2GFX_TogglePerspective()
{
    gGfxSettings.bPerspectiveEnabled = gGfxSettings.bPerspectiveEnabled == 0;
    return gGfxSettings.bPerspectiveEnabled;
}

// 0x004F54D0
int __stdcall D2GFX_ToggleBlendedShadows()
{
    gGfxSettings.bBlendedShadows = gGfxSettings.bBlendedShadows == 0;
    return gGfxSettings.bBlendedShadows;
}

// 0x004F54F0
int __stdcall D2GFX_ToggleLowQuality()
{
    gGfxSettings.bLowQuality = gGfxSettings.bLowQuality == 0;
    return gGfxSettings.bLowQuality;
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

// 0x004F5570
void __stdcall sub_004F5570_GetResolutionSize(int nResolution, long* pWidth, long* pHeight)
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

int gbIsWindowed; // 0x007C8CB4

void* ghWnd; // 0x007C8CBC

const char* gszWindowClass_007C9344; // 0x007C9344

const char* gszWindowTitle_007C9348; // 0x007C9348

// 0x004F5610
int __stdcall WINDOW_Create(int bWindowed, int nResolution)
{
    if (FindWindowA(gszWindowClass_007C9344, 0))
    {
        char szCaption[256];
        char szText[256];
        sprintf(szCaption, "Diablo II Critical Error");
        sprintf(szText, "Only one copy of Diablo II may run at a time.");
        MessageBoxA(0, szText, szCaption, 0x30);
        return 0;
    }

    D2_ASSERT(gpGraphicsInterface, 0x90);
    D2_ASSERT(!ghWnd, 0x91);
    gbIsWindowed = bWindowed;
    gnResolutionMode = nResolution;
    tagRECT tRect;
    tRect.left = 0;
    tRect.top = 0;
    sub_004F5570_GetResolutionSize(nResolution, &tRect.right, &tRect.bottom);
    gnCaptionHeight_007C9270 = tRect.bottom;
    unsigned int dwStyle;
    if (gbIsWindowed == 1)
    {
        dwStyle = 0xCB0000;
    }
    else
    {
        dwStyle = 0x80080000;
        if (gnDisplayType == 5)
        {
            dwStyle = 0x86080000;
        }
    }

    AdjustWindowRectEx(&tRect, dwStyle, 0, 0x40000);
    int nWidth = tRect.right - tRect.left;
    int nHeight = tRect.bottom - tRect.top;
    gnCaptionHeight_007C9270 = nHeight - gnCaptionHeight_007C9270;
    int nY = 0;
    int nX = 0;
    if (gbIsWindowed == 1)
    {
        tagRECT tDesktop;
        GetClientRect(GetDesktopWindow(), &tDesktop);
        nX = (tDesktop.right - nWidth) >> 1;
        if (nX < 0)
        {
            nX = 0;
        }
        nY = (tDesktop.bottom - nHeight) >> 1;
        if (nY < 0)
        {
            nY = 0;
        }
    }
    else if (gnDisplayType == 4)
    {
        nX = 0;
        nY = 0;
        nWidth = GetSystemMetrics(0) > 800 ? GetSystemMetrics(0) : 800;
        nHeight = GetSystemMetrics(1) > 600 ? GetSystemMetrics(1) : 600;
    }

    if (GetSystemMetrics(0) < 800)
    {
        D2DevModeStrc tDevMode;
        memset(&tDevMode, 0, sizeof(tDevMode));
        tDevMode.dmSize = sizeof(tDevMode);
        tDevMode.dmBitsPerPel = 8;
        tDevMode.dmPelsWidth = 800;
        tDevMode.dmPelsHeight = 600;
        tDevMode.dmFields = 0x1C0000;
        ChangeDisplaySettingsA(&tDevMode, 0);
    }

    ghWnd = CreateWindowExA(0x40008, gszWindowClass_007C9344, gszWindowTitle_007C9348, dwStyle, nX, nY, nWidth, nHeight, 0, 0, ghInstance_007C8CA8, 0);
    if (!ghWnd)
    {
        sub_0051793E_FormatAndRaise(GetLastError());
        return 0;
    }

    ShowWindow(ghWnd, 1);
    UpdateWindow(ghWnd);
    SetFocus(ghWnd);
    GdiSetBatchLimit(1);
    sub_004F5510_HideCursor();
    const int bResult = gpGraphicsInterface->pfCreateSurface(ghWnd, gnResolutionMode);
    if (!bResult)
    {
        gbNoWindowCreated_007C9338 = 1;
        sub_004F5540_ShowCursor();
        if (ghWnd)
        {
            DestroyWindow(ghWnd);
            ghWnd = 0;
        }
    }

    sub_004F8EA0();
    SetWindowPos(ghWnd, (void*)-2, 0, 0, nWidth, nHeight, 2);
    return bResult;
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

// 0x004F5A30
int __stdcall WINDOW_IsFullScreen()
{
    if (gpGraphicsInterface)
    {
        return gbIsWindowed == 0;
    }

    return 0;
}

// 0x004F5A50
int __stdcall WINDOW_Activate(int bActive)
{
    D2_ASSERT(gpGraphicsInterface, 471);

    gbIsWindowed = bActive == 0;
    return gpGraphicsInterface->pfActivateWindow(bActive, gbIsWindowed);
}

// 0x004F5AA0
int __stdcall WINDOW_Resize(int nResolution, int bForceResize)
{
    D2_ASSERT(gpGraphicsInterface, 485);

    if (!bForceResize && nResolution == gnResolutionMode)
    {
        return 1;
    }

    gnResolutionMode = nResolution;

    if (gbIsWindowed == 1)
    {
        tagRECT tClientRect = { 0 };
        GetClientRect(ghWnd, &tClientRect);
        if (tClientRect.right - tClientRect.left <= 800 && tClientRect.bottom - tClientRect.top <= 600)
        {
            tagRECT tRect;
            tRect.left = 0;
            tRect.top = 0;
            sub_004F5570_GetResolutionSize(nResolution, &tRect.right, &tRect.bottom);
            AdjustWindowRectEx(&tRect, 0xCB0000, 0, 0x40000);
            SetWindowPos(ghWnd, (void*)-2, 0, 0, tRect.right - tRect.left, tRect.bottom - tRect.top, 0x16);
        }
    }

    const int bResult = gpGraphicsInterface->pfChangeRes(ghWnd, nResolution);
    sub_004F8EA0();
    return bResult;
}

int gnResolutionMode; // 0x007C8CB8

int gnCaptionHeight_007C9270; // 0x007C9270

// 0x004F5BC0
int __stdcall sub_004F5BC0_CenterWindow(int nResolution)
{
    D2_ASSERT(gpGraphicsInterface, 562);

    gnResolutionMode = nResolution;

    if (gbIsWindowed == 1)
    {
        void* hWnd = ghWnd;
        tagRECT tClientRect = { 0 };
        GetClientRect(hWnd, &tClientRect);
        if (tClientRect.right - tClientRect.left <= 800 && tClientRect.bottom - tClientRect.top <= 600)
        {
            tagRECT tWorkArea = { 0 };
            SystemParametersInfoA(0x30, 0, &tWorkArea, 0);
            const int nWorkHeight = tWorkArea.bottom - tWorkArea.top;
            const int nWorkWidth = tWorkArea.right - tWorkArea.left;

            tagRECT tWindowRect = {};
            GetWindowRect(hWnd, &tWindowRect);

            tagRECT tRect = { 0 };
            sub_004F5570_GetResolutionSize(nResolution, &tRect.right, &tRect.bottom);
            gnCaptionHeight_007C9270 = tRect.bottom;
            AdjustWindowRectEx(&tRect, 0xCB0000, 0, 0x40000);
            const int nHeight = tRect.bottom - tRect.top;
            const int nWidth = tRect.right - tRect.left;
            gnCaptionHeight_007C9270 = nHeight - gnCaptionHeight_007C9270;

            int nX = (nWorkWidth - nWidth) / 2 + tWorkArea.left;
            if (nX < 0)
            {
                nX = 0;
            }

            int nY = (nWorkHeight - nHeight) / 2 + tWorkArea.top;
            if (nY < 0)
            {
                nY = 0;
            }

            SetWindowPos(ghWnd, (void*)-2, nX, nY, nWidth, nHeight, 0x14);
            sub_004F5570_GetResolutionSize(nResolution, &gWindowRect_007C9160.right, &gWindowRect_007C9160.bottom);
            GetWindowRect(hWnd, &gWindowRect_007C9160);
        }
    }

    return 1;
}

// 0x004F5D50
void __stdcall WINDOW_ClearCaches()
{
    gpGraphicsInterface->pfClearCaches();
}

// 0x004F5D60
void __stdcall WINDOW_PlayCutscene()
{
    D2_ASSERT(gpGraphicsInterface, 0x2AD);
    gpGraphicsInterface->pfPlayCutscene();
}

// 0x004F5D90
void __stdcall WINDOW_OpenSmackCutscene(const char* szFile, int nResolution, void* pfFrame)
{
    D2_ASSERT(gpGraphicsInterface, 732);

    return gpGraphicsInterface->pfOpenSmackCutscene(szFile, nResolution, pfFrame);
}

// 0x004F5DD0
int __stdcall WINDOW_CheckCutScene()
{
    D2_ASSERT(gpGraphicsInterface, 0x2F6);

    return gpGraphicsInterface->pfCheckCutScene();
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

// 0x004F5EC0
void __cdecl WINDOW_UpdatePlacement()
{
    if (gbIsWindowed == 1)
    {
        return;
    }

    _AppBarData tData = {};
    tData.cbSize = sizeof(tData);
    tData.hWnd = ghWnd;

    for (int i = 0; i < 4; ++i)
    {
        tData.uEdge = i;

        D2WindowPlacementStrc* pWindowPlacement = &gWindowPlacement[i];
        pWindowPlacement->hWnd = (void*)SHAppBarMessage(7, &tData);
        if (pWindowPlacement->hWnd)
        {
            pWindowPlacement->windowPlacement.length = sizeof(tagWINDOWPLACEMENT);
            GetWindowPlacement(pWindowPlacement->hWnd, &pWindowPlacement->windowPlacement);
            ShowWindow(pWindowPlacement->hWnd, 0);
        }
    }
}

D2WindowPlacementStrc gWindowPlacement[4]; // 0x007C9278

int gbPaused_6FA8D84C; // 0x007C933C

int gbWindowState_6FA8D850; // 0x007C9340

// 0x004F5F60
void __stdcall WINDOW_ShowAll()
{
    if (gbIsWindowed == 1)
    {
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        D2WindowPlacementStrc* pWindowPlacement = &gWindowPlacement[i];
        if (pWindowPlacement->hWnd)
        {
            ShowWindow(pWindowPlacement->hWnd, pWindowPlacement->windowPlacement.showCmd);
        }
    }
}

// 0x004F5FA0
void __cdecl sub_004F5FA0_UpdatePauseState()
{
    if (gbWindowState_6FA8D850 == gbPaused_6FA8D84C || !ghWnd)
    {
        return;
    }

    D2_ASSERT(gpGraphicsInterface, 361);

    int bPaused = gbPaused_6FA8D84C;
    if (!gbPaused_6FA8D84C)
    {
        if (IsIconic(ghWnd))
        {
            return;
        }
        bPaused = gbPaused_6FA8D84C;
    }

    gbWindowState_6FA8D850 = bPaused;
    if (bPaused)
    {
        ShowWindow(ghWnd, 6);
        WINDOW_ShowAll();
        while (ShowCursor(1) < 0);
    }
    else
    {
        WINDOW_UpdatePlacement();
        while (ShowCursor(0) >= 0);
    }

    gpGraphicsInterface->pfPauseSurface(ghWnd, gnResolutionMode, gbWindowState_6FA8D850);

    if (!gbWindowState_6FA8D850)
    {
        D2GFX_SetPalette(0);
        sub_004F8EA0();
    }
}

// 0x004F6070
int __stdcall WINDOW_GetState()
{
    sub_004F5FA0_UpdatePauseState();
    return gbWindowState_6FA8D850;
}

// 0x004F6080
void __stdcall WINDOW_EndCutScene(int nResolution)
{
    D2_ASSERT(gpGraphicsInterface, 697);

    sub_004F5FA0_UpdatePauseState();

    if (gbWindowState_6FA8D850)
    {
        gnResolutionMode = nResolution;
    }
    else if (!WINDOW_Resize(nResolution, 1))
    {
        sub_00410610_WriteLogLine("Failed to resize window after cutscenes... this is fatal!");
        exit(-1);
    }

    D2GFX_SetPalette(0);
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

// 0x004F6270
int __stdcall D2GFX_HardwareAcceleratedRenderMode()
{
    return gnDisplayType >= DISPLAYTYPE_GLIDE;
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

// 0x004F6300
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode)
{
    if (nXEnd >= nXStart && nYEnd >= nYStart)
    {
        gpGraphicsInterface->pfDrawBox(nXStart, nYStart, nXEnd, nYEnd, dwColor, eDrawMode);
    }
}

// 0x004F6340
void __stdcall D2GFX_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    if (nXEnd >= nXStart && nYEnd >= nYStart)
    {
        gpGraphicsInterface->pfDrawBoxAlpha(nXStart, nYStart, nXEnd, nYEnd, dwColor, nAlpha);
    }
}

// 0x004F63B0
void __stdcall D2GFX_ClearScreen(int bPartial)
{
    return gpGraphicsInterface->pfClearScreen(bPartial);
}

// 0x004F63D0
__declspec(noinline) void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette)
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
        gLightPalettes_007D2348[i] = *(D2PaletteStrc*)gPaletteTables_007D5458.pShadowLightGammaPalettes[i];
    }
}
