#include "D2Multi.h"
#include "D2MultiTypes.h"
#include "D2Unicode.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __fastcall sub_0043FB50_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x0043FB50
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox);                                                      // 0x004F91C0
int __stdcall sub_004450A0_JoinNameKey(D2WinControlStrc* pControl, int nArg, const char* pChar);            // 0x004450A0
int __stdcall sub_004450C0_JoinNameEnter(int nArg);                                                         // 0x004450C0
int __stdcall sub_00443600_IsPrintableChar(D2WinControlStrc* pControl, int nArg, const char* pChar);        // 0x00443600

extern D2WinControlInitStrc gtControlInit_0070D630;                                                         // 0x0070D630
extern D2WinControlInitStrc gtControlInit_0070D660;                                                         // 0x0070D660
extern D2WinControlInitStrc gtControlInit_0070D690;                                                         // 0x0070D690
extern D2WinControlInitStrc gtControlInit_0070D6C0;                                                         // 0x0070D6C0
extern D2WinControlInitStrc gtControlInit_0070D6F0;                                                         // 0x0070D6F0
extern D2WinControlInitStrc gtControlInit_0070D720;                                                         // 0x0070D720
extern D2WinControlInitStrc gtControlInit_0070D750;                                                         // 0x0070D750
extern D2WinControlInitStrc gtControlInit_0070D780;                                                         // 0x0070D780
extern D2WinControlInitStrc gtControlInit_0070D7B0;                                                         // 0x0070D7B0
extern D2WinControlInitStrc gtControlInit_0070D8A0;                                                         // 0x0070D8A0
extern D2WinControlInitStrc gtControlInit_0070E110;                                                         // 0x0070E110
extern D2WinControlStrc* gpControl_00798BC8;                                                                // 0x00798BC8
extern D2WinControlStrc* gpControl_00798BD0;                                                                // 0x00798BD0
D2WinControlStrc* gpJoinName_00798BD4;                                                                      // 0x00798BD4
D2WinControlStrc* gpControl_00798BD8;                                                                       // 0x00798BD8
D2WinControlStrc* gpControl_00798BDC;                                                                       // 0x00798BDC
D2WinControlStrc* gpControl_00798BE0;                                                                       // 0x00798BE0
D2WinControlStrc* gpControl_00798BE4;                                                                       // 0x00798BE4
D2WinControlStrc* gpControl_00798BE8;                                                                       // 0x00798BE8
unsigned long gdwLastRefresh_00798CF0;                                                                      // 0x00798CF0

// 0x00445DF0
void __cdecl sub_00445DF0_CreateJoinScreen()
{
    if (sub_0043DC30_GetStatus() == -1)
    {
        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
        return;
    }
    gpControl_00798BC8 = CONTROL_Create(&gtControlInit_0070D630);
    gpControl_00798BDC = CONTROL_Create(&gtControlInit_0070D660);
    D2Win_10044(gpControl_00798BDC, D2LANG_GetStringFromTblIndex(0x141F));
    gpControl_00798BE0 = CONTROL_Create(&gtControlInit_0070D690);
    D2Win_10044(gpControl_00798BE0, D2LANG_GetStringFromTblIndex(0x149A));
    gpControl_00798BE4 = CONTROL_Create(&gtControlInit_0070D6C0);
    D2Win_10044(gpControl_00798BE4, D2LANG_GetStringFromTblIndex(0x1469));
    gpControl_00798BE8 = CONTROL_Create(&gtControlInit_0070D6F0);
    D2Win_10044(gpControl_00798BE8, D2LANG_GetStringFromTblIndex(0x149B));
    gpControl_00798BCC = CONTROL_Create(&gtControlInit_0070D7B0);
    gpControl_00798BD0 = CONTROL_Create(&gtControlInit_0070E110);
    sub_004FA450_SetActive(gpControl_00798BD0);
    gpJoinName_00798BD4 = CONTROL_Create(&gtControlInit_0070D720);
    sub_004FDD50_SetMaxLength(gpJoinName_00798BD4, 0x10);
    sub_004FDAD0_SetKeyCallback(gpJoinName_00798BD4, sub_004450A0_JoinNameKey);
    sub_004FDB00_SetEnterCallback(gpJoinName_00798BD4, sub_004450C0_JoinNameEnter);
    gpControl_00798BD8 = CONTROL_Create(&gtControlInit_0070D750);
    sub_004FDD50_SetMaxLength(gpControl_00798BD8, 0x10);
    sub_004FDAD0_SetKeyCallback(gpControl_00798BD8, sub_00443600_IsPrintableChar);
    sub_004FDDD0_LinkTab(gpJoinName_00798BD4, gpControl_00798BD8);
    sub_004FDDD0_LinkTab(gpControl_00798BD8, gpJoinName_00798BD4);
    gpGameList_00798BC0 = CONTROL_Create(&gtControlInit_0070D780);
    if (sub_00449B30_QueryAddress())
    {
        sub_004FBC20(gpGameList_00798BC0, 2);
        sub_004FBC80(gpGameList_00798BC0, 1, 0x87);
    }
    gpControl_00798BC4 = CONTROL_Create(&gtControlInit_0070D8A0);
    const unsigned long dwElapsed = GetTickCount() - gdwLastRefresh_00798CF0;
    if (dwElapsed >= 0x1388)
    {
        gdwLastRefresh_00798CF0 += dwElapsed;
        sub_00445020_SendLaunchRequest();
    }
    CONTROL_SetFocusedEditBox(gpJoinName_00798BD4);
    gnGameCount_00798CC8 = 0;
    gnValue_00798CCC = 0;
    sub_004437E0_UpdateButtonState();
}

#include "gen/data/Source/D2Multi/Unknown_00445DF0.inc"
