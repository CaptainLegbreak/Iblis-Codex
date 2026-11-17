void __fastcall sub_0046F870(int nItemId, int nArg);                                                         // 0x0046F870

char gbGlobal_007C025D;                                                                                     // 0x007C025D
char gbGlobal_007C025E;                                                                                     // 0x007C025E
extern char gbGlobal_007C025F;                                                                              // 0x007C025F

// 0x004A30A0
void __cdecl sub_004A30A0_TriggerOnceD3()
{
    if (!gbGlobal_007C025D)
    {
        gbGlobal_007C025D = 1;
        sub_0046F870(0xD3, 1);
    }
}

// 0x004A30C0
void __cdecl sub_004A30C0_TriggerOnce219()
{
    if (!gbGlobal_007C025E)
    {
        gbGlobal_007C025E = 1;
        sub_0046F870(0x219, 0);
        sub_0046F870(0x21A, 0);
        sub_0046F870(0x21B, 0);
    }
}

// 0x004A3110
char __cdecl sub_004A3110_GetFlag025F()
{
    return gbGlobal_007C025F;
}
