struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

typedef void (__cdecl* D2LaunchDoneFn)();

void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId);                              // 0x0042F3A0
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg);                                            // 0x004FA470
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet);                  // 0x004FA420
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790

extern int gbFeCharPalette_007795F0;                                                                        // 0x007795F0
D2LaunchDoneFn gpfnGatewayDone_007795BC;                                                                    // 0x007795BC

// 0x004330A0
static int __stdcall sub_004330A0_SetMultilineText(D2WinControlStrc* pControl, int nArg, const Unicode* pText, bool bWrapped)
{
    Unicode aBuffer[0x400];
    for (int i = 0; i < 0x400; ++i)
        aBuffer[i].wChar = 0;
    sub_00526790(aBuffer, pText, 0x400);
    Unicode* pChar = aBuffer;
    Unicode* pLine = pChar;
    while (pChar->wChar)
    {
        if (pChar->wChar == 0xA)
        {
            pChar->wChar = 0;
            D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
            pLine = pChar + 1;
        }
        ++pChar;
    }
    if (pLine < pChar)
        D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
    return 1;
}

// 0x00433130
void __fastcall sub_00433130_ShowTwoTexts(const Unicode* pText1, const Unicode* pText2, D2LaunchDoneFn pfnDone)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xE7);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = sub_0042F3A0_CreateFromTemplate(0xE8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xE9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText1, false);
    pControl = sub_0042F3A0_CreateFromTemplate(0xEA);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText2, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x004331C0
void __fastcall sub_004331C0_ShowThreeTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, D2LaunchDoneFn pfnDone)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xEB);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = sub_0042F3A0_CreateFromTemplate(0xEC);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xED);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText1, false);
    if (pText3 && pText3->wChar)
    {
        pControl = sub_0042F3A0_CreateFromTemplate(0xEF);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004330A0_SetMultilineText(pControl, 0, pText2, false);
        pControl = sub_0042F3A0_CreateFromTemplate(0xF0);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004330A0_SetMultilineText(pControl, 4, pText3, false);
        gpfnGatewayDone_007795BC = pfnDone;
        return;
    }
    pControl = sub_0042F3A0_CreateFromTemplate(0xEE);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText2, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x004332B0
void __fastcall sub_004332B0_ShowFourTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, const Unicode* pText4, D2LaunchDoneFn pfnDone)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xF1);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = sub_0042F3A0_CreateFromTemplate(0xF2);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xF3);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText1, false);
    pControl = sub_0042F3A0_CreateFromTemplate(0xF4);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText2, false);
    pControl = sub_0042F3A0_CreateFromTemplate(0xF5);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText3, false);
    pControl = sub_0042F3A0_CreateFromTemplate(0xF6);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 4, pText4, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x00433380
void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg)
{
    D2WinControlStrc* pFrame;
    D2WinControlStrc* pButton;
    D2WinControlStrc* pTextBox;
    sub_0042F3F0_DestroyControls();
    if (gbFeCharPalette_007795F0)
    {
        pFrame = sub_0042F3A0_CreateFromTemplate(0xF7);
        D2Win_10033(pFrame, 1);
        pButton = sub_0042F3A0_CreateFromTemplate(nArg ? 0xF8 : 0xFA);
        pTextBox = sub_0042F3A0_CreateFromTemplate(0xF9);
    }
    else
    {
        pFrame = sub_0042F3A0_CreateFromTemplate(0xDE);
        D2Win_10033(pFrame, 1);
        pButton = sub_0042F3A0_CreateFromTemplate(nArg ? 0xE1 : 0xDF);
        pTextBox = sub_0042F3A0_CreateFromTemplate(0xE0);
    }
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pButton, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pTextBox, 1);
    sub_004330A0_SetMultilineText(pTextBox, 0, pText, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x00433460
void __fastcall sub_00433460_ShowTextBox(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xF7);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = sub_0042F3A0_CreateFromTemplate(0xFA);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xF9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004330A0_SetMultilineText(pControl, 0, pText, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x00435180
void __fastcall sub_00435180_ShowMessage2(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg)
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pFrame = sub_0042F3A0_CreateFromTemplate(0xDE);
    D2Win_10033(pFrame, 1);
    D2WinControlStrc* pButton = sub_0042F3A0_CreateFromTemplate(nArg ? 0xE1 : 0xDF);
    D2WinControlStrc* pTextBox = sub_0042F3A0_CreateFromTemplate(0xE0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pButton, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pTextBox, 1);
    sub_004330A0_SetMultilineText(pTextBox, 0, pText, false);
    gpfnGatewayDone_007795BC = pfnDone;
}
