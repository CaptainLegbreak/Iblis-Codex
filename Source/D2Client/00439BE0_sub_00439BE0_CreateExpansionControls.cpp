struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

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

int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId);                              // 0x0042F3A0
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet);                  // 0x004FA420
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg);                                            // 0x004FA470
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_004FC620_GetValue(D2WinControlStrc* pControl);                                           // 0x004FC620
void __cdecl sub_00439CC0_CreateControls();                                                                 // 0x00439CC0
void __cdecl sub_00438560_Refresh();                                                                        // 0x00438560
void __cdecl sub_00439210_Redraw();                                                                         // 0x00439210
extern int gnSelected_0070CC00;                                                                             // 0x0070CC00
extern int gnVisibleRows_0070CC0C;                                                                          // 0x0070CC0C
extern int gdwGlobal_00779DC4;                                                                              // 0x00779DC4
extern int gnTopRow_00779DC8;                                                                               // 0x00779DC8
int gnLastValue_00779DCC;                                                                                   // 0x00779DCC
extern D2WinControlStrc* gpControl_00779C84;                                                                // 0x00779C84

// 0x00439BE0
int __stdcall sub_00439BE0_CreateExpansionControls(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_0042F3F0_DestroyControls();
        D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xDA);
        D2Win_10033(pControl, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        D2WinControlStrc* pControl2 = sub_0042F3A0_CreateFromTemplate(0xDB);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
        D2WinControlStrc* pControl3 = sub_0042F3A0_CreateFromTemplate(0xDC);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
        pControl = sub_0042F3A0_CreateFromTemplate(0xDD);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58CE), 0, 0, 0);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58CF), 0, 0, 0);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58D0), 0, 0, 0);
    }
    return 1;
}

// 0x00439CA0
int __stdcall sub_00439CA0_DestroyIfExpansion(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_00408F20_HasExpansionMpq())
        sub_0042F3F0_DestroyControls();
    return 1;
}

// 0x00439D40
int __stdcall sub_00439D40_DestroyControls(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0042F3F0_DestroyControls();
    return 1;
}

// 0x00439D50
int __stdcall sub_00439D50_CreateControls(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00439CC0_CreateControls();
    return 1;
}

// 0x00439D60
int __stdcall sub_00439D60_ScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnTopRow_00779DC8 > 0)
        gnTopRow_00779DC8 -= 1;
    if (gnSelected_0070CC00 > 0)
        gnSelected_0070CC00 -= 1;
    sub_00438560_Refresh();
    sub_00439210_Redraw();
    return 1;
}

// 0x00439DA0
int __stdcall sub_00439DA0_ScrollDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnTopRow_00779DC8 + gnVisibleRows_0070CC0C < gdwGlobal_00779DC4)
    {
        if (gnSelected_0070CC00 < gdwGlobal_00779DC4 - 1)
            gnSelected_0070CC00 += 1;
        gnTopRow_00779DC8 += 1;
        sub_00438560_Refresh();
        sub_00439210_Redraw();
    }
    return 1;
}

// 0x00439DF0
int __stdcall sub_00439DF0_OnScroll(SMSGHANDLER_PARAMS* pMsg)
{
    const int nValue = sub_004FC620_GetValue(gpControl_00779C84);
    if (gnLastValue_00779DCC == nValue)
        return 0;
    gnTopRow_00779DC8 += 2 * (nValue - gnLastValue_00779DCC);
    if (gnTopRow_00779DC8 < 0)
        gnTopRow_00779DC8 = 0;
    if (gnTopRow_00779DC8 >= gdwGlobal_00779DC4)
        gnTopRow_00779DC8 = gdwGlobal_00779DC4 - 1;
    gnLastValue_00779DCC = nValue;
    sub_00438560_Refresh();
    sub_00439210_Redraw();
    return 1;
}
