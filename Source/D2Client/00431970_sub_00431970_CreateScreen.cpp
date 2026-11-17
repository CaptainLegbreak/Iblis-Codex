struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId);                              // 0x0042F3A0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet);                  // 0x004FA420
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg);                                            // 0x004FA470
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl);                             // 0x004FDD90
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern D2WinControlStrc* gpEdit_007799CC;                                                                   // 0x007799CC
extern D2WinControlStrc* gpEdit_007799D0;                                                                   // 0x007799D0
extern D2WinControlStrc* gpControl_007799D4;                                                                // 0x007799D4

// 0x00431970
void __cdecl sub_00431970_CreateScreen()
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xD6);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0x3A);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0x3B);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1430), 0, 0, 0);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1432), 0, 0, 0);
}

// build: context sub_00436CF0
void __cdecl sub_00436CF0()
{
    const Unicode* pText1 = sub_004FDD90_GetEditText(gpEdit_007799CC);
    const Unicode* pText2 = sub_004FDD90_GetEditText(gpEdit_007799D0);
    sub_004F96F0_ControlClearState(gpControl_007799D4, (sub_00526800(pText1) > 0) | (sub_00526800(pText2) > 0));
}
