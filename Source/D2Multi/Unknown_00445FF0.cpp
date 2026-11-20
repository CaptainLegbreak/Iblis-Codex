#include "D2Multi.h"

struct D2WinButtonStrc;
struct D2WinEditBoxStrc;
struct Unicode;
struct D2LaunchCharInfoStrc
{
    char unk0x000[0x1EF];
    char nByte1EF;
    char nByte1F0;
    char unk0x1F1[0x1F];
    char nByte210;
};
extern D2WinControlStrc* gpPanelControl_00798BEC;                                                           // 0x00798BEC
D2WinControlStrc* gpControl_00798BF8;                                                                       // 0x00798BF8
D2WinControlStrc* gpControl_00798BFC;                                                                       // 0x00798BFC
D2WinControlStrc* gpControl_00798C00;                                                                       // 0x00798C00
D2WinControlStrc* gpControl_00798C04;                                                                       // 0x00798C04
D2WinControlStrc* gpControl_00798C08;                                                                       // 0x00798C08
D2WinControlStrc* gpControl_00798C0C;                                                                       // 0x00798C0C
D2WinControlStrc* gpControl_00798C10;                                                                       // 0x00798C10
D2WinControlStrc* gpControl_00798C14;                                                                       // 0x00798C14
D2WinControlStrc* gpControl_00798C18;                                                                       // 0x00798C18
extern D2WinControlStrc* gpControl_00798C1C;                                                                // 0x00798C1C
extern D2WinControlStrc* gpControl_00798C20;                                                                // 0x00798C20
D2WinControlStrc* gpControl_00798C24;                                                                       // 0x00798C24
D2WinControlStrc* gpCreateName_00798C2C;                                                                    // 0x00798C2C
D2WinControlStrc* gpControl_00798C30;                                                                       // 0x00798C30
D2WinControlStrc* gpControl_00798C34;                                                                       // 0x00798C34
D2WinControlStrc* gpControl_00798C38;                                                                       // 0x00798C38
D2WinControlStrc* gpControl_00798C3C;                                                                       // 0x00798C3C
extern D2WinControlStrc* gpButton_00798C40;                                                                 // 0x00798C40
D2WinControlStrc* gpControl_00798C44;                                                                       // 0x00798C44
extern D2WinControlStrc* gpControl_00798C4C;                                                                // 0x00798C4C
extern D2WinControlStrc* gpControl_00798C50;                                                                // 0x00798C50
extern D2WinControlStrc* gpControl_00798C54;                                                                // 0x00798C54
D2WinControlStrc* gpControl_00798C58;                                                                       // 0x00798C58
D2WinControlStrc* gpControl_00798C5C;                                                                       // 0x00798C5C
D2WinControlStrc* gpControl_00798C60;                                                                       // 0x00798C60
extern D2WinControlInitStrc gtControlInit_0070DA50;                                                         // 0x0070DA50
extern D2WinControlInitStrc gtControlInit_0070DA80;                                                         // 0x0070DA80
extern D2WinControlInitStrc gtControlInit_0070DAB0;                                                         // 0x0070DAB0
extern D2WinControlInitStrc gtControlInit_0070DAE0;                                                         // 0x0070DAE0
extern D2WinControlInitStrc gtControlInit_0070DB10;                                                         // 0x0070DB10
extern D2WinControlInitStrc gtControlInit_0070DB40;                                                         // 0x0070DB40
extern D2WinControlInitStrc gtControlInit_0070DCC0;                                                         // 0x0070DCC0
extern D2WinControlInitStrc gtControlInit_0070E110;                                                         // 0x0070E110
extern D2WinControlInitStrc gtControlInit_0070DBD0;                                                         // 0x0070DBD0
extern D2WinControlInitStrc gtControlInit_0070DC00;                                                         // 0x0070DC00
extern D2WinControlInitStrc gtControlInit_0070DC30;                                                         // 0x0070DC30
extern D2WinControlInitStrc gtControlInit_0070DC60;                                                         // 0x0070DC60
extern D2WinControlInitStrc gtControlInit_0070DCF0;                                                         // 0x0070DCF0
extern D2WinControlInitStrc gtControlInit_0070DD20;                                                         // 0x0070DD20
extern D2WinControlInitStrc gtControlInit_0070DC90;                                                         // 0x0070DC90
extern D2WinControlInitStrc gtControlInit_0070DB70;                                                         // 0x0070DB70
extern D2WinControlInitStrc gtControlInit_0070DBA0;                                                         // 0x0070DBA0
extern D2WinControlInitStrc gtControlInit_0070DE70;                                                         // 0x0070DE70
extern D2WinControlInitStrc gtControlInit_0070DEA0;                                                         // 0x0070DEA0
extern D2WinControlInitStrc gtControlInit_0070DED0;                                                         // 0x0070DED0
extern D2WinControlInitStrc gtControlInit_0070DF00;                                                         // 0x0070DF00
extern D2WinControlInitStrc gtControlInit_0070DF30;                                                         // 0x0070DF30
extern D2WinControlInitStrc gtControlInit_0070DF60;                                                         // 0x0070DF60
extern D2WinControlInitStrc gtControlInit_0070DF90;                                                         // 0x0070DF90
extern D2WinControlInitStrc gtControlInit_0070DDB0;                                                         // 0x0070DDB0
extern D2WinControlInitStrc gtControlInit_0070DE40;                                                         // 0x0070DE40
extern D2WinControlInitStrc gtControlInit_0070DD80;                                                         // 0x0070DD80
extern D2WinControlInitStrc gtControlInit_0070DE10;                                                         // 0x0070DE10
extern D2WinControlInitStrc gtControlInit_0070DDE0;                                                         // 0x0070DDE0
extern D2WinControlInitStrc gtControlInit_0070DD50;                                                         // 0x0070DD50
extern "C" const char gszFormatInt_006D57BC[];                                                              // 0x006D57BC
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern int gnDiffSelect_00798CD0;                                                                           // 0x00798CD0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_0043FB50_ShowWait(const Unicode* pText, int (__stdcall* pfnDone)(int));                 // 0x0043FB50
void __cdecl sub_004453B0_BuildPanel();                                                                     // 0x004453B0
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __stdcall sub_004FA450(D2WinControlStrc* pControl);                                                     // 0x004FA450
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*));// 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int));// 0x004FDB00
void __fastcall BUTTON_SetIsPressed(D2WinButtonStrc* pButton, int bIsPressed);                              // 0x005009A0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC);// 0x004FC9B0
void __cdecl sub_00445300_LoadLvlRest();                                                                    // 0x00445300
void __cdecl sub_004431B0();                                                                                // 0x004431B0
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue);// 0x004150E0
void __fastcall sub_0043F560_Disable(D2WinControlStrc* pControl);                                           // 0x0043F560
int __stdcall sub_004F91C0(D2WinEditBoxStrc* pEditBox);                                                      // 0x004F91C0
void __stdcall sub_00445550(int nArg);                                                                      // 0x00445550
int __stdcall sub_00443540_IsNameChar(D2WinControlStrc* pControl, int nArg, const char* pChar);             // 0x00443540
int __stdcall sub_004456A0_OnEnter(int nArg);                                                               // 0x004456A0
int __stdcall sub_00443600_IsPrintableChar(D2WinControlStrc* pControl, int nArg, const char* pChar);        // 0x00443600
int __stdcall sub_004435D0_IsTextChar(D2WinControlStrc* pControl, int nArg, const char* pChar);             // 0x004435D0
int __stdcall sub_004FE770_IsDigitChar(D2WinControlStrc* pControl, int nArg, const char* pChar);            // 0x004FE770
int __stdcall sub_004456B0_OnEnter(int nArg);                                                               // 0x004456B0
int __stdcall sub_004456C0_OnEnter(int nArg);                                                               // 0x004456C0

// 0x00445FF0
void __cdecl sub_00445FF0_BuildCreateScreen()
{
    if (sub_0043DC30_GetStatus() == -1)
    {
        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
        return;
    }
    if (sub_00449E40())
    {
        sub_004453B0_BuildPanel();
        return;
    }
    gpCharInfo_0077BBD8->nByte210 = 0;
    gpPanelControl_00798BEC = CONTROL_Create(&gtControlInit_0070DA50);
    gpControl_00798BF0 = CONTROL_Create(&gtControlInit_0070DA80);
    D2Win_10044(gpControl_00798BF0, D2LANG_GetStringFromTblIndex(0x141E));
    gpControl_00798BF4 = CONTROL_Create(&gtControlInit_0070DAB0);
    D2Win_10044(gpControl_00798BF4, D2LANG_GetStringFromTblIndex(0x149A));
    gpControl_00798BF8 = CONTROL_Create(&gtControlInit_0070DAE0);
    D2Win_10044(gpControl_00798BF8, D2LANG_GetStringFromTblIndex(0x1488));
    gpControl_00798BFC = CONTROL_Create(&gtControlInit_0070DB10);
    D2Win_10044(gpControl_00798BFC, D2LANG_GetStringFromTblIndex(0x1489));
    if (sub_00449B30_QueryAddress())
    {
        gpControl_00798C00 = CONTROL_Create(&gtControlInit_0070DB40);
        D2Win_10044(gpControl_00798C00, D2LANG_GetStringFromTblIndex(0x148A));
    }
    gpControl_00798C28 = CONTROL_Create(&gtControlInit_0070DCC0);
    gpControl_00798C48 = CONTROL_Create(&gtControlInit_0070E110);
    sub_004FA450(gpControl_00798C48);
    gpCreateName_00798C2C = CONTROL_Create(&gtControlInit_0070DBD0);
    sub_004FDD50_SetMaxLength(gpCreateName_00798C2C, 0x10);
    sub_004FDAD0_SetKeyCallback(gpCreateName_00798C2C, sub_00443540_IsNameChar);
    sub_004FDB00_SetEnterCallback(gpCreateName_00798C2C, sub_004456A0_OnEnter);
    gpControl_00798C30 = CONTROL_Create(&gtControlInit_0070DC00);
    sub_004FDD50_SetMaxLength(gpControl_00798C30, 0x10);
    sub_004FDAD0_SetKeyCallback(gpControl_00798C30, sub_00443600_IsPrintableChar);
    gpControl_00798C34 = CONTROL_Create(&gtControlInit_0070DC30);
    sub_004FDD50_SetMaxLength(gpControl_00798C34, 0x20);
    sub_004FDAD0_SetKeyCallback(gpControl_00798C34, sub_004435D0_IsTextChar);
    sprintf(gszValue_0070EBD0, gszFormatInt_006D57BC, 4);
    sprintf(gszValue_0070EBD4, gszFormatInt_006D57BC, 4);
    if (sub_00449B30_QueryAddress())
    {
        gpControl_00798C38 = CONTROL_Create(&gtControlInit_0070DC60);
        sub_004FFE10_SetTextA(gpControl_00798C38, gszValue_0070EBD4);
        sub_004FDD50_SetMaxLength(gpControl_00798C38, 3);
        sub_004FDAD0_SetKeyCallback(gpControl_00798C38, sub_004FE770_IsDigitChar);
        sub_004FDB00_SetEnterCallback(gpControl_00798C38, sub_004456B0_OnEnter);
        gpButton_00798C40 = CONTROL_Create(&gtControlInit_0070DCF0);
        BUTTON_SetIsPressed((D2WinButtonStrc*)gpButton_00798C40, 1);
        gpControl_00798C44 = CONTROL_Create(&gtControlInit_0070DD20);
        gpControl_00798C3C = CONTROL_Create(&gtControlInit_0070DC90);
        sub_004FFE10_SetTextA(gpControl_00798C3C, gszValue_0070EBD0);
        sub_004FDD50_SetMaxLength(gpControl_00798C3C, 3);
        sub_004FDAD0_SetKeyCallback(gpControl_00798C3C, sub_004FE770_IsDigitChar);
        sub_004FDB00_SetEnterCallback(gpControl_00798C3C, sub_004456C0_OnEnter);
        sub_004F96F0_ControlClearState(gpControl_00798C3C, 0);
        gpControl_00798C04 = CONTROL_Create(&gtControlInit_0070DB70);
        sub_004FC9B0_SetText(gpControl_00798C04, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        gpControl_00798C08 = CONTROL_Create(&gtControlInit_0070DBA0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
        gpControl_00798C14 = CONTROL_Create(&gtControlInit_0070DE70);
        gpControl_00798C18 = CONTROL_Create(&gtControlInit_0070DEA0);
        gpControl_00798C1C = CONTROL_Create(&gtControlInit_0070DED0);
        gpControl_00798C20 = CONTROL_Create(&gtControlInit_0070DF00);
        gpControl_00798C24 = CONTROL_Create(&gtControlInit_0070DF30);
        sub_00500B20_SetValue(gpControl_00798C18, 2);
        sub_00500B20_SetValue(gpControl_00798C20, 2);
        sub_004F9740_SetControlState(gpControl_00798C24, 1);
        sub_004F96F0_ControlClearState(gpControl_00798C24, 0);
        sub_004F9740_SetControlState(gpControl_00798C1C, 0);
        sub_004F9740_SetControlState(gpControl_00798C20, 0);
        sub_004F96F0_ControlClearState(gpControl_00798C1C, 0);
        sub_004F96F0_ControlClearState(gpControl_00798C20, 0);
        sub_004FDDD0_LinkTab(gpCreateName_00798C2C, gpControl_00798C30);
        sub_004FDDD0_LinkTab(gpControl_00798C30, gpControl_00798C34);
        sub_004FDDD0_LinkTab(gpControl_00798C34, gpControl_00798C38);
        sub_004FDDD0_LinkTab(gpControl_00798C38, gpControl_00798C3C);
        sub_004FDDD0_LinkTab(gpControl_00798C3C, gpCreateName_00798C2C);
        sub_00445300_LoadLvlRest();
        sub_004431B0();
    }
    else
    {
        sub_004FDDD0_LinkTab(gpCreateName_00798C2C, gpControl_00798C30);
        sub_004FDDD0_LinkTab(gpControl_00798C30, gpControl_00798C34);
        sub_004FDDD0_LinkTab(gpControl_00798C34, gpCreateName_00798C2C);
        gpControl_00798C00 = CONTROL_Create(&gtControlInit_0070DB40);
        sub_004FC9B0_SetText(gpControl_00798C00, D2LANG_GetStringFromTblIndex(0x148A), 5, 0, 0);
        gpControl_00798C04 = CONTROL_Create(&gtControlInit_0070DB70);
        sub_004FC9B0_SetText(gpControl_00798C04, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        gpControl_00798C08 = CONTROL_Create(&gtControlInit_0070DBA0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
        gpControl_00798C44 = CONTROL_Create(&gtControlInit_0070DD20);
        sub_004F9740_SetControlState(gpControl_00798C44, 1);
        gpControl_00798C24 = CONTROL_Create(&gtControlInit_0070DF30);
        sub_004F9740_SetControlState(gpControl_00798C24, 1);
        sub_004F96F0_ControlClearState(gpControl_00798C24, 0);
        gpControl_00798C0C = CONTROL_Create(&gtControlInit_0070DF60);
        sub_004F9740_SetControlState(gpControl_00798C0C, 1);
        gpControl_00798C10 = CONTROL_Create(&gtControlInit_0070DF90);
        sub_004F9740_SetControlState(gpControl_00798C10, 1);
        sub_004F96F0_ControlClearState(gpControl_00798C10, 0);
    }
    int bSelected = 0;
    unsigned long dwDifficulty = 0;
    if (!SRegLoadValue("Diablo II", "DIFF_LEVEL", 0, &dwDifficulty))
        SRegSaveValue("Diablo II", "DIFF_LEVEL", 0, 0);
    int nLevel = gpCharInfo_0077BBD8->nByte1F0 & 0x1F;
    gpControl_00798C54 = CONTROL_Create(&gtControlInit_0070DDB0);
    gpControl_00798C60 = CONTROL_Create(&gtControlInit_0070DE40);
    gpControl_00798C50 = CONTROL_Create(&gtControlInit_0070DD80);
    gpControl_00798C5C = CONTROL_Create(&gtControlInit_0070DE10);
    int bExpansion = gpCharInfo_0077BBD8->nByte1EF & 0x20;
    if ((!bExpansion && nLevel >= 8) || nLevel >= 10)
    {
        sub_004FC9B0_SetText(gpControl_00798C60, D2LANG_GetStringFromTblIndex(0x2720), 4, 0, 0);
        if (dwDifficulty == 2)
        {
            BUTTON_SetIsPressed((D2WinButtonStrc*)gpControl_00798C54, 1);
            gnDiffSelect_00798CD0 = 2;
            gpCharInfo_0077BBD8->nByte210 = 2;
            bSelected = 1;
        }
    }
    else
    {
        sub_004FC9B0_SetText(gpControl_00798C60, D2LANG_GetStringFromTblIndex(0x2720), 5, 0, 0);
        sub_0043F560_Disable(gpControl_00798C54);
    }
    if ((!bExpansion && nLevel >= 4) || nLevel >= 5)
    {
        sub_004FC9B0_SetText(gpControl_00798C5C, D2LANG_GetStringFromTblIndex(0x2721), 4, 0, 0);
        if (dwDifficulty == 1)
        {
            BUTTON_SetIsPressed((D2WinButtonStrc*)gpControl_00798C50, 1);
            gnDiffSelect_00798CD0 = 1;
            gpCharInfo_0077BBD8->nByte210 = 1;
            bSelected = 1;
        }
    }
    else
    {
        sub_004FC9B0_SetText(gpControl_00798C5C, D2LANG_GetStringFromTblIndex(0x2721), 5, 0, 0);
        sub_0043F560_Disable(gpControl_00798C50);
    }
    gpControl_00798C58 = CONTROL_Create(&gtControlInit_0070DDE0);
    sub_004FC9B0_SetText(gpControl_00798C58, D2LANG_GetStringFromTblIndex(0x2722), 4, 0, 0);
    gpControl_00798C4C = CONTROL_Create(&gtControlInit_0070DD50);
    if (!bSelected)
    {
        BUTTON_SetIsPressed((D2WinButtonStrc*)gpControl_00798C4C, 1);
        gnDiffSelect_00798CD0 = 0;
    }
    sub_004F91C0((D2WinEditBoxStrc*)gpCreateName_00798C2C);
    if (sub_00449B30_QueryAddress())
        sub_00445550(0);
}

#include "gen/data/Source/D2Multi/Unknown_00445FF0.inc"
