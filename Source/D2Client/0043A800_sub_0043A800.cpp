struct D2WinControlStrc;
struct D2WinTextBoxStrc;
typedef unsigned short Unicode;

int __cdecl sub_00408F20_HasExpansionMpq(); // 0x00408F20
int __stdcall sub_00413590_StrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId); // 0x0042F3A0
int __cdecl sub_00430B40(); // 0x00430B40
char* __fastcall sub_00430B50_GetSlotName(int nIndex); // 0x00430B50
void __cdecl sub_00437BF0_CreateControls(); // 0x00437BF0
void __cdecl sub_0043A650_Refresh(); // 0x0043A650
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet); // 0x004FA420
int __stdcall D2Win_10033(D2WinControlStrc* a1, int a2); // 0x004FA470
int __fastcall D2Win_10062(D2WinTextBoxStrc* pTextBox, int a2, int a3); // 0x004FB740
void __fastcall D2Win_10050_TEXTBOX_SetLine(D2WinTextBoxStrc* pTextBox, int nLine); // 0x004FB9D0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern int gnLaunchMode_007795EC; // 0x007795EC
D2WinControlStrc* gpNameControl_007799E8;        // 0x007799E8
D2WinControlStrc* gpControl_007799EC;        // 0x007799EC
extern char gData_00779A40[]; // 0x00779A40
extern int gbFlag_00779C6C; // 0x00779C6C
D2WinControlStrc* gpControl_00779C74;        // 0x00779C74
D2WinControlStrc* gpControl_00779C7C;        // 0x00779C7C
D2WinControlStrc* gpControl_00779D88;        // 0x00779D88
D2WinControlStrc* gpControl_00779D9C;        // 0x00779D9C

// 0x0043A800
void __cdecl sub_0043A800()
{
    if (gnLaunchMode_007795EC == 1)
    {
        if (sub_00408F20_HasExpansionMpq())
        {
            sub_00437BF0_CreateControls();
        }
        else
        {
            gpControl_007799EC = sub_0042F3A0_CreateFromTemplate(0x73);
            D2Win_10033(gpControl_007799EC, 1);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_007799EC, 1);
            gpControl_00779C7C = sub_0042F3A0_CreateFromTemplate(0x74);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C7C, 1);
            gpControl_00779D9C = sub_0042F3A0_CreateFromTemplate(0x75);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D9C, 1);
            gpNameControl_007799E8 = sub_0042F3A0_CreateFromTemplate(0x76);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpNameControl_007799E8, 1);
            gpControl_00779D88 = sub_0042F3A0_CreateFromTemplate(0x77);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D88, 1);
            gpControl_00779C74 = sub_0042F3A0_CreateFromTemplate(0x78);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C74, 1);
        }

        sub_004FC9B0_SetText(gpControl_00779C7C, D2LANG_GetStringFromTblIndex(0x2B31), 0, 0, 0);
        D2Win_10062((D2WinTextBoxStrc*)gpControl_00779D9C, -6, 0);
        for (int i = 0; ; ++i)
        {
            char* szName = i < sub_00430B40() ? sub_00430B50_GetSlotName(i) : 0;
            if (!szName) { break; }
            D2Win_10045(gpNameControl_007799E8, szName);
            if (!sub_00413590_StrCmpI(gData_00779A40, szName, 0x7FFFFFFF))
            {
                D2Win_10050_TEXTBOX_SetLine((D2WinTextBoxStrc*)gpNameControl_007799E8, i);
            }
        }
        sub_0043A650_Refresh();
    }
    gbFlag_00779C6C = 1;
}
