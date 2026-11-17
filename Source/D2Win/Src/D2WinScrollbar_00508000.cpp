#include "D2Win.h"

enum D2C_WinControlTypes
{
    D2WIN_SCROLLBAR = 5,
    D2WIN_POPUP = 11,
};
struct D2WinControlStrc;
struct D2WinTextBoxStrc;

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);
typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct tagPOINT
{
    long x;
    long y;
};

struct Unicode
{
    unsigned short wChar;
};

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
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210
int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl);                                           // 0x004F9310
int __fastcall sub_00508710(D2WinControlStrc* pControl);                                                // 0x00508710
int __fastcall POPUP_Draw(D2WinControlStrc* pControl);                                                      // 0x005087A0
extern tagPOINT gMousePosition_6F8FE234;                                                                    // 0x007D55A4
extern D2WinPopUpStrc* gpPopUp_0087E974;                                                                    // 0x0087E974

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
