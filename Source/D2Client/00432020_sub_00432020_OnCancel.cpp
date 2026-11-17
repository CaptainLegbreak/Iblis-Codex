void __cdecl sub_00515020_FadeOutWaves();                                                                   // 0x00515020
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __cdecl sub_0043B080();                                                                                // 0x0043B080
void __cdecl sub_00432100_CreateLoginScreen();                                                              // 0x00432100

// 0x00432020
int __stdcall sub_00432020_OnCancel(int nArg)
{
    sub_00515020_FadeOutWaves();
    sub_0042F480_Reset();
    sub_0043B080();
    return 1;
}

// 0x00432040
int __stdcall sub_00432040_OnCancel2(int nArg)
{
    sub_00515020_FadeOutWaves();
    sub_0042F480_Reset();
    sub_0043B080();
    return 1;
}

// 0x00432300
int __stdcall sub_00432300_OnLoginScreen(int nArg)
{
    sub_00432100_CreateLoginScreen();
    return 1;
}
