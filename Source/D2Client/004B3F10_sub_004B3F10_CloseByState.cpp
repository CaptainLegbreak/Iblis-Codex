void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
void __cdecl sub_004B3DE0_CloseNpc();                                                                       // 0x004B3DE0
void __cdecl sub_004B3ED0();                                                                                // 0x004B3ED0
void __cdecl sub_0048A6A0_ClearHover();                                                                     // 0x0048A6A0
void __cdecl sub_004C0440();                                                                                // 0x004C0440
void __cdecl sub_004B2110_CloseNpcDialogs();                                                                // 0x004B2110

extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern char gbGlobal_007C0C69;                                                                              // 0x007C0C69
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25

// 0x004B3F10
void __cdecl sub_004B3F10_CloseByState()
{
    if (gnGlobal_007C0C6B == 1)
    {
        gbGlobal_007C0C69 = 0;
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
    }
    else if (gnGlobal_007C0C6B >= 3 && gnGlobal_007C0C6B <= 6)
    {
        sub_004B3ED0();
        sub_0048A6A0_ClearHover();
    }
    else if (gnGlobal_007C0C6B == 7)
    {
        sub_004C0440();
    }
    else if (gbGlobal_007C0C69)
    {
        gbGlobal_007C0C69 = 0;
        sub_004B3DE0_CloseNpc();
    }

    sub_004B2110_CloseNpcDialogs();
    gnGlobal_007C0C6B = 0;
}
