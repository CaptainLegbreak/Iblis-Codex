#include "D2Client.h"
#include "D2StormTypes.h"

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __cdecl sub_00466FE0(); // 0x00466FE0
int __fastcall sub_00469D90(int nA, int nB); // 0x00469D90
unsigned short __fastcall sub_00469AA0(int nA, int nB); // 0x00469AA0
void __cdecl sub_0044C060_Refresh(); // 0x0044C060
void __cdecl sub_00466FF0(); // 0x00466FF0
extern int gdwGlobal_007A0664; // 0x007A0664
extern int gdwGlobal_007A065C; // 0x007A065C
extern int gdwGlobal_007A0654; // 0x007A0654
extern int gdwGlobal_007A0670; // 0x007A0670
extern int gdwGlobal_007A0658; // 0x007A0658

// 0x0044C5E0
void __stdcall sub_0044C5E0_ActivateMsg(SMSGHANDLER_PARAMS* pMessage)
{
    gdwGlobal_0070F7E0 = pMessage->wParam;
    if (pMessage->wParam)
    {
        sub_00455F20(0xD, 1, 0);
        gdwGlobal_007A0664 = 0;
        sub_00466FE0();
        sub_004FB130_SetActiveState(0);
        pMessage->bReturn = 0;
        return;
    }

    if (sub_00469D90(0x22, 1) && (static_cast<unsigned short>(GetAsyncKeyState(sub_00469AA0(0x22, 1))) & 0x8000) == 0)
    {
        gdwGlobal_007A065C = 0;
    }

    if (gdwGlobal_0070F234 != 0x10)
    {
        sub_0044C060_Refresh();
    }

    if (gdwGlobal_0070F2BC != 0x10)
    {
        gdwGlobal_0070F2BC = 0x10;
        gdwGlobal_007A0654 = 0;
        gdwGlobal_007A0670 = 1;
        gdwGlobal_007A0658 = 0;
        sub_00466FF0();
        pMessage->bReturn = 0;
        return;
    }

    pMessage->bReturn = 0;
}

#include "gen/data/Source/D2Client/Unknown_0044C5E0.inc"
