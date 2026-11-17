void __cdecl sub_0043F8C0_ResetLaunchState();                                                               // 0x0043F8C0
void __cdecl sub_00443630_UpdateCreateButton();                                                             // 0x00443630
void __cdecl sub_004437E0_UpdateButtonState();                                                              // 0x004437E0
void __cdecl sub_004453B0_BuildPanel();                                                                     // 0x004453B0

// 0x004450C0
int __stdcall sub_004450C0_JoinNameEnter(int nArg)
{
    sub_004437E0_UpdateButtonState();
    return 1;
}

// 0x00445530
int __stdcall sub_00445530_ResetBuildPanel(int nArg)
{
    sub_0043F8C0_ResetLaunchState();
    sub_004453B0_BuildPanel();
    return 1;
}

// 0x004456A0
int __stdcall sub_004456A0_OnEnter(int nArg)
{
    sub_00443630_UpdateCreateButton();
    return 1;
}

// 0x004456B0
int __stdcall sub_004456B0_OnEnter(int nArg)
{
    sub_00443630_UpdateCreateButton();
    return 1;
}

// 0x004456C0
int __stdcall sub_004456C0_OnEnter(int nArg)
{
    sub_00443630_UpdateCreateButton();
    return 1;
}
