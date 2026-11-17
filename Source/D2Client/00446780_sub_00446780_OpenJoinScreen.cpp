struct D2WinControlStrc;

void __cdecl sub_0043F8C0_ResetLaunchState();                                                               // 0x0043F8C0
void __cdecl sub_00445DF0_CreateJoinScreen();                                                               // 0x00445DF0
void __cdecl sub_00445FF0_BuildCreateScreen();                                                              // 0x00445FF0
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0
void __cdecl sub_00444020();                                                                                // 0x00444020
void __cdecl sub_0043D990();                                                                                // 0x0043D990

extern int gnLaunchMode_0077BBE4;                                                                           // 0x0077BBE4
extern D2WinControlStrc* gpControlA_0077B070;                                                               // 0x0077B070
D2WinControlStrc* gpChatControl_0077B074;                                                                   // 0x0077B074
extern D2WinControlStrc* gpControlB_0077B078;                                                               // 0x0077B078
D2WinControlStrc* gpControlC_0077B07C;                                                                      // 0x0077B07C

// 0x00446780
int __stdcall sub_00446780_OpenJoinScreen(int nArg)
{
    sub_0043F8C0_ResetLaunchState();
    gnLaunchMode_0077BBE4 = 3;
    sub_00445DF0_CreateJoinScreen();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    return 1;
}

// 0x004467D0
int __stdcall sub_004467D0_OpenCreateScreen(int nArg)
{
    sub_0043F8C0_ResetLaunchState();
    sub_00445FF0_BuildCreateScreen();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    return 1;
}

// 0x00446950
int __stdcall sub_00446950_Refresh(int nArg)
{
    sub_00444020();
    sub_0043D990();
    return 1;
}

// 0x00446D20
int __stdcall sub_00446D20_AlwaysOne(int nArg1, int nArg2)
{
    return 1;
}
