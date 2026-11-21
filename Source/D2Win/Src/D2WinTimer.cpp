#include "D2Win.h"
#include "D2WinTypes.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2WinControls.h"

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

struct D2WinTimerStrc
{
    D2WinControlStrc controlHeader;
    unsigned int nTimeout;
    unsigned int dwTickCount;
};

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __fastcall sub_6F8B1C60(D2WinControlStrc* pControl);                                                    // 0x004FD860

int __fastcall sub_6F8B1CF0(D2WinControlStrc* pControl);                                                    // 0x004FD8F0

// 0x004FD830
void __fastcall sub_004FD830_2(D2WinTimerStrc* ptTimerData)
{
    D2_ASSERT(ptTimerData->controlHeader.eType == D2WIN_TIMER, 0x3B);
    ptTimerData->controlHeader.pfHandleVirtualKeyInput = 0;
}

// 0x004FD970
int __stdcall TIMER_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinControlStrc* pTimer = (D2WinControlStrc*)pMsg->hWnd;
    D2_ASSERT(pTimer->eType == 8, 0x82);
    if (pMsg->uMessage == 0x102 || pMsg->wParam != 0x20)
        return 0;
    if (pTimer->field_34)
        pTimer->field_34(pMsg);
    return 1;
}

// 0x004FD9D0
D2WinTimerStrc* __fastcall TIMER_Create(unsigned int nTimeout, D2WinMsgHandler pfCallback)
{
    D2WinTimerStrc* pTimer = (D2WinTimerStrc*)FOG_Alloc(sizeof(D2WinTimerStrc), ".\\Src\\D2WinTimer.cpp", 0x1C, 0);
    memset(pTimer, 0, sizeof(D2WinTimerStrc));
    pTimer->controlHeader.eType = D2WIN_TIMER;
    pTimer->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pTimer->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pTimer->nTimeout = nTimeout;
    pTimer->dwTickCount = GetTickCount();
    pTimer->controlHeader.pfInitialize = sub_6F8B1C60;
    pTimer->controlHeader.pNext = 0;
    pTimer->controlHeader.field_34 = pfCallback;
    pTimer->controlHeader.pfHandleVirtualKeyInput = TIMER_HandleVirtualKeyInput;
    CONTROL_AppendToList(&pTimer->controlHeader);
    return pTimer;
}

// 0x004FDA50
void __fastcall sub_004FDA50_2(D2WinTimerStrc* ptTimerData)
{
    D2_ASSERT(ptTimerData->controlHeader.eType == D2WIN_TIMER, 0x45);
    ptTimerData->controlHeader.pfInitialize = sub_6F8B1CF0;
}

