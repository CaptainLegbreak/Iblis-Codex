struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

struct D2WinControlInitStrc
{
    char data[0x30];
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);

void __cdecl sub_0043F8C0_ResetLaunchState();                                                               // 0x0043F8C0
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit);                             // 0x004F93C0
void __fastcall sub_004F9740_ControlSetState(D2WinControlStrc* pControl, int nFlags);                       // 0x004F9740
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0

extern D2WinControlInitStrc gtWaitInit_0070D3C0;                                                            // 0x0070D3C0
extern D2WinControlStrc* gpControlA_0077B070;                                                               // 0x0077B070
extern D2WinControlStrc* gpChatControl_0077B074;                                                            // 0x0077B074
extern D2WinControlStrc* gpControlB_0077B078;                                                               // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C;                                                               // 0x0077B07C
extern int gnLaunchMode_0077BBE4;                                                                           // 0x0077BBE4
extern D2WinControlStrc* gpControlMain_0077BC4C;                                                            // 0x0077BC4C
extern D2WinControlStrc* gpWaitText_0077BD9C;                                                               // 0x0077BD9C
extern D2LaunchCallback gpfnLaunchCallback_0077BDA4;                                                        // 0x0077BDA4

// 0x0043FB50
int __fastcall sub_0043FB50_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone)
{
    sub_0043F8C0_ResetLaunchState();
    if (gpControlMain_0077BC4C)
        sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 0);
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gpWaitText_0077BD9C = CONTROL_Create(&gtWaitInit_0070D3C0);
    sub_004FD060_SetText(gpWaitText_0077BD9C, pText);
    gpfnLaunchCallback_0077BDA4 = pfnDone;
    return 1;
}

// 0x0043FBD0
void __cdecl sub_0043FBD0_Refresh()
{
    sub_0043F8C0_ResetLaunchState();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gnLaunchMode_0077BBE4 = 0;
}

#include "gen/data/Source/D2Client/0043FB50_sub_0043FB50_ShowWait.inc"
