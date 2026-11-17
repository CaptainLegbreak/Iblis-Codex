int __cdecl sub_004F5170();                                                                                 // 0x004F5170
int __stdcall D2GFX_GammaCanBeControlled();                                                                 // 0x004F5260
int __cdecl sub_004577B0();                                                                                 // 0x004577B0

// 0x0047D120
int __cdecl sub_0047D120_PerspectiveEnabled()
{
    return sub_004F5170();
}

// 0x0047D1F0
int __cdecl sub_0047D1F0_GammaEnabled()
{
    return D2GFX_GammaCanBeControlled();
}

// 0x0047D4B0
int __cdecl sub_0047D4B0_PartyNamesEnabled()
{
    return sub_004577B0();
}
