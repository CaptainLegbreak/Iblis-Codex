extern "C" int gnFlag_007788DC;
extern "C" int gnBufferBase_007D5448;
extern "C" int gnSoundFlag_007C545C; // 0x007C545C
extern "C" int gnSoundSerial_007C5460; // 0x007C5460
extern "C" { int gnSubsystemActive_007A0458; } // 0x007A0458
extern "C" void __cdecl sub_004142A0(); // 0x004142A0
extern "C" void __cdecl sub_004F7CC0(); // 0x004F7CC0
extern "C" void __cdecl sub_004E4280(); // 0x004E4280
extern "C" int __cdecl sub_0052C030(); // 0x0052C030

// build: context sub_00414360_CallThenSetFlag
extern "C" void __cdecl sub_00414360_CallThenSetFlag()
{
    sub_004142A0();
    gnFlag_007788DC = 1;
}

// build: context sub_004F8DC0_InitLookupTable
extern "C" void __cdecl sub_004F8DC0_InitLookupTable()
{
    sub_004F7CC0();
    gnBufferBase_007D5448 = 0;
}

// 0x004B9D00
extern "C" void __cdecl sub_004B9D00_ResetSoundState()
{
    gnSoundFlag_007C545C = 1;
    gnSoundSerial_007C5460 = 0;
    sub_004E4280();
}

// 0x0044BB80
extern "C" int __cdecl sub_0044BB80_ShutdownIfActive()
{
    if (gnSubsystemActive_007A0458 == 0)
        return 0;
    gnSubsystemActive_007A0458 = 0;
    return sub_0052C030();
}
