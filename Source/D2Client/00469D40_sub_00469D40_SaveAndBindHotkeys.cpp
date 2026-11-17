void __cdecl sub_00469780_SaveKeyConfig();                                                                  // 0x00469780
void __cdecl sub_004694A0_BindMouseHotkeys();                                                               // 0x004694A0

// 0x00469D40
void __cdecl sub_00469D40_SaveAndBindHotkeys()
{
    sub_00469780_SaveKeyConfig();
    sub_004694A0_BindMouseHotkeys();
}
