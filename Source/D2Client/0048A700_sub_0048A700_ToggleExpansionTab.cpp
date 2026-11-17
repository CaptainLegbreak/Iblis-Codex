int __cdecl sub_00408F20_HasExpansionMpq(); // 0x00408F20
int __cdecl sub_0044DCC0(); // 0x0044DCC0
extern int gbWeaponSwitch_007BCC4C; // 0x007BCC4C

// 0x0048A700
void __cdecl sub_0048A700_ToggleExpansionTab()
{
    if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
    {
        gbWeaponSwitch_007BCC4C = !gbWeaponSwitch_007BCC4C;
    }
}
