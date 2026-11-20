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
