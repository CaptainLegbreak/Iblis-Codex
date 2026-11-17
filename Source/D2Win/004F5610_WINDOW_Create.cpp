struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

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

struct D2GraphicsInterfaceStrc
{
    char unk0x00[0x0C];
    int (__fastcall* pfCreateSurface)(void* hWnd, int nResolutionMode);
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();                                    // 0x006CC1B4
extern "C" __declspec(dllimport) unsigned long __stdcall GdiSetBatchLimit(unsigned long dwLimit);           // 0x006CC0DC
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464
extern "C" __declspec(dllimport) void* __stdcall GetDesktopWindow();                                        // 0x006CC494
extern "C" __declspec(dllimport) int __stdcall GetSystemMetrics(int nIndex);                                // 0x006CC4B8
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void* hWnd, void* hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags); // 0x006CC4DC
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(void* hWnd);                                  // 0x006CC4E0
extern "C" __declspec(dllimport) void* __stdcall SetFocus(void* hWnd);                                     // 0x006CC4E4
extern "C" __declspec(dllimport) int __stdcall UpdateWindow(void* hWnd);                                   // 0x006CC4E8
extern "C" __declspec(dllimport) int __stdcall ShowWindow(void* hWnd, int nCmdShow);                       // 0x006CC4EC
extern "C" __declspec(dllimport) void* __stdcall CreateWindowExA(unsigned long dwExStyle, const char* szClass, const char* szWindow, unsigned long dwStyle, int nX, int nY, int nWidth, int nHeight, void* hParent, void* hMenu, void* hInstance, void* pParam); // 0x006CC4F0
extern "C" __declspec(dllimport) long __stdcall ChangeDisplaySettingsA(void* lpDevMode, unsigned long dwFlags); // 0x006CC4F4
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* lpRect);                 // 0x006CC4F8
extern "C" __declspec(dllimport) int __stdcall AdjustWindowRectEx(tagRECT* lpRect, unsigned long dwStyle, int bMenu, unsigned long dwExStyle); // 0x006CC4FC
extern "C" __declspec(dllimport) void* __stdcall FindWindowA(const char* szClass, const char* szWindow);   // 0x006CC500

extern void* ghInstance_007C8CA8;                                                                           // 0x007C8CA8
extern int gnDisplayType;                                                                                   // 0x007C8CB0
int gbIsWindowed;                                                                                           // 0x007C8CB4
extern int gnResolutionMode;                                                                                // 0x007C8CB8
void* ghWnd;                                                                                                // 0x007C8CBC
extern D2GraphicsInterfaceStrc* gpGraphicsInterface;                                                        // 0x007C8CC0
extern int gnCaptionHeight_007C9270;                                                                        // 0x007C9270
extern int gbNoWindowCreated_007C9338;                                                                      // 0x007C9338
const char* gszWindowClass_007C9344;                                                                        // 0x007C9344
const char* gszWindowTitle_007C9348;                                                                        // 0x007C9348

void __cdecl sub_004F5510_HideCursor();                                                                     // 0x004F5510
void __cdecl sub_004F5540_ShowCursor();                                                                     // 0x004F5540
void __stdcall sub_004F5570_GetResolutionSize(int nResolution, long* pWidth, long* pHeight);                // 0x004F5570
void __cdecl sub_004F8EA0();                                                          // 0x004F8EA0
void __cdecl sub_0051793E_FormatAndRaise(unsigned long dwError);                                               // 0x0051793E

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
