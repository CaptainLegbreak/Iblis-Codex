struct D2WinControlStrc;

void __cdecl sub_00435330_ShowLoginScreen();                                                                // 0x00435330
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __cdecl sub_0042F6C0_SetDone();                                                                        // 0x0042F6C0

extern int gbGatewayFlag_00779954;                                                                          // 0x00779954
extern void (__cdecl* gpfnGatewayDone_007795BC)();                                                          // 0x007795BC
extern D2WinControlStrc* gpStatusText_007799A8;                                                             // 0x007799A8
extern D2WinControlStrc* gpCounterText_007799AC;                                                            // 0x007799AC

// 0x00436320
int __stdcall sub_00436320_GatewayOk(int nUnused)
{
    gbGatewayFlag_00779954 = 1;
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x00436340
int __stdcall sub_00436340_GatewayBack(int nUnused)
{
    gpfnGatewayDone_007795BC = sub_0042F6C0_SetDone;
    sub_0042F3F0_DestroyControls();
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x00436AC0
void __cdecl sub_00436AC0_ClearStatusTexts()
{
    gpStatusText_007799A8 = 0;
    gpCounterText_007799AC = 0;
}
