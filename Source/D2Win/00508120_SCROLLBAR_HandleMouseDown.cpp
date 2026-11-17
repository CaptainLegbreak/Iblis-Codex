struct D2CelFileStrc;
struct D2WinControlStrc;
struct D2WinTextBoxStrc;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
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
    D2WinMsgHandler field_5C;
};

struct tagPOINT
{
    int x;
    int y;
};

#define D2WIN_SCROLLBAR 5
#define WM_LBUTTONDOWN 0x201

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern tagPOINT gMousePosition_6F8FE234;                                                                    // 0x007D55A4
int __fastcall D2Win_10053(D2WinTextBoxStrc* pTextBox, int nLine);                                          // 0x004FBA30

// 0x00508120
int __stdcall SCROLLBAR_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinScrollBarStrc* pScrollBar = (D2WinScrollBarStrc*)pMsg->hWnd;
    D2_ASSERT(pScrollBar->controlHeader.nType == D2WIN_SCROLLBAR, 0x12F);

    if (pMsg->uMessage != WM_LBUTTONDOWN)
    {
        return 1;
    }

    if (!(pScrollBar->controlHeader.dwFlags & gdwBitMasks[2]) || !(pScrollBar->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        return 1;
    }

    const int nMaxSteps = pScrollBar->nMaxSteps;
    if (!nMaxSteps)
    {
        return 1;
    }

    const int nX = gMousePosition_6F8FE234.x - pScrollBar->controlHeader.nImageX;
    const int nY = pScrollBar->controlHeader.nHeight - pScrollBar->controlHeader.nImageY + gMousePosition_6F8FE234.y;
    if (nX < 0 || nX > pScrollBar->controlHeader.nWidth)
    {
        return 0;
    }

    int nValue = pScrollBar->controlHeader.nHeight - 10;
    const int nRange = pScrollBar->controlHeader.nHeight - 30;

    const int nCurrentStep = pScrollBar->nCurrentStep;
    const int nIndicatorY = nCurrentStep * nRange / nMaxSteps + 10;
    if (nY >= nIndicatorY && nY <= nIndicatorY + 10)
    {
        pScrollBar->bIsStepIndicatorDragged = 1;
    }

    if (nY < 11 && !pScrollBar->bIsLowerArrowPressed && !pScrollBar->bIsStepIndicatorDragged)
    {
        pScrollBar->bIsUpperArrowPressed = 1;
        pScrollBar->nCurrentStep = nCurrentStep - 1;
    }
    else if (nY > nValue && !pScrollBar->bIsUpperArrowPressed && !pScrollBar->bIsStepIndicatorDragged)
    {
        pScrollBar->bIsLowerArrowPressed = 1;
        pScrollBar->nCurrentStep = nCurrentStep + 1;
    }
    else if (!pScrollBar->bIsLowerArrowPressed && !pScrollBar->bIsUpperArrowPressed)
    {
        if (pScrollBar->bIsStepIndicatorDragged)
        {
            pScrollBar->nCurrentStep = (nY - 11) * nMaxSteps / nRange;
        }
        else
        {
            nValue = pScrollBar->field_50;
            if (!nValue)
            {
                int nPages = nRange / 10;
                if (!nPages)
                {
                    nPages = 1;
                }

                nValue = pScrollBar->nMaxSteps / nPages;
                if (!nValue)
                {
                    nValue = 1;
                }
            }

            const int nStepY = pScrollBar->nCurrentStep * nRange / pScrollBar->nMaxSteps + 10;
            if (nY < nStepY)
            {
                pScrollBar->nCurrentStep = nCurrentStep - nValue;
            }
            else if (nY > nStepY + 10)
            {
                pScrollBar->nCurrentStep = nCurrentStep + nValue;
            }
        }
    }

    if (pScrollBar->nCurrentStep < 0)
    {
        pScrollBar->nCurrentStep = 0;
    }
    else if (pScrollBar->nCurrentStep > pScrollBar->nMaxSteps)
    {
        pScrollBar->nCurrentStep = pScrollBar->nMaxSteps;
    }

    if (pScrollBar->pTextBox && pMsg->uMessage == WM_LBUTTONDOWN)
    {
        D2Win_10053(pScrollBar->pTextBox, pScrollBar->nCurrentStep);
    }

    if (pScrollBar->field_5C)
    {
        pScrollBar->field_5C(pMsg);
    }

    if (pScrollBar->controlHeader.field_34)
    {
        return pScrollBar->controlHeader.field_34(pMsg);
    }

    return 0;
}
