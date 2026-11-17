struct T004F51E0;

struct tagPOINT
{
    long x;
    long y;
};

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct tagWINDOWPLACEMENT
{
    unsigned int length;
    unsigned int flags;
    unsigned int showCmd;
    tagPOINT ptMinPosition;
    tagPOINT ptMaxPosition;
    tagRECT rcNormalPosition;
};

struct D2WindowPlacementStrc
{
    void* hWnd;
    tagWINDOWPLACEMENT windowPlacement;
};

struct D2GraphicsInterfaceStrc
{
    void* unk0x00[5];
    void (__fastcall* pfPauseSurface)(void* hWnd, int nResolutionMode, int nWindowState);
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall ShowWindow(void* hWnd, int nCmdShow);                       // 0x006CC4EC
extern "C" __declspec(dllimport) int __stdcall ShowCursor(int bShow);                                     // 0x006CC4D8
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd);                                      // 0x006CC50C
void __cdecl WINDOW_UpdatePlacement();                                                                      // 0x004F5EC0
void __stdcall D2GFX_SetPalette(T004F51E0* pPalette);                                              // 0x004F63D0
void __cdecl sub_004F8EA0();                                                          // 0x004F8EA0

extern int gnResolutionMode;                                                                                // 0x007C8CB8
extern int gbIsWindowed;                                                                                    // 0x007C8CB4
extern void* ghWnd;                                                                                         // 0x007C8CBC
extern D2GraphicsInterfaceStrc* gpGraphicsInterface;                                                        // 0x007C8CC0
D2WindowPlacementStrc gWindowPlacement[4];                                                                  // 0x007C9278
int gbPaused_6FA8D84C;                                                                                      // 0x007C933C
int gbWindowState_6FA8D850;                                                                                 // 0x007C9340

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
