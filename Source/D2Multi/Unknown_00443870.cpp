#include "D2Multi.h"
#include "D2MultiTypes.h"

int gdwGlobal_00798CC4;                                                                                     // 0x00798CC4
D2WinControlStrc* gpControl_00798C4C;                                                                       // 0x00798C4C
D2WinControlStrc* gpControl_00798C50;                                                                       // 0x00798C50
D2WinControlStrc* gpControl_00798C54;                                                                       // 0x00798C54
int gnDiffSelect_00798CD0;                                                                                  // 0x00798CD0
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
char gszName_00798CD4[16];                                                                                  // 0x00798CD4
int gnPendingValueA_00798CE4;                                                                               // 0x00798CE4
int gnPendingValueB_00798CE8;                                                                               // 0x00798CE8
int __fastcall sub_004F9190();                                                            // 0x004F9190
int __cdecl sub_00449B70_PollMcpConnection();                                                               // 0x00449B70
int __cdecl sub_0043EBA0_ResetControls();                                                                   // 0x0043EBA0
void __cdecl sub_00443220_DestroyControls();                                                                // 0x00443220
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0
void __cdecl sub_00443E10();                                                                                // 0x00443E10
void __cdecl sub_004408B0_OpenClassSelectA();                                                                                // 0x004408B0
void __cdecl sub_00440980_OpenClassSelectB();                                                                                // 0x00440980
void __cdecl sub_00440A50_OpenClassSelectC();                                                                                // 0x00440A50
void __cdecl sub_00440B30_OpenClassSelectD();                                                                                // 0x00440B30
void __fastcall sub_0043EC60_SelectEntry(const char* szName, int nValueA, int nValueB);                    // 0x0043EC60

// 0x00443870
int __stdcall sub_00443870_SetCancel(int nArg)
{
    gdwGlobal_00798CC4 = 1;
    return 1;
}

// 0x00443880
int __stdcall sub_00443880_PollMcp(int nArg)
{
    sub_00449B70_PollMcpConnection();
    if (sub_00449E40() || sub_00449BE0() || sub_00449C00() || gdwGlobal_00798CC4)
        sub_004F9190();
    return 1;
}

// 0x004438C0
int __stdcall sub_004438C0_OnCancel(int nArg)
{
    sub_0043EBA0_ResetControls();
    sub_0043F850();
    sub_00443220_DestroyControls();
    return 1;
}

// 0x00443C20
int __stdcall sub_00443C20_SelectNormal(int nArg)
{
    BUTTON_SetIsPressed(gpControl_00798C4C, 1);
    BUTTON_SetIsPressed(gpControl_00798C50, 0);
    BUTTON_SetIsPressed(gpControl_00798C54, 0);
    gnDiffSelect_00798CD0 = 0;
    gpCharInfo_0077BBD8->nByte210 = 0;
    return 1;
}

// 0x00443C70
int __stdcall sub_00443C70_SelectNightmare(int nArg)
{
    BUTTON_SetIsPressed(gpControl_00798C4C, 0);
    BUTTON_SetIsPressed(gpControl_00798C50, 1);
    BUTTON_SetIsPressed(gpControl_00798C54, 0);
    gpCharInfo_0077BBD8->nByte210 = 1;
    gnDiffSelect_00798CD0 = 1;
    return 1;
}

// 0x00443CC0
int __stdcall sub_00443CC0_SelectHell(int nArg)
{
    BUTTON_SetIsPressed(gpControl_00798C4C, 0);
    BUTTON_SetIsPressed(gpControl_00798C50, 0);
    BUTTON_SetIsPressed(gpControl_00798C54, 1);
    gnDiffSelect_00798CD0 = 2;
    gpCharInfo_0077BBD8->nByte210 = 2;
    return 1;
}

// 0x00443EF0
int __stdcall sub_00443EF0_OnSelect(int nArg)
{
    sub_00443E10();
    if (gnPendingValueB_00798CE8)
    {
        if (gnPendingValueA_00798CE4)
            sub_00440B30_OpenClassSelectD();
        else
            sub_00440A50_OpenClassSelectC();
    }
    else
    {
        if (gnPendingValueA_00798CE4)
            sub_00440980_OpenClassSelectB();
        else
            sub_004408B0_OpenClassSelectA();
    }
    sub_0043EC60_SelectEntry(gszName_00798CD4, gnPendingValueA_00798CE4, gnPendingValueB_00798CE8);
    return 1;
}

// 0x00443F70
int __stdcall sub_00443F70_OnRefresh(int nArg)
{
    sub_00443E10();
    return 1;
}
