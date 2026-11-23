#include "D2Multi.h"
#include "D2MultiTypes.h"
#include "D2Unicode.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __fastcall CHATDLG_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x0043FB50
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox);                                                      // 0x004F91C0
int __stdcall sub_004450A0_JoinNameKey(D2WinControlStrc* pControl, int nArg, const char* pChar);            // 0x004450A0
int __stdcall sub_004450C0_JoinNameEnter(int nArg);                                                         // 0x004450C0
int __stdcall CHATDLG_IsPrintableChar(D2WinControlStrc* pControl, int nArg, const char* pChar);        // 0x00443600

extern D2WinControlInitStrc gtJoinGameBckgImageInit;                                                         // 0x0070D630
extern D2WinControlInitStrc gtJoinGameTitleInit;                                                         // 0x0070D660
extern D2WinControlInitStrc gtJoinNameLabelInit;                                                         // 0x0070D690
extern D2WinControlInitStrc gtJoinPasswordLabelInit;                                                         // 0x0070D6C0
extern D2WinControlInitStrc gtControlInit_0070D6F0;                                                         // 0x0070D6F0
extern D2WinControlInitStrc gtJoinNameInit;                                                         // 0x0070D720
extern D2WinControlInitStrc gtJoinPasswordInit;                                                         // 0x0070D750
extern D2WinControlInitStrc gtGameListInit;                                                         // 0x0070D780
extern D2WinControlInitStrc gtJoinButtonInit;                                                         // 0x0070D7B0
extern D2WinControlInitStrc gtGameInfoTextInit;                                                         // 0x0070D8A0
extern D2WinControlInitStrc gtControlInit_0070E110;                                                         // 0x0070E110
extern D2WinControlStrc* gpJoinGameBckgImage;                                                                // 0x00798BC8
extern D2WinControlStrc* gpControl_00798BD0;                                                                // 0x00798BD0
D2WinControlStrc* gpJoinName;                                                                      // 0x00798BD4
D2WinControlStrc* gpJoinPassword;                                                                       // 0x00798BD8
D2WinControlStrc* gpJoinGameTitle;                                                                       // 0x00798BDC
D2WinControlStrc* gpJoinNameLabel;                                                                       // 0x00798BE0
D2WinControlStrc* gpJoinPasswordLabel;                                                                       // 0x00798BE4
D2WinControlStrc* gpControl_00798BE8;                                                                       // 0x00798BE8
unsigned long gdwLastRefresh;                                                                      // 0x00798CF0

// 0x00445DF0
void __cdecl sub_00445DF0_CreateJoinScreen()
{
// build: symbol ?CHARSEL_GetConnectStatus@* 0x0043DC30
    if (CHARSEL_GetConnectStatus() == -1)
    {
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
        return;
    }
    gpJoinGameBckgImage = CONTROL_Create(&gtJoinGameBckgImageInit);
    gpJoinGameTitle = CONTROL_Create(&gtJoinGameTitleInit);
    D2Win_10044(gpJoinGameTitle, D2LANG_GetStringFromTblIndex(0x141F));
    gpJoinNameLabel = CONTROL_Create(&gtJoinNameLabelInit);
    D2Win_10044(gpJoinNameLabel, D2LANG_GetStringFromTblIndex(0x149A));
    gpJoinPasswordLabel = CONTROL_Create(&gtJoinPasswordLabelInit);
    D2Win_10044(gpJoinPasswordLabel, D2LANG_GetStringFromTblIndex(0x1469));
    gpControl_00798BE8 = CONTROL_Create(&gtControlInit_0070D6F0);
    D2Win_10044(gpControl_00798BE8, D2LANG_GetStringFromTblIndex(0x149B));
    gpControl_00798BCC = CONTROL_Create(&gtJoinButtonInit);
    gpControl_00798BD0 = CONTROL_Create(&gtControlInit_0070E110);
    sub_004FA450_SetActive(gpControl_00798BD0);
    gpJoinName = CONTROL_Create(&gtJoinNameInit);
    sub_004FDD50_SetMaxLength(gpJoinName, 0x10);
    sub_004FDAD0_SetKeyCallback(gpJoinName, sub_004450A0_JoinNameKey);
    sub_004FDB00_SetEnterCallback(gpJoinName, sub_004450C0_JoinNameEnter);
    gpJoinPassword = CONTROL_Create(&gtJoinPasswordInit);
    sub_004FDD50_SetMaxLength(gpJoinPassword, 0x10);
    sub_004FDAD0_SetKeyCallback(gpJoinPassword, CHATDLG_IsPrintableChar);
    sub_004FDDD0_LinkTab(gpJoinName, gpJoinPassword);
    sub_004FDDD0_LinkTab(gpJoinPassword, gpJoinName);
// build: symbol ?gpGameList@* 0x00798BC0
    gpGameList = CONTROL_Create(&gtGameListInit);
    if (sub_00449B30_QueryAddress())
    {
        sub_004FBC20(gpGameList, 2);
        sub_004FBC80(gpGameList, 1, 0x87);
    }
    gpControl_00798BC4 = CONTROL_Create(&gtGameInfoTextInit);
    const unsigned long dwElapsed = GetTickCount() - gdwLastRefresh;
    if (dwElapsed >= 0x1388)
    {
        gdwLastRefresh += dwElapsed;
// build: symbol ?CHARSEL_RequestGameList@* 0x00445020
        CHARSEL_RequestGameList();
    }
    CONTROL_SetFocusedEditBox(gpJoinName);
// build: symbol ?gnLastGameCount@* 0x00798CC8
    gnLastGameCount = 0;
    gnValue_00798CCC = 0;
// build: symbol ?CHARSEL_UpdateJoinButtonState@* 0x004437E0
    CHARSEL_UpdateJoinButtonState();
}

#include "gen/data/Source/D2Multi/Unknown_00445DF0.inc"
