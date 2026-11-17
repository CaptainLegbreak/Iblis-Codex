struct D2WinControlStrc;

void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __cdecl sub_00439210_Redraw();                                                                         // 0x00439210
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __cdecl sub_0043A800();                                                                                // 0x0043A800

extern int gnSelected_0070CC00;                                                                             // 0x0070CC00
extern int gnSelectionA_0070CC04;                                                                           // 0x0070CC04
extern D2WinControlStrc* gpControl_007799F4;                                                                // 0x007799F4
extern D2WinControlStrc* gpControl_007799F8;                                                                // 0x007799F8
extern D2WinControlStrc* gpControl_00779A1C;                                                                // 0x00779A1C
extern char gData_00779A40[];                                                                               // 0x00779A40
extern D2WinControlStrc* gpControl_00779B64;                                                                // 0x00779B64
extern D2WinControlStrc* gpControl_00779C68;                                                                // 0x00779C68
extern D2WinControlStrc* gpControl_00779C80;                                                                // 0x00779C80
extern char gszName_00779C88[];                                                                             // 0x00779C88
extern D2WinControlStrc* gpControl_00779D90;                                                                // 0x00779D90
int gdwGlobal_00779DB8;                                                                                     // 0x00779DB8
extern int gdwGlobal_00779DC4;                                                                              // 0x00779DC4

// 0x0043A730
void __cdecl sub_0043A730_UpdateButtons()
{
    sub_004F96F0_ControlClearState(gpControl_007799F4, (gdwGlobal_00779DC4 > 0 && gnSelected_0070CC00 > gnSelectionA_0070CC04) ? 1 : 0);
    sub_004F96F0_ControlClearState(gpControl_00779C68, gdwGlobal_00779DC4 > 0);
    sub_004F96F0_ControlClearState(gpControl_007799F8, 1);
    sub_004F96F0_ControlClearState(gpControl_00779A1C, 1);
    sub_004F96F0_ControlClearState(gpControl_00779B64, 1);
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_004F96F0_ControlClearState(gpControl_00779C80, 1);
        sub_004F96F0_ControlClearState(gpControl_00779D90, gdwGlobal_00779DB8 == 0);
    }
    gnSelected_0070CC00 = 0;
    sub_00439210_Redraw();
}

// 0x0043A9A0
int __stdcall sub_0043A9A0_CopyName(int nArg)
{
    SStrCopy(gszName_00779C88, gData_00779A40, 0x7FFFFFFF);
    sub_0043A800();
    return 1;
}
