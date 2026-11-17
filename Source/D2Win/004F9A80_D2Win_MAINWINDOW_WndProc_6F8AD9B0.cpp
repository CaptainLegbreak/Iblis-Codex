enum D2ControlTypes
{
    D2WIN_EDITBOX = 1,
    D2WIN_IMAGE = 2,
    D2WIN_ANIMIMAGE = 3,
    D2WIN_TEXTBOX = 4,
    D2WIN_SCROLLBAR = 5,
    D2WIN_BUTTON = 6,
    D2WIN_LIST = 7,
    D2WIN_TIMER = 8,
    D2WIN_SMACK = 9,
    D2WIN_PROGRESSBAR = 10,
    D2WIN_POPUP = 11,
    D2WIN_ACCOUNTLIST = 12,
    D2WIN_IMAGE2 = 13,
};

#define D2WIN_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2WIN_MIN(a, b) (((a) < (b)) ? (a) : (b))

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

struct tagPOINT
{
    long x;
    long y;
};

struct tagMSG
{
    void* hwnd;
    unsigned int message;
    unsigned int wParam;
    long lParam;
    unsigned long time;
    tagPOINT pt;
};

struct Unicode
{
    unsigned short wChar;
};

typedef long (__stdcall* WNDPROC)(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam);

struct D2CelFileStrc;
struct D2WinControlStrc;
struct D2WinEditBoxStrc;

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

struct D2WinTextBoxLineStrc
{
    Unicode* pColumns[5];
    int field_14;
    char field_18;
    char field_19;
    char field_1A;
    char field_1B;
    D2WinTextBoxLineStrc* pNext;
};

struct D2WinScrollBarStrc;

struct D2WinTextBoxStrc
{
    D2WinControlStrc controlHeader;
    int field_40;
    int field_44;
    D2WinTextBoxLineStrc* pFirstLine;
    D2WinTextBoxLineStrc* pLastLine;
    D2WinTextBoxLineStrc* pCurrentLine;
    int nNumLines;
    int nLine;
    int dwTextBoxFlags;
    int nCurrentLine;
    int nNumColumns;
    int unk0x68[5];
    int unk0x7C[5];
    D2WinScrollBarStrc* pScrollBar;
};

struct D2WinImageClickRectStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    D2WinMsgHandler pCallback;
};

struct D2WinImage2Strc
{
    D2WinControlStrc controlHeader;
    int nFrame;
    int eDrawMode;
    D2WinImageClickRectStrc* pClickRect;
};

struct D2WinEditBoxStrc
{
    D2WinControlStrc controlHeader;
    int field_40;
    int field_44;
};

struct D2HoverLineStrc
{
    Unicode wszText[256];
    int nWidth;
    int nHeight;
};

struct D2WinListDataStrc
{
    Unicode wszText[256];
    int field_200;
    D2WinMsgHandler field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    char field_218;
    char field_219;
    char field_21A;
    char field_21B;
    int field_21C;
    D2WinListDataStrc* pNext;
};

struct D2WinListStrc
{
    D2WinControlStrc controlHeader;
    int eFont;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int nWidestEntry;
    D2WinListDataStrc* pDataList;
    D2WinListDataStrc* pSelectedDataEntry;
};

struct D2WinAccountListDataStrc
{
    char szText[50];
    short field_32;
    D2WinAccountListDataStrc* pNext;
};

struct D2WinAccountListStrc
{
    D2WinControlStrc controlHeader;
    D2WinAccountListDataStrc* pDataList;
    D2WinAccountListDataStrc* pSelectedDataEntry;
};

struct D2WinScrollBarStrc
{
    D2WinControlStrc controlHeader;
    int bIsUpperArrowPressed;
    int bIsLowerArrowPressed;
    int nMaxSteps;
    int nCurrentStep;
    int field_50;
    D2WinTextBoxStrc* pTextBox;
    int bIsStepIndicatorDragged;
    void (__stdcall* field_5C)(SMSGHANDLER_PARAMS* pMsg);
};

struct D2WinPopUpLineStrc
{
    Unicode wszText[64];
    void (__stdcall* pfHandleMouseInput)();
};

struct D2WinPopUpStrc
{
    D2WinControlStrc controlHeader;
    int nLines;
    D2WinPopUpLineStrc lines[8];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const tagMSG* pMsg);                       // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const tagMSG* pMsg);                        // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(tagMSG* pMsg, void* hWnd, unsigned int uMsgFilterMin, unsigned int uMsgFilterMax, unsigned int wRemoveMsg); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall GetMessageA(tagMSG* pMsg, void* hWnd, unsigned int uMsgFilterMin, unsigned int uMsgFilterMax); // 0x006CC484
extern "C" __declspec(dllimport) long __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam); // 0x006CC488
extern "C" __declspec(dllimport) void __stdcall PostQuitMessage(int nExitCode);                             // 0x006CC4A4

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00420290
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam, int* pUseResult, int* pResult); // 0x00420B00
int __stdcall D2GFX_Initialize(void* hInstance, WNDPROC pfWndProc, int nRenderMode, int bWindowed);         // 0x004F52E0
void __stdcall sub_004F98E0();                                                                               // 0x004F98E0
int __cdecl sub_004F9200();                                                                                 // 0x004F9200
void __stdcall D2Win_COMMANDS_MouseMove_6F8AD670(SMSGHANDLER_PARAMS* pMsg);                                 // 0x004FA6B0
void __stdcall D2Win_10168_WINMAIN_CreateScreenshot();                                                      // 0x004FA7A0
int __fastcall D2Win_10053(D2WinTextBoxStrc* pTextBox, int nLine);                                          // 0x004FBA30
int __fastcall D2Win_10055(D2WinTextBoxStrc* pTextBox);                                                     // 0x004FBAB0
int __stdcall sub_004FE3B0_EditBoxClick(SMSGHANDLER_PARAMS* pMsg, int nX, int nY);                          // 0x004FE3B0
int __fastcall D2Win_10074(D2WinEditBoxStrc* pEditBox, unsigned char nChar);                                // 0x004FEAE0
int __fastcall sub_6F8A7AB0(D2WinEditBoxStrc* pEditBox, char nKey);                                         // 0x004FF050
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __stdcall POPUP_Destroy();                                                                             // 0x005085A0
int __stdcall POPUP_IsActive();                                                                             // 0x005085C0
int __stdcall POPUP_HandleMouseButtonInput(SMSGHANDLER_PARAMS* pMsg);                                       // 0x005086A0
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __stdcall D2CMP_SetCompressedDataMode(int bCompress);                                                  // 0x005FE280

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
extern int dword_6F8BDE20;                                                                                  // 0x0072DC44
extern int dword_6F8BDF78;                                                                                  // 0x0072DDD4
extern int gdwGlobal_007D5590;                                                                              // 0x007D5590
tagPOINT gMousePosition_6F8FE234;                                                                           // 0x007D55A4
extern D2WinControlStrc* gpControlList_6F8FE24C;                                                            // 0x007D55BC
int dword_6F8FE254;                                                                                         // 0x007D55C4
extern D2WinEditBoxStrc* gpEditBox_6F8FE258;                                                                // 0x007D55C8
extern D2WinEditBoxStrc* dword_6F8FE25C;                                                                    // 0x007D55CC
D2WinControlStrc* dword_6F8FE264;                                                                           // 0x007D55D4
extern WNDPROC gpfWndProc_6F8FE268;                                                                         // 0x007D55D8
extern int dword_6F8FE26C;                                                                                  // 0x007D55DC
int gbIsMouseButtonPressed;                                                                                 // 0x007D55E0
extern int (__cdecl* dword_6F8FE27C)();                                                                     // 0x007D55EC
int dword_6F8FE280;                                                                                         // 0x007D55F4
extern D2WinPopUpStrc* gpPopUp_0087E974;                                                                    // 0x0087E974

static int CONTROL_IsMouseInside_004FA860(D2WinControlStrc* pControl)
{
    const int nImageY = pControl->nImageY;
    return gMousePosition_6F8FE234.x >= pControl->nImageX && gMousePosition_6F8FE234.y >= nImageY - pControl->nHeight
        && gMousePosition_6F8FE234.x < pControl->nImageX + pControl->nWidth && gMousePosition_6F8FE234.y < nImageY;
}

// 0x004F9A80
long __stdcall D2Win_MAINWINDOW_WndProc_6F8AD9B0(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam)
{
    if (!dword_6F8FE26C)
    {
        return 0;
    }

    if (gpfWndProc_6F8FE268)
    {
        return gpfWndProc_6F8FE268(hWnd, uMsg, wParam, lParam);
    }

    int bUseResult = 0;
    int lResult = 0;
    if (uMsg == 0x10)
    {
        dword_6F8FE280 = 1;
        PostQuitMessage(0);
        return 0;
    }

    if (SMsgDispatchMessage(hWnd, uMsg, wParam, lParam, &bUseResult, &lResult) && bUseResult)
    {
        return lResult;
    }

    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

// 0x004F9B60
void __stdcall D2Win_COMMANDS_Char_6F8ADA80(SMSGHANDLER_PARAMS* pMsg)
{
    const int nChar = pMsg->wParam;
    if (dword_6F8FE25C)
    {
        if (dword_6F8FE264)
        {
            for (D2WinControlStrc* i = dword_6F8FE264; i; i = i->pNext)
            {
                if ((D2WinEditBoxStrc*)i == dword_6F8FE25C)
                {
                    goto check_edit_box;
                }
            }
            goto dispatch;
        }

check_edit_box:
        if (D2Win_10074(dword_6F8FE25C, nChar))
        {
            goto done;
        }
    }

dispatch:
    {
        D2WinControlStrc* pControl = dword_6F8FE264;
        if (!pControl)
        {
            pControl = gpControlList_6F8FE24C;
        }

        while (pControl)
        {
            if (pControl->pfHandleCharInput)
            {
                pMsg->hWnd = pControl;
                ++dword_6F8FE254;
                const int nResult = pControl->pfHandleCharInput(pMsg);
                --dword_6F8FE254;
                if (nResult)
                {
                    break;
                }
            }
            pControl = pControl->pNext;
        }
    }

done:
    sub_00420290_HandleMsg(pMsg);
}

// 0x004F9BF0
void __stdcall D2Win_COMMANDS_VirtualKey_6F8ADB50(SMSGHANDLER_PARAMS* pMsg)
{
    const int nKey = pMsg->wParam;
    if (dword_6F8FE25C)
    {
        if (dword_6F8FE264)
        {
            for (D2WinControlStrc* i = dword_6F8FE264; i; i = i->pNext)
            {
                if ((D2WinEditBoxStrc*)i == dword_6F8FE25C)
                {
                    goto check_edit_box;
                }
            }
            goto dispatch;
        }

check_edit_box:
        if (sub_6F8A7AB0(dword_6F8FE25C, nKey))
        {
            goto done;
        }
    }

dispatch:
    {
        D2WinControlStrc* pControl = dword_6F8FE264;
        if (!pControl)
        {
            pControl = gpControlList_6F8FE24C;
        }

        while (pControl)
        {
            if (pControl->pfHandleVirtualKeyInput)
            {
                pMsg->hWnd = pControl;
                ++dword_6F8FE254;
                const int nResult = pControl->pfHandleVirtualKeyInput(pMsg);
                --dword_6F8FE254;
                if (nResult)
                {
                    break;
                }
            }
            pControl = pControl->pNext;
        }
    }

done:
    sub_00420290_HandleMsg(pMsg);
}

// 0x004FA520
int __stdcall D2Win_CreateWindow(void* hInstance, int nRenderMode, int bWindowed, int bCompress)
{
    gdwGlobal_007D5590 = nRenderMode;
    D2CMP_SetCompressedDataMode(bCompress);
    return D2GFX_Initialize(hInstance, D2Win_MAINWINDOW_WndProc_6F8AD9B0, nRenderMode, bWindowed);
}

// 0x004FA590
int __stdcall sub_004FA590(void (__stdcall* pCallback)(unsigned long))
{
    unsigned long dwCounter = 0;
    unsigned long dwTickCount = GetTickCount();
    int nSleepMillis = 0;

    while (dword_6F8BDF78)
    {
        tagMSG tMsg;
        if (PeekMessageA(&tMsg, 0, 0, 0, 0))
        {
            dword_6F8BDF78 = GetMessageA(&tMsg, 0, 0, 0);
            if (!dword_6F8BDF78 && dword_6F8FE27C)
            {
                dword_6F8FE27C();
            }

            TranslateMessage(&tMsg);
            DispatchMessageA(&tMsg);
        }
        else
        {
            unsigned long dwTickDiff = GetTickCount() - dwTickCount;
            dwTickCount = GetTickCount();
            if (dwTickDiff > 1000)
            {
                dwTickDiff = 1000;
            }

            nSleepMillis -= dwTickDiff;
            if (nSleepMillis <= 0)
            {
                nSleepMillis += 40;
                if (nSleepMillis < -1000)
                {
                    nSleepMillis = 0;
                }

                if (pCallback)
                {
                    pCallback(dwCounter);
                    dwCounter += 1;
                }

                sub_004F98E0();
            }

            dword_6F8FE25C = gpEditBox_6F8FE258;
            unsigned long dwSleepMillis = nSleepMillis;
            if (dwSleepMillis > 20)
            {
                dwSleepMillis = 20;
            }

            if (dword_6F8BDE20)
            {
                dwSleepMillis = 0;
            }

            Sleep(dwSleepMillis);
        }
    }

    sub_004F98E0();
    if (!dword_6F8FE280)
    {
        dword_6F8BDF78 = 1;
    }

    return 0;
}

// 0x004FA840
void __stdcall D2Win_COMMANDS_Snapshot_6F8ADE70(SMSGHANDLER_PARAMS* pMsg)
{
    D2Win_10168_WINMAIN_CreateScreenshot();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x004FA860
void __stdcall D2Win_COMMANDS_MouseButton_6F8AE070(SMSGHANDLER_PARAMS* pMsg)
{
    D2Win_COMMANDS_MouseMove_6F8AD670(pMsg);
    if (POPUP_IsActive())
    {
        const int bInputHandled = POPUP_HandleMouseButtonInput(pMsg);
        POPUP_Destroy();
        if (bInputHandled)
        {
            return;
        }
    }

    D2WinControlStrc* pControl = dword_6F8FE264;
    if (!pControl)
    {
        pControl = gpControlList_6F8FE24C;
    }

    switch (pMsg->uMessage)
    {
    case 0x201:
    case 0x204:
        gbIsMouseButtonPressed = 1;
        while (pControl)
        {
            if (pControl->pfShouldMouseInputBeHandled ? pControl->pfShouldMouseInputBeHandled(pControl) : CONTROL_IsMouseInside_004FA860(pControl))
            {
                pMsg->hWnd = pControl;
                if (pControl->pfHandleMouseDown)
                {
                    ++dword_6F8FE254;
                    const int nResult = pControl->pfHandleMouseDown(pMsg);
                    --dword_6F8FE254;
                    if (nResult)
                    {
                        break;
                    }
                }
            }
            pControl = pControl->pNext;
        }
        break;

    case 0x202:
    case 0x205:
        gbIsMouseButtonPressed = 0;
        while (pControl)
        {
            pMsg->hWnd = pControl;
            if (pControl->pfHandleMouseUp)
            {
                ++dword_6F8FE254;
                pControl->pfHandleMouseUp(pMsg);
                --dword_6F8FE254;
            }
            pControl = pControl->pNext;
        }
        break;
    }

    sub_00420290_HandleMsg(pMsg);
}

// 0x004FBB90
Unicode* __fastcall D2Win_10196(D2WinTextBoxStrc* pTextBox, int nLineNum, int nColumnNum)
{
    D2_ASSERT(pTextBox, 0x2C2);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x2C3);
    D2_ASSERT(nLineNum <= pTextBox->nNumLines, 0x2C4);
    D2_ASSERT(nColumnNum < 5, 0x2C5);

    D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine;
    int i = 0;
    while (i < nLineNum)
    {
        if (!pLine->pNext)
        {
            break;
        }

        pLine = pLine->pNext;
        ++i;
    }

    D2_ASSERT(pLine, 0x2CF);
    D2_ASSERT(i == nLineNum, 0x2D0);

    return pLine->pColumns[nColumnNum];
}

// 0x004FBDE0
int __fastcall D2Win_10188(D2WinTextBoxStrc* pTextBox, int nLineNum, int a3)
{
    D2_ASSERT(pTextBox, 0x368);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x369);

    if (nLineNum == -1)
    {
        for (D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine; pLine; pLine = pLine->pNext)
        {
            pLine->field_14 = a3;
        }

        return 1;
    }

    D2_ASSERT(nLineNum <= pTextBox->nNumLines, 0x378);

    D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine;
    int i = 0;
    while (i < nLineNum)
    {
        if (!pLine->pNext)
        {
            break;
        }

        pLine = pLine->pNext;
        ++i;
    }

    D2_ASSERT(pLine, 0x382);
    D2_ASSERT(i == nLineNum, 0x383);

    pLine->field_14 = a3;
    return 1;
}

// 0x004FC3F0
int __stdcall TEXTBOX_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinTextBoxStrc* pTextBox = (D2WinTextBoxStrc*)pMsg->hWnd;

    D2_ASSERT(pTextBox, 0x501);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0x502);

    if (!(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[0])
        || pTextBox->nNumLines < 1 || pTextBox->nCurrentLine == -1 || sub_004F9200())
    {
        return 0;
    }

    const int nNumLines = pTextBox->nNumLines;
    int nLine = pTextBox->nLine;
    int nCurrentLine = pTextBox->nCurrentLine;
    const int nVisibleLines = D2Win_10055((D2WinTextBoxStrc*)pMsg->hWnd);

    switch (pMsg->wParam)
    {
    case 0x21:
        if (nCurrentLine > nLine)
        {
            nCurrentLine = nLine;
        }
        else if (nLine > 0)
        {
            nLine = D2WIN_MAX(nLine - nVisibleLines + 1, 0);
            nCurrentLine = nLine;
        }
        break;

    case 0x22:
    {
        const int nLastVisible = nVisibleLines + nLine - 1;
        if (nCurrentLine < nLastVisible)
        {
            nCurrentLine = D2WIN_MIN(nLastVisible, nNumLines - 1);
        }
        else if (nLine < nNumLines - nVisibleLines)
        {
            nLine = D2WIN_MIN(nLastVisible, nNumLines - nVisibleLines);
            nCurrentLine = D2WIN_MIN(nVisibleLines + nLine - 1, nNumLines - 1);
        }
        break;
    }

    case 0x26:
        if (nCurrentLine > 0)
        {
            --nCurrentLine;
            if (nCurrentLine < nLine)
            {
                nLine = nCurrentLine;
            }
            else if (nCurrentLine > nVisibleLines + nLine - 1)
            {
                nLine = nCurrentLine - nVisibleLines + 1;
            }
        }
        break;

    case 0x28:
        if (nCurrentLine < nNumLines - 1)
        {
            ++nCurrentLine;
            if (nCurrentLine < nLine)
            {
                nLine = nCurrentLine;
            }
            else if (nCurrentLine > nVisibleLines + nLine - 1)
            {
                nLine = nCurrentLine - nVisibleLines + 1;
            }
        }
        break;

    case 0x24:
        nCurrentLine = 0;
        nLine = 0;
        break;

    case 0x23:
        nCurrentLine = nNumLines - 1;
        nLine = nNumLines - nVisibleLines;
        break;
    }

    const int bHasChanged = nCurrentLine != pTextBox->nCurrentLine;
    pTextBox->nCurrentLine = nCurrentLine;

    if (nNumLines > nVisibleLines && nLine != pTextBox->nLine)
    {
        D2Win_10053((D2WinTextBoxStrc*)pMsg->hWnd, nLine);
    }

    if (bHasChanged && pTextBox->controlHeader.field_34)
    {
        pTextBox->controlHeader.field_34(pMsg);
    }

    return 0;
}

// 0x004FD5D0
int __stdcall IMAGE2_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinImage2Strc* pImage = (D2WinImage2Strc*)pMsg->hWnd;

    D2_ASSERT(pImage->controlHeader.nType == D2WIN_IMAGE, 0x159);

    if (!(pImage->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pImage->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const int nX = gMousePosition_6F8FE234.x - pImage->controlHeader.nImageX;
    const int nY = gMousePosition_6F8FE234.y + pImage->controlHeader.nHeight - pImage->controlHeader.nImageY;

    D2WinImageClickRectStrc* pClickRect = pImage->pClickRect;
    if (pClickRect)
    {
        for (int i = 0; pClickRect[i].pCallback; ++i)
        {
            const int nRectX = pClickRect[i].nX;
            const int nRectY = pClickRect[i].nY;
            if (nX >= nRectX && nY >= nRectY - pClickRect[i].nHeight && nX < nRectX + pClickRect[i].nWidth && nY < nRectY)
            {
                return pClickRect[i].pCallback(pMsg);
            }
        }
    }

    if (((D2WinImage2Strc*)pMsg->hWnd)->controlHeader.field_34)
    {
        return ((D2WinImage2Strc*)pMsg->hWnd)->controlHeader.field_34(pMsg);
    }

    return 0;
}

// 0x004FE710
int __stdcall sub_004FE710_EditBoxMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinEditBoxStrc* pEditBox = (D2WinEditBoxStrc*)pMsg->hWnd;

    D2_ASSERT(pEditBox, 0x7E5);
    D2_ASSERT(pEditBox->controlHeader.nType == D2WIN_EDITBOX, 0x7E6);

    const int nX = gMousePosition_6F8FE234.x - pEditBox->field_40 - pEditBox->controlHeader.nImageX;
    const int nY = gMousePosition_6F8FE234.y + pEditBox->controlHeader.nHeight - pEditBox->field_44 - pEditBox->controlHeader.nImageY;
    return sub_004FE3B0_EditBoxClick(pMsg, nX, nY);
}

// 0x00503FA0
void __stdcall sub_00503FA0_AddHoverLine(const Unicode* wszText, D2HoverLineStrc* pLines, int* pCount, int* pMaxWidth, int* pTotalHeight)
{
    D2HoverLineStrc* pLine = &pLines[*pCount];
    D2_ASSERT(*pCount < 7, 0x738);

    sub_005267E0(pLine->wszText, wszText);
    D2Win_10131_GetTextDimensions(pLine->wszText, &pLine->nWidth, &pLine->nHeight);
    *pMaxWidth = *pMaxWidth > pLine->nWidth + 6 ? *pMaxWidth : pLine->nWidth + 6;
    *pTotalHeight += pLine->nHeight;
    ++*pCount;
}

// 0x00506EC0
void __fastcall D2Win_10137(D2WinListStrc* pList, const Unicode* wszText, D2WinMsgHandler a3, char a4, int a5, int a6, int a7)
{
    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0xA1);

    sub_00502EF0(pList->eFont);

    D2WinListDataStrc* pNewData = (D2WinListDataStrc*)FOG_Alloc(sizeof(D2WinListDataStrc), ".\\Src\\D2WinList.cpp", 0xA5, 0);
    D2_ASSERT(sub_00526800(wszText) < 256, 0xA6);

    sub_005267E0(pNewData->wszText, wszText);

    int nTextWidth;
    int nTextHeight;
    D2Win_10131_GetTextDimensions(wszText, &nTextWidth, &nTextHeight);
    nTextWidth += 8;
    if (nTextWidth > pList->nWidestEntry)
    {
        pList->nWidestEntry = nTextWidth;
    }

    pNewData->field_200 = nTextWidth;
    pNewData->field_204 = a3;
    pNewData->field_208 = 0;
    pNewData->field_20C = 0;
    pNewData->field_210 = 0;
    pNewData->field_214 = 0;
    pNewData->field_218 = a4;
    pNewData->field_21C = a5;

    if (!a6)
    {
        D2WinListDataStrc* pLast = pList->pDataList;
        if (pLast)
        {
            while (pLast->pNext)
            {
                pLast = pLast->pNext;
            }

            pLast->pNext = pNewData;
            pNewData->pNext = 0;
        }
        else
        {
            pList->pDataList = pNewData;
            pNewData->pNext = 0;
        }
    }
    else
    {
        pNewData->pNext = pList->pDataList;
        pList->pDataList = pNewData;
    }

    ++pList->field_50;
    sub_00502EF0(1);

    if (a7)
    {
        pList->pSelectedDataEntry = pNewData;
        pList->field_54 = pList->field_50 - 1;
    }
}

// 0x00507A10
int __stdcall ACCOUNTLIST_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinAccountListStrc* pAccountList = (D2WinAccountListStrc*)pMsg->hWnd;

    D2_ASSERT(pAccountList->controlHeader.nType == D2WIN_ACCOUNTLIST, 0x10D);

    if (!(pAccountList->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pAccountList->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    if (!pAccountList->pDataList)
    {
        return 0;
    }

    const int nIndex = (gMousePosition_6F8FE234.x - pAccountList->controlHeader.nImageX) / 120
        + 6 * ((pAccountList->controlHeader.nHeight - pAccountList->controlHeader.nImageY + gMousePosition_6F8FE234.y + 4) / 20);
    D2WinAccountListDataStrc* pData = pAccountList->pDataList;
    for (int nCounter = 0; pData; ++nCounter)
    {
        if (nCounter == nIndex)
        {
            pAccountList->pSelectedDataEntry = pData;
            return 1;
        }
        pData = pData->pNext;
    }

    pAccountList->pSelectedDataEntry = 0;
    return 1;
}

// 0x00508030
int __fastcall sub_6F8AF240(SMSGHANDLER_PARAMS* pMsg, D2WinScrollBarStrc* pScrollBar, int a3)
{
    D2_ASSERT(pScrollBar->controlHeader.nType == D2WIN_SCROLLBAR, 0x99);

    if (!pScrollBar->bIsStepIndicatorDragged)
    {
        if (a3 > 0)
        {
            --pScrollBar->nCurrentStep;
            pScrollBar->bIsUpperArrowPressed = 1;
        }
        else if (a3 < 0)
        {
            ++pScrollBar->nCurrentStep;
            pScrollBar->bIsLowerArrowPressed = 1;
        }

        if (pScrollBar->nCurrentStep < 0)
        {
            pScrollBar->nCurrentStep = 0;
        }
        else if (pScrollBar->nCurrentStep > pScrollBar->nMaxSteps)
        {
            pScrollBar->nCurrentStep = pScrollBar->nMaxSteps;
        }

        if (pScrollBar->pTextBox)
        {
            D2Win_10053(pScrollBar->pTextBox, pScrollBar->nCurrentStep);
        }

        if (pScrollBar->field_5C)
        {
            pScrollBar->field_5C(pMsg);
        }
    }

    return 0;
}

// 0x00508610
int __stdcall POPUP_AddLine(D2WinPopUpLineStrc* pPopUpLine)
{
    D2WinPopUpStrc* pPopUp = gpPopUp_0087E974;

    D2_ASSERT(pPopUp->controlHeader.nType == D2WIN_POPUP, 0x74);

    if (pPopUp->nLines >= 8)
    {
        return 0;
    }

    pPopUp->lines[pPopUp->nLines] = *pPopUpLine;
    sub_00502EF0(1);

    const int nTextWidth = sub_00501820(pPopUpLine->wszText);
    pPopUp->controlHeader.nWidth = pPopUp->controlHeader.nWidth > nTextWidth ? pPopUp->controlHeader.nWidth : nTextWidth;
    ++pPopUp->nLines;
    pPopUp->controlHeader.nHeight = 20 * pPopUp->nLines;
    return 1;
}

#include "gen/data/Source/D2Win/004F9A80_D2Win_MAINWINDOW_WndProc_6F8AD9B0.inc"
