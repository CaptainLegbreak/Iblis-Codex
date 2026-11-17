extern int gnChangedScaleFactor_0072DB40;                                                                   // 0x0072DB40

// 0x004F6610
void __cdecl sub_004F6610_IncreaseScaleFactor()
{
    if (gnChangedScaleFactor_0072DB40 < 0x200)
    {
        gnChangedScaleFactor_0072DB40 += 0x20;
        if (gnChangedScaleFactor_0072DB40 > 0x200)
        {
            gnChangedScaleFactor_0072DB40 = 0x200;
        }
    }
}

// 0x004F6640
void __cdecl sub_004F6640_DecreaseScaleFactor()
{
    if (gnChangedScaleFactor_0072DB40 > 0x100)
    {
        gnChangedScaleFactor_0072DB40 -= 0x20;
        if (gnChangedScaleFactor_0072DB40 < 0x100)
        {
            gnChangedScaleFactor_0072DB40 = 0x100;
        }
    }
}
