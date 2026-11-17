struct D2WinControlStrc;
struct D2LaunchCharInfoStrc;

extern int gbFlag_0077ADA4;                                                                                 // 0x0077ADA4
int __cdecl sub_00444E20();                                                                                 // 0x00444E20
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0
extern D2WinControlStrc* gpChatControl_0077B074;                                                            // 0x0077B074
D2WinControlStrc* gpControlB_0077B078;                                                                      // 0x0077B078
D2WinControlStrc* gpControlA_0077B070;                                                                      // 0x0077B070
extern D2WinControlStrc* gpControlC_0077B07C;                                                               // 0x0077B07C
void __cdecl sub_0043F8C0_ResetLaunchState();                                                               // 0x0043F8C0
void __cdecl sub_0043EB30_CreateControls();                                                                 // 0x0043EB30
void __cdecl sub_00440FC0();                                                                                // 0x00440FC0
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
void __cdecl sub_004F8FE0();                                                                                // 0x004F8FE0
void __stdcall sub_004F90A0(int nResolution);                                                               // 0x004F90A0
int __fastcall sub_00441B70_RunChat(D2LaunchCharInfoStrc* pInfo);                                           // 0x00441B70
void __cdecl sub_004FA550();                                                                                // 0x004FA550
extern int gbDone_0077BDA0;                                                                                 // 0x0077BDA0
void __cdecl sub_00440980_OpenClassSelectB();                                                               // 0x00440980
extern unsigned char gnSelectModeA_0070CD62;                                                                // 0x0070CD62
extern int gnSelectIdA_0070CD7C;                                                                            // 0x0070CD7C
int __cdecl sub_00442810_SendChatBuffer();                                                                  // 0x00442810
void __cdecl sub_0043EA20_Wait();                                                                           // 0x0043EA20

// 0x0043F580
int __stdcall sub_0043F580(int nArg)
{
    gbFlag_0077ADA4 = 1;
    return 1;
}

// 0x0043F720
int __stdcall sub_0043F720_Callback(int nArg)
{
    sub_00444E20();
    return 1;
}

// 0x0043F970
int __stdcall sub_0043F970_ReleaseAndRecreate(int nArg)
{
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    sub_0043F8C0_ResetLaunchState();
    sub_0043EB30_CreateControls();
    return 1;
}

// 0x00442150
int __fastcall sub_00442150_StartChat(D2LaunchCharInfoStrc* pInfo)
{
    gpCharInfo_0077BBD8 = pInfo;
    sub_004F8FE0();
    sub_004F90A0(1);
    sub_00441B70_RunChat(pInfo);
    sub_004FA550();
    return gbDone_0077BDA0;
}

// 0x00442350
int __stdcall sub_00442350_OpenClassSelect(int nArg)
{
    sub_0043F8C0_ResetLaunchState();
    sub_00440980_OpenClassSelectB();
    gnSelectModeA_0070CD62 = 0;
    gnSelectIdA_0070CD7C = 0;
    return 1;
}

// 0x00442370
int __stdcall sub_00442370_ReleaseAndCreate(int nArg)
{
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    sub_0043F8C0_ResetLaunchState();
    sub_00440FC0();
    return 1;
}

// 0x004428B0
int __stdcall sub_004428B0_SendChat(int nArg)
{
    sub_00442810_SendChatBuffer();
    sub_0043EA20_Wait();
    return 1;
}
