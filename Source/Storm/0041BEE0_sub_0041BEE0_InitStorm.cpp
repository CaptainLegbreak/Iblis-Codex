void __cdecl sub_00411CD0_InitHeaps();                                                                     // 0x00411CD0
void __cdecl sub_00420040_InitLocks();                                                                     // 0x00420040
extern "C" void __cdecl sub_00414360_CallThenSetFlag();                                                    // 0x00414360

// 0x0041BEE0
void __cdecl sub_0041BEE0_InitStorm()
{
    sub_00411CD0_InitHeaps();
    sub_00420040_InitLocks();
    sub_00414360_CallThenSetFlag();
}
