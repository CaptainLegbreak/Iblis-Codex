#include "D2Multi.h"
#include "D2MultiTypes.h"

struct D2WinButtonStrc;
struct D2WinEditBoxStrc;
struct Unicode;
extern D2WinControlStrc* gpPanelBackground;                                                           // 0x00798BEC
D2WinControlStrc* gpCreatePasswordLabel;                                                                       // 0x00798BF8
D2WinControlStrc* gpCreateDescLabel;                                                                       // 0x00798BFC
D2WinControlStrc* gpMaxPlayersLabel;                                                                       // 0x00798C00
D2WinControlStrc* gpLevelDiffLabel;                                                                       // 0x00798C04
D2WinControlStrc* gpControl_00798C08;                                                                       // 0x00798C08
D2WinControlStrc* gpMaxPlayersBoxImage;                                                                       // 0x00798C0C
D2WinControlStrc* gpControl_00798C10;                                                                       // 0x00798C10
D2WinControlStrc* gpMaxPlayersUpButton;                                                                       // 0x00798C14
D2WinControlStrc* gpMaxPlayersDownButton;                                                                       // 0x00798C18
extern D2WinControlStrc* gpLevelDiffUpButton;                                                                // 0x00798C1C
extern D2WinControlStrc* gpLevelDiffDownButton;                                                                // 0x00798C20
D2WinControlStrc* gpLevelDiffGreyArrows;                                                                       // 0x00798C24
D2WinControlStrc* gpCreateName;                                                                    // 0x00798C2C
D2WinControlStrc* gpCreatePassword;                                                                       // 0x00798C30
D2WinControlStrc* gpCreateDesc;                                                                       // 0x00798C34
D2WinControlStrc* gpMaxPlayerControl;                                                                       // 0x00798C38
D2WinControlStrc* gpLevelDiffEdit;                                                                       // 0x00798C3C
extern D2WinControlStrc* gpLevelDiffCheck;                                                                 // 0x00798C40
D2WinControlStrc* gpLevelDiffBoxImage;                                                                       // 0x00798C44
extern D2WinControlStrc* gpNormalRadio;                                                                // 0x00798C4C
extern D2WinControlStrc* gpNightmareRadio;                                                                // 0x00798C50
extern D2WinControlStrc* gpHellRadio;                                                                // 0x00798C54
D2WinControlStrc* gpNormalLabel;                                                                       // 0x00798C58
D2WinControlStrc* gpNightmareLabel;                                                                       // 0x00798C5C
D2WinControlStrc* gpHellLabel;                                                                       // 0x00798C60
extern D2WinControlInitStrc gtCreateGameBckgImageInit;                                                         // 0x0070DA50
extern D2WinControlInitStrc gtCreateGameTitleInit;                                                         // 0x0070DA80
extern D2WinControlInitStrc gtCreateNameLabelInit;                                                         // 0x0070DAB0
extern D2WinControlInitStrc gtCreatePasswordLabelInit;                                                         // 0x0070DAE0
extern D2WinControlInitStrc gtCreateDescLabelInit;                                                         // 0x0070DB10
extern D2WinControlInitStrc gtMaxPlayersLabelInit;                                                         // 0x0070DB40
extern D2WinControlInitStrc gtCreateButtonInit;                                                         // 0x0070DCC0
extern D2WinControlInitStrc gtControlInit_0070E110;                                                         // 0x0070E110
extern D2WinControlInitStrc gtCreateNameInit;                                                         // 0x0070DBD0
extern D2WinControlInitStrc gtCreatePasswordInit;                                                         // 0x0070DC00
extern D2WinControlInitStrc gtCreateDescInit;                                                         // 0x0070DC30
extern D2WinControlInitStrc gtMaxPlayersEditInit;                                                         // 0x0070DC60
extern D2WinControlInitStrc gtLevelDiffCheckInit;                                                         // 0x0070DCF0
extern D2WinControlInitStrc gtLevelDiffBoxImageInit;                                                         // 0x0070DD20
extern D2WinControlInitStrc gtLevelDiffEditInit;                                                         // 0x0070DC90
extern D2WinControlInitStrc gtLevelDiffLabelInit;                                                         // 0x0070DB70
extern D2WinControlInitStrc gtControlInit_0070DBA0;                                                         // 0x0070DBA0
extern D2WinControlInitStrc gtMaxPlayersUpInit;                                                         // 0x0070DE70
extern D2WinControlInitStrc gtMaxPlayersDownInit;                                                         // 0x0070DEA0
extern D2WinControlInitStrc gtLevelDiffUpInit;                                                         // 0x0070DED0
extern D2WinControlInitStrc gtLevelDiffDownInit;                                                         // 0x0070DF00
extern D2WinControlInitStrc gtLevelDiffGreyArrowsInit;                                                         // 0x0070DF30
extern D2WinControlInitStrc gtMaxPlayersBoxImageInit;                                                         // 0x0070DF60
extern D2WinControlInitStrc gtControlInit_0070DF90;                                                         // 0x0070DF90
extern D2WinControlInitStrc gtHellRadioInit;                                                         // 0x0070DDB0
extern D2WinControlInitStrc gtHellLabelInit;                                                         // 0x0070DE40
extern D2WinControlInitStrc gtNightmareRadioInit;                                                         // 0x0070DD80
extern D2WinControlInitStrc gtNightmareLabelInit;                                                         // 0x0070DE10
extern D2WinControlInitStrc gtNormalLabelInit;                                                         // 0x0070DDE0
extern D2WinControlInitStrc gtNormalRadioInit;                                                         // 0x0070DD50
extern "C" const char gszFormatInt_006D57BC[];                                                              // 0x006D57BC
extern D2LaunchCharInfoStrc* gpCharInfo;                                                           // 0x0077BBD8
extern int gnDiffSelect;                                                                           // 0x00798CD0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall CHATDLG_ShowWait(const Unicode* pText, int (__stdcall* pfnDone)(int));                 // 0x0043FB50
void __cdecl COMCALLBACK_BuildCreateGamePanel();                                                                     // 0x004453B0
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __stdcall CONTROL_SetEscapeButton(void* a1); // 0x004FA450
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*));// 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int));// 0x004FDB00
extern "C" void __fastcall BUTTON_SetIsPressed(D2WinButtonStrc* ptBtnData, int bIsPressed); // 0x005009A0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC);// 0x004FC9B0
void __cdecl COMCALLBACK_LoadLevelRestriction();                                                                    // 0x00445300
void __cdecl MAINMENUS_LoadMaxPlayers();                                                                                // 0x004431B0
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue);// 0x004150E0
void __fastcall CHARSEL_DisableControl(D2WinControlStrc* pControl);                                           // 0x0043F560
int __stdcall CONTROL_SetFocusedEditBox(D2WinEditBoxStrc* pEditBox);                                                      // 0x004F91C0
int __stdcall CHATDLG_OnLevelRestrictToggle(int nArg); // 0x00445550
int __stdcall sub_00443540_IsNameChar(D2WinControlStrc* pControl, int nArg, const char* pChar);             // 0x00443540
int __stdcall sub_004456A0_OnEnter(int nArg);                                                               // 0x004456A0
int __stdcall CHATDLG_IsPrintableChar(D2WinControlStrc* pControl, int nArg, const char* pChar);        // 0x00443600
int __stdcall sub_004435D0_IsTextChar(D2WinControlStrc* pControl, int nArg, const char* pChar);             // 0x004435D0
int __stdcall sub_004FE770_IsDigitChar(D2WinControlStrc* pControl, int nArg, const char* pChar);            // 0x004FE770
int __stdcall sub_004456B0_OnEnter(int nArg);                                                               // 0x004456B0
int __stdcall sub_004456C0_OnEnter(int nArg);                                                               // 0x004456C0

// 0x00445FF0
void __cdecl sub_00445FF0_BuildCreateScreen()
{
// build: symbol ?CHARSEL_GetConnectStatus@* 0x0043DC30
    if (CHARSEL_GetConnectStatus() == -1)
    {
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
        return;
    }
    if (sub_00449E40())
    {
        COMCALLBACK_BuildCreateGamePanel();
        return;
    }
    gpCharInfo->nByte210 = 0;
    gpPanelBackground = CONTROL_Create(&gtCreateGameBckgImageInit);
    gpControl_00798BF0 = CONTROL_Create(&gtCreateGameTitleInit);
    D2Win_10044(gpControl_00798BF0, D2LANG_GetStringFromTblIndex(0x141E));
    gpControl_00798BF4 = CONTROL_Create(&gtCreateNameLabelInit);
    D2Win_10044(gpControl_00798BF4, D2LANG_GetStringFromTblIndex(0x149A));
    gpCreatePasswordLabel = CONTROL_Create(&gtCreatePasswordLabelInit);
    D2Win_10044(gpCreatePasswordLabel, D2LANG_GetStringFromTblIndex(0x1488));
    gpCreateDescLabel = CONTROL_Create(&gtCreateDescLabelInit);
    D2Win_10044(gpCreateDescLabel, D2LANG_GetStringFromTblIndex(0x1489));
    if (sub_00449B30_QueryAddress())
    {
        gpMaxPlayersLabel = CONTROL_Create(&gtMaxPlayersLabelInit);
        D2Win_10044(gpMaxPlayersLabel, D2LANG_GetStringFromTblIndex(0x148A));
    }
    gpControl_00798C28 = CONTROL_Create(&gtCreateButtonInit);
    gpControl_00798C48 = CONTROL_Create(&gtControlInit_0070E110);
    CONTROL_SetEscapeButton(gpControl_00798C48);
    gpCreateName = CONTROL_Create(&gtCreateNameInit);
    sub_004FDD50_SetMaxLength(gpCreateName, 0x10);
    sub_004FDAD0_SetKeyCallback(gpCreateName, sub_00443540_IsNameChar);
    sub_004FDB00_SetEnterCallback(gpCreateName, sub_004456A0_OnEnter);
    gpCreatePassword = CONTROL_Create(&gtCreatePasswordInit);
    sub_004FDD50_SetMaxLength(gpCreatePassword, 0x10);
    sub_004FDAD0_SetKeyCallback(gpCreatePassword, CHATDLG_IsPrintableChar);
    gpCreateDesc = CONTROL_Create(&gtCreateDescInit);
    sub_004FDD50_SetMaxLength(gpCreateDesc, 0x20);
    sub_004FDAD0_SetKeyCallback(gpCreateDesc, sub_004435D0_IsTextChar);
// build: symbol ?gszLevelDiffText@* 0x0070EBD0
    sprintf(gszLevelDiffText, gszFormatInt_006D57BC, 4);
// build: symbol ?gszMaxPlayersText@* 0x0070EBD4
    sprintf(gszMaxPlayersText, gszFormatInt_006D57BC, 4);
    if (sub_00449B30_QueryAddress())
    {
        gpMaxPlayerControl = CONTROL_Create(&gtMaxPlayersEditInit);
        sub_004FFE10_SetTextA(gpMaxPlayerControl, gszMaxPlayersText);
        sub_004FDD50_SetMaxLength(gpMaxPlayerControl, 3);
        sub_004FDAD0_SetKeyCallback(gpMaxPlayerControl, sub_004FE770_IsDigitChar);
        sub_004FDB00_SetEnterCallback(gpMaxPlayerControl, sub_004456B0_OnEnter);
        gpLevelDiffCheck = CONTROL_Create(&gtLevelDiffCheckInit);
        BUTTON_SetIsPressed((D2WinButtonStrc*)gpLevelDiffCheck, 1);
        gpLevelDiffBoxImage = CONTROL_Create(&gtLevelDiffBoxImageInit);
        gpLevelDiffEdit = CONTROL_Create(&gtLevelDiffEditInit);
        sub_004FFE10_SetTextA(gpLevelDiffEdit, gszLevelDiffText);
        sub_004FDD50_SetMaxLength(gpLevelDiffEdit, 3);
        sub_004FDAD0_SetKeyCallback(gpLevelDiffEdit, sub_004FE770_IsDigitChar);
        sub_004FDB00_SetEnterCallback(gpLevelDiffEdit, sub_004456C0_OnEnter);
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpLevelDiffEdit, 0);
        gpLevelDiffLabel = CONTROL_Create(&gtLevelDiffLabelInit);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        gpControl_00798C08 = CONTROL_Create(&gtControlInit_0070DBA0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
        gpMaxPlayersUpButton = CONTROL_Create(&gtMaxPlayersUpInit);
        gpMaxPlayersDownButton = CONTROL_Create(&gtMaxPlayersDownInit);
        gpLevelDiffUpButton = CONTROL_Create(&gtLevelDiffUpInit);
        gpLevelDiffDownButton = CONTROL_Create(&gtLevelDiffDownInit);
        gpLevelDiffGreyArrows = CONTROL_Create(&gtLevelDiffGreyArrowsInit);
        sub_00500B20_SetValue(gpMaxPlayersDownButton, 2);
        sub_00500B20_SetValue(gpLevelDiffDownButton, 2);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 1);
        CONTROL_SetEnabled(gpLevelDiffGreyArrows, 0);
        sub_004F9740_SetControlState(gpLevelDiffUpButton, 0);
        sub_004F9740_SetControlState(gpLevelDiffDownButton, 0);
        CONTROL_SetEnabled(gpLevelDiffUpButton, 0);
        CONTROL_SetEnabled(gpLevelDiffDownButton, 0);
        sub_004FDDD0_LinkTab(gpCreateName, gpCreatePassword);
        sub_004FDDD0_LinkTab(gpCreatePassword, gpCreateDesc);
        sub_004FDDD0_LinkTab(gpCreateDesc, gpMaxPlayerControl);
        sub_004FDDD0_LinkTab(gpMaxPlayerControl, gpLevelDiffEdit);
        sub_004FDDD0_LinkTab(gpLevelDiffEdit, gpCreateName);
        COMCALLBACK_LoadLevelRestriction();
        MAINMENUS_LoadMaxPlayers();
    }
    else
    {
        sub_004FDDD0_LinkTab(gpCreateName, gpCreatePassword);
        sub_004FDDD0_LinkTab(gpCreatePassword, gpCreateDesc);
        sub_004FDDD0_LinkTab(gpCreateDesc, gpCreateName);
        gpMaxPlayersLabel = CONTROL_Create(&gtMaxPlayersLabelInit);
        sub_004FC9B0_SetText(gpMaxPlayersLabel, D2LANG_GetStringFromTblIndex(0x148A), 5, 0, 0);
        gpLevelDiffLabel = CONTROL_Create(&gtLevelDiffLabelInit);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        gpControl_00798C08 = CONTROL_Create(&gtControlInit_0070DBA0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
        gpLevelDiffBoxImage = CONTROL_Create(&gtLevelDiffBoxImageInit);
        sub_004F9740_SetControlState(gpLevelDiffBoxImage, 1);
        gpLevelDiffGreyArrows = CONTROL_Create(&gtLevelDiffGreyArrowsInit);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 1);
        CONTROL_SetEnabled(gpLevelDiffGreyArrows, 0);
        gpMaxPlayersBoxImage = CONTROL_Create(&gtMaxPlayersBoxImageInit);
        sub_004F9740_SetControlState(gpMaxPlayersBoxImage, 1);
        gpControl_00798C10 = CONTROL_Create(&gtControlInit_0070DF90);
        sub_004F9740_SetControlState(gpControl_00798C10, 1);
        CONTROL_SetEnabled(gpControl_00798C10, 0);
    }
    int bSelected = 0;
    unsigned long dwDifficulty = 0;
    if (!SRegLoadValue("Diablo II", "DIFF_LEVEL", 0, &dwDifficulty))
        SRegSaveValue("Diablo II", "DIFF_LEVEL", 0, 0);
    int nLevel = gpCharInfo->wFlags[1] & 0x1F;
    gpHellRadio = CONTROL_Create(&gtHellRadioInit);
    gpHellLabel = CONTROL_Create(&gtHellLabelInit);
    gpNightmareRadio = CONTROL_Create(&gtNightmareRadioInit);
    gpNightmareLabel = CONTROL_Create(&gtNightmareLabelInit);
    int bExpansion = gpCharInfo->wFlags[0] & 0x20;
    if ((!bExpansion && nLevel >= 8) || nLevel >= 10)
    {
        sub_004FC9B0_SetText(gpHellLabel, D2LANG_GetStringFromTblIndex(0x2720), 4, 0, 0);
        if (dwDifficulty == 2)
        {
            BUTTON_SetIsPressed((D2WinButtonStrc*)gpHellRadio, 1);
            gnDiffSelect = 2;
            gpCharInfo->nByte210 = 2;
            bSelected = 1;
        }
    }
    else
    {
        sub_004FC9B0_SetText(gpHellLabel, D2LANG_GetStringFromTblIndex(0x2720), 5, 0, 0);
        CHARSEL_DisableControl(gpHellRadio);
    }
    if ((!bExpansion && nLevel >= 4) || nLevel >= 5)
    {
        sub_004FC9B0_SetText(gpNightmareLabel, D2LANG_GetStringFromTblIndex(0x2721), 4, 0, 0);
        if (dwDifficulty == 1)
        {
            BUTTON_SetIsPressed((D2WinButtonStrc*)gpNightmareRadio, 1);
            gnDiffSelect = 1;
            gpCharInfo->nByte210 = 1;
            bSelected = 1;
        }
    }
    else
    {
        sub_004FC9B0_SetText(gpNightmareLabel, D2LANG_GetStringFromTblIndex(0x2721), 5, 0, 0);
        CHARSEL_DisableControl(gpNightmareRadio);
    }
    gpNormalLabel = CONTROL_Create(&gtNormalLabelInit);
    sub_004FC9B0_SetText(gpNormalLabel, D2LANG_GetStringFromTblIndex(0x2722), 4, 0, 0);
    gpNormalRadio = CONTROL_Create(&gtNormalRadioInit);
    if (!bSelected)
    {
        BUTTON_SetIsPressed((D2WinButtonStrc*)gpNormalRadio, 1);
        gnDiffSelect = 0;
    }
    CONTROL_SetFocusedEditBox((D2WinEditBoxStrc*)gpCreateName);
    if (sub_00449B30_QueryAddress())
        CHATDLG_OnLevelRestrictToggle(0);
}

#include "gen/data/Source/D2Multi/Unknown_00445FF0.inc"
