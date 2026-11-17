#include "D2Client.h"

void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg);                                            // 0x004FA470
void __cdecl sub_0042FF20_ShowLocalAddress();                                                               // 0x0042FF20
extern void (__cdecl* gpfnGatewayDone_007795BC)();                                                          // 0x007795BC

// 0x0042F6C0
void __cdecl sub_0042F6C0_SetDone()
{
    gdwGlobal_00779974 = 1;
}

// 0x0042F790
int __stdcall sub_0042F790_ShowCantConnect(SMSGHANDLER_PARAMS* pMsg)
{
    gpfnGatewayDone_007795BC = sub_0042F6C0_SetDone;
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xDE);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControlB = sub_0042F3A0_CreateFromTemplate(0xFD);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlB, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xFE);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FCF80_SetTextA(pControl, "Can't connect to Battle.Net. Try again later.");
    return 1;
}

// 0x0042FE60
int __stdcall sub_0042FE60_FilterChar(void* pControl, int nUnused, const char* pChar)
{
    return 1;
}

// 0x0042FF00
int __stdcall sub_0042FF00_FilterChar(void* pControl, int nUnused, const char* pChar)
{
    return 1;
}

// 0x0042FFD0
int __stdcall sub_0042FFD0_ShowAddress(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0042FF20_ShowLocalAddress();
    return 1;
}
