struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

int __fastcall sub_00500960_IsPressed(D2WinControlStrc* pButton);                                           // 0x00500960
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet);                         // 0x004F9740
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __cdecl sub_00443630_UpdateCreateButton();                                                             // 0x00443630

extern D2WinControlStrc* gpControl_00798C04;                                                                // 0x00798C04
extern D2WinControlStrc* gpControl_00798C08;                                                                // 0x00798C08
extern D2WinControlStrc* gpControl_00798C1C;                                                                // 0x00798C1C
extern D2WinControlStrc* gpControl_00798C20;                                                                // 0x00798C20
extern D2WinControlStrc* gpControl_00798C24;                                                                // 0x00798C24
extern D2WinControlStrc* gpControl_00798C3C;                                                                // 0x00798C3C
extern D2WinControlStrc* gpButton_00798C40;                                                                 // 0x00798C40
extern D2WinControlStrc* gpControl_00798C44;                                                                // 0x00798C44

// 0x004451C0
void __cdecl sub_004451C0_UpdateLevelControls()
{
    if (sub_00500960_IsPressed(gpButton_00798C40))
    {
        sub_004F9740_SetControlState(gpControl_00798C44, 0);
        sub_004F9740_SetControlState(gpControl_00798C24, 0);
        sub_004F9740_SetControlState(gpControl_00798C1C, 1);
        sub_004F9740_SetControlState(gpControl_00798C20, 1);
        sub_004F96F0_ControlClearState(gpControl_00798C3C, 1);
        sub_004F96F0_ControlClearState(gpControl_00798C1C, 1);
        sub_004F96F0_ControlClearState(gpControl_00798C20, 1);
        sub_004FC9B0_SetText(gpControl_00798C04, D2LANG_GetStringFromTblIndex(0x148B), 4, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 4, 0, 0);
    }
    else
    {
        sub_004F9740_SetControlState(gpControl_00798C44, 1);
        sub_004F9740_SetControlState(gpControl_00798C24, 1);
        sub_004F9740_SetControlState(gpControl_00798C1C, 0);
        sub_004F9740_SetControlState(gpControl_00798C20, 0);
        sub_004F96F0_ControlClearState(gpControl_00798C3C, 0);
        sub_004F96F0_ControlClearState(gpControl_00798C1C, 0);
        sub_004F96F0_ControlClearState(gpControl_00798C20, 0);
        sub_004FC9B0_SetText(gpControl_00798C04, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
    }
    sub_00443630_UpdateCreateButton();
}
