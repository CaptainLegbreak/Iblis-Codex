struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

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

struct tagWINDOWPLACEMENT
{
    unsigned int length;
    unsigned int flags;
    unsigned int showCmd;
    tagPOINT ptMinPosition;
    tagPOINT ptMaxPosition;
    tagRECT rcNormalPosition;
};

struct tagMONITORINFO
{
    unsigned long cbSize;
    tagRECT rcMonitor;
    tagRECT rcWork;
    unsigned long dwFlags;
};

extern "C" __declspec(dllimport) void* __stdcall GetDesktopWindow();                                       // 0x006CC494
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void* hWnd, void* hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags); // 0x006CC4DC
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* lpRect);                 // 0x006CC4F8
extern "C" __declspec(dllimport) int __stdcall GetWindowPlacement(void* hWnd, tagWINDOWPLACEMENT* lpwndpl); // 0x006CC508
extern "C" __declspec(dllimport) int __stdcall GetMonitorInfoA(void* hMonitor, tagMONITORINFO* lpmi);      // 0x006CC510
extern "C" __declspec(dllimport) void* __stdcall MonitorFromWindow(void* hWnd, unsigned long dwFlags);      // 0x006CC514

int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160
int __cdecl sub_004F5180();                                                                                 // 0x004F5180
void __stdcall sub_004F5570_GetResolutionSize(int nResolution, long* pWidth, long* pHeight);                // 0x004F5570
void* __cdecl sub_004F59A0();                                                                              // 0x004F59A0
int __cdecl sub_004F5A30();                                                                                 // 0x004F5A30
int __stdcall sub_004F5BC0_CenterWindow(int nResolution);                                                   // 0x004F5BC0

tagRECT gWindowRect_007C9160;                                                                               // 0x007C9160

// 0x004F9CC0
void __stdcall sub_004F9CC0_SysCommandMaximizeMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned short nCommand = pMsg->nWParamLo & 0xFFF0;
    if (nCommand == 0xF130 || nCommand == 0xF100 || (nCommand == 0xF010 && sub_004F5A30()))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        return;
    }

    if (nCommand != 0xF030)
    {
        return;
    }

    if (sub_004F5A30())
    {
        return;
    }

    void* hWnd = sub_004F59A0();
    void* hMonitor = MonitorFromWindow(hWnd, 2);
    tagMONITORINFO tMonitorInfo;
    tMonitorInfo.cbSize = sizeof(tagMONITORINFO);
    GetMonitorInfoA(hMonitor, &tMonitorInfo);

    tagRECT tClientRect = {};
    GetClientRect(hWnd, &tClientRect);
    const int nClientWidth = tClientRect.right - tClientRect.left;
    const int nClientHeight = tClientRect.bottom - tClientRect.top;

    tagRECT tWorkArea = tMonitorInfo.rcWork;
    const int nWorkWidth = tWorkArea.right - tWorkArea.left;
    const int nWorkHeight = tWorkArea.bottom - tWorkArea.top;

    tagRECT tRect = {};
    const int nMode = D2GFX_GetResolutionMode();
    sub_004F5570_GetResolutionSize(nMode, &tRect.right, &tRect.bottom);

    tagRECT tDesktopRect;
    GetClientRect(GetDesktopWindow(), &tDesktopRect);

    if (nClientWidth == tRect.right && nClientHeight == tRect.bottom
        && tDesktopRect.right - tDesktopRect.left > tRect.right && tDesktopRect.bottom - tDesktopRect.top > tRect.bottom)
    {
        tRect.left = tWorkArea.left;
        tRect.top = tWorkArea.top;
        if (!sub_004F5180())
        {
            return;
        }

        tagWINDOWPLACEMENT tPlacement;
        GetWindowPlacement(hWnd, &tPlacement);
        if (tPlacement.showCmd != 3)
        {
            while (tRect.right < nWorkWidth && tRect.bottom < nWorkHeight)
            {
                tRect.right += 4;
                tRect.bottom += 3;
            }
            tRect.right -= 12;
            tRect.bottom -= 9;
            tRect.left = (nWorkWidth - tRect.right) / 2 + tWorkArea.left;
            tRect.top = (nWorkHeight - tRect.bottom) / 2 + tWorkArea.top;
            if (tRect.top < 0)
            {
                tRect.top = 0;
            }
            if (tRect.left < 0)
            {
                tRect.left = 0;
            }
            gWindowRect_007C9160 = tPlacement.rcNormalPosition;
            SetWindowPos(hWnd, (void*)-2, tRect.left, tRect.top, tRect.right, tRect.bottom, 0x14);
        }
    }
    else if (tRect.bottom < tWorkArea.bottom && tRect.right < tWorkArea.right)
    {
        tagRECT tNewRect = { 0 };
        const int nResolution = D2GFX_GetResolutionMode();
        sub_004F5570_GetResolutionSize(nResolution, &tNewRect.right, &tNewRect.bottom);
        SetWindowPos(hWnd, (void*)-2, 0, 0, tNewRect.right, tNewRect.bottom, 0x14);
        sub_004F5BC0_CenterWindow(nResolution);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}
