#include "D2Multi.h"
#include "D2MultiTypes.h"

int gdwGlobal_00798CC4;                                                                                     // 0x00798CC4
D2WinControlStrc* gpNormalRadio;                                                                       // 0x00798C4C
D2WinControlStrc* gpNightmareRadio;                                                                       // 0x00798C50
D2WinControlStrc* gpHellRadio;                                                                       // 0x00798C54
int gnDiffSelect;                                                                                  // 0x00798CD0
extern D2LaunchCharInfoStrc* gpCharInfo;                                                           // 0x0077BBD8
char gszPendingEntryName[16];                                                                                  // 0x00798CD4
int gnPendingValueA;                                                                               // 0x00798CE4
int gnPendingValueB;                                                                               // 0x00798CE8
int __fastcall D2Win_StopMessageLoop();                                                            // 0x004F9190
int __cdecl WINMAIN_PollMcpConnection();                                                               // 0x00449B70
int __cdecl CHATDLG_ResetControls();                                                                   // 0x0043EBA0
void __cdecl CHATDLG_DestroyCreateControls();                                                                // 0x00443220
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0
void __cdecl CHATDLG_DestroyProfileControls();                                                                                // 0x00443E10
void __cdecl CHATDLG_OpenStandardLadder();                                                                                // 0x004408B0
void __cdecl CHATDLG_OpenHardcoreLadder();                                                                                // 0x00440980
void __cdecl CHATDLG_OpenExpansionLadder();                                                                                // 0x00440A50
void __cdecl CHATDLG_OpenExpansionHardcoreLadder();                                                                                // 0x00440B30
void __fastcall CHATDLG_SelectEntry(const char* szName, int nValueA, int nValueB);                    // 0x0043EC60

// 0x00443870
int __stdcall sub_00443870_SetCancel(int nArg)
{
    gdwGlobal_00798CC4 = 1;
    return 1;
}

// 0x00443880
int __stdcall sub_00443880_PollMcp(int nArg)
{
    WINMAIN_PollMcpConnection();
// build: symbol ?GAME_GetConnectError@* 0x00449C00
    if (sub_00449E40() || sub_00449BE0() || GAME_GetConnectError() || gdwGlobal_00798CC4)
        D2Win_StopMessageLoop();
    return 1;
}

// 0x004438C0
int __stdcall sub_004438C0_OnCancel(int nArg)
{
    CHATDLG_ResetControls();
// build: symbol ?CHARSEL_CancelGameCreate@* 0x0043F850
    CHARSEL_CancelGameCreate();
    CHATDLG_DestroyCreateControls();
    return 1;
}

// 0x00443C20
int __stdcall sub_00443C20_SelectNormal(int nArg)
{
    BUTTON_SetIsPressed(gpNormalRadio, 1);
    BUTTON_SetIsPressed(gpNightmareRadio, 0);
    BUTTON_SetIsPressed(gpHellRadio, 0);
    gnDiffSelect = 0;
    gpCharInfo->nByte210 = 0;
    return 1;
}

// 0x00443C70
int __stdcall sub_00443C70_SelectNightmare(int nArg)
{
    BUTTON_SetIsPressed(gpNormalRadio, 0);
    BUTTON_SetIsPressed(gpNightmareRadio, 1);
    BUTTON_SetIsPressed(gpHellRadio, 0);
    gpCharInfo->nByte210 = 1;
    gnDiffSelect = 1;
    return 1;
}

// 0x00443CC0
int __stdcall sub_00443CC0_SelectHell(int nArg)
{
    BUTTON_SetIsPressed(gpNormalRadio, 0);
    BUTTON_SetIsPressed(gpNightmareRadio, 0);
    BUTTON_SetIsPressed(gpHellRadio, 1);
    gnDiffSelect = 2;
    gpCharInfo->nByte210 = 2;
    return 1;
}

// 0x00443EF0
int __stdcall sub_00443EF0_OnSelect(int nArg)
{
    CHATDLG_DestroyProfileControls();
    if (gnPendingValueB)
    {
        if (gnPendingValueA)
            CHATDLG_OpenExpansionHardcoreLadder();
        else
            CHATDLG_OpenExpansionLadder();
    }
    else
    {
        if (gnPendingValueA)
            CHATDLG_OpenHardcoreLadder();
        else
            CHATDLG_OpenStandardLadder();
    }
    CHATDLG_SelectEntry(gszPendingEntryName, gnPendingValueA, gnPendingValueB);
    return 1;
}

// 0x00443F70
int __stdcall sub_00443F70_OnRefresh(int nArg)
{
    CHATDLG_DestroyProfileControls();
    return 1;
}
