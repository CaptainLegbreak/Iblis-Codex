typedef long (__stdcall* WNDPROC)(void*, unsigned int, unsigned int, long);
struct WNDCLASSA
{
    unsigned int style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    void* hInstance;
    void* hIcon;
    void* hCursor;
    void* hbrBackground;
    const char* lpszMenuName;
    const char* lpszClassName;
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
    int (__fastcall* pfDetect)(void*);
    int (__fastcall* pfInit)(D2GfxSettingsStrc*, const void*);
    int (__fastcall* pfClose)();
    int (__fastcall* pfCreateSurface)(void*, int);
    int (__fastcall* pfCloseSurface)();
    void (__fastcall* pfPauseSurface)(void*, int, int);
    int (__fastcall* pfStartDraw)(int, unsigned char, unsigned char, unsigned char);
    int (__fastcall* pfEndDraw)();
    int (__fastcall* pfBlit)();
    int (__fastcall* pfChangeRes)(void*, int);
    int (__fastcall* pfGetBackBuffer)(unsigned char*);
    int (__fastcall* pfActivateWindow)(int, int);
    int (__fastcall* pfSetOption)(int, int);
};
extern "C" __declspec(dllimport) void* __stdcall LoadImageA(void*, const char*, unsigned int, int, int, unsigned int); // 0x006CC4D4
extern "C" __declspec(dllimport) void* __stdcall LoadCursorA(void*, const char*); // 0x006CC4D0
extern "C" __declspec(dllimport) void* __stdcall GetStockObject(int); // 0x006CC0E8
extern "C" __declspec(dllimport) unsigned short __stdcall RegisterClassA(const WNDCLASSA*); // 0x006CC4CC
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4
int __fastcall sub_00408F20_HasExpansionMpq(); // 0x00408F20
void __cdecl sub_0051793E_FormatAndRaise(unsigned long dwError, ...); // 0x0051793E
extern "C" void __cdecl sub_004F8DC0_InitLookupTable(); // 0x004F8DC0
void __cdecl j_D2GFX_10040_ShowAllWindows(); // 0x004F5030
extern "C" int __cdecl atexit(void (__cdecl*)()); // 0x00683824
void __cdecl sub_00410610_WriteLogLine(const char*, ...); // 0x00410610
void __cdecl sub_00408900_RaiseErrorReport(int, const char*, int, const char*, ...); // 0x00408900
extern void* ghInstance_007C8CA8; // 0x007C8CA8
extern WNDPROC gpWndProc_007C8CAC; // 0x007C8CAC
extern const char* gszWindowClassName_007C9158; // 0x007C9158
extern int gnDisplayType; // 0x007C8CB0
extern int gbIsWindowed; // 0x007C8CB4
extern D2GraphicsInterfaceStrc* gpGraphicsInterface; // 0x007C8CC0
extern D2GraphicsInterfaceStrc* gapGraphicsInterfaces_0072DA80[]; // 0x0072DA80
extern D2GfxSettingsStrc gGfxSettings; // 0x0072DA48
extern const unsigned char gGraphicsHelpers_0072DA60[]; // 0x0072DA60
extern const char gszUnsupportedMode_006DC458[]; // 0x006DC458
extern const char gszStringFormat_006FFC58[]; // 0x006FFC58
extern const char gszUnsupportedGraphics_0072DAF0[]; // 0x0072DAF0
extern const char gszRetryUnsupportedGraphics_0072DAA8[]; // 0x0072DAA8

// 0x004F4FF0
int __fastcall sub_004F4FF0_SetVideoMode(int nMode)
{
    if (!gapGraphicsInterfaces_0072DA80[nMode])
    {
        sub_00410610_WriteLogLine(gszUnsupportedMode_006DC458, nMode);
        return 0;
    }
    gpGraphicsInterface = gapGraphicsInterfaces_0072DA80[nMode];
    return 1;
}

// 0x004F52E0
int __stdcall D2GFX_Initialize(void* hInstance, WNDPROC pfWndProc, int nRenderMode, int bWindowed)
{
    ghInstance_007C8CA8 = hInstance;
    gpWndProc_007C8CAC = pfWndProc;
    WNDCLASSA windowClass;
    windowClass.style = nRenderMode == 5 ? 0x20 : 0;
    windowClass.lpfnWndProc = pfWndProc;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = hInstance;
    const int nIconId = sub_00408F20_HasExpansionMpq() ? 103 : 102;
    windowClass.hIcon = LoadImageA(ghInstance_007C8CA8, (const char*)(unsigned short)nIconId, 1, 0, 0, 0);
    windowClass.hCursor = LoadCursorA(0, (const char*)32512);
    windowClass.hbrBackground = GetStockObject(5);
    windowClass.lpszMenuName = 0;
    windowClass.lpszClassName = gszWindowClassName_007C9158;
    if (!RegisterClassA(&windowClass))
    {
        sub_0051793E_FormatAndRaise(GetLastError());
        return 0;
    }
    sub_004F8DC0_InitLookupTable();
    atexit(j_D2GFX_10040_ShowAllWindows);
    gnDisplayType = nRenderMode;
    gbIsWindowed = bWindowed;
    if (!sub_004F4FF0_SetVideoMode(nRenderMode))
    {
        return 0;
    }
    gpGraphicsInterface->pfSetOption(8, bWindowed == 1);
    if (!gpGraphicsInterface->pfDetect(hInstance))
    {
        sub_00408900_RaiseErrorReport(9, 0, 0, gszStringFormat_006FFC58, gszUnsupportedGraphics_0072DAF0);
        return 0;
    }
    int bPerspectiveCapable = gGfxSettings.bPerspectiveCapable;
    if (!(gnDisplayType >= 4))
    {
        bPerspectiveCapable = 0;
    }
    gGfxSettings.bPerspectiveCapable = bPerspectiveCapable;
    int result = gpGraphicsInterface->pfInit(&gGfxSettings, gGraphicsHelpers_0072DA60);
    if (!result)
    {
        if (!gpGraphicsInterface->pfDetect(hInstance))
        {
            sub_00408900_RaiseErrorReport(9, 0, 0, gszStringFormat_006FFC58, gszRetryUnsupportedGraphics_0072DAA8);
        }
        else
        {
            result = gpGraphicsInterface->pfInit(&gGfxSettings, gGraphicsHelpers_0072DA60);
        }
    }
    return result;
}

#include "gen/data/Source/D2Win/004F52E0_D2GFX_Initialize.inc"
