#include "D2Win.h"

struct D2WinControlStrc;
struct Unicode;
struct D2LaunchRecordStrc;
struct D2FuncTable_0077ABF0Strc;

struct Unicode
{
    unsigned short wChar;
};

typedef void (__cdecl* D2LaunchDoneFn)();

struct D2LaunchRecordStrc
{
    char unk0x000[0x8D];
    char szAccount[0x18];
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x68];
    int (__fastcall* pfnSlot68)();
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __cdecl sub_0043C4F0(); // 0x0043C4F0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId); // 0x0042F430
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId); // 0x0042F3A0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength); // 0x004FDD50
int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText); // 0x004FFE10
int __stdcall sub_004F91C0(D2WinControlStrc* pEditBox); // 0x004F91C0
void __fastcall sub_004FDDD0_LinkTab(D2WinControlStrc* pControl, D2WinControlStrc* pNext); // 0x004FDDD0
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450
void __cdecl sub_004336C0_ShowMainMenu(); // 0x004336C0
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg); // 0x004FA470
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet); // 0x004FA420
void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
void __fastcall sub_0042E6B0(int nValue); // 0x0042E6B0
void __fastcall sub_0042E6A0(void (__cdecl* pfnCallback)()); // 0x0042E6A0
void __cdecl sub_0043B810_SetFlag(); // 0x0043B810
void __cdecl sub_00436AD0_UpdateStatus(); // 0x00436AD0
int __cdecl sub_004F5D60(); // 0x004F5D60
int __stdcall sub_0042FE70_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FE70
int __stdcall sub_0042FEF0_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FEF0
int __stdcall sub_0042FF00_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FF00
int __stdcall sub_00436F20_OnEditChange(int nArg); // 0x00436F20
int __stdcall sub_004372A0_OnEnter(int nArg); // 0x004372A0
void __cdecl sub_00436EB0_UpdateOkButton(); // 0x00436EB0
void __cdecl sub_004371E0_UpdatePasswordOk(); // 0x004371E0
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4; // 0x007795D4
extern D2WinControlStrc* gpEdit_00779334; // 0x00779334
extern D2WinControlStrc* gpEdit_00779340; // 0x00779340
extern D2WinControlStrc* gpEdit_0077958C; // 0x0077958C
extern D2WinControlStrc* gpEdit_007795A8; // 0x007795A8
extern D2WinControlStrc* gpPasswordOk_007799A4; // 0x007799A4
extern D2WinControlStrc* gpStatusText_007799A8; // 0x007799A8
extern D2WinControlStrc* gpCounterText_007799AC; // 0x007799AC
extern int gnStatusStringId_007799B0; // 0x007799B0
extern int gnStatusDots_007799B4; // 0x007799B4
extern unsigned long gdwStatusStart_007799B8; // 0x007799B8
extern D2WinControlStrc* gpPasswordEdit_007799BC; // 0x007799BC
extern D2WinControlStrc* gpPasswordEdit_007799C0; // 0x007799C0
extern D2WinControlStrc* gpPasswordEdit_007799C4; // 0x007799C4
extern D2WinControlStrc* gpPasswordEdit_007799C8; // 0x007799C8
extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC
extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0
extern D2WinControlStrc* gpButton_007799E4; // 0x007799E4
extern int gdwGlobal_007D55B8; // 0x007D55B8
void __stdcall WINDOW_ClearCaches(); // 0x004F5D50

// 0x00432100
void __cdecl sub_00432100_CreateLoginScreen()
{
    sub_0043C4F0();
    sub_0042F430_CreateControl(0x15);
    sub_0042F430_CreateControl(0x16);
    sub_0042F430_CreateControl(0x18);
    sub_0042F430_CreateControl(0x19);
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x1A);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = sub_0042F430_CreateControl(0x1B);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B2C));
    pControl = sub_0042F430_CreateControl(0x1D);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B2D));
    pControl = sub_0042F430_CreateControl(0x1E);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B2E));
    if (sub_00408F20_HasExpansionMpq())
        pControl = sub_0042F430_CreateControl(0x21);
    else
        pControl = sub_0042F430_CreateControl(0x1F);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B2B), 0x0, 0x0, 0x0);
    gpEdit_0077958C = sub_0042F430_CreateControl(0x59);
    sub_004FDAD0_SetKeyCallback(gpEdit_0077958C, sub_0042FE70_FilterChar);
    sub_004FDD50_SetMaxLength(gpEdit_0077958C, 0x10);
    D2Win_10076(gpEdit_0077958C, gpLaunchRecord_007795D4->szAccount);
    gpEdit_00779334 = sub_0042F430_CreateControl(0x5A);
    sub_004FDAD0_SetKeyCallback(gpEdit_00779334, sub_0042FF00_FilterChar);
    sub_004FDD50_SetMaxLength(gpEdit_00779334, 0xD);
    gpEdit_00779340 = sub_0042F430_CreateControl(0x5B);
    sub_004FDD50_SetMaxLength(gpEdit_00779340, 0xD);
    gpEdit_007795A8 = sub_0042F430_CreateControl(0x5C);
    sub_004FDD50_SetMaxLength(gpEdit_007795A8, 0xD);
    if (gpLaunchRecord_007795D4->szAccount[0] != 0x0)
        sub_004F91C0(gpEdit_00779334);
    else
        sub_004F91C0(gpEdit_0077958C);
    sub_004FDDD0_LinkTab(gpEdit_0077958C, gpEdit_00779334);
    sub_004FDDD0_LinkTab(gpEdit_00779334, gpEdit_00779340);
    sub_004FDDD0_LinkTab(gpEdit_00779340, gpEdit_007795A8);
    sub_004FDDD0_LinkTab(gpEdit_007795A8, gpEdit_0077958C);
    sub_0042F430_CreateControl(0x5D);
    sub_0042F430_CreateControl(0x5E);
}

// 0x00436F30
void __cdecl sub_00436F30_CreateEmailScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0_ShowMainMenu);
        return;
    }
    sub_0043C4F0();
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x12B);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6A), 0x0, 0x0, 0x0);
    pControl = sub_0042F430_CreateControl(0x12E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B5F), 0x0, 0x0, 0x0);
    sub_0042F430_CreateControl(0x12F);
    pControl = sub_0042F430_CreateControl(0x130);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpEdit_007799DC = sub_0042F430_CreateControl(0x131);
    sub_004FDD50_SetMaxLength(gpEdit_007799DC, 0x10);
    sub_004FDAD0_SetKeyCallback(gpEdit_007799DC, sub_0042FEF0_FilterChar);
    sub_004FDB00_SetEnterCallback(gpEdit_007799DC, sub_00436F20_OnEditChange);
    sub_0042F430_CreateControl(0x132);
    pControl = sub_0042F430_CreateControl(0x133);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B57));
    gpEdit_007799E0 = sub_0042F430_CreateControl(0x134);
    sub_004FDB00_SetEnterCallback(gpEdit_007799E0, sub_00436F20_OnEditChange);
    D2Win_10076(gpEdit_007799DC, gpLaunchRecord_007795D4->szAccount);
    sub_004F91C0(gpEdit_007799DC);
    sub_004FDDD0_LinkTab(gpEdit_007799DC, gpEdit_007799E0);
    sub_004FDDD0_LinkTab(gpEdit_007799E0, gpEdit_007799DC);
    gpButton_007799E4 = sub_0042F430_CreateControl(0x12C);
    sub_0042F430_CreateControl(0x12D);
    sub_00436EB0_UpdateOkButton();
}

// 0x004370C0
void __cdecl sub_004370C0_CreateInfoScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0_ShowMainMenu);
        return;
    }
    sub_0043C4F0();
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x135);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B65), 0x0, 0x0, 0x0);
    pControl = sub_0042F430_CreateControl(0x136);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B66), 0x0, 0x0, 0x0);
    pControl = sub_0042F430_CreateControl(0x137);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B67), 0x0, 0x0, 0x0);
    pControl = sub_0042F430_CreateControl(0x138);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B68), 0x0, 0x0, 0x0);
    sub_0042F430_CreateControl(0x139);
    sub_0042F430_CreateControl(0x13A);
    sub_0042F430_CreateControl(0x13B);
    sub_0042F430_CreateControl(0x13C);
}

// 0x004372B0
void __cdecl sub_004372B0_CreatePasswordScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0_ShowMainMenu);
        return;
    }
    sub_0043C4F0();
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x13D);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6C), 0x0, 0x0, 0x0);
    pControl = sub_0042F430_CreateControl(0x13E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B70), 0x0, 0x0, 0x0);
    sub_0042F430_CreateControl(0x13F);
    pControl = sub_0042F430_CreateControl(0x140);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpPasswordEdit_007799BC = sub_0042F430_CreateControl(0x141);
    D2Win_10076(gpPasswordEdit_007799BC, gpLaunchRecord_007795D4->szAccount);
    sub_004FDD50_SetMaxLength(gpPasswordEdit_007799BC, 0x10);
    sub_004FDAD0_SetKeyCallback(gpPasswordEdit_007799BC, sub_0042FEF0_FilterChar);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799BC, sub_004372A0_OnEnter);
    sub_0042F430_CreateControl(0x142);
    pControl = sub_0042F430_CreateControl(0x143);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B6D));
    gpPasswordEdit_007799C0 = sub_0042F430_CreateControl(0x144);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799C0, sub_004372A0_OnEnter);
    sub_0042F430_CreateControl(0x145);
    pControl = sub_0042F430_CreateControl(0x146);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B6E));
    gpPasswordEdit_007799C8 = sub_0042F430_CreateControl(0x147);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799C8, sub_004372A0_OnEnter);
    sub_0042F430_CreateControl(0x148);
    pControl = sub_0042F430_CreateControl(0x149);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B6F));
    gpPasswordEdit_007799C4 = sub_0042F430_CreateControl(0x14A);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799C4, sub_004372A0_OnEnter);
    gpPasswordOk_007799A4 = sub_0042F430_CreateControl(0x14B);
    sub_0042F430_CreateControl(0x14C);
    sub_004F91C0(gpPasswordEdit_007799BC);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799BC, gpPasswordEdit_007799C0);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799C0, gpPasswordEdit_007799C8);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799C8, gpPasswordEdit_007799C4);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799C4, gpPasswordEdit_007799BC);
    sub_004371E0_UpdatePasswordOk();
}

// 0x00437550
void __cdecl sub_00437550_CreateStatusScreen()
{
    gdwStatusStart_007799B8 = GetTickCount();
    sub_0042F3F0_DestroyControls();
    sub_0042E6B0(0x1);
    D2WinControlStrc* pFrame = sub_0042F3A0_CreateFromTemplate(0xE2);
    D2Win_10033(pFrame, 0x0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 0x1);
    D2WinControlStrc* pOther = sub_0042F3A0_CreateFromTemplate(0xE3);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 0x1);
    D2WinControlStrc* pText = sub_0042F3A0_CreateFromTemplate(0xE4);
    D2Win_10030_CONTROL_ToggleFourthFlag(pText, 0x1);
    D2Win_10051(pText, D2LANG_GetStringFromTblIndex(0x1433), 0x0, 0x0, 0x0);
    gpStatusText_007799A8 = sub_0042F3A0_CreateFromTemplate(0xE5);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpStatusText_007799A8, 0x1);
    gpCounterText_007799AC = sub_0042F3A0_CreateFromTemplate(0xE6);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpCounterText_007799AC, 0x1);
    gnStatusStringId_007799B0 = -1;
    gnStatusDots_007799B4 = 0x0;
    sub_0042E6A0(sub_0043B810_SetFlag);
    sub_00436AD0_UpdateStatus();
}

// 0x004F9050
int __cdecl sub_004F9050()
{
    gdwGlobal_007D55B8 = 0x0;
    return sub_004F5D60();
}

// 0x004F9130
void __stdcall D2Win_10006_ClearDrawCaches()
{
    WINDOW_ClearCaches();
}
