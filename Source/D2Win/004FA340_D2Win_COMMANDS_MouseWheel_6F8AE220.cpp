struct D2CelFileStrc;
struct D2WinControlStrc;
struct D2WinScrollBarStrc;
struct D2WinButtonStrc;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);
typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinControlStrc
{
    int nType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    D2WinControlFn pfDraw;
    D2WinControlFn pfInitialize;
    D2WinMsgHandler pfHandleMouseDown;
    D2WinMsgHandler pfHandleMouseUp;
    D2WinMsgHandler pfHandleCharInput;
    D2WinMsgHandler pfHandleVirtualKeyInput;
    D2WinMsgHandler field_34;
    D2WinControlFn pfShouldMouseInputBeHandled;
    D2WinControlStrc* pNext;
};

#define D2WIN_SCROLLBAR 5
#define D2WIN_BUTTON 6

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2WinControlStrc* gpControlList_6F8FE24C;                                                            // 0x007D55BC
extern void* dword_6F8FE260;                                                                                // 0x007D55D0
extern D2WinControlStrc* dword_6F8FE264;                                                                    // 0x007D55D4
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
void __stdcall D2Win_COMMANDS_VirtualKey_6F8ADB50(SMSGHANDLER_PARAMS* pMsg);                                // 0x004F9BF0
D2WinControlStrc* __stdcall sub_004FA200_PickScrollBar(D2WinControlStrc* pScrollBar, D2WinControlStrc* pControl); // 0x004FA200
int __fastcall BUTTON_OnMouseWheelScrolled(D2WinButtonStrc* pButton, int nMouseWheelIncrement);             // 0x00500B50
void __fastcall BUTTON_SimulateClick(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00500AB0
int __fastcall SCROLLBAR_GetMaxSteps(D2WinScrollBarStrc* pScrollBar);                                       // 0x00507EF0
int __fastcall sub_6F8AF240(SMSGHANDLER_PARAMS* pMsg, D2WinScrollBarStrc* pScrollBar, int a3);              // 0x00508030
int __stdcall POPUP_IsActive();                                                                             // 0x005085C0

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
            if (pControl->nType == D2WIN_SCROLLBAR && pControl->dwFlags & gdwBitMasks[2] && pControl->dwFlags & gdwBitMasks[0] && SCROLLBAR_GetMaxSteps((D2WinScrollBarStrc*)pControl) > 0)
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
        if (i->nType == D2WIN_BUTTON && BUTTON_OnMouseWheelScrolled((D2WinButtonStrc*)i, nIncrement))
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
