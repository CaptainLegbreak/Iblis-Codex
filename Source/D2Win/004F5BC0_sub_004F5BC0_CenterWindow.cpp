struct T004F51E0;

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct tagPOINT
{
    long x;
    long y;
};

struct _AppBarData
{
    unsigned long cbSize;
    void* hWnd;
    unsigned int uCallbackMessage;
    unsigned int uEdge;
    tagRECT rc;
    long lParam;
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
    void* unk0x00[46];
    void (__fastcall* pfDrawBox)(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode);
    void (__fastcall* pfDrawBoxAlpha)(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha);
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned int __stdcall SHAppBarMessage(unsigned long dwMessage, _AppBarData* pData); // 0x006CC434
extern "C" __declspec(dllimport) int __stdcall GetWindowRect(void* hWnd, tagRECT* lpRect);                 // 0x006CC4BC
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void* hWnd, void* hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags); // 0x006CC4DC
extern "C" __declspec(dllimport) int __stdcall ShowWindow(void* hWnd, int nCmdShow);                       // 0x006CC4EC
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* lpRect);                 // 0x006CC4F8
extern "C" __declspec(dllimport) int __stdcall AdjustWindowRectEx(tagRECT* lpRect, unsigned long dwStyle, int bMenu, unsigned long dwExStyle); // 0x006CC4FC
extern "C" __declspec(dllimport) int __stdcall SystemParametersInfoA(unsigned int uiAction, unsigned int uiParam, void* pvParam, unsigned int fWinIni); // 0x006CC504
extern "C" __declspec(dllimport) int __stdcall GetWindowPlacement(void* hWnd, tagWINDOWPLACEMENT* lpwndpl); // 0x006CC508

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
void __stdcall sub_004F5570_GetResolutionSize(int nResolution, long* pWidth, long* pHeight);                // 0x004F5570
int __stdcall WINDOW_Resize(int nResolution, int bForceResize);                                             // 0x004F5AA0
void __cdecl sub_004F5FA0_UpdatePauseState();                                                               // 0x004F5FA0
void __stdcall D2GFX_SetPalette(T004F51E0* pPalette);                                              // 0x004F63D0

extern int gbIsWindowed;                                                                                    // 0x007C8CB4
int gnResolutionMode;                                                                                       // 0x007C8CB8
extern void* ghWnd;                                                                                         // 0x007C8CBC
extern D2GraphicsInterfaceStrc* gpGraphicsInterface;                                                        // 0x007C8CC0
extern tagRECT gWindowRect_007C9160;                                                                        // 0x007C9160
int gnCaptionHeight_007C9270;                                                                               // 0x007C9270
extern D2WindowPlacementStrc gWindowPlacement[4];                                                           // 0x007C9278
extern int gbWindowState_6FA8D850;                                                                          // 0x007C9340

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
