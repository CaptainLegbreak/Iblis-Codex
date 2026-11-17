void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __cdecl sub_0043A730_UpdateButtons();                                                                  // 0x0043A730

extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
extern int gbFlag_00779C6C;                                                                                 // 0x00779C6C

// 0x0043A7E0
void __cdecl sub_0043A7E0_ResetRealmScreen()
{
    if (gnLaunchMode_007795EC == 1)
    {
        sub_0042F3F0_DestroyControls();
        sub_0043A730_UpdateButtons();
    }
    gbFlag_00779C6C = 0;
}
