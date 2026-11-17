extern unsigned short gwszRealmNames_00779DF0[7 * 0x100]; // 0x00779DF0

// 0x006CA940
void __cdecl sub_006CA940_ClearRealmNames()
{
    for (int n = 0; n < 7 * 0x100; ++n)
    {
        gwszRealmNames_00779DF0[n] = 0;
    }
}
