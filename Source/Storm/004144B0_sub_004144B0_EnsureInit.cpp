extern "C" int gnFlag_007788DC;                                                                             // 0x007788DC
extern "C" void __cdecl sub_00414360_CallThenSetFlag();                                                     // 0x00414360

// 0x004144B0
extern "C" void __cdecl sub_004144B0_EnsureInit()
{
    if (!gnFlag_007788DC)
        sub_00414360_CallThenSetFlag();
}
