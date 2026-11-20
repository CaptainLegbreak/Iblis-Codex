#include "D2Win.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2WIN_SCROLLBAR 5
#define D2WIN_BUTTON 6

struct D2CellFileStrc;
struct Control;
struct D2WinControlStrc;
struct D2WinButtonStrc;
struct tagRECT;
struct D2CelContextStrc;
struct tagPOINT;
struct tagWINDOWPLACEMENT;
struct tagMONITORINFO;
struct Point;
struct Obj004FA490;

struct D2WinControlStrc
{
    int eType;
    D2CellFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    int (__fastcall* pfDraw)(D2WinControlStrc*);
    int (__fastcall* pfInitialize)(D2WinControlStrc*);
    void* unk0x24[6];
    D2WinControlStrc* pNext;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CellFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall GetWindowRect(void* hWnd, tagRECT* lpRect); // 0x006CC4BC
void* __cdecl sub_004F59A0(); // 0x004F59A0
int __stdcall WINDOW_GetDimensions(long* pWidth, long* pHeight); // 0x004F59B0
int __stdcall WINDOW_Create(int bWindowed, int nResolution); // 0x004F5610
int __stdcall WINDOW_Resize(int nResolution, int bForceResize); // 0x004F5AA0
void __stdcall WINDOW_EndCutScene(int nResolution); // 0x004F6080
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004F60F0
int __stdcall D2GFX_EndScene(); // 0x004F6190
void __stdcall D2GFX_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6340
void __stdcall D2GFX_ClearScreen(int bPartial); // 0x004F63B0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_004F9250_AppendToDeadList(D2WinControlStrc* pControl); // 0x004F9250
int __stdcall CONTROL_FreeDeadList(); // 0x004F9290
void __cdecl sub_004F97E0_PaintCursor(); // 0x004F97E0
void __cdecl sub_004F9870_DrawFontCaches(); // 0x004F9870
void __stdcall D2CMPSpriteCacheInit(void* pMemPool, unsigned int nMaxSize, int nArg, unsigned int nCacheSize); // 0x005FFD40
void __stdcall sub_005FFE30_FreeTileCache(int bFree); // 0x005FFE30
extern void* ghMainWindow_6F8FE23C; // 0x007D55AC
extern int gbWindowed_6F8FE244; // 0x007D55B4
extern D2WinControlStrc* dword_6F8FE250; // 0x007D55C0
extern int dword_6F8FE254; // 0x007D55C4
extern D2WinControlStrc* gpEditBox_6F8FE258; // 0x007D55C8
extern D2WinControlStrc* dword_6F8FE264; // 0x007D55D4
extern int dword_6F8FE26C; // 0x007D55DC
extern int (__cdecl* dword_6F8FE27C)(); // 0x007D55EC
int __stdcall WINDOW_Destroy(); // 0x004F5900
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

struct tagPOINT
{
    long x;
    long y;
};
extern D2CellFileStrc* gpCursorCellFile; // 0x007D5594
extern int gnCursorFrame; // 0x007D55A0
extern tagPOINT gMousePosition_6F8FE234; // 0x007D55A4

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        unsigned int wParam;
        unsigned short nWParamLo;
    };
    unsigned short nXpos;
    unsigned short nYpos;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
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

extern "C" __declspec(dllimport) void* __stdcall GetDesktopWindow(); // 0x006CC494
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void* hWnd, void* hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags); // 0x006CC4DC
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* lpRect); // 0x006CC4F8
extern "C" __declspec(dllimport) int __stdcall GetWindowPlacement(void* hWnd, tagWINDOWPLACEMENT* lpwndpl); // 0x006CC508
extern "C" __declspec(dllimport) int __stdcall GetMonitorInfoA(void* hMonitor, tagMONITORINFO* lpmi); // 0x006CC510
extern "C" __declspec(dllimport) void* __stdcall MonitorFromWindow(void* hWnd, unsigned long dwFlags); // 0x006CC514
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __cdecl sub_004F5180(); // 0x004F5180
void __stdcall sub_004F5570_GetResolutionSize(int nResolution, long* pWidth, long* pHeight); // 0x004F5570
int __stdcall WINDOW_IsFullScreen(); // 0x004F5A30
int __stdcall sub_004F5BC0_CenterWindow(int nResolution); // 0x004F5BC0

struct Point { int x, y; };

typedef int (__fastcall* ControlFn)(Control*);

struct Control {
    char prefix[0x0C];
    int x, y, width, height;
    char callbacks[0x1C];
    ControlFn shouldHandle;
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

extern D2WinControlStrc* gpControlList_6F8FE24C; // 0x007D55BC
extern void* dword_6F8FE260; // 0x007D55D0
void __stdcall D2Win_COMMANDS_VirtualKey_6F8ADB50(SMSGHANDLER_PARAMS* pMsg); // 0x004F9BF0
D2WinControlStrc* __stdcall sub_004FA200_PickScrollBar(D2WinControlStrc* pScrollBar, D2WinControlStrc* pControl); // 0x004FA200
int __fastcall BUTTON_OnMouseWheelScrolled(D2WinButtonStrc* pButton, int nMouseWheelIncrement); // 0x00500B50
void __fastcall BUTTON_SimulateClick(SMSGHANDLER_PARAMS* pMsg); // 0x00500AB0
int __fastcall sub_6F8AF240(SMSGHANDLER_PARAMS* pMsg, D2WinScrollBarStrc* pScrollBar, int a3); // 0x00508030
int __stdcall POPUP_IsActive(); // 0x005085C0

struct Obj004FA490 { unsigned int dwValue00; };

tagRECT gSavedWindowRect_007D5580; // 0x007D5580

int gnCursorFrame; // 0x007D55A0

D2CellFileStrc* gpBackgroundCellFile; // 0x007D55B0

int gnResolution_6F8FE248; // 0x007D55B8

D2WinControlStrc* gpControlList_6F8FE24C; // 0x007D55BC

D2WinControlStrc* dword_6F8FE25C; // 0x007D55CC

void* dword_6F8FE260; // 0x007D55D0

void* gpfWndProc_6F8FE268; // 0x007D55D8

int dword_6F8FE278; // 0x007D55E8

// 0x004F8F10
int __stdcall D2Win_InitializeSpriteCache(int bWindowed, int nResolution)
{
    dword_6F8FE26C = 1;

    if (!WINDOW_Create(bWindowed, nResolution))
    {
        return 0;
    }

    D2CMPSpriteCacheInit(0, 0x800000, 0x7D000, 0);
    ghMainWindow_6F8FE23C = sub_004F59A0();
    gpBackgroundCellFile = 0;
    gpControlList_6F8FE24C = 0;
    dword_6F8FE250 = 0;
    dword_6F8FE254 = 0;
    dword_6F8FE25C = 0;
    dword_6F8FE260 = 0;
    gpEditBox_6F8FE258 = 0;
    gpfWndProc_6F8FE268 = 0;
    dword_6F8FE264 = 0;
    dword_6F8FE278 = 0;
    gnCursorFrame = 0;
    dword_6F8FE27C = 0;
    gnResolution_6F8FE248 = nResolution;
    gbWindowed_6F8FE244 = bWindowed;
    return 1;
}

// 0x004F9060
void __stdcall D2Win_10004(int nResolution)
{
    gnResolution_6F8FE248 = nResolution;

    if (nResolution == 1)
    {
        sub_005FFE30_FreeTileCache(1);
    }

    WINDOW_EndCutScene(nResolution);

    if (nResolution == 1)
    {
        D2CMPSpriteCacheInit(0, 0x800000, 0x7D000, 0);
    }
}

// 0x004F90A0
int __stdcall sub_004F90A0_SwitchResolution(int nResolution)
{
    if (!gnResolution_6F8FE248 && !gSavedWindowRect_007D5580.right)
    {
        void* hWnd = sub_004F59A0();
        WINDOW_GetDimensions(&gSavedWindowRect_007D5580.right, &gSavedWindowRect_007D5580.bottom);
        GetWindowRect(hWnd, &gSavedWindowRect_007D5580);
    }

    gnResolution_6F8FE248 = nResolution;
    sub_005FFE30_FreeTileCache(1);
    if (!WINDOW_Resize(nResolution, 0))
    {
        sub_00410610_WriteLogLine("Failed to resize window... this is fatal!");
        exit(-1);
    }

    sub_004FB130_SetActiveState(0);
    D2CMPSpriteCacheInit(0, 0x800000, 0x7D000, 0);
    return 1;
}

// 0x004F9310
int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl)
{
    if (dword_6F8FE25C == pControl)
    {
        dword_6F8FE25C = 0;
    }

    if (gpEditBox_6F8FE258 == pControl)
    {
        gpEditBox_6F8FE258 = 0;
    }

    if (dword_6F8FE264 == pControl)
    {
        dword_6F8FE264 = 0;
        dword_6F8FE278 = 0;
    }

    if (dword_6F8FE260 == pControl)
    {
        dword_6F8FE260 = 0;
    }

    D2WinControlStrc* pPrevious = gpControlList_6F8FE24C;
    if (!pPrevious)
    {
        return 0;
    }

    if (pPrevious == pControl)
    {
        gpControlList_6F8FE24C = pControl->pNext;
        sub_004F9250_AppendToDeadList(pControl);
        return 1;
    }

    for (D2WinControlStrc* pCurrent = pPrevious->pNext; pCurrent; pCurrent = pCurrent->pNext)
    {
        if (pCurrent == pControl)
        {
            pPrevious->pNext = pCurrent->pNext;
            sub_004F9250_AppendToDeadList(pControl);
            return 1;
        }

        pPrevious = pCurrent;
    }

    return 1;
}

// 0x004F98E0
void __stdcall sub_004F98E0()
{
    if (WINDOW_GetState())
    {
        return;
    }

    for (D2WinControlStrc* i = gpControlList_6F8FE24C; i; i = i->pNext)
    {
        if (i->pfInitialize)
        {
            i->pfInitialize(i);
        }
    }

    if (gpfWndProc_6F8FE268)
    {
        return;
    }

    long nScreenWidth;
    long nScreenHeight;
    WINDOW_GetDimensions(&nScreenWidth, &nScreenHeight);

    if (D2GFX_StartDraw(0, 0, 0, 0))
    {
        D2GFX_ClearScreen(0);

        if (gpBackgroundCellFile)
        {
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = gpBackgroundCellFile;
            tContext.unk0x40 = 0;
            tContext.nFrame = 0;

            for (int y = 256; y < 768; y += 256)
            {
                for (int x = 0; x < 1024; x += 256)
                {
                    sub_004F6480(&tContext, x, y, -1, 5, 0);
                    ++tContext.nFrame;
                }
            }

            for (int x = 0; x < 1024; x += 256)
            {
                sub_004F6480(&tContext, x, nScreenHeight - 1, -1, 5, 0);
                ++tContext.nFrame;
            }
        }

        for (D2WinControlStrc* i = gpControlList_6F8FE24C; i; i = i->pNext)
        {
            if (i->pfDraw && !(i->dwFlags & gdwBitMasks_006CE268[3]))
            {
                i->pfDraw(i);
            }
        }

        sub_004F9870_DrawFontCaches();

        if (dword_6F8FE278)
        {
            D2GFX_DrawBoxAlpha(0, 0, nScreenWidth, nScreenHeight, 0, 127);
        }

        for (D2WinControlStrc* i = gpControlList_6F8FE24C; i; i = i->pNext)
        {
            if (i->pfDraw && (i->dwFlags & gdwBitMasks_006CE268[3]))
            {
                i->pfDraw(i);
            }
        }

        sub_004F97E0_PaintCursor();
        D2GFX_EndScene();
    }

    CONTROL_FreeDeadList();
}

int dword_6F8FE26C; // 0x007D55DC

void* ghMainWindow_6F8FE23C; // 0x007D55AC

// 0x004F9030
int __stdcall D2Win_CloseSpriteCache()
{
    dword_6F8FE26C = 0;
    ghMainWindow_6F8FE23C = 0;
    sub_005FFE30_FreeTileCache(1);
    WINDOW_Destroy();
    return 1;
}

// 0x004F9190
int __fastcall sub_004F9190()
{
    dword_6F8BDF78 = 0;
    return 1;
}

// 0x004F96F0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags)
{
    if (!pControl)
    {
        return;
    }

    if (nFlags)
    {
        pControl->dwFlags |= gdwBitMasks[0];
    }
    else
    {
        pControl->dwFlags &= gdwInvBitMasks[0];
    }
}

// 0x004F9780
int __fastcall sub_004F9780(D2WinControlStrc* pControl)
{
    D2_ASSERT(pControl, 0x35A);

    return pControl->dwFlags & gdwBitMasks[2];
}

// 0x004F9B30
int __fastcall sub_004F9B30_CONTROL_IsInActiveList(D2WinControlStrc* pControl)
{
    if (dword_6F8FE264)
    {
        for (D2WinControlStrc* p = dword_6F8FE264; p; p = p->pNext)
        {
            if (p == pControl)
            {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

int dword_6F8FE228; // 0x007D5598

int dword_6F8FE22C; // 0x007D559C

// 0x004F97E0
void __cdecl sub_004F97E0_PaintCursor()
{
    if (gpCursorCellFile && dword_6F8BDE18)
    {
        int nX = gMousePosition_6F8FE234.x;
        int nY = gMousePosition_6F8FE234.y;
        dword_6F8FE228 = nX;
        dword_6F8FE22C = nY;

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.nFrame = gnCursorFrame;
        tContext.pCellFile = gpCursorCellFile;
        tContext.unk0x40 = 0;
        sub_004F6480(&tContext, nX <= 0 ? 0 : nX, (nY <= 0 ? 0 : nY) - 1, -1, 5, 0);
    }
}

tagRECT gWindowRect_007C9160; // 0x007C9160

// 0x004F9CC0
void __stdcall sub_004F9CC0_SysCommandMaximizeMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned short nCommand = pMsg->nWParamLo & 0xFFF0;
    if (nCommand == 0xF130 || nCommand == 0xF100 || (nCommand == 0xF010 && WINDOW_IsFullScreen()))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        return;
    }

    if (nCommand != 0xF030)
    {
        return;
    }

    if (WINDOW_IsFullScreen())
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

// 0x004FA1B0
static __forceinline int sub_004FA1B0(Control* control, const Point* point)
{
    if (control->shouldHandle)
        return control->shouldHandle(control);
    const int left = control->x;
    const int bottom = control->y;
    if (point->x >= left && point->y >= bottom - control->height
        && point->x < left + control->width && point->y < bottom)
        return 1;
    return 0;
}

int __stdcall emit_hit_test_004FA1B0(Control* control, const Point* point) { return sub_004FA1B0(control, point); }

inline int CONTROL_IsInActiveList(void* pControl)
{
    if (!dword_6F8FE264)
    {
        return 1;
    }

    for (D2WinControlStrc* p = dword_6F8FE264; p; p = p->pNext)
    {
        if (p == pControl)
        {
            return 1;
        }
    }

    return 0;
}

// 0x004FA340
void __stdcall D2Win_COMMANDS_MouseWheel_6F8AE220(SMSGHANDLER_PARAMS* pMsg)
{
    const int nIncrement = (int)(short)(pMsg->wParam >> 16) / 120;

    if (POPUP_IsActive())
    {
        return;
    }

    D2WinControlStrc* pScrollBar = 0;
    D2WinControlStrc* pFirst = dword_6F8FE264 ? dword_6F8FE264 : gpControlList_6F8FE24C;
    if (pFirst)
    {
        D2WinControlStrc* pControl = pFirst;
        do
        {
            if (pControl->eType == D2WIN_SCROLLBAR && pControl->dwFlags & gdwBitMasks[2] && pControl->dwFlags & gdwBitMasks[0] && SCROLLBAR_GetMaxSteps((D2WinScrollBarStrc*)pControl) > 0)
            {
                pScrollBar = sub_004FA200_PickScrollBar(pScrollBar, pControl);
            }

            pControl = pControl->pNext;
        }
        while (pControl);

        if (pScrollBar && sub_6F8AF240(pMsg, (D2WinScrollBarStrc*)pScrollBar, nIncrement))
        {
            goto done;
        }
    }

    for (D2WinControlStrc* i = pFirst; i; i = i->pNext)
    {
        if (i->eType == D2WIN_BUTTON && BUTTON_OnMouseWheelScrolled((D2WinButtonStrc*)i, nIncrement))
        {
            break;
        }
    }

done:
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004FA760
void __stdcall D2Win_COMMANDS_Escape_6F8ADB10(SMSGHANDLER_PARAMS* pMsg)
{
    if (dword_6F8FE260 && CONTROL_IsInActiveList(dword_6F8FE260))
    {
        pMsg->hWnd = dword_6F8FE260;
        BUTTON_SimulateClick(pMsg);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    D2Win_COMMANDS_VirtualKey_6F8ADB50(pMsg);
}

// 0x004FA490
extern "C" __declspec(dllexport) unsigned int __stdcall sub_004FA490(Obj004FA490* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue00;
}
