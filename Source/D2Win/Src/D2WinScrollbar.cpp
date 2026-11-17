#include "D2Win.h"

#define WM_LBUTTONDOWN 0x201
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WinControlStrc;
struct D2WinTextBoxStrc;
struct tagPOINT;
struct D2CelContextStrc;
struct SMSGHANDLER_PARAMS;
struct D2WinScrollBarStrc;
struct Unicode;
struct D2WinPopUpLineStrc;
struct D2WinPopUpStrc;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
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

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern tagPOINT gMousePosition_6F8FE234; // 0x007D55A4
int __fastcall D2Win_10053(D2WinTextBoxStrc* pTextBox, int nLine); // 0x004FBA30

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};
extern "C" void* __cdecl memset(void* destination, int value, unsigned int size); // 0x00681EF0
int __stdcall SCROLLBAR_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x00508120
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

enum D2C_WinControlTypes
{
    D2WIN_SCROLLBAR = 5,
    D2WIN_POPUP = 11,
};

struct Unicode
{
    unsigned short wChar;
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
    int nCurrentLine;
};
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210
int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl); // 0x004F9310
int __fastcall sub_00508710(D2WinControlStrc* pControl); // 0x00508710
int __fastcall POPUP_Draw(D2WinControlStrc* pControl); // 0x005087A0
extern D2WinPopUpStrc* gpPopUp_0087E974; // 0x0087E974

// 0x00508000
extern "C" int __fastcall sub_00508000_SetScrollBarHandler(D2WinScrollBarStrc* pScrollBar, D2WinMsgHandler pfHandler)
{
    D2_ASSERT(pScrollBar->controlHeader.nType == D2WIN_SCROLLBAR, 0x8B);
    pScrollBar->field_5C = pfHandler;
    return 1;
}

// 0x005080F0
extern "C" int __fastcall sub_005080F0_GetScrollBarField50(D2WinScrollBarStrc* pScrollBar)
{
    D2_ASSERT(pScrollBar->controlHeader.nType == D2WIN_SCROLLBAR, 0xD2);
    return pScrollBar->field_50;
}

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

// 0x00508370
int __fastcall SCROLLBAR_Draw(D2WinControlStrc* pControl)
{
    D2WinScrollBarStrc* pScrollBar = (D2WinScrollBarStrc*)pControl;
    D2_ASSERT(pScrollBar, 0xE7);
    D2_ASSERT(pScrollBar->controlHeader.nType == 5, 0xE8);
    if (!(pScrollBar->controlHeader.dwFlags & gdwBitMasks[2]) ||
        !(pScrollBar->controlHeader.dwFlags & gdwBitMasks[0]))
        return 0;

    D2CelFileStrc* pCellFile = pScrollBar->controlHeader.pCellFile;
    int nX = pScrollBar->controlHeader.nImageX;
    int nY = pScrollBar->controlHeader.nImageY - 1;
    if (pScrollBar->nMaxSteps)
    {
        if (!sub_004FA460())
            pScrollBar->bIsStepIndicatorDragged = 0;
        if (pScrollBar->bIsStepIndicatorDragged)
        {
            SMSGHANDLER_PARAMS msg;
            msg.hWnd = pScrollBar;
            msg.uMessage = 0x201;
            SCROLLBAR_HandleMouseDown(&msg);
        }

        D2CelContextStrc context;
        memset(&context, 0, sizeof(context));
        context.pCellFile = pCellFile;
        context.unk0x40 = 0;
        context.nFrame = pScrollBar->bIsLowerArrowPressed ? 3 : 1;
        sub_004F6480(&context, nX, nY, -1, 5, 0);
        context.nFrame = 5;
        if (pScrollBar->controlHeader.nHeight - 10 > 10)
        {
            int nOffset = 10;
            do
            {
                nOffset += 10;
                nY -= 10;
                sub_004F6480(&context, nX, nY, -1, 5, 0);
            } while (nOffset < pScrollBar->controlHeader.nHeight - 10);
        }
        context.nFrame = pScrollBar->bIsUpperArrowPressed != 0 ? 2 : 0;
        sub_004F6480(&context, nX,
            pScrollBar->controlHeader.nImageY - pScrollBar->controlHeader.nHeight + 9,
            -1, 5, 0);
        context.nFrame = 4;
        sub_004F6480(&context, nX,
            (pScrollBar->controlHeader.nHeight - 30) * pScrollBar->nCurrentStep / pScrollBar->nMaxSteps
                - pScrollBar->controlHeader.nHeight + pScrollBar->controlHeader.nImageY + 19,
            -1, 5, 0);
    }
    return 1;
}

// 0x005088C0
void __stdcall POPUP_Create()
{
    if (gpPopUp_0087E974)
    {
        CONTROL_RemoveFromList(&gpPopUp_0087E974->controlHeader);
        gpPopUp_0087E974 = 0;
    }
    D2WinPopUpStrc* pPopUp = (D2WinPopUpStrc*)FOG_Alloc(sizeof(D2WinPopUpStrc), ".\\Src\\D2WinPopup.cpp", 0x29, 0);
    memset(pPopUp, 0, sizeof(D2WinPopUpStrc));
    pPopUp->controlHeader.nType = D2WIN_POPUP;
    pPopUp->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pPopUp->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pPopUp->controlHeader.dwFlags |= gdwBitMasks_006CE268[3];
    pPopUp->controlHeader.nImageX = gMousePosition_6F8FE234.x;
    pPopUp->controlHeader.nImageY = gMousePosition_6F8FE234.y;
    pPopUp->controlHeader.pfDraw = POPUP_Draw;
    pPopUp->controlHeader.pfInitialize = sub_00508710;
    pPopUp->controlHeader.pNext = 0;
    pPopUp->controlHeader.pfHandleMouseDown = 0;
    pPopUp->controlHeader.pfHandleMouseUp = 0;
    pPopUp->controlHeader.pfHandleCharInput = 0;
    pPopUp->controlHeader.pfHandleVirtualKeyInput = 0;
    pPopUp->controlHeader.field_34 = 0;
    pPopUp->nCurrentLine = -1;
    CONTROL_AppendToList(&pPopUp->controlHeader);
    gpPopUp_0087E974 = pPopUp;
}
