#include "D2Win.h"
#include "D2WinTypes.h"
#include "D2Unicode.h"
#include "D2Win32Types.h"

enum D2C_WinControlTypes
{
    D2WIN_POPUP = 11,
};

struct D2WinControlStrc;

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);
typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

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
extern tagPOINT gMousePosition_6F8FE234;                                                                    // 0x007D55A4

D2WinPopUpStrc* gpPopUp_0087E974;                                                                           // 0x0087E974

int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl);                                           // 0x004F9310

// 0x00508710
int __fastcall sub_00508710(D2WinControlStrc* pControl)
{
    D2WinPopUpStrc* pPopUp = (D2WinPopUpStrc*)pControl;

    D2_ASSERT(pPopUp->controlHeader.eType == D2WIN_POPUP, 0xA6);

    if (!(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    pPopUp->nCurrentLine = -1;

    const int nX = gMousePosition_6F8FE234.x - pPopUp->controlHeader.nImageX;
    const int nY = pPopUp->controlHeader.nHeight - pPopUp->controlHeader.nImageY + gMousePosition_6F8FE234.y;

    if (nX >= 0 && nX <= pPopUp->controlHeader.nWidth && nY >= 0 && nY <= pPopUp->controlHeader.nHeight)
    {
        pPopUp->nCurrentLine = nY / 20;
    }

    return 1;
}

// 0x005085A0
int __stdcall POPUP_Destroy()
{
    int nResult = 0;
    if (gpPopUp_0087E974)
    {
        nResult = CONTROL_RemoveFromList(&gpPopUp_0087E974->controlHeader);
        gpPopUp_0087E974 = 0;
    }
    return nResult;
}

// 0x005085C0
int __stdcall POPUP_IsActive()
{
    D2WinPopUpStrc* pPopUp = gpPopUp_0087E974;
    if (!pPopUp)
        return 0;
    D2_ASSERT(pPopUp->controlHeader.eType == D2WIN_POPUP, 0x62);
    if (!(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
        return 0;
    return 1;
}

// 0x005086A0
int __stdcall POPUP_HandleMouseButtonInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinPopUpStrc* pPopUp = gpPopUp_0087E974;
    D2_ASSERT(pPopUp->controlHeader.eType == D2WIN_POPUP, 0x90);
    if (!(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
        return 0;
    const int nCurrentLine = pPopUp->nCurrentLine;
    if (nCurrentLine == -1)
        return 0;
    void (__stdcall* pfHandleMouseInput)() = pPopUp->lines[nCurrentLine].pfHandleMouseInput;
    if (!pfHandleMouseInput)
        return 0;
    pfHandleMouseInput();
    return 1;
}
